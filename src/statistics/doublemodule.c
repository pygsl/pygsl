/**
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 */


#include <Python.h>
#if NUMERIC!=0
# define PY_ARRAY_UNIQUE_SYMBOL PYGSL_STATISTICS_DOUBLE
# include <Numeric/arrayobject.h>
#endif
#include <gsl/gsl_statistics.h>


/* include real functions for default data-types (double in C) */

#define STATMOD_WEIGHTED
#define STATMOD_APPEND_PY_TYPE(X) X ## Float
#define STATMOD_APPEND_PYC_TYPE(X) X ## DOUBLE
#define STATMOD_FUNC_EXT(X, Y) X ## Y
#define STATMOD_PY_AS_C PyFloat_AsDouble
#define STATMOD_C_TYPE double
#include "functions.c"




/* initialization */

DL_EXPORT(void) initdouble(void)
{
#if NUMERIC!=0
    import_array();
#endif
    (void)Py_InitModule("double", STATMOD_APPEND_PYC_TYPE(StatisticsMethods_));
    return;
}



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */


