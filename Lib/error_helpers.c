#include <pygsl/error_helpers.h>
#include <pygsl/utils.h>
#include <gsl/gsl_errno.h>

PyObject * 
PyGSL_error_flag_to_pyint(long flag)
{
     PyObject * result = NULL;
     if(DEBUG > 2){
	  fprintf(stderr,"I got an Error of %ld\n", flag);
     }
     if(PyErr_Occurred())
	  return NULL;
     if(flag>0){
	  /* How can I end here without an Python error? */
	  gsl_error("Unknown Reason. It was not set by GSL.",  __FILE__,
		    __LINE__, flag);
	  return NULL;
     }
     result = PyInt_FromLong((long) flag);
     return result;
}
