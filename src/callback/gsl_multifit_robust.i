/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
%module multifit_robust
%feature("autodoc", "3");
%{
#include <gsl/gsl_multifit.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
%}

%init{
  init_pygsl();
}

%include typemaps.i
%include constraints.i

%include gsl_block_typemaps.i
%include gsl_error_typemap.i

%rename(stats) gsl_multifit_robust_stats;
%rename(workspace) gsl_multifit_robust_workspace;

typedef struct{
  %immutable;
 } gsl_multifit_robust_stats;

typedef struct{
  %immutable;
 } gsl_multifit_robust_workspace;

%extend gsl_multifit_robust_stats{
	/*
	gsl_multifit_robust_stats(void){
		return (gsl_multifit_robust_stats *) PyMem_New(gsl_multifit_robust_stats, 1);
	}
	~gsl_multifit_robust_stats(void){
		PyMem_Del(self);
	}
	*/
	/* OLS estimate of sigma */
	double sigma_ols(void){
		return self->sigma_ols;
	}
	/* MAD estimate of sigma */
	double sigma_mad(void){
		return self->sigma_mad;
	}
        /* robust estimate of sigma */
	double sigma_rob(void){
		return self->sigma_rob;
	} 
	
	/* final estimate of sigma */
	double sigma(void){
		return self->sigma;
	}
        /* R^2 coefficient of determination */
	double Rsq(void){
		return self->Rsq;
	}
        /* degree of freedom adjusted R^2 */
	double adj_Rsq(void){
		return self->adj_Rsq;
	}	
        /* root mean squared error */
	double rmse(void){
		return self->rmse;
	}         
        /* residual sum of squares */
	double sse(void){
		return self->sse;
	}
        /* degrees of freedom */
	size_t dof(void){
		return self->dof;
	}
        /* number of iterations */
	size_t numit(void){
		return self->numit;
	}
	/* final weights */
	PyObject * weights(void){
		return (PyObject *) PyGSL_copy_gslvector_to_pyarray(self->weights);
	} 

	/* final residuals y - X c */
	PyObject * residuals(void){
		return  (PyObject *) PyGSL_copy_gslvector_to_pyarray(self->r);
	}     
 };

%extend gsl_multifit_robust_workspace{
	gsl_multifit_robust_workspace(const gsl_multifit_robust_type *T,
				      const size_t n, const size_t p){
		return gsl_multifit_robust_alloc(T, n, p);
	}

	~gsl_multifit_robust_workspace(){
		gsl_multifit_robust_free(self);
	}

	gsl_error_flag_drop tune(double t){
		return gsl_multifit_robust_tune(t, self);
	}

	const char * name(void){
		return gsl_multifit_robust_name(self);
	}
	
	PyObject *fit(const gsl_matrix * X, const gsl_vector * y){
		gsl_vector_view  c; 
		gsl_matrix_view  cov;
		PyObject * returnobj = NULL;
		PyArrayObject *c_a = NULL, *cov_a = NULL;
		int status;
		PyGSL_array_index_t dims[2];
	  
		dims[0] = X->size2;
		c_a = PyGSL_New_Array(1, dims, NPY_DOUBLE);
		if(c_a == NULL){
			goto fail;
		}
	  
		dims[0] = dims[1] = X->size2;
		cov_a = PyGSL_New_Array(2, dims, NPY_DOUBLE);
		if(cov_a == NULL){
			goto fail;
		}
		
		c = gsl_vector_view_array((double *)PyArray_DATA(c_a), PyArray_DIM(c_a, 0));
		cov = gsl_matrix_view_array((double *)PyArray_DATA(cov_a), PyArray_DIM(cov_a, 0), PyArray_DIM(cov_a, 1));

		status = gsl_multifit_robust(X, y, &c.vector, &cov.matrix, self);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			goto fail;
		}

		returnobj = PyTuple_New(2);
		if (returnobj == NULL)
			goto fail;

		PyTuple_SetItem(returnobj, 0, (PyObject *) c_a);
		PyTuple_SetItem(returnobj, 1, (PyObject *) cov_a);

		return returnobj;
		  
	  fail:
		Py_XDECREF(c_a);
		Py_XDECREF(cov_a);
		return NULL;
	}
	
	gsl_multifit_robust_stats statistics(void){
		return gsl_multifit_robust_statistics(self);
        }
	
 };

%apply(double * OUTPUT){double * y, double * y_err}
%rename(est) gsl_multifit_robust_est;
gsl_error_flag_drop gsl_multifit_robust_est(const gsl_vector * v, const gsl_vector * c,
					    const gsl_matrix * cov, double * y, double * y_err);


%rename(est_vector) pygsl_multifit_robust_est_vector;
%inline{
PyObject *
pygsl_multifit_robust_est_vector(const gsl_matrix * X, const gsl_vector * c, const gsl_matrix * cov)
{

	double y, y_err, *y_p, *y_err_p;
	PyObject * returnobj = NULL;
	PyArrayObject *y_a = NULL, *y_err_a = NULL;
	size_t cnt, cnt_max;
	PyGSL_array_index_t dim;
	int status;

	FUNC_MESS_BEGIN();

	cnt_max = X->size1;
	dim =  (PyGSL_array_index_t) cnt_max;      
	y_a =  PyGSL_New_Array(1, &dim, NPY_DOUBLE);
	if(y_a == NULL){
		goto fail;
	}
	y_err_a =  PyGSL_New_Array(1, &dim, NPY_DOUBLE);
	if(y_err_a == NULL){
		goto fail;
	}

	y_p = (double *) PyArray_DATA(y_a);
	y_err_p = (double *) PyArray_DATA(y_err_a);
	for(cnt = 0; cnt<cnt_max; cnt++){
		gsl_vector_const_view v = gsl_matrix_const_row(X, cnt);
		status = gsl_multifit_robust_est(&v.vector, c, cov, &y, &y_err);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			goto fail;
		}
		y_p[cnt] = y;
		y_err_p[cnt] = y_err;
	}

	returnobj = PyTuple_New(2);
	if (returnobj == NULL){
		goto fail;
	}
	
	PyTuple_SetItem(returnobj, 0, (PyObject *) y_a);
	PyTuple_SetItem(returnobj, 1, (PyObject *) y_err_a);
	DEBUG_MESS(2, "return object %p", (void *) returnobj);

	FUNC_MESS_END();

	return returnobj;

  fail:
	Py_XDECREF(y_a);
	Py_XDECREF(y_err_a);
	DEBUG_MESS(2, "failed! returnobj = %p", (void *) returnobj);
	return NULL;
}
}

%rename(default)  gsl_multifit_robust_default;
%rename(bisquare) gsl_multifit_robust_bisquare;
%rename(cauchy)   gsl_multifit_robust_cauchy;
%rename(fair)     gsl_multifit_robust_fair;
%rename(huber)    gsl_multifit_robust_huber;
%rename(ols)      gsl_multifit_robust_ols;
%rename(welsch)   gsl_multifit_robust_welsch;

extern const gsl_multifit_robust_type * gsl_multifit_robust_default;
extern const gsl_multifit_robust_type * gsl_multifit_robust_bisquare;
extern const gsl_multifit_robust_type * gsl_multifit_robust_cauchy;
extern const gsl_multifit_robust_type * gsl_multifit_robust_fair;
extern const gsl_multifit_robust_type * gsl_multifit_robust_huber;
extern const gsl_multifit_robust_type * gsl_multifit_robust_ols;
extern const gsl_multifit_robust_type * gsl_multifit_robust_welsch;
