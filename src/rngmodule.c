/*
 * author: Achim Gaedke
 * created reimplementation: August 2002
 * file: pygsl/src/ngmodule.c
 * $Id$
 */

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_errno.h>
#include <Python.h>


#if 0
/* maybe we will recycle this code later */
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
#endif

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
  double result;

  if (0==PyArg_ParseTuple(args,"id",&x,&mu))
    return NULL;

  result=gsl_ran_poisson_pdf(x,mu);

  py_result=PyFloat_FromDouble(result);
  return py_result;
}

static PyObject* ran_bernoulli_pdf(PyObject *self,
			       PyObject *args
			       )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"id",&x,&p))
    return NULL;

  result=gsl_ran_bernoulli_pdf(x,p);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_binomial_pdf(PyObject *self,
			      PyObject *args
			      )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int n;
  double result;

  if (0==PyArg_ParseTuple(args,"idi",&x,&p,&n))
    return NULL;

  result=gsl_ran_binomial_pdf(x,p,n);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_negative_binomial_pdf(PyObject *self,
					   PyObject *args
					   )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int n;
  double result;

  if (0==PyArg_ParseTuple(args,"idi",&x,&p,&n))
    return NULL;

  result=gsl_ran_negative_binomial_pdf(x,p,n);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}
 
static PyObject* ran_pascal_pdf(PyObject *self,
			    PyObject *args
			    )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  unsigned int k;
  double result;

  if (0==PyArg_ParseTuple(args,"idi",&x,&p,&k))
    return NULL;

  result=gsl_ran_pascal_pdf(x,p,k);

  py_result=PyFloat_FromDouble(result);
  return py_result;
}

static PyObject* ran_geometric_pdf(PyObject *self,
			       PyObject *args
			       )
{
  unsigned int x;
  
  double p;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"id",&x,&p))
    return NULL;

  result=gsl_ran_geometric_pdf(x,p);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_hypergeometric_pdf(PyObject *self,
				    PyObject *args
				    )
{
  unsigned int x;
  
  PyObject* py_result;
  unsigned int n1,n2,t;
  double result;
  if (0==PyArg_ParseTuple(args,"iiii",&x,&n1,&n2,&t))
    return NULL;
  result=gsl_ran_hypergeometric_pdf(x,n1,n2,t);
  py_result=PyFloat_FromDouble(result);
  return py_result;
}

static PyObject* ran_logarithmic_pdf(PyObject *self,
				 PyObject *args
				 )
{
  unsigned int x;
  double p;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"id",&x,&p))
    return NULL;

  result=gsl_ran_logarithmic_pdf(x,p);

  py_result=PyFloat_FromDouble(result);
  return py_result;
}


static PyObject* ran_landau_pdf(PyObject *self,
				PyObject *args
				)
{
  double p;
  PyObject* py_result;
  double result;
  if (0==PyArg_ParseTuple(args,"d",&p))
    return NULL;
  result=gsl_ran_landau_pdf(p);
  py_result=PyFloat_FromDouble(result);
  return py_result;
}

static PyObject* ran_erlang_pdf(PyObject *self,
				PyObject *args
				)
{
  double x;
  double a;
  double n;
  PyObject* py_result;
  double result;
  if (0==PyArg_ParseTuple(args,"ddd",&x,&a,&n))
    return NULL;
  result=gsl_ran_erlang_pdf(x,a,n);
  py_result=PyFloat_FromDouble(result);
  return py_result;
}

/* end pdf*/

static PyMethodDef rngMethods[] = {
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
  {"landau_pdf",ran_landau_pdf,METH_VARARGS},  
  {"erlang_pdf",ran_erlang_pdf,METH_VARARGS},  
  {NULL, NULL, 0}        /* Sentinel */
};


/*
  start of implementation of rng classes
*/


