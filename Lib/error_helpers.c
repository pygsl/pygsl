#include <pygsl/error_helpers.h>
#include <pygsl/utils.h>
#include <gsl/gsl_errno.h>
#include <compile.h>
#include <frameobject.h>

PyObject * 
PyGSL_error_flag_to_pyint(long flag)
{
     PyObject * result = NULL;
     if(DEBUG > 2){
	  fprintf(stderr,"I got an Error of %ld\n", flag);
     }
     if(PyErr_Occurred())
	  return NULL;
     if(flag>0){
	  /* How can I end here without an Python error? */
	  gsl_error("Unknown Reason. It was not set by GSL.",  __FILE__,
		    __LINE__, flag);
	  return NULL;
     }
     result = PyInt_FromLong((long) flag);
     return result;
}

void 
PyGSL_add_traceback(PyObject *module, char *filename, char *funcname, int lineno)
{
     PyObject *py_srcfile = NULL, *py_funcname = NULL, *py_globals = NULL,
	  *empty_tuple = NULL,  *empty_string = NULL;
     PyCodeObject *py_code = NULL;
     PyFrameObject *py_frame = NULL;
     
     FUNC_MESS_BEGIN();

     if(filename == NULL)
	  filename = "file ???";
     py_srcfile = PyString_FromString(filename);
     if (py_srcfile == NULL) 
	  goto fail;

     if(funcname == NULL)
	  funcname = "function ???";

     py_funcname = PyString_FromString(funcname);
     if (py_funcname == NULL) 
	  goto fail;

     /* Use the module if provided */
     if(module == NULL){
	  py_globals = PyDict_New();
     } else {
	  py_globals = PyModule_GetDict(module);
     } 
     if (py_globals == NULL) 
	  goto fail;

     empty_tuple = PyTuple_New(0);
     if (empty_tuple == NULL) 
	  goto fail;

     empty_string = PyString_FromString("");
     if (empty_string == NULL) 
	  goto fail;

     py_code = PyCode_New(
	  0,            /*int argcount,*/
	  0,            /*int nlocals,*/
	  0,            /*int stacksize,*/
	  0,            /*int flags,*/
	  empty_string, /*PyObject *code,*/
	  empty_tuple,  /*PyObject *consts,*/
	  empty_tuple,  /*PyObject *names,*/
	  empty_tuple,  /*PyObject *varnames,*/
	  empty_tuple,  /*PyObject *freevars,*/
	  empty_tuple,  /*PyObject *cellvars,*/
	  py_srcfile,   /*PyObject *filename,*/
	  py_funcname,  /*PyObject *name,*/
	  lineno,       /*int firstlineno,*/
	  empty_string  /*PyObject *lnotab*/
	  );
     if (py_code == NULL) 
	  goto fail;

     py_frame = PyFrame_New(
	  PyThreadState_Get(), /*PyThreadState *tstate,*/
	  py_code,             /*PyCodeObject *code,*/
	  py_globals,          /*PyObject *globals,*/
	  0                    /*PyObject *locals*/
	  );

     if (py_frame == NULL) 
	  goto fail;
     py_frame->f_lineno = lineno;
     PyTraceBack_Here(py_frame);

     FUNC_MESS_END();
 fail:
     FUNC_MESS("Handling failure");
     Py_XDECREF(py_srcfile);
     Py_XDECREF(py_funcname);
     Py_XDECREF(empty_tuple);
     Py_XDECREF(empty_string);
     Py_XDECREF(py_code);
     Py_XDECREF(py_frame);
}


/*
 * sets the right exception, but does not return to python!
 */
void PyGSL_module_error_handler(const char *reason, /* name of function*/
				const char *file, /*from CPP*/
				int line,   /*from CPP*/
				int gsl_error) /* real "reason" */
{
  const char* error_explanation;
  char error_text[255];
  PyObject* gsl_error_object;
  PyObject* gsl_error_module;
  PyObject* gsl_error_dict;

  error_explanation = gsl_strerror(gsl_error);
  if (error_explanation==NULL)
    if (reason==NULL)
      snprintf(error_text,sizeof(error_text),
	       "unknown error %d, no reason given",
	       gsl_error);
    else
      snprintf(error_text,sizeof(error_text),
	       "unknown error %d: %s",
	       gsl_error,reason);
  else
    if (reason==NULL)
      snprintf(error_text,sizeof(error_text),
	       "%s",
	       error_explanation);
    else
      snprintf(error_text,sizeof(error_text),
	       "%s: %s",
	       error_explanation,reason);

  /*
   * some functions call error handler more than once before returning 
   *  report only the first (most specific) error 
   */

  /* test, if exception is already set */
  /* ToDo: Send message only if debug mode enabled */
  if (PyErr_Occurred()) {
    fprintf(stderr,"Another error occured: %s\n",error_text);
    return;
  }


  /* error handler for gsl routines, sets exception */

  gsl_error_module=PyImport_ImportModule("pygsl.errors");
  gsl_error_dict=PyModule_GetDict(gsl_error_module);
  Py_INCREF(gsl_error_dict);
  gsl_error_object=PyDict_GetItemString(gsl_error_dict,"gsl_Error");
  Py_INCREF(gsl_error_object);
  PyErr_SetObject(gsl_error_object,
		  PyString_FromString(error_text));
  Py_DECREF(gsl_error_object);
  Py_DECREF(gsl_error_dict);
  Py_DECREF(gsl_error_module);
  return;
}
