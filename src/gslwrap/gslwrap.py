# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.
import _gslwrap
def _swig_setattr(self,class_type,name,value):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    self.__dict__[name] = value

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


gsl_spline_alloc = _gslwrap.gsl_spline_alloc

gsl_spline_init = _gslwrap.gsl_spline_init

gsl_spline_eval_e = _gslwrap.gsl_spline_eval_e

gsl_spline_eval = _gslwrap.gsl_spline_eval

gsl_spline_eval_deriv_e = _gslwrap.gsl_spline_eval_deriv_e

gsl_spline_eval_deriv = _gslwrap.gsl_spline_eval_deriv

gsl_spline_eval_deriv2_e = _gslwrap.gsl_spline_eval_deriv2_e

gsl_spline_eval_deriv2 = _gslwrap.gsl_spline_eval_deriv2

gsl_spline_eval_integ_e = _gslwrap.gsl_spline_eval_integ_e

gsl_spline_eval_integ = _gslwrap.gsl_spline_eval_integ

gsl_spline_free = _gslwrap.gsl_spline_free

gsl_interp_accel_alloc = _gslwrap.gsl_interp_accel_alloc

gsl_interp_accel_find = _gslwrap.gsl_interp_accel_find

gsl_interp_accel_reset = _gslwrap.gsl_interp_accel_reset

gsl_interp_accel_free = _gslwrap.gsl_interp_accel_free

gsl_interp_alloc = _gslwrap.gsl_interp_alloc

gsl_interp_init = _gslwrap.gsl_interp_init

gsl_interp_name = _gslwrap.gsl_interp_name

gsl_interp_min_size = _gslwrap.gsl_interp_min_size

gsl_interp_eval_e = _gslwrap.gsl_interp_eval_e

gsl_interp_eval = _gslwrap.gsl_interp_eval

gsl_interp_eval_deriv_e = _gslwrap.gsl_interp_eval_deriv_e

gsl_interp_eval_deriv = _gslwrap.gsl_interp_eval_deriv

gsl_interp_eval_deriv2_e = _gslwrap.gsl_interp_eval_deriv2_e

gsl_interp_eval_deriv2 = _gslwrap.gsl_interp_eval_deriv2

gsl_interp_eval_integ_e = _gslwrap.gsl_interp_eval_integ_e

gsl_interp_eval_integ = _gslwrap.gsl_interp_eval_integ

gsl_interp_free = _gslwrap.gsl_interp_free

gsl_interp_bsearch = _gslwrap.gsl_interp_bsearch

cvar = _gslwrap.cvar

