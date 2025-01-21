/*
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * " <- to fix Emacs colouring
 */

/*
 * 27. December 2003. Removed support for non numeric part.
 *  Pierre Schnizer <schnizer@users.sourceforge.net>
 *
 *    March 2004: Made it compatible with nummarray
 *       On this way: converted the macros to functions and generated functions
 *       pushing the pointer to the function on the stack
 *       Converted it to use the conversion functions as defined in <pygsl/block_helpers.h>
 */


#include <pygsl/block_helpers.h>

#define PyGSL_STATISTICS_IMPORT_API
#include "statmodule.h"

/** macros of the actual function implementations
 *
 * One macro for each kind of parameter set.
 */
static PyObject*
statistics_t_A(PyObject *self, PyObject *args, STATMOD_C_TYPE (*pointer)(const STATMOD_C_TYPE *, size_t, size_t))
{
    PyObject *input = NULL, *r; 
    PyArrayObject *data; 
    STATMOD_C_TYPE  result;
    PyGSL_array_index_t stride=1, n;
    PyGSL_array_info_t info;
    int flag; 
    
    FUNC_MESS_BEGIN();
    if(!(PyArg_ParseTuple(args, "O", &input))) 
	return NULL;

    info = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, 
				  STATMOD_APPEND_PYC_TYPE(NPY_), 
				  sizeof(STATMOD_C_TYPE), 1);
    data = PyGSL_vector_check(input, -1, info, &stride, NULL);
    if(data == NULL)
	 return NULL;

    n = PyArray_DIM(data, 0);
    result = pointer((STATMOD_C_TYPE *)PyArray_DATA(data), (size_t) stride, (size_t) n);
    Py_DECREF(data);
    
    flag = STATMOD_APPEND_PYC_TYPE(NPY_);
    if(flag == NPY_DOUBLE || flag == NPY_FLOAT)
	r = PyFloat_FromDouble((double) result);
    else
	r = PyLong_FromLong((long) result);
    FUNC_MESS_END();
    return r;
}

static PyObject*
statistics_tt_A(PyObject *self, PyObject *args, void (*pointer)(STATMOD_C_TYPE *, STATMOD_C_TYPE *, const STATMOD_C_TYPE *, size_t, size_t))
{
    PyObject *input = NULL, *r; 
    PyArrayObject *data; 
    STATMOD_C_TYPE result1, result2;
    PyGSL_array_index_t stride=1, n;
    PyGSL_array_info_t info;
    int flag;

    FUNC_MESS_BEGIN();

    if(!(PyArg_ParseTuple(args, "O", &input))) 
	return NULL;

    info = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, 
				  STATMOD_APPEND_PYC_TYPE(NPY_), 
				  sizeof(STATMOD_C_TYPE), 1);
    data = PyGSL_vector_check(input, -1, info, &stride, NULL);
    if(data == NULL) 
	return NULL;


    n = PyArray_DIM(data, 0);
    pointer(&result1, &result2, (STATMOD_C_TYPE *)PyArray_DATA(data), (size_t) stride, (size_t) n);
    Py_DECREF(data); 
    
    r = PyTuple_New(2);
    flag = STATMOD_APPEND_PYC_TYPE(NPY_);
    if(flag == NPY_DOUBLE || flag == NPY_FLOAT){
	PyTuple_SET_ITEM(r, 0, PyFloat_FromDouble((double) result1));
	PyTuple_SET_ITEM(r, 1, PyFloat_FromDouble((double) result2));
    }else{
	PyTuple_SET_ITEM(r, 0, PyLong_FromLong((long) result1));
	PyTuple_SET_ITEM(r, 1, PyLong_FromLong((long) result2));
    }
    FUNC_MESS_END();
    return r;
}

#define _STATMOD_FUNCTION_GENERIC(name, type)\
static PyObject *\
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject * self, PyObject *args) \
{\
     return statistics_## type(self, args, STATMOD_FUNC_EXT(gsl_stats,_ ## name)); \
}

