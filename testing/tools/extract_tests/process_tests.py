#!/usr/bin/env python
# Author: Pierre Schnizer <schnizer@users.sourceforge.net> 2016, 2017
# $Id: process_tests.py,v 1.1 2016/04/18 17:08:30 schnizer Exp $
"""extracts the  tests defined in test_sf* funcions and converts them to 
unittests

Reads all test_* files from GSL source directory.
Extracts the test_sf macros one by one.
The arguments of the macros are converted into sf_test_types cls instances
These can be used later on to convert automatically tests from its
"""
from __future__ import print_function, division
import re


import sf_test_types
import generate_sf_tests

# Patterns for finding the test macros
test_macro_match = re.compile("^.*(?P<macro>TEST_SF.*?)\s*?\(.*$")
# Up to now only the macro TEST_SF() and TEST_SF_2 is converted
macro_args_match = re.compile("^.*?TEST_SF\s*?(?P<params>\(.*\))\s*?$")
macro_args_rlx_match = re.compile("^.*?TEST_SF_RLX\s*?(?P<params>\(.*\))\s*?$")
macro_args_theta_match = re.compile("^.*?TEST_SF_THETA\s*?(?P<params>\(.*\))\s*?$")
macro_args2_match = re.compile("^.*?TEST_SF_2\s*?(?P<params>\(.*\))\s*?$")

_pattern_arg = ".+?"
_pattern_sf_result_arg = '\(.+?\)'
_test_sf_args = (
    r'\((?P<s>%s),(?P<func>%s), (?P<args>%s),(?P<result>%s),\s*(?P<tolerance>%s),\s*(?P<status>%s)\)'
    %(_pattern_arg, _pattern_arg, _pattern_sf_result_arg, _pattern_arg, _pattern_arg, _pattern_arg)
    )
analyse_macro_match = re.compile(_test_sf_args)

_test_sf_args_theta = (
    r'\((?P<s>%s),(?P<func>%s), (?P<args>%s),(?P<result>%s),\s*(?P<tolerance>%s)\)'
    %(_pattern_arg, _pattern_arg, _pattern_sf_result_arg, _pattern_arg, _pattern_arg)
    )
analyse_macro_match_theta = re.compile(_test_sf_args_theta)

_test_sf2_args = (
    r'\((?P<s>%s),(?P<func>%s), (?P<args>%s),\s*(?P<result1>%s),\s*(?P<tolerance1>%s),\s*(?P<result2>%s),\s*(?P<tolerance2>%s),\s*(?P<status>%s)\)'
    %(_pattern_arg, _pattern_arg, _pattern_sf_result_arg, _pattern_arg, _pattern_arg, _pattern_arg, _pattern_arg, _pattern_arg)
    )
analyse_macro2_match = re.compile(_test_sf2_args)

#test_list_file_name = "test_list.dump"

func_exclude_list = (
    "gsl_sf_coupling_3j_e",
    "gsl_sf_exp_mult_e",
    "gsl_sf_exp_mult_err_e",
    "gsl_sf_lambert_W0_e",
    "gsl_sf_lambert_Wm1_e",
    #"gsl_sf_mathieu_ce_e"
    #"gsl_sf_mathieu_se_e"
    )



def dbl_str_to_int(a_str):
    """Convert a double to int checking that rounding error is tolerable

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
            
        
class build_sf_params(_build_sf_params):
    """Used for the arguments found in the macro TEST_SF()
    """
    _t_store = sf_test_types.test_sf_params 

    def _HandleArgs(self, args_text, func_name):
        """Process the arguments to the functions
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


class build_sf_params_rlx(build_sf_params):
    """RLX same as SF ... but what's the difference?
    """
    _t_store = sf_test_types.test_sf_params_rlx

class build_sf_params_theta(build_sf_params):
    """signature similar to TEST_SF ... but returns always success?
    """
    _t_store = sf_test_types.test_sf_params_theta
    def _HandleArgs(self, args_text, func_name):
        """Process the arguments to the functions
        """
        assert(args_text[0] == "(")
        assert(args_text[-1] == ")")
        
        args_text = args_text[1:-1]

        # No reference to GSL struct for this test macro
        # as for TEST_SF
        args = args_text.split(",")
        
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
        m = analyse_macro_match_theta.match(text)
        assert(m)
        d = m.groupdict()
        func   = d["func"]
        args   = d["args"]
        result = d["result"]
        status = "GSL_SUCCESS"
        tolerance = d["tolerance"]
        
        func = func.strip()
        args = args.strip()
        result = result.strip()
        status = status.strip()
        text = text.strip()
        tolerance = tolerance.strip()
        
        if func in func_exclude_list:
            return

        test = 0
        try:
            args = self._HandleArgs(args, func)
            test = 1
        finally:
            if test == 0:
                print("Handled macro text '%s' for TEST_SF_THETA" %(text,))
        
        store =  self._t_store(
            func   = func  ,
            result = result,
            args   = args  ,
            status = status,
            tolerance = tolerance,
            text = text
            )

        self._store = store


