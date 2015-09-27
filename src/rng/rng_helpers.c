#include <pygsl/intern.h>
#include <pygsl/general_helpers.h>
#include <pygsl/block_helpers.h>
#define PyGSL_NO_IMPORT_API 1
#include <pygsl/rng_helpers.h>
#include <pygsl/rng.h>
#include <pygsl/utils.h>

/* 
 * The default macros defined by the setup script are not used when building 
 * the static library. I assume that you have numeric installed. It will not 
 * work otherwise anyway.
 */
#ifndef NUMERIC
#define NUMERIC 1
#else 
#if NUMERIC <= 0
#undef NUMERIC
#define NUMERIC 1
#endif
#endif 

/*
 * Numeric 21.0 does not include PyArray_UINT. Until Numerical 23.0 is 
 * more spread I will use PyArray_Long instead. The following switch allows 
 * to choose one over the other.
 */

#ifndef USE_PyArray_UINT
#endif
#if NUMERIC > 0
#define RNG_EVALUATOR                                                        \
{									     \
     int i;                                                                  \
     DATA_TYPE * data;                                                       \
     PyArrayObject *a_array;						     \
                                                                             \
     if(dimension <= 0){                                                     \
	  PyErr_SetString(PyExc_ValueError,                                  \
			  "The sample number must be positive!");            \
	  goto fail;                                                         \
     }                                                                       \
     if(dimension == 1){                                                     \
        return TOPYOBJECT(evaluator(rng->rng RNG_ARGUMENTS));                \
     }                                                                       \
                                                                             \
     a_array = (PyArrayObject *) PyGSL_New_Array(1, &dimension, ARRAY_TYPE); \
     									     \
     if(NULL == a_array){						     \
	FUNC_MESS("FAIL"); return NULL;					     \
     }									     \
     data = (DATA_TYPE *) PyArray_DATA(a_array);  			     \
     for (i=0; i<dimension;i++){					     \
	  data[i] = evaluator(rng->rng RNG_ARGUMENTS);			     \
     }									     \
     FUNC_MESS_END();							     \
     return (PyObject *) a_array;					     \
}									     
/* All probability density functions return double */
#define PDF_EVALUATOR                                                        \
{									     \
     double *data_out; 						             \
     DATA_TYPE x;                                                            \
     int i;						                     \
     if(!PyGSL_array_check(tmp)){	  			             \
	  if(PyGSL_CONVERTER(tmp, &x, NULL) != GSL_SUCCESS)	             \
	       goto fail;						     \
	  return PyFloat_FromDouble(evaluator(x  RNG_ARGUMENTS));            \
     }									     \
     array_in = PyGSL_vector_check(tmp, -1,                                  \
PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS |PyGSL_INPUT_ARRAY, ARRAY_TYPE_IN, 1, 1), \
				   NULL, NULL);\
     if(array_in == NULL)						     \
	  goto fail;							     \
     dimension = PyArray_DIM(array_in, 0);				     \
     array_out = (PyArrayObject *) PyGSL_New_Array(1, &dimension,            \
						    NPY_DOUBLE);             \
									     \
									     \
     data_out = (double *) PyArray_DATA(array_out);			     \
									     \
     for(i=0; i<dimension; i++){					     \
       x = *((double *) (PyArray_GETPTR1(array_in, i)));		\
	  data_out[i] = evaluator(x RNG_ARGUMENTS);  		             \
     }									     \
									     \
									     \
     Py_DECREF(array_in); array_in = NULL;				     \
     FUNC_MESS_END();                                                        \
     return (PyObject *) array_out;                                          \
}
#else /* Numeric */
#define RNG_EVALUATOR                                                        \
{									     \
     PyObject *list;							     \
     int i;                                                                  \
                                                                             \
     if(dimension <= 0){                                                     \
	  PyErr_SetString(PyExc_ValueError,                                  \
			  "The sample number must be positive!");            \
	  goto fail;                                                         \
     }                                                                       \
     if(dimension == 1){                                                     \
        return TOPYOBJECT(evaluator(rng->rng RNG_ARGUMENTS));                \
     }                                                                       \
                                                                             \
     list = PyList_New(dimension);					     \
     if(!list){								     \
	  FUNC_MESS("FAIL");						     \
	  return NULL;							     \
     }                                                                       \
     for (i=0; i<dimension;i++){					     \
	  PyObject *tmp;						     \
	  tmp = TOPYOBJECT(evaluator(rng->rng RNG_ARGUMENTS));		     \
	  if(!tmp){							     \
	       Py_DECREF(list);						     \
	       return NULL;						     \
	  }								     \
	  PyList_SET_ITEM(list, i, tmp);				     \
     }									     \
     FUNC_MESS_END();                                                        \
     return list;     							     \
}
#define PDF_EVALUATOR                                                        \
{									     \
     DATA_TYPE x; 						             \
     int i;						                     \
     if(!PyGSL_array_check(tmp)){	  			             \
	  if(PyGSL_CONVERTER(tmp, &x, NULL) != GSL_SUCCESS)	             \
	       goto fail;						     \
	  return TOPYOBJECT(evaluator(x RNGARGUMENTS));	                     \
     }									     \
}									   
#endif /* Numeric */

