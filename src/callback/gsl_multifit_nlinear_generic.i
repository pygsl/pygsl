/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
%feature ("autodoc", "3");

 
//typedef enum gsl_multifit_nlinear_fdtype;

%include gsl_error_typemap.i
%include gsl_block_typemaps.i
%include typemaps.i


/* tunable parameters */
%rename(parameters)         MODULEWRAP(parameters);
%rename(default_parameters) MODULEWRAP(default_parameters);
//%feature("python:slot", "tp_repr", functype="reprfunc") parameters::print_repr;

%rename(trust_state) MODULEWRAP(trust_state);
%rename(workspace)   PyMODULEWRAP(workspace);


%rename(CTRDIFF) GSL_MULTIFIT_NLINEAR_CTRDIFF;
%rename(FWDIFF)  GSL_MULTIFIT_NLINEAR_FWDIFF;   
#define GSL_VAR extern 
//%ignore gsl_multifit_nlinear_covar;
%ignore MODULEWRAP(workspace);
%ignore MODULEWRAP(name);
%ignore MODULEWRAP(trs_name);
%ignore MODULEWRAP(alloc);
%ignore MODULEWRAP(free);
%ignore MODULEWRAP(init);
%ignore MODULEWRAP(winit);
%ignore MODULEWRAP(trs_name);
%ignore MODULEWRAP(iterate);
%ignore MODULEWRAP(avratio);
%ignore MODULEWRAP(driver);
%ignore MODULEWRAP(jac);
%ignore MODULEWRAP(name);
%ignore MODULEWRAP(position);
%ignore MODULEWRAP(residual);
%ignore MODULEWRAP(niter);
%ignore MODULEWRAP(test);
%ignore MODULEWRAP(rcond);

%ignore MODULEWRAP(trust);
%ignore _pygsl_multifit_nlinear_covar;
%rename(covar) PyMODULEWRAP(covar);

%rename(trust)           MODULEWRAP(trust);

/* trust region subproblem methods */
%rename(trs_lm)          MODULEWRAP(trs_lm);
%rename(trs_lmaccel)     MODULEWRAP(trs_lmaccel);
%rename(trs_dogleg)      MODULEWRAP(trs_dogleg);
%rename(trs_ddogleg)     MODULEWRAP(trs_ddogleg);
%rename(trs_subspace2D)  MODULEWRAP(trs_subspace2D);

/* scaling matrix strategies */
%rename(scale_levenberg) MODULEWRAP(scale_levenberg);
%rename(scale_marquardt) MODULEWRAP(scale_marquardt);
%rename(scale_more)      MODULEWRAP(scale_more);

/* linear solvers */
%rename(solver_cholesky) MODULEWRAP(solver_cholesky);
%rename(solver_qr)       MODULEWRAP(solver_qr);
%rename(solver_svd)      MODULEWRAP(solver_svd);



typedef struct{
  MODULEWRAP(fdf) fdf;
  %immutable;
  int buf_is_set;
}PyMODULEWRAP(params);

typedef struct{
  %immutable;
  MODULEWRAP(workspace) * w;
  %mutable;
  PyMODULEWRAP(params) params;
}PyMODULEWRAP(workspace);


%extend MODULEWRAP(workspace) {
  MODULEWRAP(workspace)(const MODULEWRAP(type) * T,
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

#define _PYGSL_WRAP_SETJMP(cmd)                       \
    do{                                               \
      self->params.buf_is_set = 0;		      \
      if( (status = setjmp(self->params.env)) == 0){  \
	self->params.buf_is_set = 1;		      \
	status = cmd;				      \
	self->params.buf_is_set = 0;                  \
      } else {					      \
	self->params.buf_is_set = 0;		      \
      }						      \
    }while(0)
    
%extend PyMODULEWRAP(workspace) {
  PyMODULEWRAP(workspace)(const MODULEWRAP(type) * T, const MODULEWRAP(parameters) * params,
			  const size_t n, const size_t p){

    return PyMODULEWRAP(alloc)(T, params, n, p);
  }
  
  ~PyMODULEWRAP(workspace)(void){
    PyMODULEWRAP(deallocate)(self);
  }

  gsl_error_flag_drop init(const gsl_vector * x, PyObject * f, PyObject *df = NULL,
			   PyObject *fvv = NULL,  PyObject *args=NULL){
    int status = GSL_SUCCESS, line = __LINE__;

    FUNC_MESS_BEGIN();
    status = PyMODULEWRAP(handle_callbacks)(self, f, df, fvv, args);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }

    DEBUG_MESS(2, "Calling MODULEWRAP(init) x[0] = %e", gsl_vector_get(x, 0));
    _PYGSL_WRAP_SETJMP(    MODULEWRAP(init)(x, &self->params.fdf, self->w) );
    if(status != GSL_SUCCESS){
      line = __LINE__ - 13;
      goto fail;    
    }
    
    FUNC_MESS_END();
    return status;
      
  fail:
    FUNC_MESS_FAILED();
    DEBUG_MESS(2, "fdf->n %lu fdf->p %lu x->size %lu",
	       (unsigned long) self->params.fdf.p, (unsigned long) self->params.fdf.n,
	       (unsigned long) x->size);
    DEBUG_MESS(2, "Failed at line %d", line);
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
  }
  
  gsl_error_flag_drop winit(const gsl_vector * x, const gsl_vector * wts,
			    PyObject * f, PyObject *df = NULL, PyObject *fvv = NULL,
			    PyObject *args = NULL){
    int status = GSL_SUCCESS, line = __LINE__;

    FUNC_MESS_BEGIN();
    status = PyMODULEWRAP(handle_callbacks)(self, f, df, fvv, args);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }

    _PYGSL_WRAP_SETJMP(  MODULEWRAP(winit)(x, wts, &self->params.fdf, self->w));
    if(status != GSL_SUCCESS){
      line = __LINE__ - 13;
      goto fail;    
    }

    FUNC_MESS_END();
    return status;
    
  fail:
    FUNC_MESS_FAILED();
    DEBUG_MESS(2, "Failed at line %d", line);
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
 }

  gsl_error_flag_drop iterate(void){
    int status = GSL_SUCCESS, line = __LINE__;

    FUNC_MESS_BEGIN();
    _PYGSL_WRAP_SETJMP(  MODULEWRAP(iterate)(self->w));
    if(status != GSL_SUCCESS){
      line = __LINE__ - 13;
      goto fail;    
    }

    FUNC_MESS_END();
    return status;
    
  fail:
    FUNC_MESS_FAILED();
    DEBUG_MESS(2, "Failed at line %d", line);
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
    
    

    return MODULEWRAP(iterate)(self->w);
  }

  double avratio(void){
    return MODULEWRAP(avratio)(self->w);
  }

  
  gsl_error_flag
    driver(const size_t maxiter, const double xtol,
	     const double gtol, const double ftol,
	     PyObject *callback = NULL, PyObject *callback_params = NULL,
	     int *OUTPUT)
  {
    int status = GSL_EFAILED, line = __LINE__;

    FUNC_MESS_BEGIN();

    self->params.exception_occured = GSL_SUCCESS;

    _PYGSL_WRAP_SETJMP(PyMODULEWRAP(driver)(self, maxiter, xtol, gtol, ftol,
				callback, callback_params, OUTPUT) );
    if(status != GSL_SUCCESS){
      line = __LINE__ - 13;
      goto fail;    
    }
    FUNC_MESS_END();
    return status;
    
  fail:
    FUNC_MESS("FAIL");
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
  }
  
  PyObject * position(void){
    gsl_vector *v = NULL;

    v = MODULEWRAP(position)(self->w);
    return (PyObject*) PyGSL_copy_gslvector_to_pyarray(v);
  }

  PyObject * x(void){
    gsl_vector *v = NULL;

    v =self->w->x;
    return (PyObject*) PyGSL_copy_gslvector_to_pyarray(v);
  }
  
  PyObject * residual(void){
    gsl_vector *v = NULL;

    v = MODULEWRAP(residual)(self->w);
    return (PyObject*) PyGSL_copy_gslvector_to_pyarray(v);
  }

  size_t niter(void){
    return MODULEWRAP(niter)(self->w);
  }
  
  gsl_error_flag_drop rcond(double * OUTPUT){
    return MODULEWRAP(rcond)(OUTPUT, self->w);
  }

  gsl_error_flag test(const double xtol, const double gtol,
                           const double ftol, int *OUTPUT){
    return MODULEWRAP(test)(xtol, gtol, ftol, OUTPUT, self->w);
  }
  
  const char * name(void){
    return  MODULEWRAP(name)(self->w);
  }
  
  const char * trs_name(void){
    return  MODULEWRAP(trs_name)(self->w);
  }


  /* 
   * The callback typically requires information of the state of the solver. 
   * Thus the C Implementation passes a pointer to the actual 
   * :c:any`gsl_multifit_nlinear_workspace`. 
   *
   * The equivalent is the python object of this structure. But how to access it
   * directly from the swig c code?
   */
  gsl_error_flag_drop set_pyobject(PyObject * obj){

    /* 
     * put on the argument list with args afterwards. if obj == NULL it would
     * terminate the list of arguments
     */
    assert(obj != NULL);
    Py_XDECREF(self->params.self_pyobj);
    Py_XINCREF(obj);    
    self->params.self_pyobj = obj;

    return GSL_SUCCESS;
  }
}


//%feature("python:slot", "tp_repr", functype="reprfunc") HelpMimic::printRepr;


