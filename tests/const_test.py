import unittest
import math
import pygsl.const

class math_const_test(unittest.TestCase):
    """
    the mere existence of mathmatical constants and simple correlations are tested
    """
    epsilon=1e-15

    def test_pi(self):
        my_pi=pygsl.const.pi

    def test_sqrt_2(self):
        self.failIf(abs(pygsl.const.sqrt2**2-2.0)>self.epsilon)

class sci_const_test(unittest.TestCase):
    """
    the mere existence of scientific constants and simple correlations are tested
    """
    def test_cgs_c(self):
        my_c=pygsl.const.cgs.speed_of_light

    def test_c(self):
        """
        is the factor 100 between meter and centimeter correct?
        """
        self.failIf(pygsl.const.cgs.speed_of_light/pygsl.const.mks.speed_of_light!=100)

    def test_default(self):
        self.failIf(pygsl.const.cgs.speed_of_light/pygsl.const.speed_of_light!=100)

if __name__ == "__main__":
    unittest.main()
