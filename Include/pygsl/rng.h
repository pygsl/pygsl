#ifndef PyGSL_RNG_H
#define PyGSL_RNG_H 1

#include <Python.h>
#include <gsl/gsl_rng.h>
typedef struct {
  PyObject_HEAD
  gsl_rng * rng;
} PyGSL_rng;

#define PyGSL_API_UNIQUE_SYMBOL PyGSL_API

/*
 * This API import trick was copied from Numeric/arrayobject.h
 */
#if defined(PyGSL_API_UNIQUE_SYMBOL)
#define PyGSL_API PyGSL_API_UNIQUE_SYMBOL
#endif

/* C API address pointer */ 
#if defined(PyGSL_NO_IMPORT_API)
extern void **PyGSL_API;
#else
#if defined(PyGSL_API_UNIQUE_SYMBOL)
void **PyGSL_API = NULL;
#else
static void **PyGSL_API = NULL;
#endif
#endif



/* First entry is the RNG Object Type */
#define PyGSL_RNG_ObjectType_NUM 0
#define PyGSL_RNG_Check(op) \
   ((op)->ob_type == (PyTypeObject *)PyGSL_API[PyGSL_RNG_ObjectType_NUM])

#define import_pygsl_rng() \
{ \
   PyObject *pygsl = NULL, *c_api = NULL, *md = NULL; \
   if ( \
      (pygsl = PyImport_ImportModule("pygsl.rng"))         != NULL && \
      (md = PyModule_GetDict(pygsl))                       != NULL && \
      (c_api = PyDict_GetItemString(md, "_PYGSL_RNG_API")) != NULL && \
      (PyCObject_Check(c_api))                                        \
     ) { \
	 PyGSL_API = (void **)PyCObject_AsVoidPtr(c_api); \
   } else { \
        PyGSL_API = NULL; \
   } \
   /* fprintf(stderr, "PyGSL_API points to %p\n", (void *) PyGSL_API); */ \
}
#endif  /* PyGSL_RNG_H */





