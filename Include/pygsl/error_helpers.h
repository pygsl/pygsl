#ifndef PyGSL_ERROR_HELPER_H
#define PyGSL_ERROR_HELPER_H 1
#include <gsl/gsl_errno.h>
#include <pygsl/utils.h>
#include <Python.h>


/*
 * Handle gsl error flags.
 *
 * If a flag arrives check if there was already a python error. If so leave it alone.
 * We cannot return two exceptions. 
 *
 * Otherwise:
 *       Should I put an exception up? E.g. some function not conforming to GSL 
 *       Convention returning a flag, instead of calling gsl_error?
 *       Currently I follow that idea. But I have no more information about the reason
 *       than the flag.
 *
 * Return:
 *       GSL_SUCCESS ... No errornous call
 *       GSL_FAILURE ...    errornous call
 *
 * If you need to return the flag e.g. "int gsl_odeiv_iterate( ... " use 
 * PyGSL_error_flag_to_pyint instead!
 * 
 */
#define PyGSL_ERROR_FLAG(flag)                                              \
(((long) flag == 0) && (!PyErr_Occurred())) ? GSL_SUCCESS :                 \
                     PyGSL_error_flag((long) (flag))

int  
PyGSL_error_flag(long flag);

/*
 * Handles gsl_error flags.
 * It differs from the above that it returns the integer. 
 *
 * Negative values mean something like go one with the iteration. These are 
 * converted to an python integer. Positive values flag a problem. These are 
 * converted to python exceptions.
 */
#define PyGSL_ERROR_FLAG_TO_PYINT(flag)                                     \
(((long) flag <= 0) && (!PyErr_Occurred())) ? PyInt_FromLong((long) flag) : \
                     PyGSL_error_flag_to_pyint((long) (flag))
PyObject * 
PyGSL_error_flag_to_pyint(long flag);


/*
 * Add a Python trace back frame to the python interpreter.
 * Input :
 *     module   ... the module. Pass NULL if not known.
 *     filename ... The filename to list in the stack frame. Pass NULL if not 
 *                  known.
 *     funcname ... The function name to list in the stack frame. Pass NULL if
 *                  not known.
 *     lineno   ... The Linenumber where the error occurred.
 */
void 
PyGSL_add_traceback(PyObject *module, char *filename, char *funcname, int lineno);

void PyGSL_module_error_handler(const char *reason, /* name of function*/
				const char *file,   /*from CPP*/
				int line,          /*from CPP*/
				int gsl_error);    /* real "reason" */

#define init_pygsl()\
{ \
  gsl_set_error_handler (&PyGSL_module_error_handler); \
} 
#endif /* PyGSL_ERROR_HELPER_H  */
