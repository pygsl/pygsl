#include "statmodule.h"

static void * __PyGSL_STATISTICS_API[8] = {NULL, NULL, NULL, NULL, NULL, NULL,
					   NULL, NULL};


static PyObject*
PyGSL_statistics_d_A(PyObject *self, PyObject *args,
		     double (*pointer)(const void *, size_t, size_t),
		     int array_type, int basis_type_size)
{
    PyObject *input = NULL; 
    PyArrayObject *data; 
    double result;
    int stride=1, n; 
    
    FUNC_MESS_BEGIN();
    if(!(PyArg_ParseTuple(args, "O", &input))) 
	return NULL;

    data = PyGSL_PyArray_PREPARE_gsl_vector_view(input, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, -1, 1, NULL);
    if(data == NULL) 
	return NULL;

    
    if(PyGSL_STRIDE_RECALC(data->strides[0], basis_type_size, &stride) != GSL_SUCCESS){
	 Py_XDECREF(data); 
	 return NULL;
    }

    n = data->dimensions[0];
    result = pointer((void *)data->data, (size_t) stride, (size_t) n);
    Py_DECREF(data);
    FUNC_MESS_END();
    return PyFloat_FromDouble(result);
}


static PyObject*
PyGSL_statistics_l_A(PyObject *self, PyObject *args, 
		     size_t (*pointer)(const void *, size_t, size_t),
		     int array_type, int basis_type_size)
{
    PyObject *input = NULL; 
    PyArrayObject *data; 
    long result;
    int stride=1, n; 
    
    if(!(PyArg_ParseTuple(args, "O", &input))) 
	return NULL;

    data = PyGSL_PyArray_PREPARE_gsl_vector_view(input, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, -1, 1, NULL);
    if(data == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data->strides[0], basis_type_size, &stride) != GSL_SUCCESS){
	 Py_XDECREF(data); 
	 return NULL;
    }


    n = data->dimensions[0]; 
    result = pointer((void *)data->data, (size_t) stride, (size_t) n);
    Py_DECREF(data);
    return PyInt_FromLong(result);
}


static PyObject*
PyGSL_statistics_d_Ad(PyObject *self, PyObject *args, 
		      double (*pointer)(const void *, size_t, size_t, double),
		      int array_type, int basis_type_size)
{
    PyObject *input = NULL; 
    PyArrayObject *data; 
    double result, mean;
    size_t stride=1, n; 
    
    if(!(PyArg_ParseTuple(args, "Od", &input, &mean))) 
	return NULL;

    data = PyGSL_PyArray_PREPARE_gsl_vector_view(input, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, -1, 1, NULL);
    if(data == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data->strides[0], basis_type_size, &stride) != GSL_SUCCESS){
	 Py_XDECREF(data); 
	 return NULL;
    }


    n = data->dimensions[0];
    result = pointer((void *)data->data, (size_t) stride, (size_t) n, mean);
    Py_DECREF(data);
    return PyFloat_FromDouble(result);
}

static PyObject*
PyGSL_statistics_d_AA(PyObject *self, PyObject *args, 
		      double (*pointer)(const void *, size_t,const void *, size_t, size_t),
		      int array_type, int basis_type_size)
{ 
    PyObject *input1 = NULL, *input2 = NULL;
    PyArrayObject *data1=NULL, *data2=NULL;
    double result;
    int stride1=1, stride2=1, n1;

    FUNC_MESS_BEGIN();
    if(!(PyArg_ParseTuple(args, "OO", &input1, &input2))) 
	return NULL;

    data1 = PyGSL_PyArray_PREPARE_gsl_vector_view(input1, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, -1, 1, NULL);
    if(data1 == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data1->strides[0], basis_type_size, &stride1) != GSL_SUCCESS){
	 goto fail;
    }

    n1 = data1->dimensions[0];


    data2 = PyGSL_PyArray_PREPARE_gsl_vector_view(input1, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, n1, 1, NULL);
    if(data2 == NULL){
	 goto fail;
    }

    if(PyGSL_STRIDE_RECALC(data2->strides[0], basis_type_size, &stride2) != GSL_SUCCESS){
	 goto fail;
    }    
    result = pointer((void *)data1->data, (size_t) stride1, (void *)data2->data, (size_t) stride2,  (size_t) n1);
    Py_DECREF(data1); 
    Py_DECREF(data2); 
    FUNC_MESS_END();
    return PyFloat_FromDouble(result); 
 fail:    
    FUNC_MESS("Fail");
    Py_XDECREF(data1);
    Py_XDECREF(data2);
    return NULL;
}


