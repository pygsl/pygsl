#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
Wrapper over the functions as described in Chapter 32 of the
reference manual.

Routines for finding the minimum of a function of one variable.
Example: searching for pi using brent:



m = 2.0
a = 0.0
b = 6.0

def fn1(x, params):
    return cos(x) + 1.0

self.sys  = gsl_function(fn1, None)
minimizer = brent(self.sys)

minimizer.set(m, a, b)
t1 = fn1(a, None)
t2 = fn1(b, None)

print "Testing minimizer ", minimizer.name()
for iter in range(100):
    status = minimizer.iterate()
    a      = minimizer.x_lower()
    b      = minimizer.x_upper()
    m      = minimizer.minimum()
    status = minimize.test_interval(a, b, 0.001, 0)
    if status == 0:
        break

print "Minimum found at ", m

"""
import _callback

from gsl_function import gsl_function, gsl_function_fdf
from _generic_solver import _generic_solver

class _minsolver(_generic_solver):
    type = None
    _alloc   = _callback.gsl_min_fminimizer_alloc  
    _free    = _callback.gsl_min_fminimizer_free   
    _set     = _callback.gsl_min_fminimizer_set    
    _name    = _callback.gsl_min_fminimizer_name   
    _iterate = _callback.gsl_min_fminimizer_iterate

    def set(self, x, x_lower, x_upper):
        """
        This function sets, or resets, an existing minimizer S to use the
        function F and the initial search interval [X_LOWER, X_UPPER],
        with a guess for the location of the minimum X_MINIMUM.

        If the interval given does not contain a minimum, then the method
        raises an exception.

        input : x, x_lower, x_upper
            x        ... inital guess for x
            x_lower  ... the lower bound of the search interval
            x_upper  ... the upper bound of the search interval
        """
        f = self.system.get_ptr()
        _callback.gsl_min_fminimizer_set(self._ptr, f, x, x_lower, x_upper)
        self._isset = 1
        
    def set_with_values(self, x_m, x_lower, x_upper, f_m, f_lower, f_upper):
        """
        This method is equat to the set method but uses
        the values F_MINIMUM, F_LOWER and F_UPPER instead of computing
        them internaly.

        input : x, x_lower, x_upper, f_minimum, f_lower, f_upper
            x        ... inital guess for x
            x_lower  ... the lower bound of the search interval
            x_upper  ... the upper bound of the search interval
            f        ... f(x)
            f_lower  ... f(x_lower)
            f_upper  ... f(x_upper)

        """
        f = self.system.get_ptr()
        _callback.gsl_min_fminimizer_set_with_values(self._ptr, f,
                                                  x_m, x_lower, x_upper,
                                                  f_m, f_lower, f_upper)
        self._isset = 1
        
    def minimum(self):
        """
        Get the current estimation for the minimum
        """
        return _callback.gsl_min_fminimizer_minimum(self._ptr)
    
    def x_lower(self):
        """
        Get the lower bound
        """
        return _callback.gsl_min_fminimizer_x_lower(self._ptr)
    
    def x_upper(self):
        """
        Get the upper bound
        """                
        return _callback.gsl_min_fminimizer_x_upper(self._ptr)


    
class brent(_minsolver):
    """
    The "Brent minimization algorithm" combines a parabolic
    interpolation with the golden section algorithm.  This produces a
    fast algorithm which is still robust.
    
    The outline of the algorithm can be summarized as follows: on each
    iteration Brent's method approximates the function using an
    interpolating parabola through three existing points.  The minimum
    of the parabola is taken as a guess for the minimum.  If it lies
    within the bounds of the current interval then the interpolating
    point is accepted, and used to generate a smaller interval.  If
    the interpolating point is not accepted then the algorithm falls
    back to an ordinary golden section step.  The full details of
    Brent's method include some additional checks to improve
    convergence.
    """

    type = _callback.cvar.gsl_min_fminimizer_brent

class goldensection(_minsolver):
    """
    The "golden section algorithm" is the simplest method of bracketing
    the minimum of a function.  It is the slowest algorithm provided
    by the library, with linear convergence.

    On each iteration, the algorithm first compares the subintervals
    from the endpoints to the current minimum.  The larger subinterval
    is divided in a golden section (using the famous ratio (3-\sqrt
    5)/2 = 0.3189660...) and the value of the function at this new
    point is calculated.  The new value is used with the constraint
    f(a') > f(x') < f(b') to a select new interval containing the
    minimum, by discarding the least useful point.  This procedure can
    be continued indefinitely until the interval is sufficiently
    small.  Choosing the golden section as the bisection ratio can be
    shown to provide the fastest convergence for this type of
    algorithm.
    
    """

    type = _callback.cvar.gsl_min_fminimizer_goldensection



def test_interval(x_lower, x_upper, epsabs, epsrel):
    """
    This function tests for the convergence of the interval [X_LOWER,
     X_UPPER] with absolute error EPSABS and relative error EPSREL.
     The test returns `GSL_SUCCESS' if the following condition is
     achieved,

          |a - b| < epsabs + epsrel min(|a|,|b|)

     when the interval x = [a,b] does not include the origin.  If the
     interval includes the origin then \min(|a|,|b|) is replaced by
     zero (which is the minimum value of |x| over the interval).  This
     ensures that the relative error is accurately estimated for minima
     close to the origin.

     This condition on the interval also implies that any estimate of
     the minimum x_m in the interval satisfies the same condition with
     respect to the true minimum x_m^*,

          |x_m - x_m^*| < epsabs + epsrel x_m^*

     assuming that the true minimum x_m^* is contained within the
     interval.

     input : x_lower, x_upper, eps_abs, eps_rel
     """
    return _callback.gsl_min_test_interval(x_lower, x_upper, epsabs, epsrel)
