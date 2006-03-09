#ifndef PyGSL_COMPLEX_HELPERS_H
#define PyGSL_COMPLEX_HELPERS_H 1
#include <pygsl/utils.h>
#include <pygsl/intern.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_errno.h>

/*
 *  These macros convert a PyObect to  a complex if numeric 
 *  Input recieved. If complex, accessing the data, otherwise
 *  reverting to a function.
 */
/* -------------------------------------------------------------------------
   Helper Functions
   ------------------------------------------------------------------------- */
PyGSL_API_EXTERN int
PyGSL_PyComplex_to_gsl_complex(PyObject * src, gsl_complex * mycomplex);

PyGSL_API_EXTERN int
PyGSL_PyComplex_to_gsl_complex_float(PyObject * src, 
				     gsl_complex_float * mycomplex);
PyGSL_API_EXTERN int 
PyGSL_PyComplex_to_gsl_complex_long_double(PyObject * src, 
					   gsl_complex_long_double * mycomplex);

#ifndef _PyGSL_API_MODULE
#define PyGSL_PyComplex_to_gsl_complex \
(*(int (*) (PyObject *, gsl_complex *))              PyGSL_API[PyGSL_PyComplex_to_gsl_complex_NUM])
#define PyGSL_PyComplex_to_gsl_complex_float \
(*(int (*) (PyObject *, gsl_complex_float *))        PyGSL_API[PyGSL_PyComplex_to_gsl_complex_float_NUM])
#define PyGSL_PyComplex_to_gsl_complex_long_double \
(*(int (*) (PyObject *, gsl_complex_long_double *))  PyGSL_API[PyGSL_PyComplex_to_gsl_complex_long_double_NUM])
#endif /* _PyGSL_API_MODULE */

#define PyGSL_PyCOMPLEX_TO_gsl_complex(object, tmp)            \
(PyComplex_Check((object))) ? 				       \
     ((tmp)->dat[0] = ((PyComplexObject *)(object))->cval.real,\
      (tmp)->dat[1] = ((PyComplexObject *)(object))->cval.imag,\
      GSL_SUCCESS) 					       \
     : PyGSL_PyComplex_to_gsl_complex(object, tmp)         

#define PyGSL_PyCOMPLEX_TO_gsl_complex_float(object, tmp )     \
(PyComplex_Check((object))) ?                                  \
     ((tmp)->dat[0] = ((PyComplexObject *)(object))->cval.real,\
      (tmp)->dat[1] = ((PyComplexObject *)(object))->cval.imag,\
      GSL_SUCCESS)                                             \
     : PyGSL_PyComplex_to_gsl_complex_float(object, tmp)      

#define PyGSL_PyCOMPLEX_TO_gsl_complex_long_double(object, tmp ) \
(PyComplex_Check((object))) ?                                     \
     ((tmp)->dat[0] = ((PyComplexObject *)(object))->cval.real,  \
      (tmp)->dat[1] = ((PyComplexObject *)(object))->cval.imag,  \
      GSL_SUCCESS)                                               \
     : PyGSL_PyComplex_to_gsl_complex_long_double(object, tmp)

#endif  /* PyGSL_COMPLEX_HELPERS_H */
