/**
 * author: Jochen K"upper
 * created: Jan 2002
 * file: pygsl/src/statisticsmodule.c
 * $Id$
 *
 * "
 */


#include <Python.h>
#include <gsl/gsl_statistics.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>


/* include real functions for default data-types (double in C) */

#define STATMOD_WEIGHTED
#define STATMOD_APPEND_PY_TYPE(X) X ## Float32
#define STATMOD_APPEND_PYC_TYPE(X) X ## FLOAT
#define STATMOD_FUNC_EXT(X, Y) X ## _float ## Y
#define STATMOD_PY_AS_C PyFloat_AsDouble
#define STATMOD_C_TYPE float
#include "functions.c"



/* initialization */

PyGSL_STATISTICS_INIT(float, "float")


/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */


