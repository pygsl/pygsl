#include <pygsl/rng.h>

static gsl_rng *
PyGSL_gsl_rng_from_pyobject(PyObject * object)
{
     PyGSL_rng *rng = NULL;
     gsl_rng *random = NULL;

     FUNC_MESS("Begin GSL_RNG");
     assert(object);
     
     assert(PyGSL_API != NULL);

     /* Check that it is from the approbriate type ... */
     if(object == NULL){
	  pygsl_error("I expected a rng instance, but got a NULL pointer!", __FILE__, __LINE__, GSL_ESANITY);
     }
     if(!PyGSL_RNG_Check(object)){
	  pygsl_error("I expected a rng instance or an instance from "
		    "a derived class",
		    __FILE__, __LINE__, GSL_EFAULT);
	  return NULL;
     }
     rng = ((PyGSL_rng *) object);
     random = rng->rng;
     if(random == NULL){
	  pygsl_error("I expected a valid rng_pointer, but got a NULL pointer!", __FILE__, __LINE__, GSL_ESANITY);
	  return NULL;
     }
     FUNC_MESS("End GSL_RNG");
     
     return random;
}
