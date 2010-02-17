#!/usr/bin/env python
import unittest
import pygsl._numobj as Numeric
from pygsl import spline, interpolation, errors

class _test_common(unittest.TestCase):
    def setUp(self):
        x  = Numeric.arange(100)
        y  = 2 * x + 1
        self.x  = x
        self.y1 = y[:80]
        self.interp = self._testtype(100)
        self.interp.init(x,y)

    def test_wrong_init(self):
        self.assertRaises(errors.gsl_BadLength, self.interp.init, self.x, self.y1)
        
    def test_name(self):
        self.interp.name()

       
    def test_eval_e(self):
        v = self.interp.eval_e(10)
        assert(v==21)
        
    def test_eval_deriv_e(self):
        v = self.interp.eval_deriv_e(10)

        assert(v==2)
        
    def test_eval_deriv2_e(self):
        v = self.interp.eval_deriv2_e(10)

        assert(v==0)
        
    def test_eval_integ_e(self):
        v = self.interp.eval_integ_e(0,10)
        assert(v==110)

        
    def test_accel_reset(self):
        t = self.interp.accel_reset()
        assert(t==None)
        
    def test_accel_find(self):
        v = self.interp.accel_find(10.5)
        assert(v==10)
        
    def test_bsearch(self):
        v = interpolation.bsearch(self.x, 10.5, 3, 30)
        assert(v==10)

    #def test_bsearch_0_false(self):
    #    self.assertRaises(ValueError, self.interp.bsearch, 10.5, 3, 300)

    #def test_bsearch_1_false(self):
    #    self.assertRaises(ValueError, self.interp.bsearch, 10.5, -3, 300)

    
    def test_eval(self):
        v = self.interp.eval(10)
        assert(v==21)

    def test_eval_wrong(self):
        v = self.interp.eval(10)
        assert(v==21)
    
    def test_eval_deriv(self):
        v = self.interp.eval_deriv(10)
        assert(v==2)
        
    def test_eval_deriv2(self):
        v = self.interp.eval_deriv2(10)
        assert(v==0)
        
    def test_eval_integ(self):
        v = self.interp.eval_integ(0,10)
        assert(v==110)
    
class _interp_test(_test_common):
    def test_min_size(self):
        tmp = self.interp.min_size()
        assert(tmp>0)
    pass

class _spline_test(_test_common):
    pass

class interpolation_linear            (_interp_test): _testtype = interpolation.linear
class interpolation_polynomial        (_interp_test): _testtype = interpolation.polynomial      
class interpolation_cspline           (_interp_test): _testtype = interpolation.cspline         
class interpolation_cspline_periodic  (_interp_test): _testtype = interpolation.cspline_periodic
class interpolation_akima             (_interp_test): _testtype = interpolation.akima           
class interpolation_akima_periodic    (_interp_test): _testtype = interpolation.akima_periodic  

class spline_linear            (_spline_test): _testtype = spline.linear          
class spline_polynomial        (_spline_test): _testtype = spline.polynomial      
class spline_cspline           (_spline_test): _testtype = spline.cspline         
class spline_cspline_periodic  (_spline_test): _testtype = spline.cspline_periodic
class spline_akima             (_spline_test): _testtype = spline.akima           
class spline_akima_periodic    (_spline_test): _testtype = spline.akima_periodic  

del _test_common
del _interp_test
del _spline_test

if __name__ == '__main__':
    unittest.main()

