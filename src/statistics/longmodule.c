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
# define PY_ARRAY_UNIQUE_SYMBOL PYGSL_STATISTICS_LONG
# include <Numeric/arrayobject.h>
#endif
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Int
#define STATMOD_APPEND_PYC_TYPE(X) X ## LONG
#define STATMOD_FUNC_EXT(X, Y) X ## _long ## Y
#define STATMOD_C_TYPE long int
#include "functions.c"



/* initialization */

DL_EXPORT(void) initlong(void)
{
    Py_InitModule("long", STATMOD_APPEND_PYC_TYPE(StatisticsMethods_));
#ifdef HAVE_NUMERIC
    import_array();
#endif
    return;
}


#undef STATMOD_C_TYPE
#undef STATMOD_FUNC_EXT
#undef STATMOD_APPEND_PYC_TYPE
#undef STATMOD_APPEND_PY_TYPE



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
