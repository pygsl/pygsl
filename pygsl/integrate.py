#!/usr/bin/env python
# Author : Pierre Schnizer
"""
This   modules   defines  routines   for   performing  numerical   integration
(quadrature) of a function in  one dimension.  There are routines for adaptive
and non-adaptive  integration of general functions,  with specialised routines
for specific cases.  These include integration over infinite and semi-infinite
ranges, singular  integrals, including logarithmic  singularities, computation
of   Cauchy  principal   values  and   oscillatory  integrals.    The  library
reimplements the algorithms used  in QUADPACK, a numerical integration package
written by Piessens, Doncker-Kapenga, Uberhuber and Kahaner.  Fortran code for
QUADPACK is available on Netlib.
"""
import _callback


from  gsl_function import gsl_function
from _generic_solver import _workspace

GAUSS15 = _callback.GSL_INTEG_GAUSS15        # 15 point Gauss-Kronrod rule
GAUSS21 = _callback.GSL_INTEG_GAUSS21        # 21 point Gauss-Kronrod rule
GAUSS31 = _callback.GSL_INTEG_GAUSS31        # 31 point Gauss-Kronrod rule
GAUSS41 = _callback.GSL_INTEG_GAUSS41        # 41 point Gauss-Kronrod rule
GAUSS51 = _callback.GSL_INTEG_GAUSS51        # 51 point Gauss-Kronrod rule
GAUSS61 = _callback.GSL_INTEG_GAUSS61        # 61 point Gauss-Kronrod rule
SINE    = _callback.GSL_INTEG_SINE
COSINE  = _callback.GSL_INTEG_COSINE

class workspace(_workspace):
    """
    This class provides a workspace sufficient to hold N double
    precision intervals, their integration results and error estimates.

    input : size
        size ... size of the workspace
    """
    _alloc   = _callback.gsl_integration_workspace_alloc
    _free    = _callback.gsl_integration_workspace_free
    _size    = _callback.gsl_integration_workspace_get_size
    
    def get_size(self):
        """
        Get the size of the workspace
        """
        return self._size(self._ptr)

class qaws_table(_workspace):
    """
    This class allocates space for a `gsl_integration_qaws_table'
    struct and associated workspace describing a singular weight
    function W(x) with the parameters (\alpha, \beta, \mu, \nu),

          W(x) = (x-a)^alpha (b-x)^beta log^mu (x-a) log^nu (b-x)
          
    where \alpha < -1, \beta < -1, and \mu = 0, 1, \nu = 0, 1.  The
    weight function can take four different forms depending on the
     values of \mu and \nu,

          W(x) = (x-a)^alpha (b-x)^beta                   (mu = 0, nu = 0)
          W(x) = (x-a)^alpha (b-x)^beta log(x-a)          (mu = 1, nu = 0)
          W(x) = (x-a)^alpha (b-x)^beta log(b-x)          (mu = 0, nu = 1)
          W(x) = (x-a)^alpha (b-x)^beta log(x-a) log(b-x) (mu = 1, nu = 1)

     The singular points (a,b) do not have to be specified until the
     integral is computed, where they are the endpoints of the
     integration range.

     The function returns a pointer to the newly allocated
     `gsl_integration_qaws_table' if no errors were detected, and 0 in
     the case of error.

    """
    _alloc   = _callback.gsl_integration_qaws_table_alloc  
    _free    = _callback.gsl_integration_qaws_table_free   
    _set     = _callback.gsl_integration_qaws_table_set
 
    def __init__(self, alpha, beta, mu, nu):
        self._ptr = None
        assert(self._alloc != None)
        assert(self._free != None)
        self._ptr = self._alloc(alpha, beta, mu, nu)

    def set(self, alpha, beta, mu, nu):
        """
         This function modifies the parameters (\alpha, \beta, \mu, \nu)

         input : alpha, beta, mu, nu
        """
        self._set(self._ptr, alpha, beta, mu, nu)


