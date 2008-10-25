#include <pygsl/solver.h>
#include <gsl/gsl_multiroots.h>

static PyObject * module = NULL;

/* accessor methods */
#define _SOLVER_METH(solver, name) \
static PyObject*  \
PyGSL_multiroot_ ## solver ## _ ## name(PyGSL_solver *self, PyObject *args) \
{ return PyGSL_solver_ret_vec(self, args, (ret_vec)gsl_multiroot_## solver ## _ ## name); }

#define FSOLVER(name)   _SOLVER_METH(fsolver, name)
#define FDFSOLVER(name) _SOLVER_METH(fdfsolver, name)
#define BSOLVER_METH(name) _SOLVER_METH(fsolver, name) _SOLVER_METH(fdfsolver, name)
BSOLVER_METH(root)
BSOLVER_METH(f)
BSOLVER_METH(dx)

static PyObject* 
PyGSL_multiroot_fsolver_test_residual(PyGSL_solver *self, PyObject *args)
{
     int flag;
     double epsabs;     
     gsl_multiroot_fsolver *s = self->solver;     
     if(!PyArg_ParseTuple(args, "d", &epsabs))
	  return NULL;
     flag = gsl_multiroot_test_residual(s->f, epsabs);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}
static PyObject* 
PyGSL_multiroot_fdfsolver_test_residual(PyGSL_solver *self, PyObject *args)
{
     int flag;
     double epsabs;     
     gsl_multiroot_fdfsolver *s = self->solver;     
     if(!PyArg_ParseTuple(args, "d", &epsabs))
	  return NULL;
     flag = gsl_multiroot_test_residual(s->f, epsabs);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}

static PyObject* 
PyGSL_multiroot_fsolver_test_delta(PyGSL_solver *self, PyObject *args)
{
     int flag;
     double epsabs, epsrel;     
     gsl_multiroot_fsolver *s = self->solver;     
     if(!PyArg_ParseTuple(args, "dd", &epsabs, &epsrel))
	  return NULL;
     flag = gsl_multiroot_test_delta(s->dx, s->x, epsabs, epsrel);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}
static PyObject* 
PyGSL_multiroot_fdfsolver_test_delta(PyGSL_solver *self, PyObject *args)
{
     int flag;
     double epsabs, epsrel;     
     gsl_multiroot_fdfsolver *s = self->solver;     
     if(!PyArg_ParseTuple(args, "dd", &epsabs, &epsrel))
	  return NULL;
     flag = gsl_multiroot_test_delta(s->dx, s->x, epsabs, epsrel);
     return PyGSL_ERROR_FLAG_TO_PYINT(flag);
}
int 
PyGSL_multiroot_function_wrap(const gsl_vector *x, void *params, gsl_vector *f)
{
     int flag;
     PyGSL_solver *p = (PyGSL_solver *) params;
     FUNC_MESS_BEGIN();
     if(PyGSL_DEBUG_LEVEL() > 2){
       gsl_vector_fprintf(stderr, x, "x = %d");
     }
     flag =  PyGSL_function_wrap_Op_On(x, f, p->cbs[0], p->args, x->size, 
				       x->size, __FUNCTION__);
     FUNC_MESS_END();
     return flag;
}


int 
PyGSL_multiroot_function_wrap_df(const gsl_vector *x, void *params, gsl_matrix *J)
{
     int flag;
     PyGSL_solver *p = (PyGSL_solver *) params;
     FUNC_MESS_BEGIN();
     flag =  PyGSL_function_wrap_Op_Opn(x, J, p->cbs[1], p->args, x->size, x->size,
					__FUNCTION__);
     FUNC_MESS_END();
     return flag;
}

int 
PyGSL_multiroot_function_wrap_fdf(const gsl_vector *x, void *params, gsl_vector *f, gsl_matrix *J)
{
     int flag;
     PyGSL_solver *p = (PyGSL_solver *) params;
     FUNC_MESS_BEGIN();
     flag = PyGSL_function_wrap_Op_On_Opn(x, f, J, p->cbs[2], p->args, x->size, x->size,
					  __FUNCTION__);
     FUNC_MESS_END();
     return flag;
}




PyObject *
PyGSL_multiroot_fsolver_set(PyGSL_solver *self, PyObject *pyargs, PyObject *kw)
{

     gsl_multiroot_function * c_sys;
     struct pygsl_solver_n_set info = {0, NULL, (set_m_t) gsl_multiroot_fsolver_set};
     PyObject * tmp;

     FUNC_MESS_BEGIN();
     if(self->c_sys == NULL){	  
	  if((c_sys = calloc(1, sizeof(gsl_multiroot_function))) == NULL){
	       PyGSL_ERROR_NULL("Could not allocate the memory for the c_sys", GSL_ENOMEM);
	  }	  
	  c_sys->n =self->problem_dimensions[0];
	  c_sys->f =PyGSL_multiroot_function_wrap;
	  c_sys->params=(void*)self;
	  info.c_sys = c_sys;	  
     }else{
	  info.c_sys = self->c_sys;
     }
     tmp =  PyGSL_solver_n_set(self, pyargs, kw, &info);
     FUNC_MESS_END();
     return tmp;
}

PyObject *
PyGSL_multiroot_fdfsolver_set(PyGSL_solver *self, PyObject *pyargs, PyObject *kw)
{

     gsl_multiroot_function_fdf * c_sys;
     struct pygsl_solver_n_set info = {1, NULL, (set_m_t)gsl_multiroot_fdfsolver_set};
     PyObject * tmp;

     FUNC_MESS_BEGIN();
     if(self->c_sys == NULL){	  
	  if((c_sys = calloc(1, sizeof(gsl_multiroot_function_fdf))) == NULL){
	       PyGSL_ERROR_NULL("Could not allocate the memory for the c_sys", GSL_ENOMEM);
	  }	  
	  c_sys->n=self->problem_dimensions[0];
	  c_sys->f  = PyGSL_multiroot_function_wrap;
	  c_sys->df = PyGSL_multiroot_function_wrap_df;
	  c_sys->fdf = PyGSL_multiroot_function_wrap_fdf;
	  c_sys->params=(void*)self;
	  info.c_sys = c_sys;	  
     }else{
	  info.c_sys = self->c_sys;
     }
     tmp = PyGSL_solver_n_set(self, pyargs, kw, &info);     
     FUNC_MESS_END();
     return tmp;
}


static PyMethodDef PyGSL_multiroot_fmethods[] = {     
     {"dx",   (PyCFunction)PyGSL_multiroot_fsolver_dx,   METH_NOARGS, NULL},
     {"f",    (PyCFunction)PyGSL_multiroot_fsolver_f,    METH_NOARGS, NULL},
     {"root", (PyCFunction)PyGSL_multiroot_fsolver_root, METH_NOARGS, NULL},
     {"set",  (PyCFunction)PyGSL_multiroot_fsolver_set,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"test_delta",    (PyCFunction)PyGSL_multiroot_fsolver_test_delta, METH_VARARGS, NULL},
     {"test_residual", (PyCFunction)PyGSL_multiroot_fsolver_test_residual, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};

static PyMethodDef PyGSL_multiroot_fdfmethods[] = {     
     {"dx",            (PyCFunction)PyGSL_multiroot_fdfsolver_dx,   METH_NOARGS, NULL},
     {"f",             (PyCFunction)PyGSL_multiroot_fdfsolver_f,    METH_NOARGS, NULL},
     {"root",          (PyCFunction)PyGSL_multiroot_fdfsolver_root, METH_NOARGS, NULL},
     {"set",           (PyCFunction)PyGSL_multiroot_fdfsolver_set,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"test_delta",    (PyCFunction)PyGSL_multiroot_fdfsolver_test_delta, METH_VARARGS, NULL},
     {"test_residual", (PyCFunction)PyGSL_multiroot_fdfsolver_test_residual, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};


static const char multiroot_f_type_name[] = "F-MultiRootSolver";
static const char multiroot_fdf_type_name[] = "FdF-MultiRootSolver";

const struct _SolverStatic
multiroot_solver_f   = {{(void_m_t) gsl_multiroot_fsolver_free,   
			/* gsl_multiroot_fsolver_restart */  (void_m_t) NULL,
			(name_m_t) gsl_multiroot_fsolver_name,   
			 (int_m_t) gsl_multiroot_fsolver_iterate},
			1, PyGSL_multiroot_fmethods, multiroot_f_type_name},
multiroot_solver_fdf = {{(void_m_t) gsl_multiroot_fdfsolver_free, 
			 /* gsl_multiroot_fdfsolver_restart (void_m_t) */ NULL,
			 (name_m_t) gsl_multiroot_fdfsolver_name, 
			 (int_m_t)  gsl_multiroot_fdfsolver_iterate},
			3, PyGSL_multiroot_fdfmethods, multiroot_fdf_type_name};


static PyObject* 
PyGSL_multiroot_f_init(PyObject *self, PyObject *args, 
		      const gsl_multiroot_fsolver_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_multiroot_fsolver_alloc,
			      &multiroot_solver_f};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 1);
     FUNC_MESS_END();     
     return tmp;
}

static PyObject* 
PyGSL_multiroot_fdf_init(PyObject *self, PyObject *args, 
		      const gsl_multiroot_fdfsolver_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_multiroot_fdfsolver_alloc,
			      &multiroot_solver_fdf};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 1);
     FUNC_MESS_END();     
     return tmp;
}

