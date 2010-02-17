/* -*- C -*- */
/**
 * Author : Pierre Schnizer
 * Date: January 2003
 */
#include <pygsl/function_helpers.h>
#include <pygsl/error_helpers.h>



/* 1. A_n O -> A_p  */
int
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
int
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
int
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

/* -------------------------------------------------------------------------
      Register Python Call backs
      
      Generic Helper Functions
   ------------------------------------------------------------------------ */
/* Callbacks using one function */
callback_function_params *
PyGSL_convert_to_generic_function(PyObject *object, int *size, int *size2, const char * c_func_name)
{
     PyObject *func=NULL, *args=NULL;
     callback_function_params *params;

     FUNC_MESS_BEGIN();
     /*
      * check perhaps if SWIG pointer to allow call back to a real C 
      * function ? 
      */
     if(size == NULL && size2 == NULL){
	  if(!(PyArg_ParseTuple(object, "OO", &func, &args))){
	       PyErr_SetString(PyExc_ValueError, 
			       "I expect a tuple as input for the gsl_function!\n"
			       "The first item is the function and the second item it's "
			       "additional arguments.");
	       return NULL;
	  }
     }
     else if(size2 == NULL)
     {
	  if(!(PyArg_ParseTuple(object, "OOi", &func, &args, size))){
	       PyErr_SetString(PyExc_ValueError, 
			       "I expect a tuple as input for the gsl_function!\n"
			       "The first item is the function, the second item it's "
			       "additional arguments and the third the size of the problem.");
	       return NULL;
	  }
	  if(DEBUG>2){
	       fprintf(stderr, "The size of the problem = %d\n", *size);
	  }
     }
     else
     {
	  if(!(PyArg_ParseTuple(object, "OOii", &func, &args, size, size2))){
	       PyErr_SetString(PyExc_ValueError, 
			       "I expect a tuple as input for the gsl_function!\n"
			       "The first item is the function, the second item it's "
			       "additional arguments, the third the number of parameters "
			       "and the forth the size of the problem.");
	       return NULL;
	  }
	  if(DEBUG>2){
	       fprintf(stderr, "The size of the problem = %d %d\n", *size, *size2);
	  }
     }
     if(!(PyCallable_Check(func))){
	  PyErr_SetString(PyExc_TypeError, 
			  "The first item of the tuple for the gsl_function"
			  "must be callable");
	  return NULL;
     }
     if ((params = (callback_function_params *) malloc(sizeof(callback_function_params))) == NULL){
	  PyErr_NoMemory();
	  return NULL;
     }
     Py_INCREF(func);
     Py_INCREF(args);
  
     params->function = func;
     params->arguments = args;
     params->c_func_name = c_func_name;
     params->buffer_is_set = 0;
     FUNC_MESS_END();
     return params;
}

