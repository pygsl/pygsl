#ifndef _PYGSL_MULTIFIT_NLINEAR_H_
#define _PYGSL_MULTIFIT_NLINEAR_H_ 1

#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_multifit_nlinear.h>
#include <setjmp.h>


typedef struct{
  //%immutable;
  gsl_multifit_nlinear_fdf fdf;
  PyObject *f;
  PyObject *df;
  PyObject *fvv;
  PyObject *args;
  PyObject *callback;
  PyObject *callback_params;
  /*
   * ptr to the python object which wrapps this object. required for passing to
   * the callback object
   */
  PyObject *self_pyobj;
  jmp_buf env;
  int buf_is_set;
  /* 
   * The solvers can deal that the function to evaluate returns an error status.
   * Therefore the error code can not be directly used. Therefore this flag is
   * used so that code can check if an error can be traced back to that issue
   */
  int exception_occured;
}pygsl_multifit_nlinear_params;
  
typedef struct{
  //%immutable;
  gsl_multifit_nlinear_workspace * w;
  pygsl_multifit_nlinear_params params;
}pygsl_multifit_nlinear_workspace;

static PyObject *
_pygsl_multifit_nlinear_covar(const gsl_matrix *J, const double epsrel,
			     const PyGSL_array_index_t p);
static PyObject *
pygsl_multifit_nlinear_covar(const gsl_matrix *J, const double epsrel,
			     const long p);

static int
PyGSL_multifit_nlinear_driver(pygsl_multifit_nlinear_workspace *w,
			      const size_t maxiter, const double xtol,
			      const double gtol, const double ftol,
			      PyObject *callback, PyObject *callback_params,
			      int *OUTPUT);

#endif /* _PYGSL_MULTIFIT_NLINEAR_H_ */