PyObject *
PyGSL_rng_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *))
{
     PyGSL_array_index_t dimension=1;
     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "|i", &dimension)){
	  return NULL;
     }

#define RNG_ARGUMENTS
#define DATA_TYPE     double
#define ARRAY_TYPE     NPY_DOUBLE
#define ARRAY_TYPE_IN  NPY_DOUBLE
#define ARRAY_TYPE_OUT NPY_DOUBLE
#define TOPYOBJECT     PyFloat_FromDouble
#define PyGSL_CONVERTER  PyGSL_PYFLOAT_TO_DOUBLE

     RNG_EVALUATOR
  fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

PyObject *
PyGSL_pdf_to_double(PyObject *self, PyObject *args, double (*evaluator)(double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     PyGSL_array_index_t dimension=1;


     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "O", &tmp)){
	  return NULL;
     }

     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

PyObject *
PyGSL_rng_d_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, double))
{
     PyGSL_array_index_t dimension=1;
     double d;
     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "d|i", &d, &dimension)){
	  return NULL;
     }
#undef  RNG_ARGUMENTS
#define RNG_ARGUMENTS ,d 


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

PyObject *
PyGSL_pdf_d_to_double(PyObject *self, PyObject *args, double (*evaluator)(double, double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     double d;
     PyGSL_array_index_t dimension=1;


     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "Od", &tmp, &d)){
	  return NULL;
     }

     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

PyObject *
PyGSL_rng_dd_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, double, double))
{
     PyGSL_array_index_t dimension=1;
     double d1, d2;
     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "dd|i", &d1, &d2, &dimension)){
	  return NULL;
     }
#undef  RNG_ARGUMENTS
#define RNG_ARGUMENTS , d1, d2


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     return NULL;
}

PyObject *
PyGSL_pdf_dd_to_double(PyObject *self, PyObject *args, double (*evaluator)(double, double, double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     double d1, d2;
     PyGSL_array_index_t dimension=1;


     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "Odd", &tmp, &d1, &d2)){
	  return NULL;
     }

     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

PyObject *
PyGSL_rng_ddd_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, double, double, double))
{
     PyGSL_array_index_t dimension=1;
     double d1, d2, d3;
     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "ddd|i", &d1, &d2, &d3, &dimension)){
	  return NULL;
     }
#undef  RNG_ARGUMENTS
#define RNG_ARGUMENTS , d1, d2, d3


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

PyObject *
PyGSL_pdf_ddd_to_double(PyObject *self, PyObject *args, double (*evaluator)(double, double, double, double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     double d1, d2, d3;
     PyGSL_array_index_t dimension=1;




     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "Oddd", &tmp, &d1, &d2, &d3)){
	  return NULL;
     }

     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}


#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT


PyObject *
PyGSL_rng_ui_to_double(PyGSL_rng *rng, PyObject *args, double (*evaluator)(const gsl_rng *, unsigned int))
{
     PyObject *tmp, *limit_o = NULL;
     unsigned long int limit;
     PyGSL_array_index_t dimension=1;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "O|i", &tmp, &dimension)){
	  return NULL;
     }
     if(PyGSL_PYLONG_TO_ULONG(tmp, &limit, NULL) != GSL_SUCCESS)
	  goto fail;
#define RNG_ARGUMENTS ,limit
#define DATA_TYPE     double
#define ARRAY_TYPE    NPY_DOUBLE
#define TOPYOBJECT    PyFloat_FromDouble


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(limit_o);
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  ARRAY_TYPE
#undef  PyGSL_CONVERTER  
#undef  DATA_TYPE
#undef  ARRAY_TYPE_IN
#undef  ARRAY_TYPE_OUT

PyObject *
PyGSL_pdf_ui_to_double(PyObject *self, PyObject *args, double (*evaluator)(unsigned int, double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     double d;
     PyGSL_array_index_t dimension=1;


     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "Od", &tmp, &d)){
	  return NULL;
     }


#define RNG_ARGUMENTS    ,d
#define ARRAY_TYPE       NPY_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define ARRAY_TYPE_IN    NPY_LONG
#define ARRAY_TYPE_OUT   NPY_DOUBLE
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT


PyObject *
PyGSL_rng_d_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, double))
{
     double d;
     PyGSL_array_index_t dimension=1;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "d|i", &d, &dimension)){
	  return NULL;
     }
#define RNG_ARGUMENTS ,d
#define DATA_TYPE     long
#define ARRAY_TYPE    NPY_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT


PyObject *
PyGSL_pdf_d_to_ui(PyObject *self, PyObject *args, double (*evaluator)(unsigned int, double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     double d;
     PyGSL_array_index_t dimension=1;


     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "Od", &tmp, &d)){
	  return NULL;
     }


#define RNG_ARGUMENTS    ,d
#define ARRAY_TYPE       NPY_INT
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define ARRAY_TYPE_IN    NPY_LONG
#define ARRAY_TYPE_OUT   NPY_DOUBLE
#define TOPYOBJECT       PyFloat_FromDouble
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT

PyObject *
PyGSL_rng_dui_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, double, unsigned int))
{
     PyObject *tmp;
     double d;
     PyGSL_array_index_t dimension=1;
     unsigned long int llimit;
     unsigned int limit;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "dO|i", &d, &tmp, &dimension)){
	  return NULL;
     }
     if(PyGSL_PYLONG_TO_ULONG(tmp, &llimit, NULL) != GSL_SUCCESS)
	  goto fail;
     limit = llimit;

#define RNG_ARGUMENTS ,d ,limit
#define DATA_TYPE     long
#define ARRAY_TYPE    NPY_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT


PyObject *
PyGSL_pdf_dui_to_ui(PyObject *self, PyObject *args, double (*evaluator)(unsigned int, double, unsigned int))
{

     PyObject *tmp, *tmp1;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     PyGSL_array_index_t dimension=1;
     unsigned int n;
     double p;
	  

     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "OdO", &tmp, &p, &tmp1)){
	  return NULL;
     }
     if(PyGSL_PYLONG_TO_UINT(tmp1, &n, NULL) != GSL_SUCCESS){
	  goto fail;
     }

#undef PyGSL_CONVERTER
#define RNG_ARGUMENTS    ,p ,n
#define ARRAY_TYPE       NPY_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define TOPYOBJECT       PyFloat_FromDouble
#define ARRAY_TYPE_IN    NPY_LONG
#define ARRAY_TYPE_OUT   NPY_DOUBLE
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT


PyObject *
PyGSL_rng_dd_to_ui(PyGSL_rng *rng, PyObject *args, unsigned int  (*evaluator)(const gsl_rng *, double, double))
{

     double d1, d2;
     PyGSL_array_index_t dimension=1;


     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "dd|i", &d1, &d2, &dimension)){
	  return NULL;
     }

#define RNG_ARGUMENTS ,d1 , d2
#define DATA_TYPE     long
#define ARRAY_TYPE    NPY_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT

PyObject *
PyGSL_pdf_dd_to_ui(PyObject *self, PyObject *args, double (*evaluator)(const unsigned int, const double, const double))
{

     PyObject *tmp;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     PyGSL_array_index_t dimension=1;
     double d1, d2;
	  

     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "Odd", &tmp, &d1, &d2)){
	  return NULL;
     }

#define RNG_ARGUMENTS    ,d1 ,d2
#define ARRAY_TYPE       NPY_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define TOPYOBJECT       PyFloat_FromDouble
#define ARRAY_TYPE_IN    NPY_LONG
#define ARRAY_TYPE_OUT   NPY_DOUBLE
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT

PyObject *
PyGSL_rng_uiuiui_to_ui(PyGSL_rng *rng, PyObject *args, 
		       unsigned int  (*evaluator)(const gsl_rng *, unsigned int, unsigned int, unsigned int))
{
     PyObject *tmp1, *tmp2, *tmp3;
     PyGSL_array_index_t dimension=1;
     unsigned int u1, u2, u3;
     unsigned long int lu1, lu2, lu3;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "OOO|i", &tmp1, &tmp2, &tmp3, &dimension)){
	  return NULL;
     }


     if(PyGSL_PYLONG_TO_ULONG(tmp1, &lu1, NULL) != GSL_SUCCESS) goto fail;
     if(PyGSL_PYLONG_TO_ULONG(tmp2, &lu2, NULL) != GSL_SUCCESS) goto fail;
     if(PyGSL_PYLONG_TO_ULONG(tmp3, &lu3, NULL) != GSL_SUCCESS) goto fail;
     u1 = lu1;
     u2 = lu2;
     u3 = lu3;

#define RNG_ARGUMENTS ,u1, u2, u3
#define DATA_TYPE     long
#define ARRAY_TYPE    NPY_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT

PyObject *
PyGSL_pdf_uiuiui_to_ui(PyObject *self, PyObject *args, 
		       double (*evaluator)(const unsigned int, const unsigned int, const unsigned int, unsigned int))
{

     PyObject *tmp, *tmp1, *tmp2, *tmp3;
     PyArrayObject *array_in = NULL, *array_out = NULL;
     PyGSL_array_index_t dimension=1;
     unsigned int u1, u2, u3;
	  

     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "OOOO", &tmp, &tmp1, &tmp2, &tmp3)){
	  return NULL;
     }
     if(PyGSL_PYLONG_TO_UINT(tmp1, &u1, NULL) != GSL_SUCCESS)
	  goto fail;
     if(PyGSL_PYLONG_TO_UINT(tmp2, &u2, NULL) != GSL_SUCCESS)
	  goto fail;
     if(PyGSL_PYLONG_TO_UINT(tmp3, &u3, NULL) != GSL_SUCCESS)
	  goto fail;

#define RNG_ARGUMENTS    ,u1 ,u2 ,u3
#define ARRAY_TYPE       NPY_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define TOPYOBJECT       PyFloat_FromDouble
#define ARRAY_TYPE_IN    NPY_LONG
#define ARRAY_TYPE_OUT   NPY_DOUBLE
     PDF_EVALUATOR

 fail:     
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(array_in);
     Py_XDECREF(array_out);
     return NULL;
}

#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT


PyObject *
PyGSL_rng_ddd_to_dd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double, double, double, double *, double *))
{
     PyGSL_array_index_t dimension=1, dims[2], i;
     PyArrayObject *a_array;
     double *data, d1, d2, d3;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "ddd|i", &d1, &d2, &d3, &dimension)){
	  return NULL;
     }
     dims[0] = dimension;
     dims[1] = 2;
     if(dimension <= 0){                                                    
	  PyErr_SetString(PyExc_ValueError,                                  
			  "The sample number must be positive!");            
	  return NULL;                                                        
     }                                                                       

     if(dimension == 1){
	  a_array = (PyArrayObject *) PyGSL_New_Array(1, &dims[1], NPY_DOUBLE);
     } else {
	  a_array = (PyArrayObject *) PyGSL_New_Array(2, dims, NPY_DOUBLE);
     }

     if(a_array == NULL){
          FUNC_MESS("FAIL");
	  return NULL;
     }

     for(i=0; i<dimension; i++){
	  data = (double *) (PyArray_GETPTR1(a_array, i));
	  evaluator(rng->rng, d1, d2, d3, data, data+1);
     }

     FUNC_MESS_END();
     return (PyObject *) a_array;
}

PyObject *
PyGSL_pdf_ddd_to_dd(PyObject *self, PyObject *args, 
		    double (*evaluator)(const double, const double, const double, const double, const double))
{

     PyObject *tmp1, *tmp2;
     PyArrayObject *array_x = NULL, *array_y = NULL, *array_out = NULL;
     double d1, d2, d3;
     double x,y;
     PyGSL_array_index_t dimension=-1;


     FUNC_MESS_BEGIN();
     assert(args && evaluator);

     if(0 == PyArg_ParseTuple(args, "OOddd", &tmp1, &tmp2, &d1, &d2, &d3)){
	  return NULL;
     }
#ifdef NUMERIC
     if((!PyGSL_array_check(tmp1)) && (!PyGSL_array_check(tmp2)))
#endif
     {  /* No arrays, just calculate one float */
	  if(!PyGSL_array_check(tmp1)){
	      if(PyGSL_PYFLOAT_TO_DOUBLE(tmp1, &x, NULL) != GSL_SUCCESS){
		  FUNC_MESS("FAIL");
		  return NULL;
	    }
	  }
	  if(!PyGSL_array_check(tmp1)){
	      if(PyGSL_PYFLOAT_TO_DOUBLE(tmp2, &y, NULL) != GSL_SUCCESS){
		  FUNC_MESS("FAIL");
		  return NULL;
	      }
	  }
	  return PyFloat_FromDouble(evaluator(x, y, d1, d2, d3));
     }


     {
	  /* Arrays ... */
	  int i;
	  double *data_out;

	  
	  array_x = PyGSL_vector_check(tmp1, -1, PyGSL_DARRAY_INPUT(1), NULL, NULL);
	  if(array_x == NULL)
	       goto fail;
	  dimension = PyArray_DIM(array_x, 0);
	  /* 
	   * PyGSL_PyArray_PREPARE_gsl_vector_view checks if the input can be converted. 
	   * Dimension -1 means no check necessary
	   */
	  array_y = PyGSL_vector_check(tmp2, -1, PyGSL_DARRAY_INPUT(1), NULL, NULL);
	  if(array_y == NULL){
	       goto fail;
	  }
	  if (dimension == -1)
	       dimension = PyArray_DIM(array_y, 0);
	  else
	       assert(PyArray_DIM(array_y, 0) == dimension);
	  
	  array_out = (PyArrayObject *) PyGSL_New_Array(1, &dimension, NPY_DOUBLE);
	  if(array_out == NULL)
	       goto fail;

	  DEBUG_MESS(2, "Evaluating pdf at %p",   (void *) evaluator);
	  DEBUG_MESS(2, "Evaluating array x at %p with data at %p and strides of %ld", (void *) array_x, 
		     (void *) PyArray_DATA(array_x), PyArray_STRIDE(array_x, 0));
	  for(i=0; i<dimension; i++){			
	       DEBUG_MESS(2, "Evaluating element [%d]", i);
	       x =  *((double *)(PyArray_GETPTR1(array_x, i)));
	       y =  *((double *)(PyArray_GETPTR1(array_y, i)));
	       data_out = ((double *)(PyArray_GETPTR1(array_out, i)));
	       *data_out =  evaluator(x, y, d1, d2, d3);
	  }
	  DEBUG_MESS(2, "Done %ld iterations", (long)dimension);

	  Py_DECREF(array_x);						       
	  Py_DECREF(array_y);
	  FUNC_MESS_END();
	  return (PyObject *) array_out;
     }


	  fail:
	  FUNC_MESS("Fail");
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
	  Py_XDECREF(array_x);
	  Py_XDECREF(array_y);
	  Py_XDECREF(array_out);
	  return NULL;
}

