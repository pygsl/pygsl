/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/_rngmodule.c
 * $Id$
 */

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_errno.h>
#include <Python.h>

typedef struct {
  char *name;
  const gsl_rng_type **type;
} const_rng_names;

static const_rng_names rng_names[] = {
  /* used as rng prototype in gsl_rng_alloc*/
  {"cmrg",&gsl_rng_cmrg},
  {"minstd",&gsl_rng_minstd},
  {"mrg",&gsl_rng_mrg},
  {"mt19937",&gsl_rng_mt19937},
  {"r250",&gsl_rng_r250},
  {"ran0",&gsl_rng_ran0},
  {"ran1",&gsl_rng_ran1},
  {"ran2",&gsl_rng_ran2},
  {"ran3",&gsl_rng_ran3},
  {"rand",&gsl_rng_rand},
  {"rand48",&gsl_rng_rand48},
  {"random_bsd",&gsl_rng_random_bsd},
  {"random_glibc2",&gsl_rng_random_glibc2},
  {"random_libc5",&gsl_rng_random_libc5},
  {"randu",&gsl_rng_randu},
  {"ranf",&gsl_rng_ranf},
  {"ranlux",&gsl_rng_ranlux},
  {"ranlux389",&gsl_rng_ranlux389},
  {"ranmar",&gsl_rng_ranmar},
  {"slatec",&gsl_rng_slatec},
  {"taus",&gsl_rng_taus},
  /*  {"tds",&gsl_rng_tds}, */
  {"tt800",&gsl_rng_tt800},
  {"uni",&gsl_rng_uni},
  {"uni32",&gsl_rng_uni32},
  {"vax",&gsl_rng_vax},
  {"zuf",&gsl_rng_zuf},
  {"default",&gsl_rng_default},
  {0x0,0x0}
};

static void define_rng_names(PyObject* module)
{
  int i=0;
  PyObject* module_dict;
  module_dict=PyModule_GetDict(module);

  while (rng_names[i].name!=NULL)
    {
      PyObject* new_object;
      new_object=PyCObject_FromVoidPtr ((void*)rng_names[i].type, NULL);
      PyDict_SetItemString(module_dict,rng_names[i].name,new_object);
      Py_DECREF(new_object);
      i++;
    }
  return;
}


static PyObject* rng_env_setup(PyObject *self,
			       PyObject *args
			       )
{
  gsl_rng_env_setup();
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* rng_alloc(PyObject *self,
			   PyObject *args
			   )
{
  const gsl_rng_type** rng;
  gsl_rng* new_rng;
  PyObject* new_py_rng;
  PyObject* rng_pointer;

  if (0==PyArg_ParseTuple(args,"O",&rng_pointer))
    return NULL;
  rng=PyCObject_AsVoidPtr(rng_pointer);

  new_rng=gsl_rng_alloc(*rng);

  if (new_rng==NULL)
    {
      /* raise exception*/
      return NULL;
    }

  new_py_rng=PyCObject_FromVoidPtr((void*)new_rng, NULL);
  if (new_py_rng==NULL)
    return NULL;
  return new_py_rng;
}

static PyObject* rng_free(PyObject *self,
			  PyObject *args
			  )
{
  PyObject* py_rng;
  gsl_rng* rng;

  if (0==PyArg_ParseTuple(args,"O",&py_rng)) {
    return NULL;
  }
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  if (rng==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_rng.free got a void pointer" );
    return NULL;
  }
  gsl_rng_free(rng);

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* rng_clone(PyObject *self,
			   PyObject *args
			   )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_new_rng;
  gsl_rng* new_rng;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  new_rng=gsl_rng_clone(rng);

  if (new_rng==NULL)
    {
      /* raise exception*/
      return NULL;
    }

  py_new_rng=PyCObject_FromVoidPtr((void*)new_rng, NULL);
  return py_new_rng;
}

static PyObject* rng_set(PyObject *self,
			 PyObject *args
			 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  unsigned long int seed;

  if (0==PyArg_ParseTuple(args,"Ol",&py_rng,&seed))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  gsl_rng_set(rng,seed);

  Py_INCREF(Py_None);
  return Py_None;
}



static PyObject* rng_get(PyObject *self,
			 PyObject *args
			 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  unsigned long int result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_rng_get(rng);

  py_result=PyLong_FromUnsignedLong(result);
  if (py_result==NULL)
    return NULL;

  return py_result;
}

static PyObject* rng_uniform(PyObject *self,
			     PyObject *args
			     )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_rng_uniform(rng);

  py_result=PyFloat_FromDouble(result);
  if (py_result==NULL)
    return NULL;

  return py_result;
}

static PyObject* rng_uniform_pos(PyObject *self,
				 PyObject *args
				 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_rng_uniform_pos(rng);

  py_result=PyFloat_FromDouble(result);
  if (py_result==NULL)
    return NULL;

  return py_result;
}

static PyObject* rng_uniform_int(PyObject *self,
				 PyObject *args
				 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  unsigned long int n;
  unsigned long int result;

  if (0==PyArg_ParseTuple(args,"Ol",&py_rng,&n))
    return NULL;
  if (n==0)
    {
      /* floating point exception is raised, if n==0 */
      /* prevent this by raising python exception */
      PyObject* err_module;
      PyObject* err_module_dict;
      PyObject* raise_error;
      err_module=PyImport_ImportModule("gsl.errors");
      err_module_dict=PyModule_GetDict(err_module);
      raise_error=PyDict_GetItemString(err_module_dict,"gsl_ZeroDivisionError");
      PyErr_SetString(raise_error,"2nd argument must be !=0");
      return NULL;
    }
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_rng_uniform_int(rng,n);

  py_result=PyLong_FromUnsignedLong(result);
  if (py_result==NULL)
    return NULL;

  return py_result;
}

/* other distributions */

static PyObject* ran_gaussian(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&sigma))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gaussian(rng,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gaussian_ratio_method(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&sigma))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gaussian_ratio_method(rng,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_ugaussian(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_ugaussian(rng);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_ugaussian_ratio_method(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_ugaussian_ratio_method(rng);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gaussian_tail(PyObject *self,
				   PyObject *args
				   )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&sigma,&a))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gaussian_tail(rng,sigma,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_ugaussian_tail(PyObject *self,
				   PyObject *args
				   )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&a))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_ugaussian_tail(rng,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_bivariate_gaussian(PyObject *self,
					PyObject *args
					)
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma_x,sigma_y,rho,x,y;
  PyObject* py_result;

  if (0==PyArg_ParseTuple(args,"Oddd",&py_rng,&sigma_x,&sigma_y,&rho))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  gsl_ran_bivariate_gaussian(rng,sigma_x, sigma_y, rho, &x, &y);

  py_result=Py_BuildValue("(dd)",x,y);
  return py_result;
}

static PyObject* ran_exponential(PyObject *self,
				 PyObject *args
				 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&mu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_exponential(rng,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_laplace(PyObject *self,
			     PyObject *args
			     )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&mu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_laplace(rng,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_exppow(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&mu,&a))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_exppow(rng,mu,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_cauchy(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&mu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_cauchy(rng,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_rayleigh(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&sigma))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_rayleigh(rng,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_rayleigh_tail(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&sigma))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_rayleigh_tail(rng,a,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_levy(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&mu,&a))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_levy(rng,mu,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gamma(PyObject *self,
			   PyObject *args
			   )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&b))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gamma(rng,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_flat(PyObject *self,
			  PyObject *args
			  )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&b))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_flat(rng,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_lognormal(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double zeta,sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&zeta,&sigma))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_lognormal(rng,zeta,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_chisq(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double nu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&nu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_chisq(rng,nu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_fdist(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double nu1,nu2;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&nu1,&nu2))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_fdist(rng,nu1,nu2);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_tdist(PyObject *self,
			   PyObject *args
			   )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double nu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&nu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_tdist(rng,nu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_beta(PyObject *self,
			  PyObject *args
			  )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&b))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_beta(rng,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_logistic(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&mu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_logistic(rng,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_pareto(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&b))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_pareto(rng,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}


static PyObject* ran_dir_2d(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double x,y;
  PyObject* py_result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  gsl_ran_dir_2d(rng, &x, &y);

  py_result=Py_BuildValue("(dd)",x,y);
  return py_result;
}

static PyObject* ran_dir_2d_trig_method(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double x,y;
  PyObject* py_result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  gsl_ran_dir_2d_trig_method(rng, &x, &y);

  py_result=Py_BuildValue("(dd)",x,y);
  return py_result;
}

static PyObject* ran_dir_3d(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double x,y,z;
  PyObject* py_result;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  gsl_ran_dir_3d(rng, &x, &y, &z);

  py_result=Py_BuildValue("(ddd)",x,y,z);
  return py_result;
}


static PyObject* ran_dir_nd(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  int n,i;
  double* vector;
  PyObject* py_result;

  if (0==PyArg_ParseTuple(args,"Oi",&py_rng,&n))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  if (n<1)
    {
      PyErr_SetString(PyExc_ValueError,"2nd argument must be >0");
      return NULL;
    }

  vector=malloc(n*sizeof(double));
  if (vector==NULL)
    {
      PyErr_SetString(PyExc_MemoryError,"no memory for vector");
      return NULL;
    }

  gsl_ran_dir_nd(rng,n,vector);

  py_result=PyTuple_New(n);
  if (py_result==NULL)
    {
      free(vector);
      return NULL;
    }

  for(i=0;i<n;i++)
    {
      PyObject* py_float;
      py_float=PyFloat_FromDouble(vector[i]);
      if (py_float==NULL)
	{
	  free(vector);
	  /*other elements from tuple must be freed*/
	  /* not done :-( */
	  return NULL;
	}
      PyTuple_SetItem(py_result,i,py_float);
    }

  free(vector);
  return py_result;
}

static PyObject* ran_weibull(PyObject *self,
			     PyObject *args
			     )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&mu,&a))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_weibull(rng,mu,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gumbel1(PyObject *self,
			     PyObject *args
			     )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&b))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gumbel1(rng,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gumbel2(PyObject *self,
			     PyObject *args
			     )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"Odd",&py_rng,&a,&b))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gumbel2(rng,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_poisson(PyObject *self,
			     PyObject *args
			     )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double mu;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&mu))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_poisson(rng,mu);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}

static PyObject* ran_bernoulli(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double p;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&p))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_bernoulli(rng,p);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_binomial(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double p;
  PyObject* py_result;
  unsigned int n,result;

  if (0==PyArg_ParseTuple(args,"Odi",&py_rng,&p,&n))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_binomial(rng,p,n);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_negative_binomial(PyObject *self,
				       PyObject *args
				       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double p;
  PyObject* py_result;
  unsigned int n,result;

  if (0==PyArg_ParseTuple(args,"Odi",&py_rng,&p,&n))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_negative_binomial(rng,p,n);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}
 
static PyObject* ran_pascal(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double p;
  PyObject* py_result;
  unsigned int k,result;

  if (0==PyArg_ParseTuple(args,"Odi",&py_rng,&p,&k))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_pascal(rng,p,k);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}

static PyObject* ran_geometric(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double p;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&p))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_geometric(rng,p);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_hypergeometric(PyObject *self,
				    PyObject *args
				    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  unsigned int n1,n2,t,result;

  if (0==PyArg_ParseTuple(args,"Oiii",&py_rng,&n1,&n2,&t))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_hypergeometric(rng,n1,n2,t);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_logarithmic(PyObject *self,
				 PyObject *args
				 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double p;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"Od",&py_rng,&p))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_logarithmic(rng,p);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}

/* useful rng informations */

static PyObject* rng_name(PyObject *self,
			  PyObject *args
			  )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_name;
  const char* name;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  name=gsl_rng_name(rng);

  py_name=PyString_FromString(name);
  if (py_name==NULL)
    return NULL;

  return py_name;
}

static PyObject* rng_max(PyObject *self,
			 PyObject *args
			 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_max;
  unsigned long int max;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  max=gsl_rng_max(rng);

  py_max=PyLong_FromUnsignedLong(max);
  if (py_max==NULL)
    return NULL;

  return py_max;
}

static PyObject* rng_min(PyObject *self,
			 PyObject *args
			 )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_min;
  unsigned long int min;

  if (0==PyArg_ParseTuple(args,"O",&py_rng))
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  min=gsl_rng_min(rng);

  py_min=PyLong_FromUnsignedLong(min);
  if (py_min==NULL)
    return NULL;

  return py_min;
}

/* probability densities */

static PyObject* ran_gaussian_pdf(PyObject *self,
				  PyObject *args
				  )
{
  double x;
  double sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&sigma))
    return NULL;

  result=gsl_ran_gaussian_pdf(x,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_ugaussian_pdf(PyObject *self,
			       PyObject *args
			       )
{
  double x;
  
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"d",&x))
    return NULL;
  result=gsl_ran_ugaussian_pdf(x);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gaussian_tail_pdf(PyObject *self,
				   PyObject *args
				   )
{
  double x;
  
  double sigma,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&sigma,&a))
    return NULL;

  result=gsl_ran_gaussian_tail_pdf(x,sigma,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_ugaussian_tail_pdf(PyObject *self,
				   PyObject *args
				   )
{
  double x;
  
  double a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&a))
    return NULL;

  result=gsl_ran_ugaussian_tail_pdf(x,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_bivariate_gaussian_pdf(PyObject *self,
					PyObject *args
					)
{
  double result;
  
  double sigma_x,sigma_y,rho,x,y;
  PyObject* py_result;

  if (0==PyArg_ParseTuple(args,"ddddd",&x,&y,&sigma_x,&sigma_y,&rho))
    return NULL;

  result=gsl_ran_bivariate_gaussian_pdf(x,y,sigma_x, sigma_y, rho);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_exponential_pdf(PyObject *self,
				 PyObject *args
				 )
{
  double x;
  
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&mu))
    return NULL;

  result=gsl_ran_exponential_pdf(x,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_laplace_pdf(PyObject *self,
			     PyObject *args
			     )
{
  double x;
  
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&mu))
    return NULL;

  result=gsl_ran_laplace_pdf(x,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_exppow_pdf(PyObject *self,
			    PyObject *args
			    )
{
  double x;
  
  double mu,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&mu,&a))
    return NULL;

  result=gsl_ran_exppow_pdf(x,mu,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_cauchy_pdf(PyObject *self,
			      PyObject *args
			      )
{
  double x;
  
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&mu))
    return NULL;

  result=gsl_ran_cauchy_pdf(x,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_rayleigh_pdf(PyObject *self,
			      PyObject *args
			      )
{
  double x;
  
  double sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&sigma))
    return NULL;

  result=gsl_ran_rayleigh_pdf(x,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_rayleigh_tail_pdf(PyObject *self,
			      PyObject *args
			      )
{
  double x;
  
  double sigma,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&sigma))
    return NULL;

  result=gsl_ran_rayleigh_tail_pdf(x,a,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

/*just missing ?!*/
#if 0
static PyObject* ran_levy_pdf(PyObject *self,
			      PyObject *args
			      )
{
  double x;
  
  double mu,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&mu,&a))
    return NULL;

  result=gsl_ran_levy_pdf(x,mu,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

#endif

static PyObject* ran_gamma_pdf(PyObject *self,
			   PyObject *args
			   )
{
  double x;
  
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&b))
    return NULL;

  result=gsl_ran_gamma_pdf(x,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_flat_pdf(PyObject *self,
			  PyObject *args
			  )
{
  double x;
  
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&b))
    return NULL;

  result=gsl_ran_flat_pdf(x,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_lognormal_pdf(PyObject *self,
			       PyObject *args
			       )
{
  double x;
  
  double zeta,sigma;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&zeta,&sigma))
    return NULL;

  result=gsl_ran_lognormal_pdf(x,zeta,sigma);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_chisq_pdf(PyObject *self,
			       PyObject *args
			       )
{
  double x;
  
  double nu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&nu))
    return NULL;

  result=gsl_ran_chisq_pdf(x,nu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_fdist_pdf(PyObject *self,
			      PyObject *args
			      )
{
  double x;
  
  double nu1,nu2;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&nu1,&nu2))
    return NULL;

  result=gsl_ran_fdist_pdf(x,nu1,nu2);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_tdist_pdf(PyObject *self,
			   PyObject *args
			   )
{
  double x;
  
  double nu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&nu))
    return NULL;

  result=gsl_ran_tdist_pdf(x,nu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_beta_pdf(PyObject *self,
			  PyObject *args
			  )
{
  double x;
  
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&b))
    return NULL;

  result=gsl_ran_beta_pdf(x,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_logistic_pdf(PyObject *self,
			      PyObject *args
			      )
{
  double x;
  
  double mu;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"dd",&x,&mu))
    return NULL;

  result=gsl_ran_logistic_pdf(x,mu);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_pareto_pdf(PyObject *self,
			    PyObject *args
			    )
{
  double x;
  
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&b))
    return NULL;

  result=gsl_ran_pareto_pdf(x,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_weibull_pdf(PyObject *self,
			     PyObject *args
			     )
{
  double x;
  
  double mu,a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&mu,&a))
    return NULL;

  result=gsl_ran_weibull_pdf(x,mu,a);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gumbel1_pdf(PyObject *self,
			     PyObject *args
			     )
{
  double x;
  
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&b))
    return NULL;

  result=gsl_ran_gumbel1_pdf(x,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gumbel2_pdf(PyObject *self,
			     PyObject *args
			     )
{
  double x;
  
  double a,b;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&b))
    return NULL;

  result=gsl_ran_gumbel2_pdf(x,a,b);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_poisson_pdf(PyObject *self,
			     PyObject *args
			     )
{
  unsigned int x;
  
  double mu;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"id",&x,&mu))
    return NULL;

  result=gsl_ran_poisson_pdf(x,mu);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}

