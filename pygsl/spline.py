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
    _alloc         = gslwrap.gsl_spline_alloc
    _free          = gslwrap.gsl_spline_free
    _eval          = gslwrap.gsl_spline_eval
    _eval_deriv    = gslwrap.gsl_spline_eval_deriv
    _eval_deriv2   = gslwrap.gsl_spline_eval_deriv2
    _eval_deriv2_e = gslwrap.gsl_spline_eval_deriv2_e
    _eval_deriv_e  = gslwrap.gsl_spline_eval_deriv_e
    _eval_e        = gslwrap.gsl_spline_eval_e
    _eval_integ    = gslwrap.gsl_spline_eval_integ
    _eval_integ_e  = gslwrap.gsl_spline_eval_integ_e
    _init          = gslwrap.gsl_spline_init
    _type          = None


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
        self._xa = xa
        self._init(self._ptr, (xa,ya))
        self._xyptr = (self._ptr,)
        self.accel_reset()
        
    def name(self):
        """
        Returns the name of the interpolation type used
        """
        # The spline struct has no name method, thus I use the class name.
        return self.__class__.__name__
    

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

