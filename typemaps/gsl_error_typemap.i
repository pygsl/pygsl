/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 * Date  : December 2002
 */
%{   
#include <pygsl/utils.h>
#include <pygsl/error_helpers.h>
typedef int gsl_error_flag;
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
%typemap(python, out) gsl_error_flag {
     $result = PyGSL_ERROR_FLAG_TO_PYINT($1);
     if ($result == NULL){ 
	  PyGSL_add_traceback(pygsl_module_for_error_treatment, __FILE__, 
			      __FUNCTION__, __LINE__);
	  goto fail;
     }
}

