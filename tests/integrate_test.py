#!/usr/bin/env python
# Author : Pierre Schnizer

import unittest
import pygsl._numobj as Numeric
import pygsl
from pygsl import  integrate


class IntegrateTest(unittest.TestCase):
    def setUp(self):        
        self.w = integrate.workspace(1000000)

    def test_1_qags(self):
        expected = -4.0
        def f(x, params):
            alpha = params
            return Numeric.log(alpha *x) / Numeric.sqrt(x)
        self.sys = integrate.gsl_function(f, 1)
        flag, result, error = integrate.qags(self.sys, 0, 1, 0, 1e-7, 1000,
                                             self.w, )
        assert(Numeric.absolute(result - expected) < 1e-7)
        assert(Numeric.absolute(error) < 1e-7)
        self.w.get_size()

    def test_0_qagi(self):
        expected = Numeric.pi
        def f1(x,y):
            return 1. / (1. + x ** 2)
        sys = integrate.gsl_function(f1, None)
        flag, result, error = integrate.qagi(sys, 1e-8, 1e-8, 1000000, self.w)
        #print result
        assert(Numeric.absolute(result - expected) < 1e-7)
        assert(Numeric.absolute(error) < 1e-7)
        self.w.get_size()

    def test_0_qagiu(self):
        expected = 1./2.
        def f1(x,y):
            return 1. / (1.* x**2)
        
        sys = integrate.gsl_function(f1, None)
        flag, result, error = integrate.qagiu(sys, 2, 1e-8, 1e-8, 1000000, self.w)
        assert(Numeric.absolute(result - expected) < 1e-7)
        assert(Numeric.absolute(error) < 1e-7)
        self.w.get_size()

    def test_0_qagil(self):
        expected = 1./2.
        def f1(x,y):
            return 1. / (1.* x**2)
        
        sys = integrate.gsl_function(f1, None)
        test = 0
        try:
            flag, result, error = integrate.qagil(sys, -2, 1e-8, 1e-8, 1000000, self.w)
            test = 1
        finally:
            if test == 0:
                print integrate.qagil(sys, -2, 1e-8, 1e-8, 1000000, self.w)
        assert(Numeric.absolute(result - expected) < 1e-7)
        assert(Numeric.absolute(error) < 1e-7)
        self.w.get_size()

    def test_qawc(self):
        pass
    
    def test_qwas(self):
        pass
    
    def test_qawo(self):
        def f(x,y):
            return 1
        sys = integrate.gsl_function(f, None)
        table = integrate.qawo_table(1, 2*Numeric.pi, integrate.COSINE, 100)
        flag, result, error = integrate.qawo(sys, -Numeric.pi, 1e-8,  1e-8, 100, self.w, table)
        assert(Numeric.absolute(result) < 1e-7)
        assert(Numeric.absolute(error) < 1e-7)
        
    def test_qawf(self):
        def f2(x,y):
            return Numeric.sin(x) / x
        sys2 = integrate.gsl_function(f2, None)
        def f1(x,y):
            return 1 / x        
        sys1 = integrate.gsl_function(f1, None)
        def f3(x,y):
            return 1 / -x        
        sys3 = integrate.gsl_function(f3, None)
        
        pts = Numeric.array((-Numeric.pi, 0, Numeric.pi))
        flag, result1, error = integrate.qagp(sys2, pts, 1e-8, 1e-8, 100000, self.w)
        table1 = integrate.qawo_table(1, 100, integrate.SINE, 100)        
        cyclew = integrate.workspace(1000000)
        flag, result2, error = integrate.qawf(sys1, Numeric.pi, 1e-8,  100, self.w, cyclew, table1)
        table2 = integrate.qawo_table(-1, 100, integrate.SINE, 100)        
        flag, result3, error = integrate.qawf(sys3, Numeric.pi, 1e-8,  100, self.w, cyclew, table2)
        assert(Numeric.absolute(result1+result2+result3 - Numeric.pi) < 1e-8)

    
    def test_qagp(self):
        def f1(x,y):
            return x / x
        sys = integrate.gsl_function(f1, None)
        pts = Numeric.array((-1, 0, 1))
        flag, result, error = integrate.qagp(sys, pts, 1e-8, 1e-8, 100000, self.w)
        assert(Numeric.absolute(result - 2.) < 1e-3)
        assert(error<1e-8)


    def run_qag(self, method):
        def f1(x,y):
            return Numeric.sin(x)
        sys = integrate.gsl_function(f1, None)
        flag, result, error = integrate.qag(sys, 0, Numeric.pi, 1e-8, 1e-8, 1000, method, self.w)
        assert(Numeric.absolute(result - 2) < 1e-7)
        assert(error<1e-8)

    def test_qag_61(self):
        self.run_qag(integrate.GAUSS61)

    def test_qag_51(self):
        self.run_qag(integrate.GAUSS51)

    def test_qag_41(self):
        self.run_qag(integrate.GAUSS41)
        
    def test_qag_31(self):
        self.run_qag(integrate.GAUSS31)

    def test_qag_21(self):
        self.run_qag(integrate.GAUSS21)

    def test_qag_15(self):
        self.run_qag(integrate.GAUSS15)
    
    def test_qng(self):
        def f1(x,y):
            return Numeric.sin(x)
        sys = integrate.gsl_function(f1, None)
        flag, result, error, method = integrate.qng(sys, 0, Numeric.pi, 1e-8, 1e-8)
        assert(Numeric.absolute(result - 2) < 1e-7)
        assert(error<1e-8)


if __name__ == '__main__':
    unittest.main()
