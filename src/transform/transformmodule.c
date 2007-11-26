/*
 * Author : Pierre Schnizer
 * Date   : February 2005
 *
 */
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <pygsl/pygsl_features.h>
#include <string.h>

#include <gsl/gsl_fft.h>
#include <gsl/gsl_fft_complex.h>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>
#include <gsl/gsl_fft_complex_float.h>
#include <gsl/gsl_fft_real_float.h>
#include <gsl/gsl_fft_halfcomplex_float.h>
#include <gsl/gsl_blas.h>
#ifdef _PYGSL_GSL_HAS_WAVELET
#define forward forward_wavelet
#define backward backward_wavelet
#include <gsl/gsl_wavelet.h>
#include <gsl/gsl_wavelet2d.h>
#undef forward
#undef backward
#else
/*
#error Need GSL version 1.6 or higher with wavelet implementation! If you need it for a lower version
#error add the different conditional compilation!
*/
#endif /* gsl version > 1.5*/
static PyObject *module = NULL;
static const char filename[] = __FILE__;

/* The types */
#include "transformtypes.h"
/* The documentation strings */
#include "doc.h"
/* The python type which allows to allocate and pass the work space */
#include "space.c"
/* Function to copy the different arrays. */
#include "arraycopy.c"
/* 
 * Macros and functions which set the information up and call the
 * PyGSL_transform functions 
 */
#include "fft.c"
/*
 * The wavelet type and the methods to call the different transform functions.
 */
#ifdef _PYGSL_GSL_HAS_WAVELET
#include "wavelet.c"
#define PyGSL_WAVELET_TRANSFORM_TYPE(name) \
       {#name,             PyGSL_wavelet_init_ ## name,              METH_VARARGS, NULL}, \
       {#name "_centered", PyGSL_wavelet_init_ ## name ## _centered, METH_VARARGS, NULL},
#else
#define PyGSL_WAVELET_TRANSFORM_TYPE(name)
#endif
/*
 * The real workers. 
 */
#include "core.c"

static PyMethodDef transformMethods[] = {
	/* workspace init functions  */
	{"complex_workspace",           PyGSL_transform_space_init_COMPLEX_WORKSPACE,            METH_VARARGS, (char*)cws_doc},
	{"complex_wavetable",           PyGSL_transform_space_init_COMPLEX_WAVETABLE,            METH_VARARGS, (char*)cwt_doc},
	{"real_workspace",              PyGSL_transform_space_init_REAL_WORKSPACE,               METH_VARARGS, (char*)rws_doc},
	{"real_wavetable",              PyGSL_transform_space_init_REAL_WAVETABLE,               METH_VARARGS, (char*)rwt_doc},
	{"halfcomplex_wavetable",       PyGSL_transform_space_init_HALFCOMPLEX_WAVETABLE,        METH_VARARGS, (char*)hcwt_doc},
	{"complex_workspace_float",     PyGSL_transform_space_init_COMPLEX_WORKSPACE_FLOAT,      METH_VARARGS, (char*)cws_doc},
	{"complex_wavetable_float",     PyGSL_transform_space_init_COMPLEX_WAVETABLE_FLOAT,      METH_VARARGS, (char*)cwt_doc},
	{"real_workspace_float",        PyGSL_transform_space_init_REAL_WORKSPACE_FLOAT,         METH_VARARGS, (char*)rws_doc},
	{"real_wavetable_float",        PyGSL_transform_space_init_REAL_WAVETABLE_FLOAT,         METH_VARARGS, (char*)rwt_doc},
	{"halfcomplex_wavetable_float", PyGSL_transform_space_init_HALFCOMPLEX_WAVETABLE_FLOAT,  METH_VARARGS, (char*)hcwt_doc},
#ifdef _PYGSL_GSL_HAS_WAVELET
	{"wavelet_workspace",           PyGSL_transform_space_init_WAVELET_WORKSPACE,            METH_VARARGS, (char*)ww_doc},
#endif
	/* transform functions */
	PyGSL_TRANSFORM_FD_FUNCTION("complex_forward",             fft_complex_forward,              cf_doc)
	PyGSL_TRANSFORM_FD_FUNCTION("complex_backward",            fft_complex_backward,             cb_doc)	
	PyGSL_TRANSFORM_FD_FUNCTION("complex_inverse",             fft_complex_inverse,              ci_doc)	
	PyGSL_TRANSFORM_FD_FUNCTION("complex_radix2_forward",      fft_complex_radix2_forward,       cf_doc_r2)	
	PyGSL_TRANSFORM_FD_FUNCTION("complex_radix2_backward",     fft_complex_radix2_backward,      cb_doc_r2)
	PyGSL_TRANSFORM_FD_FUNCTION("complex_radix2_inverse",      fft_complex_radix2_inverse,       ci_doc_r2)
	PyGSL_TRANSFORM_FD_FUNCTION("complex_radix2_dif_forward",  fft_complex_radix2_dif_forward,   cf_doc_r2_dif)
	PyGSL_TRANSFORM_FD_FUNCTION("complex_radix2_dif_backward", fft_complex_radix2_dif_backward,  cb_doc_r2_dif)
	PyGSL_TRANSFORM_FD_FUNCTION("complex_radix2_dif_inverse",  fft_complex_radix2_dif_inverse,   ci_doc_r2_dif)
	PyGSL_TRANSFORM_FD_FUNCTION("real_transform",              fft_real_transform,               rt_doc)	
	PyGSL_TRANSFORM_FD_FUNCTION("halfcomplex_transform",       fft_halfcomplex_transform,        hc_doc)
	PyGSL_TRANSFORM_FD_FUNCTION("halfcomplex_inverse",         fft_halfcomplex_inverse,          hi_doc)
	PyGSL_TRANSFORM_FD_FUNCTION("real_radix2_transform",       fft_real_radix2_transform,        rt_doc_r2)	
	PyGSL_TRANSFORM_FD_FUNCTION("halfcomplex_radix2_transform",fft_halfcomplex_radix2_transform, hc_doc_r2)
	PyGSL_TRANSFORM_FD_FUNCTION("halfcomplex_radix2_inverse",  fft_halfcomplex_radix2_inverse,   hi_doc_r2)
	/* helper functions */
	{"halfcomplex_radix2_unpack",         PyGSL_fft_halfcomplex_radix2_unpack,       METH_VARARGS, (char*)un_doc_r2},
	{"halfcomplex_radix2_unpack_float",   PyGSL_fft_halfcomplex_radix2_unpack_float, METH_VARARGS, (char*)float_doc},
	/* wavelet inits */ 
#ifdef _PYGSL_GSL_HAS_WAVELET
	PyGSL_WAVELET_TRANSFORM_TYPE(daubechies)
	PyGSL_WAVELET_TRANSFORM_TYPE(haar)
	PyGSL_WAVELET_TRANSFORM_TYPE(bspline)
#endif
	{NULL, NULL, 0, NULL} /* Sentinel */
};


/*
 * Set the various function pointers for the different transforms. See the 
 * structure _pygsl_transform_func_s for the functions. Some architectures do 
 * not allow to initalise function pointers in static structures on the heap. 
 * (some solaris versions? )
 */
#define PYGSL_INIT_FUNCS(helpers, space, table, spacet, tablet) \
	helpers.space_alloc = (pygsl_transform_helpn_t *) gsl_fft_ ## space ## _alloc; \
	helpers.space_free  = (pygsl_transform_help_t *)  gsl_fft_ ## space ## _free;  \
	helpers.table_alloc = (pygsl_transform_helpn_t *) gsl_fft_ ## table ## _alloc; \
	helpers.table_free  = (pygsl_transform_help_t *)  gsl_fft_ ## table ## _free; \
	helpers.space_type  = spacet; \
	helpers.table_type  = tablet; \
       
#define PYGSL_INIT_FUNCS_DF(helpers, space, table, spacet, tablet) \
       PYGSL_INIT_FUNCS(helpers ## _funcs, space, table, spacet, tablet) \
       PYGSL_INIT_FUNCS(helpers ## _float ## _funcs, space ## _float, table ## _float, spacet ## _FLOAT, tablet ## _FLOAT)

static void
init_helpers(void)
{
	FUNC_MESS_BEGIN();
	PYGSL_INIT_FUNCS_DF(complex,     complex_workspace, complex_wavetable, COMPLEX_WORKSPACE, COMPLEX_WAVETABLE)
	PYGSL_INIT_FUNCS_DF(real,        real_workspace,    real_wavetable, REAL_WORKSPACE, REAL_WAVETABLE)
	PYGSL_INIT_FUNCS_DF(halfcomplex, real_workspace,    halfcomplex_wavetable, REAL_WORKSPACE, HALFCOMPLEX_WAVETABLE)

        DEBUG_MESS(3, "PyArray_FLOAT   = %d ", PyArray_FLOAT  ); 
	DEBUG_MESS(3, "PyArray_DOUBLE  = %d ", PyArray_DOUBLE );
	DEBUG_MESS(3, "PyArray_CFLOAT  = %d ", PyArray_CFLOAT );
	DEBUG_MESS(3, "PyArray_CDOUBLE = %d ", PyArray_CDOUBLE);

#ifdef _PYGSL_GSL_HAS_WAVELET	
	DEBUG_MESS(4, "%s @ %p", "daubechies", gsl_wavelet_daubechies);
	DEBUG_MESS(4, "%s @ %p", "daubechies_centered", gsl_wavelet_daubechies_centered);
	DEBUG_MESS(4, "%s @ %p", "haar", gsl_wavelet_haar);
	DEBUG_MESS(4, "%s @ %p", "haar_centered", gsl_wavelet_haar_centered);
	DEBUG_MESS(4, "%s @ %p", "bspline", gsl_wavelet_bspline);
	DEBUG_MESS(4, "%s @ %p", "bspline_centered", gsl_wavelet_bspline_centered);     
#endif
	FUNC_MESS_END();

}

DL_EXPORT(void) init_transform(void)
{
     	PyObject *m = NULL, *dict = NULL, *item = NULL;
	
	FUNC_MESS_BEGIN();
	PyGSL_transform_space_pytype.ob_type = &PyType_Type;
#ifdef _PYGSL_GSL_HAS_WAVELET
	PyGSL_wavelet_pytype.ob_type = &PyType_Type;
#endif
	m = Py_InitModule("_transform", transformMethods);
	module = m;
	init_pygsl();
	init_helpers();
	if (m == NULL)
		return;

	dict = PyModule_GetDict(m);
	if (dict == NULL)
		return;
	
	if (!(item = PyString_FromString(transform_module_doc))){
		PyErr_SetString(PyExc_ImportError, 
				"I could not generate module doc string!");
		return;
	}
	if (PyDict_SetItemString(dict, "__doc__", item) != 0){
		PyErr_SetString(PyExc_ImportError, 
				"I could not init doc string!");
		return;
	}
	FUNC_MESS_END();
	return;
}


/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
