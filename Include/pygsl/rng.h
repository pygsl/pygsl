#ifndef PyGSL_RNG_H
#define PyGSL_RNG_H 1

#include <Python.h>
#include <gsl/gsl_rng.h>
typedef struct {
  PyObject_HEAD
  gsl_rng * rng;
} PyGSL_rng;

#define PyGSLRng_Check(v) ((v)->ob_type == &PyGSL_rng_pytype)
#endif  /* PyGSL_RNG_H */
