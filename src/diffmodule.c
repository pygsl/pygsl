/**
 * author: Jochen K"upper
 * created: April 2002
 * file: pygsl/src/diffmodule.c
 * $Id$
 *
 * December 2003: Changes by Pierre Schnizer <schnizer@users.sourceforge.net>
 *     Changed return value to nan, if an error occurs.
 *     Changed the three function into one, adding the function pointer which 
 *     diff to use.
 *     The wrapper now uses PyGSL_function_wrap_helper the common wrapper for 
 *     gsl function
 *
 *     Made all static variables local to the function. So now it should be 
 *     threadsave.
 *
 *     Unfortunatley gsl_function does not allow error reporting. Thus I use
 *     a jmp_buf to get back to the calling function.
 * " <- To Fix Emacs colouring
 */

#include <gsl/gsl_diff.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <Python.h>

#include <pygsl/error_helpers.h>
#include <pygsl/function_helpers.h>
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
					  pargs->args, __FUNCTION__);

	if(GSL_SUCCESS != flag){
		longjmp(pargs->buffer, flag);
		return gsl_nan();
	}
	return value;
}




/* wrapper function */
typedef int pygsl_diff_func(const gsl_function *, double, double *, double *);

static PyObject *
PyGSL_diff_generic(PyObject *self, PyObject *args, pygsl_diff_func func)
{
	PyObject *result=NULL, *myargs=NULL;
	PyObject *cb=NULL;

	pygsl_diff_args pargs = {NULL, NULL};
	/* Changed to compile using Sun's Compiler */
	gsl_function diff_gsl_callback = {NULL, NULL};




	double x, value, abserr;
	int flag;

	/* Changed to compile using Sun's Compiler */
	diff_gsl_callback.function = diff_callback;
	diff_gsl_callback.params = (void *) &pargs;

	if(! PyArg_ParseTuple(args, "Od|O", &cb, &x, &myargs)){
		return NULL;
	}
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
		flag = func(&diff_gsl_callback, x, &value, &abserr);
	}else{
		DEBUG_MESS(2, "CALLBACK called longjmp!");
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


#define DIFF_FUNCTION(name)                                                  \
static PyObject* diff_ ## name (PyObject *self, PyObject *args)              \
{                                                                            \
     PyObject *tmp = NULL;                                                   \
     FUNC_MESS_BEGIN();                                                      \
     tmp = PyGSL_diff_generic(self, args,  gsl_diff_ ## name);               \
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
#define PyGSL_DIFF_USAGE  "\n See module doc string for function call description."
static PyMethodDef diffMethods[] = {
	{"backward", diff_backward, METH_VARARGS,
	 "Computer derivative of |f| at |x| using backward differences." \
	 "Returns |value| and |abserr|." PyGSL_DIFF_USAGE},
	{"central", diff_central, METH_VARARGS,
	 "Computer derivative of |f| at |x| using central differences." \
	 "Returns |value| and |abserr|." PyGSL_DIFF_USAGE},
	{"forward", diff_forward, METH_VARARGS,
	 "Computer derivative of |f| at |x| using forward differences." \
	 "Returns |value| and |abserr|."PyGSL_DIFF_USAGE },
	{NULL, NULL} /* Sentinel */
};


static const char diff_module_doc[] = 
"Numerical differentation \n\
\n\
This module allows to differentiate functions numerically. It provides\n\
the following functions:\n\
         backward\n\
         central\n\
         forward\n\
\n\
All have the same usage:\n\
         func(callback, x, [args])\n\
              callback ... foo(x, args):\n\
                               ... some calculation here ...\n\
                               return y\n\
              x        ... the position where to differentate the callback\n\
              args     ... additional object to be passed to the function.\n\
                           It is optional. In this case None is passed as\n\
                           args to foo\n\
";
DL_EXPORT(void) initdiff(void)
{
	PyObject *m = NULL, *dict = NULL, *item = NULL;

	m = Py_InitModule("diff", diffMethods);
	init_pygsl();
        import_array();
	if (m == NULL)
		return;

	dict = PyModule_GetDict(m);
	if (dict == NULL)
		return;
	
	if (!(item = PyString_FromString(diff_module_doc))){
		PyErr_SetString(PyExc_ImportError, 
				"I could not generate module doc string!");
		return;
	}
	if (PyDict_SetItemString(dict, "__doc__", item) != 0){
		PyErr_SetString(PyExc_ImportError, 
				"I could not init doc string!");
		return;
	}

	return;
}



/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
