/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/initmodule.c
 * $Id$
 *
 * Changes: 
 *     7. October 2003:
 *     Removed the error handler from this file. It is now in 
 *     Lib/error_helpers.c Each module must call init_pygsl()
 *     in its init routine. This is necessary to support platforms
 *     where the gsl library is statically linked to the various 
 *     modules.    
 */

#include <gsl/gsl_rng.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_version.h>
#include <Python.h>
#include <pygsl/error_helpers.h>

static PyMethodDef initMethods[] = {
  {NULL,     NULL}        /* Sentinel */
};


DL_EXPORT(void) initinit(void)
{
  PyObject *m = NULL, *d = NULL, *version=NULL;

  m = Py_InitModule("pygsl.init", initMethods);
  init_pygsl();

  if(m == NULL){
       fprintf(stderr, "I could not init pygsl.init!");
       return;
  }

  d = PyModule_GetDict(m);
  if(d == NULL){
       fprintf(stderr, "I could not get the module dict for  pygsl.init!");
       return;
  }

  version = PyString_FromString(GSL_VERSION);
  if(version == NULL){
       fprintf(stderr, "I could not create the version string for pygsl.init!");
       return;
  }
  if(PyDict_SetItemString(d, "compiled_gsl_version", version) != 0){
       fprintf(stderr, "I could not add the compile version string to the module dict of pygsl.init!");
       return;
  }

  version = PyString_FromString(gsl_version);
  if(version == NULL){
       fprintf(stderr, "I could not create the version string for pygsl.init!");
       return;
  }
  if(PyDict_SetItemString(d, "run_gsl_version", version) != 0){
       fprintf(stderr, "I could not add the run version string to the module dict of pygsl.init!");
       return;
  }

  /* setup gsl mode and ieee modes from environment variable GSL_IEEE_MODE */
  gsl_ieee_env_setup();
  /* setup default random generator from environment variables */
  gsl_rng_env_setup();
  
  return;
}
