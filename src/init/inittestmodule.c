#include <pygsl/intern.h>
#include <pygsl/utils.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>

static PyObject * module = NULL;

static PyObject*
PyGSL_test_GetPTR1(PyObject *self, PyObject *args)
{
	PyObject * tmp1=NULL;
	PyArrayObject * a = NULL;
	void *v =NULL, *ptr1=NULL, *vtest=NULL, *ptr2=NULL;
	char *cptr=NULL, *ctest;
	PyGSL_array_index_t stride = 0, dim=0, cnt;	
	int line = __LINE__;
	
	if(!PyArg_ParseTuple(args, "O", &tmp1)){
		line = __LINE__ - 1;
		goto fail;
	}

	a = PyGSL_matrix_check(tmp1, -1, -1, PyGSL_DARRAY_INPUT(1), NULL, NULL, NULL);
	if(a == NULL)
		goto fail;

	stride = PyArray_STRIDE(a, 0);
	dim = PyArray_DIM(a, 0);

	v = PyArray_DATA(a);
	cptr = PyArray_BYTES(a);
	ptr1 = PyArray_GETPTR1(a, 0);
	ptr2 = PyArray_GETPTR2(a, 0,0);
	DEBUG_MESS(2, "cnt = 0:  ptr1 = %p, data = %p, bytes = %p, ptr2=%p",
		   (void *)ptr1, (void *)v, (void *)cptr, ptr2);
	for(cnt = 0; cnt < dim; ++cnt){
		ptr1 = PyArray_GETPTR1(a, cnt);
		vtest = 
#ifdef __cplusplus 
		  /* in c mode I want to test if it exists */
		  (char *) 
#endif
		  v + stride * cnt;
		ctest = cptr + stride * cnt;

		if ((ptr1 == vtest) && (ptr1 == vtest)){	       	
			DEBUG_MESS(2, "cnt = %3ld:  ptr1 = data = bytes %p;",
				   cnt, ptr1);
		} else{
		DEBUG_MESS(2, "cnt = %3ld:  ptr1 = %p, data = %p  (%s), bytes = %p (%s)",
			   cnt, (void *)ptr1,  (void *)vtest,
			   ptr1 == vtest ? "TRUE" : "FALSE",
			   (void *)ctest,
			   ptr1 == ctest ? "TRUE" : "FALSE");
		}
	}
	
	Py_DECREF(a); a = NULL;
	Py_INCREF(Py_None);
	return Py_None;

  fail:
	Py_XDECREF(a);
	PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
	return NULL;

}
static PyObject*
PyGSL_test_new_array(PyObject *self, PyObject *args)
{
     PyGSL_array_index_t dimensions[2];
     PyObject * tmp1, *tmp2=NULL;
     PyArrayObject * a = NULL;
     int nd=1, line=-1;
     unsigned long dim1=0, dim2=0;

     FUNC_MESS_BEGIN();

     if(!PyArg_ParseTuple(args, "O|O", &tmp1, &tmp2)){
 	  line = __LINE__ - 1;
	  goto fail;
     }
     if(PyGSL_pylong_to_ulong(tmp1, &dim1, NULL) != GSL_SUCCESS){
	  goto fail;
     }
     dimensions[0] = dim1;
     if (tmp2 != NULL) {
	  nd = 2;
	  if(PyGSL_pylong_to_ulong(tmp2, &dim2, NULL) != GSL_SUCCESS){
	       goto fail;
	  }
	  dimensions[1] = dim2;	  
     }
     DEBUG_MESS(4, "Creating an array with %d dimensions dim1 %lu and dim 2 with %lu", nd, dim1, dim2);
     a = (PyArrayObject *) PyGSL_New_Array(nd, dimensions, NPY_DOUBLE);	  
     if (a == NULL)
	  goto fail;
     FUNC_MESS_END();     
     return (PyObject *) a;

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     return NULL;
}

static PyObject*
PyGSL_vector_refcount(PyObject *self, PyObject *args)
{
     PyObject * ret = NULL, *tmp;     
     PyArrayObject *a = NULL;
     int line = -1;
     long result;
     PyGSL_array_info_t info; 

     FUNC_MESS_BEGIN();
     if(!PyArg_ParseTuple(args, "O", &tmp)){
 	  line = __LINE__ - 1;
	  goto fail;
     }

     info = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS |PyGSL_INPUT_ARRAY, NPY_DOUBLE, 1, 1);
     info = PyGSL_DARRAY_CINPUT(1);
     a = PyGSL_vector_check(tmp, -1, info, NULL, NULL);
     if(a == NULL){
 	  line = __LINE__ - 1;
	  goto fail;
     }
     
     result = PyGSL_PY_ARRAY_GET_REFCNT(a);
     ret = PyLong_FromLong(result);
     Py_DECREF(a);
     FUNC_MESS_END();
     return ret;

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     Py_XDECREF(a);
     return NULL;
}


static PyObject*
PyGSL_test_vector_or_double(PyObject *self, PyObject *args)
{
     int line;
     PyObject *obj;
     PyArrayObject * a = NULL;
     FUNC_MESS_BEGIN();

     if(!PyArg_ParseTuple(args, "O", &obj)){
 	  line = __LINE__ - 1;
	  goto fail;
     }
     a = PyGSL_vector_or_double(obj, PyGSL_DARRAY_CINPUT(1), -1, NULL);     
     FUNC_MESS_END();
     return (PyObject *) a;

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
     Py_XDECREF(a);
     return NULL;
}


static char refcount_doc[] = "Accepts a vector and returns the refcount to the\n\
object\n";
static char new_array_doc[] = "create a vector or a matrix. Requires first\n\
 dimension plus optional a second dimension\n";
static char vector_or_double_doc[] = "Pass a vector or a double in. It will return\n\
a Python Array Object\n";

static char test_getptr1_doc[] = "Prints the offset calculated for the different cols for a matrix using stride or GetPtr1\n";

static PyMethodDef inittestMethods[] = {
     {"vector_refcount", PyGSL_vector_refcount, METH_VARARGS, refcount_doc},
     {"new_array", PyGSL_test_new_array, METH_VARARGS, new_array_doc},
     {"vector_or_double", PyGSL_test_vector_or_double, METH_VARARGS, vector_or_double_doc},
     {"test_getptr1",    PyGSL_test_GetPTR1, METH_VARARGS, test_getptr1_doc},
     {NULL,     NULL, 0, NULL}        /* sentinel */
};  


#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.inittest",
        NULL,
        -1,
        inittestMethods,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif 


#ifdef __cplusplus
extern "C"
#endif

#ifdef PyGSL_PY3K
PyObject *PyInit_inittest(void)
#define RETVAL m
#else
#define RETVAL
DL_EXPORT(void) initinittest(void)
#endif
{
  PyObject *m = NULL;

#ifdef PyGSL_PY3K
  m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
  m = Py_InitModule("pygsl.inittest", inittestMethods);
#endif /* PyGSL_PY3K */

  FUNC_MESS_BEGIN();
  module = m;
  init_pygsl();

  FUNC_MESS_END();
  return RETVAL;
}
