****************
Chebyshev Series
****************

:class:`cheb_series` This base class can be instantiated by its name

::

    import pygsl.chebyshev
    s=pygsl.chebyshev.cheb_series()

.. function:: __init__(n) ... number of coefficients

.. function:: init(f, a, b)
	      This function computes the Chebyshev approximation for the
	      function F over the range (a,b) to the previously specified order. The
	      computation of the Chebyshev approximation is an O(\ :math:`n^2`)
	      process, and requires n function evaluations.

              f ... a gsl_function
	      a ... lower limit
	      b ... upper limit

evalx This function evaluates the Chebyshev series at a given point X.

eval\_errx This function computes the Chebyshev series at a given point
X, estimating both the series RESULT and its absolute error ABSERR. The
error estimate is made from the first neglected term in the series.

eval\_nn, x This function evaluates the Chebyshev series at a given
point x, to (at most) the given order n

eval\_n\_errn, x This function evaluates a Chebyshev series at a given
point X, estimating both the series RESULT and its absolute error
ABSERR, to (at most) the given order ORDER. The error estimate is made
from the first neglected term in the series.

calc\_deriv This method computes the derivative of the series CS. It
returns a new instance of the cheb\_series class.

calc\_integ This method computes the integral of the series CS. It
returns a new instance of the cheb\_series class.

get\_a Get the lower boundary of the current representation

get\_b Get the upper boundary of the current representation

get\_coefficients Get the chebyshev coefficients.

get\_f Get the value f (what is it ?) The documentation does not tell
anything about it.

get\_order\_sp Get the value f (what is it ?) The documentation does not
tell anything about it.

set\_a Set the lower boundary of the current representation

set\_b Set the upper boundary of the current

set\_coefficients Sets the chebyshev coefficients.

set\_ff Set the value f (what is it ?)

set\_order\_sp... Set the value f (what is it ?)

gsl\_functionf, params

This class defines the callbacks known as gsl\_function to gsl.

e.g to supply the function f:

def f(x, params): a = params[0] b = parmas[1] c = params[3] return a \*
x \*\* 2 + b \* x + c

to some solver, use

function = gsl\_function(f, params)
