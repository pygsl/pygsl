#ifndef PyGSL_RNG_HELPERS_H
#define PyGSL_RNG_HELPERS_H 1
#include <pygsl/rng.h>


/*
 * Evaluators for various random distributions. They all parse the parameters to the number of available parameters.
 */

PyGSL_API_EXTERN  PyObject *
PyGSL_rng_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *));

PyGSL_API_EXTERN  PyObject *
PyGSL_rng_d_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_dd_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, const double, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_ddd_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, const double, const double, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_ui_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, unsigned int));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_d_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, double));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_dui_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, double, unsigned int));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_dd_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, double, double));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_to_dd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double *, double *));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_ddd_to_dd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double, double, double, double *, double *));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_to_ddd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double *, double *, double *));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_to_nd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, size_t n, double *));



PyGSL_API_EXTERN PyObject *
PyGSL_rng_uiuiui_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, unsigned int, unsigned int, unsigned int));


PyGSL_API_EXTERN PyObject *
PyGSL_rng_uidA_to_uiA(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, const size_t, const unsigned int, const double * , unsigned int *));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_dA_to_dA(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, const size_t, const double * , double *));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_to_ulong(PyGSL_rng *rng, PyObject *args, unsigned long int (*evaluator)(const gsl_rng *));

PyGSL_API_EXTERN PyObject *
PyGSL_rng_ul_to_ulong(PyGSL_rng *rng, PyObject *args, unsigned long int (*evaluator)(const gsl_rng *, unsigned long int));


/*
 * Probability density functions. x can be a float or an array.
 */
PyGSL_API_EXTERN PyObject *
PyGSL_pdf_to_double(PyObject *self, PyObject *args, double (*evaluator)(const double));

PyGSL_API_EXTERN PyObject *
PyGSL_pdf_d_to_double(PyObject *self, PyObject *args, double (*evaluator)(const double, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_pdf_dd_to_double(PyObject *self, PyObject *args, double (*evaluator)(const double, const double, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_pdf_ddd_to_double(PyObject *self, PyObject *args, double (*evaluator)(const double, const double, const double, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_pdf_ddd_to_dd(PyObject *self, PyObject *args, 
		    double (*evaluator)(const double, const double, const double, const double, const double));

PyGSL_API_EXTERN PyObject *
PyGSL_pdf_d_to_ui(PyObject *self, PyObject *args, double (*evaluator)(const unsigned int, double));

PyGSL_API_EXTERN PyObject *
PyGSL_pdf_dd_to_ui(PyObject *self, PyObject *args, 
		   double (*evaluator)(const unsigned int, const double, double)
		   /*(const unsigned int, const double, const unsigned int)*/);
PyGSL_API_EXTERN PyObject*
PyGSL_pdf_dui_to_ui(PyObject *self, PyObject *args, 
		    double (*evaluator)(const unsigned int k, const double p, const unsigned int n));
PyGSL_API_EXTERN PyObject *
PyGSL_pdf_uiuiui_to_ui(PyObject *self, PyObject *args, 
		       double (*evaluator)(const unsigned int, const unsigned int, const unsigned int, unsigned int));

PyGSL_API_EXTERN PyObject*
PyGSL_pdf_dA_to_dA(PyObject *self, PyObject *args, 
		   double (*evaluator) (const size_t, const double [], const double []));
PyGSL_API_EXTERN PyObject*
PyGSL_pdf_uidA_to_uiA(PyObject *self, PyObject *args, 
		      double (*evaluator) (const size_t, const double [], const unsigned int []));
#endif  /* PyGSL_RNG_HELPERS_H */


