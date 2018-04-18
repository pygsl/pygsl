#ifndef _PYGSL_MULTIFIT_NLINEAR_H_
#define _PYGSL_MULTIFIT_NLINEAR_H_ 1

#include "pygsl_multifit_nlinear_generic.h"
static PyObject *
PyMODULEWRAP(covar_intern)(const gsl_matrix *J, const double epsrel,
			   const PyGSL_array_index_t p);
static PyObject *
PyMODULEWRAP(covar)(const gsl_matrix *J, const double epsrel, const long p);

#endif /* _PYGSL_MULTIFIT_NLINEAR_H_ */