static
PyObject* class___init__(PyObject *self,
			 PyObject* args) {

  const gsl_rng_type* rng_type=gsl_rng_default;
  gsl_rng* my_rng=NULL;
  PyObject* thisInstance;
  PyObject* py_rng;

  if (!PySequence_Check(args)) {
    PyErr_SetString(PyExc_Exception,"expected sequence");
    return  NULL;
  }
  if (PySequence_Length(args)>2 || PySequence_Length(args)==0) {
    PyErr_SetString(PyExc_Exception,"expected one or two arguments");
    return  NULL;
  }
  thisInstance=PySequence_GetItem(args,0);
  if (!PyInstance_Check(thisInstance)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    Py_DECREF(thisInstance);
    return  NULL;
  }

  /* the type is given as name or CObject or a rng is copied/cloned */
  if (PySequence_Length(args)==2) {
    PyObject* typeArg=PySequence_GetItem(args,1);
    /* the type is given */
    if (PyCObject_Check(typeArg)) {
      rng_type=(gsl_rng_type*)PyCObject_AsVoidPtr(typeArg);
    }
    /* find by name */
    else if (PyString_Check(typeArg)) {
      const gsl_rng_type** t=gsl_rng_types_setup();
      /* find rng type */
      while ((*t)!=NULL) {
	PyObject* nameObject=PyString_FromString((*t)->name);
	int cmpResult=PyObject_Compare(nameObject, typeArg);
	Py_DECREF(nameObject);
	if (cmpResult==0) break;
	t++;
      }
      if ((*t)==NULL) {
	PyErr_SetString(PyExc_Exception,"rng does not exist");
	Py_DECREF(typeArg);
	Py_DECREF(thisInstance);
	return NULL;
      }
      rng_type=*t;
    }
    /* clone a rng */
    else if (PyInstance_Check(typeArg)) {
      /* check if these are the same classes */
      PyObject* orig_rng;
      if ((((PyInstanceObject*)typeArg)->in_class)!=(((PyInstanceObject*)thisInstance)->in_class)) {
	PyErr_SetString(PyExc_Exception,"cloning only permitted between same classes");
	Py_DECREF(thisInstance);
	Py_DECREF(typeArg);
	return NULL;
      }
      /* clone the rng */
      orig_rng=PyObject_GetAttrString(typeArg,"_rng");
      if (orig_rng==NULL)
	return  NULL;
      my_rng=gsl_rng_clone((gsl_rng*)PyCObject_AsVoidPtr(orig_rng));
      py_rng=PyCObject_FromVoidPtr((void*)my_rng,(void (*)(void*))gsl_rng_free);
      if (py_rng==NULL) {
	return NULL;
      }

      /* and put it into the instance */
      PyObject_SetAttrString(thisInstance,"_rng",py_rng);
      Py_DECREF(py_rng);
      Py_DECREF(thisInstance);
      Py_DECREF(orig_rng);

      /* exit here immediatley */
      Py_INCREF(Py_None);
      return Py_None;
    }
    else {
      PyErr_SetString(PyExc_Exception,"expected string or CObject as argument");
      Py_DECREF(thisInstance);
      Py_DECREF(typeArg);
      return NULL;
    }
    Py_DECREF(typeArg);
  }

  /* instantiate the gsl rng */
  my_rng=gsl_rng_alloc(rng_type);
  if (my_rng==NULL) {
    /* a gsl error occured */
    return NULL;
  }
  
  /* create an apropriate object */
  py_rng=PyCObject_FromVoidPtr((void*)my_rng,(void (*)(void*))gsl_rng_free);
  if (py_rng==NULL) {
    return NULL;
  }

  /* and put it into the class */
  PyObject_SetAttrString(thisInstance,"_rng",py_rng);
  Py_DECREF(py_rng);
  Py_DECREF(thisInstance);

  Py_INCREF(Py_None);
  return Py_None;
}

static
PyObject* class___del__(PyObject *self,
			PyObject* arg) {

  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  PyObject_DelAttrString(arg,"_rng");

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* class_rng_name(PyObject *self,
				PyObject *arg
				)
{
  PyObject* py_rng=NULL;
  gsl_rng* rng=NULL;
  const char* name;

  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  py_rng=PyObject_GetAttrString(arg,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  name=gsl_rng_name(rng);
  Py_DECREF(py_rng);
  return PyString_FromString(name);
}

static PyObject* class_rng_set(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  PyObject* class_instance;
  gsl_rng* rng;
  unsigned long int seed;

  if (0==PyArg_ParseTuple(args,"O!l",&PyInstance_Type,&class_instance,&seed))
    return NULL;
  py_rng=PyObject_GetAttrString(class_instance,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  gsl_rng_set(rng,seed);
  Py_DECREF(py_rng);

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* class_rng_get(PyObject *self,
			       PyObject *arg) {
  unsigned long int result;
  PyObject* py_rng;
  gsl_rng* rng;
  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  py_rng=PyObject_GetAttrString(arg,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_rng_get(rng);
  Py_DECREF(py_rng);
  return PyLong_FromUnsignedLong(result);
}

static PyObject* class_rng_max(PyObject *self,
			       PyObject *arg) {
  unsigned long int result;
  PyObject* py_rng;
  gsl_rng* rng;
  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  py_rng=PyObject_GetAttrString(arg,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_rng_max(rng);
  Py_DECREF(py_rng);
  return PyLong_FromUnsignedLong(result);
}

static PyObject* class_rng_min(PyObject *self,
			       PyObject *arg) {
  unsigned long int result;
  PyObject* py_rng;
  gsl_rng* rng;
  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  py_rng=PyObject_GetAttrString(arg,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_rng_min(rng);
  Py_DECREF(py_rng);
  return PyLong_FromUnsignedLong(result);
}

static PyObject* class_rng_uniform(PyObject *self,
				   PyObject *arg
				   )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double result;
  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  py_rng=PyObject_GetAttrString(arg,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_rng_uniform(rng);
  Py_DECREF(py_rng);
  return PyFloat_FromDouble(result);
}

static PyObject* class_rng_uniform_pos(PyObject *self,
				       PyObject *arg) {
  PyObject* py_rng;
  gsl_rng* rng;
  double result;
  if (!PyInstance_Check(arg)) {
    PyErr_SetString(PyExc_Exception,"expected instance as first argument");
    return  NULL;
  }
  py_rng=PyObject_GetAttrString(arg,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_rng_uniform(rng);
  Py_DECREF(py_rng);
  return PyFloat_FromDouble(result);
}

static PyObject* class_rng_uniform_int(PyObject *self,
				       PyObject *args) {
  PyObject* class_instance;
  PyObject* py_rng;
  gsl_rng* rng;
  unsigned long int n;
  unsigned long int result;

  if (0==PyArg_ParseTuple(args,"O!l",&PyInstance_Type,&class_instance,&n))
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
  py_rng=PyObject_GetAttrString(class_instance,"_rng");
  if (py_rng==NULL)
    return NULL;
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_rng_uniform_int(rng,n);
  Py_DECREF(py_rng);
  return PyLong_FromUnsignedLong(result);
}

/* other distributions */

static PyObject* ran_gaussian(PyObject *self,
			      PyObject *args
			      )
{
  PyObject* py_rng;
  gsl_rng* rng;
  double sigma;
  double result;

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng, &sigma))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);
  result=gsl_ran_gaussian(rng,sigma);  
  Py_DECREF(py_rng);
  return PyFloat_FromDouble(result);
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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&sigma))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(py_rng);

  result=gsl_ran_gaussian_ratio_method(rng,sigma);
  Py_DECREF(py_rng);
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

  if (0==PyArg_ParseTuple(args,"O!", &PyInstance_Type, &py_rng))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_ugaussian(rng);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!", &PyInstance_Type, &py_rng))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_ugaussian_ratio_method(rng);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&sigma,&a))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_gaussian_tail(rng,sigma,a);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&a))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_ugaussian_tail(rng,a);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!ddd", &PyInstance_Type, &py_rng,&sigma_x,&sigma_y,&rho))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  gsl_ran_bivariate_gaussian(rng,sigma_x, sigma_y, rho, &x, &y);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&mu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_exponential(rng,mu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&mu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_laplace(rng,mu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&mu,&a))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_exppow(rng,mu,a);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&mu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_cauchy(rng,mu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&sigma))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_rayleigh(rng,sigma);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&sigma))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_rayleigh_tail(rng,a,sigma);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&mu,&a))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_levy(rng,mu,a);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&b))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_gamma(rng,a,b);
  Py_DECREF(py_rng);

  py_result=PyFloat_FromDouble(result);

  return py_result;
}

static PyObject* ran_gamma_int(PyObject *self,
			       PyObject *args
			       )
{
  PyObject* py_rng;
  gsl_rng* rng;
  long int a;
  PyObject* py_result;
  double result;

  if (0==PyArg_ParseTuple(args,"O!l", &PyInstance_Type, &py_rng,&a))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_gamma_int(rng,a);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&b))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_flat(rng,a,b);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&zeta,&sigma))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_lognormal(rng,zeta,sigma);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&nu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_chisq(rng,nu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&nu1,&nu2))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_fdist(rng,nu1,nu2);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&nu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_tdist(rng,nu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&b))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_beta(rng,a,b);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&mu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_logistic(rng,mu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&b))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_pareto(rng,a,b);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!", &PyInstance_Type, &py_rng))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  gsl_ran_dir_2d(rng, &x, &y);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!", &PyInstance_Type, &py_rng))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  gsl_ran_dir_2d_trig_method(rng, &x, &y);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!", &PyInstance_Type, &py_rng))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  gsl_ran_dir_3d(rng, &x, &y, &z);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!i", &PyInstance_Type, &py_rng,&n))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

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
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&mu,&a))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_weibull(rng,mu,a);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&b))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_gumbel1(rng,a,b);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&b))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_gumbel2(rng,a,b);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&mu))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_poisson(rng,mu);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&p))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_bernoulli(rng,p);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!di", &PyInstance_Type, &py_rng,&p,&n))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_binomial(rng,p,n);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!di", &PyInstance_Type, &py_rng,&p,&n))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_negative_binomial(rng,p,n);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!di", &PyInstance_Type, &py_rng,&p,&k))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_pascal(rng,p,k);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&p))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_geometric(rng,p);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!iii", &PyInstance_Type, &py_rng,&n1,&n2,&t))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_hypergeometric(rng,n1,n2,t);
  Py_DECREF(py_rng);

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

  if (0==PyArg_ParseTuple(args,"O!d", &PyInstance_Type, &py_rng,&p))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));

  result=gsl_ran_logarithmic(rng,p);
  Py_DECREF(py_rng);

  py_result=PyLong_FromUnsignedLong(result);
  return py_result;
}


static PyObject* ran_landau(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  double result;
  if (0==PyArg_ParseTuple(args,"O!", &PyInstance_Type, &py_rng))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));
  result=gsl_ran_landau(rng);
  Py_DECREF(py_rng);
  py_result=PyFloat_FromDouble(result);
  return py_result;
}

static PyObject* ran_erlang(PyObject *self,
			    PyObject *args
			    )
{
  PyObject* py_rng;
  gsl_rng* rng;
  PyObject* py_result;
  double a;
  double n;
  double result;
  if (0==PyArg_ParseTuple(args,"O!dd", &PyInstance_Type, &py_rng,&a,&n))
    return NULL;
  py_rng=PyObject_GetAttrString(py_rng,"_rng");
  rng=(gsl_rng*)PyCObject_AsVoidPtr(PyObject_GetAttrString(py_rng,"_rng"));
  result=gsl_ran_erlang(rng,a,n);
  Py_DECREF(py_rng);
  py_result=PyFloat_FromDouble(result);
  return py_result;
}

static PyMethodDef classMethods[] = {
  {"__init__", class___init__, METH_VARARGS,NULL},
  {"__del__", class___del__, METH_O, NULL},
  {"set",class_rng_set,METH_VARARGS,NULL},
  {"max",class_rng_max,METH_O,NULL},
  {"min",class_rng_min,METH_O,NULL},
  {"name",class_rng_name,METH_O,NULL},
  /* some basic methods for random number generation */
  {"get",class_rng_get,METH_O,NULL},
  {"uniform",class_rng_uniform, METH_O, NULL},
  {"uniform_int",class_rng_uniform_int, METH_VARARGS, NULL},
  {"uniform_pos",class_rng_uniform_pos, METH_O, NULL},
  /* distributions */
  {"gaussian",ran_gaussian,METH_VARARGS, NULL},
  {"gaussian_ratio_method",ran_gaussian_ratio_method,METH_VARARGS, NULL},
  {"ugaussian",ran_ugaussian,METH_VARARGS, NULL},
  {"ugaussian_ratio_method",ran_ugaussian_ratio_method,METH_VARARGS, NULL},
  {"gaussian_tail",ran_gaussian_tail,METH_VARARGS, NULL},
  {"ugaussian_tail",ran_ugaussian_tail,METH_VARARGS, NULL},
  {"bivariate_gaussian",ran_bivariate_gaussian,METH_VARARGS, NULL},
  {"exponential",ran_exponential,METH_VARARGS, NULL},
  {"laplace",ran_laplace,METH_VARARGS, NULL},
  {"exppow",ran_exppow,METH_VARARGS, NULL},
  {"cauchy",ran_cauchy,METH_VARARGS, NULL},
  {"rayleigh",ran_rayleigh,METH_VARARGS, NULL},
  {"rayleigh_tail",ran_rayleigh_tail,METH_VARARGS, NULL},
  {"levy",ran_levy,METH_VARARGS, NULL},
  {"gamma",ran_gamma,METH_VARARGS, NULL},
  {"gamma_int",ran_gamma_int,METH_VARARGS, NULL},
  {"flat",ran_flat,METH_VARARGS, NULL},
  {"lognormal",ran_lognormal,METH_VARARGS, NULL},
  {"chisq",ran_chisq,METH_VARARGS, NULL},
  {"fdist",ran_fdist,METH_VARARGS, NULL},
  {"tdist",ran_tdist,METH_VARARGS, NULL},
  {"beta",ran_beta,METH_VARARGS, NULL},
  {"logistic",ran_logistic,METH_VARARGS, NULL},
  {"pareto",ran_pareto,METH_VARARGS, NULL},
  {"dir_2d",ran_dir_2d,METH_VARARGS, NULL},
  {"dir_2d_trig_method",ran_dir_2d_trig_method,METH_VARARGS, NULL},
  {"dir_3d",ran_dir_3d,METH_VARARGS, NULL},
  {"dir_nd",ran_dir_nd,METH_VARARGS, NULL},
  {"weibull",ran_weibull,METH_VARARGS, NULL},
  {"gumbel1",ran_gumbel1,METH_VARARGS, NULL},
  {"gumbel2",ran_gumbel2,METH_VARARGS, NULL},
  {"poisson",ran_poisson,METH_VARARGS, NULL},
  {"bernoulli",ran_bernoulli,METH_VARARGS, NULL},
  {"binomial",ran_binomial,METH_VARARGS, NULL},
  {"negative_binomial",ran_negative_binomial,METH_VARARGS, NULL},
  {"pascal",ran_pascal,METH_VARARGS, NULL},
  {"geometric",ran_geometric,METH_VARARGS, NULL},
  {"hypergeometric",ran_hypergeometric,METH_VARARGS, NULL},
  {"logarithmic",ran_logarithmic,METH_VARARGS, NULL},
  {"landau",ran_landau,METH_VARARGS, NULL},
  {"erlang",ran_erlang,METH_VARARGS, NULL},
  {NULL, NULL, 0, NULL}
};


static PyObject* derived_rng___init__(PyObject* self,
				      PyObject* args) {
  PyObject* thisInstance;
  PyObject* py_result;
  if (0==PyArg_ParseTuple(args,"O!",&PyInstance_Type,&thisInstance))
    return NULL;

  if (self==NULL || !PyCObject_Check(self)) {
    PyErr_SetString(PyExc_RuntimeError, "found no type information in *self while initialising" );
    return NULL;
  }

  /* initialise base class with gsl_rng_type handover */
  {
    PyClassObject* base=(PyClassObject*)PySequence_GetItem(((PyInstanceObject*)thisInstance)->in_class->cl_bases,0);
    PyObject* base_init=PyMethod_Function(PyMapping_GetItemString(base->cl_dict,"__init__"));
    py_result=PyObject_CallFunction(base_init, "OO", thisInstance, self);
  }
  return py_result;
}

