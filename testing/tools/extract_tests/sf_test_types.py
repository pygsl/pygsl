class _test_sf_params_basis:
    def GetTestText(self):
        return self._text

    def GetFunctionName(self):
        return self._func

    def GetFunctionArguments(self):
        return self._args

    def GetFunctionStatus(self):
        return self._status

class _test_sf_params(_test_sf_params_basis):
    _t_type = None
    def __init__(self, func = None, result = None, args = None, status = None, text = None, tolerance = None):
        self._func   = func
        self._result = result
        self._args   = args
        self._status = status
        self._text = text
        self._tolerance = tolerance        

    def GetResultTolerance(self):
        return self._tolerance

    def GetFunctionResult(self):
        return self._result

    def GetTestCode(self, cnt):
# Code for TEST_SF
        code="""
        def test_args%d(self):
            '%s'            
            self._test(%s, %s, %s, %s)

"""
        t_code = code %(cnt, self.GetTestText(),
                        self.GetFunctionArguments(), self.GetFunctionResult(), self.GetResultTolerance(), self.GetFunctionStatus())
        return t_code


    def __str__(self):
        fmt = "%s (%s, %s, %s, %s)"
        msg = fmt  %(self._t_type, self._func, self._args, self._result, self._status)
        return msg


class _test_sf_params_2(_test_sf_params_basis):
    def __init__(self, func = None,  args = None,  status = None, text = None, result1 = None, tolerance1 = None, result2 = None, tolerance2 = None):
        self._func   = func
        self._args   = args
        self._status = status
        self._text = text
        self._result1 = result1
        self._tolerance1 = tolerance1
        self._result2 = result2
        self._tolerance2 = tolerance2

    def GetResultTolerance1(self):
        return self._tolerance1

    def GetFunctionResult1(self):
        return self._result1

    def GetResultTolerance2(self):
        return self._tolerance2

    def GetFunctionResult2(self):
        return self._result2

    def GetTestCode(self, cnt):
        code="""
        def test_args%d(self):
            '%s'            
            self._test_2(%s, %s, (%s, %s), (%s, %s))

"""
        t_code = code %(cnt, self.GetTestText(),
                    self.GetFunctionArguments(), self.GetFunctionStatus(),
                    self.GetFunctionResult1(), self.GetResultTolerance1(),
                    self.GetFunctionResult2(), self.GetResultTolerance2(),
        )
        return t_code

    def __str__(self):
        fmt = "%s (%s, %s, (%s, %s), (%s, %s), %s)"
        msg = fmt  %(self._t_type, self._func, self._args,
                     self._result1, self._tolerance1,
                     self._result2, self._tolerance2,
                     self._status)
        return msg

_test_sf_type = "test_sf"
class test_sf_params(_test_sf_params):
    _t_type = _test_sf_type

_test_sf_type = "test_sf_rlx"
class test_sf_params_rlx(_test_sf_params):
    _t_type = _test_sf_type

_test_sf_type = "test_sf_theta"
class test_sf_params_theta(_test_sf_params):
    _t_type = _test_sf_type

_test_sf_type = "test_sf_2"
class test_sf_params_2(_test_sf_params_2):
    _t_type = _test_sf_type