class qawo_table(_workspace):
    """
        This class manages space for a `qawo_table'
      and its associated workspace describing a sine or cosine
     weight function W(x) with the parameters (\omega, L),

          W(x) = sin(omega x)
          W(x) = cos(omega x)

     The parameter L must be the length of the interval over which the
     function will be integrated L = b - a.  The choice of sine or
     cosine is made with the parameter SINE which should be chosen from
     one of the two following symbolic values:

         COSINE
         SINE

     The `gsl_integration_qawo_table' is a table of the trigonometric
     coefficients required in the integration process.  The parameter N
     determines the number of levels of coefficients that are computed.
     Each level corresponds to one bisection of the interval L, so that
     N levels are sufficient for subintervals down to the length L/2^n.
     The integration routine `gsl_integration_qawo' returns the error
     `GSL_ETABLE' if the number of levels is insufficient for the
     requested accuracy.

     input : omega, L, sine, n
    """
    _alloc      = _callback.gsl_integration_qawo_table_alloc  
    _free       = _callback.gsl_integration_qawo_table_free   
    _set        = _callback.gsl_integration_qawo_table_set
    _set_length = _callback.gsl_integration_qawo_table_set

    def __init__(self, omega, L, sine, n):
        self._ptr = None
        assert(self._alloc != None)
        assert(self._free != None)
        self._ptr = self._alloc(omega, L, sine, n)

    def set(self, omega, L, sine, n):
        """
        Change the parameters OMEGA, L and SINE
        """
        self._set(self._ptr, omega, L, sine, n)

    def set_length(self, L):
        """
        Change the length parameter L
        """
        self._set_length(self._ptr, L)

def qng(f, a, b, epsabs, epsrel):
    """
    This function applies the Gauss-Kronrod 10-point, 21-point,
    43-point and 87-point integration rules in succession until an
    estimate of the integral of f over (a,b) is achieved within the
    desired absolute and relative error limits, EPSABS and EPSREL.  The
    function returns the final approximation, RESULT, an estimate of
    the absolute error, ABSERR and the number of function evaluations
    used, NEVAL.  The Gauss-Kronrod rules are designed in such a way
    that each rule uses all the results of its predecessors, in order
    to minimize the total number of function evaluations.
    
    input : f, a, b, epsabs, epsrel
            f ... gsl_function
    """
    
    return _callback.gsl_integration_qng(f.get_ptr(), a, b, epsabs, epsrel)

def qag(f, a, b, epsabs, epsrel, limit, key, workspace):
    """
    The QAG algorithm is a simple adaptive integration procedure.  The
    integration region is divided into subintervals, and on each iteration
    the subinterval with the largest estimated error is bisected.  This
    reduces the overall error rapidly, as the subintervals become
    concentrated around local difficulties in the integrand.  These
    subintervals are managed by a `gsl_integration_workspace' struct, which
    handles the memory for the subinterval ranges, results and error
    estimates.

     This function applies an integration rule adaptively until an
     estimate of the integral of f over (a,b) is achieved within the
     desired absolute and relative error limits, EPSABS and EPSREL.
     The function returns the final approximation, RESULT, and an
     estimate of the absolute error, ABSERR.  The integration rule is
     determined by the value of KEY, which should be chosen from the
     following symbolic names,

          GAUSS15  
          GAUSS21  
          GAUSS31  
          GAUSS41  
          GAUSS51  
          GAUSS61  

     corresponding to the 15, 21, 31, 41, 51 and 61 point Gauss-Kronrod
     rules.  The higher-order rules give better accuracy for smooth
     functions, while lower-order rules save time when the function
     contains local difficulties, such as discontinuities.

     On each iteration the adaptive integration strategy bisects the
     with the largest error estimate.  The subintervals and
     their results are stored in the memory provided by WORKSPACE.  The
     maximum number of subintervals is given by LIMIT, which may not
     exceed the allocated size of the workspace.

     input : f, a, b, epsabs, epsrel, limit, key, workspace
         f ... gsl_function
    """
    return _callback.gsl_integration_qag(f.get_ptr(), a, b, epsabs, epsrel, limit,
                                           key, workspace._ptr)

def qags(f, a, b, epsabs, epsrel, limit, workspace):
    """
    This function applies the Gauss-Kronrod 21-point integration rule
     adaptively until an estimate of the integral of f over (a,b) is
     achieved within the desired absolute and relative error limits,
     EPSABS and EPSREL.  The results are extrapolated using the
     epsilon-algorithm, which accelerates the convergence of the
     integral in the presence of discontinuities and integrable
     singularities.  The function returns the final approximation from
     the extrapolation, RESULT, and an estimate of the absolute error,
     ABSERR.  The subintervals and their results are stored in the
     memory provided by WORKSPACE.  The maximum number of subintervals
     is given by LIMIT, which may not exceed the allocated size of the
     workspace.

     input : f.get_ptr(), a, b, epsabs, epsrel, limit, key, workspace
         f ... gsl_function
         
    """
    return _callback.gsl_integration_qags(f._ptr, a, b, epsabs, epsrel,
                                            limit,       workspace._ptr)

