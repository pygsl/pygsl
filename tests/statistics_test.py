# statistics tests
#
# author: Jochen K"upper

import unittest
try:
    from Numeric import array
except ImportError:
    array=lambda seq:seq

from pygsl.statistics import *
import pygsl.statistics.long as long

class statistics_test(unittest.TestCase):
    """Simple tests on statistics functions"""

    def test_mean(self):
        self.failIf(mean(array([-1.,-3.,1.])) != -1.0)
        self.failIf(mean([1, 2, 3]) != 2)

    def test_mean_long(self):
        self.failIf(long.mean(array([-1,-3,1])) != -1)
        self.failIf(long.mean([1, 2, 3]) != 2)

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
