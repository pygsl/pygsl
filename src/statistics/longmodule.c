/**
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statistics/longmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 */


#include <Python.h>
#ifdef HAVE_NUMERIC
# include <Numeric/arrayobject.h>
#endif
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Long
#define STATMOD_APPEND_PYC_TYPE(X) X ## LONG
#define STATMOD_FUNC_EXT(X, Y) X ## _long ## Y
#define STATMOD_C_TYPE long
#define STATMOD_PY_AS_C PyLong_AsInt
#define STATMOD_PY_FROM_C PyInt_FromLong
#include "functions.c"
#undef STATMOD_PY_FROM_C
#undef STATMOD_PY_AS_C
#undef STATMOD_C_TYPE
#undef STATMOD_FUNC_EXT
#undef STATMOD_APPEND_PYC_TYPE
#undef STATMOD_APPEND_PY_TYPE





/* table of methods */

static PyMethodDef StatisticsLongMethods[] = {
    {"absdev", statistics_absdev_long, METH_VARARGS},
    {"absdev_m", statistics_absdev_m_long, METH_VARARGS},
    {"mean", statistics_mean_long, METH_VARARGS},
    {"sd", statistics_sd_long, METH_VARARGS},
    {"sd_m", statistics_sd_m_long, METH_VARARGS},
    {"sd_with_fixed_mean", statistics_sd_with_fixed_mean_long, METH_VARARGS},
    {"variance", statistics_variance_long, METH_VARARGS},
    {"variance_m", statistics_variance_m_long, METH_VARARGS},
    {"variance_with_fixed_mean", statistics_variance_with_fixed_mean_long, METH_VARARGS},
    {NULL, NULL}
};



/* initialization */

DL_EXPORT(void) initlong(void)
{
    Py_InitModule("long", StatisticsLongMethods);
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
