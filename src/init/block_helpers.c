/* -*- C -*- */
/*
 * Author : Pierre Schnizer
 * Date   : January 2003
 * 
 *  Changes for better error reporting from 
 *  17. 01. 2003
 *  Adding a info struct. This struct contains additional information used for 
 *  error Reporting.
 *
 *  Changed to support Numeric and nummarray.
 */

#define PyGSL_IMPORT_ARRAY 1
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <stdlib.h>
#include <stdio.h>
#include <pygsl/profile.h>
#include <pygsl/general_helpers.h>
#include <pygsl/utils.h>

static const char filename[] = __FILE__;

static int
PyGSL_array_check(PyObject * ob)
{
     return PyArray_Check(ob);
}

/*
 * PyGSL_PyArray_PREPARE_gsl_vector_view :
 *                                 Check if an array can be treated as vector.
 *
 * It is provided using a macro / function pair. The macro will accept a
 * numpy array and return the pointer to the numpy object if the array is one
 * dimensional and has the required number of elements. Further its 
 * contiguousity is checked. If the object did not fulfill the requirements the
 * function PyGSL_PyArray_prepare_gsl_vector_view is called. This function will
 * try to convert the object, or generate an approbriate error message. If the 
 * conversion is successful it will increase the profile counter 
 * pygsl_profile_vector_transform_counter via the macro 
 * PyGSL_INCREASE_vector_transform_counter().
 *
 * Input : 
 *         object              : a general python object
 *         array_type          : the required C type for the array
 *         contiguous          : 2 copy the original array
 *                               1 the array must be contigous,
 *                               0 discontigous ones are acceptable.
 *         size                : length of the vector, or -1 if no check 
 *                               needed.
 *         argument number     : The argument number. Used for error reporting
 *         info                : a PyGSL_Error_info struct. Used for error 
 *                               reporting during callback evaluation. Pass 
 *                               NULL if not needed.
 *
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 */
#ifdef NO_PyGSL_LEGACY
#endif /* NO_PyGSL_LEGACY */
PyGSL_API_EXTERN PyArrayObject * 
PyGSL_PyArray_prepare_gsl_vector_view(PyObject *src,
				      int array_type,
				      int flag, 
				      PyGSL_array_index_t size, int argnum, PyGSL_error_info * info);

/*
 * PyGSL_PyArray_PREPARE_gsl_matrix_view
 *                           Check if an array can be treated as matrix. 
 *
 * It is provided using a macro / function pair. The macro will accept a
 * numpy array and return the pointer to the numpy object if the array is two
 * dimensional and has the required number of elements in both dimensions. 
 * Further its contiguousity is checked. If the object did not fulfill the 
 * requirements the function PyGSL_PyArray_prepare_gsl_matrix_view is called. 
 * This function will try to convert the object or generate an approbriate 
 * error message. If the conversion is successful it will increase the profile
 * counter pygsl_profile_matrix_transform_counter via the macro 
 * PyGSL_INCREASE_matrix_transform_counter().
 *
 * Input : 
 *         PyObject            : a general python object
 *         array_type          : the required C type for the array
 *         contiguous          : 2 make a copy of that array!
 *                               1 the array must be contigous,
 *                               0 discontigous ones are acceptable.
 *         size1               : number of elements in the first dimension, or
 *                                -1 if no check needed.
 *         size2               : number of elements in the second dimension, or
 *                                -1 if no check needed.
 *         argument number     : The argument number. Used for error reporting
 *         info struct         : a PyGSL_Error_info struct. Used for error
 *                               reporting during callback evaluation. Pass
 *                               NULL if not needed.
 *
 * Output: 
 *                             : a pointer to a PyArrayObject or NULL in case 
 *                              of error. This object must be dereferenced.
 *
 * Important: When the data will be passed to gsl via gsl_matrix_view_array, 
 *            then  you must enforce an contiguous array.
 */


PyGSL_API_EXTERN PyArrayObject *
PyGSL_PyArray_prepare_gsl_matrix_view(PyObject *src,
				      int array_type,
				      int flag, 
				      PyGSL_array_index_t size1,  PyGSL_array_index_t size2, int argnum, 
				      PyGSL_error_info * info);

static int 
PyGSL_stride_recalc(PyGSL_array_index_t strides, int basic_type_size,
		    PyGSL_array_index_t * stride_recalc)
{
     int line;

     FUNC_MESS_BEGIN();
     line = __LINE__ + 1;
     if((strides % basic_type_size) == 0) {
	  *stride_recalc = strides / basic_type_size; 
	  DEBUG_MESS(2, "\tRecalculated strides to %ld", (long)*stride_recalc);
	  FUNC_MESS_END();
	  return GSL_SUCCESS;
     }

     DEBUG_MESS(2, "Failed to convert stride. %ld/%d != 0", 
		(long)strides, basic_type_size);
     pygsl_error("Can not convert the stride to a GSL stride", 
	       filename, __LINE__, PyGSL_ESTRIDE);
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);     
     return PyGSL_ESTRIDE;
}
/* ========================================================================= */
/*
 * Implementation of the above routines.
 */

static int
PyGSL_PyArray_Check(PyArrayObject *a_array, int array_type, int flag,  int nd,
		    PyGSL_array_index_t *dimensions, int argnum, PyGSL_error_info * info)
{

     int i;
     int error_flag = GSL_ESANITY, line = -1;
     PyGSL_array_index_t  dim_temp;

     FUNC_MESS_BEGIN();
     if(!PyArray_Check((PyObject *) a_array)){
	  pygsl_error("Did not recieve an array!", filename, __LINE__, GSL_ESANITY);
	  line = __LINE__ - 2;
	  error_flag =  GSL_ESANITY;
	  goto fail;
     }
     if(nd <  1 || nd > 2){	  
	  DEBUG_MESS(2, "Got an nd of %d", nd);          
	  line = __LINE__ - 2;
	  pygsl_error("nd must either 1 or 2!", filename, __LINE__, GSL_ESANITY);
	  error_flag =  GSL_ESANITY;
	  goto fail;
     }

     if (a_array->nd !=  nd){
	  DEBUG_MESS(3, "array->nd = %d\t nd = %d", a_array->nd, nd);
	  line = __LINE__ - 1;
	  sprintf(pygsl_error_str, "I could not convert argument number % 3d."
		  " I expected a %s, but got an array of % 3d dimensions!\n", argnum, 
		  (nd == 1) ? "vector" : "matrix", a_array->nd);

	  if (info){
	       info->error_description = pygsl_error_str;
	       PyGSL_set_error_string_for_callback(info);
	  } else {
	       pygsl_error(pygsl_error_str, filename, __LINE__, GSL_EBADLEN);
	  }
	  error_flag = GSL_EBADLEN;
	  goto fail;
     }
     

     
     for(i=0; i<nd; ++i){
	  if(dimensions[i] == -1 ){
	       switch(i){
	       case 0: 
		 DEBUG_MESS(2, "\t\t No one cares about its first dimension! %d", 0); 
		 break;

	       case 1: 
		 DEBUG_MESS(2, "\t\t No one cares about its second dimension! %d", 0); 
		 break;
		 
	       default: 
		 error_flag = GSL_ESANITY; 
		 line = __LINE__ - 3; 
		 goto fail; 
		 break;
	       }
	       continue;
	  } 

	  /* Check to be performed ... */
	  dim_temp = a_array->dimensions[i];
	  DEBUG_MESS(9, "Dimension %d has %ld elements", i, 
		     (unsigned long) dim_temp);

	  if(dim_temp != (dimensions[i])){
	       sprintf(pygsl_error_str, 
		       "The size of argument % 3d did not match the expected"
		       " size for the %d dimension. I got % 3ld elements but" 
		       " expected % 3ld elements!\n",  argnum, i, 
		       (long)a_array->dimensions[0],(long)dimensions[0]);

	       if (info){
		    info->error_description = pygsl_error_str;
		    PyGSL_set_error_string_for_callback(info);
	       } else {
		    pygsl_error(pygsl_error_str, filename, __LINE__, GSL_EBADLEN);
	       }	       
	       error_flag = GSL_EBADLEN;
	       line = __LINE__ - 11;
	       goto fail;
	  }
     }

     if(a_array->data == NULL){
	  pygsl_error("Got an array object were the data was NULL!", filename,
		      __LINE__, GSL_ESANITY);
	  error_flag = GSL_ESANITY;	  
	  line = __LINE__ - 4;
	  goto fail;
     }

     if(a_array->descr->type_num == array_type){
	  DEBUG_MESS(4, "\t\tArray type matched! %d", 0);
     }else{
	  pygsl_error("The array type did not match the spezified one!",
		      filename, __LINE__, GSL_ESANITY);	  
	  DEBUG_MESS(4, "Found an array type of %d but expected %d",
		     (int) a_array->descr->type_num, array_type);
	  error_flag = GSL_ESANITY;
	  line = __LINE__ - 6;
	  goto fail;
     }

     if ((flag &  PyGSL_CONTIGUOUS) == 0){
	  DEBUG_MESS(2, "\t\t Can deal with discontiguous arrays! flag = %d", flag);
     } else {
	  if(!(a_array->flags & CONTIGUOUS)){
	       DEBUG_MESS(3, "array->flags %d requested flags %d", 
			  a_array->flags, flag);
	       pygsl_error("The array is not contiguous as requested!", filename,
			   __LINE__, GSL_ESANITY);
	       error_flag = GSL_ESANITY;
	       line = __LINE__ - 3;
	       goto fail;
	  }
     }
     FUNC_MESS_END();
     return GSL_SUCCESS;    

 fail:
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);
     DEBUG_MESS(4, "common array types: Double %d, CDouble %d", PyArray_DOUBLE, PyArray_CDOUBLE);
     DEBUG_MESS(4, "integer: Long %d, Int %d, Short %d", PyArray_LONG, PyArray_INT, PyArray_SHORT);
     /* DEBUG_MESS(8, "Char type %d  Byte type %d String type %d", PyArray_CHAR, PyArray_BYTE, PyArray_STRING); */
     return error_flag;
}


