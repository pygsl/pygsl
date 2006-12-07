#include <pygsl/solver.h>
#include <gsl/gsl_roots.h>


const char  * filename = __FILE__;
PyObject *module = NULL;

static const char root_f_type_name[] = "F-RootSolver";
static const char root_fdf_type_name[] = "FdF-RootSolver";
static const char root_f_root_doc[] = "Get the value of F";
static const char root_set_f_doc[] = "";
static const char root_set_fdf_doc[] = "";
static const char root_fdf_root_doc[] = "";
static const char root_x_lower_doc  [] = "Get the lower bound of x";
static const char root_x_upper_doc  [] = "Get the upper bound of x"; 

static PyObject* 
PyGSL_root_f_root(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_root_fsolver_root);
}

static PyObject* 
PyGSL_root_fdf_root(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_root_fdfsolver_root);
}

static PyObject* 
PyGSL_root_x_lower(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_root_fsolver_x_lower);
}

static PyObject* 
PyGSL_root_x_upper(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_root_fsolver_x_upper);
}

static PyObject*
PyGSL_root_solver_test_interval(PyGSL_solver * self, PyObject *args)
{
     double epsabs, epsrel;
     gsl_root_fsolver *s = (gsl_root_fsolver *) self->solver;
     if(!PyArg_ParseTuple(args, "dd", &epsabs, &epsrel))
	  return NULL;
     return PyInt_FromLong(gsl_root_test_interval(s->x_lower, s->x_upper, epsabs, epsrel));
}

static PyObject* 
PyGSL_root_set_f(PyGSL_solver *self, PyObject *args, PyObject *kw) 
{
     return PyGSL_solver_set_f(self, args, kw, (void *)gsl_root_fsolver_set, 0); 
}

static PyObject* 
PyGSL_root_set_fdf(PyGSL_solver *self, PyObject *args, PyObject *kw) 
{
     return PyGSL_solver_set_f(self, args, kw,  (void *)gsl_root_fdfsolver_set, 1); 
}

static PyMethodDef PyGSL_root_fmethods[] = {     
     {"root",      (PyCFunction)PyGSL_root_f_root,     METH_NOARGS, (char *)root_f_root_doc}, 
     {"x_lower",   (PyCFunction)PyGSL_root_x_lower,    METH_NOARGS, (char *)root_x_lower_doc}, 
     {"x_upper",   (PyCFunction)PyGSL_root_x_upper,    METH_NOARGS, (char *)root_x_upper_doc}, 
     {"set",       (PyCFunction)PyGSL_root_set_f,      METH_VARARGS|METH_KEYWORDS, (char *)root_set_f_doc}, 
     {"test_interval",(PyCFunction)PyGSL_root_solver_test_interval, METH_VARARGS, NULL},      
     {NULL, NULL, 0, NULL}           /* sentinel */
};
static PyMethodDef PyGSL_root_fdfmethods[] = {     
     {"root",      (PyCFunction)PyGSL_root_fdf_root,     METH_NOARGS, (char *)root_fdf_root_doc}, 
     {"set",       (PyCFunction)PyGSL_root_set_fdf,      METH_VARARGS|METH_KEYWORDS, (char *)root_set_fdf_doc}, 
     {NULL, NULL, 0, NULL}           /* sentinel */
};


const struct _SolverStatic 
root_solver_f = {{(void_m_t) gsl_root_fsolver_free,   
		  /* gsl_multimin_fminimizer_restart */  (void_m_t) NULL,
		  (name_m_t) gsl_root_fsolver_name,   
		  (int_m_t) gsl_root_fsolver_iterate},
		 1, PyGSL_root_fmethods, root_f_type_name},
root_solver_fdf = {{(void_m_t) gsl_root_fdfsolver_free,   
		    /* gsl_multimin_fminimizer_restart */  (void_m_t) NULL,
		    (name_m_t) gsl_root_fdfsolver_name,   
		     (int_m_t) gsl_root_fdfsolver_iterate},
		   3, PyGSL_root_fdfmethods, root_fdf_type_name};

static PyObject* 
PyGSL_root_f_init(PyObject *self, PyObject *args, 
		 const gsl_root_fsolver_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_root_fsolver_alloc,
			      &root_solver_f};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 0);
     FUNC_MESS_END();     
     return tmp;
}

static PyObject* 
PyGSL_root_fdf_init(PyObject *self, PyObject *args, 
		 const gsl_root_fdfsolver_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_root_fdfsolver_alloc,
			      &root_solver_fdf};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 0);
     FUNC_MESS_END();     
     return tmp;
}

#define AROOT_F(name)                                                  \
static PyObject* PyGSL_root_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_root_f_init(self, args,  gsl_root_fsolver_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}
#define AROOT_FDF(name)                                                  \
static PyObject* PyGSL_root_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_root_fdf_init(self, args,  gsl_root_fdfsolver_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}
AROOT_F(bisection)
AROOT_F(falsepos)
AROOT_F(brent)
AROOT_FDF(newton)
AROOT_FDF(secant)
AROOT_FDF(steffenson)


static PyObject*
PyGSL_root_test_delta(PyObject * self, PyObject *args)
{
     double x_lower, x_upper, epsabs, epsrel;
     if(!PyArg_ParseTuple(args, "dddd", &x_lower, &x_upper, &epsabs, &epsrel))
	  return NULL;
     return PyInt_FromLong(gsl_root_test_delta(x_lower, x_upper, epsabs, epsrel));
}

static PyObject*
PyGSL_root_test_interval(PyObject * self, PyObject *args)
{
     double x_lower, x_upper, epsabs, epsrel;
     if(!PyArg_ParseTuple(args, "dddd", &x_lower, &x_upper, &epsabs, &epsrel))
	  return NULL;
     return PyInt_FromLong(gsl_root_test_interval(x_lower, x_upper, epsabs, epsrel));
}

static const char PyGSL_roots_module_doc [] = "XXX Missing ";
static PyMethodDef mMethods[] = {
     /* solver */
     {"bisection",  PyGSL_root_init_bisection, METH_NOARGS, NULL},
     {"falsepos",  PyGSL_root_init_falsepos, METH_NOARGS, NULL},
     {"brent",  PyGSL_root_init_brent, METH_NOARGS, NULL},
     {"newton",  PyGSL_root_init_newton, METH_NOARGS, NULL},
     {"secant",  PyGSL_root_init_secant, METH_NOARGS, NULL},
     {"steffenson",  PyGSL_root_init_steffenson, METH_NOARGS, NULL},
     /* functions */
     {"test_delta",  PyGSL_root_test_delta, METH_VARARGS, NULL},
     {"test_interval",  PyGSL_root_test_interval, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};

void
initroots(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("roots", mMethods);
     module = m;
     assert(m);
     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     init_pygsl()
     import_pygsl_solver();
     assert(PyGSL_API);


     if (!(item = PyString_FromString((char*)PyGSL_roots_module_doc))){
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
