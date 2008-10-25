#include "solver_intern.h"
#include <pygsl/general_helpers.h>
#include <pygsl/block_helpers.h>
#if 0
#include <pygsl/function_helpers.h>
#endif
#include <setjmp.h>
#include <gsl/gsl_math.h>
#include <pygsl/error_helpers.h>
#include <strings.h>
#include "solver_doc.ic"


PyObject * module = NULL;
const char *filename = __FILE__;


static int
PyGSL_solver_set_called(PyGSL_solver *self)
{
     FUNC_MESS_BEGIN();
     if(self->set_called == 1)
	  return GSL_SUCCESS;
     DEBUG_MESS(2, "self->set_called was %d", self->set_called);
     pygsl_error("The set() method must be called before using the other methods!",
	       filename, __LINE__, GSL_EINVAL);
     FUNC_MESS_END();
     return GSL_EINVAL;
}

static PyObject* 
PyGSL_solver_restart(PyGSL_solver *self, PyObject *args) 
{
     FUNC_MESS_BEGIN();
     if (PyGSL_SOLVER_SET_CALLED(self) != GSL_SUCCESS)
	  return NULL;

     if(self->mstatic->cmethods.restart == NULL)
	  PyGSL_ERROR_NULL("Can not restart a solver of this type!", GSL_ESANITY);
     self->mstatic->cmethods.restart(self->solver);
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
     if(self->mstatic->cmethods.name == NULL)
	  PyGSL_ERROR_NULL("Can not restart a solver of this type!", GSL_ESANITY);
     ctmp = self->mstatic->cmethods.name(self->solver);
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

     if(self->mstatic->cmethods.iterate == NULL)
	  PyGSL_ERROR_NULL("Can not restart a solver of this type!", GSL_ESANITY);

     assert(self->mstatic->cmethods.iterate);
     assert(self->solver);
     tmp = (self->mstatic->cmethods.iterate(self->solver));
     if(PyGSL_ERROR_FLAG(tmp) != GSL_SUCCESS)
	  return NULL;

     return PyInt_FromLong((long) tmp);
}


static void
PyGSL_solver_dealloc(PyGSL_solver * self)
{
     /* struct pygsl_array_cache * cache_ptr; 
     int i, count;
     PyObject * ob;
     PyArrayObject *tmp;
     */
     FUNC_MESS_BEGIN();
     assert(self);
     assert(self->mstatic);

     if(self->mstatic->cmethods.free == NULL){
	  DEBUG_MESS(3, "Could not free solver @ %p. No free method specified!", self->solver);
     }else{
	  DEBUG_MESS(3, "Freeing a solver of type %s", self->mstatic->type_name);
	  if(self->solver != NULL){
	       self->mstatic->cmethods.free(self->solver);
	       self->solver = NULL;
	  }
     }

     Py_XDECREF(self->args);     
     self->args = NULL;
     if(self->c_sys){
	  DEBUG_MESS(3, "Freeing c_sys @ %p", self->c_sys);
	  free(self->c_sys);
	  self->c_sys = NULL;
     }

     /*
      * remove the cached arrays
      */
     if(self->cache == NULL){
	  DEBUG_MESS(2, "No cache was used cache = %p", self->cache);
     }else{
#if 0
	  cache_ptr = self->cache;
	  for(i = 0; i< PyGSL_SOLVER_N_ARRAYS; ++i){
	       tmp =  cache_ptr[i].ref;
	       ob = (PyObject *) tmp;
	       if(ob == NULL){
		    break;
	       }
	       count =  ob->ob_refcnt;
	       if(count == 0){
		    DEBUG_MESS(3, "object[%d] @ %p has a zero reference count!"
			       " array should be deposed already and ptr set to zero!", i, ob);
	       }else if(count == 1){
		    /* no one referencing the array; good */		    
		    DEBUG_MESS(3, "Dereferencing  object[%d] @ %p", i, ob);
		    Py_DECREF(ob);
		    cache_ptr[i].ref = NULL;
	       }else if(count < 0){
		    DEBUG_MESS(2, "I found an array (object) at %p which had "
			       "a count [%d] smaller than zero", ob, count);
		    
	       }else{
		    /* count > 1 */
		    fprintf(stderr, "In %s at %d array %d had %d refcouts.\n"
			    "This means you reference an array which was\n"
			    "passed to you while evaluating your callback.\n" 
			    "This produces a memory leak!\n", 
			    __FILE__, __LINE__, i, count);		    
	       
	       }
	  } /* handeled cached objects */
	  fprintf(stderr, "Freed %d cached objects\n", i);
	  /* free the cache */
	  free(self->cache);
	  self->cache = NULL;
#endif 

     } /* freeing cached objects */
     PyObject_Del(self);
     self = NULL;
     FUNC_MESS_END();

}

static PyObject *
PyGSL_solver_type(PyGSL_solver * self, PyObject *unused)
{
     assert(self->mstatic->type_name);
     return PyString_FromString(self->mstatic->type_name);
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
     if(self->mstatic->pymethods)
	  tmp = Py_FindMethod(self->mstatic->pymethods, (PyObject *) self, name);
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

PyGSL_solver* 
_PyGSL_solver_init(const struct _SolverStatic *mstatic) 
{
     PyGSL_solver *solver_o=NULL;
     int line = -1;
     int i;

     FUNC_MESS_BEGIN();     
     if(mstatic->n_cbs > PyGSL_SOLVER_NCBS_MAX){
	  line = __LINE__ - 1;
	  pygsl_error("More callbacks requested than possible!", __FILE__,
		    line, GSL_ESANITY);
	  goto fail;
     }
     solver_o =  (PyGSL_solver *) PyObject_NEW(PyGSL_solver, &PyGSL_solver_pytype);
     if(solver_o == NULL){
	  line = __LINE__ -1;
	  goto fail;
     }
     
     solver_o->args = NULL;     
     solver_o->cache = NULL;
     solver_o->mstatic = NULL;
     solver_o->mstatic = mstatic;
     solver_o->solver = NULL;
     solver_o->c_sys = NULL;
     solver_o->set_called = 0;
     solver_o->isset = 0;

     for(i = 0; i < PyGSL_SOLVER_NCBS_MAX; ++i){
	  solver_o->cbs[i] = NULL;
     }

     for(i = 0; i < PyGSL_SOLVER_PB_ND_MAX; ++i){
	  solver_o->problem_dimensions[i] = -1;
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
PyGSL_solver_dn_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc, int nd)
{
     PyGSL_solver *solver_o=NULL;
     int n1=1, n2=1;
     int line = -1;
     int flag=0;

     FUNC_MESS_BEGIN();
     assert(alloc);
     solver_o =  _PyGSL_solver_init(alloc->mstatic);
     if(solver_o == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     switch(nd){
     case 0: flag = 1; break;
     case 1: flag = PyArg_ParseTuple(args,"i", &n1); break;
     case 2: flag = PyArg_ParseTuple(args,"ii", &n1, &n2); break;
     case 3:
	  /* odeiv */
	  flag = 1; break;
     default:
	  line = __LINE__;
	  pygsl_error("Only 1 or two for number of problem_dimensions implemented!",
		    __FILE__, line, GSL_ESANITY);
	  goto fail;
     }
     if (0==flag){
	  /* Successful parsing of the arguments ?*/
	  line = __LINE__ - 1;
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
	  case 3:
	       /* odeiv handles that itself */
	       break;
	  default:
	       pygsl_error("Only 0,1 or 2 for number of problem_dimensions implemented!",
			 __FILE__, __LINE__, GSL_ESANITY);
	       goto fail;
	  }
     }

     switch(nd){
     case 1:
     case 2:
	  if(solver_o->solver == NULL){
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

     solver_o->cache = (struct pygsl_array_cache *) calloc(PyGSL_SOLVER_N_ARRAYS, sizeof(struct pygsl_array_cache));
     if(solver_o->cache == NULL){
	  PyErr_NoMemory();
	  line = __LINE__ - 1;
	  goto fail;
     }

     FUNC_MESS_END();
     return (PyObject *) solver_o;
 fail:
     FUNC_MESS("Fail");
     DEBUG_MESS(3, "line was %d", line);
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     Py_XDECREF(solver_o);
     return NULL;
}

#if 0
static PyObject *
_PyGSL_solver_np_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc)
{
    FUNC_MESS_BEGIN();     
    return PyGSL_solver_dn_init(self, args, alloc, 2);
    FUNC_MESS_END();
}

static PyObject *
PyGSL_solver_n_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc)
{
     FUNC_MESS_BEGIN();
     return PyGSL_solver_dn_init(self, args, alloc, 1);
     FUNC_MESS_END();
}

static PyObject *
_PyGSL_solver_1_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc)
{
     FUNC_MESS_BEGIN();
     return PyGSL_solver_dn_init(self, args, alloc, 0);
     FUNC_MESS_END();
}

#endif
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
PyGSL_solver_set_f(PyGSL_solver *self, PyObject *pyargs, PyObject *kw, 
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
	  pygsl_error("Got a NULL Pointer of min.f",  filename, __LINE__ - 3, GSL_EFAULT);
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
	  pygsl_error("First argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	  return NULL;	  
     }
     if(isfdf == 1){
	  if(!PyCallable_Check(df)){
	       pygsl_error("Second argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
	       return NULL;	  
	  }
	  if(!PyCallable_Check(fdf)){
	       pygsl_error("Third argument must be callable",  filename, __LINE__ - 3, GSL_EBADFUNC);
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
	       pygsl_error("Could not allocate the object for the minimizer function", 
			 filename, __LINE__ - 3, GSL_ENOMEM);
	       goto fail;
	  }
     }
     DEBUG_MESS(3, "Everything allocated args = %p", args);
     /* add new function  and parameters */

     if(PyGSL_solver_func_set(self, args, f, df, fdf) != GSL_SUCCESS)
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

/*
 * Set the solver
 */
PyGSL_API_EXTERN PyObject *
PyGSL_solver_n_set(PyGSL_solver *self, PyObject *pyargs, PyObject *kw, 
		    const struct pygsl_solver_n_set * info)
{
     int n, flag=GSL_EFAILED;
     PyGSL_array_index_t stride;

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
	  pygsl_error("solver ==  NULL at solver_n_set", filename, __LINE__ - 3, GSL_EFAULT);
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
     xa  = PyGSL_vector_check(x, n, PyGSL_DARRAY_INPUT(2), &stride, NULL);
     if (xa == NULL){
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

     if(PyGSL_solver_func_set(self, args, f, df, fdf) != GSL_SUCCESS){
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
PyGSL_solver_ret_size_t(PyGSL_solver *self, PyObject *args, 
			size_t_m_t func)
{
     size_t result;
     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     result=func(self->solver);
     FUNC_MESS_END();
     return (PyObject *) PyLong_FromLong((long)result);
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
	  PyGSL_ERROR_NULL("Could not retrive vector ...", GSL_ESANITY);
     FUNC_MESS_END();
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(result);
} 

/*
 * evaluates a C function taking an vector and a double as input and returning a status.
 */
static PyObject*
PyGSL_solver_vd_i(PyObject * self, PyObject *args, int_f_vd_t func)
{
     PyObject *g=NULL;
     PyArrayObject *ga=NULL;
     gsl_vector_view gradient;

     double epsabs;
     int flag = GSL_EFAILED;
     PyGSL_array_index_t stride_recalc=-1;

     FUNC_MESS_BEGIN();
     if (0==PyArg_ParseTuple(args,"Od", &g, &epsabs))
	  return NULL;     

     ga  = PyGSL_vector_check(g, -1, PyGSL_DARRAY_INPUT(1), &stride_recalc, NULL);
     if (ga == NULL){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 1);
	  return NULL;
     }
     gradient = gsl_vector_view_array_with_stride((double *)(ga->data), stride_recalc,
						  ga->dimensions[0]);
     flag = func(&gradient.vector, epsabs);
     FUNC_MESS_END();
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
     
}

static PyObject *
PyGSL_solver_vvdd_i(PyObject * self, PyObject * args, int_f_vvdd_t func)
{
     int flag;
     int line = -1;
     double epsabs, epsrel;
     PyObject *dx_o, *x_o;
     PyArrayObject *dx_a = NULL, *x_a = NULL;
     gsl_vector_view x, dx;
     PyGSL_array_index_t dimension, stride;

     FUNC_MESS_BEGIN();
     if(!PyArg_ParseTuple(args, "OOdd", &dx_o, &x_o, &epsabs, &epsrel))
	  return NULL;

     dx_a = PyGSL_vector_check(dx_o, -1, PyGSL_DARRAY_INPUT(1), &stride, NULL);
     if(dx_a == NULL){
	  line = __LINE__ - 4;
	  goto fail;
     }
     dx = gsl_vector_view_array_with_stride((double *)(dx_a->data), stride, dx_a->dimensions[0]);

     dimension = dx_a->dimensions[0];
     x_a = PyGSL_vector_check(x_o, dimension, PyGSL_DARRAY_CINPUT(2), &stride,  NULL);
     if(x_a == NULL){
	  line = __LINE__ - 4;
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

PyGSL_API_EXTERN int
PyGSL_Callable_Check(PyObject *f, const char * myname)
{
     FUNC_MESS_BEGIN();
     if(!PyCallable_Check(f)){
	  char str[256];
	  snprintf(str, 254, "Callback named %s is not callable!", myname);
	  PyGSL_ERROR(str, GSL_EINVAL);
     }
     FUNC_MESS_END();
     return GSL_SUCCESS;
}

PyGSL_API_EXTERN int
PyGSL_solver_func_set(PyGSL_solver *self, PyObject *args, PyObject *f,
		       PyObject *df, PyObject *fdf)
{
     int flag = GSL_EFAILED;
     if(df){
	  if(!fdf)
	       PyGSL_ERROR("If df is given, fdf must be given as well!", GSL_ESANITY);
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


static PyObject *
PyGSL_solver_GetSet(PyObject *self, PyObject *args, void * address, enum PyGSL_GETSET_typemode mode)
{
     PyObject *ret=NULL, *input=NULL;
     unsigned long ultmp;
     int flag;

     if (!PyArg_ParseTuple(args, "|O", &input))	  
	  return NULL;

     if(input){
	  switch(mode){
	  case PyGSL_MODE_DOUBLE:
	       flag = PyGSL_PYFLOAT_TO_DOUBLE(input, (double *) address, NULL);
	       break;
	  case PyGSL_MODE_INT:
	       flag = PyGSL_PYINT_TO_INT(input, (int *) address, NULL);
	       break;
	  case PyGSL_MODE_SIZE_T:
	       flag = PyGSL_PYLONG_TO_ULONG(input, &ultmp, NULL);
	       *((size_t *) address) = ultmp;
	       break;
	  default:
	       PyGSL_ERROR_NULL("Unknown mode",GSL_ESANITY);
	  }
	  if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS)
	       return NULL;

	  Py_INCREF(Py_None);
	  ret = Py_None;
	  return ret;     
     }

     switch(mode){
     case PyGSL_MODE_DOUBLE:
	  ret = PyFloat_FromDouble(*((double *) address));
	  break;
     case PyGSL_MODE_INT:
	  ret = PyInt_FromLong(((long) *((int *) address)));
	  break;
     case PyGSL_MODE_SIZE_T:
	  ret = PyLong_FromUnsignedLong(((unsigned long) *((size_t *) address)));
	  break;
     default:
	  PyGSL_ERROR_NULL("Unknown mode",GSL_ESANITY);
     }
     return ret;
}

#ifdef ONEFILE

#include "chars.c"
#include "function_helpers2.c"
/* 

#include "function_helpers.c"
#include "integrate.c"
#include "odeiv.c"
#include "roots.c"
#include "minimize.c"
#include "multifit_nlin.c"
#include "multimin.c" 
#include "multiroot.c"
*/
#endif /* ONEFILE */

static PyMethodDef solverMethods[] = {
     {NULL, NULL, 0, NULL}
};

void
init_api(void)
{
     FUNC_MESS_BEGIN();    
     PyGSL_API[PyGSL_solver_type_NUM            ] = (void *) &PyGSL_solver_pytype     ;
     PyGSL_API[PyGSL_solver_ret_int_NUM         ] = (void *) &PyGSL_solver_ret_int    ;
     PyGSL_API[PyGSL_solver_ret_double_NUM      ] = (void *) &PyGSL_solver_ret_double ;
     PyGSL_API[PyGSL_solver_ret_size_t_NUM      ] = (void *) &PyGSL_solver_ret_size_t ;
     PyGSL_API[PyGSL_solver_ret_vec_NUM         ] = (void *) &PyGSL_solver_ret_vec    ;
     PyGSL_API[PyGSL_solver_dn_init_NUM         ] = (void *) &PyGSL_solver_dn_init    ;
     PyGSL_API[PyGSL_solver_vd_i_NUM            ] = (void *) &PyGSL_solver_vd_i       ;
     PyGSL_API[PyGSL_solver_vvdd_i_NUM          ] = (void *) &PyGSL_solver_vvdd_i     ;
     PyGSL_API[PyGSL_Callable_Check_NUM         ] = (void *) &PyGSL_Callable_Check    ;
     PyGSL_API[PyGSL_solver_func_set_NUM        ] = (void *) &PyGSL_solver_func_set   ;
     PyGSL_API[PyGSL_function_wrap_OnOn_On_NUM  ] = (void *) &PyGSL_function_wrap_OnOn_On;
     PyGSL_API[PyGSL_function_wrap_On_O_NUM     ] = (void *) &PyGSL_function_wrap_On_O;
     PyGSL_API[PyGSL_function_wrap_Op_On_NUM    ] = (void *) &PyGSL_function_wrap_Op_On;
     PyGSL_API[PyGSL_function_wrap_Op_Opn_NUM   ] = (void *) &PyGSL_function_wrap_Op_Opn;
     PyGSL_API[PyGSL_function_wrap_Op_On_Opn_NUM] = (void *) &PyGSL_function_wrap_Op_On_Opn;
     PyGSL_API[PyGSL_solver_n_set_NUM           ] = (void *) &PyGSL_solver_n_set      ;
     PyGSL_API[PyGSL_solver_set_f_NUM           ] = (void *) &PyGSL_solver_set_f      ;
     PyGSL_API[PyGSL_solver_getset_NUM          ] = (void *) &PyGSL_solver_GetSet     ;
     FUNC_MESS_END();
}

void
initsolver(void)
{
  PyObject* m, *dict, *item;

  FUNC_MESS_BEGIN();
  m=Py_InitModule("solver", solverMethods);
  init_pygsl();


  /* init multimin type */
  PyGSL_solver_pytype.ob_type  = &PyType_Type;

  init_api();


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
  FUNC_MESS_END();

 fail:
  FUNC_MESS("FAIL");
  return;

}
