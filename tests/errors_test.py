#!/usr/bin/env python
# Author : Pierre Schnizer <schnizer@users.sourceforge.net>
# Date   : 5. October 2003, 2017, 2018

import unittest
import pygsl
#pygsl.init.set_debug_level(10)
from pygsl import errortest, errors, errno

en = errno

#: only use for testing if the hnadler can be switched off

class TestInstalledHandler(unittest.TestCase):
    def test_handler(self):
        "Test that the installeed hander is the save state "
        self.assertEqual(errortest.set_gsl_error_handler_val, 1)

    def test_gslstrerror(self):
        "Test that gsl_strerror is part of the errortestmodule"
        t_errno = 0
        txt = errortest.gsl_strerror(t_errno)
        self.assertEqual(txt, "success")

class _TestException(unittest.TestCase):
    errno = None
    exception = None

    #: currently assumed to be an invalid code. Thus should not be set before ..
    invalid_test_code = en.PyGSL_EUNIMPL
    def _checkExceptionMsg(self, t_exp_save):
        # Now: No exception was raised or the approbriate one_bunch
        self.assertFalse(t_exp_save is None)

        self.assertEqual(self.errno, t_exp_save.errno)
        self.assertEqual(len( t_exp_save.args), 1)

        txt, = t_exp_save.args
        gsl_txt = errortest.gsl_strerror(self.errno)
        expected = gsl_txt + ": " + self.message_token
        self.assertEqual(txt, expected)

    def test0(self):
        """Test that the appropriate exception is raised
        """
        assert(self.errno != None)
        assert(self.exception != None)
        self.assertRaises(self.exception, errortest.trigger, self.errno)

    def test1(self):
        """Test that the exception raised is derived from gsl_Error
        thus by :c:func:`pygsl_error()`
        """
        self.assertRaises(errors.gsl_Error, errortest.trigger, self.errno)

    def test2(self):
        """Test that the approbriate exception is raised by trigger_gsl and
        thus by :c:func:`gsl_error()`
        """
        self.assertRaises(errors.gsl_Error, errortest.trigger_gsl, self.errno)


    def test3(self):
        """Test that the text can be stored and retrieved
        """
        self.message_token = "The answer to everything"
        errortest.trigger_save_test(self.errno, self.message_token)

        state = errors.error_safe_state

        self.assertEqual(state.errno, self.errno)
        self.assertEqual(state.reason, self.message_token)

    def test4(self):
        """Test that the saved state can be reset
        """
        self.message_token = "The right question to ask"
        errortest.trigger_save_test(self.errno, self.message_token)

        state = errors.error_safe_state

        self.assertEqual(state.errno, self.errno)
        self.assertEqual(state.reason, self.message_token)

        state.reset()
        self.assertEqual(state.errno, errno.PyGSL_EINIT)
        self.assertEqual(state.reason, "no message stored since error save state was reset")

class _TestExceptionGSL(_TestException):
    """Collection of tests which do not work if non GSL error codes are used
    """
    def test5(self):
        """Test that the appropriate text is returned
        """
        self.message_token = "Lore Ipsum"
        t_exp_save = None

        # Clean start condition
        errors.error_safe_state.reset()

        try:
            errortest.trigger_gsl(self.errno, self.message_token)
        except self.exception as t_exp:
            t_exp_save = t_exp
        self._checkExceptionMsg(t_exp_save)

    def test6(self):
        """Test that the appropriate text is returned saving code and restoring afterwards
        """
        self.message_token = "karkulka"
        t_exp_save = None

        # Clean start condition
        errors.error_safe_state.reset()

        errortest.trigger_save_test(self.errno, self.message_token)
        try:
            errortest.PyGSL_error_flag(self.errno)
        except self.exception as t_exp:
            t_exp_save = t_exp
            
        self._checkExceptionMsg(t_exp_save)

    def test7(self):
        """Test that the appropriate text is appended with a question mark if the error code changes
        """
        test_token = "karkulka"
        self.message_token =  test_token + " ?"
        t_exp_save = None

        # Clean start condition
        errors.error_safe_state.reset()

        errortest.trigger_save_test(self.errno, test_token)

        test_code = en.PyGSL_EUNIMPL
        self.errno = test_code        
        try:
            errortest.PyGSL_error_flag(test_code)
        except errors.pygsl_NotImplementedError  as t_exp:
            t_exp_save = t_exp
            
        self._checkExceptionMsg(t_exp_save)
        
