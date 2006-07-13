/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/sfmodule.c
 * $Id$
 */
#include <pygsl/error_helpers.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_errno.h>



static PyObject* gsl_module_error;

int eval_gsl_mode_char(gsl_mode_t* mode, char mode_char) {

  char error_text[]="illegal gsl_mode";
  PyObject* gsl_error_object;
  PyObject* gsl_error_module;
  PyObject* gsl_error_dict;

  switch (mode_char)
    {
    case 's':
    case 'S':
      *mode=GSL_PREC_SINGLE;
      return 0;
    case 'a':
    case 'A':
      *mode=GSL_PREC_APPROX;
      return 0;
    case 'd':
    case 'D':
      *mode=GSL_PREC_DOUBLE;
      return 0;
    }
  /* must set exception */
  gsl_error_module=PyImport_ImportModule("pygsl.errors");
  gsl_error_dict=PyModule_GetDict(gsl_error_module);
  gsl_error_object=PyDict_GetItemString(gsl_error_dict,"gsl_Error");
  PyErr_SetObject(gsl_error_object,
		  PyString_FromString(error_text));

  return -1;
}

static PyObject* gsl_sf_gauss(PyObject *self,
			      PyObject *args
			      )
{
  const double norm=1.0/M_SQRT2/M_SQRTPI;
  double x;
  double sigma=1.0;
  double mu=0;
  double tmp;
  gsl_sf_result result;
  int err_result;
  PyObject* python_result;

  if (!PyArg_ParseTuple(args, "d|dd:gauss", &x, &mu,  &sigma))
    return NULL;
  
  /*use tmp as temporary variable*/
  tmp=((x-mu)/sigma);
  err_result=gsl_sf_exp_mult_e(tmp*tmp/-2.0,
				  norm/sigma,
				  &result);
  if (err_result)
    return NULL;

  python_result=PyTuple_New(2);
  if (python_result==NULL)
    return NULL;
  PyTuple_SetItem(python_result,0,PyFloat_FromDouble(result.val));
  PyTuple_SetItem(python_result,1,PyFloat_FromDouble(result.err));
  return python_result;
}

/*automatically wrapped functions*/
#include "sf_functions.c"

static PyMethodDef sfMethods[] = {
#include "sf_index.c"
  {"gauss",gsl_sf_gauss, METH_VARARGS},
  {NULL,     NULL}        /* Sentinel */
};

DL_EXPORT(void) initsf(void)
{
  PyObject* gsl_errors_module;
  PyObject* sf_module;
  PyObject* gsl_errors_dict;

  gsl_errors_module=PyImport_ImportModule ("pygsl.errors");
  init_pygsl();
  /* here is an error check needed! */
  gsl_errors_dict=PyModule_GetDict(gsl_errors_module);
  gsl_module_error=PyDict_GetItemString(gsl_errors_dict,"gsl_Error");
  sf_module=Py_InitModule("sf", sfMethods);

  return;
}
