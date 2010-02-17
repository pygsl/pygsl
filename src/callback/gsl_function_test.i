/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 */   
%module callback_function_test

%{
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <pygsl/error_helpers.h>
#include <pygsl/general_helpers.h>
#include "function_helpers.c"
#include "chars.c"   


%}
%include typemaps.i
%include gsl_error_typemap.i


%rename(gsl_function) gsl_function_struct;

struct gsl_function_struct
{
  %immutable;
};
typedef struct gsl_function_struct gsl_function;

%extend gsl_function_struct{
  gsl_function_struct(PyObject *tup){
    return PyGSL_convert_to_gsl_function(tup);
  }
  ~gsl_function_struct(){
	  PyGSL_params_free((callback_function_params *) self->params);
	  free(self);
	  self = NULL;
  }

}
/* add functions to allocate and free the memory stored by gsl_function */

%init %{
  init_pygsl();
%}



%inline %{
static
int pygsl_test_gsl_function_cb(gsl_function * BUFFER, double x, double *OUTPUT)
{

  double result;
  result = GSL_FN_EVAL(BUFFER, x);
  *OUTPUT = result;
  return GSL_SUCCESS;
  
}


static
int test_callback(PyObject *callback, PyObject * arguments, int nargs, char *message)
{
     PyObject *arglist = NULL, *object = NULL;
     int istuple = -1, tuple_size = -1;
     PyGSL_error_info  info;

     
     if(!PyCallable_Check(callback)){
	  goto fail;
     }

     info.callback = callback;
     info.message = __FUNCTION__;
     info.error_description = "XXX";
     info.argnum = 1;

     arglist = Py_BuildValue("(O)", arguments);
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("    Call Python Object BEGIN");
     object  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     fprintf(stderr, "callback = %p, Py_None = %p, nargs = %d, message = %s\n", 
	     callback, Py_None, nargs, message);

     if(PyGSL_CHECK_PYTHON_RETURN(object, nargs, &info) != GSL_SUCCESS){
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