/*
 * handles the following wrapper routines:
 *        rng_to_dd :   type value = 2
 *        rng_to_ddd :  type value = 3  
 *        rng_to_nd :   type value = 0  to be able to handle rng_to_dddd in future
 */
PyObject*
PyGSL_rng_to_generic_nd(PyGSL_rng *rng, PyObject *args, int type, void *evaluator)
{
     PyGSL_array_index_t dimension=1, dims[2], i, ds=1;
     PyArrayObject *a_array;
     double *data;
     void (*evaluator_2)(const gsl_rng *, double *, double *) = NULL;
     void (*evaluator_3)(const gsl_rng *, double *, double *, double *) = NULL;
     void (*evaluator_0)(const gsl_rng *, size_t n, double *) = NULL;     
     
     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     assert(type == 2 || type == 3 || type == 0);

     if(type == 0){
	  if(0 == PyArg_ParseTuple(args, "i|i", &ds, &dimension)){
	       return NULL;
	  }
     }else{
	  if(0 == PyArg_ParseTuple(args, "|i", &dimension)){
	       return NULL;
	  }
     }

     if(dimension <= 0){
	  PyErr_SetString(PyExc_ValueError,
			  "The sample number must be positive!");
	  return NULL;             
     }                                                                       

     if(ds <= 0){                                                    
	  PyErr_SetString(PyExc_ValueError,                                  
			  "The request dimensions must be positive!");            
	  return NULL;                                                        
     }                                                                       

     dims[0] = dimension;

     switch(type){
     case 2: dims[1] = 2;   evaluator_2 = (void (*) (const gsl_rng *, double *, double *)) evaluator; break;
     case 3: dims[1] = 3;   evaluator_3 = (void (*) (const gsl_rng *, double *, double *, double *)) evaluator; break;
     case 0: dims[1] = ds;  evaluator_0 = (void (*) (const gsl_rng *, size_t, double *)) evaluator; break;
     default: assert(0);
     }

     assert(dims[1] > 0);

     /* In case only one item was requested, return a one dimensional array */
     if(dimension == 1){
	  a_array = (PyArrayObject *) PyGSL_New_Array(1, &dims[1], NPY_DOUBLE);
     } else {
	  a_array = (PyArrayObject *) PyGSL_New_Array(2, dims, NPY_DOUBLE);
     }
     if(a_array == NULL){
	  FUNC_MESS("FAIL");
	  return NULL;
     }
     for(i=0; i<dimension; i++){
	  data = (double *) (PyArray_GETPTR1(a_array, i));
	  switch(type){
	  case 2: evaluator_2(rng->rng, data, data+1); break;
	  case 3: evaluator_3(rng->rng, data, data+1, data+2); break;
	  case 0: evaluator_0(rng->rng, (size_t) ds, data); break;
	  default: assert(0);
	  }
     }

     FUNC_MESS_END();
     return (PyObject *) a_array;
}
     

PyObject *
PyGSL_rng_to_dd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double *, double *))
{
  return PyGSL_rng_to_generic_nd(rng, args, 2, (void *) evaluator);
}

PyObject *
PyGSL_rng_to_ddd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double *, double *, double *))
{
  return PyGSL_rng_to_generic_nd(rng, args, 3, (void *) evaluator);
}

PyObject *
PyGSL_rng_to_nd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, size_t n, double *))
{
  return PyGSL_rng_to_generic_nd(rng, args, 0, (void *) evaluator);
}



PyObject *
PyGSL_rng_dA_to_dA(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, const size_t, const double * , double *))
{
     PyGSL_array_index_t dimension=1, dims[2], i;
     PyObject *tmp;
     PyArrayObject *a_array_in =NULL, *a_array_out = NULL;
     double *data_out;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "O|i", &tmp, &dimension)){
	  return NULL;
     }
     
     a_array_in = PyGSL_vector_check(tmp, -1, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
     if(a_array_in == NULL)
	  goto fail;

     dims[0] = dimension;
     dims[1] = PyArray_DIM(a_array_in, 0);
     if(dimension <= 0){                                                    
	  PyErr_SetString(PyExc_ValueError,                                  
			  "The sample number must be positive!");            
	  goto fail;                                                        
     }                                                                       
     if (dimension == 1){
	  a_array_out = (PyArrayObject *) PyGSL_New_Array(1, &dims[1], NPY_DOUBLE);
     }else{
	  a_array_out = (PyArrayObject *) PyGSL_New_Array(2, dims, NPY_DOUBLE);
     }
     if(a_array_out == NULL)
	  goto fail;


     for(i=0; i<dimension; i++){
	  data_out = (double *) PyArray_GETPTR1(a_array_out,  i);
	  evaluator(rng->rng, (size_t) dims[1], (double *) PyArray_DATA(a_array_in), data_out);
	  
	  if(PyErr_Occurred()){
	       DEBUG_MESS(3, "Already a python error occured for dim %ld", i);
	       goto fail;
	  }
     }
     Py_DECREF(a_array_in);
     FUNC_MESS_END();
     return (PyObject *) a_array_out;

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     Py_XDECREF(a_array_in);
     Py_XDECREF(a_array_out);
     return NULL;
}



PyObject *
PyGSL_rng_uidA_to_uiA(PyGSL_rng *rng, PyObject *args, 
		    void (*evaluator)(const gsl_rng *, const size_t, const unsigned int, 
				      const double * , unsigned int *))
{
     PyGSL_array_index_t dimension=0, dimension_check=-1, dimension_tmp, dims[2], 
	     i,  stride2, stride_n, stride_phi;
     PyGSL_array_info_t a_info;
     PyObject *tmp_n, *tmp_phi, *dimension_o = NULL;
     PyArrayObject *a_phi = NULL, *a_n =NULL, *a_array_out = NULL;
     double * pd_phi;
     int use_array_dimension = 0, iterate_over_parameters = 0, line_no = __LINE__;
     unsigned int *data_out = NULL;
     unsigned int  *pui_n = NULL;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "OO|O", &tmp_n, &tmp_phi, &dimension_o)){
	  return NULL;
     }
     
     /* default: internal sampling rate not checked */
     dimension = 0;
     /* default: any array size allowed */
     dimension_check = -1;
     /* default: single values for the parameters */
     stride_n = 0; 
     stride_phi = 0;


     
     a_info = PyGSL_BUILD_ARRAY_INFO(PyGSL_CONTIGUOUS | PyGSL_INPUT_ARRAY, 
				     NPY_UINT, sizeof(unsigned int), 1);
     a_n = PyGSL_vector_check(tmp_n, dimension_check, a_info, &stride_n, NULL);
     if(a_n == NULL){
	     line_no = __LINE__ - 2;
	     goto fail;
     }
     dimension_tmp = PyArray_DIM(a_n, 0);
     if(dimension_tmp == 1){
	     ;
     } else {
	     dimension_check = dimension_tmp;
     }


     a_phi = PyGSL_matrix_check(tmp_phi, dimension_check, -1, PyGSL_DARRAY_CINPUT(2),
				&stride_phi, &stride2, NULL);
     if(a_phi == NULL){
	     line_no = __LINE__ - 3;
	     goto fail;
     }

     if(stride2 != 1){
	     line_no = __LINE__ - 1;
	     pygsl_error("the last dimension of the matrix phi must be contiguous",
			 __FILE__, __LINE__, GSL_ESANITY);
	     goto fail;
     }

     dimension_tmp = PyArray_DIM(a_phi, 0);
     if(dimension_tmp == 1){
	     dimension_check = 1;
     } else {
	     dimension_check = dimension_tmp;
     }

     DEBUG_MESS(2, "Input data: pui_N: len(%ld) stride = %ld, "
		"pd_phishape = (%ld,%ld), stride = %ld",
		(long) PyArray_DIM(a_n, 0), (long) stride_n, 
		(long) PyArray_DIM(a_phi, 0), (long) PyArray_DIM(a_phi, 1),
		(long) stride_phi);

     DEBUG_MESS(2, "Found %ld samples ", (long) dimension_check);
     if(dimension_o == NULL){
	     dimension = dimension_check;
     }else{
	     unsigned long ultmp;
	     if(PyGSL_PYLONG_TO_ULONG(dimension_o, &ultmp, NULL) != GSL_SUCCESS){
		     line_no = __LINE__ - 1;
		     goto fail;
	     }
	     if(ultmp == 0) {
		     pygsl_error("the internal iteration number must be >= 1",
				 __FILE__, __LINE__, GSL_ESANITY);
		     line_no = __LINE__ - 3;
		     goto fail;
		     
	     }
	     dimension = ultmp;
	     if(dimension_check != 1 && dimension != dimension_check){
		     DEBUG_MESS(2, "optional sample argument was %lu array n = %ld array phi = %ld ", 
				ultmp, (long) PyArray_DIM(a_n, 0), (long) PyArray_DIM(a_phi, 0));
		     pygsl_error("at least one of the arrays gave the number" 
				 " of samples != 1 not matching the optional argument number of samples",
				 __FILE__, __LINE__, GSL_ESANITY);
		     line_no = __LINE__ - 3;
		     goto fail;		     
	     }
     }

     
     /* clear up */
     if (dimension == 0){
	     /* no dimension found up to now ... */
	     dimension = 1;
     }

     if(PyArray_DIM(a_n, 0) == 1){
	     stride_n = 0;
     }

     if(PyArray_DIM(a_phi, 0) == 1){
	     stride_phi = 0;
     }


     dims[0] = dimension;
     dims[1] = PyArray_DIM(a_phi, 1);
     if(dimension <= 0){                                                    
	  PyErr_SetString(PyExc_ValueError,                                  
			  "The sample number must be positive!");            
	  line_no = __LINE__ - 3;
	  goto fail;                                                        
     }                                                                       

     a_array_out = (PyArrayObject *) PyGSL_New_Array(2, dims, NPY_UINT);
     if(a_array_out == NULL){
	  line_no = __LINE__ - 2;
	  goto fail;
     }

     
     pd_phi = (double *) PyArray_DATA(a_phi);
     pui_n  = (unsigned int *) PyArray_DATA(a_n);

     for(i=0; i<dimension; i++){
	     data_out = (unsigned int *) PyArray_GETPTR1(a_array_out, i);	  
	     evaluator(rng->rng, (size_t) dims[1], pui_n[stride_n * i], &(pd_phi[stride_phi * i]), data_out);
     }
     Py_DECREF(a_phi);
     Py_DECREF(a_n);
     FUNC_MESS_END();
     return (PyObject *) a_array_out;

 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line_no);  
     Py_XDECREF(a_n);
     Py_XDECREF(a_phi);
     Py_XDECREF(a_array_out);
     return NULL;
}

