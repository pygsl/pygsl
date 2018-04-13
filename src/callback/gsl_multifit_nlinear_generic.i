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
%rename(workspace)   pygsl_multifit_nlinear_workspace;


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
%rename(covar) pygsl_multifit_nlinear_covar;

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
  gsl_multifit_nlinear_fdf fdf;
  %immutable;
  int buf_is_set;
}pygsl_multifit_nlinear_params;

typedef struct{
  %immutable;
  gsl_multifit_nlinear_workspace * w;
  pygsl_multifit_nlinear_params params;
}pygsl_multifit_nlinear_workspace;

static PyObject *
pygsl_multifit_nlinear_covar(const gsl_matrix *J, const double epsrel,
			     const long p);


%extend pygsl_multifit_nlinear_workspace {
  pygsl_multifit_nlinear_workspace(const MODULEWRAP(type) * T,
				   const MODULEWRAP(parameters) * params,
				 const size_t n, const size_t p){
    
    pygsl_multifit_nlinear_workspace * obj = NULL;
    int line = __LINE__;
    
    obj = (pygsl_multifit_nlinear_workspace *) calloc(1, sizeof(pygsl_multifit_nlinear_workspace));

    memset(&obj->params.fdf, 0, sizeof(MODULEWRAP(fdf)) );

    obj->params.f = NULL;
    obj->params.df = NULL;
    obj->params.fvv = NULL;
    obj->params.args = NULL;
    obj->params.callback = NULL;
    obj->params.callback_params = NULL;
    obj->params.fdf.params = &obj->params;
    obj->params.fdf.f = NULL;
    obj->params.fdf.df = NULL;
    obj->params.fdf.fvv = NULL;
    obj->params.self_pyobj = NULL;
    obj->w = NULL;
    
    obj->w = MODULEWRAP(alloc)(T, params, n, p);
    if(obj->w == NULL){
      PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line - 2);
      free(obj);
      PyGSL_error_flag(PyGSL_ANY);
      return NULL;
    }

    obj->params.fdf.f = PyGSL_multifit_nlinear_callback_f;
    obj->params.fdf.p = p;
    obj->params.fdf.n = n;
    Py_INCREF(Py_None);
    obj->params.self_pyobj = Py_None;
    obj->params.callback_params = NULL;
    obj->params.buf_is_set = 0;
    return obj;
  }
  
  ~pygsl_multifit_nlinear_workspace(void){
    FUNC_MESS_BEGIN();
    Py_XDECREF(self->params.f);
    self->params.f = NULL;
    Py_XDECREF(self->params.df);
    self->params.df = NULL;
    Py_XDECREF(self->params.fvv);
    self->params.fvv = NULL;
    Py_XDECREF(self->params.args);
    self->params.args = NULL;
    Py_XDECREF(self->params.callback);
    self->params.callback = NULL;
    Py_XDECREF(self->params.callback_params);
    self->params.callback_params = NULL;

    Py_XDECREF(self->params.self_pyobj);
    self->params.self_pyobj = NULL;
    FUNC_MESS_END();
  }

  gsl_error_flag_drop init(const gsl_vector * x, PyObject * f, PyObject *df = NULL,
			   PyObject *fvv = NULL,  PyObject *args=NULL){
    int status = GSL_SUCCESS, line = __LINE__;

    FUNC_MESS_BEGIN();
    status = pygsl_multifit_nlinear_handle_callbacks(self, f, df, fvv, args);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }

    DEBUG_MESS(2, "Calling MODULEWRAP(init x[0] = %e", gsl_vector_get(x, 0));
    status = MODULEWRAP(init)(x, &self->params.fdf, self->w);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }
    
    FUNC_MESS_END();
    return status;
      
  fail:
    FUNC_MESS("FAIL");
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
  }
  
  gsl_error_flag_drop winit(const gsl_vector * x, const gsl_vector * wts,
			    PyObject * f, PyObject *df = NULL, PyObject *fvv = NULL,
			    PyObject *args = NULL){
    int status = GSL_SUCCESS, line = __LINE__;

    FUNC_MESS_BEGIN();
    status = pygsl_multifit_nlinear_handle_callbacks(self, f, df, fvv, args);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }
    
    status = MODULEWRAP(winit)(x, wts, &self->params.fdf, self->w);
    if(status != GSL_SUCCESS){
      line = __LINE__ - 2;
      goto fail;
    }

    FUNC_MESS_END();
    return status;
    
  fail:
    FUNC_MESS("FAIL");
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
 }

  gsl_error_flag_drop iterate(void){
    self->params.exception_occured = GSL_SUCCESS;
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
    status = PyGSL_multifit_nlinear_driver(self, maxiter, xtol, gtol, ftol,
					   callback, callback_params, OUTPUT);
    
    switch(status){
    case GSL_SUCCESS:
      break;
      line = __LINE__ - 5;
      goto fail;
    }
    
    FUNC_MESS_END();
    return status;
    
  fail:
    FUNC_MESS("FAIL");
    PyGSL_add_traceback(pygsl_multifit_nlinear_module, __FILE__, __FUNCTION__, line);
    return status;
  }

  PyObject * jac(void){
    gsl_matrix * m = NULL;
    m = MODULEWRAP(jac)(self->w);
    return (PyObject*) PyGSL_copy_gslmatrix_to_pyarray(m);
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


