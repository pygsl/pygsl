/**
 * author: Jochen K"upper
 * created: April 2002
 * file: pygsl/src/diffmodule.c
 * $Id$
 *
 * December 2003: Changes by Pierre Schnizer <schnizer@users.sourceforge.net>
 *     Changed return value to nan, if an error occurs.
 *     Changed the three function into one, adding the function pointer which diff to use.
 *     The wrapper now uses PyGSL_function_wrap_helper the common wrapper for gsl functions.
 * " <- To Fix Emacs colouring
 */

#include <gsl/gsl_diff.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <Python.h>
#include <stdio.h>
#include <pygsl/error_helpers.h>
#include <pygsl/function_helpers.h>

/* callback functions
 * - python function passed by user
 * - actual C callback
 * - GSL wrapper struct
 */

/* Used for traceback */
static PyObject *module = NULL;
static PyObject *diff_py_callback = NULL;

static double diff_callback(double x, void *p)
{
	double value;
	int flag;

	Py_INCREF(Py_None);
	Py_DECREF(Py_None);

	flag = PyGSL_function_wrap_helper(x, &value, NULL, diff_py_callback, Py_None, __FUNCTION__);
	if(GSL_SUCCESS != flag){
		return gsl_nan();
	}
	return value;
}
static gsl_function diff_gsl_callback;



/* wrapper functions */

typedef int pygsl_diff_func(const gsl_function *, double, double *, double *);
static PyObject *diff_generic(PyObject *self, PyObject *args, pygsl_diff_func func)
{
	PyObject *result;
	PyObject *cb;
	double x, value, abserr;
	diff_gsl_callback.function = &diff_callback;
	diff_gsl_callback.params = NULL;

	if(! PyArg_ParseTuple(args, "Od", &cb, &x))
		return NULL;
	if(! PyCallable_Check(cb)) {
		PyErr_SetString(PyExc_TypeError, "The first parameter must be callable");
		return NULL;
	}
	Py_XINCREF(cb);               /* Add a reference to new callback */
	Py_XDECREF(diff_py_callback); /* Dispose of previous callback */
	diff_py_callback = cb;        /* Remember new callback */
	func(&diff_gsl_callback, x, &value, &abserr);
	result = Py_BuildValue("(dd)", value, abserr);
	return result;
}


#define DIFF_FUNCTION(name)                                                  \
static PyObject* diff_ ## name (PyObject *self, PyObject *args)              \
{                                                                            \
     PyObject *tmp = NULL;                                                   \
     FUNC_MESS_BEGIN();                                                      \
     tmp = diff_generic(self, args,  gsl_diff_ ## name);                     \
     if (tmp == NULL){                                                       \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);     \
     }                                                                       \
     FUNC_MESS_END();                                                        \
     return tmp;                                                             \
}

DIFF_FUNCTION(backward)
DIFF_FUNCTION(forward)
DIFF_FUNCTION(central)

	

/* module initialization */

static PyMethodDef diffMethods[] = {
	{"backward", diff_backward, METH_VARARGS,
	 "Computer derivative of |f| at |x| using backward differences." \
	 "Returns |value| and |abserr|."},
	{"central", diff_central, METH_VARARGS,
	 "Computer derivative of |f| at |x| using central differences." \
	 "Returns |value| and |abserr|."},
	{"forward", diff_forward, METH_VARARGS,
	 "Computer derivative of |f| at |x| using forward differences." \
	 "Returns |value| and |abserr|."},
	{NULL, NULL} /* Sentinel */
};



DL_EXPORT(void) initdiff(void)
{
	(void)Py_InitModule("diff", diffMethods);
	init_pygsl();
	return;
}



/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
