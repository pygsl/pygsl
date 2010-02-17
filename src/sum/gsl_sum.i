/* -*- C -*- */
%define DOCSTRING
"""This module provides a function for accelerating the convergence of
series based on the Levin u-transform.  This method takes a small
number of terms from the start of a series and uses a systematic
approximation to compute an extrapolated value and an estimate of its
error. The u-transform works for both convergent and divergent
series, including asymptotic series."""
%enddef
%module(docstring=DOCSTRING) sum;
%{
#include <gsl/gsl_sum.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
%}

%init {
  init_pygsl();
}
typedef unsigned int size_t;

%include typemaps.i
%include gsl_error_typemap.i
%include gsl_block_special_typemaps.i

%typemap(out) int = gsl_error_flag_drop;

%rename(_levin) gsl_sum_levin_u_workspace;
%rename(_levin_utrunc) gsl_sum_levin_utrunc_workspace;

%pythoncode %{
def levin_sum(a, truncate=False, info_dict=None):
    """Return (sum(a), err) where sum(a) is the extrapolated
    sum of the infinite series a and err is an error estimate.

    Uses the Levin u-transform method.

    Parameters:
      a : A list or array of floating point numbers assumed
          to be the first terms in a series.
      truncate: If True, then use a more efficient algorithm, but with
          a less accurate error estimate
      info_dict: If info_dict is provided, then two entries will
          be added: 'terms_used' will be the number of terms
          used and 'sum_plain' will be the sum of these terms
          without acceleration.

    Notes: The error estimate is made assuming that the terms a are
    computed to machined precision.

    Example: Computing the zeta function 
    zeta(2) = 1/1**2 + 1/2**2 + 1/3**2 + ... = pi**2/6

    >>> from math import pi
    >>> zeta_2 = pi**2/6
    >>> a = [1.0/n**2 for n in range(1,21)]
    >>> info_dict = {}
    >>> (ans, err_est) = levin_sum(a, info_dict=info_dict)
    >>> ans, zeta_2             # doctest: +ELLIPSIS
    1.644934066..., 1.644934066...
    >>> err = abs(ans - zeta_2)
    >>> err < err_est
    True
    >>> (ans, err_est) = levin_sum(a, truncate=False)
    >>> ans             # doctest: +ELLIPSIS
    1.644934066...
    """
    if truncate:
        l = _levin_utrunc(len(a))
    else:
        l = _levin(len(a))

    ans = l.accel(a)
    if info_dict is not None:
        info_dict['sum_plain'] = l.sum_plain()
        info_dict['terms_used'] = l.get_terms_used()
    del l
    return ans
%}

typedef struct {
  /*	
  size_t size;
  size_t i;                    
  size_t terms_used;           
  double sum_plain;
  double *q_num;
  double *q_den;
  double *dq_num;
  double *dq_den;
  double *dsum;
  */
} gsl_sum_levin_u_workspace;


%apply (double * OUTPUT){double * sum_accel,
			 double * abserr};
%apply (const double *, size_t ){(const double *array, const size_t n)};

%extend gsl_sum_levin_u_workspace{

  gsl_sum_levin_u_workspace(const size_t n) {
    return gsl_sum_levin_u_alloc(n);
  }
  ~gsl_sum_levin_u_workspace() {
     gsl_sum_levin_u_free(self);
  }
  %apply (double * OUTPUT){double * sum_accel, double * abserr};
  %apply (const double *, size_t ){(const double *array, const size_t n)};
  int accel(const double *array, const size_t n, double *sum_accel, double *abserr){
       return gsl_sum_levin_u_accel(array, n, self, sum_accel, abserr);
  }
  size_t get_terms_used(){
       return self->terms_used;
  }
  double sum_plain(){
       return self->sum_plain;
  }
  
  int minmax(const double *array, const size_t n, const size_t min_terms,
	      const size_t max_terms, double *sum_accel, double *abserr){
       return gsl_sum_levin_u_minmax(array, n, min_terms, max_terms, self, sum_accel, abserr);
  }
  /*
  int step(const double term, const size_t n, const size_t nmax, double *sum_accel){
       return gsl_sum_levin_u_step(term, n, nmax, self,  sum_accel);
  }
  */
};


typedef struct {
	/*
  size_t size;
  size_t i;                    
  size_t terms_used;           
  double sum_plain;
  double *q_num;
  double *q_den;
  double *dsum;
  */
} gsl_sum_levin_utrunc_workspace;
%extend gsl_sum_levin_utrunc_workspace{
  gsl_sum_levin_utrunc_workspace(const size_t n) {
    return gsl_sum_levin_utrunc_alloc(n);
  }
  ~gsl_sum_levin_utrunc_workspace() {
     gsl_sum_levin_utrunc_free(self);
  }
  int accel(const double *array, const size_t n, double *sum_accel, double *abserr){
       return gsl_sum_levin_utrunc_accel(array, n, self, sum_accel, abserr);
  }
  size_t get_terms_used(){
       return self->terms_used;
  }
  double sum_plain(){
       return self->sum_plain;
  }
  int minmax(const double *array, const size_t n, const size_t min_terms,
	      const size_t max_terms, double *sum_accel, double *abserr){
       return gsl_sum_levin_utrunc_minmax(array, n, min_terms, max_terms, self, sum_accel, abserr);
  }
  /*
  int step(const double term, const size_t n, const size_t nmax, double *sum_accel){
       return gsl_sum_levin_utrunc_step(term, n, nmax, self, sum_accel);
  }
  */
};
