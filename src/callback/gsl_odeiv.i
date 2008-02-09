/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * created: December 2002
 * file: src/odeiv/gsl_odeiv.i
 *
 * This interface file was generated for gsl version 1.0. It uses hand coded 
 * wrappers for the core path. See odeiv.ic
 */


%{
#include <gsl/gsl_odeiv.h>
#include <stdlib.h>
#include <assert.h>
  /* Some functions needed hand coded wrapper. These are in here. */
#include <odeiv.ic>
%}

/* Error handling the int */
%include gsl_error_typemap.i

/* ------------------------------------------------------------------------ */
/* Available stepper types. */
extern const gsl_odeiv_step_type *gsl_odeiv_step_rk2;
extern const gsl_odeiv_step_type *gsl_odeiv_step_rk4;
extern const gsl_odeiv_step_type *gsl_odeiv_step_rkf45;
extern const gsl_odeiv_step_type *gsl_odeiv_step_rkck;
extern const gsl_odeiv_step_type *gsl_odeiv_step_rk8pd;
extern const gsl_odeiv_step_type *gsl_odeiv_step_rk2imp;
extern const gsl_odeiv_step_type *gsl_odeiv_step_rk4imp;
extern const gsl_odeiv_step_type *gsl_odeiv_step_bsimp;
extern const gsl_odeiv_step_type *gsl_odeiv_step_gear1;
extern const gsl_odeiv_step_type *gsl_odeiv_step_gear2;


extern gsl_odeiv_step * 
gsl_odeiv_step_alloc(const gsl_odeiv_step_type * T, size_t dim);
extern int  
gsl_odeiv_step_reset(gsl_odeiv_step * s);
extern void 
gsl_odeiv_step_free(gsl_odeiv_step * s);

extern const char * 
gsl_odeiv_step_name(const gsl_odeiv_step *);
extern unsigned int 
gsl_odeiv_step_order(const gsl_odeiv_step * s);

%native(gsl_odeiv_step_apply) PyObject *pygsl_odeiv_step_apply(PyObject *self, PyObject *args);

/* ------------------------------------------------------------------------ */
/* Available control  types.
 *
 */

%constant int gsl_odeiv_hadj_dec = GSL_ODEIV_HADJ_DEC;
%constant int gsl_odeiv_hadj_inc = GSL_ODEIV_HADJ_INC;
%constant int gsl_odeiv_hadj_nil = GSL_ODEIV_HADJ_NIL;

extern gsl_odeiv_control * 
gsl_odeiv_control_alloc(const gsl_odeiv_control_type * T);
extern int 
gsl_odeiv_control_init(gsl_odeiv_control * c, double eps_abs, double eps_rel, 
		       double a_y, double a_dydt);
extern void 
gsl_odeiv_control_free(gsl_odeiv_control * c);

%native(gsl_odeiv_control_hadjust) PyObject *pygsl_odeiv_control_hadjust(PyObject *self, PyObject *args);



extern const char * 
gsl_odeiv_control_name(const gsl_odeiv_control * c);

extern gsl_odeiv_control * 
gsl_odeiv_control_standard_new(double eps_abs, double eps_rel, 
				 double a_y, double a_dydt);

extern gsl_odeiv_control * 
gsl_odeiv_control_y_new(double eps_abs, double eps_rel);
extern gsl_odeiv_control * 
gsl_odeiv_control_yp_new(double eps_abs, double eps_rel);


extern gsl_odeiv_evolve * 
gsl_odeiv_evolve_alloc(size_t dim);

extern int 
gsl_odeiv_evolve_reset(gsl_odeiv_evolve *);
extern void 
gsl_odeiv_evolve_free(gsl_odeiv_evolve *);

%native(gsl_odeiv_evolve_apply) PyObject *pygsl_odeiv_evolve_apply(PyObject *self, PyObject *args);
%native(gsl_odeiv_evolve_apply_vector) PyObject *pygsl_odeiv_evolve_apply_vector(PyObject *self, PyObject *args);

/* EOF */
