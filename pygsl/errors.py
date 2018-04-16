# authors: Achim Gaedke, Pierre Schnizer
# created: May 2001
# modified : August 2017
# file: pygsl/errors.py
# $Id:$
#
# Changes:
#       5. October 2003. Added various exceptions to cover the whole range of
#       error numbers. Needed to translate error numbers to the approbriate
#       exception. See Lib/error_helpers.c
"""Exceptions raised by pygsl

GSL error codes are translated to python exceptions. These exceptions are listed 
here. As far as appropriate the exceptions are derived from python exceptions.

The GSL error codes can be accessed from :mod:`pygsl.errno`
"""
import sys

if sys.version_info[0] < 3:
    import exceptions
    Exception = exceptions.Exception
    Warning = exceptions.Warning
    
import types
from pygsl import errno as errno_m

class gsl_Error(Exception):
    """base of all gsl exceptions
    """
    IsA = 'gsl_Error'
    errno = None
    pass


class gsl_Warning(Warning):
    """base of all gsl warnings
    """
    errno = None
    pass

class gsl_ArithmeticError(gsl_Error,ArithmeticError):
    """base of all common arithmetic exceptions
    """
    pass

class gsl_RangeError(gsl_ArithmeticError):
    """output range error, e.g. exp(1e100)
    """
    errno = errno_m.GSL_ERANGE
    """gsl error number :data:`pygsl.errno.GSL_ERANGE`"""

    pass

class gsl_PointerError(gsl_Error):
    """invalid pointer

    This error is typically raised if GSL is checking a pointer and 
    that pointer is NULL.
    """
    errno = errno_m.GSL_EFAULT
    """gsl error number :data:`pygsl.errno.GSL_EFAULT`"""
    pass

class gsl_InvalidArgumentError(gsl_Error):
    """invalid argument supplied by user
    """
    errno = errno_m.GSL_EINVAL
    """gsl error number :data:`pygsl.errno.GSL_EINVAL`"""
    pass

class gsl_GenericError(gsl_Error):
    """generic failure
    """
    errno = errno_m.GSL_EFAILED
    """gsl error number :data:`pygsl.errno.GSL_EFAILED`"""
    pass

class gsl_FactorizationError(gsl_Error):
    """factorization failed
    """
    errno = errno_m.GSL_EFACTOR
    """gsl error number :data:`pygsl.errno.GSL_EFACTOR`"""
    pass

class gsl_SanityCheckError(gsl_Error):
    """sanity check failed - shouldn't happen
    """
    errno = errno_m.GSL_ESANITY
    """gsl error number :data:`pygsl.errno.GSL_ESANITY`"""
    pass

class gsl_BadFuncError(gsl_Error):
    """problem with user-supplied function
    """
    errno = errno_m.GSL_EBADFUNC
    """gsl error number :data:`pygsl.errno.GSL_EBADFUNC`"""
    pass

class gsl_RunAwayError(gsl_ArithmeticError):
    """iterative process is out of control
    """
    errno = errno_m.GSL_ERUNAWAY        
    """gsl error number :data:`pygsl.errno.GSL_ERUNAWAY`"""
    pass

class gsl_MaximumIterationError(gsl_ArithmeticError):
    """exceeded max number of iterations
    """
    errno = errno_m.GSL_EMAXITER
    """gsl error number :data:`pygsl.errno.GSL_EMAXITER`"""
    pass

class gsl_ZeroDivisionError(gsl_Error,ZeroDivisionError):
    """zero Division Error
    """
    errno = errno_m.GSL_EZERODIV
    """gsl error number :data:`pygsl.errno.GSL_EZERODIV`"""
    pass

class gsl_BadToleranceError(gsl_Error):
    """user specified an invalid tolerance
    """
    errno = errno_m.GSL_EBADTOL
    """gsl error number :data:`pygsl.errno.GSL_EBADTOL`"""
    pass

class gsl_ToleranceError(gsl_ArithmeticError):
    """failed to reach the specified tolerance
    """
    errno = errno_m.GSL_ETOL
    """gsl error number :data:`pygsl.errno.GSL_ETOL`"""
    pass

class gsl_UnderflowError(gsl_Error,OverflowError):
    """Underflow error
    """
    errno = errno_m.GSL_EUNDRFLW
    """gsl error number :data:`pygsl.errno.GSL_EUNDRFLW`"""

    pass

