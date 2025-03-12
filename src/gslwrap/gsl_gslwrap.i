/* -*- C -*- */
/*
 * Author: Fabian Jakobs
 * Modified by : Pierre Schnizer January 2003, 2025
 *
 * Changes:
 *   22. May 2003: Changed to use the pygsl library. Warning! Do not import
 * Numeric/arrayobject.h before pygsl_block_helpers.h.  pygsl_block_helpers.h
 * defines the PY_ARRAY_UNIQUE_SYMBOL.
 *
 * 2025: swig 4.3 compatible
 */
%module gslwrap
%feature ("autodoc", "3");
%include pygsl_compat.i

%{
#include <gsl/gsl_types.h>
#include <stdio.h>
#include <pygsl/error_helpers.h>

static PyObject *module = NULL;

static const char _pygsl_gsl_unimpl_feature[] =  "Feature not implemented in your version of GSL";
#define _PyGSL_ERROR_UNIMPL pygsl_error(_pygsl_gsl_unimpl_feature, __FILE__, __LINE__, GSL_EUNIMPL)
#define PyGSL_ERROR_UNIMPL      do{_PyGSL_ERROR_UNIMPL; PyGSL_ERROR_FLAG(GSL_EUNIMPL); return GSL_EUNIMPL; }while(0);
#define PyGSL_ERROR_UNIMPL_NULL do{_PyGSL_ERROR_UNIMPL; PyGSL_ERROR_FLAG(GSL_EUNIMPL); return GSL_EUNIMPL; }while(0);
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
%include permutation.i
%include linalg.i
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
