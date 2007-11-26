/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
%{
#include <gsl/gsl_multimin.h>
%}

%apply gsl_fsolver * { gsl_multimin_fminimizer *, gsl_multimin_fdfminimizer *}
%apply gsl_fsolver * BUFFER {gsl_multimin_fminimizer  * BUFFER}
%apply gsl_fdfsolver * BUFFER {gsl_multimin_fdfminimizer * BUFFER}
%{
#define PyGSL_gsl_multimin_fminimizer_GET_PARAMS(sys)   \
        (sys)->f->params;
#define PyGSL_gsl_multimin_fdfminimizer_GET_PARAMS(sys)   \
        (sys)->fdf->params;
#define  PyGSL_gsl_multimin_function_GET_PARAMS(sys) \
         (sys)->params
#define  PyGSL_gsl_multimin_function_fdf_GET_PARAMS(sys) \
         (sys)->params
%}
%apply gsl_fsolver   * BUFFER {gsl_multimin_function     * BUFFER};
%apply gsl_fdfsolver * BUFFER {gsl_multimin_function_fdf * BUFFER};

/*
 * This typemap is needed to enable the _x functions to return a numeric array
 */
%{
  typedef gsl_vector gsl_multimin_solver_data;
%}
/* add functions to allocate and free the memory stored by gsl_multimin_function */
%inline %{
  gsl_multimin_function * gsl_multimin_function_init(gsl_multimin_function * STORE)
  {
    return STORE;
  }
  gsl_multimin_function_fdf * gsl_multimin_function_init_fdf(gsl_multimin_function_fdf * STORE)
  {
	 return STORE;
    /* Do Not need to do anything here. All done in the typemaps */
  }
  void gsl_multimin_function_free(gsl_multimin_function * FREE)
  {
       ;
  }

  void gsl_multimin_function_free_fdf(gsl_multimin_function_fdf * FREE)
  {
    /* Do Not need to do anything here. All done in the typemaps */
       ;
  }
%}
%{
  double  gsl_multimin_fminimizer_f(gsl_multimin_fminimizer * s)
  {	
    	return s->fval;
  }
%}
double  
gsl_multimin_fminimizer_f(gsl_multimin_fminimizer * s);

gsl_multimin_fminimizer *
gsl_multimin_fminimizer_alloc(const gsl_multimin_fminimizer_type *T,
                                size_t n);

int 
gsl_multimin_fminimizer_set (gsl_multimin_fminimizer * s,
                             gsl_multimin_function * BUFFER,
                             const gsl_vector * IN,
                             const gsl_vector * IN);

void
gsl_multimin_fminimizer_free(gsl_multimin_fminimizer *s);

const char * 
gsl_multimin_fminimizer_name (const gsl_multimin_fminimizer * s);

int
gsl_multimin_fminimizer_iterate(gsl_multimin_fminimizer *s);


gsl_multimin_solver_data *
gsl_multimin_fminimizer_x (const gsl_multimin_fminimizer * s);

double 
gsl_multimin_fminimizer_minimum (const gsl_multimin_fminimizer * s);

double
gsl_multimin_fminimizer_size (const gsl_multimin_fminimizer * s);


gsl_multimin_fdfminimizer *
gsl_multimin_fdfminimizer_alloc(const gsl_multimin_fdfminimizer_type *T,
                                size_t n);

int 
gsl_multimin_fdfminimizer_set(gsl_multimin_fdfminimizer * s,
			      gsl_multimin_function_fdf * BUFFER,
			      const gsl_vector * IN,
			      double step_size, double tol);

void
gsl_multimin_fdfminimizer_free(gsl_multimin_fdfminimizer *s);

const char * 
gsl_multimin_fdfminimizer_name (const gsl_multimin_fdfminimizer * s);

int
gsl_multimin_fdfminimizer_iterate(gsl_multimin_fdfminimizer * BUFFER);

int
gsl_multimin_fdfminimizer_restart(gsl_multimin_fdfminimizer * BUFFER);
int
gsl_multimin_test_gradient(const gsl_vector * IN,double epsabs);
int
gsl_multimin_test_size(double size, double epsabs);

%{
  double  gsl_multimin_fdfminimizer_f(gsl_multimin_fdfminimizer * s)
  {	
    	return s->f;
  }
%}
double  
gsl_multimin_fdfminimizer_f(gsl_multimin_fdfminimizer * s);
gsl_multimin_solver_data *
gsl_multimin_fdfminimizer_x(gsl_multimin_fdfminimizer * s);

gsl_multimin_solver_data *
gsl_multimin_fdfminimizer_dx(gsl_multimin_fdfminimizer * s);

gsl_multimin_solver_data *
gsl_multimin_fdfminimizer_gradient(gsl_multimin_fdfminimizer * s);

double 
gsl_multimin_fdfminimizer_minimum(gsl_multimin_fdfminimizer * s);

extern const 
gsl_multimin_fdfminimizer_type *gsl_multimin_fdfminimizer_steepest_descent;
extern const 
gsl_multimin_fdfminimizer_type *gsl_multimin_fdfminimizer_conjugate_pr;
extern const 
gsl_multimin_fdfminimizer_type *gsl_multimin_fdfminimizer_conjugate_fr;
extern const 
gsl_multimin_fdfminimizer_type *gsl_multimin_fdfminimizer_vector_bfgs;

%inline %{
	  /* 
	   * Try to find what level of GSL I am running. If less than zero, 
	   * give a NULL. The overlying wrapper must check for NULL and raise 
           * an approbriate error message.
	   */
#include <pygsl/pygsl_features.h>
#ifdef _PYGSL_GSL_HAS_FMINIMIZER_NMSIMPLEX
	  extern const
	       gsl_multimin_fminimizer_type *gsl_multimin_fminimizer_nmsimplex;
#else
	  gsl_multimin_fminimizer_type *gsl_multimin_fminimizer_nmsimplex = NULL;
#endif
%}


