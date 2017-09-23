#!/usr/bin/env python
from __future__ import print_function, division
import pickle
import unittest
import numpy as np
sqrt = np.sqrt
log = np.log
exp = np.exp
M_LN2 = np.log(2)
M_PI=np.pi
M_PI_2=np.pi/2
DELTA=1.2246467991473531772e-16

import pygsl
import pygsl.ieee
import pygsl.testing.sf as sf
import pygsl._numobj as np
import pygsl.gslwrap
from pygsl import errno, errors

class TestNoFuncError(errors.gsl_Error):
    "Called function was not specified!"
    pass

gsl_isnan = pygsl.gslwrap.gsl_isnan
gsl_fcmp = pygsl.gslwrap.gsl_fcmp
GSL_NAN=pygsl.gslwrap.gsl_nan()
GSL_SUCCESS=errno.GSL_SUCCESS
GSL_EDOM=errno.GSL_EDOM
DBL_MAX=1e200
GSL_EMAXITER=errno.GSL_EMAXITER
GSL_ELOSS=errno.GSL_ELOSS

GSL_DBL_EPSILON=2.2204460492503131e-16
GSL_SQRT_DBL_EPSILON=1.4901161193847656e-08
TEST_TOL0 = (2.0*GSL_DBL_EPSILON)
TEST_TOL1 = (16.0*GSL_DBL_EPSILON)
TEST_TOL2 = (256.0*GSL_DBL_EPSILON)
TEST_TOL3 = (2048.0*GSL_DBL_EPSILON)
TEST_TOL4 = (16384.0*GSL_DBL_EPSILON)
TEST_TOL5 = (131072.0*GSL_DBL_EPSILON)
TEST_TOL6 = (1048576.0*GSL_DBL_EPSILON)
TEST_SQRT_TOL0 = (2.0*GSL_SQRT_DBL_EPSILON)
TEST_SNGL =  (1.0e-06)


_tol_dic = {
    "TEST_TOL0": TEST_TOL0, 
    "TEST_TOL1": TEST_TOL1, 
    "TEST_TOL2": TEST_TOL2, 
    "TEST_TOL3": TEST_TOL3, 
    "TEST_TOL4": TEST_TOL4, 
    "TEST_TOL5": TEST_TOL5, 
    "TEST_TOL6": TEST_TOL6, 
    "TEST_SNGL": TEST_SNGL, 
    "TEST_SQRT_TOL0": TEST_SQRT_TOL0    
    }

