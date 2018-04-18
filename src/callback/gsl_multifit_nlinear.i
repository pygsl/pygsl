/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * Date: April 2018
 */

%define MODULEWRAP(name) gsl_multifit_nlinear_ ## name
%enddef
%define PyMODULEWRAP(name) pygsl_multifit_nlinear_ ## name
%enddef

%{
static PyObject * pygsl_multifit_nlinear_module = NULL;

#define MODULEWRAP(name) gsl_multifit_nlinear_ ## name
#define PyMODULEWRAP(name) pygsl_multifit_nlinear_ ## name

#include <gsl/gsl_multifit_nlinear.h>
#include "pygsl_multifit_nlinear.h"
#include "pygsl_multifit_nlinear.ic"

%}
%init{
  init_pygsl();
  pygsl_multifit_nlinear_module = m;
}

%define MODULEDOCSTRING
"Wrapper for the newer interface to nonlinear multifit"
%enddef

//%module multifit_nlinear;
%module(docstring=MODULEDOCSTRING) multifit_nlinear;
%feature ("autodoc", "3");
%init{
  init_pygsl();
  pygsl_multifit_nlinear_module = m; 
}


typedef struct
{
  %mutable;
  const gsl_multifit_nlinear_trs *trs;        /* trust region subproblem method */
  const gsl_multifit_nlinear_scale *scale;    /* scaling method */
  const gsl_multifit_nlinear_solver *solver;  /* solver method */
  gsl_multifit_nlinear_fdtype fdtype;         /* finite difference method */
  double factor_up;                           /* factor for increasing trust radius */
  double factor_down;                         /* factor for decreasing trust radius */
  double avmax;                               /* max allowed |a|/|v| */
  double h_df;                                /* step size for finite difference Jacobian */
  double h_fvv;                               /* step size for finite difference fvv */
} gsl_multifit_nlinear_parameters;

%include gsl_multifit_nlinear_generic.i


%immutable;
%ignore gsl_multifit_nlinear_parameters;
%include gsl/gsl_multifit_nlinear.h
%mutable;

static PyObject *
PyMODULEWRAP(covar)(const gsl_matrix *J, const double epsrel, const long p);


%extend pygsl_multifit_nlinear_workspace {
  PyObject * jac(void){
    gsl_matrix * m = NULL;
    m = MODULEWRAP(jac)(self->w);
    return (PyObject*) PyGSL_copy_gslmatrix_to_pyarray(m);
  }

  PyObject * covar(const double epsrel){
    PyObject *obj = NULL;
    PyGSL_array_index_t p;
    int /* status = GSL_EFAILED,*/ line = __LINE__;

    p = self->params.fdf.p;
    obj = pygsl_multifit_nlinear_covar_intern(self->w->J, epsrel, p);
    if(obj == NULL){
	line = __LINE__ - 2;
	goto fail;
    }
    return obj;
    
  fail:
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    PyGSL_error_flag(PyGSL_ANY);
    return NULL;
  }
 }
