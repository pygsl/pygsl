import types
import unittest
import math
import copy
import Numeric
import MLab
import pygsl.testing.rng as rngmodule
import sys
sys.stdout = sys.stderr
rng_types = rngmodule.types_setup()


class _rng_type:
    _type = None

for i in rng_types:
    tmp = "class %s(_rng_type): _type = rngmodule.%s" % ((i,) * 2)
    exec(tmp)


class _rng_basics(unittest.TestCase):
    """
    here are things tested like allocation, destruction, initialisation
    """
    def test_alloc(self):
        """
        allocate the default rng
        """
        rng=rngmodule.rng(self._type)
        self.failIf(rng.name()=="","name of rng was \"\"")
        self.failIf(rng.name() is None,"name of rng was None")
        rng=None

    def test_uniform(self):
        """
        get one value from rng
        """
        rng=rngmodule.rng(self._type)
        value=rng.uniform()
        rng=None
        self.failIf(value<0 or value>=1.0,
                    "value of %f not expected from uniform distribution"%value)

    def test_uniform_pos(self):
        """
        get one value from rng
        """
        rng=rngmodule.rng(self._type)
        value=rng.uniform_pos()
        rng=None
        self.failIf(value<0 or value>1.0,
                    "value of %f not expected from uniform distribution"%value)


    def test_rng_reproduce(self):
        rng=rngmodule.rng(self._type)
        rng.set(1)
        value1=rng.get()
        rng.set(1)
        value2=rng.get()
        self.failIf(value1!=value2,"values from rng not reproducable")

