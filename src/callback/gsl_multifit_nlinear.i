/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * Date: April 2018
 */
%{
static PyObject * pygsl_multifit_nlinear_module = NULL;
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

%define MODULEWRAP(name) gsl_multifit_nlinear_ ## name
%enddef
  
%include gsl_multifit_nlinear_generic.i

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

%extend pygsl_multifit_nlinear_workspace {
  PyObject * covar(const double epsrel){
    PyObject *obj = NULL;
    PyGSL_array_index_t p;
    int /* status = GSL_EFAILED,*/ line = __LINE__;

    p = self->params.fdf.p;
    obj = _pygsl_multifit_nlinear_covar(self->w->J, epsrel, p);
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
