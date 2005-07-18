#!/usr/bin/env python
"""
Wrapper over the functions as described in Chapter 33 of the
reference manual.

Routines for finding the minimum of a function depending on more than one
variable.

"""
import _callback
from gsl_function import gsl_multimin_function_fdf, gsl_multimin_function
from _generic_solver import _generic_solver

class _fsolver(_generic_solver):
    type = None
    _alloc   = _callback.gsl_multimin_fminimizer_alloc  
    _free    = _callback.gsl_multimin_fminimizer_free   
    _set     = _callback.gsl_multimin_fminimizer_set    
    _name    = _callback.gsl_multimin_fminimizer_name   
    _iterate = _callback.gsl_multimin_fminimizer_iterate
    _minimum = _callback.gsl_multimin_fminimizer_minimum
    _size    = _callback.gsl_multimin_fminimizer_size
    _getx    = _callback.gsl_multimin_fminimizer_x
    _getf    = _callback.gsl_multimin_fminimizer_f

    
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

    def set(self, x, step_size):
        """
        This function initializes the minimizer to minimize the function
        starting from the initial point x. The size of the initial
        trial steps is given in vector STEP_SIZE. The precise meaning of
        this parameter depends on the method used.
        """
        f = self.system.get_ptr()
        self._set(self._ptr, f, x, step_size)
        self._isset = 1

    def minimum(self):
        """
        Get the current minimum
        """
        return self._minimum(self._ptr)

    def size(self):
        """
        Get the characteristic size
        """
        return self._size(self._ptr)
    

    def getx(self):
        """
        Get the current x value
        """
        return self._getx(self._ptr)

    def getf(self):
        """
        Get the current function value
        """
        return self._getf(self._ptr)
    


class _fdfsolver(_fsolver):
    type = None
    _alloc   = _callback.gsl_multimin_fdfminimizer_alloc  
    _free    = _callback.gsl_multimin_fdfminimizer_free   
    _set     = _callback.gsl_multimin_fdfminimizer_set    
    _name    = _callback.gsl_multimin_fdfminimizer_name   
    _iterate = _callback.gsl_multimin_fdfminimizer_iterate
    _minimum = _callback.gsl_multimin_fdfminimizer_minimum
    _gradient= _callback.gsl_multimin_fdfminimizer_gradient
    _getx    = _callback.gsl_multimin_fdfminimizer_x
    _getf    = _callback.gsl_multimin_fdfminimizer_f
    _restart = _callback.gsl_multimin_fdfminimizer_restart

    def gradient(self):
        """
        Get the last gradient
        """
        return self._gradient(self._ptr)

    def restart(self):
        """
        Restart the iteration at the current point
        """
        return self._restart(self._ptr)

    def set(self, x, step_size, tolerance):
        """
        This function initializes the minimizer S to minimize the function
        FDF starting from the initial point X.  The size of the first
        trial step is given by STEP_SIZE.  The accuracy of the line
        minimization is specified by TOL.  The precise meaning of this
        parameter depends on the method used.  Typically the line
        minimization is considered successful if the gradient of the
        function g is orthogonal to the current search direction p to a
        relative accuracy of TOL, where dot(p,g) < tol |p| |g|.

        """
        f = self.system.get_ptr()
        self._set(self._ptr, f, x, step_size, tolerance)
        self._isset = 1

class steepest_descent(_fdfsolver):
    """
    The steepest descent algorithm follows the downhill gradient of the
     function at each step. When a downhill step is successful the
     step-size is increased by factor of two.  If the downhill step
     leads to a higher function value then the algorithm backtracks and
     the step size is decreased using the parameter TOL.  A suitable
     value of TOL for most applications is 0.1.  The steepest descent
     method is inefficient and is included only for demonstration
     purposes.

    """
    type = _callback.cvar.gsl_multimin_fdfminimizer_steepest_descent
    
class conjugate_pr(_fdfsolver):
    """
    This is the Polak-Ribiere conjugate gradient algorithm.  It is
     similar to the Fletcher-Reeves method, differing only in the
     choice of the coefficient \beta. Both methods work well when the
     evaluation point is close enough to the minimum of the objective
     function that it is well approximated by a quadratic hypersurface.
    """
    type = _callback.cvar.gsl_multimin_fdfminimizer_conjugate_pr
    
class conjugate_fr(_fdfsolver):
    """
     This is the Fletcher-Reeves conjugate gradient algorithm. The
     conjugate gradient algorithm proceeds as a succession of line
     minimizations. The sequence of search directions is used to build
     up an approximation to the curvature of the function in the
     neighborhood of the minimum.  An initial search direction P is
     chosen using the gradient and line minimization is carried out in
     that direction.  The accuracy of the line minimization is
     specified by the parameter TOL.  At the minimum along this line
     the function gradient G and the search direction P are orthogonal.
     The line minimization terminates when dot(p,g) < tol |p| |g|.  The
     search direction is updated  using the Fletcher-Reeves formula p'
     = g' - \beta g where \beta=-|g'|^2/|g|^2, and the line
     minimization is then repeated for the new search direction.

    """
    type = _callback.cvar.gsl_multimin_fdfminimizer_conjugate_fr
    
class vector_bfgs(_fdfsolver):
    """
    This is the vector Broyden-Fletcher-Goldfarb-Shanno (BFGS)
     conjugate gradient algorithm.  It is a quasi-Newton method which
     builds up an approximation to the second derivatives of the
     function f using the difference between successive gradient
     vectors.  By combining the first and second derivatives the
     algorithm is able to take Newton-type steps towards the function
     minimum, assuming quadratic behavior in that region.

    """
    type = _callback.cvar.gsl_multimin_fdfminimizer_vector_bfgs    



class nmsimplex(_fsolver):
    """
     This is the Simplex algorithm by Nelder and Mead. It constructs n
     vectors p_i from the starting vector X as follows:

     that form the n+1 vertices of a simplex in n dimensions.  In each
     iteration step the algorithm tries to improve the parameter vector
     p_i corresponding to the highest, i. e.  worst, function value by
     simple geometrical transformations.  These are reflection,
     reflection followed by expansion, contraction and multiple
     contraction. Using these transformations the simplex moves through
     the parameter space towards the minimum, where it contracts itself.

     After each iteration, the best vertex is returned.  Note, that due
     to the nature of the algorithm (getting rid of the worst
     estimate), every iteration doesn't necessarily improve the current
     best parameter vector.  Usually several iterations are required.

     The routine calculates the minimizer specific characteristic size
     as the average distance from the geometrical center of the simplex
     to all its vertices.  This size can be used as a stopping
     criteria, as the simplex contracts itself near the minimum. The
     size is returned by the function `gsl_multimin_fminimizer_size'.
     """
    type = _callback.cvar.gsl_multimin_fminimizer_nmsimplex
    
def test_gradient(g, epsabs):
    """
    This function tests the norm of the gradient  against the
    absolute tolerance epsabs. The gradient of a multidimensional
    function goes to zero at a minimum. The test returns `GSL_SUCCESS'
    if the following condition is achieved,

          |g| < epsabs

    and returns `GSL_CONTINUE' otherwise.  A suitable choice of EPSABS
    can be made from the desired accuracy in the function for small
    variations in x.  The relationship between these quantities is
    given by \delta f = g \delta x.
    """
    return _callback.gsl_multimin_test_gradient(g, epsabs)


def test_size(gradient, tolerance):
    """
    This function tests the minimizer specific characteristic size (if
    applicable to the used minimizer) against the absolute tolerance.
    """
    return _callback.gsl_multimin_test_size(gradient, tolerance)








