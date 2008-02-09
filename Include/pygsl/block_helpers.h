#ifndef PyGSL_BLOCK_HELPERS_H
#define PyGSL_BLOCK_HELPERS_H 1
/*
 * Author:  Pierre Schnizer
 *
 *
 */

/*****************************************************************************
 * The functions in this file are implemented in src/init/block_helpers*     *
 * These functions try to simplify the conversion between the PyArrayObjects *
 * and the gsl_vector and gsl_matrix types. Further they try to provide a    *
 * compatibility layer for the different implementations of the              *
 * PyArrayObjects (Numeric, numarray, numpy). All code using the functions   *
 * must:                                                                     *
 *       Use these functions here :-)					     *
 *       Declare all varibales referencing dimensions and indexing arrays    *
 *       "PyGSL_array_index_t"						     *
 *       Expect these variables to be either of type int or long. This most  *
 *       probable is only noticable on 64bit architectures.		     *
 *****************************************************************************/
/*
#define PY_ARRAY_UNIQUE_SYMBOL PyGSL_PY_ARRAY_API
*/

#ifndef _PyGSL_API_MODULE
/*
 * Not possible to just import the declaration of the PyArrayObject struct. The
 * pointer comes along as well ...
 *
 */
#ifndef PyGSL_IMPORT_ARRAY
#define NO_IMPORT_ARRAY
#endif
#endif  /* _PyGSL_API_MODULE */
#include <pygsl/intern.h>
#include <pygsl/utils.h>
#include <pygsl/general_helpers.h>
#include <limits.h>
/*
 * Build array info out of various parts.
 *
 * array_flag 
 */

#if ULONG_MAX < 0xffffff
#error "unsigned long not big enough for array info"
#else 
typedef unsigned long PyGSL_array_info_t;
#endif



/* typedef Py_ssize_t PyGSL_array_index_t; */
/*
#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#endif
*/
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
/* 
 *  required for 64 bit machines; backward compability. I rather perfer
 *  to declare it as a long as its just my functions.
 *
 *  For now I keep it as the same type as the underlaying array package
 *  uses for its conversions.
 */
#ifdef PyGSL_NUMERIC
typedef int PyGSL_array_index_t;
#endif
#ifdef PyGSL_NUMARRAY
typedef maybelong PyGSL_array_index_t;
#endif
#ifdef PyGSL_NUMPY
/* typedef intp PyGSL_array_index_t; */
typedef npy_intp PyGSL_array_index_t;
#endif 



#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

enum PyGSL_Array_Flags {
     PyGSL_NON_CONTIGUOUS = 0,
     PyGSL_CONTIGUOUS = 1,
     /* Additional flags needed for numarray and numpy */
     PyGSL_INPUT_ARRAY = 2,
     PyGSL_OUTPUT_ARRAY = 4,
     PyGSL_IO_ARRAY = 8,
};

/*
 * Convienience functions for handling the flags
 */
#define PyGSL_GET_ARRAYFLAG(flag) (( (flag) >>  0) & 0x000000ff)
#define PyGSL_GET_ARRAYTYPE(flag) (( (flag) >>  8) & 0x000000ff)
#define PyGSL_GET_TYPESIZE(flag)  (( (flag) >> 16) & 0x000000ff)
#define PyGSL_GET_ARGNUM(flag)    (( (flag) >> 24) & 0x000000ff) 

#define PyGSL_BUILD_ARRAY_INFO(array_flag, array_type, type_size, argnum) \
(\
 (  ((array_flag) & 0x000000ff) <<  0) + \
 (  ((array_type) & 0x000000ff) <<  8) + \
 (  ((type_size)  & 0x000000ff) << 16) + \
 (  ((argnum)     & 0x000000ff) << 24)   \
)

#define PyGSL_DARRAY_INFO(array_flag, argnum)  \
   PyGSL_BUILD_ARRAY_INFO(array_flag, PyArray_DOUBLE, sizeof(double), argnum) 
#define PyGSL_DARRAY_CINPUT(argnum)  PyGSL_DARRAY_INFO(PyGSL_CONTIGUOUS     | PyGSL_INPUT_ARRAY, argnum) 
#define PyGSL_DARRAY_INPUT(argnum)   PyGSL_DARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, argnum) 

/*
 * PyGSL_New_Array:
 *                Generate an new array with the specified dimensions.
 *
 *                The numpy backend expects an array of int, whereas 
 *                the numarray backend expects  an array of long
 */