#class Testgsl_Error                  (_TestException): errno = en.GSL_FAILURE  ; exception = errors.gsl_Error                  
class Testgsl_DomainError            (_TestExceptionGSL): errno = en.GSL_EDOM     ; exception = errors.gsl_DomainError            
class Testgsl_RangeError             (_TestExceptionGSL): errno = en.GSL_ERANGE   ; exception = errors.gsl_RangeError             
class Testgsl_PointerError           (_TestExceptionGSL): errno = en.GSL_EFAULT   ; exception = errors.gsl_PointerError           
class Testgsl_InvalidArgumentError   (_TestExceptionGSL): errno = en.GSL_EINVAL   ; exception = errors.gsl_InvalidArgumentError   
class Testgsl_GenericError           (_TestExceptionGSL): errno = en.GSL_EFAILED  ; exception = errors.gsl_GenericError           
class Testgsl_FactorizationError     (_TestExceptionGSL): errno = en.GSL_EFACTOR  ; exception = errors.gsl_FactorizationError     
class Testgsl_SanityCheckError       (_TestExceptionGSL): errno = en.GSL_ESANITY  ; exception = errors.gsl_SanityCheckError       
class Testgsl_BadFuncError           (_TestExceptionGSL): errno = en.GSL_EBADFUNC ; exception = errors.gsl_BadFuncError           
class Testgsl_RunAwayError           (_TestExceptionGSL): errno = en.GSL_ERUNAWAY ; exception = errors.gsl_RunAwayError           
class Testgsl_MaximumIterationError  (_TestExceptionGSL): errno = en.GSL_EMAXITER ; exception = errors.gsl_MaximumIterationError  
class Testgsl_ZeroDivisionError      (_TestExceptionGSL): errno = en.GSL_EZERODIV ; exception = errors.gsl_ZeroDivisionError      
class Testgsl_BadToleranceError      (_TestExceptionGSL): errno = en.GSL_EBADTOL  ; exception = errors.gsl_BadToleranceError      
class Testgsl_ToleranceError         (_TestExceptionGSL): errno = en.GSL_ETOL     ; exception = errors.gsl_ToleranceError         
class Testgsl_UnderflowError         (_TestExceptionGSL): errno = en.GSL_EUNDRFLW ; exception = errors.gsl_UnderflowError         
class Testgsl_OverflowError          (_TestExceptionGSL): errno = en.GSL_EOVRFLW  ; exception = errors.gsl_OverflowError          
class Testgsl_AccuracyLossError      (_TestExceptionGSL): errno = en.GSL_ELOSS    ; exception = errors.gsl_AccuracyLossError      
class Testgsl_RoundOffError          (_TestExceptionGSL): errno = en.GSL_EROUND   ; exception = errors.gsl_RoundOffError          
class Testgsl_BadLength              (_TestExceptionGSL): errno = en.GSL_EBADLEN  ; exception = errors.gsl_BadLength              
class Testgsl_MatrixNotSquare        (_TestExceptionGSL): errno = en.GSL_ENOTSQR  ; exception = errors.gsl_MatrixNotSquare        
class Testgsl_SingularityError       (_TestExceptionGSL): errno = en.GSL_ESING    ; exception = errors.gsl_SingularityError       
class Testgsl_DivergeError           (_TestExceptionGSL): errno = en.GSL_EDIVERGE ; exception = errors.gsl_DivergeError           
class Testgsl_NoHardwareSupportError (_TestExceptionGSL): errno = en.GSL_EUNSUP   ; exception = errors.gsl_NoHardwareSupportError 
class Testgsl_NotImplementedError    (_TestExceptionGSL): errno = en.GSL_EUNIMPL  ; exception = errors.gsl_NotImplementedError    
class Testgsl_CacheLimitError        (_TestExceptionGSL): errno = en.GSL_ECACHE   ; exception = errors.gsl_CacheLimitError        
class Testgsl_TableLimitError        (_TestExceptionGSL): errno = en.GSL_ETABLE   ; exception = errors.gsl_TableLimitError        
class Testgsl_NoProgressError        (_TestExceptionGSL): errno = en.GSL_ENOPROG  ; exception = errors.gsl_NoProgressError        
class Testgsl_JacobianEvaluationError(_TestExceptionGSL): errno = en.GSL_ENOPROGJ ; exception = errors.gsl_JacobianEvaluationError
class Testgsl_ToleranceFError        (_TestExceptionGSL): errno = en.GSL_ETOLF    ; exception = errors.gsl_ToleranceFError        
class Testgsl_ToleranceXError        (_TestExceptionGSL): errno = en.GSL_ETOLX    ; exception = errors.gsl_ToleranceXError        
class Testgsl_ToleranceGradientError (_TestExceptionGSL): errno = en.GSL_ETOLG    ; exception = errors.gsl_ToleranceGradientError 
class Testgsl_EOFError               (_TestExceptionGSL): errno = en.GSL_EOF      ; exception = errors.gsl_EOFError               
class Testpygsl_StrideError          (_TestException):   errno = en.PyGSL_ESTRIDE; exception = errors.pygsl_StrideError

class TestErrorMsg(_TestException):
    """Test if the text of gsl_error() is returnd when the error code is a 
    gsl error code
    """

    errno = en.GSL_EFAILED
    exception = errors.gsl_GenericError

    #: currently assumed to be an invalid code. Thus should not be set before ..
    invalid_test_code = en.PyGSL_EUNIMPL

        
    def test100(self):
        #errortest.select_error_handler(0)
        pass

del _TestException, _TestExceptionGSL

if __name__ == '__main__':
    unittest.main()
