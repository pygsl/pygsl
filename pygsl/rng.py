# author: Achim Gaedke
# created: May 2001
# file: pygsl/rng.py
# $Id$

# import internal functions
import pygsl._rng
import pygsl.errors

class rng:
    """
    base class for all gsl random number generators
    """

    def __init__(self,name="default",rng=None):
        """
        """
        self._rng=rng
        if self._rng==None:
            if pygsl._rng.__dict__.has_key(name):
                self._rng=pygsl._rng.alloc(pygsl._rng.__dict__[name])
            else:
                raise pygsl.errors.gsl_error,"no such random number generator"

    def __del__(self):
        """
        frees the random number generator
        """
        if self._rng is not None:
            pygsl._rng.free(self._rng)
            self._rng=None

    def __copy__(self):
        """
        clones the object
        """
        return gsl_rng(name=None,rng=pygsl._rng.copy(self._rng))

    def name(self):
        """
        name of this random number generator
        """
        return pygsl._rng.name(self._rng)

    def max(self):
        """
        largest number get() can return
        """
        return pygsl._rng.max(self._rng)

    def min(self):
        """
        smalest number get can return
        """
        return pygsl._rng.min(self._rng)

    def state(self):
        """
        internal state
        """
        pass

    def size(self):
        """
        byte size of internal state
        """
        pass

    def set(self,seed):
        """
        set seed (=start value)
        """
        pygsl._rng.set(self._rng,seed)

    # basic uniform distributions:

    def get(self):
        """
        """
        return pygsl._rng.get(self._rng)

    def uniform(self):
        """
        """
        return pygsl._rng.uniform(self._rng)

    def uniform_pos(self):
        """
        """
        return pygsl._rng.uniform_pos(self._rng)
        
    def uniform_int(self,n):
        """
        retruns random integer in [0;n-1]
        """
        return pygsl._rng.uniform_int(self._rng,n)

    # derived distributions:

    def gaussian(self,sigma):
        return pygsl._rng.gaussian(self._rng,sigma)

    def ugaussian(self):
        return pygsl._rng.ugaussian(self._rng)

    def gaussian_tail(self,a,sigma):
        return pygsl._rng.gaussian_tail(self._rng,a,sigma)

    def ugaussian_tail(self,a):
        return pygsl._rng.ugaussian_tail(self._rng,a)

    def bivariate_gaussian(self,sigma_x,sigma_y,rho):
        return pygsl._rng.bivariate_gaussian(self._rng,sigma_x,sigma_y,rho)

    def exponential(self,mu):
        return pygsl._rng.exponential(self._rng,mu)

    def laplace(self,mu):
        return pygsl._rng.laplace(self._rng,mu)

    def exppow(self,mu,a):
        return pygsl._rng.exppow(self._rng,mu,a)

    def cauchy(self,mu):
        return pygsl._rng.cauchy(self._rng,mu)

    def rayleigh(self,sigma):
        return pygsl._rng.rayleigh(self._rng,sigma)

    def rayleigh_tail(self,a,sigma):
        return pygsl._rng.rayleigh_tail(self._rng,a,sigma)

    def levy(self,mu,a):
        return pygsl._rng.levy(self._rng,mu,a)

    def gamma(self,a,b):
        return pygsl._rng.gamma(self._rng,a,b)

    def flat(self,a,b):
        return pygsl._rng.flat(self._rng,a,b)

    def lognormal(self,zeta,sigma):
        return pygsl._rng.lognormal(self._rng,zeta,sigma)

    def chisq(self,nu):
        return pygsl._rng.chisq(self._rng,nu)

    def fdist(self,nu1,nu2):
        return pygsl._rng.fdist(self._rng,nu1,nu2)

    def tdist(self,nu1,nu2):
        return pygsl._rng.tdist(self._rng,nu1,nu2)

    def beta(self,a,b):
        return pygsl._rng.beta(self._rng,a,b)

    def logistic(self,mu):
        return pygsl._rng.logistic(self._rng,mu)

    def pareto(self,a,b):
        return pygsl._rng.pareto(self._rng,a,b)

    def dir_2d(self):
        return pygsl._rng.dir_2d(self._rng)

    def dir_2d_trig_method(self):
        return pygsl._rng.dir_2d_trig_method(self._rng)

    def dir_3d(self):
        return pygsl._rng.dir_3d(self._rng)

    def dir_nd(self,n):
        return pygsl._rng.dir_nd(self._rng,n)

    def weibull(self,mu,a):
        return pygsl._rng.weibull(self._rng,mu,a)

    def gumbel1(self,a,b):
        return pygsl._rng.gumbel1(self._rng,a,b)

    def gumbel2(self,a,b):
        return pygsl._rng.gumbel2(self._rng,a,b)

    def poisson(self,mu):
        return pygsl._rng.poisson(self._rng,mu)

    def bernoulli(self,p):
        return pygsl._rng.bernoulli(self._rng,p)

    def binomial(self,p,n):
        return pygsl._rng.binomial(self._rng,p,n)

    def negative_binomial(self,p,n):
        return pygsl._rng.negative_binomial(self._rng,p,n)

    def pascal(self,p,k):
        return pygsl._rng.pascal(self._rng,p,k)

    def geometric(self,p):
        return pygsl._rng.geometric(self._rng,p)

    def hypergeometric(self,n1,n2,t):
        return pygsl._rng.hypergeometric(self._rng,n1,n2,t)

    def logarithmic(self,p):
        return pygsl._rng.logarithmic(self._rng,p)

    def landau(self):
        return pygsl._rng.landau(self._rng)

    def erlang(self,a,n):
        return pygsl._rng.erlang(self._rng,a,n)

