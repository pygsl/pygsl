#ifndef _PyGSL_BLOCK_CONVERSION_FUNCTIONS_H_
#define _PyGSL_BLOCK_CONVERSION_FUNCTIONS_H_ 1

/* 
 * Types necessary as changed from defines to typedefs
 */
/*
typedef unsigned char  uchar;
typedef long double    long_double; 
typedef unsigned long  ulong;
typedef unsigned int   uint;
typedef unsigned short ushort;
*/
#include <typemaps/convert_block_description.h>
#define gsl_vector_complex_view_memcpy(dst, src)       gsl_vector_complex_memcpy(dst, src)
#define gsl_vector_complex_float_view_memcpy(dst, src) gsl_vector_complex_float_memcpy(dst, src)
#define gsl_vector_double_view_memcpy(dst, src)        gsl_vector_double_memcpy(dst, src)
#define gsl_vector_float_view_memcpy(dst, src)         gsl_vector_float_memcpy(dst, src)
#define gsl_vector_long_view_memcpy(dst, src)          gsl_vector_long_memcpy(dst, src)
#define gsl_vector_int_view_memcpy(dst, src)           gsl_vector_int_memcpy(dst, src)
#define gsl_vector_short_view_memcpy(dst, src)         gsl_vector_short_memcpy(dst, src)
#define gsl_vector_char_view_memcpy(dst, src)          gsl_vector_char_memcpy(dst, src)
#define gsl_vector_view_memcpy(dst, src)               gsl_vector_memcpy(dst, src)

#define BASIS_TYPE(basetype) \
          basetype ## _basis_type

#define BASIS_C_TYPE(basetype) \
          basetype ## _basis_c_type

/*
 * I have no idea why all these braces are necessary, but apparently they are
 * necessary for correct functioning.
 */

#if 0    
#define PyGSL_VECTOR_CONVERT(input, output, pyvector, vectorview, flag, basetype, argnum, stride)\
   (( \
       ((pyvector =  PyGSL_PyArray_PREPARE_gsl_vector_view(input, basetype ## _py_array_type, \
							  PyGSL_NON_CONTIGUOUS | flag, -1, argnum, NULL)) != NULL) \
     &&  \
	 ((PyGSL_STRIDE_RECALC(pyvector->strides[0], sizeof(basetype ## _basis_type), stride)) == GSL_SUCCESS)\
    ) ? \
	 (vectorview = TYPE_VIEW_ARRAY_STRIDES_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                           *(stride), pyvector->dimensions[0]),\
         output =  (basetype *) &(vectorview.vector), \
	 GSL_SUCCESS) \
     : \
     (GSL_FAILURE))


#define PyGSL_MATRIX_CONVERT(input, output, pyvector, matrixview, flag, basetype, argnum, stride)\
   (( \
       ((pyvector =  PyGSL_PyArray_PREPARE_gsl_matrix_view(input, basetype ## _py_array_type, \
							  PyGSL_CONTIGUOUS | flag, -1, -1, argnum, NULL)) != NULL) \
     &&  \
	 ((PyGSL_STRIDE_RECALC(pyvector->strides[1], sizeof(basetype ## _basis_type), stride)) == GSL_SUCCESS)\
     &&  \
         ((*(stride) == 1)) \
    ) ? \
	 (matrixview = TYPE_VIEW_ARRAY_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                    pyvector->dimensions[0], pyvector->dimensions[1]),\
         output =  (basetype *) &(matrixview.matrix), \
	 GSL_SUCCESS) \
     : \
     (GSL_FAILURE))
#else

#define PyGSL_VECTOR_CONVERT(input, output, pyvector, vectorview, flag, basetype, argnum, stride)\
( \
     ((pyvector =  PyGSL_vector_check(input, -1, \
                  PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | flag,  basetype ## _py_array_type, \
                                         sizeof(basetype ## _basis_type), argnum), \
                  stride, NULL)) != NULL) \
 ? \
	 (vectorview = TYPE_VIEW_ARRAY_STRIDES_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                           *(stride), pyvector->dimensions[0]),\
         output =  (basetype *) &(vectorview.vector), \
	 GSL_SUCCESS) \
     : \
     (GSL_FAILURE))

#define PyGSL_MATRIX_CONVERT(input, output, pyvector, matrixview, flag, basetype, argnum, stride)\
( \
     ( ((pyvector =  PyGSL_matrix_check(input, -1, -1, PyGSL_BUILD_ARRAY_INFO(PyGSL_CONTIGUOUS | flag, \
		   basetype ## _py_array_type, sizeof(basetype ## _basis_type), argnum), NULL, stride, NULL)) != NULL) &&\
         ((*(stride) == 1))) \
 ? \
	 (matrixview = TYPE_VIEW_ARRAY_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                    pyvector->dimensions[0], pyvector->dimensions[1]),\
         output =  (basetype *) &(matrixview.matrix), \
	 GSL_SUCCESS) \
     : \
     (GSL_FAILURE))
#endif
#define PyGSL_VECTOR_GENERATE(input, output, pyvector, vectorview, flag, basetype, argnum, stride)\
   ((\
     ((pyvector = PyGSL_PyArray_generate_gsl_vector_view(input,  basetype ## _py_array_type, argnum)) != NULL) \
   && \
      ((PyGSL_STRIDE_RECALC(pyvector->strides[0], sizeof(basetype ## _basis_type), stride)) == GSL_SUCCESS) \
    )\
    ? \
        (vectorview = TYPE_VIEW_ARRAY_STRIDES_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                                    *(stride), pyvector->dimensions[0]),\
         output =  (basetype *) &(vectorview.vector), \
	 GSL_SUCCESS) \
    : \
        (GSL_FAILURE))

#define PyGSL_MATRIX_GENERATE(input, output, pyvector, matrixview, flag, basetype, argnum, stride)\
   ((\
     ((pyvector = PyGSL_PyArray_generate_gsl_matrix_view(input,  basetype ## _py_array_type, argnum)) != NULL) \
   && \
      ((PyGSL_STRIDE_RECALC(pyvector->strides[1], sizeof(basetype ## _basis_type), stride)) == GSL_SUCCESS) \
   && \
      ((*(stride)) == 1) \
    )\
    ? \
        (matrixview = TYPE_VIEW_ARRAY_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                  pyvector->dimensions[0],pyvector->dimensions[1]),\
                       output =  (basetype *) &(matrixview.matrix), \
	 GSL_SUCCESS) \
    : \
       (GSL_FAILURE))

#define PyGSL_VECTORVIEW_COPY(pyvector, myvector, basetype, vectorview, tmp)\
    ((\
       (tmp = myvector.vector.size) \
     && \
       ((pyvector = (PyArrayObject *) PyGSL_New_Array(1, &tmp,  basetype ## _py_array_type)) != NULL)\
      && \
        ((PyGSL_STRIDE_RECALC(pyvector->strides[0], sizeof(basetype ## _basis_type), &tmp)) == GSL_SUCCESS) \
    )\
      ? \
       (vectorview = TYPE_VIEW_ARRAY_STRIDES_ ## basetype((basetype ## _basis_c_type *) pyvector->data, \
                                                                tmp, pyvector->dimensions[0]),     \
       basetype ## _memcpy(&(vectorview.vector), &(myvector.vector)))\
    :  \
       	  (GSL_FAILURE))


#endif /* _PyGSL_BLOCK_CONVERSION_FUNCTIONS_H_ */
