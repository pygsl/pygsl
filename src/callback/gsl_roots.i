/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 */   

%{
#include <gsl/gsl_types.h>
#include <gsl/gsl_roots.h>
%}
%include typemaps.i
%include gsl_function_typemaps.i
%include gsl_error_typemap.i

/*
 * Functions need the jmp buffer
 */
%{
#define PyGSL_gsl_root_fsolver_GET_PARAMS(sys)   \
        (sys)->function->params

#define PyGSL_gsl_root_fdfsolver_GET_PARAMS(sys)   \
        (sys)->fdf->params
%}
%apply gsl_fsolver * { gsl_root_fsolver *, gsl_root_fdfsolver *};
%apply gsl_fsolver   * BUFFER { gsl_root_fsolver   * BUFFER};
%apply gsl_fdfsolver * BUFFER { gsl_root_fdfsolver * BUFFER};


extern const gsl_root_fsolver_type   * gsl_root_fsolver_bisection;
extern const gsl_root_fsolver_type   * gsl_root_fsolver_brent;
extern const gsl_root_fsolver_type   * gsl_root_fsolver_falsepos;
extern const gsl_root_fdfsolver_type * gsl_root_fdfsolver_newton;
extern const gsl_root_fdfsolver_type * gsl_root_fdfsolver_secant;
extern const gsl_root_fdfsolver_type * gsl_root_fdfsolver_steffenson;

extern gsl_root_fsolver * gsl_root_fsolver_alloc (const gsl_root_fsolver_type * T);
extern void gsl_root_fsolver_free (gsl_root_fsolver * s);


extern gsl_root_fdfsolver * gsl_root_fdfsolver_alloc (const gsl_root_fdfsolver_type * T);
extern void gsl_root_fdfsolver_free (gsl_root_fdfsolver * s);
extern int gsl_root_fsolver_set (gsl_root_fsolver * s, gsl_function * BUFFER, double X_LOWER, double X_UPPER);
extern int gsl_root_fdfsolver_set (gsl_root_fdfsolver * s, gsl_function_fdf * BUFFER, double ROOT);


extern const char * gsl_root_fsolver_name (const gsl_root_fsolver * S);
extern const char * gsl_root_fdfsolver_name (const gsl_root_fdfsolver * S);


extern int gsl_root_fsolver_iterate (gsl_root_fsolver * BUFFER);
extern int gsl_root_fdfsolver_iterate (gsl_root_fdfsolver * BUFFER);
extern double gsl_root_fsolver_root (const gsl_root_fsolver * S);
extern double gsl_root_fdfsolver_root (const gsl_root_fdfsolver * S);
extern double gsl_root_fsolver_x_lower (const gsl_root_fsolver * S);
extern double gsl_root_fsolver_x_upper (const gsl_root_fsolver * S);
extern int gsl_root_test_interval (double X_LOWER, double X_UPPER, double EPSABS, double EPSREL);
extern int gsl_root_test_delta (double X1, double X0, double EPSREL, double EPSABS);
extern int gsl_root_test_residual (double F, double EPSABS);






