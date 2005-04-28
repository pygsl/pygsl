#include <Python.h>
/*
  #include <Numeric/arrayobject.h>
*/
#include <gsl/gsl_sf.h>
#include <gsl/gsl_nan.h>
#include <pygsl/utils.h>
#include <pygsl/block_helpers.h>

typedef  int (array_p_evaluator_iid_ad)(int nmin, int nmax, double x, double * result_array);

static PyObject*
PyGSL_sf_array_evaluator_iid_ad(PyObject *self, PyObject *args, 
				array_p_evaluator_iid_ad * eval)
{
     PyArrayObject *result = NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, *data=NULL;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "iid", &nmin, &nmax, &x)){
	  return NULL;
     }
     if(nmin < 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     if(nmax < nmin){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmax must be bigger or equal to nmin!");
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(nmin, nmax, x, data);

     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;

     FUNC_MESS_END();
     return (PyObject *) result;

 fail:
     Py_XDECREF(result);
     return NULL;
}

typedef  int (array_p_evaluator_id_ad)(int nmax, double x, double * result_array);

static PyObject*
PyGSL_sf_array_evaluator_id_ad(PyObject *self, PyObject *args, array_p_evaluator_id_ad * eval)
{
     PyArrayObject *result = NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, *data=NULL;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "id", &nmax, &x)){
	  return NULL;
     }
     if(nmin < 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(nmax, x, data);
     FUNC_MESS_END();
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;

     return (PyObject *) result;

 fail:
     Py_XDECREF(result);
     return NULL;

}
