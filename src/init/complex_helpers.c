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
     PyObject * fitem;

     FUNC_MESS_BEGIN();
    /* 
     * This function is only called if the straight one did not succed.
     */
     
     /*
     * As it was not a complex (or a complex array element) I try to get a 
     * float.
     */

     fitem = PyNumber_Float(src);
     if(!fitem){
	  PyErr_SetString(PyExc_TypeError, 
			  "I could not convert the input to complex or float!"\
			  "Was the input numeric?\n");
	  return GSL_FAILURE;
     }
     PyGSL_INCREASE_complex_transform_counter();

     mycomplex->dat[0] = PyFloat_AS_DOUBLE(fitem);
     mycomplex->dat[1] = 0;
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
     fitem = PyNumber_Float(src);
     if(!fitem){
	  PyErr_SetString(PyExc_TypeError, 
			  "I could not convert the input to complex or float!"\
			  "Was the input numeric?\n");
	  return GSL_FAILURE;
     }
     PyGSL_INCREASE_complex_transform_counter();
     mycomplex->dat[0] = PyFloat_AS_DOUBLE(fitem);
     mycomplex->dat[1] = 0;
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
     fitem = PyNumber_Float(src);
     if(!fitem){
	  PyErr_SetString(PyExc_TypeError, 
			  "I could not convert the input to complex or float!"\
			  " Was the input numeric?\n");
	  return GSL_FAILURE;
     }
     PyGSL_INCREASE_complex_transform_counter();
     mycomplex->dat[0] = PyFloat_AS_DOUBLE(fitem);
     mycomplex->dat[1] = 0;
     FUNC_MESS_END();
     return GSL_SUCCESS;
}
