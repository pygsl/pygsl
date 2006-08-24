#ifndef PYGSL_BLOCK_HELPERS_NUMARRAY_H
#define PYGSL_BLOCK_HELPERS_NUMARRAY_H 1

#ifndef _PyGSL_API_MODULE

#endif /* _PyGSL_API_MODULE */
#define import_array() import_libnumarray()
#define PyArray_Return(obj) ((PyObject *) obj)
#define PyArray_Check(obj)  NA_NumArrayCheck((obj))
/*
 * No special macro conversions here, lets first just use the compiled functions.
 */

#endif  /* PYGSL_BLOCK_HELPERS_NUMARRAY_H */
