/* -*- C -*- */
/*
 * Author: Pierre Schnizer
 * Date: 2008
 */

%module bspline
%feature("autodoc", 3);

%include gsl_error_typemap.i
%include gsl_block_typemaps.i
%{
#include <pygsl/block_helpers.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_bspline.h>
#include <stdlib.h>
#include <stdio.h>
struct pygsl_bspline
{
     gsl_matrix_view cov;
     gsl_vector_view coeffs;
     gsl_vector_view tmp;
     gsl_bspline_workspace *w;
     PyArrayObject *knots_a;
     PyArrayObject *coeffs_a;
     PyArrayObject *cov_a;
     PyArrayObject *tmp_a;
};
#include "bspline.ic"
%}

%define pygsl_bspline_doc
"bspline base class.\n"
""
"wraps ...\n"
%enddef
%rename(bspline) pygsl_bspline;
%feature("docstring") pygsl_bspline
pygsl_bspline_doc



struct pygsl_bspline
{
     %immutable;
  //gsl_matrix_view cov;
  //gsl_vector_view coeffs;
  //gsl_vector_view tmp;
  //gsl_bspline_workspace *w;
  //PyArrayObject *knots_a;
  //PyArrayObject *coeffs_a;
  //PyArrayObject *cov_a;
  //PyArrayObject *tmp_a;
};


%define pygsl_bspline_eval_doc
"function eval(x)\n"
"evaluates the bspline object at position x\n"
"Args:\n"
"    x: independent variable\n"
"\n"
"Returns:\n"
"    vec: vector of points\n"
"\n"
"uses: :c:func:`gsl_bspline_eval`\n"
%enddef
%feature("docstring") pygsl_bspline::eval
pygsl_bspline_eval_doc
 /*
%feature("docstring") bspline::eval
pygsl_bspline_eval_doc
 */

%define pygsl_bspline_knots_uniform_doc
"function knots_uniform(a, b)\n"
"creates uniform knots\n"
"Args:\n"
"    a: lower boundary\n"
"    b: upper boundary\n"
"\n"
"\n"
"uses: :c:func:`gsl_bspline_knots_uniform`\n"
%enddef
%feature("docstring") pygsl_bspline::knots_uniform
pygsl_bspline_eval_doc
 /*
 %feature("docstring") bspline::knots_uniform
 pygsl_bspline_eval_doc
%feature("docstring") uniform
pygsl_bspline_eval_doc
 */

%extend pygsl_bspline{
  pygsl_bspline(size_t K, size_t NBREAK) {
       struct pygsl_bspline *tmp;
       tmp = (struct pygsl_bspline *) calloc(1, sizeof(struct pygsl_bspline));
       if(tmp == NULL){
	    return NULL;
       }
       tmp->w = gsl_bspline_alloc(K, NBREAK);
       tmp->coeffs_a = NULL;
       tmp->cov_a = NULL;
       tmp->knots_a = NULL;
       return tmp;
  }

  ~pygsl_bspline() {
       gsl_bspline_free(self->w);
       self->w = NULL;
       Py_XDECREF(self->coeffs_a);
       self->coeffs_a = NULL;
       Py_XDECREF(self->cov_a);
       self->cov_a = NULL;
       Py_XDECREF(self->tmp_a);
       self->tmp_a = NULL;
       Py_XDECREF(self->knots_a);
       self->knots_a = NULL;
       free(self);
  }

  PyObject * get_internal_knots(){
       return (PyObject *) PyGSL_copy_gslvector_to_pyarray(self->w->knots);

  }
  gsl_error_flag_drop knots(PyObject * knots_o){
       PyGSL_array_index_t sample_len, stride;
       PyArrayObject * knots_a = NULL;
       gsl_vector_view vec;
       int flag = GSL_EINVAL;

       FUNC_MESS_BEGIN();
       knots_a = PyGSL_vector_check(knots_o, self->w->knots->size, PyGSL_DARRAY_INPUT(1), &stride, NULL);
       if(knots_a == NULL){
	    flag =  GSL_EINVAL;
	    goto fail;
       }
       sample_len = PyArray_DIM(knots_a,0);
       vec = gsl_vector_view_array_with_stride((double *)PyArray_DATA(knots_a), stride, sample_len);
       Py_XDECREF(self->knots_a);
       /* pass the reference to knots_a */
       self->knots_a = knots_a;
       knots_a = NULL;

       DEBUG_MESS(2, "sample_len = %ld", (long) sample_len);
       if(sample_len != self->w->nbreak){
	    pygsl_error("Knots vector did not mach the number of break points!",
			__FILE__, __LINE__ - 2, GSL_EBADLEN);
	    return GSL_EBADLEN;
       }
       flag =  gsl_bspline_knots(&(vec.vector), self->w);
       return flag;
       FUNC_MESS_END();

  fail:
       FUNC_MESS("FAIL");
       Py_XDECREF(knots_a);
       return flag;
  }

  gsl_error_flag_drop knots_uniform(const double a, const double b){
       return gsl_bspline_knots_uniform(a, b, self->w);
  }

  /*
%feature("autodoc") pygsl_bspline "calls eval for each element of the vector and returns a matrix", "XXX whats that";
  */

  PyObject*  eval_vector(const gsl_vector *IN){
       PyArrayObject *B_M_a = NULL;
       gsl_vector_view B_v;
       PyGSL_array_index_t n, sample_len, tmp[2], i=0, strides;
       double x;
       char * row_ptr;
       int flag=GSL_EFAILED;

       FUNC_MESS_BEGIN();
       n = self->w->n;
       sample_len = IN->size;
       DEBUG_MESS(2, "sample_len = %ld", (long) sample_len);
       tmp[0] = sample_len;
       tmp[1] = n;
       B_M_a = PyGSL_New_Array(2, tmp, NPY_DOUBLE);
       if(B_M_a == NULL)
	    return NULL;

       DEBUG_MESS(2, "B_M_a = %p, strides = (%ld, %ld) size = (%ld, %ld)",
		  (void *) B_M_a,
		  (long) PyArray_STRIDE(B_M_a, 0), (long) PyArray_STRIDE(B_M_a, 1),
		  (long) PyArray_DIM(B_M_a, 0), (long)  PyArray_DIM(B_M_a, 1)
		  );


       for(i = 0; i < sample_len; ++i){
	       row_ptr = (char *) PyArray_GETPTR1(B_M_a, i);
	       B_v = gsl_vector_view_array((double *) (row_ptr), (PyArray_DIM(B_M_a, 1)));
	       x = gsl_vector_get(IN, i);
	       DEBUG_MESS(5, "i  = %ld, x = %f row_ptr = %p, B_v = %p->data = %p", (long) i, x,
			  (void *) row_ptr, (void *) &(B_v.vector), (void *)(B_v.vector.data));
	       flag = gsl_bspline_eval(x, &(B_v.vector), self->w);
	       if (PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS)
		       goto fail;
       }
       FUNC_MESS_END();
       return (PyObject *) B_M_a;

  fail:
       /* Failed */
       Py_XDECREF(B_M_a);
       return NULL;
  }

  PyObject*  eval(const double X){
       PyArrayObject *B_a = NULL;
       gsl_vector_view B_v;
       PyGSL_array_index_t n;
       int flag=GSL_EFAILED;

       n = self->w->n;
       B_a = PyGSL_New_Array(1, &n, NPY_DOUBLE);
       if(B_a == NULL)
	    return NULL;
       B_v = gsl_vector_view_array((double *) PyArray_DATA(B_a), PyArray_DIM(B_a,0));
       flag = gsl_bspline_eval(X, &(B_v.vector), self->w);
       if (PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS)
	    goto fail;
       return (PyObject *) B_a;

  fail:
       /* Failed */
       Py_XDECREF(B_a);
       return NULL;
  }

  gsl_error_flag_drop set_coefficients_and_covariance_matrix(PyObject * coeffs_o,
							     PyObject * cov_o)
    {

    PyArrayObject *coeffs_a = NULL, *cov_a = NULL;
    PyGSL_array_index_t size;


    FUNC_MESS_BEGIN();
    if(self->coeffs_a != NULL){
      Py_XDECREF(self->coeffs_a);
      self->coeffs_a = NULL;

    }

    size = self->w->n;
    coeffs_a = PyGSL_vector_check(coeffs_o, size, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
    if(coeffs_a == NULL)
      return GSL_FAILURE;

    self->coeffs_a = coeffs_a;
    self->coeffs = gsl_vector_view_array((double *) PyArray_DATA(coeffs_a),
					 PyArray_DIM(coeffs_a,0));
    coeffs_a = NULL;

    /* work array, does the size fit? */
    if(self->tmp_a != NULL && PyArray_DIM(self->tmp_a, 0) != size){
	Py_DECREF(self->tmp_a);
	self->tmp_a = NULL;
    }
    if(self->tmp_a == NULL){
      PyGSL_array_index_t size_tmp = self->w->n;
      self->tmp_a = PyGSL_New_Array(1, &size_tmp, NPY_DOUBLE);
    }
    if(self->tmp_a == NULL){
      return GSL_ENOMEM;
    }
    self->tmp = gsl_vector_view_array((double *) PyArray_DATA(self->tmp_a),
				      PyArray_DIM(self->tmp_a, 0));
    if(cov_o == NULL){
      /* Nothing left to do ...*/
      Py_XDECREF(self->cov_a);
      self->cov_a = NULL;
      return GSL_SUCCESS;
    }

    if(self->cov_a != NULL){
      Py_XDECREF(self->cov_a);
      self->cov_a = NULL;
    }

    cov_a = PyGSL_matrix_check(cov_o, size, size, PyGSL_DARRAY_CINPUT(2),
			       NULL, NULL, NULL);
    if(cov_a == NULL)
      return GSL_FAILURE;

    self->cov_a = cov_a;
    self->cov = gsl_matrix_view_array((double *) PyArray_DATA(cov_a),
				      PyArray_DIM(cov_a, 0),
				      PyArray_DIM(cov_a, 1));
    FUNC_MESS_END();
    return GSL_SUCCESS;

  }

  gsl_error_flag_drop eval_dep(const double x, double *OUT){
    int flag;
    if(self->coeffs_a == NULL || self->tmp_a == NULL){
      PyGSL_ERROR("No coefficients set", GSL_EFAULT);
    }

    flag = _pygsl_bspline_eval_dep(self, x, OUT);
    return flag;
  }

  PyObject * eval_dep_vector(const gsl_vector *X){
    PyArrayObject *a;
    double * data, xt;
    PyGSL_array_index_t size, i;
    int flag;

    if(self->coeffs_a == NULL || self->tmp_a == NULL){
      PyGSL_ERROR_NULL("No coefficients set", GSL_EFAULT);
    }
    size = X->size;
    a = PyGSL_New_Array(1, &size, NPY_DOUBLE);

    if(a == NULL)
      return NULL;

    data = ((double *) PyArray_DATA(a));
    for(i = 0; i < size; ++i){
      xt = gsl_vector_get(X, i);
      flag = _pygsl_bspline_eval_dep(self, xt, &(data[i]));
      if (flag != GSL_SUCCESS){
	Py_DECREF(a);
	return NULL;
      }
    }
    return (PyObject *) a;
  }

  gsl_error_flag_drop eval_dep_yerr(const double x, double *OUT, double *OUT2){
    int flag;
    if(self->coeffs_a == NULL || self->tmp_a == NULL || self->cov_a == NULL){
      PyGSL_ERROR("No coefficients or No covarince matrix set",
		     GSL_EFAULT);
    }
    flag = _pygsl_bspline_eval_dep_yerr(self, x, OUT, OUT2);
    return flag;
  }

  PyObject*  eval_dep_yerr_vector(const gsl_vector * X){
    PyArrayObject *y_a = NULL, *yerr_a = NULL;
    double *y_d, *yerr_d, xt;
    PyGSL_array_index_t size, i;
    int flag;

    FUNC_MESS_BEGIN();
    if(self->coeffs_a == NULL || self->tmp_a == NULL || self->cov_a == NULL){
      PyGSL_ERROR_NULL("No coefficients of No covarince matrix set",
		GSL_EFAULT);
    }
    size = X->size;
    y_a = PyGSL_New_Array(1, &size, NPY_DOUBLE);
    if(y_a == NULL)
      goto fail;
    yerr_a = PyGSL_New_Array(1, &size, NPY_DOUBLE);
    if(yerr_a == NULL)
      goto fail;

    y_d = (double *) PyArray_DATA(y_a);
    yerr_d = (double *) PyArray_DATA(yerr_a);

    for(i = 0; i < size; ++i){
      xt = gsl_vector_get(X, i);
      flag = _pygsl_bspline_eval_dep_yerr(self, xt, &(y_d[i]), &(yerr_d[i]));
      if (flag != GSL_SUCCESS)
	goto fail;
    }
    return Py_BuildValue("(OO)", y_a, yerr_a);

  fail:
    Py_XDECREF(y_a);
    Py_XDECREF(yerr_a);
    return NULL;

  }

};


%init{
     swig_init_pygsl();
}
