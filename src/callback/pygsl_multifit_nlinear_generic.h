#ifndef _PYGSL_MULTIFIT_NLINEAR_GENERIC_H_
#define _PYGSL_MULTIFIT_NLINEAR_GENERIC_H_ 1

#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <setjmp.h>


typedef struct{
  //%immutable;
  MODULEWRAP(fdf) fdf;
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
}PyMODULEWRAP(params);
  
typedef struct{
  //%immutable;
  MODULEWRAP(workspace) * w;
  PyMODULEWRAP(params) params;
  //PyThreadState *thread;
}PyMODULEWRAP(workspace);

static int
PyMODULEWRAP(callback_obj_intern)(PyObject * callback, const gsl_vector * x,
				  PyMODULEWRAP(params) * t_params, PyObject **ob);


static int
PyMODULEWRAP(driver)(PyMODULEWRAP(workspace) *w,
		     const size_t maxiter, const double xtol,
		     const double gtol, const double ftol,
		     PyObject *callback, PyObject *callback_params,
		     int *OUTPUT);

#endif /* _PYGSL_MULTIFIT_NLINEAR_GENERIC_H_ */
