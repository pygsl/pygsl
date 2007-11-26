/* -*- C -*- */
/**
 * Author : Pierre Schnizer
 * Date: January 2003
 */
#include <pygsl/function_helpers.h>
#include <pygsl/error_helpers.h>

/* 3   dO -> d      gsl_function     */
/* 3.1 dO -> d d    gsl_function_fdf */
PyGSL_API_EXTERN int 
PyGSL_function_wrap_helper(double x, double * result, double *result2,
			   PyObject *callback, PyObject *arguments, const char *c_func_name)
{
     PyObject *object = NULL, *arglist = NULL, *tmp = NULL;
     int flag;
     PyGSL_error_info  info;
     /* the line number to appear in the traceback */ 
     int trb_lineno = -1;

     FUNC_MESS_BEGIN();
     assert(arguments != NULL);
     arglist = Py_BuildValue("(dO)", x, arguments);
     FUNC_MESS("    Call Python Object BEGIN");
     assert(arglist != NULL);
     assert(callback != NULL);

     if(DEBUG > 2){
	  fprintf(stderr, "callback = %p, arglist = %p\n", callback, arglist);
     }
     object  = PyEval_CallObject(callback, arglist);
     info.callback = callback;
     info.message  = c_func_name;	  

     Py_DECREF(arglist);
     FUNC_MESS("    Call Python Object END");
     if (result2){
	  flag = PyGSL_CHECK_PYTHON_RETURN(object, 2, &info);
	  if(flag !=  GSL_SUCCESS){
	       trb_lineno = __LINE__ - 2;
	       FUNC_MESS("   PyGSL_CHECK_PYTHON_RETURN  Failed ");
	       goto fail;
	  }
	  tmp = PyTuple_GET_ITEM(object, 0);
     }else{
	  flag = PyGSL_CHECK_PYTHON_RETURN(object, 1, &info);
	  if(flag !=  GSL_SUCCESS){
	       trb_lineno = __LINE__ - 2;
	       FUNC_MESS("   PyGSL_CHECK_PYTHON_RETURN  Failed ");
	       goto fail;
	  }
	  tmp = object;
     }
     assert(tmp);
     info.argnum = 1;
     flag = PyGSL_PYFLOAT_TO_DOUBLE(tmp, result, &info);
     if(flag !=  GSL_SUCCESS){
	  trb_lineno = __LINE__ - 2;
	  FUNC_MESS("   PyGSL_PYFLOAT_TO_DOUBLE  Failed ");
	  goto fail;
     }
     if(result2){
	  tmp = PyTuple_GET_ITEM(object, 1);
	  info.argnum = 2;
	  flag = PyGSL_PYFLOAT_TO_DOUBLE(tmp, result2, &info);
	  if(flag !=  GSL_SUCCESS){
	       trb_lineno = __LINE__ - 2;
	       FUNC_MESS("   PyGSL_PYFLOAT_TO_DOUBLE  Failed ");
	       goto fail;
	  }
     }
     Py_XDECREF(object);
     FUNC_MESS_END();
     return GSL_SUCCESS;

 fail:
     PyGSL_add_traceback(NULL, __FILE__, c_func_name, trb_lineno);
     FUNC_MESS("Fail");
     Py_XDECREF(object);
     return flag;
}

