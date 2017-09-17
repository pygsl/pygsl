"""Provides the various special functions as UFuncs
"""
from pygsl.testing import _ufuncs
_token = "sf_"
_tokl  = len(_token)

for _name in dir(_ufuncs):
    if _name[:_tokl] == _token:
        _shortname = _name[_tokl:]
        _cmd = "%s = _ufuncs.%s" % (_shortname, _name)
        #printy cmd
        exec(_cmd)

from pygsl.testing._ufuncs import PREC_DOUBLE, PREC_SINGLE, PREC_APPROX

del _token
del _tokl
del _shortname
del _name
del _cmd
