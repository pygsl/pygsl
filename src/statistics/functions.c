/*
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 */


#if NUMERIC==0
/** NumPy replacements
 *
 * In case NumPy is not available,
 * provide missing array conversion ala Numeric module
 */

typedef struct {
    int type_num;
} PyArray_Descr;

typedef  struct {
    STATMOD_C_TYPE *data;
    size_t nd;
    size_t *dimensions;
    size_t *strides;
    size_t length;
    PyArray_Descr *descr;
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
    my_struct->descr = (PyArray_Descr *)malloc(sizeof(PyArray_Descr));
    if (my_struct->descr == NULL) {
	PyErr_SetString(PyExc_MemoryError,
			"could not allocate C array");
	Py_DECREF(O);
	return NULL;
    }
    my_struct->descr->type_num = -1;
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


PyTypeObject PyArray_Type = { 
    PyObject_HEAD_INIT(0)
    0,                      /*ob_size*/
    "array",                /*tp_name*/
    sizeof(PyArrayObject),  /*tp_basicsize*/
    0,                      /*tp_itemsize*/
};
#  define STATMOD_FREE(data) free(data->descr); free(data);
#else
#  define STATMOD_FREE(data) Py_DECREF(data);
#endif /* NUMERIC */


/** macros of the actual function implementations
 *
 * One macro for each kind of parameter set.
 */
#define STATMOD_FUNCTION_d_A(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input = NULL; \
    PyArrayObject *data; \
    double result; \
    size_t stride=1, n; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!", &PyArray_Type, &data) \
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of right data-type */ \
        if(data->nd != 1) { \
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional"); \
            return NULL; \
        } \
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "O", &input)) \
            return NULL; \
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input, \
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                         1, 1))) \
            return NULL; \
    } \
    n = data->dimensions[0]; \
    result = STATMOD_FUNC_EXT(gsl_stats,_ ## name)((STATMOD_C_TYPE *)data->data, stride, n); \
    if(NULL != input) { STATMOD_FREE(data) } \
    return PyFloat_FromDouble(result); \
}


#define STATMOD_FUNCTION_d_AA(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input1 = NULL, *input2 = NULL; \
    PyArrayObject *data1, *data2; \
    double result; \
    size_t stride1=1, stride2=1; \
    size_t n1, n2; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!O!", &PyArray_Type, &data1, &PyArray_Type, &data2) \
       && (data1->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_)) \
       && (data2->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if((data1->nd != 1) ||(data2->nd != 1)) { \
            PyErr_SetString(PyExc_ValueError, "data arrays must be one-dimensional"); \
            return NULL; \
        } \
        stride1 = data1->strides[0] / sizeof(STATMOD_C_TYPE); \
        stride2 = data2->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "OO", &input1, &input2)) \
            return NULL; \
        if(NULL == (data1 = (PyArrayObject *)PyArray_ContiguousFromObject(input1, \
                                                                          STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                          1, 1))) \
            return NULL; \
        if(NULL == (data2 = (PyArrayObject *)PyArray_ContiguousFromObject(input2, \
                                                                          STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                          1, 1))) { \
            STATMOD_FREE(data1) \
            return NULL; \
        } \
    } \
    n1 = data1->dimensions[0]; \
    n2 = data2->dimensions[0]; \
    if(n1 != n2) { \
        PyErr_SetString(PyExc_ValueError, "data arrays must be of same length"); \
        if(NULL != input1) { STATMOD_FREE(data1) }\
        return NULL; \
     } \
    result = STATMOD_FUNC_EXT(gsl_stats,_ ## name)((STATMOD_C_TYPE *)data1->data, stride1, \
                                                   (STATMOD_C_TYPE *)data2->data, stride2, n1); \
    if(NULL != input1) { STATMOD_FREE(data1) } \
    if(NULL != input2) { STATMOD_FREE(data2) } \
    return PyFloat_FromDouble(result); \
}


#define STATMOD_FUNCTION_d_AAd(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input1 = NULL, *input2 = NULL; \
    PyArrayObject *data1, *data2; \
    double mean, result; \
    size_t stride1=1, stride2=1; \
    size_t n1, n2; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!O!d", &PyArray_Type, &data1, &PyArray_Type, &data2, &mean) \
       && (data1->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_)) \
       && (data2->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if((data1->nd != 1) ||(data2->nd != 1)) { \
            PyErr_SetString(PyExc_ValueError, "data arrays must be one-dimensional"); \
            return NULL; \
        } \
        stride1 = data1->strides[0] / sizeof(STATMOD_C_TYPE); \
        stride2 = data2->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "OOdd", &input1, &input2, &mean)) \
            return NULL; \
        if(NULL == (data1 = (PyArrayObject *)PyArray_ContiguousFromObject(input1, \
                                                                          STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                          1, 1))) \
            return NULL; \
        if(NULL == (data2 = (PyArrayObject *)PyArray_ContiguousFromObject(input2, \
                                                                          STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                          1, 1))) { \
            STATMOD_FREE(data1) \
            return NULL; \
        } \
    } \
    n1 = data1->dimensions[0]; \
    n2 = data2->dimensions[0]; \
    if(n1 != n2) { \
        PyErr_SetString(PyExc_ValueError, "data arrays must be of same length"); \
        if(NULL != input1) { STATMOD_FREE(data1) }\
        return NULL; \
     } \
    result = STATMOD_FUNC_EXT(gsl_stats,_ ## name)((STATMOD_C_TYPE *)data1->data, stride1, \
                                                   (STATMOD_C_TYPE *)data2->data, stride2, n1, \
                                                   mean); \
    if(NULL != input1) { STATMOD_FREE(data1) } \
    if(NULL != input2) { STATMOD_FREE(data2) } \
    return PyFloat_FromDouble(result); \
}


#define STATMOD_FUNCTION_d_AAdd(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input1 = NULL, *input2 = NULL; \
    PyArrayObject *data1, *data2; \
    double mean1, mean2, result; \
    int stride1=1, stride2=1; \
    size_t n1, n2; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!O!dd", &PyArray_Type, &data1, &PyArray_Type, &data2, &mean1, &mean2) \
       && (data1->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_)) \
       && (data2->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if((data1->nd != 1) ||(data2->nd != 1)) { \
            PyErr_SetString(PyExc_ValueError, "data arrays must be one-dimensional"); \
            return NULL; \
        } \
        stride1 = data1->strides[0] / sizeof(STATMOD_C_TYPE); \
        stride2 = data2->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "OOdd", &input1, &input2, &mean1, &mean2)) \
            return NULL; \
        if(NULL == (data1 = (PyArrayObject *)PyArray_ContiguousFromObject(input1, \
                                                                          STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                          1, 1))) \
            return NULL; \
        if(NULL == (data2 = (PyArrayObject *)PyArray_ContiguousFromObject(input2, \
                                                                          STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                          1, 1))) { \
            STATMOD_FREE(data1) \
            return NULL; \
        } \
    } \
    n1 = data1->dimensions[0]; \
    n2 = data2->dimensions[0]; \
    if(n1 != n2) { \
        PyErr_SetString(PyExc_ValueError, "data arrays must be of same length"); \
        if(NULL != input1) { STATMOD_FREE(data1) }\
        return NULL; \
     } \
    result = STATMOD_FUNC_EXT(gsl_stats,_ ## name)((STATMOD_C_TYPE *)data1->data, stride1, \
                                                   (STATMOD_C_TYPE *)data2->data, stride2, n1, \
                                                   mean1, mean2); \
    if(NULL != input1) { STATMOD_FREE(data1) } \
    if(NULL != input2) { STATMOD_FREE(data2) } \
    return PyFloat_FromDouble(result); \
}


#define STATMOD_FUNCTION_d_Ad(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input = NULL; \
    PyArrayObject *data; \
    double mean; \
    double result; \
    size_t stride=1, n; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!d", &PyArray_Type, &data, &mean) \
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if(data->nd != 1) { \
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional"); \
            return NULL; \
        } \
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "Od", &input, &mean)) \
            return NULL; \
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input, \
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                         1, 1))) \
            return NULL; \
    } \
    n = data->dimensions[0]; \
    result = STATMOD_FUNC_EXT(gsl_stats, _ ## name)((STATMOD_C_TYPE *)data->data, stride, n, mean); \
    if(NULL != input) { STATMOD_FREE(data) } \
    return PyFloat_FromDouble(result); \
}


#define STATMOD_FUNCTION_d_Add(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name, )(PyObject *self, PyObject *args) \
{ \
    PyObject *input; \
    PyArrayObject *data; \
    double mean, sd; \
    double result; \
    int stride=1; \
    size_t n; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!dd", &PyArray_Type, &data, &mean, &sd) \
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if(data->nd != 1) { \
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional"); \
            return NULL; \
        } \
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "Odd", &input, &mean, &sd)) \
            return NULL; \
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input, \
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                         1, 1))) \
            return NULL; \
    } \
    n = data->dimensions[0]; \
    result = STATMOD_FUNC_EXT(gsl_stats, _ ## name)((STATMOD_C_TYPE *)data->data, stride, n, mean, sd); \
    if(NULL != input) { \
        STATMOD_FREE(data) \
    } \
    return PyFloat_FromDouble(result); \
}


