/* -*- C -*- */
/**
 * Author: Pierre Schnizer		
 */
/* Allow passing PyObjects for callbacks.*/
%typemap(python, in) PyObject * CALLABLE{
  PyObject * callback = NULL;
  callback = $input;
  assert(callback != NULL);
  if(!(PyCallable_Check(callback))){
    PyErr_SetString(PyExc_TypeError, 
		    "The callback object must be callable!");
    return NULL;   
  }
  $1 = callback;
}
