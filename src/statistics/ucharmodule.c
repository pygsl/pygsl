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
# define PY_ARRAY_UNIQUE_SYMBOL PYGSL_STATISTICS_UCHAR
# include <Numeric/arrayobject.h>
#endif
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Int
#define STATMOD_APPEND_PYC_TYPE(X) X ## UBYTE
#define STATMOD_FUNC_EXT(X, Y) X ## _uchar ## Y
#define STATMOD_PY_AS_C PyInt_AsLong
#define STATMOD_C_TYPE unsigned char
#include "functions.c"




/* initialization */

DL_EXPORT(void) inituchar(void)
{
    Py_InitModule("uchar", STATMOD_APPEND_PYC_TYPE(StatisticsMethods_));
#if NUMERIC!=0
    import_array();
#endif
    return;
}


#undef STATMOD_C_TYPE
#undef STATMOD_PY_AS_C
#undef STATMOD_FUNC_EXT
#undef STATMOD_APPEND_PYC_TYPE
#undef STATMOD_APPEND_PY_TYPE



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
