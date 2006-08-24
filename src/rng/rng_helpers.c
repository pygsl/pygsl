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
#define NUMERIC 1

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
     data = (DATA_TYPE *) a_array->data;			             \
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
     dimension = array_in->dimensions[0];				     \
     array_out = (PyArrayObject *) PyGSL_New_Array(1, &dimension,            \
						    PyArray_DOUBLE);         \
									     \
									     \
     data_out = (double *) array_out->data;				     \
									     \
     for(i=0; i<dimension; i++){					     \
	  x = *((double *) (array_in->data + array_in->strides[0] * i));     \
	  data_out[i] = evaluator(x RNG_ARGUMENTS);  		             \
     }									     \
									     \
									     \
     Py_DECREF(array_in);						     \
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
#define ARRAY_TYPE    PyArray_DOUBLE
#define ARRAY_TYPE_IN PyArray_DOUBLE
#define ARRAY_TYPE_OUT PyArray_DOUBLE
#define TOPYOBJECT     PyFloat_FromDouble
#define PyGSL_CONVERTER  PyGSL_PYFLOAT_TO_DOUBLE

     RNG_EVALUATOR
  fail:
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE    PyArray_DOUBLE
#define TOPYOBJECT    PyFloat_FromDouble


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE       PyArray_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define ARRAY_TYPE_IN    PyArray_LONG
#define ARRAY_TYPE_OUT   PyArray_DOUBLE
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE    PyArray_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE       PyArray_INT
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define ARRAY_TYPE_IN    PyArray_LONG
#define ARRAY_TYPE_OUT   PyArray_DOUBLE
#define TOPYOBJECT       PyFloat_FromDouble
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE    PyArray_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE       PyArray_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define TOPYOBJECT       PyFloat_FromDouble
#define ARRAY_TYPE_IN    PyArray_LONG
#define ARRAY_TYPE_OUT   PyArray_DOUBLE
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE    PyArray_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE       PyArray_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define TOPYOBJECT       PyFloat_FromDouble
#define ARRAY_TYPE_IN    PyArray_LONG
#define ARRAY_TYPE_OUT   PyArray_DOUBLE
     PDF_EVALUATOR

 fail:
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE    PyArray_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR
  fail:  
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE       PyArray_LONG
#define PyGSL_CONVERTER  PyGSL_PYLONG_TO_UINT
#define DATA_TYPE        unsigned int
#define TOPYOBJECT       PyFloat_FromDouble
#define ARRAY_TYPE_IN    PyArray_LONG
#define ARRAY_TYPE_OUT   PyArray_DOUBLE
     PDF_EVALUATOR

 fail:     
     FUNC_MESS("FAIL");
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
	  a_array = (PyArrayObject *) PyGSL_New_Array(1, &dims[1], PyArray_DOUBLE);
     } else {
	  a_array = (PyArrayObject *) PyGSL_New_Array(2, dims, PyArray_DOUBLE);
     }

     if(a_array == NULL){
          FUNC_MESS("FAIL");
	  return NULL;
     }

     for(i=0; i<dimension; i++){
	  data = (double *) (a_array->data + a_array->strides[0] * i);
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
	  dimension = array_x->dimensions[0];
	  /* 
	   * PyGSL_PyArray_PREPARE_gsl_vector_view checks if the input can be converted. 
	   * Dimension -1 means no check necessary
	   */
	  array_y = PyGSL_vector_check(tmp2, -1, PyGSL_DARRAY_INPUT(1), NULL, NULL);
	  if(array_y == NULL){
	       goto fail;
	  }
	  if (dimension == -1)
	       dimension = array_y->dimensions[0];
	  else
	       assert(array_y->dimensions[0] == dimension);
	  
	  array_out = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
	  if(array_out == NULL)
	       goto fail;

	  DEBUG_MESS(2, "Evaluating pdf at %p",   (void *) evaluator);
	  DEBUG_MESS(2, "Evaluating array x at %p with data at %p and strides of %d", (void *) array_x, 
		     (void *) array_x->data, array_x->strides[0]);
	  for(i=0; i<dimension; i++){			
	       DEBUG_MESS(2, "Evaluating element [%d]", i);
	       x =  *((double *)(array_x->data + array_x->strides[0] * i));
	       y =  *((double *)(array_y->data + array_y->strides[0] * i));
	       data_out = ((double *)(array_out->data + array_out->strides[0] * i));
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
     case 2: dims[1] = 2;   evaluator_2 = evaluator; break;
     case 3: dims[1] = 3;   evaluator_3 = evaluator; break;
     case 0: dims[1] = ds;  evaluator_0 = evaluator; break;
     default: assert(0);
     }

     assert(dims[1] > 0);

     /* In case only one item was requested, return a one dimensional array */
     if(dimension == 1){
	  a_array = (PyArrayObject *) PyGSL_New_Array(1, &dims[1], PyArray_DOUBLE);
     } else {
	  a_array = (PyArrayObject *) PyGSL_New_Array(2, dims, PyArray_DOUBLE);
     }
     if(a_array == NULL){
	  FUNC_MESS("FAIL");
	  return NULL;
     }
     for(i=0; i<dimension; i++){
	  data = (double *) (a_array->data + a_array->strides[0] * i);
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
     return PyGSL_rng_to_generic_nd(rng, args, 2, evaluator);
}

PyObject *
PyGSL_rng_to_ddd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, double *, double *, double *))
{
     return PyGSL_rng_to_generic_nd(rng, args, 3, evaluator);
}

PyObject *
PyGSL_rng_to_nd(PyGSL_rng *rng, PyObject *args, void (*evaluator)(const gsl_rng *, size_t n, double *))
{
     return PyGSL_rng_to_generic_nd(rng, args, 0, evaluator);
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
     dims[1] = a_array_in->dimensions[0];
     if(dimension <= 0){                                                    
	  PyErr_SetString(PyExc_ValueError,                                  
			  "The sample number must be positive!");            
	  goto fail;                                                        
     }                                                                       
     if (dimension == 1){
	  a_array_out = (PyArrayObject *) PyGSL_New_Array(1, &dims[1], PyArray_DOUBLE);
     }else{
	  a_array_out = (PyArrayObject *) PyGSL_New_Array(2, dims, PyArray_DOUBLE);
     }
     if(a_array_out == NULL)
	  goto fail;


     for(i=0; i<dimension; i++){
	  data_out = (double *) (a_array_out->data + a_array_out->strides[0] * i);
	  evaluator(rng->rng, (size_t) dims[1], (double *) a_array_in->data, data_out);
     }
     Py_DECREF(a_array_in);
     FUNC_MESS_END();
     return (PyObject *) a_array_out;

 fail:
     Py_XDECREF(a_array_in);
     Py_XDECREF(a_array_out);
     return NULL;
}


