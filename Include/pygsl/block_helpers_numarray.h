#ifndef PYGSL_BLOCK_HELPERS_NUMARRAY_H
#define PYGSL_BLOCK_HELPERS_NUMARRAY_H 1

#ifndef _PyGSL_API_MODULE

#endif /* _PyGSL_API_MODULE */

/*
 * No special macro conversions here, lets first just use the compiled functions.
 */
#define PyGSL_PyArray_PREPARE_gsl_vector_view(object, array_type, flag, num, argnum, info) \
    PyGSL_PyArray_prepare_gsl_vector_view(object, array_type, flag, num, argnum, info)

#define PyGSL_PyArray_PREPARE_gsl_matrix_view(object, array_type, flag, size1, size2, argnum, info) \
    PyGSL_PyArray_prepare_gsl_matrix_view(object, array_type, flag, size1, size2, argnum, info)


#endif  /* PYGSL_BLOCK_HELPERS_NUMARRAY_H */
