#!/usr/bin/env python
# Author: Pierre Schnizer <schnizer@users.sourceforge.net> 2016, 2017
# $Id$
"""Generate python testcases from GSL src

Reads all test_* files from GSL source directory.
Extracts the test_sf macros one by one.
The arguments of the macros are converted into sf_test_types cls instances
These can be used later on to convert automatically tests from its
"""

from __future__ import print_function
import sys
import os
import glob
import os.path
import process_tests
import generate_sf_tests

_gsl_dir_env_var = "GSL_SRC"

# _base_dir = os.path.abspath(os.path.dirname(__file__))
# _t_dir = os.path.join(_base_dir, "extract_tests")
# sys.path.append(_t_dir)


def find_gsl_src_dir_from_env():
    """Find the top directory of the GSL SRC tree
    """
    
    # Installation of the GSL_SRC

    gsl_dir = None
    try:
        gsl_dir = os.environ[_gsl_dir_env_var]
    except KeyError as des:
        pass
    
    if gsl_dir == None:
        msg = """You must specify where the GSL source directory is to be found.
Either use the command line switch '-g' or define the environment variable '%s',
which specifies where the GSL source directory is found. This module will then
parse the tests in the directory 'specfunc' and translate them to
unittest.TestCase tests.
"""
        raise ValueError(msg %(_gsl_dir_env_var,))
    
    return gsl_dir

def help_text():
    msg = """
Usage '%s' -g gsl_src --gsl-src-directory gsl_src

Parses test_*.c files in the gsl_src/sepcfunc directory and generates
unittest.TestCases out of it.
"""
    print(msg % (sys.argv[0], ))
          
def find_gsl_src_dir():
    import getopt

    progname = "%s %s" % (sys.executable, sys.argv[0])
    try:
        res = getopt.getopt(sys.argv[1:], 'g:h', ('gsl-src-directory='))
    except getopt.GetoptError as err:
        err.msg += ". Run %s -h for further information" %(progname,)
        raise(err)
    
    found_options = res[0]


    for opt in found_options:
        if '-h' in opt:
            help_text()
            return
        
    gsl_src = None
    opt_arg = None
    how_specified = None
    for opt in found_options:
        if '-g' or '--gsl-src-directory' in opt:
            gsl_src = opt[1]
            how_specified = "command line option %s %s" % opt
            
    if gsl_src == None:
        # No option found ... try environement
        gsl_src = find_gsl_src_dir_from_env()
        how_specified = "Environment variable  os.environ[%s]=%s"
        how_specified = how_specified %(_gsl_dir_env_var, gsl_src)
        
    # Check if gsl_src is a directory
    if not os.path.isdir(gsl_src):
        msg = """
    The path '%s' specified via '%s' is not a directory!
"""
        print(msg %(gsl_src, how_specified))
        return 

    t_dir =  "specfunc",
    spec_func_dir = os.path.join(*((gsl_src,) + t_dir))
    
    # Check if gsl_spec_func_dir is a directory
    if not os.path.isdir(spec_func_dir):
        msg = """
    The path '%s' specified via '%s' is not a directory!
"""
        print(msg %(spec_func_dir, how_specified))
        return 

    return spec_func_dir

def run():    
    "main function"
    gsl_src_dir= find_gsl_src_dir()
    if gsl_src_dir == None:
        return
    
    print("Using GSL source dir '%s'" %(gsl_src_dir,))
    test_files = os.path.join(gsl_src_dir, "*test*.c")
    #test_files = os.path.join(gsl_src_dir, "*test_bessel*.c")
    all_tests = glob.glob(test_files)

    for a_test in all_tests:
        #if "airy" in a_test:
        #    continue
        first_comment, tests = process_tests.handle_one_test_file(a_test)
    
        base = os.path.basename(a_test)        
        outfile_name = base[:-2] + '_from_gsl_src.py'
        print("Writing tests to '%s'" % (outfile_name,))
        all_stores = map(lambda x: x.GetStore(), tests)
        generate_sf_tests.write_tests(outfile_name, first_comment, all_stores)
        
if __name__ == '__main__':
    run()