static PyObject*
PyGSL_statistics_d_AAd(PyObject *self, PyObject *args, 
		       double (*pointer)(const void *, size_t,const void *, size_t, size_t, double),
		       int array_type, int basis_type_size)
{ 
    PyObject *input1 = NULL, *input2 = NULL;
    PyArrayObject *data1=NULL, *data2=NULL;
    double result, mean;
    size_t stride1=1, stride2=1;
    size_t n1;
 
    if(!(PyArg_ParseTuple(args, "OOd", &input1, &input2, &mean))) 
	return NULL;

    data1 = PyGSL_PyArray_PREPARE_gsl_vector_view(input1, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, -1, 1, NULL);
    if(data1 == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data1->strides[0], basis_type_size, &stride1) != GSL_SUCCESS){
	 goto fail;
    }

    n1 = data1->dimensions[0];

    data2 = PyGSL_PyArray_PREPARE_gsl_vector_view(input1, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, n1, 1, NULL);
    if(data2 == NULL){
	Py_XDECREF(data1); 
	return NULL;
    }

    if(PyGSL_STRIDE_RECALC(data2->strides[0], basis_type_size, &stride2) != GSL_SUCCESS){
	 goto fail;
    }

    result = pointer((void *)data1->data, (size_t) stride1, (void *)data2->data, (size_t) stride2, (size_t) n1, mean);
    Py_DECREF(data1); 
    Py_DECREF(data2); 
    return PyFloat_FromDouble(result); 
 fail:
    Py_XDECREF(data1);
    Py_XDECREF(data2);
    return NULL;
}



static PyObject*
PyGSL_statistics_d_AAdd(PyObject *self, PyObject *args, 
			double (*pointer)(const void *, size_t,const void *, size_t, size_t, double, double),
			int array_type, int basis_type_size)
{ 
    PyObject *input1 = NULL, *input2 = NULL;
    PyArrayObject *data1=NULL, *data2=NULL;
    double result, mean1, mean2;
    size_t stride1=1, stride2=1;
    size_t n1;
 
    if(!(PyArg_ParseTuple(args, "OOdd", &input1, &input2, &mean1, &mean2))) 
	return NULL;

    data1 = PyGSL_PyArray_PREPARE_gsl_vector_view(input1, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, -1, 1, NULL);
    if(data1 == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data1->strides[0], basis_type_size, &stride1) != GSL_SUCCESS){
	 goto fail;
    }

    n1 = data1->dimensions[0];

    data2 = PyGSL_PyArray_PREPARE_gsl_vector_view(input1, array_type, PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY, n1, 1, NULL);
    if(data2 == NULL){
	Py_XDECREF(data1); 
	return NULL;
    }

    if(PyGSL_STRIDE_RECALC(data2->strides[0], basis_type_size, &stride2) != GSL_SUCCESS){
	 goto fail;
    }

    result = pointer((void *)data1->data, (size_t) stride1, (void *)data2->data, (size_t) stride2, (size_t) n1, mean1, mean2);
    Py_DECREF(data1); 
    Py_DECREF(data2); 
    return PyFloat_FromDouble(result); 
 fail:
    Py_XDECREF(data1);
    Py_XDECREF(data2);
    return NULL;
}



