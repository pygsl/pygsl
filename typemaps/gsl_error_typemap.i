/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 * Date  : December 2002
 */
%{   
#include <utils/util.h>  
typedef int gsl_error_flag;
%}

/*
 * GSL passes the error as int. The following typemap will make python 
 * raising the error if it was installed by the approbriate typemap. 
 *
 * Here two different types exist. 
 * The first uses a special defined data type gsl_error_flag. 
 *  Drawback : the wrapper allocates the memory for 
 *             the pointer.
 * The second overloads int when returned. 
 * Drawback : it will treated all integes returned by functions as 
 *            errorcodes.
 *
 * As far as I know all integers returned in python are errorcodes thus, 
 * I think the second approach should be the preferred one. 
 */
/*
%typemap(python, arginit) gsl_error_flag %{
     int gsl_error_flag$argnum;
%}
%typemap(python, default) gsl_error_flag %{
     $1 = gsl_error_flag$argnum;
%}
*/
%typemap(python, out) gsl_error_flag {
     /* Warning: Swig will treat it as an pointer !! */
     int flag;
     flag = $1;
     if(DEBUG > 2){
	  fprintf(stderr,"I got an Error of %d\n", flag);
     }
     if(PyErr_Occurred())
	  goto fail;
     $result = PyInt_FromLong((long) flag);
     if(flag>0){
	  /* How can I end here without an Python error? */
	  gsl_error("Unknown Reason. It was not set by GSL.",  __FILE__, __LINE__, flag);
	  goto fail;
     }
}

