/* -*- C -*- */

/* 
 * Type mapping for grabbing a FILE * from Python
 * Taken from the Swig documentation ... 
 */
%typemap(python,in) FILE * {
  if (!PyFile_Check($input)) {
      PyErr_SetString(PyExc_TypeError, "Need a file!");
      goto fail;
  }
  $1 = PyFile_AsFile($input);
}
