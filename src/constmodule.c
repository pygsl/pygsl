/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/constmodule.c
 * $Id$
 */

#include <Python.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_const_cgs.h>
#include <gsl/gsl_const_mks.h>
#include <gsl/gsl_const_num.h>

static PyMethodDef constMethods[] = {
  {NULL,     NULL}        /* Sentinel */
};

typedef struct {
  char* name;
  double value;
  char* doc;
} constConstants;

constConstants m_array[]={
#include "const_m_array.c"
{NULL,0,NULL}
};

constConstants mks_array[]={
# include "const_mks_array.c"
  {NULL,0,NULL}
};

constConstants cgs_array[]={
# include "const_cgs_array.c"
  {NULL,0,NULL}
};

constConstants num_array[]={
# include "const_num_array.c"
  {NULL,0,NULL}
};



static void
add_constants(constConstants* constants, PyObject* m)
{
  int i=0;
  while (constants[i].name!=NULL) {
    PyObject* floatObject=PyFloat_FromDouble(constants[i].value);
    if (floatObject==NULL) break;
    PyModule_AddObject(m,constants[i].name,floatObject);
    /* Py_DECREF(floatObject); */
    i++;
  }
}

DL_EXPORT(void) initconst(void)
{
  PyObject* const_module = Py_InitModule("const", constMethods);
  PyObject* mks_module   = PyImport_AddModule("pygsl.const.mks");
  PyObject* cgs_module   = PyImport_AddModule("pygsl.const.cgs");
  PyObject* math_module  = PyImport_AddModule("pygsl.const.m");
  PyObject* num_module   = PyImport_AddModule("pygsl.const.num");

  /* distribute constants on modules */
  add_constants(m_array  , const_module);
  add_constants(num_array, const_module);
  add_constants(mks_array, const_module);
  add_constants(mks_array, mks_module);
  add_constants(cgs_array, cgs_module);
  add_constants(num_array, num_module);
  add_constants(m_array  , math_module);

  PyModule_AddObject(const_module, "m",   math_module);
  PyModule_AddObject(const_module, "cgs", cgs_module);
  PyModule_AddObject(const_module, "mks", mks_module);
  PyModule_AddObject(const_module, "num", num_module);
  return;
}

