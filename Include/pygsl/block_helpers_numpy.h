#ifndef PYGSL_BLOCK_HELPERS_NUMPY_H
#define PYGSL_BLOCK_HELPERS_NUMPY_H 1

#ifndef _PyGSL_API_MODULE
#undef  PyGSL_New_Array
#define PyGSL_New_Array(nd, dimensions, type) \
        PyArray_FromDims(nd, dimensions, type)
#endif /* _PyGSL_API_MODULE */

/*
 * Numarray can handle more flags than numpy, lets single the one out, which are not needed here
 */
#define PyGSL_NUMPY_FLAGS 0x000000000001
#define PyGSL_PyArray_PREPARE_gsl_vector_view(object, array_type, contiguous, num, argnum, info) \
  (                                                                                              \
       ( PyArray_Check((object)) )                                                               \
    && ( ((PyArrayObject *) (object))->nd == 1 )                                                 \
    && ( ((PyArrayObject *) (object))->descr->type_num == (array_type) )                         \
    && ( ((PyArrayObject *) (object))->data != (NULL) )                                          \
    && ( ( -1 == (num)        )  || ( ((PyArrayObject *) (object))->dimensions[0] == (num) ) )   \
    && ( (  0 == (contiguous) )  || ( ((PyArrayObject *) (object))->flags & (CONTIGUOUS& PyGSL_NUMPY_FLAGS)))\
  )                                                                                              \
   ?                                                                                             \
    Py_INCREF( (object) ), ( (PyArrayObject *) (object))                                         \
 :                                                                                               \
    PyGSL_PyArray_prepare_gsl_vector_view(object, array_type, contiguous, num, argnum, info)

#define PyGSL_PyArray_PREPARE_gsl_matrix_view(object, array_type, contiguous, size1, size2, argnum, info) \
  (                                                                                                       \
       ( PyArray_Check((object)) )                                                                        \
    && ( ( (PyArrayObject *) (object))->nd == 2 )                                                         \
    && ( ( (PyArrayObject *) (object))->descr->type_num == (array_type) )                                 \
    && ( ( (PyArrayObject *) (object))->data != (NULL) )                                                  \
    && ( ( -1 == (size1) )       ||  ( ((PyArrayObject *) (object))->dimensions[0] == (size1) ) )         \
    && ( ( -1 == (size2) )       ||  ( ((PyArrayObject *) (object))->dimensions[1] == (size2) ) )         \
    && ( (  0 == (contiguous) )  ||  ( ((PyArrayObject *) (object))->flags & (CONTIGUOUS & PyGSL_NUMPY_FLAGS)))\
  )                                                                                                       \
   ?                                                                                                      \
    Py_INCREF( (object) ), ( (PyArrayObject *) (object))                                                  \
 :                                                                                                        \
    PyGSL_PyArray_prepare_gsl_matrix_view(object, array_type, contiguous, size1, size2, argnum, info)

#endif  /* PYGSL_BLOCK_HELPERS_NUMPY_H */
