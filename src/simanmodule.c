/**
 * author: Jochen K"upper
 * created: April 2002
 * file: pygsl/src/diffmodule.c
 * $Id$
 *
 * Only works in fixed-size mode (yet).
 * uses default random number generator (for now).
 * A configuration has to be a Numeric array.
 */

#include <Python.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_siman.h>



/* callback functions
 * - python function passed by user
 * - actual C callback
 * - GSL wrapper struct
 */
/* This function type should return the energy of a configuration XP. */
static PyObject *siman_py_efunc = NULL;
static double siman_efunc(void *xp)
{
	PyObject *arglist = Py_BuildValue("(d)", xp);
	PyObject *result;
	double value;
	result = PyEval_CallObject(siman_py_efunc, arglist);
	Py_DECREF(arglist);
	if(! result)
		PyErr_SetString(PyExc_ValueError, "exception in python function.");
	if(! PyArg_Parse(result, "d", &value))
		PyErr_SetString(PyExc_ValueError, "non-Float result form python function.");
	Py_DECREF(result);
	return value;
}
static gsl_siman_Efunc_t siman_gsl_efunc;


/* This function type should modify the configuration XP using a random step
   taken from the generator R, up to a maximium distance of STEP_SIZE. */
static PyObject *siman_py_step = NULL;
static double siman_step(const gsl_rng *r, void *xp, double step_size)
{
	PyObject *arglist = Py_BuildValue("(d)", step_size);
	PyObject *result;
	double value;
	result = PyEval_CallObject(siman_py_step, arglist);
	Py_DECREF(arglist);
	if(! result)
		PyErr_SetString(PyExc_ValueError, "exception in python function.");
	if(! PyArg_Parse(result, "d", &value))
		PyErr_SetString(PyExc_ValueError, "non-Float result form python function.");
	Py_DECREF(result);
	return value;
}
static gsl_siman_step_t siman_gsl_step;


/* This function type should return the distance between two configurations XP
   and YP. */
static PyObject *siman_py_metric = NULL;
static double siman_metric(void *xp, void *yp)
{
	PyObject *arglist = Py_BuildValue("(d)", xp);
	PyObject *result;
	double value;
	result = PyEval_CallObject(siman_py_metric, arglist);
	Py_DECREF(arglist);
	if(! result)
		PyErr_SetString(PyExc_ValueError, "exception in python function.");
	if(! PyArg_Parse(result, "d", &value))
		PyErr_SetString(PyExc_ValueError, "non-Float result form python function.");
	Py_DECREF(result);
	return value;
}
static gsl_siman_metric_t siman_gsl_metric;


/* This function type should print the contents of the configuration XP. */
static PyObject *siman_py_print = NULL;
static double siman_print(void *xp)
{
	PyObject *arglist = Py_BuildValue("(d)", xp);
	PyObject *result;
	double value;
	result = PyEval_CallObject(siman_py_print, arglist);
	Py_DECREF(arglist);
	if(! result)
		PyErr_SetString(PyExc_ValueError, "exception in python function.");
	if(! PyArg_Parse(result, "d", &value))
		PyErr_SetString(PyExc_ValueError, "non-Float result form python function.");
	Py_DECREF(result);
	return value;
}
static gsl_siman_print_t siman_gsl_print;



/* wrapper functions */

static PyObject *siman_solve(PyObject *self, PyObject *args)
{
	PyObject *result;
	PyObject *efunc, *step, *metric, *print, *params;
	gsl_rng_type *T;
	gsl_rng *rng;

	/* python arguments are (efunc, step, metric, print, (params)) */
	if(! PyArg_ParseTuple(args, "OOOOO", &efunc, &step, &metric, &print, &params))
		return NULL;
	if(!(PyCallable_Check(efunc) && PyCallable_Check(step) && PyCallable_Check(metric))) {
		PyErr_SetString(PyExc_TypeError, "first three function parameters must be callable");
		return NULL;
	}

	if(! (PyCallable_Check(print) || (PyNone != print))) {
		PyErr_SetString(PyExc_TypeError, "print-function must be callable if given.");
		return NULL;
	}
	
	/* initialize/assign functions */
	siman_gsl_efunc.function = &siman_efunc;
	siman_gsl_efunc.params = NULL;
	Py_XINCREF(efunc);
	Py_XDECREF(siman_py_efunc);
	siman_py_efunc = efunc;

	siman_gsl_step.function = &siman_step;
	siman_gsl_step.params = NULL;
	Py_XINCREF(step);
	Py_XDECREF(siman_py_step);
	siman_py_step = step;

	siman_gsl_metric.function = &siman_metric;
	siman_gsl_metric.params = NULL;
	Py_XINCREF(metric);
	Py_XDECREF(siman_py_metric);
	siman_py_metric = metric;

	siman_gsl_print.function = &siman_print;
	siman_gsl_print.params = NULL;
	Py_XINCREF(print);
	Py_XDECREF(siman_py_print);
	siman_py_print = print;
	
	/* use default random number generator for now */
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);

	if(PyNone != print)
		gsl_siman_solve(r, &x0, &siman_gsl_efunc, &siman_gsl_step, &siman_gsl_metric,
				&siman_gsl_print, NULL, NULL, NULL, size, params);
	else
		gsl_siman_solve(r, &x0, &siman_gsl_efunc, &siman_gsl_step, &siman_gsl_metric,
				NULL, NULL, NULL, NULL, size, params);

	// result = Py_BuildValue("(dd)", value, abserr);
	return result;
}


/* moduloe initialization */

static PyMethodDef simanMethods[] = {
	{"solve", siman_solve, METH_VARARGS,
	 "Simulated anealing driver."},
	{NULL, NULL} /* Sentinel */
};



DL_EXPORT(void) simandiff(void)
{
	(void)Py_InitModule("siman", simanMethods);
	return;
}



/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
