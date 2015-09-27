/*
 *  A rng module implementation which can return a sample as an array.
 *  Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 *  Date   : 1. July. 2003
 *
 */
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <pygsl/string_helpers.h>
#include <pygsl/utils.h>
#include <pygsl/pygsl_features.h>
#ifdef PyGSL_NO_IMPORT_API
#undef PyGSL_NO_IMPORT_API
#endif
#include <pygsl/rng_helpers.h>
#include <pygsl/rng.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/*
 * All doc strings
 */
static PyObject *module = NULL;
#include "rng_helpers.c"
#include "rngmodule_docs.h"


static void rng_delete(PyGSL_rng *self);
static PyObject * rng_call(PyGSL_rng *self, PyObject *args);

#undef PyGSL_RNG_Check

#define PyGSL_RNG_Check(ob) (Py_TYPE(ob) == &PyGSL_rng_pytype)

static void
rng_delete(PyGSL_rng *self);

static PyObject *	
rng_call (PyGSL_rng *self, PyObject *args);
static PyObject *
rng_get(PyGSL_rng *self, PyObject *args);
static PyObject *
rng_set(PyGSL_rng *self, PyObject *args);
static PyObject *
rng_uniform_int (PyGSL_rng *self, PyObject *args);
 static PyObject *
rng_uniform_pos (PyGSL_rng *self, PyObject *args);

static PyObject * rng_max(PyGSL_rng *self, PyObject *args);
static PyObject * rng_min(PyGSL_rng *self, PyObject *args);
static PyObject * rng_name(PyGSL_rng *self, PyObject *args);
static PyObject * rng_clone(PyGSL_rng *self, PyObject *args);

#define RNG_DISTRIBUTION(name, function)                                     \
static PyObject* rng_ ## name (PyGSL_rng *self, PyObject *args);              
#include "rng_distributions.h"
#undef RNG_DISTRIBUTION

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
  {"multinomial",(PyCFunction)rng_multinomial,METH_VARARGS, multinomial_doc},
  {"dirichlet",(PyCFunction)rng_dirichlet,METH_VARARGS, rng_dirichlet_doc},
  {NULL, NULL}
};


#ifdef PyGSL_PY3K
static PyTypeObject PyGSL_rng_pytype = {
	PyObject_HEAD_INIT(NULL)
	"PyGSL_rng",                    /* tp_name */
	sizeof(PyGSL_rng),              /* tp_basicsize */
	0,                                          /* tp_itemsize */
	(destructor) rng_delete, /* tp_dealloc */
	0,                       /* tp_print */
	0,                       /* tp_getattr */
	0,                       /* tp_setattr */
	0,                       /* tp_reserved */
	0,                       /* tp_repr */
	0,                       /* tp_as_number */
	0,                       /* tp_as_sequence */
	0,                       /* tp_as_mapping */
	0,                       /* tp_hash */
	(ternaryfunc)  rng_call, /* tp_call */
	0,                       /* tp_str */
	0,                       /* tp_getattro */
	0,                       /* tp_setattro */
	0,                       /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,      /* tp_flags */
	(char *)rng_type_doc, /* tp_doc */
	0,                       /* tp_traverse */
	0,                       /* tp_clear */
	0,                       /* tp_richcompare */
	0,                       /* tp_weaklistoffset */
	0,                       /* tp_iter */
	0,                       /* tp_iternext */
	rng_methods,          /* tp_methods */
	0,                       /* tp_members */
	0,                       /* tp_getset */
	0,                       /* tp_base */
	0,                       /* tp_dict */
	0,                       /* tp_descr_get */
	0,                       /* tp_descr_set */
	0,                       /* tp_dictoffset */
	0,                       /* tp_init */
	0,                       /* tp_alloc */
	0,                       /* tp_new */
};
#else /* PyGSL_PY3K */
static PyObject *
rng_getattr(PyGSL_rng *self, char *name);
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
#endif /* PyGSL_PY3K */




