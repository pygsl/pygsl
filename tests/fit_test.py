#!/usr/bin/env python
# Author : Pierre Schnizer 
import unittest

import pygsl
from pygsl import fit
from pygsl import multifit
import pygsl._numobj as Numeric


class FitTest(unittest.TestCase):
    _eps = 1e-8
    def setUp(self):
        self.a = 1000.1
        self.b = 100
        self.x = Numeric.arange(100)
        self.y = self.a + self.b * self.x
        self.w = Numeric.ones(100) * 1000000


    def test_0_linear(self):
        c0, c1, c00, c01, c10, sumsq =  fit.linear(self.x, self.y)
        assert(Numeric.absolute(c0 - self.a)<self._eps)
        assert(Numeric.absolute(c1 - self.b)<self._eps)
        y, yerr =  fit.est(1, c0, c1, c00, c01, c10)
        assert(Numeric.absolute(y - (self.a+self.b*1)) < self._eps)
        assert(Numeric.absolute(yerr) < self._eps)
        

        
    def test_1_wlinear(self):
        c0, c1, c00, c01, c10, chisq = fit.wlinear(self.x, self.w, self.y)
        assert(Numeric.absolute(c0 - self.a)<self._eps)
        assert(Numeric.absolute(c1 - self.b)<self._eps)
        y, yerr =  fit.est(1, c0, c1, c00, c01, c10)
        assert(Numeric.absolute(y - (self.a+self.b*1)) < self._eps)

class FitMulTest(unittest.TestCase):
    _eps = 1e-8
    def setUp(self):
        self.a = 0.0
        self.b = 100
        self.x = Numeric.arange(100)
        self.y = self.a + self.b * self.x
        self.w = Numeric.ones(100) * 1000000


    def test_0_linear(self):
        c1, c11, sumsq =  fit.mul(self.x, self.y)
        assert(Numeric.absolute(c1 - self.b)<self._eps)
        y, yerr =  fit.mul_est(1, c1, c11)
        assert(Numeric.absolute(y - (self.a+self.b*1)) < self._eps)
        assert(Numeric.absolute(yerr) < self._eps)
        

        
    def test_1_wlinear(self):
        c1,  c11, chisq = fit.wmul(self.x, self.w, self.y)
        assert(Numeric.absolute(c1 - self.b)<self._eps)
        y, yerr =  fit.mul_est(1, c1, c11)
        assert(Numeric.absolute(y - (self.a+self.b*1)) < self._eps)


        
class MultiFitTest(unittest.TestCase):
    _eps = 1e-10
    def setUp(self):
        self.dim   = 100
        self.param = 2
        self.a = 1000.1
        self.b = 100        
        self.x = Numeric.arange(self.dim)
        x = self.x
        self.y = self.a + self.b * self.x
        self.w = Numeric.ones((self.dim,))
        self.ws = multifit.linear_workspace(self.dim, self.param)
        self.X = Numeric.transpose(Numeric.array((Numeric.ones(self.dim,), x)))

    
    def test_linear(self):
        c, cov, chisq = multifit.linear(self.X, self.y, self.ws)
        assert(Numeric.absolute(c[0] - self.a) < self._eps)
        assert(Numeric.absolute(c[1] - self.b) < self._eps)

    def test_wlinear(self):
        c, cov, chisq = multifit.wlinear(self.X, self.w, self.y, self.ws)
        assert(Numeric.absolute(c[0] - self.a) < self._eps)
        assert(Numeric.absolute(c[1] - self.b) < self._eps)

        
if __name__ == '__main__':
    unittest.main()