PyObject*
PyGSL_pdf_dA_to_uint_or_dA(PyObject *self, PyObject *args, void * evaluator, enum NPY_TYPES type_3darg)
{
     PyObject *tmp, *tmp1;
     PyArrayObject *array_n = NULL, *array_p = NULL, *array_out = NULL;
     PyGSL_array_index_t dimension=1, k, i, line=-1;
     PyGSL_array_info_t ainfo;

     double *data_p, *data_out, *data_theta, tmp_data; 
     unsigned int *data_n;

     double (*evaluator_double) (const size_t, const double [], const double []) = NULL;
     double (*evaluator_uint) (const size_t, const double [], const unsigned int []) = NULL;

     FUNC_MESS_BEGIN();
     assert(args && evaluator);
     assert(type_3darg == NPY_DOUBLE || type_3darg == NPY_LONG);

     if(0 == PyArg_ParseTuple(args, "OO", &tmp, &tmp1)){
	  line = __LINE__ -1;
	  goto fail;
     }
     array_p = PyGSL_vector_check(tmp, -1, PyGSL_DARRAY_INPUT(1), NULL, NULL);
     if(array_p == NULL){
	  line = __LINE__ - 2;
	  goto fail;	  
     }
     k = PyArray_DIM(array_p, 0);
     DEBUG_MESS(4, "Building Matrix. Input Object @ %p with refcount %ld!", (void *) tmp1, tmp1->ob_refcnt);
     ainfo = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, type_3darg, 1, 2);
     array_n = PyGSL_matrix_check(tmp1, -1, k, ainfo,  NULL, NULL, NULL);
     if(array_n == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     DEBUG_MESS(4, "Built Matrix. Object @ %p with refcount %ld!", (void *) array_n, PyGSL_PY_ARRAY_GET_REFCNT(array_n));
     dimension = PyArray_DIM(array_n, 0);

     FUNC_MESS("New Array ...");
     array_out = (PyArrayObject *) PyGSL_New_Array(1, &dimension, NPY_DOUBLE);
     FUNC_MESS("BUILT New Array");
     if(array_out == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     data_p = (double *) PyArray_DATA(array_p);
     data_out = (double *) PyArray_DATA(array_out);

     FUNC_MESS("SWITCHING callback");
     assert(type_3darg == NPY_DOUBLE || type_3darg == NPY_LONG);
     switch(type_3darg){
     case NPY_DOUBLE:      
	  evaluator_double = (double (*) (const size_t, const double [], const double [])) evaluator;
	  break;
     case NPY_LONG:      
	  evaluator_uint    = (double (*) (const size_t, const double [], const unsigned int [])) evaluator;
	  break;
     default:
	  assert(0);
     }
     DEBUG_MESS(5, "array_n has %d dimensions. dim = [%ld, %ld] strides = [%ld,%ld]",
		PyArray_NDIM(array_n), 
		PyArray_DIM(array_n, 0), PyArray_DIM(array_n, 1),
		PyArray_STRIDE(array_n, 0), PyArray_STRIDE(array_n, 1));
     DEBUG_MESS(5, "array_out has %d dimensions. dim = [%ld]" 
		" strides = [%ld,], dimension = %ld, k = %ld", PyArray_NDIM(array_out), 
		(long)PyArray_DIM(array_out, 0), (long)PyArray_STRIDE(array_out, 0), (long)dimension,(long) k);
     FUNC_MESS("Evaluating callback");
     assert(PyArray_DIM(array_out, 0) >= dimension);
     for(i = 0; i < dimension; i++){
	  if(type_3darg == NPY_DOUBLE){
	       DEBUG_MESS(2, "Referenceing double element %ld", (long)i);
	       data_theta = (double *)PyArray_GETPTR1(array_n, i);
	       assert(evaluator_double != NULL);
	       DEBUG_MESS(2, "Calling Function for element %ld", (long)i);
	       tmp_data = evaluator_double((size_t) k, data_p, data_theta);
	       DEBUG_MESS(2, "Storing in array_out %f", tmp_data);
	       data_out[i] = tmp_data;
	  }else if (type_3darg == NPY_LONG){
	       DEBUG_MESS(2, "Evaluating long element %ld", (long)i);
	       data_n = (unsigned int *)((long *) PyArray_GETPTR1(array_n, i));
	       assert(evaluator_uint != NULL);
	       data_out[i] = evaluator_uint((size_t) k, data_p, data_n);
	  }else {
	      /*
	       * Why did I end here?? I checked in the beginnig that it was 
	       *  either or ... 
	       */
	       assert(0);
	  }
     }

     DEBUG_MESS(4, "Dereferencing p @ %p  and n @ %p", 
		(void *) array_p, (void *) array_n);
     Py_DECREF(array_p);
     Py_DECREF(array_n);
     return (PyObject *) array_out;
 fail:
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, line);
     Py_XDECREF(array_p);
     Py_XDECREF(array_n);
     Py_XDECREF(array_out);
     return NULL;     
}