class build_sf_params_2(_build_sf_params):
    """Used for the arguments found in the macro TEST_SF()
    """
    _t_store = sf_test_types.test_sf_params_2
    def _HandleArgs(self, args_text, func_name):
        """
        Arguments to the functions
        """
        assert(args_text[0] == "(")
        assert(args_text[-1] == ")")
        
        args_text = args_text[1:-1]

        args = args_text.split(",")

        # Last to shall be gsl sf result
        for cnt in range(2):
            arg = args[-2 + cnt]
            gsl_sf_result = arg
            gsl_sf_result = gsl_sf_result.strip()
            token = "&r%d" %(cnt+1,)
            if gsl_sf_result != token:
                msg = "Failed to find gsl_sf_result %d for func '%s'(%s): '%s' <- pointer to gsl_sf_result '%s'"
                raise ValueError(msg %(cnt+1, func_name, args_text, gsl_sf_result, token))
                             
        args  = args[:-2]

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
        m = analyse_macro2_match.match(text)
        assert(m)
        d = m.groupdict()
        func   = d["func"]
        args   = d["args"]
        status = d["status"]
        result1 = d["result1"]
        tolerance1 = d["tolerance1"]
        result2 = d["result2"]
        tolerance2 = d["tolerance2"]
        
        func = func.strip()
        args = args.strip()
        status = status.strip()
        text = text.strip()
        result1 = result1.strip()
        result2 = result2.strip()
        tolerance1 = tolerance1.strip()
        tolerance2 = tolerance2.strip()
        
        if func in func_exclude_list:
            return
        
        args = self._HandleArgs(args, func)
        
        store =  self._t_store(
            func   = func  ,
            args   = args  ,
            status = status,
            result1 = result1,
            tolerance1 = tolerance1,
            result2 = result2,
            tolerance2 = tolerance2,
            text = text
            )
        self._store = store
    
        
