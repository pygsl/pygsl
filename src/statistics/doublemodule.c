/**
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


/* include real functions for default data-types (double in C) */

#define STATMOD_APPEND_PY_TYPE(X) X ## Float
#define STATMOD_APPEND_PYC_TYPE(X) X ## DOUBLE
#define STATMOD_FUNC_EXT(X, Y) X ## Y
#define STATMOD_C_TYPE double
#define STATMOD_PY_AS_C PyFloat_AsDouble
#define STATMOD_PY_FROM_C PyFloat_FromDouble
#include "functions.c"
#undef STATMOD_PY_FROM_C
#undef STATMOD_PY_AS_C
#undef STATMOD_C_TYPE
#undef STATMOD_FUNC_EXT
#undef STATMOD_APPEND_PYC_TYPE
#undef STATMOD_APPEND_PY_TYPE




/* table of methods */

static PyMethodDef StatisticsMethods[] = {
    {"absdev", statistics_absdev, METH_VARARGS, ""},
    {"absdev_m", statistics_absdev_m, METH_VARARGS, ""},
    {"mean", statistics_mean, METH_VARARGS, ""},
    {"sd", statistics_sd, METH_VARARGS, ""},
    {"sd_m", statistics_sd_m, METH_VARARGS, ""},
    {"sd_with_fixed_mean", statistics_sd_with_fixed_mean, METH_VARARGS, ""},
    {"variance", statistics_variance, METH_VARARGS, ""},
    {"variance_m", statistics_variance_m, METH_VARARGS, ""},
    {"variance_with_fixed_mean", statistics_variance_with_fixed_mean, METH_VARARGS, ""},
    {NULL, NULL, 0, ""}
};



/* initialization */

DL_EXPORT(void) initdouble(void)
{
#ifdef HAVE_NUMERIC
    import_array();
#endif
    (void)Py_InitModule("double", StatisticsMethods);
    return;
}



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */


