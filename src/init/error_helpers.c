#include <pygsl/error_helpers.h>
#include <pygsl/utils.h>
#include <gsl/gsl_errno.h>
#include <compile.h>
#include <frameobject.h>


enum handleflag {
     HANDLE_ERROR = 0,
     HANDLE_WARNING
};

static int
PyGSL_internal_error_handler(const char *reason, /* name of function*/
			     const char *file, /*from CPP*/
			     int line,   /*from CPP*/
			     int gsl_error,
			     enum handleflag flag);

static int  
PyGSL_error_flag(long flag)
{
     FUNC_MESS_BEGIN();
     if(PyGSL_DEBUG_LEVEL() > 2){
	  fprintf(stderr,"I got an Error %ld\n", flag);
     }
     if(PyErr_Occurred()){
	     DEBUG_MESS(3, "Already a python error registered for flag %ld", flag);
	     return GSL_FAILURE;
     }
     if(flag>0){
	  /* 
	   * How can I end here without an Python error? 
	   *
	   * 25. October 2008
	   * Well, very simply when the GSL_ERROR_HANDLER is set to off. 
	   *
	   * All GSL modules are
	   * supposed to call GSL_ERROR which should call the default error
	   * handler.
	   *
	   * 25. October 2008
	   * No not when the handler is set to off, which is necessary in 
	   * a threaded python. That's why it was a bad idea to call the
	   * gsl_error_handler here!
	   */
	  /*
	   * gsl_error("Unknown Reason. It was not set by GSL.",  __FILE__, 
	   *	    __LINE__, flag);
	  */
	  PyGSL_internal_error_handler("Unknown Reason. It was not set by GSL",  __FILE__, 
				       __LINE__, flag, HANDLE_ERROR);
	  /* 
	   * So lets keep the flag to return ... who knows what it will be used for...
	   * return GSL_FAILURE;
	   */
	  return flag;
     }
     FUNC_MESS_END();
     return GSL_SUCCESS;
}

