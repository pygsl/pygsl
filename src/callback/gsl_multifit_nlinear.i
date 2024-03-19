/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
%include gsl_error_typemap.i
%include gsl_block_typemaps.i

%define MULTFIT_NLINAR_DOC
"Wrapper for the multifit_nlinear module"
%enddef

%module(docstring=MULTFIT_NLINAR_DOC) multifit_nlinear
%feature ("autodoc", "3");

%init{
  init_pygsl();
  /* to use at traceback */
  module = m;
}

%pythoncode {
def strinfo(info: int) -> str:
    """explanation of the integer info

    info is either returned by the driver of by the
    test method
    """
    d = {1: "small step size", 2: "small gradient"}
    return d[info]

}

%{

#include <gsl/gsl_multifit_nlinear.h>
#include <pygsl/block_helpers.h>

static PyObject * module = NULL;
#include "function_helpers_multifit_nlinear.ic"


typedef struct {
    gsl_multifit_nlinear_fdf fdf;
    PyObject *f;
    PyObject *df;
    PyObject *fvv;
    PyObject *arguments;
    const char * c_f_func_name;
    const char * c_df_func_name;
    const char * c_fvv_func_name;
} pygsl_multifit_nlinear_fdf;


typedef struct {
    PyObject * fdf_py;
    pygsl_multifit_nlinear_fdf *fdf;
    gsl_multifit_nlinear_workspace * w;
} pygsl_multifit_nlinear_workspace;



static int
pygsl_multifit_nlinear_workspace_set_fdf_py(pygsl_multifit_nlinear_workspace *self, PyObject *fdf_py){
    FUNC_MESS_BEGIN();
    self->fdf = NULL;
    Py_XDECREF(self->fdf_py);
    self->fdf_py = NULL;

    if((SWIG_ConvertPtr(fdf_py, (void **) &self->fdf, SWIGTYPE_p_pygsl_multifit_nlinear_fdf, 1)) == -1){
	FUNC_MESS_FAILED();
	GSL_ERROR("object passed for fdf is not pygsl_multifit_nlinear_fdf", GSL_EINVAL);
	return GSL_EINVAL;
    }
    Py_XINCREF(fdf_py);
    self->fdf_py = fdf_py;
    assert(self->fdf);
    FUNC_MESS_END();
    return GSL_SUCCESS;
}


static int
pygsl_multifit_nlinear_f(const gsl_vector *x, void *params, gsl_vector *f)
{
    pygsl_multifit_nlinear_fdf *p = NULL;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    p = (pygsl_multifit_nlinear_fdf *) params;
    assert(p);
    if(!p->f){
	FUNC_MESS_FAILED();
	GSL_ERROR("multfit_nlinear: No python callback for function f", GSL_EINVAL);
	return GSL_EINVAL;
    }
    status = PyGSL_function_wrap_Op_On(x, f, p->f, p->arguments, x->size, f->size, p->c_f_func_name);
    FUNC_MESS_END();
    return status;
}


static int
pygsl_multifit_nlinear_df(const gsl_vector *x, void *params, gsl_matrix *df)
{
    pygsl_multifit_nlinear_fdf *p = NULL;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    p = (pygsl_multifit_nlinear_fdf *) params;
    assert(p);
    if(!p->df){
	FUNC_MESS_FAILED();
	GSL_ERROR("multfit_nlinear: No python callback for function df", GSL_EINVAL);
	return GSL_EINVAL;
    }
    status = PyGSL_function_wrap_Op_Opn(x, df, p->df, p->arguments, df->size1, x->size, p->c_df_func_name);
    FUNC_MESS_END();
    return status;
}


static int
pygsl_multifit_nlinear_fvv(const gsl_vector * x, const gsl_vector * v, void * params, gsl_vector * fvv)
{
    pygsl_multifit_nlinear_fdf *p = NULL;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    p = (pygsl_multifit_nlinear_fdf *) params;
    assert(p);
    if(!p->df){
	FUNC_MESS_FAILED();
	GSL_ERROR("multfit_nlinear: No python callback for function fvv", GSL_EINVAL);
	return GSL_EINVAL;
    }
    status = PyGSL_function_wrap_OpOp_On(x, v, fvv, p->fvv, p->arguments, v->size, x->size, p->c_df_func_name);
    FUNC_MESS_END();
    return status;
}

static void
PyGSL_multifit_nlinear_driver_callback(const size_t iter, void *params, const gsl_multifit_nlinear_workspace *w)
{
    int trb_lineno = __LINE__, status = GSL_EFAILED;
    pygsl_multifitorlarge_nlinear_driver_callback * p = NULL;

    FUNC_MESS_BEGIN();
    if(!params){
	trb_lineno = __LINE__ - 1;
	status = GSL_ESANITY;
	pygsl_error("multifit_nlinear_callback params NULL?", __FILE__, trb_lineno, status);
	goto fail;
     }
    p = (pygsl_multifitorlarge_nlinear_driver_callback *) params;

    PyGSL_multifitorlarge_nlinear_driver_callback(iter, p);
    FUNC_MESS_END();
    return;

fail:
    FUNC_MESS_FAILED();
    DEBUG_MESS(2, "failed with status %d", status);
    if(p){
	longjmp(p->jbuf, status);
    } else{
	fprintf(stderr, "ERROR ERROR ERROR\n gsl_status = %d can not flag error!\n ERROR ERROR ERROR", status);
    }
}


static int
driver(const size_t maxiter, const double xtol, const double gtol, const double ftol,
       PyObject *callback, PyObject *args, int *OUTPUT, PyObject *workspace_o)
{
    int status = GSL_EFAILED;
    void (*cb)(const size_t iter, void *params,  const gsl_multifit_nlinear_workspace *w) = NULL;
    pygsl_multifitorlarge_nlinear_driver_callback cb_args;
    pygsl_multifit_nlinear_workspace *workspace;
    void * cb_args_v = NULL;

    FUNC_MESS_BEGIN();

    if((SWIG_ConvertPtr(workspace_o, (void **) &workspace, SWIGTYPE_p_pygsl_multifit_nlinear_workspace, 1)) == -1){
	FUNC_MESS_FAILED();
	GSL_ERROR("object passed for workspace is not pygsl_multifit_nlinear_workspace", GSL_EINVAL);
    }

    if(callback == Py_None){
	cb = NULL;
	cb_args_v = NULL;
    } else if(PyCallable_Check(callback)){
	if(!args){
	    status = GSL_ESANITY;
	    pygsl_error("callback args == NULL", __FILE__, __LINE__, status);
	}
	cb_args.callback = callback;
	cb_args.callback_arguments = args;
	cb_args.workspace = workspace_o;
	cb_args_v = (void *) &cb_args;
	cb = PyGSL_multifit_nlinear_driver_callback;
    } else {
	status = GSL_EINVAL;
	pygsl_error("Object provided for callable is not callable (nor None)", __FILE__, __LINE__, status);
	goto fail;
    }

    DEBUG_MESS(2, "Calling driver with maxiter %ld cb %p cb_args_v %p", (long) maxiter, (void *) cb, cb_args_v);
	if((status = setjmp(cb_args.jbuf)) != 0){
	    DEBUG_MESS(2, "Jump buffer returned failure, status = %d!", status);
	    goto fail;
	}
	DEBUG_MESS(2, "Jump buffer set, status = %d (should be 0)", status);

    if(cb_args_v){
    }
    assert(workspace->w->fdf);
    status = gsl_multifit_nlinear_driver(maxiter, xtol, gtol, ftol, cb, cb_args_v, OUTPUT, workspace->w);
    if(PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
	goto fail;
    }
    FUNC_MESS_END();
    return status;

fail:
    FUNC_MESS_FAILED();
    DEBUG_MESS(2, "Failed with status %d", status);
    return status;
}


PyObject* covar(const gsl_matrix *J, const double epsrel)
{
    PyArrayObject *ra = NULL;
    gsl_matrix_view covar;
    npy_intp dims[] = {0, 0};
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();

    dims[0] = J->size2;
    dims[1] = J->size2;
    ra = PyGSL_New_Array(2, dims, NPY_DOUBLE);
    if(!ra){
	status = GSL_ENOMEM;
	goto fail;
    }
    covar = gsl_matrix_view_array(PyArray_DATA(ra), PyArray_DIM(ra, 0), PyArray_DIM(ra, 1));
    status = gsl_multifit_nlinear_covar(J, epsrel, &covar.matrix);
    if(PyGSL_ERROR_FLAG(status) == 0){
	goto fail;
    }
    FUNC_MESS_END();
    return (PyObject *) ra;

fail:
    FUNC_MESS_FAILED();
    Py_XDECREF(ra);
    return NULL;
}

%}


