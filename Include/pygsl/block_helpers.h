#ifndef PyGSL_BLOCK_HELPERS_H
#define PyGSL_BLOCK_HELPERS_H 1

/*
 * Author:  Pierre Schnizer
 *
 */

/*****************************************************************************
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!* 
 *!									    !*
 *! Important: If you want to use this library, you must not include 	    !*
 *! <Numeric/arrayobject.h> into any file you want to link against this     !*
 *! library. Instead include this file. In this file PY_ARRAY_UNIQUE_SYMBOL !*
 *! is defined. This define must be the same in all link files. See the     !*
 *! the numeric documentation for further details.			    !*
 *!									    !*
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!* 
 *****************************************************************************/
#define PY_ARRAY_UNIQUE_SYMBOL PyGSL_PY_ARRAY_API

#include <pygsl/utils.h>
#include <Python.h>
#include <Numeric/arrayobject.h>
#include <pygsl/general_helpers.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>


/*
 * PyGSL_PyArray_PREPARE_gsl_vector_view :
 *                                 Check if an array can be treated as vector.
 *
 * It is provided using a macro / function pair. The macro will accept a
 * numpy array and return the pointer to the numpy object if the array is one
 * dimensional and has the required number of elements. Further its 
 * contiguousity is checked. If the object did not fulfill the requirements the
 * function PyGSL_PyArray_prepare_gsl_vector_view is called. This function will
 * try to convert the object, or generate an approbriate error message. If the 
 * conversion is successful it will increase the profile counter 
 * pygsl_profile_vector_transform_counter via the macro 
 * PyGSL_INCREASE_vector_transform_counter().
 *
 * Input : 
 *         object              : a general python object
 *         array_type          : the required C type for the array
 *         contiguous          : 1 the array must be contigous,
 *                               0 discontigous ones are acceptable.
 *         number of elements  : length of the vector, or -1 if no check 
 *                               needed.
 *         argument number     : The argument number. Used for error reporting
 *         info                : a PyGSL_Error_info struct. Used for error 
 *                               reporting during callback evaluation. Pass 
 *                               NULL if not needed.
 *
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 */


#define PyGSL_PyArray_PREPARE_gsl_vector_view(object, array_type, contiguous, num, argnum, info) \
  (                                                                                              \
       ( PyArray_Check((object)) )                                                               \
    && ( ((PyArrayObject *) (object))->nd == 1 )                                                 \
    && ( ((PyArrayObject *) (object))->descr->type_num == (array_type) )                         \
    && ( ( -1 == (num)        )  || ( ((PyArrayObject *) (object))->dimensions[0] == (num) ) )   \
    && ( (  0 == (contiguous) )  || ( ((PyArrayObject *) (object))->flags & CONTIGUOUS     ) )   \
  )                                                                                              \
   ?                                                                                             \
    Py_INCREF( (object) ), ( (PyArrayObject *) (object))                                         \
 :                                                                                               \
    PyGSL_PyArray_prepare_gsl_vector_view(object, array_type, contiguous, num, argnum, info)


PyArrayObject * 
PyGSL_PyArray_prepare_gsl_vector_view(PyObject *src,
				      enum PyArray_TYPES array_type,
				      int contiguous, 
				      int num, int argnum, PyGSL_error_info * info);

/*
 * PyGSL_PyArray_PREPARE_gsl_matrix_view
 *                           Check if an array can be treated as matrix. 
 *
 * It is provided using a macro / function pair. The macro will accept a
 * numpy array and return the pointer to the numpy object if the array is two
 * dimensional and has the required number of elements in both dimensions. 
 * Further its contiguousity is checked. If the object did not fulfill the 
 * requirements the function PyGSL_PyArray_prepare_gsl_matrix_view is called. 
 * This function will try to convert the object or generate an approbriate 
 * error message. If the conversion is successful it will increase the profile
 * counter pygsl_profile_matrix_transform_counter via the macro 
 * PyGSL_INCREASE_matrix_transform_counter().
 *
 * Input : 
 *         PyObject            : a general python object
 *         array_type          : the required C type for the array
 *         contiguous          : 1 the array must be contigous,
 *                               0 discontigous ones are acceptable.
 *         size1               : number of elements in the first dimension, or
 *                                -1 if no check needed.
 *         size2               : number of elements in the second dimension, or
 *                                -1 if no check needed.
 *         argument number     : The argument number. Used for error reporting
 *         info struct         : a PyGSL_Error_info struct. Used for error
 *                               reporting during callback evaluation. Pass
 *                               NULL if not needed.
 *
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 *
 * Important: When the data will be passed to gsl via gsl_matrix_view_array, 
 *            then  you must enforce an contiguous array.
 */

