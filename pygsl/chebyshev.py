#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
This module describes routines for computing Chebyshev
approximations to univariate functions.  A Chebyshev approximation is a
truncation of the series \M{f(x) = S{sum} c_n T_n(x)}, where the Chebyshev
polynomials \M{T_n(x) = cos(n \arccos x)} provide an orthogonal basis of
polynomials on the interval [-1,1] with the weight function
\M{1 / sqrt{1-x^2}}.  The first few Chebyshev polynomials are, T_0(x) = 1,
T_1(x) = x, T_2(x) = 2 x^2 - 1.

def f(x, p):
    if x < 0.5:
        return 0.25
    else:
        return 0.75

     
n = 10000;

cs = cheb_series(40)
F = gsl_function(f, None)
cs.init(F, 0.0, 1.0)

nf = float(n)
for i in range(100):
    x = i / nf
    r10 = cs.eval_n(10, x)
    r40 = cs.eval(x)
    print "%g %g %g %g" % (x, f(x, None), r10, r40)
"""
import _callback

from  _generic_solver import _workspace
from gsl_function import gsl_function

class cheb_series(_workspace):
    """
    This class manages all internal detail. It provides the space for a
    Chebyshev series of order N.

    """
    _alloc    = _callback.gsl_cheb_alloc
    _free     = _callback.gsl_cheb_free
    _init     = _callback.gsl_cheb_init
    _eval     = _callback.gsl_cheb_eval
    _eval_err = _callback.gsl_cheb_eval_err
    _eval_n   = _callback.gsl_cheb_eval_n
    _eval_n_err = _callback.gsl_cheb_eval_n_err
    #_eval_mode   = _callback.gsl_cheb_eval_mode
    #_eval_mode_e   = _callback.gsl_cheb_eval_mode_e
    _calc_deriv   = _callback.gsl_cheb_calc_deriv
    _calc_integ   = _callback.gsl_cheb_calc_integ
    _get_coeff = _callback.pygsl_cheb_get_coefficients
    _set_coeff = _callback.pygsl_cheb_set_coefficients
    _get_a = _callback.pygsl_cheb_get_a
    _set_a = _callback.pygsl_cheb_set_a
    _get_b = _callback.pygsl_cheb_get_b
    _set_b = _callback.pygsl_cheb_set_b
    _get_f = _callback.pygsl_cheb_get_f
    _set_f = _callback.pygsl_cheb_set_f
    _get_order_sp = _callback.pygsl_cheb_get_order_sp
    _set_order_sp = _callback.pygsl_cheb_set_order_sp

    def __init__(self, size):
        """
        input : n
        @params n : number of coefficients
        """
        self._size = size
        _workspace.__init__(self, size)
        
    def init(self, f, a, b):
        """
        This function computes the Chebyshev approximation for the
        function F over the range (a,b) to the previously specified order.
        The computation of the Chebyshev approximation is an \M{O(n^2)}
        process, and requires n function evaluations.

        input : f, a, b
        @params  f : a gsl_function
        @params  a : lower limit
        @params  b : upper limit
        """
        return self._init(self._ptr, f.get_ptr(), a, b)

    def eval(self, x):
        """
        This function evaluates the Chebyshev series CS at a given point X

        input : x
             x ... value where the series shall be evaluated.
        """
        return self._eval(self._ptr, x)

    def eval_err(self, x):
        """
         This function computes the Chebyshev series  at a given point X,
         estimating both the series RESULT and its absolute error ABSERR.
         The error estimate is made from the first neglected term in the
         series.
         
         input : x
             x ... value where the error shall be evaluated.
        """
        return self._eval_err(self._ptr, x)

    def eval_n(self, order, x):
        """
         This function evaluates the Chebyshev series CS at a given point
         N, to (at most) the given order ORDER.

        input : n, x
             n ... number of cooefficients
             x ... value where the series shall be evaluated.
         
        """
        return self._eval_n(self._ptr, order, x)

    def eval_n_err(self, order, x):
        """
        This function evaluates a Chebyshev series CS at a given point X,
        estimating both the series RESULT and its absolute error ABSERR,
        to (at most) the given order ORDER.  The error estimate is made
        from the first neglected term in the series.

        input : n, x
             n ... number of cooefficients
             x ... value where the error shall be evaluated.

        """
        return self._eval_n_err(self._ptr, order, x)

#    def eval_mode(self, x, mode):
#        """
#        
#        """
#        return self._eval(self._ptr, x, mode)
#
#    def eval_mode_e(self, x, mode):
#        return self._eval(self._ptr, x, mode)

    def calc_deriv(self):
        """
        This method computes the derivative of the series CS. It returns
        a new instance of the cheb_series class.
        """
        tmp = cheb_series(self._size)
        self._calc_deriv(tmp._ptr, self._ptr)
        return tmp

    def calc_integ(self):
        """
        This method computes the integral of the series CS. It returns
        a new instance of the cheb_series class.

        """
        tmp = cheb_series(self._size)
        self._calc_integ(tmp._ptr, self._ptr)
        return tmp

    def get_coefficients(self):
        """
        Get the chebyshev coefficients. 
        """
        return self._get_coeff(self._ptr)


    def set_coefficients(self, coefs):
        """
        Sets the chebyshev coefficients. 
        """
        return self._set_coeff(self._ptr, coefs)

    def get_a(self):
        """
        Get the lower boundary of the current representation
        """
        return self._get_a(self._ptr)

    def set_a(self, a):
        """
        Set the lower boundary of the current representation
        """
        return self._set_a(self._ptr, a)

    def get_b(self):
        """
        Get the upper boundary of the current representation
        """
        return self._get_b(self._ptr)

    def set_b(self, a):
        """
        Set the upper boundary of the current representation
        """
        return self._set_b(self._ptr, a)

    def get_f(self):
        """
        Get the value f (what is it ?) The documentation does not tell anything
        about it.
        """
        return self._get_f(self._ptr)

    def set_f(self, a):
        """
        Set the value f (what is it ?)
        """
        return self._set_f(self._ptr, a)

    def get_order_sp(self):
        """
        Get the value f (what is it ?) The documentation does not tell anything
        about it.
        """
        return self._get_order_sp(self._ptr)

    def set_order_sp(self, a):
        """
        Set the value f (what is it ?)
        """
        return self._set_order_sp(self._ptr, a)



if __name__ == '__main__':
    def f(x, p):
        if x < 0.5:
            return 0.25
        else:
            return 0.75
        
     

    cs = cheb_series(40)
    F = gsl_function(f, None)
    cs.init(F, 0.0, 1.0)
    i = 10000;
    n = i

    for i in xrange(n):
        x = i / float(n)
        r10 = cs.eval_n(10, x)
        r40 = cs.eval(x)
        print "%g %g %g %g" % (x, f(x, None), r10, r40)
