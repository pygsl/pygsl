import string
import unittest
import math
import pygsl.const

version = string.split(pygsl.compiled_gsl_version, '.')
major_version = version[0]
minor_version = version[1]

if major_version == 1 and minor_version < 4:
    import pygsl.const.cgs as cgs
    import pygsl.const.mks as mks
else:
    import pygsl.const.cgsm as cgs
    import pygsl.const.mksa as mks
    
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
        my_c=cgs.speed_of_light

    def test_c(self):
        """
        is the factor 100 between meter and centimeter correct?
        """
        self.failIf(cgs.speed_of_light/mks.speed_of_light!=100)

    def test_default(self):
        self.failIf(cgs.speed_of_light/pygsl.const.speed_of_light!=100)

if __name__ == "__main__":
    unittest.main()
