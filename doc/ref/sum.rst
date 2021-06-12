
Series acceleration
===================

This chapter describes the use of the series acceleration tools based on
the Levin :math:`u`-transform. This method takes a small number of terms
from the start of a series and uses a systematic approximation to
compute an extrapolated value and an estimate of its error. The
:math:`u`-transform works for both convergent and divergent series,
including asymptotic series.

.. math::

   \label{eq:levin}
     \function{levin_sum}\code{(a)} = (A, \epsilon)
     \qquad\text{where}
     \qquad
     A \approx \sum_{n=0}^{\infty} a_{n} \pm \epsilon,

:math:`\code{a} = [a_{0}, a_{1}, \ldots, a_{n}]`, and :math:`\epsilon`
is an estimate of the absolute error.

Note: This function is intended for summing analytic series where each
term is known to high accuracy, and the rounding errors are assumed to
originate from finite precision. They are taken to be relative errors of
order for each term (as defined in the GNU Scientific Library source
code).

Function list
-------------

levin\_suma, truncate=False, info\_dict=None Return
(:math:`A, \epsilon`) where :math:`A` is the approximated sum of the
series ([eq:levin]) and :math:`\epsilon` is its absolute error estimate.

The calculation of the error in the extrapolated value is an
O\ :math:`(N^2)` process, which is expensive in time and memory. A full
table of intermediate values and derivatives through to O\ :math:`(N)`
must be computed and stored, but this does give a reliable error
estimate.

A faster but less reliable method which estimates the error from the
convergence of the extrapolated value is employed if is . This attempts
to estimate the error from the “truncation error” in the extrapolation,
the difference between the final two approximations. Using this method
avoids the need to compute an intermediate table of derivatives because
the error is estimated from the behavior of the extrapolated value
itself. Consequently this algorithm is an O\ :math:`(N)` process and
only requires O\ :math:`(N)` terms of storage. If the series converges
sufficiently fast then this procedure can be acceptable. It is
appropriate to use this method when there is a need to compute many
extrapolations of series with similar convergence properties at
high-speed. For example, when numerically integrating a function defined
by a parameterized series where the parameter varies only slightly. A
reliable error estimate should be computed first using the full
algorithm described above in order to verify the consistency of the
results.

If a dictionary is passed as , then two entries will be added: will be
the number of terms used [1]_ and will be the sum of these terms without
acceleration.

Further Reading
---------------

For details on the underlying implementation of these functions please
consult the GNU Scientific Library reference manual. The algorithms used
by these functions are described Fessler *et al.* (1983). The theory of
the :math:`u`-transform was presented Levin in 1973, and a review paper
from 2000 by Homeier is available online.
