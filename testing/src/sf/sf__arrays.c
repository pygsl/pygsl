#include <pygsl/utils.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_nan.h>

#ifndef IMPORTALL
static PyObject *module=NULL;
#endif

typedef  int (array_p_evaluator_iid_ad)(int nmin, int nmax, double x, double * result_array);
static PyObject*
PyGSL_sf_array_evaluator_legendre_iid_ad(PyObject *self, PyObject *args, 
					 array_p_evaluator_iid_ad * eval)
{
     PyArrayObject *result = NULL;
     int lmax=0, m=0, dimension = 0, ret;
     double x=0, *data=NULL;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "iid", &lmax, &m, &x)){
	  return NULL;
     }
     if(m < 0){
	  PyErr_SetString(PyExc_ValueError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     if(lmax < m){
	  PyErr_SetString(PyExc_ValueError, 
			  "Nmax must be bigger or equal to nmin!");
     }
     dimension = gsl_sf_legendre_array_size(lmax, m);
     result = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(lmax, m, x, data);
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;

     FUNC_MESS_END();
     return (PyObject *) result;

 fail:
     Py_XDECREF(result);
     return NULL;
}

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
     result = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
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
     result = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(nmax, x, data);
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;

     FUNC_MESS_END();
     return (PyObject *) result;

 fail:
     Py_XDECREF(result);
     return NULL;
}

typedef  int (array_p_evaluator_idd_ad)(int nmax, double x1, double x2, double * result_array);
static PyObject*
PyGSL_sf_array_evaluator_idd_ad(PyObject *self, PyObject *args, array_p_evaluator_idd_ad * eval)
{
     PyArrayObject *result = NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, x1=0, *data=NULL;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "idd", &nmax, &x, &x1)){
	  return NULL;
     }
     if(nmin < 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(nmax, x, x1, data);
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;

     FUNC_MESS_END();
     return (PyObject *) result;

 fail:
     Py_XDECREF(result);
     return NULL;
}
typedef  int (array_p_evaluator_did_ad)( double x1, int nmax, double x2, double * result_array);
static PyObject*
PyGSL_sf_array_evaluator_did_ad(PyObject *self, PyObject *args, array_p_evaluator_did_ad * eval)
{
     PyArrayObject *result = NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, x1=0, *data=NULL;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "did",&x, &nmax, &x1)){
	  return NULL;
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(nmax, x, x1, data);
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;

     FUNC_MESS_END();
     return (PyObject *) result;

 fail:
     Py_XDECREF(result);
     return NULL;
}

typedef int (array_p_evaluator_didd_add)(double , int , double , double , double * array, double*);
static PyObject*
PyGSL_sf_array_evaluator_didd_add(PyObject *self, PyObject *args, array_p_evaluator_didd_add * eval)
{
     PyArrayObject *result = NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, x1=0, *data=NULL, l_min, exponent;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "didd", &l_min, &nmax, &x, &x1)){
	  return NULL;
     }
     if(nmin < 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result == NULL)
	  return NULL;

     data = (double *) result->data;
     ret =  eval(l_min, nmax, x, x1, data, &exponent);
     FUNC_MESS_END();
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;
     
     return Py_BuildValue("Od",result,exponent);     
 fail:
     Py_XDECREF(result);
     return NULL;
}

typedef int (array_p_evaluator_didd_addadd)(double , int , double , double , double * array1, double*, double *array2, double*);
static PyObject*
PyGSL_sf_array_evaluator_didd_addadd(PyObject *self, PyObject *args, array_p_evaluator_didd_addadd * eval)
{
     PyArrayObject *result1 = NULL,*result2 = NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, x1=0, *data1=NULL, *data2=NULL, l_min, exponent1,exponent2;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "didd", &l_min, &nmax, &x, &x1)){
	  return NULL;
     }
     if(nmin < 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result1 = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result1 == NULL)
	  goto fail;
     result2 = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result2 == NULL)
	  goto fail;

     data1 = (double *) result1->data;
     data2 = (double *) result2->data;

     ret =  eval(l_min, nmax, x, x1, data1, &exponent1, data2, &exponent2);
     FUNC_MESS_END();
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;
     
     return Py_BuildValue("OdOd",result1,exponent1,result2,exponent2);     
 fail:
     Py_XDECREF(result1);
     Py_XDECREF(result2);
     return NULL;
}


typedef int (array_p_evaluator_didd_adadadaddd)(double , int , double , double , double * a1, double * a2, double * a3, double * a4, 
						double*, double*);
static PyObject*
PyGSL_sf_array_evaluator_didd_adadadaddd(PyObject *self, PyObject *args, array_p_evaluator_didd_adadadaddd * eval)
{
     PyArrayObject *result1 = NULL,*result2 = NULL, *result3=NULL,*result4=NULL;
     int nmin=0, nmax=0, dimension = 0, ret;
     double x=0, x1=0, l_min, exponent1, exponent2;


     FUNC_MESS_BEGIN();
     if (!PyArg_ParseTuple(args, "didd", &l_min, &nmax, &x, &x1)){
	  return NULL;
     }
     if(nmin < 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "Nmin must be bigger than 0!");
	  return NULL;
     }
     dimension = nmax - nmin + 1; /* Goes form nmin to nmax, both included */
     result1 = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result1 == NULL)
	  goto fail;
     result2 = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result2 == NULL)
	  goto fail;
     result3 = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result3 == NULL)
	  goto fail;
     result4 = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
     if(result4 == NULL)
	  goto fail;


     ret =  eval(l_min, nmax, x, x1, (double *) result1->data, (double *)result2->data,
		 (double *) result3->data, (double *)result4->data, &exponent1, &exponent2);
     FUNC_MESS_END();
     if(PyGSL_ERROR_FLAG(ret) != GSL_SUCCESS)
	  goto fail;
     
     return Py_BuildValue("OOOOdd",result1,result2,result3,result4,exponent1, exponent2);
 fail:
     Py_XDECREF(result1);
     Py_XDECREF(result2);
     Py_XDECREF(result3);
     Py_XDECREF(result4);
     return NULL;
}

