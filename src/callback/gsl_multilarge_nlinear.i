/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * year: 2024
 */
%include gsl_error_typemap.i
%include gsl_block_typemaps.i

%define MULTFIT_NLINAR_DOC
"Wrapper for the multilarge_nlinear module"
%enddef

%module(docstring=MULTFIT_NLINAR_DOC) multilarge_nlinear
%feature ("autodoc", "3");

%init{
  module = m;
  init_pygsl();
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
#include <gsl/gsl_multilarge_nlinear.h>
#include <pygsl/block_helpers.h>
static PyObject *module = NULL;
#include "function_helpers_multifit_nlinear.ic"


typedef struct {
    gsl_multilarge_nlinear_fdf fdf;
    PyObject *f;
    PyObject *df;
    PyObject *fvv;
    PyObject *arguments;
    const char * c_f_func_name;
    const char * c_df_func_name;
    const char * c_fvv_func_name;
} pygsl_multilarge_nlinear_fdf;


typedef struct {
    PyObject * fdf_py;
    pygsl_multilarge_nlinear_fdf *fdf;
    gsl_multilarge_nlinear_workspace * w;
} pygsl_multilarge_nlinear_workspace;



static int
pygsl_multilarge_nlinear_workspace_set_fdf_py(pygsl_multilarge_nlinear_workspace *self, PyObject *fdf_py){
    FUNC_MESS_BEGIN();
    self->fdf = NULL;
    Py_XDECREF(self->fdf_py);
    self->fdf_py = NULL;

    if((SWIG_ConvertPtr(fdf_py, (void **) &self->fdf, SWIGTYPE_p_pygsl_multilarge_nlinear_fdf, 1)) == -1){
	FUNC_MESS_FAILED();
	GSL_ERROR("object passed for fdf is not pygsl_multilarge_nlinear_fdf", GSL_EINVAL);
    }
    Py_XINCREF(fdf_py);
    self->fdf_py = fdf_py;
    FUNC_MESS_END();
    return GSL_SUCCESS;

}


static int
pygsl_multilarge_nlinear_f(const gsl_vector *x, void *params, gsl_vector *f)
{
    pygsl_multilarge_nlinear_fdf *p = NULL;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    p = (pygsl_multilarge_nlinear_fdf *) params;
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
_pygsl_multilarge_nlinear_df (CBLAS_TRANSPOSE_t TransJ, const gsl_vector * x, const gsl_vector * u,
				  PyObject * callback, PyObject * args, gsl_vector * v, gsl_matrix * JTJ)
{

    PyArrayObject *x_array = NULL, *u_array = NULL, *jtj_a = NULL;
    PyObject *transj_o = NULL, *use_jtj_o = NULL, *ret_o = NULL, *ret_elem = NULL, *arglist=NULL;
    int status = GSL_EFAILED, uses_jtj = 0, trb_lineno=-1;
    PyGSL_error_info  info;
    gsl_matrix_view jtj_view;

    FUNC_MESS_BEGIN();

    if(JTJ){
	uses_jtj = 1;
    }
    DEBUG_MESS(2, "pygsl.multilarge_nlinear df  uses JTJ %s", (uses_jtj) ? "yes": "no");
    DEBUG_MESS(4, "pygsl.multilarge_nlinear df v size %lu",
	       (unsigned long) v->size);
    if(uses_jtj){
	DEBUG_MESS(4, "pygsl.multilarge_nlinear df JTJ[ %lu, %lu]",
		   (unsigned long) JTJ->size1, (unsigned long) JTJ->size2);
    }
    x_array = PyGSL_copy_gslvector_to_pyarray(x);
    if (x_array == NULL){
	trb_lineno = __LINE__ - 2;
	goto fail;
    }
    u_array = PyGSL_copy_gslvector_to_pyarray(u);
    if (u_array == NULL){
	trb_lineno = __LINE__ - 2;
	goto fail;
    }
    arglist = PyTuple_New(5);
    if(arglist == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
    }
    transj_o = PyInt_FromLong((long) TransJ);
    if(transj_o == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
    }
    PyTuple_SetItem(arglist, 0, transj_o);
    transj_o = NULL;
    PyTuple_SetItem(arglist, 1, (PyObject *) x_array);
    x_array = NULL;
    PyTuple_SetItem(arglist, 2, (PyObject *) u_array);
    u_array = NULL;
    assert(args);
    Py_XINCREF(args);
    PyTuple_SetItem(arglist, 3, args);
    args = NULL;
    use_jtj_o = PyBool_FromLong(uses_jtj);
    if(use_jtj_o == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
    }
    PyTuple_SetItem(arglist, 4, use_jtj_o);
    use_jtj_o = NULL;

    FUNC_MESS("    Call Python Object BEGIN");
    ret_o  = PyObject_CallObject(callback, arglist);
    FUNC_MESS("    Call Python Object END");

    info.callback = callback;
    info.message  = "pygsl.multilarge_nlinear_df";
    info.error_description = "checking returned object";
    status = PyGSL_CHECK_PYTHON_RETURN(ret_o, 2, &info);
    if(status != GSL_SUCCESS){
	trb_lineno = __LINE__ - 2;
	goto fail;
    }
    info.error_description = "checking returned v";
    info.argnum = 0;
    ret_elem = PySequence_GetItem(ret_o, 0);
    if(!ret_elem){
	trb_lineno = __LINE__ - 2;
	status = GSL_EBADFUNC;
	goto fail;
    }
    status = PyGSL_copy_pyarray_to_gslvector(v, ret_elem, v->size, &info);
    if(status != GSL_SUCCESS){
	trb_lineno = __LINE__ - 2;
	DEBUG_MESS(2, "Could not convert v  = arg 1 to gsl vector, status = %d", status);
	goto fail;
    }
    ret_elem = PySequence_GetItem(ret_o, 1);
    if(!ret_elem){
	trb_lineno = __LINE__ - 1;
	status = GSL_EBADFUNC;
	// todo: who owns ret_elem: I think ret_o
	ret_elem = NULL;
	goto fail;
    }
    info.argnum = 1;

    if(uses_jtj){
	/* copy only lower half of JTJ */
	/* currently not checking if upper half is zero */
	npy_intp stride1 = -1, stride2 = -1;
	jtj_a = PyGSL_matrix_check(ret_elem, JTJ->size1, JTJ->size2, PyGSL_DARRAY_CINPUT(1), &stride1, &stride2, &info);
	if(!jtj_a){
	    trb_lineno = __LINE__ - 2;
	    goto fail;
	}
	DEBUG_MESS(2, "JTJ.shape = [%lu %lu] strides = [%lu, %li] ",
		   (unsigned long) JTJ->size1, (unsigned long) JTJ->size2, (long) stride1, (long) stride2);
	jtj_view = gsl_matrix_view_array(PyArray_DATA(jtj_a), PyArray_DIM(jtj_a, 0), PyArray_DIM(jtj_a, 1));
	status = _pygsl_matrix_copy_lower_triangle(&jtj_view.matrix, JTJ);
	if(status != GSL_SUCCESS){
	    trb_lineno = __LINE__ - 2;
	    goto fail;
	}
    } else {
	if(ret_elem == Py_None){
	    ret_elem = NULL;
	} else{
	    status = GSL_EBADFUNC;
	    trb_lineno = __LINE__;
	    DEBUG_MESS(2, "pygsl.multilarge_nlinear df not using jtj %d = 0, but jtj @ %p is not Py_None",
		       uses_jtj, ret_elem);
	    ret_elem = NULL;
	    gsl_error("pygsl.multilarge_nlinear df not using jtj but jtj is not Py_None",
		      __FILE__, trb_lineno, status);
	    goto fail;
	}
    }
    Py_XDECREF(jtj_a);
    FUNC_MESS_END();
    return GSL_SUCCESS;

fail:
    FUNC_MESS_FAILED();
    Py_XDECREF(x_array);
    Py_XDECREF(u_array);
    Py_XDECREF(transj_o);
    Py_XDECREF(use_jtj_o);
    Py_XDECREF(arglist);
    Py_XDECREF(ret_o);
    Py_XDECREF(jtj_a);
    return status;
}

static int
pygsl_multilarge_nlinear_df (CBLAS_TRANSPOSE_t TransJ, const gsl_vector * x, const gsl_vector * u, void * params, gsl_vector * v, gsl_matrix * JTJ)
{
    pygsl_multilarge_nlinear_fdf *p = NULL;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    p = (pygsl_multilarge_nlinear_fdf *) params;
    assert(p);
    if(!p->df){
	FUNC_MESS_FAILED();
	GSL_ERROR("multfit_nlinear: No python callback for function df", GSL_EINVAL);
	return GSL_EINVAL;
    }
    status = _pygsl_multilarge_nlinear_df(TransJ, x, u, p->df, p->arguments, v, JTJ);
    if(status != GSL_SUCCESS){
	DEBUG_MESS(2, " _pygsl_multilarge_nlinear_df failed with %d", status);
	return status;
    }
    FUNC_MESS_END();
    return status;
}


static int
pygsl_multilarge_nlinear_fvv(const gsl_vector * x, const gsl_vector * v, void * params, gsl_vector * fvv)
{
    pygsl_multilarge_nlinear_fdf *p = NULL;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    p = (pygsl_multilarge_nlinear_fdf *) params;
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
PyGSL_multilarge_nlinear_driver_callback(const size_t iter, void *params, const gsl_multilarge_nlinear_workspace *w)
{
    PyGSL_multifitorlarge_nlinear_driver_callback(iter, params);
}

int driver(const size_t maxiter, const double xtol, const double gtol, const double ftol,
	   PyObject *callback, PyObject *args, int *OUTPUT, PyObject *workspace_o)
{
    int status = GSL_EFAILED;
    void (*cb)(const size_t iter, void *params,  const gsl_multilarge_nlinear_workspace *w) = NULL;
    pygsl_multifitorlarge_nlinear_driver_callback cb_args;
    pygsl_multilarge_nlinear_workspace *workspace;
    void * cb_args_v = NULL;

    FUNC_MESS_BEGIN();

    if((SWIG_ConvertPtr(workspace_o, (void **) &workspace, SWIGTYPE_p_pygsl_multilarge_nlinear_workspace, 1)) == -1){
	status = GSL_EINVAL;
	pygsl_error("object passed for workspace is not pygsl_multilarge_nlinear_workspace", __FILE__, __LINE__, GSL_EINVAL);
	goto fail;
    }

    if(callback == Py_None){
	cb = NULL;
	cb_args_v = NULL;
    } else if(PyCallable_Check(callback)){
	if(!args){
	    status = GSL_ESANITY;
	    pygsl_error("callback args == NULL", __FILE__, __LINE__, status);
	    goto fail;
	}
	cb_args.callback = callback;
	cb_args.callback_arguments = args;
	cb_args.workspace = workspace_o;
	cb_args_v = (void *) &cb_args;
	cb = PyGSL_multilarge_nlinear_driver_callback;
    } else {
	status = GSL_EINVAL;
	pygsl_error("Object provided for callable is not callable (nor None)", __FILE__, __LINE__, status);
	goto fail;
    }

    assert(workspace);
    assert(workspace->w);
    DEBUG_MESS(2, "python workspace @ %p w @ %p, fdf @ %p",
	       (void *) workspace, (void *) workspace->w, (void *) workspace->w->fdf);

    assert(workspace->w->fdf);
    DEBUG_MESS(2, "Calling driver with maxiter %ld cb %p cb_args_v %p", (long) maxiter, (void *) cb, cb_args_v);
    DEBUG_MESS(2, "Calling driver c callbacks: f @ %p, df @ %p, fvv @ %p",
	       (void *) workspace->w->fdf->f, (void *) workspace->w->fdf->df, (void *) workspace->w->fdf->fvv);

    if(cb_args_v){
	if((status = setjmp(cb_args.jbuf)) != 0){
	    DEBUG_MESS(2, "Jump buffer returned failure, status = %d!", status);
	    goto fail;
	}
    }
    status = gsl_multilarge_nlinear_driver(maxiter, xtol, gtol, ftol, cb, cb_args_v, OUTPUT, workspace->w);
    if(status != GSL_SUCCESS){
	goto fail;
    }
    FUNC_MESS_END();
    return status;

fail:
    FUNC_MESS_FAILED();
    assert(status != GSL_SUCCESS);
    PyGSL_ERROR_FLAG(status);
    return status;
}

static PyObject *
pygsl_matrix_copy_lower_triangle(const gsl_matrix * in, const double fill_value)
{
    PyArrayObject *outa = NULL;
    PyGSL_array_index_t dims[] = {in->size1, in->size2};
    gsl_matrix_view  out;
    int status = GSL_EFAILED;

    FUNC_MESS_BEGIN();
    outa = PyGSL_New_Array(2, dims, NPY_DOUBLE);
    if(!outa){
	goto fail;
    }
    out = gsl_matrix_view_array(PyArray_DATA(outa), PyArray_DIM(outa, 0), PyArray_DIM(outa, 1));
    DEBUG_MESS(4, "in size = [%lu, %lu] dims = [%lu, %lu] out array [%lu, %lu] out matrix [%lu, %lu]",
	       (unsigned long) in->size1, (unsigned long) in->size2,
	       (unsigned long) dims[0], (unsigned long) dims[1],
	       (unsigned long) PyArray_DIM(outa, 0), (unsigned long) PyArray_DIM(outa, 1),
	       (unsigned long) out.matrix.size1, (unsigned long) out.matrix.size2
	);

    gsl_matrix_set_all(&out.matrix, fill_value);

    status = _pygsl_matrix_copy_lower_triangle(in, &out.matrix);
    if(PyGSL_ERROR_FLAG(status) != GSL_SUCCESS){
	goto fail;
    }
    FUNC_MESS_END();
    return (PyObject *) outa;

fail:
    FUNC_MESS_FAILED();
    Py_XDECREF(outa);
    return NULL;
}

%}


%rename(fdf) pygsl_multilarge_nlinear_fdf;
typedef struct {
    %immutable;
} pygsl_multilarge_nlinear_fdf;


// todo ... rename it to something better
%rename (workspace) pygsl_multilarge_nlinear_workspace;
typedef struct {
    %immutable;
} pygsl_multilarge_nlinear_workspace;


%rename (parameters) gsl_multilarge_nlinear_parameters;
typedef struct {
    %immutable;
} gsl_multilarge_nlinear_parameters;


%extend gsl_multilarge_nlinear_parameters {
    gsl_multilarge_nlinear_parameters(void){
	gsl_multilarge_nlinear_parameters *p, tmp;

	FUNC_MESS_BEGIN();
	p = (gsl_multilarge_nlinear_parameters *) calloc(1, sizeof(gsl_multilarge_nlinear_parameters));
	if(!p){
	    FUNC_MESS_FAILED();
	    PyGSL_ERROR_NULL("multfit nlinear params, can not allocate space", GSL_ENOMEM);
	    return NULL;
	}
	tmp = gsl_multilarge_nlinear_default_parameters();
	memcpy(p, &tmp, sizeof(gsl_multilarge_nlinear_parameters));
	FUNC_MESS_END();
	return p;
    }

    ~gsl_multilarge_nlinear_parameters(void){
	free(self);
    }

    void set_trs(const gsl_multilarge_nlinear_trs *trs){
	self->trs = trs;
    }
    void set_scale(const gsl_multilarge_nlinear_scale *scale){
	self->scale = scale;
    }
    void set_solver(const gsl_multilarge_nlinear_solver *solver){
	self->solver = solver;
    }
    const gsl_multilarge_nlinear_trs * get_trs(){
	return self->trs;
    }
    const gsl_multilarge_nlinear_scale * get_scale(void){
	return self->scale;
    }
    const gsl_multilarge_nlinear_solver * get_solver(void){
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
    double get_avmax(void) {
	return self->avmax;
    }
    double get_h_df(void){
	return self->h_df;
    }
    double get_h_fvv(void){
	return self->h_fvv;
    }
}


%extend pygsl_multilarge_nlinear_fdf{
    ~pygsl_multilarge_nlinear_fdf(void){
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

    pygsl_multilarge_nlinear_fdf(PyObject *f, PyObject *df, PyObject *fvv,
			       PyObject *args, size_t n, size_t p){

	pygsl_multilarge_nlinear_fdf * ptr = NULL;
	int status = GSL_EFAILED;

	FUNC_MESS_BEGIN();
	ptr = (pygsl_multilarge_nlinear_fdf *) calloc(1, sizeof(pygsl_multilarge_nlinear_fdf));
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
	ptr->fdf.f = pygsl_multilarge_nlinear_f;
	ptr->fdf.df = pygsl_multilarge_nlinear_df;
	ptr->fdf.fvv = pygsl_multilarge_nlinear_fvv;


	if(!PyCallable_Check(f)){
	    status = GSL_EINVAL;
	    pygsl_error("Object for callback 'f' not callable!", __FILE__, __LINE__, status);
	    goto fail;
	}
	Py_XINCREF(f);
	ptr->f = f;

	if(df == Py_None){
	    ptr->df = NULL;
	    ptr->fdf.df = NULL;
	} else if(PyCallable_Check(df)){
	    Py_XINCREF(df);
	    ptr->df = df;
	} else {
	    status = GSL_EINVAL;
	    pygsl_error("Object for callback 'df' neither None nor callable!",  __FILE__, __LINE__, status);
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
    size_t nevaldfu() {
	return self->fdf.nevaldfu;
    }
    size_t nevaldf2() {
	return self->fdf.nevaldf2;
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


%apply gsl_vector *IN {const gsl_vector * weights};

%extend pygsl_multilarge_nlinear_workspace{
    pygsl_multilarge_nlinear_workspace(
	const gsl_multilarge_nlinear_type * T,
	const gsl_multilarge_nlinear_parameters * params,
	size_t n, size_t p
	){
	pygsl_multilarge_nlinear_workspace * pw = NULL;

	FUNC_MESS_BEGIN();
	pw = (pygsl_multilarge_nlinear_workspace *) calloc(1, sizeof(pygsl_multilarge_nlinear_workspace));
	if(!pw){
	    pygsl_error("could not allocate gsl multilarge nlinear workspace", __FILE__, __LINE__,  GSL_ENOMEM);
	    goto fail;
	}
	pw->w = NULL;
	pw->fdf = NULL;
	pw->fdf_py = NULL;
	pw->w = gsl_multilarge_nlinear_alloc(T, params, n, p);
	if(!pw->w){
	    pygsl_error("could not allocate pygsl multilarge nlinear workspace", __FILE__, __LINE__,  GSL_ENOMEM);
	    goto fail;
	}
	FUNC_MESS_END();
	return pw;
    fail:
	if(pw){
	    free(pw);
	}
	return NULL;
    }

    ~pygsl_multilarge_nlinear_workspace(){
	FUNC_MESS_BEGIN();
	self->fdf = NULL;
	Py_XDECREF(self->fdf_py);
	self->fdf_py = NULL;
	if (self->w){
	    gsl_multilarge_nlinear_free(self->w);
	    self->w = NULL;
	}
	free(self);
	FUNC_MESS_END();
    }

    const char * name() {
	return gsl_multilarge_nlinear_name(self->w);
    }

    const char * trs_name() {
	return gsl_multilarge_nlinear_trs_name(self->w);
    }

    size_t niter() {
	return gsl_multilarge_nlinear_niter(self->w);
    }

    double avratio() {
	return gsl_multilarge_nlinear_avratio(self->w);
    }


    gsl_error_flag test(const double xtol, const double gtol,
			const double ftol, int *OUTPUT) {
	return gsl_multilarge_nlinear_test(xtol, gtol, ftol, OUTPUT, self->w);
    }

    gsl_error_flag iterate () {
	return gsl_multilarge_nlinear_iterate(self->w);
    }

    gsl_error_flag_drop init(const gsl_vector *x, PyObject* fdf_py) {
	int status;
	FUNC_MESS_BEGIN();
	status = pygsl_multilarge_nlinear_workspace_set_fdf_py(self, fdf_py);
	if(status != GSL_SUCCESS){
	    FUNC_MESS_FAILED();
	    return status;
	}
	assert(self->fdf);
	self->w->fdf = &self->fdf->fdf;
	assert(self->w->fdf);
	assert(self->fdf->fdf.f);
	DEBUG_MESS(2, "self @ %p self->w @ %p, fdf @ %p",
		   (void *) self, (void *) self->w, (void *) self->w->fdf);
	status = gsl_multilarge_nlinear_init(x, self->w->fdf, self->w);
	FUNC_MESS_END();
	return status;
    }

    gsl_error_flag_drop winit(const gsl_vector *x, const gsl_vector *weights, PyObject* fdf_py) {
	int status;
	FUNC_MESS_BEGIN();
	status = pygsl_multilarge_nlinear_workspace_set_fdf_py(self, fdf_py);
	if(status != GSL_SUCCESS){
	    FUNC_MESS_FAILED();
	    return status;
	}
	assert(self->fdf);
	self->w->fdf = &self->fdf->fdf;
	assert(self->w->fdf);
	assert(self->fdf->fdf.f);
	DEBUG_MESS(2, "self @ %p, self->fdf @ %p self->fdf->fdf.params @ %p, self->fdf->arguments @ %p",
		   (void * ) self, (void *) self->fdf, (void *) self->fdf->fdf.params,
		   (void *) self->fdf->arguments
	    );
	status = gsl_multilarge_nlinear_winit(x, weights, &self->fdf->fdf, self->w);
	FUNC_MESS_END();
	return status;
    }

    PyObject * residual () {
	PyArrayObject *r = NULL;
	gsl_vector *v = NULL;

	FUNC_MESS_BEGIN();
	v = gsl_multilarge_nlinear_residual(self->w);
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
	status = gsl_multilarge_nlinear_rcond(OUTPUT, self->w);
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
	v = gsl_multilarge_nlinear_position(self->w);
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

    PyObject* covar()
    {
	PyArrayObject *ra = NULL;
	gsl_matrix_view covar;
	npy_intp dims[] = {self->w->p, self->w->p};
	int status = GSL_EFAILED;

	FUNC_MESS_BEGIN();

	ra = PyGSL_New_Array(2, dims, NPY_DOUBLE);
	if(!ra){
	    status = GSL_ENOMEM;
	    goto fail;
	}
	covar = gsl_matrix_view_array(PyArray_DATA(ra), PyArray_DIM(ra, 0), PyArray_DIM(ra, 1));
	status = gsl_multilarge_nlinear_covar(&covar.matrix, self->w);
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


}


PyObject * pygsl_matrix_copy_lower_triangle(const gsl_matrix * IN, const double fill_value = GSL_NAN);


gsl_error_flag_drop _pygsl_matrix_copy_lower_triangle(const gsl_matrix * IN, gsl_matrix * OUT);

gsl_error_flag_drop driver(const size_t maxiter, const double xtol, const double gtol, const double ftol,
			   PyObject *callback, PyObject *args, int *OUTPUT, PyObject *workspace_o);


%rename (trust) gsl_multilarge_nlinear_trust;
extern const gsl_multilarge_nlinear_type * gsl_multilarge_nlinear_trust;

/* trust region subproblem methods */
%rename ( trs_lm         ) gsl_multilarge_nlinear_trs_lm;
%rename ( trs_lmaccel    ) gsl_multilarge_nlinear_trs_lmaccel;
%rename ( trs_dogleg     ) gsl_multilarge_nlinear_trs_dogleg;
%rename ( trs_ddogleg    ) gsl_multilarge_nlinear_trs_ddogleg;
%rename ( trs_subspace2D ) gsl_multilarge_nlinear_trs_subspace2D;
%rename ( trs_cgst       ) gsl_multilarge_nlinear_trs_cgst;

extern const gsl_multilarge_nlinear_trs * gsl_multilarge_nlinear_trs_lm;
extern const gsl_multilarge_nlinear_trs * gsl_multilarge_nlinear_trs_lmaccel;
extern const gsl_multilarge_nlinear_trs * gsl_multilarge_nlinear_trs_dogleg;
extern const gsl_multilarge_nlinear_trs * gsl_multilarge_nlinear_trs_ddogleg;
extern const gsl_multilarge_nlinear_trs * gsl_multilarge_nlinear_trs_subspace2D;
extern const gsl_multilarge_nlinear_trs * gsl_multilarge_nlinear_trs_cgst;

/* scaling matrix strategies */
%rename ( scale_levenberg ) gsl_multilarge_nlinear_scale_levenberg;
%rename ( scale_marquardt ) gsl_multilarge_nlinear_scale_marquardt;
%rename ( scale_more      ) gsl_multilarge_nlinear_scale_more;


extern const gsl_multilarge_nlinear_scale * gsl_multilarge_nlinear_scale_levenberg;
extern const gsl_multilarge_nlinear_scale * gsl_multilarge_nlinear_scale_marquardt;
extern const gsl_multilarge_nlinear_scale * gsl_multilarge_nlinear_scale_more;

/* linear solvers */
%rename ( solver_cholesky  ) gsl_multilarge_nlinear_solver_cholesky;
%rename ( solver_mcholesky ) gsl_multilarge_nlinear_solver_mcholesky;

extern const gsl_multilarge_nlinear_solver * gsl_multilarge_nlinear_solver_cholesky;
extern const gsl_multilarge_nlinear_solver * gsl_multilarge_nlinear_solver_mcholesky;
