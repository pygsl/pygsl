/* -*- C -*- */
/** 
 *  Author : Fabian Jakobs
 */
%{
#include <gsl/gsl_permutation.h>
%}

%rename(Permutation) gsl_permutation_struct;

#define INLINE_DECL
%include gsl/gsl_permutation.h


%extend gsl_permutation_struct{
  %rename(__getitem__) get_item;
  %rename(__len__) size;
  %rename(__str__) printf;

  gsl_permutation_struct(size_t n) {
    return gsl_permutation_calloc(n);
  }
  ~gls_permutation_struct() {
    gsl_permutation_free(self);
  }
  gsl_error_flag_drop _linear_to_canonical(struct gsl_permutation_struct *q){
       return gsl_permutation_linear_to_canonical(q, self);
  }
  gsl_error_flag_drop _canonical_to_linear(struct gsl_permutation_struct *q){
       return gsl_permutation_canonical_to_linear(q, self);
  }  
  gsl_error_flag_drop _mul(struct gsl_permutation_struct *res, struct gsl_permutation_struct *m2){
       return gsl_permutation_mul(res, self, m2);
  }
  size_t inversions(){
       return gsl_permutation_inversions(self);
  }
  size_t linear_cycles(){
       return gsl_permutation_linear_cycles(self);
  }
  size_t canonical_cycles(){
       return gsl_permutation_canonical_cycles(self);
  }
  
  gsl_error_flag_drop _inverse(struct gsl_permutation_struct *inv){
       return gsl_permutation_inverse(inv, self);
  }

  size_t get_item(const size_t i) {
    return gsl_permutation_get(self, i);
  }

  gsl_error_flag_drop swap(const size_t i, const size_t j) {
    return gsl_permutation_swap(self, i, j);
  }

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
       a_array = (PyArrayObject *) PyGSL_New_Array(1, &size, PyArray_LONG);
       if(a_array == NULL)
	    return NULL;
       data = (long *) a_array->data;
       for(i=0; i<size; i++){
	    data[i] = (long) gsl_permutation_get(self, i);
       }
       return (PyObject *) a_array;
  }
}