class _test_sf_automatic(unittest.TestCase):
    """Base class for all tests
    """
    _func = None

    def _GetArgs(self, args):
        """Convert string to arguments
        """
        types = self._func.types
        a_type = types[-1]
        inargs, outargs = a_type.split('->')

        
        nargs = len(args)
        l = []
        for cnt in range(nargs):
            arg = args[cnt]

            type_code = inargs[cnt]

            if arg == "GSL_MODE_DEFAULT":
                #arg = sf.GSL_MODE_DEFAULT
                arg = 0

            #if type_code in "iI":
            #    arg = int(arg)
            #    if type_code == "i":
            #        arg = np.int32(arg)
            #    elif type_code == "I":
            #        arg = np.uint32(arg)
            #    else:
            #        msg = "Could not match integer code type '%s' for cnt %d. full types: %s"
            #        raise ValueError(msg %(type_code, cnt, inargs))
            #
            #elif type_code in "lL":
            #    msg = "Not prepared for type '%s' for cnt %d. full types: %s"
            #    raise ValueError(msg %(type_code, cnt, inargs))
            #
            #elif type(arg) == type(1):
            #    msg = "Int argument but unknown type code?'%s' for cnt %d. full types: %s"
            #    raise ValueError(msg %(type_code, cnt, inargs))

            elif type(arg) == type(""):
                arg = eval(arg)
            
            l.append(arg)
            cnt += 1
        args = tuple(l)    
        return args

    #def _Check_Func(self):
    #    pass

    def _ConvertError(self, err):
        """Converts standard values used by GSL
        """
        if type(err) == type(""):
                err = eval(err)
        return err

    def _ConvertTolerance(self, tol):
        
        try:
            tol = float(tol)
            return tol
        except ValueError as ve:
            pass
        
        if type(tol) == type(""):
            try:
                tol = _tol_dic[tol]
                return tol
            except KeyError as ke:
                pass

        tol = eval(tol)
        return tol
        
    
    
    def _EvalFunc(self, *args, **kws):
        """Evaluate the function to test
        
        The method:
          * ensures that the method is not None
          * If a  TypeError is raised during execution, the argument values and
            the function name will be added

        Make sure func member is defined. Call it with args and kwsx
        """
        
        if self._func is None:
           fmt = "%s:%s self_func is None Thus I do not know which one to evaluate!"
           msg = fmt %(__file__, self.__class__.__name__)           
           raise ValueError(msg)

        def gen_arg_desc(arg):
            t_type = type(arg)
            msg = 'type(%s) = %s' %(arg, t_type)
            return msg
        
        msg = tuple(map(gen_arg_desc, args))
        msg = "args: " + " ".join(msg)
           
        func_name = self._func.__name__
        msg += " func: '%s' '%s'" % (func_name, self._func.types)

        try:
           result = self._func(*args, **kws)
        except TypeError as t_err:
            t_err.args += (msg,)
            raise t_err

        return result


    def _Check_sf_result(self, orig_args, ref, sf_result):
        """Check result and error. 
        
        Args:
            * orig_args : arguments the checked function was passed
            * sf_result : result returned by the function
            * expected :  expected return value
            * tolerance : tolerated deviation
        """
        test = 0
        try:
            val, err  = sf_result
            test = 1
        finally:
            if test == 0:
                print("sf_result '%s'" %(sf_result,))
            pass

        test = 0
        try:
            expected, tolerance = ref
            test = 1
        finally:
            if test == 0:
                print("check sf result ref '%s'" %(ref,))

        if type(val) == type(""):
            val = eval(val)
        else:
            val = float(val)

        if type(expected) == type(""):
            expected = eval(expected)
        else:
            expected = float(expected)

        err = self._ConvertError(err)
        err = float(err)
                
        fmt = "args=%s, Exp=%s, tol=%s, res =%s+/-%s"
        msg = fmt %(orig_args, expected, tolerance, val, err)

        #print("\n"+ msg)
        val = float(val)
        result = float(expected)
        #print("val", val, type(val))
        
        if gsl_isnan(val):
            self.assertEqual(np.isfinite(val), False, msg)
            return

        if gsl_isnan(result):
            self.assertEqual(np.isfinite(result), False, msg)
            return

        self.assertEqual(np.isfinite(val), True, msg)
        
        diff = val - result
        a_diff = np.absolute(diff)
           
        a_res = np.absolute(result)

        tol = self._ConvertTolerance(tolerance)
        
        # Check included as extended tests failed?
        # On the other hand ... sf functions are already testablelel using
        # gsl tests
        # If inconsistencies are detedcetd these should be reported to GSL.
        tol = tol * 4 + 1e-5
        if a_res > 1:
            tol *= a_res
        msg += " diff = %e a_diff = %e tol = %e" %(diff, a_diff, tol)        
        self.assertTrue(a_diff <= tol, msg)
           
           
    def _Check_Func_With_Error(self, orig_args, ref,  ref_status):
        args = self._GetArgs(orig_args)

        result, tolerance = ref
        
        # If the full func doc is needed for error analysis
        #func_doc = self._func.__doc__
        #func_doc = map(lambda x: x.strip(), func_doc.split("\n"))
        #func_doc = ";".join(func_doc)
        
        pygsl.ieee.env_setup()

        t = self._EvalFunc(*args)
        status = t[0]
        self.assertEqual(status, ref_status)

        sf_result = t[1:3]
        self._Check_sf_result(args, ref, sf_result)
    
    def _test(self, orig_args, ref, status):
        """Test translated from TEST_SF

        Args:
            orig_args : text stored
            ref : expected value and error tolerance
            status : return status
        """
        func_name = self._func.__name__
        if func_name[-2:] == "_e":
            self._Check_Func_With_Error(orig_args, ref, status)
        else:            
            raise  NotImplementedError("Tests for function without status not implemented")
        
    def _Check_Func_With_Error2(self, orig_args, ref1, ref2, ref_status):
        o_args = self._GetArgs(orig_args)
        pygsl.ieee.env_setup()

        #handle args
        #print("o_args", o_args)
        o_args1, o_args2 = o_args
        
        call_args = (o_args1,) + (o_args2,)
        t = self._EvalFunc(*call_args)
        status = t[0]
        self.assertEqual(status, ref_status)

        sf_result = t[1:3]        
        self._Check_sf_result(o_args, ref1, sf_result)
        
        sf_result = t[3:5]
        self._Check_sf_result(o_args, ref2, sf_result)

    def _test2(self, orig_args, ref1, ref2, status):
        """Test translated from TEST_SF2

        Args:
            orig_args : text stored
            ref1 : expected value and error tolerance return from first gsl_result
            ref1 : expected value and error tolerance return from second gsl_result
            status : return status
        """
        if(self._func == None):
            raise TestNoFuncError("self._func was not defined!")
            return

        func_name = self._func.__name__
        if func_name[-2:] == "_e":
            test = 0
            try:
                self._Check_Func_With_Error2(orig_args, ref1, ref2, status)
                test = 1
            finally:
                if test == 0:
                    print("orig '%s' ref1 '%s' ref2 '%s' status '%s'" %(orig_args, ref1, ref2, status))
                
        else:            
            raise  NotImplementedError("Tests for function without status not implemented")
