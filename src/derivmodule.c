#define PyGSL_DERIV_MODULE
#include "diff_deriv_common.c"






#define DERIV_FUNCTION(name)                                                  \
static PyObject* deriv_ ## name (PyObject *self, PyObject *args)              \
{                                                                            \
     PyObject *tmp = NULL;                                                   \
     FUNC_MESS_BEGIN();                                                      \
     tmp = PyGSL_diff_generic(self, args,  gsl_deriv_ ## name);              \
     if (tmp == NULL){                                                       \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);     \
     }                                                                       \
     FUNC_MESS_END();                                                        \
     return tmp;                                                             \
}

DERIV_FUNCTION(backward)
DERIV_FUNCTION(forward)
DERIV_FUNCTION(central)

	

/* module initialization */
#define PyGSL_DIFF_USAGE  "\n See module doc string for function call description."
static PyMethodDef derivMethods[] = {
	{"backward", deriv_backward, METH_VARARGS,
	 "Computer derivative of |f| at |x| with stepsize |H| using backward differences." \
	 "Returns |value| and |abserr|." PyGSL_DIFF_USAGE},
	{"central", deriv_central, METH_VARARGS,
	 "Computer derivative of |f| at |x| with stepsize |H| using central differences." \
	 "Returns |value| and |abserr|." PyGSL_DIFF_USAGE},
	{"forward", deriv_forward, METH_VARARGS,
	 "Computer derivative of |f| at |x| with stepsize |H| using forward differences." \
	 "Returns |value| and |abserr|."PyGSL_DIFF_USAGE },
	{NULL, NULL} /* Sentinel */
};


static const char deriv_module_doc[] = 
"Numerical differentation \n\
\n\
This module allows to differentiate functions numerically. It provides\n\
the following functions:\n\
         backward\n\
         central\n\
         forward\n\
\n\
All have the same usage:\n\
         func(callback, x, h, [args])\n\
              callback ... foo(x, args):\n\
                               ... some calculation here ...\n\
                               return y\n\
              x        ... the position where to differentate the callback\n\
              h        ... initial step size used to calculate the optimal one\n\
              args     ... additional object to be passed to the function.\n\
                           It is optional. In this case None is passed as\n\
                           args to foo\n\
";


#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.rng",
        NULL,
        -1,
	derivMethods,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif /* PyGSL_PY3K */

#ifdef __cplusplus
extern "C"
#endif

#ifdef PyGSL_PY3K
PyObject *PyInit_deriv(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) initderiv(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
	PyObject *m = NULL, *dict = NULL, *item = NULL;

#ifdef PyGSL_PY3K
	m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
	m = Py_InitModule("deriv", derivMethods);
#endif /* PyGSL_PY3K */

	init_pygsl();
	if (m == NULL)
		return RETVAL;

	dict = PyModule_GetDict(m);
	if (dict == NULL)
		return  RETVAL;
	
	if (!(item = PyGSL_string_from_string(deriv_module_doc))){
		PyErr_SetString(PyExc_ImportError, 
				"I could not generate module doc string!");
		return  RETVAL;
	}
	if (PyDict_SetItemString(dict, "__doc__", item) != 0){
		PyErr_SetString(PyExc_ImportError, 
				"I could not init doc string!");
		return  RETVAL;
	}

	return  RETVAL;
}



/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
