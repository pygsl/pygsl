#ifndef PyGSL_GENERAL_HELPERS_H
#define PyGSL_GENERAL_HELPERS_H 1

#include <pygsl/intern.h>
#include <pygsl/utils.h>


typedef struct 
{
     /* 
      * The callback object. It is used to retrieve the 
      *  name of the object to inform the user which object
      *  made troubles. 
      */
     PyObject * callback;       
     const char     * message; /* Typically the name of the function */
     const char     * error_description; /* ?? What is this used for */
     /* 
      * For callbacks the number of argument, which is currently converted 
      *	to some C readable type 
      */
     int argnum;
}   
PyGSL_error_info;

PyGSL_API_EXTERN int
PyGSL_set_error_string_for_callback(PyGSL_error_info * info);


PyGSL_API_EXTERN int 
PyGSL_pyfloat_to_double(PyObject *object, double *result, PyGSL_error_info *info);



PyGSL_API_EXTERN  int 										       
PyGSL_pylong_to_ulong(PyObject *object, unsigned long *result, PyGSL_error_info *info);

PyGSL_API_EXTERN int 
PyGSL_pylong_to_uint(PyObject *object, unsigned int *result, PyGSL_error_info *info);

PyGSL_API_EXTERN int 
PyGSL_pyint_to_int(PyObject *object,  int *result, PyGSL_error_info *info);

/*
 * Checks following conditions:
 *  For No Arguments: Got Py_None and No Error
 *  For 1  Argument:  Got an Object, No None  and No Error 
 *         (Is None a legal return for one object? I think so.) On the other hand its a
 *         callback and Conversions are waiting, so its good not to accept None.
 * For 2  Arguments: Got a tuple of approbriate size
 */

PyGSL_API_EXTERN int
PyGSL_check_python_return(PyObject *object, int nargs, PyGSL_error_info  *info);

/*
 * PyGSL automatically names objects using their name method. Some names use
 * chars which must not appear in names of python objects. This function 
 * replaces these strings with an other value. E.g. '-' -> '_'
 */
PyGSL_API_EXTERN void
PyGSL_clear_name(char *name, int size);

#ifndef _PyGSL_API_MODULE
#define PyGSL_set_error_string_for_callback\
  (*(int (*) (PyGSL_error_info *))                            PyGSL_API[PyGSL_error_string_for_callback_NUM])
#define PyGSL_pyfloat_to_double\
 (*(int (*)(PyObject *, double *, PyGSL_error_info *))        PyGSL_API[PyGSL_pyfloat_to_double_NUM])
#define PyGSL_pylong_to_ulong\
 (*(int (*)(PyObject *, unsigned long *, PyGSL_error_info *))  PyGSL_API[PyGSL_pylong_to_ulong_NUM])
#define PyGSL_pylong_to_uint\
 (*(int (*)(PyObject *, unsigned int *, PyGSL_error_info *))   PyGSL_API[PyGSL_pylong_to_uint_NUM])
#define PyGSL_pyint_to_int\
 (*(int (*)(PyObject *, int *, PyGSL_error_info *))   PyGSL_API[PyGSL_pyint_to_int_NUM])
#define PyGSL_check_python_return \
 (*(int (*) (PyObject *object, int, PyGSL_error_info  *))     PyGSL_API[PyGSL_check_python_return_NUM])
#define PyGSL_clear_name          (*(void (*)(char *, int))   PyGSL_API[PyGSL_clear_name_NUM])
#endif /* _PyGSL_API_MODULE */




#define PyGSL_PYLONG_TO_ULONG(object, result, info)        \
  ( PyLong_Check((object)) )                               \
  ?                                                        \
    ((*(result))   = PyLong_AsUnsignedLong((object)), GSL_SUCCESS) \
  :  PyGSL_pylong_to_ulong((object), (result), (info))

#define PyGSL_PYLONG_TO_UINT(object, result, info)        \
  ( PyLong_Check((object)) )                               \
  ?                                                        \
   ((*(result))   = (unsigned int) PyLong_AsUnsignedLong((object)), GSL_SUCCESS) \
  :  PyGSL_pylong_to_uint((object),  (result), (info))  

#define PyGSL_PYINT_TO_INT(object, result, info)        \
  ( PyInt_Check((object)) )                               \
  ?                                                        \
   ((*(result))   = (int) PyInt_AsLong((object)), GSL_SUCCESS) \
  :  PyGSL_pyint_to_int((object),  (result), (info))  

#define PyGSL_PYFLOAT_TO_DOUBLE(object, result, info)      \
  ( PyFloat_Check((object)) )                              \
  ?                                                        \
   ((*(result))   = PyFloat_AsDouble((object)), (GSL_SUCCESS)) \
  :  PyGSL_pyfloat_to_double((object), (result), (info))  

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


#endif /* PyGSL_GENERAL_HELPERS_H */