%rename(fdf) pygsl_multifit_nlinear_fdf;
typedef struct {
    %immutable;
} pygsl_multifit_nlinear_fdf;


// todo ... rename it to something better
%rename (workspace) pygsl_multifit_nlinear_workspace;
typedef struct {
    %immutable;
} pygsl_multifit_nlinear_workspace;


%rename (parameters) gsl_multifit_nlinear_parameters;
typedef struct {
    %immutable;
} gsl_multifit_nlinear_parameters;


%extend gsl_multifit_nlinear_parameters {
    gsl_multifit_nlinear_parameters(void){
	gsl_multifit_nlinear_parameters *p, tmp;

	FUNC_MESS_BEGIN();
	p = (gsl_multifit_nlinear_parameters *) calloc(1, sizeof(gsl_multifit_nlinear_parameters));
	if(!p){
	    FUNC_MESS_FAILED();
	    PyGSL_ERROR_NULL("multfit nlinear params, can not allocate space", GSL_ENOMEM);
	    return NULL;
	}
	tmp = gsl_multifit_nlinear_default_parameters();
	memcpy(p, &tmp, sizeof(gsl_multifit_nlinear_parameters));
	FUNC_MESS_END();
	return p;
    }

    ~gsl_multifit_nlinear_parameters(void){
	free(self);
    }

    void set_trs(const gsl_multifit_nlinear_trs *trs){
	self->trs = trs;
    }
    void set_scale(const gsl_multifit_nlinear_scale *scale){
	self->scale = scale;
    }
    void set_solver(const gsl_multifit_nlinear_solver *solver){
	self->solver = solver;
    }
    const gsl_multifit_nlinear_trs * get_trs(){
	return self->trs;
    }
    const gsl_multifit_nlinear_scale * get_scale(void){
	return self->scale;
    }
    const gsl_multifit_nlinear_solver * get_solver(void){
	return self->solver;
    }
    void set_factor_up(const double val) {
	self->factor_up = val;
    }
    void set_factor_down(const double val) {
	self->factor_down = val;
    }
    void set_avmax(const double val) {
	self->avmax = val;
    }
    void set_h_df(const double val){
	self->h_df = val;
    }
    void set_h_fvv(const double val){
	self->h_fvv = val;
    }
    double get_factor_up(void) {
	return self->factor_up;
    }
    double get_factor_down(void) {
	return self->factor_down;
    }
    double set_avmax(void) {
	return self->avmax;
    }
    double get_h_df(void){
	return self->h_df;
    }
    double get_h_fvv(void){
	return self->h_fvv;
    }
}


