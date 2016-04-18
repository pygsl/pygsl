import pickle


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

code="""
        def test_args%d(self):
            '%s'            
            self._test(%s, %s, %s, %s)

"""


def _write_tests(of, tests):
    
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
            
            t_code = code %(cnt, ins.GetTestText(),
            ins.GetFunctionArguments(), ins.GetFunctionResult(), ins.GetResultTolerance(), ins.GetFunctionStatus())
            of.write(t_code)

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
