/*
 * author: Achim Gaedke
 * created: January 2002
 * file: pygsl/src/multiminmodule.c
 * $Id$
 */
#include <setjmp.h>
#include <pygsl/transition.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <pygsl/function_helpers.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_multimin.h>
#include "multiminmodule_doc.h"
/* 
 * I have two different types to minimize and I am too lazy to implement the same
 * twice. Therefore I use unions and add a flag to the minimizer for the type
 */

union pygsl_multimin_minimizer_type{
     const gsl_multimin_fminimizer_type   *f; 
     const gsl_multimin_fdfminimizer_type *fdf; 
};

union pygsl_multimin_minimizer{
     gsl_multimin_fminimizer   *f; 
     gsl_multimin_fdfminimizer *fdf; 
};

union pygsl_multimin_func{
     gsl_multimin_function     *f; 
     gsl_multimin_function_fdf *fdf; 
};

struct pygsl_solver_types{
     const char * f_minimizer;
     const char * fdf_minimizer;
};
static struct pygsl_solver_types my_solvers = {"F-Minimizer", "Fdf-Minimizer"};

/* 
 *  type: 
 *	 == 0 -> f 
 *	 != 0 -> fdf
 */
typedef struct {
     PyObject_HEAD
     PyObject* py_f;
     PyObject* py_df;
     PyObject* py_fdf;
     PyObject* trailing_params;
     union pygsl_multimin_func      func;
     union pygsl_multimin_minimizer min;
     size_t n;
     const char *mytype;
     int isset; /* Used as a flag if the jmp_buf is set */
     jmp_buf buffer;
} PyGSL_multimin;

#define PyGSL_multimin_check(op)  ((op)->ob_type == &PyGSL_multimin_pytype)
#define PyGSL_multimin_isf(op)    ((op)->mytype  == my_solvers.f_minimizer)


static void
PyGSL_multimin_dealloc(PyGSL_multimin* self);
static PyObject*
PyGSL_multimin_getattr(PyGSL_multimin * obj, char *name);



PyTypeObject PyGSL_multimin_pytype = {
  PyObject_HEAD_INIT(NULL)	 /* fix up the type slot in initcrng */
  0,				 /* ob_size */
  "PyGSL_multimin",		 /* tp_name */
  sizeof(PyGSL_multimin),	 /* tp_basicsize */
  0,				 /* tp_itemsize */

  /* standard methods */
  (destructor)  PyGSL_multimin_dealloc, /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		 /* tp_print    "print x"     */
  (getattrfunc) PyGSL_multimin_getattr,/* tp_getattr  "x.attr"      */
  (setattrfunc) 0,		 /* tp_setattr  "x.attr=v"    */
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */

  /* type categories */
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/
  0,				/* tp_as_mapping  [key], len, ...*/

  /* more methods */
  (hashfunc)     0,		/* tp_hash    "dict[x]" */
  (ternaryfunc)  0,      /* tp_call    "x()"     */
  (reprfunc)     0,             /* tp_str     "str(x)"  */
  (getattrofunc) 0,		/* tp_getattro */
  (setattrofunc) 0,		/* tp_setattro */
  0,				/* tp_as_buffer */
  0L,				/* tp_flags */
  (char *) PyGSL_multimin_type_doc		/* tp_doc */
};


/* Reference to this module */
PyObject *module = NULL;
static const char filename[] = __FILE__;

/* The Callbacks */
double 
PyGSL_multimin_function_f(const gsl_vector* x, void* params) 
{
     double result;
     int flag;
     int i;

     FUNC_MESS_BEGIN();     
     PyGSL_multimin *min_o;     
     min_o = (PyGSL_multimin *) params;
     assert(PyGSL_multimin_check(min_o));     
     for(i = 0; i<x->size; i++){
	  DEBUG_MESS(2, "Got a x[%d] of %f", i, gsl_vector_get(x, i));
     }
     flag = PyGSL_function_wrap_On_O(x, min_o->py_f, min_o->trailing_params, &result,
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
     PyGSL_multimin *min_o;     
     min_o = (PyGSL_multimin *) params;

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(min_o));     
     for(i = 0; i<x->size; i++){
	  DEBUG_MESS(2, "Got a x[%d] of %f", i, gsl_vector_get(x, i));
     }
     flag = PyGSL_function_wrap_Op_On(x, df, min_o->py_df, min_o->trailing_params,
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
     PyGSL_multimin *min_o;     

     FUNC_MESS_BEGIN();
     min_o = (PyGSL_multimin *) params;
     assert(PyGSL_multimin_check(min_o));     
     for(i = 0; i<x->size; i++){
	  DEBUG_MESS(2, "Got a x[%d] of %f", i, gsl_vector_get(x, i));
     }
     flag = PyGSL_function_wrap_On_O(x, min_o->py_fdf, min_o->trailing_params, f,
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
PyGSL_multimin_set_f(PyGSL_multimin *self, PyObject *args, PyObject *kw) 
{

     PyObject* func = NULL, * params = NULL, * x = NULL, * steps = NULL;
     PyArrayObject * xa = NULL, * stepsa = NULL;
     int n=0, flag=GSL_EFAILED;
     int stride_recalc;
     gsl_vector_view gsl_x;
     gsl_vector_view gsl_steps;
     static const char *kwlist[] = {"f", "x0", "args", "steps", NULL};

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if (self->min.f == NULL) {
	  gsl_error("Got a NULL Pointer of min.f",  filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }

     assert(args);
     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if (0==PyArg_ParseTupleAndKeywords(args,kw,"OOOO", (char **) kwlist, &func,&x,&params,&steps))
	  return NULL;

     if(!PyCallable_Check(func)){
	  gsl_error("First argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	  return NULL;	  
     }
     n=self->n;
     xa  = PyGSL_PyArray_PREPARE_gsl_vector_view(x, PyArray_DOUBLE, 0, n, 4, NULL);
     if (xa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     if(PyGSL_STRIDE_RECALC(xa->strides[0],sizeof(double), &stride_recalc) != GSL_SUCCESS)
	  goto fail;

     gsl_x = gsl_vector_view_array_with_stride((double *)(xa->data), stride_recalc, xa->dimensions[0]);
     stepsa =  PyGSL_PyArray_PREPARE_gsl_vector_view(steps, PyArray_DOUBLE, 0, n, 5, NULL);
     if (stepsa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     if(PyGSL_STRIDE_RECALC(stepsa->strides[0],sizeof(double), &stride_recalc) != GSL_SUCCESS)
	  goto fail;

     gsl_steps = gsl_vector_view_array_with_stride((double *)(stepsa->data), stride_recalc, stepsa->dimensions[0]);

     if (self->func.f != NULL) {
	  /* free the previous function and params */
	  Py_XDECREF(self->trailing_params);
	  Py_XDECREF(self->py_f);
     } else {
	  /* allocate function space */
	  self->func.f=calloc(1, sizeof(gsl_multimin_function));
	  if (self->func.f==NULL) {
	       gsl_error("Could not allocate the object for the minimizer function", 
			 filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
     /* add new function  and parameters */
     self->trailing_params=params;
     Py_INCREF(params);
     self->py_f=func;
     Py_INCREF(func);
     
     /* initialize the function struct */
     self->func.f->n=n;
     self->func.f->f=PyGSL_multimin_function_f;
     self->func.f->params=(void*)self;
     
     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;
	  flag = gsl_multimin_fminimizer_set(self->min.f,self->func.f, &gsl_x.vector, &gsl_steps.vector);
	  if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       goto fail;
	  }
     } else {
	  goto fail;
     }
     Py_DECREF(xa);
     Py_DECREF(stepsa);

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
PyGSL_multimin_set_fdf(PyGSL_multimin *self, PyObject *args, PyObject *kw) 
{

     PyObject * f = NULL, * df = NULL, * fdf = NULL, * params = NULL,
	      * x = NULL;
     PyArrayObject * xa = NULL;
     int n=0, flag=GSL_EFAILED;
     int stride_recalc=-1;
     double step=0.01, tol=1e-4;
     gsl_vector_view gsl_x;
     static const char *kwlist[] = {"f", "df", "fdf",  "x0", "args", "step", "tol", NULL};

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if (self->min.fdf == NULL) {
	  gsl_error("Got a NULL Pointer of min.fdf", filename, __LINE__ - 3, GSL_EFAULT);
	       return NULL;
	  }	  

     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if (0==PyArg_ParseTupleAndKeywords(args, kw, "OOOO|Odd", (char **)kwlist, 
					&f, &df, &fdf, &x, &params, &step, &tol))
	  return NULL;

     n=self->n;
     xa  = PyGSL_PyArray_PREPARE_gsl_vector_view(x, PyArray_DOUBLE, 0, n, 4, NULL);
     if (xa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     if(params == NULL){
          /* Reference counter increased later, when the parameters are set */
	  params = Py_None; 
     }
     if(PyGSL_STRIDE_RECALC(xa->strides[0],sizeof(double), &stride_recalc) != GSL_SUCCESS)
	  goto fail;
     gsl_x = gsl_vector_view_array_with_stride((double *)(xa->data), stride_recalc, xa->dimensions[0]);

     if (self->func.fdf != NULL) {
	  /* free the previous function and params */
	  Py_XDECREF(self->trailing_params);
	  Py_XDECREF(self->py_f);
	  Py_XDECREF(self->py_df);
	  Py_XDECREF(self->py_fdf);
     } else {
	  /* allocate function space */
	  self->func.fdf=malloc(sizeof(gsl_multimin_function_fdf));
	  if (self->func.fdf==NULL) {
	       gsl_error("Could not allocate the object for the minimizer function", 
			 filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
     /* add new function  and parameters */
     self->trailing_params=params;     Py_INCREF(params);
     self->py_f=f;                     Py_INCREF(f);
     self->py_df=df;                   Py_INCREF(df);
     self->py_fdf=fdf;                 Py_INCREF(fdf);
     
     /* initialize the function struct */
     self->func.fdf->n=n;
     self->func.fdf->f  =PyGSL_multimin_function_f;
     self->func.fdf->df =PyGSL_multimin_function_df;  
     self->func.fdf->fdf=PyGSL_multimin_function_fdf;
     self->func.fdf->params=(void*)self;

     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;	  
	  flag = gsl_multimin_fdfminimizer_set(self->min.fdf,self->func.fdf, &gsl_x.vector, step, tol);
	  if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       goto fail;
	  }
     }else{
	  goto fail;
     }
     self->isset = 0;
     Py_DECREF(xa);

     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;

 fail:
     PyGSL_ERROR_FLAG(flag);
     self->isset = 0;
     Py_XDECREF(xa);
     return NULL;
     
}
/*
static PyObject* 
PyGSL_multimin_set(PyGSL_multimin *self, PyObject *args) 
{

     if(PyGSL_multimin_isf(self)){       
	  return PyGSL_multimin_set_f(self, args);
     }else {
	  return PyGSL_multimin_set_fdf(self, args);
     }  
}
*/
static PyObject* 
PyGSL_multimin_iterate(PyGSL_multimin *self, PyObject *args) 
{
     int result, flag;

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if ( self->min.f ==NULL || self->func.f ==NULL) {
	  gsl_error("Got a NULL Pointer of min.f", filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }

     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;	      
	  if(PyGSL_multimin_isf(self)){       
	       result = gsl_multimin_fminimizer_iterate(self->min.f);
	  } else {
	       result = gsl_multimin_fdfminimizer_iterate(self->min.fdf);
	  }
     } else {
	  PyGSL_ERROR_FLAG(flag);
	  self->isset = 0;
	  return NULL;
     }
     self->isset = 0;
     FUNC_MESS_END();
     return PyGSL_error_flag_to_pyint(result);
}


static PyObject* 
PyGSL_multimin_x(PyGSL_multimin *self, PyObject *args) 
{
     gsl_vector* result;
     
     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if (self->min.f==NULL || self->func.f==NULL) {
	  gsl_error("Got a NULL Pointer for min.f", filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }
     if(PyGSL_multimin_isf(self)){       
	  result=gsl_multimin_fminimizer_x(self->min.f);
     } else {
	  result=gsl_multimin_fdfminimizer_x(self->min.fdf);
     }
     if (result==NULL) {
	  gsl_error("How could that happen?",  filename, __LINE__ - 3, GSL_ESANITY);
	  return NULL;
     }
     FUNC_MESS_END();
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(result);
}

static PyObject* 
PyGSL_multimin_minimum(PyGSL_multimin *self, PyObject *args) 
{
     double min;

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if (self->min.f == NULL || self->func.f ==NULL) {
	  gsl_error("Got a NULL Pointer of min.f", filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }
     if(PyGSL_multimin_isf(self)){       
	  min = gsl_multimin_fminimizer_minimum(self->min.f);
     } else {
	  min = gsl_multimin_fdfminimizer_minimum(self->min.fdf);
     }
     FUNC_MESS_END();
     return PyFloat_FromDouble(min);
}

static PyObject* 
PyGSL_multimin_name(PyGSL_multimin *self, PyObject *args) 
{
     const char * name;
     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if(PyGSL_multimin_isf(self)){       
	  name = gsl_multimin_fminimizer_name(self->min.f);
     } else {
	  name = gsl_multimin_fdfminimizer_name(self->min.fdf);
     }
     FUNC_MESS_END();
     return PyGSL_string_from_string(name);
}

static PyObject* 
PyGSL_multimin_size(PyGSL_multimin *self, PyObject *args) 
{
     double size;
     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if ( self->min.f ==NULL || self->func.f ==NULL) {
	  PyErr_SetString(PyExc_RuntimeError,"no function specified!");
	  return NULL;
     }
     if(PyGSL_multimin_isf(self)){       
	  size = gsl_multimin_fminimizer_size(self->min.f);
     } else {
	  gsl_error("Can not calculate size for a FDF", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     }
     FUNC_MESS_END();
     return PyFloat_FromDouble(size);
}

static PyObject* 
PyGSL_multimin_test_size_method(PyGSL_multimin *self, PyObject *args) 
{
     int flag=GSL_EFAILED;
     double epsabs;

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if ( self->min.f ==NULL || self->func.f ==NULL) {
	  PyErr_SetString(PyExc_RuntimeError,"no function specified!");
	  return NULL;
     }

     if(PyGSL_multimin_isf(self)){
	  if (0==PyArg_ParseTuple(args,"d", &epsabs))
	       return NULL;            
	  flag = gsl_multimin_test_size(gsl_multimin_fminimizer_size(self->min.f), epsabs);
     } else {
	  gsl_error("Can not calculate size for a FDF", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     }

     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}

static PyObject* 
PyGSL_multimin_restart(PyGSL_multimin *self, PyObject *args) 
{
     int flag;

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if(PyGSL_multimin_isf(self)){       
	  gsl_error("Can not restart for a F type solver", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     }
     flag = gsl_multimin_fdfminimizer_restart(self->min.fdf);

     if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	  return NULL;
     }
     FUNC_MESS_END();
     Py_INCREF(Py_None);
     return Py_None;
}
static PyObject* 
PyGSL_multimin_vec_fdf(PyGSL_multimin *self, PyObject *args, 
		       gsl_vector *(*func)(gsl_multimin_fdfminimizer * s))
{
     gsl_vector *result;
     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if(PyGSL_multimin_isf(self)){       
	  gsl_error("Can not retrieve this information for a F type solver!", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     } else {
	  result=func(self->min.fdf);
     }
     FUNC_MESS_END();
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(result);
} 

static PyObject* 
PyGSL_multimin_istype(PyGSL_multimin *self, PyObject *args)
{
     static const char *f = "F-Minimizer",  *fdf = "Fdf-Minimizer";
     const char *p;

     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if(PyGSL_multimin_isf(self)){ 
	  p = f;
     } else {
	  p = fdf;
     }
     FUNC_MESS_END();
     return PyString_FromString(p);
}

static PyObject* 
PyGSL_multimin_dx(PyGSL_multimin *self, PyObject *args)
{
     return PyGSL_multimin_vec_fdf(self, args, gsl_multimin_fdfminimizer_dx);
}

static PyObject* 
PyGSL_multimin_gradient(PyGSL_multimin *self, PyObject *args)
{
     return PyGSL_multimin_vec_fdf(self, args, gsl_multimin_fdfminimizer_gradient);
}

static PyObject*
PyGSL_multimin_test_gradient_method(PyGSL_multimin * self, PyObject *args)
{

     double epsabs;
     int flag;
     FUNC_MESS_BEGIN();

     assert(PyGSL_multimin_check(self));     
     if (0==PyArg_ParseTuple(args,"d", &epsabs))
	  return NULL;     

     if(PyGSL_multimin_isf(self)){       
	  gsl_error("Can not retrieve this information for a F type solver!", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     }
     flag = gsl_multimin_test_gradient(gsl_multimin_fdfminimizer_gradient(self->min.fdf), epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}

#define PyGSL_MULTIMIN_COMMON_METHODS  \
  {"iterate",     (PyCFunction)PyGSL_multimin_iterate,METH_NOARGS,(char *)multimin_iterate_doc,}, \
  {"x",           (PyCFunction)PyGSL_multimin_x,      METH_NOARGS,(char *)multimin_x_doc,      }, \
  {"minimum",     (PyCFunction)PyGSL_multimin_minimum,METH_NOARGS,(char *)multimin_minimum_doc,}, \
  {"name",        (PyCFunction)PyGSL_multimin_name,   METH_NOARGS,(char *)multimin_name_doc,   }, \
  {"type",        (PyCFunction)PyGSL_multimin_istype, METH_NOARGS,(char *)multimin_istype_doc, },

static PyMethodDef PyGSL_multimin_fmethods[] = {
     PyGSL_MULTIMIN_COMMON_METHODS
     {"set",      (PyCFunction)PyGSL_multimin_set_f,           METH_VARARGS|METH_KEYWORDS, (char *)multimin_set_f_doc    },     
     {"size",     (PyCFunction)PyGSL_multimin_size,            METH_NOARGS,  (char *)multimin_size_doc     },
     {"test_size",(PyCFunction)PyGSL_multimin_test_size_method,METH_VARARGS, (char *)multimin_test_size_doc},
     {NULL, NULL, 0, NULL}           /* sentinel */
};

static PyMethodDef PyGSL_multimin_fdfmethods[] = {
     PyGSL_MULTIMIN_COMMON_METHODS
     {"set",      (PyCFunction)PyGSL_multimin_set_fdf,                 METH_VARARGS|METH_KEYWORDS, (char *)multimin_set_fdf_doc      },     
     {"restart",  (PyCFunction)PyGSL_multimin_restart,                 METH_NOARGS,  (char *)multimin_restart_doc      },     
     {"dx",       (PyCFunction)PyGSL_multimin_dx,                      METH_NOARGS,  (char *)multimin_dx_doc           },     
     {"gradient", (PyCFunction)PyGSL_multimin_gradient,                METH_NOARGS,  (char *)multimin_gradient_doc     },     
     {"test_gradient",(PyCFunction)PyGSL_multimin_test_gradient_method,METH_VARARGS, (char *)multimin_test_gradient_doc},     
     {NULL, NULL, 0, NULL}           /* sentinel */
};


static PyObject* 
PyGSL_multimin_init(PyObject *self, PyObject *args, 
		    union pygsl_multimin_minimizer_type type, int t) 
{

     PyGSL_multimin *min_o=NULL;
     size_t n;
     /* static const char functionname [] = __FUNCTION__; */

     FUNC_MESS_BEGIN();     
     min_o =  (PyGSL_multimin *) PyObject_NEW(PyGSL_multimin, &PyGSL_multimin_pytype);
     if(min_o == NULL){
	  return NULL;
     }

     if (0==PyArg_ParseTuple(args,"l", &n))
	  return NULL;


     if (n<=0) {
	  PyErr_SetString(PyExc_RuntimeError, "dimension must be >0");
	  return NULL;
     }
     min_o->n=n;
     min_o->min.f=NULL;
     min_o->min.fdf=NULL;
     min_o->func.f=NULL;
     min_o->func.fdf=NULL;
     min_o->py_f=NULL;
     min_o->py_df=NULL;
     min_o->py_fdf=NULL;
     min_o->trailing_params=NULL;
     min_o->mytype=NULL;

     if(t == 0){
	  min_o->min.f = gsl_multimin_fminimizer_alloc(type.f,n);
	  if (min_o->min.f == NULL) {
		gsl_error("Could not allocate the object for the minimizer", 
			  filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
	  min_o->mytype = my_solvers.f_minimizer;
	  assert(PyGSL_multimin_isf(min_o));
     } else {
	  min_o->min.fdf = gsl_multimin_fdfminimizer_alloc(type.fdf,n);
	  if (min_o->min.fdf == NULL) {
		gsl_error("Could not allocate the object for the fdfminimizer", 
			  filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
	  min_o->mytype = my_solvers.fdf_minimizer;
	  assert(!PyGSL_multimin_isf(min_o));
     }
     FUNC_MESS_END();
     return (PyObject *) min_o;
 fail:
     Py_XDECREF(min_o);
     return NULL;
}

#define AMINIMIZER(name)                                                      \
static PyObject* PyGSL_multimin_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     union pygsl_multimin_minimizer_type type;                                \
     FUNC_MESS_BEGIN();                                                       \
     type.f  = gsl_multimin_fminimizer_ ## name;                              \
     tmp = PyGSL_multimin_init(self, args, type, 0);                          \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, (char *) filename, __FUNCTION__, __LINE__);      \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}
#define AMINIMIZER_FDF(name)                                                  \
static PyObject* PyGSL_multimin_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     union pygsl_multimin_minimizer_type type;                                \
     FUNC_MESS_BEGIN();                                                       \
     type.fdf  = gsl_multimin_fdfminimizer_ ## name;                          \
     tmp = PyGSL_multimin_init(self, args,  type, 1);                         \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, (char *) filename, __FUNCTION__, __LINE__);      \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}

AMINIMIZER(nmsimplex)
AMINIMIZER_FDF(steepest_descent)
AMINIMIZER_FDF(vector_bfgs)
AMINIMIZER_FDF(conjugate_pr)
AMINIMIZER_FDF(conjugate_fr)



static void
PyGSL_multimin_dealloc(PyGSL_multimin *self)
{
     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if(PyGSL_multimin_isf(self)){
	  if (self->min.f  != NULL)   gsl_multimin_fminimizer_free(self->min.f);
	  if (self->func.f != NULL)  free(self->func.f); 
     }else{
	  if (self->min.fdf  != NULL)   gsl_multimin_fdfminimizer_free(self->min.fdf);
	  if (self->func.fdf != NULL)  free(self->func.fdf); 
     }

     Py_XDECREF(self->trailing_params);     
     Py_XDECREF(self->py_f);     
     Py_XDECREF(self->py_df);     
     Py_XDECREF(self->py_fdf);     
     PyMem_Free(self);
     FUNC_MESS_END();
}


static PyObject*
PyGSL_multimin_getattr(PyGSL_multimin *self, char *name)
{

     PyObject *tmp = NULL;


     FUNC_MESS_BEGIN();
     assert(PyGSL_multimin_check(self));     
     if(PyGSL_multimin_isf(self)){
	  tmp = Py_FindMethod(PyGSL_multimin_fmethods, (PyObject *) self, name);
     } else {
	  tmp = Py_FindMethod(PyGSL_multimin_fdfmethods, (PyObject *) self, name);
     }
     FUNC_MESS_END();
     return tmp;
}




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
     PyObject *g=NULL;
     PyArrayObject *ga=NULL;
     gsl_vector_view gradient;

     double epsabs;
     int flag = GSL_EFAILED, stride_recalc=-1;

     FUNC_MESS_BEGIN();
     if (0==PyArg_ParseTuple(args,"Od", &g, &epsabs))
	  return NULL;     

     ga  = PyGSL_PyArray_PREPARE_gsl_vector_view(g, PyArray_DOUBLE, 0, -1, 1, NULL);
     if (ga == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  return NULL;
     }
     if((PyGSL_STRIDE_RECALC(ga->strides[0],sizeof(double), &stride_recalc)) != GSL_SUCCESS){
	  Py_XDECREF(ga);
	  return NULL;
     }
     gradient = gsl_vector_view_array_with_stride((double *)(ga->data), stride_recalc, ga->dimensions[0]);

     flag = gsl_multimin_test_gradient(&gradient.vector, epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}




static PyMethodDef multiminMethods[] = {
     {"nmsimplex",        PyGSL_multimin_init_nmsimplex,        METH_VARARGS, (char *)nmsimplex_doc       },
     {"steepest_descent", PyGSL_multimin_init_steepest_descent, METH_VARARGS, (char *)steepest_descent_doc},
     {"vector_bfgs",      PyGSL_multimin_init_vector_bfgs,      METH_VARARGS, (char *)vector_bfgs_doc     },
     {"conjugate_pr",     PyGSL_multimin_init_conjugate_pr,     METH_VARARGS, (char *)conjugate_pr_doc    },
     {"conjugate_fr",     PyGSL_multimin_init_conjugate_fr,     METH_VARARGS, (char *)conjugate_fr_doc    },
     {"test_size",        PyGSL_multimin_test_size,             METH_VARARGS, (char *)test_size_doc       },
     {"test_gradient",    PyGSL_multimin_test_gradient,         METH_VARARGS, (char *)test_gradient_doc   },
     {NULL, NULL, 0, NULL}        /* Sentinel */
};



#ifdef PyGSL_PY3K
PyObject *PyInit_multimin(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) inimultimin(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
  PyObject* m, *dict, *item;
  m=Py_InitModule("multimin", multiminMethods);
  import_array();
  init_pygsl();
  /* init multimin type */
  PyGSL_multimin_pytype.ob_type  = &PyType_Type;


  module = m;

  Py_INCREF((PyObject*)&PyGSL_multimin_pytype);

  dict = PyModule_GetDict(m);
  if(!dict)
       goto fail;
  
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

  return RETVAL

 fail:
  return RETVAL;
}
