/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 */   
%module _function_test

%{
#include <gsl/gsl_errno.h>
#include <typemaps/gsl_function_helpers.ic>
%}
%include gsl_error_typemap.i
%init %{
     import_array();
%}
%inline %{
static
int test_callback(PyObject *callback, PyObject * arguments, int nargs, char *message)
{
     PyObject *arglist = NULL, *object = NULL;
     
     int istuple = -1, tuple_size = -1;
     
     if(!PyCallable_Check(callback)){
	  goto fail;
     }
     arglist = Py_BuildValue("(O)", arguments);
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("    Call Python Object BEGIN");
     object  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     fprintf(stderr, "callback = %p, Py_None = %p, nargs = %d, message = %s\n", 
	     callback, Py_None, nargs, message);

     if(PyGSL_CHECK_PYTHON_RETURN(object, nargs, callback, message) != GSL_SUCCESS){
	  goto fail;
     }

     if((object))
	  if( ( istuple = PyTuple_Check(object) ) )
	       tuple_size = PyTuple_Size(object);

     fprintf(stderr, "object = %p, PyTuple_Check(object) = %d len(object) = %d\n", 
	     object,  istuple, tuple_size);

	  
     return GSL_SUCCESS;
 fail:
     Py_XDECREF(arglist);
     Py_XDECREF(object);
     return GSL_FAILURE;
}
%}

