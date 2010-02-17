#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
Wrapper for the splines  of gsl. This solver wraps all features as described
in Chapter 26 of the gsl documentation.

Difference between spline and interpolation module:
--------------------------------------------------
In the interpolation module the data for the independent and dependent data are
kept as reference in the various objects,whereas the spline module copies these
data into the internal C gsl_spline struct.
"""

import errors
import gslwrap
import interpolation

_acceleration     = interpolation._acceleration
_common           = interpolation._common
#linear            = interpolation.linear          
#polynomial        = interpolation.polynomial      
#cspline           = interpolation.cspline         
#cspline_periodic  = interpolation.cspline_periodic
#akima             = interpolation.akima           
#akima_periodic    = interpolation.akima_periodic  

class _spline(_common):
    _type          = None


    def __init__(self, n):
        assert(self._type != None)
        if n <= 0:
            msg = "Number of elements must be positive but was %d!"
            raise errors.gsl_InvalidArgumentError, msg % (n,)

        tmp = gslwrap.pygsl_spline(self._type, n)
        if tmp == None:
            raise errors.gsl_GenericError, "Failed to allocate spline!"
        self._object = tmp

    
    def init(self, xa, ya):
        """
        input : xa, ya
            xa ... array of independent values
            ya ... array of dependent values
            
        This method initializes this for the  data (xa,ay) where ya and ya are
        arrays of the  size, which was set, when  this object was initialised.
        The  interpolation object  copys the  data arrays  xa and  ya  and and
        stores the static state computed from  the data.  The ya data array is
        always  assumed  to  be  strictly  ordered;  the  behavior  for  other
        arrangements is not defined.
        """
        self._object.init((xa,ya))

    def eval_vector(self, x):
        """
        input : x
               a vector of independent values
        """
        return  self._object.eval_vector(x)

    def eval_e_vector(self, x):
        """
        input : x
               a vector of independent values
        """
        return  self._object.eval_e_vector(x)

    def eval_deriv_vector(self, x):
        """
        input : x
               a vector of independent values
        """
        return  self._object.eval_deriv_vector(x)

    def eval_deriv_e_vector(self, x):
        """
        input : x
               a vector of independent values
        """
        return  self._object.eval_deriv_e_vector(x)

    def eval_deriv2_vector(self, x):
        """
        input : x
               a vector of independent values
        """
        return  self._object.eval_deriv2_vector(x)

    def eval_deriv2_e_vector(self, x):
        """
        input : x
               a vector of independent values
        """
        return  self._object.eval_deriv2_e_vector(x)
    
    def eval_integ_vector(self, a, b):
        """
        input : a, b
               two vector of independent values of same length
        """
        return  self._object.eval_deriv_vector(a, b)

    def eval_integ_e_vector(self, a, b):
        """
        input : a, b
               two vector of independent values of same length
        """
        return  self._object.eval_deriv_e_vector(a, b)

    def name(self):
        """
        Returns the name of the interpolation type used
        """
        # The spline struct has no name method, thus I use the class name.
        return self.__class__.__name__
    
    def GetSplineCObject(self):
        """
        Useful when using GSL in C code.
        """
        raise pygsl_NotImplementedError

    def GetAccelCObject(self):
        """
        Useful when using GSL in C code.
        """
        raise pygsl_NotImplementedError

class linear(_spline):
    """
    Linear interpolation. 
    """
    _type = gslwrap.cvar.gsl_interp_linear

class polynomial(_spline):
    """    
    Polynomial   interpolation.   This   method  should   only  be   used  for
    interpolating  small numbers  of points  because  polynomial interpolation
    introduces large oscillations, even for well-behaved datasets.  The number
    of terms in the interpolating polynomial is equal to the number of points.    
    """
    _type = gslwrap.cvar.gsl_interp_polynomial
    
class cspline(_spline):
    """
    Cubic spline with natural boundary conditions.
    """
    _type = gslwrap.cvar.gsl_interp_cspline
    
class cspline_periodic(_spline):
    """
    Cubic spline with periodic boundary conditions
    """
    _type = gslwrap.cvar.gsl_interp_cspline_periodic
    
class akima(_spline):
    """
    Akima spline with natural boundary conditions
    """
    _type = gslwrap.cvar.gsl_interp_akima
    
class akima_periodic(_spline):
    """
    Akima spline with periodic boundary conditions
    """
    _type = gslwrap.cvar.gsl_interp_akima_periodic

