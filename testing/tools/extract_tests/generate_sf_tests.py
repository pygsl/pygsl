import pickle
import sf_test_types


def _include_file(file_name, of):
    fp = open(file_name, "rt")
    try:
        text = fp.read()
    finally:
        fp.close()
        del fp

    of.write(text)
    of.write("\n")
    
def _write_header(of):
    header="""
import unittest
import pygsl.testing.sf as sf

import sf_test_basis
from sf_test_basis import *
_test_sf_automatic = sf_test_basis._test_sf_automatic
"""
    of.write(header)
    
def _write_footer(of):
    footer="""
if __name__ == '__main__':
    unittest.main()
"""
    of.write(footer)


code_cls="""_t_func = None
try:    
    _t_func = sf.%s
except AttributeError:
    print("Not including tests for %s")
    
if _t_func != None:
    class test_sf_automatic_%s(_test_sf_automatic):
        _func = _t_func
"""

#       def _test(self, orig_args, result, tolerance, status):
code="""
        def test_args%d_1(self):
            '%s'            
            self._test(%s, %s, %s)

"""

#       def _test_rlx(self, orig_args, result, tolerance, status):
code_rlx="""
        def test_args%d_1_rlx(self):
            '%s'            
            self._test(%s, %s, %s)

"""
code_theta="""
        def test_args%d_1_theta(self):
            '%s'            
            self._test(%s, %s, %s)

"""

#       def _test2(self, orig_args, ref1, ref2, status):
code2="""
        def test_args%d_2(self):
            '%s'            
            self._test2(%s, %s, %s, %s)

"""


def _write_tests(of, tests):
    """Writing tests ... 

    x
    """
    # Sort the tests for each function
    d = {}
    for ins in tests:
        if ins == None:
            continue
        func = ins.GetFunctionName()
        try:
            l = d[func]
        except KeyError:
            d[func] = []

        # Now the function must exist
        l = d[func]
        l.append(ins)


    # Alphabetic test list
    keys = d.keys()
    keys = list(keys)
    keys.sort()


    cnt_all = 0
    for key in keys:
        t_test_ins = d[key]

        ## see if all are None
        ## ins = t_test_ins

        cls_code_generated = 0
        for cnt in range(len(t_test_ins)):
            ins = t_test_ins[cnt]
            if ins == None:
                # Skipped function tests
                continue

            if cls_code_generated == 0:
                func_name_ref = ins.GetFunctionName()
                func_name = func_name_ref[7:]
                params =  (func_name,) *3
                t_code_cls = code_cls % params
                of.write(t_code_cls)

                cls_code_generated = 1

            func_name_test = ins.GetFunctionName()
            assert(func_name_test == func_name_ref)

            #print(ins, ins.__class__.__name__)
            txt = ins.GetTestText()
            args = ins.GetFunctionArguments()
            status = ins.GetFunctionStatus()
            if isinstance(ins, sf_test_types.test_sf_params_rlx):
                f = ins.GetFunctionResult()
                t = ins.GetResultTolerance()
                t_code = code_rlx %(cnt_all, txt, args, (f, t), status)

            elif isinstance(ins, sf_test_types.test_sf_params_theta):
                f = ins.GetFunctionResult()
                t = ins.GetResultTolerance()
                t_code = code_theta %(cnt_all, txt, args, (f, t), status)

            elif isinstance(ins, sf_test_types.test_sf_params):
                f = ins.GetFunctionResult()
                t = ins.GetResultTolerance()
                t_code = code %(cnt_all, txt, args, (f, t), status)

            elif isinstance(ins, sf_test_types.test_sf_params_2):
                f1 = ins.GetFunctionResult1()
                t1 = ins.GetResultTolerance1()
                f2 = ins.GetFunctionResult2()
                t2 = ins.GetResultTolerance2()

                t_code = code2 %(cnt_all, txt, args, (f1, t1), (f2, t2), status)

            else:
                fmt = "instance '%s' of class '%s' not known"
                msg = fmt %(ins, ins.__class__.__name__)
                raise ValueError(msg)
                
            test = 0
            try:
                test = 1
            finally:
                if test == 0:
                    print(ins, dir(ins))

            of.write(t_code)
            cnt_all += 1

def _write_comment(fp, first_comment):
    msg="""#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
"""
    fp.write(msg)
    for line in first_comment:
        fp.write("# %s" %(line,))
    _write_header(fp)
    
def write_tests(test_file_name, first_comment, tests):
    fp = open(test_file_name, "wt")
    try:
        _write_comment(fp, first_comment)
        _write_tests(fp, tests)
        _write_footer(fp)
    finally:
        fp.close()
        del fp

if __name__ == "__main__":
    run()