static PyObject* ran_bernoulli_pdf(PyObject *self,
			       PyObject *args
			       )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"id",&x,&p))
    return NULL;

  result=gsl_ran_bernoulli_pdf(x,p);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_binomial_pdf(PyObject *self,
			      PyObject *args
			      )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int n,result;

  if (0==PyArg_ParseTuple(args,"idi",&x,&p,&n))
    return NULL;

  result=gsl_ran_binomial_pdf(x,p,n);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_negative_binomial_pdf(PyObject *self,
				       PyObject *args
				       )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int n,result;

  if (0==PyArg_ParseTuple(args,"idi",&x,&p,&n))
    return NULL;

  result=gsl_ran_negative_binomial_pdf(x,p,n);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}
 
static PyObject* ran_pascal_pdf(PyObject *self,
			    PyObject *args
			    )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int k,result;

  if (0==PyArg_ParseTuple(args,"idi",&x,&p,&k))
    return NULL;

  result=gsl_ran_pascal_pdf(x,p,k);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}

static PyObject* ran_geometric_pdf(PyObject *self,
			       PyObject *args
			       )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"id",&x,&p))
    return NULL;

  result=gsl_ran_geometric_pdf(x,p);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_hypergeometric_pdf(PyObject *self,
				    PyObject *args
				    )
{
  unsigned int x;
  
  PyObject* py_result;
  unsigned int n1,n2,t,result;

  if (0==PyArg_ParseTuple(args,"iiii",&x,&n1,&n2,&t))
    return NULL;

  result=gsl_ran_hypergeometric_pdf(x,n1,n2,t);

  py_result=PyLong_FromUnsignedLong(result);

  return py_result;
}

static PyObject* ran_logarithmic_pdf(PyObject *self,
				 PyObject *args
				 )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int result;

  if (0==PyArg_ParseTuple(args,"id",&x,&p))
    return NULL;

  result=gsl_ran_logarithmic_pdf(x,p);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}

/* end pdf*/



