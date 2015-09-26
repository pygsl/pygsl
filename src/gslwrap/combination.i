/* -*- C -*- */
/** 
 *  Author : Pierre Schnizer
 */
%{
#include <gsl/gsl_combination.h>
%}


%rename(Combination) gsl_combination_struct;

%feature("autodoc");

struct gsl_combination_struct
{
     %immutable;     
/*  size_t n;
  size_t k;
  size_t *data; */
};
%feature("autodoc") gsl_combination_struct "bla bla" "more blah blah";
%extend gsl_combination_struct{
  %rename(__getitem__) get_item;
  %rename(__len__) get_k;


  gsl_combination_struct(const size_t n, const size_t k) {
    return gsl_combination_calloc(n,k);
  }
  ~gsl_combination_struct() {
    gsl_combination_free(self);
  }
  size_t get_item(const size_t i){
       return gsl_combination_get(self, i);
  }
  size_t  k(){
       return gsl_combination_k(self);
  }
  size_t  n(){
       return gsl_combination_n(self);
  }
  void init_first() {
       gsl_combination_init_first(self);	       
  }    
  void init_last() {
       gsl_combination_init_last(self);
  }

  int valid(){
       return gsl_combination_valid(self);
  }
  int next(){
       /* returns gsl_success or gsl_failure. Should gsl_failure translate to an exception? */
       return gsl_combination_next(self);
  }
  int prev(){
       /* returns gsl_success or gsl_failure. Should gsl_failure translate to an exception? */
       return gsl_combination_prev(self);
  }
  
  PyObject *tolist(){
       
       PyObject *a_list = NULL, *a_int;
       long size = 0, i;

       size = (long) gsl_combination_k(self);
       a_list = PyList_New(size);
       if (a_list == NULL)
	    return NULL;
       for(i=0; i<size; i++){
	    a_int = PyInt_FromLong((long) gsl_combination_get(self, i));
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

       size = (int) gsl_combination_k(self);
       a_array = (PyArrayObject *) PyGSL_New_Array(1, &size, NPY_LONG);
       if(a_array == NULL)
	    return NULL;
       data = (long *) PyArray_DATA(a_array);
       for(i=0; i<size; i++){
	    data[i] = (long) gsl_combination_get(self, i);
       }
       return (PyObject *) a_array;
  }
}
