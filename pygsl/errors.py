# author: Achim Gaedke
# created: May 2001
# file: pygsl/errors.py
# $Id$

import exceptions

class gsl_Error(exceptions.Exception):
    """
    base of all gsl exceptions defined here
    """
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

class gsl_OverflowError(gsl_Error,exceptions.OverflowError):
    """
    """
    pass

class gsl_ZeroDivisionError(gsl_Error,exceptions.ZeroDivisionError):
    """
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