#define STATMOD_FUNCTION_dd_A(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input = NULL; \
    PyArrayObject *data; \
    STATMOD_C_TYPE result1, result2; \
    int stride=1; \
    size_t n; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!", &PyArray_Type, &data) \
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if(data->nd != 1) { \
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional"); \
            return NULL; \
        } \
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "O", &input)) \
            return NULL; \
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input, \
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                         1, 1))) \
            return NULL; \
    } \
    n = data->dimensions[0]; \
    STATMOD_FUNC_EXT(gsl_stats,_ ## name)(&result1, &result2, (STATMOD_C_TYPE *)data->data, stride, n); \
    if(NULL != input) { \
        STATMOD_FREE(data) \
    } \
    return Py_BuildValue( "dd", result1, result2); \
}


#define STATMOD_FUNCTION_ll_A(name) static PyObject * \
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject *self, PyObject *args) \
{ \
    PyObject *input = NULL; \
    PyArrayObject *data; \
    size_t result1, result2; \
    int stride=1; \
    size_t n; \
 \
    if(NUMERIC && PyArg_ParseTuple(args, "O!", &PyArray_Type, &data) \
       && (data->descr->type_num == STATMOD_APPEND_PYC_TYPE(PyArray_))) { \
        /* already have NumPy array of Floats  */ \
        if(data->nd != 1) { \
            PyErr_SetString(PyExc_ValueError, "data array must be one-dimensional"); \
            return NULL; \
        } \
        stride = data->strides[0] / sizeof(STATMOD_C_TYPE); \
    } else { \
        if(!PyArg_ParseTuple(args, "O", &input)) \
            return NULL; \
        if(NULL == (data = (PyArrayObject *)PyArray_ContiguousFromObject(input, \
                                                                         STATMOD_APPEND_PYC_TYPE(PyArray_), \
                                                                         1, 1))) \
            return NULL; \
    } \
    n = data->dimensions[0]; \
    STATMOD_FUNC_EXT(gsl_stats,_ ## name)(&result1, &result2, (STATMOD_C_TYPE *)data->data, stride, n); \
    if(NULL != input) { \
        STATMOD_FREE(data) \
    } \
    return Py_BuildValue( "ll", result1, result2); \
}




/*** Mean, standard deviation, and variance ***/

STATMOD_FUNCTION_d_A(mean)
STATMOD_FUNCTION_d_A(variance)
STATMOD_FUNCTION_d_Ad(variance_m)
STATMOD_FUNCTION_d_A(sd)
STATMOD_FUNCTION_d_Ad(sd_m)
STATMOD_FUNCTION_d_Ad(variance_with_fixed_mean)
STATMOD_FUNCTION_d_Ad(sd_with_fixed_mean)


/*** Absolute deviation ***/

STATMOD_FUNCTION_d_A(absdev)
STATMOD_FUNCTION_d_Ad(absdev_m)


/*** Higher moments (skewness and kurtosis) ***/

STATMOD_FUNCTION_d_A(skew)
STATMOD_FUNCTION_d_Add(skew_m_sd)
STATMOD_FUNCTION_d_A(kurtosis)
STATMOD_FUNCTION_d_Add(kurtosis_m_sd)


/*** Autocorrelation ***/

STATMOD_FUNCTION_d_A(lag1_autocorrelation)
STATMOD_FUNCTION_d_Ad(lag1_autocorrelation_m)


/*** Covariance ***/

STATMOD_FUNCTION_d_AA(covariance)
STATMOD_FUNCTION_d_AAdd(covariance_m)


/*** Weighted Samples ***/

#ifdef STATMOD_WEIGHTED
STATMOD_FUNCTION_d_AA(wmean)
STATMOD_FUNCTION_d_AA(wvariance)
STATMOD_FUNCTION_d_AAd(wvariance_m)
STATMOD_FUNCTION_d_AA(wsd)
STATMOD_FUNCTION_d_AAd(wsd_m)
STATMOD_FUNCTION_d_AAd(wvariance_with_fixed_mean)
STATMOD_FUNCTION_d_AAd(wsd_with_fixed_mean)
STATMOD_FUNCTION_d_AA(wabsdev)
STATMOD_FUNCTION_d_AAd(wabsdev_m)
STATMOD_FUNCTION_d_AA(wskew)
STATMOD_FUNCTION_d_AAdd(wskew_m_sd)
STATMOD_FUNCTION_d_AA(wkurtosis)
STATMOD_FUNCTION_d_AAdd(wkurtosis_m_sd)
#endif


/*** Maximum and Minimum values ***/

STATMOD_FUNCTION_d_A(max)
STATMOD_FUNCTION_d_A(min)
STATMOD_FUNCTION_dd_A(minmax)
STATMOD_FUNCTION_d_A(max_index)
STATMOD_FUNCTION_d_A(min_index)
STATMOD_FUNCTION_ll_A(minmax_index)

    
/*** Median and Percentiles ***/

STATMOD_FUNCTION_d_A(median_from_sorted_data)
STATMOD_FUNCTION_d_Ad(quantile_from_sorted_data)

    

/*** table of methods ***/

static PyMethodDef STATMOD_APPEND_PYC_TYPE(StatisticsMethods_)[] = {
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
    {"lag1_autocorrelation",            STATMOD_FUNC_EXT(statistics_lag1_autocorrelation,),
                                        METH_VARARGS, ""},
    {"lag1_autocorrelation_m",          STATMOD_FUNC_EXT(statistics_lag1_autocorrelation_m,),
                                        METH_VARARGS, ""},
    {"covariance",                      STATMOD_FUNC_EXT(statistics_covariance,),
                                        METH_VARARGS, ""},
    {"covariance_m",                    STATMOD_FUNC_EXT(statistics_covariance_m,),
                                        METH_VARARGS, ""},
#ifdef STATMOD_WEIGHTED
    {"wmean",                           STATMOD_FUNC_EXT(statistics_wmean,),
                                        METH_VARARGS, ""},
    {"wvariance",                       STATMOD_FUNC_EXT(statistics_wvariance,),
                                        METH_VARARGS, ""},
    {"wvariance_m",                     STATMOD_FUNC_EXT(statistics_wvariance_m,),
                                        METH_VARARGS, ""},
    {"wsd",                             STATMOD_FUNC_EXT(statistics_wsd,),
                                        METH_VARARGS, ""},
    {"wsd_m",                           STATMOD_FUNC_EXT(statistics_wsd_m,),
                                        METH_VARARGS, ""},
    {"wvariance_with_fixed_mean",       STATMOD_FUNC_EXT(statistics_wvariance_with_fixed_mean,),
                                        METH_VARARGS, ""},
    {"wsd_with_fixed_mean",             STATMOD_FUNC_EXT(statistics_wsd_with_fixed_mean,),
                                        METH_VARARGS, ""},
    {"wabsdev",                         STATMOD_FUNC_EXT(statistics_wabsdev,),
                                        METH_VARARGS, ""},
    {"wabsdev_m",                       STATMOD_FUNC_EXT(statistics_wabsdev_m,),
                                        METH_VARARGS, ""},
    {"wskew",                           STATMOD_FUNC_EXT(statistics_wskew,),
                                        METH_VARARGS, ""},
    {"wskew_m_sd",                      STATMOD_FUNC_EXT(statistics_wskew_m_sd,),
                                        METH_VARARGS, ""},
    {"wkurtosis",                       STATMOD_FUNC_EXT(statistics_wkurtosis,),
                                        METH_VARARGS, ""},
    {"wkurtosis_m_sd",                  STATMOD_FUNC_EXT(statistics_wkurtosis_m_sd,),
                                        METH_VARARGS, ""},
#endif
    {"max",                             STATMOD_FUNC_EXT(statistics_max,),
                                        METH_VARARGS, ""},
    {"min",                             STATMOD_FUNC_EXT(statistics_min,),
                                        METH_VARARGS, ""},
    {"minmax",                          STATMOD_FUNC_EXT(statistics_minmax,),
                                        METH_VARARGS, ""},
    {"min_index",                       STATMOD_FUNC_EXT(statistics_min_index,),
                                        METH_VARARGS, ""},
    {"max_index",                       STATMOD_FUNC_EXT(statistics_max_index,),
                                        METH_VARARGS, ""},
    {"minmax_index",                    STATMOD_FUNC_EXT(statistics_minmax_index,),
                                        METH_VARARGS, ""},
    {"median_from_sorted_data",         STATMOD_FUNC_EXT(statistics_median_from_sorted_data,),
                                        METH_VARARGS, ""},
    {"quantile_from_sorted_data",       STATMOD_FUNC_EXT(statistics_quantile_from_sorted_data,),
                                        METH_VARARGS, ""},
    {NULL, NULL, 0, ""}
};






/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
