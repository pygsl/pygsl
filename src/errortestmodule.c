/*
 *
 * Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 * Date   : 5. October 2003
 * Only used to test the error handling of pygsl.
 */
#include <Python.h>
#include <gsl/gsl_errno.h>
#include <pygsl/error_helpers.h>

static char trigger_doc [] = "Calls gsl_error with the passed error number";
static PyObject *module;

static PyObject*
trigger(PyObject *self, PyObject *args)
{
     int gsl_errno = GSL_SUCCESS;
     if (0 == PyArg_ParseTuple(args, "i", &gsl_errno)){
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__ - 1);
	  return NULL;
     }

     gsl_error ("Just a test to see what pygsl is doing!",
		__FILE__, __LINE__, gsl_errno);
     return NULL;
}
static PyMethodDef errortestMethods[] = {
     /*densities*/
     {"trigger", trigger, METH_VARARGS, trigger_doc},
     {NULL, NULL, 0, NULL}
};

#define ADD_ERRNO(ERRNO, ERRNOSTR)                     \
   (item = PyInt_FromLong((ERRNO))) ? ((PyDict_SetItemString(dict, ERRNOSTR, item) != 0) ? 1 : 0) : 0
   


DL_EXPORT(void) initerrortest(void)
{
     PyObject *dict=NULL, *item=NULL, *m=NULL;
     
     m = Py_InitModule("errortest", errortestMethods);
     assert(m);
     module = m;

     init_pygsl();

     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     ADD_ERRNO(GSL_FAILURE , "GSL_FAILURE" );
     ADD_ERRNO(GSL_CONTINUE, "GSL_CONTINUE");
     ADD_ERRNO(GSL_EDOM    , "GSL_EDOM"    );
     ADD_ERRNO(GSL_ERANGE  , "GSL_ERANGE"  );
     ADD_ERRNO(GSL_EFAULT  , "GSL_EFAULT"  );
     ADD_ERRNO(GSL_EINVAL  , "GSL_EINVAL"  );
     ADD_ERRNO(GSL_EFAILED , "GSL_EFAILED" );
     ADD_ERRNO(GSL_EFACTOR , "GSL_EFACTOR" );
     ADD_ERRNO(GSL_ESANITY , "GSL_ESANITY" );
     ADD_ERRNO(GSL_ENOMEM  , "GSL_ENOMEM"  );
     ADD_ERRNO(GSL_EBADFUNC, "GSL_EBADFUNC");
     ADD_ERRNO(GSL_ERUNAWAY, "GSL_ERUNAWAY");
     ADD_ERRNO(GSL_EMAXITER, "GSL_EMAXITER");
     ADD_ERRNO(GSL_EZERODIV, "GSL_EZERODIV");
     ADD_ERRNO(GSL_EBADTOL , "GSL_EBADTOL" );
     ADD_ERRNO(GSL_ETOL    , "GSL_ETOL"    );
     ADD_ERRNO(GSL_EUNDRFLW, "GSL_EUNDRFLW");
     ADD_ERRNO(GSL_EOVRFLW , "GSL_EOVRFLW" );
     ADD_ERRNO(GSL_ELOSS   , "GSL_ELOSS"   );
     ADD_ERRNO(GSL_EROUND  , "GSL_EROUND"  );
     ADD_ERRNO(GSL_EBADLEN , "GSL_EBADLEN" );
     ADD_ERRNO(GSL_ENOTSQR , "GSL_ENOTSQR" );
     ADD_ERRNO(GSL_ESING   , "GSL_ESING"   );
     ADD_ERRNO(GSL_EDIVERGE, "GSL_EDIVERGE");
     ADD_ERRNO(GSL_EUNSUP  , "GSL_EUNSUP"  );
     ADD_ERRNO(GSL_EUNIMPL , "GSL_EUNIMPL" );
     ADD_ERRNO(GSL_ECACHE  , "GSL_ECACHE"  );
     ADD_ERRNO(GSL_ETABLE  , "GSL_ETABLE"  );
     ADD_ERRNO(GSL_ENOPROG , "GSL_ENOPROG" );
     ADD_ERRNO(GSL_ENOPROGJ, "GSL_ENOPROGJ");
     ADD_ERRNO(GSL_ETOLF   , "GSL_ETOLF"   );
     ADD_ERRNO(GSL_ETOLX   , "GSL_ETOLX"   );
     ADD_ERRNO(GSL_ETOLG   , "GSL_ETOLG"   );
     ADD_ERRNO(GSL_EOF     , "GSL_EOF"     );
     ADD_ERRNO(PyGSL_ESTRIDE, "PyGSL_ESTRIDE");
     


     return;
 fail:
     fprintf(stderr, "Initialisation of module errortest failed!\n");
     return;
}

