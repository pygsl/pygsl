/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * Date: April 2018
 */

%define MODULEWRAP(name) gsl_multilarge_nlinear_ ## name
%enddef
%define PyMODULEWRAP(name) pygsl_multilarge_nlinear_ ## name
%enddef

%{
static PyObject * pygsl_multifit_nlinear_module = NULL;

#define MODULEWRAP(name) gsl_multilarge_nlinear_ ## name
#define PyMODULEWRAP(name) pygsl_multilarge_nlinear_ ## name

#include <gsl/gsl_multilarge_nlinear.h>
#include "pygsl_multilarge_nlinear.h"
#include "pygsl_multilarge_nlinear.ic"

%}
%init{
  init_pygsl();
  pygsl_multifit_nlinear_module = m;
}

%define MODULEDOCSTRING
"Wrapper for the newer interface to nonlinear multifit"
%enddef

//%module multifit_nlinear;
%module(docstring=MODULEDOCSTRING) multilarge_nlinear;
%feature ("autodoc", "3");
%init{
  init_pygsl();
  pygsl_multifit_nlinear_module = m; 
}


typedef struct
{
  %mutable;
  const gsl_multilarge_nlinear_trs *trs;       /* trust region subproblem method */
  const gsl_multilarge_nlinear_scale *scale;   /* scaling method */
  const gsl_multilarge_nlinear_solver *solver; /* solver method */
  gsl_multilarge_nlinear_fdtype fdtype;        /* finite difference method */
  double factor_up;                            /* factor for increasing trust radius */
  double factor_down;                          /* factor for decreasing trust radius */
  double avmax;                                /* max allowed |a|/|v| */
  double h_df;                                 /* step size for finite difference Jacobian */
  double h_fvv;                                /* step size for finite difference fvv */
  size_t max_iter;                             /* maximum iterations for trs method */
  double tol;                                  /* tolerance for solving trs */
} gsl_multilarge_nlinear_parameters;

%include gsl_multifit_nlinear_generic.i

%immutable;
%ignore gsl_multilarge_nlinear_df;
%ignore gsl_multilarge_nlinear_fvv;
%ignore gsl_multilarge_nlinear_fdfvv;
%ignore gsl_multilarge_nlinear_eval_fvv;
%ignore gsl_multilarge_nlinear_eval_df;
%ignore gsl_multilarge_nlinear_eval_fdfvv;
%ignore gsl_multilarge_nlinear_parameters;
/* trust region subproblem methods */
%rename(trs_cgst)  gsl_multilarge_nlinear_trs_cgst;
%include gsl/gsl_multilarge_nlinear.h
%mutable;


/*
%extend gsl_multifit_nlinear_workspace {
  gsl_multifit_nlinear_workspace(const MODULEWRAP(type) * T,
				 const MODULEWRAP(parameters) * params,
				 const size_t n, const size_t p){
    return MODULEWRAP(alloc)(T, params, n, p);
  }
  ~MODULEWRAP(workspace)(void){
    MODULEWRAP(free)(self);
  }
  const char * name(void){
      return  MODULEWRAP(name)(self);
  }
  const char * trs_name(void){
    return  MODULEWRAP(trs_name)(self);
  }
  double avratio(void){
    return MODULEWRAP(avratio)(self);
  }
}
*/
