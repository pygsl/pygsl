# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.
import _hankel
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


class DiscreteHankelTransform(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, DiscreteHankelTransform, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, DiscreteHankelTransform, name)
    def __init__(self,*args,**kwargs):
        _swig_setattr(self, DiscreteHankelTransform, 'this', apply(_hankel.new_DiscreteHankelTransform,args, kwargs))
        _swig_setattr(self, DiscreteHankelTransform, 'thisown', 1)
    def __del__(self, destroy= _hankel.delete_DiscreteHankelTransform):
        try:
            if self.thisown: destroy(self)
        except: pass
    def init(*args, **kwargs): return apply(_hankel.DiscreteHankelTransform_init,args, kwargs)
    def x_sample(*args, **kwargs): return apply(_hankel.DiscreteHankelTransform_x_sample,args, kwargs)
    def k_sample(*args, **kwargs): return apply(_hankel.DiscreteHankelTransform_k_sample,args, kwargs)
    def get_size(*args, **kwargs): return apply(_hankel.DiscreteHankelTransform_get_size,args, kwargs)
    def apply(*args, **kwargs): return apply(_hankel.DiscreteHankelTransform_apply,args, kwargs)
    def __repr__(self):
        return "<C DiscreteHankelTransform instance at %s>" % (self.this,)

class DiscreteHankelTransformPtr(DiscreteHankelTransform):
    def __init__(self,this):
        _swig_setattr(self, DiscreteHankelTransform, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, DiscreteHankelTransform, 'thisown', 0)
        _swig_setattr(self, DiscreteHankelTransform,self.__class__,DiscreteHankelTransform)
_hankel.DiscreteHankelTransform_swigregister(DiscreteHankelTransformPtr)