%extend pygsl_multifit_nlinear_fdf{
    ~pygsl_multifit_nlinear_fdf(void){
	FUNC_MESS_BEGIN();
	Py_XDECREF(self->f);
	Py_XDECREF(self->df);
	Py_XDECREF(self->fvv);
	Py_XDECREF(self->arguments);
	self->f = NULL;
	self->df = NULL;
	self->fvv = NULL;
	self->arguments = NULL;
	self->fdf.params = NULL;
	self->fdf.n = 0;
	self->fdf.p = 0;
	FUNC_MESS_END();
    }

    pygsl_multifit_nlinear_fdf(PyObject *f, PyObject *df, PyObject *fvv,
			       PyObject *args, size_t n, size_t p){

	pygsl_multifit_nlinear_fdf * ptr = NULL;
	int status = GSL_EFAILED;

	FUNC_MESS_BEGIN();
	ptr = (pygsl_multifit_nlinear_fdf *) calloc(1, sizeof(pygsl_multifit_nlinear_fdf));

	if(!ptr){
	    status = GSL_ENOMEM;
	    pygsl_error("Could not allocate pygsl multfit_fdf struct!",  __FILE__, __LINE__, status);
	    goto fail;
	}
	ptr->f = NULL;
	ptr->df = NULL;
	ptr->fvv = NULL;
	ptr->arguments = NULL;

	/* callback functions need to check if python object is not null */
	ptr->fdf.f = pygsl_multifit_nlinear_f;
	ptr->fdf.df = pygsl_multifit_nlinear_df;
	ptr->fdf.fvv = pygsl_multifit_nlinear_fvv;

	if(!PyCallable_Check(f)){
	    status = GSL_EINVAL;
	    pygsl_error("Object for callback 'f' not callable!", __FILE__, __LINE__, status);
	    goto fail;
	}
	Py_XINCREF(f);
	ptr->f = f;
	if(df == Py_None){
	    // nothing to do
	    ptr->df = NULL;
	    ptr->fdf.df = NULL;
	} else if(PyCallable_Check(df)){
	    Py_XINCREF(df);
	    ptr->df = df;
	} else {
	    status = GSL_EINVAL;
	    pygsl_error("Object for callback 'df' neither None nor  callable!",  __FILE__, __LINE__, status);
	    goto fail;
	}

	if(fvv == Py_None){
	    // nothing to do
	    ptr->fvv = NULL;
	    ptr->fdf.fvv = NULL;
	}else if(PyCallable_Check(fvv)){
	    Py_XINCREF(fvv);
	    ptr->fvv = fvv;
	} else {
	    status = GSL_EINVAL;
	    pygsl_error("Object for callback 'fvv' not None, but not callable!",
			__FILE__, __LINE__, status);
	    goto fail;
	}

	Py_XINCREF(args);
	ptr->arguments = args;
	ptr->fdf.n = n;
	ptr->fdf.p = p;
	ptr->fdf.params = (void *) ptr;

	FUNC_MESS_END();
	return ptr;

    fail:
	FUNC_MESS_FAILED();
	assert(PyGSL_error_flag(status) != GSL_SUCCESS);
	return NULL;
	if(ptr){
	    Py_XDECREF(ptr->f);
	    Py_XDECREF(ptr->df);
	    Py_XDECREF(ptr->fvv);
	    Py_XDECREF(args);
	    ptr->f = NULL;
	    ptr->df = NULL;
	    ptr->fvv = NULL;
	    free(ptr);
	}
	// now put exception on stack ...
	// unfortunatley I have a race condition here, so I only do it down
	// here ... pushing my luck
	assert(PyGSL_error_flag(status) != GSL_SUCCESS);
	return NULL;
    }

    size_t nevalf() {
	return self->fdf.nevalf;
    }
    size_t nevaldf() {
	return self->fdf.nevaldf;
    }
    size_t nevalfvv() {
	return self->fdf.nevalfvv;
    }

    size_t get_n() {
	return self->fdf.n;
    }

    size_t get_p() {
	return self->fdf.p;
    }

}


%apply const gsl_vector *IN {const gsl_vector * weights};

%extend pygsl_multifit_nlinear_workspace{
    pygsl_multifit_nlinear_workspace(
	const gsl_multifit_nlinear_type * T,
	const gsl_multifit_nlinear_parameters * params,
	size_t n, size_t p
	){
	pygsl_multifit_nlinear_workspace * pw = NULL;

	FUNC_MESS_BEGIN();
	pw = (pygsl_multifit_nlinear_workspace *) calloc(1, sizeof(pygsl_multifit_nlinear_workspace));
	if(!pw){
	    pygsl_error("could not allocate pygsl multifit nlinear workspace", __FILE__, __LINE__, GSL_ENOMEM);
	    // Todo: set GSL_EMEM;
	    goto fail;
	}
	pw->w = NULL;
	pw->fdf = NULL;
	pw->fdf_py = NULL;
	pw->w = gsl_multifit_nlinear_alloc(T, params, n, p);
	if(!pw->w){
	    pygsl_error("could not allocate multifit nlinear workspace", __FILE__, __LINE__, GSL_ENOMEM);
	    // Todo: set GSL_EMEM / free memory;
	    goto fail;
	}
	FUNC_MESS_END();
	return pw;

    fail:
	FUNC_MESS_FAILED();
	if(pw){
	    free(pw);
	}
	return NULL;
    }

    ~pygsl_multifit_nlinear_workspace(){
	FUNC_MESS_BEGIN();
	self->fdf = NULL;
	Py_XDECREF(self->fdf_py);
	self->fdf_py = NULL;
	if (self->w){
	    gsl_multifit_nlinear_free(self->w);
	    self->w = NULL;
	}
	free(self);
	FUNC_MESS_END();
    }

    const char * name() {
	return gsl_multifit_nlinear_name(self->w);
    }

    const char * trs_name() {
	return gsl_multifit_nlinear_trs_name(self->w);
    }

    size_t niter() {
	return gsl_multifit_nlinear_niter(self->w);
    }

    double avratio() {
	return gsl_multifit_nlinear_avratio(self->w);
    }


    gsl_error_flag test(const double xtol, const double gtol,
			const double ftol, int *OUTPUT) {
	return gsl_multifit_nlinear_test(xtol, gtol, ftol, OUTPUT, self->w);
    }

    gsl_error_flag iterate () {
	return gsl_multifit_nlinear_iterate(self->w);
    }

    gsl_error_flag_drop init(const gsl_vector *x, PyObject* fdf_py) {
	int status = GSL_EFAILED;
	FUNC_MESS_BEGIN();
	status = pygsl_multifit_nlinear_workspace_set_fdf_py(self, fdf_py);
	if(status != GSL_SUCCESS){
	    FUNC_MESS_FAILED();
	    return status;
	}
	assert(self->fdf);
	assert(self->w);
	self->w->fdf = &self->fdf->fdf;
	assert(self->w->fdf);
	assert(self->fdf->fdf.f);
	// assert(self->fdf->fdf.df);
	DEBUG_MESS(2, "fdf @ %p", &self->fdf->fdf);
	status = gsl_multifit_nlinear_init(x, &self->fdf->fdf, self->w);
	FUNC_MESS_END();
	return status;
    }

    gsl_error_flag_drop winit(const gsl_vector *x, const gsl_vector *weights, PyObject* fdf_py) {
	int status = GSL_EFAILED;
	FUNC_MESS_BEGIN();
	status = pygsl_multifit_nlinear_workspace_set_fdf_py(self, fdf_py);
	if(status != GSL_SUCCESS){
	    FUNC_MESS_FAILED();
	    return status;
	}
	assert(self->fdf);
	assert(self->w);
	self->w->fdf = &self->fdf->fdf;
	assert(self->w->fdf);
	assert(self->fdf->fdf.f);
	// assert(self->fdf->fdf.df);
	DEBUG_MESS(2, "self @ %p, self->fdf @ %p self->fdf->fdf.params @ %p, self->fdf->arguments @ %p",
		   (void * ) self, (void *) self->fdf, (void *) self->fdf->fdf.params,
		   (void *) self->fdf->arguments
	    );
	DEBUG_MESS(2, "fdf @ %p", &self->fdf->fdf);
	status = gsl_multifit_nlinear_winit(x, weights, &self->fdf->fdf, self->w);
	FUNC_MESS_END();
	return status;
    }

    PyObject * residual () {
	PyArrayObject *r = NULL;
	gsl_vector *v = NULL;

	FUNC_MESS_BEGIN();
	v = gsl_multifit_nlinear_residual(self->w);
	if(!v){
	    goto fail;
	}
	r =  PyGSL_copy_gslvector_to_pyarray(v);
	if(!r){
	    goto fail;
	}
	FUNC_MESS_END();
	return (PyObject *) r;

    fail:
	FUNC_MESS_FAILED();
	return NULL;
    }

    gsl_error_flag_drop rcond(double *OUTPUT) {
	int status = GSL_EFAILED;

	FUNC_MESS_BEGIN();
	status = gsl_multifit_nlinear_rcond(OUTPUT, self->w);
	if(PyGSL_ERROR_FLAG(status) != GSL_SUCCESS) {
	    goto fail;
	}
	FUNC_MESS_END();
	return status;

    fail:
	FUNC_MESS_FAILED();
	return status;
    }

    PyObject * position() {
	PyArrayObject* r = NULL;
	gsl_vector *v;


	FUNC_MESS_BEGIN();
	v = gsl_multifit_nlinear_position(self->w);
	if(!v){
	    goto fail;
	}
	r =  PyGSL_copy_gslvector_to_pyarray(v);
	if(!r){
	    goto fail;
	}
	FUNC_MESS_END();
	return (PyObject *) r;

    fail:
	FUNC_MESS_FAILED();
	Py_XDECREF(r);
	return NULL;
    }

    PyObject * jac()
    {
	gsl_matrix * J;
	PyArrayObject *r = NULL;

	FUNC_MESS_BEGIN();
	J = gsl_multifit_nlinear_jac(self->w);
	if(!J){
	    gsl_error("multifit_nlinear: no jacobian returned", __FILE__, __LINE__, GSL_ESANITY);
	    FUNC_MESS_FAILED();
	    return NULL;
	}
	r =  PyGSL_copy_gslmatrix_to_pyarray(J);
	FUNC_MESS_END();
	return (PyObject *) r;
  }

}