#define PyGSL_PyArray_PREPARE_gsl_matrix_view(object, array_type, contiguous, size1, size2, argnum, info) \
  (                                                                                                       \
       ( PyArray_Check((object)) )                                                                        \
    && ( ( (PyArrayObject *) (object))->nd == 2 )                                                         \
    && ( ( (PyArrayObject *) (object))->descr->type_num == (array_type) )                                 \
    && ( ( -1 == (size1) )       ||  ( ((PyArrayObject *) (object))->dimensions[0] == (size1) ) )         \
    && ( ( -1 == (size2) )       ||  ( ((PyArrayObject *) (object))->dimensions[1] == (size2) ) )         \
    && ( (  0 == (contiguous) )  ||  ( ((PyArrayObject *) (object))->flags & CONTIGUOUS       ) )         \
  )                                                                                                       \
   ?                                                                                                      \
    Py_INCREF( (object) ), ( (PyArrayObject *) (object))                                                  \
 :                                                                                                        \
    PyGSL_PyArray_prepare_gsl_matrix_view(object, array_type, contiguous, size1, size2, argnum, info)

PyArrayObject *
PyGSL_PyArray_prepare_gsl_matrix_view(PyObject *src,
				      enum PyArray_TYPES array_type,
				      int contiguous, 
				      int size1, int size2, int argnum, 
				      PyGSL_error_info * info);


/*
 * PyGSL_PyArray_generate_gsl_vector_view :
 *                                 Generate an new array of given dimensions .
 *
 *  This function will try to convert the object, to a Python integer and 
 *  generate an apropriate one dimensional numpy array.
 *
 * Input : 
 *         object              : a general python object
 *         array_type          : the required C type for the array
 *         argument number     : The argument number. Used for error reporting
 *
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 */
PyArrayObject * 
PyGSL_PyArray_generate_gsl_vector_view(PyObject *src,
				       enum PyArray_TYPES array_type,
				       int argnum);

/*
 * PyGSL_PyArray_generate_gsl_matrix_view :
 *                                 Generate an new array of given dimensions .
 *
 *  This function will try to convert the object, to a sequence of two Python 
 *  integer and generate an apropriate two dimensional numpy array.
 *
 * Input : 
 *         object              : a general python object
 *         array_type          : the required C type for the array
 *         argument number     : The argument number. Used for error reporting
 *
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 */
PyArrayObject * 
PyGSL_PyArray_generate_gsl_matrix_view(PyObject *src,
				       enum PyArray_TYPES array_type,
				       int argnum);

/*
 * PyGSL_copy_pyarray_to_gslvector
 *                           Copy the contents of a pyarray to a gsl_vector.
 *
 *
 * Input :
 *         f                   : a pointer to the target vector
 *         object              : a general python object
 *         n                   : number of elements
 *         info                : a PyGSL_Error_info struct. Used for error
 *                               reporting during callback evaluation. Pass
 *                               NULL if not needed.
 *
 * Output: 
 *                             : GSL_SUCCESS | GSL_FAILURE
 *
 */
int
PyGSL_copy_pyarray_to_gslvector(gsl_vector *f, PyObject *object, int n, 
				PyGSL_error_info * info);

/*
 * PyGSL_copy_pyarray_to_gslmatrix
 *                           Copy the contents of a pyarray to a gsl_matrix.
 *
 *
 * Input :
 *         f                   : a pointer to the target gsl_vector
 *         object              : a general python object referring to a numpy 
 *                               array
 *         n                   : number of elements in the first dimension
 *         p                   : number of elements in the second dimension
 *         info                : a PyGSL_error_info struct. Used for error
 *                               reporting during callback evaluation. Pass
 *                               NULL if not needed.
 *
 * Output: 
 *                             : GSL_SUCCESS | GSL_FAILURE
 *
 */
int
PyGSL_copy_pyarray_to_gslmatrix(gsl_matrix *f, PyObject *object, int n, int p,
				PyGSL_error_info * info);

/*
 * PyGSL_copy_gslvector_to_pyarrary :
 *                Generate a new numpy array of approbriate size and copy the
 *                data of the vector to it.
 *
 *
 * Input : 
 *              x              : a gsl_vector
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 */
PyArrayObject *
PyGSL_copy_gslvector_to_pyarray(const gsl_vector *x);

/*
 * PyGSL_copy_gslmatrix_to_pyarrary :
 *                Generate a new numpy array of approbriate size and copy the
 *                data of the matrix to it.
 *
 *
 * Input : 
 *              x              : a gsl_matrix
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 */
PyArrayObject *
PyGSL_copy_gslmatrix_to_pyarray(const gsl_matrix *x);

#endif /* PyGSL_BLOCK_HELPERS_H */
