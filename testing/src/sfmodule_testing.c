/*
 * author: Pierre Schnizer
 * created: June 2003
 */
#define DEBUG 10
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_nan.h>
#include <Python.h>
#include <Numeric/arrayobject.h>
#include <Numeric/ufuncobject.h>

/* #include <pygsl/block_helpers.h>
   #include <pygsl/utils.h>
   #include <pygsl/error_helpers.h>
*/

static PyObject* gsl_module_error;
static PyObject* module = NULL; /*used by the backtrace*/


static void 
invoke_error_handler(char *filename, char *func_name, int errno, int element)
{
     ;
     /* DEBUG_MESS(2, "Got error flag of %d for element number %d", errno, element); */
}
/* I add the evaluate functions types by hand to have an extra check */

static PyMethodDef sf_functions[] = {
     {NULL, NULL, 0}
};

#include "sf__evals.c"
#include "sf__data.c"

DL_EXPORT(void) initsf(void)
{
  PyObject* gsl_errors_module;
  PyObject* sf_module, *sf_dict;
  PyObject* gsl_errors_dict;
  PyObject* f;

  sf_module=Py_InitModule("sf", sf_functions);
  module = sf_module;
  import_array();
  import_ufunc();

  /* here is an error check needed! */
  /*
  gsl_errors_module=PyImport_ImportModule ("pygsl.errors");

  gsl_errors_dict=PyModule_GetDict(gsl_errors_module);
  gsl_module_error=PyDict_GetItemString(gsl_errors_dict,"gsl_Error");
  */


  sf_dict=PyModule_GetDict(sf_module);
  PyDict_SetItemString(sf_dict, "PREC_DOUBLE", PyInt_FromLong(GSL_PREC_DOUBLE));
  PyDict_SetItemString(sf_dict, "PREC_SINGLE", PyInt_FromLong(GSL_PREC_SINGLE));
  PyDict_SetItemString(sf_dict, "PREC_APPROX", PyInt_FromLong(GSL_PREC_APPROX));

#include "sf__objects.c"


  module = sf_module;

  return;
}
