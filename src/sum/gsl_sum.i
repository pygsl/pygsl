/* -*- C -*- */
%module sum;
%{
#include <gsl/gsl_sum.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
%}

%init {
  import_array();
  init_pygsl();
}
typedef unsigned int size_t;

%include typemaps.i
%include gsl_error_typemap.i
%include gsl_block_special_typemaps.i

%typemap(out) int = gsl_error_flag;

%rename(levin) gsl_sum_levin_u_workspace;
%rename(levin_utrunc) gsl_sum_levin_utrunc_workspace;

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
  int accel(const double *array, const size_t n, double *sum_accel, double *abserr){
       return gsl_sum_levin_u_accel(array, n, self, sum_accel, abserr);
  }
  size_t get_terms_used(){
       return self->terms_used;
  }
  double sum_plain(){
       return self->sum_plain;
  }
  /*
  int minmax(const double *array, const size_t n, const size_t min_terms,
	      const size_t max_terms, double *sum_accel, double *abserr){
       return gsl_sum_levin_u_minmax(array, n, min_terms, max_terms, self, sum_accel, abserr);
  }
  int step(const double term, const size_t n, const size_t nmax, double *sum_accel){
       return gsl_sum_levin_u_step(term, n, nmaxn sum_accel);
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
  /*
  int minmax(const double *array, const size_t n, const size_t min_terms,
	      const size_t max_terms, double *sum_accel, double *abserr){
       return gsl_sum_levin_utrunc_minmax(array, n, min_terms, max_terms, self, sum_accel, abserr);
  }
  int step(const double term, const size_t n, const size_t nmax, double *sum_accel){
       return gsl_sum_levin_utrunc_step(term, n, nmaxn sum_accel);
  }
  */
};
