/* -*- C -*- */
%apply double * OUTPUT {
	double * Y,
	double * Y_ERR
};

gsl_error_flag_drop
gsl_multifit_linear_est (const gsl_vector * x, 
			 const gsl_vector * c, 
			 const gsl_matrix * IN, 
			 double * Y, double *Y_ERR);


PyObject *
gsl_multifit_linear_est_matrix (const gsl_matrix * x, 
				const gsl_vector * c, 
				const gsl_matrix * cov);



PyObject *
pygsl_multifit_linear_residuals (const gsl_matrix *X, const gsl_vector *y,
				 const gsl_vector *c);

%{

PyObject *
pygsl_multifit_linear_residuals (const gsl_matrix *X, const gsl_vector *y,
				 const gsl_vector *c)
{

#ifndef _PYGSL_GSL_HAS_MULTIFIT_LINEAR_RESIDUALS
  PyGSL_ERROR_UNIMPL_NULL;
#endif /*  _PYGSL_GSL_HAS_MULTIFIT_LINEAR_RESIDUALS */
  {
	int flag, line = __LINE__;

	PyArrayObject *r_a = NULL;
	gsl_vector_view r;
	PyGSL_array_index_t dim = 0;
	
	FUNC_MESS_BEGIN();

	dim = y->size;
	r_a = PyGSL_New_Array(1, &dim, NPY_DOUBLE);
	if(r_a == NULL){
		goto fail;
	}
	r = gsl_vector_view_array(PyArray_DATA(r_a), PyArray_DIM(r_a, 0)); 
	flag = gsl_multifit_linear_residuals(X, y, c, &r.vector);
	if(GSL_SUCCESS != PyGSL_ERROR_FLAG(flag)){
		goto fail;
	}
	FUNC_MESS_END();

	return (PyObject *) r_a;
	
  fail:
	FUNC_MESS_FAILED();
	Py_XDECREF(r_a);	
	return NULL;
  }

}

%}
