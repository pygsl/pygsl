/**
 * file: pygsl/src/statisticsmodule.c
 * $Id$
  * "
 */

#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <Python.h>
#include <gsl/gsl_statistics.h>


/* include real functions for default data-types (double in C) */

#define STATMOD_WEIGHTED
#define STATMOD_APPEND_PY_TYPE(X) X ## Float
#define STATMOD_APPEND_PYC_TYPE(X) X ## DOUBLE
#define STATMOD_FUNC_EXT(X, Y) X ## Y
#define STATMOD_PY_AS_C PyFloat_AsDouble
#define STATMOD_C_TYPE double
#define PyGSL_STATISTICS_IMPORT_API
#include "functions.c"



PyGSL_STATISTICS_INIT(double, "double")



/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */


