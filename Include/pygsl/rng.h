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

static int _import_pygsl_rng(const char * filename, const char *func_name, const int lineno)
{
    PyObject *pygsl = NULL, *c_api = NULL, *md = NULL;
    unsigned long version;

    if(! (pygsl = PyImport_ImportModule("pygsl.rng")) ){
	fprintf(stderr, "FAILED %s:@%d %s import of pygsl.rng: failed to import module\n",  filename,  lineno, func_name);
	return -1;
    }
    if (!  (md = PyModule_GetDict(pygsl)) ){
	fprintf(stderr, "FAILED %s:@%d %s import of pygsl.rng: failed to get module dictionary\n",  filename,  lineno, func_name);
	return -1;
    }
    if (! (c_api = PyDict_GetItemString(md, "_PYGSL_RNG_API")) ){
	fprintf(stderr, "FAILED %s:@%d %s import of pygsl.rng: failed to get c_api object\n",  filename,  lineno, func_name);
	return -1;
    }
    if( ! PyCapsule_CheckExact(c_api) ) {
	fprintf(stderr, "FAILED %s:@%d %s import of pygsl.rng: c_api object is not a python capsule \n",  filename,  lineno, func_name);
	return -1;
    }

    PyGSL_API = (void **)PyCapsule_GetPointer(c_api, _pygsl_rng_api_cap_name);
    if(!PyGSL_API) {
	fprintf(stderr, "FAILED %s:@%d %s import of pygsl.rng: c_api capsule contained NULL pointer \n",  filename,  lineno, func_name);
	return -1;
    }
    return 0;
}

#define import_pygsl_rng1(ret) { \
if (_import_pygsl_rng(__FILE__, __FUNCTION__, __LINE__) < 0) { \
    PyErr_Print(); \
    PyErr_SetString( \
        PyExc_ImportError, \
        "pygsl.rng failed to import" \
    ); \
    return ret; \
  } \
}


#define import_pygsl_rng() import_pygsl_rng1(NULL)

__END_DECLS

#endif  /* PyGSL_RNG_H */
