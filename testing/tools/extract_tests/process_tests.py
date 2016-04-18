#!/usr/bin/env python
# Author: Pierre Schnizer <schnizer@users.sourceforge.net> 2016
# $Id$
# Reads all test_* files from GSL source directory.
# Extracts the test_sf macros one by one.
# The arguments of the macros are converted into sf_test_types cls instances
# These can be used later on to convert automatically tests from its
from __future__ import print_function
import re


import sf_test_types
import generate_sf_tests

# Patterns for finding the test macros
test_macro_match = re.compile("^.*(?P<macro>TEST_SF.*?)\s*?\(.*$")
# Up to now only the macro TEST_SF() is converted
macro_args_match = re.compile("^.*?TEST_SF\s*?(?P<params>\(.*\))\s*?$")

_pattern_arg = ".+?"
_pattern_sf_result_arg = '\(.+?\)'
_test_sf_args = (
    r'\((?P<s>%s),(?P<func>%s), (?P<args>%s),(?P<result>%s),\s*(?P<tolerance>%s),\s*(?P<status>%s)\)'
    %(_pattern_arg, _pattern_arg, _pattern_sf_result_arg, _pattern_arg, _pattern_arg, _pattern_arg)
    )
analyse_macro_match = re.compile(_test_sf_args)

#test_list_file_name = "test_list.dump"

func_exclude_list = (
    "gsl_sf_coupling_3j_e",
    "gsl_sf_exp_mult_e",
    "gsl_sf_exp_mult_err_e",
    "gsl_sf_lambert_W0_e",
    "gsl_sf_lambert_Wm1_e",
    "gsl_sf_mathieu_ce_e"
    "gsl_sf_mathieu_se_e"
    )

class _build_sf_params:
    """Each macro call is stored in an instance of _t_store which is an instance
    of a subclass of _test_sf_params. The info stored there is then later used
    for writing the particular test case """
    
    _t_store = None
    def __init__(self, macro_args_line):
        self._text = macro_args_line
        self._store = None
        # To be implemented in the subclass. Should create an instance of
        # _t_store and feed the marco arguments to this instance        
        self._HandleText()

    def GetStore(self):
        return self._store
    
    def __str__(self):
        return str(self._store)


def dbl_str_to_int(a_str):
    """
    Some GSL tests set an int value with classical double format.
    """
    test_val = float(a_str)
    prep = round(test_val)
    diff = test_val - prep

    a_diff = abs(diff)
    if a_diff == 0:
        result = int(prep)
        return result

    msg = "Can not convert '%s' reliably to int diff = '%s'" %(a_str, diff)
    raise ValueError(msg)
    
    
    parts = a_str.split(".")
    l = len(parts)
    if l == 0:
        result = int(a_str)
        return result

    elif l == 1:
        result = int(parts[0])
        return result

    elif l == 2:
        test = int(parts[1])
        
        if test != 0:
            msg = "Can not convert '%s' split to '%s' to int" %(a_str, parts)
            raise ValueError(msg)
        
        result = int(parts[0])
        return result

    else:
        msg = "Can not convert '%s' split to '%d' parts to int" %(a_str, l)
        raise ValueError(msg)
        
