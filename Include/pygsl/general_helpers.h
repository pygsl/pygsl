#ifndef PyGSL_GENERAL_HELPERS_H
#define PyGSL_GENERAL_HELPERS_H 1

#include <pygsl/utils.h>
#include <Python.h>


typedef struct 
{
     PyObject * callback;
     char     * message;
     char     * error_description;
     /* For callbacks this argnum is used */
     int argnum;
}   
PyGSL_error_info;

int
PyGSL_set_error_string_for_callback(PyGSL_error_info * info);

#define PyGSL_PYFLOAT_TO_DOUBLE(object, result, info)      \
  ( PyFloat_Check((object)) )                              \
  ?                                                        \
   (*(result))   = PyFloat_AsDouble((object)), GSL_SUCCESS \
  :  PyGSL_pyfloat_to_double((object), (result), (info))  

int 
PyGSL_pyfloat_to_double(PyObject *object, double *result, PyGSL_error_info *info);

#define PyGSL_PYLONG_TO_ULONG(object, result, info)        \
  ( PyLong_Check((object)) )                               \
  ?                                                        \
   (*(result))   = PyLong_AsUnsignedLong((object)), GSL_SUCCESS \
  :  PyGSL_pylong_to_ulong((object), (result), (info))  

int 
PyGSL_pylong_to_ulong(PyObject *object, unsigned long *result, PyGSL_error_info *info);

#define PyGSL_PYLONG_TO_UINT(object, result, info)        \
  ( PyLong_Check((object)) )                               \
  ?                                                        \
   (*(result))   = (unsigned int) PyLong_AsUnsignedLong((object)), GSL_SUCCESS \
  :  PyGSL_pylong_to_uint((object),  (result), (info))  

int 
PyGSL_pylong_to_uint(PyObject *object, unsigned int *result, PyGSL_error_info *info);

/*
 * Checks following conditions:
 *  For No Arguments: Got Py_None and No Error
 *  For 1  Argument:  Got an Object, No None  and No Error 
 *         (Is None a legal return for one object? I think so.) On the other hand its a
 *         callback and Conversions are waiting, so its good not to accept None.
 * For 2  Arguments: Got a tuple of approbriate size
 */
#define PyGSL_CHECK_PYTHON_RETURN(object, nargs, info)                              \
  (                                                                                 \
        (  ( (nargs) == 0 ) && ( object ) && ( Py_None == (object) ) && ( !PyErr_Occurred() ) )   \
    ||  (  ( (nargs) == 1 ) && ( object ) && ( Py_None != (object) ) && ( !PyErr_Occurred() ) )   \
    ||  (  ( (nargs) >  1 ) && ( object ) && ( PyTuple_Check((object)) ) &&                       \
                 ( (nargs) == PyTuple_GET_SIZE((object)) ) )                        \
 )                                                                                  \
 ?                                                                                  \
    GSL_SUCCESS                                                                     \
 :                                                                                  \
   PyGSL_check_python_return((object), (nargs), (info))        

int
PyGSL_check_python_return(PyObject *object, int nargs, PyGSL_error_info  *info);

/*
 * PyGSL automatically names objects using their name method. Some names use
 * chars which must not appear in names of python objects. This function 
 * replaces these strings with an other value. E.g. '-' -> '_'
 */
void
PyGSL_clear_name(char *name, int size);
#endif /* PyGSL_GENERAL_HELPERS_H */
