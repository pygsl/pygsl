#include <gsl/gsl_integration.h>
#include <pygsl/error_helpers.h>
#include <pygsl/function_helpers.h>
#include <setjmp.h>

PyObject *module = NULL;
typedef struct{
	PyObject * callback;
	PyObject * args;
	jmp_buf  buffer;
}pygsl_function_args;


static double 
pygsl_function_callback(double x, void *p)
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


PyObject *
integrate(PyObject *self, PyObject *pyargs)
{
     PyObject *callback = NULL, *args = NULL;
     pygsl_function_args cb_args;
     gsl_function f;
     int flag;
     double a, b, epsabs, epsrel, result, abserr;
     size_t neval;

     if(!PyArg_ParseTuple(args, "Odddd|O", &callback, &a, &b, &epsabs, &epsrel, &args))
	  goto fail;

     if(!Py_Callable(callback)){
	  pygsl_error("First argument must be a callable object!", GSL_EINVAL);
	  goto fail;
     }

     if(args == NULL){
	  args = Py_NONE;
     }

     f.f = pygsl_function_callback;
     f.params = &cb_args;
     cb_args.args = args;
     cb_args.callback = callback;
     flag = gsl_integration_qng (const *F, a, b, epsabs, epsrel, &result, &abserr, &neval)


     if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS)
	  goto fail;

     return Py_BuildValue("(ddi)", result, abserr, neval);

 fail:
     Py_XDECREF(callback);
     Py_XDECREF(args);
     return NULL;
}
void
initintegrate(void)
{
     PyObject *m;

     m=Py_InitModule("integrate", mMethods);
     module = m;
     assert(m);
}
