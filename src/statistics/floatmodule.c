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

#define STATMOD_WEIGHTED
#define STATMOD_APPEND_PY_TYPE(X) X ## Float32
#define STATMOD_APPEND_PYC_TYPE(X) X ## FLOAT
#define STATMOD_FUNC_EXT(X, Y) X ## _float ## Y
#define STATMOD_C_TYPE float
#include "functions.c"



/* initialization */

DL_EXPORT(void) initfloat(void)
{
#ifdef HAVE_NUMERIC
    import_array();
#endif
    (void)Py_InitModule("float", STATMOD_APPEND_PYC_TYPE(StatisticsMethods_));
    return;
}


#undef STATMOD_C_TYPE
#undef STATMOD_FUNC_EXT
#undef STATMOD_APPEND_PYC_TYPE
#undef STATMOD_APPEND_PY_TYPE
#undef STATMOD_WEIGHTED


/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */


