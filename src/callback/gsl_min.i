/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
/*---------------------------------------------------------------------------
                           Minimizer
  ---------------------------------------------------------------------------*/
%{
#include <gsl/gsl_min.h>
%}

%apply gsl_fsolver *        { gsl_min_fminimizer  *}
%apply gsl_fsolver * BUFFER { gsl_min_fminimizer  * BUFFER}
%{
#define PyGSL_gsl_min_fminimizer_GET_PARAMS(sys)   \
        (sys)->function->params
%}



extern const gsl_min_fminimizer_type * gsl_min_fminimizer_goldensection;
extern const gsl_min_fminimizer_type * gsl_min_fminimizer_brent;

extern gsl_min_fminimizer * gsl_min_fminimizer_alloc (const gsl_min_fminimizer_type * T);
extern int gsl_min_fminimizer_set (gsl_min_fminimizer * s, gsl_function * BUFFER, double X_MINIMUM, double X_LOWER, double X_UPPER);
extern int 
gsl_min_fminimizer_set_with_values (gsl_min_fminimizer * s, gsl_function * BUFFER, 
				    double X_MINIMUM, double F_MINIMUM, 
				    double X_LOWER, double F_LOWER, 
				    double X_UPPER, double F_UPPER);
extern void gsl_min_fminimizer_free (gsl_min_fminimizer * S);
extern const char * gsl_min_fminimizer_name (const gsl_min_fminimizer * S);

extern int gsl_min_fminimizer_iterate (gsl_min_fminimizer * BUFFER);
extern double gsl_min_fminimizer_minimum (const gsl_min_fminimizer * S);
extern double gsl_min_fminimizer_x_upper (const gsl_min_fminimizer * S);
extern double gsl_min_fminimizer_x_lower (const gsl_min_fminimizer * S);

extern int gsl_min_test_interval (double X_LOWER, double X_UPPER, double EPSABS,
 double EPSREL);
