/* -*- C -*- */
/* ------------------------------------------------------------------------- 
   ------------------------------------------------------------------------- 
            Typemaps to translate python complex to gsl_complex.
   ------------------------------------------------------------------------- 
   ------------------------------------------------------------------------- */
/**
 * author: Pierre Schnizer
 * Date : December 2002
 *
 * Changelog: 22. May 2002
 *            Update to use libpygsl

 */
/*
 * Currently these typemaps just support the conversion of Python_complex.
 * gsl also supports complex built from float and long double. Numpy also 
 * supports such sizes. Therefore one could consider to accept Numeric arrays 
 * as input and iterate over the array?
 */

/* -------------------------------------------------------------------------
   Helper Functions
   ------------------------------------------------------------------------- */
%{
#include <gsl/gsl_errno.h>
#include <pygsl/utils.h>
#include <pygsl/complex_helpers.h>
%}

/* In direct */

%typemap(in) gsl_complex {
     $1_basetype tmp;
     if(PyGSL_PyCOMPLEX_TO_$1_basetype($input, &tmp) != GSL_SUCCESS)
	  goto fail;
     $1 = tmp;
};

/* ------------------------------------------------------------------------- 
   Pointer Version
   ------------------------------------------------------------------------- */
%typemap(arginit) gsl_complex * IN %{
    $1_basetype _complex_tmp$argnum;
%}
/* In Pointer */
%typemap( in) gsl_complex * IN {
     if(PyGSL_PyCOMPLEX_TO_$1_basetype ($input, &_complex_tmp$argnum) != GSL_SUCCESS)
	  goto fail;
     $1 = &_complex_tmp$argnum;
}

%typemap(arginit) gsl_complex * OUT %{
%}
/* Make the input ignored for the output */
%typemap( in, numinputs=0) gsl_complex * OUT($basetype temp){
  FUNC_MESS_BEGIN();
  $1 = &temp;
  FUNC_MESS_END();
}

%typemap( argout) gsl_complex * OUT { 
  PyObject *out = NULL;
  FUNC_MESS_BEGIN();
  out = PyComplex_FromDoubles((double) $1->dat[0],(double) $1->dat[1]);
  if(out == NULL){
    PyErr_SetString(PyExc_TypeError, "Could not convert to complex!\n");
    goto fail;    
  }
  $result = SWIG_Python_AppendOutput($result, out);
  FUNC_MESS_END();
}


/* ------------------------------------------------------------------------- 
   Direct  Version
   ------------------------------------------------------------------------- */
/* 
 *  swig wraps structs as pointers anyway. So the pointer version can be 
 *  reused.
 */
%typemap(arginit) gsl_complex * INOUT = gsl_complex *IN;
%typemap(in)      gsl_complex * INOUT = gsl_complex *IN;
%typemap(argout)  gsl_complex * INOUT = gsl_complex *OUT;

/* %typemap( in)     gsl_complex IN = gsl_complex *IN; */

%typemap( argout) gsl_complex OUT { 
  PyObject *out = NULL;
  FUNC_MESS_BEGIN();
  out = PyComplex_FromDoubles((double) $1.dat[0],(double) $1.dat[1]);
  if(out == NULL){
    PyErr_SetString(PyExc_TypeError, "Could not convert to complex!\n");
    goto fail;    
  }
  $result = SWIG_Python_AppendOutput($result, out);
  FUNC_MESS_END();
}

%typemap( out) gsl_complex  {
  PyObject *out = NULL;
  FUNC_MESS_BEGIN();
  out = PyComplex_FromDoubles((double) $1.dat[0],(double) $1.dat[1]);
  if(out == NULL){
    PyErr_SetString(PyExc_TypeError, "Could not convert to complex!\n");
    goto fail;    
  }
  $result = out;
  FUNC_MESS_END();
}
/* ------------------------------------------------------------------------- 
   Typemap copies
   ------------------------------------------------------------------------- */
%apply gsl_complex *OUT {gsl_complex *OUTPUT};
%apply gsl_complex *INOUT {gsl_complex *};
/* ---------------------------------------------------------------------------
   Cfloat
   --------------------------------------------------------------------------*/
%apply gsl_complex *OUT {gsl_complex_float *OUTPUT, 
			 gsl_complex_long_double *OUTPUT, 
			 gsl_complex_float *OUT, 
			 gsl_complex_long_double *OUT};

%apply gsl_complex * IN {gsl_complex_float        * IN, 
			 gsl_complex_long_double *IN};

%apply gsl_complex       {gsl_complex_float        , 
			  gsl_complex_long_double };

%apply gsl_complex * IN {gsl_complex_double       *,
                         gsl_complex_float        *, 
			 gsl_complex_long_double  *};
/* EOF */
