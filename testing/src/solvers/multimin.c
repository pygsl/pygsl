/*
 * author: Achim Gaedke
 * created: January 2002
 * file: pygsl/src/multiminmodule.c
 * $Id$
 */
#include <pygsl/solver.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_multimin.h>
#include "multiminmodule_doc.h"


const char  * filename = __FILE__;
PyObject *module = NULL;

/* 
 * I have two different types to minimize and I am too lazy to implement the same
 * twice. Therefore I use unions and add a flag to the minimizer for the type
 */

/* The Callbacks */
double 
PyGSL_multimin_function_f(const gsl_vector* x, void* params) 
{
     double result;
     int flag;
     int i;

     FUNC_MESS_BEGIN();     
     PyGSL_solver *min_o;     
     min_o = (PyGSL_solver *) params;
     assert(PyGSL_solver_check(min_o));     
     for(i = 0; i<x->size; i++){
	  DEBUG_MESS(2, "Got a x[%d] of %f", i, gsl_vector_get(x, i));
     }
     assert(min_o->mstatic->n_cbs >= 1);
     flag = PyGSL_function_wrap_On_O(x, min_o->cbs[0], min_o->args, &result,
				     NULL, x->size, __FUNCTION__);
     if (flag!= GSL_SUCCESS){
	  result = gsl_nan();
	  if(min_o->isset == 1) longjmp(min_o->buffer,flag);	  
     }  
     DEBUG_MESS(2, "Got a result of %f", result);
     FUNC_MESS_END();
     return result;
}

void 
PyGSL_multimin_function_df(const gsl_vector* x, void* params, gsl_vector *df)
{
     int flag, i;
     PyGSL_solver *min_o;     
     min_o = (PyGSL_solver *) params;

     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(min_o));     
     for(i = 0; i<x->size; i++){
	  DEBUG_MESS(2, "Got a x[%d] of %f", i, gsl_vector_get(x, i));
     }
     assert(min_o->mstatic->n_cbs >= 2);
     flag = PyGSL_function_wrap_Op_On(x, df, min_o->cbs[1], min_o->args,
				      x->size, x->size, __FUNCTION__);
     for(i = 0; i<df->size; i++){
	  DEBUG_MESS(2, "Got df x[%d] of %f", i, gsl_vector_get(df, i));
     }
     if(flag!=GSL_SUCCESS){
	  if(min_o->isset == 1) longjmp(min_o->buffer,flag);	  
     }
     FUNC_MESS_END();
} 

void 
PyGSL_multimin_function_fdf(const gsl_vector* x, void* params, double *f, gsl_vector *df)
{
     int flag, i;
     PyGSL_solver *min_o;     

     FUNC_MESS_BEGIN();
     min_o = (PyGSL_solver *) params;
     assert(PyGSL_solver_check(min_o));     
     for(i = 0; i<x->size; i++){
	  DEBUG_MESS(2, "Got a x[%d] of %f", i, gsl_vector_get(x, i));
     }
     assert(min_o->mstatic->n_cbs >= 3);
     flag = PyGSL_function_wrap_On_O(x, min_o->cbs[2], min_o->args, f,
				     df, x->size, __FUNCTION__);
     DEBUG_MESS(2, "Got a result of %f", *f);
     for(i = 0; i<df->size; i++){
	  DEBUG_MESS(2, "Got df x[%d] of %f", i, gsl_vector_get(df, i));
     }
     if (flag!= GSL_SUCCESS){
	  *f = gsl_nan();
	  if(min_o->isset == 1) longjmp(min_o->buffer,flag);  
     }  
     FUNC_MESS_END();
     return;
}


static PyObject* 
PyGSL_multimin_set_f(PyGSL_solver *self, PyObject *pyargs, PyObject *kw) 
{

     PyObject* func = NULL, * args = Py_None, * x = NULL, * steps = NULL;
     PyArrayObject * xa = NULL, * stepsa = NULL;
     int n=0, flag=GSL_EFAILED;
     PyGSL_array_index_t stride_recalc;
     gsl_vector_view gsl_x;
     gsl_vector_view gsl_steps;
     gsl_multimin_function * c_sys = NULL;
     static const char *kwlist[] = {"f", "x0", "args", "steps", NULL};

     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     if (self->solver == NULL) {
	  pygsl_error("Got a NULL Pointer of min.f",  filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }

     assert(pyargs);
     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if (0==PyArg_ParseTupleAndKeywords(pyargs,kw,"OOOO", (char **)kwlist, &func,
					&x,&args,&steps))
	  return NULL;

     if(!PyCallable_Check(func)){
	  pygsl_error("First argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	  return NULL;	  
     }
     n=self->problem_dimensions[0]; 
     xa  = PyGSL_vector_check(x, n, PyGSL_DARRAY_INPUT(4), &stride_recalc, NULL);
     if (xa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }

     gsl_x = gsl_vector_view_array_with_stride((double *)(PyArray_DATA(xa)), stride_recalc, PyArray_DIM(xa, 0));
     stepsa =  PyGSL_vector_check(steps, n, PyGSL_DARRAY_INPUT(5), &stride_recalc, NULL);
     if (stepsa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     gsl_steps = gsl_vector_view_array_with_stride((double *)(PyArray_DATA(stepsa)), stride_recalc, PyArray_DIM(stepsa, 0));

     if (self->c_sys != NULL) {
	  /* free the previous function and args */
	  c_sys = self->c_sys;
     } else {
	  /* allocate function space */
       c_sys=(gsl_multimin_function *)calloc(1, sizeof(gsl_multimin_function));
	  if (c_sys == NULL) {
	       pygsl_error("Could not allocate the object for the minimizer function", 
			 filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
     DEBUG_MESS(3, "Everything allocated args = %p", args);
     /* add new function  and parameters */

     if(PyGSL_solver_func_set(self, args, func, NULL, NULL) != GSL_SUCCESS)
	  goto fail;
     
     /* initialize the function struct */
     c_sys->n=n;
     c_sys->f=PyGSL_multimin_function_f;
     c_sys->params=(void*)self;
     
     DEBUG_MESS(3, "Setting jmp buffer isset = % d", self->isset);
     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;
	  flag = gsl_multimin_fminimizer_set(self->solver,c_sys, &gsl_x.vector, &gsl_steps.vector);
	  if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       goto fail;
	  }
     } else {
	  goto fail;
     }
     DEBUG_MESS(4, "Set evaluated. flag = %d", flag);
     self->c_sys = c_sys;
     Py_DECREF(xa);
     Py_DECREF(stepsa);
     self->set_called = 1;

     Py_INCREF(Py_None);
     self->isset = 0;
     FUNC_MESS_END();
     return Py_None;

     
 fail:
     FUNC_MESS("Fail");
     PyGSL_ERROR_FLAG(flag);
     self->isset = 0;
     Py_XDECREF(xa);
     Py_XDECREF(stepsa);
     return NULL;
     
}

static PyObject* 
PyGSL_multimin_set_fdf(PyGSL_solver *self, PyObject *pyargs, PyObject *kw) 
{

     PyObject * f = NULL, * df = NULL, * fdf = NULL, * args = Py_None,
	      * x = NULL;
     PyArrayObject * xa = NULL;
     int n=0, flag=GSL_EFAILED;
     PyGSL_array_index_t stride_recalc=-1;
     double step=0.01, tol=1e-4;
     gsl_vector_view gsl_x;
     gsl_multimin_function_fdf * c_sys;
     static const char *kwlist[] = {"f", "df", "fdf",  "x0", "args", "step", "tol", NULL};

     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     if (self->solver == NULL) {
	  pygsl_error("Got a NULL Pointer of min.fdf", filename, __LINE__ - 3, GSL_EFAULT);
	       return NULL;
	  }	  

     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if (0==PyArg_ParseTupleAndKeywords(pyargs, kw, "OOOO|Odd", (char **)kwlist, 
					&f, &df, &fdf, &x, &args, &step, &tol))
	  return NULL;

     n=self->problem_dimensions[0];
     xa  = PyGSL_vector_check(x, n, PyGSL_DARRAY_INPUT(4), &stride_recalc, NULL);
     if (xa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     gsl_x = gsl_vector_view_array_with_stride((double *)(PyArray_DATA(xa)), stride_recalc, PyArray_DIM(xa, 0));


     if (self->c_sys != NULL) {
	  /* free the previous function and args */
	  c_sys = self->c_sys;
     } else {
	  /* allocate function space */
	  c_sys=malloc(sizeof(gsl_multimin_function_fdf));
	  if (c_sys==NULL) {
	       pygsl_error("Could not allocate the object for the minimizer function", 
			 filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
     if(PyGSL_solver_func_set(self, args, f, df, fdf) != GSL_SUCCESS)
	  goto fail;
     
     /* initialize the function struct */
     c_sys->n=n;
     c_sys->f  =PyGSL_multimin_function_f;
     c_sys->df =PyGSL_multimin_function_df;  
     c_sys->fdf=PyGSL_multimin_function_fdf;
     c_sys->params=(void*)self;

     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;	  
	  flag = gsl_multimin_fdfminimizer_set(self->solver, c_sys, &gsl_x.vector, step, tol);
	  if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       goto fail;
	  }
     }else{
	  goto fail;
     }
     self->c_sys = c_sys;
     self->isset = 0;
     Py_DECREF(xa);
     self->set_called = 1;

     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;

 fail:
     PyGSL_ERROR_FLAG(flag);
     self->isset = 0;
     Py_XDECREF(xa);
     return NULL;
     
}

static PyObject* 
PyGSL_multimin_dx(PyGSL_solver *self, PyObject *args)
{
     return PyGSL_solver_ret_vec(self, args, (ret_vec)gsl_multimin_fdfminimizer_dx);
}

static PyObject* 
PyGSL_multimin_gradient(PyGSL_solver *self, PyObject *args)
{
     return PyGSL_solver_ret_vec(self, args, (ret_vec)gsl_multimin_fdfminimizer_gradient);
}

static PyObject* 
PyGSL_multimin_f_x(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_vec(self, args, (ret_vec)gsl_multimin_fminimizer_x);
}

static PyObject* 
PyGSL_multimin_fdf_x(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_vec(self, args, (ret_vec)gsl_multimin_fdfminimizer_x);
}

static PyObject* 
PyGSL_multimin_f_minimum(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_multimin_fminimizer_minimum);
}

static PyObject* 
PyGSL_multimin_fdf_minimum(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_multimin_fdfminimizer_minimum);
}


static PyObject* 
PyGSL_multimin_f_size(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_multimin_fminimizer_size);
}

static PyObject* 
PyGSL_multimin_test_size_method(PyGSL_solver *self, PyObject *args) 
{
     int flag=GSL_EFAILED;
     double epsabs;

     FUNC_MESS_BEGIN();

     if (0==PyArg_ParseTuple(args,"d", &epsabs))
	  return NULL;            
     flag = gsl_multimin_test_size(gsl_multimin_fminimizer_size(self->solver), epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}


static PyObject*
PyGSL_multimin_test_gradient_method(PyGSL_solver * self, PyObject *args)
{

     double epsabs;
     int flag;
     FUNC_MESS_BEGIN();

     assert(PyGSL_solver_check(self));     
     if (0==PyArg_ParseTuple(args,"d", &epsabs))
	  return NULL;     

     flag = gsl_multimin_test_gradient(gsl_multimin_fdfminimizer_gradient(self->solver), epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}



static PyMethodDef PyGSL_multimin_fmethods[] = {     
     {"x",           (PyCFunction)PyGSL_multimin_f_x,      METH_NOARGS,(char *)multimin_x_doc,      }, 
     {"minimum",     (PyCFunction)PyGSL_multimin_f_minimum,METH_NOARGS,(char *)multimin_minimum_doc,}, 
     {"set",      (PyCFunction)PyGSL_multimin_set_f,           METH_VARARGS|METH_KEYWORDS, (char *)multimin_set_f_doc    },     
     {"size",     (PyCFunction)PyGSL_multimin_f_size,            METH_NOARGS,  (char *)multimin_size_doc     },
     {"test_size",(PyCFunction)PyGSL_multimin_test_size_method,METH_VARARGS, (char *)multimin_test_size_doc},
     {NULL, NULL, 0, NULL}           /* sentinel */
};

static PyMethodDef PyGSL_multimin_fdfmethods[] = {
     {"x",           (PyCFunction)PyGSL_multimin_fdf_x,      METH_NOARGS,(char *)multimin_x_doc,      }, 
     {"minimum",     (PyCFunction)PyGSL_multimin_fdf_minimum,METH_NOARGS,(char *)multimin_minimum_doc,}, 
     {"set",      (PyCFunction)PyGSL_multimin_set_fdf,                 METH_VARARGS|METH_KEYWORDS, (char *)multimin_set_fdf_doc      },
     {"dx",       (PyCFunction)PyGSL_multimin_dx,                      METH_NOARGS,  (char *)multimin_dx_doc           },     
     {"gradient", (PyCFunction)PyGSL_multimin_gradient,                METH_NOARGS,  (char *)multimin_gradient_doc     },     
     {"test_gradient",(PyCFunction)PyGSL_multimin_test_gradient_method,METH_VARARGS, (char *)multimin_test_gradient_doc},     
     {NULL, NULL, 0, NULL}           /* sentinel */
};

const struct _GSLMethods 
multimin_f   = { (void_m_t) gsl_multimin_fminimizer_free,   
		/* gsl_multimin_fminimizer_restart */  (void_m_t) NULL,
		  (name_m_t) gsl_multimin_fminimizer_name,   
		 (int_m_t) gsl_multimin_fminimizer_iterate};

const struct _GSLMethods
multimin_fdf = {(void_m_t) gsl_multimin_fdfminimizer_free, 
		(void_m_t) gsl_multimin_fdfminimizer_restart,
		(name_m_t) gsl_multimin_fdfminimizer_name, 
		(int_m_t)  gsl_multimin_fdfminimizer_iterate};

static const char multimin_f_type_name[] = "F-MultiMinimizer";
static const char multimin_fdf_type_name[] = "FdF-MultiMinimizer";

const struct _SolverStatic 
multimin_solver_f   = {{(void_m_t) gsl_multimin_fminimizer_free,   
			(void_m_t) NULL,
			(name_m_t) gsl_multimin_fminimizer_name,   
			(int_m_t) gsl_multimin_fminimizer_iterate}, 
		       1, PyGSL_multimin_fmethods, multimin_f_type_name},
multimin_solver_fdf = {{(void_m_t) gsl_multimin_fdfminimizer_free, 
			(void_m_t) gsl_multimin_fdfminimizer_restart,
			(name_m_t) gsl_multimin_fdfminimizer_name, 
			(int_m_t)  gsl_multimin_fdfminimizer_iterate},
		       3, PyGSL_multimin_fdfmethods, multimin_fdf_type_name};

static PyObject* 
PyGSL_multimin_f_init(PyObject *self, PyObject *args, 
		      const gsl_multimin_fminimizer_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_multimin_fminimizer_alloc,
			      &multimin_solver_f};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 1);
     FUNC_MESS_END();     
     return tmp;
}

static PyObject* 
PyGSL_multimin_fdf_init(PyObject *self, PyObject *args, 
		      const gsl_multimin_fdfminimizer_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_multimin_fdfminimizer_alloc,
			      &multimin_solver_fdf};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 1);
     FUNC_MESS_END();     
     return tmp;
}


#define AMINIMIZER_F(name)                                                  \
static PyObject* PyGSL_multimin_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_multimin_f_init(self, args,  gsl_multimin_fminimizer_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}

#define AMINIMIZER_FDF(name)                                                  \
static PyObject* PyGSL_multimin_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_multimin_fdf_init(self, args,  gsl_multimin_fdfminimizer_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}

AMINIMIZER_F(nmsimplex)
AMINIMIZER_FDF(steepest_descent)
AMINIMIZER_FDF(vector_bfgs)
AMINIMIZER_FDF(conjugate_pr)
AMINIMIZER_FDF(conjugate_fr)

static PyObject*
PyGSL_multimin_test_size(PyObject * self, PyObject *args)
{
     double size, epsabs;
     int flag = GSL_EFAILED;
     FUNC_MESS_BEGIN();
     if (0==PyArg_ParseTuple(args,"dd", &size, &epsabs))
	  return NULL;     
     flag = gsl_multimin_test_size(size, epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}

static PyObject*
PyGSL_multimin_test_gradient(PyObject * self, PyObject *args)
{
     return PyGSL_solver_vd_i (self, args, gsl_multimin_test_gradient);     
}


static PyMethodDef mMethods[] = {
     /* solvers */
     {"nmsimplex",        PyGSL_multimin_init_nmsimplex,        METH_VARARGS, (char *)nmsimplex_doc       },
     {"steepest_descent", PyGSL_multimin_init_steepest_descent, METH_VARARGS, (char *)steepest_descent_doc},
     {"vector_bfgs",      PyGSL_multimin_init_vector_bfgs,      METH_VARARGS, (char *)vector_bfgs_doc     },
     {"conjugate_pr",     PyGSL_multimin_init_conjugate_pr,     METH_VARARGS, (char *)conjugate_pr_doc    },
     {"conjugate_fr",     PyGSL_multimin_init_conjugate_fr,     METH_VARARGS, (char *)conjugate_fr_doc    },
     /* multimin funcs */
     {"test_size",        PyGSL_multimin_test_size,             METH_VARARGS, (char *)test_size_doc       },
     {"test_gradient",    PyGSL_multimin_test_gradient,         METH_VARARGS, (char *)test_gradient_doc   },
     {NULL, NULL, 0, NULL}
};

#ifdef __cplusplus
extern "C"
#endif


void
initmultimin(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("multimin", mMethods);
     module = m;
     assert(m);
     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     init_pygsl()
     import_pygsl_solver();
     assert(PyGSL_API);


     if (!(item = PyGSL_string_from_string((char*)PyGSL_multimin_module_doc))){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not generate module doc string!");
	  goto fail;
     }
     if (PyDict_SetItemString(dict, "__doc__", item) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not init doc string!");
	  goto fail;
     }
     
     FUNC_MESS_END();

 fail:
     FUNC_MESS("FAIL");
     return;
}
