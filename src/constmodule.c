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

static void add_math_constants(PyObject* m)
{
#include "const_add_math.c"
}

static void add_num_constants(PyObject* m)
{
#include "const_add_num.c"
}

static void add_mks_constants(PyObject *m){
#include "const_add_mks.c"
}

static void add_cgs_constants(PyObject *m){
#include "const_add_cgs.c"
}

DL_EXPORT(void) initconst(void)
{
  PyObject* const_module = Py_InitModule("const", constMethods);
  PyObject* mks_module   = PyImport_AddModule("pygsl.const.mks");
  PyObject* cgs_module   = PyImport_AddModule("pygsl.const.cgs");
  PyObject* math_module  = PyImport_AddModule("pygsl.const.math");
  PyObject* num_module   = PyImport_AddModule("pygsl.const.num");

  /* distribute constants on modules */
  add_math_constants(const_module);
  add_num_constants(const_module);
  add_mks_constants(const_module);
  add_mks_constants(mks_module);
  add_cgs_constants(cgs_module);
  add_num_constants(num_module);
  add_math_constants(math_module);

  /* add them to to the root module */
  PyModule_AddObject(const_module,"cgs",cgs_module);
  PyModule_AddObject(const_module,"mks",mks_module);
  PyModule_AddObject(const_module,"math",math_module);
  PyModule_AddObject(const_module,"num",num_module);

  return;
}

