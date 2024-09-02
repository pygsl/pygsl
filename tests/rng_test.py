from __future__ import print_function
import types
import unittest
import math
import copy
import pygsl
numx =  pygsl._numobj

import pygsl.rng as rngmodule
import sys
sys.stdout = sys.stderr
from pygsl import Float, Int
import numpy as np
from array_check import array_check
from gsl_test import isfloat, iscomplex, array_max

class _rng_type:
    _type = None

if sys.version_info[0] >= 3:
    _longtype = type(1)
else:
    _longtype = types.LongType

def convert_rng_names():
    names = rngmodule.list_available_rngs()
    result = []
    for name in names:
        tmp = name.replace('-', '_')
        result.append(tmp)
    result = tuple(result)
    return result

rng_types = convert_rng_names()


class _rng_basics(unittest.TestCase):
    """here are things tested like allocation, destruction, initialisation
    """
    def test_alloc(self):
        """allocate the default rng
        """

        rng=self._type()
        self.assertFalse(rng.name()=="","name of rng was \"\"")
        self.assertFalse(rng.name() is None,"name of rng was None")
        rng=None

    def test_uniform(self):
        """get one value from rng
        """
        rng=self._type()
        value=rng.uniform()
        rng=None
        self.assertFalse(value<0 or value>=1.0,
                    "value of %f not expected from uniform distribution"%value)

    def test_uniform_pos(self):
        """get one value from rng
        """
        rng=self._type()
        value=rng.uniform_pos()
        rng=None
        self.assertFalse(value<0 or value>1.0,
                         "value of %f not expected from uniform distribution"%value)


    def test_rng_reproduce(self):
        rng=self._type()
        rng.set(1)
        value1=rng.get()
        rng.set(1)
        value2=rng.get()
        self.assertFalse(value1!=value2,"values from rng not reproducable")

class _rng_distributions(unittest.TestCase):
    """test different distributions
    """
    def setUp(self):
        #print ("Testing Class ", self.__class__.__name__)
        sys.stdout.flush()
        sys.stderr.flush()
        self.rng=self._type()


    def tearDown(self):
        self.rng=None

    def testMin(self):
        min = self.rng.min()
        assert(type(min) == _longtype)

    def testMax(self):
        max = self.rng.max()
        assert(type(max) == _longtype)

    def testMinMax(self):
        min = self.rng.min()
        max = self.rng.max()
        assert(min<max)

    def testcopy(self):
        rng = self.rng.clone()
        for i in range(10):
            assert(rng.get() == self.rng.get())


    def test_uniform_int(self):
        for i in range(10):
            tmp = self.rng.uniform_int(2)
            assert(tmp>=0)
            assert(tmp<=2)

    def _test_generic_return_generic(self, method, pdf_method, mytype, arraytype, *args):
        a_result = method(*args)
        #flag = type(a_result) == mytype
        #assert(flag)
        if pdf_method:
            tmp =  (a_result,) + args
            test2 = 0
            try:
                p = pdf_method(*tmp)
                test2 = 1
            finally:
                if test2 == 0:
                    print("called pdf method", pdf_method)
                    print("with args", tmp)

            assert(isfloat(p))

        tmp = args + (10,)
        da = method(*tmp)

        array_check(da, arraytype, (10,))
        if pdf_method:

            tmp = (da,) + args
            pa = pdf_method(*tmp)
            array_check(pa, Float, (10,))

    def _test_ui_return_one(self, method, pdf_method, *args):
        self._test_generic_return_generic(method, pdf_method, type(10),
                                          Int, *args)

    def _test_double_return_one(self, method, pdf_method, *args):
        self._test_generic_return_generic(method, pdf_method, type(10),
                                          Float, *args)


    def _test_nd_return_one(self, method, pdf_method, n, *args):
        test = 0
        try:
            d = method(*args)
            assert(len(d) == n)
            for i in d:
                assert(isfloat(i))
            if pdf_method:
                p = pdf_method(*(tuple(d) + args))
                assert(isfloat(p))
            da = method( *(args + (10,)))
            array_check(da, Float, (10, n))
            if pdf_method:
                x = da[:,0]
                y = da[:,1]
                pa = pdf_method( *((x, y) + args))
                array_check(da, Float, (10,2))
            test = 1
        finally:
            if test == 0:
                print( "I was testing ", method, "with args", args)

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
            pdf = None
            try:
                pdf = getattr(rngmodule, i + '_pdf')
            except AttributeError:
                pass

            test = 0
            try:
                self._test_double_return_one(tmp, pdf, *args)
                test = 1
            finally:
                if test == 0:
                    print( "I was operating on method", i, "of rng", self.rng.name())
                    print( "using", tmp, "and", pdf)

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
        self._test_double_return_one(self.rng.gamma_int, None, 1000)

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
             'logistic'
             )
        self._test_double_return(t, 2.0)

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
                                 4, 2, 56)


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
        a = numx.arange(10) * .1 + .1
        d = self.rng.dirichlet(a)
        array_check(d, Float, (a.shape[0],))
        ra = numx.reshape(a, (a.shape[0], -1))
        ra = numx.transpose(ra)
        p = rngmodule.dirichlet_pdf(d,ra)
        d = self.rng.dirichlet(a,100)
        array_check(d, Float, (100, a.shape[0]))

    def test_multinomial(self):
        phi = (0.2,0.2,0.2,0.4)
        n = self.rng.multinomial(10, phi, 1)
        array_check(n, np.uint32, [1, len(phi)])

        n_sample = 3
        n = self.rng.multinomial(10, phi, n_sample)
        array_check(n, np.uint32, [n_sample, len(phi)])


    def test_gaussian(self):
        sum=0
        count=0
        num=10000
        accepted_deviation=math.sqrt(num)*5.0
        sum = numx.add.reduce(self.rng.gaussian(1.0, num))
        self.assertFalse(abs(sum)>accepted_deviation,"the sum of %d gaussian values is %g"%(num,sum))

    def test_gaussian_tail(self):
        self.rng.gaussian_tail(1.0, 0.5, 1000)

# I guess this is now supported by all available installations
rng_notimplemented_types = [
    #"knuthran2002",
    #"slatec",
    #"uni"
]
class TestIfAll(unittest.TestCase):
    """
    Now all different rng's have to be added by hand. GSL and its wrapper
    provide a list of all available rngs. Test if all are here
    """

    def test(self):
        refrng = rngmodule.rng()
        mylist = rng_types
        for i in mylist:
            if i in rng_notimplemented_types:
                print ("Not Testing for ", i)
                continue

            rngtypeinit = getattr(rngmodule, i)
            r = rngtypeinit()
            test = 0
            try:
                assert(type(r) == type(refrng))
                test = 1
            finally:
                if test == 0:
                    print( "r      = %s %s" % (type(r), repr(r)))
                    print( "refrng = %s %s" % (type(refrng), repr(refrng)))


#print (rng_types)
#print (rng_notimplemented_types)
for i in rng_types:
    if i in rng_notimplemented_types:
        print ("Skipping rng type", i)
        continue

    tmp = "class %s(_rng_type): _type = rngmodule.%s" % ((i,) * 2)
    #print(tmp)
    exec(tmp)

    tmp = "class %s_rng_basics(%s, _rng_basics): pass" % ((i,) *2)
    #print(tmp)
    exec(tmp)

    tmp = "class %s_rng_distributions(%s, _rng_distributions): pass" % ((i,) *2)
    #print(tmp)
    exec(tmp)


del _rng_basics
del _rng_distributions



if __name__ == "__main__":
    unittest.main()
