/**
 * author: Jochen K"upper
 * created: April 2002
 * file: pygsl/src/diffmodule.c
 * $Id$
 */

#include <gsl/gsl_diff.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <Python.h>
#include <stdio.h>


/* callback functions
 * - python function passed by user
 * - actual C callback
 * - GSL wrapper struct
 */
static PyObject *diff_py_callback = NULL;
static double diff_callback(double x, void *p)
{
	PyObject *arglist = Py_BuildValue("(d)", x);
	PyObject *result;
	double value;
	result = PyEval_CallObject(diff_py_callback, arglist);
	Py_DECREF(arglist);
	if(! result)
		PyErr_SetString(PyExc_ValueError, "exception in python function.");
	if(! PyArg_Parse(result, "d", &value))
		PyErr_SetString(PyExc_ValueError, "non-Float result form python function.");
	Py_DECREF(result);
	return value;
}
static gsl_function diff_gsl_callback;



/* wrapper functions */

static PyObject *diff_backward(PyObject *self, PyObject *args)
{
	PyObject *result;
	PyObject *cb;
	double x, value, abserr;
	diff_gsl_callback.function = &diff_callback;
	diff_gsl_callback.params = NULL;

	if(! PyArg_ParseTuple(args, "Od", &cb, &x))
		return NULL;
	if(! PyCallable_Check(cb)) {
		PyErr_SetString(PyExc_TypeError, "first parameter must be callable");
		return NULL;
	}
	Py_XINCREF(cb);               /* Add a reference to new callback */
	Py_XDECREF(diff_py_callback); /* Dispose of previous callback */
	diff_py_callback = cb;        /* Remember new callback */
	gsl_diff_central(&diff_gsl_callback, x, &value, &abserr);
	result = Py_BuildValue("(dd)", value, abserr);
	return result;
}

	


static PyObject *diff_central(PyObject *self, PyObject *args)
{
	PyObject *result;
	PyObject *cb;
	double x, value, abserr;
	diff_gsl_callback.function = &diff_callback;
	diff_gsl_callback.params = NULL;

	if(! PyArg_ParseTuple(args, "Od", &cb, &x))
		return NULL;
	if(! PyCallable_Check(cb)) {
		PyErr_SetString(PyExc_TypeError, "parameter must be callable");
		return NULL;
	}
	Py_XINCREF(cb);               /* Add a reference to new callback */
	Py_XDECREF(diff_py_callback); /* Dispose of previous callback */
	diff_py_callback = cb;        /* Remember new callback */
	gsl_diff_central(&diff_gsl_callback, x, &value, &abserr);
	result = Py_BuildValue("(dd)", value, abserr);
	return result;
}

	


static PyObject *diff_forward(PyObject *self, PyObject *args)
{
	PyObject *result;
	PyObject *cb;
	double x, value, abserr;
	diff_gsl_callback.function = &diff_callback;
	diff_gsl_callback.params = NULL;

	if(! PyArg_ParseTuple(args, "Od", &cb, &x))
		return NULL;
	if(! PyCallable_Check(cb)) {
		PyErr_SetString(PyExc_TypeError, "parameter must be callable");
		return NULL;
	}
	Py_XINCREF(cb);               /* Add a reference to new callback */
	Py_XDECREF(diff_py_callback); /* Dispose of previous callback */
	diff_py_callback = cb;        /* Remember new callback */
	gsl_diff_forward(&diff_gsl_callback, x, &value, &abserr);
	result = Py_BuildValue("(dd)", value, abserr);
	return result;
}

	

/* moduloe initialization */

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
	return;
}



/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
