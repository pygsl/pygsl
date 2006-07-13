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
/*
#ifndef PyGSL_IMPORT_ARRAY
#define NO_IMPORT_ARRAY
#endif
*/
/*
#define PY_ARRAY_UNIQUE_SYMBOL PyGSL_PY_ARRAY_API
*/

#include <pygsl/intern.h>
#include <pygsl/utils.h>
#include <pygsl/general_helpers.h>

/* 
 *  required for 64 bit machines; backward compability. I rather perfer
 *  to declare it as a long as its just my functions
 */
#if PY_VERSION_HEX < 0x02050000
typedef long PyGSL_array_index_t;
typedef int Py_ssize_t;
#else 
typedef Py_ssize_t PyGSL_array_index_t;
#endif

#include <pygsl/arrayobject.h>
#ifdef PyGSL_NUMPY
#include <numpy/arrayobject.h>
#endif
#ifdef PyGSL_NUMERIC
#include <Numeric/arrayobject.h>
#endif
#ifdef PyGSL_NUMARRAY
#include <numarray/libnumarray.h>
#endif
#if (!defined PyGSL_NUMPY) && (!defined  PyGSL_NUMERIC) && (!defined PyGSL_NUMARRAY)
#error "Neither numpy nor numarray nor Numeric is defined!"
#endif



#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

enum PyGSL_Array_Flags {
     PyGSL_NON_CONTIGUOUS = 0,
     PyGSL_CONTIGUOUS = 1,
     /* Additional flags needed for numarray */
     PyGSL_INPUT_ARRAY = 2,
     PyGSL_OUTPUT_ARRAY = 4,
     PyGSL_IO_ARRAY = 8,
};

/*
 * PyGSL_New_Array:
 *                Generate an new array with the specified dimensions.
 *
 *                The numpy backend expects an array of int, whereas 
 *                the numarray backend expects  an array of long
 */
PyGSL_API_EXTERN PyArrayObject *
PyGSL_New_Array(int nd, int *dimensions, int type);

/*
 * PyGSL_Copy_Array:
 *
 *                 Copy an array. The output array will have the same
 *                 size as the input array.
 */
PyGSL_API_EXTERN PyArrayObject *
PyGSL_Copy_Array(PyArrayObject *, int type);

/*
 * PyGSL_STRIDE_RECALC:
 *                                Recalc a stride and check if it is okay
 *
 * Numpy calculates strides in bytes, gsl as multiple of the basis type size
 *
 * Return value:
 *         -1: Conversion Failed
 *         pos : recalculated stride
 */
PyGSL_API_EXTERN int 
PyGSL_stride_recalc(int strides, int basis_type_size, int * stride_recalc);


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
 *         contiguous          : 2 copy the original array
 *                               1 the array must be contigous,
 *                               0 discontigous ones are acceptable.
 *         size                : length of the vector, or -1 if no check 
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
PyGSL_API_EXTERN PyArrayObject * 
PyGSL_PyArray_prepare_gsl_vector_view(PyObject *src,
				      int array_type,
				      int flag, 
				      long size, int argnum, PyGSL_error_info * info);

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
 *         contiguous          : 2 make a copy of that array!
 *                               1 the array must be contigous,
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


