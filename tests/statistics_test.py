# statistics tests
#
# author: Jochen K"upper
#
# March 2004: Removed any code without Numeric
#
#
import unittest
import  pygsl._numobj as numx
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

from pygsl.statistics import *
from pygsl.statistics import char as char
from pygsl.statistics import float as float
from pygsl.statistics import int as int
from pygsl.statistics import long as long
from pygsl.statistics import short as short
from pygsl.statistics import uchar as uchar


class statistics_test(unittest.TestCase):
    """Simple tests on statistics functions"""

    def test_wmean(self):        
        self.failIf(wmean(numx.array([1,1,1]), numx.array([-1.,-3.,1.])) != -1.0)
        self.failIf(wmean(numx.array([1,1,1]),[1,2,3]) != 2)
        data = numx.array([1.,2.,3.,4.,5.,6.,7.,8.,9.,10.])
        weight = numx.ones(data.shape)
        self.failIf(wmean(weight,data) != 5.5)
        
        self.failIf(wmean(weight[::2],data[::2]) != 5.0)
        self.failIf(wmean(weight[::-1],data[::-1]) != 5.5)
        self.failIf(wmean(weight[::-2],data[::-2]) != 6.0)
            
    def test_mean(self):
        self.failIf(mean(numx.array([-1.,-3.,1.])) != -1.0)
        self.failIf(mean([1,2,3]) != 2)
        # test stride != 1
        # these are only valid tests when using NumPy,
        # since otherwise the sequence is trnsformed to an
        # contigous array anyway...
        data = numx.array([1.,2.,3.,4.,5.,6.,7.,8.,9.,10.])
        self.failIf(mean(data) != 5.5)

        self.failIf(mean(data[::2]) != 5.0)
        self.failIf(mean(data[::-1]) != 5.5)
        self.failIf(mean(data[::-2]) != 6.0)

    def test_mean_char(self):
        tmp = (ord("1") + ord("2") + ord("3")) / 3
        self.failIf(char.mean(numx.array([1,2,3], Int8)) != 2)
        self.failIf(char.mean([1,2,3]) != 2)
    
    def test_mean_float(self):
        self.failIf(float.mean(numx.array([-1.,-3.,1.], 'f')) != -1)
        self.failIf(float.mean([1.,2.,3.]) != 2)
    
    def test_mean_int(self):
        self.failIf(int.mean(numx.array([-1,-3,1], Int16)) != -1)
        self.failIf(int.mean([1,2,3]) != 2)
    
    def test_mean_long(self):
        self.failIf(long.mean(numx.array([-1,-3,1])) != -1)
        self.failIf(long.mean([1,2,3]) != 2)
        
    def test_mean_short(self):
        self.failIf(short.mean([1,2,3]) != 2)        
        self.failIf(short.mean(numx.array([-1,-3,1], Int16)) != -1)

    def test_mean_uchar(self):
        self.failIf(uchar.mean(numx.array([1,2,3], UInt8)) != 2)
        self.failIf(uchar.mean([1,2,3]) != 2)
        
    def test_sd(self):
        self.failIf(sd(numx.array([-1.,-3.,1.])) != 2.0)

    def test_sd_long(self):
        self.failIf(long.sd(numx.array([-1,-3,1])) != 2)

    def test_sd_m(self):
        self.failIf(sd_m(numx.array([-1.,-3.,1.]),
                         mean(numx.array([-1.,-3.,1.]))) != 2.0)
        
    def test_sd_m_long(self):
        self.failIf(long.sd_m(numx.array([-1,-3,1]),
                              long.mean(numx.array([-1,-3,1]))) != 2)

    def test_variance(self):
        self.failIf(variance(numx.array([-1.,-3.,1.])) != 4.0)
        return

    def test_variance_long(self):
        self.failIf(long.variance(numx.array([-1,-3,1])) != 4.0)
        return
    
    def test_variance_m(self):
        self.failIf(variance_m(numx.array([-1.,-3.,1.]),
                               mean(numx.array([-1.,-3.,1.]))) != 4.0)
        return
        
    def test_variance_m_long(self):
        self.failIf(long.variance_m(numx.array([-1,-3,1]),
                                    long.mean(numx.array([-1,-3,1]))) != 4)
        return


    def test_min_long(self): 
        self.failIf(long.min(numx.array([1,2,3])) != 1)

    def test_max_long(self):
        self.failIf(long.max(numx.array([1,2,3])) != 3)


    def test_min_index(self): 
        self.failIf(long.min_index(numx.array([1,2,3])) != 0)

    def test_max_index(self):
        self.failIf(long.max_index(numx.array([1,2,3])) != 2)


if __name__ == "__main__":
    unittest.main()