def qagp(f, pts, epsabs, epsrel, limit, workspace):
    """
     This function applies the adaptive integration algorithm QAGS
     taking account of the user-supplied locations of singular points.
     The array PTS of length NPTS should contain the endpoints of the
     integration ranges defined by the integration region and locations
     of the singularities.  For example, to integrate over the region
     (a,b) with break-points at x_1, x_2, x_3 (where a < x_1 < x_2 <
     x_3 < b) the following PTS array should be used

          pts[0] = a
          pts[1] = x_1
          pts[2] = x_2
          pts[3] = x_3
          pts[4] = b

     with NPTS = 5.

     If you know the locations of the singular points in the integration
     region then this routine will be faster than `QAGS'.
     
     input : f, pts, epsabs, epsrel, limit,  workspace
         f ... gsl_function

    """
    return _callback.gsl_integration_qagp(f.get_ptr(), pts, epsabs, epsrel, limit,
                                          workspace._ptr)

def qagi(f, epsabs, epsrel, limit, workspace):
    """
    This function computes the integral of the function F over the
     infinite interval (-\infty,+\infty).  The integral is mapped onto
     the interval (0,1] using the transformation x = (1-t)/t,

          \int_{-\infty}^{+\infty} dx f(x) =
               \int_0^1 dt (f((1-t)/t) + f((-1+t)/t))/t^2.

     It is then integrated using the QAGS algorithm.  The normal
     21-point Gauss-Kronrod rule of QAGS is replaced by a 15-point
     rule, because the transformation can generate an integrable
     singularity at the origin.  In this case a lower-order rule is
     more efficient.

     input : f, epsabs, epsrel, limit,  workspace
         f ... gsl_function

    """
    return _callback.gsl_integration_qagi(f.get_ptr(), epsabs, epsrel, limit,
                                            workspace._ptr)

def qagiu(f, a, epsabs, epsrel, limit, workspace):
    """
     This function computes the integral of the function F over the
     semi-infinite interval (a,+\infty).  The integral is mapped onto
     the interval (0,1] using the transformation x = a + (1-t)/t,

          \int_{a}^{+\infty} dx f(x) =
               \int_0^1 dt f(a + (1-t)/t)/t^2

     and then integrated using the QAGS algorithm.

     input : f, a, epsabs, epsrel, limit,  workspace
         f ... gsl_function

    """
    return _callback.gsl_integration_qagiu(f.get_ptr(), a, epsabs, epsrel, limit,
                                            workspace._ptr)

def qagil(f, b, epsabs, epsrel, limit, workspace):
    """
    his function computes the integral of the function F over the
     semi-infinite interval (-\infty,b).  The integral is mapped onto
     the region (0,1] using the transformation x = b - (1-t)/t,

          \int_{+\infty}^{b} dx f(x) =
               \int_0^1 dt f(b - (1-t)/t)/t^2

     and then integrated using the QAGS algorithm.

     input : f, b, epsabs, epsrel, limit,  workspace
         f ... gsl_function

    """
    return _callback.gsl_integration_qagil(f.get_ptr(), b, epsabs, epsrel, limit,
                                            workspace._ptr)

def qawc(f, a, b, c, epsabs, epsrel, limit, workspace):
    """
     This function computes the Cauchy principal value of the integral
     of f over (a,b), with a singularity at C,

          I = \int_a^b dx f(x) / (x - c)

     The adaptive bisection algorithm of QAG is used, with
     modifications to ensure that subdivisions do not occur at the
     singular point x = c.  When a subinterval contains the point x = c
     or is close to it then a special 25-point modified Clenshaw-Curtis
     rule is used to control the singularity.  Further away from the
     singularity the algorithm uses an ordinary 15-point Gauss-Kronrod
     integration rule.

     input : f, a, b, c, epsabs, epsrel, limit,  workspace
         f ... gsl_function
     
    """
    return _callback.gsl_integration_qawc(f.get_ptr(), a, b, c, epsabs, epsrel, limit,
                                            workspace._ptr)

