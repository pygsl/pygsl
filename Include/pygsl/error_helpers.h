#ifndef PyGSL_ERROR_HELPER_H
#define PyGSL_ERROR_HELPER_H 1
#include <pygsl/utils.h>
#include <Python.h>

/*
 * Consider the passed integer as a error flag. 
 * Negative values mean something like go one with the iteration. These are 
 * converted to an python integer. Positive values flag a problem. These are 
 * converted to python exceptions.
 */
#define PyGSL_ERROR_FLAG_TO_PYINT(flag)                                     \
(((long) flag <= 0) && (!PyErr_Occurred())) ? PyInt_FromLong((long) flag) : \
                     PyGSL_error_flag_to_pyint((long) (flag))

PyObject * 
PyGSL_error_flag_to_pyint(long flag);
#endif /* PyGSL_ERROR_HELPER_H  */

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
