/* -*- C -*- */
/** 
 *  Author : Fabian Jakobs
 */
%{
#include <gsl/gsl_permutation.h>
%}

%rename(Permutation) gsl_permutation_struct;

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
  size_t get_item(const size_t i) {
    return gsl_permutation_get(self, i);
  }
  int swap(const size_t i, const size_t j) {
    return gsl_permutation_swap(self, i, j);
  }
  size_t size() {
    return gsl_permutation_size(self);
  }
  int valid () { 
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
}