class rng_borosh13(rng):
   def __init__(self):
      rng.__init__(self,"borosh13")

class rng_coveyou(rng):
   def __init__(self):
      rng.__init__(self,"coveyou")

class rng_cmrg(rng):
   def __init__(self):
      rng.__init__(self,"cmrg")

class rng_fishman18(rng):
   def __init__(self):
      rng.__init__(self,"fishman18")

class rng_fishman20(rng):
   def __init__(self):
      rng.__init__(self,"fishman20")

class rng_fishman2x(rng):
   def __init__(self):
      rng.__init__(self,"fishman2x")

class rng_gfsr4(rng):
   def __init__(self):
      rng.__init__(self,"gfsr4")

class rng_knuthran(rng):
   def __init__(self):
      rng.__init__(self,"knuthran")

class rng_knuthran2(rng):
   def __init__(self):
      rng.__init__(self,"knuthran2")

class rng_lecuyer21(rng):
   def __init__(self):
      rng.__init__(self,"lecuyer21")

class rng_minstd(rng):
   def __init__(self):
      rng.__init__(self,"minstd")

class rng_mrg(rng):
   def __init__(self):
      rng.__init__(self,"mrg")

class rng_mt19937(rng):
   def __init__(self):
      rng.__init__(self,"mt19937")

class rng_r250(rng):
   def __init__(self):
      rng.__init__(self,"r250")

class rng_ran0(rng):
   def __init__(self):
      rng.__init__(self,"ran0")

class rng_ran1(rng):
   def __init__(self):
      rng.__init__(self,"ran1")

class rng_ran2(rng):
   def __init__(self):
      rng.__init__(self,"ran2")

class rng_ran3(rng):
   def __init__(self):
      rng.__init__(self,"ran3")

class rng_rand(rng):
   def __init__(self):
      rng.__init__(self,"rand")

class rng_rand48(rng):
   def __init__(self):
      rng.__init__(self,"rand48")

class rng_random128_bsd(rng):
   def __init__(self):
      rng.__init__(self,"random128_bsd")

class rng_random128_glibc2(rng):
   def __init__(self):
      rng.__init__(self,"random128_glibc2")

class rng_random128_libc5(rng):
   def __init__(self):
      rng.__init__(self,"random128_libc5")

class rng_random256_bsd(rng):
   def __init__(self):
      rng.__init__(self,"random256_bsd")

class rng_random256_glibc2(rng):
   def __init__(self):
      rng.__init__(self,"random256_glibc2")

class rng_random256_libc5(rng):
   def __init__(self):
      rng.__init__(self,"random256_libc5")

class rng_random32_bsd(rng):
   def __init__(self):
      rng.__init__(self,"random32_bsd")

class rng_random32_glibc2(rng):
   def __init__(self):
      rng.__init__(self,"random32_glibc2")

class rng_random32_libc5(rng):
   def __init__(self):
      rng.__init__(self,"random32_libc5")

class rng_random64_bsd(rng):
   def __init__(self):
      rng.__init__(self,"random64_bsd")

class rng_random64_glibc2(rng):
   def __init__(self):
      rng.__init__(self,"random64_glibc2")

class rng_random64_libc5(rng):
   def __init__(self):
      rng.__init__(self,"random64_libc5")

class rng_random8_bsd(rng):
   def __init__(self):
      rng.__init__(self,"random8_bsd")

class rng_random8_glibc2(rng):
   def __init__(self):
      rng.__init__(self,"random8_glibc2")

class rng_random8_libc5(rng):
   def __init__(self):
      rng.__init__(self,"random8_libc5")

