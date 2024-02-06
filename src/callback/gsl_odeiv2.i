/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * created: November 2015
 * file: src/odeiv/gsl_odeiv2.i
 *
 * This interface file was generated for gsl version 2.0. It uses hand coded
 * wrappers for the callback. See odeiv_func2.ic
 *
 */
%define ODEIV2DOCSTRING
"Wrapper for the ODEIV2 module"
%enddef

%module(docstring=ODEIV2DOCSTRING)odeiv2
%feature ("autodoc", "3");
%init{
  init_pygsl();
}

%{
#include <stddef.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <odeiv_func2.ic>

typedef struct{
	gsl_odeiv2_system dydt;
	PyGSL_odeiv_parameter_pass params;
}pygsl_odeiv2_system;

/*
 * workarounds to avoid name clashes: the methods extending the type would
 * otherwise get the same name by SWIG as the function names of GSL
 *
*/
typedef gsl_odeiv2_step pygsl_odeiv2_step;
typedef struct{
	gsl_odeiv2_control *control;
	PyArrayObject *scale;
	size_t dimension;
} pygsl_odeiv2_control;
/* avoid name clashes */
typedef gsl_odeiv2_evolve pygsl_odeiv2_evolve;
typedef struct{
	gsl_odeiv2_driver * driver;
	PyObject * sys;
	PyArrayObject * scale;
	size_t dimension;
} pygsl_odeiv2_driver;

static int _pygsl_odeiv2_system_set_function(pygsl_odeiv2_system *self, PyObject * cb)
{
	if(!PyCallable_Check(cb)){
		PyGSL_ERROR("Object for function callback not callable!", GSL_EINVAL);
	}
	Py_XDECREF(self->params.py_func);
	self->params.py_func = NULL;
	self->params.py_func = cb;
	Py_INCREF(self->params.py_func);
	return GSL_SUCCESS;
}

static int _pygsl_odeiv2_system_set_jacobian(pygsl_odeiv2_system *self, PyObject * cb)
{
	if (cb == Py_None){
		Py_XDECREF(self->params.py_jac);
		self->params.py_jac = NULL;
		self->dydt.jacobian = NULL;
		return GSL_SUCCESS;
	}

	if(!PyCallable_Check(cb)){
		PyGSL_ERROR("Object for function callback not callable!", GSL_EINVAL);
	}

	Py_XDECREF(self->params.py_jac);
	self->params.py_jac = cb;
	Py_INCREF(self->params.py_jac);
	self->dydt.jacobian = PyGSL_odeiv_jac;
	return GSL_SUCCESS;
}

static int _pygsl_odeiv2_system_set_dimension(pygsl_odeiv2_system *self, size_t dimension)
{
	self->params.dimension = dimension;
	self->dydt.dimension = dimension;

	return GSL_SUCCESS;
}

/*
 * some steppers require an jacobian. These seem to crash if the jacobian is not available.
 */

struct _pygsl_odeiv2_steppers_require_jacobian{
	const gsl_odeiv2_step_type *type;
	int requires_jacobian;
};

static int _pygsl_odeiv2_check_step_jacobian(const pygsl_odeiv2_step *step, const gsl_odeiv2_system *dydt)
{

	int line = __LINE__, status = GSL_EFAILED;
	struct _pygsl_odeiv2_steppers_require_jacobian *p, _require_jac[]= {
		{gsl_odeiv2_step_rk2, 0},
		{gsl_odeiv2_step_rk4, 0},
		{gsl_odeiv2_step_rkf45, 0},
		{gsl_odeiv2_step_rkck, 0},
		{gsl_odeiv2_step_rk8pd, 0},
		{gsl_odeiv2_step_rk1imp, 1},
		{gsl_odeiv2_step_rk2imp, 1},
		{gsl_odeiv2_step_rk4imp, 1},
		{gsl_odeiv2_step_bsimp, 1},
		{gsl_odeiv2_step_msadams, 0},
		{gsl_odeiv2_step_msbdf, 1},
		/* sentinel */
		{NULL, -1}
	};

	FUNC_MESS_BEGIN();

	for (p = _require_jac; p->type != NULL; ++p){

		if(p->type != step->type){
			/* not the stepper to handle */
			continue;
		}
		switch(p->requires_jacobian){
		case 0:
			DEBUG_MESS(2, "Stepper %s does not require an jacobian",  gsl_odeiv2_step_name(step));
			FUNC_MESS_END();
			return GSL_SUCCESS;
		case 1:
			/* need to treat this case*/
			break;

		default:
			line = __LINE__;
			status =  GSL_ESANITY;
			/* should that not be a pygsl_error */
			DEBUG_MESS(2, "Unexpected requires_jacobian value %d. Expected [0|1]", p->requires_jacobian);
			gsl_error("Unexpected definition of required jacobian", __FILE__, line, status);
			goto fail;
		}

		/*
		 * so this function requires an jacobian ....
		 */
		if(dydt->jacobian){
			/* one found ... goood */
			DEBUG_MESS(2, "Stepper %s  requires jacobian, one found!",
				   gsl_odeiv2_step_name(step));
			FUNC_MESS_END();
			return GSL_SUCCESS;
		}
		status =  GSL_EINVAL;
		line = __LINE__;
		DEBUG_MESS(2, "Stepper %s  requires jacobian, but none defined!",
			   gsl_odeiv2_step_name(step));
		gsl_error("Stepper requires jacobian but none defined", __FILE__, line, status);
		goto fail;

	}
	/* so stepper was not listed if it requires an jacobian ... tsss */
	DEBUG_MESS(2, "Stepper %s unknown if jacobian required: add to internal list!",
		   gsl_odeiv2_step_name(step));
	line = __LINE__;
	status =  GSL_ESANITY;
	gsl_error("Stepper not listed if it requires jacobian", __FILE__, line, status);

  fail:
	FUNC_MESS_FAILED();
	PyGSL_add_traceback(NULL, __FILE__,  __FUNCTION__, line);
	return status;
}


%}

%include gsl_error_typemap.i


%rename(system) pygsl_odeiv2_system;
typedef struct{
	%immutable;
}pygsl_odeiv2_system;
%define ODEIV2SYSTEMCLS
"Odeiv2 system instance

It provides the following methods:
* set_func
* set_jacobian
* set_dimension
"
%enddef
%feature("autodoc", ODEIV2SYSTEMCLS) system;

%extend pygsl_odeiv2_system{
	gsl_error_flag_drop set_func(PyObject * cb){
		return  _pygsl_odeiv2_system_set_function(self, cb);
	}

	gsl_error_flag_drop set_jacobian(PyObject * cb){
		return  _pygsl_odeiv2_system_set_jacobian(self, cb);
	}

	gsl_error_flag_drop set_dimension(size_t dimension){
		return _pygsl_odeiv2_system_set_dimension(self, dimension);
	}

	pygsl_odeiv2_system(PyObject * func, PyObject *jac, size_t dimension, PyObject *args){
		pygsl_odeiv2_system *sys = NULL;
		int flag;

		sys = PyMem_NEW(pygsl_odeiv2_system, 1);
		sys->params.py_func = NULL;
		sys->params.py_jac = NULL;
		sys->params.arguments = NULL;
		sys->dydt.function = PyGSL_odeiv_func;

		flag = _pygsl_odeiv2_system_set_dimension(sys, dimension);
		if(flag != GSL_SUCCESS){
			goto fail;
		}

		flag = _pygsl_odeiv2_system_set_function(sys, func);
		if(flag != GSL_SUCCESS){
			goto fail;
		}

		flag = _pygsl_odeiv2_system_set_jacobian(sys, jac);
		if(flag != GSL_SUCCESS){
			goto fail;
		}

		sys->params.arguments = args;
		Py_INCREF(sys->params.arguments);

		sys->dydt.params = (void *)&sys->params;
		return sys;

	  fail:
		Py_XDECREF(sys->params.py_func);
		Py_XDECREF(sys->params.py_jac);
		Py_XDECREF(sys->params.arguments);
		PyMem_FREE(sys);
		sys = NULL;
		return NULL;
	}

	~pygsl_odeiv2_system(void){
		Py_XDECREF(self->params.py_func);

		Py_XDECREF(self->params.py_jac);
		Py_XDECREF(self->params.arguments);
		self->dydt.function = NULL;
		self->dydt.jacobian  = NULL;
		PyMem_FREE(self);
		self = NULL;
	}
};

typedef struct{
	%immutable;
} pygsl_odeiv2_step;


%extend pygsl_odeiv2_step{
	pygsl_odeiv2_step(const gsl_odeiv2_step_type * T, size_t dim){
		if(T == NULL){
			pygsl_error("Type None/NULL not accepted", __FILE__, __LINE__ -1, GSL_EINVAL);
			return NULL;
		}
		return gsl_odeiv2_step_alloc(T, dim);
	}

	~pygsl_odeiv2_step(void){
		gsl_odeiv2_step_free(self);
	}

	gsl_error_flag_drop reset(void){
		return gsl_odeiv2_step_reset(self);
	}
	const char * name(void){
		return gsl_odeiv2_step_name(self);
	}
	unsigned int order(void){
		return gsl_odeiv2_step_order(self);
	}

	/*
	 * should keep a reference to the driver ...
	 gsl_error_flag_drop set_driver(const gsl_odeiv2_driver * d){
		return gsl_odeiv2_step_set_driver(self, d);
	}
	*/

	PyObject *apply(double t, double h, PyObject * y_o, PyObject *dydt_in_o, PyObject *dydt_out_o,
			pygsl_odeiv2_system * dydt)
	{

		PyObject *returnobj = NULL, *three =NULL;
		PyArrayObject *yerr_a = NULL, *dydt_in_a  = NULL, *dydt_out_a = NULL;
		PyArrayObject *y_out_a = NULL, *y_in_a = NULL;
		double * yerr = NULL, *dydt_in = NULL, *dydt_out = NULL, *y =NULL;
		PyGSL_array_index_t dim = 0;
		int flag, line = __LINE__;


		FUNC_MESS_BEGIN();

		flag = _pygsl_odeiv2_check_step_jacobian(self, &dydt->dydt);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(flag)){
			line = __LINE__ - 2; goto fail;
		}

		dim = dydt->params.dimension;

		if(dydt == NULL){
			line = __LINE__ -1;
			pygsl_error("Type None/NULL not accepted", __FILE__, line, GSL_EINVAL);
			goto fail;
		}


		y_in_a = PyGSL_vector_check(y_o, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
		if(y_in_a == NULL){
			line = __LINE__ - 2; goto fail;
		}

		y_out_a = PyGSL_Copy_Array(y_in_a);
		if(y_out_a == NULL){
			line = __LINE__ - 2; goto fail;
		}
		Py_DECREF(y_in_a);
		y_in_a = NULL;

		yerr_a = PyGSL_New_Array(1,  &dim, NPY_FLOAT);
		if(yerr_a == NULL){
			line = __LINE__ - 2; goto fail;
		}

		if(dydt_in_o == Py_None){
			dydt_in_a = PyGSL_New_Array(1,  &dim, NPY_FLOAT);
			if(dydt_in_a == NULL){
				line = __LINE__ - 2; goto fail;
			}
			dydt_in = (double *)PyArray_DATA(dydt_in_a);
		}

		if(dydt_out_o == Py_None){
			dydt_out_a = PyGSL_New_Array(1,  &dim, NPY_FLOAT);
			if(dydt_out_a == NULL){
				line = __LINE__ - 2; goto fail;
			}
			dydt_out =  (double *) PyArray_DATA(dydt_out_a);
		}

		y =  (double *) PyArray_DATA(y_out_a);
		if(y == NULL){
			line = __LINE__ - 2; goto fail;
		}
		yerr =  (double *) PyArray_DATA(yerr_a);
		if(yerr == NULL){
			line = __LINE__ - 2; goto fail;
		}


		flag = gsl_odeiv2_step_apply(self, t, h, y, yerr, dydt_in, dydt_out, &dydt->dydt);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(flag)){
			line = __LINE__ - 2; goto fail;
		}

		Py_XDECREF(dydt_in_a);
		dydt_in_a = NULL;

		returnobj = PyTuple_New(3);
		if (returnobj == NULL){
			line = __LINE__ - 2; goto fail;
		}
		PyTuple_SetItem(returnobj, 0, (PyObject *) y_out_a);
		PyTuple_SetItem(returnobj, 1, (PyObject *) yerr_a);
		if(dydt_out_a == NULL){
			Py_INCREF(Py_None);
			three = Py_None;
		} else {
			three = (PyObject *) dydt_out_a;
		}
		PyTuple_SetItem(returnobj, 2, three);

		FUNC_MESS_END();
		return returnobj;

	  fail:
		FUNC_MESS_FAILED();
		PyGSL_add_traceback(NULL, __FILE__,  __FUNCTION__, line);
		Py_XDECREF(y_in_a);
		Py_XDECREF(y_out_a);
		Py_XDECREF(yerr_a);
		Py_XDECREF(dydt_in_a);
		Py_XDECREF(dydt_out_a);

		return NULL;

	}
}

%rename(step_rk2)     gsl_odeiv2_step_rk2;
%rename(step_rk4)     gsl_odeiv2_step_rk4;
%rename(step_rkf45)   gsl_odeiv2_step_rkf45;
%rename(step_rkck)    gsl_odeiv2_step_rkck;
%rename(step_rk8pd)   gsl_odeiv2_step_rk8pd;
%rename(step_rk2imp)  gsl_odeiv2_step_rk2imp;
%rename(step_rk4imp)  gsl_odeiv2_step_rk4imp;
%rename(step_bsimp)   gsl_odeiv2_step_bsimp;
%rename(step_rk1imp)  gsl_odeiv2_step_rk1imp;
%rename(step_msadams) gsl_odeiv2_step_msadams;
%rename(step_msbdf)   gsl_odeiv2_step_msbdf;

/* available steppers */
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rk2;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rk4;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rkf45;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rkck;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rk8pd;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rk2imp;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rk4imp;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_bsimp;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_rk1imp;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_msadams;
extern const gsl_odeiv2_step_type *gsl_odeiv2_step_msbdf;

%inline{
const int hadj_inc = GSL_ODEIV_HADJ_INC;
const int hadj_nil = GSL_ODEIV_HADJ_NIL;
const int hadj_dec = GSL_ODEIV_HADJ_DEC;
}

typedef struct{
	%immutable;
} pygsl_odeiv2_control;

