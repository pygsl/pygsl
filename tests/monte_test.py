#!/usr/bin/env python
import types
import pygsl._numobj as Numeric
import pygsl.monte as monte
import pygsl.rng

import unittest

def g(k, params):
    return k[0]

class _Basis:
    def _init_func(self):
        self.sys =  monte.gsl_monte_function(g, None, 1)
        self.r = pygsl.rng.mt19937_1999()
        self.xl = [ 0, ]
        self.xu = [ 1, ]
        self.exact = 0.5
        self.accepted_error = 0.1

    def _init_impl(self):
        assert(self._implementation)
        self.s = self._implementation(1)
        self.s.init()
    
class _Simple(_Basis, unittest.TestCase):
    _implementation = None
    def setUp(self):
        self._init_func()
        
    def testRun(self):
        self._init_impl()
        calls = 100
        res, err = self.s.integrate(self.sys, self.xl, self.xu, calls,
				    self.r)
        assert(Numeric.absolute(res - self.exact) < self.accepted_error)

class _Advanced(_Basis, unittest.TestCase):
    def setUp(self):
        self._init_func()
        self._init_impl()

    def testName(self):
        self.s.get_name()

    def _checkvariable(self, getm, setm, mytype, defaultvalue, testvalue):        
        self._checkvariable_readonly(getm, mytype, defaultvalue)
        self.s.set_alpha(testvalue)
        assert(self.s.get_alpha() == testvalue)

    def _checkvariable_readonly(self, getm, mytype, defaultvalue):
        assert(type(getm()) == mytype)
        var = getm()
        try:
            test = 0
            assert(var == defaultvalue)
            test = 1
        finally:
            if test == 0:
                print "Value of test variable was %s. I expected %s" %(var, defaultvalue)
                
class _Plain:
    _implementation = monte.plain

class _Miser:
    _implementation = monte.miser

class _Vegas:
    _implementation = monte.vegas

class PlainSimple(_Plain, _Simple):
    pass

class MiserSimple(_Miser, _Simple):
    pass

class VegasSimple(_Vegas, _Simple):
    pass

class PlainAdvanced(_Plain, _Advanced):
    pass

class MiserAdvanced(_Miser, _Advanced):
    def test_alpha(self):
        self._checkvariable(self.s.get_alpha, self.s.set_alpha, types.FloatType, 2.0, 1.0)
        
    def test_dither(self):
        self._checkvariable(self.s.get_dither, self.s.set_dither, types.FloatType, 0.0, 0.1)

    def test_estimate_frac(self):
        self._checkvariable(self.s.get_estimate_frac, self.s.set_estimate_frac, types.FloatType, 0.1, 2.1)

    def test_min_calls(self):
        self._checkvariable(self.s.get_min_calls, self.s.set_min_calls, types.IntType, 16*1, 5000)

    def test_min_calls_positive(self):   
        self.assertRaises(ValueError, self.s.set_min_calls, -1)

    def test_min_calls_per_bisection(self):
        self._checkvariable(self.s.get_min_calls_per_bisection, self.s.set_min_calls_per_bisection, types.IntType, 32*16*1, 5000)

    def test_min_calls_per_bisection_positive(self):   
        self.assertRaises(ValueError, self.s.set_min_calls_per_bisection, -1)

class VegasAdvanced(_Vegas, _Advanced):
    def test_result(self):
        calls = 100
	res, err = self.s.integrate(self.sys, self.xl, self.xu, calls,
                                       self.r)
        assert(type(self.s.get_result()) == types.FloatType)
        assert(Numeric.absolute(self.s.get_result() - res) < 0.01)
        
    def test_alpha(self):
        self._checkvariable(self.s.get_alpha, self.s.set_alpha, types.FloatType, 1.5, 1.9)

    def test_chisq(self):
        self._checkvariable_readonly(self.s.get_chisq, types.FloatType, 0.0)
        
    def test_iterations(self):
        self._checkvariable(self.s.get_iterations, self.s.set_iterations, types.IntType, 5, 1)

    def test_iterations_positive(self):   
        self.assertRaises(ValueError, self.s.set_iterations, -1)

    def test_mode(self):
        self._checkvariable(self.s.get_mode, self.s.set_mode, types.IntType,
                            monte.VEGAS_MODE_IMPORTANCE,
                            monte.VEGAS_MODE_IMPORTANCE_ONLY)
        
        self._checkvariable(self.s.get_mode, self.s.set_mode, types.IntType,
                            monte.VEGAS_MODE_IMPORTANCE,
                            monte.VEGAS_MODE_STRATIFIED)

    def test_stage(self):
        self._checkvariable(self.s.get_stage, self.s.set_stage, types.IntType, 0, 2)

    def test_verbose(self):
        self._checkvariable(self.s.get_stage, self.s.set_stage, types.IntType, 0, 2)

    def test_ostream(self):
        myfile = open('out', 'w')
        self.s.set_ostream(myfile)

        myfile = open('out', 'r')
        import sys
        self.s.set_ostream(sys.stderr)
        
del _Simple
del _Advanced
del _Plain
del _Miser
del _Vegas

if __name__ == '__main__':
    unittest.main()
