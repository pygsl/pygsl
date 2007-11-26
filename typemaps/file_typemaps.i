/* -*- C -*- */
%{
  /*
   * Normally Microsofts (R) Visual C (TM) Compiler is used to compile python 
   * on windows.
   * When I used MinGW to compile I could not convert Python File Objects to 
   * C File Structs (The function PyFile_AsFile generated a core). Therefore 
   * I raise a python exception if someone tries to use this Code when it was 
   * compiled with MinGW. Do you know a better solution? Perhaps how to get it 
   * work?
   */
#ifdef __MINGW32__
#define HANDLE_MINGW() \
  do { \
  PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, __LINE__); \
  PyErr_SetString(PyExc_TypeError, "This Module was compiled using MinGW32. " \
		  "Conversion of python files to C files is not supported.");\
  goto fail; \
  } while(0)
#else
#define HANDLE_MINGW()
#endif   
%}
/* 
 * Type mapping for grabbing a FILE * from Python
 * Taken from the Swig documentation ... 
 */
%typemap(in) FILE * {
  FUNC_MESS_BEGIN();
  HANDLE_MINGW();
  if (!PyFile_Check($input)) {
      PyErr_SetString(PyExc_TypeError, "Need a file!");
      PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, __LINE__);
      goto fail;
  }
  FUNC_MESS("Convert Python File to C File");
  $1 = PyFile_AsFile($input);
  DEBUG_MESS(2, "Using file at %p with filedes %d", (void *) $1, fileno($1));
  assert($1 != NULL);
  
}
