/*
 * author: Achim Gaedke
 * created: January 2001
 * file: pygsl/src/histogrammodule.c
 * $Id$
 */

#include <Python.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_histogram2d.h>

/*
 *
 * histogram type
 * for 1d histogram data
 *
 */


/* my typedef */

staticforward PyTypeObject histogram_histogramType;

typedef struct {
    PyObject_HEAD
    gsl_histogram* h;
} histogram_histogramObject;


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

static PyObject* histogram_histogram_mean(PyObject *self) {
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

static PyObject* histogram_histogram_sigma(PyObject *self) {
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.sigma got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_sigma(histogram));
}

/*
  double gsl_histogram_sum (const gsl_histogram * h)
 */

static PyObject* histogram_histogram_sum(PyObject *self) {
  gsl_histogram * histogram;
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.sum got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram_sum(histogram));
}


/*
  int gsl_histogram_set_ranges (gsl_histogram * h, const double range[], size_t size)
 */

static PyObject* histogram_histogram_set_ranges(PyObject *self, PyObject *ranges) {

  gsl_histogram * histogram;
  int gsl_result;
  double* double_ranges=NULL;
  double last_value=0;
  size_t size;
  size_t pos;

  /* get gsl_histogram struct */
  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.set_ranges got a NULL pointer");
    return NULL;
  }
  
  Py_INCREF(ranges);

  if (0==PySequence_Check(ranges)) {
    PyErr_SetString(PyExc_TypeError,
		    "histogram.set_ranges needs a sequence type");
    Py_DECREF(ranges);
    return NULL;
  }

  /* determine size */
  size=PySequence_Size(ranges);
  if (size<=0 || size!=histogram->n+1) {
    PyErr_SetString(PyExc_TypeError,
		    "histogram.set_ranges needs a sequence with n+1 elements");    
    Py_DECREF(ranges);
    return NULL;
  }

  /* allocate double array */
  double_ranges=malloc(sizeof(double)*size);
  if (double_ranges==NULL) {
    PyErr_SetString(PyExc_MemoryError,
		    "histogram.set_ranges could not allocate double field");    
    Py_DECREF(ranges);
    return NULL;
  }
  
  /* copy values to double field */
  for(pos=0; pos<size; pos++) {
    double value;
    PyObject* pos_value;
    PyObject* float_value;
    pos_value=PySequence_GetItem(ranges,pos);
    float_value=PyNumber_Float(pos_value);
    Py_DECREF(pos_value);
    if (float_value==NULL) {
      PyErr_SetString(PyExc_TypeError,
		      "histogram.set_ranges expects sequence of numbers");    
      Py_DECREF(ranges);
      free(double_ranges);
      return NULL;
    }
    value=PyFloat_AsDouble(float_value);
    Py_DECREF(float_value);    
    if (pos>0 && last_value>=value) {
      PyErr_SetString(PyExc_TypeError,
		      "histogram.set_ranges expects monotonically increasing sequence of numbers");    
      Py_DECREF(ranges);
      free(double_ranges);
      return NULL;      
    }
    double_ranges[pos]=value;
    last_value=value;
  }
  Py_DECREF(ranges);

  /* set ranges to gsl_histogram structure */
  gsl_result=gsl_histogram_set_ranges(histogram,double_ranges,size);
  free(double_ranges);

  if (GSL_SUCCESS!=gsl_result) return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}


static PyObject* histogram_histogram_shift(PyObject *self,
					   PyObject *arg) {
  gsl_histogram* histogram;
  PyObject* float_object;
  double offset;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.shift got a NULL pointer");
    return NULL;
  }

  /* get offset */
  float_object=PyNumber_Float(arg);
  if (float_object==NULL) {
    PyErr_SetString(PyExc_TypeError, "histogram.shift expects a number");
    return NULL;
  }
  offset=PyFloat_AsDouble(float_object);
  Py_DECREF(float_object);
  if (GSL_SUCCESS!=gsl_histogram_shift(histogram, offset))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* histogram_histogram_scale(PyObject *self,
					   PyObject *arg) {
  gsl_histogram* histogram;
  PyObject* float_object;
  double scale;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.scale got a NULL pointer");
    return NULL;
  }

  /* get offset */
  float_object=PyNumber_Float(arg);
  if (float_object==NULL) {
    PyErr_SetString(PyExc_TypeError, "histogram.scale expects a number");
    return NULL;
  }
  scale=PyFloat_AsDouble(float_object);
  Py_DECREF(float_object);
  if (GSL_SUCCESS!=gsl_histogram_scale(histogram, scale))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}


/*
 int gsl_histogram_equal_bins_p (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram_equal_bins_p(PyObject *self,
						  PyObject *arg) {
  gsl_histogram* histogram;
  gsl_histogram* histogram2;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.equal_bins_p got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogramType)) {
    PyErr_SetString(PyExc_TypeError, "histogram.equal_bins_p requires pygsl.histogram.histogram");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram*)((histogram_histogramObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram_equal_bins_p(histogram,histogram2);
  Py_DECREF(arg);
  return PyInt_FromLong(result);
}

/*
 int gsl_histogram_add (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram_add(PyObject *self,
					 PyObject *arg) {
  gsl_histogram* histogram;
  gsl_histogram* histogram2;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.add got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogramType)) {
    PyErr_SetString(PyExc_TypeError, "histogram.add requires pygsl.histogram.histogram");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram*)((histogram_histogramObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram_add(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 int gsl_histogram_sub (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram_sub(PyObject *self,
					 PyObject *arg) {
  gsl_histogram* histogram;
  gsl_histogram* histogram2;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.sub got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogramType)) {
    PyErr_SetString(PyExc_TypeError, "histogram.sub requires pygsl.histogram.histogram");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram*)((histogram_histogramObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram_sub(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 int gsl_histogram_mul (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram_mul(PyObject *self,
					 PyObject *arg) {
  gsl_histogram* histogram;
  gsl_histogram* histogram2;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.mul got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogramType)) {
    PyErr_SetString(PyExc_TypeError, "histogram.mul requires pygsl.histogram.histogram");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram*)((histogram_histogramObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram_mul(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 int gsl_histogram_div (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram_div(PyObject *self,
					 PyObject *arg) {
  gsl_histogram* histogram;
  gsl_histogram* histogram2;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.div got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogramType)) {
    PyErr_SetString(PyExc_TypeError, "histogram.div requires pygsl.histogram.histogram");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram*)((histogram_histogramObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram_div(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* histogram_histogram_clone(PyObject *self) {

  gsl_histogram* histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  gsl_histogram* clone;
  PyObject* return_object;
  
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.clone got a NULL pointer");
    return NULL;
  }

  clone=gsl_histogram_clone(histogram);
  if (clone==NULL)
    return NULL;

  return_object=PyType_GenericAlloc(&histogram_histogramType,1);
  if (return_object==NULL) {
    gsl_histogram_free(clone);
    return NULL;
  }
  ((histogram_histogramObject*)return_object)->h=clone;
  return return_object;
}

/*
 int gsl_histogram_copy (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram_copy(PyObject *self,
					  PyObject *arg) {
  gsl_histogram* histogram;
  gsl_histogram* histogram2;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.copy got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogramType)) {
    PyErr_SetString(PyExc_TypeError, "histogram.copy requires pygsl.histogram.histogram");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram*)((histogram_histogramObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram_memcpy(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram_fread (FILE * stream, gsl_histogram * h)
*/

static PyObject* histogram_histogram_read(PyObject *self,
					  PyObject *arg) {
  gsl_histogram* histogram;
  FILE*  stream;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.read got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get file from argument */
  if (arg==NULL || !PyFile_Check(arg)) {
    PyErr_SetString(PyExc_TypeError, "histogram.read requires file type");
    Py_DECREF(arg);
    return NULL;
  }

  stream=PyFile_AsFile(arg);
  result=gsl_histogram_fread(stream,histogram);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram_fwrite (FILE * stream, const gsl_histogram * h)
*/

static PyObject* histogram_histogram_write(PyObject *self,
					   PyObject *arg) {
  gsl_histogram* histogram;
  FILE*  stream;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.write got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get file from argument */
  if (arg==NULL || !PyFile_Check(arg)) {
    PyErr_SetString(PyExc_TypeError, "histogram.write requires file type");
    Py_DECREF(arg);
    return NULL;
  }

  stream=PyFile_AsFile(arg);
  result=gsl_histogram_fwrite(stream,histogram);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram_fscanf (FILE * stream, gsl_histogram * h)
*/

static PyObject* histogram_histogram_scanf(PyObject *self,
					   PyObject *arg) {
  gsl_histogram* histogram;
  FILE*  stream;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.scanf got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get file from argument */
  if (arg==NULL || !PyFile_Check(arg)) {
    PyErr_SetString(PyExc_TypeError, "histogram.scanf requires file type");
    Py_DECREF(arg);
    return NULL;
  }

  stream=PyFile_AsFile(arg);
  result=gsl_histogram_fscanf(stream,histogram);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram_fprintf (FILE * stream, const gsl_histogram * h, const char * range_format, const char * bin_format)
*/

static PyObject* histogram_histogram_printf(PyObject *self,
					    PyObject *arg) {
  gsl_histogram* histogram;
  PyObject* the_file;
  FILE*  stream=NULL;
  char* range_format=NULL;
  char* bin_format=NULL;
  int result;

  histogram=(gsl_histogram*)((histogram_histogramObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.printf got a NULL pointer");
    return NULL;
  }

  if (0==PyArg_ParseTuple(arg,"O!|ss",&PyFile_Type,&the_file,&range_format,&bin_format)) {
    return NULL;
  }

  if (range_format==NULL)
    range_format="%g";
  if (bin_format==NULL)
    bin_format="%g";

  Py_INCREF(the_file);
  stream=PyFile_AsFile(the_file);
  result=gsl_histogram_fprintf(stream,histogram,range_format,bin_format);
  Py_DECREF(the_file);

  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  method table
*/

static PyMethodDef histogram_histogram_methods[] = {
  {"alloc",(PyCFunction)histogram_histogram_alloc,METH_VARARGS,"allocate necessary space"},
  {"set_ranges_uniform", (PyCFunction)histogram_histogram_set_ranges_uniform, METH_VARARGS,"set the ranges to uniform distance"},
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
  {"sum",(PyCFunction)histogram_histogram_sum,METH_NOARGS,"returns sum of bin values"},
  {"set_ranges",(PyCFunction)histogram_histogram_set_ranges,METH_O,"sets range according given sequence"},
  {"shift",(PyCFunction)histogram_histogram_shift,METH_O,"shifts the contents of the bins by the given offset"},
  {"scale",(PyCFunction)histogram_histogram_scale,METH_O,"multiplies the contents of the bins by the given scale"},
  {"equal_bins_p",(PyCFunction)histogram_histogram_equal_bins_p,METH_O,"true if the all of the individual bin ranges are identical"},
  {"add",(PyCFunction)histogram_histogram_add,METH_O,"adds the contents of the bins"},
  {"sub",(PyCFunction)histogram_histogram_sub,METH_O,"substracts the contents of the bins"},
  {"mul",(PyCFunction)histogram_histogram_mul,METH_O,"multiplicates the contents of the bins"},
  {"div",(PyCFunction)histogram_histogram_div,METH_O,"divides the contents of the bins"},
  {"clone",(PyCFunction)histogram_histogram_clone,METH_NOARGS,"returns a new copy of this histogram"},
  {"copy",(PyCFunction)histogram_histogram_copy,METH_O,"copies the given histogram to myself"},
  {"read",(PyCFunction)histogram_histogram_read,METH_O,"reads histogram binary data from file"},
  {"write",(PyCFunction)histogram_histogram_write,METH_O,"writes histogram binary data to file"},
  {"scanf",(PyCFunction)histogram_histogram_scanf,METH_O,"reads histogram data from file using scanf"},
  {"printf",(PyCFunction)histogram_histogram_printf,METH_VARARGS,"writes histogram data to file using printf"},
  {NULL, NULL, 0, NULL}           /* sentinel */
};

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

  PyObject* orig_histogram;
  long int n;
  
  static char *kwlist1[] = {"histogram",NULL};
  static char *kwlist2[] = {"bins",NULL};

  /* initialise histogram pointer */
  ((histogram_histogramObject*)self)->h=NULL;

  /* test two call alternatives: */

  if (PyArg_ParseTupleAndKeywords(args, kwds,"O!",kwlist1,&histogram_histogramType,&orig_histogram)) {
    gsl_histogram* histogram;
    gsl_histogram* histogram2=(gsl_histogram*)((histogram_histogramObject*)orig_histogram)->h;
    if (histogram2==NULL) {
      PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
      return -1;
    }
    histogram=gsl_histogram_clone(histogram2);
    if (histogram==NULL)
      return -1;
    ((histogram_histogramObject*)self)->h=histogram;
    return 0;
  }
  else {
    /* reset exception */
    PyErr_Clear();
  }
  if (PyArg_ParseTupleAndKeywords(args, kwds,"l",kwlist2,&n)) {
    gsl_histogram* histogram;
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
  else {
    /* set own error message */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError, "histogram.init requires pygsl.histogram.histogram object or long int argument");
    return -1;
  }
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

static PyObject*
histogram_histogram_getattr(PyObject* obj, char *name)
{
  return Py_FindMethod(histogram_histogram_methods, obj, name);
}

static
PyTypeObject histogram_histogramType = {
	PyObject_HEAD_INIT(NULL)
	0,
	"pygsl.histogram.histogram",
	sizeof(histogram_histogramObject),
	0,
	(destructor)histogram_histogram_dealloc, /* tp_dealloc */
	0,                                      /* tp_print */
	histogram_histogram_getattr,            /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	&histogram_histogram_as_mapping,	/* tp_as_mapping */
	0,				        /* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,		                        /* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,		        /* tp_flags */
        0,				        /* tp_doc */
	0, 		                        /* tp_traverse */
	0,			                /* tp_clear */
	0,              			/* tp_richcompare */
	0,					/* tp_weaklistoffset */
	0,			                /* tp_iter */
	0,					/* tp_iternext */
	0,				        /* tp_methods */
	0,					/* tp_members */
	0,					/* tp_getset */
	0,					/* tp_base */
	0,					/* tp_dict */
	0,					/* tp_descr_get */
	0,					/* tp_descr_set */
	0,					/* tp_dictoffset */
	(initproc)histogram_histogram_init,	/* tp_init */
	NULL,              			/* tp_alloc */
	NULL,                			/* tp_new */
	NULL         			        /* tp_free */
};




/*
 *
 * here begins the section for the 2d histogram
 *
 */

/* my typedef */

staticforward PyTypeObject histogram_histogram2dType;

typedef struct {
    PyObject_HEAD
    gsl_histogram2d* h;
} histogram_histogram2dObject;


static PyObject* histogram_histogram2d_alloc(PyObject *self,
					     PyObject *args
					     )
{
  gsl_histogram2d* histogram;
  long int m;
  long int n;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.alloc got a NULL pointer");
    return NULL;
  }

  /* get size */
  if (0==PyArg_ParseTuple(args,"ll",&m,&n))
      return NULL;

  if (n<=0) {
    gsl_error ("histogram length n must be positive integer",
               __FILE__,
               __LINE__,
               GSL_EDOM );
    return NULL;
  }

  /* free existing histogram */
  gsl_histogram2d_free(histogram);

  histogram=gsl_histogram2d_alloc(m,n);
  /* if this fails, the pointer should be NULL, although this object is useless now */
  (gsl_histogram2d*)((histogram_histogram2dObject*)self)->h=histogram;
  if (histogram==NULL)
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}



static PyObject* histogram_histogram2d_set_ranges_uniform(PyObject *self,
							  PyObject *args
							  )
{
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  double xmin;
  double xmax;
  double ymin;
  double ymax;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.set_ranges_uniform got a NULL pointer");
    return NULL;
  }
  if (0==PyArg_ParseTuple(args,"dddd",&xmin,&xmax,&ymin,&ymax)) {
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram2d_set_ranges_uniform(histogram,xmin,xmax,ymin,ymax))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}


static PyObject* histogram_histogram2d_reset(PyObject *self)
{
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.reset got a NULL pointer");
    return NULL;
  }
  gsl_histogram2d_reset(histogram);
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram2d_increment (gsl_histogram * h, double x)
*/
static PyObject* histogram_histogram2d_increment(PyObject *self,
						 PyObject *args
						 )
{
  gsl_histogram2d * histogram;
  int result;
  double x;
  double y;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.increment got a NULL pointer");
    return NULL;
  }
  if (0==PyArg_ParseTuple(args,"dd",&x,&y)) {
    return NULL;
  }
  result=gsl_histogram2d_increment(histogram,x,y);
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
int gsl_histogram2d_accumulate (gsl_histogram * h, double x, double weight)
*/
static PyObject* histogram_histogram2d_accumulate(PyObject *self,
						  PyObject *args
						  )
{
  gsl_histogram2d * histogram;
  int result;
  double x;
  double y;
  double weight;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.accumulate got a NULL pointer");
    return NULL;
  }
  if (0==PyArg_ParseTuple(args,"ddd",&x,&y,&weight)) {
    return NULL;
  }

  result=gsl_histogram2d_accumulate(histogram,x,y,weight);
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
  double gsl_histogram2d_xmax (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_xmax(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.xmax got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_xmax(histogram));
}

/*
  double gsl_histogram2d_ymax (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_ymax(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.ymax got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_ymax(histogram));
}


/*
  double gsl_histogram2d_xmin (const gsl_histogram2d * h)
*/
static PyObject* histogram_histogram2d_xmin(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.xmin got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_xmin(histogram));
}

/*
  double gsl_histogram2d_ymin (const gsl_histogram2d * h)
*/
static PyObject* histogram_histogram2d_ymin(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.ymin got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_ymin(histogram));
}

/*
  size_t gsl_histogram2d_nx (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_nx(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.nx got a NULL pointer");
    return NULL;
  }
  return PyLong_FromLong(gsl_histogram2d_nx(histogram));
}

/*
  size_t gsl_histogram2d_nx (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_ny(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.ny got a NULL pointer");
    return NULL;
  }
  return PyLong_FromLong(gsl_histogram2d_ny(histogram));
}

/*
  double gsl_histogram2d_get (const gsl_histogram2d * h, size_t i, size_t j)
*/

static PyObject* histogram_histogram2d_get(PyObject *self,
					   PyObject *args
					   )
{
  gsl_histogram2d* histogram;
  long int i;
  long int j;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.get got a NULL pointer");
    return NULL;
  }

  /* get index */  
  if (0==PyArg_ParseTuple(args,"ll",&i,&j))
      return NULL;
  if (i<0 || i>=histogram->nx) {
    gsl_error ("index i lies outside valid range of 0 .. nx - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (j<0 || j>=histogram->ny) {
    gsl_error ("index j lies outside valid range of 0 .. ny - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_get(histogram,i,j));
}


/*
  int gsl_histogram_get_xrange (const gsl_histogram2d * h, size_t i, double * lower, double * upper)
 */
static PyObject* histogram_histogram2d_get_xrange(PyObject *self,
						  PyObject *args
						  )
{
  gsl_histogram2d* histogram;
  long int i;
  double lower;
  double upper;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.get_xrange got a NULL pointer");
    return NULL;
  }

  /* get index */
  if (0==PyArg_ParseTuple(args,"l",&i))
    return NULL;
  if (i<0 || i>=histogram->nx) {
    gsl_error ("index i lies outside valid range of 0 .. nx - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram2d_get_xrange(histogram,i,&lower,&upper))
    return NULL;
  return Py_BuildValue("(dd)",lower,upper);
}

/*
  int gsl_histogram_get_yrange (const gsl_histogram2d * h, size_t j, double * lower, double * upper)
 */
static PyObject* histogram_histogram2d_get_yrange(PyObject *self,
						  PyObject *args
						  )
{
  gsl_histogram2d* histogram;
  long int j;
  double lower;
  double upper;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.get_yrange got a NULL pointer");
    return NULL;
  }

  /* get index */
  if (0==PyArg_ParseTuple(args,"l",&j))
    return NULL;
  if (j<0 || j>=histogram->ny) {
    gsl_error ("index j lies outside valid range of 0 .. ny - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (GSL_SUCCESS!=gsl_histogram2d_get_yrange(histogram,j,&lower,&upper))
    return NULL;
  return Py_BuildValue("(dd)",lower,upper);
}


/*
  int gsl_histogram2d_find (const gsl_histogram * h, double x, double y, size_t * i, size_t * j)
*/
static PyObject* histogram_histogram2d_find(PyObject *self,
					    PyObject *args
					    )
{
  gsl_histogram2d* histogram;
  double xvalue;
  size_t xindex;
  double yvalue;
  size_t yindex;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.find got a NULL pointer");
    return NULL;
  }

  /* get index */
  if (0==PyArg_ParseTuple(args,"dd",&xvalue,&yvalue))
      return NULL;
  if (GSL_SUCCESS!=gsl_histogram2d_find(histogram, xvalue, yvalue, &xindex, &yindex))
    return NULL;
  return Py_BuildValue("(ll)", xindex, yindex);
}


/*
  double gsl_histogram2d_max_val (const gsl_histogram2d * h)
 */

static PyObject* histogram_histogram2d_max_val(PyObject *self)
{
  gsl_histogram2d * histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.max_val got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_max_val(histogram));
}

/*
  double gsl_histogram2d_max_bin (const gsl_histogram2d * h)
 */
static PyObject* histogram_histogram2d_max_bin(PyObject *self)
{
  gsl_histogram2d * histogram;
  size_t i;
  size_t j;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.max_bin got a NULL pointer");
    return NULL;
  }
  gsl_histogram2d_max_bin(histogram, &i, &j);
  return Py_BuildValue("(ll)", i, j);
}


/*
  double gsl_histogram2d_min_val (const gsl_histogram2d * h)
 */

static PyObject* histogram_histogram2d_min_val(PyObject *self)
{
  gsl_histogram2d * histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.min_val got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_min_val(histogram));
}

/*
  double gsl_histogram_min_bin (const gsl_histogram2d * h)
 */
static PyObject* histogram_histogram2d_min_bin(PyObject *self)
{
  gsl_histogram2d * histogram;
  size_t i;
  size_t j;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.min_bin got a NULL pointer");
    return NULL;
  }
  gsl_histogram2d_min_bin(histogram,&i,&j);
  return Py_BuildValue("(ll)", i, j);
}

/*
  double gsl_histogram2d_sum (const gsl_histogram2d * h)
 */

static PyObject* histogram_histogram2d_sum(PyObject *self) {
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.sum got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_sum(histogram));
}

/*
  double gsl_histogram2d_xmean (const gsl_histogram2d * h)
 */

static PyObject* histogram_histogram2d_xmean(PyObject *self) {
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.xmean got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_xmean(histogram));
}

/*
  double gsl_histogram2d_ymean (const gsl_histogram2d * h)
 */

static PyObject* histogram_histogram2d_ymean(PyObject *self) {
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.ymean got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_ymean(histogram));
}


/*
  double gsl_histogram2d_xsigma (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_xsigma(PyObject *self) {
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.xsigma got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_xsigma(histogram));
}

/*
  double gsl_histogram2d_ysigma (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_ysigma(PyObject *self) {
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.ysigma got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_ysigma(histogram));
}

/*
  double gsl_histogram2d_cov (const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_cov(PyObject *self) {
  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.cov got a NULL pointer");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_cov(histogram));
}


/*
  int gsl_histogram2d_set_ranges (gsl_histogram * h, const double xrange[], size_t xsize, const double yrange[], size_t ysize)
 */

static PyObject* histogram_histogram2d_set_ranges(PyObject *self, PyObject *ranges) {

  gsl_histogram2d * histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  PyObject* xranges;
  PyObject* yranges;
  double* double_xranges;
  double* double_yranges;
  size_t xsize;
  size_t ysize;
  size_t pos;
  double last_value=0;
  int gsl_result;

  /* get gsl_histogram struct */
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.set_ranges got a NULL pointer");
    return NULL;
  }

  /* get two arguments */
  Py_INCREF(ranges);
  if (0==PySequence_Check(ranges) || 2!=PySequence_Size(ranges)) {
    PyErr_SetString(PyExc_TypeError,
		    "histogram2d.set_ranges needs two sequences");
  }
  xranges=PySequence_GetItem(ranges,0);
  yranges=PySequence_GetItem(ranges,1);
  Py_DECREF(ranges);
  
  if (0==PySequence_Check(xranges) || 0==PySequence_Check(yranges)) {
    PyErr_SetString(PyExc_TypeError,
		    "histogram2d.set_ranges needs two sequences");
    Py_DECREF(xranges);
    Py_DECREF(yranges);
    return NULL;
  }

  /* determine sizes */
  xsize=PySequence_Size(xranges);
  if (xsize<=0 || xsize!=histogram->nx+1) {
    PyErr_SetString(PyExc_TypeError,
		    "histogram2d.set_ranges needs a sequence with nx+1 elements as first argument");    
    Py_DECREF(xranges);
    Py_DECREF(yranges);
    return NULL;
  }
  ysize=PySequence_Size(yranges);
  if (ysize<=0 || ysize!=histogram->ny+1) {
    PyErr_SetString(PyExc_TypeError,
		    "histogram2d.set_ranges needs a sequence with ny+1 elements as second argument");    
    Py_DECREF(xranges);
    Py_DECREF(yranges);
    return NULL;
  }

  /* allocate double arrays */
  double_xranges=malloc(sizeof(double)*xsize);
  if (double_xranges==NULL) {
    PyErr_SetString(PyExc_MemoryError,
		    "histogram2d.set_ranges could not allocate x double field");    
    Py_DECREF(xranges);
    Py_DECREF(yranges);
    return NULL;
  }
  double_yranges=malloc(sizeof(double)*ysize);
  if (double_yranges==NULL) {
    PyErr_SetString(PyExc_MemoryError,
		    "histogram2d.set_ranges could not allocate y double field");    
    Py_DECREF(xranges);
    Py_DECREF(yranges);
    free(double_xranges);
    return NULL;
  }
  
  /* copy x values to double field */
  for(pos=0; pos<xsize; pos++) {
    double value;
    PyObject* pos_value;
    PyObject* float_value;
    pos_value=PySequence_GetItem(xranges,pos);
    float_value=PyNumber_Float(pos_value);
    Py_DECREF(pos_value);
    if (float_value==NULL) {
      PyErr_SetString(PyExc_TypeError,
		      "histogram2d.set_ranges expects sequence of numbers");    
      Py_DECREF(xranges);
      Py_DECREF(yranges);
      free(double_xranges);
      free(double_yranges);
      return NULL;
    }
    value=PyFloat_AsDouble(float_value);
    Py_DECREF(float_value);
    /* check for increasing values */
    if (pos>0 && last_value>=value) {
      PyErr_SetString(PyExc_TypeError,
		      "histogram2d.set_ranges expects monotonically increasing sequence of numbers");    
      Py_DECREF(xranges);
      Py_DECREF(yranges);
      free(double_xranges);
      free(double_yranges);
      return NULL;      
    }
    double_xranges[pos]=value;
    last_value=value;
  }
  Py_DECREF(xranges);

  /* copy y values to double field */
  for(pos=0; pos<ysize; pos++) {
    double value;
    PyObject* pos_value;
    PyObject* float_value;
    pos_value=PySequence_GetItem(yranges,pos);
    float_value=PyNumber_Float(pos_value);
    Py_DECREF(pos_value);
    if (float_value==NULL) {
      PyErr_SetString(PyExc_TypeError,
		      "histogram2d.set_ranges expects sequence of numbers");    
      Py_DECREF(yranges);
      free(double_xranges);
      free(double_yranges);
      return NULL;
    }
    value=PyFloat_AsDouble(float_value);
    Py_DECREF(float_value);
    /* check for increasing values */
    if (pos>0 && last_value>=value) {
      PyErr_SetString(PyExc_TypeError,
		      "histogram2d.set_ranges expects monotonically increasing sequence of numbers");    
      Py_DECREF(yranges);
      free(double_xranges);
      free(double_yranges);
      return NULL;      
    }
    double_yranges[pos]=value;
    last_value=value;
  }
  Py_DECREF(yranges);

  /* set ranges to gsl_histogram structure */
  gsl_result=gsl_histogram2d_set_ranges(histogram,double_xranges,xsize,double_yranges,ysize);
  free(double_xranges);
  free(double_yranges);

  if (GSL_SUCCESS!=gsl_result) return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}


static PyObject* histogram_histogram2d_shift(PyObject *self,
					     PyObject *arg) {
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  PyObject* float_object;
  double offset;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.shift got a NULL pointer");
    return NULL;
  }

  /* get offset */
  float_object=PyNumber_Float(arg);
  if (float_object==NULL) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.shift expects a number");
    return NULL;
  }
  offset=PyFloat_AsDouble(float_object);
  Py_DECREF(float_object);
  if (GSL_SUCCESS!=gsl_histogram2d_shift(histogram, offset))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* histogram_histogram2d_scale(PyObject *self,
					     PyObject *arg) {
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  PyObject* float_object;
  double scale;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.scale got a NULL pointer");
    return NULL;
  }

  /* get offset */
  float_object=PyNumber_Float(arg);
  if (float_object==NULL) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.scale expects a number");
    return NULL;
  }
  scale=PyFloat_AsDouble(float_object);
  Py_DECREF(float_object);
  if (GSL_SUCCESS!=gsl_histogram2d_scale(histogram, scale))
    return NULL;
  Py_INCREF(Py_None);
  return Py_None;
}


/*
 int gsl_histogram2d_equal_bins_p (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram2d_equal_bins_p(PyObject *self,
						  PyObject *arg) {
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  gsl_histogram2d* histogram2;
  int result;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram.equal_bins_p got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogram2dType)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.equal_bins_p requires pygsl.histogram.histogram2d");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram2d_equal_bins_p(histogram,histogram2);
  Py_DECREF(arg);
  return PyInt_FromLong(result);
}

/*
 int gsl_histogram2d_add (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram2d_add(PyObject *self,
					 PyObject *arg) {
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  gsl_histogram2d* histogram2;
  int result;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.add got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogram2dType)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.add requires pygsl.histogram.histogram2d");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram2d_add(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 int gsl_histogram2d_sub (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram2d_sub(PyObject *self,
					   PyObject *arg) {
  gsl_histogram2d* histogram;
  gsl_histogram2d* histogram2;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.sub got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogram2dType)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.sub requires pygsl.histogram.histogram2d");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram2d_sub(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 int gsl_histogram2d_mul (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram2d_mul(PyObject *self,
					   PyObject *arg) {
  gsl_histogram2d* histogram;
  gsl_histogram2d* histogram2;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.mul got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogram2dType)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.mul requires pygsl.histogram.histogram2d");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram2d_mul(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 int gsl_histogram2d_div (const gsl_histogram *h1, const gsl_histogram *h2)
*/

static PyObject* histogram_histogram2d_div(PyObject *self,
					   PyObject *arg) {
  gsl_histogram2d* histogram;
  gsl_histogram2d* histogram2;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.div got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogram2dType)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.div requires pygsl.histogram.histogram2d");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram2d_div(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
 */

static PyObject* histogram_histogram2d_clone(PyObject *self) {

  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  gsl_histogram2d* clone;
  PyObject* return_object;
  
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.clone got a NULL pointer");
    return NULL;
  }

  clone=gsl_histogram2d_clone(histogram);
  if (clone==NULL)
    return NULL;

  return_object=PyType_GenericAlloc(&histogram_histogram2dType,1);
  if (return_object==NULL) {
    gsl_histogram2d_free(clone);
    return NULL;
  }
  ((histogram_histogram2dObject*)return_object)->h=clone;
  return return_object;
}

/*
 int gsl_histogram2d_copy (const gsl_histogram2d *h1, const gsl_histogram2d *h2)
*/

static PyObject* histogram_histogram2d_copy(PyObject *self,
					    PyObject *arg) {
  gsl_histogram2d* histogram;
  gsl_histogram2d* histogram2;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.copy got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&histogram_histogram2dType)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.copy requires pygsl.histogram.histogram2d");
    Py_DECREF(arg);
    return NULL;
  }
  histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)arg)->h;
  if (histogram2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_histogram2d_memcpy(histogram,histogram2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}


/*
  int gsl_histogram2d_fread (FILE * stream, gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_read(PyObject *self,
					    PyObject *arg) {
  gsl_histogram2d* histogram;
  FILE*  stream;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.read got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get file from argument */
  if (arg==NULL || !PyFile_Check(arg)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.read requires file type");
    Py_DECREF(arg);
    return NULL;
  }

  stream=PyFile_AsFile(arg);
  result=gsl_histogram2d_fread(stream,histogram);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram2d_fwrite (FILE * stream, const gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_write(PyObject *self,
					     PyObject *arg) {
  gsl_histogram2d* histogram;
  FILE*  stream;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.write got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get file from argument */
  if (arg==NULL || !PyFile_Check(arg)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.write requires file type");
    Py_DECREF(arg);
    return NULL;
  }

  stream=PyFile_AsFile(arg);
  result=gsl_histogram2d_fwrite(stream,histogram);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}


/*
  int gsl_histogram2d_fscanf (FILE * stream, gsl_histogram2d * h)
*/

static PyObject* histogram_histogram2d_scanf(PyObject *self,
					     PyObject *arg) {
  gsl_histogram2d* histogram;
  FILE*  stream;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.scanf got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get file from argument */
  if (arg==NULL || !PyFile_Check(arg)) {
    PyErr_SetString(PyExc_TypeError, "histogram2d.scanf requires file type");
    Py_DECREF(arg);
    return NULL;
  }

  stream=PyFile_AsFile(arg);
  result=gsl_histogram2d_fscanf(stream,histogram);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

/*
  int gsl_histogram2d_fprintf (FILE * stream, const gsl_histogram2d * h, const char * range_format, const char * bin_format)
*/

static PyObject* histogram_histogram2d_printf(PyObject *self,
					      PyObject *arg) {
  gsl_histogram2d* histogram;
  PyObject* the_file;
  FILE*  stream=NULL;
  char* range_format=NULL;
  char* bin_format=NULL;
  int result;

  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.printf got a NULL pointer");
    return NULL;
  }

  if (0==PyArg_ParseTuple(arg,"O!|ss",&PyFile_Type,&the_file,&range_format,&bin_format)) {
    return NULL;
  }

  if (range_format==NULL)
    range_format="%g";
  if (bin_format==NULL)
    bin_format="%g";

  Py_INCREF(the_file);
  stream=PyFile_AsFile(the_file);
  result=gsl_histogram2d_fprintf(stream,histogram,range_format,bin_format);
  Py_DECREF(the_file);

  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}


/* method index */

static PyMethodDef histogram_histogram2d_methods[] = {
  {"alloc",(PyCFunction)histogram_histogram2d_alloc,METH_VARARGS,"allocate necessary space"},
  {"set_ranges_uniform", (PyCFunction)histogram_histogram2d_set_ranges_uniform, METH_VARARGS,"set the ranges to uniform distance"},
  {"reset",(PyCFunction)histogram_histogram2d_reset,METH_NOARGS,"sets all bin values to 0"},
  {"increment",(PyCFunction)histogram_histogram2d_increment,METH_VARARGS,"increments corresponding bin"},
  {"accumulate",(PyCFunction)histogram_histogram2d_accumulate,METH_VARARGS,"adds the weight to corresponding bin"},
  {"xmax",(PyCFunction)histogram_histogram2d_xmax,METH_NOARGS,"returns upper x range"},
  {"xmin",(PyCFunction)histogram_histogram2d_xmin,METH_NOARGS,"returns lower x range"},
  {"ymax",(PyCFunction)histogram_histogram2d_ymax,METH_NOARGS,"returns upper y range"},
  {"ymin",(PyCFunction)histogram_histogram2d_ymin,METH_NOARGS,"returns lower y range"},
  {"nx",(PyCFunction)histogram_histogram2d_nx,METH_NOARGS,"returns number of x bins"},
  {"ny",(PyCFunction)histogram_histogram2d_ny,METH_NOARGS,"returns number of y bins"},
  {"get",(PyCFunction)histogram_histogram2d_get,METH_VARARGS,"gets value of indexed bin"},
  {"get_xrange",(PyCFunction)histogram_histogram2d_get_xrange,METH_VARARGS,"gets upper and lower x range of indexed bin"},
  {"get_yrange",(PyCFunction)histogram_histogram2d_get_yrange,METH_VARARGS,"gets upper and lower y range of indexed bin"},
  {"find",(PyCFunction)histogram_histogram2d_find,METH_VARARGS,"finds index pair of corresponding value pair"},
  {"max_val",(PyCFunction)histogram_histogram2d_max_val,METH_NOARGS,"returns maximal bin value"},
  {"max_bin",(PyCFunction)histogram_histogram2d_max_bin,METH_NOARGS,"returns bin index with maximal value"},
  {"min_val",(PyCFunction)histogram_histogram2d_min_val,METH_NOARGS,"returns minimal bin value"},
  {"min_bin",(PyCFunction)histogram_histogram2d_min_bin,METH_NOARGS,"returns bin index with minimal value"},
  {"sum",(PyCFunction)histogram_histogram2d_sum,METH_NOARGS,"returns sum of bin values"},
  {"xmean",(PyCFunction)histogram_histogram2d_xmean,METH_NOARGS,"returns x mean of histogram"},
  {"xsigma",(PyCFunction)histogram_histogram2d_xsigma,METH_NOARGS,"returns x std deviation of histogram"},
  {"ymean",(PyCFunction)histogram_histogram2d_ymean,METH_NOARGS,"returns y mean of histogram"},
  {"ysigma",(PyCFunction)histogram_histogram2d_ysigma,METH_NOARGS,"returns y std deviation of histogram"},
  {"cov",(PyCFunction)histogram_histogram2d_cov,METH_NOARGS,"returns covariance of histogram"},
  {"set_ranges", (PyCFunction)histogram_histogram2d_set_ranges, METH_VARARGS,"set the ranges according to given sequences"},
  {"shift",(PyCFunction)histogram_histogram2d_shift,METH_O,"shifts the contents of the bins by the given offset"},
  {"scale",(PyCFunction)histogram_histogram2d_scale,METH_O,"multiplies the contents of the bins by the given scale"},
  {"equal_bins_p",(PyCFunction)histogram_histogram2d_equal_bins_p,METH_O,"true if the all of the individual bin ranges are identical"},
  {"add",(PyCFunction)histogram_histogram2d_add,METH_O,"adds the contents of the bins"},
  {"sub",(PyCFunction)histogram_histogram2d_sub,METH_O,"substracts the contents of the bins"},
  {"mul",(PyCFunction)histogram_histogram2d_mul,METH_O,"multiplicates the contents of the bins"},
  {"div",(PyCFunction)histogram_histogram2d_div,METH_O,"divides the contents of the bins"},
  {"clone",(PyCFunction)histogram_histogram2d_clone,METH_NOARGS,"returns a new copy of this histogram"},
  {"copy",(PyCFunction)histogram_histogram2d_copy,METH_O,"copies the given histogram to myself"},
  {"read",(PyCFunction)histogram_histogram2d_read,METH_O,"reads histogram binary data from file"},
  {"write",(PyCFunction)histogram_histogram2d_write,METH_O,"writes histogram binary data to file"},
  {"scanf",(PyCFunction)histogram_histogram2d_scanf,METH_O,"reads histogram data from file using scanf"},
  {"printf",(PyCFunction)histogram_histogram2d_printf,METH_VARARGS,"writes histogram data to file using printf"},
  {NULL, NULL, 0, NULL} /* sentinel */
};

/*
  methods for map protocol
 */

static int histogram_histogram2d_mp_length(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d_mp_length got a NULL pointer");
    return -1;
  }
  return histogram->nx*histogram->ny;
}

static PyObject* histogram_histogram2d_mp_subscript(PyObject *self,
						  PyObject *key
						  )
{
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  long int i; /* indices for histogram access */
  long int j;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.mp_subscript got a NULL pointer");
    return NULL;
  }

  if (0==PyArg_ParseTuple(key,"ll",&i,&j)) {
    return NULL;
  }

  if (i<0 || i>=histogram->nx) {
    gsl_error ("index i lies outside valid range of 0 .. nx - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (j<0 || j>=histogram->ny) {
    gsl_error ("index j lies outside valid range of 0 .. ny - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  return PyFloat_FromDouble(gsl_histogram2d_get(histogram,i,j));
}


static int
histogram_histogram2d_mp_ass_subscript(PyObject *self, PyObject *key, PyObject *value) {
  gsl_histogram2d* histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  long int i; /* indices for histogram access */
  long int j;
  double v;

  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.mp_subscript got a NULL pointer");
    return -1;
  }

  if (0==PyArg_ParseTuple(key,"ll",&i,&j)) {
    return -1;
  }

  if (i<0 || i>=histogram->nx) {
    gsl_error ("index i lies outside valid range of 0 .. nx - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return -1;
  }
  if (j<0 || j>=histogram->ny) {
    gsl_error ("index j lies outside valid range of 0 .. ny - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return -1;
  }

  /* get value */
  if (value == NULL)
    v=0;
  else {
    PyObject* my_value=PyNumber_Float(value);
    if (my_value==NULL) return -1;
    v=PyFloat_AsDouble(value);
    Py_DECREF(my_value);
  }

  histogram->bin[i*histogram->ny+j]=v;
  return 0;
}


/*
  typedef struct {
        inquiry mp_length;
        binaryfunc mp_subscript;
        objobjargproc mp_ass_subscript;
  } PyMappingMethods;
 */

static PyMappingMethods histogram_histogram2d_as_mapping = {
  (inquiry)histogram_histogram2d_mp_length, /* inquiry mp_length */
  (binaryfunc)histogram_histogram2d_mp_subscript, /* binaryfunc mp_subscript */
  (objobjargproc)histogram_histogram2d_mp_ass_subscript/* objobjargproc mp_ass_subscript */
};



/* initialisation and finalisation functions */

static void
histogram_histogram2d_dealloc(PyObject* self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram!=NULL) gsl_histogram2d_free(histogram);
  self->ob_type->tp_free(self);
}

static int histogram_histogram2d_init(PyObject *self,
				    PyObject *args,
				    PyObject *kwds
				    )
{

  PyObject* orig_histogram;
  long int n;
  long int m;
  
  static char *kwlist1[] = {"histogram",NULL};
  static char *kwlist2[] = {"nx","ny",NULL};

  /* initialise histogram pointer */
  ((histogram_histogram2dObject*)self)->h=NULL;

  /* test two call alternatives: */

  if (PyArg_ParseTupleAndKeywords(args, kwds,"O!",kwlist1,&histogram_histogram2dType,&orig_histogram)) {
    gsl_histogram2d* histogram;
    gsl_histogram2d* histogram2=(gsl_histogram2d*)((histogram_histogram2dObject*)orig_histogram)->h;
    if (histogram2==NULL) {
      PyErr_SetString(PyExc_RuntimeError, "histogram2d in argument has a NULL pointer");
      return -1;
    }
    histogram=gsl_histogram2d_clone(histogram2);
    if (histogram==NULL)
      return -1;
    ((histogram_histogram2dObject*)self)->h=histogram;
    return 0;
  }
  else {
    /* reset exception */
    PyErr_Clear();
  }
  if (PyArg_ParseTupleAndKeywords(args, kwds,"ll",kwlist2,&m,&n)) {
    gsl_histogram2d* histogram;
    if (n<=0 || m<=0) {
      gsl_error ("histogram length n and m must be positive",
		 __FILE__,
		 __LINE__,
		 GSL_EDOM );
      return -1;
    }
    histogram=gsl_histogram2d_alloc(m,n);
    if (histogram==NULL)
      return -1;
    gsl_histogram2d_reset(histogram);
    ((histogram_histogram2dObject*)self)->h=histogram;
    return 0;
    
  }
  else {
    /* set own error message */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError, "histogram2d.init requires pygsl.histogram.histogram2d object or two long int arguments");
    return -1;
  }
}


static int
histogram_histogram2d_clear(PyObject *self)
{
  gsl_histogram2d* histogram;
  histogram=(gsl_histogram2d*)((histogram_histogram2dObject*)self)->h;
  if (histogram==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "histogram2d.clear got a NULL pointer");
    return -1;
  }
  gsl_histogram2d_reset(histogram);
  return 0;
}

static PyObject*
histogram_histogram2d_getattr(PyObject* obj, char *name)
{
  return Py_FindMethod(histogram_histogram2d_methods, obj, name);
}

static
PyTypeObject histogram_histogram2dType = {
	PyObject_HEAD_INIT(NULL)
	0,
	"pygsl.histogram.histogram2d",
	sizeof(histogram_histogram2dObject),
	0,
	(destructor)histogram_histogram2d_dealloc, /* tp_dealloc */
	0,                                      /* tp_print */
	histogram_histogram2d_getattr,          /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	&histogram_histogram2d_as_mapping,      /* tp_as_mapping */
	0,				        /* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,		                        /* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,		        /* tp_flags */
        0,				        /* tp_doc */
	0, 		                        /* tp_traverse */
	0,			                /* tp_clear */
	0,              			/* tp_richcompare */
	0,					/* tp_weaklistoffset */
	0,			                /* tp_iter */
	0,					/* tp_iternext */
	0,				        /* tp_methods */
	0,					/* tp_members */
	0,					/* tp_getset */
	0,					/* tp_base */
	0,					/* tp_dict */
	0,					/* tp_descr_get */
	0,					/* tp_descr_set */
	0,					/* tp_dictoffset */
	(initproc)histogram_histogram2d_init,	/* tp_init */
	NULL,            			/* tp_alloc */
	NULL,			                /* tp_new */
	NULL			                /* tp_free */
};


/*
 *
 * module specific stuff
 *
 */


static PyMethodDef histogramMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

void
inithistogram(void)
{
  PyObject* m;
  m=Py_InitModule("histogram", histogramMethods);

  /* init histogram type */
  histogram_histogramType.ob_type  = &PyType_Type;
  histogram_histogramType.tp_alloc = PyType_GenericAlloc;
  histogram_histogramType.tp_new   = PyType_GenericNew;
  histogram_histogramType.tp_free  = _PyObject_Del;

  /* install histogram type */
  /* important! must increment histogram type reference counter */
  Py_INCREF((PyObject*)&histogram_histogramType);
  PyModule_AddObject(m,"histogram", (PyObject*)&histogram_histogramType);

  /* init histogram type */
  histogram_histogram2dType.ob_type  = &PyType_Type;
  histogram_histogram2dType.tp_alloc = PyType_GenericAlloc;
  histogram_histogram2dType.tp_new   = PyType_GenericNew;
  histogram_histogram2dType.tp_free  = _PyObject_Del;

  /* install histogram type */
  /* important! must increment histogram type reference counter */
  Py_INCREF((PyObject*)&histogram_histogram2dType);
  PyModule_AddObject(m,"histogram2d", (PyObject*)&histogram_histogram2dType);
}
