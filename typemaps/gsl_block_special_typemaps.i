/* -*- C -*- */
/*
 * Author: Pierre Schnizer January 2003 
 *
 * Changelog: 
 *   22. May 2003. Changed to use the pygsl library. Warning! Do not import
 * Numeric/arrayobject.h before pygsl_block_helpers.h.  pygsl_block_helpers.h
 * defines the PY_ARRAY_UNIQUE_SYMBOL.
 * 
 */		 
%{
#include <pygsl/block_helpers.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#include <stdio.h>
%}

%typemap(arginit) (const double *, const double *, size_t ) %{
     PyArrayObject *_PyVector_1$argnum = NULL;
     PyArrayObject *_PyVector_2$argnum = NULL;
%};

%typemap(in) (const double *, const double *, size_t ) {
     int mysize = 0;
     if(!PySequence_Check($input)){
	  PyErr_SetString(PyExc_TypeError, "Expected a sequence!");
	  goto fail;
     }
     if(PySequence_Fast_GET_SIZE($input) != 2){
	  PyErr_SetString(PyExc_TypeError, "Expected a sequence with length 2!");
	  goto fail;
     }
     _PyVector_1$argnum = PyGSL_PyArray_PREPARE_gsl_vector_view(
	  PySequence_Fast_GET_ITEM($input, 0), PyArray_DOUBLE, 1, -1, $argnum, NULL);
     if (_PyVector_1$argnum == NULL)
	  goto fail;

     mysize = _PyVector_1$argnum->dimensions[0];

     _PyVector_2$argnum = PyGSL_PyArray_PREPARE_gsl_vector_view(
	   PySequence_Fast_GET_ITEM($input, 1), PyArray_DOUBLE, 1, mysize, $argnum+1, NULL);
     if (_PyVector_2$argnum == NULL)
	  goto fail;

     $1 = (double *)(_PyVector_1$argnum->data);
     $2 = (double *)(_PyVector_2$argnum->data);
     $3 = (size_t) mysize;

};
%typemap(check) (const double *, const double *, size_t ) {
     ;
};
%typemap(argfree) (const double *, const double *, size_t ) {
     Py_XDECREF(_PyVector_1$argnum);
     Py_XDECREF(_PyVector_2$argnum);
};
%typemap(arginit) (const double *, size_t ) %{
     PyArrayObject *_PyVector$argnum = NULL;
%};
%typemap(in) (const double *, size_t ) {
     int mysize = 0;
     _PyVector$argnum = PyGSL_PyArray_PREPARE_gsl_vector_view(
	  $input, PyArray_DOUBLE, 1, -1, $argnum, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;

     mysize = _PyVector$argnum->dimensions[0];
     $1 = (double *)(_PyVector$argnum->data);
     $2 = (size_t) mysize;
};
/* Just to prevent that the check typemap below is applied. */
%typemap(argfree) (const double *, size_t ) {
     Py_XDECREF(_PyVector$argnum);
};

