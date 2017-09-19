#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
Wrapper over the functions as described in Chapter 33 of the
reference manual.

Routines for approximating a data set with a non linear function

"""
import pygsl
from . import _callback
from .gsl_function import gsl_multifit_function_fdf, gsl_multifit_function
from ._generic_solver import _generic_solver

class _fsolver(_generic_solver):
    type = None
    _alloc     = _callback.gsl_multifit_fsolver_alloc  
    _free      = _callback.gsl_multifit_fsolver_free   
    _set       = _callback.gsl_multifit_fsolver_set    
    _name      = _callback.gsl_multifit_fsolver_name   
    _position  = _callback.gsl_multifit_fsolver_position
    _iterate   = _callback.gsl_multifit_fsolver_iterate
    _getx      = _callback.gsl_multifit_fsolver_getx
    _getdx      = _callback.gsl_multifit_fsolver_getdx
    _getf      = _callback.gsl_multifit_fsolver_getf

    def __init__(self, system, n, p):
        self._ptr = None
        assert(self._free != None)
        assert(self._alloc != None)
        assert(self._set != None)
        assert(self._name != None)
        assert(self._iterate != None)
        self._ptr = self._alloc(self.type, n, p)
        self._isset = 0
        self.system = system

    def set(self, x):
        f = self.system.get_ptr()
        self._set(self._ptr, f, x)
        self._isset = 1

    def position(self, x):
        f = self.system.get_ptr()
        self._position(self._ptr, f, x)
        self._isset = 1

    def getx(self):
        return self._getx(self._ptr)

    def getdx(self):
        return self._getdx(self._ptr)

    def getf(self):
        return self._getf(self._ptr)


        
class _fdfsolver(_fsolver):
    type = None
    _alloc     = _callback.gsl_multifit_fdfsolver_alloc  
    _free      = _callback.gsl_multifit_fdfsolver_free   
    _set       = _callback.gsl_multifit_fdfsolver_set    
    _name      = _callback.gsl_multifit_fdfsolver_name   
    _position  = _callback.gsl_multifit_fdfsolver_position
    _iterate   = _callback.gsl_multifit_fdfsolver_iterate
    _getx      = _callback.gsl_multifit_fdfsolver_getx
    _getdx     = _callback.gsl_multifit_fdfsolver_getdx
    _getf      = _callback.gsl_multifit_fdfsolver_getf
    _getJ      = _callback.gsl_multifit_fdfsolver_getJ

    def getJ(self):
        return self._getJ(self._ptr)

class lmder(_fdfsolver):
    r"""unscaled scaled Levenberg-Marquardt solver
    
    This is an unscaled version of the LMDER algorithm.  The elements
    of the diagonal scaling matrix D are set to 1.  This algorithm may
    be useful in circumstances where the scaled version of LMDER
    converges too slowly, or the function is already scaled
    appropriately.

    See also :c:type:`gsl_multifit_fdfsolver_lmder`
    """
    type = _callback.cvar.gsl_multifit_fdfsolver_lmder
    
class lmsder(_fdfsolver):
    r"""scaled Levenberg-Marquardt solver

    This is a robust and efficient version of the Levenberg-Marquardt
    algorithm as implemented in the scaled LMDER routine in MINPACK.
    Minpack was written by Jorge J. More', Burton S. Garbow and
    Kenneth E. Hillstrom.

    The algorithm uses a generalized trust region to keep each step
    under control.  In order to be accepted a proposed new position
    :math:`x'`
    must satisfy the condition :math:`|D (x' - x)| < \delta`, where D is a
    diagonal scaling matrix and \delta is the size of the trust
    region.  The components of D are computed internally, using the
    column norms of the Jacobian to estimate the sensitivity of the
    residual to each component of x.  This improves the behavior of the
    algorithm for badly scaled functions.

    On each iteration the algorithm attempts to minimize the linear
    system :math:`|F + J p|` subject to the constraint
    :math:`|D p| < \Delta`.  The
    solution to this constrained linear system is found using the
    Levenberg-Marquardt method.

    The proposed step is now tested by evaluating the function at the
    resulting point, :math:`x'`.  If the step reduces the norm of the function
    sufficiently, and follows the predicted behavior of the function
    within the trust region. then it is accepted and size of the trust
    region is increased.  If the proposed step fails to improve the
    solution, or differs significantly from the expected behavior
    within the trust region, then the size of the trust region is
    decreased and another trial step is computed.

    The algorithm also monitors the progress of the solution and
    returns an error if the changes in the solution are smaller than
    the machine precision.  The possible error codes are,

    `GSL_ETOLF'
          the decrease in the function falls below machine precision

    `GSL_ETOLX'
          the change in the position vector falls below machine

    `GSL_ETOLG'
          the norm of the gradient, relative to the norm of the
          function, falls below machine precision

    These error codes indicate that further iterations will be
    unlikely to change the solution from its current value.

    See also :c:type:`gsl_multifit_fdfsolver_lmsder`

    """
    type = _callback.cvar.gsl_multifit_fdfsolver_lmsder

_t_type = _callback.cvar.gsl_multifit_fdfsolver_lmniel
if _t_type:
    # Only available for GSL 2. or above
    class lmniel(_fdfsolver):
        r"""Levenberg-Marquardt solver

        This is a Levenberg-Marquardt solver based on a smoother updating procedure for
        the damping parameter mu proposed by Nielsen, 1999. It does not use a trust region
        approach and only performs rudimentary scaling and is therefore not as robust as
        lmsder. However, on each iteration it solves the normal equation system to compute
        the next step:
                                      
        .. math:: |(J^T   J + mu I) |  = - J^T   f
                               
        which makes it a much more practical method for problems with a large number of
        residuals :math:`(n >> p)`, since only the p-by-p matrix :math:`J^T J` is decomposed rather than the
        full n-by-p Jacobian. This makes a significant difference in efficiency when solving
        systems with large amounts of data. While not as robust as lmsder, this algorithm
        has proven effective on a wide class of problems.

        See also :c:type:`gsl_multifit_fdfsolver_lmniel`
        """
        type = _t_type
        

def test_delta(dx, x, epsabs, epsrel):
    r"""Test convergence

    This function tests for the convergence of the sequence by
    comparing the last step DX with the absolute error EPSABS and
    relative error EPSREL to the current position X.  The test returns
    `GSL_SUCCESS' if the following condition is achieved,

    .. math::     |dx_i| < epsabs + epsrel |x_i|

    for each component of X and returns `GSL_CONTINUE' otherwise.
    """
    return _callback.gsl_multifit_test_delta(dx, x, epsabs, epsrel)

def test_gradient(dx, epsabs):
    r"""residual gradient test
    
    This function tests the residual gradient G against the absolute
    error bound EPSABS.  Mathematically, the gradient should be
    exactly zero at the minimum. The test returns `GSL_SUCCESS' if the
    following condition is achieved,

    .. math::     \sum_i |g_i| < epsabs
         
    and returns `GSL_CONTINUE' otherwise.  This criterion is suitable
    for situations where the precise location of the minimum, x, is
    unimportant provided a value can be found where the gradient is
    small enough.
    """
    return _callback.gsl_multifit_test_gradient(dx, epsabs)

def gradient(J, f):
    r"""computes the gradient

    This function computes the gradient G of
    :math:`\Phi(x) = (1/2) ||F(x)||^2` from the Jacobian matrix J and the function values F,
    using the formula :math:`g = J^T f`.

    """
    return _callback.gsl_multifit_gradient(J, f)

def covar(J, epsrel):
    r"""compute the covariance matrix from the Jacobian J
    
    This function uses the Jacobian matrix J to compute the covariance
    matrix of the best-fit parameters, COVAR.  The parameter EPSREL is
    used to remove linear-dependent columns when J is rank deficient.
    
    The covariance matrix is given by,
    
    covar = :math:`(J^T J)^{-1}
    
    and is computed by QR decomposition of J with column-pivoting.  Any
    columns of R which satisfy
    
    .. math::      |R_{kk}| <= epsrel |R_{11}|

    are considered linearly-dependent and are excluded from the
    covariance matrix (the corresponding rows and columns of the
    covariance matrix are set to zero).

    Args: 
       J: Jacobian matrix
       epsrel  
    """
    return _callback.gsl_multifit_covar(J, epsrel)

#fsolver_driver = _callback.gsl_multifit_fsolver_driver
#fdfsolver_driver = _callback.gsl_multifit_fdfsolver_driver
