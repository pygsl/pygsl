# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.12
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

"""
Sum modul for Levin u-transform

This module provides a function for accelerating the convergence of
series based on the Levin u-transform.  This method takes a small
number of terms from the start of a series and uses a systematic
approximation to compute an extrapolated value and an estimate of its
error. The u-transform works for both convergent and divergent
series, including asymptotic series.
"""


from sys import version_info as _swig_python_version_info
if _swig_python_version_info >= (2, 7, 0):
    def swig_import_helper():
        import importlib
        pkg = __name__.rpartition('.')[0]
        mname = '.'.join((pkg, '_sum')).lstrip('.')
        try:
            return importlib.import_module(mname)
        except ImportError:
            return importlib.import_module('_sum')
    _sum = swig_import_helper()
    del swig_import_helper
elif _swig_python_version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_sum', [dirname(__file__)])
        except ImportError:
            import _sum
            return _sum
        try:
            _mod = imp.load_module('_sum', fp, pathname, description)
        finally:
            if fp is not None:
                fp.close()
        return _mod
    _sum = swig_import_helper()
    del swig_import_helper
else:
    import _sum
# pull in all the attributes from _sum
if __name__.rpartition('.')[0] != '':
    if _swig_python_version_info >= (2, 7, 0):
        try:
            from ._sum import *
        except ImportError:
            from _sum import *
    else:
        from _sum import *
else:
    from _sum import *
del _swig_python_version_info

try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        object.__setattr__(self, name, value)
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr(self, class_type, name):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    raise AttributeError("'%s' object has no attribute '%s'" % (class_type.__name__, name))


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_method(set):
    def set_attr(self, name, value):
        if (name == "thisown"):
            return self.this.own(value)
        if hasattr(self, name) or (name == "this"):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr



def levin_sum(a, truncate=False, info_dict=None):
    """Return (sum(a), err) where sum(a) is the extrapolated
    sum of the infinite series a and err is an error estimate.

    Uses the Levin u-transform method.

    Parameters:
      a : A list or array of floating point numbers assumed
          to be the first terms in a series.
      truncate: If True, then use a more efficient algorithm, but with
          a less accurate error estimate
      info_dict: If info_dict is provided, then two entries will
          be added: 'terms_used' will be the number of terms
          used and 'sum_plain' will be the sum of these terms
          without acceleration.

    Notes: The error estimate is made assuming that the terms a are
    computed to machined precision.

    Example: Computing the zeta function 
    zeta(2) = 1/1**2 + 1/2**2 + 1/3**2 + ... = pi**2/6

    >>> from math import pi
    >>> zeta_2 = pi**2/6
    >>> a = [1.0/n**2 for n in range(1,21)]
    >>> info_dict = {}
    >>> (ans, err_est) = levin_sum(a, info_dict=info_dict)
    >>> ans, zeta_2             # doctest: +ELLIPSIS
    1.644934066..., 1.644934066...
    >>> err = abs(ans - zeta_2)
    >>> err < err_est
    True
    >>> (ans, err_est) = levin_sum(a, truncate=False)
    >>> ans             # doctest: +ELLIPSIS
    1.644934066...
    """
    if truncate:
        l = _levin_utrunc(len(a))
    else:
        l = _levin(len(a))

    ans = l.accel(a)
    if info_dict is not None:
        info_dict['sum_plain'] = l.sum_plain()
        info_dict['terms_used'] = l.get_terms_used()
    del l
    return ans