%extend pygsl_odeiv2_control{
	pygsl_odeiv2_control(double eps_abs, double eps_rel, double a_y, double a_dydt, PyObject *scale_abs){
		size_t dim= 0;
		PyArrayObject *sa = NULL;
		double * s_abs;
		pygsl_odeiv2_control * r = NULL;

		r = (pygsl_odeiv2_control *) PyMem_Malloc(sizeof(pygsl_odeiv2_control));
		if(r == NULL){
			goto fail;
		}
		r->control = NULL;
		r->scale = NULL;
		r->dimension = 0;

		if(scale_abs == Py_None){
			r->control = gsl_odeiv2_control_standard_new(eps_abs, eps_rel, a_y, a_dydt);
			if(r->control == NULL){
				goto fail;
			}
			return r;
		}
		/*
		 * Warning potential crash ... wrapper must ensure that scale abs
		 * lives as long as required!
		 * Thus reference in self->control
		 */
		sa =  PyGSL_vector_check(scale_abs, -1, PyGSL_DARRAY_CINPUT(5), NULL, NULL);
		if(sa == NULL){
			goto fail;
		}
		r->scale = sa;
		s_abs = (double *) PyArray_DATA(sa);
		r->control = gsl_odeiv2_control_scaled_new(eps_abs, eps_rel, a_y, a_dydt, s_abs, dim);
		if(r->control == NULL){
			goto fail;
		}
		return r;

	  fail:
		Py_XDECREF(sa);
		PyMem_FREE(r);
		return NULL;
	}

	~pygsl_odeiv2_control(void){
		gsl_odeiv2_control_free(self->control);
		self->control = NULL;
		Py_XDECREF(self->scale);
		self->scale = NULL;
	}

	gsl_error_flag_drop init(double eps_abs, double eps_rel, double a_y, double a_dydt){
		return gsl_odeiv2_control_init(self->control, eps_abs, eps_rel, a_y, a_dydt);
	}
	const char * name(void){
		return  gsl_odeiv2_control_name(self->control);
	}

	PyObject * hadjust(pygsl_odeiv2_step * s, PyObject * y_o, PyObject *yerr_o, PyObject * dydt_o, double h_in){
		PyObject *returnobj = NULL, *h_o = NULL, *flag_o = NULL;
		PyArrayObject *y_a = NULL,  *yerr_a = NULL, *dydt_a = NULL;
		double *dydt = NULL, *y = NULL, *yerr = NULL, h=0;
		PyGSL_array_index_t dim=0;
		int flag;


		dim = s->dimension;
		if(dim != self->dimension){
			pygsl_error("dimension of step and control do not match!", __FILE__, __LINE__-1, GSL_EINVAL);
		}
		y_a = PyGSL_vector_check(y_o, dim, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
		if(y_a == NULL){
			goto fail;
		}
		yerr_a = PyGSL_vector_check(yerr_o, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
		if(yerr_a == NULL){
			goto fail;
		}
		dydt_a = PyGSL_vector_check(dydt_o, dim, PyGSL_DARRAY_CINPUT(4), NULL, NULL);
		if(yerr_a == NULL){
			goto fail;
		}

		y    = (double *) PyArray_DATA(y_a);
		yerr = (double *) PyArray_DATA(yerr_a);
		dydt = (double *) PyArray_DATA(dydt_a);

		h = h_in;
		flag = gsl_odeiv2_control_hadjust(self->control, s, y, yerr, dydt, &h);

		flag_o = PyLong_FromLong((long) flag);
		if(flag_o == NULL){
			goto fail;
		}

		h_o = PyFloat_FromDouble(h);
		if(h_o == NULL){
			goto fail;
		}

		returnobj = PyTuple_New(2);
		if (returnobj == NULL){
			goto fail;
		}
		PyTuple_SetItem(returnobj, 0, (PyObject *) flag_o);
		PyTuple_SetItem(returnobj, 1, (PyObject *) h_o);

		Py_DECREF(y_a);
		Py_DECREF(yerr_a);
		Py_DECREF(dydt_a);
		return  returnobj;

	  fail:
		Py_XDECREF(returnobj);
		Py_XDECREF(y_a);
		Py_XDECREF(yerr_a);
		Py_XDECREF(dydt_a);
		Py_XDECREF(h_o);
		Py_XDECREF(flag_o);
		return NULL;
	}

	gsl_error_flag_drop errlevel(const double y, const double dydt, const double h, const size_t ind, double * errlev){
		return gsl_odeiv2_control_errlevel(self->control, y, dydt, h, ind, errlev);
	}

}

typedef struct{
	%immutable;
} pygsl_odeiv2_evolve;

%extend pygsl_odeiv2_evolve{
	pygsl_odeiv2_evolve(size_t dim){
		return gsl_odeiv2_evolve_alloc(dim);
	}

	~pygsl_odeiv2_evolve(void){
		gsl_odeiv2_evolve_free(self);
	}

	gsl_error_flag_drop reset(void){
		return gsl_odeiv2_evolve_reset(self);
	}
	PyObject * get_yerr(void){
		const gsl_vector_view v = gsl_vector_view_array(self->yerr, self->dimension);
		return (PyObject *) PyGSL_copy_gslvector_to_pyarray(&v.vector);
	}

	PyObject *
	apply(pygsl_odeiv2_control * con,
	      pygsl_odeiv2_step * step,
	      const pygsl_odeiv2_system * sys, const double t_in,
	      const double t1, const double h_in, PyObject * y_in_o)
	{
		PyObject *t_out_o = NULL, *h_out_o = NULL, *s_o=NULL,  *returnobj = NULL;
		PyArrayObject *y_in_a = NULL, *y_out_a = NULL;
		double t, h, *y=NULL;
		int status, line = __LINE__;
		PyGSL_array_index_t dim;

		if(con == NULL){
			pygsl_error("control object not set?", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}
		if(step == NULL){
			pygsl_error("step object not set?", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}
		if(sys == NULL){
			pygsl_error("sys object not set?", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}

		status = _pygsl_odeiv2_check_step_jacobian(step, &sys->dydt);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}

		dim = self->dimension;
		if(sys->dydt.dimension != dim){
			pygsl_error("sys dimension does not match evolve dimension", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}
		y_in_a = PyGSL_vector_check(y_in_o, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
		if(y_in_a == NULL){
			line = __LINE__ - 2; goto fail;
		}

		y_out_a = PyGSL_Copy_Array(y_in_a);
		if(y_out_a == NULL){
			line = __LINE__ - 2; goto fail;
		}
		Py_DECREF(y_in_a);
		y_in_a = NULL;

		y =  (double *) PyArray_DATA(y_out_a);
		if(y == NULL){
			line = __LINE__ - 2; goto fail;
		}

		h = h_in;
		t = t_in;

		status = gsl_odeiv2_evolve_apply(self, con->control, step, &sys->dydt, &t, t1, &h, y);

		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}
		s_o = PyLong_FromLong((long) status);
		if(s_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		t_out_o = PyFloat_FromDouble(t);
		if(t_out_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		h_out_o = PyFloat_FromDouble(h);
		if(h_out_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		returnobj = PyTuple_New(4);
		if (returnobj == NULL){
			line = __LINE__ - 2; goto fail;
		}
		PyTuple_SetItem(returnobj, 0, (PyObject *) s_o);
		PyTuple_SetItem(returnobj, 1, (PyObject *) t_out_o);
		PyTuple_SetItem(returnobj, 2, (PyObject *) h_out_o);
		PyTuple_SetItem(returnobj, 3, (PyObject *) y_out_a);
		return  returnobj;

	  fail:
		PyGSL_add_traceback(NULL, __FILE__,  __FUNCTION__, line);
		Py_XDECREF(y_out_a);
		Py_XDECREF(y_in_a);
		Py_XDECREF(returnobj);
		Py_XDECREF(t_out_o);
		Py_XDECREF(h_out_o);
		return NULL;
	}

	PyObject *
	apply_fixed_step(pygsl_odeiv2_control * con,
			 pygsl_odeiv2_step * step, const pygsl_odeiv2_system * sys,
			 const double t_in, const double h0,
			 PyObject * y_in_o){

		PyObject *t_out_o = NULL, *returnobj = NULL, *s_o = NULL;
		PyArrayObject *y_in_a = NULL, *y_out_a = NULL;
		double t, *y=NULL;
		int status, line = __LINE__;
		PyGSL_array_index_t dim;

		dim = self->dimension;
		if(con == NULL){
			pygsl_error("control object not set?", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}
		if(step == NULL){
			pygsl_error("step object not set?", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}
		if(sys == NULL){
			pygsl_error("sys object not set?", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}
		if(sys->dydt.dimension != dim){
			pygsl_error("sys dimension does not match evolve dimension", __FILE__, __LINE__, GSL_EINVAL);
			line = __LINE__ - 2; goto fail;
		}

		status = _pygsl_odeiv2_check_step_jacobian(step, &sys->dydt);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}

		y_in_a = PyGSL_vector_check(y_in_o, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
		if(y_in_a == NULL){
			line = __LINE__ - 2; goto fail;
		}

		y_out_a = PyGSL_Copy_Array(y_in_a);
		if(y_out_a == NULL){
			line = __LINE__ - 2; goto fail;
		}
		Py_DECREF(y_in_a);
		y_in_a = NULL;

		y =  (double *) PyArray_DATA(y_out_a);
		if(y == NULL){
			line = __LINE__ - 2; goto fail;
		}

		t = t_in;
		status = gsl_odeiv2_evolve_apply_fixed_step(self, con->control, step, &sys->dydt, &t, h0, y);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}

		t_out_o = PyFloat_FromDouble(t);
		if(t_out_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		s_o = PyLong_FromLong((long) status);
		if(s_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		returnobj = PyTuple_New(3);
		if (returnobj == NULL){
			line = __LINE__ - 2; goto fail;
		}
		PyTuple_SetItem(returnobj, 0, (PyObject *) s_o);
		PyTuple_SetItem(returnobj, 1, (PyObject *) t_out_o);
		PyTuple_SetItem(returnobj, 2, (PyObject *) y_out_a);
		return  returnobj;

	  fail:
		PyGSL_add_traceback(NULL, __FILE__,  __FUNCTION__, line);
		Py_XDECREF(y_out_a);
		Py_XDECREF(y_in_a);
		Py_XDECREF(t_out_o);
		Py_XDECREF(returnobj);
		return NULL;

	}

}

typedef struct{
	%immutable;
} pygsl_odeiv2_driver;


/* make sure that you use a derived class, whose calling instance keeps a reference to sys ... */
%extend pygsl_odeiv2_driver{
	~pygsl_odeiv2_driver(void){
		DEBUG_MESS(2, "Freeing driver %p", (void *) self);
		Py_XDECREF(self->scale);
		Py_XDECREF(self->sys);
		gsl_odeiv2_driver_free(self->driver);
		PyMem_Free(self);
		self = NULL;
	}

	/* the different allocators can be easily given as derived classes */
	pygsl_odeiv2_driver(PyObject *sys_o,
			    const gsl_odeiv2_step_type *T,
			    const double hstart,
			    const double epsabs,
			    const double epsrel,
			    const double a_y,
			    const double a_dydt,
			    PyObject * scale_abs_o){

		pygsl_odeiv2_driver *d =NULL;
		double *scale_abs;
		PyArrayObject * scale_abs_a = NULL;
		PyGSL_array_index_t dim = 0;
		gsl_odeiv2_system * sys = NULL;
		int flag;

		FUNC_MESS_BEGIN();
		flag = SWIG_ConvertPtr(sys_o, (void **) &sys, SWIGTYPE_p_pygsl_odeiv2_system, 0 |  0 );
		if (!SWIG_IsOK(flag)) {
			DEBUG_MESS(2, "sys_o = %p", (void *) sys_o);
			PyErr_SetString(PyExc_TypeError, "Could not convert sys object to pointer");
			goto fail;
		}
		if(sys == NULL){
			DEBUG_MESS(2, "sys = %p", (void *) sys);
			pygsl_error("sys None/NULL not accepted", __FILE__, __LINE__ -1, GSL_EINVAL);
			goto fail;
		}
		if(T == NULL){
			DEBUG_MESS(2, "T = %p", (void *) T);
			pygsl_error("Type None/NULL not accepted", __FILE__, __LINE__ -1, GSL_EINVAL);
			goto fail;
		}

		dim = sys->dimension;
		d = (pygsl_odeiv2_driver *) PyMem_Malloc(sizeof(pygsl_odeiv2_driver));
		if(d == NULL){
			goto fail;
		}
		d->driver = NULL;
		d->scale = NULL;
		d->sys = NULL;
		d->dimension = dim;

		/*
		 *  make sure the sys object lives as long as a reference to
		 *  the sys memory is used
		 */
		d->sys = sys_o;
		Py_INCREF(d->sys);

		if(scale_abs_o == Py_None){
			d->driver = gsl_odeiv2_driver_alloc_standard_new(sys, T, hstart, epsabs, epsrel, a_y, a_dydt);
			if(d->driver == NULL){
				goto fail;
			}
			return d;
		}

		scale_abs_a = PyGSL_New_Array(1, &dim, NPY_DOUBLE);
		if(scale_abs_a == NULL){
			return NULL;
		}
		d->scale = scale_abs_a;
		scale_abs_a = NULL;
		scale_abs =  (double *) PyArray_DATA(d->scale);
		d->driver =  gsl_odeiv2_driver_alloc_scaled_new(sys, T, hstart, epsabs, epsrel, a_y, a_dydt, scale_abs);
		if(d->driver == NULL){
			goto fail;
		}
		return d;

	  fail:
		FUNC_MESS("Fail");
		if(d){
			Py_XDECREF(d->scale);
			Py_XDECREF(d->sys);
			PyMem_Free(d);
		}
		return NULL;
	}

	gsl_error_flag_drop set_hmin(const double h_min){
		return gsl_odeiv2_driver_set_hmin(self->driver, h_min);
	}

	gsl_error_flag_drop set_hmax(const double h_max){
		return gsl_odeiv2_driver_set_hmax(self->driver, h_max);
	}

	gsl_error_flag_drop set_nmax(const unsigned long int nmax){
		return gsl_odeiv2_driver_set_nmax(self->driver, nmax);
	}

	gsl_error_flag_drop reset(void){
		return gsl_odeiv2_driver_reset(self->driver);
	}

	gsl_error_flag_drop reset_hstart(const double hstart){
		return gsl_odeiv2_driver_reset_hstart(self->driver, hstart);
	}

	PyObject * apply_fixed_step(const double tin, const double h, const unsigned long int n, PyObject *y_o){
		PyObject *returnobj = NULL, *t_out_o = NULL;
		PyArrayObject *y_in_a = NULL, *y_out_a = NULL;
		double *y = NULL, t=0;
		PyGSL_array_index_t dim;
		int status, line = __LINE__;

		t = tin;
		dim = self->driver->sys->dimension;
		y_in_a = PyGSL_vector_check(y_o, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
		if(y_in_a == NULL){
			line = __LINE__ - 2; goto fail;
		}

		y_out_a = PyGSL_Copy_Array(y_in_a);
		if(y_out_a == NULL){
			line = __LINE__ - 2; goto fail;
		}
		Py_DECREF(y_in_a);
		y_in_a = NULL;

		y =  (double *) PyArray_DATA(y_out_a);
		if(y == NULL){
			line = __LINE__ - 2; goto fail;
		}

		status = _pygsl_odeiv2_check_step_jacobian(self->driver->s, self->driver->sys);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}


		status = gsl_odeiv2_driver_apply_fixed_step(self->driver, &t, h, n, y);
		DEBUG_MESS(2, "gsl_odeiv2_driver_apply_fixed_step failed with %d", status);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}
		returnobj = PyTuple_New(2);
		if (returnobj == NULL){
			line = __LINE__ - 2; goto fail;
		}
		t_out_o = PyFloat_FromDouble(t);
		if(t_out_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		PyTuple_SetItem(returnobj, 0, (PyObject *) t_out_o);
		PyTuple_SetItem(returnobj, 1, (PyObject *) y_out_a);
		return  returnobj;

	  fail:
		PyGSL_add_traceback(NULL, __FILE__,  __FUNCTION__, line);
		Py_XDECREF(y_out_a);
		Py_XDECREF(y_in_a);
		Py_XDECREF(returnobj);
		Py_XDECREF(t_out_o);
		return NULL;
	}

	PyObject * apply(const double tin, const double t1, PyObject *y_o){
		PyObject *returnobj = NULL, *t_out_o = NULL;
		PyArrayObject *y_in_a = NULL, *y_out_a = NULL;
		double *y = NULL, t=0;
		PyGSL_array_index_t dim;
		int status, line = __LINE__;

		t = tin;
		dim = self->driver->sys->dimension;

		status = _pygsl_odeiv2_check_step_jacobian(self->driver->s, self->driver->sys);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}


		y_in_a = PyGSL_vector_check(y_o, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
		if(y_in_a == NULL){
			line = __LINE__ - 2; goto fail;
		}

		y_out_a = PyGSL_Copy_Array(y_in_a);
		if(y_out_a == NULL){
			line = __LINE__ - 2; goto fail;
		}
		Py_DECREF(y_in_a);
		y_in_a = NULL;

		y =  (double *) PyArray_DATA(y_out_a);
		if(y == NULL){
			line = __LINE__ - 2; goto fail;
		}

		status = gsl_odeiv2_driver_apply(self->driver, &t, t1, y);
		DEBUG_MESS(2, "gsl_odeiv2_driver_apply returned status %d", status);
		if(GSL_SUCCESS != PyGSL_ERROR_FLAG(status)){
			line = __LINE__ - 2; goto fail;
		}
		t_out_o = PyFloat_FromDouble(t);
		if(t_out_o == NULL){
			line = __LINE__ - 2; goto fail;
		}
		returnobj = PyTuple_New(2);
		if (returnobj == NULL){
			line = __LINE__ - 2; goto fail;
		}
		PyTuple_SetItem(returnobj, 0, (PyObject *) t_out_o);
		PyTuple_SetItem(returnobj, 1, (PyObject *) y_out_a);
		return  returnobj;

	  fail:
		FUNC_MESS("fail");
		PyGSL_add_traceback(NULL, __FILE__,  __FUNCTION__, line);
		Py_XDECREF(y_out_a);
		Py_XDECREF(y_in_a);
		Py_XDECREF(t_out_o);
		Py_XDECREF(returnobj);
		return NULL;
	}
}
