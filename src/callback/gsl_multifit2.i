/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */

/*
 * The gsl_multifit_linear_workspace structre was changed from GSL 1.X to 
 * GSL 2.X.
 * setup checks for that and then appropriate measures are taken
 */
%{
#include <pygsl/pygsl_features.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_multifit.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

static PyObject * pygsl_multifit2_module = NULL;
#include "pygsl_multifit2.ic"
%}

%init{
  init_pygsl();
  pygsl_multifit2_module = m;

}
%include typemaps.i
%include gsl_block_typemaps.i
%include gsl_error_typemap.i

%feature("autodoc", "3");
%define MODULEDOCSTRING
"(New|extended) wrapper for multifit interface"
""
"This interfaces tries to be a little more object oriented. Feedback is highly"
"appretiated"
""
%enddef
%module(docstring=MODULEDOCSTRING) multifit2;

%{
  
%}

/* -- gsl_multifit_linear  ------------------------------------------------- */
%rename(multifit) gsl_multifit_linear_workspace;
typedef struct{
}gsl_multifit_linear_workspace;
%extend gsl_multifit_linear_workspace{
	gsl_multifit_linear_workspace(const size_t n, const size_t p){
		gsl_multifit_linear_workspace * obj;
		FUNC_MESS_BEGIN();
		obj =  gsl_multifit_linear_alloc(n, p);
		FUNC_MESS_END();
		return obj;
	}

	~gsl_multifit_linear_workspace(void){
		FUNC_MESS_BEGIN();
		gsl_multifit_linear_free(self);
		FUNC_MESS_END();
	}

	gsl_error_flag_drop svd(const gsl_matrix *X) {
		return gsl_multifit_linear_svd(X, self);
	}

	gsl_error_flag_drop bsvd(const gsl_matrix *X) {
		return gsl_multifit_linear_svd(X, self);
	}

	PyObject * linear(const gsl_matrix *X, const gsl_vector *y) {
		PyObject *obj;
		FUNC_MESS_BEGIN();
		obj =  pygsl_multifit2_linear_or_w(X, NULL, y, self);
		FUNC_MESS_END();
		return obj;
	}

	PyObject * wlinear(const gsl_matrix *X, const gsl_vector *w, const gsl_vector *y) {
		PyObject *obj;
		FUNC_MESS_BEGIN();
		obj =  pygsl_multifit2_linear_or_w(X, w, y, self);
		FUNC_MESS_END();
		return obj;
	}
	
	PyObject * linear_tsvd(const gsl_matrix *X, const gsl_vector *y, const double tol){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		obj =  pygsl_multifit2_linear_tvsd_or_w(X, NULL, y, tol, self);
		FUNC_MESS_END();
		return obj;	
	}
    
	PyObject * wlinear_tsvd(const gsl_matrix *X, const gsl_vector *w, const gsl_vector *y, const double tol){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		obj =  pygsl_multifit2_linear_tvsd_or_w(X, w, y, tol, self);
		FUNC_MESS_END();
		return obj;	
	}
	
	size_t rank(const double tol){
		return gsl_multifit_linear_rank(tol, self);
	}
      
}
/* -- gsl_multifit_linear  ------------------------------------------------- */

%include gsl_multifit_common.i
%{
%}
/* -- gsl_multifit_linear regularisd --------------------------------------- */
%extend gsl_multifit_linear_workspace{
	PyObject *
		stdform1(const gsl_vector * L, const gsl_matrix * X, const gsl_vector * y){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		/* returns gsl_matrix * Xs, gsl_vector * ys */
		obj =  pygsl_multifit2_linear_stdform_12_or_w(NULL, L, X, NULL, y, self);
		FUNC_MESS_END();
		return obj;	
		
	}
	PyObject *
		wstdform1(const gsl_vector * L, const gsl_matrix * X, const gsl_vector * w, const gsl_vector * y){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		/* returns gsl_matrix * Xs, gsl_vector * ys */
		obj =  pygsl_multifit2_linear_stdform_12_or_w(NULL, L, X, w, y, self);
		FUNC_MESS_END();
		return obj;	
	}

	PyObject *
		stdform2(const gsl_matrix * LQR, const gsl_vector * Ltau,
			 const gsl_matrix * X, const gsl_vector * y){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		/* returns gsl_matrix * Xs, gsl_vector * ys  gsl_matrix * M */
		obj =  pygsl_multifit2_linear_stdform_12_or_w(LQR, Ltau, X, NULL, y, self);
		FUNC_MESS_END();
		return obj;	
		
	}
	PyObject *
		wstdform2(const gsl_matrix * LQR, const gsl_vector * Ltau,
			 const gsl_matrix * X, const gsl_vector * w, const gsl_vector * y){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		/* returns gsl_matrix * Xs, gsl_vector * ys  gsl_matrix * M */
		obj =  pygsl_multifit2_linear_stdform_12_or_w(LQR, Ltau, X, w, y, self);
		FUNC_MESS_END();
		return obj;	
	}


	PyObject *
		solve (const double lambda, const gsl_matrix * Xs, const gsl_vector * ys){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		/* returns gsl_vector * cs, double * rnorm, double * snorm */
		obj = pygsl_multifit_linear_solve(lambda, Xs, ys, self);
		FUNC_MESS_END();
		return obj;	
	}
	
	double rcond(void){
		return gsl_multifit_linear_rcond(self);
	}

	PyObject *lcurve(const gsl_vector * y, size_t n_points){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		obj = pygsl_multifit_linear_lcurve(y, n_points, self);
		FUNC_MESS_END();
		return obj;	
	}

	/* 
	 * XXX reg_param ... should that be just n_points as the vector is 
	 * calculated on the fly
	 */
	PyObject * gcv(const gsl_vector * y, gsl_vector * reg_param){
		PyObject *obj;
		FUNC_MESS_BEGIN();
		obj = pygsl_multifit_linear_gcv(y, reg_param, self);
		FUNC_MESS_END();
		return obj;
	}
}

PyObject *
pygsl_multifit_linear_L_decomp(PyObject *L, int do_copy = 1);

%apply size_t * OUTPUT {
	size_t * idx_out
};

%rename(lcorner) gsl_multifit_linear_lcorner;
gsl_error_flag_drop
gsl_multifit_linear_lcorner(const gsl_vector * rho, const gsl_vector * eta, size_t * idx_out);

%rename(lcorner2) gsl_multifit_linear_lcorner2;
gsl_error_flag_drop
gsl_multifit_linear_lcorner2(const gsl_vector * rho, const gsl_vector * eta, size_t * idx_out);
/* -- gsl_multifit_linear regularisd --------------------------------------- */

