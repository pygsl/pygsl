/**
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statistics/longmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 */


#include <Python.h>
#if NUMERIC!=0
# define PY_ARRAY_UNIQUE_SYMBOL PYGSL_STATISTICS_LONG
# include <Numeric/arrayobject.h>
#endif
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Int
#define STATMOD_APPEND_PYC_TYPE(X) X ## SHORT
#define STATMOD_FUNC_EXT(X, Y) X ## _short ## Y
#define STATMOD_PY_AS_C PyInt_AsLong
#define STATMOD_C_TYPE short int
#include "functions.c"




/* initialization */

DL_EXPORT(void) initshort(void)
{
    Py_InitModule("short", STATMOD_APPEND_PYC_TYPE(StatisticsMethods_));
#if NUMERIC!=0
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
