/*
 * author: Achim Gaedke
 * created: January 2001
 * file: pygsl/src/histogrammodule.c
 * $Id$
 */

#include <Python.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram.h>

/* my typedef */

typedef struct {
    PyObject_HEAD
    gsl_histogram* h;
} histogram_histogramObject;

/* initialisation and finalisation functions */

static void
histogram_histogram_dealloc(PyObject* self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram!=NULL) gsl_histogram_free(histogram);
  self->ob_type->tp_free(self);
}

static int histogram_histogram_init(PyObject *self,
			       PyObject *args,
			       PyObject *kwds
			       )
{
  gsl_histogram* histogram;
  long int n;
  static char *kwlist[] = {"n",NULL};

  /* initialise histogram pointer */
  ((histogram_histogramObject*)self)->h=NULL;

  /* get size */
  if (!PyArg_ParseTupleAndKeywords(args, kwds,"l",kwlist,&n))
    return -1;

  if (n<=0) {
    gsl_error ("histogram length n must be positive",
               __FILE__,
               __LINE__,
               GSL_EDOM );
    return -1;
  }

  histogram=gsl_histogram_alloc(n);

  if (histogram==NULL)
    return -1;
  gsl_histogram_reset(histogram);
  ((histogram_histogramObject*)self)->h=histogram;
  return 0;
}

static int
histogram_histogram_clear(PyObject *self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.reset got a NULL pointer");
    return -1;
  }
  gsl_histogram_reset(histogram);
  return 0;
}


/*
  the very methods!
 */

static PyObject* histogram_histogram_alloc(PyObject *self,
				      PyObject *args
				      )
{
  gsl_histogram* histogram;
  long int n;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.alloc got a NULL pointer");
    return NULL;
  }

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

  /* free existing histogram */
  gsl_histogram_free(histogram);

  histogram=gsl_histogram_alloc(n);
  /* if this fails, the pointer should be NULL, although this object is useless now */
  (gsl_histogram*)((histogram_histogramObject*)self)->h=histogram;
  if (histogram==NULL)
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* histogram_histogram_set_ranges_uniform(PyObject *self,
						   PyObject *args
						   )
{
  gsl_histogram * histogram;
  double xmin;
  double xmax;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.set_ranges_uniform got a NULL pointer");
    return NULL;
  }
  if (0==PyArg_ParseTuple(args,"dd",&xmin,&xmax)) {
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram_set_ranges_uniform(histogram,xmin,xmax))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}


static PyObject* histogram_histogram_reset(PyObject *self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.reset got a NULL pointer");
    return NULL;
  }
  gsl_histogram_reset(histogram);
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram_increment (gsl_histogram * h, double x)
*/
static PyObject* histogram_histogram_increment(PyObject *self,
				      PyObject *args
				      )
{
  gsl_histogram * histogram;
  int result;
  double x;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.increment got a NULL pointer");
    return NULL;
  }
  if (0==PyArg_ParseTuple(args,"d",&x)) {
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
static PyObject* histogram_histogram_accumulate(PyObject *self,
				       PyObject *args
				       )
{
  gsl_histogram * histogram;
  int result;
  double x;
  double weight;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.accumulate got a NULL pointer");
    return NULL;
  }
  if (0==PyArg_ParseTuple(args,"dd",&x,&weight)) {
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

static PyObject* histogram_histogram_max(PyObject *self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.max got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_max(histogram));
}

/*
  double gsl_histogram_min (const gsl_histogram * h)
*/

static PyObject* histogram_histogram_min(PyObject *self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.min got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_min(histogram));
}

/*
  size_t gsl_histogram_bins (const gsl_histogram * h)
*/

static PyObject* histogram_histogram_bins(PyObject *self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.bins got a NULL pointer");
    return NULL;
  }
  return PyLong_FromLong(gsl_histogram_bins(histogram));
}


/*
  double gsl_histogram_get (const gsl_histogram * h, size_t i)
*/

