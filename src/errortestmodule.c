/*
 *
 * Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 * Date   : 5. October 2003
 * Only used to test the error handling of pygsl.
 */
#include <Python.h>
#include <gsl/gsl_errno.h>
#include <pygsl/error_helpers.h>

static char trigger_doc [] = "Calls gsl_error with the passed error number";
static PyObject *module;

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
     {NULL, NULL, 0, NULL}
};


DL_EXPORT(void) initerrortest(void)
{
     PyObject  *m=NULL;
     
     m = Py_InitModule("errortest", errortestMethods);
     assert(m);
     module = m;

     init_pygsl();
     
     return;
}

