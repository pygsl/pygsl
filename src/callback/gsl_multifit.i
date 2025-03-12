/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * Date: 2025
 */

/*
 * The gsl_multifit_linear_workspace structre was changed from GSL 1.X to
 * GSL 2.X.
 * setup checks for that and then appropriate measures are taken
 */

%include pygsl_compat.i
%{
#include <gsl/gsl_multifit.h>
#include <gsl/gsl_fit.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include "pygsl_multifit_config.h"
// #include <pygsl/pygsl_features.h>

#define  _PyGSL_TO_ARRAY_INDEX_CAST(arg) ((PyGSL_array_index_t) (arg))
#if PYGSL_GSL_MAJOR_VERSION == 2
#if PYGSL_GSL_MINOR_VERSION == 0
#error GSL 2.0 implementation of multifit has a bug in multifit_wliner
#endif /* PYGSL_GSL_MINOR_VERSION == 0 */
#endif /* PYGSL_GSL_MAJOR_VERSION == 2 */
#define _PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX
#ifdef _PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX
#define _PyGSL_MULTIFIT_GET_NMAX(s) _PyGSL_TO_ARRAY_INDEX_CAST((s->nmax))
#define _PyGSL_MULTIFIT_GET_PMAX(s) _PyGSL_TO_ARRAY_INDEX_CAST((s->pmax))
  /* fix a bug in multifit_wlinear ... */
#define _PyGSL_MULTIFIT_WORKSPACE_SET(s) s->n = s->nmax; (s->p = s->pmax);
#else /*  _PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX */
#ifndef _PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P
#error "I expected that if nmax and pmax is not found that n and p are always"
#error "found"
#endif /* _PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P */
#define _PyGSL_MULTIFIT_WORKSPACE_SET(s)
#define _PyGSL_MULTIFIT_GET_NMAX(s) _PyGSL_TO_ARRAY_INDEX_CAST((s->n))
#define _PyGSL_MULTIFIT_GET_PMAX(s) _PyGSL_TO_ARRAY_INDEX_CAST((s->p))
#endif /* _PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX */
%}
%include typemaps.i
%include gsl_block_typemaps.i

%typemap(arginit) const gsl_matrix *  IN_AND_SIZE %{
	  PyArrayObject * _PyMatrix$argnum = NULL;
	  TYPE_VIEW_$1_basetype _matrix$argnum;
	  PyGSL_array_index_t _mat_dim0_arg$argnum = -1;
	  PyGSL_array_index_t _mat_dim1_arg$argnum = -1;

%}
%typemap(check) const gsl_matrix *  IN_AND_SIZE  %{
          assert(_PyMatrix$argnum != NULL);
          _mat_dim0_arg$argnum =  PyArray_DIM(_PyMatrix$argnum, 0);
          _mat_dim1_arg$argnum =  PyArray_DIM(_PyMatrix$argnum, 1);
%}

%typemap(in)      gsl_matrix * IN_AND_SIZE  = gsl_matrix * IN;
%typemap(freearg) gsl_matrix * IN_AND_SIZE  = gsl_matrix * IN;


gsl_multifit_linear_workspace *
gsl_multifit_linear_alloc (size_t n, size_t p);

void
gsl_multifit_linear_free (gsl_multifit_linear_workspace * work);

%typemap(arginit) gsl_multifit_linear_workspace * work_provide %{
     PyGSL_array_index_t _work_provide_n_$1_name = -1;
     PyGSL_array_index_t _work_provide_p_$1_name = -1;
%}

%typemap( in) gsl_multifit_linear_workspace *  work_provide {
     if ((SWIG_ConvertPtr($input, (void **) &$1, SWIGTYPE_p_gsl_multifit_linear_workspace,1)) == -1){
	  goto fail;
     }
     _work_provide_n_$1_name = _PyGSL_MULTIFIT_GET_NMAX($1);
     _work_provide_p_$1_name = _PyGSL_MULTIFIT_GET_PMAX($1);
     _PyGSL_MULTIFIT_WORKSPACE_SET($1);
    DEBUG_MESS(2, "work->n  = %ld work ->p = %ld",
	       (long) _work_provide_n_$1_name, (long) _work_provide_p_$1_name);
     /*
    DEBUG_MESS(2, "work->n  = %ld work ->p = %ld work->nmax = %ld, work->pmax = %ld",
		(long) _work_provide_n_$1_name, (long) _work_provide_p_$1_name,
		(long) $1->nmax, (long) $1->pmax);
     */
};

%typemap( in, numinputs = 0) gsl_vector * OUT %{
     /* All done in check as the workspace stores the information about the required size */
%}

%typemap(check) gsl_vector * OUT {
          PyGSL_array_index_t stride, lvec;
	  lvec = _work_provide_p_work_provide;
	  lvec = _mat_dim1_arg1;

	  DEBUG_MESS(2, "out vector length = %ld not %ld", (long) lvec, (long) _work_provide_p_work_provide);
	  _PyVector$argnum = (PyArrayObject *) PyGSL_New_Array(1, &lvec, NPY_DOUBLE);
          if(NULL == _PyVector$argnum){
               goto fail;
          }

	  if(PyGSL_STRIDE_RECALC(PyArray_STRIDE(_PyVector$argnum, 0), sizeof(BASIS_TYPE($1_basetype)), &stride) != GSL_SUCCESS)
	       goto fail;

          _vector$argnum  = TYPE_VIEW_ARRAY_STRIDES_$1_basetype((BASIS_C_TYPE($1_basetype) *) PyArray_DATA(_PyVector$argnum),
                                                                stride,
                                                                PyArray_DIM(_PyVector$argnum, 0));
          $1 = ($basetype *) &(_vector$argnum.vector);

}
%typemap( in) gsl_matrix * OUT = gsl_vector * OUT;
%typemap(check) gsl_matrix * OUT {
	  PyArrayObject * a_array;
	  BASIS_C_TYPE($1_basetype)  *data = NULL;
	  PyGSL_array_index_t stride_recalc=0, dimensions[2];


	  dimensions[0] = _mat_dim1_arg1;
	  dimensions[1] = _mat_dim1_arg1;
	  a_array = (PyArrayObject *) PyGSL_New_Array(2, dimensions, NPY_DOUBLE);
	  if(NULL == a_array){
	       goto fail;
	  }
	  _PyMatrix$argnum = a_array;


	  if(PyGSL_STRIDE_RECALC(PyArray_STRIDE(a_array, 0), sizeof(BASIS_TYPE($1_basetype)), &stride_recalc) != GSL_SUCCESS)
	       goto fail;
	  /* (BASIS_TYPE_$1_basetype *) */
	  data = (BASIS_C_TYPE($1_basetype)  *) PyArray_DATA(a_array);
	  assert(data != NULL);
	  _matrix$argnum  = TYPE_VIEW_ARRAY_$1_basetype(data, PyArray_DIM(a_array,0), PyArray_DIM(a_array, 1));
	  assert(_matrix$argnum.matrix.data != NULL);
	  $1 = ($basetype *) &(_matrix$argnum.matrix);
	  DEBUG_MESS(2, "matrix: data %p size = [%ld, %ld]", (void *) _matrix$argnum.matrix.data,
		     (long) _matrix$argnum.matrix.size1,
		     (long) _matrix$argnum.matrix.size2
		     );

}
%typemap(argout) gsl_vector * OUT{
     $result = PyGSL_SWIG_Python_AppendOutput($result,  (PyObject *) _PyVector$argnum);
     _PyVector$argnum =NULL;
};
%typemap(argout) gsl_matrix * OUT{
     $result = PyGSL_SWIG_Python_AppendOutput($result,  (PyObject *) _PyMatrix$argnum);
     _PyMatrix$argnum =NULL;
};

/* ---------------------------------------------------------------------- */
/*
 *  A typemap for translating numpy arrays to the least squares
 *  representation.
 *
 * The length of vector x establishes the reference. All others check
 * their length to this vector. So if you apply this typemap it will
 * fail if no variable was named x!!!
 *
 *
 */

%typemap(arginit) (double *, size_t ) %{
     PyArrayObject *_PyVector$argnum = NULL;
     size_t         _PyVectorLength$1_name   = 0;
%}

%typemap(in)  (double * ,  size_t ){
     PyGSL_array_index_t strides, size;
     /* This should be a preprocessor directive. */
     if ( '$1_name' == 'x' )
	  size = -1;
     else
	  size = _PyVectorLengthx;
     _PyVector$argnum = PyGSL_vector_check($input, size, PyGSL_DARRAY_INPUT($argnum), &strides, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;

     $1 = (double *) PyArray_DATA(_PyVector$argnum);
     $2 = (size_t) strides;
     _PyVectorLength$1_name = (size_t) PyArray_DIM(_PyVector$argnum, 0);
};
%typemap(argout) (double *, size_t ) {
     Py_XDECREF(_PyVector$argnum);
};

%typemap( in, numinputs=0) const size_t n {
     $1 = 0;
};

%typemap(check) const size_t n {
     $1 = _PyVectorLengthx;
};

%apply double * OUTPUT {double * c0,
                       double * c1,
		       double * cov00,
                       double * cov01,
                       double * cov11,
		       double * sumsq,
		       double * chisq,
		       double * Y,
		       double * Y_ERR};

gsl_error_flag_drop
gsl_multifit_linear (const gsl_matrix * IN_AND_SIZE,
                     const gsl_vector * IN,
                     gsl_vector * OUT,
                     gsl_matrix * OUT,
                     double * chisq,
                     gsl_multifit_linear_workspace * work_provide);

#if 0
#if PyGSL_GSL_MAJOR_VERSION >= 2
/* needs works space ... implement ... */
#error "Work space needs to be correctly implemented "
gsl_error_flag_drop
gsl_multifit_linear_svd (const gsl_matrix * IN,
			 gsl_multifit_linear_workspace * work_provide);
gsl_error_flag_drop
gsl_multifit_linear_bsvd (const gsl_matrix * IN,
			 gsl_multifit_linear_workspace * work_provide);
#else /* PyGSL_GSL_MAJOR_VERSION >= 2 */
gsl_error_flag_drop
gsl_multifit_linear_svd (const gsl_matrix * IN,
			 const gsl_vector * IN,
			 double TOL,
			 size_t * OUTPUT,
			 gsl_vector * OUT,
			 gsl_matrix * OUT2,
			 double * chisq,
			 gsl_multifit_linear_workspace * work_provide);
#endif /* PyGSL_GSL_MAJOR_VERSION >= 2 */
#endif

%apply gsl_vector *IN {gsl_vector *y};
%apply gsl_vector *IN {gsl_vector *w};
%apply gsl_vector *IN {gsl_vector *c};
%apply gsl_vector *IN {gsl_vector *r};
%apply gsl_matrix *IN {gsl_matrix *x};
%apply gsl_matrix *IN {gsl_matrix *cov};
gsl_error_flag_drop
gsl_multifit_wlinear (const gsl_matrix * IN_AND_SIZE,
                      const gsl_vector * w,
                      const gsl_vector * y,
                      gsl_vector * OUT,
                      gsl_matrix * OUT,
                      double * chisq,
                      gsl_multifit_linear_workspace * work_provide);


gsl_error_flag_drop
gsl_multifit_wlinear_svd (const gsl_matrix * IN_AND_SIZE,
                          const gsl_vector * w,
                          const gsl_vector * y,
			 double TOL,
			 size_t * OUTPUT,
                          gsl_vector * OUT,
                          gsl_matrix * OUT,
                          double * chisq,
                          gsl_multifit_linear_workspace * work_provide);

gsl_error_flag_drop
gsl_multifit_linear_est (const gsl_vector * x,
			 const gsl_vector * c,
			 const gsl_matrix * IN,
			 double * Y, double *Y_ERR);

/*
gsl_error_flag_drop
gsl_multifit_linear_residuals(const gsl_matrix * IN,
			      const gsl_vector * y,
			      const gsl_vector * c,
			      gsl_vector * r);

*/


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
	FUNC_MESS("Fail");
	Py_XDECREF(r_a);
	return NULL;
}
%}

%apply (double *, size_t){(const double * x, const size_t xstride),
			  (const double * y, const size_t ystride),
			  (const double * w, const size_t wstride)
			 };
/* ---------------------------------------------------------------------- */
gsl_error_flag_drop gsl_fit_linear (const double * x, const size_t xstride,
                    const double * y, const size_t ystride,
                    const size_t n,
                    double * c0, double * c1,
                    double * cov00, double * cov01, double * cov11,
                    double * sumsq);


gsl_error_flag_drop gsl_fit_wlinear (const double * x, const size_t xstride,
                     const double * w, const size_t wstride,
                     const double * y, const size_t ystride,
                     const size_t n,
                     double * c0, double * c1,
                     double * cov00, double * cov01, double * cov11,
                     double * chisq);

%apply double * OUTPUT {double * y,
			double * y_err}

gsl_error_flag_drop
gsl_fit_linear_est (const double x,
                    const double c0, const double c1,
                    const double c00, const double c01, const double c11,
                    double *y, double *y_err);


gsl_error_flag_drop gsl_fit_mul (const double * x, const size_t xstride,
                 const double * y, const size_t ystride,
                 const size_t n,
                 double * c1,
                 double * cov11,
                 double * sumsq);

gsl_error_flag_drop gsl_fit_wmul (const double * x, const size_t xstride,
                  const double * w, const size_t wstride,
                  const double * y, const size_t ystride,
                  const size_t n,
                  double * c1,
                  double * cov11,
                  double * sumsq);


gsl_error_flag_drop
gsl_fit_mul_est (const double x,
                 const double c1,
                 const double c11,
                 double *y, double *y_err);


/*
int gsl_fit_poly (const double * x,
                  const double * w,
                  const double * y,
                  size_t n,
                  double * c, size_t m,
                  double * chisq);

int gsl_fit_fns (const double * A,
                 const double * w,
                 const double * y,
                 size_t n,
                 double * c, size_t m,
                 double * chisq);

int gsl_fit_linear_nd (double * m, double * y, double * w);
*/
