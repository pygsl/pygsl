/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */

%{
#include <gsl/gsl_multiroots.h>
%}

/* add functions to allocate and free the memory stored by gsl_function */
%inline %{
  gsl_multiroot_function * gsl_multiroot_function_init(gsl_multiroot_function * STORE)
  {
    return STORE;
    /* Do Not need to do anything here. All done in the typemaps */
  }
  gsl_multiroot_function_fdf * gsl_multiroot_function_init_fdf(gsl_multiroot_function_fdf * STORE)
  {
    return STORE;
    /* Do Not need to do anything here. All done in the typemaps */
  }
  typedef gsl_vector gsl_multiroot_solver_data;
  gsl_multiroot_solver_data * gsl_multiroot_function_getf(gsl_multiroot_fsolver * s)
  {
    return s->f;
  }
  gsl_multiroot_solver_data * gsl_multiroot_function_fdf_getf(gsl_multiroot_fdfsolver * s)
  {
    return s->f;
  }
  gsl_multiroot_solver_data * gsl_multiroot_function_getx(gsl_multiroot_fsolver * s)
  {
    return s->x;
  }
  gsl_multiroot_solver_data * gsl_multiroot_function_fdf_getx(gsl_multiroot_fdfsolver * s)
  {
    return s->x;
  }
  
  void gsl_multiroot_function_free(gsl_multiroot_function * FREE)
  {
    /* Do Not need to do anything here. All done in the typemaps */
  }
  void gsl_multiroot_function_free_fdf(gsl_multiroot_function_fdf * FREE)
  {
    /* Do Not need to do anything here. All done in the typemaps */
  }

%}


gsl_multiroot_fsolver * 
gsl_multiroot_fsolver_alloc (const gsl_multiroot_fsolver_type * T, 
			     size_t n); 

void gsl_multiroot_fsolver_free (gsl_multiroot_fsolver * s);

int gsl_multiroot_fsolver_set (gsl_multiroot_fsolver * s, 
                               gsl_multiroot_function * f, gsl_vector * IN);

int gsl_multiroot_fsolver_iterate (gsl_multiroot_fsolver * s);

const char * gsl_multiroot_fsolver_name (const gsl_multiroot_fsolver * s);
gsl_vector * gsl_multiroot_fsolver_root (const gsl_multiroot_fsolver * s);

/* Definition of vector-valued functions and gradient with parameters
   based on gsl_vector */
gsl_multiroot_fdfsolver *
gsl_multiroot_fdfsolver_alloc (const gsl_multiroot_fdfsolver_type * T,
			       size_t n);

int
gsl_multiroot_fdfsolver_set (gsl_multiroot_fdfsolver * s, 
                             gsl_multiroot_function_fdf * fdf,
                             gsl_vector * IN);

int
gsl_multiroot_fdfsolver_iterate (gsl_multiroot_fdfsolver * s);

void
gsl_multiroot_fdfsolver_free (gsl_multiroot_fdfsolver * s);

const char * gsl_multiroot_fdfsolver_name (const gsl_multiroot_fdfsolver * s);
gsl_vector * gsl_multiroot_fdfsolver_root (const gsl_multiroot_fdfsolver * s);

int gsl_multiroot_test_delta (const gsl_vector * IN, const gsl_vector * IN, 
                              double epsabs, double epsrel);

int gsl_multiroot_test_residual (const gsl_vector * IN, double epsabs);

extern const gsl_multiroot_fsolver_type * gsl_multiroot_fsolver_dnewton;
extern const gsl_multiroot_fsolver_type * gsl_multiroot_fsolver_broyden;
extern const gsl_multiroot_fsolver_type * gsl_multiroot_fsolver_hybrid;
extern const gsl_multiroot_fsolver_type * gsl_multiroot_fsolver_hybrids;

extern const gsl_multiroot_fdfsolver_type * gsl_multiroot_fdfsolver_newton;
extern const gsl_multiroot_fdfsolver_type * gsl_multiroot_fdfsolver_gnewton;
extern const gsl_multiroot_fdfsolver_type * gsl_multiroot_fdfsolver_hybridj;
extern const gsl_multiroot_fdfsolver_type * gsl_multiroot_fdfsolver_hybridsj;



