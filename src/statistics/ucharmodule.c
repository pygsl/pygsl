/**
 * author: Jochen K"upper, Pierre Schnizer
 * created: Jan 2002
 * updated: 2024
 * file: pygsl/src/statistics/longmodule.c
 * $Id$
 *
 *"
 */


#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_statistics.h>


/* include real functions for different data-types */

#define STATMOD_APPEND_PY_TYPE(X) X ## Int
#define STATMOD_APPEND_PYC_TYPE(X) X ## UBYTE
#define STATMOD_FUNC_EXT(X, Y) X ## _uchar ## Y
#define STATMOD_PY_AS_C PyInt_AsLong
#define STATMOD_C_TYPE unsigned char
#include "functions.c"






PyGSL_STATISTICS_INIT(uchar, "uchar")


/*
 * Local Variables:
 * mode: c
 * c-file-style: "Stroustrup"
 * End:
 */