static PyObject*
PyGSL_statistics_d_Add(PyObject *self, PyObject *args, 
		       double (*pointer)(const void *, size_t, size_t, double, double),
		       int array_type, int basis_type_size)
{
    PyObject *input = NULL; 
    PyArrayObject *data; 
    double result, mean1, mean2;
    size_t stride=1, n; 
    
    if(!(PyArg_ParseTuple(args, "Odd", &input, &mean1, &mean2))) 
	return NULL;

    data = PyGSL_PyArray_PREPARE_gsl_vector_view(input, array_type, 0, -1, 1, NULL);
    if(data == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data->strides[0], basis_type_size, &stride) != GSL_SUCCESS){
	 Py_XDECREF(data); 
	 return NULL;
    }


    n = data->dimensions[0];
    result = pointer((void *)data->data, (size_t) stride, (size_t) n, mean1, mean2);
    Py_DECREF(data);
    return PyFloat_FromDouble(result);
}


static PyObject*
PyGSL_statistics_ll_A(PyObject *self, PyObject *args, 
		      void (*pointer)(size_t *, size_t *, const void *, size_t, size_t),
		      int array_type, int basis_type_size)
{
    PyObject *input = NULL; 
    PyArrayObject *data; 
    size_t result1, result2;
    size_t stride=1, n; 
    
    if(!(PyArg_ParseTuple(args, "O", &input))) 
	return NULL;

    data = PyGSL_PyArray_PREPARE_gsl_vector_view(input, array_type, 0, -1, 1, NULL);
    if(data == NULL) 
	return NULL;

    if(PyGSL_STRIDE_RECALC(data->strides[0], basis_type_size, &stride) != GSL_SUCCESS){
	 Py_XDECREF(data); 
	 return NULL;
    }


    n = data->dimensions[0];
    pointer(&result1, &result2, (void *)data->data, (size_t) stride, (size_t) n);
    Py_DECREF(data);
    return Py_BuildValue("ll", (long) result1, (long) result2);
}

static void 
set_api_pointer(void)
{

     FUNC_MESS_BEGIN();

    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_A_NUM]    = (void *) PyGSL_statistics_d_A; 
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_l_A_NUM]    = (void *) PyGSL_statistics_l_A;
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_Ad_NUM]   = (void *) PyGSL_statistics_d_Ad;
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_AA_NUM]   = (void *) PyGSL_statistics_d_AA;
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_AAd_NUM]  = (void *) PyGSL_statistics_d_AAd;
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_AAdd_NUM] = (void *) PyGSL_statistics_d_AAdd;
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_Add_NUM]  = (void *) PyGSL_statistics_d_Add;
    __PyGSL_STATISTICS_API[PyGSL_STATISTICS_ll_A_NUM]   = (void *) PyGSL_statistics_ll_A;
     PyGSL_STATISTICS_API = __PyGSL_STATISTICS_API;
     DEBUG_MESS(2, "__PyGSL_STATISTICS_API @ %p\n", (void *) __PyGSL_STATISTICS_API);
     FUNC_MESS_END();
}

static PyMethodDef _statMethods[] = 
{
     {	NULL,     NULL} /* Sentinel */
};
                                                                                                                                                                         

/* initialization */

DL_EXPORT(void) init_stat(void)
{
     PyObject *api, *dict, *m;

     FUNC_MESS_BEGIN();

     m = Py_InitModule("_stat", _statMethods);
     if(m == NULL)
	  goto fail;

     DEBUG_MESS(2, "Importing Array!", NULL);
     import_array();
   
     DEBUG_MESS(2, "Importing pygsl!", NULL);
     init_pygsl();


     dict = PyModule_GetDict(m);
     if(dict == NULL)
	  goto fail;

   
     set_api_pointer();
   
     DEBUG_MESS(2, "PyGSL_STATISTICS_API @ %p\n", (void *) PyGSL_STATISTICS_API);
     api = PyCObject_FromVoidPtr((void *) PyGSL_STATISTICS_API, NULL);
     assert(api);
     if (PyDict_SetItemString(dict, "_PYGSL_STATISTICS_API", api) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not add  _PYGSL_STATISTICS_API!");
	  goto fail;
     }
     FUNC_MESS_END();
     return;
 fail:
     FUNC_MESS("Failed");
     if(!PyErr_Occurred()){
	  PyErr_SetString(PyExc_ImportError, "I could not init statistics._stat module!");
     }

}

