#ifndef PyGSL_TRANSFORM_TYPES_H
#define PyGSL_TRANSFORM_TYPES_H 1
/*
 * All different transforms are handled by only two functions. 
 *       PyGSL_transform_
 * and 
 *       PyGSL_transform_2d_.
 * 
 * This was done as similar functionallity is needed by all the transforms.
 * Copy the input data (transforms are often in place), check or allocate 
 * help spaces. Call the function and make clean up. To allow that the 
 * functions need to do quite some decisions to prepare all in proper order
 * and to do the clean up.
 * In this file various data types are defined. The first two are needed by the
 * python type which allows to allocate the proper help space and pass it to
 * the function. All the others are needed to store the information about the
 * transform.
 */

/* ------------------------------------------------------------------------- */
/*
 * One Python type is used to encapsulate all the different workspaces. This
 * enum allows the C Code to destinquish between the different types.
 */

enum pygsl_transform_space_type{
	NOSPACE=0,
	COMPLEX_WORKSPACE,
	REAL_WORKSPACE,
	COMPLEX_WAVETABLE,
	REAL_WAVETABLE,
	HALFCOMPLEX_WAVETABLE,
	COMPLEX_WORKSPACE_FLOAT,
	REAL_WORKSPACE_FLOAT,
	COMPLEX_WAVETABLE_FLOAT,
	REAL_WAVETABLE_FLOAT,
	HALFCOMPLEX_WAVETABLE_FLOAT,
	WAVELET_WORKSPACE
};

#include <pygsl/pygsl_features.h>
#include <gsl/gsl_fft.h>
#include <gsl/gsl_fft_complex.h>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>
#include <gsl/gsl_fft_complex_float.h>
#include <gsl/gsl_fft_real_float.h>
#include <gsl/gsl_fft_halfcomplex_float.h>
#include <gsl/gsl_blas.h>
#ifdef  _PYGSL_GSL_HAS_WAVELET
#define forward forward_wavelet
#define backward backward_wavelet
#include <gsl/gsl_wavelet.h>
#include <gsl/gsl_wavelet2d.h>
#undef forward
#undef backward
#else /* _PYGSL_GSL_HAS_WAVELET */
#endif /* _PYGSL_GSL_HAS_WAVELET */

/*
 * Here the corresponding union to address the pointer as the proper type.
 */
union pygsl_transform_space_t{
	gsl_fft_complex_workspace           *cws;
	gsl_fft_complex_wavetable           *cwt;
	gsl_fft_real_workspace              *rws;
	gsl_fft_real_wavetable              *rwt;
	gsl_fft_halfcomplex_wavetable       *hcwt;
	gsl_fft_complex_workspace_float     *cwsf;
	gsl_fft_complex_wavetable_float     *cwtf;
	gsl_fft_real_workspace_float        *rwsf;
	gsl_fft_real_wavetable_float        *rwtf;
	gsl_fft_halfcomplex_wavetable_float *hcwtf;
#ifdef _PYGSL_GSL_HAS_WAVELET 
	gsl_wavelet_workspace               *wws; 
#endif
	void                                *v;
};

/* ------------------------------------------------------------------------- */
/*
 * From here all data types are defined needed to guide the transform 
 * functions.
 */
/*
 * Transformation in float or double mode 
 */
enum pygsl_transform_mode{
	MODE_DOUBLE = 1,
	MODE_FLOAT
};

/*
 * Input data in ... output data in ...
 */
enum transform_mode{
	ComplexComplex = 1,
	RealReal,
	RealHalfcomplex,
	HalfComplexReal
	
};

/*
 * Should be renamed. Originally the transform mode would only handle the FFT.
 * There one only needed to destinquish between the radix. Wavelets are also a 
 * bit different. Others to come.
 */
enum radix_mode{
	RADIX_TWO = 1,
	RADIX_FREE,
	WAVELET
};

/*
 * Does the basis type consist of only one machine type or two. e.g real
 * is SINGLE_TYPE, complex PACKED_TYPE (a real and an imaginary part).
 */
enum pygsl_packed_type{
	SINGLE_TYPE=1,
	PACKED_TYPE=2
};


#define PyGSL_TRANSFORM_MODE_SWITCH(mode, double_element, float_element) \
        ((mode == MODE_DOUBLE) ? double_element : float_element)

typedef int transform(void * data, size_t stride, size_t N, const void *, void *);
typedef int transform_r2(void * data, size_t stride, size_t N);
#ifdef  _PYGSL_GSL_HAS_WAVELET
typedef int wavelet(const gsl_wavelet * W, double *data, size_t stride, size_t N, void *);
typedef int wavelet2d(const gsl_wavelet * W, gsl_matrix *m, void *);
#endif
typedef void * pygsl_transform_helpn_t(int);
typedef void * pygsl_transform_help_t(void *);

/*
 * The different transform types.
 */
union transforms{
	transform *free;
	transform_r2 *radix2;
#ifdef  _PYGSL_GSL_HAS_WAVELET
	wavelet *wavelet;
	wavelet2d *wavelet2d;
#endif
	void *v;
};

/*
 * Functions to construct and destruct the helpers space and the helpers table.
 * The user can pass them as a proper python type. If not, the proper space
 * will be allocated using these functions.
 */
struct _pygsl_transform_func_rf_s {
	pygsl_transform_helpn_t  * space_alloc;
	pygsl_transform_help_t   * space_free;
	pygsl_transform_helpn_t  * table_alloc;
	pygsl_transform_help_t   * table_free;
	enum pygsl_transform_space_type space_type;
	enum pygsl_transform_space_type table_type;
};

/*
 * Not all transforms need additional workspace. The ones that need it will put
 * an instance somewhere and point the func to the approbriate initalisers.
 * free_space and free_table is used to store if the space and table have to be
 * freeded at the end of the transform.
 */
struct _pygsl_transform_help_rf_s{
	const struct _pygsl_transform_func_rf_s *func;
	void * space;
	void * table;
	int free_space;
	int free_table;
};

/*
 * The info about which transform, what input and output
 * arrays and so forth. Used by _pygsl_transform_help_s to inform the transform
 * function about the various properties.
 */
struct _pygsl_transform_info_s {
	/* 
	 *  complex -> complex
	 *  real    -> half_complex
	 *  half_complex -> real
	 *  real -> real
	 */
	enum transform_mode mode;
        /* float or double ? */
	enum pygsl_transform_mode datatype; 
	enum PyArray_TYPES input_array_type;
	enum PyArray_TYPES output_array_type;
        /* 
	 *  Do I need to add some additional offset to the data 
	 *  pointer before
	 *  calling the function. A trick needed for the real to
	 *  halfcomplex transform.
	 */
	int data_offset; 
	/* Type of the transform. Should be renamed */
	enum radix_mode radix2; 
	/* one or two machine types make on basis type ? */
	enum pygsl_packed_type packed; 
};

/*
 * Finally the struct which gathers all the information. The split up was made, as the 
 * info struct is always needed, but not the helpers.
 */
struct _pygsl_transform_help_s{
	struct _pygsl_transform_info_s *info;
	union transforms  transform;
	struct _pygsl_transform_help_rf_s *helpers;
};
typedef  struct _pygsl_transform_help_s pygsl_transform_help_s;

/* 
 * The main function doing all the work. Its a function for the ffts and a 
 *  method for the wavelets! 
 */
static PyObject *
PyGSL_transform_(PyObject *self, PyObject *args, pygsl_transform_help_s *helps);

/*
 * Currently only wavelets provide a 2 dimensional transform
 */
#ifdef _PYGSL_GSL_HAS_WAVELET
static PyObject *
PyGSL_transform_2d_(PyObject *self, PyObject *args, pygsl_transform_help_s *helps);
#endif 

#endif /* PyGSL_TRANSFORM_TYPES_H */
/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
