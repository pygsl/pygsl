/* 
 * Get a gsl_rng object from a PyGSL rng wrapper.
 */
#include <Python.h>
#include <gsl/gsl_rng.h>
gsl_rng *
PyGSL_gsl_rng_from_pyobject(PyObject * object);
