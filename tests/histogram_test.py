import unittest
import math
import pygsl.histogram
import warnings
import pygsl.errors

class histogram_basics(unittest.TestCase):
    """
    here are things tested like allocation, destruction, initialisation
    """
    def test_alloc(self):
        """
        allocate a histogram
        """
        hist=pygsl.histogram.histogram(100)
        self.failIf(hist.bins()!=100)
        hist.alloc(500)
        self.failIf(hist.bins()!=500)
        exception_seen=0
        try:
            hist.alloc(-1)
        except pygsl.errors.gsl_Error:
            exception_seen=1
        self.failIf(exception_seen==0)
        self.failIf(hist.bins()!=500)
        
    def test_initialize(self):
        """
        allocate a histogram
        """
        hist=pygsl.histogram.histogram(100)
        self.failIf(hist.bins()!=100)
        hist.set_ranges_uniform(0.0,2.0)
        self.failIf(hist.min()!=0.0)
        self.failIf(hist.max()!=2.0)

    def test_DomainWarning(self):
        """
        """
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(1,20)
        # raise domain warning as exception here...
        exception_seen=0
        warnings.filterwarnings("error",
                                category=pygsl.errors.gsl_DomainWarning)
        try:
            hist.increment(22)
        except pygsl.errors.gsl_Warning:
            exception_seen=1
        self.failIf(exception_seen==0)
        # no warning/exception should occur
        hist.increment(10)

    def test_ranges(self):
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(0,20)
        self.failIf(0!=hist.get_range(0)[0])
        self.failIf(20!=hist.get_range(99)[1])
        self.failIf(0!=hist.find(0))
        self.failIf(99!=hist.find(19.9999))

    def test_minimax(self):
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(0,20)
        hist.increment(10)
        hist.accumulate(0,-1)
        self.failIf(1!=hist.max_val())
        self.failIf(50!=hist.max_bin())
        self.failIf(-1!=hist.min_val())
        self.failIf(0!=hist.min_bin())

    def test_meansigma(self):
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(0,20)
        hist.increment(10)
        self.failIf(10.1!=hist.mean())

if __name__ == "__main__":
    unittest.main()
   