static PyMethodDef derivedClassMethods[] = {
  {"__init__", derived_rng___init__, METH_VARARGS,NULL},
  {NULL, NULL, 0, NULL}
};


void make_baseclass(PyObject* module) {
  /* start creating the basic rng class */
  PyObject* module_dict=PyModule_GetDict(module);
  PyObject* new_class=NULL;
  PyObject* new_class_dict=PyDict_New();
  PyObject* new_class_name=PyString_FromString("rng");

  /* fill dictionary with some stuff */
  {
    PyObject* stuff=PyString_FromString("random number generator class");
    PyDict_SetItemString(new_class_dict,"__doc__",stuff);
    Py_DECREF(stuff);
  }

  /* create new class*/
  new_class=PyClass_New(NULL,new_class_dict,new_class_name);
  Py_DECREF(new_class_dict);

  /* add some methods */
  {
    PyMethodDef* methods_pos=classMethods;
    while (methods_pos->ml_name!=NULL)
      {
	PyObject* myFunc=PyCFunction_New(methods_pos,(PyObject*)NULL);
	PyObject* myMeth=PyMethod_New(myFunc, (PyObject*)NULL, new_class);
	Py_DECREF(myFunc);
	PyObject_SetAttrString(new_class,methods_pos->ml_name,myMeth);
	Py_DECREF(myMeth);
	methods_pos++;
      }
  }
  /* and provide it under the same name*/
  PyDict_SetItem(module_dict,new_class_name,new_class);
  Py_DECREF(new_class_name);
  Py_DECREF(new_class);
}

void make_subclasses(PyObject* module) {

  PyObject* module_dict=PyModule_GetDict(module);
  PyObject* base_class=PyDict_GetItemString(module_dict,"rng");
  const gsl_rng_type** thisRNGType=gsl_rng_types_setup();

  /* provide other rng types as subclasses of rng */
  
  while ((*thisRNGType)!=NULL) {
    /* create a new class with seperate name */
    PyObject* derived_class_name=PyString_FromString("rng_");
    PyObject* derived_class_dict=PyDict_New();
    PyObject* derived_class;
    PyObject* base_classes=PyTuple_New(1);

    PyTuple_SET_ITEM(base_classes,0,base_class); /* the base of this class is the basic rng */
    PyString_ConcatAndDel(&derived_class_name,
			  PyString_FromString((*thisRNGType)->name));/* prefix the name */

    /* create the very class object */
    derived_class=PyClass_New(base_classes,derived_class_dict,derived_class_name);
    Py_DECREF(base_classes);
    Py_DECREF(derived_class_dict);
    if (derived_class==NULL) {
      Py_DECREF(derived_class_name);
      return;
    }
    
    /* there is only one special element: the __init__ function */
    {
      PyMethodDef* methods_pos=derivedClassMethods;
      /* grant access to rng type of this class */
      PyObject* myRNGType=PyCObject_FromVoidPtr((void*)(*thisRNGType), NULL);
      PyObject* myFunc=PyCFunction_New(methods_pos, myRNGType);
      PyObject* myMeth=PyMethod_New(myFunc, (PyObject*)NULL, derived_class);
      Py_DECREF(myRNGType);
      Py_DECREF(myFunc);
      PyObject_SetAttrString(derived_class,methods_pos->ml_name,myMeth);
      Py_DECREF(myMeth);
      thisRNGType++;
    }
    /* make it available to the module */
    PyDict_SetItem(module_dict,derived_class_name,derived_class);
    Py_DECREF(derived_class_name);
    Py_DECREF(derived_class);
  }

  Py_DECREF(base_class);
  return;
}

DL_EXPORT(void) initrng(void) {
  PyObject* m;
  m=Py_InitModule("rng", rngMethods);
  /* already done in init
    gsl_rng_env_setup();
  */
  make_baseclass(m);
  make_subclasses(m);
  return;
}
