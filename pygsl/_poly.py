# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import __poly
import new
new_instancemethod = new.instancemethod
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

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

