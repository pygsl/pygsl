#!/usr/bin/env python
import pygsl


import pygsl.qrng as qrng
import unittest
import pygsl._numobj as Numeric
import types
import string
import copy
from array_check import array_check
Float = pygsl.Float

class _QrngTest(unittest.TestCase):
    _type = None
    #def testType(self):
    #    self.assertRaises(TypeError, qrng.qrng, 2, 2)

    def testDims(self):
        self.assertRaises(ValueError, self._type, -1)

        
    def testName(self):
        q = self._type(2)
        name = q.name()
        assert(type(name) == types.StringType)
        test = 0
        name = string.replace(name, '-', '_')
        try:
            assert(name == self._name)
            test = 1
        finally:
            if test == 0:
                print "Expected name %s, but got name %s " % (name, self._name)

    def testGet(self):
        """
        self and call are calling the same C function. Just test if it is there
        """
        q = self._type(2)
        q.get(5)
        
    def testClone(self):
        q = self._type(1)
        q1 = q.clone()
        for i in range(10):
            t1 = q1()
            t = q()
            assert(len(t1) == len(t))
            for j in range(len(t1)):
                assert(t[0,j] == t1[0,j])


    def setUp(self):
        self.qrng = self._type(self._dim)

    def __testreturn(self, array, dim0):
        test = 0
        array_check(array, Float, (dim0, self._dim))
                        
    def testGet(self):
        tmp = self.qrng()
        self.__testreturn(tmp, 1)
        for i in (Numeric.arange(10) + 1):
            tmp = self.qrng(i)
            self.__testreturn(tmp, i)

class Sobol:
    _name = "sobol"
    def _type(self, dim):
        return qrng.sobol(dim)

class Niederreiter:
    _name = "niederreiter_base_2"
    def _type(self, dim):
        return qrng.niederreiter_base_2(dim)

    
class _Dim1:    _dim = 1
class _Dim2:    _dim = 2
class _Dim3:    _dim = 3
class _Dim4:    _dim = 4
class _Dim5:    _dim = 5
class _Dim6:    _dim = 6
class _Dim7:    _dim = 7
class _Dim8:    _dim = 8
class _Dim9:    _dim = 9
class _Dim10:    _dim = 10
class _Dim11:    _dim = 11
class _Dim12:    _dim = 12


class QRNGTestSobol1(_Dim1, Sobol, _QrngTest): pass
class QRNGTestSobol2(_Dim2, Sobol, _QrngTest): pass
class QRNGTestSobol3(_Dim3, Sobol, _QrngTest): pass
class QRNGTestSobol4(_Dim4, Sobol, _QrngTest): pass
class QRNGTestSobol5(_Dim5, Sobol, _QrngTest): pass
class QRNGTestSobol6(_Dim6, Sobol, _QrngTest): pass
class QRNGTestSobol7(_Dim7, Sobol, _QrngTest): pass
class QRNGTestSobol8(_Dim8, Sobol, _QrngTest): pass
class QRNGTestSobol9(_Dim9, Sobol, _QrngTest): pass
class QRNGTestSobol10(_Dim10, Sobol, _QrngTest): pass
class QRNGTestSobol11(_Dim11, Sobol, _QrngTest): pass
class QRNGTestSobol12(_Dim12, Sobol, _QrngTest): pass

class QRNGTestNiederreiter1(_Dim1,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter2(_Dim2,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter3(_Dim3,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter4(_Dim4,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter5(_Dim5,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter6(_Dim6,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter7(_Dim7,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter8(_Dim8,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter9(_Dim9,   Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter10(_Dim10, Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter11(_Dim11, Niederreiter, _QrngTest): pass
class QRNGTestNiederreiter12(_Dim12, Niederreiter, _QrngTest): pass

del Sobol
del Niederreiter
del _QrngTest

if __name__ == '__main__':
    unittest.main()