PyGSL_API_EXTERN PyArrayObject *
PyGSL_New_Array(int nd,  PyGSL_array_index_t *dimensions, int type);

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
PyGSL_stride_recalc(PyGSL_array_index_t strides, int basis_type_size,
		    PyGSL_array_index_t * stride_recalc);




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
PyGSL_vector_check(PyObject *src, PyGSL_array_index_t size, PyGSL_array_info_t ainfo,
		   PyGSL_array_index_t *stride, PyGSL_error_info * info);


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
		   PyGSL_array_info_t ainfo,
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
PyGSL_copy_pyarray_to_gslvector(gsl_vector *f, PyObject *object, PyGSL_array_index_t n, 
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
PyGSL_copy_pyarray_to_gslmatrix(gsl_matrix *f, PyObject *object,  PyGSL_array_index_t n,
				PyGSL_array_index_t p, PyGSL_error_info * info);

PyGSL_API_EXTERN PyArrayObject * 
PyGSL_vector_or_double(PyObject *src, PyGSL_array_info_t ainfo, PyGSL_array_index_t size,
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
(*(int (*)(PyGSL_array_index_t, int, PyGSL_array_index_t * ))                                        PyGSL_API[PyGSL_stride_recalc_NUM])
#define  PyGSL_New_Array  \
(*(PyArrayObject * (*)(int, PyGSL_array_index_t *, int))                              PyGSL_API[PyGSL_PyArray_new_NUM])
#define  PyGSL_Copy_Array  \
(*(PyArrayObject * (*)(PyArrayObject *))                               PyGSL_API[PyGSL_PyArray_copy_NUM])
#ifdef NO_PyGSL_LEGACY
#define  PyGSL_PyArray_prepare_gsl_vector_view  \
(*(PyArrayObject * (*)(PyObject *, int, int,  PyGSL_array_index_t, int, PyGSL_error_info *)) \
                                                                     PyGSL_API[PyGSL_PyArray_prepare_gsl_vector_view_NUM])
#define  PyGSL_PyArray_prepare_gsl_matrix_view  \
(*(PyArrayObject * (*)(PyObject *, int, int,  PyGSL_array_index_t, PyGSL_array_index_t, int, PyGSL_error_info *)) \
                                                                     PyGSL_API[PyGSL_PyArray_prepare_gsl_matrix_view_NUM])
#endif /* NO_PyGSL_LEGACY */
#define PyGSL_PyArray_generate_gsl_vector_view \
(*(PyArrayObject *(*)(PyObject *, int, int))          PyGSL_API[PyGSL_PyArray_generate_gsl_vector_view_NUM]) 

#define PyGSL_PyArray_generate_gsl_matrix_view \
(*(PyArrayObject *(*)(PyObject *, int, int))          PyGSL_API[PyGSL_PyArray_generate_gsl_matrix_view_NUM]) 

#define PyGSL_copy_pyarray_to_gslvector \
(*(int (*) (gsl_vector *, PyObject *, PyGSL_array_index_t, PyGSL_error_info *))      PyGSL_API[PyGSL_copy_pyarray_to_gslvector_NUM])
#define PyGSL_copy_pyarray_to_gslmatrix \
(*(int (*) (gsl_matrix *, PyObject *, PyGSL_array_index_t, PyGSL_array_index_t, PyGSL_error_info *)) PyGSL_API[PyGSL_copy_pyarray_to_gslmatrix_NUM])

#define PyGSL_copy_gslvector_to_pyarray \
 (*(PyArrayObject * (*)(const gsl_vector *))                         PyGSL_API[ PyGSL_copy_gslvector_to_pyarray_NUM])

#define PyGSL_copy_gslmatrix_to_pyarray \
 (*(PyArrayObject * (*)(const gsl_matrix *))                         PyGSL_API[ PyGSL_copy_gslmatrix_to_pyarray_NUM])


#define  PyGSL_vector_or_double  \
(*(PyArrayObject * (*)(PyObject *, PyGSL_array_info_t , PyGSL_array_index_t, PyGSL_error_info *)) \
                                                                     PyGSL_API[PyGSL_vector_or_double_NUM])

#define PyGSL_vector_check  \
(*(PyArrayObject * (*) (PyObject *, PyGSL_array_index_t, \
 PyGSL_array_info_t, PyGSL_array_index_t *, PyGSL_error_info *)) \
                                                                      PyGSL_API[PyGSL_vector_check_NUM])

#define PyGSL_matrix_check  \
(*(PyArrayObject * (*) (PyObject *, PyGSL_array_index_t, PyGSL_array_index_t, \
 PyGSL_array_info_t, PyGSL_array_index_t *, PyGSL_array_index_t *, PyGSL_error_info *)) \
                                                                      PyGSL_API[PyGSL_matrix_check_NUM])

#define PyGSL_array_check (*(int (*)(PyObject *))  PyGSL_API[PyGSL_array_check_NUM])
#define PyGSL_array_return(ob) ((PyObject *) ob)
#endif /* _PyGSL_API_MODULE */

#define PyGSL_STRIDE_RECALC(strides, basis_type_size, stride_recalc) \
      ( \
           (((strides) % (basis_type_size)) == 0) \
         ? \
           ( ((*(stride_recalc)) = (strides) / (basis_type_size)), GSL_SUCCESS ) \
         : \
           PyGSL_stride_recalc(strides, basis_type_size, stride_recalc) \
     )
/*
#define PyGSL_DVECTOR_CHECK(src, size, info, stride, info) \
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
