from __future__ import print_function
from . import _ufuncs
_token = "complex_"
_tokl  = len(_token)

for _name in dir(_ufuncs):
    #print("name", _name)
    if _name[:_tokl] == _token:
        _shortname = _name[_tokl:]
        _cmd = "%s = _ufuncs.%s" % (_shortname, _name)
        #print(_cmd)
        exec(_cmd)
del _token
del _tokl
del _shortname
del _name
del _cmd
