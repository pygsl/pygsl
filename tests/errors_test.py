#!/usr/bin/env python
# Author : Pierre Schnizer <schnizer@users.sourceforge.net>
# Date   : 5. October 2003

import unittest
import pygsl
#pygsl.init.set_debug_level(10)
import pygsl.errortest
import pygsl.errors as errors

en = errors.errno

class _TestException(unittest.TestCase):
    errno = None
    exception = None
    def test0(self):
        assert(self.errno != None)
        assert(self.exception != None)
        self.assertRaises(self.exception, pygsl.errortest.trigger, self.errno)

    def test1(self):
        self.assertRaises(errors.gsl_Error, pygsl.errortest.trigger, self.errno)

#class Testgsl_Error                  (_TestException): errno = en.GSL_FAILURE  ; exception = errors.gsl_Error                  
class Testgsl_DomainError            (_TestException): errno = en.GSL_EDOM     ; exception = errors.gsl_DomainError            
class Testgsl_RangeError             (_TestException): errno = en.GSL_ERANGE   ; exception = errors.gsl_RangeError             
class Testgsl_PointerError           (_TestException): errno = en.GSL_EFAULT   ; exception = errors.gsl_PointerError           
class Testgsl_InvalidArgumentError   (_TestException): errno = en.GSL_EINVAL   ; exception = errors.gsl_InvalidArgumentError   
class Testgsl_GenericError           (_TestException): errno = en.GSL_EFAILED  ; exception = errors.gsl_GenericError           
class Testgsl_FactorizationError     (_TestException): errno = en.GSL_EFACTOR  ; exception = errors.gsl_FactorizationError     
class Testgsl_SanityCheckError       (_TestException): errno = en.GSL_ESANITY  ; exception = errors.gsl_SanityCheckError       
class Testgsl_BadFuncError           (_TestException): errno = en.GSL_EBADFUNC ; exception = errors.gsl_BadFuncError           
class Testgsl_RunAwayError           (_TestException): errno = en.GSL_ERUNAWAY ; exception = errors.gsl_RunAwayError           
class Testgsl_MaximumIterationError  (_TestException): errno = en.GSL_EMAXITER ; exception = errors.gsl_MaximumIterationError  
class Testgsl_ZeroDivisionError      (_TestException): errno = en.GSL_EZERODIV ; exception = errors.gsl_ZeroDivisionError      
class Testgsl_BadToleranceError      (_TestException): errno = en.GSL_EBADTOL  ; exception = errors.gsl_BadToleranceError      
class Testgsl_ToleranceError         (_TestException): errno = en.GSL_ETOL     ; exception = errors.gsl_ToleranceError         
class Testgsl_UnderflowError         (_TestException): errno = en.GSL_EUNDRFLW ; exception = errors.gsl_UnderflowError         
class Testgsl_OverflowError          (_TestException): errno = en.GSL_EOVRFLW  ; exception = errors.gsl_OverflowError          
class Testgsl_AccuracyLossError      (_TestException): errno = en.GSL_ELOSS    ; exception = errors.gsl_AccuracyLossError      
class Testgsl_RoundOffError          (_TestException): errno = en.GSL_EROUND   ; exception = errors.gsl_RoundOffError          
class Testgsl_BadLength              (_TestException): errno = en.GSL_EBADLEN  ; exception = errors.gsl_BadLength              
class Testgsl_MatrixNotSquare        (_TestException): errno = en.GSL_ENOTSQR  ; exception = errors.gsl_MatrixNotSquare        
class Testgsl_SingularityError       (_TestException): errno = en.GSL_ESING    ; exception = errors.gsl_SingularityError       
class Testgsl_DivergeError           (_TestException): errno = en.GSL_EDIVERGE ; exception = errors.gsl_DivergeError           
class Testgsl_NoHardwareSupportError (_TestException): errno = en.GSL_EUNSUP   ; exception = errors.gsl_NoHardwareSupportError 
class Testgsl_NotImplementedError    (_TestException): errno = en.GSL_EUNIMPL  ; exception = errors.gsl_NotImplementedError    
class Testgsl_CacheLimitError        (_TestException): errno = en.GSL_ECACHE   ; exception = errors.gsl_CacheLimitError        
class Testgsl_TableLimitError        (_TestException): errno = en.GSL_ETABLE   ; exception = errors.gsl_TableLimitError        
class Testgsl_NoProgressError        (_TestException): errno = en.GSL_ENOPROG  ; exception = errors.gsl_NoProgressError        
class Testgsl_JacobianEvaluationError(_TestException): errno = en.GSL_ENOPROGJ ; exception = errors.gsl_JacobianEvaluationError
class Testgsl_ToleranceFError        (_TestException): errno = en.GSL_ETOLF    ; exception = errors.gsl_ToleranceFError        
class Testgsl_ToleranceXError        (_TestException): errno = en.GSL_ETOLX    ; exception = errors.gsl_ToleranceXError        
class Testgsl_ToleranceGradientError (_TestException): errno = en.GSL_ETOLG    ; exception = errors.gsl_ToleranceGradientError 
class Testgsl_EOFError               (_TestException): errno = en.GSL_EOF      ; exception = errors.gsl_EOFError               
class Testpygsl_StrideError          (_TestException): errno = en.PyGSL_ESTRIDE; exception = errors.pygsl_StrideError               




del _TestException

if __name__ == '__main__':
    unittest.main()
