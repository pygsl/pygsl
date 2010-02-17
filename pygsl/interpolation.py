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
from  pygsl import errors

def bsearch(xa, x, index_lo, index_high):
    """
    input : x, index_lo, index_high
    
    This function returns the index i of the array X_ARRAY such that
    `x_array[i] <= x < x_array[i+1]'.  The index is searched for in
    the range [INDEX_LO,INDEX_HI].        
    """
    return gslwrap.gsl_interp_bsearch(xa, x, index_lo, index_high)

class _acceleration:
    """
    This class is meant to be used together with the interpolation and the spline.
    """

    def __init__(self):
        self._object = gslwrap.gsl_interp_accel()
    
    def reset(self):        
        self._object.reset()

    def find(self, xa, x):
        """
         This method performs a lookup action on the data array X_ARRAY
         of size SIZE, using the given accelerator A.  This is how lookups
         are performed during evaluation of an interpolation.  The function
         returns an index i such that `xarray[i] <= x < xarray[i+1]'.
         """
        return self._object.find(xa, x)

    
class _common:
    _type          = None
        
    def accel_reset(self):        
        self._object.accel_reset()

    def accel_find(self, x):
        """
         This method performs a lookup action on the data array X_ARRAY
         of size SIZE, using the given accelerator A.  This is how lookups
         are performed during evaluation of an interpolation.  The function
         returns an index i such that `xarray[i] <= x < xarray[i+1]'.
         """
        return self._object.accel_find(x)

    def min_size(self):
        """
        This function returns the minimum number of points required by the
        interpolation.
        """
        return self._object.min_size()
    
    def name(self):
        """
        Returns the name of the interpolation type used
        """
        return self._object.name()

        
    def eval(self, x):
        """
        input : x
             x ... value of the independent variable
        output : y
             y ... returns the interpolated value at x  
        
        """
        return self._object.eval(x)

    
    def eval_e(self, x):
        """
        input : x
             x ... value of the independent variable
        output : flag, y
             flag  error flag 
             y ... returns the interpolated value at x  
        
        """
        return self._object.eval_e(x)


    def eval_deriv(self, x):
        """
        input : x
             x ... value of the independent variable
        output : y
             y ... returns the  value of the derivative at x          
        """
        return self._object.eval_deriv(x)

    
    def eval_deriv_e(self, x):
        """
        input : x
             x ... value of the independent variable
        output : flag, y
             flag  error flag 
             y ... returns the  value of the derivative at x  
        """
        return self._object.eval_deriv_e(x)
    
    def eval_deriv2(self, x):
        """
        input : x
             x ... value of the independent variable
        output : y
             y ... the value of the second derivative at x  
        """
        return self._object.eval_deriv2(x)
    
    def eval_deriv2_e(self, x):
        """
        input : x
             x ... value of the independent variable
        output : flag, y
             flag  error flag 
             y ... the value of the second derivative at x  
        """
        return self._object.eval_deriv2_e(x)


    def eval_integ(self, a, b):
        """
        input : a, b,
             a ... lower boundary
             b ... upper boundary
        output : y
             y ... the integral of the object over the range [a,b]
        """
        return self._object.eval_integ(a, b)
    
    def eval_integ_e(self, a, b):
        """
        input : a, b,
             a ... lower boundary
             b ... upper boundary
        output : flag, y
             flag  error flag 
             y ... the integral of the object over the range [a,b]
        """
        return self._object.eval_integ_e(a, b)


class _interpolation(_common):
    def __init__(self, n):
        if n <= 0:
            msg = "Number of elements must be positive but was %d!"
            raise errors.gsl_InvalidArgumentError, msg % (n,)


        self._object = gslwrap.pygsl_interp(self._type, n)


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
        return self._object.init(xa,ya)
        


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


