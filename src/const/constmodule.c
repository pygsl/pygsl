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
#include <pygsl/error_helpers.h>
#include "pygsl_const_config.h"

#ifdef _PYGSL_GSL_HAS_CONST_CGS
#include <gsl/gsl_const_cgs.h>
#endif

#ifdef _PYGSL_GSL_HAS_CONST_CGSM
#include <gsl/gsl_const_cgsm.h>
#else
#error "Should be defined"
#endif

#ifdef _PYGSL_GSL_HAS_CONST_MKS
#include <gsl/gsl_const_mks.h>
#endif

#ifdef _PYGSL_GSL_HAS_CONST_MKSA
#include <gsl/gsl_const_mksa.h>
#endif


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

#ifdef _PYGSL_GSL_HAS_CONST_MKS
constConstants mks_array[]={
#include "const_mks_array.c"
  {NULL,0,NULL}
};
#endif

#ifdef _PYGSL_GSL_HAS_CONST_CGS
constConstants cgs_array[]={
#include "const_cgs_array.c"
  {NULL,0,NULL}
};
#endif

#ifdef _PYGSL_GSL_HAS_CONST_MKSA
constConstants mksa_array[]={
#include "const_mksa_array.c"
  {NULL,0,NULL}
};
#endif

#ifdef _PYGSL_GSL_HAS_CONST_CGSM
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


static int
_init_const_module(PyObject * const_module)
{
#ifdef _PYGSL_GSL_HAS_CONST_MKS
  PyObject* mks_module   = PyImport_AddModule("pygsl.const.mks");
#endif
#ifdef _PYGSL_GSL_HAS_CONST_CGS
  PyObject* cgs_module   = PyImport_AddModule("pygsl.const.cgs");
#endif

#ifdef _PYGSL_GSL_HAS_CONST_MKSA
  PyObject* mksa_module   = PyImport_AddModule("pygsl.const.mksa");
#endif
#ifdef _PYGSL_GSL_HAS_CONST_CGSM
  PyObject* cgsm_module   = PyImport_AddModule("pygsl.const.cgsm");
#endif

  PyObject* math_module  = PyImport_AddModule("pygsl.const.m");
  PyObject* num_module   = PyImport_AddModule("pygsl.const.num");

  /* distribute constants on modules */
  add_constants(m_array  , const_module);
  add_constants(num_array, const_module);

#ifdef _PYGSL_GSL_HAS_CONST_MKS
  add_constants(mks_array, const_module);
  add_constants(mks_array, mks_module);
#endif
#ifdef _PYGSL_GSL_HAS_CONST_CGS
  add_constants(cgs_array, cgs_module);
#endif

#ifdef _PYGSL_GSL_HAS_CONST_MKSA
  add_constants(mksa_array, const_module);
  add_constants(mksa_array, mksa_module);
#endif
#ifdef _PYGSL_GSL_HAS_CONST_CGSM
  add_constants(cgsm_array, cgsm_module);
#endif

  add_constants(num_array, num_module);
  add_constants(m_array  , math_module);


  PyModule_AddObject(const_module, "m",   math_module);
#ifdef _PYGSL_GSL_HAS_CONST_CGS
  PyModule_AddObject(const_module, "cgs", cgs_module);
#endif
#ifdef _PYGSL_GSL_HAS_CONST_MKS
  PyModule_AddObject(const_module, "mks", mks_module);
#endif
   
#ifdef _PYGSL_GSL_HAS_CONST_CGSM
  PyModule_AddObject(const_module, "cgsm", cgsm_module);
#endif
#ifdef _PYGSL_GSL_HAS_CONST_MKSA
  PyModule_AddObject(const_module, "mksa", mksa_module);
#endif

  PyModule_AddObject(const_module, "num", num_module);

  return GSL_SUCCESS;
}


#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.const",
        NULL,
        -1,
        constMethods,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif /* PyGSL_PY3K */

#ifdef __cplusplus
extern "C"
#endif


#ifdef PyGSL_PY3K
PyMODINIT_FUNC PyInit_const(void)
#define RETVAL const_module
#else /* PyGSL_PY3K */
DL_EXPORT(void) initconst(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
	int status;
	PyObject* const_module = NULL;

#ifdef PyGSL_PY3K
	const_module = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
	const_module = Py_InitModule("const", constMethods);
#endif /* PyGSL_PY3K */
	
	if(const_module == NULL)
		return RETVAL;

	status = _init_const_module(const_module); 
	return RETVAL;
}

