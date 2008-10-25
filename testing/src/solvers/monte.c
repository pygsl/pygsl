#include <pygsl/solver.h>
#include <pygsl/rng.h>
#include <gsl/gsl_monte.h>
#include <gsl/gsl_monte_plain.h>
#include <gsl/gsl_monte_miser.h>
#include <gsl/gsl_monte_vegas.h>

const char  * filename = __FILE__;
PyObject *module = NULL;
static const char monte_f_type_name[] = "F-monte";
static const char module_doc[] = "XXX Missing";
static const char PyGSL_monte_type[] = "monte";

enum PyGSL_gsl_monte_type{
     PyGSL_MONTE_plain = 1,
     PyGSL_MONTE_miser = 2,
     PyGSL_MONTE_vegas = 3
};

struct _monte_csys{
     enum PyGSL_gsl_monte_type type;
};

typedef struct _monte_csys monte_csys;

static double
PyGSL_g_test(double *k, size_t dim, void *params)
{
     double A = 1.0 / (M_PI * M_PI * M_PI);
     return A / (1.0 - cos (k[0]) * cos (k[1]) * cos (k[2]));
}

static double
PyGSL_monte_function_wrap(double *x,  size_t dim, void *params)
{
     double tmp, *dresult;
     int dimension;
     PyGSL_solver *s;
     PyArrayObject *a_array = NULL;
     PyObject *result = NULL, *arglist=NULL, *callback, *retval;
     PyGSL_error_info  info;
     /* the line number to appear in the traceback */ 
     int trb_lineno = -1, i;
     struct pygsl_array_cache * cache_ptr;
     gsl_vector_view view;

     FUNC_MESS_BEGIN();
     s = (PyGSL_solver  *) params;

     /*
     flag = PyGSL_function_wrap_On_O(&view.vector, s->cbs[0], s->args,
                                     &tmp, NULL, view.vector.size, 
                                     "monte_wrap");
     */

     FUNC_MESS_BEGIN();    
     callback = s->cbs[0];
     assert(s->args != NULL);
     assert(callback != NULL);

     /* Do I need to copy the array ??? */
     for(i = 2; i < PyGSL_SOLVER_N_ARRAYS; ++i){
	  cache_ptr = &(s->cache[i]);
	  if(cache_ptr->ref == NULL)
	       /* no array found */
	       break;
	  if(x == cache_ptr->data){
	       a_array = cache_ptr->ref;
	       break;
	  }
     }
     if(i >= PyGSL_SOLVER_N_ARRAYS){
	  trb_lineno = __LINE__ -1;
	  pygsl_error("Not enough space to cache arrays...", filename, trb_lineno, GSL_ESANITY);
	  goto fail;
     }
     if(a_array == NULL){
	  dimension = dim;
	  a_array = (PyArrayObject *) PyArray_FromDimsAndData(1, &dimension, PyArray_DOUBLE, (char *)x);
	  cache_ptr->ref = a_array;
	  cache_ptr->data = x;
	  /*
	   * Required for deallocation.      
	   * Tuples steal the references. But this array will be dereferenced by the
	   * normal procedure!
	   */
	  Py_INCREF(a_array);
     }
     if (a_array == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
     }
     /* arglist was already set up */
     result = (PyObject *) s->cache[1].ref;
     dresult = (double *) s->cache[1].data;
     arglist = (PyObject *) s->cache[0].ref;

     Py_INCREF(s->args);
     PyTuple_SET_ITEM(arglist, 0, (PyObject *) a_array);
     PyTuple_SET_ITEM(arglist, 1, s->args);

     /*
     arglist = Py_BuildValue("(OOO)", a_array, s->args, result);
     if(DEBUG > 2){
	  fprintf(stderr, "callback = %p, arglist = %p\n", callback, arglist);
     }
     */
     FUNC_MESS("    Call Python Object BEGIN");
     retval = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     /*
     info.callback = callback;
     info.message  = __FUNCTION__;
     if(PyGSL_CHECK_PYTHON_RETURN(retval, 0, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     info.argnum = 1;
     DEBUG_MESS(3, "result was %e", *dresult);
     */
     FUNC_MESS_END();
     return *dresult;


 fail:
     PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, trb_lineno);
     FUNC_MESS("Failure");

     if(s->isset == 1){
	  longjmp(s->buffer, GSL_EFAILED);
	  FUNC_MESS("\t\t Using jump buffer");
     } else {
	  FUNC_MESS("\t\t Jump buffer was not defined!");
     }
     tmp = gsl_nan();
     return tmp;
}

static PyObject *
PyGSL_monte_init(PyGSL_solver *self, PyObject *args)
{
     int flag = GSL_EFAILED;
     monte_csys * csys;
     
     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));
     csys = (monte_csys *)self->c_sys;
     assert(csys);
     switch(csys->type){
     case PyGSL_MONTE_plain:
	  flag = gsl_monte_plain_init(self->solver);
	  break;
     case PyGSL_MONTE_miser:
	  flag = gsl_monte_miser_init(self->solver);
	  break;
     case PyGSL_MONTE_vegas:
	  flag = gsl_monte_vegas_init(self->solver);
	  break;
     default:
	  DEBUG_MESS(2, "Monte type %d unknown",flag);
	  PyGSL_ERROR_NULL("Unknown monte type!", GSL_ESANITY);
     }

     if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	  PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
	  return NULL;
     }
     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;
}

typedef int (*pygsl_monte_fptr_t)(gsl_monte_function * F, double XL[], double XU[], size_t DIM,
		     size_t CALLS, gsl_rng * R, gsl_monte_plain_state * S, 
		     double * RESULT, double * ABSERR);

static PyObject *
PyGSL_monte_integrate(PyGSL_solver *self, PyObject *args)
{

     int flag = GSL_EFAILED, line, dim;
     unsigned int ncalls;
     monte_csys * csys;
     gsl_rng * rng;
     PyObject  *func=NULL, *xlo=NULL, *xuo=NULL, *rng_obj=NULL, *ncallso=NULL, *argso=NULL;
     PyArrayObject *xla=NULL;
     PyArrayObject *xua=NULL;
     double result, abserr;
     gsl_monte_function mfunc;
     pygsl_monte_fptr_t fptr;

     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));
     
     if(!PyArg_ParseTuple(args, "OOOOO|O", &func, &xlo, &xuo, &ncallso, &rng_obj, &argso)){
	  line = __LINE__ - 1;
	  goto fail;
     }

     if(!PyCallable_Check(func)){
	  line = __LINE__ - 1;
	  pygsl_error("The function argument must be callable!", filename, line, GSL_EINVAL);
	  goto fail;	  
     }

     if(PyGSL_PYLONG_TO_UINT(ncallso, &ncalls, NULL) != GSL_SUCCESS){
	  line = __LINE__ - 1;
	  goto fail;
     }

     if(!PyGSL_RNG_Check(rng_obj)){
	  line = __LINE__ - 1;
	  pygsl_error("The rng object must be a rng!", filename, line, GSL_EINVAL);
	  goto fail;
     }

     rng = ((PyGSL_rng *) rng_obj)->rng;
     
     xla = PyGSL_vector_check(xlo, -1, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
     if(xla == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }

     dim = xla->dimensions[0];
     xua = PyGSL_vector_check(xuo, dim, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
     if(xua == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }

     if(argso == NULL){
	  Py_INCREF(Py_None);
	  argso = Py_None;
     }
     Py_XDECREF(self->cbs[0]);
     Py_INCREF(func);
     self->cbs[0] = func;
     self->args = argso;
     csys = (monte_csys *)self->c_sys;

     switch(csys->type){
     case PyGSL_MONTE_plain:	  fptr = (pygsl_monte_fptr_t)&gsl_monte_plain_integrate; break;
     case PyGSL_MONTE_miser:	  fptr = (pygsl_monte_fptr_t)&gsl_monte_miser_integrate; break;
     case PyGSL_MONTE_vegas:	  fptr = (pygsl_monte_fptr_t)&gsl_monte_vegas_integrate; break;
     default:
	  line = __LINE__ - 5;
	  DEBUG_MESS(2, "Monte type %d unknown",flag);
	  pygsl_error("Unknown monte type!", filename, line, GSL_ESANITY);
	  goto fail;
     }

     assert(fptr);
     mfunc.f = &PyGSL_monte_function_wrap;
     mfunc.f = &PyGSL_g_test;
     mfunc.dim = dim;
     mfunc.params = self;

     if(setjmp(self->buffer) != 0){
	  self->isset = 0;
	  line = __LINE__ - 2;
	  goto fail;
     }else{
	  self->isset = 1;
     }
     flag = fptr(&mfunc, (double *) xla->data, (double *)xua->data,
		 dim, ncalls, rng, self->solver, &result, &abserr);
     self->isset = 0;
     if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	  line = __LINE__ - 2;
	  return NULL;
     }

     Py_DECREF(xla);     xla = NULL;
     Py_DECREF(xua);     xua = NULL;
     Py_DECREF(self->cbs[0]);
     Py_DECREF(self->args);
     self->cbs[0] = NULL;
     self->args = NULL;
     FUNC_MESS_END();

     return Py_BuildValue("dd", result, abserr);

 fail:
     FUNC_MESS("FAIL");
     Py_XDECREF(xla);
     Py_XDECREF(xua);
     Py_XDECREF(self->cbs[0]);
     Py_XDECREF(self->args);
     self->cbs[0] = NULL;
     self->args = NULL;
     PyGSL_add_traceback(module, filename, __FUNCTION__, line);
     return NULL;
}

#define GET_SET(montetype, name, mode) \
static PyObject * GetSet_ ## montetype ## _ ## name(PyGSL_solver *self, PyObject *args) \
{ \
     gsl_monte_## montetype ## _state *state = self->solver; \
     return PyGSL_solver_GetSet((PyObject *)self, args, &(state->name), mode); \
}

#define GET_SET_DOUBLE(mintype, name) GET_SET(mintype, name, PyGSL_MODE_DOUBLE)
#define GET_SET_SIZE_T(mintype, name) GET_SET(mintype, name, PyGSL_MODE_SIZE_T)
#define GET_SET_INT(mintype, name)    GET_SET(mintype, name, PyGSL_MODE_INT)

GET_SET_DOUBLE(miser, estimate_frac)
GET_SET_SIZE_T(miser, min_calls)
GET_SET_SIZE_T(miser, min_calls_per_bisection)
GET_SET_DOUBLE(miser, alpha)
GET_SET_DOUBLE(miser, dither)

GET_SET_DOUBLE(vegas, result)
GET_SET_DOUBLE(vegas, sigma)
GET_SET_DOUBLE(vegas, chisq)
GET_SET_DOUBLE(vegas, alpha)
GET_SET_SIZE_T(vegas, iterations)
GET_SET_INT(vegas, stage)
GET_SET_INT(vegas, mode)
GET_SET_INT(vegas, verbose)

#undef GET_SET_DOUBLE
#undef GET_SET_SIZE_T
#undef GET_SET_INT
#undef GET_SET
#define GETSET(montetype, name, mode) {#name, (PyCFunction) GetSet_ ## montetype ## _ ## name, METH_VARARGS, NULL},
#define GET_SET_DOUBLE(montetype, name) GETSET(montetype, name, 0)
#define GET_SET_INT(montetype, name) GETSET(montetype, name, 0)
#define GET_SET_SIZE_T(montetype, name) GETSET(montetype, name, 0)

#define MONTE_STANDARD_METHODS \
     {"init",      (PyCFunction)PyGSL_monte_init,      METH_VARARGS, NULL}, \
     {"integrate", (PyCFunction)PyGSL_monte_integrate, METH_VARARGS, NULL}, \

static PyMethodDef PyGSL_monte_plain_methods[] = {
     MONTE_STANDARD_METHODS
     {NULL, NULL, 0, NULL}
};

static PyMethodDef PyGSL_monte_miser_methods[] = {
     MONTE_STANDARD_METHODS
     GET_SET_DOUBLE(miser, estimate_frac)
     GET_SET_SIZE_T(miser, min_calls)
     GET_SET_SIZE_T(miser, min_calls_per_bisection)
     GET_SET_DOUBLE(miser, alpha)
     GET_SET_DOUBLE(miser, dither)
     {NULL, NULL, 0, NULL}
};

static PyMethodDef PyGSL_monte_vegas_methods[] = {
     MONTE_STANDARD_METHODS
     GET_SET_DOUBLE(vegas, result)
     GET_SET_DOUBLE(vegas, sigma)
     GET_SET_DOUBLE(vegas, chisq)
     GET_SET_DOUBLE(vegas, alpha)
     GET_SET_SIZE_T(vegas, iterations)
     GET_SET_INT(vegas, stage)
     GET_SET_INT(vegas, mode)
     GET_SET_INT(vegas, verbose)
     {NULL, NULL, 0, NULL}
};


/* make the init look similar to the one */
static void *
PyGSL_gsl_monte_alloc(void * type, int n)
{
     enum PyGSL_gsl_monte_type flag = (enum PyGSL_gsl_monte_type) type;
     void * result = NULL;

     FUNC_MESS_BEGIN();
     switch(flag){
     case PyGSL_MONTE_plain:
	  result = gsl_monte_plain_alloc(n);
	  break;
     case PyGSL_MONTE_miser:
	  result = gsl_monte_miser_alloc(n);
	  break;
     case PyGSL_MONTE_vegas:
	  result = gsl_monte_vegas_alloc(n);
	  break;
     default:
	  DEBUG_MESS(2, "Monte type %d unknown",flag);
	  PyGSL_ERROR_NULL("Unknown monte type!", GSL_ESANITY);
     }
     FUNC_MESS_END();
     return result;
}

const struct _SolverStatic
monte_plain_solver_f   = {{(void_m_t) gsl_monte_plain_free,   
			  (void_m_t) NULL,
			  NULL,   
			  NULL},
			  1, PyGSL_monte_plain_methods,  PyGSL_monte_type},
monte_miser_solver_f   = {{(void_m_t) gsl_monte_miser_free,   
			  (void_m_t) NULL,
			  NULL,   
			   NULL},
			  1, PyGSL_monte_miser_methods,  PyGSL_monte_type},
monte_vegas_solver_f   = {{(void_m_t) gsl_monte_vegas_free,   
			  (void_m_t) NULL,
			  NULL,   
			  NULL},
			  1, PyGSL_monte_vegas_methods,  PyGSL_monte_type};

static PyObject*
PyGSL_init_monte(PyObject *self, PyObject *args, int type, const struct _SolverStatic *sost)
{
     PyGSL_solver *result = NULL;
     struct pygsl_array_cache *tmp;
     int line = -1, dims;
     monte_csys * csys;
     PyObject *mytuple;

     FUNC_MESS_BEGIN();
     const solver_alloc_struct alloc = {(const void *) type, (void *) PyGSL_gsl_monte_alloc, sost};          
     result = (PyGSL_solver *) PyGSL_solver_dn_init(self, args, &alloc, 1);
     if(result == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
	  
     csys = (monte_csys *) calloc(1, sizeof(monte_csys));
     if(csys == NULL){
	  PyErr_NoMemory();
	  line = __LINE__ - 1;
	  goto fail;
     }
     

     dims = 1;
     tmp = result->cache;

     tmp[1].ref = PyGSL_New_Array(1, &dims, PyArray_DOUBLE);
     tmp[1].data = (double *) tmp[1].ref->data;
     mytuple =  PyTuple_New(3);
     PyTuple_SetItem(mytuple, 2, (PyObject *) tmp[1].ref);
     /*
      * Required for deallocation.      
      * Tuples steal the references. But this array will be dereferenced by the
      * normal procedure!
      */
     Py_INCREF(tmp[1].ref);
     Py_INCREF(tmp[1].ref);

     /*
      * Initalise the others
      */
     Py_INCREF(Py_None);
     Py_INCREF(Py_None);
     Py_INCREF(Py_None);
     Py_INCREF(Py_None);
     PyTuple_SetItem(mytuple, 0, Py_None);
     PyTuple_SetItem(mytuple, 1, Py_None);

     tmp[0].ref = (PyArrayObject*) mytuple;
     
     result->cache = tmp;
     csys->type = type;
     result->c_sys = csys;

     FUNC_MESS_END();
     return (PyObject *) result;

 fail:
     FUNC_MESS("Fail");
     Py_XDECREF(result);
     PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
     return NULL;
}

#define MONTE_INIT(name) \
static PyObject* PyGSL_init_ ## name(PyObject * self, PyObject *args) \
{ return PyGSL_init_monte(self, args, PyGSL_MONTE_ ##name, &monte_ ## name ## _solver_f); }

MONTE_INIT(plain)
MONTE_INIT(miser)
MONTE_INIT(vegas)


static PyMethodDef mMethods[] = {
     {"plain", PyGSL_init_plain, METH_VARARGS, NULL},
     {"miser", PyGSL_init_miser, METH_VARARGS, NULL},
     {"vegas", PyGSL_init_vegas, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};

void
initmonte(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("monte", mMethods);
     module = m;
     assert(m);
     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     init_pygsl()
     import_pygsl_solver();
     assert(PyGSL_API);


     if (!(item = PyString_FromString((char*)module_doc))){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not generate module doc string!");
	  goto fail;
     }
     if (PyDict_SetItemString(dict, "__doc__", item) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not init doc string!");
	  goto fail;
     }
     PyModule_AddIntConstant(m, "GSL_VEGAS_MODE_IMPORTANCE",      GSL_VEGAS_MODE_IMPORTANCE);
     PyModule_AddIntConstant(m, "GSL_VEGAS_MODE_IMPORTANCE_ONLY", GSL_VEGAS_MODE_IMPORTANCE_ONLY);
     PyModule_AddIntConstant(m, "GSL_VEGAS_MODE_STRATIFIED",      GSL_VEGAS_MODE_STRATIFIED);
     
     FUNC_MESS_END();
     return;

 fail:
     FUNC_MESS("FAIL");
     return;

}
