#include <pygsl/error_helpers.h>
#include <pygsl/utils.h>
#include <gsl/gsl_errno.h>
#include <compile.h>
#include <frameobject.h>

static const char  error_module[] = "pygsl.errors";

static int  
PyGSL_error_flag(long flag)
{
     if(DEBUG > 2){
	  fprintf(stderr,"I got an Error of %ld\n", flag);
     }
     if(PyErr_Occurred())
	  return GSL_FAILURE;
     if(flag>0){
	  /* How can I end here without an Python error? */
	  gsl_error("Unknown Reason. It was not set by GSL.",  __FILE__, 
		    __LINE__, flag);
	  return GSL_FAILURE;
     }
     return GSL_SUCCESS;
}

static PyObject * 
PyGSL_error_flag_to_pyint(long flag)
{
     PyObject * result = NULL;
     if(GSL_FAILURE == PyGSL_error_flag(flag)){
	  return NULL;
     }
     result = PyInt_FromLong((long) flag);
     return result;
}

static void 
PyGSL_add_traceback(PyObject *module, const char *filename, const char *funcname, int lineno)
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
     return;

 fail:
     FUNC_MESS("Handling failure");
     Py_XDECREF(py_srcfile);
     Py_XDECREF(py_funcname);
     Py_XDECREF(empty_tuple);
     Py_XDECREF(empty_string);
     Py_XDECREF(py_code);
     Py_XDECREF(py_frame);
}



static PyObject * 
PyGSL_get_error_object(int gsl_error)
{
     PyObject *gsl_error_module=NULL, *gsl_error_dict=NULL, *gsl_error_object=NULL;
     char *err_str, *default_err_str="gsl_Error";

     FUNC_MESS_BEGIN();
     gsl_error_module=PyImport_ImportModule((char *) error_module);
     if(!gsl_error_module){
	  fprintf(stderr, "I could not get module %s!\n", error_module);
	  goto fail;
     }

     gsl_error_dict=PyModule_GetDict(gsl_error_module);
     if(!gsl_error_dict){
	  fprintf(stderr, "I could not get the dictionary of the module %s!\n",
		  error_module);
	  goto fail;
     }


     err_str = default_err_str;
     switch(gsl_error)
     {
     case GSL_FAILURE : err_str = "gsl_Error";                   break;
     case GSL_CONTINUE: err_str = NULL;                          break;
     case GSL_EDOM    : err_str = "gsl_DomainError";             break;
     case GSL_ERANGE  : err_str = "gsl_RangeError";              break;
     case GSL_EFAULT  : err_str = "gsl_PointerError";            break;
     case GSL_EINVAL  : err_str = "gsl_InvalidArgumentError";    break;
     case GSL_EFAILED : err_str = "gsl_GenericError";            break;
     case GSL_EFACTOR : err_str = "gsl_FactorizationError";      break;
     case GSL_ESANITY : err_str = "gsl_SanityCheckError";        break;
     case GSL_ENOMEM  : PyErr_NoMemory();                        break;
     case GSL_EBADFUNC: err_str = "gsl_BadFuncError";            break;
     case GSL_ERUNAWAY: err_str = "gsl_RunAwayError";            break;
     case GSL_EMAXITER: err_str = "gsl_MaximumIterationError";   break;
     case GSL_EZERODIV: err_str = "gsl_ZeroDivisionError";       break;
     case GSL_EBADTOL : err_str = "gsl_BadToleranceError";       break;
     case GSL_ETOL    : err_str = "gsl_ToleranceError";          break;
     case GSL_EUNDRFLW: err_str = "gsl_UnderflowError";          break;
     case GSL_EOVRFLW : err_str = "gsl_OverflowError";           break;
     case GSL_ELOSS   : err_str = "gsl_AccuracyLossError";       break;
     case GSL_EROUND  : err_str = "gsl_RoundOffError";           break;
     case GSL_EBADLEN : err_str = "gsl_BadLength";               break;
     case GSL_ENOTSQR : err_str = "gsl_MatrixNotSquare";         break;
     case GSL_ESING   : err_str = "gsl_SingularityError";        break;
     case GSL_EDIVERGE: err_str = "gsl_DivergeError";            break;
     case GSL_EUNSUP  : err_str = "gsl_NoHardwareSupportError";  break;
     case GSL_EUNIMPL : err_str = "gsl_NotImplementedError";     break;
     case GSL_ECACHE  : err_str = "gsl_CacheLimitError";         break;
     case GSL_ETABLE  : err_str = "gsl_TableLimitError";         break;
     case GSL_ENOPROG : err_str = "gsl_NoProgressError";         break;
     case GSL_ENOPROGJ: err_str = "gsl_JacobianEvaluationError"; break;
     case GSL_ETOLF   : err_str = "gsl_ToleranceFError";         break;
     case GSL_ETOLX   : err_str = "gsl_ToleranceXError";         break;
     case GSL_ETOLG   : err_str = "gsl_ToleranceGradientError";  break;
     case GSL_EOF     : err_str = "gsl_EOFError";                break;
     case PyGSL_ESTRIDE : err_str = "pygsl_StrideError";	 break; 
     default:
	  err_str = default_err_str;
     } /* switch(gsl_errno) */


     if (err_str == NULL) {
	  fprintf(stderr, "Pygsl Internal Error. I got an error number of %d. "
		  "For this errno no approbriate Exception was found!", gsl_error);
     } else {
	  gsl_error_object=PyDict_GetItemString(gsl_error_dict, err_str);
     }
     FUNC_MESS_END();
     return gsl_error_object;

 fail:
     Py_XDECREF(gsl_error_module);
     return NULL;
}
/*
 * sets the right exception, but does not return to python!
 */
static void 
PyGSL_module_error_handler(const char *reason, /* name of function*/
			const char *file, /*from CPP*/
			int line,   /*from CPP*/
			int gsl_error) /* real "reason" */
{
  const char* error_explanation;
  char error_text[255];
  PyObject* gsl_error_object;
  PyObject* gsl_error_module;
  PyObject* gsl_error_dict;

  FUNC_MESS_BEGIN();
  /*
   * GSL_ENOMEM is special. I am out of memory. No fancy tricks here.
   */
  if (GSL_ENOMEM == gsl_error){
       PyErr_NoMemory();
       return;
  }

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

  gsl_error_module=PyImport_ImportModule((char *) error_module);
  if(gsl_error_module == NULL){
       fprintf(stderr, "I could not import the module %s\n", error_module);
  }
  gsl_error_dict=PyModule_GetDict(gsl_error_module);
  Py_INCREF(gsl_error_dict);
  gsl_error_object=PyGSL_get_error_object(gsl_error);

  if(gsl_error_object) {
       Py_INCREF(gsl_error_object);
       PyErr_SetObject(gsl_error_object,
		       PyString_FromString(error_text));
  } else {
       fprintf(stderr, "%s. In Function %s. I could not get object gsl_Error!\n", 
	       error_module, __FUNCTION__);
  }
  Py_XDECREF(gsl_error_object);
  Py_DECREF(gsl_error_dict);
  Py_XDECREF(gsl_error_module);
  FUNC_MESS_END();
  return;
}
