/*
 * author: Achim Gaedke
 * created: Jan 2002
 * file: pygsl/src/_histogrammodule.c
 * $Id$
 */

#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram.h>
#include <Python.h>

static PyObject* _histogram_alloc(PyObject *self,
				  PyObject *args
				  )
{
  PyObject* new_py_histogram;
  gsl_histogram* new_histogram;
  long int n;

  /* get size */
  if (0==PyArg_ParseTuple(args,"l",&n))
      return NULL;

  if (n<=0) {
    gsl_error ("histogram length n must be positive integer",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }

  new_histogram=gsl_histogram_alloc(n);
  if (new_histogram==NULL)
    return NULL;

  new_py_histogram=PyCObject_FromVoidPtr((void*)new_histogram, NULL);
  if (new_py_histogram==NULL) {
    gsl_histogram_free(new_histogram);
    return NULL;
  }
  return new_py_histogram;
}

static PyObject* _histogram_free(PyObject *self,
				 PyObject *args
				 )
{
  PyObject* py_histogram;
  gsl_histogram* histogram;

  if (0==PyArg_ParseTuple(args,"O",&py_histogram)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.free got a NULL pointer" );
    return NULL;
  }
  gsl_histogram_free(histogram);

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* _histogram_set_ranges_uniform(PyObject *self,
					       PyObject *args
					       )
{
  PyObject* py_histogram;
  gsl_histogram * histogram;
  double xmin;
  double xmax;

  if (0==PyArg_ParseTuple(args,"Odd",&py_histogram,&xmin,&xmax)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.set_ranges_uniform got a NULL pointer" );
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram_set_ranges_uniform(histogram,xmin,xmax))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* _histogram_reset(PyObject *self,
				  PyObject *args
				  )
{
  PyObject* py_histogram;
  gsl_histogram* histogram;

  if (0==PyArg_ParseTuple(args,"O",&py_histogram)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.free got a NULL pointer" );
    return NULL;
  }

  gsl_histogram_reset(histogram);

  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram_increment (gsl_histogram * h, double x)
*/
static PyObject* _histogram_increment(PyObject *self,
				      PyObject *args
				      )
{
  PyObject* py_histogram;
  gsl_histogram * histogram;
  int result;
  double x;

  if (0==PyArg_ParseTuple(args,"Od",&py_histogram,&x)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.increment got a NULL pointer" );
    return NULL;
  }
  result=gsl_histogram_increment(histogram,x);
  if (GSL_EDOM==result) {
    /* warning */
    PyObject* gsl_error_module;
    PyObject* gsl_error_dict;
    PyObject* gsl_domain_warning_object;
    int warn_result;
    gsl_error_module=PyImport_ImportModule("pygsl.errors");
    gsl_error_dict=PyModule_GetDict(gsl_error_module);
    Py_INCREF(gsl_error_dict);
    gsl_domain_warning_object=PyDict_GetItemString(gsl_error_dict,"gsl_DomainWarning");
    Py_INCREF(gsl_domain_warning_object);
    warn_result=PyErr_Warn(gsl_domain_warning_object,
			   "value out of histogram range");
    Py_DECREF(gsl_domain_warning_object);
    Py_DECREF(gsl_error_dict);
    Py_DECREF(gsl_error_module);
    if (warn_result==-1)
      /* exception is raised by PyErr_Warn */
      return NULL;
  }
  else if (GSL_SUCCESS!=result)
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

/*
int gsl_histogram_accumulate (gsl_histogram * h, double x, double weight)
*/
static PyObject* _histogram_accumulate(PyObject *self,
				       PyObject *args
				       )
{
  PyObject* py_histogram;
  gsl_histogram * histogram;
  int result;
  double x;
  double weight;

  if (0==PyArg_ParseTuple(args,"Odd",&py_histogram,&x,&weight)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.accumulate got a NULL pointer" );
    return NULL;
  }
  result=gsl_histogram_accumulate(histogram,x,weight);
  if (GSL_EDOM==result) {
    /* warning */
    PyObject* gsl_error_module;
    PyObject* gsl_error_dict;
    PyObject* gsl_domain_warning_object;
    int warn_result;
    gsl_error_module=PyImport_ImportModule("pygsl.errors");
    gsl_error_dict=PyModule_GetDict(gsl_error_module);
    Py_INCREF(gsl_error_dict);
    gsl_domain_warning_object=PyDict_GetItemString(gsl_error_dict,"gsl_DomainWarning");
    Py_INCREF(gsl_domain_warning_object);
    warn_result=PyErr_Warn(gsl_domain_warning_object,
			   "value out of histogram range");
    Py_DECREF(gsl_domain_warning_object);
    Py_DECREF(gsl_error_dict);
    Py_DECREF(gsl_error_module);
    if (warn_result==-1)
      /* exception is raised by PyErr_Warn */
      return NULL;
  }
  else if (GSL_SUCCESS!=result)
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  double gsl_histogram_max (const gsl_histogram * h)
*/

static PyObject* _histogram_max(PyObject *self,
				PyObject *args
				)
{
  PyObject* py_histogram;
  gsl_histogram * histogram;
  if (0==PyArg_ParseTuple(args,"O",&py_histogram)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.max got a NULL pointer" );
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_max(histogram));
}

/*
  double gsl_histogram_min (const gsl_histogram * h)
*/

static PyObject* _histogram_min(PyObject *self,
				PyObject *args
				)
{
  PyObject* py_histogram;
  gsl_histogram * histogram;
  if (0==PyArg_ParseTuple(args,"O",&py_histogram)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.max got a NULL pointer" );
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_min(histogram));
}

/*
  size_t gsl_histogram_bins (const gsl_histogram * h)
*/

static PyObject* _histogram_bins(PyObject *self,
				PyObject *args
				)
{
  PyObject* py_histogram;
  gsl_histogram * histogram;
  if (0==PyArg_ParseTuple(args,"O",&py_histogram)) {
    return NULL;
  }
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.bins got a NULL pointer" );
    return NULL;
  }
  return PyLong_FromLong(gsl_histogram_bins(histogram));
}


/*
  double gsl_histogram_get (const gsl_histogram * h, size_t i)
*/

static PyObject* _histogram_get(PyObject *self,
				PyObject *args
				)
{
  PyObject* py_histogram;
  gsl_histogram* histogram;
  long int n;
  /* get index */
  if (0==PyArg_ParseTuple(args,"Ol",&py_histogram,&n))
      return NULL;
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.get got a NULL pointer" );
    return NULL;
  }
  if (n<0 || n>=histogram->n) {
    gsl_error ("index lies outside valid range of 0 .. n - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_get(histogram,n));
}


/*
  int gsl_histogram_get_range (const gsl_histogram * h, size_t i, double * lower, double * upper)
 */
static PyObject* _histogram_get_range(PyObject *self,
				      PyObject *args
				      )
{
  PyObject* py_histogram;
  gsl_histogram* histogram;
  long int n;
  double lower;
  double upper;

  /* get index */
  if (0==PyArg_ParseTuple(args,"Ol",&py_histogram,&n))
      return NULL;
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.get_range got a NULL pointer" );
    return NULL;
  }
  if (n<0 || n>=histogram->n) {
    gsl_error ("index lies outside valid range of 0 .. n - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram_get_range(histogram,n,&lower,&upper))
    return NULL;
  return Py_BuildValue("(dd)",lower,upper);
}


/*
  int gsl_histogram_find (const gsl_histogram * h, double x, size_t * i)
*/
static PyObject* _histogram_find(PyObject *self,
				 PyObject *args
				 )
{
  PyObject* py_histogram;
  gsl_histogram* histogram;
  double value;
  size_t index;
  /* get index */
  if (0==PyArg_ParseTuple(args,"Od",&py_histogram,&value))
      return NULL;
  histogram=(gsl_histogram*)PyCObject_AsVoidPtr(py_histogram);
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "_histogram.get got a NULL pointer" );
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram_find(histogram, value, &index))
    return NULL;
  return PyLong_FromUnsignedLong(index);
}



static PyMethodDef _histogramMethods[] = {
  {"alloc",_histogram_alloc,METH_VARARGS},
  {"free",_histogram_free,METH_VARARGS},
  {"reset",_histogram_reset,METH_VARARGS},
  {"increment",_histogram_increment,METH_VARARGS},
  {"accumulate",_histogram_accumulate,METH_VARARGS},
  {"set_ranges_uniform",_histogram_set_ranges_uniform,METH_VARARGS},
  {"max",_histogram_max,METH_VARARGS},
  {"min",_histogram_min,METH_VARARGS},
  {"bins",_histogram_bins,METH_VARARGS},
  {"get",_histogram_get,METH_VARARGS},
  {"get_range",_histogram_get_range,METH_VARARGS},
  {"find",_histogram_find,METH_VARARGS},
  {0x0,0x0}
};


DL_EXPORT(void) init_histogram(void)
{
  PyObject* m;
  m=Py_InitModule("_histogram", _histogramMethods);
  return;
}
