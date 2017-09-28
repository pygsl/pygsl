***************************************
pygsl application programming interface
***************************************

pygsl module
============

.. automodule:: pygsl
    :members:
    :undoc-members:
    :show-inheritance:
.. autofunction:: pygsl.set_debug_level
.. autofunction:: pygsl.get_debug_level		


Subpackages
===========

.. toctree::
    pygsl.statistics
    pygsl.testing
    
		  
Submodules
==========

pygsl\.errno module
-------------------

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

pygsl\.errors module
--------------------

.. automodule:: pygsl.errors
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.errors._ErrorSafeState
.. autodata:: pygsl.errors.error_safe_state
       

pygsl\.math module
------------------

.. automodule:: pygsl.math
    :members:
    :undoc-members:
    :show-inheritance:


pygsl\.poly module
------------------

.. automodule:: pygsl.poly
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.sf module
----------------

.. automodule:: pygsl.sf
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.permutation module
-------------------------

.. automodule:: pygsl.permutation
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.combination module
-------------------------

.. automodule:: pygsl.combination
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.combination.Combination
	       

pygsl\.blas module
------------------
    
.. automodule:: pygsl.blas
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.linalg module
--------------------

.. automodule:: pygsl.linalg
    :members:
    :undoc-members:
    :show-inheritance:
       

pygsl\.eigen module
-------------------

.. automodule:: pygsl.eigen
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.fft module
-----------------

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
    
pygsl\.integrate module
-----------------------

.. automodule:: pygsl.integrate
    :members:
    :undoc-members:
    :show-inheritance:
       

pygsl\.rng module
-----------------

.. automodule:: pygsl.rng
    :members:
    :undoc-members:
    :show-inheritance:

.. autclass:: pygsl.rng.mt19937
    :members:
    :undoc-members:
    :show-inheritance:

	      
pygsl\.qrng module
------------------

.. automodule:: pygsl.qrng
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.statistics module
------------------------
.. include   pygsl.statistics


pygsl\.monte module
-------------------

.. automodule:: pygsl.monte
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.monte._Monte
    :members:
    :undoc-members:
    :show-inheritance:
       

pygsl\.siman module
-------------------

.. automodule:: pygsl.siman
    :members:
    :undoc-members:
    :show-inheritance:


pygsl\.odeiv2 module
--------------------

.. automodule:: pygsl.odeiv2
     :members:
     :undoc-members:
     :show-inheritance:

.. autoclass:: pygsl.odeiv2.system
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


pygsl\.interpolation module
---------------------------

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

pygsl\.spline module
--------------------

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


       
pygsl\.interpolation2d module
-----------------------------

.. automodule:: pygsl.interpolation2d
    :members:
    :undoc-members:
    :show-inheritance:


pygsl\.deriv module
-------------------

.. automodule:: pygsl.deriv
    :members:
    :undoc-members:
    :show-inheritance:


pygsl\.chebyshev module
-----------------------

.. automodule:: pygsl.chebyshev
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.sum module
-----------------

.. automodule:: pygsl.sum
    :members:
    :undoc-members:
    :show-inheritance:
       
pygsl\.wavelet module
---------------------

.. automodule:: pygsl.wavelet
    :members:
    :undoc-members:
    :show-inheritance:
	      

pygsl\.hankel module
--------------------

.. automodule:: pygsl.hankel
    :members:
    :undoc-members:
    :show-inheritance:
       

pygsl\.roots module
-------------------

.. automodule:: pygsl.roots
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.roots._fsolver
    :members:
    :undoc-members:
    :show-inheritance:
       

pygsl\.minimize module
----------------------

.. automodule:: pygsl.minimize
    :members:
    :undoc-members:
    :show-inheritance:

.. autoclass:: pygsl.minimize._minsolver
    :members:
    :undoc-members:
    :show-inheritance:


pygsl\.multiroots module
------------------------

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
       

pygsl\.multiminimize module
---------------------------

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

pygsl\.fit module
-----------------

.. automodule:: pygsl.fit
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.multifit module
----------------------

.. automodule:: pygsl.multifit
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.multifit\_nlin module
----------------------------

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
       
pygsl\.multifit\_robust module
------------------------------

.. automodule:: pygsl.multifit_robust
    :members:
    :undoc-members:
    :show-inheritance:
       


pygsl\.bspline module
---------------------

.. automodule:: pygsl.bspline
    :members:
    :undoc-members:
    :show-inheritance:

	      
pygsl\.ieee module
------------------

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

Obsolete Modules
================
.. toctree::


pygsl\.diff module
------------------

.. automodule:: pygsl.diff
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.odeiv module
-------------------

.. automodule:: pygsl.odeiv
    :members:
    :undoc-members:
    :show-inheritance:


Modules containing wrappers
===========================

These wrappers are used by API modules. Typically these are not
directly accessed by the user.

pygsl\.init module
------------------

.. automodule:: pygsl.init
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.gsl\_function module
---------------------------

.. automodule:: pygsl.gsl_function
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.gslwrap module
---------------------

.. automodule:: pygsl.gslwrap
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.interpolation2d\_wrap module
-----------------------------------

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


pygsl\.init module
------------------

.. automodule:: pygsl.init
    :members:
    :undoc-members:
    :show-inheritance:


pygsl\.inittest module
----------------------

Functions needed to test the :mod:`pygsl.init` module

.. automodule:: pygsl.inittest
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.errortest module
-----------------------
Functions needed to test the error handling provided by
:mod:`pygsl.init` and the gsl error handler 
:c:func:`gsl_error()`.

.. automodule:: pygsl.errortest
    :members:
    :undoc-members:
    :show-inheritance:
       
pygsl\.block module
-------------------

.. automodule:: pygsl.block
    :members:
    :undoc-members:
    :show-inheritance:
       
pygsl\.vector module
--------------------

.. automodule:: pygsl.vector
    :members:
    :undoc-members:
    :show-inheritance:

pygsl\.matrix\_pierre module
----------------------------

.. automodule:: pygsl.matrix_pierre
    :members:
    :undoc-members:
    :show-inheritance:
       