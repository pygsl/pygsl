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
     PyObject *py_srcfile = NULL, *py_funcname = NULL, *py_globals = 0,
	  *empty_tuple = 0,  *empty_string = 0;
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
