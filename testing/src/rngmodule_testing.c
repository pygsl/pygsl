/*
 *  A rng module implementation which can return a sample as an array.
 *  Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 *  Date   : 1. July. 2003
 *
 */
#include <pygsl/utils.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <pygsl/rng.h>
#include <pygsl/rng_helpers.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/*
 * All doc strings
 */
#include "rngmodule_docs.h"

static PyObject *module = NULL;

static void			/* generic instance destruction */
generic_dealloc (PyObject *self)
{
  DEBUG_MESS(1, " *** generic_dealloc %p\n", (void *) self);
  PyMem_Free(self);
}

static char  PyGSL_rng_type_type_doc[] = "A GSL rng type. GSL provides "\
"different types of random generators. These types are wrapped here.";

/*---------------------------------------------------------------------------*/
/* encapsulation for the PyGSL_rng_type */
typedef struct {
  PyObject_HEAD
  gsl_rng_type * rng_type;
} PyGSL_rng_type;


/*
 * I prefer a seperate type here as it allows to check for the type in C. Do 
 * not like to end in nirvana, when I try to find a pointer to a gsl_rng_type.
 */
static PyTypeObject PyGSL_rng_type_pytype = {
  PyObject_HEAD_INIT(NULL)	/* fix up the type slot in initcrng */
  0,				/* ob_size */
  "PyGSL_rng_type",     	/* tp_name */
  sizeof(PyGSL_rng_type),       /* tp_basicsize */
  0,				/* tp_itemsize */

  /* standard methods */
  (destructor)  generic_dealloc,   /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		   /* tp_print    "print x"     */
  (getattrfunc) 0,                 /* tp_getattr  "x.attr"      */
  (setattrfunc) 0,		   /* tp_setattr  "x.attr=v"    */
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */

  /* type categories */
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/
  0,				/* tp_as_mapping  [key], len, ...*/

  /* more methods */
  (hashfunc)     0,		/* tp_hash    "dict[x]" */
  (ternaryfunc)  0,             /* tp_call    "x()"     */
  (reprfunc)     0,             /* tp_str     "str(x)"  */
  (getattrofunc) 0,		/* tp_getattro */
  (setattrofunc) 0,		/* tp_setattro */
  0,				/* tp_as_buffer */
  0L,				/* tp_flags */
  PyGSL_rng_type_type_doc       /* tp_doc */
};

#define PyGSLRngType_Check(v) ((v)->ob_type == &PyGSL_rng_type_pytype)


/*---------------------------------------------------------------------------*/
/* rng */

staticforward PyTypeObject PyGSL_rng_pytype;
#if 0
typedef struct {
  PyObject_HEAD
  gsl_rng * rng;
} PyGSL_rng;
#endif 
static void rng_delete(PyGSL_rng *self);
static PyObject * rng_call(PyGSL_rng *self, PyObject *args);


static PyObject *		/* on "instance.attr" */
rng_getattr (PyGSL_rng *self, char *name);


static PyTypeObject PyGSL_rng_pytype = {
  PyObject_HEAD_INIT(NULL)	/* fix up the type slot in initcrng */
  0,				/* ob_size */
  "PyGSL_rng",			/* tp_name */
  sizeof(PyGSL_rng),	        /* tp_basicsize */
  0,				/* tp_itemsize */

  /* standard methods */
  (destructor)  rng_delete,       /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		   /* tp_print    "print x"     */
  (getattrfunc) rng_getattr,       /* tp_getattr  "x.attr"      */
  (setattrfunc) 0,		   /* tp_setattr  "x.attr=v"    */
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */

  /* type categories */
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/
  0,				/* tp_as_mapping  [key], len, ...*/

  /* more methods */
  (hashfunc)     0,		/* tp_hash    "dict[x]" */
  (ternaryfunc)  rng_call,      /* tp_call    "x()"     */
  (reprfunc)     0,             /* tp_str     "str(x)"  */
  (getattrofunc) 0,		/* tp_getattro */
  (setattrofunc) 0,		/* tp_setattro */
  0,				/* tp_as_buffer */
  0L,				/* tp_flags */
  rng_type_doc		/* tp_doc */
};


#define PyGSLRng_Check(v) ((v)->ob_type == &PyGSL_rng_pytype)


PyObject *
rng_init(PyObject *self, PyObject *args)
{
     PyObject *type = NULL;
     PyGSL_rng *rng = NULL;

     FUNC_MESS_BEGIN();
     assert(args);
     if (0 == PyArg_ParseTuple(args, "|O!:rng.__init__", 
			       &PyGSL_rng_type_pytype, &type)){
	  PyGSL_add_traceback(module, __FILE__, "rng.__init__", __LINE__ - 2);
	  return NULL;
     }     
     rng =  (PyGSL_rng *) PyObject_NEW(PyGSL_rng, &PyGSL_rng_pytype);
     if(type == NULL){
	  rng->rng = gsl_rng_alloc(gsl_rng_default);
	  gsl_rng_set(rng->rng, gsl_rng_default_seed);
     }else{
	  rng->rng = gsl_rng_alloc(((PyGSL_rng_type *)type)->rng_type);
     }
     FUNC_MESS_END();
     return (PyObject *) rng;
}

static void
rng_delete(PyGSL_rng *self)
{
     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     gsl_rng_free(self->rng);
     DEBUG_MESS(1, " self %p\n",(void *) self);
     PyMem_Free(self);
     FUNC_MESS_END();
}

static PyObject *		/* on "instance.uniform()" and "instance()" */
rng_call (PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     tmp = PyGSL_rng_to_double(self, args, gsl_rng_uniform);
     if(!tmp)
	  PyGSL_add_traceback(module, __FILE__, "rng.__call__", __LINE__ - 2);
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_uniform_pos (PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     tmp = PyGSL_rng_to_double(self, args, gsl_rng_uniform_pos);
     if(!tmp)
	  PyGSL_add_traceback(module, __FILE__, "rng.uniform_pos", __LINE__-2);
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_uniform_int (PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp = NULL;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     tmp = PyGSL_rng_ul_to_ulong(self, args, gsl_rng_uniform_int);
     if(!tmp)
	  PyGSL_add_traceback(module, __FILE__, "rng.uniform_int", __LINE__-2);
     FUNC_MESS_END();
     return tmp;
}



static PyObject *
rng_get(PyGSL_rng *self, PyObject *args)
{
     PyObject  *tmp = NULL;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     tmp = PyGSL_rng_to_ulong(self, args, gsl_rng_get);
     if(!tmp)
	  PyGSL_add_traceback(module, __FILE__, "rng.get", __LINE__ - 2);
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_set(PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp = NULL, *seed = NULL;
     unsigned long int useed;
     int lineno;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     if(0 == PyArg_ParseTuple(args, "O", &tmp)){
	  lineno = __LINE__; goto fail;
     }
     assert(tmp != NULL);
     seed = PyNumber_Long(tmp);
     if(!seed){lineno = __LINE__ - 1; goto fail;}
     useed =  PyLong_AsUnsignedLong(seed);
     gsl_rng_set(self->rng, useed);
     
     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, "rng.set", lineno);
     return NULL;
}

static PyObject *
rng_name(PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp = NULL;
     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":name"))
	  return NULL;
     tmp = PyString_FromString(gsl_rng_name(self->rng));
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_max(PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp = NULL;
     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":max"))
	  return NULL;
     tmp = PyLong_FromUnsignedLong(gsl_rng_max(self->rng));
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_min(PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp = NULL;
     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":min"))
	  return NULL;
     tmp = PyLong_FromUnsignedLong(gsl_rng_min(self->rng));
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_clone(PyGSL_rng *self, PyObject *args)
{
     PyGSL_rng * rng = NULL;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":clone"))
	  return NULL;
     rng =  (PyGSL_rng *) PyObject_NEW(PyGSL_rng, &PyGSL_rng_pytype);
     rng->rng = gsl_rng_clone(self->rng);
     FUNC_MESS_END();
     return (PyObject *) rng;
}

/*
 * Is #name a standard macro definition?
 */