static PyMethodDef rngMethods[] = {
  {"env_setup", rng_env_setup, METH_VARARGS},
  {"alloc",rng_alloc,METH_VARARGS},
  {"clone",rng_clone,METH_VARARGS},
  {"free",rng_free,METH_VARARGS},
  {"max",rng_max,METH_VARARGS},
  {"min",rng_min,METH_VARARGS},
  {"name",rng_name,METH_VARARGS},
  {"set",rng_set,METH_VARARGS},
  /* original distributions */
  {"get",rng_get,METH_VARARGS},
  {"uniform",rng_uniform,METH_VARARGS},
  {"uniform_pos",rng_uniform_pos,METH_VARARGS},
  {"uniform_int",rng_uniform_int,METH_VARARGS},
  /* derived distributions */
  {"gaussian",ran_gaussian,METH_VARARGS},
  {"gaussian_ratio_method",ran_gaussian_ratio_method,METH_VARARGS},
  {"ugaussian",ran_ugaussian,METH_VARARGS},
  {"ugaussian_ratio_method",ran_ugaussian_ratio_method,METH_VARARGS},
  {"gaussian_tail",ran_gaussian_tail,METH_VARARGS},
  {"ugaussian_tail",ran_ugaussian_tail,METH_VARARGS},
  {"bivariate_gaussian",ran_bivariate_gaussian,METH_VARARGS},
  {"exponential",ran_exponential,METH_VARARGS},
  {"laplace",ran_laplace,METH_VARARGS},
  {"exppow",ran_exppow,METH_VARARGS},
  {"cauchy",ran_cauchy,METH_VARARGS},
  {"rayleigh",ran_rayleigh,METH_VARARGS},
  {"rayleigh_tail",ran_rayleigh_tail,METH_VARARGS},
  {"levy",ran_levy,METH_VARARGS},
  {"gamma",ran_gamma,METH_VARARGS},
  {"flat",ran_flat,METH_VARARGS},
  {"lognormal",ran_lognormal,METH_VARARGS},
  {"chisq",ran_chisq,METH_VARARGS},
  {"fdist",ran_fdist,METH_VARARGS},
  {"tdist",ran_tdist,METH_VARARGS},
  {"beta",ran_beta,METH_VARARGS},
  {"logistic",ran_logistic,METH_VARARGS},
  {"pareto",ran_pareto,METH_VARARGS},
  {"dir_2d",ran_dir_2d,METH_VARARGS},
  {"dir_2d_trig_method",ran_dir_2d_trig_method,METH_VARARGS},
  {"dir_3d",ran_dir_3d,METH_VARARGS},
  {"dir_nd",ran_dir_nd,METH_VARARGS},
  {"weibull",ran_weibull,METH_VARARGS},
  {"gumbel1",ran_gumbel1,METH_VARARGS},
  {"gumbel2",ran_gumbel2,METH_VARARGS},
  {"poisson",ran_poisson,METH_VARARGS},
  {"bernoulli",ran_bernoulli,METH_VARARGS},
  {"binomial",ran_binomial,METH_VARARGS},
  {"negative_binomial",ran_negative_binomial,METH_VARARGS},
  {"pascal",ran_pascal,METH_VARARGS},
  {"geometric",ran_geometric,METH_VARARGS},
  {"hypergeometric",ran_hypergeometric,METH_VARARGS},
  {"logarithmic",ran_logarithmic,METH_VARARGS},
  /*densities*/
  {"gaussian_pdf",ran_gaussian_pdf,METH_VARARGS},
  {"ugaussian_pdf",ran_ugaussian_pdf,METH_VARARGS},
  {"gaussian_tail_pdf",ran_gaussian_tail_pdf,METH_VARARGS},
  {"ugaussian_tail_pdf",ran_ugaussian_tail_pdf,METH_VARARGS},
  {"bivariate_gaussian_pdf",ran_bivariate_gaussian_pdf,METH_VARARGS},
  {"exponential_pdf",ran_exponential_pdf,METH_VARARGS},
  {"laplace_pdf",ran_laplace_pdf,METH_VARARGS},
  {"exppow_pdf",ran_exppow_pdf,METH_VARARGS},
  {"cauchy_pdf",ran_cauchy_pdf,METH_VARARGS},
  {"rayleigh_pdf",ran_rayleigh_pdf,METH_VARARGS},
  {"rayleigh_tail_pdf",ran_rayleigh_tail_pdf,METH_VARARGS},
  /*missing*/
#if 0
  {"levy_pdf",ran_levy_pdf,METH_VARARGS},
#endif
  {"gamma_pdf",ran_gamma_pdf,METH_VARARGS},
  {"flat_pdf",ran_flat_pdf,METH_VARARGS},
  {"lognormal_pdf",ran_lognormal_pdf,METH_VARARGS},
  {"chisq_pdf",ran_chisq_pdf,METH_VARARGS},
  {"fdist_pdf",ran_fdist_pdf,METH_VARARGS},
  {"tdist_pdf",ran_tdist_pdf,METH_VARARGS},
  {"beta_pdf",ran_beta_pdf,METH_VARARGS},
  {"logistic_pdf",ran_logistic_pdf,METH_VARARGS},
  {"pareto_pdf",ran_pareto_pdf,METH_VARARGS},
  {"weibull_pdf",ran_weibull_pdf,METH_VARARGS},
  {"gumbel1_pdf",ran_gumbel1_pdf,METH_VARARGS},
  {"gumbel2_pdf",ran_gumbel2_pdf,METH_VARARGS},
  {"poisson_pdf",ran_poisson_pdf,METH_VARARGS},
  {"bernoulli_pdf",ran_bernoulli_pdf,METH_VARARGS},
  {"binomial_pdf",ran_binomial_pdf,METH_VARARGS},
  {"negative_binomial_pdf",ran_negative_binomial_pdf,METH_VARARGS},
  {"pascal_pdf",ran_pascal_pdf,METH_VARARGS},
  {"geometric_pdf",ran_geometric_pdf,METH_VARARGS},
  {"hypergeometric_pdf",ran_hypergeometric_pdf,METH_VARARGS},
  {"logarithmic_pdf",ran_logarithmic_pdf,METH_VARARGS},  
  {NULL,     NULL}        /* Sentinel */
};

DL_EXPORT(void) init_rng(void)
{
  PyObject* m;
  m=Py_InitModule("_rng", rngMethods);
  /* already done in init
    gsl_rng_env_setup();
  */
  define_rng_names(m);

  return;
}