gsl_error_flag_drop driver(const size_t maxiter, const double xtol, const double gtol, const double ftol,
			   PyObject *callback, PyObject *args, int *OUTPUT, PyObject *workspace);

PyObject* covar(const gsl_matrix *j, const double epsrel);

%rename (trust) gsl_multifit_nlinear_trust;
extern const gsl_multifit_nlinear_type * gsl_multifit_nlinear_trust;

/* trust region subproblem methods */
%rename ( trs_lm         ) gsl_multifit_nlinear_trs_lm;
%rename ( trs_lmaccel    ) gsl_multifit_nlinear_trs_lmaccel;
%rename ( trs_dogleg     ) gsl_multifit_nlinear_trs_dogleg;
%rename ( trs_ddogleg    ) gsl_multifit_nlinear_trs_ddogleg;
%rename ( trs_subspace2D ) gsl_multifit_nlinear_trs_subspace2D;

extern const gsl_multifit_nlinear_trs * gsl_multifit_nlinear_trs_lm;
extern const gsl_multifit_nlinear_trs * gsl_multifit_nlinear_trs_lmaccel;
extern const gsl_multifit_nlinear_trs * gsl_multifit_nlinear_trs_dogleg;
extern const gsl_multifit_nlinear_trs * gsl_multifit_nlinear_trs_ddogleg;
extern const gsl_multifit_nlinear_trs * gsl_multifit_nlinear_trs_subspace2D;