static PyObject* histogram_histogram_get(PyObject *self,
					 PyObject *args
					 )
{
  gsl_histogram* histogram;
  long int n;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.get got a NULL pointer");
    return NULL;
  }

  /* get index */  
  if (0==PyArg_ParseTuple(args,"l",&n))
      return NULL;
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
static PyObject* histogram_histogram_get_range(PyObject *self,
				      PyObject *args
				      )
{
  gsl_histogram* histogram;
  long int n;
  double lower;
  double upper;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.get_range got a NULL pointer");
    return NULL;
  }

  /* get index */
  if (0==PyArg_ParseTuple(args,"l",&n))
    return NULL;
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
static PyObject* histogram_histogram_find(PyObject *self,
				 PyObject *args
				 )
{
  gsl_histogram* histogram;
  double value;
  size_t index;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.find got a NULL pointer");
    return NULL;
  }

  /* get index */
  if (0==PyArg_ParseTuple(args,"d",&value))
      return NULL;
  if (GSL_SUCCESS!=gsl_histogram_find(histogram, value, &index))
    return NULL;
  return PyLong_FromUnsignedLong(index);
}


/*
  double gsl_histogram_max_val (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_max_val(PyObject *self)
{
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.max_val got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_max_val(histogram));
}

/*
  double gsl_histogram_max_bin (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_max_bin(PyObject *self)
{
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.max_bin got a NULL pointer");
    return NULL;
  }
  return PyLong_FromUnsignedLong(gsl_histogram_max_bin(histogram));
}


/*
  double gsl_histogram_min_val (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_min_val(PyObject *self)
{
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.min_val got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_min_val(histogram));
}

/*
  double gsl_histogram_min_bin (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_min_bin(PyObject *self)
{
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.min_bin got a NULL pointer");
    return NULL;
  }
  return PyLong_FromUnsignedLong(gsl_histogram_min_bin(histogram));
}

/*
  double gsl_histogram_min_val (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_mean(PyObject *self)
{
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.mean got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_mean(histogram));
}


/*
  double gsl_histogram_sigma (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_sigma(PyObject *self)
{
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.sigma got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_sigma(histogram));
}

/*
  methods for map protocol
 */


static int histogram_histogram_mp_length(PyObject *self)
{
  gsl_histogram* histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.bins got a NULL pointer");
    return -1;
  }
  return gsl_histogram_bins(histogram);
}

static PyObject* histogram_histogram_mp_subscript(PyObject *self,
						  PyObject *key
						  )
{
  gsl_histogram* histogram;
  long int k;
  PyObject* my_key;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.get got a NULL pointer");
    return NULL;
  }

  /* get key */
  my_key=PyNumber_Long(key);
  if (my_key==NULL) return NULL;
  k=PyInt_AsLong(my_key);
  if (k<0 || k>=histogram->n) {
    gsl_error ("index lies outside valid range of 0 .. n - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  Py_DECREF(my_key);
  return PyFloat_FromDouble(gsl_histogram_get(histogram,k));
}


static int
histogram_histogram_mp_ass_subscript(PyObject *self, PyObject *key, PyObject *value) {
  gsl_histogram* histogram;
  PyObject* my_key;
  PyObject* my_value;
  double v;
  size_t k;
  /* get histogram struct */
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.get got a NULL pointer");
    return -1;
  }

  /* get key */
  my_key=PyNumber_Long(key);
  if (my_key==NULL) return -1;
  k=PyInt_AsLong(my_key);
  if (k<0 || k>=histogram->n) {
    gsl_error ("index lies outside valid range of 0 .. n - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return -1;
  }
  Py_DECREF(my_key);

  /* get value */
  if (value == NULL)
    v=0;
  else {
    my_value=PyNumber_Float(value);
    if (my_value==NULL) return -1;
    v=PyFloat_AsDouble(value);
    Py_DECREF(my_value);
  }

  histogram->bin[k]=v;
  return 0;
}


/*
  typedef struct {
        inquiry mp_length;
        binaryfunc mp_subscript;
        objobjargproc mp_ass_subscript;
  } PyMappingMethods;
 */

static PyMappingMethods histogram_histogram_as_mapping = {
  (inquiry)histogram_histogram_mp_length, /* inquiry mp_length */
  (binaryfunc)histogram_histogram_mp_subscript, /* binaryfunc mp_subscript */
  (objobjargproc)histogram_histogram_mp_ass_subscript/* objobjargproc mp_ass_subscript */
};


/*
  methods and definitions for method invokation
*/


static PyMethodDef histogram_histogram_methods[] = {
  {"alloc",(PyCFunction)histogram_histogram_alloc,METH_VARARGS,"allocate necessary space"},
  {"set_ranges_uniform", (PyCFunction)histogram_histogram_set_ranges_uniform, METH_VARARGS,
   "set the ranges to uniform distance"},
  {"reset",(PyCFunction)histogram_histogram_reset,METH_NOARGS,"sets all bin values to 0"},
  {"increment",(PyCFunction)histogram_histogram_increment,METH_VARARGS,"increments corresponding bin"},
  {"accumulate",(PyCFunction)histogram_histogram_accumulate,METH_VARARGS,"adds the weight to corresponding bin"},
  {"max",(PyCFunction)histogram_histogram_max,METH_NOARGS,"returns upper range"},
  {"min",(PyCFunction)histogram_histogram_min,METH_NOARGS,"returns lower range"},
  {"bins",(PyCFunction)histogram_histogram_bins,METH_NOARGS,"returns number of bins"},
  {"get",(PyCFunction)histogram_histogram_get,METH_VARARGS,"gets value of indexed bin"},
  {"get_range",(PyCFunction)histogram_histogram_get_range,METH_VARARGS,"gets upper and lower range of indexed bin"},
  {"find",(PyCFunction)histogram_histogram_find,METH_VARARGS,"finds index of corresponding bin"},
  {"max_val",(PyCFunction)histogram_histogram_max_val,METH_NOARGS,"returns maximal bin value"},
  {"max_bin",(PyCFunction)histogram_histogram_max_bin,METH_NOARGS,"returns bin index with maximal value"},
  {"min_val",(PyCFunction)histogram_histogram_min_val,METH_NOARGS,"returns minimal bin value"},
  {"min_bin",(PyCFunction)histogram_histogram_min_bin,METH_NOARGS,"returns bin index with minimal value"},
  {"mean",(PyCFunction)histogram_histogram_mean,METH_NOARGS,"returns mean of histogram"},
  {"sigma",(PyCFunction)histogram_histogram_sigma,METH_NOARGS,"returns std deviation of histogram"},
  {NULL, NULL, 0, NULL}           /* sentinel */
};

static PyObject*
histogram_histogram_getattr(PyObject* obj, char *name)
{
  return Py_FindMethod(histogram_histogram_methods, obj, name);
}

static PyTypeObject histogram_histogramType = {
    PyObject_HEAD_INIT(NULL)
    0,
    "pygsl.histogram.histogram",
    sizeof(histogram_histogramObject),
    0,
    histogram_histogram_dealloc, /*tp_dealloc*/
    0,          /*tp_print*/
    histogram_histogram_getattr,          /*tp_getattr*/
    0,          /*tp_setattr*/
    0,          /*tp_compare*/
    0,          /*tp_repr*/
    0,          /*tp_as_number*/
    0,          /*tp_as_sequence*/
    0,          /*tp_as_mapping*/
    0,          /*tp_hash */
};

static PyMethodDef histogramMethods[] = {
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

void
inithistogram(void)
{
  PyObject* m;
  m=Py_InitModule("histogram", histogramMethods);

  /* init histogram type */
  histogram_histogramType.ob_type = &PyType_Type;
  histogram_histogramType.tp_new=PyType_GenericNew;
  histogram_histogramType.tp_alloc=PyType_GenericAlloc;
  histogram_histogramType.tp_init=histogram_histogram_init;
  histogram_histogramType.tp_free=_PyObject_Del;
  histogram_histogramType.tp_as_mapping=&histogram_histogram_as_mapping;
  /* install histogram type */
  /* important! must increment histogram type reference counter */
  Py_INCREF((PyObject*)&histogram_histogramType);
  PyModule_AddObject(m,"histogram", (PyObject*)&histogram_histogramType);
}