#define AMROOTS_F(name)                                                  \
static PyObject* PyGSL_multiroot_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_multiroot_f_init(self, args,  gsl_multiroot_fsolver_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}

#define AMROOTS_FDF(name)                                                  \
static PyObject* PyGSL_multiroot_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_multiroot_fdf_init(self, args,  gsl_multiroot_fdfsolver_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}

AMROOTS_F(dnewton)
AMROOTS_F(broyden)
AMROOTS_F(hybrid)
AMROOTS_F(hybrids)

AMROOTS_FDF(newton)
AMROOTS_FDF(gnewton)
AMROOTS_FDF(hybridj)
AMROOTS_FDF(hybridsj)

static PyObject *
PyGSL_multiroot_test_delta(PyObject * self, PyObject * args)
{
     return PyGSL_solver_vvdd_i(self, args, gsl_multiroot_test_delta);     
}

static PyObject *
PyGSL_multiroot_test_residual(PyObject * self, PyObject * args)
{
     return PyGSL_solver_vd_i(self, args, gsl_multiroot_test_residual);     
}



static PyMethodDef mMethods[] = {
     /* solvers */
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
     {NULL, NULL, 0, NULL}
};

static const char PyGSL_multiroot_module_doc[] = "XXX Missing\n";

void
initmultiroot(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("multiroot", mMethods);
     module = m;
     assert(m);

     init_pygsl()
     import_pygsl_solver();
     assert(PyGSL_API);

     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     if (!(item = PyString_FromString((char*)PyGSL_multiroot_module_doc))){
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

