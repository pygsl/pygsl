# Author : Fabian Jakobs
import types
import unittest
import MLab
import pygsl.math 
from Numeric import *

fcmp = pygsl.math.fcmp

def fpcompare(a, b, digits):
    result = 1
    ac = type(a) is types.ComplexType
    bc = type(b) is types.ComplexType
    if ac and bc:
        res1 = (fcmp(a.real, b.real, 10**-digits) == 0)
        res2 = (fcmp(a.imag, b.imag, 10**-digits) == 0)
        result = res1 and res2
    elif ac and not bc:
        res1 = (fcmp(a.real, b, 10**-digits) == 0)
        res2 = (fcmp(a.imag, 0, 10**-digits) == 0)
        result = res1 and res2
    elif not ac and bc:
        res1 = (fcmp(a, b.real, 10**-digits) == 0)
        res2 = (fcmp(0, b.imag, 10**-digits) == 0)
        result = res1 and res2
    else:
        result = (fcmp(a, b, 10**-digits) == 0)
    return result

def arrayCompare(a, l, digits):
    result = 1 # true
    for i in range(len(l)):
        result = result and fpcompare(a[i], l[i], digits)
        if not result: print "Fehler: %s \t %s" % (a[i], l[i])
    return result

def arrayIsZero(a):
    result = 1
    return MLab.max(absolute(ravel(a))) < 1e-8


def herm(A):
    return transpose(conjugate(A))

class GSLTestCase(unittest.TestCase):
    def setUp(self):
        self.v1_4 = array([-13, 2.45, 4, 23])
        self.v2_4 = array([42, -2.55, 1, 19.23])
        self.vz1_4 = array([-13, 2.45+3j, 4, 23])
        self.vz2_4 = array([42, -2.55, 1, 19.23+1.4j])
        self.m1_4 = array([[1.123,2,3,4],
                           [5,6,7,8],
                           [9,10,11,12],
                           [13,14,15,-16]])
        self.m2_4 = array([[1.155,33,3,22],
                           [5,6,-12.5,8],
                           [701.3,10,31,12],
                           [13,14,15,-16]])
        self.mz1_4 = array([[1.123,2,3,4],
                           [5+3j,6,7,8],
                           [9,10,11-12.3j,12],
                           [13,14,15,-16]])
        self.mz2_4 = array([[1.123,22,3,4-1.44j],
                           [5+3j,6,71,8j],
                           [9,-10,11-12.3j,12],
                           [13+2j,14,15,-16]])
        self.symm = array([[1,2,6,-1.2],
                           [2,-3.4,6,77],
                           [6,6,77,-1],
                           [-1.2,77,-1,23]])
        self.symmz = array([[1,2+2j,6,-1.2],
                           [2+2j,-3.4,6,77],
                           [6,6,77-2.3j,-1],
                           [-1.2,77,-1,23]])
        self.triang = array([[1,0,0,0],
                           [2,-3.4,0,0],
                           [6,6,77,0],
                           [-1.2,77,-1,23]])
        self.triangz = array([[1,0,0,0],
                           [2+3j,-3.4,0,0],
                           [6j,6,77,0],
                           [-1.2,77-1.44j,-1,23]])
        self.herm = array([[1,    2,    6,   -1.2],
                           [2,   -3.4,  6,    77],
                           [6,    6,    77,  -1],
                           [-1.2, 77,  -1,    23]], Complex)
