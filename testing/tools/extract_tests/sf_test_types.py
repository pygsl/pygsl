
class _test_sf_params:
    _t_type = None
    def __init__(self, func = None, result = None, args = None, status = None, text = None, tolerance = None):
        self._func   = func
        self._result = result
        self._args   = args
        self._status = status
        self._text = text
        self._tolerance = tolerance

    def GetTestText(self):
        return self._text
    
    def GetResultTolerance(self):
        return self._tolerance
    
    def GetFunctionName(self):
        return self._func

    def GetFunctionResult(self):
        return self._result

    def GetFunctionArguments(self):
        return self._args

    def GetFunctionStatus(self):
        return self._status

    def __str__(self):
        fmt = "%s (%s, %s, %s, %s)"
        msg = fmt  %(self._t_type, self._func, self._args, self._result, self._status)
        return msg

_test_sf_type = "test_sf"

class test_sf_params(_test_sf_params):
    _t_type = _test_sf_type
