#!/usr/bin/env python
# Author : Pierre Schnizer 
import types
import tempfile
import pygsl
import pygsl._numobj as nummodule
from pygsl import vector, ArrayType
from pygsl import matrix_pierre
matrix = matrix_pierre

from pygsl import _block, get_typecode
from array_check import myord, myorda, array_check

import unittest
import sys
sys.stderr = sys.stdout
#pygsl.set_debug_level(10)
    
def getopentmpfile(mode='rb'):
    file = tempfile.TemporaryFile(mode)
    assert(type(file.file) == types.FileType)
    return file.file

class _DefaultTestCase(unittest.TestCase):
    _type     = ''
    _base     = None
    _reference_value = 137
    #_retrieve = None
    
    def setUp(self):
	#print "Testing class ", self.__class__.__name__
        sys.stdout.flush()
        sys.stderr.flush()
        self._mysetUp()

    def _get_reference_value(self):
        return self._reference_value
    
    def _get_format(self):
        return self._format
    
    def _get_function_direct(self, suffix=None):
        """
        translate some prefix to the full qualified name of the block
        """
        if suffix == None:
            suffix = self.function

        if self._type == '':
            tmp = '_'
        else:
            tmp = '_' + self._type + '_'
        # base is matrix or vector or .....
        assert self._base != None, 'Use a derived class!'
        base =  self._base
        function = eval('_block.gsl_' + base + tmp + suffix)        
        return function
    
    def _get_function_ui(self, suffix=None):
        """
        Get the method to the underlying function from the UI.
        """
        if suffix == None:
            suffix = self.function

        if self._type == '':            tmp = '.'
        else:
            tmp = '.' + self._type + '.'
        # base is matrix or vector or .....
        assert self._base != None, 'Use a derived class!'
        base =  self._base
        function = eval(base + tmp + suffix)        
        return function

    def _get_function(self, suffix=None):
        if self._retrieve == 'direct':
            return self._get_function_direct(suffix)
        elif self._retrieve == 'UI':
            return self._get_function_ui(suffix)
        else:
            tmp = str(self._retrieve)
            raise ValueError, "Unknown switch for _retrieve: " + tmp
        
    def test_0_matrixtype(self):
        test = 0
        try:
            assert type(self.array) == ArrayType, "Not an array type"
            test = 1
        finally:
            if test == 0:
                print "Expected a type of %s but got a type of %s" %(ArrayType, type(self.array))
    def tearDown(self):
        self._mytearDown()

class _DirectAccess:
    _retrieve = 'direct'
class _UIAccess:
    _retrieve = 'UI'

    
class _DefaultMatrixTestCase(_DefaultTestCase):
    _base = 'matrix'

class _DefaultVectorTestCase(_DefaultTestCase):
    _base = 'vector'

class _DoubleMatrixTestCase(_DefaultMatrixTestCase):
    _type = ''
    _format   = '%f'
    
class _FloatMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'float'
    _format   = '%f'
    
class _ComplexMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'complex'
    _format   = '%f'
    
class _ComplexFloatMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'complex_float'
    _format   = '%f'
    
class _LongMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'long'
    _format   = '%ld'
    
class _IntMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'int'
    _format   = '%d'
    
class _ShortMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'short'
    _format   = '%d'

class _CharMatrixTestCase(_DefaultMatrixTestCase):
    _type = 'char'
    _format   = '%c'
    
class _DoubleVectorTestCase(_DefaultVectorTestCase):
    _type = ''
    _format   = '%f'

class _FloatVectorTestCase(_DefaultVectorTestCase):
    _type = 'float'
    _format   = '%f'
    
class _ComplexVectorTestCase(_DefaultVectorTestCase):
    _type = 'complex'
    _format   = '%f'
    
class _ComplexFloatVectorTestCase(_DefaultVectorTestCase):
    _type = 'complex_float'
    _format   = '%f'
    
class _LongVectorTestCase(_DefaultVectorTestCase):
    _type = 'long'
    _format   = '%ld'
    
class _IntVectorTestCase(_DefaultVectorTestCase):
    _type = 'int'
    _format   = '%d'
    
class _ShortVectorTestCase(_DefaultVectorTestCase):
    _type = 'short'
    _format   = '%d'
    
class _CharVectorTestCase(_DefaultVectorTestCase):
    _type = 'char'
    _format   = '%c'
    _reference_value = chr(137)
    
class _SetIdentityMatrixTestCase(_DefaultMatrixTestCase):
    function = 'set_identity'
    size = 10

    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size))
                    
    def test_1_matrixsize(self):
        array_check(self.array, None, (self.size, self.size))

    def test_2_diagonale(self):
        for i in range(self.size):
            assert self.array[i,i] == 1, "Diagonale not one !"

    def test_3_diagonale(self):
        for i in range(self.size):
            for j in range(self.size):
                if i == j :
                    continue                
                assert self.array[i,j] ==  0, "Of Diagonale not zero!"
        
    def _mytearDown(self):
        del self.array
        self.array = None
        

class SetIdentityMatrixTestCase(_DoubleMatrixTestCase,
                                _DirectAccess,
                                _SetIdentityMatrixTestCase,
                                ):
    pass

class SetIdentityMatrixUITestCase(_DoubleMatrixTestCase,
                                  _UIAccess,
                                  _SetIdentityMatrixTestCase,
                                  ):
    pass

class SetIdentityFloatMatrixTestCase(_FloatMatrixTestCase,
                                     _DirectAccess,
                                     _SetIdentityMatrixTestCase,
                                      ):
    pass

class SetIdentityComplexMatrixTestCase(_ComplexMatrixTestCase,
                                       _DirectAccess,
                                       _SetIdentityMatrixTestCase,
                                       ):
    pass

class SetIdentityComplexFloatMatrixTestCase(_ComplexFloatMatrixTestCase,
                                            _DirectAccess,
                                            _SetIdentityMatrixTestCase,
                                            ):
    pass

class SetIdentityLongMatrixTestCase(_LongMatrixTestCase,
                                    _DirectAccess,
                                    _SetIdentityMatrixTestCase,
                                    ):
    pass

class SetIdentityIntMatrixTestCase(_IntMatrixTestCase,
                                   _DirectAccess,
                                   _SetIdentityMatrixTestCase,
                                   ):
    pass

class SetIdentityShortMatrixTestCase(_ShortMatrixTestCase,
                                     _DirectAccess,
                                     _SetIdentityMatrixTestCase,
                                     ):
    pass

class SetIdentityFloatMatrixUITestCase(_FloatMatrixTestCase,
                                       _UIAccess,
                                       _SetIdentityMatrixTestCase,
                                      ):
    pass
class SetIdentityComplexMatrixUITestCase(_ComplexMatrixTestCase,
                                         _UIAccess,
                                         _SetIdentityMatrixTestCase,
                                         ):
    pass

class SetIdentityComplexFloatMatrixUITestCase(_ComplexFloatMatrixTestCase,
                                              _UIAccess,
                                             _SetIdentityMatrixTestCase,
                                             ):
    pass

class SetIdentityLongMatrixUITestCase(_LongMatrixTestCase,
                                      _UIAccess,
                                      _SetIdentityMatrixTestCase,
                                      ):
    pass
class SetIdentityIntMatrixUITestCase(_IntMatrixTestCase,
                                     _UIAccess,
                                     _SetIdentityMatrixTestCase,
                                     ):
    pass

class SetIdentityShortMatrixUITestCase(_ShortMatrixTestCase,
                                       _UIAccess,
                                       _SetIdentityMatrixTestCase,
                                       ):
    pass

class SetIdentityCharMatrixTestCase(_CharMatrixTestCase,
                                    _UIAccess,
                                    _SetIdentityMatrixTestCase,
                                    ):
    def test_2_diagonale(self):
        for i in range(self.size):            
            assert myord(self.array[i,i][0]) == 1, "Diagonale not one !"

    def test_3_diagonale(self):
        for i in range(self.size):
            for j in range(self.size):
                if i == j :
                    continue
                test = 0
                try:
                    assert myord(self.array[i,j][0]) ==  0, "Of Diagonale not zero!"
                    test = 1
                finally:
                    if test == 0:
                        print self.array
                        print self.array[i,j]

class SetIdentityCharMatrixTestCase(_CharMatrixTestCase,
                                    _DirectAccess,
                                    _SetIdentityMatrixTestCase,
                                    ):
    def test_2_diagonale(self):
        for i in range(self.size):
            assert myorda(self.array[i,i]) == 1, "Diagonale not one !"
            
    def test_3_diagonale(self):
        for i in range(self.size):
            for j in range(self.size):
                if i == j :
                    continue                
                assert myorda(self.array[i,j]) ==  0, "Of Diagonale not zero!"

        
class _SetZeroMatrixTestCase(_DefaultMatrixTestCase):
    function = 'set_zero'
    size = 10
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size))
        
        
    def test_1_matrixsize(self):
        array_check(self.array, None, (self.size, self.size))

    def test_2_all(self):
        for i in range(self.size):
            for j in range(self.size):
                assert self.array[i,j] ==  0, "Off Diagonale not zero!"
                
    def test_2_isnull(self):
        tmp = self._get_function('isnull')
        test = 0
        try:
            a = tmp(self.array)
            test = 1
        finally:
            if test == 0:
                print self, tmp
                
        assert tmp(self.array)
        
    def _mytearDown(self):
        del self.array
        self.array = None

class SetZeroMatrixTestCase(_DoubleMatrixTestCase,
                            _DirectAccess,
                            _SetZeroMatrixTestCase,
                            ):
    pass

class SetZeroFloatMatrixTestCase(_FloatMatrixTestCase,
                                 _DirectAccess,
                                 _SetZeroMatrixTestCase,
                                 ):
    pass
class SetZeroComplexMatrixTestCase(_ComplexMatrixTestCase,
                                   _DirectAccess,
                                   _SetZeroMatrixTestCase,
                                   ):
    pass

class SetZeroComplexFloatMatrixTestCase(_ComplexFloatMatrixTestCase,
                                        _DirectAccess,
                                        _SetZeroMatrixTestCase,
                                        ):
    pass

class SetZeroLongMatrixTestCase(_LongMatrixTestCase,
                                _DirectAccess,
                                _SetZeroMatrixTestCase,
                                ):
    pass

class SetZeroIntMatrixTestCase(_IntMatrixTestCase,
                               _DirectAccess,
                               _SetZeroMatrixTestCase,
                               ):
    pass

class SetZeroShortMatrixTestCase(_ShortMatrixTestCase,
                                 _DirectAccess,
                                 _SetZeroMatrixTestCase,
                                 ):
    pass

class SetZeroMatrixUITestCase(_DoubleMatrixTestCase,
                            _UIAccess,
                            _SetZeroMatrixTestCase,
                            ):
    pass

class SetZeroFloatMatrixUITestCase(_FloatMatrixTestCase,
                                 _UIAccess,
                                 _SetZeroMatrixTestCase,
                                 ):
    pass
class SetZeroComplexMatrixUITestCase(_ComplexMatrixTestCase,
                                   _UIAccess,
                                   _SetZeroMatrixTestCase,
                                   ):
    pass

class SetZeroComplexFloatMatrixUITestCase(_ComplexFloatMatrixTestCase,
                                        _UIAccess,
                                        _SetZeroMatrixTestCase,
                                        ):
    pass

class SetZeroLongMatrixUITestCase(_LongMatrixTestCase,
                                _UIAccess,
                                _SetZeroMatrixTestCase,
                                ):
    pass

class SetZeroIntMatrixUITestCase(_IntMatrixTestCase,
                               _UIAccess,
                               _SetZeroMatrixTestCase,
                               ):
    pass

class SetZeroShortMatrixUITestCase(_ShortMatrixTestCase,
                                 _UIAccess,
                                 _SetZeroMatrixTestCase,
                                 ):
    pass

class SetZeroCharMatrixTestCase(_CharMatrixTestCase,
                                _DirectAccess,
                                _SetZeroMatrixTestCase,
                                ):
    def test_2_all(self):
        for i in range(self.size):
            for j in range(self.size):
                test = 0
                try:
                    assert myorda(self.array[i,j]) ==  0, "Of Diagonale not zero!"
                    test = 1
                finally:
                    if test == 0:
                        print repr(self.array[i,j])
                        
class SetZeroCharMatrixUITestCase(_CharMatrixTestCase,
                                _UIAccess,
                                _SetZeroMatrixTestCase,
                                ):
    def test_2_all(self):
        for i in range(self.size):
            for j in range(self.size):
                test = 0
                try:
                    assert myorda(self.array[i,j]) ==  0, "Of Diagonale not zero!"
                    test = 1
                finally:
                    if test == 0:
                        print repr(self.array[i,j])



class _SetAllMatrixTestCase(_DefaultMatrixTestCase):
    function = 'set_all'
    size = 10
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size), self._get_reference_value())
        
        
    def test_1_matrixsize(self):
        array_check(self.array, None, (self.size, self.size))

    def test_2_all(self):
        for i in range(self.size):
            for j in range(self.size):
                assert self.array[i,j] ==  self._get_reference_value(), "Value not 137!"
        
    def _mytearDown(self):
        del self.array
        self.array = None

class SetAllFloatMatrixTestCase(_FloatMatrixTestCase,
                                _DirectAccess,
                                _SetAllMatrixTestCase,
                                 ):
    pass

class SetAllComplexMatrixTestCase(_ComplexMatrixTestCase,
                                  _DirectAccess,
                                  _SetAllMatrixTestCase,
                                  ):
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size), self._get_reference_value()+0j)

   

class SetAllComplexFloatMatrixTestCase(_ComplexFloatMatrixTestCase,
                                       _DirectAccess,
                                       _SetAllMatrixTestCase,
                                       ):
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size), 137+0j)

class SetAllLongMatrixTestCase(_LongMatrixTestCase,
                               _DirectAccess,
                                _SetAllMatrixTestCase,
                                ):
    pass

class SetAllIntMatrixTestCase(_IntMatrixTestCase,
                              _DirectAccess,
                               _SetAllMatrixTestCase,
                               ):
    pass

class SetAllShortMatrixTestCase(_ShortMatrixTestCase,
                                _DirectAccess,
                                _SetAllMatrixTestCase,
                                 ):
    pass

class SetAllFloatMatrixUITestCase(_FloatMatrixTestCase,
                                  _UIAccess,
                                  _SetAllMatrixTestCase,
                                 ):
    pass

class SetAllComplexMatrixUITestCase(_ComplexMatrixTestCase,
                                    _UIAccess,
                                    _SetAllMatrixTestCase,
                                    ):
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size), 137+0j)
        

class SetAllComplexFloatMatrixUITestCase(_ComplexFloatMatrixTestCase,
                                       _UIAccess,
                                       _SetAllMatrixTestCase,
                                       ):
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size), 137+0j)


class SetAllLongMatrixUITestCase(_LongMatrixTestCase,
                               _UIAccess,
                               _SetAllMatrixTestCase,
                                ):
    pass

class SetAllIntMatrixUITestCase(_IntMatrixTestCase,
                              _UIAccess,
                               _SetAllMatrixTestCase,
                               ):
    pass

class SetAllShortMatrixUITestCase(_ShortMatrixTestCase,
                                _UIAccess,
                                _SetAllMatrixTestCase,
                                 ):
    pass

class _MatrixSetup:
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp((self.size, self.size), chr(137))

    def test_2_all(self):
        for i in range(self.size):
            for j in range(self.size):
                assert myorda(self.array[i,j]) == 137, "Of Diagonale not zero!"
    
class SetAllCharMatrixTestCase(_CharMatrixTestCase,
                               _DirectAccess,
                               _MatrixSetup,
                               _SetAllMatrixTestCase,
                               ):
    pass

class SetAllCharMatrixUITestCase(_CharMatrixTestCase,
                                 _UIAccess,
                                 _MatrixSetup,
                                 _SetAllMatrixTestCase,
                                ):
    pass

class _DiagonalMatrixTestCase(_DefaultMatrixTestCase):
    size = 4
    def _mysetUp(self):
        tmp = self._get_function('set_zero')
        array = tmp((self.size, self.size))
        type = get_typecode(array)
        array = nummodule.zeros((self.size,self.size)).astype(type)
        for i in range(self.size):
            for j in range(self.size):
                if i < j:
                    array[i,j] = -i
                else:
                    array[i,j] = i
        self.array = array
        
    def test_1_matrixsize(self):
        array_check(self.array, None, (self.size, self.size))

    def _gettranspose(self):
        function = self._get_function('transpose')
        tmp = function(self.array)
        assert(tmp[0] == 0)
        return tmp[1]
    
    def test_2_matrixsizetranspose(self):
        tmp = self._gettranspose()
        assert tmp.shape == (self.size, self.size), "Not of size 10, 10"

    def test_3_diagonal(self):
        function = self._get_function('diagonal')
        tmp = function(self.array)
        for i in range(self.size):
            msg = "Error in getting diagonal! tmp[+"+`i`+"] = " + `tmp`
            #assert tmp[i] ==  i, msg

    def test_4_diagonaltranspose(self):
        tmp = self._gettranspose()
        for i in range(self.size):
            msg = "Error in getting diagonal! tmp[+"+`i`+"] = " + `tmp`
            #assert tmp[i,i] ==  i, msg

    def test_5_super_diagonal(self):
        function = self._get_function('superdiagonal')        
        for j in range(1,self.size):
            tmp = function(self.array, j)
            for i in range(self.size - j):
                #assert tmp[i,j] ==  i*-1, "Error in getting super diagonal!"
                pass
            
    def test_6_super_diagonaltranspose(self):
        function = self._get_function('superdiagonal')
        array = self._gettranspose()
        for j in range(1,self.size):
            tmp = function(array, j)
            for i in range(self.size - j):
                msg = "Error in getting super diagonal! tmp[+"+`i`+"] = " + `tmp`
                #assert tmp[i,j] == i*1+j, msg
    
                
    def test_7_sub_diagonal(self):
        function = self._get_function('subdiagonal')
        for j in range(1,self.size):
            tmp = function(self.array, j)
            for i in range(self.size - j):
                assert tmp[i] ==  i+j, "Error in getting sub diagonal!"
    
    def _mytearDown(self):
        del self.array
        self.array = None


class DiagonaMatrixTestCase(_DoubleMatrixTestCase,
                            _DirectAccess,
                            _DiagonalMatrixTestCase,
                            ):
    pass

class DiagonalFloatMatrixTestCase(_FloatMatrixTestCase,
                                  _DirectAccess,
                                  _DiagonalMatrixTestCase,
                                  ):
    pass
class DiagonalComplexMatrixTestCase(_ComplexMatrixTestCase,
                                    _DirectAccess,
                                   _DiagonalMatrixTestCase,
                                   ):
    pass

class DiagonalComplexFloatMatrixTestCase(_ComplexFloatMatrixTestCase,
                                         _DirectAccess,
                                        _DiagonalMatrixTestCase,
                                        ):
    pass

class DiagonalLongMatrixTestCase(_LongMatrixTestCase,
                                 _DirectAccess,
                                _DiagonalMatrixTestCase,
                                ):
    pass
class DiagonalIntMatrixTestCase(_IntMatrixTestCase,
                                _DirectAccess,
                               _DiagonalMatrixTestCase,
                               ):
    pass

class DiagonalShortMatrixTestCase(_ShortMatrixTestCase,
                                  _DirectAccess,                           
                                 _DiagonalMatrixTestCase,
                                 ):
    pass

class DiagonaMatrixUITestCase(_DoubleMatrixTestCase,
                            _UIAccess,
                            _DiagonalMatrixTestCase,
                            ):
    pass

class DiagonalFloatMatrixUITestCase(_FloatMatrixTestCase,
                                  _UIAccess,
                                  _DiagonalMatrixTestCase,
                                  ):
    pass
class DiagonalComplexMatrixUITestCase(_ComplexMatrixTestCase,
                                    _UIAccess,
                                   _DiagonalMatrixTestCase,
                                   ):
    pass

class DiagonalComplexFloatMatrixUITestCase(_ComplexFloatMatrixTestCase,
                                         _UIAccess,
                                        _DiagonalMatrixTestCase,
                                        ):
    pass

class DiagonalLongMatrixUITestCase(_LongMatrixTestCase,
                                 _UIAccess,
                                _DiagonalMatrixTestCase,
                                ):
    pass
class DiagonalIntMatrixUITestCase(_IntMatrixTestCase,
                                _UIAccess,
                               _DiagonalMatrixTestCase,
                               ):
    pass

class DiagonalShortMatrixUITestCase(_ShortMatrixTestCase,
                                  _UIAccess,                           
                                 _DiagonalMatrixTestCase,
                                 ):
    pass

class _MinMaxMatrixTestCase(_DefaultMatrixTestCase):
    size = 10
    def _mysetUp(self):
        tmp = self._get_function('set_zero')
        array = tmp((self.size, self.size))
        type = get_typecode(array)
        array = nummodule.zeros((self.size,self.size)).astype(type)
        array[5,4] = -1
        array[8,7] =  1        
        self.array = array

    def test_max(self):
        function = self._get_function('max')
        assert(function(self.array)==  1)

    def test_min(self):
        function = self._get_function('min')
        assert(function(self.array)== -1)

    def test_minmax(self):
        function = self._get_function('minmax')
        tmp = function(self.array)                
        assert(tmp[0] == -1)
        assert(tmp[1] ==  1)

    def test_minmax(self):
        function = self._get_function('minmax')
        tmp = function(self.array)
        assert(tmp[0] == -1)
        assert(tmp[1] ==  1)

    def test_maxindex(self):
        function = self._get_function('max_index')
        tmp = function(self.array)
        assert(tmp[0] ==  8)
        assert(tmp[1] ==  7)

    def test_minindex(self):
        function = self._get_function('min_index')
        tmp = function(self.array)
        assert(tmp[0] ==  5)
        assert(tmp[1] ==  4)

    def test_minmaxindex(self):
        function = self._get_function('minmax_index')
        tmp = function(self.array)
        assert(tmp[0] ==  5)
        assert(tmp[1] ==  4)
        assert(tmp[2] ==  8)
        assert(tmp[3] ==  7)


    def _mytearDown(self):
        pass

class MinMaxMatrixTestCase(_DoubleMatrixTestCase,
                           _DirectAccess,
                           _MinMaxMatrixTestCase,
                           ):
    pass
    
class MinMaxFloatMatrixTestCase(_FloatMatrixTestCase,
                                _DirectAccess,
                                _MinMaxMatrixTestCase,
                                 ):
    pass

class MinMaxLongMatrixTestCase(_LongMatrixTestCase,
                               _DirectAccess,
                                _MinMaxMatrixTestCase,
                                ):
    pass
class MinMaxIntMatrixTestCase(_IntMatrixTestCase,
                              _DirectAccess,
                               _MinMaxMatrixTestCase,
                               ):
    pass

class MinMaxShortMatrixTestCase(_ShortMatrixTestCase,
                                _DirectAccess,
                                 _MinMaxMatrixTestCase,
                                 ):
    pass

class MinMaxMatrixUITestCase(_DoubleMatrixTestCase,
                             _UIAccess,
                             _MinMaxMatrixTestCase,
                             ):
    pass
    
class MinMaxFloatMatrixUITestCase(_FloatMatrixTestCase,
                                  _UIAccess,
                                  _MinMaxMatrixTestCase,
                                  ):
    pass

class MinMaxLongMatrixUITestCase(_LongMatrixTestCase,
                                 _UIAccess,
                                 _MinMaxMatrixTestCase,
                                ):
    pass
class MinMaxIntMatrixUITestCase(_IntMatrixTestCase,
                                _UIAccess,
                               _MinMaxMatrixTestCase,
                               ):
    pass

class MinMaxShortMatrixUITestCase(_ShortMatrixTestCase,
                                  _UIAccess,
                                  _MinMaxMatrixTestCase,
                                  ):
    pass


class _SwapMatrixTestCase(_DefaultMatrixTestCase):
    size = 10
    def _mysetUp(self):
        tmp = self._get_function('set_zero')
        array = tmp((self.size, self.size))
        type = get_typecode(array)
        
        array = nummodule.fromfunction(lambda x,y,size=self.size : x*size + y,
                                     (self.size, self.size))        
        self.array = array.astype(type)
        self.array1 = (array*10).astype(type)
        
    def test_1_swap(self):
        function =  self._get_function('swap')
        type = get_typecode(self.array)
        tmp = function(self.array, self.array1)
        function =  self._get_function('isnull')
        assert(function((tmp[1]/10).astype(type) - tmp[2]))

    def test_2_swap_columns(self):
        function =  self._get_function('swap_columns')
        tmp = function(self.array, 3, 5)
        assert(tmp[0] == 0)
        for i in range(self.size):
            assert(tmp[1][i,3]==10*i+5)
            assert(tmp[1][i,5]==10*i+3)

    def test_3_swap_rows(self):
        function =  self._get_function('swap_rows')
        tmp = function(self.array, 3, 5)
        assert(tmp[0] == 0)
        for i in range(self.size):
            assert(tmp[1][3,i]==i+50)
            assert(tmp[1][5,i]==i+30)


    def test_4_swap_rowcol(self):
        function =  self._get_function('swap_rowcol')
        tmp = function(self.array, 3, 5)
        assert(tmp[0] == 0)
        for i in range(self.size):           
            assert(tmp[1][3,i]==10*i+5)
        for i in range(self.size):
            if i == 3:
                assert(tmp[1][3,5] == 55)
            elif i == 5:
                assert(tmp[1][5,5] == 33)
            else:
                assert(tmp[1][i,5]==30+i)

#    def test_5_fwrite(self):
#        print "Seek finished "
#        file = getopentmpfile('w')
#        function =  self._get_function('fwrite')
#        tmp = function(file, self.array)
#
#    def test_6_fread(self):
#
#        file = getopentmpfile('w+')
#        function =  self._get_function('fwrite')
#        tmp = function(file, (self.array * 2).astype(self.get_typecode(array)))
#        assert(tmp == 0)
#        file.seek(0)
#
#        function =  self._get_function('fread')
#        tmp = function(file, self.array.shape)
#        assert(tmp[0] == 0)
#        for i in range(self.size):
#            for j in range(self.size):
#                assert(tmp[1][i,j] == self.array[i,j] * 2)
#                
#
#    def test_7_fprintf(self):        
#        file = getopentmpfile('w')
#        function =  self._get_function('fprintf')
#        tmp = function(file, self.array, self._get_format())
#        assert(tmp == 0)
#        
#    def test_8_fscanf(self):
#        file = getopentmpfile('w+')
#        function =  self._get_function('fprintf')
#        ttype = self.get_typecode(array)
#        tmp = function(file, (self.array*2).astype(ttype), self._get_format())
#
#        function =  self._get_function('fscanf')
#        file.seek(0)
#
#        tmp = function(file, self.array.shape)
#        assert(tmp[0] == 0)
#        for i in range(self.size):
#            for j in range(self.size):
#                assert(tmp[1][i,j] == self.array[i,j] * 2)

    def _mytearDown(self):
        pass

class SwapMatrixTestCase(_DoubleMatrixTestCase,
                         _DirectAccess,
                         _SwapMatrixTestCase,
                         ):
    pass

class SwapFloatMatrixTestCase(_FloatMatrixTestCase,
                              _DirectAccess,
                              _SwapMatrixTestCase,
                              ):
    pass
class SwapComplexMatrixTestCase(_ComplexMatrixTestCase,
                                _DirectAccess,
                                _SwapMatrixTestCase,
                                ):
    pass

class SwapComplexFloatMatrixTestCase(_ComplexFloatMatrixTestCase,
                                     _DirectAccess,
                                     _SwapMatrixTestCase,
                                     ):
    pass

class SwapLongMatrixTestCase(_LongMatrixTestCase,
                             _DirectAccess,
                             _SwapMatrixTestCase,
                             ):
    pass
class SwapIntMatrixTestCase(_IntMatrixTestCase,
                            _DirectAccess,
                            _SwapMatrixTestCase,
                            ):
    pass

class SwapShortMatrixTestCase(_ShortMatrixTestCase,
                              _DirectAccess,
                              _SwapMatrixTestCase,
                              ):
    pass

class SwapMatrixUITestCase(_DoubleMatrixTestCase,
                           _UIAccess,
                           _SwapMatrixTestCase,
                           ):
    pass

class SwapFloatMatrixUITestCase(_FloatMatrixTestCase,
                                _UIAccess,
                                _SwapMatrixTestCase,
                                ):
    pass
class SwapComplexMatrixUITestCase(_ComplexMatrixTestCase,
                                  _UIAccess,
                                  _SwapMatrixTestCase,
                                  ):
    pass

class SwapComplexFloatMatrixUITestCase(_ComplexFloatMatrixTestCase,
                                       _UIAccess,
                                       _SwapMatrixTestCase,
                                       ):
    pass

class SwapLongMatrixUITestCase(_LongMatrixTestCase,
                               _UIAccess,
                               _SwapMatrixTestCase,
                               ):
    pass
class SwapIntMatrixUITestCase(_IntMatrixTestCase,
                              _UIAccess,
                              _SwapMatrixTestCase,
                              ):
    pass

class SwapShortMatrixUITestCase(_ShortMatrixTestCase,
                                _UIAccess,
                                _SwapMatrixTestCase,
                                ):
    pass

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
#                            Vectors
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
class _SetBasisVectorTestCase(_DefaultVectorTestCase):
    function = 'set_basis'
    size  = 10
    basis = 5 

    def _mysetUp(self):
        tmp = self._get_function()
        basis = self.basis
        tmp1 = tmp(self.size, basis)
        assert(tmp1[0] == 0)
        self.array = tmp1[1]
        
    def test_1_matrixsize(self):
        array_check(self.array, None, (self.size,))

    def test_2_diagonale(self):
        assert self.array[self.basis] == 1, "Basis not one !"

    def test_3_diagonale(self):
        for i in range(self.size):
            if i == self.basis :
                continue                
            assert self.array[i] ==  0, "Basis not zero!"
        
    def _mytearDown(self):
        del self.array
        self.array = None
        

class SetBasisVectorTestCase(_DoubleVectorTestCase,
                                _DirectAccess,
                                _SetBasisVectorTestCase,
                                ):
    pass

class SetBasisVectorUITestCase(_DoubleVectorTestCase,
                                  _UIAccess,
                                  _SetBasisVectorTestCase,
                                  ):
    pass

class SetBasisFloatVectorTestCase(_FloatVectorTestCase,
                                     _DirectAccess,
                                     _SetBasisVectorTestCase,
                                      ):
    pass

class SetBasisComplexVectorTestCase(_ComplexVectorTestCase,
                                    _DirectAccess,
                                    _SetBasisVectorTestCase,
                                    ):
    pass

class SetBasisComplexFloatVectorTestCase(_ComplexFloatVectorTestCase,
                                         _DirectAccess,
                                         _SetBasisVectorTestCase,
                                         ):
    pass

class SetBasisLongVectorTestCase(_LongVectorTestCase,
                                 _DirectAccess,
                                 _SetBasisVectorTestCase,
                                 ):
    pass

class SetBasisIntVectorTestCase(_IntVectorTestCase,
                                   _DirectAccess,
                                   _SetBasisVectorTestCase,
                                   ):
    pass

class SetBasisShortVectorTestCase(_ShortVectorTestCase,
                                     _DirectAccess,
                                     _SetBasisVectorTestCase,
                                     ):
    pass

class SetBasisFloatVectorUITestCase(_FloatVectorTestCase,
                                       _UIAccess,
                                       _SetBasisVectorTestCase,
                                      ):
    pass
class SetBasisComplexVectorUITestCase(_ComplexVectorTestCase,
                                         _UIAccess,
                                         _SetBasisVectorTestCase,
                                         ):
    pass

class SetBasisComplexFloatVectorUITestCase(_ComplexFloatVectorTestCase,
                                              _UIAccess,
                                             _SetBasisVectorTestCase,
                                             ):
    pass

class SetBasisLongVectorUITestCase(_LongVectorTestCase,
                                      _UIAccess,
                                      _SetBasisVectorTestCase,
                                      ):
    pass
class SetBasisIntVectorUITestCase(_IntVectorTestCase,
                                     _UIAccess,
                                     _SetBasisVectorTestCase,
                                     ):
    pass

class SetBasisShortVectorUITestCase(_ShortVectorTestCase,
                                       _UIAccess,
                                       _SetBasisVectorTestCase,
                                       ):
    pass


class _CharVectorSetup:
    def _mysetup(self):
        self.array = tmp(self.size, myord(137))
        
    #def test_2_diagonale(self):
    #    assert ord(self.array[self.basis][0]) == 1, "Diagonale not one !"

    #def test_3_diagonale(self):
    #    for i in range(self.size):
    #        if i == self.basis :
    #            continue                
    #        assert ord(self.array[i][0]) ==  0, \
    #               "Off Diagonale not zero!"
    
class SetBasisCharVectorUITestCase(_CharVectorTestCase,
                                   _UIAccess,
                                   _CharVectorSetup,
                                   _SetBasisVectorTestCase,
                                 ):
    def test_2_diagonale(self):
        assert myord(self.array[self.basis]) == 1, "Basis not one !"

    def test_3_diagonale(self):
        for i in range(self.size):
            if i == self.basis :
                continue                
            assert myord(self.array[i]) ==  0, "Basis not zero!"

class SetBasisCharVectorTestCase(_CharVectorTestCase,
                                 _DirectAccess,
                                 _CharVectorSetup,
                                 _SetBasisVectorTestCase,
                                 ):
    def test_2_diagonale(self):
        assert myord(self.array[self.basis]) == 1, "Basis not one !"

    def test_3_diagonale(self):
        for i in range(self.size):
            if i == self.basis :
                continue                
            assert myord(self.array[i]) ==  0, "Basis not zero!"

        
class _SetZeroVectorTestCase(_DefaultVectorTestCase):
    function = 'set_zero'
    size = 10
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp(self.size)
        
        
    def test_1_matrixsize(self):        
        assert self.array.shape == (self.size,), "Not of size 10, 10"

    def test_2_all(self):
        for i in range(self.size):
            assert self.array[i] ==  0, "Off Diagonale not zero!"
                
    def test_2_isnull(self):
        tmp = self._get_function('isnull')
        assert tmp(self.array)
        
    def _mytearDown(self):
        del self.array
        self.array = None

class SetZeroVectorTestCase(_DoubleVectorTestCase,
                            _DirectAccess,
                            _SetZeroVectorTestCase,
                            ):
    pass

class SetZeroFloatVectorTestCase(_FloatVectorTestCase,
                                 _DirectAccess,
                                 _SetZeroVectorTestCase,
                                 ):
    pass
class SetZeroComplexVectorTestCase(_ComplexVectorTestCase,
                                   _DirectAccess,
                                   _SetZeroVectorTestCase,
                                   ):
    pass

class SetZeroComplexFloatVectorTestCase(_ComplexFloatVectorTestCase,
                                        _DirectAccess,
                                        _SetZeroVectorTestCase,
                                        ):
    pass

class SetZeroLongVectorTestCase(_LongVectorTestCase,
                                _DirectAccess,
                                _SetZeroVectorTestCase,
                                ):
    pass

class SetZeroIntVectorTestCase(_IntVectorTestCase,
                               _DirectAccess,
                               _SetZeroVectorTestCase,
                               ):
    pass

class SetZeroShortVectorTestCase(_ShortVectorTestCase,
                                 _DirectAccess,
                                 _SetZeroVectorTestCase,
                                 ):
    pass

class SetZeroVectorUITestCase(_DoubleVectorTestCase,
                            _UIAccess,
                            _SetZeroVectorTestCase,
                            ):
    pass

class SetZeroFloatVectorUITestCase(_FloatVectorTestCase,
                                 _UIAccess,
                                 _SetZeroVectorTestCase,
                                 ):
    pass
class SetZeroComplexVectorUITestCase(_ComplexVectorTestCase,
                                   _UIAccess,
                                   _SetZeroVectorTestCase,
                                   ):
    pass

class SetZeroComplexFloatVectorUITestCase(_ComplexFloatVectorTestCase,
                                        _UIAccess,
                                        _SetZeroVectorTestCase,
                                        ):
    pass

class SetZeroLongVectorUITestCase(_LongVectorTestCase,
                                _UIAccess,
                                _SetZeroVectorTestCase,
                                ):
    pass

class SetZeroIntVectorUITestCase(_IntVectorTestCase,
                               _UIAccess,
                               _SetZeroVectorTestCase,
                               ):
    pass

class SetZeroShortVectorUITestCase(_ShortVectorTestCase,
                                 _UIAccess,
                                 _SetZeroVectorTestCase,
                                 ):
    pass

class SetZeroCharVectorTestCase(_CharVectorTestCase,
                                _DirectAccess,
                                _SetZeroVectorTestCase,
                                ):
    def test_2_all(self):
        for i in range(self.size):
            test = 0
            cztmp = myorda(self.array[i])
            try:
                assert cztmp  ==  0, "Of Diagonale not zero!"
                test = 1
            finally:
                if test == 0:
                    print "Of Diagonale not zero (but %s) for class %s !" (cztmp, self)
                    
class SetZeroCharVectorUITestCase(_CharVectorTestCase,
                                _UIAccess,
                                _SetZeroVectorTestCase,
                                ):
    def test_2_all(self):
        for i in range(self.size):
            assert myorda(self.array[i]) ==  0, "Of Diagonale not zero!"


class _SetAllVectorTestCase(_DefaultVectorTestCase):
    function = 'set_all'
    size = 10
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp(self.size, self._get_reference_value())
        
        
    def test_1_matrixsize(self):
        array_check(self.array, None, (self.size,))

    def test_2_all(self):
        for i in range(self.size):
            tmp = self.array[i]
            try:
                test = 0
                assert tmp ==  self._get_reference_value(), "Value not 137!"
                test = 1
            finally:
                if test == 0:
                    print type(self.array), get_typecode(self.array)
                    print "self.array[%d]  was %s" %(i, tmp)
        
    def _mytearDown(self):
        del self.array
        self.array = None

class SetAllFloatVectorTestCase(_FloatVectorTestCase,
                                _DirectAccess,
                                _SetAllVectorTestCase,
                                 ):
    pass

class _ComplexVectorSetup:
    def _mysetUp(self):
        tmp = self._get_function()
        self.array = tmp(self.size, 137+0j)
    
class SetAllComplexVectorTestCase(_ComplexVectorTestCase,
                                  _DirectAccess,
                                  _ComplexVectorSetup,
                                  _SetAllVectorTestCase,
                                  ):
    pass
   

class SetAllComplexFloatVectorTestCase(_ComplexFloatVectorTestCase,
                                       _DirectAccess,
                                       _ComplexVectorSetup,
                                       _SetAllVectorTestCase,
                                       ):
    pass

class SetAllLongVectorTestCase(_LongVectorTestCase,
                               _DirectAccess,
                               _SetAllVectorTestCase,
                               ):
    pass

class SetAllIntVectorTestCase(_IntVectorTestCase,
                              _DirectAccess,
                              _SetAllVectorTestCase,
                              ):
    pass

class SetAllShortVectorTestCase(_ShortVectorTestCase,
                                _DirectAccess,
                                _SetAllVectorTestCase,
                                ):
    pass

class SetAllFloatVectorUITestCase(_FloatVectorTestCase,
                                  _UIAccess,
                                  _SetAllVectorTestCase,
                                  ):
    pass

class SetAllComplexVectorUITestCase(_ComplexVectorTestCase,
                                    _UIAccess,
                                    _ComplexVectorSetup,
                                    _SetAllVectorTestCase,
                                    ):
    pass

class SetAllComplexFloatVectorUITestCase(_ComplexFloatVectorTestCase,
                                         _UIAccess,
                                         _ComplexVectorSetup,
                                         _SetAllVectorTestCase,
                                         ):
    pass

class SetAllLongVectorUITestCase(_LongVectorTestCase,
                                 _UIAccess,
                                 _SetAllVectorTestCase,
                                 ):
    pass

class SetAllIntVectorUITestCase(_IntVectorTestCase,
                                _UIAccess,
                                _SetAllVectorTestCase,
                                ):
    pass

class SetAllShortVectorUITestCase(_ShortVectorTestCase,
                                  _UIAccess,
                                  _SetAllVectorTestCase,
                                  ):
    pass

    
class SetAllCharVectorTestCase(_CharVectorTestCase,
                               _DirectAccess,
                               _CharVectorSetup,
                               _SetAllVectorTestCase,
                               ):
    pass
class SetAllCharVectorUITestCase(_CharVectorTestCase,
                                 _UIAccess,
                                 _CharVectorSetup,
                                 _SetAllVectorTestCase,
                                ):
    pass


class _MinMaxVectorTestCase(_DefaultVectorTestCase):
    size = 10
    def _mysetUp(self):
        tmp = self._get_function('set_zero')
        array = tmp((self.size))
        type = get_typecode(array)
        array = nummodule.zeros((self.size,)).astype(type)
        array[5] = -1
        array[8] =  1        
        self.array = array

    def test_max(self):
        function = self._get_function('max')
        assert(function(self.array)==  1)

    def test_min(self):
        function = self._get_function('min')
        assert(function(self.array)== -1)

    def test_minmax(self):
        function = self._get_function('minmax')
        tmp = function(self.array)                
        assert(tmp[0] == -1)
        assert(tmp[1] ==  1)

    def test_maxindex(self):
        function = self._get_function('max_index')
        tmp = function(self.array)
        assert(tmp ==  8)


    def test_minindex(self):
        function = self._get_function('min_index')
        tmp = function(self.array)
        assert(tmp ==  5)


    def test_minmaxindex(self):
        function = self._get_function('minmax_index')
        tmp = function(self.array)
        assert(tmp[0] ==  5)
        assert(tmp[1] ==  8)

    def _mytearDown(self):
        pass

class MinMaxVectorTestCase(_DoubleVectorTestCase,
                           _DirectAccess,
                           _MinMaxVectorTestCase,
                           ):
    pass
    
class MinMaxFloatVectorTestCase(_FloatVectorTestCase,
                                _DirectAccess,
                                _MinMaxVectorTestCase,
                                 ):
    pass

class MinMaxLongVectorTestCase(_LongVectorTestCase,
                               _DirectAccess,
                                _MinMaxVectorTestCase,
                                ):
    pass
class MinMaxIntVectorTestCase(_IntVectorTestCase,
                              _DirectAccess,
                               _MinMaxVectorTestCase,
                               ):
    pass

class MinMaxShortVectorTestCase(_ShortVectorTestCase,
                                _DirectAccess,
                                 _MinMaxVectorTestCase,
                                 ):
    pass

class MinMaxVectorUITestCase(_DoubleVectorTestCase,
                             _UIAccess,
                             _MinMaxVectorTestCase,
                             ):
    pass
    
class MinMaxFloatVectorUITestCase(_FloatVectorTestCase,
                                  _UIAccess,
                                  _MinMaxVectorTestCase,
                                  ):
    pass

class MinMaxLongVectorUITestCase(_LongVectorTestCase,
                                 _UIAccess,
                                 _MinMaxVectorTestCase,
                                ):
    pass
class MinMaxIntVectorUITestCase(_IntVectorTestCase,
                                _UIAccess,
                               _MinMaxVectorTestCase,
                               ):
    pass

class MinMaxShortVectorUITestCase(_ShortVectorTestCase,
                                  _UIAccess,
                                  _MinMaxVectorTestCase,
                                  ):
    pass


class _SwapVectorTestCase(_DefaultVectorTestCase):
    size = 10
    def _mysetUp(self):
        tmp = self._get_function('set_zero')
        array = tmp(self.size)
        type = get_typecode(array)
        
        array = nummodule.arange(self.size)
        self.array = array.astype(type)
        self.array1 = (array*10).astype(type)

    def testswap(self):
        function =  self._get_function('swap')
        type = get_typecode(self.array)
        tmp = function(self.array, self.array1)
        function =  self._get_function('isnull')
        assert(function((tmp[1]/10).astype(type) - tmp[2]))


    def testswap_elements(self):
        function =  self._get_function('swap_elements')
        tmp = function(self.array, 3, 5)
        assert(tmp[0] == 0)
        for i in range(self.size):
            if i == 3:
                assert(tmp[1][3] == 5)
            elif i == 5:
                assert(tmp[1][5] == 3)
            else:
                assert(tmp[1][i]==i)

    def test_reverse(self):
        function =  self._get_function('reverse')
        tmp = function(self.array)
        assert(tmp[0] == 0)
        for i in range(self.size):
            assert(tmp[1][-(i+1)]==i)

    
