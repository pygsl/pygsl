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


/* Evaluate a Chebyshev series at a given point, using the default
 * order for double precision mode(s) and the single precision
 * order for other modes.
 * No errors can occur for a struct obtained from gsl_cheb_new().
 */
/*
double gsl_cheb_eval_mode(const gsl_cheb_series * cs, double x, gsl_mode_t mode);
int gsl_cheb_eval_mode_e(const gsl_cheb_series * cs, const double x, 
			 gsl_mode_t mode, double * result, double * abserr);
*/
/* Compute the derivative of a Chebyshev series.
 */
int gsl_cheb_calc_deriv(gsl_cheb_series * deriv, const gsl_cheb_series * cs);

/* Compute the integral of a Chebyshev series. The
 * integral is fixed by the condition that it equals zero at
 * the left end-point, ie it is precisely
 *       Integrate[cs(t; a,b), {t, a, x}]
 */
int gsl_cheb_calc_integ(gsl_cheb_series * integ, const gsl_cheb_series * cs);





