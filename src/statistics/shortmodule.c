/**
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statistics/longmodule.c
 * $Id$
 *
 * "
 */


#include <Python.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Int
#define STATMOD_APPEND_PYC_TYPE(X) X ## SHORT
#define STATMOD_FUNC_EXT(X, Y) X ## _short ## Y
#define STATMOD_PY_AS_C PyInt_AsLong
#define STATMOD_C_TYPE short int
#include "functions.c"




/* initialization */

PyGSL_STATISTICS_INIT(short, "short")


/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
