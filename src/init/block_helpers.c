/* -*- C -*- */
/*
 * Author : Pierre Schnizer
 * Date   : January 2003
 * 
 *  Changes for better error reporting from 
 *  17. 01. 2003
 *  Adding a info struct. This struct contains additional information used for 
 *  error Reporting.
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

int 
PyGSL_stride_recalc(int strides, int basic_type_size, int * stride_recalc)
{
     if((strides % basic_type_size) == 0) {
	  *stride_recalc = strides / basic_type_size; 
	  return GSL_SUCCESS;
     }
     gsl_error("Can not convert the stride to a GSL stride", 
	       filename, __LINE__, PyGSL_ESTRIDE);
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, __LINE__);     
     return PyGSL_ESTRIDE;
}
/* ========================================================================= */
/*
 * Implementation of the above routines.
 */
PyArrayObject * 
PyGSL_PyArray_prepare_gsl_vector_view(PyObject *src,
				      enum PyArray_TYPES array_type,
				      int contiguous, 
				      int num, int argnum, PyGSL_error_info * info)
{
     PyArrayObject * a_array = NULL;
     char *ctmp;

     FUNC_MESS_BEGIN();
     if( PyArray_Check((src)) ){
	  FUNC_MESS("\t\tGot an Array Object!");
	  if( ((PyArrayObject *) (src))->nd == 1){
	       FUNC_MESS("\t\tGot an vector!");
	       if( num == -1 ){
		    FUNC_MESS("\t\t No one cares about its length!");
	       } else {
		    if( ((PyArrayObject *) (src))->dimensions[0] == (num) )
			 FUNC_MESS("\t\tLength matched!");
	       }
	       if(  ((PyArrayObject *) (src))->data == NULL){
		    gsl_error("Got an array object were the data was NULL!", __FILE__, __LINE__, GSL_ESANITY);
		    return NULL;
	       }
	       if(  ((PyArrayObject *) (src))->descr->type_num == (array_type) )
		    FUNC_MESS("\t\tArray type matched!");
	       if ( contiguous == 0){
		    FUNC_MESS("\t\t Can deal with discontiguous arrays!");
	       } else {
		    if(((PyArrayObject *) (src))->flags & CONTIGUOUS )
			 FUNC_MESS("\t\t Is a contiguous array!");
	       }
	  }
     }

     if (contiguous == 0)
	  a_array = (PyArrayObject *) PyArray_FromObject(src, array_type, 1, 1);
     else
	  a_array = (PyArrayObject *) PyArray_ContiguousFromObject(src, array_type, 1, 1);
     /* Here one could put some more information */
     if(NULL == a_array)
	  goto fail;
    

     if(a_array->nd != 1){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "I could not convert argument number % 3d."
		 " I expected a vector, but got an array of % 3d dimensions!\n", argnum, a_array->nd);
	  if (info){
	       info->error_description = ctmp;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       PyErr_SetString(PyExc_ValueError, ctmp);
	  }
	 free(ctmp);
	 goto fail;
     }
     if(num != -1 && a_array->dimensions[0] != num){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "I could not match argument number % 3d.The vector must exactly match the number of required elements."
		 " I got % 3d elements but expected % 3d elements!\n", argnum, a_array->dimensions[0], num);	  
	  if (info){
	       info->error_description = ctmp;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       PyErr_SetString(PyExc_ValueError, ctmp);
	  }
	 free(ctmp);
	 goto fail;
     }
     FUNC_MESS_END();
     PyGSL_INCREASE_vector_transform_counter();
     return a_array;
 fail:
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, __LINE__);
     Py_XDECREF(a_array);
     return NULL;
}

