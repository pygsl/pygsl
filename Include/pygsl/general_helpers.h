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
#endif /* PyGSL_GENERAL_HELPERS_H */
