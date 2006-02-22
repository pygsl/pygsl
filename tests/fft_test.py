import sys
sys.stdout = sys.stderr
import unittest
import pygsl
import pygsl.fft as fft
pygsl.set_debug_level(0)
import pygsl._numobj as Numeric
import pygsl._mlab as MLab
from pygsl.math import fcmp

from array_object_functions import get_type_code
_eps = 1e-8

class _ffttest(unittest.TestCase):
    # Type of the array
    typecode = None
    def _CheckSinResult(self, f, l):
        a = Numeric.absolute(f)
        test = 0
        tmp1 = None
        tmp2 = None
        try:
            tmp1 = f[l].imag
            tmp2 = self.sin_n
            assert(fcmp(f[l].imag, self.sin_n, self._eps) == 0)
            a[l] = 0
            if(len(f) > self.n/2 + 1):
                # Only for the complex transform
                tmp1 = f[self.n-l].imag
                tmp2 = self.sin_n_l
                assert(fcmp(tmp1, tmp2, self._eps) == 0)
                a[self.n-l] = 0
            test = 1
        finally:
            if test == 0:
                print 
                print "Check Sin Result len(f) = %s, self.n/2 = %s", len(f), self.n/2                
                print f[l]
                print "tmp1 = %s, tmp2 = %s" % (tmp1, tmp2)
                #print f[self.n-l]
                
        # Take the maximum
        test = 0
        try:
            assert(MLab.max(a) < self._eps)
            test = 1
        finally:
            if test == 0:
                print a, MLab.max(a)

    def _CheckCosResult(self, f, l):
        # Take all data
        a = Numeric.absolute(f)
        assert(fcmp(f[l].real, self.n/2, self._eps) == 0)
        a[l] = 0
        if(len(f) > self.n/2 + 1):
                # Only for the complex transform
                assert(fcmp(f[self.n-l].real, self.n/2, self._eps) == 0)
                a[self.n-l] = 0
        # Take the maximum


        test = 0
        try:
            assert(MLab.max(a) < self._eps)
            test = 1
        finally:
            if test == 0:
                print "Check Cos Result",
                print a, MLab.max(a)
        
    def SinOne(self, x, l, args=()):
        y = Numeric.sin(x * l)
        tmp = self.convert(y)
        f = self.transform(*((tmp,) + args))
        self._CheckSinResult(f, l)

    def CosOne(self, x, l, args=()):
        y = Numeric.cos(x * l)
        tmp = self.convert(y)
        f = self.transform(*((tmp,) + args))
        self._CheckCosResult(f, l)
        
    def testSin(self):        
        x = Numeric.arange(self.n) * (2 * Numeric.pi / self.n)
        for i in range(1,self.n/2):
           self.SinOne(x,i)

    def testCos(self):        
        x = Numeric.arange(self.n) * (2 * Numeric.pi / self.n)
        for i in range(1,self.n/2):
            if self.__class__.__name__ == "testrealforwardradix2float":
                pygsl.set_debug_level(0)
            try:                
                self.CosOne(x,i)
            finally:
                pygsl.set_debug_level(0)
                
class _radix2(_ffttest):
    pass

class _mixedradix(_ffttest):
    def testSinSpace(self):        
        x = Numeric.arange(self.n) * (2 * Numeric.pi / self.n)
        space = self.workspace(self.n)
        assert(space.get_n() == self.n)
        table = self.wavetable(self.n)
        assert(table.get_n() == self.n)
        for i in range(1,self.n/2):
           self.SinOne(x,i, (space,table))

    def testCosSpace(self):        
        x = Numeric.arange(self.n) * (2 * Numeric.pi / self.n)
        space = self.workspace(self.n)
        assert(space.get_n() == self.n)
        table = self.wavetable(self.n)
        assert(table.get_n() == self.n)
        for i in range(1,self.n/2):
           self.CosOne(x,i, (space,table))

class _mixedradixcomplex(_mixedradix):
    def testSinReturnSaveSpaces(self):
        space = self.workspace(self.n)
        table = self.wavetable(self.n)
        x = Numeric.arange(self.n) * ((2+0j) * Numeric.pi / self.n)
        for i in range(1,self.n/2):
            y = Numeric.sin(x * i)
            tmp = self.convert(y)
            f = self.transform(tmp, space, table, tmp)
            self._CheckSinResult(f, i)

class DoubleType:
    _eps = 1e-8
    def convert(self, y):
        return y

