# statistics tests
#
# author: Jochen K"upper

import unittest
try:
    from Numeric import *
except ImportError:
    print "Numpy not available, some tests are pretty meaningless..."
    array = lambda seq: seq

import random

from pygsl.statistics import *
from pygsl.statistics import float as float
from pygsl.statistics import long as long
from pygsl.statistics import short as short


class statistics_test(unittest.TestCase):
    """Simple tests on statistics functions"""

    def test_mean(self):
        self.failIf(mean(array([-1.,-3.,1.])) != -1.0)
        self.failIf(mean([1,2,3]) != 2)
        # test stride != 1
        # these are only valid tests when using NumPy,
        # since otherwise the sequence is trnsformed to an
        # contigous array anyway...
        data = array([1.,2.,3.,4.,5.,6.,7.,8.,9.,10.])
        self.failIf(mean(data) != 5.5)
        self.failIf(mean(data[::-1]) != 5.5)
        self.failIf(mean(data[::2]) != 5.0)
        self.failIf(mean(data[::-2]) != 6.0)

    def test_mean_float(self):
        self.failIf(float.mean(array([-1.,-3.,1.], Float32)) != -1)
        self.failIf(float.mean([1.,2.,3.]) != 2)
        return
    
    def test_mean_long(self):
        self.failIf(long.mean(array([-1,-3,1])) != -1)
        self.failIf(long.mean([1, 2, 3]) != 2)

    def test_mean_short(self):
        self.failIf(short.mean(array([-1,-3,1], Int16)) != -1)
        self.failIf(short.mean([1,2,3]) != 2)

    def test_sd(self):
        self.failIf(sd(array([-1.,-3.,1.])) != 2.0)

    def test_sd_long(self):
        self.failIf(long.sd(array([-1,-3,1])) != 2)

    def test_sd_m(self):
        self.failIf(sd_m(array([-1.,-3.,1.]),
                         mean(array([-1.,-3.,1.]))) != 2.0)
    def test_sd_m_long(self):
        self.failIf(long.sd_m(array([-1,-3,1]),
                              long.mean(array([-1,-3,1]))) != 2)

    def test_variance(self):
        self.failIf(variance(array([-1.,-3.,1.])) != 4.0)

    def test_variance_long(self):
        self.failIf(long.variance(array([-1,-3,1])) != 4)

    def test_variance_m(self):
        self.failIf(variance_m(array([-1.,-3.,1.]),
                               mean(array([-1.,-3.,1.]))) != 4.0)
    def test_variance_m_long(self):
        self.failIf(long.variance_m(array([-1,-3,1]),
                                    long.mean(array([-1,-3,1]))) != 4)


if __name__ == "__main__":
    unittest.main()
