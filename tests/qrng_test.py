#!/usr/bin/env python
import pygsl._qrng as qrng
import unittest
import Numeric
import types
import string
import copy



class _QRNGType:
    _type = None

class Sobol(_QRNGType):
    _type = qrng.sobol
    _name = 'sobol'
    
class Niederreiter(_QRNGType):
    _type = qrng.niederreiter_base_2
    _name = 'niederreiter_base_2'
    
class _QrngTestBasics(unittest.TestCase):
    def testType(self):
        self.assertRaises(TypeError, qrng.qrng, 2, 2)

    def testDims(self):
        self.assertRaises(ValueError, qrng.qrng, self._type, -1)

        
    def testName(self):
        q = qrng.qrng(self._type, 2)
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
        q = qrng.qrng(self._type, 2)
        q.get(5)
        
    def testClone(self):
        q = qrng.qrng(self._type, 1)
        q1 = q.clone()
        for i in range(10):
            assert(q1() == q())

    def testCopy(self):
        """
        Using clone I should be able to make a copy ...
        """
        q = qrng.qrng(self._type, 1)
        q1 = copy.copy(q)
        for i in range(10):
            assert(q1() == q())

            
class _QrngTest(unittest.TestCase):
    def setUp(self):
        self.qrng = qrng.qrng(self._type, self._dim)

    def __testreturn(self, array, dim0):
        test = 0
        try:
            assert(type(array) == Numeric.ArrayType)
            assert(len(array.shape) == 2)
            assert(array.shape[1] == self._dim)
            assert(array.shape[0] == dim0)
            test = 1
        finally:
            if test == 0:
                print "Got type ", type(array),
                print "with shape ", array.shape,
                print "Expected shape ", dim0, self._dim
                
    def testGet(self):
        tmp = self.qrng()
        self.__testreturn(tmp, 1)
        for i in (Numeric.arange(10) + 1):
            tmp = self.qrng(i)
            self.__testreturn(tmp, i)

class TestSobolBasics(_QrngTestBasics, Sobol): pass
class TestNiederreiterBasics(_QrngTestBasics, Niederreiter): pass
    
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

del _QrngTestBasics
del _QRNGType
del Sobol
del Niederreiter
del _QrngTest

if __name__ == '__main__':
    unittest.main()

