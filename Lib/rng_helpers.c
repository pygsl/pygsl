#include <pygsl/utils.h>
#include <pygsl/rng_helpers.h>

gsl_rng *
PyGSL_gsl_rng_from_pyobject(PyObject * object)
{
     PyObject *tmp = NULL;
     gsl_rng *random = NULL;

     FUNC_MESS("Begin GSL_RNG");
     assert(object);
     
     /* Check that it is from the approbriate type ... */
     /* rng is not a type yet. Can not check for that yet .... */
     /*
     if(!PyGSL_RngCheck(object)){
	  gsl_error("I expected a rng instance or an instance from "
		    "a derived class",
		    __FILE__, __LINE__, GSL_EFAULT);
	  return NULL;
     }
     */
     tmp = PyObject_GetAttrString(object, "_rng");
     if(tmp  == NULL)
	  return NULL;

     if(!PyCObject_Check(tmp)){
	  gsl_error("I expected a PythonCObject as attribute '_rng.'",
		    __FILE__, __LINE__, GSL_EFAULT);
	  return NULL;
     }

     random =(gsl_rng*) PyCObject_AsVoidPtr(tmp);
     if(random == NULL)
	  return NULL;
     FUNC_MESS("End GSL_RNG");
     
     return random;
}
