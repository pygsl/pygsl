/*
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 */


#include <Python.h>
#ifdef HAVE_NUMERIC
# include <Numeric/arrayobject.h>
#endif
#include <gsl/gsl_statistics.h>

#ifndef HAVE_NUMERIC

/* provide missing array conversion from numeric module */

typedef  struct {
    double* data;
    size_t* dimensions;
    size_t length;
} PyArrayObject;

#define PyArray_DOUBLE 1

PyArrayObject *
PyArray_ContiguousFromObject(PyObject* O, int arg1 ,int arg2 ,int arg3) {

    PyArrayObject* my_struct;
    double* double_array;
    size_t size;
    size_t pos;
    Py_INCREF(O);

    if (0==PySequence_Check(O)) {
	PyErr_SetString(PyExc_TypeError,
			"sequence type expected");
	Py_DECREF(O);
	return NULL;
    }

    /* determine size */
    size=PySequence_Size(O);
    if (size<0) {
	PyErr_SetString(PyExc_TypeError,
			"expected positive size");
	Py_DECREF(O);
	return NULL;
    }

    /* allocate double array */
    my_struct=(PyArrayObject*)malloc(sizeof(PyArrayObject)+sizeof(double)*size);
    if (my_struct==NULL) {
	PyErr_SetString(PyExc_MemoryError,
			"could not allocate double array");
	Py_DECREF(O);
	return NULL;
    }
    double_array=(double*)((void*)my_struct+sizeof(PyArrayObject));
    my_struct->length=size;
    my_struct->dimensions=&(my_struct->length);
    my_struct->data=double_array;
  
    /* copy values to double field */
    for(pos=0; pos<size; pos++) {
	PyObject* pos_value;
	PyObject* float_value;
	pos_value=PySequence_GetItem(O,pos);
	float_value=PyNumber_Float(pos_value);
	Py_DECREF(pos_value);
	if (float_value==NULL) {
	    PyErr_SetString(PyExc_TypeError,
			    "expect sequence of numbers");    
	    Py_DECREF(O);
	    free(my_struct);
	    return NULL;
	}
	double_array[pos]=PyFloat_AsDouble(float_value);
	Py_DECREF(float_value);
    }
    Py_DECREF(O);
    return my_struct;
}
#endif /* HAVE_NUMERIC */

/* Mean and standard deviation and variance */

static PyObject *
statistics_mean(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "O", &input))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    mean = gsl_stats_mean((double *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(mean);
}


static PyObject *
statistics_variance(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double variance;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "O", &input))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    variance = gsl_stats_variance((double *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(variance);
}


static PyObject *
statistics_variance_m(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, variance;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "Od", &input, &mean))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    variance = gsl_stats_variance_m((double *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(variance);
}


static PyObject *
statistics_sd(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double sd;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "O", &input))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    sd = gsl_stats_sd((double *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(sd);
}


static PyObject *
statistics_sd_m(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, sd;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "Od", &input, &mean))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    sd = gsl_stats_sd_m((double *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(sd);
}


static PyObject *
statistics_variance_with_fixed_mean(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, variance;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "Od", &input, &mean))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    variance = gsl_stats_variance_with_fixed_mean((double *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(variance);
}


static PyObject *
statistics_sd_with_fixed_mean(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, sd;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "Od", &input, &mean))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    sd = gsl_stats_sd_with_fixed_mean((double *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(sd);
}


/* Absolute deviation */

static PyObject *
statistics_absdev(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double absdev;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "O", &input))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    absdev = gsl_stats_absdev((double *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(absdev);
}


static PyObject *
statistics_absdev_m(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, absdev;
    int stride=1, n;
    
    if(!PyArg_ParseTuple(args, "Od", &input, &mean))
        return NULL;
    data = (PyArrayObject *)PyArray_ContiguousFromObject(input, PyArray_DOUBLE, 1, 1);
    if(data == NULL)
        return NULL;
    n = data->dimensions[0];
    absdev = gsl_stats_absdev_m((double *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    Py_DECREF(data);
#else
    free(data);
#endif
    return PyFloat_FromDouble(absdev);
}

/* table of methods */

static PyMethodDef StatisticsMethods[] = {
    {"absdev", statistics_absdev, METH_VARARGS},
    {"absdev_m", statistics_absdev_m, METH_VARARGS},
    {"mean", statistics_mean, METH_VARARGS},
    {"sd", statistics_sd, METH_VARARGS},
    {"sd_m", statistics_sd_m, METH_VARARGS},
    {"sd_with_fixed_mean", statistics_sd_with_fixed_mean, METH_VARARGS},
    {"variance", statistics_variance, METH_VARARGS},
    {"variance_m", statistics_variance_m, METH_VARARGS},
    {"variance_with_fixed_mean", statistics_variance_with_fixed_mean, METH_VARARGS},
    {NULL, NULL}
};


/* initialization */

DL_EXPORT(void) initstatistics(void)
{
    Py_InitModule("statistics", StatisticsMethods);
#ifdef HAVE_NUMERIC
    import_array();
#endif
    return;
}



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
