#ifndef PyGSL_ERROR_HELPER_H
#define PyGSL_ERROR_HELPER_H 1
#include <pygsl/intern.h>
#include <pygsl/utils.h>
#include <gsl/gsl_errno.h>
#include <pygsl/errorno.h>

/*
 * 22 Sep. 2009 Pierre Schnizer
 * Uncomment only if trouble with the gsl error handler (e.g. when using
 * Python with threading support (typical ufuncs). At the time of this writing
 * the error handler would call python to find the approbriate python exception
 *
 * So I used to uncomment the macro as well as the function to ensure that 
 * gsl_error was not called any more within the pygsl wrappper
 */
/*
#undef GSL_ERROR
#undef GSL_ERROR_VAL
#undef GSL_ERROR_NULL
#define gsl_error()
*/
/*
 * handle gsl error flags.
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

PyGSL_API_EXTERN int  
PyGSL_error_flag(long flag);

/*
 * Handles gsl_error flags.
 * It differs from the above that it returns the integer. 
 *
 * Negative values mean something like go one with the iteration. These are 
 * converted to an python integer. Positive values flag a problem. These are 
 * converted to python exceptions.
 */
PyGSL_API_EXTERN PyObject * 
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
PyGSL_API_EXTERN void 
PyGSL_add_traceback(PyObject *module, const char *filename, const char *funcname, int lineno);

PyGSL_API_EXTERN int
PyGSL_warning(const char *, const char*, int, int);

#ifndef _PyGSL_API_MODULE
/* Section for modules importing the functions */
#define PyGSL_error_flag           (*(int (*)(long))                                         PyGSL_API[PyGSL_error_flag_NUM])
#define PyGSL_error_flag_to_pyint  (*(PyObject * (*)(long))                                  PyGSL_API[PyGSL_error_flag_to_pyint_NUM])
#define PyGSL_add_traceback        (*(void (*)(PyObject *, const char *, const char *, int)) PyGSL_API[PyGSL_add_traceback_NUM])      
#define PyGSL_warning              (*(int (*)(const char *, const char *, int, int))         PyGSL_API[PyGSL_warning_NUM])

#endif /* _PyGSL_API_MODULE */

#define PyGSL_ERROR_FLAG(flag)                                              \
(((long) flag == GSL_SUCCESS) && (!PyErr_Occurred())) ? GSL_SUCCESS :       \
                     PyGSL_error_flag((long) (flag))

#define PyGSL_ERROR_FLAG_TO_PYINT(flag)                                     \
(((long) flag <= 0) && (!PyErr_Occurred())) ? PyInt_FromLong((long) flag) : \
                     PyGSL_error_flag_to_pyint((long) (flag))

#endif /* PyGSL_ERROR_HELPER_H  */
