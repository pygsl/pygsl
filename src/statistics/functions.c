/*
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 */

#ifndef HAVE_NUMERIC
/** NumPy replacements
 *
 * In case NumPy is not available,
 * provide missing array conversion ala Numeric module
 */

typedef  struct {
    STATMOD_C_TYPE *data;
    size_t *dimensions;
    size_t length;
} PyArrayObject;

enum PyArray_TYPES { PyArray_CHAR, PyArray_UBYTE, PyArray_SBYTE,
                     PyArray_SHORT, PyArray_INT, PyArray_LONG,
                     PyArray_FLOAT, PyArray_DOUBLE, 
                     PyArray_CFLOAT, PyArray_CDOUBLE,
                     PyArray_OBJECT,
                     PyArray_NTYPES, PyArray_NOTYPE};


PyArrayObject *
PyArray_ContiguousFromObject(PyObject* O, int arg1 ,int arg2 ,int arg3) {

    PyArrayObject* my_struct;
    STATMOD_C_TYPE *c_array;
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
    /* allocate c array */
    my_struct=(PyArrayObject*)malloc(sizeof(PyArrayObject)+sizeof(STATMOD_C_TYPE)*size);
    if (my_struct==NULL) {
	PyErr_SetString(PyExc_MemoryError,
			"could not allocate C array");
	Py_DECREF(O);
	return NULL;
    }
    c_array=(STATMOD_C_TYPE*)((void*)my_struct+sizeof(PyArrayObject));
    my_struct->length=size;
    my_struct->dimensions=&(my_struct->length);
    my_struct->data=c_array;
    /* copy values to double field */
    for(pos=0; pos<size; pos++) {
	PyObject* pos_value;
	PyObject* py_value;
	pos_value=PySequence_GetItem(O,pos);
	py_value=STATMOD_APPEND_PY_TYPE(PyNumber_)(pos_value);
	Py_DECREF(pos_value);
	if (py_value==NULL) {
	    PyErr_SetString(PyExc_TypeError,
			    "expect sequence of numbers");    
	    Py_DECREF(O);
	    free(my_struct);
	    return NULL;
	}
	c_array[pos]=STATMOD_PY_AS_C(py_value);
	Py_DECREF(py_value);
    }
    Py_DECREF(O);
    return my_struct;
}
#endif /* HAVE_NUMERIC */




/*** Mean, standard deviation, and variance ***/

static PyObject *
STATMOD_FUNC_EXT(statistics_mean, ) (PyObject *self, PyObject *args)
{
    PyObject *input = NULL;
    PyArrayObject *data;
    double result;
    int stride=1, n;

    if(PyArg_ParseTuple(args, "O!", &PyArray_Type, &data)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "O", &input))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats,_mean)((STATMOD_C_TYPE *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_variance, )(PyObject *self, PyObject *args)
{
    PyObject *input = NULL;
    PyArrayObject *data;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!", &PyArray_Type, &data)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "O", &input))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _variance)((STATMOD_C_TYPE *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
    #else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_variance_m, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!d", &PyArray_Type, &data, &mean)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Od", &input, &mean))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _variance_m)((STATMOD_C_TYPE *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_sd, )(PyObject *self, PyObject *args)
{
    PyObject *input = NULL;
    PyArrayObject *data;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!", &PyArray_Type, &data)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "O", &input))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _sd)((STATMOD_C_TYPE *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_sd_m, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!d", &PyArray_Type, &data, &mean)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Od", &input, &mean))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _sd_m)((STATMOD_C_TYPE *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_variance_with_fixed_mean, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!d", &PyArray_Type, &data, &mean)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Od", &input, &mean))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _variance_with_fixed_mean)((STATMOD_C_TYPE *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_sd_with_fixed_mean, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!d", &PyArray_Type, &data, &mean)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Od", &input, &mean))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _sd_with_fixed_mean)((STATMOD_C_TYPE *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}



/*** Absolute deviation ***/

static PyObject *
STATMOD_FUNC_EXT(statistics_absdev, )(PyObject *self, PyObject *args)
{
    PyObject *input = NULL;
    PyArrayObject *data;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!", &PyArray_Type, &data)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "O", &input))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _absdev)((STATMOD_C_TYPE *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
    #else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_absdev_m, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!d", &PyArray_Type, &data, &mean)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Od", &input, &mean))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _absdev_m)((STATMOD_C_TYPE *)data->data, stride, n, mean);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}



/*** Higher moments (skewness and kurtosis) ***/

static PyObject *
STATMOD_FUNC_EXT(statistics_skew, )(PyObject *self, PyObject *args)
{
    PyObject *input = NULL;
    PyArrayObject *data;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!", &PyArray_Type, &data)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "O", &input))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _skew)((STATMOD_C_TYPE *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
    #else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_skew_m_sd, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, sd;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!dd", &PyArray_Type, &data, &mean, &sd)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Odd", &input, &mean, &sd))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _skew_m_sd)((STATMOD_C_TYPE *)data->data, stride, n, mean, sd);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_kurtosis, )(PyObject *self, PyObject *args)
{
    PyObject *input = NULL;
    PyArrayObject *data;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!", &PyArray_Type, &data)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "O", &input))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _kurtosis)((STATMOD_C_TYPE *)data->data, stride, n);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
    #else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


static PyObject *
STATMOD_FUNC_EXT(statistics_kurtosis_m_sd, )(PyObject *self, PyObject *args)
{
    PyObject *input;
    PyArrayObject *data;
    double mean, sd;
    double result;
    int stride=1, n;
    
    if(PyArg_ParseTuple(args, "O!dd", &PyArray_Type, &data, &mean, &sd)
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) {
        /* already have NumPy array of Floats  */
        if(data->nd != 1) {
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional");
            return NULL;
        }
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE);
    } else {
        if(!PyArg_ParseTuple(args, "Odd", &input, &mean, &sd))
            return NULL;
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input,
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_),
                                                                         1, 1)))
            return NULL;
    }
    n = data->dimensions[0];
    result = STATMOD_FUNC_EXT(gsl_stats, _kurtosis_m_sd)((STATMOD_C_TYPE *)data->data, stride, n, mean, sd);
#ifdef HAVE_NUMERIC
    if(NULL != input) {
        Py_DECREF(data);
    }
#else
    free(data);
#endif
    return PyFloat_FromDouble(result);
}


/*** table of methods ***/

static PyMethodDef STATMOD_APPEND_PY_TYPE(StatisticsMethods_)[] = {
    {"absdev",                          STATMOD_FUNC_EXT(statistics_absdev,),
                                        METH_VARARGS, ""},
    {"absdev_m",                        STATMOD_FUNC_EXT(statistics_absdev_m,),
                                        METH_VARARGS, ""},
    {"mean",                            STATMOD_FUNC_EXT(statistics_mean,),
                                        METH_VARARGS, ""},
    {"sd",                              STATMOD_FUNC_EXT(statistics_sd,),
                                        METH_VARARGS, ""},
    {"sd_m",                            STATMOD_FUNC_EXT(statistics_sd_m,),
                                        METH_VARARGS, ""},
    {"sd_with_fixed_mean",              STATMOD_FUNC_EXT(statistics_sd_with_fixed_mean,),
                                        METH_VARARGS, ""},
    {"variance",                        STATMOD_FUNC_EXT(statistics_variance,),
                                        METH_VARARGS, ""},
    {"variance_m",                      STATMOD_FUNC_EXT(statistics_variance_m,),
                                        METH_VARARGS, ""},
    {"variance_with_fixed_mean",        STATMOD_FUNC_EXT(statistics_variance_with_fixed_mean,),
                                        METH_VARARGS, ""},
    {"skew",                            STATMOD_FUNC_EXT(statistics_skew,),
                                        METH_VARARGS, ""},
    {"skew_m_sd",                       STATMOD_FUNC_EXT(statistics_skew_m_sd,),
                                        METH_VARARGS, ""},
    {"kurtosis",                        STATMOD_FUNC_EXT(statistics_kurtosis,),
                                        METH_VARARGS, ""},
    {"kurtosis_m_sd",                   STATMOD_FUNC_EXT(statistics_kurtosis_m_sd,),
                                        METH_VARARGS, ""},
    {NULL, NULL, 0, ""}
};






/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
