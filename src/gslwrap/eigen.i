/* -*- C -*- */
/**
 * Author: Fabian Jakobs
 *
 * Modified by: 26. November 2007
 *          P. Schnizer <schnizer@users.sourceforge.net>
 *          added francis workspace
 */
%{
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_vector_complex_double.h>
%}



%extend gsl_eigen_symm_workspace {
  gsl_eigen_symm_workspace(const size_t n) {
    return gsl_eigen_symm_alloc(n);
  }
  ~gsl_eigen_symm_workspace() {
    gsl_eigen_symm_free(self);
  }
};

%extend gsl_eigen_symmv_workspace {
  gsl_eigen_symmv_workspace(const size_t n) {
    return gsl_eigen_symmv_alloc(n);
  }
  ~gsl_eigen_symmv_workspace() {
    gsl_eigen_symmv_free(self);
  }
};

%extend gsl_eigen_herm_workspace {
  gsl_eigen_herm_workspace(const size_t n) {
    return gsl_eigen_herm_alloc(n);
  }
  ~gsl_eigen_herm_workspace() {
    gsl_eigen_herm_free(self);
  }
};

%extend gsl_eigen_hermv_workspace {
  gsl_eigen_hermv_workspace(const size_t n) {
    return gsl_eigen_hermv_alloc(n);
  }
  ~gsl_eigen_hermv_workspace() {
    gsl_eigen_hermv_free(self);
  }
};

%extend gsl_eigen_genherm_workspace {
  gsl_eigen_genherm_workspace(const size_t n) {
    return gsl_eigen_genherm_alloc(n);
  }
  ~gsl_eigen_genherm_workspace() {
    gsl_eigen_genherm_free(self);
  }
};


%extend gsl_eigen_genhermv_workspace {
  gsl_eigen_genhermv_workspace(const size_t n) {
    return gsl_eigen_genhermv_alloc(n);
  }
  ~gsl_eigen_genhermv_workspace() {
    gsl_eigen_genhermv_free(self);
  }
};





%extend gsl_eigen_francis_workspace{
     gsl_eigen_francis_workspace (void){
	  return gsl_eigen_francis_alloc();
     }
     ~gsl_eigen_francis_workspace (void){
	  gsl_eigen_francis_free(self);
     }
}


/*
gsl_error_flag_drop
gsl_eigen_nonsymm_sort(gsl_vector_complex *INOUT, gsl_matrix_complex *INOUT, gsl_eigen_sort_t IN);
*/
gsl_error_flag_drop
gsl_eigen_nonsymmv_sort(gsl_vector_complex *INOUT, gsl_matrix_complex *INOUT, gsl_eigen_sort_t IN);

%ignore gsl_eigen_nonsymmv_params;
%{
  static int
  pygsl_eigen_nonsymm_params (const int t, const int balance, gsl_eigen_nonsymm_workspace * self)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
  gsl_eigen_nonsymm_params (t, balance, self);
  return GSL_SUCCESS;
#else
	 PyGSL_ERROR_UNIMPL
#endif
  }
  static int
  pygsl_eigen_nonsymmv_params (const int balance, gsl_eigen_nonsymmv_workspace * self)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
  gsl_eigen_nonsymmv_params (balance, self);
  return GSL_SUCCESS;
#else
	 PyGSL_ERROR_UNIMPL
#endif
  }

  static int
  pygsl_eigen_nonsymm (gsl_matrix *A, gsl_vector_complex *eval, gsl_eigen_nonsymm_workspace *w)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
    return gsl_eigen_nonsymm(A, eval, w);
#else
	 PyGSL_ERROR_UNIMPL
#endif
  }
  static int
  pygsl_eigen_nonsymm_Z (gsl_matrix *A, gsl_vector_complex *eval, gsl_matrix *Z, gsl_eigen_nonsymm_workspace *w)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
    return gsl_eigen_nonsymm_Z(A, eval, Z, w);
#else
	 PyGSL_ERROR_UNIMPL
#endif
  }
  static int
  pygsl_eigen_nonsymmv (gsl_matrix *A, gsl_vector_complex *eval, gsl_matrix_complex *evec, gsl_eigen_nonsymmv_workspace *w)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
    return gsl_eigen_nonsymmv(A, eval, evec, w);
#else
	 PyGSL_ERROR_UNIMPL
#endif
  }
  static int
  pygsl_eigen_nonsymmv_Z (gsl_matrix *A, gsl_vector_complex *eval, gsl_matrix_complex *evec, gsl_matrix *Z, gsl_eigen_nonsymmv_workspace *w)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
    return gsl_eigen_nonsymmv_Z(A, eval, evec, Z, w);
#else
	 PyGSL_ERROR_UNIMPL
#endif
  }
%}
%extend gsl_eigen_nonsymm_workspace {
  gsl_eigen_nonsymm_workspace(const size_t n) {
    return gsl_eigen_nonsymm_alloc(n);
  }
  ~gsl_eigen_nonsymm_workspace() {
    gsl_eigen_nonsymm_free(self);
  }

  gsl_error_flag_drop
    params(const int compute_t, const int balance)
    {
      return pygsl_eigen_nonsymm_params (compute_t, balance, self);
    }

  PyObject *  non_symm_int(PyObject* obj, int do_schur)
    {
        PyArrayObject *tmp = NULL, *array_a = NULL, *eval_a = NULL, *schur_a = NULL;
    	PyObject * r = NULL;
	gsl_vector_complex_view eval;
    	gsl_matrix_view A, Z;
    	PyGSL_array_index_t np = self->size, dims[2] = {0, 0};

    	int status = GSL_EFAILED,  line = __LINE__;

	FUNC_MESS_BEGIN();
	DEBUG_MESS(2, "Doing evaluation with Schur? %d", do_schur);
    	tmp = PyGSL_matrix_check(obj, np, np, PyGSL_DARRAY_CINPUT(1), NULL, NULL, NULL);
    	if(!tmp){
    		line = __LINE__ -2;
    		goto fail;
    	}
    	array_a = PyGSL_Copy_Array(tmp);
    	if(!array_a){
    		line = __LINE__ -2;
    		goto fail;
    	}
        Py_DECREF(tmp);
        tmp = NULL;
    	A = gsl_matrix_view_array(PyArray_DATA(array_a), PyArray_DIM(array_a, 0),  PyArray_DIM(array_a, 1));
	DEBUG_MESS(2, "A py ndim = %d size [%ld,%ld] gsl size [%lu,%lu]", PyArray_NDIM(array_a),
		   (long int) PyArray_DIM(array_a, 0),(long int) PyArray_DIM(array_a, 1),
		   (unsigned long)A.matrix.size1, (unsigned long)A.matrix.size2);
    	eval_a =  PyGSL_New_Array(1, &np, NPY_CDOUBLE);
    	if(!eval_a){
    		line = __LINE__ -2;
    		goto fail;
    	}
    	eval = gsl_vector_complex_view_array(PyArray_DATA(eval_a), PyArray_DIM(eval_a, 0));
	DEBUG_MESS(2, "eval py size %ld gsl size %lu", (long int) PyArray_DIM(eval_a, 0),
		   (unsigned long)eval.vector.size);
	if(!do_schur){
	  status = pygsl_eigen_nonsymm(&A.matrix,  &eval.vector, self);
	  if (PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
	        line = __LINE__ -1;
    		goto fail;
    	  }
	  r = Py_BuildValue("OO", eval_a, array_a);
	  array_a = eval_a = NULL;
	  DEBUG_MESS(2, "Doing schur %d", do_schur);
	  FUNC_MESS_END();
	  return r;
	}

	dims[0] = dims[1] = np;
	DEBUG_MESS(2, "Allocating data for Schur result dims = [%ld, %ld]", dims[0], dims[1]);
	schur_a = PyGSL_New_Array(2, dims, NPY_DOUBLE);
	if(!schur_a){
	  line = __LINE__ -2;
	  goto fail;
	}
	Z = gsl_matrix_view_array(PyArray_DATA(schur_a), PyArray_DIM(schur_a, 0),  PyArray_DIM(schur_a, 1));
	DEBUG_MESS(2, "Z py ndims = %ld size [%ld,%ld] gsl size [%lu,%lu]", (long int) PyArray_NDIM(schur_a),
		   (long int) PyArray_DIM(schur_a, 0),(long int) PyArray_DIM(schur_a, 1),
		   (unsigned long)Z.matrix.size1, (unsigned long)Z.matrix.size2);

	status = pygsl_eigen_nonsymm_Z(&A.matrix,  &eval.vector, &Z.matrix, self);
	if (PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
	        line = __LINE__ -1;
    		goto fail;
	}
	r = Py_BuildValue("OOO", eval_a, array_a, schur_a);
	array_a = eval_a = schur_a = NULL;
	FUNC_MESS_END();
	return r;

      fail:
	FUNC_MESS("FAILED");
    	PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
    	Py_XDECREF(eval_a);
    	Py_XDECREF(tmp);
    	Py_XDECREF(array_a);
    	Py_XDECREF(schur_a);
    	return NULL;
    }

  int n_evaluations(void){
    return self->n_evals;
  }
};


%extend gsl_eigen_nonsymmv_workspace {
  gsl_eigen_nonsymmv_workspace(const size_t n) {
    return gsl_eigen_nonsymmv_alloc(n);
  }
  ~gsl_eigen_nonsymmv_workspace() {
    gsl_eigen_nonsymmv_free(self);
  }

  gsl_error_flag_drop
    params(const int balance)
    {
      return pygsl_eigen_nonsymmv_params (balance, self);
    }

  PyObject *  non_symmv_int(PyObject* obj, int do_schur)
    {
        PyArrayObject *tmp = NULL, *array_a = NULL, *eval_a = NULL, *evec_a = NULL,*schur_a = NULL;
        PyObject * r = NULL;
        gsl_vector_complex_view eval;
        gsl_matrix_view A, Z;
        gsl_matrix_complex_view evec;
        PyGSL_array_index_t np = self->size, dims[2] = {0, 0};

        int status = GSL_EFAILED,  line = __LINE__;

        FUNC_MESS_BEGIN();
        DEBUG_MESS(2, "Doing evaluation with Schur? %d", do_schur);
        tmp = PyGSL_matrix_check(obj, np, np, PyGSL_DARRAY_CINPUT(1), NULL, NULL, NULL);
        if(!tmp){
	    line = __LINE__ -2;
            goto fail;
        }
        array_a = PyGSL_Copy_Array(tmp);
        if(!array_a){
            line = __LINE__ -2;
            goto fail;
        }
        Py_DECREF(tmp);
        tmp = NULL;
        A = gsl_matrix_view_array(PyArray_DATA(array_a), PyArray_DIM(array_a, 0),  PyArray_DIM(array_a, 1));
        DEBUG_MESS(2, "A py ndim = %d size [%ld,%ld] gsl size [%lu,%lu]", PyArray_NDIM(array_a),
                   (long int) PyArray_DIM(array_a, 0),(long int) PyArray_DIM(array_a, 1),
                   (unsigned long)A.matrix.size1, (unsigned long)A.matrix.size2);

        eval_a =  PyGSL_New_Array(1, &np, NPY_CDOUBLE);
        if(!eval_a){
            line = __LINE__ -2;
            goto fail;
        }
        eval = gsl_vector_complex_view_array(PyArray_DATA(eval_a), PyArray_DIM(eval_a, 0));
        DEBUG_MESS(2, "eval py size %ld gsl size %lu", (long int) PyArray_DIM(eval_a, 0),
                   (unsigned long)eval.vector.size);

        dims[0] = dims[1] = np;
        evec_a =  PyGSL_New_Array(2, dims, NPY_CDOUBLE);
        evec = gsl_matrix_complex_view_array(PyArray_DATA(evec_a), PyArray_DIM(evec_a, 0),  PyArray_DIM(evec_a, 1));
        if(!do_schur){
            status = pygsl_eigen_nonsymmv(&A.matrix,  &eval.vector, &evec.matrix, self);
            if (PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
                line = __LINE__ -1;
                goto fail;
            }
            r = Py_BuildValue("OOO",  eval_a, evec_a, array_a);
            array_a = eval_a = evec_a = NULL;
            DEBUG_MESS(2, "Doing schur %d", do_schur);
            FUNC_MESS_END();
            return r;
        }

        DEBUG_MESS(2, "Allocating data for Schur result dims = [%ld, %ld]", dims[0], dims[1]);
        schur_a = PyGSL_New_Array(2, dims, NPY_DOUBLE);
        if(!schur_a){
            line = __LINE__ -2;
            goto fail;
        }
        Z = gsl_matrix_view_array(PyArray_DATA(schur_a), PyArray_DIM(schur_a, 0),  PyArray_DIM(schur_a, 1));
        DEBUG_MESS(2, "Z py ndims = %ld size [%ld,%ld] gsl size [%lu,%lu]", (long int) PyArray_NDIM(schur_a),
                   (long int) PyArray_DIM(schur_a, 0),(long int) PyArray_DIM(schur_a, 1),
                   (unsigned long)Z.matrix.size1, (unsigned long)Z.matrix.size2);

        status = pygsl_eigen_nonsymmv_Z(&A.matrix,  &eval.vector, &evec.matrix, &Z.matrix, self);
        if (PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
            line = __LINE__ -1;
            goto fail;
        }
        r = Py_BuildValue("OOO", eval_a, array_a, evec_a, schur_a);
        array_a = eval_a = evec_a = schur_a = NULL;
        FUNC_MESS_END();
        return r;

      fail:
        FUNC_MESS("FAILED");
        PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
        Py_XDECREF(eval_a);
        Py_XDECREF(evec_a);
        Py_XDECREF(tmp);
        Py_XDECREF(array_a);
        Py_XDECREF(schur_a);
        return NULL;
    }

  int n_evaluations(void){
    gsl_eigen_nonsymm_workspace *nonsymm_workspace_p = NULL;
    nonsymm_workspace_p = self->nonsymm_workspace_p;
    assert(nonsymm_workspace_p)
    return nonsymm_workspace_p->n_evals;
  }

};


%extend gsl_eigen_gen_workspace {
  gsl_eigen_gen_workspace(const size_t n) {
    return gsl_eigen_gen_alloc(n);
  }
  ~gsl_eigen_gen_workspace() {
    gsl_eigen_gen_free(self);
  }
};


%extend gsl_eigen_genv_workspace {
  gsl_eigen_genv_workspace(const size_t n) {
    return gsl_eigen_genv_alloc(n);
  }
  ~gsl_eigen_genv_workspace() {
    gsl_eigen_genv_free(self);
  }
};

/*
%ignore gsl_eigen_nonsymm_sort;
%ignore gsl_eigen_nonsymmv_sort;
*/

%include gsl/gsl_eigen.h
