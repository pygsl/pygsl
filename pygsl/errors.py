# author: Achim Gaedke
# created: May 2001
# file: pygsl/errors.py
# $Id$

import exceptions

class gsl_Error(exceptions.Exception):
    """
    base of all exceptions defined here
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
