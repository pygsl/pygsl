import unittest
import math
import pygsl.histogram
import warnings
import exceptions
import pygsl.errors
import tempfile
import os
import os.path


pygsl.set_debug_level(0)
class histogram_tests(unittest.TestCase):
    """
    gsl_histogram tests
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
        except pygsl.errors.gsl_DomainWarning:
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
        except pygsl.errors.gsl_InvalidArgumentError:
            exception_seen=1
        self.failIf(exception_seen==0)
        exception_seen=0
        try:
            hist.set_ranges((1,2,"bla"))
        except exceptions.Exception:
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

    def test_meansigmasum(self):
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(0,20)
        hist.increment(10)
        self.failIf(10.1!=hist.mean())
        self.failIf(hist.sum()!=1)

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

    def test_readwrite(self):
        self.my_filename=tempfile.mktemp()
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(1,2)
        hist[10]=1
        # write it
        hist_file=file(self.my_filename,'w')
        hist.write(hist_file)
        hist_file.close()
        # clear and change histogram
        hist.set_ranges_uniform(0,1)
        # reread it from file
        hist_file=file(self.my_filename,'r')
        hist.read(hist_file)
        hist_file.close()
        self.failIf(hist.max()!=2 or hist.min()!=1 or hist[10]!=1 or hist[99]!=0,
                    "rereading histogram failed")

    def test_scanfprintf(self):
        self.my_filename=tempfile.mktemp()
        hist=pygsl.histogram.histogram(100)
        hist.set_ranges_uniform(1,2)
        hist[10]=1
        # write it
        hist_file=file(self.my_filename,'w')
        hist.printf(hist_file,"%g","%f")
        hist_file.close()
        # clear and change histogram
        hist.set_ranges_uniform(0,1)
        # reread it from file
        hist_file=file(self.my_filename,'r')
        hist.scanf(hist_file)
        hist_file.close()
        self.failIf(hist.max()!=2 or hist.min()!=1 or hist[10]!=1 or hist[99]!=0,
                    "rescaning histogram failed")

    def tearDown(self):
        # clean up files
        if 'my_filename' in vars(self) and os.path.isfile(self.my_filename):
            os.remove(self.my_filename)
            del self.my_filename


class histogram2d_tests(unittest.TestCase):
    """
    gsl_histogram2d tests
    """
    def test_alloc(self):
        """
        allocate a histogram
        """
        hist=pygsl.histogram.histogram2d(100,100)
        # clone will fail, if not initialised
        hist.set_ranges_uniform(-1,1,-1,1)
        hist[3,3]=5
        self.failIf(hist[3,3]!=5,"mapping protocol failed")
        hist2=pygsl.histogram.histogram2d(hist)
        self.failIf(hist2[3,3]!=5,"copy constructor failed")
        hist2=hist.clone()
        self.failIf(hist2[3,3]!=5,"clone failed")

    def test_initialize(self):
        """
        allocate a histogram
        """
        hist=pygsl.histogram.histogram2d(100,200)
        self.failIf(hist.nx()!=100)
        self.failIf(hist.ny()!=200)
        hist.set_ranges_uniform(0.0,2.0,0.0,2.0)
        self.failIf(hist.xmin()!=0.0)
        self.failIf(hist.xmax()!=2.0)
        self.failIf(hist.ymin()!=0.0)
        self.failIf(hist.ymax()!=2.0)

    def test_DomainWarning(self):
        """
        """
        hist=pygsl.histogram.histogram2d(100,100)
        hist.set_ranges_uniform(1,20,1,20)
        # raise domain warning as exception here...
        exception_seen=0
        warnings.filterwarnings("error",
                                category=pygsl.errors.gsl_DomainWarning)
        try:
            hist.increment(22,0)
        except pygsl.errors.gsl_Warning:
            exception_seen=1
        self.failIf(exception_seen==0)
        # no warning/exception should occur
        hist.increment(10,10)

    def test_mapping_protocol(self):
        """
        test things like h[3,4]=0
        """
        hist=pygsl.histogram.histogram2d(100,100)
        # raise domain warning as exception here...
        self.failIf(len(hist)!=100*100,"length function does not work")
        hist[0,0]=1
        hist[99,99]=1
        self.failIf(hist[0,0]!=1 or hist[99,99]!=1,"subscription does not work")
        exception_seen=0
        try:
            hist[-1,-1]=0
        except pygsl.errors.gsl_Error:
            exception_seen=1
        self.failIf(exception_seen==0,"no error produced by hist[-1,-1]")
        exception_seen=0
        try:
            hist[100,0]=0
        except pygsl.errors.gsl_Error:
            exception_seen=1
        self.failIf(exception_seen==0,"no error produced by hist[100,0]")
        
    def test_statistics(self):
        """
        sum, mean, sigma and cov
        """
        hist=pygsl.histogram.histogram2d(100,100)
        hist.set_ranges_uniform(-1,1,-1,1)
        xmean=0.0
        ymean=0.0
        xsigma=0.3
        ysigma=0.3
        cov=0.5
        # bivariate normal distribution 
        my_dist=lambda x,y:math.exp((((x-xmean)/xsigma)**2\
                                     -2*cov*((x-xmean)/xsigma)*((y-ymean)/ysigma)\
                                     +((y-ymean)/ysigma)**2)\
                                    /(-2.0*(1-cov**2)))\
                                    /(2.0*math.pi*xsigma*ysigma*math.sqrt(1-cov**2))
        for i in xrange(0,hist.nx()):
            (ux,lx)=hist.get_xrange(i)
            mx=(ux+lx)/2.0
            for j in xrange(0,hist.ny()):
                (uy,ly)=hist.get_yrange(j)
                hist[i,j]=my_dist(mx,(uy+ly)/2.0)
        self.failIf(abs(hist.sum()/(hist.nx()*hist.ny()/(hist.xmax()-hist.xmin())/(hist.ymax()-hist.ymin()))\
                        -1)>2.0/hist.nx())
        self.failIf(abs(hist.xmean()-xmean)>2.0/hist.nx())
        self.failIf(abs(hist.ymean()-ymean)>2.0/hist.ny())
        self.failIf(abs(hist.xsigma()-xsigma)>2.0/hist.nx())
        self.failIf(abs(hist.ysigma()-ysigma)>2.0/hist.ny())
        self.failIf(abs(hist.cov()/(hist.xsigma()*hist.ysigma())-cov)>2.0/hist.nx())

    def test_set_ranges(self):
        hist=pygsl.histogram.histogram2d(50,100)
        hist.set_ranges(xrange(0,51),xrange(2,103))
        for i in xrange(0,hist.nx()):
            (lx,ux)=hist.get_xrange(i)
            self.failIf(lx!=i or ux!=i+1)
        for j in xrange(0,hist.ny()):
            (ly,uy)=hist.get_yrange(j)
            self.failIf(ly!=j+2 or uy!=j+3)

    def test_addsubdivmul(self):
        """
        ToDo
        """
        hist1=pygsl.histogram.histogram2d(100,10)
        hist2=pygsl.histogram.histogram2d(100,10)
        hist1.set_ranges_uniform(1,2,1,2)
        hist2.set_ranges_uniform(1,2,1,2)
        hist1.shift(1)
        hist2.shift(2)
        hist1.add(hist2)
        self.failIf(hist1[1,3]!=3)
        hist2.sub(hist1)
        self.failIf(hist2[1,3]!=-1)
        self.failIf(hist1[1,3]!=3)

    def test_copy(self):
        """
        tests the copy command
        """
        hist=pygsl.histogram.histogram2d(100,10)
        hist.set_ranges_uniform(-1,1,-2,2)
        hist[1,3]=5
        hist2=pygsl.histogram.histogram2d(100,10)
        hist2.copy(hist)
        self.failIf(hist2.xmin()!=-1 or hist2.xmax()!=1,"copy failed")
        self.failIf(hist2.ymin()!=-2 or hist2.ymax()!=2,"copy failed")
        self.failIf(hist2[1,3]!=5,"copy failed")
        hist2=pygsl.histogram.histogram2d(10,10)
        exception_seen=0
        try:
            hist2.copy(hist)
        except pygsl.errors.gsl_Error:
            exception_seen=1
        self.failIf(exception_seen==0,"no error produced by hist.copy")

    def test_readwrite(self):
        self.my_filename=tempfile.mktemp()
        hist=pygsl.histogram.histogram2d(100,100)
        hist.set_ranges_uniform(1,2,3,4)
        hist[10,50]=1
        # write it
        hist_file=file(self.my_filename,'w')
        hist.write(hist_file)
        hist_file.close()
        # clear and change histogram
        hist.set_ranges_uniform(0,1,0,1)
        # reread it from file
        hist_file=file(self.my_filename,'r')
        hist.read(hist_file)
        hist_file.close()
        self.failIf(hist.xmax()!=2 or hist.ymin()!=3 or hist[10,50]!=1 or hist[99,99]!=0,
                    "rereading histogram failed")

    def test_scanfprintf(self):
        self.my_filename=tempfile.mktemp()
        hist=pygsl.histogram.histogram2d(100,100)
        hist.set_ranges_uniform(1,2,3,4)
        hist[10,50]=1
        # write it
        hist_file=file(self.my_filename,'w')
        hist.printf(hist_file,"%g","%f")
        hist_file.close()
        # clear and change histogram
        hist.set_ranges_uniform(0,1,0,1)
        # reread it from file
        hist_file=file(self.my_filename,'r')
        hist.scanf(hist_file)
        hist_file.close()
        self.failIf(hist.xmax()!=2 or hist.ymin()!=3 or hist[10,50]!=1 or hist[99,99]!=0,
                    "rereading histogram failed")

    def tearDown(self):
        # clean up files
        if 'my_filename' in vars(self) and os.path.isfile(self.my_filename):
            os.remove(self.my_filename)
            del self.my_filename



#test=unittest.TestSuite((histogram_tests, histogram2d_tests))

if __name__ == "__main__":
    unittest.main()
   
