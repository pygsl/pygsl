/* -*- C -*- */
/*
 * Author: Fabian Jakobs
 * Modified by : Pierre Schnizer Feburary 2003
 */     
%{
#include <gsl/gsl_fft.h>
#include <gsl/gsl_fft_complex.h>
#include <gsl/gsl_fft_real.h>
#include <pygsl/block_helpers.h>
%}

%include typemaps.i
%include gsl_error_typemap.i

%typemap(arginit) (double data[], const size_t stride, const size_t n) %{
     PyArrayObject *_PyVector$argnum = NULL;
%};

%typemap(in) (double data[], const size_t stride, const size_t n) {
     _PyVector$argnum = PyGSL_PyArray_PREPARE_gsl_vector_view(
	  $input, PyArray_DOUBLE, PyGSL_NON_CONTIGUOUS | PyGSL_IO_ARRAY, -1, $argnum, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;
     $1 = (double *)(_PyVector$argnum->data);
     $2 = _PyVector$argnum->strides[0] / sizeof(double); 
     $3 = _PyVector$argnum->dimensions[0];
};

%typemap(argout) (double data[], const size_t stride, const size_t n) {
  $result = SWIG_Python_AppendOutput($result, (PyObject*)_PyVector$argnum);	
};

%typemap(arginit) (gsl_complex_packed_array data, const size_t stride, const size_t n) %{
     PyArrayObject *_PyVector$argnum = NULL;
%};

/* I do not support strides here, before I have implemented the tests. */
%typemap(in) (gsl_complex_packed_array data, const size_t stride, const size_t n) {
     _PyVector$argnum = PyGSL_PyArray_PREPARE_gsl_vector_view(
	  $input, PyArray_CDOUBLE, PyGSL_CONTIGUOUS | PyGSL_IO_ARRAY, -1, $argnum, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;
     $1 = (double *)(_PyVector$argnum->data);
     $2 = 1; /*_PyVector$argnum->strides[0] / (2 * sizeof(double)); */
     $3 = _PyVector$argnum->dimensions[0];
};

%typemap(argout) (gsl_complex_packed_array data, const size_t stride, const size_t n) {
  $result = SWIG_Python_AppendOutput($result, (PyObject*)_PyVector$argnum);	
};


%extend gsl_fft_complex_wavetable {
  gsl_fft_complex_wavetable(size_t n) {
    return gsl_fft_complex_wavetable_alloc(n);
  }
  ~gsl_fft_complex_wavetable() {
    gsl_fft_complex_wavetable_free(self);
  }
}

%extend gsl_fft_real_wavetable {
  gsl_fft_real_wavetable(size_t n) {
    return gsl_fft_real_wavetable_alloc(n);
  }
  ~gsl_fft_real_wavetable() {
    gsl_fft_real_wavetable_free(self);
  }
}

%extend gsl_fft_complex_workspace {
  gsl_fft_complex_workspace(size_t n) {
    return gsl_fft_complex_workspace_alloc(n);
  }
  ~gsl_fft_complex_workspace() {
    gsl_fft_complex_workspace_free(self);
  }
}

%extend gsl_fft_real_workspace {
  gsl_fft_real_workspace(size_t n) {
    return gsl_fft_real_workspace_alloc(n);
  }
  ~gsl_fft_real_workspace() {
    gsl_fft_real_workspace_free(self);
  }
}

%ignore gsl_fft_complex_bitreverse_order;
enum gsl_fft_direction { forward=-1, backward=1 };
%include gsl/gsl_fft_complex.h
%include gsl/gsl_fft_real.h
