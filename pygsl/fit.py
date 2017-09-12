#!/usr/bin/env python
# Author : Pierre Schnizer <pierre.schnizer@helmholtz-berlin.de>
#  Date  : January 2003, 2017
"""

The functions described in this section can be used to perform
least-squares fits to a straight line model, 
.. math:: Y = c_0 + c_1 X.  

For
weighted data the best-fit is found by minimizing the weighted sum of
squared residuals, :math:`\chi^2`,

.. math::     \chi^2 = \sum_i w_i (y_i - (c_0 + c_1 x_i))^2

for the parameters c_0, c_1.  For unweighted data the sum is computed
with w_i = 1.
"""

from . import _callback

def linear(x, y):
    """Computes the best fit linear regression

    Args:
         x ... independent data
         y ... dependent data

    Returns:
           tuple: ((C0, C1), (COV00, COV01, COV11), sumsq)

    wrapper of the function  :c:func:`gsl_fit_linear`

    This function computes the best-fit linear regression coefficients
    (C0,C1) of the model Y = c_0 + c_1 X for the datasets (X, Y).  The
    variance-covariance matrix for the parameters (C0, C1) is
    estimated from the scatter of the points around the best-fit line
    and returned via the parameters (COV00, COV01, COV11).  The sum of
    squares of the residuals from the best-fit line is returned in
    SUMSQ.
    """
    return _callback.gsl_fit_linear(x,y)

def wlinear(x, y, w):
    """Weighted linear fit

    Args:
         x ... independent data
         y ... dependent data
         w ... weights for the dependent data

    Returns:
           tuple: ((C0, C1), (COV00, COV01, COV11), sumsq)


    wrapper of the function  :c:func:`gsl_fit_wlinear`

    This function computes the best-fit linear regression coefficients
    (C0,C1) of the model Y = c_0 + c_1 X for the weighted datasets (X,
    Y).  The vector W specifies the weight of
    each datapoint. The weight is the reciprocal of the variance for
    each datapoint in Y.

    The covariance matrix for the parameters (C0, C1) is estimated
    from weighted data and returned via the parameters (COV00, COV01,
    COV11).  The weighted sum of squares of the residuals from the
    best-fit line, \chi^2, is returned in CHISQ.
    """
    return _callback.gsl_fit_wlinear(x, y, w)

def est(x, c0, c1, c00, c01, c10):
    """return the estimation at point x

    Args:
         x:   independent data
         c0:  fit coefficient (intercept)
         c1:  fit coefficient (slope)
         c00: covariance - variance matrix coefficient
         c01: covariance - variance matrix coefficient
         c11: covariance - variance matrix coefficient

    Returns:
           double: y
           double: y_err


    wrapper of the function  :c:func:`gsl_fit_linear_est`

    This function uses the best-fit linear regression coefficients
     C0,C1 and their estimated covariance COV00,COV01,COV11 to compute
     the fitted function Y and its standard deviation Y_ERR for the
     model Y = c_0 + c_1 X at the point X.
    """
    return _callback.gsl_fit_linear_est(x, c0, c1, c00, c01, c10)

def mul(x,y):
    """compute best linear regression (without abszissa)

    Args:
         x: independent data
         y: dependent data

    Returns:
           tuple: (C1, COV11, sumsq)

    wrapper of the function  :c:func:`gsl_fit_mul`

    This function computes the best-fit linear regression coefficient
    C1 of the model Y = c_1 X for the datasets (X, Y).
    The variance of the
    parameter C1 is estimated from the scatter of the points around
    the best-fit line and returned via the parameter COV11.  The sum
    of squares of the residuals from the best-fit line is returned in
    SUMSQ.
    """
    return _callback.gsl_fit_mul(x,y)

def wmul(x, y, w):
    """compute weighted best linear regression (without abszissa)

    Args:
         x: independent data
         y: dependent data
         w: weights for the dependent data

    Returns:
           tuple: (C1, COV11, sumsq)


    wrapper of the function  :c:func:`gsl_fit_wmul`

    This function computes the best-fit linear regression coefficient
    C1 of the model Y = c_1 X for the weighted datasets (X, Y).
    The vector
    W, of length N and stride WSTRIDE, specifies the weight of each
    datapoint. The weight is the reciprocal of the variance for each
    datapoint in Y.

    The variance of the parameter C1 is estimated from the weighted
    data and returned via the parameters COV11.  The weighted sum of
    squares of the residuals from the best-fit line, \chi^2, is
    returned in CHISQ.
    """
    return _callback.gsl_fit_wmul(x, y, w)

def mul_est(x, c1, c11):
    """
    Args:
         x:   independent data
         c1:  fit coefficient (slope)
         c11: covariance - variance matrix coefficient

    Returns:
           y
           y_err

    wrapper of the function  :c:func:`gsl_fit_mul_est`

    This function uses the best-fit linear regression coefficient C1
    and its estimated covariance COV11 to compute the fitted function
    Y and its standard deviation Y_ERR for the model Y = c_1 X at the
    point X.
    """
    return _callback.gsl_fit_mul_est(x, c1, c11)

# def gsl_fit_poly(x, w, y):
#     return _callback.gsl_fit_poly(x, w, y)
# 
# def gsl_fit_fns(A, w, y):
#     return _callback.gsl_fit_fns(A, w, y)
# 
# def gsl_fit_linear_nd(m, y, w):
#     return _callback.gsl_fit_linear_nd(m, y, w)