/* Callbacks using 3  functions */
callback_function_params_fdf *
PyGSL_convert_to_generic_function_fdf(PyObject *object, int *size, int *size2, 
				const char * c_f_func_name, const char * c_df_func_name, const char * c_fdf_func_name)
{
     PyObject *f = NULL, *df = NULL, *fdf = NULL, *args = NULL;
     callback_function_params_fdf * params = NULL;
     int tmp;

     FUNC_MESS_BEGIN();
     if ((params = (callback_function_params_fdf *) malloc(sizeof(callback_function_params_fdf))) == NULL){
	  PyErr_NoMemory();
	  return NULL;
     }
     /*
      * check perhaps if SWIG pointer to allow call back to a real C 
      * function ? 
      */
     if(size == NULL && size2 == NULL){
       if(!(PyArg_ParseTuple(object, "OOOO:setting functions for gsl_function", &f, &df, &fdf, &args))){
	 PyErr_SetString(PyExc_ValueError, 
			 "I expect a tuple as input for the gsl_function_fdf!\n"
			 "The first 3 items are functions and the last item it's"
			 "additional arguments.");
	 return NULL;
       }
     } else if(size2  == NULL) {
       if(!(PyArg_ParseTuple(object, "OOOOi:setting parameters for gsl_function_fdf", &f, &df, &fdf, &args, &tmp))){
	 PyErr_SetString(PyExc_ValueError, 
			 "I expect a tuple as input for the gsl_function_fdf!\n"
			 "The first 3 items are functions the 4 item it's"
			 "additional arguments. The 5 is the size of the problem");
	 return NULL;
       }
       *size = tmp;
     } else {
	  if (!(PyArg_ParseTuple(object, "OOOOii:setting parameters for gsl_function_fdf", 
				 &f, &df, &fdf, &args, size, size2))){
	       PyErr_SetString(PyExc_ValueError, 
			       "I expect a tuple as input for the gsl_function_fdf!\n"
			       "The first 3 items are functions the 4 item it's "
			       "additional arguments. The 5 is the number of parameters " 
			       "and the 6 is the size of the problem");
	       return NULL;
	  }
     }
     if(!(PyCallable_Check(f))){
	  PyErr_SetString(PyExc_TypeError, 
			  "The first item of the tuple for the gsl_function"
			  "must be callable");
	  return NULL;
     }
     if(!(PyCallable_Check(df))){
	  PyErr_SetString(PyExc_TypeError, 
			  "The second item of the tuple for the gsl_function"
			  "must be callable");
	  return NULL;
     }
     if(!(PyCallable_Check(fdf))){
	  PyErr_SetString(PyExc_TypeError, 
			  "The third item of the tuple for the gsl_function"
			  "must be callable");
	  return NULL;
     }
     assert(f!=NULL);
     assert(df!=NULL);
     assert(fdf!=NULL);
     assert(args!=NULL);
     Py_INCREF(f);
     Py_INCREF(df);
     Py_INCREF(fdf);
     Py_INCREF(args);
     params->f = f;
     params->df = df;
     params->fdf = fdf;
     params->c_f_func_name = c_f_func_name;
     params->c_df_func_name = c_df_func_name;
     params->c_fdf_func_name = c_fdf_func_name;
     params->arguments = args;
     params->buffer_is_set = 0;
     FUNC_MESS_END();
     return params;
}

void 
PyGSL_params_free(callback_function_params *p)
{

	DEBUG_MESS(10, "Freeing callback function parameters %p", p);
	if(p != NULL){
		assert(p->function != NULL);
		assert(p->arguments != NULL);
		Py_DECREF(p->function);
		Py_DECREF(p->arguments);
		free(p);
	}else{		
		DEBUG_MESS(2, "f->params = %p", (void *) p);
	}	
  
}

void 
PyGSL_params_free_fdf(callback_function_params_fdf *p)
{

	DEBUG_MESS(2, "Freeing callback function parameters %p", p);
	if(p != NULL){
		assert(p->f != NULL);
		assert(p->df != NULL);
		assert(p->fdf != NULL);
		assert(p->arguments != NULL);
		Py_DECREF(p->f);
		Py_DECREF(p->df);
		Py_DECREF(p->fdf);
		Py_DECREF(p->arguments);
		free(p);
	} else {
		if(DEBUG){
			fprintf(stderr,"In %s at line % d,  f->params = %p\n", 
				__FUNCTION__,__LINE__, (void *)p);
		}
	}
}

/* -------------------------------------------------------------------------
      Register Python Call backs
      
      Type Specific Functions
   ------------------------------------------------------------------------ */
/* -------------------------------------------------------------------------
   Special Helper Functions
   ------------------------------------------------------------------------ */

double 
PyGSL_function_wrap(double x, void * params)
{
     int flag;
     double result;
     callback_function_params *p = NULL;

     p = (callback_function_params *) params;
     assert(p->function != NULL);
     assert(p->arguments != NULL);
     flag = PyGSL_function_wrap_helper(x, &result, NULL, p->function, p->arguments, p->c_func_name);
     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1) {
	       FUNC_MESS("\t\t Using jump buffer");
	       longjmp(p->buffer, flag);
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       result = gsl_nan();
	  }
     }
     return result;
}
double 
PyGSL_function_wrap_f(double x, void * params)
{
     int flag;
     double result;
     callback_function_params_fdf *p = NULL;

     p = (callback_function_params_fdf *) params;
     flag =  PyGSL_function_wrap_helper(x, &result, NULL, p->f, p->arguments, p->c_f_func_name);

     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       result = gsl_nan();
	  }
     }

     return result;

}
double 
PyGSL_function_wrap_df(double x, void * params)
{
     int flag;
     double result;

     callback_function_params_fdf *p = NULL;
     p = (callback_function_params_fdf *) params;
     flag = PyGSL_function_wrap_helper(x, &result, NULL, p->df, p->arguments, p->c_df_func_name);

     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       result = gsl_nan();
	  }
     }

     return result;

}
void
PyGSL_function_wrap_fdf(double x,  void * params, double *f, double * fdf)
{
     int flag;
     callback_function_params_fdf *p = NULL;
     p = (callback_function_params_fdf *) params;

     flag =  PyGSL_function_wrap_helper(x, f, fdf, p->fdf, p->arguments, p->c_fdf_func_name);

     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       FUNC_MESS("\t\t Using jump buffer");
	       longjmp(p->buffer, flag);
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       *f = gsl_nan();
	       *fdf = gsl_nan();
	  }
     }

}

gsl_function *  
PyGSL_convert_to_gsl_function(PyObject * object)
{
     gsl_function * f = NULL;
     callback_function_params *params;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function(object, NULL, NULL, pygsl_gsl_function);
     if(params == NULL){
	  return NULL;
     }
     if ((f = (gsl_function *) malloc(sizeof(gsl_function))) == NULL){
	  PyGSL_params_free(params);
	  PyErr_NoMemory();
	  return NULL;
     }
     f->function = PyGSL_function_wrap;
     f->params   = params; 
     FUNC_MESS_END();
     return f;
}


gsl_function_fdf *  
PyGSL_convert_to_gsl_function_fdf(PyObject * object)
{

     gsl_function_fdf * F = NULL;
     callback_function_params_fdf *params;
  
     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function_fdf(object, NULL, NULL, 
					      pygsl_gsl_f_function, pygsl_gsl_df_function, pygsl_gsl_fdf_function);
     if(params == NULL){
	  return NULL;
     }
     if ((F = (gsl_function_fdf *) malloc(sizeof(gsl_function_fdf))) == NULL){
	  PyGSL_params_free_fdf(params);
	  PyErr_NoMemory();
	  return NULL;
     }
     F->f = PyGSL_function_wrap_f;
     F->df = PyGSL_function_wrap_df;
     F->fdf = PyGSL_function_wrap_fdf;    
     F->params   = params;
     FUNC_MESS_END();
     return F;
}


int 
PyGSL_multiroot_function_wrap(const gsl_vector *x, void *params, gsl_vector *f)
{
     callback_function_params *p;
     p = (callback_function_params *) params;
     FUNC_MESS_BEGIN();
     if(DEBUG > 2){
       gsl_vector_fprintf(stderr, x, "x = %d");
     }
     return PyGSL_function_wrap_Op_On(x, f, p->function, p->arguments, x->size, x->size, p->c_func_name);
}
int 
PyGSL_multiroot_function_wrap_f(const gsl_vector *x, void *params, gsl_vector *f)
{
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params;

     return PyGSL_function_wrap_Op_On(x, f, p->f, p->arguments, x->size, x->size, p->c_f_func_name);
}
int 
PyGSL_multiroot_function_wrap_df(const gsl_vector *x, void *params, gsl_matrix *J)
{
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params;
     return PyGSL_function_wrap_Op_Opn(x, J, p->df, p->arguments, x->size, x->size, p->c_df_func_name);
}
int 
PyGSL_multiroot_function_wrap_fdf(const gsl_vector *x, void *params, gsl_vector *f, gsl_matrix *J)
{
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params;
     return PyGSL_function_wrap_Op_On_Opn(x, f, J, p->fdf, p->arguments, x->size, x->size, p->c_fdf_func_name);
}
 
gsl_multiroot_function *  
PyGSL_convert_to_gsl_multiroot_function(PyObject * object)
{
     gsl_multiroot_function * f = NULL;
     callback_function_params *params;
     int size;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function(object, &size, NULL, pygsl_multiroot_function);
     if(params == NULL){
	  return NULL;
     }
     if ((f = (gsl_multiroot_function *) malloc(sizeof(gsl_multiroot_function))) == NULL){
	  PyGSL_params_free(params);
	  PyErr_NoMemory();
	  return NULL;
     }

     f->f = PyGSL_multiroot_function_wrap;
     f->n = size;
     f->params   = params; 
     FUNC_MESS_END();
     return f;
}


gsl_multiroot_function_fdf *  
PyGSL_convert_to_gsl_multiroot_function_fdf(PyObject * object){

     gsl_multiroot_function_fdf * F = NULL;
     callback_function_params_fdf *params;
     int size;
     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function_fdf(object, &size, NULL, pygsl_multiroot_f_function, 
					      pygsl_multiroot_df_function, 
					      pygsl_multiroot_fdf_function);
     if(params == NULL){
	  return NULL;
     }
     if ((F = (gsl_multiroot_function_fdf *) malloc(sizeof(gsl_multiroot_function_fdf))) == NULL){
	  PyGSL_params_free_fdf(params);
	  PyErr_NoMemory();
	  return NULL;
     }
     F->f   = PyGSL_multiroot_function_wrap_f;
     F->df  = PyGSL_multiroot_function_wrap_df;
     F->fdf = PyGSL_multiroot_function_wrap_fdf;
     F->n = size;
     F->params   = params;
     FUNC_MESS_END();
     return F;
}


double
PyGSL_multimin_function_wrap(const gsl_vector *x, void *params)
{
     double tmp;
     int flag;
     callback_function_params *p;


     p = (callback_function_params *) params;
     flag = PyGSL_function_wrap_On_O(x, p->function, p->arguments, &tmp, NULL, x->size, p->c_func_name);
     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       tmp = gsl_nan();
	  }
     }
     return tmp;
}
double
PyGSL_multimin_function_wrap_f(const gsl_vector *x, void *params)
{
     double tmp;
     int flag;
     callback_function_params_fdf *p;


     p = (callback_function_params_fdf *) params;
     flag = PyGSL_function_wrap_On_O(x, p->f, p->arguments, &tmp, NULL, x->size, p->c_f_func_name);
     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       tmp = gsl_nan();
	  }
     }
     return tmp;
}
/* GSL Documentation specifies this function to int, header to void */
void
PyGSL_multimin_function_wrap_df(const gsl_vector *x, void *params, gsl_vector *g)
{
     int flag;
     callback_function_params_fdf *p;
     
     p = (callback_function_params_fdf *) params;
     flag = PyGSL_function_wrap_Op_On(x, g, p->df, p->arguments, x->size, x->size, p->c_df_func_name);
     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       gsl_vector_set_all(g, gsl_nan());
	       
	  }
     }

}
/* GSL Documentation specifies this function to int, header to void */
void
PyGSL_multimin_function_wrap_fdf(const gsl_vector *x, void *params, double *f, gsl_vector *g)
{
     int flag;
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params;

     flag = PyGSL_function_wrap_On_O(x, p->fdf, p->arguments, f, g, x->size, p->c_fdf_func_name);
     if (flag!= GSL_SUCCESS){
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       *f = gsl_nan();
	       gsl_vector_set_all(g, gsl_nan());
	  }
     }


}

gsl_multimin_function *  
PyGSL_convert_to_gsl_multimin_function(PyObject * object)
{
     gsl_multimin_function * f = NULL;
     callback_function_params *params;
     int size;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function(object, &size, NULL, pygsl_multimin_function);
     if(params == NULL){
	  return NULL;
     }
     if ((f = (gsl_multimin_function *) malloc(sizeof(gsl_multimin_function))) == NULL){
	  PyGSL_params_free(params);
	  PyErr_NoMemory();
	  return NULL;
     }

     /* f->f =  double (*) (const gsl_vector *, void *) PyGSL_multimin_function_wrap; */
     f->f =  PyGSL_multimin_function_wrap;
     f->n = size;
     f->params   = params; 
     FUNC_MESS_END();
     return f;
}

gsl_multimin_function_fdf *  
PyGSL_convert_to_gsl_multimin_function_fdf(PyObject * object){

     gsl_multimin_function_fdf * F = NULL;
     callback_function_params_fdf *params;  
     int size = 0;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function_fdf(object, &size, NULL, pygsl_multimin_f_function, 
					      pygsl_multimin_df_function, pygsl_multimin_fdf_function);
     if(!params){
	  return NULL;
     }
     if ((F = (gsl_multimin_function_fdf *) malloc(sizeof(gsl_multimin_function_fdf))) == NULL){
	  PyGSL_params_free_fdf(params);
	  PyErr_NoMemory();
	  return NULL;
     }
     F->f   = PyGSL_multimin_function_wrap_f;
     F->df  = PyGSL_multimin_function_wrap_df;
     F->fdf = PyGSL_multimin_function_wrap_fdf;    
     F->n = size;
     F->params   = params;
     FUNC_MESS_END();
     return F;
}


int 
PyGSL_multifit_function_wrap(const gsl_vector *x, void *params, gsl_vector *f)
{
     callback_function_params *p;
     p = (callback_function_params *) params;
     return PyGSL_function_wrap_Op_On(x, f, p->function, p->arguments, x->size, f->size, p->c_func_name);
}