static PyObject *
PyGSL_rng_init(PyObject *self, PyObject *args, const gsl_rng_type * rng_type)
{

     PyGSL_rng *rng = NULL;

     FUNC_MESS_BEGIN();
     rng =  (PyGSL_rng *) PyObject_NEW(PyGSL_rng, &PyGSL_rng_pytype);
     if(rng == NULL){
	  return NULL;
     }
     if(rng_type == NULL){
	  rng->rng = gsl_rng_alloc(gsl_rng_default);
	  gsl_rng_set(rng->rng, gsl_rng_default_seed);
     }else{
	  rng->rng = gsl_rng_alloc(rng_type);
     }
     FUNC_MESS_END();
     return (PyObject *) rng;
}

#define RNG_ARNG(name)                                                       \
static PyObject* PyGSL_rng_init_ ## name (PyObject *self, PyObject *args)    \
{                                                                            \
     PyObject *tmp = NULL;                                                   \
     FUNC_MESS_BEGIN();                                                      \
     tmp = PyGSL_rng_init(self, args,  gsl_rng_ ## name);                    \
     if (tmp == NULL){                                                       \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);     \
     }                                                                       \
     FUNC_MESS_END();                                                        \
     return tmp;                                                             \
}

#include "rng_list.h"

static PyObject *
PyGSL_rng_init_default(PyObject *self, PyObject *args)              
{                                                                    
     PyObject *tmp = NULL;                                           
     FUNC_MESS_BEGIN();                                              
     tmp = PyGSL_rng_init(self, args,  NULL);            
     if (tmp == NULL){                                               
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__ - 1);
     }                                                               
     FUNC_MESS_END();                                                
     return tmp;                                                     
}


static void
rng_delete(PyGSL_rng *self)
{
     FUNC_MESS_BEGIN();
     assert(PyGSL_RNG_Check(self));
     if(self->rng != NULL){
	  DEBUG_MESS(5, "Freeing gsl_rng @ %p", self->rng);
	  gsl_rng_free(self->rng);
	  self->rng = NULL;
     }
     DEBUG_MESS(1, " self %p\n",(void *) self);
     PyObject_Del(self);
     self = NULL;
     FUNC_MESS_END();
}

static PyObject *		/* on "instance.uniform()" and "instance()" */
rng_call (PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp;

     FUNC_MESS_BEGIN();
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
     if(0 == PyArg_ParseTuple(args, ":name"))
	  return NULL;
     tmp = PyGSL_string_from_string(gsl_rng_name(self->rng));
     FUNC_MESS_END();
     return tmp;
}

