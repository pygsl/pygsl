#!/usr/bin/env python
# Author : Pierre Schnizer 
import types
import pygsl._numobj as Numeric
from pygsl import poly
import unittest
from gsl_test import iscomplex

_eps = 1e-8
class TestPoly(unittest.TestCase):
    def test_poly_eval(self):
        c = Numeric.ones((3,))
        x = 2
        assert(poly.poly_eval(c,x) == 7.0)

class TestPolyDD(unittest.TestCase):
    def setUp(self):
        xa = Numeric.arange(100) / 100.0 * 2. * Numeric.pi
        ya = Numeric.sin(xa)
        self.dd = poly.poly_dd(xa, ya)
        
    def test_1_poly_dd(self):    
        assert(self.dd.eval(0) == 0.0)
        
    def test_2_poly_dd(self):    
        assert(Numeric.absolute(self.dd.eval(Numeric.pi)) < _eps)

    def test_3_poly_dd(self):    
        assert(Numeric.absolute(self.dd.eval(Numeric.pi/2)-1)  < _eps)

    def test_4_poly_dd(self):    
        c = self.dd.taylor(0.0)

class TestQuadratic(unittest.TestCase):
    def test_double(self):
        test = 0
        try:
            tmp, r1, r2 = poly.solve_quadratic(1,3,2)
            test = 1
        finally:
            if test == 0:
                print  poly.solve_quadratic(1,3,2)
        assert(tmp == 2)
        assert(r1 == -2 or r2 == -2)
        assert(r1 == -1 or r2 == -1)
        
    def test_complex(self):
        test = 0
        try:
            tmp, r1, r2 = poly.complex_solve_quadratic(1,3,2)
            test = 1
        finally:
            if test == 0:
                print poly.complex_solve_quadratic(1,3,2)
        assert(tmp == 2)
        
        assert(type(r1) == types.ComplexType)
        assert(type(r2) == types.ComplexType)
        assert(r1 == -2 or r2 == -2)
        assert(r1 == -1 or r2 == -1)

class TestCubic(unittest.TestCase):
    def test_cubic_double(self):
        test = 0
        try:
            tmp, r1, r2, r3 = poly.solve_cubic(6,11,6)
            test = 1
        finally:
            if test == 0:
                print poly.solve_cubic(6,11,6)                
        assert(tmp == 3)
        assert(r1 == -2 or r2 == -2 or r3 == -2)
        assert(r1 == -1 or r2 == -1 or r3 == -1)
        assert(r1 == -3 or r2 == -3 or r3 == -3)

    def test_cubic_complex(self):        
        tmp, r1, r2, r3 = poly.complex_solve_cubic(6,11,6)
        assert(tmp == 3)
        assert(type(r1) == types.ComplexType)
        assert(type(r2) == types.ComplexType)
        assert(type(r3) == types.ComplexType)
        assert(r1 == -2 or r2 == -2 or r3 == -2)
        assert(r1 == -1 or r2 == -1 or r3 == -1)
        assert(r1 == -3 or r2 == -3 or r3 == -3) 

class TestCubicWorkspace(unittest.TestCase):
    def setUp(self):
        self.pc = poly.poly_complex(3)

    def test_poly_workspace1(self):
        pc = self.pc

    def test_poly_workspace(self):
        pc = self.pc
        rs = pc.solve((2,3,1))
        r1 = rs[0]
        r2 = rs[1]
        
        assert(iscomplex(r1))
        assert(iscomplex(r2))
        assert(r1 == -2 or r2 == -2)
        assert(r1 == -1 or r2 == -1)
    
def test():
    unittest.main()


    
if __name__ == '__main__':
    test()
