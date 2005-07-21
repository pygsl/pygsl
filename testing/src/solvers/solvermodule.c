#include "solver.h"
#include "solver_doc.ic"
#include <pygsl/error_helpers.h>
#include <strings.h>

static int *
PyGSL_solver_set_called(PyGSL_solver *self)
{
     FUNC_MESS_BEGIN();
     if(self->set_called == 1)
	  return GSL_SUCCESS;
     DEBUG_MESS(2, "self->set_called was %d", self->set_called);
     gsl_error("The set() method must be called before using the other methods!",
	       filename, __LINE__, GSL_EINVAL);
     FUNC_MESS_END();
}

static PyObject* 
PyGSL_solver_restart(PyGSL_solver *self, PyObject *args) 
{
     FUNC_MESS_BEGIN();
     if (PyGSL_SOLVER_SET_CALLED(self) != GSL_SUCCESS)
	  return NULL;

     if(self->raw_methods->restart == NULL)
	  GSL_ERROR_NULL("Can not restart a solver of this type!", GSL_ESANITY);
     self->raw_methods->restart(self->solver);
     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;
}

static PyObject* 
PyGSL_solver_name(PyGSL_solver *self, PyObject *args) 
{
     PyObject * tmp;
     const char * ctmp;
     FUNC_MESS_BEGIN();
     if(self->raw_methods->name == NULL)
	  GSL_ERROR_NULL("Can not restart a solver of this type!", GSL_ESANITY);
     ctmp = self->raw_methods->name(self->solver);
     tmp =  PyString_FromString(ctmp);
     FUNC_MESS_END();
     return tmp;
}

static PyObject* 
PyGSL_solver_iterate(PyGSL_solver *self, PyObject *args) 
{
     int tmp;
     FUNC_MESS_BEGIN();
     if (PyGSL_SOLVER_SET_CALLED(self) != GSL_SUCCESS)
	  return NULL;

     if(self->raw_methods->iterate == NULL)
	  GSL_ERROR_NULL("Can not restart a solver of this type!", GSL_ESANITY);

     assert(self->raw_methods->iterate);
     assert(self->solver);
     tmp = (self->raw_methods->iterate(self->solver));
     if(PyGSL_ERROR_FLAG(tmp) != GSL_SUCCESS)
	  return NULL;

     return PyInt_FromLong((long) tmp);
}


static void
PyGSL_solver_dealloc(PyGSL_solver * self)
{
     FUNC_MESS_BEGIN();
     assert(self);
     assert(self->raw_methods);
     DEBUG_MESS(3, "Freeing a solver of type %s", self->type_name);
     if(self->raw_methods->free != NULL && self->solver != NULL){
	  self->raw_methods->free(self->solver);
	  self->solver = NULL;
     }
     Py_XDECREF(self->args);     
     self->args = NULL;
     if(self->c_sys){
	  free(self->c_sys);
	  self->c_sys = NULL;
     }
     if(self->problem_dimensions){
	  free(self->problem_dimensions);
	  self->problem_dimensions = NULL;
     }
     PyMem_Free(self);
     self = NULL;
     FUNC_MESS_END();

}
static PyObject *
PyGSL_solver_type(PyGSL_solver * self, PyObject *unused)
{
     assert(self->type_name);
     return PyString_FromString(self->type_name);
}
static PyMethodDef solver_methods[] = {
     {"name",    (PyCFunction) PyGSL_solver_name,    METH_NOARGS, NULL},
     {"restart", (PyCFunction) PyGSL_solver_restart, METH_NOARGS, NULL},
     {"iterate", (PyCFunction) PyGSL_solver_iterate, METH_NOARGS, NULL},
     {"type",    (PyCFunction) PyGSL_solver_type,    METH_NOARGS, NULL},
     {NULL, NULL, 0, NULL}
};
static PyObject *
PyGSL_solver_getattr(PyGSL_solver * self, char * name)
{
     PyObject *tmp = NULL;
     FUNC_MESS_BEGIN();
     if(self->methods->pymethods)
	  tmp = Py_FindMethod(self->methods->pymethods, (PyObject *) self, name);
     if(tmp == NULL){
	  PyErr_Clear();
	  tmp = Py_FindMethod(solver_methods, (PyObject *) self, name);
     }
     FUNC_MESS_END();
     return tmp;
}

static PyTypeObject PyGSL_solver_pytype = {
  PyObject_HEAD_INIT(NULL)	 /* fix up the type slot in initcrng */
  0,				 /* ob_size */
  "PyGSL_solver",		 /* tp_name */
  sizeof(PyGSL_solver),	 /* tp_basicsize */
  0,				 /* tp_itemsize */

  /* standard methods */
  (destructor)  PyGSL_solver_dealloc, /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		 /* tp_print    "print x"     */
  (getattrfunc) PyGSL_solver_getattr,/* tp_getattr  "x.attr"      */
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
  (char *) PyGSL_solver_type_doc		/* tp_doc */
};

PyGSL_SOLVER_STATIC PyGSL_solver* 
_PyGSL_solver_init(const struct _SolverMethods *methods, const struct _GSLMethods* raw_methods) 
{
     PyGSL_solver *solver_o=NULL;
     int line = -1;

     FUNC_MESS_BEGIN();     
     solver_o =  (PyGSL_solver *) PyObject_NEW(PyGSL_solver, &PyGSL_solver_pytype);
     if(solver_o == NULL){
	  line = __LINE__ -1;
	  goto fail;
     }
     solver_o->isset = 0;
     solver_o->args = NULL;     
     solver_o->cbs = NULL;     
     solver_o->tmparrays = NULL;
     solver_o->solver = NULL;
     solver_o->methods = NULL;
     solver_o->raw_methods = NULL;
     solver_o->methods = methods;
     solver_o->raw_methods = raw_methods;
     solver_o->c_sys = NULL;
     solver_o->problem_dimensions = NULL;
     solver_o->type_name = NULL;
     solver_o->set_called = 0;
     solver_o->cbs = (PyObject **) calloc(methods->n_cbs, sizeof(PyObject *));
     if(solver_o->cbs == NULL){
	  line = __LINE__ -1;
	  gsl_error("Could not allocate space for callbacks", __FILE__, line, GSL_ENOMEM);
	  goto fail;
     }
     DEBUG_MESS(3, "refcount = %d", solver_o->ob_refcnt);
     FUNC_MESS_END();
     return solver_o;
 fail:
     FUNC_MESS("Fail");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     return NULL;
}


static PyObject *
_PyGSL_solver_dn_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc, int nd)
{
     PyGSL_solver *solver_o=NULL;
     int n1=1, n2=1;
     int line = -1;
     int flag;

     FUNC_MESS_BEGIN();
     assert(alloc);
     solver_o =  _PyGSL_solver_init(alloc->methods, alloc->raw_methods);
     if(solver_o == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     solver_o->type_name = alloc->type_name;
     switch(nd){
     case 0: flag = 1; break;
     case 1: flag = PyArg_ParseTuple(args,"i", &n1); break;
     case 2: flag = PyArg_ParseTuple(args,"ii", &n1, &n2); break;
     default:
	  gsl_error("Only 1 or two for number of problem_dimensions implemented!",
		    __FILE__, __LINE__, GSL_ESANITY);
	  goto fail;
     }
     if (0==flag){
	  line = __LINE__ - 8 + (nd-1);
	  goto fail;
     }
     if (n1<=0) {
	  PyErr_SetString(PyExc_RuntimeError, "dimension 1 must be >0");
	  line = __LINE__ - 2;
	  goto fail;
     }
     if (n2<=0) {
	  PyErr_SetString(PyExc_RuntimeError, "dimension 2 must be >0");
	  line = __LINE__ - 2;
	  goto fail;
     }
     {
	  void *tmp = alloc->alloc;
	  switch(nd){
	  case 0:
	       solver_o->solver =  ((void_a_t)(tmp))(alloc->type);
	       break;
	  case 1: 
	       solver_o->solver =  (void *) ((void_an_t) tmp)(alloc->type, n1); 
	       break;
	  case 2: 
	       DEBUG_MESS(3, "Allocating solver with N=%d, p=%d", n1, n2);
	       solver_o->solver =  (void *) ((void_anp_t) tmp)(alloc->type, n1, n2); 
	       break;
	  default:
	       gsl_error("Only 0,1 or 2 for number of problem_dimensions implemented!",
			 __FILE__, __LINE__, GSL_ESANITY);
	       goto fail;
	  }
     }

     switch(nd){
     case 1:
     case 2:
	  solver_o->problem_dimensions = calloc(nd, sizeof(int));
	  if(solver_o->solver == NULL || solver_o->problem_dimensions == NULL){
	       line = __LINE__ - 1;
	       goto fail;
	  }
	  break;
     default:
	  ;
     }
     switch(nd){
     case 1:
	  solver_o->problem_dimensions[0] = n1;
	  break;
     case 2:
	  solver_o->problem_dimensions[0] = n2;
	  solver_o->problem_dimensions[1] = n1;
	  break;
     default:
	  ;
     }

     FUNC_MESS_END();
     return (PyObject *) solver_o;
 fail:
     FUNC_MESS("Fail");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     Py_XDECREF(solver_o);
     return NULL;
}

static PyObject *
_PyGSL_solver_np_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc)
{
    FUNC_MESS_BEGIN();     
    return _PyGSL_solver_dn_init(self, args, alloc, 2);
    FUNC_MESS_END();
}

static PyObject *
_PyGSL_solver_n_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc)
{
     FUNC_MESS_BEGIN();
     return _PyGSL_solver_dn_init(self, args, alloc, 1);
     FUNC_MESS_END();
}

static PyObject *
_PyGSL_solver_1_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc)
{
     FUNC_MESS_BEGIN();
     return _PyGSL_solver_dn_init(self, args, alloc, 0);
     FUNC_MESS_END();
}

static double
PyGSL_gsl_function(double x, void * params)
{
     PyGSL_solver *s;
     double result = GSL_NAN;
     int flag = GSL_EFAILED;

     FUNC_MESS_BEGIN();
     assert(params);
     assert(PyGSL_solver_check((PyObject *) params));
     s = (PyGSL_solver *) params;

     flag = PyGSL_function_wrap_helper(x, &result, NULL, s->cbs[0], s->args, __FUNCTION__);
     if(flag == GSL_SUCCESS){
	  FUNC_MESS_END();
	  return result;
     }
     FUNC_MESS("Fail");
     if(s->isset)
	  longjmp(s->buffer, flag);
     DEBUG_MESS(2, "Found an error of %d but could not jump!", flag);
     return GSL_NAN;
}

static double
PyGSL_gsl_function_df(double x, void * params)
{
     PyGSL_solver *s;
     double result = GSL_NAN;
     int flag = GSL_EFAILED;

     FUNC_MESS_BEGIN();
     assert(params);
     assert(PyGSL_solver_check((PyObject *) params));
     s = (PyGSL_solver *) params;

     flag = PyGSL_function_wrap_helper(x, &result, NULL, s->cbs[1], s->args, __FUNCTION__);
     if(flag == GSL_SUCCESS){
	  FUNC_MESS_END();
	  return result;
     }
     FUNC_MESS("Fail");
     if(s->isset)
	  longjmp(s->buffer, flag);
     DEBUG_MESS(2, "Found an error of %d but could not jump!", flag);
     return GSL_NAN;
}

static void
PyGSL_gsl_function_fdf(double x, void * params,  double *f, double *df)
{
     PyGSL_solver *s;
     int flag = GSL_EFAILED;

     FUNC_MESS_BEGIN();
     assert(params);
     assert(PyGSL_solver_check((PyObject *) params));
     s = (PyGSL_solver *) params;

     assert(s->cbs[2]);
     assert(PyCallable_Check(s->cbs[2]));
     flag = PyGSL_function_wrap_helper(x, f, df, s->cbs[2], s->args, __FUNCTION__);
     if(flag == GSL_SUCCESS){
	  FUNC_MESS_END();
	  return;
     }
     FUNC_MESS("Fail");
     if(s->isset)
	  longjmp(s->buffer, flag);
     DEBUG_MESS(2, "Found an error of %d but could not jump!", flag);
     *f = GSL_NAN;
     *df = GSL_NAN;
}

static PyObject* 
_PyGSL_solver_set_f(PyGSL_solver *self, PyObject *pyargs, PyObject *kw, 
		    void *fptr, int isfdf) 
{

     PyObject *f = NULL, *df = NULL, *fdf = NULL, *args = Py_None;
     int  flag=GSL_EFAILED;
     void *c_sys = NULL;
     gsl_function * f_sys = NULL;
     gsl_function_fdf * fdf_sys = NULL;
     double x0, lower=0, upper=0;

     static const char *f_kwlist[]   = {"f", "x0", "upper", "lower", "args", NULL};
     static const char *fdf_kwlist[] = {"f", "df", "fdf", "x0", "args", NULL};

     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     if (self->solver == NULL) {
	  gsl_error("Got a NULL Pointer of min.f",  filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }

     assert(pyargs);
     /* arguments PyFunction, Parameters, start Vector, step Vector */

     if(isfdf == 0){
	  if (0==PyArg_ParseTupleAndKeywords(pyargs,kw,"OdddO", (char **)f_kwlist, &f,
					     &x0,&lower,&upper,&args))
	       return NULL;
     }else{
	  if (0==PyArg_ParseTupleAndKeywords(pyargs,kw,"OOOdO", (char **)fdf_kwlist, &f,&df,&fdf,
					     &x0,&args))
	       return NULL;	  
     }

     if(!PyCallable_Check(f)){
	  gsl_error("First argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	  return NULL;	  
     }
     if(isfdf == 1){
	  if(!PyCallable_Check(df)){
	       gsl_error("Second argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	       return NULL;	  
	  }
	  if(!PyCallable_Check(fdf)){
	       gsl_error("Third argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	       return NULL;	  
	  }
     }
     if (self->c_sys != NULL) {
	  /* free the previous function and args */
	  c_sys = self->c_sys;
     } else {
	  /* allocate function space */
	  if(isfdf == 0)
	       c_sys=calloc(1, sizeof(gsl_function));
	  else
	       c_sys=calloc(1, sizeof(gsl_function_fdf));
	  if (c_sys == NULL) {
	       gsl_error("Could not allocate the object for the minimizer function", 
			 filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
     DEBUG_MESS(3, "Everything allocated args = %p", args);
     /* add new function  and parameters */

     if(_PyGSL_solver_func_set(self, args, f, df, fdf) != GSL_SUCCESS)
	  goto fail;
     
     /* initialize the function struct */
     if(isfdf == 0){
	  f_sys = c_sys;
	  f_sys->function=PyGSL_gsl_function;
	  f_sys->params=(void*)self;
     }else{
	  fdf_sys = c_sys;
	  fdf_sys->f=PyGSL_gsl_function;
	  fdf_sys->df=PyGSL_gsl_function_df;
	  fdf_sys->fdf=PyGSL_gsl_function_fdf;
	  fdf_sys->params=(void*)self;	  
     }
     DEBUG_MESS(3, "Setting jmp buffer isset = % d", self->isset);
     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;
	  if(isfdf == 0){
	       DEBUG_MESS(3, "Calling f isfdf = %d", isfdf);
	       flag = ((set_m_ddd_t) fptr)(self->solver, c_sys, x0, lower, upper);
	  }else{
	       DEBUG_MESS(3, "Calling fdf isfdf = %d", isfdf);
	       flag = ((set_m_d_t) fptr)(self->solver, c_sys, x0);
	  }
	  if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       goto fail;
	  }
     } else {
	  goto fail;
     }
     DEBUG_MESS(4, "Set evaluated. flag = %d", flag);
     self->c_sys = c_sys;
     self->set_called = 1;

     self->isset = 0;
     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;

     
 fail:
     FUNC_MESS("Fail");
     PyGSL_ERROR_FLAG(flag);
     self->isset = 0;
     return NULL;
     
}

PyObject *
_PyGSL_solver_n_set(PyGSL_solver *self, PyObject *pyargs, PyObject *kw, 
		    const struct pygsl_solver_n_set * info)
{
     int n, flag=GSL_EFAILED;
     long stride;

     PyObject *args=Py_None, *f=NULL, *df=NULL, *fdf=NULL, *x;
     PyArrayObject * xa = NULL;
     gsl_vector_view gsl_x;
     void *c_sys;
     int line = -1;
     static const char *f_kwlist[]   = {"f", "x0", "args", NULL};
     static const char *fdf_kwlist[] = {"f", "df", "fdf", "x0", "args", NULL};

     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     if (self->solver == NULL) {
	  gsl_error("Got a NULL Pointer of multiroots.f", filename, __LINE__ - 3, GSL_EFAULT);
	  return NULL;
     }	  

     /* arguments PyFunction, Parameters, start Vector, step Vector */
     if(info->is_fdf == 0){
	  if (0==PyArg_ParseTupleAndKeywords(pyargs, kw, "OO|O", (char **)f_kwlist, 
					     &f, &x, &args))
	       return NULL;
     } else {
	  if (0==PyArg_ParseTupleAndKeywords(pyargs, kw, "OOOO|O", (char **)fdf_kwlist, 
					     &f, &df, &fdf, &x, &args))
	       return NULL;
     }

     n=self->problem_dimensions[0];
     DEBUG_MESS(3, "len(x) should be %d", n);
     xa  = PyGSL_PyArray_PREPARE_gsl_vector_view(x, PyArray_DOUBLE, 0, n, 2, NULL);
     if (xa == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     if(PyGSL_STRIDE_RECALC(xa->strides[0], sizeof(double), &stride) != GSL_SUCCESS){
	  line = __LINE__ - 2;
	  goto fail;
     }
     gsl_x = gsl_vector_view_array_with_stride((double *)(xa->data), stride,
					       xa->dimensions[0]);


     if (self->c_sys != NULL) {
	  c_sys = self->c_sys;
     } else {
	  c_sys=info->c_sys;
     }

     if(_PyGSL_solver_func_set(self, args, f, df, fdf) != GSL_SUCCESS){
	  line = __LINE__ - 1;
	  goto fail;
     }
     if((flag = setjmp(self->buffer)) == 0){
	  self->isset = 1;	  
	  flag = info->set(self->solver, c_sys, &gsl_x.vector);
	  if((PyGSL_ERROR_FLAG(flag)) != GSL_SUCCESS){
	  line = __LINE__ - 2;
	       goto fail;
	  }
     }else{
	  line = __LINE__ - 9;
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
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     self->isset = 0;
     self->set_called = 0;
     Py_XDECREF(xa);
     return NULL;
     
}

static PyObject* 
PyGSL_solver_ret_int(PyGSL_solver *self, PyObject *args, 
			int_m_t func)
{
     int result;
     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     result=func(self->solver);
     FUNC_MESS_END();
     return (PyObject *) PyLong_FromLong((long)result);
} 

static PyObject* 
PyGSL_solver_ret_double(PyGSL_solver *self, PyObject *args, 
			double_m_t func)
{
     double result;
     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     result=func(self->solver);
     FUNC_MESS_END();
     return (PyObject *) PyFloat_FromDouble(result);
} 

static PyObject* 
PyGSL_solver_ret_vec(PyGSL_solver *self, PyObject *args, 
		     ret_vec func)
{
     gsl_vector *result;
     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     result=func(self->solver);
     if(result == NULL)
	  GSL_ERROR_NULL("Could not retrive vector ...", GSL_ESANITY);
     FUNC_MESS_END();
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(result);
} 

/*
 * evaluates a C function taking an vector and a double as input and returning a status.
 */
static PyObject*
_PyGSL_solver_i_vd(PyObject * self, PyObject *args, int_f_vd_t func)
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
     gradient = gsl_vector_view_array_with_stride((double *)(ga->data), stride_recalc,
						  ga->dimensions[0]);
     flag = func(&gradient.vector, epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}

static PyObject *
_PyGSL_solver_i_vvdd(PyObject * self, PyObject * args, int_f_vvdd_t func)
{
     int flag;
     int line = -1;
     long stride;
     double epsabs, epsrel;
     PyObject *dx_o, *x_o;
     PyArrayObject *dx_a = NULL, *x_a = NULL;
     gsl_vector_view x, dx;

     FUNC_MESS_BEGIN();
     if(!PyArg_ParseTuple(args, "OOdd", &dx_o, &x_o, &epsabs, &epsrel))
	  return NULL;

     dx_a = PyGSL_PyArray_prepare_gsl_vector_view(dx_o, PyArray_DOUBLE,
						 PyGSL_CONTIGUOUS | PyGSL_INPUT_ARRAY,
						 -1, 1, NULL);
     if(dx_a == NULL){
	  line = __LINE__ - 4;
	  goto fail;
     }
     if((PyGSL_STRIDE_RECALC(dx_a->strides[0], sizeof(double), &stride)) != GSL_SUCCESS){
	  line = __LINE__ - 2;
	  goto fail;
     }
     dx = gsl_vector_view_array_with_stride((double *)(dx_a->data), stride, dx_a->dimensions[0]);

     x_a = PyGSL_PyArray_prepare_gsl_vector_view(x_o, PyArray_DOUBLE,
						 PyGSL_CONTIGUOUS | PyGSL_INPUT_ARRAY,
						 -1, dx_a->dimensions[0], NULL);
     if(x_a == NULL){
	  line = __LINE__ - 4;
	  goto fail;
     }
     if((PyGSL_STRIDE_RECALC(x_a->strides[0],sizeof(double), &stride)) != GSL_SUCCESS){
	  line = __LINE__ - 2;
	  goto fail;
     }
     x = gsl_vector_view_array_with_stride((double *)(x_a->data), stride, x_a->dimensions[0]);
     flag = func(&(dx.vector), &(x.vector), epsabs, epsrel);
     Py_DECREF(x_a);
     Py_DECREF(dx_a);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     Py_XDECREF(dx_a);
     Py_XDECREF(x_a);
     return NULL;
}

PyGSL_SOLVER_STATIC int
PyGSL_Callable_Check(PyObject *f, const char * myname)
{
     FUNC_MESS_BEGIN();
     if(!PyCallable_Check(f)){
	  char str[256];
	  snprintf(str, 254, "Callback named %s is not callable!", myname);
	  GSL_ERROR(str, GSL_EINVAL);
     }
     FUNC_MESS_END();
     return GSL_SUCCESS;
}

PyGSL_SOLVER_STATIC int
_PyGSL_solver_func_set(PyGSL_solver *self, PyObject *args, PyObject *f,
		       PyObject *df, PyObject *fdf)
{
     int flag = GSL_EFAILED;
     if(df){
	  if(!fdf)
	       GSL_ERROR("If df is given, fdf must be given as well!", GSL_ESANITY);
	  Py_XDECREF(self->cbs[1]);
	  Py_XDECREF(self->cbs[2]);
	  self->cbs[1] = NULL;	  
	  self->cbs[2] = NULL;
     }
     Py_XDECREF(self->args);
     Py_XDECREF(self->cbs[0]);
     self->args = NULL;     
     self->cbs[0] = NULL;

     
     DEBUG_MESS(3, "args = %p", (void *) args);
     self->args=args; Py_XINCREF(args);
     assert(f);
     if((flag = PyGSL_CALLABLE_CHECK(f, "f")) != GSL_SUCCESS)
	  return flag;
     self->cbs[0] = f; Py_INCREF(f);
     if(df){
	  assert(fdf);
	  if((flag = PyGSL_CALLABLE_CHECK(df, "df")) != GSL_SUCCESS)
	       return flag;
	  if((flag = PyGSL_CALLABLE_CHECK(fdf, "fdf")) != GSL_SUCCESS)
	       return flag;
	  self->cbs[1]=df;   Py_INCREF(df);
	  self->cbs[2]=fdf;  Py_INCREF(fdf);
     }
     return GSL_SUCCESS;     
}

#ifdef ONEFILE
#include "chars.c"
#include "function_helpers.c"
#include "odeiv.c"
#include "integrate.c"
#include "roots.c"
#include "minimize.c"
#include "multifit_nlin.c"
#include "multimin.c"
#include "multiroot.c"
#endif /* ONEFILE */

static PyMethodDef solverMethods[] = {
     /* multimin inits */
     {"nmsimplex",        PyGSL_multimin_init_nmsimplex,        METH_VARARGS, (char *)nmsimplex_doc       },
     {"steepest_descent", PyGSL_multimin_init_steepest_descent, METH_VARARGS, (char *)steepest_descent_doc},
     {"vector_bfgs",      PyGSL_multimin_init_vector_bfgs,      METH_VARARGS, (char *)vector_bfgs_doc     },
     {"conjugate_pr",     PyGSL_multimin_init_conjugate_pr,     METH_VARARGS, (char *)conjugate_pr_doc    },
     {"conjugate_fr",     PyGSL_multimin_init_conjugate_fr,     METH_VARARGS, (char *)conjugate_fr_doc    },
     {"test_size",        PyGSL_multimin_test_size,             METH_VARARGS, (char *)test_size_doc       },
     {"test_gradient",    PyGSL_multimin_test_gradient,         METH_VARARGS, (char *)test_gradient_doc   },
     /* multimin funcs */
     {"test_size",        PyGSL_multimin_test_size,             METH_VARARGS, (char *)test_size_doc       },
     {"test_gradient",    PyGSL_multimin_test_gradient,         METH_VARARGS, (char *)test_gradient_doc   },
     /* mutliroot solvers */
     {"dnewton" ,      PyGSL_multiroot_init_dnewton,  METH_VARARGS, NULL},   
     {"broyden" ,      PyGSL_multiroot_init_broyden,  METH_VARARGS, NULL},
     {"hybrid"  ,      PyGSL_multiroot_init_hybrid ,  METH_VARARGS, NULL},
     {"hybrids" ,      PyGSL_multiroot_init_hybrids,  METH_VARARGS, NULL},
     {"newton"  ,      PyGSL_multiroot_init_newton ,  METH_VARARGS, NULL},
     {"gnewton" ,      PyGSL_multiroot_init_gnewton,  METH_VARARGS, NULL},
     {"hybridj" ,      PyGSL_multiroot_init_hybridj,  METH_VARARGS, NULL},
     {"hybridsj",      PyGSL_multiroot_init_hybridsj, METH_VARARGS, NULL},
     /* mutliroot funcs */
     {"test_delta",    PyGSL_multiroot_test_delta,     METH_VARARGS, NULL},
     {"test_residual", PyGSL_multiroot_test_residual,  METH_VARARGS, NULL},
     /* multifit solvers */
     {"lmder",          PyGSL_multifit_init_lmder,  METH_VARARGS, NULL},
     {"lmsder",          PyGSL_multifit_init_lmsder,  METH_VARARGS, NULL},
     /* multifit funcs */
     {"fit_test_delta",    PyGSL_multifit_test_delta,     METH_VARARGS, NULL},
     {"fit_test_gradient", PyGSL_multifit_test_gradient,  METH_VARARGS, NULL},
     {"gradient",          PyGSL_multifit_gradient,  METH_VARARGS, NULL},
     {"covar",             PyGSL_multifit_covar,  METH_VARARGS, NULL},
     /* min methods */
     {"test_interval",   PyGSL_min_test_interval, METH_VARARGS, (char *)min_test_delta_doc}, 
     {"brent",        PyGSL_min_init_brent, METH_NOARGS, (char *)min_init_brent_doc}, 
     {"goldensection",PyGSL_min_init_goldensection, METH_NOARGS, (char *)min_init_goldensection_doc}, 
     /* root solver methods */
     {"bisection",  PyGSL_root_init_bisection, METH_NOARGS, NULL},
     {"falsepos",  PyGSL_root_init_falsepos, METH_NOARGS, NULL},
     {"rbrent",  PyGSL_root_init_brent, METH_NOARGS, NULL},
     {"rnewton",  PyGSL_root_init_newton, METH_NOARGS, NULL},
     {"secant",  PyGSL_root_init_secant, METH_NOARGS, NULL},
     {"steffenson",  PyGSL_root_init_steffenson, METH_NOARGS, NULL},
     {"rtest_delta",  PyGSL_root_test_delta, METH_VARARGS, NULL},
     {"rtest_interval",  PyGSL_root_test_interval, METH_VARARGS, NULL},
     /* odeiv */
     {"step_rk2",    (PyCFunction)PyGSL_odeiv_step_init_rk2,    METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk4",    (PyCFunction)PyGSL_odeiv_step_init_rk4,    METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rkf45",  (PyCFunction)PyGSL_odeiv_step_init_rkf45,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rkck",   (PyCFunction)PyGSL_odeiv_step_init_rkck,   METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk8pd",  (PyCFunction)PyGSL_odeiv_step_init_rk8pd,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk2imp", (PyCFunction)PyGSL_odeiv_step_init_rk2imp, METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk4imp", (PyCFunction)PyGSL_odeiv_step_init_rk4imp, METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_bsimp",  (PyCFunction)PyGSL_odeiv_step_init_bsimp,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_gear1",  (PyCFunction)PyGSL_odeiv_step_init_gear1,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_gear2",  (PyCFunction)PyGSL_odeiv_step_init_gear2,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"control_standard_new", PyGSL_odeiv_control_init_standard_new, METH_VARARGS, NULL},
     {"control_y_new",        PyGSL_odeiv_control_init_y_new,        METH_VARARGS, NULL},
     {"control_yp_new",       PyGSL_odeiv_control_init_yp_new,       METH_VARARGS, NULL},
     {"evolve", PyGSL_odeiv_evolve_init, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};

void
initsolver(void)
{
  PyObject* m, *dict, *item;
  m=Py_InitModule("solver", solverMethods);
  import_array();
  init_pygsl();
  /* init multimin type */
  PyGSL_solver_pytype.ob_type  = &PyType_Type;


  module = m;

  Py_INCREF((PyObject*)&PyGSL_solver_pytype);

  dict = PyModule_GetDict(m);
  if(!dict)
       goto fail;
  
  if (!(item = PyString_FromString((char*)PyGSL_solver_module_doc))){
       PyErr_SetString(PyExc_ImportError, 
		       "I could not generate module doc string!");
       goto fail;
  }
  if (PyDict_SetItemString(dict, "__doc__", item) != 0){
       PyErr_SetString(PyExc_ImportError, 
		       "I could not init doc string!");
       goto fail;
  }

 fail:
  return;

}
