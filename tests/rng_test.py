import unittest
import math
import pygsl.rng

class rng_basics(unittest.TestCase):
    """
    here are things tested like allocation, destruction, initialisation
    """
    def test_alloc(self):
        """
        allocate the default rng
        """
        rng=pygsl.rng.gsl_rng()
        self.failIf(rng.name()=="","name of rng was \"\"")
        self.failIf(rng.name() is None,"name of rng was None")
        rng=None

    def test_generate_numbers(self):
        """
        get one value from rng
        """
        rng=pygsl.rng.gsl_rng()
        value=rng.uniform()
        rng=None
        self.failIf(value<0 or value>=1.0,"value of %f not expected from uniform distribution"%value)

    def test_gsl_rng_rand(self):
        rng=pygsl.rng.gsl_rng_rand()
        rng=None

    def test_rng_reproduce(self):
        rng=pygsl.rng.gsl_rng()
        rng.set(1)
        value1=rng.get()
        rng.set(1)
        value2=rng.get()
        self.failIf(value1!=value2,"values from rng not reproducable")

class rng_distributions(unittest.TestCase):
    """
    test different distributions
    """
    def setUp(self):
        self.rng=pygsl.rng.gsl_rng()

    def tearDown(self):
        self.rng=None

    def test_gaussian(self):
        sum=0
        count=0
        num=1000
        accepted_deviation=math.sqrt(num)*2.0
        while count<num:
            sum+=self.rng.gaussian(1.0)
            count+=1
        self.failIf(abs(sum)>accepted_deviation,"the sum of %d gaussian values is %g"%(num,sum))

if __name__ == "__main__":
    unittest.main()
   
