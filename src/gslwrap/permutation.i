/* -*- C -*- */
/**
 * Author : Fabian Jakobs, Pierre Schnizer <schnizer@users.sourceforge.net>
 * Date: 2003, 2017
 * $Id:$
 */
%{
#include <gsl/gsl_permutation.h>
#include "pygsl_permutation_config.h"
%}

%rename(Permutation) gsl_permutation_struct;

//%ignore gsl_permutation_linear_to_canonical;
//%ignore gsl_permutation_canonical_to_linear;
%ignore gsl_permutation_mul;
%ignore gsl_permutation_memcpy;
%ignore gsl_permutation_inversions;
%ignore gsl_permutation_canonical_cycles;
%ignore gsl_permutation_linear_cycles;
%include gsl_block_typemaps.i
%include gsl_error_typemap.i
#define INLINE_DECL
%include gsl/gsl_permutation.h


%extend gsl_permutation_struct{
  %rename(__getitem__) get_item;
  %rename(__len__) size;
  %rename(__str__) printf;

  gsl_permutation_struct(size_t n) {
    struct gsl_permutation_struct *p;

    p = gsl_permutation_calloc(n);
    DEBUG_MESS(2, "permutation (len %lu) = %p", (unsigned long) n,  (void *) p);
    return p;
  }
  ~gsl_permutation_struct() {
    gsl_permutation_free(self);
  }
  size_t inversions(){
       return gsl_permutation_inversions(self);
  }


  size_t get_item(const size_t i) {
    return gsl_permutation_get(self, i);
  }

  gsl_error_flag_drop swap(const size_t i, const size_t j) {
    return gsl_permutation_swap(self, i, j);
  }

  /*
  gsl_error_flag_drop permute(gsl_vector * INOUT){
    return gsl_permute (self, INOUT->data, INOUT->stride, INOUT->size);

  }
  */
  size_t size() {
    return gsl_permutation_size(self);
  }

  gsl_error_flag_drop valid () {
    return gsl_permutation_valid(self);
  }

  void reverse() {
    gsl_permutation_reverse(self);
  }

  int next() {
    return gsl_permutation_next(self);
  }

  int prev() {
    return gsl_permutation_prev(self);
  }

  char *printf() {
    /* FIXME this must return a string */
    gsl_permutation_fprintf (stdout, self, " %u");
    return NULL;
  }

  PyObject *tolist(){
       PyObject *a_list = NULL, *a_int;
       PyGSL_array_index_t size = 0, i;

       size = (long) gsl_permutation_size(self);
       a_list = PyList_New(size);
       if (a_list == NULL)
	    return NULL;
       for(i=0; i<size; i++){
	    a_int = PyInt_FromLong((long) gsl_permutation_get(self, i));
	    if (a_int == NULL){
		 Py_DECREF(a_list);
		 return NULL;
	    }
	    PyList_SET_ITEM(a_list, i, a_int);
       }
       return a_list;
  }

  PyObject *toarray(){
       PyArrayObject * a_array = NULL;
       long *data;
       PyGSL_array_index_t size, i;

       size = (int) gsl_permutation_size(self);
       a_array = (PyArrayObject *) PyGSL_New_Array(1, &size, NPY_LONG);
       if(a_array == NULL)
	    return NULL;
       data = (long *) PyArray_DATA(a_array);
       for(i=0; i<size; i++){
	    data[i] = (long) gsl_permutation_get(self, i);
       }
       return (PyObject *) a_array;
  }


  gsl_error_flag_drop _linear_to_canonical(struct gsl_permutation_struct *q){
%#ifdef _PYGSL_GSL_HAS_GSL_PERMUTATION_LINEAR_TO_CANONICAL
      return gsl_permutation_linear_to_canonical(q, self);
%#else
      PyGSL_ERROR_UNIMPL;
%#endif
  }
  gsl_error_flag_drop _canonical_to_linear(struct gsl_permutation_struct *q){
    %#ifdef _PYGSL_GSL_HAS_GSL_PERMUTATION_CANONICAL_TO_LINEAR
      return gsl_permutation_canonical_to_linear(q, self);
    %#else
     PyGSL_ERROR_UNIMPL;
    %#endif
  }

gsl_error_flag_drop _mul(struct gsl_permutation_struct *res, struct gsl_permutation_struct *m2){
  %#ifdef _PYGSL_GSL_HAS_GSL_PERMUTATION_MUL
      return gsl_permutation_mul(res, self, m2);
  %#else
      PyGSL_ERROR_UNIMPL;
  %#endif
     }

    gsl_error_flag_drop _inverse(struct gsl_permutation_struct *inv){
%#ifdef _PYGSL_GSL_HAS_GSL_PERMUTATION_INVERSIONS
      int status = GSL_EFAILED;
      FUNC_MESS_BEGIN();
     status = gsl_permutation_inverse(inv, self);
      FUNC_MESS_END();
      return status;
%#else
      PyGSL_ERROR_UNIMPL;
%#endif
    }

    pygsl_size_t_or_error linear_cycles(){
%#ifdef _PYGSL_GSL_HAS_GSL_PERMUTATION_LINEAR_CYCLES
           return gsl_permutation_linear_cycles(self);
%#else
      PyGSL_ERROR_UNIMPL;
%#endif
    }

  pygsl_size_t_or_error canonical_cycles(){
%#ifdef _PYGSL_GSL_HAS_GSL_PERMUTATION_CANONICAL_CYCLES
         return  gsl_permutation_canonical_cycles(self);
%#else
      PyGSL_ERROR_UNIMPL;
%#endif
  }

 }