static PyObject * 
PyGSL_error_flag_to_pyint(long flag)
{
     PyObject * result = NULL;
     FUNC_MESS_BEGIN();
     if(GSL_FAILURE == PyGSL_error_flag(flag)){
	  return NULL;
     }
     result = PyInt_FromLong((long) flag);
     FUNC_MESS_END();

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


#define PyGSL_ERRNO_MAX 32
static PyObject * errno_accel[PyGSL_ERRNO_MAX];
static PyObject * error_dict = NULL;
static PyObject * warning_dict = NULL;
static PyObject * unknown_error = NULL;

static void
PyGSL_print_accel_object(void)
{
     int i;
     FUNC_MESS_BEGIN();
     for(i = 0; i<PyGSL_ERRNO_MAX; ++i){
	  DEBUG_MESS(4, "errno_accel[%d] = %p", i, (void*)(errno_accel[i]));
     }
     FUNC_MESS_END();
}

static int
PyGSL_register_accel_err_object(PyObject * err_ob, long test_errno)
{
     PyObject *tmp;

     FUNC_MESS_BEGIN();
     assert(err_ob);
     tmp = errno_accel[test_errno];
     if(tmp != NULL){
	  PyErr_Format(PyExc_ValueError, 
		       "In errno_accel: errno %ld already occupied with object %p!\n",
		       test_errno, (void *) tmp);
	  return -2;
     }
     Py_INCREF(err_ob);
     errno_accel[test_errno] = err_ob;
     FUNC_MESS_END();
     return 0;
}

/* register an error object to the Python dictionary */
static int
_PyGSL_register_err_object(PyObject *dict, PyObject * err_ob, PyObject *the_errno)
{
     PyObject *test;

     FUNC_MESS_BEGIN();
     assert(error_dict);
     test = PyDict_GetItem(dict, the_errno);
     if(test != NULL){
	  PyErr_Format(PyExc_ValueError, 
		       "In dict %p: key %p already occupied with object %p!\n",
		       dict, the_errno, (void *) test);
	  return -2;
     }
     Py_INCREF(err_ob);
     PyDict_SetItem(dict, the_errno, err_ob);
     FUNC_MESS_END();
     return 0;
}

/* register an error object */
static int
_PyGSL_register_error(PyObject *dict, int errno_max, PyObject * err_ob)
{
     PyObject *tmp, *name;
     long test_errno;
     int flag; 
     char * c_name;

     FUNC_MESS_BEGIN();
     assert(err_ob);
     tmp = PyObject_GetAttrString(err_ob, "errno");
     if(tmp == NULL){
	  name = PyObject_GetAttrString(err_ob, "__name__");

	  if(name == NULL) 
	       c_name = "unknown name";
	  else if (!PyString_Check(name))
	       c_name = "name not str object!";	       
	  else	       
	       c_name = PyString_AsString (name);

	  fprintf(stderr, "failed to get errno from err_ob '%s' @ %p\n",
		  c_name, (void *) err_ob);
	  PyErr_Format(PyExc_AttributeError,
		       "err_ob '%s' @ %p missed attribue 'errno!'\n", c_name,
		       err_ob);
	  return -1;
     }
     
     if(!PyInt_CheckExact(tmp)){
	  fprintf(stderr, "errno %p from err_ob %p was not an exact int!\n", 
		  (void *) tmp, (void *) err_ob);
	  PyErr_Format(PyExc_TypeError, "errno %p from err_ob %p was not an exact int!\n",
		       (void *) tmp, (void *) err_ob);
	  return -1;
     }

     test_errno = PyInt_AsLong(tmp);
     if((dict == error_dict) && (test_errno < PyGSL_ERRNO_MAX)){
	  flag = PyGSL_register_accel_err_object(err_ob, test_errno);
     }else{
	  flag = _PyGSL_register_err_object(dict, err_ob, tmp);
     }	       
     if(flag != 0)
	  fprintf(stderr, "Failed to register err_ob %p with errno %ld.\n" 
		  "\tAlready registered?\n", err_ob, test_errno);
     FUNC_MESS_END();
     return flag;
}

static PyObject*
PyGSL_register_error_objs(PyObject *self, PyObject *args, PyObject *dict, int errno_max)
{
     int flag, i, len;
     PyObject *tmp;

     FUNC_MESS_BEGIN();     
     if(!PySequence_Check(args))
	  return NULL;

     len = PySequence_Size(args);
     DEBUG_MESS(5, "Recieved %d error objects", len);
     for(i = 0; i < len; ++i){
	  tmp = PySequence_GetItem(args, i);
	  flag = _PyGSL_register_error(dict, errno_max, tmp);
	  if(flag != 0){
	       fprintf(stderr, "Failed to register error object %d\n", i);
	       return NULL;
	  }
     }
     PyGSL_print_accel_object();
     
     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;
}

static PyObject*
PyGSL_register_warnings(PyObject *self, PyObject *args)
{
     PyObject *tmp;
     FUNC_MESS_BEGIN();
     tmp = PyGSL_register_error_objs(self, args, warning_dict, 0);    
     FUNC_MESS_END();
     return tmp;
}

static PyObject*
PyGSL_register_exceptions(PyObject *self, PyObject *args)
{
     PyObject *tmp;
     FUNC_MESS_BEGIN();
     tmp = PyGSL_register_error_objs(self, args, error_dict, PyGSL_ERRNO_MAX);
     FUNC_MESS_END();
     return tmp;
}


static PyObject *
PyGSL_get_error_object(int the_errno, PyObject ** accel, int accel_max, PyObject *dict)
{
     PyObject *tmp;

     FUNC_MESS_BEGIN();
     assert(the_errno >= 0);
     if (the_errno < accel_max){
	  DEBUG_MESS(4, "Trying to get an error object from accel array at %p",
		     (void*) accel);
	  tmp = accel[the_errno];
     }else{
	  DEBUG_MESS(4, "Trying to get an error object from dictonary at %p",
		     (void*) dict);
	  tmp =  PyDict_GetItem(dict, PyInt_FromLong(the_errno));
     }
     if(tmp == NULL){
	  DEBUG_MESS(3, "Could not find an error object for errno %d", the_errno);
	  PyGSL_print_accel_object();
	  return unknown_error;
     }
     FUNC_MESS_END();
     return tmp;
}

static int 
PyGSL_init_errno(void)
{
     int i;
     FUNC_MESS_BEGIN();

     for(i = 0; i< PyGSL_ERRNO_MAX; ++i){
	  DEBUG_MESS(3, "setting errno_accel[%d] to NULL; was %p", 
		     i, (void*) (errno_accel[i]));
	  errno_accel[i] = NULL;
     }
     error_dict = PyDict_New();
     if (error_dict == NULL)
	  return -1;

     warning_dict = PyDict_New();
     if (warning_dict == NULL)
	  return -1;

     unknown_error = PyExc_ValueError;
     FUNC_MESS_END();
     return 0;
}



/*
 * Warnings return a flag, so one can see if the warning raises an exception
 *  or not.
 */
static int
PyGSL_internal_error_handler(const char *reason, /* name of function*/
			     const char *file, /*from CPP*/
			     int line,   /*from CPP*/
			     int gsl_error,
			     enum handleflag flag)			     
{
  const char* error_explanation;
  char error_text[255];
  PyObject* gsl_error_object;

  FUNC_MESS_BEGIN();
  /*
   * GSL_ENOMEM is special. I am out of memory. No fancy tricks here.
   */
  if (GSL_ENOMEM == gsl_error){
       PyErr_NoMemory();
       return -1;
  }

  /*
   * some functions call error handler more than once before returning 
   *  report only the first (most specific) error 
   */
  if (line < 0) line = 0;
  /* test, if exception is already set */
  DEBUG_MESS(5, "Checking if python error occured, gsl error %d, line %d", gsl_error, line);
  if (PyErr_Occurred()) {
       if(PyGSL_DEBUG_LEVEL() > 0)
	    fprintf(stderr, "Another error occured: %s\n",error_text);
       FUNC_MESS("Already set python error found");
       return -1;    
  }
  
  /*
   * Find the approbriate error
   */
  error_explanation = gsl_strerror(gsl_error);
  if (reason==NULL){
       reason = "no reason given!";
  }

  if (error_explanation==NULL){
      snprintf(error_text,sizeof(error_text),
	       "unknown error %d: %s",
	       gsl_error, reason);
  }else{
      snprintf(error_text,sizeof(error_text),
	       "%s: %s",
	       error_explanation,reason);
  }


  switch(flag){
  case HANDLE_ERROR:   
       assert(gsl_error > 0);
       gsl_error_object = PyGSL_get_error_object(gsl_error, errno_accel, PyGSL_ERRNO_MAX, error_dict);
       Py_INCREF(gsl_error_object);  
       PyErr_SetObject(gsl_error_object, PyString_FromString(error_text)); 
       FUNC_MESS("Set Python error object");
       return -1;
       break;
  case HANDLE_WARNING:
       assert(gsl_error > 0);
       gsl_error_object = PyGSL_get_error_object(gsl_error, NULL, 0, warning_dict);
       Py_INCREF(gsl_error_object);  
       FUNC_MESS("Returning python warning");
       return PyErr_Warn(gsl_error_object, error_text); 
       break;
  default:
       fprintf(stderr, "Unknown handle %d\n", flag);
  }
  FUNC_MESS("Should not end here!");
  return -1;
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
     FUNC_MESS_BEGIN();
     PyGSL_internal_error_handler(reason, file, line,  gsl_error, HANDLE_ERROR);
     FUNC_MESS_END();
}

static int
PyGSL_warning(const char *reason, /* name of function*/
	      const char *file, /*from CPP*/
	      int line,   /*from CPP*/
	      int gsl_error) /* real "reason" */
{
     int tmp;
     FUNC_MESS_BEGIN();
     tmp =  PyGSL_internal_error_handler(reason, file, line,  gsl_error, HANDLE_WARNING);
     FUNC_MESS_END();
     return tmp;
}
