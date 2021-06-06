
NumericalDifferentiation
========================

    This chapter describes the available functions for numerical
    differentiation.

The functions described in this chapter compute numerical derivatives by
finite differencing. An adaptive algorithm is used to find the best
choice of finite difference and to estimate the error in the derivative.
This module supersedes the diff module which has been deprecated with
the release of GSL-1. XXX

centralfunc, x, h This function computes the numerical derivative of the
function at the point using an adaptive central difference algorithm
with a step size of h. A tuple is returned with the derivative and its
estimated absolute error.

backwardfunc, x, h This function computes the numerical derivative of
the function at the point using an adaptive backward difference
algorithm with a step size of h. The function is evaluated only at
points smaller than and at itself. A tuple is returned with the
derivative and its estimated absolute error.

forwardfunc, x, h This function computes the numerical derivative of the
function at the point using an adaptive forward difference algorithm
with a step size of h. The function is evaluated only at points greater
than and at itself. A tuple is returned with the derivative and its
estimated absolute error.

The algorithms used by these functions are described in the following
book:
