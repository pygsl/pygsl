/*
 *
 * Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 * Date   : 5. October 2003
 * Only used to test the error handling of pygsl.
 */
#include <Python.h>
#include <gsl/gsl_errno.h>
#include <pygsl/error_helpers.h>
#include <pygsl/general_helpers.h>

static char trigger_doc [] = "Calls pygsl_error with the passed error number";
static char trigger_gsl_doc [] = 
"Calls gsl_error with the passed error number. This function allows testing if\n\
the gsl_error is off or not.";

static PyObject *module = NULL;

static PyObject*
trigger_save_state(PyObject *self, PyObject *args)
{
	int t_gsl_errno = GSL_SUCCESS;

	FUNC_MESS_BEGIN();
	if (0 == PyArg_ParseTuple(args, "i", &t_gsl_errno)){
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__ - 1);
		return NULL;
	}
	pygsl_error("Triggered safe test!",
		  __FILE__, __LINE__, t_gsl_errno);
	FUNC_MESS_END();
	Py_INCREF(Py_None);
	return (Py_None);
}

static PyObject*
trigger_gsl(PyObject *self, PyObject *args)
{
        int t_gsl_errno = GSL_SUCCESS;

	FUNC_MESS_BEGIN();
	if (0 == PyArg_ParseTuple(args, "i", &t_gsl_errno)){
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__ - 1);
		return NULL;
	}
	/*
	 *
	 * 25. October 2008
	 * set the internal gsl_error_handler to off
	 * 
	 */ 
	gsl_error("Just a test to see what gsl is doing!",
		  __FILE__, __LINE__, t_gsl_errno);
	if (PyGSL_ERROR_FLAG(t_gsl_errno) != GSL_SUCCESS){	
		FUNC_MESS_FAILED();
		return NULL;
	}
	FUNC_MESS_END();
	Py_INCREF(Py_None);
	return (Py_None);
}

enum {
	PyGSL_ERROR_HANDLER_OFF = 0,
	PyGSL_ERROR_HANDLER_MODULE,
	PyGSL_ERROR_HANDLER_UNKNOWN,
};

static PyObject*
select_error_handler(PyObject *self, PyObject *args)
{

	int status = GSL_EFAILED, line = __LINE__, val=0;

	FUNC_MESS_BEGIN();

	status = PyGSL_PYINT_TO_INT(args, &val, NULL);
	if(PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
		line = __LINE__ -1;
		goto fail;
	}
	
	switch(val){
	case  PyGSL_ERROR_HANDLER_OFF:
		gsl_set_error_handler_off();
		break;

	case  PyGSL_ERROR_HANDLER_MODULE:
		gsl_set_error_handler(PyGSL_module_error_handler);
		break;

	default:
		line = __LINE__ -1;
		status = GSL_EINVAL;
		DEBUG_MESS(2, "Do not which error handler to select for value %d", val);
		pygsl_error("Unknown error handler to be selected", __FILE__, line, status);
		goto fail;
		

	}

	if(PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
		line = __LINE__ -1;
		goto fail;
	}
	
	FUNC_MESS_END();
	Py_INCREF(Py_None);
	return Py_None;

 fail:
	PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
	return NULL;

}
static PyObject*
check_installed_error_handler(PyObject *self, PyObject *args)
{
	PyObject *result = NULL;
	gsl_error_handler_t *check = NULL, *check_off = NULL;
	gsl_error_handler_t *module_f  = PyGSL_module_error_handler;
	int val, line = __LINE__;

	FUNC_MESS_BEGIN();

	check = gsl_set_error_handler(NULL);
	gsl_set_error_handler(check);	

	gsl_set_error_handler_off();	
	check_off = gsl_set_error_handler(NULL);

	if(check == check_off){
	  val = PyGSL_ERROR_HANDLER_OFF;
	}else if(check == module_f){
	  val = PyGSL_ERROR_HANDLER_MODULE;
	}else{
	  val = PyGSL_ERROR_HANDLER_UNKNOWN;
	}
	DEBUG_MESS(2, "Error handler = %p. module = %p (%s) off = %p (%s)", 
		   (void *) check,
		   (void *) module_f,  (check == module_f)  ? "true" : "false",
		   (void *) check_off, (check == check_off) ? "true" : "false");

	gsl_set_error_handler(check);	

	result = PyLong_FromLong((long) val);
	if(result == NULL){
	    line = __LINE__ -1;
	    goto fail;
	}
	FUNC_MESS_END();
	return result;

 fail:
	FUNC_MESS_FAILED();
	PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
	return NULL;
}

static PyObject*
trigger(PyObject *self, PyObject *args)
{
	int gsl_errno = GSL_SUCCESS;

	FUNC_MESS_BEGIN();
	if (0 == PyArg_ParseTuple(args, "i", &gsl_errno)){
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__ - 1);
		return NULL;
	}
	/*
	 *
	 * 25. October 2008
	 * set the internal gsl_error_handler to off
	 * 
	 */ 
	pygsl_error("Just a test to see what pygsl is doing!",
		  __FILE__, __LINE__, gsl_errno);
	if (PyGSL_ERROR_FLAG(gsl_errno) != GSL_SUCCESS){	
		FUNC_MESS_FAILED();
		return NULL;
	}
	FUNC_MESS_END();
	Py_INCREF(Py_None);
	return (Py_None);
}

static PyMethodDef errortestMethods[] = {
     /*densities*/
     {"trigger", trigger, METH_VARARGS, trigger_doc},
     {"trigger_gsl", trigger_gsl, METH_VARARGS, trigger_gsl_doc},
     {"trigger_save_test", trigger_save_state, METH_VARARGS, NULL},
     {"check_installed_error_handler", check_installed_error_handler, METH_NOARGS, NULL},
     {"select_error_handler", select_error_handler, METH_O, NULL},
     {NULL, NULL, 0, NULL}
};

#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.init",
        NULL,
        -1,
        errortestMethods,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif 


#ifdef __cplusplus
extern "C"
#endif

#ifdef PyGSL_PY3K
PyMODINIT_FUNC
PyInit_errortest(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) initerrortest(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
  PyObject  *m=NULL;
     
#ifdef PyGSL_PY3K
     m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
     m = Py_InitModule("errortest", errortestMethods);

#endif /* PyGSL_PY3K */
     if(m == NULL)
       return RETVAL;
     
     assert(m);
     module = m;

     {
       PyObject *item=NULL, *dict = NULL;
       int val = 0;
#ifdef PyGSL_SET_GSL_ERROR_HANDLER
       val = PyGSL_SET_GSL_ERROR_HANDLER;
       val = (val == 0) ? 1 : val;
#endif /* PyGSL_SET_GSL_ERROR_HANDLER */
       
       dict = PyModule_GetDict(m);
       if(dict == NULL){
	 goto fail;
       }
       item = PyLong_FromLong(val);
       if(item == NULL){
	 goto fail;
       }       
       if(PyDict_SetItemString(dict, "set_gsl_error_handler_val", item) == -1){
	 goto fail;
       }
     }
     init_pygsl();
     
     return RETVAL;

 fail:
     
#ifdef PyGSL_PY3K
     return NULL;
#else 
     /* void function no return value*/
     return;
#endif 
}

