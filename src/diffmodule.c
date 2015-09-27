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

#define PyGSL_DIFF_MODULE
#include "diff_deriv_common.c"

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
#ifdef __cplusplus
extern "C"
#endif

DL_EXPORT(void) initdiff(void)
{
	PyObject *m = NULL, *dict = NULL, *item = NULL;

	m = Py_InitModule("diff", diffMethods);
	init_pygsl();
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
