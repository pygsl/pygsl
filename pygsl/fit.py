#!/usr/bin/env python
# Author : Pierre Schnizer <pierre@itp.tu-graz.ac.at>
#  Date  : January 2003
"""
   The functions described in this section can be used to perform
least-squares fits to a straight line model, Y = c_0 + c_1 X.  For
weighted data the best-fit is found by minimizing the weighted sum of
squared residuals, \chi^2,

     \chi^2 = \sum_i w_i (y_i - (c_0 + c_1 x_i))^2

for the parameters c_0, c_1.  For unweighted data the sum is computed
with w_i = 1.
"""

import _callback

def linear(x, y):
    """
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
    """
    This function computes the best-fit linear regression coefficients
     (C0,C1) of the model Y = c_0 + c_1 X for the weighted datasets (X,
     Y).  The
     vector W specifies the weight of
     each datapoint. The weight is the reciprocal of the variance for
     each datapoint in Y.

     The covariance matrix for the parameters (C0, C1) is estimated
     from weighted data and returned via the parameters (COV00, COV01,
     COV11).  The weighted sum of squares of the residuals from the
     best-fit line, \chi^2, is returned in CHISQ.
    """
    return _callback.gsl_fit_wlinear(x, y, w)

def est(x, c0, c1, c00, c01, c10):
    """
    This function uses the best-fit linear regression coefficients
     C0,C1 and their estimated covariance COV00,COV01,COV11 to compute
     the fitted function Y and its standard deviation Y_ERR for the
     model Y = c_0 + c_1 X at the point X.
    """
    return _callback.gsl_fit_linear_est(x, c0, c1, c00, c01, c10)

def mul(x,y):
    """
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
    """
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