int 
PyGSL_multifit_function_wrap_f(const gsl_vector *x, void *params, gsl_vector *f)
{
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params;
     return PyGSL_function_wrap_Op_On(x, f, p->f, p->arguments, x->size, f->size, p->c_f_func_name);
}

int 
PyGSL_multifit_function_wrap_df(const gsl_vector *x, void *params, gsl_matrix *df)
{
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params; 
     /* size 1 or size 2 from matrix ? */
     return PyGSL_function_wrap_Op_Opn(x, df, p->df, p->arguments, df->size1, x->size, p->c_df_func_name);
}

int 
PyGSL_multifit_function_wrap_fdf(const gsl_vector *x, void *params, gsl_vector *f, gsl_matrix *df)
{
     callback_function_params_fdf *p;
     p = (callback_function_params_fdf *) params;
     /* size 1 or size 2 from matrix ? */
     return PyGSL_function_wrap_Op_On_Opn(x, f, df, p->fdf, p->arguments, f->size, x->size, p->c_fdf_func_name);
}
 
gsl_multifit_function *  
PyGSL_convert_to_gsl_multifit_function(PyObject * object)
{
     gsl_multifit_function * f = NULL;
     callback_function_params *params;
     int p, n;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function(object, &n, &p, pygsl_multifit_function);
     if(params == NULL){
	  return NULL;
     }
     if ((f = (gsl_multifit_function *) malloc(sizeof(gsl_multifit_function))) == NULL){
	  PyGSL_params_free(params);
	  PyErr_NoMemory();
	  return NULL;
     }

     f->f = PyGSL_multifit_function_wrap;
     f->params   = params; 
     f->p = p;
     f->n = n;
     FUNC_MESS_END();
     return f;
}


gsl_multifit_function_fdf *  
PyGSL_convert_to_gsl_multifit_function_fdf(PyObject * object){

     gsl_multifit_function_fdf * F = NULL;
     callback_function_params_fdf *params;
     int p,n;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function_fdf(object, &n, &p, pygsl_multifit_f_function, 
					      pygsl_multifit_df_function, pygsl_multifit_fdf_function);
     if(params == NULL){
	  return NULL;
     }
     if ((F = (gsl_multifit_function_fdf *) malloc(sizeof(gsl_multifit_function_fdf))) == NULL){
	  PyGSL_params_free_fdf(params);
	  PyErr_NoMemory();
	  return NULL;
     }
     F->f   = PyGSL_multifit_function_wrap_f;
     F->df  = PyGSL_multifit_function_wrap_df;
     F->fdf = PyGSL_multifit_function_wrap_fdf;    
     F->params   = params;
     F->p = p;
     F->n = n;
     if(DEBUG > 2){
	  fprintf(stderr, "Parameters  are p=%d n=%d\n", p, n);
     }
     FUNC_MESS_END();
     return F;
}


double
PyGSL_monte_function_wrap(double *x,  size_t dim, void *params)
{
     double tmp;
     int flag;
     callback_function_params *p;
     gsl_vector_view view;

     FUNC_MESS_BEGIN();
     view = gsl_vector_view_array(x, dim);
     p = (callback_function_params *) params;
     flag = PyGSL_function_wrap_On_O(&view.vector, p->function, p->arguments,
				     &tmp, NULL, view.vector.size, 
				     p->c_func_name);
     if (flag!= GSL_SUCCESS) {
	  if(p->buffer_is_set == 1){
	       longjmp(p->buffer, flag);
	       FUNC_MESS("\t\t Using jump buffer");
	  } else {
	       FUNC_MESS("\t\t Jump buffer was not defined!");
	       tmp = gsl_nan();
	  }
     }
     FUNC_MESS_END();
     return tmp;
}

gsl_monte_function *
PyGSL_convert_to_gsl_monte_function(PyObject * object)
{
     gsl_monte_function * f = NULL;
     callback_function_params *params;
     int n;

     FUNC_MESS_BEGIN();
     params = PyGSL_convert_to_generic_function(object, &n, NULL, pygsl_monte_function);
     if(params == NULL){
	  return NULL;
     }
     if ((f = (gsl_monte_function *) malloc(sizeof(gsl_monte_function))) == NULL){
	  PyGSL_params_free(params);
	  PyErr_NoMemory();
	  return NULL;
     }

     f->f = PyGSL_monte_function_wrap;
     f->params = params; 
     f->dim = n;
     FUNC_MESS_END();
     return f;
}

