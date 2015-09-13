# statistics tests
#
# author: Jochen K"upper
#
# March 2004: Removed any code without Numeric
# September 2015: Adaption so that it can be used from python2 and python3
# $Id$
#

import pygsl
numx = pygsl._numobj

try:
    Int8 = numx.int8
except AttributeError:
    Int8 = numx.Int8
try:
    Int32 = numx.int32
except AttributeError:
    Int32  = numx.Int32


try:
    Int = numx.int_
except AttributeError:
    Int = numx.Int

try:
    Int16 = numx.int16
except AttributeError:
    Int16 = numx.Int16

try:
    UInt8 = numx.Uint8
except AttributeError:
    UInt8 = numx.uint8

import unittest
import pygsl.statistics
from pygsl.statistics import wmean, mean, sd, sd_m, variance, variance_m
from pygsl.statistics import char as char
from pygsl.statistics import float as float
from pygsl.statistics import int as int
from pygsl.statistics import long as long
from pygsl.statistics import short as short
from pygsl.statistics import uchar as uchar


class statistics_test(unittest.TestCase):
    """Simple tests on statistics functions"""

    def test_wmean(self):        
        self.assertFalse(wmean(numx.array([1,1,1]), numx.array([-1.,-3.,1.])) != -1.0)
        self.assertFalse(wmean(numx.array([1,1,1]),[1,2,3]) != 2)
        data = numx.array([1.,2.,3.,4.,5.,6.,7.,8.,9.,10.])
        weight = numx.ones(data.shape)
        self.assertFalse(wmean(weight,data) != 5.5)
        
        self.assertFalse(wmean(weight[::2],data[::2]) != 5.0)
        self.assertFalse(wmean(weight[::-1],data[::-1]) != 5.5)
        self.assertFalse(wmean(weight[::-2],data[::-2]) != 6.0)
            
    def test_mean(self):
        self.assertFalse(mean(numx.array([-1.,-3.,1.])) != -1.0)
        self.assertFalse(mean([1,2,3]) != 2)
        # test stride != 1
        # these are only valid tests when using NumPy,
        # since otherwise the sequence is trnsformed to an
        # contigous array anyway...
        data = numx.array([1.,2.,3.,4.,5.,6.,7.,8.,9.,10.])
        self.assertFalse(mean(data) != 5.5)

        self.assertFalse(mean(data[::2]) != 5.0)
        self.assertFalse(mean(data[::-1]) != 5.5)
        self.assertFalse(mean(data[::-2]) != 6.0)

    def test_mean_char(self):
        tmp = (ord("1") + ord("2") + ord("3")) / 3
        self.assertFalse(char.mean(numx.array([1,2,3], Int8)) != 2)
        self.assertFalse(char.mean([1,2,3]) != 2)
    
    def test_mean_float(self):
        self.assertFalse(float.mean(numx.array([-1.,-3.,1.], 'f')) != -1)
        self.assertFalse(float.mean([1.,2.,3.]) != 2)
    
    def test_mean_int(self):
        self.assertFalse(int.mean(numx.array([-1,-3,1], Int16)) != -1)
        self.assertFalse(int.mean([1,2,3]) != 2)
    
    def test_mean_long(self):
        self.assertFalse(long.mean(numx.array([-1,-3,1])) != -1)
        self.assertFalse(long.mean([1,2,3]) != 2)
        
    def test_mean_short(self):
        self.assertFalse(short.mean([1,2,3]) != 2)        
        self.assertFalse(short.mean(numx.array([-1,-3,1], Int16)) != -1)

    def test_mean_uchar(self):
        self.assertFalse(uchar.mean(numx.array([1,2,3], UInt8)) != 2)
        self.assertFalse(uchar.mean([1,2,3]) != 2)
        
    def test_sd(self):
        self.assertFalse(sd(numx.array([-1.,-3.,1.])) != 2.0)

    def test_sd_long(self):
        self.assertFalse(long.sd(numx.array([-1,-3,1])) != 2)

    def test_sd_m(self):
        self.assertFalse(sd_m(numx.array([-1.,-3.,1.]),
                         mean(numx.array([-1.,-3.,1.]))) != 2.0)
        
    def test_sd_m_long(self):
        self.assertFalse(long.sd_m(numx.array([-1,-3,1]),
                              long.mean(numx.array([-1,-3,1]))) != 2)

    def test_variance(self):
        self.assertFalse(variance(numx.array([-1.,-3.,1.])) != 4.0)
        return

    def test_variance_long(self):
        self.assertFalse(long.variance(numx.array([-1,-3,1])) != 4.0)
        return
    
    def test_variance_m(self):
        self.assertFalse(variance_m(numx.array([-1.,-3.,1.]),
                               mean(numx.array([-1.,-3.,1.]))) != 4.0)
        return
        
    def test_variance_m_long(self):
        self.assertFalse(long.variance_m(numx.array([-1,-3,1]),
                                    long.mean(numx.array([-1,-3,1]))) != 4)
        return


    def test_min_long(self): 
        self.assertFalse(long.min(numx.array([1,2,3])) != 1)

    def test_max_long(self):
        self.assertFalse(long.max(numx.array([1,2,3])) != 3)


    def test_min_index(self): 
        self.assertFalse(long.min_index(numx.array([1,2,3])) != 0)

    def test_max_index(self):
        self.assertFalse(long.max_index(numx.array([1,2,3])) != 2)


if __name__ == "__main__":
    unittest.main()
