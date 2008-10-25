#include <pygsl/solver.h>
#include <gsl/gsl_multifit_nlin.h>

const char  * filename = __FILE__;
PyObject *module = NULL;
static const char multifit_f_type_name[] = "F-MultiFitSolver";
static const char multifit_fdf_type_name[] = "FdF-MultiFitSolver";


static int 
PyGSL_multifit_function_wrap(const gsl_vector *x, void *params, gsl_vector *f)
{
     PyGSL_solver *self = (PyGSL_solver *) params;
     return PyGSL_function_wrap_Op_On(x, f, self->cbs[0], self->args, x->size, f->size,
				      __FUNCTION__);
}


static int 
PyGSL_multifit_function_wrap_df(const gsl_vector *x, void *params, gsl_matrix *df)
{
     PyGSL_solver *self = (PyGSL_solver *) params; 
     /* size 1 or size 2 from matrix ? */
     return PyGSL_function_wrap_Op_Opn(x, df, self->cbs[1], self->args, df->size1, x->size, 
				       __FUNCTION__);
}

static int 
PyGSL_multifit_function_wrap_fdf(const gsl_vector *x, void *params, gsl_vector *f, gsl_matrix *df)
{
     PyGSL_solver *self = (PyGSL_solver *) params;
     /* size 1 or size 2 from matrix ? */
     return PyGSL_function_wrap_Op_On_Opn(x, f, df, self->cbs[2], self->args, f->size, x->size, 
					  __FUNCTION__);
}

static PyObject *
PyGSL_multifit_fdfsolver_set(PyGSL_solver *self, PyObject *pyargs, PyObject *kw)
{

     gsl_multifit_function_fdf * c_sys;
     struct pygsl_solver_n_set info = {1, NULL, (set_m_t)gsl_multifit_fdfsolver_set};
     PyObject * tmp;

     FUNC_MESS_BEGIN();
     if(self->c_sys == NULL){	  
	  if((c_sys = calloc(1, sizeof(gsl_multifit_function_fdf))) == NULL){
	       PyGSL_ERROR_NULL("Could not allocate the memory for the c_sys", GSL_ENOMEM);
	  }	  
	  c_sys->n=self->problem_dimensions[1];
	  c_sys->p=self->problem_dimensions[0];
	  c_sys->f  = PyGSL_multifit_function_wrap;
	  c_sys->df = PyGSL_multifit_function_wrap_df;
	  c_sys->fdf = PyGSL_multifit_function_wrap_fdf;
	  c_sys->params=(void*)self;
	  info.c_sys = c_sys;	  
     }else{
	  info.c_sys = self->c_sys;
     }
     tmp =  PyGSL_solver_n_set(self, pyargs, kw, &info);     
     if(tmp == NULL){
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__ - 2);
     }
     FUNC_MESS_END();
     return tmp;
}

static PyObject*  
PyGSL_multifit_fdfsolver_position(PyGSL_solver *self, PyObject *args)
{ 
     return PyGSL_solver_ret_vec(self, args, (ret_vec)gsl_multifit_fdfsolver_position); 
}
static gsl_multifit_fdfsolver *
PyGSL_get_multifit_solver(PyGSL_solver *self)
{
     FUNC_MESS_BEGIN();
     assert(PyGSL_solver_check(self));     
     FUNC_MESS_END();
     return (gsl_multifit_fdfsolver *) (self->solver);
}

static PyObject*  
PyGSL_multifit_fdfsolver_x(PyGSL_solver *self, PyObject *args)
{
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(PyGSL_get_multifit_solver(self)->x);
}

static PyObject*  
PyGSL_multifit_fdfsolver_dx(PyGSL_solver *self, PyObject *args)
{
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(PyGSL_get_multifit_solver(self)->dx);
}

static PyObject*  
PyGSL_multifit_fdfsolver_f(PyGSL_solver *self, PyObject *args)
{
     return (PyObject *) PyGSL_copy_gslvector_to_pyarray(PyGSL_get_multifit_solver(self)->f);
}

static PyObject*  
PyGSL_multifit_fdfsolver_J(PyGSL_solver *self, PyObject *args)
{
     return (PyObject *) PyGSL_copy_gslmatrix_to_pyarray(PyGSL_get_multifit_solver(self)->J);
}

static PyObject*  
PyGSL_multifit_fdfsolver_test_delta(PyGSL_solver *self, PyObject *args)
{
     int flag;
     double epsabs, epsrel;     
     gsl_multifit_fdfsolver *s = self->solver;     
     if(!PyArg_ParseTuple(args, "dd", &epsabs, &epsrel))
	  return NULL;
     flag = gsl_multifit_test_delta(s->dx, s->x, epsabs, epsrel);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}

static PyObject*  
PyGSL_multifit_fdfsolver_test_gradient(PyGSL_solver *self, PyObject *args)
{
     int flag;
     double epsabs;     
     gsl_vector *g = NULL;
     gsl_multifit_fdfsolver *s = self->solver;     

     if(!PyArg_ParseTuple(args, "d", &epsabs))
	  return NULL;
     flag = gsl_multifit_gradient(s->J, s->f, g);
     if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS)
	  return NULL;
     flag = gsl_multifit_test_gradient(g, epsabs);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}

static PyMethodDef PyGSL_multifit_fmethods[] = {     
     {NULL, NULL, 0, NULL}
};

static PyMethodDef PyGSL_multifit_fdfmethods[] = {     
     {"J",    (PyCFunction)PyGSL_multifit_fdfsolver_J,   METH_NOARGS, NULL},
     {"dx",   (PyCFunction)PyGSL_multifit_fdfsolver_dx,   METH_NOARGS, NULL},
     {"x",    (PyCFunction)PyGSL_multifit_fdfsolver_x,   METH_NOARGS, NULL},
     {"position",    (PyCFunction)PyGSL_multifit_fdfsolver_position,   METH_NOARGS, NULL},
     {"f",    (PyCFunction)PyGSL_multifit_fdfsolver_f,    METH_NOARGS, NULL},
     {"set",  (PyCFunction)PyGSL_multifit_fdfsolver_set,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"test_delta",  (PyCFunction)PyGSL_multifit_fdfsolver_test_delta,  METH_VARARGS, NULL},
     {"test_gradient",  (PyCFunction)PyGSL_multifit_fdfsolver_test_gradient,  METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};



const struct _SolverStatic
multifit_solver_f   = {{ (void_m_t) gsl_multifit_fsolver_free,   
			 /* gsl_multifit_fsolver_restart */  (void_m_t) NULL,
			 (name_m_t) gsl_multifit_fsolver_name,   
			 (int_m_t) gsl_multifit_fsolver_iterate},
		       1, PyGSL_multifit_fmethods, multifit_f_type_name},
multifit_solver_fdf = {{(void_m_t) gsl_multifit_fdfsolver_free, 
		     /* gsl_multifit_fdfsolver_restart (void_m_t) */ NULL,
		     (name_m_t) gsl_multifit_fdfsolver_name, 
		     (int_m_t)  gsl_multifit_fdfsolver_iterate},
		       3, PyGSL_multifit_fdfmethods, multifit_fdf_type_name};

static PyObject* 
PyGSL_multifit_f_init(PyObject *self, PyObject *args, 
		      const gsl_multifit_fsolver_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_multifit_fsolver_alloc,
			      &multifit_solver_f};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 2);
     FUNC_MESS_END();     
     return tmp;
}

static PyObject* 
PyGSL_multifit_fdf_init(PyObject *self, PyObject *args, 
		      const gsl_multifit_fdfsolver_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_multifit_fdfsolver_alloc,
			      &multifit_solver_fdf};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 2);
     FUNC_MESS_END();     
     return tmp;
}

#define AMFIT_FDF(name)                                                  \
static PyObject* PyGSL_multifit_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_multifit_fdf_init(self, args,  gsl_multifit_fdfsolver_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}

AMFIT_FDF(lmsder)
AMFIT_FDF(lmder)

PyObject * 
PyGSL_multifit_gradient(PyObject *self, PyObject *args)
{
  PyArrayObject *J_a = NULL, *f_a = NULL, *g_a = NULL;
  PyObject *J_o = NULL, *f_o = NULL;
  gsl_vector_view f;
  gsl_vector_view g;
  gsl_matrix_view J;

  PyGSL_array_index_t stride_recalc, dimension;
  int flag;

  if(!PyArg_ParseTuple(args, "OO:gsl_multifit_gradient", &J_o, &f_o)){
       return NULL;
  }

  J_a = PyGSL_matrix_check(J_o, -1, -1, PyGSL_DARRAY_CINPUT(1), NULL, NULL, NULL);
  if(J_a == NULL) goto fail;

  dimension = J_a->dimensions[0];
  /* Numpy calculates strides in bytes, gsl in basis type */
  f_a = PyGSL_vector_check(f_o, dimension, PyGSL_DARRAY_INPUT(2), &stride_recalc, NULL);
  if(f_a == NULL) goto fail;

  dimension = J_a->dimensions[1];
  g_a = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
  if(g_a == NULL) goto fail;

  J = gsl_matrix_view_array((double *) J_a->data, J_a->dimensions[0], J_a->dimensions[1]);
  f = gsl_vector_view_array_with_stride((double *) f_a->data, stride_recalc, f_a->dimensions[0]);
  g = gsl_vector_view_array((double *) g_a->data, dimension);
  flag = gsl_multifit_gradient(&J.matrix, &f.vector, &g.vector);
  
  Py_DECREF(J_a);
  Py_DECREF(f_a);
  
  if((PyGSL_ERROR_FLAG(flag)) != GSL_SUCCESS)
       goto fail;

  return (PyObject * )g_a;

  fail :
    Py_XDECREF(J_a);
    Py_XDECREF(f_a);
    Py_XDECREF(g_a);
    return NULL;
}

PyObject * 
PyGSL_multifit_covar(PyObject *self, PyObject *args)
{
  PyArrayObject *J_a = NULL, *C_a = NULL;
  PyObject *J_o = NULL;
  gsl_matrix_view J, C;
  PyGSL_array_index_t dimensions[2];
  int flag;
  double epsrel;


  if(!PyArg_ParseTuple(args, "Od:gsl_multifit_covar", &J_o, &epsrel)){
    return NULL;
  }

  J_a = PyGSL_matrix_check(J_o, -1, -1, PyGSL_DARRAY_CINPUT(1), NULL, NULL, NULL);
  if(J_a == NULL) goto fail;

  dimensions[0] = J_a->dimensions[1];
  dimensions[1] = J_a->dimensions[1];
  C_a = (PyArrayObject *) PyGSL_New_Array(2, dimensions, PyArray_DOUBLE);
  if(C_a == NULL) goto fail;

  J = gsl_matrix_view_array((double *) J_a->data, J_a->dimensions[0], J_a->dimensions[1]);
  C = gsl_matrix_view_array((double *) C_a->data, C_a->dimensions[0], C_a->dimensions[1]);
  
  flag = gsl_multifit_covar(&J.matrix, epsrel, &C.matrix);
  
  Py_DECREF(J_a);
  if((PyGSL_ERROR_FLAG(flag)) != GSL_SUCCESS)
       goto fail;
  return (PyObject * )C_a;

  fail :
    Py_XDECREF(J_a);
    Py_XDECREF(C_a);
    return NULL;
}

static PyObject *
PyGSL_multifit_test_delta(PyObject * self, PyObject * args)
{
     return PyGSL_solver_vvdd_i(self, args, gsl_multifit_test_delta);     
}

static PyObject *
PyGSL_multifit_test_gradient(PyObject * self, PyObject * args)
{
     return PyGSL_solver_vd_i(self, args, gsl_multifit_test_gradient);     
}

static PyMethodDef mMethods[] = {
     /* multifit solvers */
     {"lmder",          PyGSL_multifit_init_lmder,  METH_VARARGS, NULL},
     {"lmsder",          PyGSL_multifit_init_lmsder,  METH_VARARGS, NULL},
     /* multifit funcs */
     {"fit_test_delta",    PyGSL_multifit_test_delta,     METH_VARARGS, NULL},
     {"fit_test_gradient", PyGSL_multifit_test_gradient,  METH_VARARGS, NULL},
     {"gradient",          PyGSL_multifit_gradient,  METH_VARARGS, NULL},
     {"covar",             PyGSL_multifit_covar,  METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};

static const char PyGSL_multifit_nlin_module_doc[] = "XXX Missing \n";
void
initmultifit_nlin(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("multifit_nlin", mMethods);
     module = m;
     assert(m);
     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     init_pygsl()
     import_pygsl_solver();
     assert(PyGSL_API);


     if (!(item = PyString_FromString((char*)PyGSL_multifit_nlin_module_doc))){
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
     return;

 fail:
     FUNC_MESS("FAIL");
     return;
}
