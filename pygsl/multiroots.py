#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
Wrapper over the functions as described in Chapter 33 of the
reference manual.

Routines for finding the root of a function depending on more than one
variable.

"""
import _callback
from gsl_function import gsl_multiroot_function_fdf, gsl_multiroot_function
from _generic_solver import _generic_solver

class _fsolver(_generic_solver):
    type = None
    _alloc   = _callback.gsl_multiroot_fsolver_alloc  
    _free    = _callback.gsl_multiroot_fsolver_free   
    _set     = _callback.gsl_multiroot_fsolver_set    
    _name    = _callback.gsl_multiroot_fsolver_name   
    _iterate = _callback.gsl_multiroot_fsolver_iterate
    _root    = _callback.gsl_multiroot_fsolver_root
    _getx    = _callback.gsl_multiroot_function_getx
    _getf    = _callback.gsl_multiroot_function_getf
    def __init__(self, system, size):
        self._ptr = None
        assert(self._free != None)
        assert(self._alloc != None)
        assert(self._set != None)
        assert(self._name != None)
        assert(self._iterate != None)
        self._ptr = self._alloc(self.type, size)
        self._isset = 0
        self.system = system

    def root(self):
        """
        Get the current root estimate
        """
        return self._root(self._ptr)

    def set(self, x):
        """
        Set the initial start guess x
        """
        f = self.system.get_ptr()
        self._set(self._ptr, f, x)
        self._isset = 1

    def getx(self):
        """
        Get the value of x
        """
        return self._getx(self._ptr)
    
    def getf(self):
        """
        Get the value of f
        """
        return self._getf(self._ptr)
    
class _fdfsolver(_fsolver):
    type = None
    _alloc   = _callback.gsl_multiroot_fdfsolver_alloc  
    _free    = _callback.gsl_multiroot_fdfsolver_free   
    _set     = _callback.gsl_multiroot_fdfsolver_set    
    _name    = _callback.gsl_multiroot_fdfsolver_name   
    _iterate = _callback.gsl_multiroot_fdfsolver_iterate
    _root    = _callback.gsl_multiroot_fdfsolver_root
    _getx    = _callback.gsl_multiroot_function_fdf_getx
    _getf    = _callback.gsl_multiroot_function_fdf_getf


def test_delta(dx, x, epsabs, epsrel):
    """
    This function tests for the convergence of the sequence by
     comparing the last step DX with the absolute error EPSABS and
     relative error EPSREL to the current position X.  The test returns
     `GSL_SUCCESS' if the following condition is achieved,

          |dx_i| < epsabs + epsrel |x_i|

     for each component of X and returns `GSL_CONTINUE' otherwise.

     input : dx, x, epsabs, epsrel
    """
    return _callback.gsl_multiroot_test_delta(dx, x, epsabs, epsrel)

def test_residual(f, epsabs):
    """
    This function tests the residual value F against the absolute
     error bound EPSABS.  The test returns `GSL_SUCCESS' if the
     following condition is achieved,

          \sum_i |f_i| < epsabs

     and returns `GSL_CONTINUE' otherwise.  This criterion is suitable
     for situations where the precise location of the root, x, is
     unimportant provided a value can be found where the residual is
     small enough.

     input : f, epsabs
     """
    return _callback.gsl_multiroot_test_residual(f, epsabs)

class dnewton(_fsolver):
    """
    The "discrete Newton algorithm" is the simplest method of solving a
     multidimensional system.  It uses the Newton iteration

          x -> x - J^{-1} f(x)

     where the Jacobian matrix J is approximated by taking finite
     differences of the function F.  The approximation scheme used by
     this implementation is,

          J_{ij} = (f_i(x + \delta_j) - f_i(x)) /  \delta_j

     where \delta_j is a step of size \sqrt\epsilon |x_j| with \epsilon
     being the machine precision (\epsilon \approx 2.22 \times 10^-16).
     The order of convergence of Newton's algorithm is quadratic, but
     the finite differences require n^2 function evaluations on each
     iteration.  The algorithm may become unstable if the finite
     differences are not a good approximation to the true derivatives.

    """
    type = _callback.cvar.gsl_multiroot_fsolver_dnewton
    
class broyden(_fsolver):
    """
    The "Broyden algorithm" is a version of the discrete Newton
     algorithm which attempts to avoids the expensive update of the
     Jacobian matrix on each iteration.  The changes to the Jacobian
     are also approximated, using a rank-1 update,

          J^{-1} \to J^{-1} - (J^{-1} df - dx) dx^T J^{-1} / dx^T J^{-1} df

     where the vectors dx and df are the changes in x and f.  On the
     first iteration the inverse Jacobian is estimated using finite
     differences, as in the discrete Newton algorithm.

     This approximation gives a fast update but is unreliable if the
     changes are not small, and the estimate of the inverse Jacobian
     becomes worse as time passes.  The algorithm has a tendency to
     become unstable unless it starts close to the root.  The Jacobian
     is refreshed if this instability is detected (consult the source
     for details).

     This algorithm is not recommended and is included only for
     demonstration purposes.

    """
    type = _callback.cvar.gsl_multiroot_fsolver_broyden
    
class hybrid(_fsolver):
    """
    This is a finite difference version of the Hybrid algorithm without
    internal scaling.
    """
    type = _callback.cvar.gsl_multiroot_fsolver_hybrid
    
class hybrids(_fsolver):
    """
     This is a version of the Hybrid algorithm which replaces calls to
     the Jacobian function by its finite difference approximation.  The
     finite difference approximation is computed using
     `gsl_multiroots_fdjac' with a relative step size of
     `GSL_SQRT_DBL_EPSILON'.
     """
    type = _callback.cvar.gsl_multiroot_fsolver_hybrids

    
class newton(_fdfsolver):
    """
    Newton's Method is the standard root-polishing algorithm.  The
     algorithm begins with an initial guess for the location of the
     solution.  On each iteration a linear approximation to the
     function F is used to estimate the step which will zero all the
     components of the residual.  The iteration is defined by the
     following sequence,

          x -> x' = x - J^{-1} f(x)

     where the Jacobian matrix J is computed from the derivative
     functions provided by F.  The step dx is obtained by solving the
     linear system,

          J dx = - f(x)

     using LU decomposition.

    """
    type = _callback.cvar.gsl_multiroot_fdfsolver_newton
    
class gnewton(_fdfsolver):
    """
        This is a modified version of Newton's method which attempts to
     improve global convergence by requiring every step to reduce the
     Euclidean norm of the residual, |f(x)|.  If the Newton step leads
     to an increase in the norm then a reduced step of relative size,

          t = (\sqrt(1 + 6 r) - 1) / (3 r)

     is proposed, with r being the ratio of norms |f(x')|^2/|f(x)|^2.
     This procedure is repeated until a suitable step size is found.

    """
    type = _callback.cvar.gsl_multiroot_fdfsolver_gnewton
    
class hybridj(_fdfsolver):
    """
    This algorithm is an unscaled version of `hybridsj'.  The steps are
     controlled by a spherical trust region |x' - x| < \delta, instead
     of a generalized region.  This can be useful if the generalized
     region estimated by `hybridsj' is inappropriate.

    """
    type = _callback.cvar.gsl_multiroot_fdfsolver_hybridj
    
class hybridsj(_fdfsolver):
    """
        This is a modified version of Powell's Hybrid method as
     implemented in the HYBRJ algorithm in MINPACK.  Minpack was
     written by Jorge J. More', Burton S. Garbow and Kenneth E.
     Hillstrom.  The Hybrid algorithm retains the fast convergence of
     Newton's method but will also reduce the residual when Newton's
     method is unreliable.

     The algorithm uses a generalized trust region to keep each step
     under control.  In order to be accepted a proposed new position x'
     must satisfy the condition |D (x' - x)| < \delta, where D is a
     diagonal scaling matrix and \delta is the size of the trust
     region.  The components of D are computed internally, using the
     column norms of the Jacobian to estimate the sensitivity of the
     residual to each component of x.  This improves the behavior of the
     algorithm for badly scaled functions.

     On each iteration the algorithm first determines the standard
     Newton step by solving the system J dx = - f.  If this step falls
     inside the trust region it is used as a trial step in the next
     stage.  If not, the algorithm uses the linear combination of the
     Newton and gradient directions which is predicted to minimize the
     norm of the function while staying inside the trust region.

          dx = - \alpha J^{-1} f(x) - \beta \nabla |f(x)|^2

     This combination of Newton and gradient directions is referred to
     as a "dogleg step".

     The proposed step is now tested by evaluating the function at the
     resulting point, x'.  If the step reduces the norm of the function
     sufficiently then it is accepted and size of the trust region is
     increased.  If the proposed step fails to improve the solution
     then the size of the trust region is decreased and another trial
     step is computed.

     The speed of the algorithm is increased by computing the changes
     to the Jacobian approximately, using a rank-1 update.  If two
     successive attempts fail to reduce the residual then the full
     Jacobian is recomputed.  The algorithm also monitors the progress
     of the solution and returns an error if several steps fail to make
     any improvement,

   `GSL_ENOPROG'
          the iteration is not making any progress, preventing the
          algorithm from continuing.

    `GSL_ENOPROGJ'
          re-evaluations of the Jacobian indicate that the iteration is
          not making any progress, preventing the algorithm from
          continuing.

    """
    type = _callback.cvar.gsl_multiroot_fdfsolver_hybridsj
