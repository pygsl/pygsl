#include <pygsl/transition.h>
#include <pygsl/error_helpers.h>
#include <pygsl/string_helpers.h>
#include <pygsl/utils.h>
#include <gsl/gsl_errno.h>
#include <compile.h>
#include <frameobject.h>


enum handleflag {
     HANDLE_ERROR = 0,
     HANDLE_WARNING
};

static int add_c_tracebacks = 0;

static const char add_c_traceback_frames_doc[]=
"GSL solvers make callbacks to registered python functions at moments often\n\
not expected. Therefore traceback frames were added which are automatically\n\
inserted by the C Code\n\
These traceback frames, however, create a memory leak in the current\n\
implementation. So these are disabled by default and can be enabled by setting\n\
a true value with this function. Setting to 0/False will disable it again\n";
static PyObject *
PyGSL_add_c_traceback_frames(PyObject * self, PyObject *args)
{

	FUNC_MESS_BEGIN();
	if(!PyArg_ParseTuple(args, "i", &add_c_tracebacks))
		return NULL;

	Py_INCREF(Py_None);
	FUNC_MESS_END();
	return Py_None;

}

static int
PyGSL_internal_error_handler(const char *reason, /* name of function*/
			     const char *file, /*from CPP*/
			     int line,   /*from CPP*/
			     int gsl_error,
			     enum handleflag flag);
/*
 * Allows storing the information without calling python states
 * UFuncs release GIL .
 */
#define PYGSL_REASON_BUFFER_N 2048
struct _pygsl_error_state{
  const char * file;
  int line;
  int gsl_errno;
  char reason[PYGSL_REASON_BUFFER_N];
};

typedef struct _pygsl_error_state pygsl_error_state_t;

pygsl_error_state_t save_error_state = {NULL, PyGSL_EINIT, -1};

static void
PyGSL_gsl_error_handler_save_reset(void)
{
	const char reset_msg[] = "no message stored since error save state was reset";
	FUNC_MESS_BEGIN();
	memset(save_error_state.reason, 0, PYGSL_REASON_BUFFER_N);
	strncpy(save_error_state.reason, reset_msg, PYGSL_REASON_BUFFER_N - 2);
	save_error_state.reason[PYGSL_REASON_BUFFER_N - 1] = '\0';
	save_error_state.file = __FILE__;
	save_error_state.line = -1;
	save_error_state.gsl_errno = PyGSL_EINIT;
	FUNC_MESS_END();
}

static PyObject *
PyGSL_pygsl_error_handler_save_reset(PyObject *src, PyObject *args)
{
	PyGSL_gsl_error_handler_save_reset();
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
PyGSL_get_gsl_error_handler_saved_state(PyObject *src, PyObject *args)
{
	PyObject *result = NULL, *r_o = NULL, *f_o = NULL, *l_o = NULL, *e_o = NULL;

	l_o = PyLong_FromLong((long) save_error_state.line);
	if(l_o == NULL){goto fail;}

	e_o = PyLong_FromLong((long) save_error_state.gsl_errno);
	if(e_o == NULL){goto fail;}

	if(save_error_state.reason){
		r_o = PyGSL_string_from_string(save_error_state.reason);
		if(r_o == NULL){goto fail;}
	} else {
		Py_INCREF(Py_None);
		r_o = Py_None;
	}

	if(save_error_state.file){
		f_o = PyGSL_string_from_string(save_error_state.file);
		if(f_o == NULL){goto fail;}
	} else {
		Py_INCREF(Py_None);
		f_o = Py_None;
	}

	result = PyTuple_New(4);
	if(result == NULL){
		goto fail;
	}
	PyTuple_SET_ITEM(result, 0, (PyObject *) r_o);
	PyTuple_SET_ITEM(result, 1, (PyObject *) f_o);
	PyTuple_SET_ITEM(result, 2, (PyObject *) l_o);
	PyTuple_SET_ITEM(result, 3, (PyObject *) e_o);

	return result;

  fail:
	DEBUG_MESS(2, "Failed: reason = %p", r_o);
	Py_XDECREF(r_o);
	Py_XDECREF(f_o);
	Py_XDECREF(l_o);
	Py_XDECREF(e_o);
	return NULL;
}

static void
PyGSL_gsl_error_handler_save(const char *reason, /* name of function*/
			     const char *file, /*from CPP*/
			     int line,   /*from CPP*/
			     int gsl_error)
{
	FUNC_MESS_BEGIN();


	DEBUG_MESS(3, "Storing GSL error: currently saved status  %s@%d: %d, %s",
		   save_error_state.file, save_error_state.line,
		   save_error_state.gsl_errno, save_error_state.reason
		);

	DEBUG_MESS(10, "Storing GSL error:   %s@%d: %d, %s",
		   file, line, gsl_error, reason);

	save_error_state.file = file;
	save_error_state.line = line;
	save_error_state.gsl_errno = gsl_error;

	if(reason){
	  memset(save_error_state.reason, 0, PYGSL_REASON_BUFFER_N);
	  strncpy(save_error_state.reason, reason, PYGSL_REASON_BUFFER_N - 2);
	}else{
	  strncpy(save_error_state.reason, "NULL", PYGSL_REASON_BUFFER_N - 2);
	}
	save_error_state.reason[PYGSL_REASON_BUFFER_N - 1] = '\0';

	DEBUG_MESS(3, "Stored GSL error %s@%d: %d, %s",
		   save_error_state.file, save_error_state.line,
		   save_error_state.gsl_errno, save_error_state.reason
		);
	FUNC_MESS_END();
}


static int
PyGSL_error_flag(long flag)
{
	int status = PyGSL_ANY, requires_saving = 0, last_status = 0, bufmax = 0;
	long l=0;
	PyObject *py_exception = NULL;

	FUNC_MESS_BEGIN();

	DEBUG_MESS(2, "status to handle %ld saved status %d (PyGSL_EINIT %d|PyGSL_ANY %d)\n",
		   flag, save_error_state.gsl_errno, PyGSL_EINIT, PyGSL_ANY);

	/* why that ? */
	/* status = last_status; */
	/* Let's check if the storted status is that relevant .... */
	switch(save_error_state.gsl_errno){
		/* the clean original state */
	case PyGSL_EINIT:
		/*
		 * the (first|last) set did not request to store its flag,
		 * typically used by funtions which are called during clean up.
		 */
		/* yes we have to save the info still */
		requires_saving = 1;

	case PyGSL_ANY:
		DEBUG_MESS(3, "Saved status %d  Setting to flagged %ld",
			   save_error_state.gsl_errno, flag);
		save_error_state.gsl_errno = (int) flag;
		/* do we need to resave the msg ? */
		break;

	default:
		break;
	}

	status = save_error_state.gsl_errno;
	py_exception = PyErr_Occurred();

	/* Let's first clear out the simple cases ... */
	if(flag == save_error_state.gsl_errno){
		/* No surpise here as expected .... */
		if(py_exception){
			/*
			 * a CB can has raised an eception already ...
			 * no extra steps required
			 */
			DEBUG_MESS(3, "Already a python error registered for flag = %ld "
				   "saved status %d. Not honoring requires_saving %d "
				   "as exception already stored",
				   flag, save_error_state.gsl_errno, requires_saving);
			FUNC_MESS_END();
			return status;
		} else { /* pyerr_occurred */
			/*
			 * classical usage ... error state set but no exception
			 * typical for GSL code with the default pygsl error
			 * handler storing all in the save_error_state
			 */
			if(requires_saving){
				DEBUG_MESS(2, "I got a flag %ld. Last status was %d"
					   " Setting save_error_state would be appropriate but no info available",
					   flag, last_status);
			}
			PyGSL_internal_error_handler(save_error_state.reason,
						     save_error_state.file,
						     save_error_state.line,
						     save_error_state.gsl_errno,
						     HANDLE_ERROR);
			PyGSL_gsl_error_handler_save_reset();
			FUNC_MESS_END();
			return status;
		} /* pyerr_occurred */
	}

	/*
	 * Now: last stored status and flag do not match....
	 * So what to do?
	 */

	if(py_exception){
		/*
		 * I prefer to give preference to the exception. I assume that
		 * it was raised before and that the correct errno was lost
		 * somewhere "unwinding the c-stack"
		 */
		DEBUG_MESS(2, "flag %ld != status %d, but PyErr_Occured %p. Thus returning exception",
			   flag, status, (void *) py_exception);
		FUNC_MESS_END();
		return status;
	}

	/*
	 * Here we are now left with a flag not matching sacecd status and
	 * no python exception
	 */

	l =  strlen(save_error_state.reason);
	bufmax = PYGSL_REASON_BUFFER_N - 5;
	l = (l > bufmax) ? bufmax : l;
	save_error_state.reason[l]   = ' ';
	save_error_state.reason[l+1] = '?';
	save_error_state.reason[l+2] = '\0';

	switch(flag){
	case PyGSL_ANY:
		/* None specified. lets used the saved state */
		flag = save_error_state.gsl_errno;
		break;
	default:
		break;
	}
	DEBUG_MESS(2, "called with flag = %ld (!= PyGSL_ANY %d ?)"
		   " NOT MATCHING status %d. Still needs to be understood",
		   flag, PyGSL_ANY, status);
	PyGSL_internal_error_handler(save_error_state.reason, __FILE__, __LINE__, (int) flag, HANDLE_ERROR);
	

	FUNC_MESS_END();
	return status;

#if 0
     if(pyerr_occurred){
	     DEBUG_MESS(3, "Already a python error registered for flag %ld", flag);
	     if (flag == status){
		     DEBUG_MESS(2, "PyErr Occured already: saved status %ld", flag);
		     FUNC_MESS_END();
		     return status;
	     }
	     /*
	      * XXX
	      * perhaps a source of trouble. better to return the current status ...
	      */
	     switch(flag){
	     case PyGSL_ANY:
		     DEBUG_MESS(2, "PyErr Occured already: called with flag = %ld (== PyGSL_ANY)"
				" returning status %d", flag, status);
		     FUNC_MESS_END();
		     return status;
	     default:
		     DEBUG_MESS(2, "PyErr Occured already: called with flag = %ld (!= PyGSL_ANY)"
				"\n\tNOT MATCHING status %d. Still needs to be understood"
				"\n\tsaved message '%s'",
				flag, status, save_error_state.reason);
		     FUNC_MESS_END();
		     return PyGSL_ENOMATCH;
	     }
	     FUNC_MESS_END();
	     return GSL_FAILURE;
     }

     if(flag>0){
	  /*
	   * How can I end here without an Python error?
	   *
	   * 3. April 2016
	   * Or the new PyGSL_gsl_error_handler_save is used. So now the appropriate
	   * message needs to be set up
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
	   /*
	    * better instead: store the info here statically. This is open to
	    * all sorts of race conditions if more than one thread is active.
	    * But still better than no info or crashing the python interpreter
	    */
	  DEBUG_MESS(2, "Called received errno %ld saved was %d", flag, status);
	  if((save_error_state.gsl_errno == flag) || (flag == PyGSL_ANY) ){
		  DEBUG_MESS(2, "called with flag = %ld (PyGSL_ANY = %d)"
			     " returning status %d", flag, PyGSL_ANY,  status);
	  } else {
	          int l, bufmax;
		  DEBUG_MESS(2, "called with flag = %ld (!= PyGSL_ANY?)"
			     " NOT MATCHING status %d. Still needs to be understood",
			     flag, status);
		  l = strlen(save_error_state.reason);
		  bufmax = PYGSL_REASON_BUFFER_N - 5;
		  l = (l > bufmax) ? bufmax : l;
		  save_error_state.reason[l]   = ' ';
		  save_error_state.reason[l+1] = '?';
		  save_error_state.reason[l+2] = '\0';
		  PyGSL_internal_error_handler(save_error_state.reason, __FILE__, __LINE__, flag, HANDLE_ERROR);
		  /*
		   * XXX should one not clear the error here too ?
		   */
	  }
	  /*
	   * So lets keep the flag to return ... who knows what it will be used for...
	   * return GSL_FAILURE;
	   */
	  FUNC_MESS_END();
	  return flag;
     }
     FUNC_MESS_END();
     return GSL_SUCCESS;
#endif
}

static PyObject *
PyGSL_error_flag_to_pyint(long flag)
{
     PyObject * result = NULL;
     FUNC_MESS_BEGIN();
     if(GSL_FAILURE == PyGSL_error_flag(flag)){
	     FUNC_MESS_END();
	     return NULL;
     }
     result = PyLong_FromLong((long) flag);
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

     DEBUG_MESS(2, "module %s file %s func %s @ line %d",
		"", filename, funcname, lineno);

     DEBUG_MESS(2, "add_c_tracebacks = %d = %s",
		add_c_tracebacks, (add_c_tracebacks == 0)? "disabled" : "enabled");
     if (add_c_tracebacks == 0){
	     FUNC_MESS_END();
	     return;
     }

     if(filename == NULL)
	  filename = "file ???";

     if(funcname == NULL)
	  funcname = "function ???";


     /* Use the module if provided */
     if(module == NULL){
	  py_globals = PyDict_New();
     } else {
	  py_globals = PyModule_GetDict(module);
     }
     if (py_globals == NULL)
	  goto fail;

#ifdef PyGSL_PY3K
     py_code = PyCode_NewEmpty(filename, funcname, lineno);
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
     DEBUG_MESS(2, "Added traceback for %s.%s @ %d",
		filename, funcname, lineno);
#else /* PyGSL_Py3K */

     py_srcfile = PyGSL_string_from_string(filename);
     if (py_srcfile == NULL)
	  goto fail;

     py_funcname = PyGSL_string_from_string(funcname);
     if (py_funcname == NULL)
	  goto fail;

     empty_tuple = PyTuple_New(0);
     if (empty_tuple == NULL)
	  goto fail;

     empty_string = PyGSL_string_from_string("");
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
#endif  /* PyGSL_Py3K */

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
	  FUNC_MESS_END();
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
	  FUNC_MESS_END();
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
	PyObject *tmp = NULL, *name = NULL;
	long test_errno;
	int flag;
	char * c_name;

	FUNC_MESS_BEGIN();
	assert(err_ob);
	tmp = PyObject_GetAttrString(err_ob, "errno");
	if(tmp == NULL){
		name = PyObject_GetAttrString(err_ob, "__name__");

		if(name == NULL){
			c_name = "unknown name";
		}else if (!PyGSL_string_check(name)){
			c_name = "name not str object!";
		}else{
			c_name = PyGSL_string_as_string (name);
		}

		fprintf(stderr, "failed to get errno from err_ob '%s' @ %p\n",
			c_name, (void *) err_ob);
		PyErr_Format(PyExc_AttributeError,
			     "err_ob '%s' @ %p missed attribue 'errno!'\n", c_name,
			     err_ob);
		FUNC_MESS_END();
		return -1;
	}

	if(!PyLong_CheckExact(tmp)){
		fprintf(stderr, "errno %p from err_ob %p was not an exact int!\n",
			(void *) tmp, (void *) err_ob);
		PyErr_Format(PyExc_TypeError, "errno %p from err_ob %p was not an exact int!\n",
			     (void *) tmp, (void *) err_ob);
		FUNC_MESS_END();
		return -1;
	}

	test_errno = PyLong_AsLong(tmp);
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
	int flag;
	long len, i;
	PyObject *tmp;

	FUNC_MESS_BEGIN();
	if(!PySequence_Check(args)){
		goto fail;
	}

	len = PySequence_Size(args);
	DEBUG_MESS(5, "Recieved %ld error objects", len);
	for(i = 0; i < len; ++i){
		tmp = PySequence_GetItem(args, i);
		flag = _PyGSL_register_error(dict, errno_max, tmp);
		if(flag != 0){
			fprintf(stderr, "Failed to register error object %ld\n", i);
			goto fail;
		}
	}
	PyGSL_print_accel_object();

	Py_INCREF(Py_None);
	FUNC_MESS_END();
	return Py_None;

  fail:
	FUNC_MESS_FAILED();
	return NULL;

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
	PyObject *tmp = NULL, *ltmp = NULL;

	FUNC_MESS_BEGIN();

	assert(the_errno >= 0);
	if (the_errno < accel_max){
		DEBUG_MESS(4, "Trying to get an error object from accel array at %p",
			   (void*) accel);
		tmp = accel[the_errno];
	}else{
		DEBUG_MESS(4, "Trying to get an error object from dictonary at %p",
			   (void*) dict);
		ltmp = PyLong_FromLong(the_errno);
		if(ltmp == NULL){
			DEBUG_MESS(4, "Failed to create python int from the_errno %d", the_errno);
			goto fail;
		}
		tmp =  PyDict_GetItem(dict, ltmp);
		Py_DECREF(ltmp);
	}

	if(tmp == NULL){
		DEBUG_MESS(3, "Could not find an error object for errno %d", the_errno);
		PyGSL_print_accel_object();
		FUNC_MESS_END();
		return unknown_error;
	}
	FUNC_MESS_END();
	return tmp;

 fail:
	Py_XDECREF(ltmp);
	Py_XDECREF(tmp);
	return NULL;
}

static int
PyGSL_init_errno(void)
{
     int i;
     FUNC_MESS_BEGIN();

     PyGSL_gsl_error_handler_save_reset();

     for(i = 0; i< PyGSL_ERRNO_MAX; ++i){
	  DEBUG_MESS(3, "setting errno_accel[%d] to NULL; was %p",
		     i, (void*) (errno_accel[i]));
	  errno_accel[i] = NULL;
     }
     error_dict = PyDict_New();
     if (error_dict == NULL){
	     FUNC_MESS_END();
	     return -1;
     }

     warning_dict = PyDict_New();
     if (warning_dict == NULL){
	     FUNC_MESS_END();
	     return -1;
     }

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
	char error_text[PYGSL_REASON_BUFFER_N];
	PyObject* gsl_error_object;
	int status;

	FUNC_MESS_BEGIN();
	DEBUG_MESS(5, "Recieved error message: %s @ %s.%d flag = %d\n",
		   reason, file, line, gsl_error);

	/*
	 * GSL_ENOMEM is special. I am out of memory. No fancy tricks here.
	 */
	if (GSL_ENOMEM == gsl_error){
		PyErr_NoMemory();
		FUNC_MESS_END();
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
		DEBUG_MESS(2,  "Another error occured: %s but python exception already set\n",error_text);
		FUNC_MESS_END();
		return -1;
	}

	/*
	 * Find the appropriate error
	 */
	switch(gsl_error){
		/* pygsl error codes */
	case PyGSL_ESTRIDE:
	case PyGSL_EINIT:
	case PyGSL_ANY:
		break;

	default:
		error_explanation = gsl_strerror(gsl_error);
		if (reason==NULL){
			reason = "no reason given!";
		}
	}

	if (error_explanation==NULL){
		snprintf(error_text, PYGSL_REASON_BUFFER_N - 2,
			 "error code %d: %s%c", gsl_error, reason, '\0');
	}else{
		snprintf(error_text, PYGSL_REASON_BUFFER_N - 2,
			 "%s: %s%c", error_explanation, reason, '\0');
	}
	error_text[PYGSL_REASON_BUFFER_N - 1] = '\0';

	switch(flag){
	case HANDLE_ERROR:
		assert(gsl_error > 0);
		gsl_error_object = PyGSL_get_error_object(gsl_error, errno_accel, PyGSL_ERRNO_MAX, error_dict);
		PyErr_SetString(gsl_error_object, error_text);
		DEBUG_MESS(2, "Raising python exception %p with error text %s for gsl_errno %d",
			   (void *) gsl_error_object, error_text, gsl_error);
		FUNC_MESS_END();
		return -1;
		break;

	case HANDLE_WARNING:
		assert(gsl_error > 0);
		gsl_error_object = PyGSL_get_error_object(gsl_error, NULL, 0, warning_dict);
		DEBUG_MESS(2, "Raising python warning %p with error text %s for gsl_errno %d",
			   (void *) gsl_error_object, error_text, gsl_error);
		FUNC_MESS("Returning python warning");
		status = PyErr_Warn(gsl_error_object, error_text);
		FUNC_MESS_END();
		return status;
		break;

	default:
		DEBUG_MESS(2,  "Unknown handle %d\n", flag);
	}

	FUNC_MESS_FAILED();
	DEBUG_MESS(2, "Should not end here! gsl_error code %d", gsl_error);
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

#ifdef _PyGSL_MODULE_ERROR_HANDLER_OLD_STYLE
/* #error "Should not use now ... " */
	PyGSL_internal_error_handler(reason, file, line,  gsl_error, HANDLE_ERROR);
#else  /* _PyGSL_MODULE_ERROR_HANDLER_OLD_STYLE */
/* #error "Should not use now ... " */
	PyGSL_gsl_error_handler_save(reason, file, line,  gsl_error);
#endif /* _PyGSL_MODULE_ERROR_HANDLER_OLD_STYLE */
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
