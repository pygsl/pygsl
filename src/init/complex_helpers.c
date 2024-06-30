/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 */
#include <pygsl/complex_helpers.h>
#include <pygsl/profile.h>
#include <pygsl/utils.h>

static int
PyGSL_PyComplex_to_gsl_complex(PyObject * src, gsl_complex * mycomplex)
{
     PyObject *fitem=NULL;

     FUNC_MESS_BEGIN();
     if(PyComplex_Check(src))
     {
	 Py_complex tmp = PyComplex_AsCComplex(src);
	 GSL_SET_REAL(mycomplex, tmp.real);
	 GSL_SET_IMAG(mycomplex, tmp.imag);
	 FUNC_MESS_END();
	 return GSL_SUCCESS;
     }
     fitem = PyNumber_Float(src);
     if(!fitem){
	  PyErr_SetString(PyExc_TypeError,
			  "I could not convert the input to complex or float!"\
			  "Was the input numeric?\n");
	  return GSL_FAILURE;
     }
     PyGSL_INCREASE_complex_transform_counter();
     GSL_SET_REAL(mycomplex, PyFloat_AS_DOUBLE(fitem));
     GSL_SET_IMAG(mycomplex, 0);
     Py_DECREF(fitem);
     FUNC_MESS_END();
     return GSL_SUCCESS;

}

static int
PyGSL_PyComplex_to_gsl_complex_float(PyObject * src,
				     gsl_complex_float * mycomplex)
{
     PyObject * fitem;
     FUNC_MESS_BEGIN();
     if(PyComplex_Check(src))
     {
	 Py_complex tmp = PyComplex_AsCComplex(src);
	 GSL_SET_REAL(mycomplex, tmp.real);
	 GSL_SET_IMAG(mycomplex, tmp.imag);
	 FUNC_MESS_END();
	 return GSL_SUCCESS;
     }
     fitem = PyNumber_Float(src);
     if(!fitem){
	  PyErr_SetString(PyExc_TypeError,
			  "I could not convert the input to complex or float!"\
			  "Was the input numeric?\n");
	  return GSL_FAILURE;
     }
     PyGSL_INCREASE_complex_transform_counter();
     GSL_SET_REAL(mycomplex, PyFloat_AS_DOUBLE(fitem));
     GSL_SET_IMAG(mycomplex, 0);
     Py_DECREF(fitem);
     FUNC_MESS_END();
     return GSL_SUCCESS;
}

static int
PyGSL_PyComplex_to_gsl_complex_long_double(PyObject * src,
					   gsl_complex_long_double * mycomplex)
{

     PyObject * fitem;
     FUNC_MESS_BEGIN();
     if(PyComplex_Check(src))
     {
	 Py_complex tmp = PyComplex_AsCComplex(src);
	 GSL_SET_REAL(mycomplex, tmp.real);
	 GSL_SET_IMAG(mycomplex, tmp.imag);
	 FUNC_MESS_END();
	 return GSL_SUCCESS;
     }
     fitem = PyNumber_Float(src);
     if(!fitem){
	  PyErr_SetString(PyExc_TypeError,
			  "I could not convert the input to complex or float!"\
			  " Was the input numeric?\n");
	  return GSL_FAILURE;
     }
     PyGSL_INCREASE_complex_transform_counter();
     GSL_SET_REAL(mycomplex, PyFloat_AS_DOUBLE(fitem));
     GSL_SET_IMAG(mycomplex, 0);
     FUNC_MESS_END();
     return GSL_SUCCESS;
}
