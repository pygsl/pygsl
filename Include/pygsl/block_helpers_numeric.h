#ifndef PYGSL_BLOCK_HELPERS_NUMPY_H
#define PYGSL_BLOCK_HELPERS_NUMPY_H 1

#ifndef _PyGSL_API_MODULE
#if 0
#undef  PyGSL_New_Array
#define PyGSL_New_Array(nd, dimensions, type) \
        PyArray_FromDims(nd, dimensions, type)
#endif
#endif /* _PyGSL_API_MODULE */

/*
 * Numarray and numpy can handle more flags than Numeric, lets single the one out, which are not needed here
 */

#endif  /* PYGSL_BLOCK_HELPERS_NUMPY_H */
