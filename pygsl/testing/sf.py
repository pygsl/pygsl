"""Provides the various special functions as UFuncs
"""
import logging
from pygsl.testing import _ufuncs
from pygsl.testing._ufuncs import PREC_DOUBLE, PREC_SINGLE, PREC_APPROX

logger = logging.getLogger("pygsl")

__all__ = ["PREC_DOUBLE", "PREC_SINGLE", "PREC_APPROX"]

_token = "sf_"
_tokl  = len(_token)
_shortname = None
_name = None
_cmd = None

# remove sf_ from name

for _name in dir(_ufuncs):
    if _name[:_tokl] == _token:
        _shortname = _name[_tokl:]
        _cmd = "%s = _ufuncs.%s" % (_shortname, _name)
        logger.debug("Adding name %s from %s (module _ufunc)", _shortname, _name)
        exec(_cmd)
        __all__.append(_shortname)

del _token
del _tokl
del _shortname
del _name
del _cmd

logger.warning("names listed in __all__: %s", __all__)
