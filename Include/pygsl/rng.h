#ifndef PyGSL_RNG_H
#define PyGSL_RNG_H 1

#include <Python.h>
#include <gsl/gsl_rng.h>
typedef struct {
  PyObject_HEAD
  gsl_rng * rng;
} PyGSL_rng;

/*
 * This API import trick was copied from Numeric/arrayobject.h
 */

/* First entry is the RNG Object Type */
#define PyGSL_RNG_ObjectType_NUM 0
#define PyGSL_RNG_Check(op) \
   ((op)->ob_type == (PyTypeObject *)PyGSL_API[PyGSL_RNG_ObjectType_NUM])

#if defined(PyGSL_API_UNIQUE_SYMBOL)
#define PyGSL_API PyGSL_API_UNIQUE_SYMBOL
#endif

/* C API address pointer */ 
#if defined(PyGSL_NO_IMPORT_API)
extern void **PyGSL_API;
#else
#if defined(PY_ARRAY_UNIQUE_SYMBOL)
void **PyGSL_API;
#else
static void **PyGSL_API;
#endif
#endif

#define import_pygsl_rng() \
{ \
  PyObject *pygsl = PyImport_ImportModule("pygsl.rng"); \
  if (pygsl != NULL) { \
    PyObject *module_dict = PyModule_GetDict(pygsl); \
    PyObject *c_api_object = PyDict_GetItemString(module_dict, "_PYGSL_RNG_API"); \
    if (PyCObject_Check(c_api_object)) { \
      PyGSL_API = (void **)PyCObject_AsVoidPtr(c_api_object); \
    } \
  } \
}
#endif  /* PyGSL_RNG_H */





