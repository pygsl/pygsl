import unittest
import math
import pygsl.histogram
import warnings
import exceptions
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
        hist.set_ranges(range(len(hist)+1))
        self.failIf(100!=hist.max())
        self.failIf(0!=hist.min())
        hist.alloc(2)
        exception_seen=0
        try:
            hist.set_ranges((1,2))
        except exceptions.TypeError:
            exception_seen=1
        self.failIf(exception_seen==0)
        exception_seen=0
        try:
            hist.set_ranges((1,2,"bla"))
        except exceptions.TypeError:
            exception_seen=1
        self.failIf(exception_seen==0)

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

    def test_as_map(self):
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(0,100)
        self.failIf(len(hist)!=100)
        hist[2]=1
        self.failIf(hist.get(2)!=1)
        self.failIf(hist[2]!=1)
        del hist[2]
        self.failIf(hist[2]!=0)

    def test_shiftscale(self):
        hist=pygsl.histogram.histogram(100)
        hist.shift(1)
        self.failIf(hist[1]!=1)
        hist.scale(10)
        self.failIf(hist[1]!=10)

    def test_compare_ranges(self):
        hist1=pygsl.histogram.histogram(100)
        hist2=pygsl.histogram.histogram(100)
        hist1.set_ranges_uniform(1,2)
        hist2.set_ranges_uniform(1,2)
        self.failIf(not hist1.equal_bins_p(hist2))

    def test_add_sub(self):
        hist1=pygsl.histogram.histogram(100)
        hist2=pygsl.histogram.histogram(100)
        hist1.set_ranges_uniform(1,2)
        hist2.set_ranges_uniform(1,2)
        hist1.shift(1)
        hist2.shift(2)
        hist1.add(hist2)
        self.failIf(hist1[1]!=3)
        hist2.sub(hist1)
        self.failIf(hist2[1]!=-1)
        self.failIf(hist1[1]!=3)

if __name__ == "__main__":
    unittest.main()
   