#    def test_fwrite(self):        
#        file = getopentmpfile('w')
#        function =  self._get_function('fwrite')
#        #print "Testing fwrite!"
#        tmp = function(file, self.array)
#
#    def test_fread(self):        
#        file = getopentmpfile('w+')
#        function =  self._get_function('fwrite')
#        tmp = function(file, (self.array * 2).astype(self.get_typecode(array)))
#        assert(tmp == 0)
#        file.seek(0)
#        function =  self._get_function('fread')
#        tmp = function(file, self.array.shape[0])
#        assert(tmp[0] == 0)
#        for i in range(self.size):
#            assert(tmp[1][i] == self.array[i] * 2)
#
#    def test_fprintf(self):        
#        file = getopentmpfile('w')
#        function =  self._get_function('fprintf')
#        tmp = function(file, self.array, self._get_format())
#        assert(tmp == 0)
#        
#    def test_fscanf(self):
#        file = getopentmpfile('w+')
#        function =  self._get_function('fprintf')
#        ttype = self.get_typecode(array)
#        tmp = function(file, (self.array*2).astype(ttype), self._get_format())
#
#        function =  self._get_function('fscanf')
#        file.seek(0)
#
#        tmp = function(file, self.array.shape[0])
#        assert(tmp[0] == 0)
#        for i in range(self.size):
#            assert(tmp[1][i] == self.array[i] * 2)

    def _mytearDown(self):
        pass

class SwapVectorTestCase(_DoubleVectorTestCase,
                         _DirectAccess,
                         _SwapVectorTestCase,
                         ):
    pass

class SwapFloatVectorTestCase(_FloatVectorTestCase,
                              _DirectAccess,
                              _SwapVectorTestCase,
                              ):
    pass
class SwapComplexVectorTestCase(_ComplexVectorTestCase,
                                _DirectAccess,
                                _SwapVectorTestCase,
                                ):
    pass

class SwapComplexFloatVectorTestCase(_ComplexFloatVectorTestCase,
                                     _DirectAccess,
                                     _SwapVectorTestCase,
                                     ):
    pass

class SwapLongVectorTestCase(_LongVectorTestCase,
                             _DirectAccess,
                             _SwapVectorTestCase,
                             ):
    pass
class SwapIntVectorTestCase(_IntVectorTestCase,
                            _DirectAccess,
                            _SwapVectorTestCase,
                            ):
    pass

class SwapShortVectorTestCase(_ShortVectorTestCase,
                              _DirectAccess,
                              _SwapVectorTestCase,
                              ):
    pass

class SwapVectorUITestCase(_DoubleVectorTestCase,
                           _UIAccess,
                           _SwapVectorTestCase,
                           ):
    pass

class SwapFloatVectorUITestCase(_FloatVectorTestCase,
                                _UIAccess,
                                _SwapVectorTestCase,
                                ):
    pass
class SwapComplexVectorUITestCase(_ComplexVectorTestCase,
                                  _UIAccess,
                                  _SwapVectorTestCase,
                                  ):
    pass

class SwapComplexFloatVectorUITestCase(_ComplexFloatVectorTestCase,
                                       _UIAccess,
                                       _SwapVectorTestCase,
                                       ):
    pass

class SwapLongVectorUITestCase(_LongVectorTestCase,
                               _UIAccess,
                               _SwapVectorTestCase,
                               ):
    pass
class SwapIntVectorUITestCase(_IntVectorTestCase,
                              _UIAccess,
                              _SwapVectorTestCase,
                              ):
    pass

class SwapShortVectorUITestCase(_ShortVectorTestCase,
                                _UIAccess,
                                _SwapVectorTestCase,
                                ):
    pass


#del DiagonalComplexFloatMatrixTestCase
#del DiagonalComplexFloatMatrixUITestCase

# del SwapComplexFloatMatrixTestCase
# del SwapComplexFloatMatrixUITestCase
# del SwapComplexFloatVectorTestCase
# del SwapComplexFloatVectorUITestCase
# del SwapComplexMatrixTestCase
# del SwapComplexMatrixUITestCase
# del SwapComplexVectorTestCase
# del SwapComplexVectorUITestCase
# del SwapFloatMatrixTestCase
# del SwapFloatMatrixUITestCase
# del SwapFloatVectorTestCase
# del SwapFloatVectorUITestCase
# del SwapIntMatrixTestCase
# del SwapIntMatrixUITestCase
# del SwapIntVectorTestCase
# del SwapIntVectorUITestCase
# del SwapLongMatrixTestCase
# del SwapLongMatrixUITestCase
# del SwapLongVectorTestCase
# del SwapLongVectorUITestCase
# del SwapMatrixTestCase
# del SwapMatrixUITestCase
# del SwapVectorTestCase
# del SwapVectorUITestCase
# del SwapShortMatrixTestCase
# del SwapShortMatrixUITestCase
# del SwapShortVectorTestCase
# del SwapShortVectorUITestCase

# del SetZeroComplexFloatVectorUITestCase
# del SetZeroComplexFloatVectorTestCase
# del SetZeroComplexVectorUITestCase
# del SetZeroComplexVectorTestCase
# del SetZeroComplexFloatMatrixUITestCase
# del SetZeroComplexFloatMatrixTestCase
# del SetZeroComplexMatrixUITestCase
# del SetZeroComplexMatrixTestCase
# del SetZeroIntMatrixTestCase
# del SetZeroIntMatrixUITestCase
# del SetZeroIntVectorTestCase
# del SetZeroIntVectorUITestCase
# del SetZeroLongMatrixTestCase
# del SetZeroLongMatrixUITestCase
# del SetZeroLongVectorTestCase
# del SetZeroLongVectorUITestCase
# del SetZeroMatrixTestCase
# del SetZeroMatrixUITestCase

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
#                            Remove ..
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
# These just provide a few values.....
del _DefaultTestCase
del _DefaultVectorTestCase
del _DefaultMatrixTestCase

del _DoubleMatrixTestCase
del _FloatMatrixTestCase
del _ComplexMatrixTestCase
del _ComplexFloatMatrixTestCase        
del _LongMatrixTestCase
del _ShortMatrixTestCase
del _IntMatrixTestCase
del _CharMatrixTestCase

del _DoubleVectorTestCase
del _FloatVectorTestCase
del _ComplexVectorTestCase
del _ComplexFloatVectorTestCase        
del _LongVectorTestCase
del _ShortVectorTestCase
del _IntVectorTestCase
del _CharVectorTestCase

del _DirectAccess
del _UIAccess

del _SetIdentityMatrixTestCase
del _MinMaxMatrixTestCase
del _DiagonalMatrixTestCase
del _SetZeroMatrixTestCase
del _SetAllMatrixTestCase
del _SwapMatrixTestCase

del _SetBasisVectorTestCase
del _MinMaxVectorTestCase
del _SetZeroVectorTestCase
del _SetAllVectorTestCase
del _SwapVectorTestCase



    
if __name__ == '__main__':
    unittest.main()