class rng_random_bsd(rng):
   def __init__(self):
      rng.__init__(self,"random_bsd")

class rng_random_glibc2(rng):
   def __init__(self):
      rng.__init__(self,"random_glibc2")

class rng_random_libc5(rng):
   def __init__(self):
      rng.__init__(self,"random_libc5")

class rng_randu(rng):
   def __init__(self):
      rng.__init__(self,"randu")

class rng_ranf(rng):
   def __init__(self):
      rng.__init__(self,"ranf")

class rng_ranlux(rng):
   def __init__(self):
      rng.__init__(self,"ranlux")

class rng_ranlux389(rng):
   def __init__(self):
      rng.__init__(self,"ranlux389")

class rng_ranlxd1(rng):
   def __init__(self):
      rng.__init__(self,"ranlxd1")

class rng_ranlxd2(rng):
   def __init__(self):
      rng.__init__(self,"ranlxd2")

class rng_ranlxs0(rng):
   def __init__(self):
      rng.__init__(self,"ranlxs0")

class rng_ranlxs1(rng):
   def __init__(self):
      rng.__init__(self,"ranlxs1")

class rng_ranlxs2(rng):
   def __init__(self):
      rng.__init__(self,"ranlxs2")

class rng_ranmar(rng):
   def __init__(self):
      rng.__init__(self,"ranmar")

class rng_slatec(rng):
   def __init__(self):
      rng.__init__(self,"slatec")

class rng_taus(rng):
   def __init__(self):
      rng.__init__(self,"taus")

class rng_transputer(rng):
   def __init__(self):
      rng.__init__(self,"transputer")

class rng_tt800(rng):
   def __init__(self):
      rng.__init__(self,"tt800")

class rng_uni(rng):
   def __init__(self):
      rng.__init__(self,"uni")

class rng_uni32(rng):
   def __init__(self):
      rng.__init__(self,"uni32")

class rng_vax(rng):
   def __init__(self):
      rng.__init__(self,"vax")

class rng_waterman14(rng):
   def __init__(self):
      rng.__init__(self,"waterman14")

class rng_zuf(rng):
   def __init__(self):
      rng.__init__(self,"zuf")

class rng_default(rng):
   def __init__(self):
      rng.__init__(self,"default")


## distributions
gaussian_pdf=pygsl._rng.gaussian_pdf
ugaussian_pdf=pygsl._rng.ugaussian_pdf
gaussian_tail_pdf=pygsl._rng.gaussian_tail_pdf
ugaussian_tail_pdf=pygsl._rng.ugaussian_tail_pdf
bivariate_gaussian_pdf=pygsl._rng.bivariate_gaussian_pdf
exponential_pdf=pygsl._rng.exponential_pdf
laplace_pdf=pygsl._rng.laplace_pdf
exppow_pdf=pygsl._rng.exppow_pdf
cauchy_pdf=pygsl._rng.cauchy_pdf
rayleigh_pdf=pygsl._rng.rayleigh_pdf
rayleigh_tail_pdf=pygsl._rng.rayleigh_tail_pdf
##missing
gamma_pdf=pygsl._rng.gamma_pdf
flat_pdf=pygsl._rng.flat_pdf
lognormal_pdf=pygsl._rng.lognormal_pdf
chisq_pdf=pygsl._rng.chisq_pdf
fdist_pdf=pygsl._rng.fdist_pdf
tdist_pdf=pygsl._rng.tdist_pdf
beta_pdf=pygsl._rng.beta_pdf
logistic_pdf=pygsl._rng.logistic_pdf
pareto_pdf=pygsl._rng.pareto_pdf
weibull_pdf=pygsl._rng.weibull_pdf
gumbel1_pdf=pygsl._rng.gumbel1_pdf
gumbel2_pdf=pygsl._rng.gumbel2_pdf
poisson_pdf=pygsl._rng.poisson_pdf
bernoulli_pdf=pygsl._rng.bernoulli_pdf
binomial_pdf=pygsl._rng.binomial_pdf
negative_binomial_pdf=pygsl._rng.negative_binomial_pdf
pascal_pdf=pygsl._rng.pascal_pdf
geometric_pdf=pygsl._rng.geometric_pdf
hypergeometric_pdf=pygsl._rng.hypergeometric_pdf
logarithmic_pdf=pygsl._rng.logarithmic_pdf  
landau_pdf=pygsl._rng.landau_pdf
erlang_pdf=pygsl._rng.erlang_pdf

## other useful things:

def rng_factory(name=None):
    """
    returns a new random number generator by name
    """
    return gsl_rng(name)
