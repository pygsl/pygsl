
%{
#include <gsl/gsl_vector.h>
%}


%typemap(in) gsl_vector* %{
  PyArrayObject *_PyVector$argnum;
  gsl_vector vector$argnum;
  {
    int len;
    _PyVector$argnum = (PyArrayObject*)
      PyArray_ContiguousFromObject($input, PyArray_DOUBLE, 1, 1);
    if (_PyVector$argnum == NULL)
      return NULL;
    len = _PyVector$argnum->dimensions[0];
    vector$argnum.size = len;
    vector$argnum.stride = 1;
    vector$argnum.data = (double*)_PyVector$argnum->data;
    vector$argnum.block = NULL;
    vector$argnum.owner = 1;
    $1 = &vector$argnum;
  }
%}

%typemap(freearg) gsl_vector* {
  Py_DECREF(_PyVector$argnum);
}


// gsl_vector_complex typemaps
%typemap(in) gsl_vector_complex* %{
  PyArrayObject *_PyVector$argnum;
  gsl_vector_complex vector$argnum;
  {
    int len;
    _PyVector$argnum = (PyArrayObject*)
      PyArray_ContiguousFromObject($input, PyArray_CDOUBLE, 1, 1);
    if (_PyVector$argnum == NULL)
      return NULL;
    len = _PyVector$argnum->dimensions[0];
    vector$argnum.size = len;
    vector$argnum.stride = 1;
    vector$argnum.data = (double*)_PyVector$argnum->data;
    vector$argnum.block = NULL;
    vector$argnum.owner = 1;
    $1 = &vector$argnum;
  }
%}

%typemap(freearg) gsl_vector_complex* {
  Py_DECREF(_PyVector$argnum);
}


//%ignore gsl_check_range;

//%include gsl/gsl_vector_complex_double.h
//%include gsl/gsl_vector_double.h
//%include gsl/gsl_vector_long.h