class FloatType:
    _eps = 1e-4
    def convert(self, y):
        if get_type_code(y) in  Numeric.typecodes['Float']:
            return y.astype(Numeric.Float32)
        elif y.typecode() in  Numeric.typecodes['Complex']:
            return y.astype(Numeric.Complex32)
        else:
            raise TypeError, "Not implemented for an array of type", y.typecode
        
class number:
    n = 64
    sin_n = - n / 2
    sin_n_l = n / 2

class numberbackward:
    n = 64
    sin_n =  n / 2
    sin_n_l = - n / 2

class numbermixedradix:
    n = 2 * 3 * 5 * 7
    sin_n = - n / 2
    sin_n_l = n / 2

class numberinverse(numberbackward):
    pass

class complexspace:
    wavetable = fft.complex_wavetable
    workspace = fft.complex_workspace

class realspace:
    wavetable = fft.real_wavetable
    workspace = fft.real_workspace

class complexspacefloat:
    wavetable = fft.complex_wavetable_float
    workspace = fft.complex_workspace_float

class realspacefloat:
    wavetable = fft.real_wavetable_float
    workspace = fft.real_workspace_float

class testcomplexbackwardradix2(_radix2, numberbackward, DoubleType):
    transform = fft.complex_radix2_backward

class testcomplexbackwardradix2dif(_radix2, numberbackward, DoubleType):
    transform = fft.complex_radix2_dif_backward

class testcomplexinverseradix2(_radix2, numberinverse, DoubleType):
    transform = fft.complex_radix2_backward

class testcomplexinverseradix2dif(_radix2, numberinverse, DoubleType):
    transform = fft.complex_radix2_dif_backward

class testcomplexforwardradix2(_radix2, number, DoubleType):
    transform = fft.complex_radix2_forward

class testcomplexforwardradix2dif(_radix2, number, DoubleType):
    transform = fft.complex_radix2_dif_forward

class testcomplexbackward64(_mixedradixcomplex, complexspace, numberbackward, DoubleType):
    transform = fft.complex_backward

class testcomplexinverse64(_mixedradixcomplex, complexspace, numberinverse, DoubleType):
    transform = fft.complex_backward



class testcomplexforward64(_mixedradixcomplex, complexspace, number, DoubleType):
    transform = fft.complex_forward


class testcomplexforward(_mixedradixcomplex, complexspace, numbermixedradix, DoubleType):
    transform = fft.complex_forward


class testrealforward(_mixedradix, realspace, numbermixedradix, DoubleType):
    transform = fft.real_transform

class testrealforwardradix2(_radix2, realspace, number, DoubleType):    
    def transform(self, x):
        return fft.halfcomplex_radix2_unpack(fft.real_radix2_transform(x))

class testcomplexbackwardradix2float(_radix2, numberbackward, FloatType):
    transform = fft.complex_radix2_backward_float

class testcomplexbackwardradix2diffloat(_radix2, numberbackward, FloatType):
    transform = fft.complex_radix2_dif_backward_float

class testcomplexinverseradix2float(_radix2, numberinverse, FloatType):
    transform = fft.complex_radix2_backward_float

class testcomplexinverseradix2diffloat(_radix2, numberinverse, FloatType):
    transform = fft.complex_radix2_dif_backward_float

class testcomplexforwardradix2float(_radix2, number, FloatType):
    transform = fft.complex_radix2_forward_float

class testcomplexforwardradix2diffloat(_radix2, number, FloatType):
    transform = fft.complex_radix2_dif_forward_float

class testcomplexbackward64float(_mixedradixcomplex, complexspacefloat, numberbackward, FloatType):
    transform = fft.complex_backward_float

class testcomplexinverse64float(_mixedradixcomplex, complexspacefloat, numberinverse, FloatType):
    transform = fft.complex_backward_float



class testcomplexforward64float(_mixedradixcomplex, complexspacefloat, number, FloatType):
    transform = fft.complex_forward_float


class testcomplexforwardfloat(_mixedradixcomplex, complexspacefloat, numbermixedradix, FloatType):
    transform = fft.complex_forward_float


class testrealforwardfloat(_mixedradix, realspacefloat, numbermixedradix, FloatType):
    transform = fft.real_transform_float

class testrealforwardradix2float(_radix2, realspacefloat, number, FloatType):    
    def transform(self, x):
        tmp = self.convert(x)
        return fft.halfcomplex_radix2_unpack_float(fft.real_radix2_transform_float(tmp))

del _ffttest
del _radix2
del _mixedradix
del _mixedradixcomplex

if __name__ == '__main__':
    unittest.main()