PyArrayObject *
PyGSL_PyArray_prepare_gsl_matrix_view(PyObject *src,
				      enum PyArray_TYPES array_type,
				      int contiguous, 
				      int size1, int size2, int argnum, 
				      PyGSL_error_info * info)
{
     PyArrayObject * a_array = NULL;
     char *ctmp;

     FUNC_MESS_BEGIN();
     if( PyArray_Check((src)) ){
	  FUNC_MESS("\t\tGot an Array Object!");
	  if( ((PyArrayObject *) (src))->nd == 2){
	       FUNC_MESS("\t\tGot a matrix!");
	       if( size1 == -1 ){
		    FUNC_MESS("\t\t No one cares about its first dimension!");
	       } else {
		    if( ((PyArrayObject *) (src))->dimensions[0] == (size1) )
			 FUNC_MESS("\t\t1. dimension matched!");
	       }
	       if( size2 == -1 ){
		    FUNC_MESS("\t\t No one cares about its second dimension!");
	       } else {
		    if( ((PyArrayObject *) (src))->dimensions[1] == (size2) )
			 FUNC_MESS("\t\t2. dimension matched!");
	       }
	       if(  ((PyArrayObject *) (src))->data == NULL){
		    gsl_error("Got an array object were the data was NULL!", __FILE__, __LINE__, GSL_ESANITY);
		    return NULL;
	       }
	       if(  ((PyArrayObject *) (src))->descr->type_num == (array_type) )
		    FUNC_MESS("\t\tArray type matched!");
	       if ( contiguous == 0){
		    FUNC_MESS("\t\t Can deal with discontiguous arrays!");
	       } else {
		    if(((PyArrayObject *) (src))->flags & CONTIGUOUS )
			 FUNC_MESS("\t\t Is a contiguous array!");
	       }
	  }
     }

     if (contiguous == 0){
	  FUNC_MESS("\t Looking for NON Contiguous Matrix");
	  a_array = (PyArrayObject *) PyArray_FromObject(src, array_type, 2, 2);
     } else {
	  FUNC_MESS("\t Looking for     Contiguous Matrix");
	  a_array = (PyArrayObject *) PyArray_ContiguousFromObject(src, array_type, 2, 2);
     }
     if(NULL == a_array){
	  FUNC_MESS("\t Conversion to Array Failed!");
	  return NULL;
     }

     if(a_array->nd != 2){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "I could not convert argument number % 3d."
		 " I expected a matrix, but got an array of % 3d dimensions!\n", argnum, a_array->nd);
	  if (info){
	       info->error_description = ctmp;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       PyErr_SetString(PyExc_ValueError, ctmp);
	  }
	 free(ctmp);
	  return NULL;
     }

     if(size1 != -1 && a_array->dimensions[0] != size1){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "The matrix size of argument % 3d did not match the expected size for the first dimension." 
		 " I got % 3d elements but expected % 3d elements!\n", argnum, a_array->dimensions[0], size1);
	  if (info){
	       info->error_description = ctmp;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       PyErr_SetString(PyExc_ValueError, ctmp);
	  }
	 free(ctmp);
	 return NULL;
     }

     if(size2 != -1 && a_array->dimensions[1] != size2){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "The matrix size of argument % 3d did not match the expected size for the second dimension." 
		 " I got % 3d elements but expected % 3d elements!\n", argnum, a_array->dimensions[1], size2);
	  if (info){
	       info->error_description = ctmp;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       PyErr_SetString(PyExc_ValueError, ctmp);
	  }
	 free(ctmp);
	 return NULL;
     }
     PyGSL_INCREASE_matrix_transform_counter();    
     FUNC_MESS_END();
     return a_array;
}

PyArrayObject * 
PyGSL_PyArray_generate_gsl_vector_view(PyObject *src,
				       enum PyArray_TYPES array_type,
				       int argnum)
{
     int dimension;
     PyObject *tmp;
     PyArrayObject *a_array = NULL;
     char *ctmp;

     FUNC_MESS_BEGIN();
     tmp = PyNumber_Int(src);
     if(!tmp){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "I could not convert argument number % 3d. to an integer.",
		  argnum);
	 PyErr_SetString(PyExc_TypeError, ctmp);
	 free(ctmp);
	 return NULL;
     }
     dimension = PyInt_AS_LONG(src);
     Py_DECREF(tmp);
     if(dimension <= 0){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "Argument number % 3d is % 10d< 0. Its the size of the vector and thus must be positive!",
		  argnum, dimension);
	 PyErr_SetString(PyExc_TypeError, ctmp);
	 free(ctmp);
	 return NULL;
     }
     
     a_array = (PyArrayObject *) PyArray_FromDims(1, &dimension, array_type);
     if(NULL == a_array){
	  return NULL;
     }
     return a_array;
}

