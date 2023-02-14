***************************************
PyGSL application programming interface
***************************************

.. toctree::
        :maxdepth: 8

pygsl
=====

.. automodule:: pygsl
    :members:
    :undoc-members:
    :show-inheritance:
.. autofunction:: pygsl.set_debug_level
.. autofunction:: pygsl.get_debug_level



Submodules
==========

errno
-----

.. automodule:: pygsl.errno
    :members:
    :undoc-members:
    :show-inheritance:

.. autodata:: pygsl.errno.GSL_SUCCESS
.. autodata:: pygsl.errno.GSL_FAILURE
.. autodata:: pygsl.errno.GSL_CONTINUE
.. autodata:: pygsl.errno.GSL_EDOM
.. autodata:: pygsl.errno.GSL_ERANGE
.. autodata:: pygsl.errno.GSL_EFAULT
.. autodata:: pygsl.errno.GSL_EINVAL
.. autodata:: pygsl.errno.GSL_EFAILED
.. autodata:: pygsl.errno.GSL_EFACTOR
.. autodata:: pygsl.errno.GSL_ESANITY
.. autodata:: pygsl.errno.GSL_ENOMEM
.. autodata:: pygsl.errno.GSL_EBADFUNC
.. autodata:: pygsl.errno.GSL_ERUNAWAY
.. autodata:: pygsl.errno.GSL_EMAXITER
.. autodata:: pygsl.errno.GSL_EZERODIV
.. autodata:: pygsl.errno.GSL_EBADTOL
.. autodata:: pygsl.errno.GSL_ETOL
.. autodata:: pygsl.errno.GSL_EUNDRFLW
.. autodata:: pygsl.errno.GSL_EOVRFLW
.. autodata:: pygsl.errno.GSL_ELOSS
.. autodata:: pygsl.errno.GSL_EROUND
.. autodata:: pygsl.errno.GSL_EBADLEN
.. autodata:: pygsl.errno.GSL_ENOTSQR
.. autodata:: pygsl.errno.GSL_ESING
.. autodata:: pygsl.errno.GSL_EDIVERGE
.. autodata:: pygsl.errno.GSL_EUNSUP
.. autodata:: pygsl.errno.GSL_EUNIMPL
.. autodata:: pygsl.errno.GSL_ECACHE
.. autodata:: pygsl.errno.GSL_ETABLE
.. autodata:: pygsl.errno.GSL_ENOPROG
.. autodata:: pygsl.errno.GSL_ENOPROGJ
.. autodata:: pygsl.errno.GSL_ETOLF
.. autodata:: pygsl.errno.GSL_ETOLX
.. autodata:: pygsl.errno.GSL_ETOLG
.. autodata:: pygsl.errno.GSL_EOF

.. autodata:: pygsl.errno.PyGSL_ESTRIDE
.. autodata:: pygsl.errno.PyGSL_EUNIMPL
.. autodata:: pygsl.errno.PyGSL_EINIT

errors
------

.. automodule:: pygsl.errors
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.errors._ErrorSafeState
.. autodata:: pygsl.errors.error_safe_state


math
----
.. py:module:: pygsl.math

.. include:: sf/sf__math_doc.rst


.. include:: sf_func.rst



poly
----

.. automodule:: pygsl.poly
    :members:
    :undoc-members:
    :show-inheritance:


permutation
-----------

.. automodule:: pygsl.permutation
    :members:
    :undoc-members:
    :show-inheritance:

combination
-----------

.. automodule:: pygsl.combination
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.combination.Combination


blas
----

.. automodule:: pygsl.blas
    :members:
    :undoc-members:
    :show-inheritance:

linalg
------

.. automodule:: pygsl.linalg
    :members:
    :undoc-members:
    :show-inheritance:


eigen
-----

.. automodule:: pygsl.eigen
    :members:
    :undoc-members:
    :show-inheritance:

fft
---

.. automodule:: pygsl.fft
    :members:
    :undoc-members:
    :show-inheritance:

.. autofunction:: complex_backward
.. autofunction:: complex_forward
.. autofunction:: complex_backward_float
.. autofunction:: complex_forward_float
.. autofunction:: complex_inverse
.. autofunction:: complex_inverse_float
.. autofunction:: complex_radix2_backward
.. autofunction:: complex_radix2_backward_float
.. autofunction:: complex_radix2_dif_backward
.. autofunction:: complex_radix2_dif_backward_float
.. autofunction:: complex_radix2_dif_forward
.. autofunction:: complex_radix2_dif_forward_float
.. autofunction:: complex_radix2_dif_inverse
.. autofunction:: complex_radix2_dif_inverse_float
.. autofunction:: complex_radix2_forward
.. autofunction:: complex_radix2_forward_float
.. autofunction:: complex_radix2_inverse
.. autofunction:: complex_radix2_inverse_float
.. autofunction:: halfcomplex_inverse
.. autofunction:: halfcomplex_inverse_float
.. autofunction:: halfcomplex_radix2_inverse
.. autofunction:: halfcomplex_radix2_inverse_float
.. autofunction:: halfcomplex_radix2_transform
.. autofunction:: halfcomplex_radix2_transform_float
.. autofunction:: halfcomplex_radix2_unpack
.. autofunction:: halfcomplex_radix2_unpack_float
.. autofunction:: halfcomplex_transform
.. autofunction:: halfcomplex_transform_float
.. autofunction:: halfcomplex_wavetable
.. autofunction:: halfcomplex_wavetable_float
.. autofunction:: real_radix2_transform
.. autofunction:: real_radix2_transform_float
.. autofunction:: real_transform
.. autofunction:: real_transform_float

.. autoclass:: complex_wavetable
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: complex_wavetable_float
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: complex_workspace
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: complex_workspace_float
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: real_wavetable
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: real_wavetable_float
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: real_workspace
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: real_workspace_float
    :members:
    :undoc-members:
    :show-inheritance:

integrate
---------

.. automodule:: pygsl.integrate
    :members:
    :undoc-members:
    :show-inheritance:


rng
---

.. automodule:: pygsl.rng
    :members:
    :undoc-members:
    :show-inheritance:

.. currentmodule :: pygsl.rng
.. autoclass:: pygsl.rng.mt19937
    :members:
    :undoc-members:
    :show-inheritance:


qrng
----

.. automodule:: pygsl.qrng
    :members:
    :undoc-members:
    :show-inheritance:

statistics
----------
.. include::  pygsl.statistics


monte
-----

.. automodule:: pygsl.monte
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.monte._Monte
    :members:
    :undoc-members:
    :show-inheritance:


siman
-----

.. automodule:: pygsl.siman
    :members:
    :undoc-members:
    :show-inheritance:


odeiv2
------

.. automodule:: pygsl.odeiv2
     :members:
     :undoc-members:
     :show-inheritance:

.. currentmodule:: pygsl.odeiv2
.. py:module:: pygsl.odeive2
.. autoclass:: pygsl.odeiv2.system
     :members:
     :undoc-members:
     :inherited-members:
     :show-inheritance:

.. autoclass:: pygsl.odeiv2.pygsl_odeiv2_step
     :members:
     :undoc-members:
     :inherited-members:
     :show-inheritance:

.. autoclass:: pygsl.odeiv2.pygsl_odeiv2_control
     :members:
     :undoc-members:
     :inherited-members:
     :show-inheritance:

.. autoclass:: pygsl.odeiv2.pygsl_odeiv2_evolve
     :members:
     :undoc-members:
     :inherited-members:
     :show-inheritance:

.. autoclass:: pygsl.odeiv2.pygsl_odeiv2_drive
     :members:
     :undoc-members:
     :inherited-members:
     :show-inheritance:

.. automethod:: pygsl.odeiv2.system.set_dimension
.. automethod:: pygsl.odeiv2.system.set_func
.. automethod:: pygsl.odeiv2.system.set_jacobian
.. autoclass:: pygsl.odeiv2.pygsl_odeiv2_step
.. autoclass:: pygsl.odeiv2.pygsl_odeiv2_control

.. autodata:: pygsl.odeiv2.hadj_nil
.. autodata:: pygsl.odeiv2.hadj_inc
.. autodata:: pygsl.odeiv2.hadj_dec

.. autodata:: pygsl.odeiv2.step_rk2
.. autodata:: pygsl.odeiv2.step_rk4
.. autodata:: pygsl.odeiv2.step_rkf45
.. autodata:: pygsl.odeiv2.step_rkck
.. autodata:: pygsl.odeiv2.step_rk8pd
.. autodata:: pygsl.odeiv2.step_rk2imp
.. autodata:: pygsl.odeiv2.step_rk4imp
.. autodata:: pygsl.odeiv2.step_bsimp
.. autodata:: pygsl.odeiv2.step_rk1imp
.. autodata:: pygsl.odeiv2.step_msadams
.. autodata:: pygsl.odeiv2.step_msbdf

interpolation
-------------

.. automodule:: pygsl.interpolation
    :members:
    :inherited-members:
    :undoc-members:
    :show-inheritance:


.. autoclass:: pygsl.interpolation._common
    :members:
    :inherited-members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.interpolation._interpolation
    :members:
    :inherited-members:
    :undoc-members:
    :show-inheritance:

spline
------

.. automodule:: pygsl.spline
    :members:
    :inherited-members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.spline._spline
    :members:
    :inherited-members:
    :undoc-members:
    :show-inheritance:



interpolation2d
---------------

.. automodule:: pygsl.interpolation2d
    :members:
    :undoc-members:
    :show-inheritance:


deriv
-----

.. automodule:: pygsl.deriv
    :members:
    :undoc-members:
    :show-inheritance:


chebyshev
---------

.. automodule:: pygsl.chebyshev
    :members:
    :undoc-members:
    :show-inheritance:

sum
---

.. automodule:: pygsl.sum
    :members:
    :undoc-members:
    :show-inheritance:

wavelet
-------

.. automodule:: pygsl.wavelet
    :members:
    :undoc-members:
    :show-inheritance:


hankel
------

.. automodule:: pygsl.hankel
    :members:
    :undoc-members:
    :show-inheritance:


roots
-----

.. automodule:: pygsl.roots
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.roots._fsolver
    :members:
    :undoc-members:
    :show-inheritance:


minimize
--------

.. automodule:: pygsl.minimize
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.minimize._minsolver
    :members:
    :undoc-members:
    :show-inheritance:


multiroots
----------

.. automodule:: pygsl.multiroots
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.multiroots._fsolver
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.multiroots._fdfsolver
    :members:
    :undoc-members:
    :show-inheritance:


multiminimize
-------------

.. automodule:: pygsl.multiminimize
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.multiminimize._fsolver
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.multiminimize._fdfsolver
    :members:
    :undoc-members:
    :show-inheritance:

fit
---

.. automodule:: pygsl.fit
    :members:
    :undoc-members:
    :show-inheritance:

multifit
--------

.. automodule:: pygsl.multifit
    :members:
    :undoc-members:
    :show-inheritance:

multifit\_nlin
--------------

.. automodule:: pygsl.multifit_nlin
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.multifit_nlin._fsolver
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.multifit_nlin._fdfsolver
    :members:
    :undoc-members:
    :show-inheritance:

multifit\_robust
----------------

.. automodule:: pygsl.multifit_robust
     :members:
     :undoc-members:
     :show-inheritance:

.. py:module:: pygsl.multifit_robust
.. currentmodule:: pygsl.multifit_robust

.. autoclass:: pygsl.multifit_robust.stats
    :members:
    :private-members:
    :special-members:

.. autoclass:: pygsl.multifit_robust.workspace
    :members:
    :private-members:
    :special-members:


.. autofunction:: pygsl.multifit_robust.est
.. autofunction:: pygsl.multifit_robust.est_vector

.. autodata:: pygsl.multifit_robust.default
.. autodata:: pygsl.multifit_robust.bisquare
.. autodata:: pygsl.multifit_robust.cauchy
.. autodata:: pygsl.multifit_robust.fair
.. autodata:: pygsl.multifit_robust.huber
.. autodata:: pygsl.multifit_robust.ols
.. autodata:: pygsl.multifit_robust.welsch



bspline
-------

.. automodule:: pygsl.bspline
    :members:
    :undoc-members:
    :show-inheritance:

.. py:module:: pygsl.bspline
.. currentmodule:: pygsl.bspline
.. autoclass:: pygsl.bspline.bspline
    :members:
    :undoc-members:
    :inherited-members:
    :show-inheritance:

.. automethod:: pygsl.bspline.bspline.get_internal_knots
.. automethod:: pygsl.bspline.bspline.knots
.. automethod:: pygsl.bspline.bspline.knots_uniform
.. automethod:: pygsl.bspline.bspline.eval_vector
.. automethod:: pygsl.bspline.bspline.eval_dep
.. automethod:: pygsl.bspline.bspline.eval_dep_yerr



ieee
----

.. automodule:: pygsl.ieee
    :members:
    :undoc-members:
    :show-inheritance:

.. autodata:: pygsl.ieee.single_precision
.. autodata:: pygsl.ieee.double_precision
.. autodata:: pygsl.ieee.extended_precision
.. autodata:: pygsl.ieee.mask_all
.. autodata:: pygsl.ieee.mask_denormalized
.. autodata:: pygsl.ieee.mask_division_by_zero
.. autodata:: pygsl.ieee.mask_invalid
.. autodata:: pygsl.ieee.mask_overflow
.. autodata:: pygsl.ieee.mask_underflow
.. autodata:: pygsl.ieee.round_to_nearest
.. autodata:: pygsl.ieee.round_down
.. autodata:: pygsl.ieee.round_up
.. autodata:: pygsl.ieee.round_to_zero
.. autodata:: pygsl.ieee.trap_inexact
.. autodata:: pygsl.ieee.type_nan
.. autodata:: pygsl.ieee.type_inf
.. autodata:: pygsl.ieee.type_normal
.. autodata:: pygsl.ieee.type_denormal
.. autodata:: pygsl.ieee.type_zero


**************************************
Modules not considered part of the API
**************************************

Obsoletes
================
.. toctree::


diff
----

.. automodule:: pygsl.diff
    :members:
    :undoc-members:
    :show-inheritance:

odeiv
-----

.. automodule:: pygsl.odeiv
    :members:
    :undoc-members:
    :show-inheritance:

sf
---

Not documented here. Name clashes with
`pygsl.testing.sf` could occur.


math
----

.. automodule:: pygsl.math
    :members:
    :undoc-members:
    :show-inheritance:



Modules containing wrappers
===========================

These wrappers are used by APIs. Typically these are not
directly accessed by the user.

init
----

.. automodule:: pygsl.init
    :members:
    :undoc-members:
    :show-inheritance:

gsl\_function
-------------

.. automodule:: pygsl.gsl_function
    :members:
    :undoc-members:
    :show-inheritance:

gslwrap
-------

.. automodule:: pygsl.gslwrap
    :members:
    :undoc-members:
    :show-inheritance:

interpolation2d\_wrap
---------------------

.. automodule:: pygsl.interpolation2d_wrap
    :members:
    :undoc-members:
    :show-inheritance:

*****************************
Modules for testing internals
*****************************

Submodules
==========

.. toctree::


init
----

.. automodule:: pygsl.init
    :members:
    :undoc-members:
    :show-inheritance:


inittest
--------

Functions needed to test the :mod:`pygsl.init`

.. automodule:: pygsl.inittest
    :members:
    :undoc-members:
    :show-inheritance:

errortest
---------
Functions needed to test the error handling provided by
:mod:`pygsl.init` and the gsl error handler
:c:func:`gsl_error()`.

.. automodule:: pygsl.errortest
    :members:
    :undoc-members:
    :show-inheritance:

block
-----

.. automodule:: pygsl.block
    :members:
    :undoc-members:
    :show-inheritance:

vector
------

.. automodule:: pygsl.vector
    :members:
    :undoc-members:
    :show-inheritance:

matrix\_pierre
--------------

.. automodule:: pygsl.matrix_pierre
    :members:
    :undoc-members:
    :show-inheritance:
