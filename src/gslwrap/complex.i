
%{
#include <gsl/gsl_complex_math.h>
%}

%typemap(in) gsl_complex {
  Py_complex temp;
  if (!PyComplex_Check($input)) {
    PyErr_SetString(PyExc_ValueError,"Expected a complex");
    return NULL;
  }
  temp = PyComplex_AsCComplex($input);
  $1.dat[0] = temp.real;
  $1.dat[1] = temp.imag;
};

%typemap(out) gsl_complex {
  Py_complex temp;
  temp.real = $1.dat[0];
  temp.imag = $1.dat[1];
  $result = PyComplex_FromCComplex(temp);
}


%typemap(in) gsl_complex * (gsl_complex *tempComplex){
  /* Complex Pointer (in) */
  Py_complex temp;
  tempComplex = new(gsl_complex);
  tempComplex->dat[0] = temp.real;
  tempComplex->dat[1] = temp.imag;
  $1 = tempComplex;
};

%typemap(out) gsl_complex * {
  /* Complex Pionter (out) */
  Py_complex temp;
  temp.real = $1->dat[0];
  temp.imag = $1->dat[1];
  $result = PyComplex_FromCComplex(temp);
}

%typemap(argout) gsl_complex * {
  /* Complex Pionter (argout) */
  Py_complex temp;
  temp.real = $1->dat[0];
  temp.imag = $1->dat[1];
  $result = SWIG_Python_AppendOutput($result, PyComplex_FromCComplex(temp), $isvoid);
}

//%include gsl/gsl_complex_math.h