class gsl_OverflowError(gsl_Error,OverflowError):
    """Overflow Error
    """
    errno = errno_m.GSL_EOVRFLW
    """gsl error number :data:`pygsl.errno.GSL_EOVERFLW`"""
    pass



class gsl_AccuracyLossError(gsl_ArithmeticError):
    """failed to reach the specified tolerance
    """
    errno = errno_m.GSL_ELOSS
    """gsl error number :data:`pygsl.errno.GSL_ELOSS`"""
    pass

class gsl_RoundOffError(gsl_ArithmeticError):
    """failed because of roundoff error 
    """
    errno = errno_m.GSL_EROUND
    """gsl error number :data:`pygsl.errno.GSL_EFOUND`"""
    pass 

class gsl_BadLength(gsl_Error):
    """matrix; vector lengths are not conformant
    """
    errno = errno_m.GSL_EBADLEN
    """gsl error number :data:`pygsl.errno.GSL_EBADLEN`"""
    pass

class gsl_MatrixNotSquare(gsl_Error):
    """matrix not square
    """
    errno = errno_m.GSL_ENOTSQR
    """gsl error number :data:`pygsl.errno.GSL_ENOTSQR`"""
    pass


class gsl_SingularityError(gsl_ArithmeticError):
    """apparent singularity detected
    """
    errno = errno_m.GSL_ESING
    """gsl error number :data:`pygsl.errno.GSL_ESING`"""

    pass

class gsl_DivergeError(gsl_ArithmeticError):
    """integral or series is divergent
    """
    errno = errno_m.GSL_EDIVERGE
    """gsl error number :data:`pygsl.errno.GSL_EDIVERGE`"""
    pass

class gsl_NoHardwareSupportError(gsl_Error):
    """requested feature is not supported by the hardware
    """
    errno = errno_m.GSL_EUNSUP
    """gsl error number :data:`pygsl.errno.GSL_EUNSUP`"""
    pass

class gsl_NotImplementedError(gsl_Error, NotImplementedError):
    """requested feature not (yet) implemented 
    """
    errno = errno_m.GSL_EUNIMPL
    """gsl error number :data:`pygsl.errno.GSL_EUNIMPL`"""

    pass

class gsl_CacheLimitError(gsl_Error):
    """cache limit exceeded
    """
    errno = errno_m.GSL_ECACHE
    """gsl error number :data:`pygsl.errno.GSL_ECACHE`"""

    pass

class gsl_TableLimitError(gsl_Error):
    """Table limit exceeded
    """
    errno = errno_m.GSL_ETABLE
    """gsl error number :data:`pygsl.errno.GSL_ETABLE`"""
    pass

class gsl_NoProgressError(gsl_ArithmeticError):
    """iteration is not making progress towards solution
    """
    errno = errno_m.GSL_ENOPROG
    """gsl error number :data:`pygsl.errno.GSL_ENOPROG`"""

    pass

class gsl_JacobianEvaluationError(gsl_ArithmeticError):
    """jacobian evaluations are not improving the solution
    """
    errno = errno_m.GSL_ENOPROGJ
    """gsl error number :data:`pygsl.errno.GSL_ENOPROGJ`"""

    pass


class gsl_ToleranceFError(gsl_ArithmeticError):
    """cannot reach the specified tolerance in F
    """
    errno = errno_m.GSL_ETOLF
    """gsl error number :data:`pygsl.errno.GSL_ETOLF`"""
    pass

class gsl_ToleranceXError(gsl_ArithmeticError):
    """cannot reach the specified tolerance in X
    """
    errno = errno_m.GSL_ETOLX
    """gsl error number :data:`pygsl.errno.GSL_ETOLX`"""
    pass

class gsl_ToleranceGradientError(gsl_ArithmeticError):
    """cannot reach the specified tolerance in gradient
    """
    errno = errno_m.GSL_ETOLG
    """gsl error number :data:`pygsl.errno.GSL_ETOLG`"""

    pass

class gsl_EOFError(gsl_Error, EOFError):
    """end of file
    """
    errno = errno_m.GSL_EOF
    """gsl error number :data:`pygsl.errno.GSL_EOF`"""
    pass



class gsl_FloatingPointError(gsl_Error,FloatingPointError):
    """base of all common floating point errors
    """
    pass

class gsl_DomainWarning(gsl_Warning):
    """used by pygsl.histogram
    """
    errno = errno_m.GSL_EDOM
    """error number :data:`pygsl.errno.GSL_EDOM`"""


class gsl_DomainError(gsl_Error):
    """Domain Error. e.g. sqrt(-1)
    """
    errno = errno_m.GSL_EDOM
    """gsl error number :data:`pygsl.errno.GSL_EDOM`"""

    pass


class pygsl_StrideError(gsl_SanityCheckError):
    """Could not recalculate a stride of a python array object to the stride
    of a gsl_vector or gsl_matrix.
    """
    errno = errno_m.PyGSL_ESTRIDE
    """pygsl error number :data:`pygsl.errno.PyGSL_ESTRIDE`"""

    pass


class pygsl_NotImplementedError(gsl_NotImplementedError):
     """Base for all Errors, which are known but not implemented yet!
     """
     errno = errno_m.PyGSL_EUNIMPL
     """pygsl error number :data:`pygsl.errno.PyGSL_EUNIMPL`"""
     pass

class pygsl_NotInitalised(gsl_SanityCheckError):
    """gsl_error calls a c callback, which saves the reason, file name, line number
    and the GSL errno.

    This errno is stored when the save state is initalised and flags that
    gsl_error was not yet called.
    """
    errno = errno_m.PyGSL_EINIT
    """pygsl error number :data:`pygsl.errno.PyGSL_EINIT`"""
    pass

_not_exported_exceptions = (
    gsl_Error,
    gsl_Warning,
    gsl_FloatingPointError,
    gsl_ArithmeticError,
)

def _get_exceptions(subclass):
    tmp = []
    globs = globals()
    for name in globs:
        the_exception = globs[name]

        if the_exception in _not_exported_exceptions:
            continue
            
        try:
            if not issubclass(the_exception, subclass):
                continue
        except TypeError:
            continue
        try:
            t_errno = the_exception.errno
        except AttributeError:
            continue

        assert(t_errno != None)

        int(t_errno)
            
        tmp.append(the_exception)
    return tmp

def get_exceptions():
    """Returns the exceptions defined within this module

    Used by the :mod:`pygsl.init` module. This is used by the C helper functions
    to turn an error reported by gsl by the C error code to the appropriate
    python exception
    """
    return _get_exceptions(gsl_Error)

def get_warnings():
    """Returns the warnings defined within this module

    Used by the :mod:`pygsl.init` module. This is used by the C helper functions
    to turn an error reported by gsl by the C error code to the appropriate
    python warning
    """
    return _get_exceptions(gsl_Warning)

class _ErrorSafeState:
    """Access to the last error stored by gsl

If PyGSL does not set gsl_error handler to off, the installed error
handler will store the arguments passed by gsl_error_handler to a single static 
variable in :mod:`pygsl.init`. This variable is exported to python space
by this class.

If pygsl raises an exception, this state here should be automatically reset.

Used gsl functions:
    * :c:func:`gsl_set_error_handler_off()`
    * :c:func:`gsl_set_error_handler()`
""" 

    def get(self):
        "Get the currently stored variables"
        from pygsl import init
        tmp = init.error_handler_state_get()
        dic = {'reason' : tmp[0], 'file' : tmp[1], 'line' : tmp[2], 'errno' : tmp[3]}
        return dic

    def reset(self):
        "Reset the state"
        from pygsl import init
        return init.error_handler_state_reset()

    @property
    def reason(self):
        dic = self.get()
        return dic["reason"]

    @property
    def file(self):
        dic = self.get()
        return dic["file"]

    @property
    def line(self):
        dic = self.get()
        return dic["line"]

    @property
    def errno(self):
        dic = self.get()
        return dic["errno"]

error_safe_state = _ErrorSafeState()
#"""Access to the last error stored by gsl
#
#If PyGSL does not set gsl_error handler to off, the installed error
#handler will store the arguments passed by gsl_error_handler to a single static 
#variable in :mod:`pygsl.init`. This variable is exported to python space
#by this class.
#
#If pygsl raises an exception, this state here should be automatically reset.
#
#Used gsl functions:
#    * :c:func:`gsl_set_error_handler_off()`
#    * :c:func:`gsl_set_error_handler()`
#""" 