def qaws(f, a, b, qwas_table, epsabs, epsrel, limit, workspace):
    """
    This function computes the integral of the function f(x) over the
     interval (a,b) with the singular weight function (x-a)^\alpha
     (b-x)^\beta \log^\mu (x-a) \log^\nu (b-x).  The parameters of the
     weight function (\alpha, \beta, \mu, \nu) are taken from the table
     T.  The integral is,

          I = \int_a^b dx f(x) (x-a)^alpha (b-x)^beta log^mu (x-a) log^nu (b-x).

     The adaptive bisection algorithm of QAG is used.  When a
     subinterval contains one of the endpoints then a special 25-point
     modified Clenshaw-Curtis rule is used to control the
     singularities.  For subintervals which do not include the
     endpoints an ordinary 15-point Gauss-Kronrod integration rule is
     used.

     input : f, a, b, qwas_table, epsabs, epsrel, limit,  workspace
         f ... gsl_function

    """
    return _callback.gsl_integration_qaws(f.get_ptr(), a, b, qwas_table._ptr, epsabs,
                                            epsrel, limit, workspace._ptr)


def qawo(f, a, epsabs, epsrel, limit, workspace, qwao_table):
    """
    This function uses an adaptive algorithm to compute the integral of
     f over (a,b) with the weight function \sin(\omega x) or
     \cos(\omega x) defined by the table WF.

          I = \int_a^b dx f(x) sin(omega x)
          I = \int_a^b dx f(x) cos(omega x)

     The results are extrapolated using the epsilon-algorithm to
     accelerate the convergence of the integral.  The function returns
     the final approximation from the extrapolation, RESULT, and an
     estimate of the absolute error, ABSERR.  The subintervals and
     their results are stored in the memory provided by WORKSPACE.  The
     maximum number of subintervals is given by LIMIT, which may not
     exceed the allocated size of the workspace.

     Those subintervals with "large" widths d, d\omega > 4 are computed
     using a 25-point Clenshaw-Curtis integration rule, which handles
     the oscillatory behavior.  Subintervals with a "small" width
     d\omega < 4 are computed using a 15-point Gauss-Kronrod
     integration.

     input : f, a, b, qwas_table, epsabs, epsrel, limit,  workspace
              qwao_table
         f ... gsl_function
     
    """
    return _callback.gsl_integration_qawo(f.get_ptr(), a, epsabs, epsrel, limit,
                                          workspace._ptr, qwao_table._ptr)

def qawf(f, a, epsabs, limit, workspace, cycleworkspace, qwao_table):
    """
        This function attempts to compute a Fourier integral of the
     function F over the semi-infinite interval [a,+\infty).

          I = \int_a^{+\infty} dx f(x) sin(omega x)
          I = \int_a^{+\infty} dx f(x) cos(omega x)

     The parameter \omega is taken from the table WF (the length L can
     take any value, since it is overridden by this function to a value
     appropriate for the fourier integration).  The integral is computed
     using the QAWO algorithm over each of the subintervals,

          C_1 = [a, a + c]
          C_2 = [a + c, a + 2 c]
          ... = ...
          C_k = [a + (k-1) c, a + k c]

     where c = (2 floor(|\omega|) + 1) \pi/|\omega|.  The width c is
     chosen to cover an odd number of periods so that the contributions
     from the intervals alternate in sign and are monotonically
     decreasing when F is positive and monotonically decreasing.  The
     sum of this sequence of contributions is accelerated using the
     epsilon-algorithm.

     This function works to an overall absolute tolerance of ABSERR.
     The following strategy is used: on each interval C_k the algorithm
     tries to achieve the tolerance

          TOL_k = u_k abserr

     where u_k = (1 - p)p^{k-1} and p = 9/10.  The sum of the geometric
     series of contributions from each interval gives an overall
     tolerance of ABSERR.

     If the integration of a subinterval leads to difficulties then the
     accuracy requirement for subsequent intervals is relaxed,

          TOL_k = u_k max(abserr, max_{i<k}{E_i})

     where E_k is the estimated error on the interval C_k.

     The subintervals and their results are stored in the memory
     provided by WORKSPACE.  The maximum number of subintervals is
     given by LIMIT, which may not exceed the allocated size of the
     workspace.  The integration over each subinterval uses the memory
     provided by CYCLE_WORKSPACE as workspace for the QAWO algorithm.

     
     input : f, a, b, qwas_table, epsabs, epsrel, limit,  workspace
              qwao_table
         f ... gsl_function

    """
    return _callback.gsl_integration_qawf(f.get_ptr(), a, epsabs, limit,
                                          workspace._ptr, cycleworkspace._ptr, qwao_table._ptr)
