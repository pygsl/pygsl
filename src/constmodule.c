/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/constmodule.c
 * $Id$
 *
 *
 * Changes:
 *    7. October 2003 Added support for gsl-1.4 constants.
 */

#include <Python.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_const_num.h>

#if (PYGSL_GSL_MAJOR_VERSION == 1) && (PYGSL_GSL_MINOR_VERSION < 4)
/* WARNING deprecated!! */
/* #warning "DEPRECATED! Consider upgrading to gsl 1.4 or higher!" */
#define _PYGSL_GSL_HAS_CGS 1
#define _PYGSL_GSL_HAS_MKS 1
#include <gsl/gsl_const_cgs.h>
#include <gsl/gsl_const_mks.h>
#else /* (PYGSL_GSL_MAJOR_VERSION == 1) && (PYGSL_GSL_MINOR_VERSION < 4) */
#define _PYGSL_GSL_HAS_CGSM 1
#define _PYGSL_GSL_HAS_MKSA 1
#include <gsl/gsl_const_cgsm.h>
#include <gsl/gsl_const_mksa.h>
#if (PYGSL_GSL_MAJOR_VERSION == 1) && (PYGSL_GSL_MINOR_VERSION > 5)
#define _PYGSL_GSL_HAS_CGS 1
#define _PYGSL_GSL_HAS_MKS 1
#include <gsl/gsl_const_cgs.h>
#include <gsl/gsl_const_mks.h>
#endif
#endif /* (PYGSL_GSL_MAJOR_VERSION == 1) && (PYGSL_GSL_MINOR_VERSION < 4) */



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

#ifdef _PYGSL_GSL_HAS_MKS
constConstants mks_array[]={
#include "const_mks_array.c"
  {NULL,0,NULL}
};
#endif

#ifdef _PYGSL_GSL_HAS_CGS
constConstants cgs_array[]={
#include "const_cgs_array.c"
  {NULL,0,NULL}
};
#endif

#ifdef _PYGSL_GSL_HAS_MKSA
constConstants mksa_array[]={
#include "const_mksa_array.c"
  {NULL,0,NULL}
};
#endif

#ifdef _PYGSL_GSL_HAS_CGSM
constConstants cgsm_array[]={
#include "const_cgsm_array.c"
  {NULL,0,NULL}
};
#endif

constConstants num_array[]={
#include "const_num_array.c"
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

#ifdef _PYGSL_GSL_HAS_MKS
  PyObject* mks_module   = PyImport_AddModule("pygsl.const.mks");
#endif
#ifdef _PYGSL_GSL_HAS_CGS
  PyObject* cgs_module   = PyImport_AddModule("pygsl.const.cgs");
#endif

#ifdef _PYGSL_GSL_HAS_MKSA
  PyObject* mksa_module   = PyImport_AddModule("pygsl.const.mksa");
#endif
#ifdef _PYGSL_GSL_HAS_CGSM
  PyObject* cgsm_module   = PyImport_AddModule("pygsl.const.cgsm");
#endif

  PyObject* math_module  = PyImport_AddModule("pygsl.const.m");
  PyObject* num_module   = PyImport_AddModule("pygsl.const.num");

  /* distribute constants on modules */
  add_constants(m_array  , const_module);
  add_constants(num_array, const_module);

#ifdef _PYGSL_GSL_HAS_MKS
  add_constants(mks_array, const_module);
  add_constants(mks_array, mks_module);
#endif
#ifdef _PYGSL_GSL_HAS_CGS
  add_constants(cgs_array, cgs_module);
#endif

#ifdef _PYGSL_GSL_HAS_MKSA
  add_constants(mksa_array, const_module);
  add_constants(mksa_array, mksa_module);
#endif
#ifdef _PYGSL_GSL_HAS_CGSM
  add_constants(cgsm_array, cgsm_module);
#endif

  add_constants(num_array, num_module);
  add_constants(m_array  , math_module);

  PyModule_AddObject(const_module, "m",   math_module);
#ifdef _PYGSL_GSL_HAS_CGS
  PyModule_AddObject(const_module, "cgs", cgs_module);
#endif
#ifdef _PYGSL_GSL_HAS_MKS
  PyModule_AddObject(const_module, "mks", mks_module);
#endif
   
#ifdef _PYGSL_GSL_HAS_CGSM
  PyModule_AddObject(const_module, "cgsm", cgsm_module);
#endif
#ifdef _PYGSL_GSL_HAS_MKSA
  PyModule_AddObject(const_module, "mksa", mksa_module);
#endif

  PyModule_AddObject(const_module, "num", num_module);
  return;
}

