/* -*- C -*- */
/*
 * Author: Fabian Jakobs
 * Modified by : Pierre Schnizer January 2003
 */		 
%module gslwrap

%{
#include <gsl/gsl_types.h>
#include <Numeric/arrayobject.h>
#include <stdio.h>
%}

%init {
  import_array();
}

typedef int size_t;

%include typemaps.i
%include gsl/gsl_types.h
%include gsl_error_typemap.i
%include gsl_block_typemaps.i
%include gsl_complex_typemap.i

%include linalg.i 
%typemap (out) int = gsl_error_flag;
%include fft.i
%include permutation.i
%include math.i
%include blas.i
%include eigen.i
%include interpolation.i

/* %include error.i */
/* %include complex.i */
/* %include matrix.i */
/* %include vector.i */