#define RNG_DISTRIBUTION(name, function)                                     \
static PyObject* rng_ ## name (PyGSL_rng *self, PyObject *args)              \
{                                                                            \
     PyObject *tmp = NULL;                                                   \
     FUNC_MESS_BEGIN();                                                      \
     tmp = PyGSL_rng_ ## function (self, args,  gsl_ran_ ## name);           \
     if (tmp == NULL){                                                       \
       /* PyGSL_add_traceback(module, __FILE__, "rng." #name, __LINE__); */  \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);     \
     }                                                                       \
     FUNC_MESS_END();                                                        \
     return tmp;                                                             \
}

#include "rng_distributions.h"

/* Redefine to trigger emacs into correct coloring */
/*
 * This list is not optimized. I guess... Do you know how to optimize it?
 */
static struct PyMethodDef rng_methods[] = {
  {"get", (PyCFunction) rng_get, METH_VARARGS, rng_get_doc},
  {"set", (PyCFunction) rng_set, METH_VARARGS, rng_set_doc},
  {"uniform", (PyCFunction) rng_call, METH_VARARGS, rng_uniform_doc},
  {"uniform_pos", (PyCFunction) rng_uniform_pos, METH_VARARGS, rng_uniform_pos_doc},
  {"uniform_int", (PyCFunction) rng_uniform_int, METH_VARARGS, rng_uniform_int_doc},
  {"name", (PyCFunction) rng_name, METH_VARARGS, NULL},
  {"max", (PyCFunction) rng_max, METH_VARARGS, rng_max_doc},
  {"min", (PyCFunction) rng_min, METH_VARARGS, rng_min_doc},
  {"clone", (PyCFunction) rng_clone, METH_VARARGS, rng_clone_doc},
#if  (PY_MAJOR_VERSION == 2) && (PY_MINOR_VERSION == 3)
  /* RNG clone can not be used to copy a rng type in python 2.3 No idea how to do that correctly */
#else
  {"__copy__", (PyCFunction) rng_clone, METH_VARARGS, rng_clone_doc},
#endif
  /* distributions */
  {"gaussian", (PyCFunction) rng_gaussian,METH_VARARGS, rng_gaussian_doc},
  {"gaussian_ratio_method", (PyCFunction) rng_gaussian_ratio_method,METH_VARARGS, rng_gaussian_ratio_doc},
  {"ugaussian", (PyCFunction) rng_ugaussian,METH_VARARGS, rng_ugaussian_doc},
  {"ugaussian_ratio_method",(PyCFunction) rng_ugaussian_ratio_method,METH_VARARGS, rng_ugaussian_ratio_doc},
  {"gaussian_tail", (PyCFunction) rng_gaussian_tail,METH_VARARGS, rng_gaussian_tail_doc},
  {"ugaussian_tail",(PyCFunction) rng_ugaussian_tail,METH_VARARGS, rng_ugaussian_tail_doc},
  {"bivariate_gaussian", (PyCFunction) rng_bivariate_gaussian,METH_VARARGS, rng_bivariate_gaussian_doc},
  {"exponential",(PyCFunction)rng_exponential,METH_VARARGS, rng_exponential_doc},
  {"laplace",(PyCFunction)rng_laplace,METH_VARARGS, rng_laplace_doc},
  {"exppow",(PyCFunction)rng_exppow,METH_VARARGS, rng_exppow_doc},
  {"cauchy",(PyCFunction)rng_cauchy,METH_VARARGS, rng_cauchy_doc},
  {"rayleigh",(PyCFunction)rng_rayleigh,METH_VARARGS, rng_rayleigh_doc},
  {"rayleigh_tail",(PyCFunction)rng_rayleigh_tail,METH_VARARGS, rng_rayleigh_tail_doc},
  {"levy",(PyCFunction)rng_levy,METH_VARARGS, rng_levy_doc},
  {"levy_skew",(PyCFunction)rng_levy_skew,METH_VARARGS, rng_levy_skew_doc},
  {"gamma",(PyCFunction)rng_gamma,METH_VARARGS, rng_gamma_doc},
  {"gamma_int",(PyCFunction)rng_gamma_int,METH_VARARGS, NULL},
  {"flat",(PyCFunction)rng_flat,METH_VARARGS, rng_flat_doc},
  {"lognormal",(PyCFunction)rng_lognormal,METH_VARARGS, rng_lognormal_doc},
  {"chisq",(PyCFunction)rng_chisq,METH_VARARGS, rng_chisq_doc},
  {"fdist",(PyCFunction)rng_fdist,METH_VARARGS, rng_fdist_doc},
  {"tdist",(PyCFunction)rng_tdist,METH_VARARGS, rng_tdist_doc},
  {"beta",(PyCFunction)rng_beta,METH_VARARGS, rng_beta_doc},
  {"logistic",(PyCFunction)rng_logistic,METH_VARARGS, rng_logistic_doc},
  {"pareto",(PyCFunction)rng_pareto,METH_VARARGS, rng_pareto_doc},
  {"dir_2d",(PyCFunction)rng_dir_2d,METH_VARARGS, rng_dir_2d_doc},
  {"dir_2d_trig_method",(PyCFunction)rng_dir_2d_trig_method,METH_VARARGS, rng_dir_2d_trig_method_doc},
  {"dir_3d",(PyCFunction)rng_dir_3d,METH_VARARGS, rng_dir_3d_doc},
  {"dir_nd",(PyCFunction)rng_dir_nd,METH_VARARGS, rng_dir_nd_doc},
  {"weibull",(PyCFunction)rng_weibull,METH_VARARGS, rng_weibull_doc},
  {"gumbel1",(PyCFunction)rng_gumbel1,METH_VARARGS, rng_gumbel1_doc},
  {"gumbel2",(PyCFunction)rng_gumbel2,METH_VARARGS, rng_gumbel2_doc},
  {"poisson",(PyCFunction)rng_poisson,METH_VARARGS, rng_poisson_doc},
  {"bernoulli",(PyCFunction)rng_bernoulli,METH_VARARGS, rng_bernoulli_doc},
  {"binomial",(PyCFunction)rng_binomial,METH_VARARGS, rng_binomial_doc},
  {"negative_binomial",(PyCFunction)rng_negative_binomial,METH_VARARGS, rng_negative_binomial_doc},
  {"pascal",(PyCFunction)rng_pascal,METH_VARARGS, rng_pascal_doc},
  {"geometric",(PyCFunction)rng_geometric,METH_VARARGS, rng_geometric_doc},
  {"hypergeometric",(PyCFunction)rng_hypergeometric,METH_VARARGS, rng_hypergeometric_doc},
  {"logarithmic",(PyCFunction)rng_logarithmic,METH_VARARGS, rng_logarithmic_doc},
  {"landau",(PyCFunction)rng_landau,METH_VARARGS, rng_landau_doc},
  {"erlang",(PyCFunction)rng_erlang,METH_VARARGS, NULL},  
  {"multinomial",(PyCFunction)rng_multinomial,METH_VARARGS, NULL},
  {"dirichlet",(PyCFunction)rng_dirichlet,METH_VARARGS, rng_dirichlet_doc},
  {NULL, NULL}
};

