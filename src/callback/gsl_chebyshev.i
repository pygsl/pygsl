/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
%{
#include <gsl/gsl_chebyshev.h>
%}

%include typemaps.i
%include gsl_function_typemaps.i
%include gsl_error_typemap.i

%apply double *OUTPUT {double *result}
%apply double *OUTPUT {double *abserr}

typedef unsigned int gsl_mode_t;
/* typedef unsigned int size_t; */

gsl_cheb_series * gsl_cheb_alloc(const size_t order);

/* Free a Chebyshev series previously calculated with gsl_cheb_alloc().
 */
void gsl_cheb_free(gsl_cheb_series * cs);

/* Calculate a Chebyshev series using the storage provided.
 * Uses the interval (a,b) and the order with which it
 * was initially created.
 *
 */
int gsl_cheb_init(gsl_cheb_series * cs, const gsl_function * BUFFER,
                  const double a, const double b);

double gsl_cheb_eval(const gsl_cheb_series * cs, const double x);
int gsl_cheb_eval_err(const gsl_cheb_series * cs, const double x, 
                      double * result, double * abserr);

/* Evaluate a Chebyshev series at a given point, to (at most) the given order.
 * No errors can occur for a struct obtained from gsl_cheb_new().
 */
double gsl_cheb_eval_n(const gsl_cheb_series * cs, const size_t order, 
                       const double x);
int gsl_cheb_eval_n_err(const gsl_cheb_series * cs, const size_t order, 
                        const double x, double * result, double * abserr);


/* 
 *Evaluate a Chebyshev series at a given point, using the default
 * order for double precision mode(s) and the single precision
 * order for other modes.
 * No errors can occur for a struct obtained from gsl_cheb_new().
 */
/* These to functions are not mentioned in the reference document. Therefore 
   they are not exposed
double gsl_cheb_eval_mode(const gsl_cheb_series * cs, double x, 
			  gsl_mode_t mode);
int gsl_cheb_eval_mode_e(const gsl_cheb_series * cs, const double x, 
			 gsl_mode_t mode, double * result, double * abserr);
*/
/*
 * Compute the derivative of a Chebyshev series.
 */
int gsl_cheb_calc_deriv(gsl_cheb_series * deriv, const gsl_cheb_series * cs);

/* Compute the integral of a Chebyshev series. The
 * integral is fixed by the condition that it equals zero at
 * the left end-point, ie it is precisely
 *       Integrate[cs(t; a,b), {t, a, x}]
 */
int gsl_cheb_calc_integ(gsl_cheb_series * integ, const gsl_cheb_series * cs);

/*
 * Get the coefficients of the chebyshev series; Suggestion from Achim. I 
 * declare it as as a gsl_vector first. So I can reuse the utility function.
 * PyObjects will be passed back directly.
 */
%inline %{ 
     PyObject *
     pygsl_cheb_get_coefficients(gsl_cheb_series * s){
	  gsl_vector_view v;
	  v = gsl_vector_view_array(s->c, s->order);
	  return (PyObject *) PyGSL_copy_gslvector_to_pyarray(&v.vector);
    }
%}

%{
     int
     pygsl_cheb_set_coefficients(gsl_cheb_series * s, gsl_vector *coef){
	  size_t i, v_size;
	  v_size = coef->size;
	  if(v_size != s->order){
	       PyGSL_ERROR("The number of coefficients does not match the specified order.", GSL_EBADLEN);
	       return GSL_EBADLEN;
	  }
	  for (i=0; i<v_size; i++){
	       s->c[i] = gsl_vector_get(coef, i);
          }
	  return GSL_SUCCESS;
     }

%}
int 
pygsl_cheb_set_coefficients(gsl_cheb_series * s, gsl_vector * IN);
/*
 * Get the border values a and b.
 */
%inline %{ 
     double
	  pygsl_cheb_get_a(gsl_cheb_series *s){
	  return s->a;
     }
     double
	  pygsl_cheb_get_b(gsl_cheb_series *s){
	  return s->b;
     }
     void
	  pygsl_cheb_set_a(gsl_cheb_series *s, double a){
	  s->a = a;
     }
     void
	  pygsl_cheb_set_b(gsl_cheb_series *s, double b){
	  s->b = b;
     }
     size_t
	  pygsl_cheb_get_order_sp(gsl_cheb_series *s){
	  return s->order_sp;
     }
     void
	  pygsl_cheb_set_order_sp(gsl_cheb_series *s, size_t sp){
	  s->order_sp = sp;
     }
     double
	  pygsl_cheb_get_f(gsl_cheb_series *s){
	  return *(s->f);
     }
     
     void
	  pygsl_cheb_set_f(gsl_cheb_series *s, double f){
	  *(s->f) = f;
     }
     

%}
