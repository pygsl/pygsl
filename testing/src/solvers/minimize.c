#include <pygsl/solver.h>
#include <gsl/gsl_min.h>

static const char min_f_type_name[] = "F-Minimizer";
static const char min_x_minimum_doc[]= ""; 	
static const char min_x_lower_doc[]= ""; 	
static const char min_x_upper_doc[]= ""; 	
static const char min_f_minimum_doc[]= ""; 	
static const char min_f_lower_doc[]= ""; 	
static const char min_f_upper_doc[]= ""; 	
static const char min_test_delta_doc[]= ""; 
static const char min_set_f_doc[]= "";
 
static const char min_init_brent_doc[]= ""; 
static const char min_init_goldensection_doc[]= ""; 

const char  * filename = __FILE__;
PyObject *module = NULL;

static PyObject* 
PyGSL_min_f_minimum(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_min_fminimizer_f_minimum);
}

static PyObject* 
PyGSL_min_f_lower(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_min_fminimizer_f_lower);
}

static PyObject* 
PyGSL_min_f_upper(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_min_fminimizer_f_upper);
}

static PyObject* 
PyGSL_min_x_minimum(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_min_fminimizer_x_minimum);
}

static PyObject* 
PyGSL_min_x_lower(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_min_fminimizer_x_lower);
}

static PyObject* 
PyGSL_min_x_upper(PyGSL_solver *self, PyObject *args) 
{
     return PyGSL_solver_ret_double(self, args, (double_m_t) gsl_min_fminimizer_x_upper);
}

static PyObject*
PyGSL_min_solver_test_interval(PyGSL_solver * self, PyObject *args)
{
     double epsabs, epsrel;
     gsl_min_fminimizer *s = (gsl_min_fminimizer *) self->solver;
     if(!PyArg_ParseTuple(args, "dd", &epsabs, &epsrel))
	  return NULL;
     return PyInt_FromLong(gsl_min_test_interval(s->x_lower, s->x_upper, epsabs, epsrel));
}


static PyObject* 
PyGSL_min_set_f(PyGSL_solver *self, PyObject *args, PyObject *kw) 
{
     return PyGSL_solver_set_f(self, args, kw,  (void *)gsl_min_fminimizer_set, 0); 
}

static PyMethodDef PyGSL_min_fmethods[] = {     
     {"x_minimum", (PyCFunction)PyGSL_min_x_minimum,  METH_NOARGS, (char *)min_x_minimum_doc}, 
     {"x_lower",   (PyCFunction)PyGSL_min_x_lower,    METH_NOARGS, (char *)min_x_lower_doc}, 
     {"x_upper",   (PyCFunction)PyGSL_min_x_upper,    METH_NOARGS, (char *)min_x_upper_doc}, 
     {"f_minimum", (PyCFunction)PyGSL_min_f_minimum,  METH_NOARGS, (char *)min_f_minimum_doc}, 
     {"f_lower",   (PyCFunction)PyGSL_min_f_lower,    METH_NOARGS, (char *)min_f_lower_doc}, 
     {"f_upper",   (PyCFunction)PyGSL_min_f_upper,    METH_NOARGS, (char *)min_f_upper_doc}, 
     {"set",       (PyCFunction)PyGSL_min_set_f,    METH_VARARGS|METH_KEYWORDS, (char *)min_set_f_doc}, 
     {"test_interval",(PyCFunction)PyGSL_min_solver_test_interval, METH_VARARGS, NULL},      
     {NULL, NULL, 0, NULL}           /* sentinel */
};



const struct _SolverStatic
min_solver_f = {{(void_m_t) gsl_min_fminimizer_free,   
		 /* gsl_multimin_fminimizer_restart */  (void_m_t) NULL,
		 (name_m_t) gsl_min_fminimizer_name,   
		 (int_m_t) gsl_min_fminimizer_iterate},
		1, PyGSL_min_fmethods, min_f_type_name};

static PyObject* 
PyGSL_min_f_init(PyObject *self, PyObject *args, 
		 const gsl_min_fminimizer_type * type) 
{

     PyObject *tmp=NULL;
     solver_alloc_struct s = {type, (void_an_t) gsl_min_fminimizer_alloc,
			      &min_solver_f};
     FUNC_MESS_BEGIN();     
     tmp = PyGSL_solver_dn_init(self, args, &s, 0);
     FUNC_MESS_END();     
     return tmp;
}

#define AMIN_F(name)                                                  \
static PyObject* PyGSL_min_init_ ## name (PyObject *self, PyObject *args)\
{                                                                             \
     PyObject *tmp = NULL;                                                    \
     FUNC_MESS_BEGIN();                                                       \
     tmp = PyGSL_min_f_init(self, args,  gsl_min_fminimizer_ ## name); \
     if (tmp == NULL){                                                        \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__); \
     }                                                                        \
     FUNC_MESS_END();                                                         \
     return tmp;                                                              \
}
AMIN_F(brent)
AMIN_F(goldensection)

static PyObject*
PyGSL_min_test_interval(PyObject * self, PyObject *args)
{
     double x_lower, x_upper, epsabs, epsrel;
     if(!PyArg_ParseTuple(args, "dddd", &x_lower, &x_upper, &epsabs, &epsrel))
	  return NULL;
     return PyInt_FromLong(gsl_min_test_interval(x_lower, x_upper, epsabs, epsrel));
}

static const char PyGSL_minimize_module_doc [] = "XXX Missing ";
static PyMethodDef mMethods[] = {
     /* solvers */
     {"brent",        PyGSL_min_init_brent, METH_NOARGS, (char *)min_init_brent_doc}, 
     {"goldensection",PyGSL_min_init_goldensection, METH_NOARGS, (char *)min_init_goldensection_doc}, 
     /* min methods */
     {"test_interval",   PyGSL_min_test_interval, METH_VARARGS, (char *)min_test_delta_doc},
     {NULL, NULL, 0, NULL}
};

void
initminimize(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("minimize", mMethods);
     import_pygsl_solver();
     assert(PyGSL_API);

     module = m;
     assert(m);
     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     if (!(item = PyString_FromString((char*)PyGSL_minimize_module_doc))){
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
