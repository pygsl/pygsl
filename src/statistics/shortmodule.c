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

#define STATMOD_APPEND_PY_TYPE(X) X ## Int16
#define STATMOD_APPEND_PYC_TYPE(X) X ## SHORT
#define STATMOD_FUNC_EXT(X, Y) X ## _short ## Y
#define STATMOD_C_TYPE short int
#define STATMOD_PY_AS_C PyLong_AsShort
#define STATMOD_PY_FROM_C PyInt_FromShort
#include "functions.c"
#undef STATMOD_PY_FROM_C
#undef STATMOD_PY_AS_C
#undef STATMOD_C_TYPE
#undef STATMOD_FUNC_EXT
#undef STATMOD_APPEND_PYC_TYPE
#undef STATMOD_APPEND_PY_TYPE




/* initialization */

DL_EXPORT(void) initshort(void)
{
    Py_InitModule("short", StatisticsMethods_SHORT);
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
