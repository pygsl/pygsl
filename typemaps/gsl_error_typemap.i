/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 * Date  : December 2002
 */
%{   
#include <pygsl/utils.h>
#include <pygsl/error_helpers.h>
typedef int gsl_error_flag;
typedef int gsl_error_flag_drop;
PyObject *pygsl_module_for_error_treatment = NULL;
                        
%}

%init {
     pygsl_module_for_error_treatment = m;
}

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

/* Warning: Swig will treat it as an pointer !! */
%typemap(out) gsl_error_flag {
     $result = PyGSL_ERROR_FLAG_TO_PYINT($1);
     if ($result == NULL){ 
	  PyGSL_add_traceback(pygsl_module_for_error_treatment, __FILE__, 
			      __FUNCTION__, __LINE__);
	  goto fail;
     }
}

/* 
 *  The same as above, but the user will never need to see the flag, as it is 
 *  turned in an exception if necessary.
 *
 *  As of this writing the GSL Errors are setup in the following way:
 *
 *  1.) GSL_CONTINUE and GSL_FAILURE are negative. I believe they should be 
 *      returned to the user.
 *  
 *  2.) GSL_SUCCESS is zero.
 *
 *  3.) All positive results indicate some error. These are turned into an
 *      exception. So it is not necessary to return the flag.
 */
%typemap(out) gsl_error_flag_drop {
     /* 
      * assert($1 >= 0);  assertion removed as PyGSL_error_flag can deal with
      *	negative numbers.
      * 
      * 17. February 2010. Check if it is not SUCCESS. If an error is found
      * it returns the flag. This should have an impact on a lot of functions
      */
     if(GSL_SUCCESS != PyGSL_ERROR_FLAG($1)){
	 PyGSL_add_traceback(pygsl_module_for_error_treatment, __FILE__, 
			     __FUNCTION__, __LINE__); 
	 goto fail;
     }
     Py_INCREF(Py_None);
     $result = Py_None;
}

