# statistics tests
#
# author: Jochen K"upper

import unittest
make_array=lambda seq:seq
try:
    import Numeric
    make_array=Numeric.array
except ImportError:
    pass
    
from pygsl.statistics import *

epsilon = 1e-8



class statistics_test(unittest.TestCase):
    """Simple tests on statistics functions"""

    def test_mean(self):
        self.failIf(mean(make_array([-1.,-3.,1.])) != -1.0)
        self.failIf(mean([1, 2, 3]) != 2)

    def test_sd(self):
        self.failIf(sd(make_array([-1.,-3.,1.])) != 2.0)

    def test_sd_m(self):
        self.failIf(sd_m(make_array([-1.,-3.,1.]),
                         mean(make_array([-1.,-3.,1.]))) != 2.0)

    def test_variance(self):
        self.failIf(variance(make_array([-1.,-3.,1.])) != 4.0)

    def test_variance_m(self):
        self.failIf(variance_m(make_array([-1.,-3.,1.]),
                               mean(make_array([-1.,-3.,1.]))) != 4.0)


if __name__ == "__main__":
    unittest.main()