PyGSL_API_EXTERN PyArrayObject *
PyGSL_PyArray_prepare_gsl_matrix_view(PyObject *src,
				      int array_type,
				      int flag, 
				      long size1, long size2, int argnum, 
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
PyGSL_API_EXTERN PyArrayObject * 
PyGSL_PyArray_generate_gsl_vector_view(PyObject *src,
				       int array_type,
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
PyGSL_API_EXTERN PyArrayObject * 
PyGSL_PyArray_generate_gsl_matrix_view(PyObject *src,
				       int array_type,
				       int argnum);

/*
 * Check if a python object can be used as a vector. If so return an
 *  approbriate python array object.
 *
 *
 * Input:
 *      src        ... the python object
 *      size       ... the required size. Pass -1 if it should not be checked.
 *
 *      array_type ... the required type.
 *      flag       ... shall be an input or output or inout array?
 *                 ... shall it be contiguous?
 *      argnum     ... the positional argument number. Used when reporting an
 *                     error
 *      
 *                     Information if the stride of the vector should be
 *                     recalulated to the native C type.
 *      type_size  ... the size of the native C type (typically sizeof(type)).
 *                     If stride is NULL this value is without meaning.
 *
 *      *stride    ... the recalculated stride. If NULL stride will not be
 *                      recalulated, and the following items can be of any value
 *
 *      info       ... info structure passed by callbacks for reporting an error
 *
 *     Convienience macros:
 *                PyGSL_DVECTOR_CHECK(src, size, flag, argnum, stride, info)
 */
PyGSL_API_EXTERN PyArrayObject *
PyGSL_vector_check(PyObject *src, PyGSL_array_index_t size, int array_type,
		   int flag, int argnum,  int type_size, int *stride,
		   PyGSL_error_info * info);


/*
 * Check if a python object can be used as a vector. If so return an
 * approbriate python array object.
 *
 *
 * Input:
 *      src        ... the python object
 *
 *      size1      ... the required size of the first dimension.  Pass -1 if it
 *                     should not be checked.
 *      size2     ...  the required size of the second dimension. Pass -1 if it
 *                     should not be checked.
 *
 *      array_type ... the required type.
 *      flag       ... shall be an input or output or inout array?
 *                     shall it be contiguous?
 *      argnum     ... the positional argument number. Used when reporting an
 *                     error
 *      
 *                     Information if the stride of the vector should be 
 *                     recalulated to the native C type.
 *      type_size  ... the size of the native C type (typically sizeof(type)).
 *                     If stride is NULL this value is without meaning.
 *
 *      *stride1   ... the recalculated stride. If NULL stride will not be
 *                      recalulated, and the following items can be of any value
 *      *stride2   ... the recalculated stride. If NULL stride will not be
 *                      recalulated, and the following items can be of any value
 *
 *      info       ... info structure passed by callbacks for reporting an error
 *
 *     Convienience macros:
 *       PyGSL_DMATRIX_CHECK(src, size1, size2, flag, argnum, stride1, stride2, info)
 */
PyGSL_API_EXTERN PyArrayObject *
PyGSL_matrix_check(PyObject *src, PyGSL_array_index_t size1, PyGSL_array_index_t size2, 
		   int array_type, int type_size, int flag, int argnum,
		   PyGSL_array_index_t *stride1, PyGSL_array_index_t *stride2,
		   PyGSL_error_info * info);

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
PyGSL_API_EXTERN int
PyGSL_copy_pyarray_to_gslvector(gsl_vector *f, PyObject *object, long n, 
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
PyGSL_API_EXTERN int
PyGSL_copy_pyarray_to_gslmatrix(gsl_matrix *f, PyObject *object, long n, long p,
				PyGSL_error_info * info);

PyGSL_API_EXTERN PyArrayObject * 
PyGSL_vector_or_double(PyObject *src, int flag, long size, int argnum,
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
PyGSL_API_EXTERN PyArrayObject *
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
PyGSL_API_EXTERN PyArrayObject *
PyGSL_copy_gslmatrix_to_pyarray(const gsl_matrix *x);
#ifndef _PyGSL_API_MODULE
#define PyGSL_stride_recalc \
(*(int (*)(int, int, int * ))                                        PyGSL_API[PyGSL_stride_recalc_NUM])
#define  PyGSL_New_Array  \
(*(PyArrayObject * (*)(int, int *, int))                              PyGSL_API[PyGSL_PyArray_new_NUM])
#define  PyGSL_Copy_Array  \
(*(PyArrayObject * (*)(PyArrayObject *))                               PyGSL_API[PyGSL_PyArray_copy_NUM])
#define  PyGSL_PyArray_prepare_gsl_vector_view  \
(*(PyArrayObject * (*)(PyObject *, enum PyArray_TYPES, int,  long, long, PyGSL_error_info *)) \
                                                                     PyGSL_API[PyGSL_PyArray_prepare_gsl_vector_view_NUM])
#define  PyGSL_PyArray_prepare_gsl_matrix_view  \
(*(PyArrayObject * (*)(PyObject *, enum PyArray_TYPES, int,  long, long, int, PyGSL_error_info *)) \
                                                                     PyGSL_API[PyGSL_PyArray_prepare_gsl_matrix_view_NUM])
#define PyGSL_PyArray_generate_gsl_vector_view \
(*(PyArrayObject *(*)(PyObject *, enum PyArray_TYPES, int))          PyGSL_API[PyGSL_PyArray_generate_gsl_vector_view_NUM]) 

#define PyGSL_PyArray_generate_gsl_matrix_view \
(*(PyArrayObject *(*)(PyObject *, enum PyArray_TYPES, int))          PyGSL_API[PyGSL_PyArray_generate_gsl_matrix_view_NUM]) 

#define PyGSL_copy_pyarray_to_gslvector \
(*(int (*) (gsl_vector *, PyObject *, long, PyGSL_error_info *))      PyGSL_API[PyGSL_copy_pyarray_to_gslvector_NUM])
#define PyGSL_copy_pyarray_to_gslmatrix \
(*(int (*) (gsl_matrix *, PyObject *, long, long, PyGSL_error_info *)) PyGSL_API[PyGSL_copy_pyarray_to_gslmatrix_NUM])

#define PyGSL_copy_gslvector_to_pyarray \
 (*(PyArrayObject * (*)(const gsl_vector *))                         PyGSL_API[ PyGSL_copy_gslvector_to_pyarray_NUM])

#define PyGSL_copy_gslmatrix_to_pyarray \
 (*(PyArrayObject * (*)(const gsl_matrix *))                         PyGSL_API[ PyGSL_copy_gslmatrix_to_pyarray_NUM])         

#define  PyGSL_vector_or_double  \
(*(PyArrayObject * (*)(PyObject *, int,  long, int, PyGSL_error_info *)) \
                                                                     PyGSL_API[PyGSL_vector_or_double_NUM])

#endif /* _PyGSL_API_MODULE */

#define PyGSL_STRIDE_RECALC(strides, basis_type_size, stride_recalc) \
           (((strides) % (basis_type_size)) == 0) \
         ? \
           ((*(stride_recalc)) = (strides) / (basis_type_size)), GSL_SUCCESS \
         : \
           PyGSL_stride_recalc(strides, basis_type_size, stride_recalc)

/*
#define PyGSL_DVECTOR_CHECK(src, size, flag, argnum, stride, info) \
PyGSL_vector_check(src, size, PyArray_DOUBLE, sizeof(double), flag, argnum, stride, info)

#define PyGSL_DMATRIX_CHECK(src, size1, size2, flag, argnum, stride1, stride2, info) \
PyGSL_vector_check(src, size1, size2, PyArray_DOUBLE, sizeof(double), flag, argnum, stride1, stride2, info)
*/

#ifdef PyGSL_NUMPY
#include <pygsl/block_helpers_numpy.h>
#endif

#ifdef PyGSL_NUMERIC
#include <pygsl/block_helpers_numeric.h>
#endif

#ifdef PyGSL_NUMARRAY
#include <pygsl/block_helpers_numarray.h>
#endif

#endif /* PyGSL_BLOCK_HELPERS_H */
