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
# define PY_ARRAY_UNIQUE_SYMBOL PYGSL_STATISTICS_DOUBLE
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




/* initialization */

DL_EXPORT(void) initdouble(void)
{
#ifdef HAVE_NUMERIC
    import_array();
#endif
    (void)Py_InitModule("double", StatisticsMethods_Float);
    return;
}



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */


