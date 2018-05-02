/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * Date: April 2018
 */

/*
%module(threads="1") MyModule
%nothread;

%thread;
%include "MyExpensiveFunctions.h"
%nothread;
*/

%{
static PyObject *pygsl_sparse_matrix_module = NULL;
#include <limits.h>
#include <gsl/gsl_spmatrix.h>
#include <gsl/gsl_spblas.h>
#include <gsl/gsl_splinalg.h>
#include <pygsl/utils.h>
#include <pygsl/errorno.h>
#include <pygsl/error_helpers.h>
/* working around name clashes ... */
struct _pygsl_spmatrix{
  gsl_spmatrix *mat;
};

typedef struct _pygsl_spmatrix pygsl_spmatrix;

/* static pygsl_spmatrix* pygsl_spmatrix_alloc_helper(void); */
static pygsl_spmatrix* pygsl_spmatrix_alloc_helper(void)
{
  pygsl_spmatrix * obj = NULL;
  int line;

  FUNC_MESS_BEGIN();
  obj = (pygsl_spmatrix *) calloc(1, sizeof(pygsl_spmatrix));
  if(obj == NULL){
    line = __LINE__ - 2;
    gsl_error("Failed to allocate space for pygsl_spmatrix",
	      __FILE__, line, GSL_ENOMEM);
    FUNC_MESS_FAILED();
    return NULL;
  }
  obj->mat = NULL;

  FUNC_MESS_END();
  return obj;
}

static pygsl_spmatrix *pygsl_spmatrix_convert(const pygsl_spmatrix *src,
					      gsl_spmatrix *(*func)(const gsl_spmatrix *) )
{
    pygsl_spmatrix * obj = NULL;
    int line = __LINE__, status = PyGSL_ANY;

    FUNC_MESS_BEGIN();
    obj = pygsl_spmatrix_alloc_helper();
    if(obj == NULL){
      line = __LINE__ - 2;
      goto fail;
    }

    //obj->mat = gsl_spmatrix_ccs(src->mat);
    obj->mat = func(src->mat);
    if(obj->mat == NULL){
      line = __LINE__ - 2;
      goto fail;
    }
    FUNC_MESS_END();
    return obj;

  fail:
    FUNC_MESS_FAILED();
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    PyGSL_error_flag(status);
    return NULL;
 }


static void pygsl_spmatrix_free_helper(pygsl_spmatrix *self)
{

   if(self == NULL){
     return;
   }

    if(self->mat){
      gsl_spmatrix_free(self->mat);
      self->mat = NULL;
    }

    free(self);
}


static pygsl_spmatrix*
pygsl_spmatrix_memcpy_helper(const pygsl_spmatrix *self,
			     int(*func)(gsl_spmatrix *, const gsl_spmatrix *) )
{
    pygsl_spmatrix * dst = NULL;
    int line = __LINE__, status = PyGSL_ANY;
    size_t nnz = 0, size1, size2;

    FUNC_MESS_BEGIN();
    dst = pygsl_spmatrix_alloc_helper();
    if(dst == NULL){
      line = __LINE__ - 2;
      goto fail;
    }

    dst->mat = NULL;

    if(self->mat == NULL){
      line = __LINE__ - 2;
      gsl_error("self->mat was NULL", __FILE__, line, GSL_ESANITY);
      goto fail;
    }

    {
      const gsl_spmatrix *mat = self->mat;
      nnz = gsl_spmatrix_nnz(mat);

      if (func == gsl_spmatrix_transpose_memcpy){
	size1 = mat->size2;
	size2 = mat->size1;
      }else{
	size1 = mat->size1;
	size2 = mat->size2;
      }
      dst->mat = gsl_spmatrix_alloc_nzmax(size1, size2, nnz, mat->sptype);
      if(dst->mat == NULL){
	line = __LINE__ - 2;
	goto fail;
      }
      status = func(dst->mat, mat);
      if(status != GSL_SUCCESS){
	line = __LINE__ - 2;
	goto fail;
      }
    }
    FUNC_MESS_END();
    return dst;

  fail:
    FUNC_MESS_FAILED();
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    PyGSL_error_flag(status);
    pygsl_spmatrix_free_helper(dst);
    return NULL;
}


%}

%init{
  init_pygsl();
  pygsl_sparse_matrix_module = m;
}

%include attribute.i
%include gsl_error_typemap.i
%include file_typemaps.i
%include gsl_block_typemaps.i
%include typemaps.i

%define MODULEDOCSTRING
"""Wrapper for sparse matrix, sparse blas and sparse linalg functions.

Users should rather use

    * :py:mod:`pygsl.sparse.matrix`
    * :py:mod:`pygsl.sparse.blas`
    * :py:mod:`pygsl.sparse.linalg`

"""
%enddef

%feature ("autodoc", "3");
%module(docstring=MODULEDOCSTRING) sparse_wrapper;

%{
const int TRIPLET = GSL_SPMATRIX_TRIPLET;
const int CCS = GSL_SPMATRIX_CCS;
const int CRS = GSL_SPMATRIX_CRS;
%}

const int TRIPLET;
const int CCS;
const int CRS;

/* name clashes */
typedef struct{
}pygsl_spmatrix;

static pygsl_spmatrix* pygsl_spmatrix_alloc_helper(void);

%rename(sparse_matrix) pygsl_spmatrix;

%newobject pygsl_spmatrix::crs;
%newobject pygsl_spmatrix::ccs;
%newobject pygsl_spmatrix::memcpy;
%newobject pygsl_spmatrix::transpose_memcpy;


// XXX: requires to be fixed
%feature("python:compare", "Py_EQ") pygsl_spmatrix_equal;

//%feature("python:slot", "nb_inplace_multiply", functype="hashfunc") MyClass::myHashFunc;
// Allows defining attribute without macros
%extend pygsl_spmatrix{
  %immutable;
  PyObject * shape;
}
%{
  static PyObject * pygsl_spmatrix_shape_get(pygsl_spmatrix *self){
    return pygsl_spmatrix_get_shape(self);
  }
%}

%extend pygsl_spmatrix {
  pygsl_spmatrix(const size_t n1, const size_t n2,
		 /*const size_t nzmax = -1, const size_t flags = -1*/
		 const unsigned long nzmax = ULONG_MAX, const unsigned long flags = ULONG_MAX
		 ){
    pygsl_spmatrix *obj = NULL;

    int line = __LINE__,  status = PyGSL_ANY;

    FUNC_MESS_BEGIN();

    obj = pygsl_spmatrix_alloc_helper();
    if(obj == NULL){
	line = __LINE__ - 2;
	status =  GSL_ENOMEM;
	goto fail;
    }
    DEBUG_MESS(2, "Allocated pygsl_spmatrix object @ %p", (void *) obj);

    if (nzmax == ULONG_MAX){
      if (flags != ULONG_MAX){
	line = __LINE__ - 1;
	status =  GSL_EINVAL;
	DEBUG_MESS(2, "nzmax = %lu flags = %lu",
		   (unsigned long) nzmax, (unsigned long) flags);
	gsl_error("If nzmax is not defined, flags must not be defined neither",
		  __FILE__, line, status);
	goto fail;
      }
      obj->mat = gsl_spmatrix_alloc(n1, n2);
    } else {
      switch(flags){
	/* known flags */
      case GSL_SPMATRIX_TRIPLET:
      case GSL_SPMATRIX_CCS:
      case GSL_SPMATRIX_CRS:
	break;

      default:
	/* unknown do not trigger error in _alloc_nzmax */
	{
	  char msg[256];
	  line = __LINE__ - 8;
	  status =  GSL_EINVAL;
	  snprintf(msg, 254, "flag %lu specifiying type is not known%c", flags, '\0');
	  msg[255] = 0;
	  gsl_error(msg,  __FILE__, line, status);
	  goto fail;
	}
      }
      DEBUG_MESS(2, "Generating sparse matrix with n1 = %lu n2 = %lu, nzmax = %lu, flags = %lu",
		 (unsigned long) n1, (unsigned long) n2, nzmax, flags);
      obj->mat = gsl_spmatrix_alloc_nzmax(n1, n2, nzmax, flags);
    }
    if(obj->mat == NULL){
      line = __LINE__ -1;
      status = PyGSL_ANY;
      goto fail;
    }
    FUNC_MESS_END();
    return obj;

  fail:
    FUNC_MESS_FAILED();
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    PyGSL_error_flag(status);
    return NULL;
  }

  ~pygsl_spmatrix(void){
    pygsl_spmatrix_free_helper(self);
  }

  gsl_error_flag_drop  realloc(const size_t nzmax){
    return gsl_spmatrix_realloc(nzmax, self->mat);
  }

  double get(const size_t i, const size_t j){
    return gsl_spmatrix_get(self->mat, i, j);
  }


  PyObject * get_shape(void) {
    PyObject * obj = NULL, *size1 = NULL, *size2 = NULL;
    int line = __LINE__, status = PyGSL_ANY;

    FUNC_MESS_BEGIN();
    size1 =  PyLong_FromSize_t(self->mat->size1);
    if(size1 == NULL){
      line = __LINE__ -2;
      goto fail;
    }
    size2 =  PyLong_FromSize_t(self->mat->size2);
    if(size2 == NULL){
      line = __LINE__ -2;
      goto fail;
    }

    obj = PyTuple_New(2);
    if(obj == NULL){
      line = __LINE__ -2;
      goto fail;
    }

    PyTuple_SET_ITEM(obj, 0, size1);
    PyTuple_SET_ITEM(obj, 1, size2);

    FUNC_MESS_END();
    return obj;

  fail:
    FUNC_MESS_FAILED();
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    PyGSL_error_flag(status);
    Py_XDECREF(size1);
    Py_XDECREF(size2);
    return NULL;

  }

  PyObject*
    get_val_or_none(const size_t i, const size_t j)
  {
    double * ptr = NULL;
    PyObject * obj = NULL;

    FUNC_MESS_BEGIN();
    ptr =  gsl_spmatrix_ptr(self->mat, i, j);
    if(ptr){
      obj = PyFloat_FromDouble(*ptr);
    } else {
      obj = Py_None;
      Py_INCREF(obj);
    }
    FUNC_MESS_END();
    return obj;
}

gsl_error_flag_drop set(const size_t i, const size_t j, const double x){
  return gsl_spmatrix_set(self->mat, i, j, x);
}

  int type_code(void){
    return self->mat->sptype;
  }
#if 0
  gsl_error_flag_drop set_from_object(PyObject * indices, PyObject * data){
    Py_buffer buffer;
    int status = GSL_EFAILED, line = __LINE__, flag, is_buf_set = 0, t_dim = 0;
    FUNC_MESS_BEGIN();

    if(PyObject_CheckBuffer(obj) == 0){
      char msg[256];

      line = __LINE__ - 3;
      status = GSL_EINVAL;
      snprintf(msg, 254, "object @ %p does not support buffer protocol %c",
	       (void *) obj, '\0');
      msg[255] = 0;
      gsl_error(msg, __FILE__, __LINE__, status);
      goto fail;
    }

    memset(&buffer, 0, sizeof(Py_buffer));
    flag = PyObject_GetBuffer(obj, &buffer, PyBUF_INDIRECT);
    switch(flag){
    case 0:
      /* success */
      is_buf_set = 1;
    default:
      line = __LINE__ - 6;
      status = PyGSL_ANY;
      goto fail;
    }

    DEBUG_MESS(2, "Buffer @ %p: len = %ld readonly = %d itemsize = %ld, format = %s, ndim = %d",
	       &buffer, (long) buffer.len, buffer.readonly, (long) buffer.itemsize,
	       buffer.format,  buffer.ndim);

    for(t_dim = 0; t_dim < buffer.ndim; ++t_dim){
      DEBUG_MESS(2, "Buffer @ %p: dim %d shape %ld stride %ld suboffsets %ld",
		 &buffer,
		 (long) buffer.shape[t_dim], (long) buffer.strides[t_dim],
		 (long) buffer.suboffsets[t_dim]);
    }

    PyBuffer_Release(&buffer);
    FUNC_MESS_END();
    return GSL_SUCCESS;

  fail:
    FUNC_MESS_FAILED();
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    if(is_buf_set){
      PyBuffer_Release(&buffer);
    }
    PyGSL_error_flag(status);
    return status;
  }
#endif

  gsl_error_flag_drop set_from_triplet(PyObject * i_o, PyObject * d_o){

    PyArrayObject *indices = NULL, * data = NULL;
    PyGSL_array_index_t stride_v, stride_m0=0, stride_m1=0, dim=0, elem, i, j;
    double datum;
    char *cptr = NULL, *idx_data = NULL, *data_data = NULL;
    int status = GSL_EFAILED, line = __LINE__;

    FUNC_MESS_BEGIN();
    indices = PyGSL_matrix_check(i_o,  -1, 2,
				 PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, NPY_LONGLONG, sizeof(long), 1),
				 NULL, NULL, NULL);
    if(indices == NULL){
      line = __LINE__ - 5;
      goto fail;
    }
    dim = PyArray_DIM(indices, 0);

    data = PyGSL_vector_check(d_o, dim, PyGSL_DARRAY_INPUT(2), NULL, NULL);
    if(data == NULL){
      line = __LINE__ - 2;
      goto fail;
    }

    idx_data = PyArray_DATA(indices);
    data_data = PyArray_DATA(data);

    stride_m0 = PyArray_STRIDE(indices, 0);
    stride_m1 = PyArray_STRIDE(indices, 1);

    stride_v = PyArray_STRIDE(data, 0);


    for(elem = 0; elem < dim; ++elem){
      cptr = idx_data + stride_m0 * elem + stride_m1 * 0;
      i = *((long long *) cptr);

      cptr = idx_data + stride_m0 * elem + stride_m1 * 1;
      j = *((long long *) cptr);

      cptr = data_data + stride_v * elem;
      datum = *((double *) cptr);

      status = gsl_spmatrix_set(self->mat, i, j, datum);
      if(status != GSL_SUCCESS){
	line = __LINE__ - 2;
	goto fail;
      }
    }
    FUNC_MESS_END();
    return GSL_SUCCESS;

  fail:
    FUNC_MESS_FAILED();
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    Py_XDECREF(indices);
    Py_XDECREF(data);
    return status;
  }

  gsl_error_flag_drop set_zero(void){
    return gsl_spmatrix_set_zero(self->mat);
  }

  gsl_error_flag_drop fwrite(FILE * stream){
    return gsl_spmatrix_fwrite(stream, self->mat);
  }

  gsl_error_flag_drop fread(FILE * stream){
    return gsl_spmatrix_fread(stream, self->mat);
  }

  gsl_error_flag_drop fprintf(FILE * stream, const char * format){
    return gsl_spmatrix_fprintf(stream, self->mat, format);
  }

  gsl_error_flag_drop gsl_transpose_inplace(void){
    return gsl_spmatrix_transpose(self->mat);
  }

  gsl_error_flag_drop gsl_transpose2_inplace(void){
    return gsl_spmatrix_transpose2(self->mat);
  }

  gsl_error_flag_drop transpose_inplace(void){
    if(GSL_SPMATRIX_ISTRIPLET(self->mat)){
      return gsl_spmatrix_transpose(self->mat);
    } else {
      return gsl_spmatrix_transpose2(self->mat);
    }
  }

  pygsl_spmatrix * memcpy(void){
    return pygsl_spmatrix_memcpy_helper(self, gsl_spmatrix_memcpy);
  }

  pygsl_spmatrix * transpose_memcpy(void){
    return pygsl_spmatrix_memcpy_helper(self, gsl_spmatrix_transpose_memcpy);
  }

  size_t nnz(void){
    return gsl_spmatrix_nnz(self->mat);
  }

  int equal(pygsl_spmatrix * other){
    return gsl_spmatrix_equal(self->mat, other->mat);
  }

  //XXX : fix auto doc
  %apply double *OUTPUT { double *min_out, double *max_out };
  gsl_error_flag_drop minmax(double * min_out, double * max_out){
    return gsl_spmatrix_minmax(self->mat, min_out, max_out);
  }

  gsl_error_flag_drop scale(const double x){
    return gsl_spmatrix_scale(self->mat, x);
  }

  pygsl_spmatrix * ccs(void){
    pygsl_spmatrix * obj = NULL;

    obj =  pygsl_spmatrix_convert(self, gsl_spmatrix_ccs);
    return obj;
  }

  pygsl_spmatrix * crs(void){
    pygsl_spmatrix * obj = NULL;

    obj =  pygsl_spmatrix_convert(self, gsl_spmatrix_crs);
    return obj;
  }

  gsl_error_flag_drop  d2sp(const gsl_matrix * A){
    return gsl_spmatrix_d2sp(self->mat, A);
  }

  /* create the required result array */
  PyObject * sp2d(void) {
    PyArrayObject * a_array = NULL;
    gsl_matrix_view matrix;
    gsl_matrix *A = NULL;
    PyGSL_array_index_t dim[2], tmp;
    size_t size1 = 0, size2 = 0;
    int line = __LINE__, status = PyGSL_ANY;

    FUNC_MESS_BEGIN();

    size1 = self->mat->size1;
    size2 = self->mat->size2;

    dim[0] = size1;
    dim[1] = size2;
    DEBUG_MESS(2, "Creating a dense matrix (np.array) with dimensions shape=(%ld,%ld)",
	       (long) dim[0], (long) dim[1]);
    a_array = PyGSL_New_Array(2, dim, NPY_DOUBLE);
    if(a_array == NULL){
      line = __LINE__ - 2;
      goto fail;
    }

    status = PyGSL_STRIDE_RECALC(PyArray_STRIDE(a_array, 0), sizeof(double), &tmp);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }
    status = PyGSL_STRIDE_RECALC(PyArray_STRIDE(a_array, 1), sizeof(double), &tmp);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }
    DEBUG_MESS(2, "Creating view from dense (np.array) "
	       "np_array shape = (%ld,%ld) "
	       "gsl_mat  shape = (%lu,%lu)",
	       (long) dim[0], (long) dim[1], (unsigned long) size1, (unsigned long) size2);
    matrix = gsl_matrix_view_array(PyArray_DATA(a_array), size1, size2);

    status = gsl_spmatrix_sp2d(&matrix.matrix, self->mat);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }

    return (PyObject *) a_array;
    FUNC_MESS_END();

  fail:
    FUNC_MESS("FAIL");
    PyGSL_add_traceback(pygsl_sparse_matrix_module, __FILE__, __FUNCTION__, line);
    PyGSL_error_flag(status);

    return NULL;
  }

}; /* %extend pygsl_spmatrix */

%{
  static int
    pygsl_spmatrix_add(pygsl_spmatrix * c, const pygsl_spmatrix * a, const pygsl_spmatrix * b)
  {
    return gsl_spmatrix_add(c->mat, a->mat, b->mat);
  }

  /*
  static int
    pygsl_spmatrix_equal(const pygsl_spmatrix *a, const pygsl_spmatrix *b)
  {
    return gsl_spmatrix_equal(a->mat, b->mat);
  }
  */

%}

gsl_error_flag_drop
pygsl_spmatrix_add(pygsl_spmatrix * c, const pygsl_spmatrix * a, const pygsl_spmatrix * b);

/* int pygsl_spmatrix_equal(const pygsl_spmatrix *a, const pygsl_spmatrix *b); */

/*
 * XXX: inform swig that this is a new object
 */
%{
static pygsl_spmatrix * pygsl_spmatrix_fscanf(FILE * stream){
  pygsl_spmatrix* obj = NULL;
  int line, status = PyGSL_ANY;

  FUNC_MESS_BEGIN();
  obj = pygsl_spmatrix_alloc_helper();
  if(obj == NULL){
    line = __LINE__ - 2;
    goto fail;
  }

  obj->mat = gsl_spmatrix_fscanf(stream);
  if(obj->mat == NULL){
    line = __LINE__ - 2;
    goto fail;
  }
  FUNC_MESS_END();

 fail:
  FUNC_MESS_FAILED();
  PyGSL_error_flag(status);
  pygsl_spmatrix_free_helper(obj);
  return NULL;
}
%}
static pygsl_spmatrix * pygsl_spmatrix_fscanf(FILE * stream);

/* blas part */
%{
static PyObject *
  pygsl_spblas_dgemv(const CBLAS_TRANSPOSE_t TransA, const double alpha, const pygsl_spmatrix * A, const gsl_vector * x, const double beta, PyObject *y)
{
  PyArrayObject * y_a = NULL;
  gsl_vector_view y_v;
  PyGSL_array_index_t dim = 0, tmp=0;
  int line, status = PyGSL_ANY;

  FUNC_MESS_BEGIN();
  y_a = PyGSL_Copy_Array(y);
  if(y_a == NULL){
    line = __LINE__ -2;
    status = GSL_ENOMEM;
    goto fail;
  }
  /* XXX
   * Check array dimensions!
   */
  //Py_DECREF(y);
  status = PyGSL_STRIDE_RECALC(PyArray_STRIDE(y_a, 0), sizeof(double), &tmp);
  if(status != GSL_SUCCESS){
    line = __LINE__ -2;
    goto fail;
  }
  y_v = gsl_vector_view_array_with_stride(PyArray_DATA(y_a), tmp, PyArray_DIM(y_a, 0));

  NPY_BEGIN_ALLOW_THREADS
  status = gsl_spblas_dgemv(TransA, alpha, A->mat, x, beta, &y_v.vector);
  NPY_END_ALLOW_THREADS

  if(status != GSL_SUCCESS){
    line = __LINE__ -2;
    goto fail;
  }
  FUNC_MESS_END();
  return (PyObject *) y_a;

 fail:
  FUNC_MESS_FAILED();
  Py_XDECREF(y_a);
  PyGSL_error_flag(status);
  return NULL;
}

int
pygsl_spblas_dgemm(const double alpha, const pygsl_spmatrix * A, const pygsl_spmatrix * B, pygsl_spmatrix * C)
{
  int status;

  NPY_BEGIN_ALLOW_THREADS
  status = gsl_spblas_dgemm(alpha, A->mat, B->mat, C->mat);
  NPY_END_ALLOW_THREADS
    return status;
}

%}

%{
static PyObject *
pygsl_splinalg_itersolve_iterate(const pygsl_spmatrix * A, const gsl_vector * b, const double tol, PyObject * x_o,  gsl_splinalg_itersolve *w)
{

  PyArrayObject * x_a = NULL, *x_in = NULL;
  gsl_vector_view x_v;
  PyGSL_array_index_t dim = 0, stride = 0;
  int line, status = PyGSL_ANY;

  FUNC_MESS_BEGIN();

  dim = b->size;
  x_in = PyGSL_vector_check(x_o, dim, PyGSL_DARRAY_INPUT(5), &stride, NULL);
  if(x_in == NULL){
    line = __LINE__ -2;
    status = GSL_ENOMEM;
    goto fail;
  }
  x_a =  PyGSL_Copy_Array(x_in);
  if(x_a == NULL){
    line = __LINE__ -2;
    status = GSL_ENOMEM;
    goto fail;
  }
  Py_DECREF(x_in);
  x_in = NULL;

  DEBUG_MESS(2, "Created array x_a @ %p shape =(%ld,), stride = (%ld,)",
	     (void *) x_a, (long)PyArray_DIM(x_a, 0), (long)PyArray_STRIDE(x_a, 0));

  x_v = gsl_vector_view_array_with_stride(PyArray_DATA(x_a), stride, PyArray_DIM(x_a, 0));
  DEBUG_MESS(2, "x vector view: vector @%p size %lu dim = %ld stride %lu set %ld",
	     (void *)&x_v.vector, (unsigned long)  x_v.vector.size, (long) dim,
	     (unsigned long) x_v.vector.stride, (long) stride);

  NPY_BEGIN_ALLOW_THREADS
  status = gsl_splinalg_itersolve_iterate(A->mat, b, tol, &x_v.vector, w);
  NPY_END_ALLOW_THREADS

  line = __LINE__ -1;
  switch(status){
  case GSL_SUCCESS:
  case GSL_CONTINUE:
    break;

  default:
    goto fail;
  }
  FUNC_MESS_END();
  return (PyObject *) Py_BuildValue("iO", status, (PyObject *) x_a);

 fail:
  FUNC_MESS_FAILED();
  Py_XDECREF(x_a);
  Py_XDECREF(x_in);
  PyGSL_error_flag(status);
  return NULL;
}
%}
gsl_error_flag_drop
pygsl_spblas_dgemm(const double alpha, const pygsl_spmatrix * A, const pygsl_spmatrix * B, pygsl_spmatrix * C);
PyObject *
pygsl_spblas_dgemv(const int TransA, const double alpha, const pygsl_spmatrix * A, const gsl_vector * x, const double beta, PyObject *y);

/* lapack */
typedef struct{
}gsl_splinalg_itersolve;


%extend gsl_splinalg_itersolve{
  %immutable;
  const char * name;
};
%{
  static const char * gsl_splinalg_itersolve_name_get(gsl_splinalg_itersolve *self) {
    return gsl_splinalg_itersolve_get_name(self);
  }
%}

%extend gsl_splinalg_itersolve{
  gsl_splinalg_itersolve(const gsl_splinalg_itersolve_type * T, const size_t n, const size_t m){
    gsl_splinalg_itersolve *obj = NULL;
    obj = gsl_splinalg_itersolve_alloc(T, n, m);
    return obj;
  }

  ~gsl_splinalg_itersolve(void){
    gsl_splinalg_itersolve_free(self);
  }

  %rename(name) t_name;
  const char * get_name(void){
    return gsl_splinalg_itersolve_name(self);
  }

  %rename(iterate) t_iterate;
  %apply double *OUTPUT { double *min_out, double *max_out };
  PyObject *
    t_iterate(const pygsl_spmatrix * A, const gsl_vector * b, const double tol, PyObject * x){
    return pygsl_splinalg_itersolve_iterate(A, b, tol, x, self);
  }

  %rename(normr) t_normr;
  double t_normr(void){
    return gsl_splinalg_itersolve_normr(self);
  }
}

%immutable;
extern const gsl_splinalg_itersolve_type *gsl_splinalg_itersolve_gmres;