class build_sf_params(_build_sf_params):
    """
    Used for the arguments found in the macro TEST_SF()
    """
    _t_store = sf_test_types.test_sf_params 

    def _ConvertNonNumericArg(self, arg, func_name):
        ""
        if "gsl_sf_airy" in func_name:
            if arg == 'm':
                return "GSL_MODE_DEFAULT"
            else:
                raise ValueError("airy test variable '%s' unknown" % (arg,))
            
        elif "gsl_sf_ellint" in func_name:
            if arg == 'mode':
                return "GSL_MODE_DEFAULT"
            if arg == "GSL_NAN":
                return "GSL_NAN"                
            # else:
            #    raise ValueError("ellint test variable '%s' unknown" % (arg,))

        return arg
        
    def _ConvertArg(self, arg, func_name):
        tmp = None
        try:
            tmp = int(arg)
        except ValueError:
            pass

        if tmp == None:
            try:
                tmp = float(arg)
            except ValueError:
                pass

        if tmp == None:
            tmp = self._ConvertNonNumericArg(arg, func_name)

        if tmp == None:
            result = arg
        else:
            result = tmp
                
        return result
    

    def _HandleArgs_ForFunc(self, func_name, args):
        """
        multiply_e x... has to be set to 0.2 DBL_MAX
        
        Test for some functions require special treatment: values with '.0' for
        int arguments
        """

        if "sf_multiply_e" in func_name:
            x_rep = "(0.2 * DBL_MAX)"
            result = []
            for arg in args:
                arg = arg.replace("x", x_rep)
                result.append(arg)
                
            return result
        

        first_arg_to_int = 0
        
        if "sf_zetam1_int_e" in func_name:
            first_arg_to_int = 1

        if "sf_zeta_int_e" in func_name:
            first_arg_to_int = 1

        if "sf_exprel_n_e" in func_name:
            #(s,  gsl_sf_exprel_n_e, (1263131.0, 1261282.3637, &r), 545.0113107238425900305428360, TEST_TOL4, GSL_SUCCESS)
            first_arg_to_int = 1
            
        if "sf_laguerre_n_e" in func_name:
            arg0 = args[0]
            
            if arg0 == "1e5":
                arg0 = int(1e5)
            elif arg0 == "1e5+1":
                arg0 = int(1e5+1)
            elif arg0 == "1e6+1":
                arg0 = int(1e6+1)
            elif arg0 == "5e6+1":
                arg0 = int(1e6+1)
            elif arg0 == "8e6+1":
                arg0 = int(8e6+1)
            elif arg0 == "1e7+1":
                arg0 = int(1e7+1)
            elif arg0 == "1e8+1":
                arg0 = int(1e8+1)
            elif arg0 == "1e9+1":
                arg0 = int(1e8+1)
            else:    
                first_arg_to_int = 1
            args = (arg0,) + args[1:]
            
        if first_arg_to_int == 1:
            # First arg should be an int
            arg = args[0]
            try:
                arg = dbl_str_to_int(arg)
            except ValueError as ve:
                msg = "func '%s' args '%s'" %(func_name, args)
                ve.args += (msg, )
                raise ve
            
            args = (arg,) + args[1:]
            return args
        
        else:
            return args

        raise ValueError("Should not end up here")
            
    def _HandleArgs(self, args_text, func_name):
        """
        Arguments to the functions
        """
        assert(args_text[0] == "(")
        assert(args_text[-1] == ")")
        
        args_text = args_text[1:-1]

        args = args_text.split(",")
        
        gsl_sf_result = args[-1]
        gsl_sf_result = gsl_sf_result.strip()
        if gsl_sf_result != "&r":
            msg = "Failed to see gsl_sf_result for func '%s'(%s): '%s' <-gsl_sf_result"
            raise ValueError(msg %(func_name, args_text, gsl_sf_result))
                             
        args  = args[:-1]

        args = tuple(map(lambda s: s.strip(), args))
        args = self._HandleArgs_ForFunc(func_name, args)
        
        l = []
        for arg in args:
            tmp = self._ConvertArg(arg, func_name)
            l.append(tmp)
        args = tuple(l)
        return args
    
    def _HandleText(self):
        assert(self._t_store)
        text = self._text
        m = analyse_macro_match.match(text)
        assert(m)
        d = m.groupdict()
        func   = d["func"]
        args   = d["args"]
        result = d["result"]
        status = d["status"]
        tolerance = d["tolerance"]
        
        func = func.strip()
        args = args.strip()
        result = result.strip()
        status = status.strip()
        text = text.strip()
        tolerance = tolerance.strip()
        
        if func in func_exclude_list:
            return
        
        args = self._HandleArgs(args, func)
        
        store =  self._t_store(
            func   = func  ,
            result = result,
            args   = args  ,
            status = status,
            tolerance = tolerance,
            text = text
            )

        self._store = store

    
        
def handle_match_test_sf(line):
    """
    line is expected to contain a TEST_SF() macro line
    """
    m = macro_args_match.match(line)
    if not m:
        print("Can not extract macro args from line '%s'" %(line,))
        return
    
    assert(m)
    d = m.groupdict()
    params = d["params"]
    c = build_sf_params(params)
    return c

_comment_start = re.compile(r"\s*/\*")
_comment_end   = re.compile(r".*?\*/")

def extract_first_comment(lines):
    """
    Used to pass the original copyright along
    """


    max_lines = 200
    for cnt in range(max_lines):
        line = lines.pop(0)
        m = _comment_start.match(line)
        if m != None:
            break
    else:
        msg = "Did not expect the first comment not to start in %d lines"
        raise ValueError(msg % (max_lines))
        
    first_comment_text = [line]
    for cnt in range(max_lines):
        # first comment started
        line = lines.pop(0)
        first_comment_text.append(line)
        m = _comment_end.match(line)
        if m != None:
            # Fist comment finished 
            break
    else:
        msg = "Did not expect the first comment not to finish in %d lines"
        raise ValueError(msg % (max_lines))

    return first_comment_text, lines
    
def handle_one_test_file(a_file_name):
    """
    seach for lines containing a macro starting with TEST_SF
    """
    try:
        fp = open(a_file_name, "rt")
        text = fp.readlines()
    finally:
        fp.close()
        del fp

    first_comment, text = extract_first_comment(text)
    # I want to extract the TEST_SF macros. Some of them span over more than
    # one line.
    text = map(lambda line: line.strip(), text)
    text = "".join(text)
    text = text.split(";")

    all_tests = []
    for line in text:        
        m = test_macro_match.match(line)
        if m:
            macro_name = m.groupdict()["macro"]
            #print("'%s' : '%s'" %(macro_name, line) )
            if macro_name == "TEST_SF":
                c = handle_match_test_sf(line)
                all_tests.append(c)
            elif macro_name == "TEST_SF_2":                
                #print("Handling macro TEST_SF_2: '%s' not yet implemented" %(line,) )
                pass
            else:
                #print("Handling macro '%s': '%s' not yet implemented" %(macro_name, line,) )
                pass
            #return
    return first_comment, all_tests

