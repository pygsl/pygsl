/* -*-C-*- */
%typemap(python, out) gsl_permutation_size_t * gsl_permutation_data{
  SWIG_GetPtr();
}