def handle_match_test_sf(line):
    """handle a line containing TEST_SF


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

def handle_match_test_sf_theta(line):
    """handle a line containing TEST_SF_THETA


    line is expected to contain a TEST_SF_THETA() macro line
    """
    m = macro_args_theta_match.match(line)
    if not m:
        print("Can not extract macro args from line '%s'" %(line,))
        return
    
    assert(m)
    d = m.groupdict()
    params = d["params"]
    c = build_sf_params_theta(params)
    return c

def handle_match_test_sf_rlx(line):
    """handle a line containing TEST_SF_RLX


    line is expected to contain a TEST_SF_RLX() macro line
    """
    # XXX same pattern as SF but different functionality
    m = macro_args_rlx_match.match(line)
    if not m:
        print("Can not extract macro args from line '%s'" %(line,))
        return
    
    assert(m)
    d = m.groupdict()
    params = d["params"]
    c = build_sf_params_rlx(params)
    print("RLX Test:", c)
    assert(c is not None)
    return c

def handle_match_test_sf_2(line):
    """extract a  TEST_SF_2 test

    Args:
        line:  is expected to contain a TEST_SF_2() macro line
    """
    m = macro_args2_match.match(line)
    if not m:
        print("Can not extract macro args from line '%s'" %(line,))
        return
    
    assert(m)
    d = m.groupdict()
    params = d["params"]
    c = build_sf_params_2(params)
    return c



_comment_start = re.compile(r"(\s*)(/\*.*)$")
_comment_end   = re.compile(r"(.*?\*/)(.*)$")

def extract_comment(lines, max_lines = None):
    """

    Args:
        lines

    Used to pass the original copyright along
    """

    if max_lines is None:
        max_lines = 200
    else:
        max_lines = int(max_lines)
        
    for cnt in range(max_lines):
        line = lines.pop(0)
        m = _comment_start.match(line)
        if m != None:
            break
    else:
        msg = "Did not expect the  comment not to start in %d lines"
        raise ValueError(msg % (max_lines))
        
    comment_text = [line]
    lines = [line] + lines
    for cnt in range(max_lines):
        # first comment started
        line = lines.pop(0)
        comment_text.append(line)
        m = _comment_end.match(line)
        if m != None:
            # Fist comment finished 
            break
    else:
        msg = "Did not expect the comment not to finish in %d lines"
        raise ValueError(msg % (max_lines))

    return comment_text, lines


_extended_start = re.compile(r"\s*#ifdef(.*?)(\s.*)?$")
_extended_end   = re.compile(r"\s*#endif(.*?)(\s.*)?$")
_comment_line = re.compile(r"^(.*)(/\*.*?\*/)(.*)$")

def handle_one_test_file(a_file_name, verbose = None):
    """
    seach for lines containing a macro starting with TEST_SF

    Args:
        a_file_name : name of a file containing TEST_SF lines
    """
    try:
        fp = open(a_file_name, "rt")
        text = fp.readlines()
    finally:
        fp.close()
        del fp
    
    first_comment, text = extract_comment(text)
    cnt_first_comment = len(first_comment)

    # Remove trailing new lines: easier info print below ....
    text = map(lambda line: line.strip(), text)
    #---------------------------------------------------------------------------
    # Extract part which is between
    # #ifdef
    # #endif    
    _extended_test = False
    # Exclude extended tests defined by
    cnt = cnt_first_comment
    cleaned_lines = []
    for line in text:
        cnt +=1
        if _extended_test == False:
            et = _extended_start.match(line)
            if et is not None:
                _extended_test = True
                grps = et.groups()
                assert(len(grps) == 2)
                fmt = ("'%s' %d extended test start with label: '%s' ignoring '%s'" +
                       "\n\t line '%s'")
                if verbose:
                    print(fmt %(a_file_name, cnt, grps[0], grps[1], line))
                cleaned_lines.append(" ")
                continue
            else:
                cleaned_lines.append(line)

        elif _extended_test == True:
            et = _extended_end.match(line)
            if et is not None:
                grps = et.groups()
                assert(len(grps) == 2)
                fmt = ("\t'%s' %d extended test end: '%s' ignoring '%s' " +
                       "\n\t line '%s'")
                if verbose:
                    print(fmt %(a_file_name, cnt,  grps[0], grps[1], line))
                _extended_test = False
            else:
                print("\tSkipped extended test", line)
                cleaned_lines.append(" ")
        else:
            raise ValueError("value '%s' of _extended_test unknown" %(_extended_test,))
        #----------------------------------------------------------------------

    
    #---------------------------------------------------------------------------
    # Extract commment
    text = cleaned_lines
    cleaned_lines = []

    _comment_part = False
    cnt = cnt_first_comment
    for line in text:
        cnt += 1

        #print(line)

        #----------------------------------------------------------------------
        # Exclude single line comments ....
        m = _comment_line.match(line)
        if m is not None:
            orig_line = line
            grps = m.groups()
            assert(len(grps) == 3)
            line = grps[0] + " " + grps[2]
            fmt = ("%s:%d Ignoring comment in line '%s';\n\t continuing with %s;" +
                   "\n\t original line '%s'\n")
            if verbose:
                print(fmt % (a_file_name, cnt, grps[2], line, orig_line) )
            
        # -----------------------------------------------------------
        # State: comment part or not
        # Exclude multi line comments ....
        if _comment_part == False:
            m = _comment_start.match(line)
            if m is not None:
                _comment_part = True
                orig_line = line
                grps = m.groups()
                assert(len(grps) == 2)
                line = grps[0]
                fmt = ("%s:%d Comment start: Continuing with '%s'" +
                       " Ignoring part '%s' of line '%s'")
                if verbose:
                    print(fmt %(a_file_name, cnt, line, grps[1], orig_line))
        elif _comment_part == True:
            m = _comment_end.match(line)
            if m is None:
                fmt = "\tIgnoring line (part of comment) '%s' "
                if verbose:
                    print(fmt %(line))
                # Keep it to the lines count of the original file
                cleaned_lines.append(" ")
                continue
            else:
                _comment_part = False
                grp = m.groups()                
                orig_line = line
                grps = m.groups()
                assert(len(grps) == 2)
                line = grps[1]
                fmt = ("%s:%d Comment end:" + 
                       "\n\t Continuing with '%s' Ignoring part '%s'" +
                       "\n\t of line '%s'" )
                if verbose:
                    print(fmt %(a_file_name, cnt, line, grps[0], orig_line))        
        else:
            raise ValueError("value '%s' of _comment_part unknown" %(_comment_part,))

        cleaned_lines.append(line)
        
    # I want to extract the TEST_SF macros. Some of them span over more than
    # one line.
    text = cleaned_lines
    text = map(lambda line: line.strip(), text)
    text = "".join(text)
    text = text.split(";")

    

    all_tests = []
    cnt_val = 0
    cnt_other = 0
    cnt = cnt_first_comment
    for line in text:
        cnt += 1
        #----------------------------------------------------------------------
        # Search for tests ....
        m = test_macro_match.match(line)        
        if m:
            macro_name = m.groupdict()["macro"]
            #print("'%s' : '%s'" %(macro_name, line) )
            if macro_name == "TEST_SF":
                c = handle_match_test_sf(line)
                all_tests.append(c)
            elif macro_name == "TEST_SF_RLX":
                #print("Handling macro TEST_SF_RLX: '%s'" %(line,) )
                c = handle_match_test_sf_rlx(line)
                all_tests.append(c)
            elif macro_name == "TEST_SF_THETA":
                #print("Handling macro TEST_SF_RLX: '%s'" %(line,) )
                c = handle_match_test_sf_theta(line)
                all_tests.append(c)                
            elif macro_name == "TEST_SF_2":                
                #print("Handling macro TEST_SF_2: '%s' not yet implemented" %(line,) )
                c = handle_match_test_sf_2(line)
                all_tests.append(c)
                pass
            elif macro_name == "TEST_SF_VAL":
                #print("Handling macro TEST_SF_VAL: '%s' not yet implemented" %(line,) )
                cnt_val += 1
                pass
            else:
                print("Handling macro '%s': '%s' not yet implemented" %(macro_name, line,) )
                cnt_other += 1
                pass
            #return
        #----------------------------------------------------------------------

    print ("Still missing %d TEST_SF_VAL and %d other tests" %(cnt_val, cnt_other))
    return first_comment, all_tests