static PyObject *
rng_max(PyGSL_rng *self, PyObject *args)
{
     PyObject *tmp = NULL;
     FUNC_MESS_BEGIN();
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
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
     assert(PyGSL_RNG_Check(self));
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


#ifndef PyGSL_PY3K
static PyObject *
rng_getattr(PyGSL_rng *self, char *name)
{
     PyObject *tmp = NULL;

     FUNC_MESS_BEGIN();
     assert(PyGSL_RNG_Check(self));
 
     tmp = Py_FindMethod(rng_methods, (PyObject *) self, name);
     if(NULL == tmp){	  
	  PyGSL_add_traceback(module, __FILE__, "rng.__attr__", __LINE__ - 1);
	  return NULL;
     }
     return tmp;
}

#endif /* PyGSL_PY3K */




#define BUF_LEN 256
static PyObject *
rng_create_list(PyObject *self, PyObject *args)
{
     const gsl_rng_type** thisRNGType=gsl_rng_types_setup();
     PyObject* list = NULL, *item=NULL;
     char buffer[BUF_LEN], *tmp;
     int size;
     FUNC_MESS_BEGIN();
     /* provide other rng types as subclasses of rng */

     list = PyList_New(0);
     while ((*thisRNGType)!=NULL) {
	     tmp = (char *) ((*thisRNGType)->name);
	     size = strlen(tmp);
	     if(size > BUF_LEN - 1){
		     pygsl_error("tmp buffer to small for clearing the name",
				 __FILE__, __LINE__, GSL_ESANITY);
	     }
	     strcpy(buffer, tmp);
	     PyGSL_clear_name(buffer, size);

	     item = PyGSL_string_from_string(tmp);
	     if(item == NULL)
		     goto fail;
	  
	     Py_INCREF(item);
	     assert(item);
	     
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
     PyObject *tmp;
     FUNC_MESS_BEGIN();
     tmp = PyGSL_pdf_dA_to_dA(self, args, gsl_ran_dirichlet_lnpdf); 
     FUNC_MESS_END();
     return tmp;
}

static PyObject* rng_multinomial_lnpdf (PyObject *self, PyObject *args)
{ 
     PyObject *tmp;
     FUNC_MESS_BEGIN();
     tmp = PyGSL_pdf_uidA_to_uiA(self, args, gsl_ran_multinomial_lnpdf);
     FUNC_MESS_END();
     return tmp;
}


static const char rng_env_setup_doc[] = 
"This function reads the environment variables `GSL_RNG_TYPE' and\n\
`GSL_RNG_SEED'.\n\
The environment variable `GSL_RNG_TYPE' should be the name of a\n\
generator, such as `taus' or `mt19937'. The environment variable\n\
`GSL_RNG_SEED' should contain the desired seed value. It is\n\
converted to an `unsigned long int' using the C library function\n\
`strtoul'.\n";

static PyObject *
PyGSL_rng_env_setup(PyObject *self, PyObject *args)
{
     gsl_rng_env_setup();
     Py_INCREF(Py_None);
     return Py_None;
}

static PyMethodDef PyGSL_rng_module_functions[] = {
     {"borosh13"        , PyGSL_rng_init_borosh13        , METH_NOARGS, NULL},
     {"cmrg"            , PyGSL_rng_init_cmrg            , METH_NOARGS, NULL},
     {"coveyou"         , PyGSL_rng_init_coveyou         , METH_NOARGS, NULL},
     {"fishman18"       , PyGSL_rng_init_fishman18       , METH_NOARGS, NULL},
     {"fishman20"       , PyGSL_rng_init_fishman20       , METH_NOARGS, NULL},
     {"fishman2x"       , PyGSL_rng_init_fishman2x       , METH_NOARGS, NULL},
     {"gfsr4"           , PyGSL_rng_init_gfsr4           , METH_NOARGS, NULL},
     {"knuthran"        , PyGSL_rng_init_knuthran        , METH_NOARGS, NULL},
     {"knuthran2"       , PyGSL_rng_init_knuthran2       , METH_NOARGS, NULL},
#ifdef  _PYGSL_GSL_HAS_RNG_KNUTHRAN2002
     {"knuthran2002"    , PyGSL_rng_init_knuthran2002    , METH_NOARGS, NULL},
#else
#error "Should be defined by now ..."
#endif
     {"lecuyer21"       , PyGSL_rng_init_lecuyer21       , METH_NOARGS, NULL},
     {"minstd"          , PyGSL_rng_init_minstd          , METH_NOARGS, NULL},
     {"mrg"             , PyGSL_rng_init_mrg             , METH_NOARGS, NULL},
     {"mt19937"         , PyGSL_rng_init_mt19937         , METH_NOARGS, NULL},
     {"mt19937_1999"    , PyGSL_rng_init_mt19937_1999    , METH_NOARGS, NULL},
     {"mt19937_1998"    , PyGSL_rng_init_mt19937_1998    , METH_NOARGS, NULL},
     {"r250"	        , PyGSL_rng_init_r250            , METH_NOARGS, NULL},
     {"ran0"	        , PyGSL_rng_init_ran0            , METH_NOARGS, NULL},
     {"ran1"	        , PyGSL_rng_init_ran1            , METH_NOARGS, NULL},
     {"ran2"	        , PyGSL_rng_init_ran2            , METH_NOARGS, NULL},
     {"ran3"	        , PyGSL_rng_init_ran3            , METH_NOARGS, NULL},
     {"rand"	        , PyGSL_rng_init_rand            , METH_NOARGS, NULL},
     {"rand48"          , PyGSL_rng_init_rand48          , METH_NOARGS, NULL},
     {"random128_bsd"   , PyGSL_rng_init_random128_bsd   , METH_NOARGS, NULL},
     {"random128_glibc2", PyGSL_rng_init_random128_glibc2, METH_NOARGS, NULL},
     {"random128_libc5" , PyGSL_rng_init_random128_libc5 , METH_NOARGS, NULL},
     {"random256_bsd"   , PyGSL_rng_init_random256_bsd   , METH_NOARGS, NULL},
     {"random256_glibc2", PyGSL_rng_init_random256_glibc2, METH_NOARGS, NULL},
     {"random256_libc5" , PyGSL_rng_init_random256_libc5 , METH_NOARGS, NULL},
     {"random32_bsd"    , PyGSL_rng_init_random32_bsd    , METH_NOARGS, NULL},
     {"random32_glibc2" , PyGSL_rng_init_random32_glibc2 , METH_NOARGS, NULL},
     {"random32_libc5"  , PyGSL_rng_init_random32_libc5  , METH_NOARGS, NULL},
     {"random64_bsd"    , PyGSL_rng_init_random64_bsd    , METH_NOARGS, NULL},
     {"random64_glibc2" , PyGSL_rng_init_random64_glibc2 , METH_NOARGS, NULL},
     {"random64_libc5"  , PyGSL_rng_init_random64_libc5  , METH_NOARGS, NULL},
     {"random8_bsd"     , PyGSL_rng_init_random8_bsd     , METH_NOARGS, NULL},
     {"random8_glibc2"  , PyGSL_rng_init_random8_glibc2  , METH_NOARGS, NULL},
     {"random8_libc5"   , PyGSL_rng_init_random8_libc5   , METH_NOARGS, NULL},
     {"random_bsd"      , PyGSL_rng_init_random_bsd      , METH_NOARGS, NULL},
     {"random_glibc2"   , PyGSL_rng_init_random_glibc2   , METH_NOARGS, NULL},
     {"random_libc5"    , PyGSL_rng_init_random_libc5    , METH_NOARGS, NULL},
     {"randu"           , PyGSL_rng_init_randu           , METH_NOARGS, NULL},
     {"ranf"            , PyGSL_rng_init_ranf            , METH_NOARGS, NULL},
     {"ranlux"          , PyGSL_rng_init_ranlux          , METH_NOARGS, NULL},
     {"ranlux389"       , PyGSL_rng_init_ranlux389       , METH_NOARGS, NULL},
     {"ranlxd1"         , PyGSL_rng_init_ranlxd1         , METH_NOARGS, NULL},
     {"ranlxd2"         , PyGSL_rng_init_ranlxd2         , METH_NOARGS, NULL},
     {"ranlxs0"         , PyGSL_rng_init_ranlxs0         , METH_NOARGS, NULL},
     {"ranlxs1"         , PyGSL_rng_init_ranlxs1         , METH_NOARGS, NULL},
     {"ranlxs2"         , PyGSL_rng_init_ranlxs2         , METH_NOARGS, NULL},
     {"ranmar"          , PyGSL_rng_init_ranmar          , METH_NOARGS, NULL},
     {"slatec"          , PyGSL_rng_init_slatec          , METH_NOARGS, NULL},
     {"taus"            , PyGSL_rng_init_taus            , METH_NOARGS, NULL},
     {"taus2"           , PyGSL_rng_init_taus2           , METH_NOARGS, NULL},
     {"taus113"         , PyGSL_rng_init_taus113         , METH_NOARGS, NULL},
     {"transputer"      , PyGSL_rng_init_transputer      , METH_NOARGS, NULL},
     {"tt800"           , PyGSL_rng_init_tt800           , METH_NOARGS, NULL},
     {"uni"             , PyGSL_rng_init_uni             , METH_NOARGS, NULL},
     {"uni32"           , PyGSL_rng_init_uni32           , METH_NOARGS, NULL},
     {"vax"             , PyGSL_rng_init_vax             , METH_NOARGS, NULL},
     {"waterman14"      , PyGSL_rng_init_waterman14      , METH_NOARGS, NULL},
     {"zuf"             , PyGSL_rng_init_zuf             , METH_NOARGS, NULL},
     {"rng", PyGSL_rng_init_default, METH_NOARGS, rng_doc},
     {"list_available_rngs", rng_create_list, METH_VARARGS},
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
     {"multinomial_pdf",rng_multinomial_pdf,METH_VARARGS,multinomial_pdf_doc},  
     {"dirichlet_pdf",rng_dirichlet_pdf,METH_VARARGS, rng_dirichlet_pdf_doc},
     {"multinomial_lnpdf",rng_multinomial_lnpdf,METH_VARARGS, NULL},  
     {"dirichlet_lnpdf",rng_dirichlet_lnpdf,METH_VARARGS, rng_dirichlet_lnpdf_doc},
     {"env_setup",PyGSL_rng_env_setup,METH_NOARGS, (char*) rng_env_setup_doc},
     {NULL, NULL, 0}        /* Sentinel */
};

static void 
set_api_pointer(void)
{

     FUNC_MESS_BEGIN();
     PyGSL_API[PyGSL_RNG_ObjectType_NUM] = (void *) &PyGSL_rng_pytype;
     DEBUG_MESS(2, "__PyGSL_RNG_API   @ %p,  ", (void *) PyGSL_API);
     DEBUG_MESS(2, "PyGSL_rng_pytype  @ %p,  ", (void *) &PyGSL_rng_pytype);
     /* fprintf(stderr, "__PyGSL_RNG_API @ %p\n", (void *) __PyGSL_RNG_API); */
     FUNC_MESS_END();
}


#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.rng",
        NULL,
        -1,
	PyGSL_rng_module_functions,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif /* PyGSL_PY3K */

#ifdef __cplusplus
extern "C"
#endif


#ifdef PyGSL_PY3K
PyObject *PyInit_rng(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) initrng(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
     PyObject *m=NULL, *item=NULL, *dict=NULL;
     PyObject *api=NULL;

#ifdef PyGSL_PY3K
	m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
	m = Py_InitModule("rng", PyGSL_rng_module_functions);
#endif /* PyGSL_PY3K */

	if(m == NULL)
	  return RETVAL;
	
     assert(m);
     /* import_array(); */
     init_pygsl();

     /* create_rng_types(m); */
     module = m;

     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;
     
     if (!(item = PyGSL_string_from_string(rng_module_doc))){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not generate module doc string!");
	  goto fail;
     }
     if (PyDict_SetItemString(dict, "__doc__", item) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not init doc string!");
	  goto fail;
     }

#ifdef PyGSL_PY3K
	if (PyType_Ready(&PyGSL_rng_pytype) < 0)
		return NULL;
#else /* PyGSL_PY3K */
     PyGSL_rng_pytype.ob_type = &PyType_Type;
#endif /* PyGSL_PY3K */


     set_api_pointer();
     api = PyCapsule_New((void *) PyGSL_API, _PyGSL_RNG_API_CAP, NULL);
     if(api == NULL)
       goto fail;
     
     assert(api);
     if (PyDict_SetItemString(dict, "_PYGSL_RNG_API", api) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not add  _PYGSL_RNG_API!");
	  goto fail;
     }
     
     return RETVAL;
     
 fail:
     if(!PyErr_Occurred()){
	  PyErr_SetString(PyExc_ImportError, "I could not init rng module!");
     }
     return RETVAL;
}
