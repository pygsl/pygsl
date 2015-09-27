#ifndef PyGSL_RNG_H
#define PyGSL_RNG_H 1
/*
 * Author: Pierre Schnizer
 *
 * $Id: 
 */
#include <pygsl/intern.h>
#include <gsl/gsl_rng.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif
__BEGIN_DECLS


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

#define PyGSL_RNG_Check(ob) \
   (Py_TYPE(ob) == (PyTypeObject *)PyGSL_API[PyGSL_RNG_ObjectType_NUM])

static const char _pygsl_rng_api_cap_name[] = "_pygsl_rng_api"; 
#define _PyGSL_RNG_API_CAP _pygsl_rng_api_cap_name

#define import_pygsl_rng() \
{ \
   PyObject *pygsl = NULL, *c_api = NULL, *md = NULL; \
   if ( \
      (pygsl = PyImport_ImportModule("pygsl.rng"))         != NULL && \
      (md = PyModule_GetDict(pygsl))                       != NULL && \
      (c_api = PyDict_GetItemString(md, "_PYGSL_RNG_API")) != NULL && \
      (PyCapsule_CheckExact(c_api))				      \
     ) { \
     PyGSL_API = (void **)PyCapsule_GetPointer(c_api,_PyGSL_RNG_API_CAP); \
   } else { \
        PyGSL_API = NULL; \
   } \
   /* fprintf(stderr, "PyGSL_API points to %p\n", (void *) PyGSL_API); */ \
}

__END_DECLS

#endif  /* PyGSL_RNG_H */





