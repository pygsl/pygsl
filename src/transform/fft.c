/*
 * The info structures for all the different FFT functions
 */


static struct _pygsl_transform_func_rf_s complex_funcs, halfcomplex_funcs, real_funcs,
	complex_float_funcs, halfcomplex_float_funcs, real_float_funcs;       


/*
 * Describes the type of the transform. 
 */
#define _INIT_INFO(mode, datatype, input_array_type, output_array_type, data_offset, radix2, packed) \
                       {mode, datatype, \
                        input_array_type, output_array_type, \
                        data_offset, radix2, packed}
#define INIT_INFO(mode,  datatype,  inaugment, outaugment, data_offset, radix2, packed) \
       _INIT_INFO(mode, MODE_ ## datatype, PyArray_ ## inaugment ## datatype, \
                     PyArray_  ## outaugment ## datatype, data_offset, radix2, packed)
static struct _pygsl_transform_info_s
complex_info                  = INIT_INFO(ComplexComplex,  DOUBLE, C, C, 0, RADIX_FREE, PACKED_TYPE),
halfcomplex_info              = INIT_INFO(HalfComplexReal, DOUBLE, C,  , 0, RADIX_FREE, SINGLE_TYPE),
real_info                     = INIT_INFO(RealHalfcomplex, DOUBLE,  , C, 1, RADIX_FREE, PACKED_TYPE),
complex_float_info            = INIT_INFO(ComplexComplex,  FLOAT,  C, C, 0, RADIX_FREE, PACKED_TYPE), 
halfcomplex_float_info        = INIT_INFO(HalfComplexReal, FLOAT,  C,  , 0, RADIX_FREE, SINGLE_TYPE),
real_float_info               = INIT_INFO(RealHalfcomplex, FLOAT,   , C, 1, RADIX_FREE, PACKED_TYPE),
complex_info_radix2           = INIT_INFO(ComplexComplex,  DOUBLE, C, C, 0, RADIX_TWO,  PACKED_TYPE),
halfcomplex_info_radix2       = INIT_INFO(HalfComplexReal, DOUBLE,  ,  , 0, RADIX_TWO,  SINGLE_TYPE),
real_info_radix2              = INIT_INFO(RealHalfcomplex, DOUBLE,  ,  , 0, RADIX_TWO,  SINGLE_TYPE),
complex_float_info_radix2     = INIT_INFO(ComplexComplex,  FLOAT,  C, C, 0, RADIX_TWO,  PACKED_TYPE), 
halfcomplex_float_info_radix2 = INIT_INFO(HalfComplexReal, FLOAT,   ,  , 0, RADIX_TWO,  SINGLE_TYPE),
real_float_info_radix2        = INIT_INFO(RealHalfcomplex, FLOAT,   ,  , 0, RADIX_TWO,  SINGLE_TYPE);

#define PyGSL_TRANSFORM(name, mode, transformp, radix2) \
    static PyObject * \
    PyGSL_transform_ ## name(PyObject *self, PyObject *args)\
    {\
           PyObject *r; \
           struct _pygsl_transform_help_s helps; \
           struct _pygsl_transform_help_rf_s s;  \
           FUNC_MESS_BEGIN(); \
           helps.transform.v = (void *) transformp;\
           switch(radix2){ \
           case RADIX_TWO:    helps.info = &mode ## _info_radix2; helps.helpers = NULL; break;\
           case RADIX_FREE:   helps.info = &mode ## _info; \
                              helps.helpers = &s;  s.func = &mode ## _funcs; \
                              break;\
			      }\
	   r = PyGSL_transform_(self, args, &helps); \
           if(r == NULL) PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__); \
           FUNC_MESS_END();\
           FUNC_MESS("------------------------------------------------");\
	   return r;\
    }

#define PyGSL_RFREE_DF(name, mode, direction) \
        PyGSL_TRANSFORM(name ## direction, mode, (void *) gsl_ ## name  ## direction, RADIX_FREE) \
        PyGSL_TRANSFORM(name ## direction ## _float, mode ## _float, \
                        (void *) gsl_ ## name  ## float_ ## direction, RADIX_FREE)

#define PyGSL_RTWO_DF(name, mode, direction) \
        PyGSL_TRANSFORM(name ## radix2_ ## direction, mode, (void *) gsl_ ## name  ## radix2_ ## direction, RADIX_TWO) \
        PyGSL_TRANSFORM(name ## radix2_ ## direction ## _float, mode ## _float, \
                        (void *) gsl_ ## name  ## float_radix2_ ## direction, RADIX_TWO) 


     
#define PyGSL_COMPLEX(direction) \
        PyGSL_RFREE_DF(fft_complex_, complex, direction) 

PyGSL_COMPLEX(forward)
PyGSL_COMPLEX(backward)
PyGSL_COMPLEX(inverse)

#define PyGSL_COMPLEX_RADIX2(direction) \
        PyGSL_RTWO_DF(fft_complex_, complex, direction) 

PyGSL_COMPLEX_RADIX2(forward)
PyGSL_COMPLEX_RADIX2(backward)
PyGSL_COMPLEX_RADIX2(inverse)

PyGSL_COMPLEX_RADIX2(dif_forward)
PyGSL_COMPLEX_RADIX2(dif_backward)
PyGSL_COMPLEX_RADIX2(dif_inverse)

#define PyGSL_REAL_RADIX2(direction) \
        PyGSL_RTWO_DF(fft_real_, real, direction) 

PyGSL_REAL_RADIX2(transform)

#define PyGSL_REAL(direction) \
        PyGSL_RFREE_DF(fft_real_, real, direction) 

PyGSL_REAL(transform)

#define PyGSL_HALFCOMPLEX(direction) \
        PyGSL_RFREE_DF(fft_halfcomplex_, halfcomplex, direction)
 
PyGSL_HALFCOMPLEX(transform)
PyGSL_HALFCOMPLEX(inverse)

#define PyGSL_HALFCOMPLEX_RADIX2(direction) \
        PyGSL_RTWO_DF(fft_halfcomplex_, halfcomplex, direction)

PyGSL_HALFCOMPLEX_RADIX2(transform)
PyGSL_HALFCOMPLEX_RADIX2(inverse)


#define PyGSL_TRANSFORM_FD_FUNCTION(name, transform, ddoc) \
        {name, PyGSL_transform_ ## transform, METH_VARARGS, (char *) ddoc}, \
        {name "_float", PyGSL_transform_ ## transform ## _float, METH_VARARGS, (char *) float_doc},

