#ifndef PyGSL_ERROR_HELPER_H
#define PyGSL_ERROR_HELPER_H 1
#include <pygsl/utils.h>
#include <Python.h>

#define PyGSL_ERROR_FLAG_TO_PYINT(flag)                                     \
(((long) flag <= 0) && (!PyErr_Occurred())) ? PyInt_FromLong((long) flag) : \
                     PyGSL_error_flag_to_pyint((long) (flag))
PyObject * 
PyGSL_error_flag_to_pyint(long flag);
#endif /* PyGSL_ERROR_HELPER_H  */
