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

class gsl_Error(exceptions.Exception):
    """
    base of all gsl exceptions defined here
    """
    IsA = 'gsl_Error'
    pass


class gsl_Warning(exceptions.Warning):
    """
    base of all gsl warnings defined here
    """
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
    pass

class gsl_PointerError(gsl_Error):
    """
    invalid pointer 
    """
    # Perhaps a lookup Error ???
    pass

class gsl_InvalidArgumentError(gsl_Error):
    """
    invalid argument supplied by user 
    """
    pass

class gsl_GenericError(gsl_Error):
    """
    generic failure
    """
    pass

class gsl_FactorizationError(gsl_Error):
    """
    factorization failed
    """
    pass

class gsl_SanityCheckError(gsl_Error):
    """
    sanity check failed - shouldn't happen
    """
    pass

class gsl_BadFuncError(gsl_Error):
    """
    problem with user-supplied function
    """
    pass

class gsl_RunAwayError(gsl_ArithmeticError):
    """
    iterative process is out of control
    """
    pass

class gsl_MaximumIterationError(gsl_ArithmeticError):
    """
    exceeded max number of iterations
    """
    pass

class gsl_ZeroDivisionError(gsl_Error,exceptions.ZeroDivisionError):
    """
    """
    pass

class gsl_BadToleranceError(gsl_Error):
    """
    user specified an invalid tolerance
    """
    pass

class gsl_ToleranceError(gsl_ArithmeticError):
    """
    failed to reach the specified tolerance
    """
    pass

class gsl_OverflowError(gsl_Error,exceptions.OverflowError):
    """
    """
    pass

class gsl_UnderflowError(gsl_Error,exceptions.OverflowError):
    """
    """
    pass


class gsl_AccuracyLossError(gsl_ArithmeticError):
    """
    failed to reach the specified tolerance
    """
    pass

class gsl_RoundOffError(gsl_ArithmeticError):
    """
    failed because of roundoff error 
    """
    pass 

class gsl_BadLength(gsl_Error):
    """
    matrix; vector lengths are not conformant
    """
    pass

class gsl_MatrixNotSquare(gsl_Error):
    """
    matrix not square
    """
    pass


class gsl_SingularityError(gsl_ArithmeticError):
    """
    apparent singularity detected
    """
    pass

class gsl_DivergeError(gsl_ArithmeticError):
    """
    integral or series is divergent
    """
    pass

class gsl_NoHardwareSupportError(gsl_Error):
    """
    requested feature is not supported by the hardware
    """
    pass

class gsl_NotImplementedError(gsl_Error, exceptions.NotImplementedError):
    """
    requested feature not (yet) implemented 
    """
    pass

class gsl_CacheLimitError(gsl_Error):
    """
    cache limit exceeded
    """
    pass

class gsl_TableLimitError(gsl_Error):
    """
    Table limit exceeded
    """
    pass

class gsl_NoProgressError(gsl_ArithmeticError):
    """
    iteration is not making progress towards solution
    """
    pass

class gsl_JacobianEvaluationError(gsl_ArithmeticError):
    """
    jacobian evaluations are not improving the solution
    """
    pass


class gsl_ToleranceFError(gsl_ArithmeticError):
    """
    cannot reach the specified tolerance in F
    """
    pass

class gsl_ToleranceXError(gsl_ArithmeticError):
    """
    cannot reach the specified tolerance in X
    """
    pass

class gsl_ToleranceGradientError(gsl_ArithmeticError):
    """
    cannot reach the specified tolerance in gradient
    """
    pass

class gsl_EOFError(gsl_Error, exceptions.EOFError):
    """
    end of file
    """
    pass



class gsl_FloatingPointError(gsl_Error,exceptions.FloatingPointError):
    """
    """
    pass

class gsl_DomainWarning(gsl_Warning):
    """
    used by pygsl.histogram
    """
    pass

class gsl_DomainError(gsl_Error):
    """
    Domain Error. e.g. sqrt(-1)
    """
    pass


class pygsl_NotImplementedError(gsl_Error, exceptions.NotImplementedError):
     """
     Base for all Errors, which are known but not implemented yet!
     """
     pass
