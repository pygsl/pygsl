# author: Achim Gaedke
# created: May 2001
# file: pygsl/errors.py
# $Id$
#
# Changes:
#       5. October 2003. Added various exceptions to cover the whole range of
#       error numbers. Needed to translate error numbers to the approbriate
#       exception. See Lib/error_helpers.c
import exceptions
import errno
import types

class gsl_Error(exceptions.Exception):
    """
    base of all gsl exceptions defined here
    """
    IsA = 'gsl_Error'
    errno = None
    pass


class gsl_Warning(exceptions.Warning):
    """
    base of all gsl warnings defined here
    """
    errno = None
    pass

class gsl_ArithmeticError(gsl_Error,exceptions.ArithmeticError):
    """
    base of all common arithmetic exceptions
    """
    pass

class gsl_RangeError(gsl_ArithmeticError):
    """
    output range error, e.g. exp(1e100)
    """
    errno = errno.GSL_ERANGE
    pass

class gsl_PointerError(gsl_Error):
    """
    invalid pointer 
    """
    errno = errno.GSL_EFAULT
    # Perhaps a lookup Error ???
    pass

class gsl_InvalidArgumentError(gsl_Error):
    """
    invalid argument supplied by user 
    """
    errno = errno.GSL_EINVAL
    pass

class gsl_GenericError(gsl_Error):
    """
    generic failure
    """
    errno = errno.GSL_EFAILED
    pass

class gsl_FactorizationError(gsl_Error):
    """
    factorization failed
    """
    errno = errno.GSL_EFACTOR
    pass

class gsl_SanityCheckError(gsl_Error):
    """
    sanity check failed - shouldn't happen
    """
    errno = errno.GSL_ESANITY
    pass

class gsl_BadFuncError(gsl_Error):
    """
    problem with user-supplied function
    """
    errno = errno.GSL_EBADFUNC
    pass

class gsl_RunAwayError(gsl_ArithmeticError):
    """
    iterative process is out of control
    """
    errno = errno.GSL_ERUNAWAY        
    pass

class gsl_MaximumIterationError(gsl_ArithmeticError):
    """
    exceeded max number of iterations
    """
    errno = errno.GSL_EMAXITER
    pass

class gsl_ZeroDivisionError(gsl_Error,exceptions.ZeroDivisionError):
    """
    """
    errno = errno.GSL_EZERODIV
    pass

class gsl_BadToleranceError(gsl_Error):
    """
    user specified an invalid tolerance
    """
    errno = errno.GSL_EBADTOL
    pass

class gsl_ToleranceError(gsl_ArithmeticError):
    """
    failed to reach the specified tolerance
    """
    errno = errno.GSL_ETOL
    pass

class gsl_UnderflowError(gsl_Error,exceptions.OverflowError):
    """
    """
    errno = errno.GSL_EUNDRFLW

    pass

class gsl_OverflowError(gsl_Error,exceptions.OverflowError):
    """
    """
    errno = errno.GSL_EOVRFLW
    pass



class gsl_AccuracyLossError(gsl_ArithmeticError):
    """
    failed to reach the specified tolerance
    """
    errno = errno.GSL_ELOSS
    pass

class gsl_RoundOffError(gsl_ArithmeticError):
    """
    failed because of roundoff error 
    """
    errno = errno.GSL_EROUND
    pass 

class gsl_BadLength(gsl_Error):
    """
    matrix; vector lengths are not conformant
    """
    errno = errno.GSL_EBADLEN
    pass

class gsl_MatrixNotSquare(gsl_Error):
    """
    matrix not square
    """
    errno = errno.GSL_ENOTSQR
    pass


class gsl_SingularityError(gsl_ArithmeticError):
    """
    apparent singularity detected
    """
    errno = errno.GSL_ESING

    pass

class gsl_DivergeError(gsl_ArithmeticError):
    """
    integral or series is divergent
    """
    errno = errno.GSL_EDIVERGE
    pass

class gsl_NoHardwareSupportError(gsl_Error):
    """
    requested feature is not supported by the hardware
    """
    errno = errno.GSL_EUNSUP
    pass

class gsl_NotImplementedError(gsl_Error, exceptions.NotImplementedError):
    """
    requested feature not (yet) implemented 
    """
    errno = errno.GSL_EUNIMPL

    pass

class gsl_CacheLimitError(gsl_Error):
    """
    cache limit exceeded
    """
    errno = errno.GSL_ECACHE

    pass

class gsl_TableLimitError(gsl_Error):
    """
    Table limit exceeded
    """
    errno = errno.GSL_ETABLE
    pass

class gsl_NoProgressError(gsl_ArithmeticError):
    """
    iteration is not making progress towards solution
    """
    errno = errno.GSL_ENOPROG

    pass

class gsl_JacobianEvaluationError(gsl_ArithmeticError):
    """
    jacobian evaluations are not improving the solution
    """
    errno = errno.GSL_ENOPROGJ

    pass


class gsl_ToleranceFError(gsl_ArithmeticError):
    """
    cannot reach the specified tolerance in F
    """
    errno = errno.GSL_ETOLF
    pass

class gsl_ToleranceXError(gsl_ArithmeticError):
    """
    cannot reach the specified tolerance in X
    """
    errno = errno.GSL_ETOLX
    pass

class gsl_ToleranceGradientError(gsl_ArithmeticError):
    """
    cannot reach the specified tolerance in gradient
    """
    errno = errno.GSL_ETOLG

    pass

class gsl_EOFError(gsl_Error, exceptions.EOFError):
    """
    end of file
    """
    errno = errno.GSL_EOF
    pass



class gsl_FloatingPointError(gsl_Error,exceptions.FloatingPointError):
    """
    """
    pass

class gsl_DomainWarning(gsl_Warning):
    """
    used by pygsl.histogram
    """
    errno = errno.GSL_EDOM


class gsl_DomainError(gsl_Error):
    """
    Domain Error. e.g. sqrt(-1)
    """
    errno = errno.GSL_EDOM

    pass


class pygsl_StrideError(gsl_SanityCheckError):
    """
    Could not recalculate a stride of a python array object to the stride
    of a gsl_vector or gsl_matrix.
    """
    errno = errno.PyGSL_ESTRIDE

    pass

class pygsl_NotImplementedError(gsl_Error, exceptions.NotImplementedError):
     """
     Base for all Errors, which are known but not implemented yet!
     """
     pass

def _get_exceptions(subclass):
    tmp = []
    globs = globals()
    for name in globs:
        i = globs[name]
        if type(i) != types.ClassType:
            continue
        if not issubclass(i, subclass):
            continue
        
        try:
            t = i.errno
        except AttributeError:
            continue

        if type(t) != types.IntType:
            continue
        
        int(t)
            
        tmp.append(i)
    return tmp

def get_exceptions():
    return _get_exceptions(gsl_Error)

def get_warnings():
    return _get_exceptions(gsl_Warning)