class _rng_distributions(unittest.TestCase):
    """
    test different distributions
    """
    def setUp(self):
	#print "Testing Class ", self.__class__.__name__
	sys.stdout.flush()
	sys.stderr.flush()
        self.rng=rngmodule.rng(self._type)

    def tearDown(self):
        self.rng=None

    def testMin(self):
        min = self.rng.min()
        assert(type(min) == types.LongType)
        
    def testMax(self):
        max = self.rng.max()
        assert(type(max) == types.LongType)
        
    def testMinMax(self):
        min = self.rng.min()
        max = self.rng.max()
        assert(min<max)

    def testcopy(self):
        rng = copy.copy(self.rng)
        for i in range(10):
            assert(rng.get() == self.rng.get())


    def test_uniform_int(self):
        for i in range(10):
            tmp = self.rng.uniform_int(2)
            assert(tmp>=0)
            assert(tmp<=2)

    def _test_generic_return_generic(self, method, pdf_method, mytype, arraytype, *args):
        test = 0
        try:
            d = method(*args)
            assert(type(d) == mytype)
            if pdf_method:
                p = apply(pdf_method, (d,) + args)
                assert(type(p) == types.FloatType)
            da = apply(method, args + (10,))
            assert(type(da) == Numeric.ArrayType)
            assert(len(da.shape) == 1)
            assert(da.typecode() == arraytype)
            assert(da.shape[0] == 10)
            if pdf_method:
                pa = apply(pdf_method, (da,) + args)
                assert(type(pa) == Numeric.ArrayType)
                assert(len(pa.shape) == 1)
                assert(pa.typecode() == Numeric.Float)
                assert(pa.shape[0] == 10)                
            test = 1
        finally:
            if test == 0:
                print "I was testing %s and pdf function %s " %(method, pdf_method)

    def _test_ui_return_one(self, method, pdf_method, *args):
        self._test_generic_return_generic(method, pdf_method, types.LongType,
                                          Numeric.Int, *args)
        
    def _test_double_return_one(self, method, pdf_method, *args):
        self._test_generic_return_generic(method, pdf_method, types.FloatType,
                                          Numeric.Float, *args)
            
                
    def _test_nd_return_one(self, method, pdf_method, n, *args):
        test = 0
        try:
            d = method(*args)
            assert(len(d) == n)
            for i in d:
                assert(type(i) == types.FloatType)
            if pdf_method:
                p = apply(pdf_method, tuple(d) + args)
                assert(type(p) == types.FloatType)
            da = apply(method, args + (10,))
            assert(type(da) == Numeric.ArrayType)
            assert(da.typecode() == Numeric.Float)
            assert(len(da.shape) == 2)
            assert(da.shape[0] == 10)
            assert(da.shape[1] == n)
            test = 1
            if pdf_method:                
                pa = apply(pdf_method, (da[:,0], da[:,1]) + args)
                assert(type(pa) == Numeric.ArrayType)
                assert(pa.typecode() == Numeric.Float)
                assert(len(pa.shape) == 1)
                assert(pa.shape[0] == 10)
                assert(type(p) == types.FloatType)

        finally:
            if test == 0:
                print "I was testing ", method

    def _test_ui_return(self, methods, *args):
        for i in methods:
            tmp = getattr(self.rng, i)
            try:
                pdf = getattr(rngmodule, i + '_pdf')
            except AttributeError:
                pass
            pdf = getattr(rngmodule, i + '_pdf')
            self._test_ui_return_one(tmp, pdf, *args)

    def _test_double_return(self, methods, *args):
        for i in methods:
            tmp = getattr(self.rng, i)
            try:
                pdf = getattr(rngmodule, i + '_pdf')
            except AttributeError:
                pass                
            self._test_double_return_one(tmp, pdf, *args)

    def _test_nd_return(self, methods, *args):
        for i in methods:
            tmp = getattr(self.rng, i)
            pdf = None
            try:
                pdf = getattr(rngmodule, i + '_pdf')
            except AttributeError:
                pass
            self._test_nd_return_one(tmp, pdf, *args)

    def test_ui_to_double(self):        
        self._test_double_return_one(self.rng.gamma_int, None, 1000L)
        
    def test_to_double(self):
        t = ('ugaussian',              
             'ugaussian_ratio_method', 
             'landau')

        self._test_double_return(t)
            
    def test_d_to_double(self):
        t = ('gaussian',              
             'gaussian_ratio_method', 
             'ugaussian_tail',        
             'exponential',           
             'laplace',               
             'cauchy',                
             'rayleigh',              
             'chisq',                 
             'tdist',                 
             'logistic')
        self._test_double_return(t, 1.0)
            
    def test_dd_to_double(self):
        t = ('gaussian_tail',
             'exppow',       
             'rayleigh_tail',
             'levy',         
             'gamma',        
             'flat',         
             'lognormal',    
             'fdist',        
             'beta',         
             'pareto',       
             'weibull',      
             'gumbel1',      
             'gumbel2',      
             'erlang')
        self._test_double_return(t, 2.0, 3.0)

    def test_ddd_to_double(self):
        self._test_double_return_one(self.rng.levy_skew, None, 0, 1.0, 2.0)



    def test_d_to_ui(self):
        t = ('poisson',    
             'bernoulli',  
             'geometric',  
             'logarithmic')
        self._test_ui_return(t, 2.3)
        
    def test_dd_to_ui(self):
        t = ('binomial', 
             'pascal',
             'negative_binomial')
        self._test_ui_return(t, 2.0, 4.5)

    def test_uiuiui_to_ui(self):
        self._test_ui_return_one(self.rng.hypergeometric, rngmodule.hypergeometric_pdf,
                                 4L, 2L, 56L)


    def test_ddd_to_dd(self):
        self._test_nd_return_one(self.rng.bivariate_gaussian, rngmodule.bivariate_gaussian_pdf,
                                 2, 0, 1, 2)

    def test_dir(self):
        self._test_nd_return_one(self.rng.dir_2d, None, 2)
        self._test_nd_return_one(self.rng.dir_2d_trig_method, None, 2)
        self._test_nd_return_one(self.rng.dir_3d, None, 3)
        self._test_nd_return_one(self.rng.dir_nd, None, 1, 1)
        self._test_nd_return_one(self.rng.dir_nd, None, 2, 2)
        self._test_nd_return_one(self.rng.dir_nd, None, 3, 3)
        self._test_nd_return_one(self.rng.dir_nd, None, 4, 4)
        self._test_nd_return_one(self.rng.dir_nd, None, 5, 5)
        self._test_nd_return_one(self.rng.dir_nd, None, 6, 6)

    def test_dirichlet(self):
        a = Numeric.arange(10) * .1 + .1
        d = self.rng.dirichlet(a)
        assert(type(d) == Numeric.ArrayType)
        assert(d.typecode() == Numeric.Float)
        assert(len(d.shape) == 1)
        assert(d.shape[0] == a.shape[0])
        ra = Numeric.reshape(a, (a.shape[0], -1))
        ra = Numeric.transpose(ra)
        p = rngmodule.dirichlet_pdf(d,ra)
        d = self.rng.dirichlet(a,100)
        assert(type(d) == Numeric.ArrayType)
        assert(d.typecode() == Numeric.Float)
        assert(len(d.shape) == 2)
        assert(d.shape[0] == 100)
        assert(d.shape[1] == a.shape[0])

    def test_multinomial(self):
        pass
     
    def test_gaussian(self):
        sum=0
        count=0
        num=10000
        accepted_deviation=math.sqrt(num)*5.0
        sum = Numeric.add.reduce(self.rng.gaussian(1.0, num))
        self.failIf(abs(sum)>accepted_deviation,"the sum of %d gaussian values is %g"%(num,sum))

    def test_gaussian_tail(self):
        self.rng.gaussian_tail(1.0, 0.5, 1000)


#print "Last rng = ", rng_types[-1]
for i in rng_types[:3]:
    tmp = "class %s_rng_basics(%s, _rng_basics): pass" % ((i,) *2)
    exec(tmp)
    tmp = "class %s_rng_distributions(%s, _rng_distributions): pass" % ((i,) *2)
    exec(tmp)

del _rng_basics
del _rng_distributions



if __name__ == "__main__":
    unittest.main()