#ifdef PyGSL_NUMPY
#include "block_helpers_numpy.ic"
#endif
#ifdef PyGSL_NUMERIC
#include "block_helpers_numeric.ic"
#endif
#ifdef PyGSL_NUMARRAY
#include "block_helpers_numarray.ic"
#endif
#if (!defined PyGSL_NUMPY) && (!defined  PyGSL_NUMERIC) && (! defined PyGSL_NUMARRAY)
#error "Neither numpy nor numarray nor numeric is defined!"
#endif

static PyArrayObject * 
PyGSL_PyArray_generate_gsl_vector_view(PyObject *src,
				       int array_type,
				       int argnum)
{
     PyGSL_array_index_t dimension;
     PyObject *tmp;
     PyArrayObject *a_array = NULL;

     FUNC_MESS_BEGIN();
     tmp = PyNumber_Int(src);
     if(!tmp){
	  sprintf(pygsl_error_str, "I could not convert argument number % 3d. to an integer.",
		  argnum);
	 PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	 return NULL;
     }
     dimension = PyInt_AS_LONG(src);
     Py_DECREF(tmp);
     if(dimension <= 0){
	  sprintf(pygsl_error_str, "Argument number % 3d is % 10ld< 0. Its the size of the vector and thus must be positive!",
		  argnum, (long)dimension);
	 PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	 return NULL;
     }
     
     a_array = (PyArrayObject *) PyGSL_New_Array(1, &dimension, array_type);
     if(NULL == a_array){
	  return NULL;
     }
     FUNC_MESS_END();
     return a_array;
}

static PyArrayObject * 
PyGSL_PyArray_generate_gsl_matrix_view(PyObject *src,
				      int array_type,
				      int argnum)
{
     PyObject *tmp;
     PyArrayObject *a_array = NULL;

     PyGSL_array_index_t dimensions[2];
     int i;

     FUNC_MESS_BEGIN();     
     if(!PySequence_Check(src) || PySequence_Size(src) != 2){
	  sprintf(pygsl_error_str, "I need a sequence of two elements as argument number % 3d",
		  argnum);
	 PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	 return NULL;

     }

     for(i = 0; i<2; i++){
	  tmp = PyNumber_Int(PySequence_GetItem(src, i));
	  if(!tmp){
	       sprintf(pygsl_error_str, "I could not convert argument number % 3d. for dimension %3d to an integer.",
		       argnum, i);
	       PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	       return NULL;
	  }
	  dimensions[i] = PyInt_AS_LONG(tmp);
	  Py_DECREF(tmp);
	  if(dimensions[i] <= 0){
	       sprintf(pygsl_error_str, "Argument number % 3d is % 10ld< 0. Its the size of the vector and thus must be positive!",
		       argnum, (long)dimensions[i]);
	       PyErr_SetString(PyExc_TypeError, pygsl_error_str);
	       return NULL;
	  }

     }     
     a_array = (PyArrayObject *) PyGSL_New_Array(2, dimensions, array_type);
     if(NULL == a_array){
	  return NULL;
     }
     return a_array;
}

static PyArrayObject *
PyGSL_copy_gslvector_to_pyarray(const gsl_vector *x)
{     
     PyGSL_array_index_t dimension = -1, i;
     PyArrayObject *a_array = NULL;
     double tmp;

     FUNC_MESS_BEGIN();
     dimension = x->size;
     a_array = (PyArrayObject *) PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
     if (a_array == NULL) return NULL;
     for (i=0;i<dimension;i++){
       tmp = gsl_vector_get(x, i);
       ((double *) a_array->data)[i] = tmp;
       DEBUG_MESS(3, "\t\ta_array_%ld = %f\n", (long)i, tmp);
     }
     FUNC_MESS_END();
     return a_array;
}

static PyArrayObject *
PyGSL_copy_gslmatrix_to_pyarray(const gsl_matrix *x)
{     
     int i, j;
     PyGSL_array_index_t dimensions[2];
     PyArrayObject *a_array = NULL;
     double tmp;
     char *myptr;

     FUNC_MESS_BEGIN();
     dimensions[0] = x->size1;
     dimensions[1] = x->size2;
     a_array = (PyArrayObject *) PyGSL_New_Array(2, dimensions, PyArray_DOUBLE);
     if (a_array == NULL) return NULL;
     for (i=0;i<dimensions[1];i++){
	  for (j=0;j<dimensions[0];j++){
	      myptr =  a_array->data + a_array->strides[0] * i  
		                     + a_array->strides[1] * j;
	       tmp = gsl_matrix_get(x, j, i);
	       *((double *) myptr) = tmp;
	       DEBUG_MESS(3, "\t\ta_array_%d = %f\n", i, tmp);
	  }
     }
     FUNC_MESS_END();
     return a_array;
}


/*
 * Set a descriptive error. The callback name is listed together with the "GSL Object"
 * that called it, and a error description.
 */
static int
PyGSL_copy_pyarray_to_gslvector(gsl_vector *f, PyObject *object,  PyGSL_array_index_t n, PyGSL_error_info * info)
{
     PyArrayObject *a_array = NULL;
     double tmp;
     int i, argnum = -1;
     

     FUNC_MESS_BEGIN();
     if (info)
	  argnum = info->argnum;
     a_array = PyGSL_vector_check(object, n, PyGSL_DARRAY_INPUT(argnum), NULL, info);
     if(a_array == NULL){
          FUNC_MESS("PyArray_FromObject failed");
	  goto fail;
     }
    if(DEBUG>2){
      fprintf(stderr, "\t\ta_array->dimensions[0] = %d\n", a_array->dimensions[0]);
      fprintf(stderr, "\t\ta_array->strides[0] = %d\n", a_array->strides[0]);
    }

    for (i=0;i<n;i++){
	 tmp = *((double *) (a_array->data + a_array->strides[0] * i));
	 gsl_vector_set(f, i, tmp);
	 DEBUG_MESS(3, "\t\ta_array_%d = %f\n", i, tmp);

     }
    FUNC_MESS_END();
    Py_DECREF(a_array);
    return GSL_SUCCESS;
 fail:
    PyGSL_add_traceback(NULL, filename, __FUNCTION__, __LINE__);
    FUNC_MESS("Failure");
    Py_XDECREF(a_array);
    return GSL_FAILURE;
}

    


static int
PyGSL_copy_pyarray_to_gslmatrix(gsl_matrix *f, PyObject *object,  PyGSL_array_index_t n,
				PyGSL_array_index_t p,  PyGSL_error_info * info)
{
     PyArrayObject *a_array = NULL;
     double tmp;
     char *myptr;
     int argnum=-1;
     long i, j;


     FUNC_MESS_BEGIN();


     
     if (info)
	  argnum = info->argnum;
     a_array = PyGSL_matrix_check(object, n, p, PyGSL_DARRAY_CINPUT(info->argnum), NULL, NULL, info);
     if(a_array == NULL){
	  FUNC_MESS(" PyGSL_PyArray_PREPARE_gsl_matrix_view failed!");
	  goto fail;
     }

    assert(f->size1 == (size_t) n);
    assert(f->size2 == (size_t) p);


    for (i=0;i<n;i++){
	 for (j=0;j<p;j++){
	      myptr =  a_array->data + a_array->strides[0] * i  
		                     + a_array->strides[1] * j;
	      tmp = *((double *)(myptr));
	      DEBUG_MESS(3, "\t\ta_array[%ld,%ld] = %f\n", i, j, tmp);
	      gsl_matrix_set(f, i, j, tmp);
	 }
    }
    FUNC_MESS_END();
    Py_DECREF(a_array);
    return GSL_SUCCESS;
 fail:
    PyGSL_add_traceback(NULL, filename, __FUNCTION__, __LINE__);
    FUNC_MESS("  Failure");
    Py_XDECREF(a_array);
    return GSL_FAILURE;
}

static PyArrayObject * 
PyGSL_vector_or_double(PyObject *src, PyGSL_array_info_t ainfo, PyGSL_array_index_t size, PyGSL_error_info * info)
{
     int line = -1;
     PyArrayObject * r = NULL;
     PyGSL_array_index_t dim = 1;

     FUNC_MESS_BEGIN();
     if (PyGSL_GET_ARRAYTYPE(ainfo) != PyArray_DOUBLE){
	  line = __LINE__ - 1;
	  pygsl_error("Array request for vector or double is not a double array!",
		    __FILE__, line, GSL_ESANITY);
	  goto fail;
     }
     if (PyGSL_GET_TYPESIZE(ainfo)  != sizeof(double)){
	  line = __LINE__ - 1;
	  pygsl_error("Type size passed for vector or double is not of sizeof(double)!",
		    __FILE__, line, GSL_ESANITY);
	  goto fail;
     }
	  
     r = PyGSL_vector_check(src, -1, ainfo, NULL, info);
     if(r == NULL){
	  /* so try if it is a float ... */
	  double v;
	  /* was not an array, but lets see if it is a float, so lets clear the error .... */
	  PyErr_Clear();
	  FUNC_MESS("PyErr_Clear END");
	  if(PyGSL_PYFLOAT_TO_DOUBLE(src, &v, NULL) != GSL_SUCCESS){
	       line = __LINE__ - 1;
	       FUNC_MESS("=> NOT FLOAT");
	       goto fail;	    
	  }	 
	  FUNC_MESS("=> FLOAT");
	  r = (PyArrayObject *) PyGSL_New_Array(1, &dim, PyArray_DOUBLE);
	  if(r == NULL) {
	       line = __LINE__ - 2;
	       goto fail;
	  }
	  (*(double *)(r->data)) = v;
     }
     FUNC_MESS_END();
     return r;

 fail:
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);
     Py_XDECREF(r);
     FUNC_MESS("Fail");
     return NULL;
}


static PyArrayObject *
PyGSL_vector_check(PyObject *src, PyGSL_array_index_t size,
		   PyGSL_array_info_t ainfo,
		   PyGSL_array_index_t *stride, PyGSL_error_info * info)
{

     int line=-1, tries;
     PyArrayObject * a_array = NULL;
     int array_type, flag,  argnum, type_size;

	  
	  
     FUNC_MESS_BEGIN();
     array_type =  PyGSL_GET_ARRAYTYPE(ainfo);
     flag       =  PyGSL_GET_ARRAYFLAG(ainfo);
     type_size  =  PyGSL_GET_TYPESIZE(ainfo);
     argnum     =  PyGSL_GET_ARGNUM(ainfo);

     DEBUG_MESS(2, "Type requests: array_type %d, flag %d, c type_size %d, argnum %d",
		array_type, flag, type_size, argnum);
     /*
      * numpy arrays are which are non contiguous can have a stride which does
      * not match the basis type. In this case the conversion is repeated and 
      * a contiguous array is demanded.
      */
     for(tries = 0; tries <2; ++tries){
	  /* try fast conversion first */
#if 0
	  a_array = PyGSL_VECTOR_CONVERT(src, array_type, flag);
	  if(a_array !=  NULL && a_array->nd == 1 && 
	     (size == -1 || a_array->dimensions[0] == size)) {
	       /* good ... everything fine */
	       ;
#else
	  if(0) {
	       ;
#endif
	  } else {
	       /* lets try if that goes okay */
	       if(a_array != NULL){
		    /* Array could be allocated previously... */
		    Py_DECREF(a_array);
	       }
	       a_array = PyGSL_PyArray_prepare_gsl_vector_view(src, array_type, flag, size, argnum, info);
	       if(a_array == NULL){
		    line = __LINE__ - 2;
		    goto fail;
	       }
	  }
	  if(stride == NULL){
	       /* no one interested in the stride. so help yourself ... */
	       break; /* will return array */
	  }

	  if(PyGSL_STRIDE_RECALC(a_array->strides[0], type_size, stride) == GSL_SUCCESS){
	       /* everybody happy I hope! */
	       if((flag & PyGSL_CONTIGUOUS) == 1){
		    /* 
		     *  just a check to see ... could be disabled later on when
		     *  the code is tested a little
		     */
		    if(PyGSL_DEBUG_LEVEL() > 0){
			 if(*stride != 1){
			      line = __LINE__ - 1;
			      pygsl_error("Stride not one for a contiguous array!",
					filename, line, GSL_ESANITY);
			      goto fail;
			 } /* stride */
		    }/*debug level */
	       }/* contiguous arrays */
	       break; /* will return array */
	  }
     
     
	  /* Lets try to see if it makes sense to meake a copy */
	  DEBUG_MESS(2, "Stride recalc failed type size is  %ld, array stride[0] is %ld",
		     (long)type_size, (long)a_array->strides[0]);

	  if((flag & PyGSL_CONTIGUOUS) == 1){
	       line = __LINE__ - 1;
	       pygsl_error("Why does the stride recalc fail for a contigous array?",
			 filename, line, GSL_ESANITY);
	       goto fail;
	  } else {
	       /* keep the flags, but demand contiguous this time */
	       flag -= (flag & PyGSL_CONTIGUOUS);
	       assert(a_array);
	       Py_DECREF(a_array);
	       a_array = NULL;
	  }

     }/* number of tries */
     DEBUG_MESS(7, "Checking refcount src obj @ %p had %d cts and array @ %p has now %d cts", 
		(void *) src, src->ob_refcnt, (void *)a_array, a_array->ob_refcnt);
    	  
    /* handling failed stride recalc */
     FUNC_MESS_END();

     return a_array;
     
 fail:
     FUNC_MESS("Fail");
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);
     Py_XDECREF(a_array);
     return NULL;

}

/*
 * maximum 0xffffffff
 *
 * array_type = flag & 0x000000ff
 * type_size  = flag & 0x0000ff00
 * array_flag = flag & 0x00ff0000
 * argnum     = flag & 0xff000000
 */


static PyArrayObject *
PyGSL_matrix_check(PyObject *src, PyGSL_array_index_t size1, PyGSL_array_index_t size2, 
		   PyGSL_array_info_t ainfo, PyGSL_array_index_t *stride1, 
		   PyGSL_array_index_t *stride2, PyGSL_error_info * info)
{
     int line= __LINE__, tries, j;
     PyArrayObject * a_array = NULL;
     PyGSL_array_index_t * stride;
     int array_type, flag,  argnum, type_size;

     FUNC_MESS_BEGIN();

     array_type =  PyGSL_GET_ARRAYTYPE(ainfo);
     flag       =  PyGSL_GET_ARRAYFLAG(ainfo);
     type_size  =  PyGSL_GET_TYPESIZE(ainfo);
     argnum     =  PyGSL_GET_ARGNUM(ainfo);

     
     /*
      * numpy arrays are which are non contiguous can have a stride which does
      * not match the basis type. In this case the conversion is repeated and 
      * a contiguous array is demanded.
      */
     for(tries = 0; tries <2; ++tries){
#if 0	  
	  a_array = PyGSL_MATRIX_CONVERT(src, array_type, flag);
	  if(a_array !=  NULL && a_array->nd == 1 && 
	     (size1 == -1 || a_array->dimensions[0] == size1) &&
	     (size2 == -1 || a_array->dimensions[1] == size2)) 
#else
	  if(0)
#endif
	  {
	       /* good ... everything fine */
	       ;
	       
	  } else {
	       DEBUG_MESS(4, "PyGSL_MATRIX_CONVERT failed a_array = %p", a_array);
	       /* lets try if that goes okay */
	       if(a_array != NULL){
		    /* Array could be allocated previously... */
		    Py_DECREF(a_array);
	       }
	       a_array = PyGSL_PyArray_prepare_gsl_matrix_view(src, array_type, flag, size1, size2, argnum, info);
	       if(a_array == NULL){
		    line = __LINE__ - 2;
		    goto fail;
	       }
	  }
	  for(j = 0; j<2; ++j){
	       switch(j){
	       case 0:  stride = stride1; break;
	       case 1:  stride = stride2; break;
	       default: assert(0);
	       }

	       if(stride == NULL){
		    /* no one interested in the stride. lets check the other one ... */
		    continue;
	       }

	       if(PyGSL_STRIDE_RECALC(a_array->strides[j], type_size, stride) == GSL_SUCCESS){
		    /* everybody happy I hope! */
		    if((flag & PyGSL_CONTIGUOUS) == 1){
			 /* 
			  *  just a check to see ... could be disabled later on when
			  *  the code is tested a little
			  *
			  * 14. Oktober 2009: but only for the last dimension!
			  */
			 if(j == 1 && *stride != 1){
			      line = __LINE__ - 1;
			      DEBUG_MESS(6, "array stride %ld, type size %d, "
					 "found a stride of %ld", 
					 (long) a_array->strides[j], type_size, (long) *stride);
			      pygsl_error("Stride not one of a contiguous array!",
				   filename, line, GSL_ESANITY);
			      goto fail;
			 }
		    }
	       } else {         
		    /* Lets try to see if it makes sense to meake a copy */
		    DEBUG_MESS(2, "Stride recalc failed type size is  %ld, array stride[0] is %ld",
			       (long)type_size, (long)a_array->strides[j]);
		    
		    if((flag & PyGSL_CONTIGUOUS) == 1){
			 line = __LINE__ - 1;
			 pygsl_error("Why does the stride recalc fail for a contigous array?",
				   filename, line, GSL_ESANITY);
			 goto fail;
		    } else {
			 /* keep the flags, but demand contiguous this time */
			 DEBUG_MESS(3, "Matrix %p ot satisfying requests, trying this time contiguous", (void *) a_array);
			 flag -= (flag & PyGSL_CONTIGUOUS);
			 Py_DECREF(a_array);
			 a_array = NULL;
			 break;
		    }
	       } /* recalc stride or try again */    
	  } /* check strides */
     }/* number of tries */
     
    /* handling failed stride recalc */
     FUNC_MESS_END();
     return a_array;


 fail:
     PyGSL_add_traceback(NULL, filename, __FUNCTION__, line);
     Py_XDECREF(a_array);
     return NULL;
     
}