PyObject*
PyGSL_pdf_dA_to_dA(PyObject *self, PyObject *args, 
		   double (*evaluator) (const size_t, const double [], const double []))
{

     PyObject *r;
     if((r = PyGSL_pdf_dA_to_uint_or_dA(self, args, (void *) evaluator, NPY_DOUBLE)) == NULL)
	  PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, __LINE__);
     return r;

}

PyObject*
PyGSL_pdf_uidA_to_uiA(PyObject *self, PyObject *args, 
		      double (*evaluator) (const size_t, const double [], const unsigned int []))
{
     PyObject *r;
     if((r= PyGSL_pdf_dA_to_uint_or_dA(self, args, (void *) evaluator, NPY_LONG)) == NULL)
	  PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, __LINE__);
     return r;
}


#ifdef NUMERIC
#undef NUMERIC
#define NUMERIC 0
#endif

/* 
 * Now the unsigned long stuff follows. Numeric arrays do not support unsigned long int. 
 * So I switch to lists here ! 
 */
PyObject *
PyGSL_rng_to_ulong(PyGSL_rng *rng, PyObject *args, unsigned long int (*evaluator)(const gsl_rng *))
{
     PyGSL_array_index_t dimension=1;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "|i", &dimension)){
	  return NULL;
     }

#define RNG_ARGUMENTS
#define DATA_TYPE     unsigned long int
#define ARRAY_TYPE    NPY_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR

 fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;	  
}
#undef  RNG_ARGUMENTS
#undef  DATA_TYPE
#undef  ARRAY_TYPE
#undef  TOPYOBJECT

PyObject *
PyGSL_rng_ul_to_ulong(PyGSL_rng *rng, PyObject *args, unsigned long int (*evaluator)(const gsl_rng *, unsigned long int))
{
     PyGSL_array_index_t dimension=1;

     PyObject *tmp;
     unsigned long int limit;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "O|i", &tmp, &dimension)){
	  return NULL;
     }
     if(PyGSL_PYLONG_TO_ULONG(tmp, &limit, NULL) != GSL_SUCCESS) goto fail;

#define RNG_ARGUMENTS ,limit
#define DATA_TYPE     unsigned long int
#define ARRAY_TYPE    NPY_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong

     RNG_EVALUATOR

  fail:  
     FUNC_MESS("FAIL");
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);  
     return NULL;
}
