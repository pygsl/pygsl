# statistics tests
#
# author: Jochen K"upper

import unittest
import Numeric as numpy
from pygsl.statistics import *

epsilon = 1e-8



class statistics_test(unittest.TestCase):
    """Simple tests on statistics functions"""

    def test_mean(self):
        self.failIf(mean(numpy.array([-1.,-3.,1.])) != -1.0)
        self.failIf(mean([1, 2, 3]) != 2)

    def test_sd(self):
        self.failIf(sd(numpy.array([-1.,-3.,1.])) != 2.0)

    def test_sd_m(self):
        self.failIf(sd_m(numpy.array([-1.,-3.,1.]),
                         mean(numpy.array([-1.,-3.,1.]))) != 2.0)

    def test_variance(self):
        self.failIf(variance(numpy.array([-1.,-3.,1.])) != 4.0)

    def test_variance_m(self):
        self.failIf(variance_m(numpy.array([-1.,-3.,1.]),
                               mean(numpy.array([-1.,-3.,1.]))) != 4.0)


if __name__ == "__main__":
    unittest.main()
