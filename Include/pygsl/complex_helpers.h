#include <pygsl/utils.h>
#include <Python.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_errno.h>

/*
 *  These macros convert a PyObect to  a complex if numeric 
 *  Input recieved. If complex, accessing the data, otherwise
 *  reverting to a function.
 */
#define PyGSL_PyCOMPLEX_TO_gsl_complex(object, tmp)            \
(PyComplex_Check(object)) ? 				       \
     (tmp)->dat[0] = ((PyComplexObject *) object)->cval.real,  \
     (tmp)->dat[1] = ((PyComplexObject *) object)->cval.imag,  \
     GSL_SUCCESS 					       \
     : PyGSL_PyComplex_to_gsl_complex(object, tmp)         

#define PyGSL_PyCOMPLEX_TO_gsl_complex_float(object, tmp )     \
(PyComplex_Check(object)) ?                                    \
     (tmp)->dat[0] = ((PyComplexObject *) object)->cval.real,  \
     (tmp)->dat[1] = ((PyComplexObject *) object)->cval.imag,  \
     GSL_SUCCESS                                               \
     : PyGSL_PyComplex_to_gsl_complex_float(object, tmp)      

#define PyGSL_PyCOMPLEX_TO_gsl_complex_long_double(object, tmp ) \
(PyComplex_Check(object)) ?                                      \
     (tmp)->dat[0] = ((PyComplexObject *) object)->cval.real,    \
     (tmp)->dat[1] = ((PyComplexObject *) object)->cval.imag,    \
     GSL_SUCCESS                                                 \
     : PyGSL_PyComplex_to_gsl_complex_long_double(object, tmp)
/* -------------------------------------------------------------------------
   Helper Functions
   ------------------------------------------------------------------------- */
int
PyGSL_PyComplex_to_gsl_complex(PyObject * src, gsl_complex * mycomplex);
int
PyGSL_PyComplex_to_gsl_complex_float(PyObject * src, 
				     gsl_complex_float * mycomplex);
int 
PyGSL_PyComplex_to_gsl_complex_long_double(PyObject * src, 
					   gsl_complex_long_double * mycomplex);