PyObject *
PyGSL_rng_uidA_to_uiA(PyGSL_rng *rng, PyObject *args, 
		    void (*evaluator)(const gsl_rng *, const size_t, const unsigned int, 
				      const double * , unsigned int *))
{
     PyGSL_array_index_t dimension=1, dims[2], i;
     PyObject *tmp, *tmp_N;
     PyArrayObject *a_array_in =NULL, *a_array_out = NULL;
     unsigned int  *data_out;
     unsigned int N;
     unsigned long int lN;

     FUNC_MESS_BEGIN();
     assert(rng && args && evaluator);

     if(0 == PyArg_ParseTuple(args, "OO|i", &tmp, &tmp_N, &dimension)){
	  return NULL;
     }
     if(PyGSL_PYLONG_TO_ULONG(tmp_N, &lN, NULL) != GSL_SUCCESS) goto fail;
     N = lN;

     a_array_in = PyGSL_vector_check(tmp, -1, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
     if(a_array_in == NULL)
	  goto fail;

     dims[0] = dimension;
     dims[1] = a_array_in->dimensions[0];
     if(dimension <= 0){                                                    
	  PyErr_SetString(PyExc_ValueError,                                  
			  "The sample number must be positive!");            
	  goto fail;                                                        
     }                                                                       

     a_array_out = (PyArrayObject *) PyGSL_New_Array(2, dims, PyArray_LONG);
     if(a_array_out == NULL)
	  goto fail;


     for(i=0; i<dimension; i++){
	  data_out = (unsigned int *) (a_array_out->data + a_array_out->strides[0] * i);
	  evaluator(rng->rng, (size_t) dims[1], (unsigned int) N, (double *) a_array_in->data, data_out);
     }
     Py_DECREF(a_array_in);
     FUNC_MESS_END();
     return (PyObject *) a_array_out;

 fail:
     FUNC_MESS("FAIL");
     Py_XDECREF(a_array_in);
     Py_XDECREF(a_array_out);
     return NULL;
}

PyObject*
PyGSL_pdf_dA_to_uint_or_dA(PyObject *self, PyObject *args, void * evaluator, enum PyArray_TYPES type_3darg)
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
     assert(type_3darg == PyArray_DOUBLE || type_3darg == PyArray_LONG);

     if(0 == PyArg_ParseTuple(args, "OO", &tmp, &tmp1)){
	  line = __LINE__ -1;
	  goto fail;
     }
     array_p = PyGSL_vector_check(tmp, -1, PyGSL_DARRAY_INPUT(1), NULL, NULL);
     if(array_p == NULL){
	  line = __LINE__ - 2;
	  goto fail;	  
     }
     k = array_p->dimensions[0];
     FUNC_MESS("Building Matrix!");
     ainfo = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, type_3darg, 1, 2);
     array_n = PyGSL_matrix_check(tmp1, -1, k, ainfo,  NULL, NULL, NULL);
     if(array_n == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     FUNC_MESS("BUILT!");
     dimension = array_n->dimensions[0];

     FUNC_MESS("New Array ...");
     array_out = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
     FUNC_MESS("BUILT New Array");
     if(array_out == NULL){
	  line = __LINE__ - 2;
	  goto fail;
     }
     data_p = (double *) array_p->data;
     data_out = (double *) array_out->data;

     FUNC_MESS("SWITCHING callback");
     assert(type_3darg == PyArray_DOUBLE || type_3darg == PyArray_LONG);
     switch(type_3darg){
     case PyArray_DOUBLE:      
	  evaluator_double = (double (*) (const size_t, const double [], const double [])) evaluator;
	  break;
     case PyArray_LONG:      
	  evaluator_uint    = (double (*) (const size_t, const double [], const unsigned int [])) evaluator;
	  break;
     default:
	  assert(0);
     }
     DEBUG_MESS(5, "array_n has %d dimensions. dim = [%d, %d] strides = [%d,%d]", array_n->nd, 
		    array_n->dimensions[0], array_n->dimensions[1],
		    array_n->strides[0], array_n->strides[1]);
     DEBUG_MESS(5, "array_out has %d dimensions. dim = [%ld]" 
		    " strides = [%ld,], dimension = %ld, k = %ld", array_out->nd, 
		    (long)array_out->dimensions[0], (long)array_out->strides[0], (long)dimension,(long) k);
     FUNC_MESS("Evaluating callback");
     assert(array_out->dimensions[0] >= dimension);
     for(i = 0; i < dimension; i++){
	  if(type_3darg == PyArray_DOUBLE){
	       DEBUG_MESS(2, "Referenceing double element %ld", (long)i);
	       data_theta = (double *)(array_n->data + array_n->strides[0]*i);
	       assert(evaluator_double != NULL);
	       DEBUG_MESS(2, "Calling Function for element %ld", (long)i);
	       tmp_data = evaluator_double((size_t) k, data_p, data_theta);
	       DEBUG_MESS(2, "Storing in array_out %f", tmp_data);
	       data_out[i] = tmp_data;
	  }else if (type_3darg == PyArray_LONG){
	       DEBUG_MESS(2, "Evaluating long element %ld", (long)i);
	       data_n = (unsigned int *)((long *) (array_n->data + array_n->strides[0] * i));
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
     if((r = PyGSL_pdf_dA_to_uint_or_dA(self, args, (void *) evaluator, PyArray_DOUBLE)) == NULL)
	  PyGSL_add_traceback(NULL, __FILE__, __FUNCTION__, __LINE__);
     return r;

}

PyObject*
PyGSL_pdf_uidA_to_uiA(PyObject *self, PyObject *args, 
		      double (*evaluator) (const size_t, const double [], const unsigned int []))
{
     PyObject *r;
     if((r= PyGSL_pdf_dA_to_uint_or_dA(self, args, (void *) evaluator, PyArray_LONG)) == NULL)
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
#define ARRAY_TYPE    PyArray_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong


     RNG_EVALUATOR

 fail:  
     FUNC_MESS("FAIL");
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
#define ARRAY_TYPE    PyArray_LONG
#define TOPYOBJECT    PyLong_FromUnsignedLong

     RNG_EVALUATOR

  fail:  
     FUNC_MESS("FAIL");
     return NULL;
}
