#!/usr/bin/env python
# Author : Pierre Schnizer
"""
Wrapper for the interpolations of gsl. This solver wraps all features as described
in Chapter 26 of the gsl documentation.

Difference between spline and interpolation module:
--------------------------------------------------
In the interpolation module the data for the independent and dependent data are
kept as reference in the various objects,whereas the spline module copies these
data into the internal C gsl_spline struct.
"""

import gslwrap

class _acceleration:
    """
    This class is meant to be used together with the interpolation and the spline.

    It expects the derived class to define the array _xa.
    """
    _accel_alloc   = gslwrap.gsl_interp_accel_alloc
    _accel_find    = gslwrap.gsl_interp_accel_find
    _accel_free    = gslwrap.gsl_interp_accel_free
    _accel_reset   = gslwrap.gsl_interp_accel_reset

    def __init__(self):
        self._accel = None
        assert(self._accel_alloc != None)
        assert(self._accel_free != None)
        self._accel= self._accel_alloc()

    def __del__(self):                
        if hasattr(self, '_accel'):
            if self._accel != None:
                self._accel_free(self._accel)

    
    def accel_reset(self):        
        self._accel_reset(self._accel)

    def accel_find(self, x):
        """
         This method performs a lookup action on the data array X_ARRAY
         of size SIZE, using the given accelerator A.  This is how lookups
         are performed during evaluation of an interpolation.  The function
         returns an index i such that `xarray[i] <= x < xarray[i+1]'.
         """
        return self._accel_find(self._accel, self._xa, x)

    def bsearch(self, x, index_lo, index_high):
        """
        input : x, index_lo, index_high
            
        This function returns the index i of the array X_ARRAY such that
        `x_array[i] <= x < x_array[i+1]'.  The index is searched for in
        the range [INDEX_LO,INDEX_HI].        
        """
        return self._bsearch(self._xa, x, index_lo, index_high)
    
class _common(_acceleration):
    _alloc         = gslwrap.gsl_interp_alloc
    _free          = gslwrap.gsl_interp_free
    _name          = gslwrap.gsl_interp_name
    _bsearch       = gslwrap.gsl_interp_bsearch
    _eval          = gslwrap.gsl_interp_eval
    _eval_deriv    = gslwrap.gsl_interp_eval_deriv
    _eval_deriv2   = gslwrap.gsl_interp_eval_deriv2
    _eval_deriv2_e = gslwrap.gsl_interp_eval_deriv2_e
    _eval_deriv_e  = gslwrap.gsl_interp_eval_deriv_e
    _eval_e        = gslwrap.gsl_interp_eval_e
    _eval_integ    = gslwrap.gsl_interp_eval_integ
    _eval_integ_e  = gslwrap.gsl_interp_eval_integ_e
    _init          = gslwrap.gsl_interp_init
    _min_size      = gslwrap.gsl_interp_min_size
    _name          = gslwrap.gsl_interp_name
    _type          = None
    
    def __init__(self, size):
        self._ptr   = None
        assert(self._alloc != None)
        assert(self._free != None)
        assert(self._type != None)
        self._ptr = self._alloc(self._type, size)
        _acceleration.__init__(self)
        self._xa = None
        self._xyptr = None

    def __del__(self):        
        if hasattr(self, '_ptr'):
            if self._ptr != None:
                self._free(self._ptr)
        _acceleration.__del__(self)

    
    def init(self, xa, ya):
        """
        input : xa, ya
            xa ... array of independent values
            ya ... array of dependent values
            
        This method initializes this for the
        data (xa,ay) where ya and ya are arrays of the size, which was set,
        when this object was initialised.  The
        interpolation object only keeps references to  the data arrays
        xa and ya and and  stores the static state computed from the data.
        The ya data array is always assumed to be strictly ordered; the
        behavior for other arrangements is not defined.
        """
        self._init(self._ptr, (xa,ya))
        self.accel_reset()
        self._xa = xa
        self._ya = ya
        self._xyptr = (self._ptr, xa, ya)
        
    def eval(self, x):
        """
        input : x
             x ... value of the independent variable
        output : y
             y ... returns the interpolated value at x  
        
        """
        return apply(self._eval, self._xyptr + (x, self._accel))
    
    def eval_e(self, x):
        """
        input : x
             x ... value of the independent variable
        output : flag, y
             flag  error flag 
             y ... returns the interpolated value at x  
        
        """
        return apply(self._eval_e, self._xyptr + (x, self._accel))

    def eval_deriv(self, x):
        """
        input : x
             x ... value of the independent variable
        output : y
             y ... returns the  value of the derivative at x          
        """
        return apply(self._eval_deriv, self._xyptr + (x, self._accel))
    
    def eval_deriv_e(self, x):
        """
        input : x
             x ... value of the independent variable
        output : flag, y
             flag  error flag 
             y ... returns the  value of the derivative at x  
        """
        return apply(self._eval_deriv_e, self._xyptr + (x, self._accel))
    
    def eval_deriv2(self, x):
        """
        input : x
             x ... value of the independent variable
        output : y
             y ... the value of the second derivative at x  
        """
        return apply(self._eval_deriv2, self._xyptr + (x, self._accel))
    
    def eval_deriv2_e(self, x):
        """
        input : x
             x ... value of the independent variable
        output : flag, y
             flag  error flag 
             y ... the value of the second derivative at x  
        """
        return apply(self._eval_deriv2_e, self._xyptr + (x, self._accel))

    def eval_integ(self, a, b):
        """
        input : a, b,
             a ... lower boundary
             b ... upper boundary
        output : y
             y ... the integral of the object over the range [a,b]
        """
        return apply(self._eval_integ, self._xyptr + (a,b, self._accel))
    
    def eval_integ_e(self, a, b):
        """
        input : a, b,
             a ... lower boundary
             b ... upper boundary
        output : flag, y
             flag  error flag 
             y ... the integral of the object over the range [a,b]
        """
        return apply(self._eval_integ_e, self._xyptr + (a,b, self._accel))

class _interpolation(_common):
    def min_size(self):
        """
        This function returns the minimum number of points required by the
        interpolation.
        """
        return self._min_size(self._ptr)
    
    def name(self):
        """
        Returns the name of the interpolation type used
        """
        return self._name(self._ptr)



class linear(_interpolation):
    """
    Linear interpolation. 
    """
    _type = gslwrap.cvar.gsl_interp_linear

class polynomial(_interpolation):
    """    
    Polynomial   interpolation.   This   method  should   only  be   used  for
    interpolating  small numbers  of points  because  polynomial interpolation
    introduces large oscillations, even for well-behaved datasets.  The number
    of terms in the interpolating polynomial is equal to the number of points.    
    """
    _type = gslwrap.cvar.gsl_interp_polynomial
    
class cspline(_interpolation):
    """
    Cubic spline with natural boundary conditions.
    """
    _type = gslwrap.cvar.gsl_interp_cspline
    
class cspline_periodic(_interpolation):
    """
    Cubic spline with periodic boundary conditions
    """
    _type = gslwrap.cvar.gsl_interp_cspline_periodic
    
class akima(_interpolation):
    """
    Akima spline with natural boundary conditions
    """
    _type = gslwrap.cvar.gsl_interp_akima
    
class akima_periodic(_interpolation):
    """
    Akima spline with periodic boundary conditions
    """
    _type = gslwrap.cvar.gsl_interp_akima_periodic


