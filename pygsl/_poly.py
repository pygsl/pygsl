# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import __poly

def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name) or (name == "thisown"):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

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
del types



gsl_poly_solve_quadratic = __poly.gsl_poly_solve_quadratic

gsl_poly_complex_solve_quadratic = __poly.gsl_poly_complex_solve_quadratic

gsl_poly_solve_cubic = __poly.gsl_poly_solve_cubic

gsl_poly_complex_solve_cubic = __poly.gsl_poly_complex_solve_cubic

gsl_poly_complex_workspace_alloc = __poly.gsl_poly_complex_workspace_alloc

gsl_poly_complex_workspace_free = __poly.gsl_poly_complex_workspace_free
gsl_poly_eval = __poly.gsl_poly_eval

gsl_poly_dd_init = __poly.gsl_poly_dd_init

gsl_poly_dd_eval = __poly.gsl_poly_dd_eval

gsl_poly_dd_taylor = __poly.gsl_poly_dd_taylor

gsl_poly_complex_solve = __poly.gsl_poly_complex_solve