#define SF_ARRAY(name, function)                                           \
static PyObject* sf_ ## name      (PyObject *self, PyObject *args)         \
{                                                                          \
     PyObject * tmp;                                                       \
     FUNC_MESS_BEGIN();                                                    \
     tmp =  PyGSL_sf_array_evaluator_ ## function (self, args, gsl_sf_ ## name); \
     if (tmp == NULL){                                                     \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__,  __LINE__);  \
     }                                                                     \
     FUNC_MESS_END();                                                      \
     return tmp;                                                           \
}

SF_ARRAY(bessel_Jn_array, iid_ad);
SF_ARRAY(bessel_Yn_array, iid_ad);
SF_ARRAY(bessel_In_array, iid_ad);
SF_ARRAY(bessel_Kn_array, iid_ad);
SF_ARRAY(bessel_Kn_scaled_array, iid_ad);
SF_ARRAY(bessel_jl_array, id_ad);
SF_ARRAY(bessel_jl_steed_array, id_ad);
SF_ARRAY(bessel_yl_array, id_ad);
SF_ARRAY(bessel_il_scaled_array, id_ad);
SF_ARRAY(bessel_kl_scaled_array, id_ad);
SF_ARRAY(gegenpoly_array, idd_ad);
SF_ARRAY(legendre_H3d_array, idd_ad);
SF_ARRAY(coulomb_wave_F_array, didd_add);
SF_ARRAY(coulomb_wave_sphF_array, didd_add);
SF_ARRAY(coulomb_wave_FG_array, didd_addadd);
SF_ARRAY(coulomb_wave_FGp_array, didd_adadadaddd);
SF_ARRAY(coulomb_CL_array, did_ad);
SF_ARRAY(legendre_Pl_array, id_ad);
SF_ARRAY(legendre_Plm_array, legendre_iid_ad);
SF_ARRAY(legendre_sphPlm_array, legendre_iid_ad);


static PyMethodDef sf_array_functions[] = {
     {"bessel_Jn_array",         (PyCFunction) sf_bessel_Jn_array,         METH_VARARGS, NULL},
     {"bessel_Yn_array",         (PyCFunction) sf_bessel_Yn_array,         METH_VARARGS, NULL},
     {"bessel_In_array",         (PyCFunction) sf_bessel_In_array,         METH_VARARGS, NULL},
     {"bessel_Kn_array",         (PyCFunction) sf_bessel_Kn_array,         METH_VARARGS, NULL},
     {"bessel_Kn_scaled_array",  (PyCFunction) sf_bessel_Kn_scaled_array,  METH_VARARGS, NULL},
     {"bessel_jl_array",         (PyCFunction) sf_bessel_jl_array,         METH_VARARGS, NULL},
     {"bessel_jl_steed_array",   (PyCFunction) sf_bessel_jl_steed_array,   METH_VARARGS, NULL},
     {"bessel_yl_array",         (PyCFunction) sf_bessel_yl_array,         METH_VARARGS, NULL},
     {"bessel_il_scaled_array",  (PyCFunction) sf_bessel_il_scaled_array,  METH_VARARGS, NULL},
     {"bessel_kl_scaled_array",  (PyCFunction) sf_bessel_kl_scaled_array,  METH_VARARGS, NULL},
     {"gegenpoly_array",         (PyCFunction) sf_gegenpoly_array,         METH_VARARGS, NULL},
     {"legendre_H3d_array",      (PyCFunction) sf_legendre_H3d_array,      METH_VARARGS, NULL},
     {"coulomb_wave_F_array",    (PyCFunction) sf_coulomb_wave_F_array,    METH_VARARGS, NULL},
     {"coulomb_wave_sphF_array", (PyCFunction) sf_coulomb_wave_sphF_array, METH_VARARGS, NULL},
     {"coulomb_wave_FG_array",   (PyCFunction) sf_coulomb_wave_FG_array,   METH_VARARGS, NULL},
     {"coulomb_wave_FGp_array",  (PyCFunction) sf_coulomb_wave_FGp_array,  METH_VARARGS, NULL},
     {"coulomb_CL_array",        (PyCFunction) sf_coulomb_CL_array,        METH_VARARGS, NULL},
     {"legendre_Pl_array",       (PyCFunction) sf_legendre_Pl_array,       METH_VARARGS, NULL},
     {"legendre_Plm_array",      (PyCFunction) sf_legendre_Plm_array,      METH_VARARGS, NULL},
     {"legendre_sphPlm_array",   (PyCFunction) sf_legendre_sphPlm_array,   METH_VARARGS, NULL},
     {NULL, NULL, 0}
};

#ifndef IMPORTALL

DL_EXPORT(void) initsfarray(void)
{
     module = Py_InitModule("sfarray", sf_array_functions);
     import_array();
       init_pygsl();
       
}
#endif
