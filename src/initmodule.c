/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/initmodule.c
 * $Id$
 */

#include <gsl/gsl_errno.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_ieee_utils.h>
#include <Python.h>

/*
 * sets the right exception, but does not return to python!
 */
void module_error_handler(const char *reason, /* name of function*/
			 const char *file, /*from CPP*/
			 int line,   /*from CPP*/
			 int gsl_error) /* real "reason" */
{
  const char* error_explanation;
  char error_text[255];
  PyObject* gsl_error_object;
  PyObject* gsl_error_module;
  PyObject* gsl_error_dict;

  error_explanation = gsl_strerror(gsl_error);
  if (error_explanation==NULL)
    snprintf(error_text,sizeof(error_text),
	     "unknown error %d in %s",
	     gsl_error,reason);
  else
    snprintf(error_text,sizeof(error_text),
	     "%s in %s",
	     error_explanation,reason);

  /* error handler for gsl routines, sets exception */

  gsl_error_module=PyImport_ImportModule("pygsl.errors");
  gsl_error_dict=PyModule_GetDict(gsl_error_module);
  gsl_error_object=PyDict_GetItemString(gsl_error_dict,"gsl_Error");

  PyErr_SetObject(gsl_error_object,
		  PyString_FromString(error_text));
  return;
}

static PyMethodDef initMethods[] = {
  {NULL,     NULL}        /* Sentinel */
};


DL_EXPORT(void) initinit(void)
{
  (void)Py_InitModule("pygsl.init", initMethods);
  /* error handler for python exceptions*/
  gsl_set_error_handler (&module_error_handler);
  /* setup gsl mode and ieee modes from environment variable GSL_IEEE_MODE */
  gsl_ieee_env_setup();
  /* setup default random generator from environment variables */
  gsl_rng_env_setup();

  return;
}
