
%{
#include <gsl/gsl_matrix_double.h>
#include <gsl/gsl_matrix_complex_double.h>
%}

%include typemaps.i

// gsl_matrix typemaps
%typemap(in) gsl_matrix* %{
  PyArrayObject *_PyMatrix$argnum;
  gsl_matrix_view matrix$argnum;
  {
    _PyMatrix$argnum = (PyArrayObject*)
      PyArray_ContiguousFromObject($input, PyArray_DOUBLE, 2, 2);
    if (_PyMatrix$argnum == NULL)
      return NULL;
    matrix$argnum
      = gsl_matrix_view_array((double*)_PyMatrix$argnum->data,
			      _PyMatrix$argnum->dimensions[0],
			      _PyMatrix$argnum->dimensions[1]);    
    $1 = &matrix$argnum.matrix;
  }
%}

%typemap(freearg) gsl_matrix* {
  Py_DECREF(_PyMatrix$argnum);
}


// gsl_matrix_complex typemaps
%typemap(in) gsl_matrix_complex* %{
  PyArrayObject *_PyMatrix$argnum;
  gsl_matrix_complex_view matrix$argnum;
  {
    _PyMatrix$argnum = (PyArrayObject*)
      PyArray_ContiguousFromObject($input, PyArray_CDOUBLE, 2, 2);
    if (_PyMatrix$argnum == NULL)
      return NULL;
    matrix$argnum
      = gsl_matrix_complex_view_array((double*)_PyMatrix$argnum->data,
				      _PyMatrix$argnum->dimensions[0],
				      _PyMatrix$argnum->dimensions[1]);
    $1 = &matrix$argnum.matrix; 
  }
%}

%typemap(freearg) gsl_matrix_complex* {
  Py_DECREF(_PyMatrix$argnum);
}
