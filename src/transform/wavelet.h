#ifndef _PyGSL_WAVELET_H_
#define _PyGSL_WAVELET_H_ 1
typedef struct {
	PyObject_HEAD
	gsl_wavelet *wavelet;
} PyGSL_wavelet;

#define  PyGSL_WAVELET_CHECK(op) ((op)->ob_type == &PyGSL_wavelet_pytype)

#endif /* _PyGSL_WAVELET_H_ */
