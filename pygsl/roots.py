#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
Wrapper over the functions as described in Chapter 31 of the
reference manual.

Routines for finding the root of a function of one variable.

Example: searching the root of a quadratic using brent:

def quadratic(x, params):
    a = params[0]
    b = params[1]
    c = params[2]
    return  a * x ** 2 + b * x + c

a = 1.0
b = 0.0
c = -5.0
sys = gsl_function(quadratic, (a,b,c))
solver = brent(sys)
while 1:
            iter += 1
            status = solver.iterate()
            x_lo = solver.x_lower()
            x_up = solver.x_upper()
            status = roots.test_interval(x_lo, x_up, 0, 0.001)
            r = solver.root()
            if status == 0:
                break
print "Root Found =", root

"""
import _callback

from gsl_function import gsl_function_fdf, gsl_function
from _generic_solver import _generic_solver

class _fsolver(_generic_solver):
    type = None
    _alloc   = _callback.gsl_root_fsolver_alloc  
    _free    = _callback.gsl_root_fsolver_free   
    _set     = _callback.gsl_root_fsolver_set    
    _name    = _callback.gsl_root_fsolver_name   
    _iterate = _callback.gsl_root_fsolver_iterate
    _root    = _callback.gsl_root_fsolver_root


    def set(self, x_lower, x_upper):
        """
        Set the bondary for the solver.
        input : x_lower, x_upper
            x_lower : the lower bound
            x_upper : the upper bound
        """
        f = self.system.get_ptr()
        self._set(self._ptr, f, x_lower, x_upper)
        self._isset = 1

    def root(self):
        """
        Get the actual guess for the root
        """
        return self._root(self._ptr)
    
    def x_lower(self):
        """
        Get the lower bound of the actual interval
        """
        return _callback.gsl_root_fsolver_x_lower(self._ptr)

    def x_upper(self):
        """
        Get the upper bound of the actual interval
        """
        return _callback.gsl_root_fsolver_x_upper(self._ptr)

    
class _fdfsolver(_fsolver):    
    type = None
    _alloc   = _callback.gsl_root_fdfsolver_alloc  
    _free    = _callback.gsl_root_fdfsolver_free   
    _set     = _callback.gsl_root_fdfsolver_set    
    _name    = _callback.gsl_root_fdfsolver_name   
    _iterate = _callback.gsl_root_fdfsolver_iterate
    _root    = _callback.gsl_root_fdfsolver_root


    def set(self, x):
        """
        Set the initial start guess  for the solver.
        input : x
            x : start value
        """
        f = self.system.get_ptr()
        self._set(self._ptr, f, x)
        self._isset = 1
        
def test_interval(x_lower, x_upper, eps_abs, eps_rel):
    """
     This function tests for the convergence of the interval [X_LOWER,
     X_UPPER] with absolute error EPSABS and relative error EPSREL.
     The test returns `GSL_SUCCESS' if the following condition is
     achieved,

          |a - b| < epsabs + epsrel min(|a|,|b|)

     when the interval x = [a,b] does not include the origin.  If the
     interval includes the origin then \min(|a|,|b|) is replaced by
     zero (which is the minimum value of |x| over the interval).  This
     ensures that the relative error is accurately estimated for roots
     close to the origin.

     This condition on the interval also implies that any estimate of
     the root r in the interval satisfies the same condition with
     respect to the true root r^*,

          |r - r^*| < epsabs + epsrel r^*

     assuming that the true root r^* is contained within the interval.

     input : x_lower, x_upper, eps_abs, eps_rel
    """
    return _callback.gsl_root_test_interval(x_lower, x_upper, eps_abs, eps_rel)

def test_delta(x_lower, x_upper, eps_abs, eps_rel):
    """
    his function tests the residual value F against the absolute
     error bound EPSABS.  The test returns `GSL_SUCCESS' if the
     following condition is achieved,

          |f| < epsabs

     and returns `GSL_CONTINUE' otherwise.  This criterion is suitable
     for situations where the precise location of the root, x, is
     unimportant provided a value can be found where the residual,
     |f(x)|, is small enough.
     
     input : x_lower, x_upper, eps_abs, eps_rel
    """
    return _callback.gsl_root_test_delta(x_lower, x_upper, eps_abs, eps_rel)


class bisection(_fsolver):
    """
    The "bisection algorithm" is the simplest method of bracketing the
     roots of a function.   It is the slowest algorithm provided by the
     library, with linear convergence.

     On each iteration, the interval is bisected and the value of the
     function at the midpoint is calculated.  The sign of this value is
     used to determine which half of the interval does not contain a
     root.  That half is discarded to give a new, smaller interval
     containing the root.  This procedure can be continued indefinitely
     until the interval is sufficiently small.

     At any time the current estimate of the root is taken as the
     midpoint of the interval.

    """
    type = _callback.cvar.gsl_root_fsolver_bisection

    
class brent(_fsolver):
    """
    The "Brent-Dekker method" (referred to here as "Brent's method")
     combines an interpolation strategy with the bisection algorithm.
     This produces a fast algorithm which is still robust.

     On each iteration Brent's method approximates the function using an
     interpolating curve.  On the first iteration this is a linear
     interpolation of the two endpoints.  For subsequent iterations the
     algorithm uses an inverse quadratic fit to the last three points,
     for higher accuracy.  The intercept of the interpolating curve
     with the x-axis is taken as a guess for the root.  If it lies
     within the bounds of the current interval then the interpolating
     point is accepted, and used to generate a smaller interval.  If
     the interpolating point is not accepted then the algorithm falls
     back to an ordinary bisection step.

     The best estimate of the root is taken from the most recent
     interpolation or bisection.

    """
    type = _callback.cvar.gsl_root_fsolver_brent
    
class falsepos(_fsolver):
    """
     The "false position algorithm" is a method of finding roots based
     on linear interpolation.  Its convergence is linear, but it is
     usually faster than bisection.

     On each iteration a line is drawn between the endpoints (a,f(a))
     and (b,f(b)) and the point where this line crosses the x-axis
     taken as a "midpoint".  The value of the function at this point is
     calculated and its sign is used to determine which side of the
     interval does not contain a root.  That side is discarded to give a
     new, smaller interval containing the root.  This procedure can be
     continued indefinitely until the interval is sufficiently small.

     The best estimate of the root is taken from the linear
     interpolation of the interval on the current iteration.

    """
    type = _callback.cvar.gsl_root_fsolver_falsepos
    
class newton(_fdfsolver):
    """
    Newton's Method is the standard root-polishing algorithm.  The
    algorithm begins with an initial guess for the location of the
    root.  On each iteration, a line tangent to the function f is
    drawn at that position.  The point where this line crosses the
    x-axis becomes the new guess.  The iteration is defined by the
    following sequence,
    
               x_{i+1} = x_i - f(x_i)/f'(x_i)
    
    Newton's method converges quadratically for single roots, and
    linearly for multiple roots.
    """
    type = _callback.cvar.gsl_root_fdfsolver_newton

class secant(_fdfsolver):
    """
    The "secant method" is a simplified version of Newton's method does
     not require the computation of the derivative on every step.

     On its first iteration the algorithm begins with Newton's method,
     using the derivative to compute a first step,

          x_1 = x_0 - f(x_0)/f'(x_0)

     Subsequent iterations avoid the evaluation of the derivative by
     replacing it with a numerical estimate, the slope through the
     previous two points,

          x_{i+1} = x_i f(x_i) / f'_{est} where
           f'_{est} = (f(x_i) - f(x_{i-1})/(x_i - x_{i-1})

     When the derivative does not change significantly in the vicinity
     of the root the secant method gives a useful saving.
     Asymptotically the secant method is faster than Newton's method
     whenever the cost of evaluating the derivative is more than 0.44
     times the cost of evaluating the function itself.  As with all
     methods of computing a numerical derivative the estimate can
     suffer from cancellation errors if the separation of the points
     becomes too small.

     On single roots, the method has a convergence of order (1 + \sqrt
     5)/2 (approximately 1.62).  It converges linearly for multiple
     roots.

    """
    type = _callback.cvar.gsl_root_fdfsolver_secant

    
class steffenson(_fdfsolver):
    """
    The "Steffenson Method" provides the fastest convergence of all the
     routines.  It combines the basic Newton algorithm with an Aitken
     "delta-squared" acceleration.  If the Newton iterates are x_i then
     the acceleration procedure generates a new sequence R_i,

          R_i = x_i - (x_{i+1} - x_i)^2 / (x_{i+2} - 2 x_{i+1} + x_{i})

     which converges faster than the original sequence under reasonable
     conditions.  The new sequence requires three terms before it can
     produce its first value so the method returns accelerated values
     on the second and subsequent iterations.  On the first iteration
     it returns the ordinary Newton estimate.  The Newton iterate is
     also returned if the denominator of the acceleration term ever
     becomes zero.

     As with all acceleration procedures this method can become
     unstable if the function is not well-behaved.

    """
    type = _callback.cvar.gsl_root_fdfsolver_steffenson

