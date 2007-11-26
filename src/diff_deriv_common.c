#include <pygsl/error_helpers.h>
#include <pygsl/function_helpers.h>
#include <pygsl/pygsl_features.h>

#ifdef PyGSL_DERIV_MODULE
#if ( _PYGSL_GSL_HAS_DERIV == 0 )
#error "The deriv module was only introduced by GSL 1.5. You seem to compile against an older verion!"
#endif
#include <gsl/gsl_deriv.h>
#endif /* PyGSL_DERIV_MODULE */

#include <gsl/gsl_diff.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <setjmp.h>
/* 
 * callback functions
 * - python function passed by user
 * - actual C callback
 * - GSL wrapper struct
 */

/* Used for traceback */
static PyObject *module = NULL;

typedef struct{
	PyObject * callback;
	PyObject * args;
	jmp_buf  buffer;
}pygsl_diff_args;


static double 
diff_callback(double x, void *p)
{
	double value;
	int flag;
	pygsl_diff_args *pargs = NULL;

	pargs = (pygsl_diff_args *) p;

	assert(pargs->callback);
	assert(pargs->args);
	flag = PyGSL_function_wrap_helper(x, &value, NULL, pargs->callback,
					  pargs->args, (char *)__FUNCTION__);

	if(GSL_SUCCESS != flag){
		longjmp(pargs->buffer, flag);
		return gsl_nan();
	}
	return value;
}

/* wrapper function */
typedef int pygsl_deriv_func(const gsl_function *, double, double, double *, double *);
typedef int pygsl_diff_func(const gsl_function *, double, double *, double *);

static PyObject *
PyGSL_diff_generic(PyObject *self, PyObject *args, 
#ifndef PyGSL_DIFF_MODULE
		   pygsl_deriv_func func
#else 
		   pygsl_diff_func func
#endif
)
{
	PyObject *result=NULL, *myargs=NULL;
	PyObject *cb=NULL;

	pygsl_diff_args pargs = {NULL, NULL};
	/* Changed to compile using Sun's Compiler */
	gsl_function diff_gsl_callback = {NULL, NULL};




	double x, value, abserr;
	int flag;
#ifndef PyGSL_DIFF_MODULE
	double h;
	if(! PyArg_ParseTuple(args, "Odd|O", &cb, &x, &h, &myargs)){
		return NULL;
	}
#else
	if(! PyArg_ParseTuple(args, "Od|O", &cb, &x, &myargs)){
		return NULL;
	}
#endif

	/* Changed to compile using Sun's Compiler */
	diff_gsl_callback.function = diff_callback;
	diff_gsl_callback.params = (void *) &pargs;

	if(! PyCallable_Check(cb)) {
		PyErr_SetString(PyExc_TypeError, 
				"The first parameter must be callable");
		return NULL;
	}
	Py_INCREF(cb);               /* Add a reference to new callback */

	pargs.callback = cb;        /* Remember new callback */


	/* Did I get arguments? If so handle them */
	if(NULL == myargs){
		Py_INCREF(Py_None);
		pargs.args= Py_None;
	}else{
		Py_INCREF(myargs);
		pargs.args= myargs;
	}

	if((flag=setjmp(pargs.buffer)) == 0){
		/* Jmp buffer set, call the function */
#ifndef PyGSL_DIFF_MODULE
	     flag = func(&diff_gsl_callback, x, h, &value, &abserr);
#else
	     flag = func(&diff_gsl_callback, x, &value, &abserr);	
#endif
	}else{
		DEBUG_MESS(2, "CALLBACK called longjmp! flag =%d", flag);
	}
	
	/* Arguments no longer used */
	Py_DECREF(pargs.args);

	/* Dispose of callback */
	Py_DECREF(pargs.callback);

 
	if(flag != GSL_SUCCESS){
		PyGSL_ERROR_FLAG(flag);
		return NULL;
	}

	result = Py_BuildValue("(dd)", value, abserr);
	return result;
}
