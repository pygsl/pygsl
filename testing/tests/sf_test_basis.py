#!/usr/bin/env python
from __future__ import print_function
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
from pygsl import errno

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

class _test_sf_automatic(unittest.TestCase):
    _func = None
    def _GetArgs(self, args):
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

    def _EvalFunc(self, args):
        return result

    def _Check_Func_With_Error(self, orig_args, result, tolerance):
        args = self._GetArgs(orig_args)

        def gen_arg_desc(arg):
            t_type = type(arg)
            msg = 'type(%s) = %s' %(arg, t_type)
            return msg
        
        msg = tuple(map(gen_arg_desc, args))
        msg = "args: " + " ".join(msg)
        func_name = self._func.__name__

        # If the full func doc is needed for error analysis
        #func_doc = self._func.__doc__
        #func_doc = map(lambda x: x.strip(), func_doc.split("\n"))
        #func_doc = ";".join(func_doc)
        
        msg += " func: '%s' '%s'" % (func_name, self._func.types)

        pygsl.ieee.env_setup()
        try:
            t = self._func(*args)
        except TypeError as t_err:
            t_err.args += (msg,)
            raise t_err
            
        val = t[0]
        err = t[1]

        val = float(val)
        err = float(err)

        msg = "args = '%s'. Exp '%s' tol '%s' res = '%s'+/-'%s'" %(orig_args, result, tolerance, val, err)
        if gsl_isnan(val):
            self.assertEqual(np.isfinite(val), False, msg)
            return

        if gsl_isnan(result):
            self.assertEqual(np.isfinite(result), False, msg)
            return

            

        self.assertEqual(np.isfinite(val), True, msg)

        diff = val - result
        a_diff = np.absolute(diff)
        tol = tolerance

        a_res = np.absolute(result)
        tol = tolerance * 4 + 1e-5
        if a_res > 1:
            tol *= a_res
        msg += " diff = %e a_diff = %e tol = %e" %(diff, a_diff, tol)        
        self.assertTrue(a_diff <= tol, msg)

    def _Check_Func(self):
        raise ValueError("not implemented")
    
    def _test(self, args, result, tolerance, status):
        if(self._func == None):
            return

        func_name = self._func.__name__
        if func_name[-2:] == "_e":
            self._Check_Func_With_Error(args, result, tolerance)
        else:            
            self._Check_Func()
