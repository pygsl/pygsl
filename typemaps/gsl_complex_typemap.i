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
#include <utils/util.h>
#include <typemaps/gsl_complex_helpers.ic>

%}

%typemap(in) gsl_complex {
     /* In direct */
     $1_basetype tmp;
     if(PyGSL_PyCOMPLEX_TO_$1_basetype($input, &tmp) != GSL_SUCCESS)
	  goto fail;
     $1 = tmp;
};

/* ------------------------------------------------------------------------- 
   Pointer Version
   ------------------------------------------------------------------------- */
%typemap(arginit) gsl_complex * IN %{
    $1_basetype tmp$argnum;
%}
%typemap( in) gsl_complex * IN %{ 
     {
	  /* In Pointer */
	  if(PyGSL_PyCOMPLEX_TO_$1_basetype ($input, &tmp$argnum) != 
	     GSL_SUCCESS)
	       goto fail;
     $1 = &tmp$argnum;
     }
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
  $result = t_output_helper($result, out);
  FUNC_MESS_END();
}


/* ------------------------------------------------------------------------- 
   Direct  Version
   ------------------------------------------------------------------------- */
/* 
 *  swig wraps structs as pointers anyway. So the pointer version can be 
 *  reused.
 */
%typemap(arginit) gsl_complex      IN = gsl_complex *IN;
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
  $result = t_output_helper($result, out);
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



