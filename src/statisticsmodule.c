/*
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * needs Numeric module, available at http://numpy.sourceforge.net
 */



#include <Python.h>
#include <Numeric/arrayobject.h>

#include <gsl/gsl_statistics.h>


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
    import_array();
    return;
}



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
