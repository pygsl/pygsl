/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/constmodule.c
 * $Id$
 */

#include <Python.h>
#include <gsl/gsl_math.h>

static PyMethodDef constMethods[] = {
  {NULL,     NULL}        /* Sentinel */
};

static void add_constants(PyObject* m)
{
  PyModule_AddObject(m,"posinf",PyFloat_FromDouble(GSL_POSINF));
  PyModule_AddObject(m,"neginf",PyFloat_FromDouble(GSL_NEGINF));
  PyModule_AddObject(m,"nan",PyFloat_FromDouble(GSL_NAN));
  PyModule_AddObject(m,"e",PyFloat_FromDouble(M_E));
  PyModule_AddObject(m,"log2e",PyFloat_FromDouble(M_LOG2E));
  PyModule_AddObject(m,"log10e",PyFloat_FromDouble(M_LOG10E));
  PyModule_AddObject(m,"sqrt2",PyFloat_FromDouble(M_SQRT2));
  PyModule_AddObject(m,"sqrt1_2",PyFloat_FromDouble(M_SQRT1_2));
  PyModule_AddObject(m,"sqrt3",PyFloat_FromDouble(M_SQRT3));
  PyModule_AddObject(m,"pi",PyFloat_FromDouble(M_PI));
  PyModule_AddObject(m,"pi_2",PyFloat_FromDouble(M_PI_2));
  PyModule_AddObject(m,"pi_4",PyFloat_FromDouble(M_PI_4));
  PyModule_AddObject(m,"sqrtpi",PyFloat_FromDouble(M_SQRTPI));
  PyModule_AddObject(m,"two_sqrtpi",PyFloat_FromDouble(M_2_SQRTPI));
  PyModule_AddObject(m,"one_pi",PyFloat_FromDouble(M_1_PI));
  PyModule_AddObject(m,"two_pi",PyFloat_FromDouble(M_2_PI));
  PyModule_AddObject(m,"ln10",PyFloat_FromDouble(M_LN10));
  PyModule_AddObject(m,"ln2",PyFloat_FromDouble(M_LN2));
  PyModule_AddObject(m,"lnpi",PyFloat_FromDouble(M_LNPI));
  PyModule_AddObject(m,"euler",PyFloat_FromDouble(M_EULER));
# include "scientific_constants.c"
}


DL_EXPORT(void) initconst(void)
{
  /* error handler for gsl routines, sets exception */

  PyObject* m=Py_InitModule("const", constMethods);
  add_constants(m);

  return;
}
