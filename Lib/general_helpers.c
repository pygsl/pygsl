/* -*- C -*- */
/**
 * Author: Pierre Schnizer		
 * Date : January 2003
 */
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>

#include <pygsl/general_helpers.h>
#include <pygsl/utils.h>
#include <pygsl/profile.h>

int
PyGSL_set_error_string_for_callback(PyGSL_error_info * info)
{
     PyObject *name_o = NULL;
     PyObject *callback;
     char * message = "";
     char * error_description = "";
     char * name, msg[1024], *mmesg;
     char *formatstring = "For the callback %s evaluted  for function %s, an error occured : %s";

     FUNC_MESS_BEGIN();    
     callback          = info->	 callback;
     if(info->message){
	  message	       = info->	 message;          
     }
     if(info->error_description){
	  error_description = info->	 error_description;
     }
     

     if (message == NULL){
	  mmesg = "Unknown";
     }else{
	  mmesg = message;
     }
     assert(callback != NULL);
     if (!PyObject_HasAttrString(callback, "__name__")){
	 PyErr_SetString(PyExc_ValueError, 
			 "While I was treating an errornous callback object,"
			 " I found that it had no attribute '__name__'!");
	 GSL_ERROR("Could not get the name of the callback!", GSL_EBADFUNC);
	 goto fail;
     }
     name_o = PyObject_GetAttrString(callback, "__name__");
     if(!PyString_Check(name_o)){
	  PyErr_SetString(PyExc_ValueError, 
			  " For an errornous callback object,"  
			  " the attribute '__name__' was not a Python string!");
	 GSL_ERROR("Nameobject of the callback was not a string!", GSL_EBADFUNC);
	 goto fail;
     }     
     name = PyString_AsString(name_o);

     /* A non completly standard but safe function. */
     FUNC_MESS("\tmakeing string");
     snprintf(msg, 1024, formatstring, name, mmesg, error_description);     
     if(DEBUG > 2){
	  fprintf(stderr, "ERROR: \t%s", msg);
     }
     GSL_ERROR(msg, GSL_EBADFUNC);

     FUNC_MESS_END();
     return GSL_EBADFUNC;
     /* Py_XDECREF(name_o);  ??? */
 fail:
     return GSL_EBADFUNC;
     /* Py_XDECREF(name_o);  ??? */
}

#define PyGSL_PYFLOAT_TO_DOUBLE(object, result, info)      \
  ( PyFloat_Check((object)) )                              \
  ?                                                        \
   (*(result))   = PyFloat_AsDouble((object)), GSL_SUCCESS \
  :  PyGSL_pyfloat_to_double((object), (result), (info))  

int 
PyGSL_pyfloat_to_double(PyObject *object, double *result, PyGSL_error_info *info)
{
     
     PyObject *object1;
     char *msg="The object returned to the GSL Function could not be converted to float";


     object1 = PyNumber_Float(object);
     if(object1 == NULL){
	 *result = gsl_nan();
	 if(info){
	      info->error_description = msg;
	      return PyGSL_set_error_string_for_callback(info);
	 }
	 GSL_ERROR(msg, GSL_EBADFUNC);
     }

     *result   = PyFloat_AsDouble(object1);
     if(DEBUG>2){
	  fprintf(stderr, "\t\t%s found a double of %f\n", __FUNCTION__, *result);
     }
     Py_DECREF(object1);

     PyGSL_INCREASE_float_transform_counter();

     return GSL_SUCCESS;
}

/*
 * Checks following conditions:
 *  For No Arguments: Got Py_None and No Error
 *  For 1  Argument:  Got an Object, No None  and No Error 
 *         (Is None a legal return for one object? I think so.) On the other hand its a
 *         callback and Conversions are waiting, so its good not to accept None. 
 * For 2  Arguments: Got a tuple of approbriate size
 */
#define PyGSL_CHECK_PYTHON_RETURN(object, nargs, info)                              \
  (                                                                                 \
        (  ( (nargs) == 0 ) && ( object ) && ( Py_None == (object) ) && ( !PyErr_Occurred() ) )   \
    ||  (  ( (nargs) == 1 ) && ( object ) && ( Py_None != (object) ) && ( !PyErr_Occurred() ) )   \
    ||  (  ( (nargs) >  1 ) && ( object ) && ( PyTuple_Check((object)) ) &&                       \
                 ( (nargs) == PyTuple_GET_SIZE((object)) ) )                        \
 )                                                                                  \
 ?                                                                                  \
    GSL_SUCCESS                                                                     \
 :                                                                                  \
   PyGSL_check_python_return((object), (nargs), (info))        

int
PyGSL_check_python_return(PyObject *object, int nargs, PyGSL_error_info  *info)
{
     int tuple_size, flag=-1;
     char *msg;


     FUNC_MESS_BEGIN();  
     
     assert(info);
     /* Expected No argumets */
     if(object == NULL && PyErr_Occurred()){
	  /* Set User Error */
	  info->error_description = "User function raised exception!";
	  return PyGSL_set_error_string_for_callback(info);
     }
     if(PyErr_Occurred()){
	  info->error_description = "Function raised an exception.";
	  return PyGSL_set_error_string_for_callback(info);
     }
	
     if(nargs == 0){
	  if(object != Py_None){
	       info->error_description = "I expected 0 arguments, but I got an object different from None.";
	       return PyGSL_set_error_string_for_callback(info);
	  } else {
	       return GSL_SUCCESS;
	  }
     }

     if(nargs == 1){
	  if(object == Py_None){
	       info->error_description = "Expected 1 argument, but None was returned. This value is not acceptable for" 
		    " the following arithmetic calculations.";
	       return PyGSL_set_error_string_for_callback(info);
	  } else {
	       return GSL_SUCCESS;
	  } 
     }

     if(nargs > 1){
	  msg = (char *) malloc(256 * sizeof(char));

	  if(object == Py_None){
	       snprintf(msg, 256, "I expected %d arguments, but the function returned None!", nargs);
	       info->error_description = msg;
	       flag = PyGSL_set_error_string_for_callback(info);	       

	  } else if(!PyTuple_Check(object)){
	       snprintf(msg, 256, "Expected %d arguments, but I didn't get a tuple! "
			"Did you just return one argument?.", nargs);
	       info->error_description = msg;
	       flag = PyGSL_set_error_string_for_callback(info);	       

	  } else {
	       tuple_size = PyTuple_GET_SIZE(object);
	       if(tuple_size != nargs){
		    snprintf(msg, 256, "I expected %d arguments, but the function returned %d arguments! ",
			     nargs, tuple_size);
	       info->error_description = msg;
	       flag = PyGSL_set_error_string_for_callback(info);

	       } else {
		    flag = GSL_SUCCESS;
	       }
	  }
	  free(msg);
     }    
     FUNC_MESS_END();
     return flag;
}



