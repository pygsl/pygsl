#!/usr/bin/env python
"""
   The functions described in this section perform least-squares fits
to a general linear model, y = X c where y is a vector of n
observations, X is an n by p matrix of predictor variables, and c are
the p unknown best-fit parameters, which are to be estimated.

   The best-fit is found by minimizing the weighted sums of squared
residuals, \chi^2,

     \chi^2 = (y - X c)^T W (y - X c)

with respect to the parameters c. The weights are specified by the
diagonal elements of the n by n matrix W.  For unweighted data W is
replaced by the identity matrix.

   This formulation can be used for fits to any number of functions
and/or variables by preparing the n-by-p matrix X appropriately.  For
example, to fit to a p-th order polynomial in X, use the following
matrix,

     X_{ij} = x_i^j

where the index i runs over the observations and the index j runs from
0 to p-1.

   To fit to a set of p sinusoidal functions with fixed frequencies
\omega_1, \omega_2, ..., \omega_p, use,

     X_{ij} = sin(\omega_j x_i)

To fit to p independent variables x_1, x_2, ..., x_p, use,

     X_{ij} = x_j(i)

where x_j(i) is the i-th value of the predictor variable x_j.

   The functions described in this section are declared in the header
file `gsl_multifit.h'.

   The solution of the general linear least-squares system requires an
additional working space for intermediate results, such as the singular
value decomposition of the matrix X.

"""
# Author : Pierre Schnizer <pierre@itp.tu-graz.ac.at>
#  Date  : January 2003

import _callback
from _generic_solver import _workspace

class linear_workspace(_workspace):
    """
    Class handling the workspace required for fitting.

    """
    _alloc = _callback.gsl_multifit_linear_alloc
    _free  = _callback.gsl_multifit_linear_free
    
    def __init__(self, n, p):
        """
        Allocates a workspace for fitting a model to N
        observations using P parameters.

        input: N, P
            N ... number of samples
            P ... number of parameters
        """
        self._ptr = None
        assert(self._alloc != None)
        assert(self._free != None)
        self._ptr = self._alloc(n, p)

def linear(X, y, work=None):
    """
    This function computes the best-fit parameters C of the model y =
    X c for the observations Y and the matrix of predictor variables
    X.  The variance-covariance matrix of the model parameters COV is
    estimated from the scatter of the observations about the best-fit.
    The sum of squares of the residuals from the best-fit, \chi^2, is
    returned in CHISQ.
    
    The best-fit is found by singular value decomposition of the matrix
    X using the preallocated workspace provided in WORK. The modified
    Golub-Reinsch SVD algorithm is used, with column scaling to
    improve the accuracy of the singular values. Any components which
    have zero singular value (to machine precision) are discarded from
    the fit.

    If work is None, the approbriate workspace will be allocated
    automatically
    """
    if work == None:
        work = linear_workspace(X.shape[0], X.shape[1])
    return _callback.gsl_multifit_linear(X, y, work._ptr)

def linear_svd(X, y, tol, work=None):
    """
    """
    if work == None:
        work = linear_workspace(X.shape[0], X.shape[1])

    return _callback.gsl_multifit_linear_svd(X, y, tol, work._ptr)
    
def wlinear(X, w, y, work=None):
    """
    This function computes the best-fit parameters C of the model y =
    X c for the observations Y and the matrix of predictor variables
    X.  The covariance matrix of the model parameters COV is estimated
    from the weighted data.  The weighted sum of squares of the
    residuals from the best-fit, \chi^2, is returned in CHISQ.

    The best-fit is found by singular value decomposition of the matrix
    X using the preallocated workspace provided in WORK. Any
    components which have zero singular value (to machine precision)
    are discarded from the fit.

    If work is None, the approbriate workspace will be allocated
    automatically
    """
    if work == None:
        work = linear_workspace(X.shape[0], X.shape[1])

    return _callback.gsl_multifit_wlinear(X, w, y, work._ptr)

def wlinear_svd(X, y, w, work=None):
    """
    Similar to wlinear, except that this function returns
    
    """
    if work == None:
        work = linear_workspace(X.shape[0], X.shape[1])

    return _callback.gsl_multifit_wlinear(X, y, w, work._ptr)

def linear_est(x, c, cov):
    """
    This function uses the best-fit multilinear regression coefficients
    c and their covariance matrix cov to compute the fitted function
    value y and its standard deviation y_err for the model y = x.c at
    the point X.

    """
    return _callback.gsl_multifit_linear_est(x, c, cov)

def linear_est_matrix(X, c, cov):
    """
    This function is similar to linear_est, but instead of a vector x it iterates
    over a matrix X 
    """
    return _callback.gsl_multifit_linear_est_matrix(X, c, cov)
