/* -*- C -*- */

/* 
 * Type mapping for grabbing a FILE * from Python
 * Taken from the Swig documentation ... 
 */
%typemap(python,in) FILE * {
  FUNC_MESS_BEGIN();
  if (!PyFile_Check($input)) {
      PyErr_SetString(PyExc_TypeError, "Need a file!");
      PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, __LINE__);
      goto fail;
  }
  FUNC_MESS("GET FILE");
  $1 = PyFile_AsFile($input);
  DEBUG_MESS(2, "Using file at %p with filedes %d", (void *) $1, fileno($1));
  assert($1 != NULL);
  
}
