# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _hankel

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


class DiscreteHankelTransform(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, DiscreteHankelTransform, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, DiscreteHankelTransform, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_dht_struct instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        _swig_setattr(self, DiscreteHankelTransform, 'this', _hankel.new_DiscreteHankelTransform(*args, **kwargs))
        _swig_setattr(self, DiscreteHankelTransform, 'thisown', 1)
    def __del__(self, destroy=_hankel.delete_DiscreteHankelTransform):
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args, **kwargs): return _hankel.DiscreteHankelTransform_init(*args, **kwargs)
    def x_sample(*args, **kwargs): return _hankel.DiscreteHankelTransform_x_sample(*args, **kwargs)
    def k_sample(*args, **kwargs): return _hankel.DiscreteHankelTransform_k_sample(*args, **kwargs)
    def get_size(*args, **kwargs): return _hankel.DiscreteHankelTransform_get_size(*args, **kwargs)
    def apply(*args, **kwargs): return _hankel.DiscreteHankelTransform_apply(*args, **kwargs)

class DiscreteHankelTransformPtr(DiscreteHankelTransform):
    def __init__(self, this):
        _swig_setattr(self, DiscreteHankelTransform, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, DiscreteHankelTransform, 'thisown', 0)
        _swig_setattr(self, DiscreteHankelTransform,self.__class__,DiscreteHankelTransform)
_hankel.DiscreteHankelTransform_swigregister(DiscreteHankelTransformPtr)


