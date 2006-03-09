#ifndef PyGSL_RNG_H
#define PyGSL_RNG_H 1

#include <pygsl/intern.h>
#include <gsl/gsl_rng.h>
typedef struct {
  PyObject_HEAD
  gsl_rng * rng;
} PyGSL_rng;



/* 
 * Get a gsl_rng object from a PyGSL rng wrapper.
 */
PyGSL_API_EXTERN gsl_rng *
PyGSL_gsl_rng_from_pyobject(PyObject * object);
#ifndef _PyGSL_API_MODULE
#define PyGSL_gsl_rng_from_pyobject \
(*(gsl_rng *  (*) (PyObject *)) PyGSL_API[PyGSL_gsl_rng_from_pyobject_NUM])
#endif /* _PyGSL_API_MODULE */

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





