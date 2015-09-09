/* -*- C -*- */
/*
 * Author: Fabian Jakobs
 * Modified by : Pierre Schnizer January 2003
 * 
 * Changes: 
 *   22. May 2003: Changed to use the pygsl library. Warning! Do not import
 * Numeric/arrayobject.h before pygsl_block_helpers.h.  pygsl_block_helpers.h
 * defines the PY_ARRAY_UNIQUE_SYMBOL.
 */		 
%module gslwrap

%{
#include <gsl/gsl_types.h>
#include <stdio.h>
#include <pygsl/error_helpers.h>

static PyObject *module = NULL;

%}

%init {
  init_pygsl();
}

typedef int size_t;

%include typemaps.i
%include gsl/gsl_types.h
%include gsl_error_typemap.i
%include gsl_block_typemaps.i
%include gsl_complex_typemap.i


%immutable;
%include linalg.i 
%include permutation.i
%include combination.i
%include math.i
%typemap (out) int = gsl_error_flag_drop;
/* %include fft.i *//* now in separate C module */
%include blas.i
%include eigen.i
%include interpolation.i

/* %include error.i */
/* %include complex.i */
/* %include matrix.i */
/* %include vector.i */




