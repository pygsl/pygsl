/**
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statistics/longmodule.c
 * $Id$
 *
 * optional usage of Numeric module, available at http://numpy.sourceforge.net
 *"
 */


#include <Python.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Int
#define STATMOD_APPEND_PYC_TYPE(X) X ## LONG
#define STATMOD_FUNC_EXT(X, Y) X ## _long ## Y
#define STATMOD_PY_AS_C PyInt_AsLong
#define STATMOD_C_TYPE long int
#include "functions.c"



/* initialization */
PyGSL_STATISTICS_INIT(long, "long")


/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
