/* -*- C -*- */
/*
 * Author : Pierre Schnizer
 * Date   : January 2003
 * 
 *  Changes for better error reporting from 
 *  17. 01. 2003
 *  Adding a info struct. This struct contains additional information used for 
 *  error Reporting.
 *
 *  Changed to support Numeric and nummarray.
 */

#define PyGSL_IMPORT_ARRAY 1
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <stdlib.h>
#include <stdio.h>
#include <pygsl/profile.h>
#include <pygsl/general_helpers.h>
#include <pygsl/utils.h>

static const char filename[] = __FILE__;

static int 
PyGSL_stride_recalc(int strides, int basic_type_size, int * stride_recalc)
{
     int line;

     FUNC_MESS_BEGIN();
     line = __LINE__ + 1;
     if((strides % basic_type_size) == 0) {
	  *stride_recalc = strides / basic_type_size; 
	  DEBUG_MESS(2, "\tRecalculated strides to %d", *stride_recalc);
	  FUNC_MESS_END();
	  return GSL_SUCCESS;
     }

     DEBUG_MESS(2, "Failed to convert stride. %d/%d != 0", 
		strides, basic_type_size);
     gsl_error("Can not convert the stride to a GSL stride", 
	       filename, __LINE__, PyGSL_ESTRIDE);
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);     
     return PyGSL_ESTRIDE;
}
/* ========================================================================= */
/*
 * Implementation of the above routines.
 */

static int
PyGSL_PyArray_Check(PyArrayObject *a_array, int array_type, int flag,  int nd,
		    long *dimensions, int argnum, PyGSL_error_info * info)
{

     int i;
     int error_flag = GSL_ESANITY, line = -1;

     if(!PyArray_Check((PyObject *) a_array)){
	  gsl_error("Did not recieve an array!", filename, __LINE__, GSL_ESANITY);
	  line = __LINE__ - 2;
	  error_flag =  GSL_ESANITY;
	  goto fail;
     }
     if(nd <  1 || nd > 2){	  
	  DEBUG_MESS(2, "Got an nd of %d", nd);          
	  line = __LINE__ - 2;
	  gsl_error("nd must either 1 or 2!", filename, __LINE__, GSL_ESANITY);
	  error_flag =  GSL_ESANITY;
	  goto fail;
     }

     if (a_array->nd !=  nd){
	  line = __LINE__ - 1;
	  sprintf(pygsl_error_str, "I could not convert argument number % 3d."
		  " I expected a %s, but got an array of % 3d dimensions!\n", argnum, 
		  (nd == 1) ? "vector" : "matrix", a_array->nd);

	  if (info){
	       info->error_description = pygsl_error_str;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       gsl_error(pygsl_error_str, filename, __LINE__, GSL_EBADLEN);
	  }
	  error_flag = GSL_EBADLEN;
	  goto fail;
     }
     

     
     for(i=0; i<nd; ++i){
	  if(dimensions[i] == -1 ){
	       switch(i){
	       case 0: DEBUG_MESS(2, "\t\t No one cares about its first dimension! %d", 0);  break;
	       case 1: DEBUG_MESS(2, "\t\t No one cares about its second dimension! %d", 0); break;
	       default: error_flag = GSL_ESANITY; line = __LINE__ - 3; goto fail; break;
	       }
	       continue;
	  } 
	  /* Check to be performed ... */
	  if( ((PyArrayObject *) (a_array))->dimensions[i] != (dimensions[i])){
	       sprintf(pygsl_error_str, "The size of argument % 3d did not match the expected size for the %d dimension." 
		       " I got % 3ld elements but expected % 3ld elements!\n", argnum, i, (long)a_array->dimensions[0], dimensions[0]);
	       if (info){
		    info->error_description = pygsl_error_str;
		    PyGSL_set_error_string_for_callback(info);
	       } else {
		    gsl_error(pygsl_error_str, filename, __LINE__, GSL_EBADLEN);
	       }	       
	       error_flag = GSL_EBADLEN;
	       line = __LINE__ - 11;
	       goto fail;
	  }
     }

     if(  ((PyArrayObject *) (a_array))->data == NULL){
	  gsl_error("Got an array object were the data was NULL!", filename, __LINE__, GSL_ESANITY);
	  error_flag = GSL_ESANITY;	  
	  line = __LINE__ - 4;
	  goto fail;
     }
     if(  ((PyArrayObject *) (a_array))->descr->type_num == (array_type) )
	  DEBUG_MESS(4, "\t\tArray type matched! %d", 0);
     else{
	  gsl_error("The array type did not match the spezified one!", filename, __LINE__, GSL_ESANITY);
	  error_flag = GSL_ESANITY;
	  line = __LINE__ - 6;
	  goto fail;
     }
     if ((flag &  PyGSL_CONTIGUOUS) == 0){
	  DEBUG_MESS(2, "\t\t Can deal with discontiguous arrays! %d", 0);
     } else {
	  if(!(((PyArrayObject *) (a_array))->flags & CONTIGUOUS )){
	       gsl_error("The array is not contingous as requested!", filename, __LINE__, GSL_ESANITY);
	       error_flag = GSL_ESANITY;
	       line = __LINE__ - 3;
	       goto fail;
	  }
     }
     return GSL_SUCCESS;    

 fail:
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);
     return error_flag;
}

static PyArrayObject * 
PyGSL_PyArray_generate_gsl_vector_view(PyObject *src,
				       int array_type,
				       int argnum)
{
     int dimension;
     PyObject *tmp;
     PyArrayObject *a_array = NULL;

     FUNC_MESS_BEGIN();
     tmp = PyNumber_Int(src);
     if(!tmp){
	  sprintf(pygsl_error_str, "I could not convert argument number % 3d. to an integer.",
		  argnum);
	 PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	 return NULL;
     }
     dimension = PyInt_AS_LONG(src);
     Py_DECREF(tmp);
     if(dimension <= 0){
	  sprintf(pygsl_error_str, "Argument number % 3d is % 10d< 0. Its the size of the vector and thus must be positive!",
		  argnum, dimension);
	 PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	 return NULL;
     }
     
     a_array = (PyArrayObject *) PyGSL_New_Array(1, &dimension, array_type);
     if(NULL == a_array){
	  return NULL;
     }
     FUNC_MESS_END();
     return a_array;
}

static PyArrayObject * 
PyGSL_PyArray_generate_gsl_matrix_view(PyObject *src,
				      int array_type,
				      int argnum)
{
     PyObject *tmp;
     PyArrayObject *a_array = NULL;

     int dimensions[2], i;

     FUNC_MESS_BEGIN();     
     if(!PySequence_Check(src) || PySequence_Size(src) != 2){
	  sprintf(pygsl_error_str, "I need a sequence of two elements as argument number % 3d",
		  argnum);
	 PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	 return NULL;

     }

     for(i = 0; i<2; i++){
	  tmp = PyNumber_Int(PySequence_GetItem(src, i));
	  if(!tmp){
	       sprintf(pygsl_error_str, "I could not convert argument number % 3d. for dimension %3d to an integer.",
		       argnum, i);
	       PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	       return NULL;
	  }
	  dimensions[i] = PyInt_AS_LONG(tmp);
	  Py_DECREF(tmp);
	  if(dimensions[i] <= 0){
	       sprintf(pygsl_error_str, "Argument number % 3d is % 10d< 0. Its the size of the vector and thus must be positive!",
		       argnum, dimensions[i]);
	       PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	       return NULL;
	  }

     }     
     a_array = (PyArrayObject *) PyGSL_New_Array(2, dimensions, array_type);
     if(NULL == a_array){
	  return NULL;
     }
     return a_array;
}

static PyArrayObject *
PyGSL_copy_gslvector_to_pyarray(const gsl_vector *x)
{     
     int dimension = -1, i;
     PyArrayObject *a_array = NULL;
     double tmp;

     FUNC_MESS_BEGIN();
     dimension = x->size;
     a_array = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
     if (a_array == NULL) return NULL;
     for (i=0;i<dimension;i++){
       tmp = gsl_vector_get(x, i);
       ((double *) a_array->data)[i] = tmp;
       DEBUG_MESS(3, "\t\ta_array_%d = %f\n", i, tmp);
     }
     FUNC_MESS_END();
     return a_array;
}

static PyArrayObject *
PyGSL_copy_gslmatrix_to_pyarray(const gsl_matrix *x)
{     
     int dimensions[2], i, j;
     PyArrayObject *a_array = NULL;
     double tmp;
     char *myptr;

     FUNC_MESS_BEGIN();
     dimensions[0] = x->size1;
     dimensions[1] = x->size2;
     a_array = (PyArrayObject *) PyGSL_New_Array(2, dimensions, PyArray_DOUBLE);
     if (a_array == NULL) return NULL;
     for (i=0;i<dimensions[1];i++){
	  for (j=0;j<dimensions[0];j++){
	      myptr =  a_array->data + a_array->strides[0] * i  
		                     + a_array->strides[1] * j;
	       tmp = gsl_matrix_get(x, j, i);
	       *((double *) myptr) = tmp;
	       DEBUG_MESS(3, "\t\ta_array_%d = %f\n", i, tmp);
	  }
     }
     FUNC_MESS_END();
     return a_array;
}


/*
 * Set a descriptive error. The callback name is listed together with the "GSL Object"
 * that called it, and a error description.
 */
static int
PyGSL_copy_pyarray_to_gslvector(gsl_vector *f, PyObject *object, int n, PyGSL_error_info * info)
{
     PyArrayObject *a_array = NULL;
     double tmp;
     int i, argnum = -1;
     

     FUNC_MESS_BEGIN();
     if (info)
	  argnum = info->argnum;
     a_array = PyGSL_PyArray_PREPARE_gsl_vector_view(object, PyArray_DOUBLE, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, n, argnum, info);
     if(a_array == NULL){
          FUNC_MESS("PyArray_FromObject failed");
	  goto fail;
     }
    if(DEBUG>2){
      fprintf(stderr, "\t\ta_array->dimensions[0] = %d\n", a_array->dimensions[0]);
      fprintf(stderr, "\t\ta_array->strides[0] = %d\n", a_array->strides[0]);
    }

    for (i=0;i<n;i++){
	 tmp = *((double *) (a_array->data + a_array->strides[0] * i));
	 gsl_vector_set(f, i, tmp);
	 DEBUG_MESS(3, "\t\ta_array_%d = %f\n", i, tmp);

     }
    FUNC_MESS_END();
    Py_DECREF(a_array);
    return GSL_SUCCESS;
 fail:
    PyGSL_add_traceback(NULL, filename, __FUNCTION__, __LINE__);
    FUNC_MESS("Failure");
    Py_XDECREF(a_array);
    return GSL_FAILURE;
}

    


static int
PyGSL_copy_pyarray_to_gslmatrix(gsl_matrix *f, PyObject *object, int n, int p,  PyGSL_error_info * info)
{
     PyArrayObject *a_array = NULL;
     double tmp;
     char *myptr;
     int i,j, argnum=-1;


     FUNC_MESS_BEGIN();


     
     if (info)
	  argnum = info->argnum;
     a_array = PyGSL_PyArray_PREPARE_gsl_matrix_view(object, PyArray_DOUBLE, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, n, p, info->argnum, info);
     if(a_array == NULL){
	  FUNC_MESS(" PyGSL_PyArray_PREPARE_gsl_matrix_view failed!");
	  goto fail;
     }

    assert(f->size1 == (size_t) n);
    assert(f->size2 == (size_t) p);


    for (i=0;i<n;i++){
	 for (j=0;j<p;j++){
	      myptr =  a_array->data + a_array->strides[0] * i  
		                     + a_array->strides[1] * j;
	      tmp = *((double *)(myptr));
	      DEBUG_MESS(3, "\t\ta_array_%d = %f\n", i, tmp);
	      gsl_matrix_set(f, i, j, tmp);
	 }
    }
    FUNC_MESS_END();
    Py_DECREF(a_array);
    return GSL_SUCCESS;
 fail:
    PyGSL_add_traceback(NULL, filename, __FUNCTION__, __LINE__);
    FUNC_MESS("  Failure");
    Py_XDECREF(a_array);
    return GSL_FAILURE;
}


#ifdef PyGSL_NUMERIC
#include "block_helpers_numpy.ic"
#endif

#ifdef PyGSL_NUMARRAY
#include "block_helpers_numarray.ic"
#endif
#if (!defined  PyGSL_NUMERIC) && (! defined PyGSL_NUMARRAY)
#error "Neither numarray nor numeric is defined!"
#endif
