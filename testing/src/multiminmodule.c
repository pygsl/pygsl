/*
 * author: Achim Gaedke
 * created: January 2002
 * file: pygsl/src/multiminmodule.c
 * $Id$
 */
#include <setjmp.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <pygsl/function_helpers.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_multimin.h>

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
     int mytype;
     int isset;
     jmp_buf buffer;
} PyGSL_multimin;

#define PyGSL_multimin_check(op)  ((op)->ob_type == &PyGSL_multimin_pytype)
#define PyGSL_multimin_isf(op)    ((op)->mytype  == 0)

static void
PyGSL_multimin_dealloc(PyGSL_multimin* self);
static PyObject*
PyGSL_multimin_getattr(PyObject * obj, char *name);

static const char PyGSL_multimin_type_doc[] = "XXX Type doc missing!";

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
  (char *)PyGSL_multimin_type_doc		/* tp_doc */
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
     
     PyGSL_multimin *min_o;     
     min_o = (PyGSL_multimin *) params;
     
     flag = PyGSL_function_wrap_On_O(x, min_o->py_f, min_o->trailing_params, &result,
				     NULL, x->size, __FUNCTION__);
     if (flag!= GSL_SUCCESS){
	  result = gsl_nan();
	  if(min_o->isset == 1) longjmp(min_o->buffer,flag);	  
     }  
     return result;
}

void 
PyGSL_multimin_function_df(const gsl_vector* x, void* params, gsl_vector *df)
{
     int flag;
     PyGSL_multimin *min_o;     
     min_o = (PyGSL_multimin *) params;
     flag = PyGSL_function_wrap_Op_On(x, df, min_o->py_f, min_o->trailing_params,
				      x->size, df->size, __FUNCTION__);
     if(flag!=GSL_SUCCESS){
	  if(min_o->isset == 1) longjmp(min_o->buffer,flag);	  
     }
} 
void 
PyGSL_multimin_function_fdf(const gsl_vector* x, void* params, double *f, gsl_vector *df)
{
     int flag;
     PyGSL_multimin *min_o;     
     min_o = (PyGSL_multimin *) params;
     flag = PyGSL_function_wrap_On_O(x, min_o->py_f, min_o->trailing_params, f,
				     df, x->size, __FUNCTION__);
     if (flag!= GSL_SUCCESS){
	  *f = gsl_nan();
	  if(min_o->isset == 1) longjmp(min_o->buffer,flag);  
     }  
     return;
}

static PyObject* 
PyGSL_multimin_set_f(PyGSL_multimin *self, PyObject *args) 
{

     PyObject* func = NULL, * params = NULL, * x = NULL, * steps = NULL;
     PyArrayObject * xa = NULL, * stepsa = NULL;
     int n=0, flag=GSL_EFAILED;
     int stride_recalc;
     gsl_vector_view gsl_x;
     gsl_vector_view gsl_steps;


     if (self->min.f == NULL) {
	  gsl_error("Got a NULL Pointer of min.f",  filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }
     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if (0==PyArg_ParseTuple(args,"O!OOO", &PyFunction_Type,&func,&params,&x,&steps))
	  return NULL;
     n=self->n;
     xa  = PyGSL_PyArray_PREPARE_gsl_vector_view(x, PyArray_DOUBLE, 0, n, 4, NULL);
     if (xa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     stride_recalc = xa->strides[0] / sizeof(double);
     gsl_x = gsl_vector_view_array_with_stride((double *)(xa->data), stride_recalc, xa->dimensions[0]);
     stepsa =  PyGSL_PyArray_PREPARE_gsl_vector_view(steps, PyArray_DOUBLE, 0, n, 5, NULL);
     if (stepsa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     stride_recalc = stepsa->strides[0] / sizeof(double);
     gsl_steps = gsl_vector_view_array_with_stride((double *)(stepsa->data), stride_recalc, stepsa->dimensions[0]);

     if (self->func.f != NULL) {
	  /* free the previous function and params */
	  Py_XDECREF(self->trailing_params);
	  Py_XDECREF(self->py_f);
     } else {
	  /* allocate function space */
	  self->func.f=malloc(sizeof(gsl_multimin_function));
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
     return Py_None;

     
 fail:
     PyGSL_ERROR_FLAG(flag);
     self->isset = 0;
     Py_XDECREF(xa);
     Py_XDECREF(stepsa);
     return NULL;
     
}
static PyObject* 
PyGSL_multimin_set_fdf(PyGSL_multimin *self, PyObject *args) 
{

     PyObject * f = NULL, * df = NULL, * fdf = NULL, * params = NULL,
	      * x = NULL;
     PyArrayObject * xa = NULL;
     int n=0, flag=GSL_EFAILED;
     int stride_recalc=-1;
     double step, tol;
     gsl_vector_view gsl_x;

     if (self->min.fdf == NULL) {
	  gsl_error("Got a NULL Pointer of min.fdf", filename, __LINE__ - 3, GSL_EFAULT);
	       return NULL;
	  }	  

     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if (0==PyArg_ParseTuple(args,"OOOOOdd", &f, &df, &fdf, &params, &x, &step, &tol))
	  return NULL;

     n=self->n;
     xa  = PyGSL_PyArray_PREPARE_gsl_vector_view(x, PyArray_DOUBLE, 0, n, 4, NULL);
     if (xa == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  goto fail;
     }
     stride_recalc = xa->strides[0] / sizeof(double);
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
     self->func.fdf->df =PyGSL_multimin_function_df;  /* XXX Missing !!! */
     self->func.fdf->fdf=PyGSL_multimin_function_fdf;/* XXX Missing !!! */
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

     return PyGSL_error_flag_to_pyint(result);
}


static PyObject* 
PyGSL_multimin_x(PyGSL_multimin *self, PyObject *args) 
{
     gsl_vector* result;
     
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
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(result);
}

static PyObject* 
PyGSL_multimin_minimum(PyGSL_multimin *self, PyObject *args) 
{
     double min;
     if (self->min.f == NULL || self->func.f ==NULL) {
	  gsl_error("Got a NULL Pointer of min.f", filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }
     if(PyGSL_multimin_isf(self)){       
	  min = gsl_multimin_fminimizer_minimum(self->min.f);
     } else {
	  min = gsl_multimin_fdfminimizer_minimum(self->min.fdf);
     }
     return PyFloat_FromDouble(min);
}

static PyObject* 
PyGSL_multimin_name(PyGSL_multimin *self, PyObject *args) 
{
     const char * name;
     if(PyGSL_multimin_isf(self)){       
	  name = gsl_multimin_fminimizer_name(self->min.f);
     } else {
	  name = gsl_multimin_fdfminimizer_name(self->min.fdf);
     }
     return PyString_FromString(name);
}

static PyObject* 
PyGSL_multimin_size(PyGSL_multimin *self, PyObject *args) 
{
     double size;
     PyGSL_multimin *min_o = NULL;
     min_o = (PyGSL_multimin *)self;
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
     return PyFloat_FromDouble(size);
}
static PyObject* 
PyGSL_multimin_restart(PyGSL_multimin *self, PyObject *args) 
{
     int flag;

     if(PyGSL_multimin_isf(self)){       
	  gsl_error("Can not restart for a F type solver", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     }
     flag = gsl_multimin_fdfminimizer_restart(self->min.fdf);
     
     if(PyGSL_ERROR_FLAG(flag) == GSL_SUCCESS){
	  Py_INCREF(Py_None);
	  return Py_None;
     }
     return NULL;

}
static PyObject* 
PyGSL_multimin_vec_fdf(PyGSL_multimin *self, PyObject *args, 
		       gsl_vector *(*func)(gsl_multimin_fdfminimizer * s))
{
     gsl_vector *result;
     if(PyGSL_multimin_isf(self)){       
	  gsl_error("Can not retrieve this information for a F type solver!", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     } else {
	  result=func(self->min.fdf);
     }
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(result);
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

     if (0==PyArg_ParseTuple(args,"d", &epsabs))
	  return NULL;     

     if(PyGSL_multimin_isf(self)){       
	  gsl_error("Can not retrieve this information for a F type solver!", filename, __LINE__, GSL_ESANITY);
	  return NULL;
     }
     flag = gsl_multimin_test_gradient(gsl_multimin_fdfminimizer_gradient(self->min.fdf), epsabs);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}

#define PyGSL_MULTIMIN_COMMON_METHODS  \
  {"x",(PyCFunction)PyGSL_multimin_x,METH_NOARGS,"estimated position of the minimum"},           \
  {"minimum",(PyCFunction)PyGSL_multimin_minimum,METH_NOARGS,"estimated value of the minimum"},  \
  {"name",(PyCFunction)PyGSL_multimin_name,METH_NOARGS,"Returns the name of the minimizer"},  \
  {"iterate",(PyCFunction)PyGSL_multimin_iterate,METH_NOARGS,"makes next step"},

static PyMethodDef PyGSL_multimin_fmethods[] = {
     PyGSL_MULTIMIN_COMMON_METHODS
     {"set",(PyCFunction)PyGSL_multimin_set_f,METH_VARARGS,"sets a function and start values"},     
     {"size",(PyCFunction)PyGSL_multimin_size,METH_NOARGS,"size of the minimizer"},
     {NULL, NULL, 0, NULL}           /* sentinel */
};

static PyMethodDef PyGSL_multimin_fdfmethods[] = {
     PyGSL_MULTIMIN_COMMON_METHODS
     {"set",(PyCFunction)PyGSL_multimin_set_fdf,METH_VARARGS,"sets a function and start values"},     
     {"restart",(PyCFunction)PyGSL_multimin_restart,METH_NOARGS,"restart the solver"},     
     {"dx",(PyCFunction)PyGSL_multimin_dx,METH_NOARGS,"get dx"},     
     {"gradient",(PyCFunction)PyGSL_multimin_gradient,METH_NOARGS,"get the gradient"},     
     {"test_gradient",(PyCFunction)PyGSL_multimin_test_gradient_method,METH_VARARGS,"test if the gradient is inside"},     
     {NULL, NULL, 0, NULL}           /* sentinel */
};

static PyObject* 
PyGSL_multimin_init(PyObject *self, PyObject *args, 
		    union pygsl_multimin_minimizer_type type, int t) 
{

     PyGSL_multimin *min_o=NULL;
     size_t n;
     /* static const char functionname [] = __FUNCTION__; */
     
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
  
     if(t == 0){
	  min_o->min.f = gsl_multimin_fminimizer_alloc(type.f,n);
	  if (min_o->min.f == NULL) {
		gsl_error("Could not allocate the object for the minimizer", 
			  filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     } else {
	  min_o->min.fdf = gsl_multimin_fdfminimizer_alloc(type.fdf,n);
	  if (min_o->min.fdf == NULL) {
		gsl_error("Could not allocate the object for the fdfminimizer", 
			  filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
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
}


static PyObject*
PyGSL_multimin_getattr(PyObject *self, char *name)
{

     PyGSL_multimin* s= (PyGSL_multimin *) self; 
     if(PyGSL_multimin_isf(s)){
	  return Py_FindMethod(PyGSL_multimin_fmethods, (PyObject *) s, name);
     } else {
	  return Py_FindMethod(PyGSL_multimin_fdfmethods, (PyObject *) s, name);
     }

}


static
PyTypeObject PyGSL_multiminType = {
	PyObject_HEAD_INIT(NULL)
	0,
	(char *) "pygsl.multimin.multimin",
	sizeof(PyGSL_multimin),
	0,
	(destructor)PyGSL_multimin_dealloc,  /* tp_dealloc */
	0,                                      /* tp_print */
	PyGSL_multimin_getattr,              /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	0,                                      /* tp_as_mapping */
	0,				        /* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,		                        /* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,		        /* tp_flags */
        0,				        /* tp_doc */
	0, 		                        /* tp_traverse */
	0,			                /* tp_clear */
	0,              			/* tp_richcompare */
	0,					/* tp_weaklistoffset */
	0,			                /* tp_iter */
	0,					/* tp_iternext */
	0,				        /* tp_methods */
	0,					/* tp_members */
	0,					/* tp_getset */
	0,					/* tp_base */
	0,					/* tp_dict */
	0,					/* tp_descr_get */
	0,					/* tp_descr_set */
	0,					/* tp_dictoffset */
	(initproc)PyGSL_multimin_init,	/* tp_init */
	NULL,              			/* tp_alloc */
	NULL,                			/* tp_new */
	NULL         			        /* tp_free */
};

static PyObject*
PyGSL_multimin_test_size(PyObject * self, PyObject *args)
{
     double size, epsabs;
     int flag = GSL_EFAILED;
     if (0==PyArg_ParseTuple(args,"dd", &size, &epsabs))
	  return NULL;     
     flag = gsl_multimin_test_size(size, epsabs);
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

     if (0==PyArg_ParseTuple(args,"Od", &g, &epsabs))
	  return NULL;     

     ga  = PyGSL_PyArray_PREPARE_gsl_vector_view(g, PyArray_DOUBLE, 0, -1, 1, NULL);
     if (ga == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  return NULL;
     }
     stride_recalc = ga->strides[0] / sizeof(double);
     gradient = gsl_vector_view_array_with_stride((double *)(ga->data), stride_recalc, ga->dimensions[0]);

     flag = gsl_multimin_test_gradient(&gradient.vector, epsabs);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}

static PyMethodDef multiminMethods[] = {
     {"nmsimplex", PyGSL_multimin_init_nmsimplex, METH_VARARGS, NULL},
     {"steepest_descent", PyGSL_multimin_init_steepest_descent, METH_VARARGS, NULL},
     {"vector_bfgs", PyGSL_multimin_init_vector_bfgs, METH_VARARGS, NULL},
     {"conjugate_pr", PyGSL_multimin_init_conjugate_pr, METH_VARARGS, NULL},
     {"conjugate_fr", PyGSL_multimin_init_conjugate_fr, METH_VARARGS, NULL},
     {"test_size", PyGSL_multimin_test_size, METH_VARARGS, NULL},
     {"test_gradient", PyGSL_multimin_test_gradient, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}        /* Sentinel */
};



void
initmultimin(void)
{
  PyObject* m;
  m=Py_InitModule("multimin", multiminMethods);
  init_pygsl();
  /* init multimin type */
  PyGSL_multiminType.ob_type  = &PyType_Type;
  PyGSL_multiminType.tp_alloc = PyType_GenericAlloc;
  PyGSL_multiminType.tp_new   = PyType_GenericNew;
  PyGSL_multiminType.tp_free  = _PyObject_Del;

  module = m;

  Py_INCREF((PyObject*)&PyGSL_multiminType);
  PyModule_AddObject(m,"multimin", (PyObject*)&PyGSL_multiminType);

}