/* scaling matrix strategies */
%rename ( scale_levenberg ) gsl_multifit_nlinear_scale_levenberg;
%rename ( scale_marquardt ) gsl_multifit_nlinear_scale_marquardt;
%rename ( scale_more      ) gsl_multifit_nlinear_scale_more;


extern const gsl_multifit_nlinear_scale * gsl_multifit_nlinear_scale_levenberg;
extern const gsl_multifit_nlinear_scale * gsl_multifit_nlinear_scale_marquardt;
extern const gsl_multifit_nlinear_scale * gsl_multifit_nlinear_scale_more;

/* linear solvers */
%rename ( solver_cholesky  ) gsl_multifit_nlinear_solver_cholesky;
%rename ( solver_mcholesky ) gsl_multifit_nlinear_solver_mcholesky;
%rename ( solver_qr        ) gsl_multifit_nlinear_solver_qr;
%rename ( solver_svd       ) gsl_multifit_nlinear_solver_svd;

extern const gsl_multifit_nlinear_solver * gsl_multifit_nlinear_solver_cholesky;
extern const gsl_multifit_nlinear_solver * gsl_multifit_nlinear_solver_mcholesky;
extern const gsl_multifit_nlinear_solver * gsl_multifit_nlinear_solver_qr;
extern const gsl_multifit_nlinear_solver * gsl_multifit_nlinear_solver_svd;
