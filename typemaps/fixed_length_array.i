/* -*-C-*- */ 
/**
 * Author: Pierre Schnizer		
 */

%{
#include <utils/util.h>
#include <utils/util.ic>

#define TO_PyArray_TYPE_float_2_elements                   PyArray_FLOAT  
#define TO_PyArray_TYPE_double_2_elements                  PyArray_DOUBLE  

#define BASIS_TYPE_float_2_elements                        float
#define BASIS_TYPE_double_2_elements                       double
%}
/*
  typedef float  float_2_elements;
  typedef double  double_2_elements;
*/
%typemap(python, in) float_2_elements * {
  PyArrayObject *a_array, *a2_array;
  a_array = make_and_check_vector($source, 2, TO_PyArray_TYPE_$basetype);
  if(a_array == NULL) return NULL;
  a2_array = (PyArrayObject *) 
    PyArray_CopyFromObject((PyObject *) a_array, TO_PyArray_TYPE_$basetype, 1, 1);
  Py_DECREF(a_array);
  if(a2_array == NULL){return NULL;};
  $target = (BASIS_TYPE_$basetype *) a2_array->data;
  if(DEBUG > 2){
    int i;
    BASIS_TYPE_$basetype *tmp;
    tmp = (BASIS_TYPE_$basetype *)((PyArrayObject *)a2_array)->data;
    for(i=0; i<2;i++){
      fprintf(stderr, "a_%d = %f\n", i, tmp[i]);
    }
  }
  /* a hack to be able to free a_array later */
   $source = (PyObject *) a2_array;
}
%typemap(python, argout) float_2_elements * {
  if(DEBUG > 1)
    fprintf(stderr, "Returning a_array at %p argnum = %d !\n", (void *) $arg, $argnum);
  if(DEBUG > 2){
    int i;
    BASIS_TYPE_$basetype *tmp;
    tmp = (BASIS_TYPE_$basetype *)((PyArrayObject *)$arg)->data;
    for(i=0; i<2;i++){
      fprintf(stderr, "a_%d = %f\n", i, tmp[i]);
    }
  }
  $target = t_output_helper($target, (PyObject *) $arg);
}

%typemap(python, in) double_2_elements *  = float_2_elements *;
%typemap(python, argout) double_2_elements *  = float_2_elements *;

