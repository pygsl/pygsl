#!/usr/bin/env python
"""
Wrapper for the Monte carlo integrators provided by GSL.

"""
import _callback
import gsl_function
gsl_monte_function = gsl_function.gsl_monte_function

VEGAS_MODE_IMPORTANCE      = _callback.GSL_VEGAS_MODE_IMPORTANCE
VEGAS_MODE_IMPORTANCE_ONLY = _callback.GSL_VEGAS_MODE_IMPORTANCE_ONLY 
VEGAS_MODE_STRATIFIED      = _callback.GSL_VEGAS_MODE_STRATIFIED     
class _Monte:
    """
    Base Wrapper class. This class does not implement any solver itself, 
    so you should use a derived class eg. miser, vegas, or plain.
    """
    _alloc     = None
    _free      = None
    _integrate = None
    _init      = None
    
    def __init__(self, dim):
        """
        Input :
            dim ... the dimension of the integrator
        """
        self._ptr = None
        self._ptr = self._alloc(dim)

    def init(self):
        """
        (Re)initialises the solver
        """
        self._init(self._ptr)

    def integrate(self, func, xl, xu, ncalls, r):
        """
        Input:
            func   ... the function to solve. Must be a gsl_monte_function
            xl     ... the lower limits for the integration
            xu     ... the upper limits for the integration
            ncalls ... number of calls 
            r      ... random generator from pygsl.rng

        Output:
            val    ... the value
            abserr ... the error estimate for that value
        """
        return self._integrate(func.get_ptr(), (xl, xu),  ncalls, r, self._ptr)

    def get_name(self):
        """
        To be compatible with the other solvers I added this method        
        """
        return self.__class__.__name__
    
    def _GetPtr(self):
        """
        Direct access to the SWIG Pointer. Only use if you know what you are doing
        """
        return self._ptr
    
    def __del__(self):
        """
        """
        if hasattr(self, '_ptr'):
            if self._ptr != None:
                self._free(self._ptr)


        
class plain(_Monte):
    """
    """
    _alloc     = _callback.gsl_monte_plain_alloc
    _free      = _callback.gsl_monte_plain_free
    _integrate = _callback.gsl_monte_plain_integrate
    _init      = _callback.gsl_monte_plain_init
    pass

class miser(_Monte):
    """
    """
    _alloc     = _callback.gsl_monte_miser_alloc
    _free      = _callback.gsl_monte_miser_free
    _integrate = _callback.gsl_monte_miser_integrate
    _init      = _callback.gsl_monte_miser_init


    def  get_min_calls                (self):         return _callback.pygsl_monte_miser_get_min_calls               (self._ptr) 
    def  get_min_calls_per_bisection  (self):         return _callback.pygsl_monte_miser_get_min_calls_per_bisection (self._ptr)
    def  get_dither                   (self):         return _callback.pygsl_monte_miser_get_dither                  (self._ptr)
    def  get_estimate_frac            (self):         return _callback.pygsl_monte_miser_get_estimate_frac           (self._ptr)
    def  get_alpha                    (self):         return _callback.pygsl_monte_miser_get_alpha                   (self._ptr)
    
    def  set_min_calls                (self, arg1):   return _callback.pygsl_monte_miser_set_min_calls               (self._ptr, arg1)
    def  set_min_calls_per_bisection  (self, arg1):   return _callback.pygsl_monte_miser_set_min_calls_per_bisection (self._ptr, arg1)
    def  set_dither                   (self, arg1):   return _callback.pygsl_monte_miser_set_dither                  (self._ptr, arg1)
    def  set_estimate_frac            (self, arg1):   return _callback.pygsl_monte_miser_set_estimate_frac           (self._ptr, arg1)
    def  set_alpha                    (self, arg1):   return _callback.pygsl_monte_miser_set_alpha                   (self._ptr, arg1)


class vegas(_Monte):
    """
    """
    _alloc     = _callback.gsl_monte_vegas_alloc
    _free      = _callback.gsl_monte_vegas_free
    _integrate = _callback.gsl_monte_vegas_integrate
    _init      = _callback.gsl_monte_vegas_init



    def get_result     (self): return _callback.pygsl_monte_vegas_get_result    (self._ptr)
    def get_sigma      (self): return _callback.pygsl_monte_vegas_get_sigma     (self._ptr)
    def get_chisq      (self): return _callback.pygsl_monte_vegas_get_chisq     (self._ptr)
    def get_alpha      (self): return _callback.pygsl_monte_vegas_get_alpha     (self._ptr)
    def get_iterations (self): return _callback.pygsl_monte_vegas_get_iterations(self._ptr)
    def get_stage      (self): return _callback.pygsl_monte_vegas_get_stage     (self._ptr)
    def get_mode       (self): return _callback.pygsl_monte_vegas_get_mode      (self._ptr)
    def get_verbose    (self): return _callback.pygsl_monte_vegas_get_verbose   (self._ptr)
    def get_ostream    (self): return _callback.pygsl_monte_vegas_get_ostream   (self._ptr)
    
    def set_result     (self, arg1): return _callback.pygsl_monte_vegas_set_result    (self._ptr, arg1)
    def set_sigma      (self, arg1): return _callback.pygsl_monte_vegas_set_sigma     (self._ptr, arg1)
    def set_chisq      (self, arg1): return _callback.pygsl_monte_vegas_set_chisq     (self._ptr, arg1)
    def set_alpha      (self, arg1): return _callback.pygsl_monte_vegas_set_alpha     (self._ptr, arg1)
    def set_iterations (self, arg1): return _callback.pygsl_monte_vegas_set_iterations(self._ptr, arg1)
    def set_stage      (self, arg1): return _callback.pygsl_monte_vegas_set_stage     (self._ptr, arg1)
    def set_mode       (self, arg1): return _callback.pygsl_monte_vegas_set_mode      (self._ptr, arg1)
    def set_verbose    (self, arg1): return _callback.pygsl_monte_vegas_set_verbose   (self._ptr, arg1)
    def set_ostream    (self, arg1): return _callback.pygsl_monte_vegas_set_ostream   (self._ptr, arg1)