PyArrayObject * 
PyGSL_PyArray_generate_gsl_matrix_view(PyObject *src,
				      enum PyArray_TYPES array_type,
				      int argnum)
{
     PyObject *tmp;
     PyArrayObject *a_array = NULL;

     int dimensions[2], i;
     char *ctmp;

     FUNC_MESS_BEGIN();     
     if(!PySequence_Check(src) || PySequence_Size(src) != 2){
	  ctmp = (char *) malloc(1024 * sizeof(char));
	  sprintf(ctmp, "I need a sequence of two elements as argument number % 3d",
		  argnum);
	 PyErr_SetString(PyExc_TypeError, ctmp);
	 free(ctmp);
	 return NULL;

     }

     for(i = 0; i<2; i++){
	  tmp = PyNumber_Int(PySequence_GetItem(src, i));
	  if(!tmp){
	       ctmp = (char *) malloc(1024 * sizeof(char));
	       sprintf(ctmp, "I could not convert argument number % 3d. for dimension %3d to an integer.",
		       argnum, i);
	       PyErr_SetString(PyExc_TypeError, ctmp);
	       free(ctmp);
	       return NULL;
	  }
	  dimensions[i] = PyInt_AS_LONG(tmp);
	  Py_DECREF(tmp);
	  if(dimensions[i] <= 0){
	       ctmp = (char *) malloc(1024 * sizeof(char));
	       sprintf(ctmp, "Argument number % 3d is % 10d< 0. Its the size of the vector and thus must be positive!",
		       argnum, dimensions[i]);
	       PyErr_SetString(PyExc_TypeError, ctmp);
	       free(ctmp);
	       return NULL;
	  }

     }     
     a_array = (PyArrayObject *) PyArray_FromDims(2, dimensions, array_type);
     if(NULL == a_array){
	  return NULL;
     }
     return a_array;
}

PyArrayObject *
PyGSL_copy_gslvector_to_pyarray(const gsl_vector *x)
{     
     int dimension = -1, i;
     PyArrayObject *a_array = NULL;
     double tmp;

     FUNC_MESS_BEGIN();
     dimension = x->size;
     a_array = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if (a_array == NULL) return NULL;
     for (i=0;i<dimension;i++){
       tmp = gsl_vector_get(x, i);
       ((double *) a_array->data)[i] = tmp;
	  if(DEBUG){
	    fprintf(stderr, "\t\ta_array_%d = %f\n", i, tmp);
	  }
     }
     FUNC_MESS_END();
     return a_array;
}

PyArrayObject *
PyGSL_copy_gslmatrix_to_pyarray(const gsl_matrix *x)
{     
     int dimensions[2], i, j;
     PyArrayObject *a_array = NULL;
     double tmp;
     char *myptr;

     FUNC_MESS_BEGIN();
     dimensions[0] = x->size1;
     dimensions[1] = x->size2;
     a_array = (PyArrayObject *) PyArray_FromDims(2, dimensions, PyArray_DOUBLE);
     if (a_array == NULL) return NULL;
     for (i=0;i<dimensions[1];i++){
	  for (j=0;j<dimensions[0];j++){
	      myptr =  a_array->data + a_array->strides[0] * i  
		                     + a_array->strides[1] * j;
	       tmp = gsl_matrix_get(x, j, i);
	       *((double *) myptr) = tmp;
	       if(DEBUG){
		    fprintf(stderr, "\t\ta_array_%d = %f\n", i, tmp);
	       }
	  }
     }
     FUNC_MESS_END();
     return a_array;
}


/*
 * Set a descriptive error. The callback name is listed together with the "GSL Object"
 * that called it, and a error description.
 */
int
PyGSL_copy_pyarray_to_gslvector(gsl_vector *f, PyObject *object, int n, PyGSL_error_info * info)
{
     PyArrayObject *a_array = NULL;
     double tmp;
     int i, argnum = -1;
     

     FUNC_MESS_BEGIN();
     if (info)
	  argnum = info->argnum;
     a_array = PyGSL_PyArray_PREPARE_gsl_vector_view(object, PyArray_DOUBLE, 0, n, argnum, info);
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
	 if(DEBUG>2){
	   fprintf(stderr, "\t\ta_array_%d = %f\n", i, tmp);
	 }

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

    


int
PyGSL_copy_pyarray_to_gslmatrix(gsl_matrix *f, PyObject *object, int n, int p,  PyGSL_error_info * info)
{
     PyArrayObject *a_array = NULL;
     double tmp;
     char *myptr;
     int i,j, argnum=-1;


     FUNC_MESS_BEGIN();


     
     if (info)
	  argnum = info->argnum;
     a_array = PyGSL_PyArray_PREPARE_gsl_matrix_view(object, PyArray_DOUBLE, 0, n, p, info->argnum, info);
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
	      if(DEBUG>2){
		   fprintf(stderr, "\t\ta_array_%d_%d = %f\n", i, j, tmp);
	      }
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