static PyObject *
rng_getattr(PyGSL_rng *self, char *name)
{
     PyObject *tmp = NULL;

     FUNC_MESS_BEGIN();
     assert(PyGSLRng_Check(self));
 
     tmp = Py_FindMethod(rng_methods, (PyObject *) self, name);
     if(NULL == tmp){	  
	  PyGSL_add_traceback(module, __FILE__, "rng.__attr__", __LINE__ - 1);
	  return NULL;
     }
     return tmp;
}

static PyObject *
rng_types_setup(PyObject *self, PyObject *args)
{
     const gsl_rng_type** thisRNGType=gsl_rng_types_setup();
     PyObject* list = NULL, *item=NULL;
     
     FUNC_MESS_BEGIN();
     /* provide other rng types as subclasses of rng */

     list = PyList_New(0);
     while ((*thisRNGType)!=NULL) {
	  item = PyString_FromString((*thisRNGType)->name);
	  Py_INCREF(item);
	  assert(item);
	  PyGSL_clear_name(PyString_AsString(item), PyString_Size(item));
	  if(PyList_Append(list, item) != 0)
	       goto fail;
	  thisRNGType++;
     }
     FUNC_MESS_END();
     return list;
 fail:
     Py_XDECREF(list);
     Py_XDECREF(item);
     return NULL;
}

/*---------------------------------------------------------------------------*/
/* Module set up */
#define RNG_GENERATE_PDF
#undef RNG_DISTRIBUTION
#define RNG_DISTRIBUTION(name, function)                                   \
static PyObject* rng_ ## name ## _pdf (PyObject *self, PyObject *args)     \
{                                                                          \
     PyObject * tmp;                                                       \
     FUNC_MESS_BEGIN();                                                    \
     tmp =  PyGSL_pdf_ ## function (self, args, gsl_ran_ ## name ## _pdf); \
     if (tmp == NULL){                                                     \
	  PyGSL_add_traceback(module, __FILE__, #name  "_pdf", __LINE__);  \
     }                                                                     \
     FUNC_MESS_END();                                                      \
     return tmp;                                                           \
}

#include "rng_distributions.h"


static PyObject* rng_dirichlet_lnpdf (PyObject *self, PyObject *args)         
{ 
   return PyGSL_pdf_dA_to_dA(self, args, gsl_ran_dirichlet_lnpdf); 
}
static PyObject* rng_multinomial_lnpdf (PyObject *self, PyObject *args)
{ 
   return PyGSL_pdf_uidA_to_uiA(self, args, gsl_ran_multinomial_lnpdf); 
}

static PyMethodDef PyGSL_rng_module_functions[] = {
     {"rng", rng_init, METH_VARARGS, rng_doc},
     {"types_setup", rng_types_setup, METH_VARARGS},
     /*densities*/
     {"gaussian_pdf",rng_gaussian_pdf,METH_VARARGS, rng_gaussian_pdf_doc},
     {"ugaussian_pdf",rng_ugaussian_pdf,METH_VARARGS, rng_ugaussian_pdf_doc},
     {"gaussian_tail_pdf",rng_gaussian_tail_pdf,METH_VARARGS, rng_gaussian_tail_pdf_doc},
     {"ugaussian_tail_pdf",rng_ugaussian_tail_pdf,METH_VARARGS, rng_ugaussian_tail_pdf_doc},
     {"bivariate_gaussian_pdf",rng_bivariate_gaussian_pdf,METH_VARARGS, rng_bivariate_gaussian_pdf_doc},
     {"exponential_pdf",rng_exponential_pdf,METH_VARARGS, rng_exponential_pdf_doc},
     {"laplace_pdf",rng_laplace_pdf,METH_VARARGS, rng_laplace_pdf_doc},
     {"exppow_pdf",rng_exppow_pdf,METH_VARARGS, rng_exppow_pdf_doc},
     {"cauchy_pdf",rng_cauchy_pdf,METH_VARARGS, rng_cauchy_pdf_doc},
     {"rayleigh_pdf",rng_rayleigh_pdf,METH_VARARGS, rng_rayleigh_pdf_doc},
     {"rayleigh_tail_pdf",rng_rayleigh_tail_pdf,METH_VARARGS, rng_rayleigh_tail_pdf_doc},
     {"gamma_pdf",rng_gamma_pdf,METH_VARARGS, rng_gamma_pdf_doc},
     {"flat_pdf",rng_flat_pdf,METH_VARARGS, rng_flat_pdf_doc},
     {"lognormal_pdf",rng_lognormal_pdf,METH_VARARGS, rng_lognormal_pdf_doc},
     {"chisq_pdf",rng_chisq_pdf,METH_VARARGS, rng_chisq_pdf_doc},
     {"fdist_pdf",rng_fdist_pdf,METH_VARARGS, rng_fdist_pdf_doc},
     {"tdist_pdf",rng_tdist_pdf,METH_VARARGS, rng_tdist_pdf_doc},
     {"beta_pdf",rng_beta_pdf,METH_VARARGS, rng_beta_pdf_doc},
     {"logistic_pdf",rng_logistic_pdf,METH_VARARGS, rng_logistic_pdf_doc},
     {"pareto_pdf",rng_pareto_pdf,METH_VARARGS, rng_pareto_pdf_doc},
     {"weibull_pdf",rng_weibull_pdf,METH_VARARGS, rng_weibull_pdf_doc},
     {"gumbel1_pdf",rng_gumbel1_pdf,METH_VARARGS, rng_gumbel1_pdf_doc},
     {"gumbel2_pdf",rng_gumbel2_pdf,METH_VARARGS, rng_gumbel2_pdf_doc},
     {"poisson_pdf",rng_poisson_pdf,METH_VARARGS, rng_poisson_pdf_doc},
     {"bernoulli_pdf",rng_bernoulli_pdf,METH_VARARGS, rng_bernoulli_pdf_doc},
     {"binomial_pdf",rng_binomial_pdf,METH_VARARGS,  rng_binomial_pdf_doc},
     {"negative_binomial_pdf",rng_negative_binomial_pdf,METH_VARARGS, rng_negative_binomial_pdf_doc},
     {"pascal_pdf",rng_pascal_pdf,METH_VARARGS, rng_pascal_pdf_doc},
     {"geometric_pdf",rng_geometric_pdf,METH_VARARGS, rng_geometric_pdf_doc},
     {"hypergeometric_pdf",rng_hypergeometric_pdf,METH_VARARGS, rng_hypergeometric_pdf_doc},
     {"logarithmic_pdf",rng_logarithmic_pdf,METH_VARARGS, rng_logarithmic_pdf_doc},  
     {"landau_pdf",rng_landau_pdf,METH_VARARGS, rng_landau_pdf_doc},  
     {"erlang_pdf",rng_erlang_pdf,METH_VARARGS, NULL},
     {"multinomial_pdf",rng_multinomial_pdf,METH_VARARGS, NULL},  
     {"dirichlet_pdf",rng_dirichlet_pdf,METH_VARARGS, rng_dirichlet_pdf_doc},
     {"multinomial_lnpdf",rng_multinomial_lnpdf,METH_VARARGS, NULL},  
     {"dirichlet_lnpdf",rng_dirichlet_lnpdf,METH_VARARGS, rng_dirichlet_lnpdf_doc},  
     {NULL, NULL, 0}        /* Sentinel */
};


void
create_rng_types(PyObject *module)
{
     PyGSL_rng_type *a_rng = NULL;
     const gsl_rng_type** thisRNGType=gsl_rng_types_setup();
     PyObject* module_dict=PyModule_GetDict(module);
     PyObject* item = NULL;

     FUNC_MESS_BEGIN();
     /* provide other rng types as subclasses of rng */
     assert(module_dict);

     while ((*thisRNGType)!=NULL) {
	  a_rng =  PyObject_NEW(PyGSL_rng_type, &PyGSL_rng_type_pytype);
	  a_rng->rng_type = (gsl_rng_type *) *thisRNGType;
	  item = PyString_FromString((*thisRNGType)->name);
	  PyGSL_clear_name(PyString_AsString(item), PyString_Size(item));
	  assert(item);
	  PyDict_SetItem(module_dict, item, (PyObject *) a_rng);
	  Py_DECREF(item);
	  item = NULL;	       
	  thisRNGType++;
     }
     FUNC_MESS_END();
}

void 
initrng(void)
{
     PyObject *m=NULL, *item=NULL, *dict=NULL;

     m = Py_InitModule("rng", PyGSL_rng_module_functions);
     assert(m);
     create_rng_types(m);
     module = m;

     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;
     
     if (!(item = PyString_FromString(rng_module_doc))){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not generate module doc string!");
	  goto fail;
     }
     if (PyDict_SetItemString(dict, "__doc__", item) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not init doc string!");
	  goto fail;
     }
     PyGSL_rng_type_pytype.ob_type = &PyType_Type;
     PyGSL_rng_pytype.ob_type = &PyType_Type;
     import_array();
     init_pygsl();
     return;
     
 fail:
     if(!PyErr_Occurred()){
	  PyErr_SetString(PyExc_ImportError, "I could not init rng module!");
     }

}