#define STATMOD_FUNCTION_t_A(name)    _STATMOD_FUNCTION_GENERIC(name, t_A)
#define STATMOD_FUNCTION_tt_A(name)   _STATMOD_FUNCTION_GENERIC(name, tt_A)

#undef STATMOD_FUNCTION_GENERIC
#define STATMOD_FUNCTION_GENERIC(name, type)\
static PyObject *\
STATMOD_FUNC_EXT(statistics_ ## name,)(PyObject * self, PyObject *args) \
{\
     return PyGSL_statistics_## type(self, args, (void *) STATMOD_FUNC_EXT(gsl_stats,_ ## name),\
				     STATMOD_APPEND_PYC_TYPE(NPY_), sizeof(STATMOD_C_TYPE));\
}

#define STATMOD_FUNCTION_d_A(name)   STATMOD_FUNCTION_GENERIC(name, d_A)

#define STATMOD_FUNCTION_l_A(name)   STATMOD_FUNCTION_GENERIC(name, l_A)
#define STATMOD_FUNCTION_d_Ad(name)  STATMOD_FUNCTION_GENERIC(name, d_Ad)
#define STATMOD_FUNCTION_d_Add(name) STATMOD_FUNCTION_GENERIC(name, d_Add)
#define STATMOD_FUNCTION_d_Add(name) STATMOD_FUNCTION_GENERIC(name, d_Add)

#define STATMOD_FUNCTION_d_AA(name)   STATMOD_FUNCTION_GENERIC(name, d_AA)
#define STATMOD_FUNCTION_d_AAdd(name) STATMOD_FUNCTION_GENERIC(name, d_AAdd)
#ifdef STATMOD_WEIGHTED
#define STATMOD_FUNCTION_d_AAd(name)  STATMOD_FUNCTION_GENERIC(name, d_AAd)
#endif

#define STATMOD_FUNCTION_ll_A(name)   STATMOD_FUNCTION_GENERIC(name, ll_A)

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
/*
  STATMOD_FUNCTION_d_A(max)
  STATMOD_FUNCTION_d_A(min)
  STATMOD_FUNCTION_dd_A(minmax)
*/
STATMOD_FUNCTION_t_A(max)
STATMOD_FUNCTION_t_A(min)
STATMOD_FUNCTION_tt_A(minmax)
STATMOD_FUNCTION_l_A(max_index)
STATMOD_FUNCTION_l_A(min_index)
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


#ifdef PyGSL_PY3K
#define PyGSL_STATISTICS_INIT(type, typestr)         \
static struct PyModuleDef moduledef = {              \
        PyModuleDef_HEAD_INIT,			      \
        "pygsl.statistics" typestr, 	              \
        NULL,					      \
        -1,					      \
        STATMOD_APPEND_PYC_TYPE(StatisticsMethods_), \
        NULL,					      \
        NULL,					      \
        NULL,					      \
        NULL					      \
};                                                   \
PyMODINIT_FUNC PyInit_ ## type (void)                \
{                                                    \
    PyObject *m = NULL;                              \
    FUNC_MESS_BEGIN();                               \
    m = PyModule_Create(&moduledef);                 \
    if(m == NULL) return NULL;                       \
    init_pygsl();                                    \
    import_pygsl_stats();                            \
    FUNC_MESS_END();                                 \
    return m;                                        \
}
#else  /* PyGSL_PY3K */
/* initialization */
#define PyGSL_STATISTICS_INIT(type, typestr) \
DL_EXPORT(void) init ## type (void) \
{ \
    FUNC_MESS_BEGIN(); \
    Py_InitModule(typestr, STATMOD_APPEND_PYC_TYPE(StatisticsMethods_)); \
    init_pygsl(); \
    import_pygsl_stats(); \
    FUNC_MESS_END(); \
    return; \
}
#endif /* PyGSL_PY3K */

/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
