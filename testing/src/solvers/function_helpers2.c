/* 1. A_n O -> A_p  */
PyGSL_API_EXTERN int
PyGSL_function_wrap_Op_On(const gsl_vector * x, gsl_vector *f, PyObject *callback, 
			PyObject * arguments, int n, int p, const char *c_func_name)
{
     PyArrayObject *a_array = NULL;
     PyObject *object=NULL, *arglist=NULL;
     PyGSL_error_info  info;
     /* the line number to appear in the traceback */ 
     int trb_lineno = -1;
     FUNC_MESS_BEGIN();    

     /* Do I need to copy the array ??? */
     a_array = PyGSL_copy_gslvector_to_pyarray(x);
     if (a_array == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
     }

     arglist = Py_BuildValue("(OO)", a_array, arguments);
     if(DEBUG > 2){
	  fprintf(stderr, "callback = %p, arglist = %p\n", callback, arglist);
     }
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("    Call Python Object BEGIN");
     object  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     info.callback = callback;
     info.message  = c_func_name;
     info.error_description = NULL;
     info.argnum = 0;
     if(PyGSL_CHECK_PYTHON_RETURN(object, 1, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     info.argnum = 1;
     if(PyGSL_copy_pyarray_to_gslvector(f, object, p, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }     
     Py_DECREF(arglist);    
     Py_DECREF(a_array);
     Py_DECREF(object);    
     FUNC_MESS_END();
     return GSL_SUCCESS;
 fail:
     PyGSL_add_traceback(NULL, __FILE__, c_func_name, trb_lineno);
     FUNC_MESS("Failure");
     Py_XDECREF(arglist);
     Py_XDECREF(a_array);
     Py_XDECREF(object);
     return GSL_FAILURE;
}


/* 2. A_n O -> A_n_p */
int
PyGSL_function_wrap_Op_Opn(const gsl_vector * x, gsl_matrix *f, PyObject *callback,
			   PyObject *arguments, int n, int p, const char * c_func_name)
{

     PyArrayObject *a_array = NULL;
     PyObject *result = NULL, *arglist=NULL;
     PyGSL_error_info  info;
     /* the line number to appear in the traceback */ 
     int trb_lineno = -1;

     FUNC_MESS_BEGIN();    

     /* Do I need to copy the array ??? */
     a_array = PyGSL_copy_gslvector_to_pyarray(x);
     if (a_array == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
     }

     arglist = Py_BuildValue("(OO)", a_array, arguments);
     if(DEBUG > 2){
	  fprintf(stderr, "callback = %p, arglist = %p\n", callback, arglist);
     }
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("    Call Python Object BEGIN");
     result  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     info.callback = callback;
     info.message  = c_func_name;
     if(PyGSL_CHECK_PYTHON_RETURN(result, 1, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     info.argnum = 1;
     if(PyGSL_copy_pyarray_to_gslmatrix(f, result, n, p, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     Py_DECREF(arglist);    
     Py_DECREF(a_array);
     FUNC_MESS_END();
     return GSL_SUCCESS;
 fail:
     PyGSL_add_traceback(NULL, __FILE__, c_func_name, trb_lineno);
     FUNC_MESS("Failure");
     Py_XDECREF(arglist);
     Py_XDECREF(a_array);
     return GSL_FAILURE;
}


/*
 * Pass a NULL pointer for result 2, if not needed.
 */
/* 4. A_n O   ->  d (A_n) */
PyGSL_API_EXTERN int
PyGSL_function_wrap_On_O(const gsl_vector * x, PyObject *callback,
			PyObject *arguments, double *result1,
			gsl_vector *result2, int n, const char * c_func_name)
{

     PyArrayObject *a_array = NULL;
     PyObject *object=NULL, *arglist=NULL, *tmp=NULL;
     PyGSL_error_info  info;
     /* the line number to appear in the traceback */ 
     int trb_lineno = -1;

     FUNC_MESS_BEGIN();    

     a_array = PyGSL_copy_gslvector_to_pyarray(x);
     if (a_array == NULL){
	  trb_lineno = __LINE__ - 2;	       
	  goto fail;
     }

     arglist = Py_BuildValue("(OO)", a_array, arguments);
     if(DEBUG > 2){
	  fprintf(stderr, "\tcallback = %p, arglist = %p\n", callback, arglist);
     }
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("\tCall Python Object BEGIN");
     object  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("\tCall Python Object END");

     info.callback = callback;
     info.message  = c_func_name;	  
     FUNC_MESS(" Checking Return Values");
     if(result2 == NULL){
	  if(PyGSL_CHECK_PYTHON_RETURN(object, 1, &info) != GSL_SUCCESS){
	       trb_lineno = __LINE__ - 1;
	       goto fail;
	  }
	  tmp = object;
     }else{
	  if(PyGSL_CHECK_PYTHON_RETURN(object, 2, &info) != GSL_SUCCESS){
	       trb_lineno = __LINE__ - 1;
	       goto fail;
	  }
	  tmp = PyTuple_GET_ITEM(object, 0);
     }
     FUNC_MESS("\tExtracting data from function");
     info.argnum = 1;
     if(PyGSL_PYFLOAT_TO_DOUBLE(tmp, result1, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     if(DEBUG>2){
       fprintf(stderr,"\tresult1 = %f\n", *result1);
     }
     
     if(result2 != NULL){
	  FUNC_MESS("\tCOPYING df");
	  tmp = PyTuple_GET_ITEM(object, 1);
	  info.argnum = 2;
	  if(PyGSL_copy_pyarray_to_gslvector(result2, tmp, n, &info)!= GSL_SUCCESS){
	       trb_lineno = __LINE__ - 1;
	       goto fail;
	  }
     }
     Py_DECREF(arglist);    
     Py_DECREF(a_array);
     Py_DECREF(object);    
     FUNC_MESS_END();
     return GSL_SUCCESS;
 fail:
     FUNC_MESS("Failure");
     PyGSL_add_traceback(NULL, __FILE__, c_func_name, trb_lineno);
     Py_XDECREF(arglist);
     Py_XDECREF(a_array);
     Py_XDECREF(object);
     FUNC_MESS("Returning failure !");
     return GSL_FAILURE;
}

/* 5. A_n O -> A_n A_n_p */
PyGSL_API_EXTERN int
PyGSL_function_wrap_Op_On_Opn(const gsl_vector * x, gsl_vector *f1, gsl_matrix *f2, PyObject *callback,
			   PyObject *arguments, int n, int p, const char * c_func_name)
{

     PyArrayObject *a_array = NULL;
     PyObject *object = NULL, *r1=NULL, *r2 = NULL, *arglist=NULL;
     PyGSL_error_info  info;
     /* the line number to appear in the traceback */ 
     int trb_lineno = -1;

     FUNC_MESS_BEGIN();    

     /* Do I need to copy the array ??? */
     a_array = PyGSL_copy_gslvector_to_pyarray(x);
     if (a_array == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
     }

     arglist = Py_BuildValue("(OO)", a_array, arguments);
     if(DEBUG > 2){
	  fprintf(stderr, "callback = %p, arglist = %p\n", callback, arglist);
     }
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("    Call Python Object BEGIN");
     object  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     info.callback = callback;
     info.message  = c_func_name;	  
     if(PyGSL_CHECK_PYTHON_RETURN(object, 2, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     r1 = PyTuple_GET_ITEM(object, 0);
     r2 = PyTuple_GET_ITEM(object, 1);
     info.argnum = 1;
     if(PyGSL_copy_pyarray_to_gslvector(f1, r1, n, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  FUNC_MESS("   Could not convert f to gsl vector!");
	  goto fail;
     }
     info.argnum = 2;
     if(PyGSL_copy_pyarray_to_gslmatrix(f2, r2, n, p, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  FUNC_MESS("   Could not convert df to gsl matrix!");
	  goto fail;
     }
     Py_DECREF(arglist);    
     Py_DECREF(a_array);
     Py_DECREF(object);    
     FUNC_MESS_END();
     return GSL_SUCCESS;
 fail:
     FUNC_MESS("Failure");
     PyGSL_add_traceback(NULL, __FILE__, c_func_name, trb_lineno);
     Py_XDECREF(arglist);
     Py_XDECREF(a_array);
     Py_XDECREF(object);
     return GSL_FAILURE;
}


/* 6. A_n A_n O -> A_n */
PyGSL_API_EXTERN int
PyGSL_function_wrap_OnOn_On(const gsl_vector * x, const gsl_vector *v, gsl_vector *hv, PyObject *callback,
			     PyObject *arguments, int n, const char * c_func_name)
{

     PyArrayObject *x_a = NULL, *v_a = NULL;
     PyObject *object = NULL, *arglist=NULL;
     PyGSL_error_info  info;

     /* the line number to appear in the traceback */ 
     int trb_lineno = -1;

     FUNC_MESS_BEGIN();    

     x_a = PyGSL_copy_gslvector_to_pyarray(x);
     if (x_a == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
     }

     v_a = PyGSL_copy_gslvector_to_pyarray(v);
     if (v_a == NULL){
	  trb_lineno = __LINE__ - 2;
	  goto fail;
     }

     arglist = Py_BuildValue("(OOO)", x_a, v_a, arguments);
     if(DEBUG > 2){
	  fprintf(stderr, "callback = %p, arglist = %p\n", callback, arglist);
     }
     assert(arglist != NULL);
     assert(callback != NULL);
     FUNC_MESS("    Call Python Object BEGIN");
     object  = PyEval_CallObject(callback, arglist);
     FUNC_MESS("    Call Python Object END");

     info.callback = callback;
     info.message  = c_func_name;	  
     if(PyGSL_CHECK_PYTHON_RETURN(object, 1, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  goto fail;
     }
     info.argnum = 1;
     if(PyGSL_copy_pyarray_to_gslvector(hv, object, n, &info) != GSL_SUCCESS){
	  trb_lineno = __LINE__ - 1;
	  FUNC_MESS("   Could not convert hv to gsl vector!");
	  goto fail;
     }
     Py_DECREF(arglist);    
     Py_DECREF(x_a);
     Py_DECREF(v_a);
     Py_DECREF(object);    
     FUNC_MESS_END();
     return GSL_SUCCESS;

 fail:
     FUNC_MESS("Failure");
     PyGSL_add_traceback(NULL, __FILE__, c_func_name, trb_lineno);
     Py_XDECREF(arglist);
     Py_XDECREF(x_a);
     Py_XDECREF(v_a);
     Py_XDECREF(object);
     return GSL_FAILURE;
}
