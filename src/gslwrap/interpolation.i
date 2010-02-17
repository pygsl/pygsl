/* -*- C -*- */
/*
 * Author: Fabian Jakobs
 * Modified by : Pierre Schnizer January 2003
 *
 * Changelog: 
 *   22. May 2003. Changed to use the pygsl library. Warning! Do not import
 * Numeric/arrayobject.h before pygsl_block_helpers.h.  pygsl_block_helpers.h
 * defines the PY_ARRAY_UNIQUE_SYMBOL.
 */		 
%{
#include <pygsl/block_helpers.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#include <stdio.h>

static const char pygsl_spline_des[] = "gsl_spline";
static const char pygsl_accel_des[] = "gsl_accel";

struct pygsl_spline{
     gsl_spline * spline;
     gsl_interp_accel *acc;     
};
 
struct pygsl_interp{
   gsl_interp * interp;
   double * xa;
   double * ya;
   gsl_interp_accel *acc;
   PyArrayObject * x_array;
   PyArrayObject * y_array;  
   size_t n;
 };
%}


%typemap(arginit) (const double *, const double *, size_t ) %{
     PyArrayObject *_PyVector_1$argnum = NULL;
     PyArrayObject *_PyVector_2$argnum = NULL;
%};

%typemap(in) (const double *, const double *, size_t ) {
     PyGSL_array_index_t mysize = 0;
     if(!PySequence_Check($input)){
	  PyErr_SetString(PyExc_TypeError, "Expected a sequence!");
	  goto fail;
     }
     if(PySequence_Fast_GET_SIZE($input) != 2){
	  PyErr_SetString(PyExc_TypeError, "Expected a sequence with length 2!");
	  goto fail;
     }
     _PyVector_1$argnum = PyGSL_vector_check(PySequence_Fast_GET_ITEM($input, 0), -1, PyGSL_DARRAY_CINPUT($argnum), NULL, NULL);
     if (_PyVector_1$argnum == NULL)
	  goto fail;

     mysize = _PyVector_1$argnum->dimensions[0];

     _PyVector_2$argnum = PyGSL_vector_check(PySequence_Fast_GET_ITEM($input, 1), mysize, PyGSL_DARRAY_CINPUT($argnum+1), NULL, NULL);
     if (_PyVector_2$argnum == NULL)
	  goto fail;

     $1 = (double *)(_PyVector_1$argnum->data);
     $2 = (double *)(_PyVector_2$argnum->data);
     $3 = (size_t) mysize;

};
%typemap(check) (const double *, const double *, size_t ) {
     ;
};
%typemap(freearg) (const double *, const double *, size_t ) {
     Py_XDECREF(_PyVector_1$argnum);
     Py_XDECREF(_PyVector_2$argnum);
};
%typemap(arginit) (const double *, size_t ) %{
     PyArrayObject *_PyVector$argnum = NULL;
%};
%typemap(in) (const double *, size_t ) {
     PyGSL_array_index_t mysize = 0;
     _PyVector$argnum = PyGSL_vector_check($input, -1, PyGSL_DARRAY_CINPUT($argnum), NULL, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;

     mysize = _PyVector$argnum->dimensions[0];
     $1 = (double *)(_PyVector$argnum->data);
     $2 = (size_t) mysize;
};
/* Just to prevent that the check typemap below is applied. */
%typemap(freearg) (const double *, size_t ) {
     Py_XDECREF(_PyVector$argnum);
};
%typemap(arginit) (const double * array) %{
     PyArrayObject *_PyVector$argnum = NULL;
     PyObject * _input$argnum;
%};
/* moved to check as I need the size of the interpolation! */
%typemap(in) (const double * array) {
     _input$argnum = $input;
};
%typemap(check) (const double * array) {
     _PyVector$argnum = PyGSL_vector_check(_input$argnum, _gslinterp_size, PyGSL_DARRAY_CINPUT($argnum), NULL, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;
     $1 = (double *)(_PyVector$argnum->data);
};
%typemap(freearg) (const double * array) {
     Py_XDECREF(_PyVector$argnum);
};
%typemap(arginit)(gsl_interp * IN) %{
     int _gslinterp_size = 0;
%};
%typemap(in)(gsl_interp * IN) {
     if(SWIG_ConvertPtr($input, (void **) &$1, $1_descriptor, SWIG_POINTER_EXCEPTION | 0 )){
	  PyErr_SetString(PyExc_TypeError, "Could not convert gsl_interp to pointer");
        goto fail;
     }
     _gslinterp_size = (int) $1->size;
};

%apply (const double *, const double *, size_t ) {(const double xa[], const double ya[], size_t size)};
%apply (const double *, size_t ) {(const double x_array[], size_t size)};
%apply (const double * array){(const double xa[]), 
			      (const double ya[])};



typedef struct
{
     
     %immutable;     
}gsl_interp_accel;


%extend gsl_interp_accel{

     gsl_interp_accel(){
	  return gsl_interp_accel_alloc();	  
     }

     ~gsl_interp_accel(){
	  return gsl_interp_accel_free(self);
     }
     
     gsl_error_flag_drop reset(void);

     size_t find(const double x_array[], size_t size, double x);
     PyObject *tocobject(){
	  return PyCObject_FromVoidPtrAndDesc((void* ) self, (void *) pygsl_accel_des, NULL);
     }
}



%{
static PyObject *
_pygsl_spline_eval_vector_generic(const gsl_spline * spline, const gsl_vector *x, gsl_interp_accel * acc,
				double (*spline_method)(const gsl_spline *, double, gsl_interp_accel *))
{
     size_t i;
     PyGSL_array_index_t n;
     double  *data;
     PyArrayObject * ret = NULL;

     FUNC_MESS_BEGIN();
     n = x->size;
     ret = PyGSL_New_Array(1, &n, PyArray_DOUBLE);
     if(ret == NULL)
	  return NULL;
     
     data = (double *) ret->data;
     for(i=0; i<n; ++i){
	  data[i] = spline_method(spline, gsl_vector_get(x, i), acc);
     }
     FUNC_MESS_END();
     return (PyObject *) ret;

}

static PyObject *
_pygsl_spline_eval_e_vector_generic(const gsl_spline * spline, const gsl_vector *x, gsl_interp_accel * acc,
				  int (*spline_method)(const gsl_spline *, double, gsl_interp_accel * , double *))
{
     size_t i;
     int flag, lineno = -1;
     PyGSL_array_index_t n;
     double  *data, *ptr;
     PyArrayObject * ret = NULL;

     FUNC_MESS_BEGIN();
     n = x->size;
     ret = PyGSL_New_Array(1, &n, PyArray_DOUBLE);
     if(ret == NULL){
	  lineno = __LINE__ - 2;
	  goto fail;
     }
	  
     
     data = (double *) ret->data;
     for(i=0; i<n; ++i){
	  ptr = &(data[i]);
	  flag = spline_method(spline, gsl_vector_get(x, i), acc, ptr);
	  if (PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       lineno = __LINE__ - 2;
	       DEBUG_MESS(2, "Failed to evaluate element %ld", (long) i);
	       goto fail;
	  }
     }
     FUNC_MESS_END();
     return (PyObject *) ret;

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, lineno);     
     Py_XDECREF(ret);
     return NULL;
}


static PyObject *
_pygsl_spline_eval_integ_vector(const gsl_spline * spline, const gsl_vector *a,
				const gsl_vector *b, gsl_interp_accel * acc)
{
     size_t i;
     PyGSL_array_index_t n;
     double  *data;
     PyArrayObject * ret = NULL;

     FUNC_MESS_BEGIN();
     n = a->size;
     if(b->size != n){
	  PyGSL_module_error_handler("Length of boundary b did not match boundary",
				     __FILE__, __LINE__ - 1, GSL_EBADLEN);
	  return NULL;
 
     }
     ret = PyGSL_New_Array(1, &n, PyArray_DOUBLE);
     if(ret == NULL)
	  return NULL;
     
     data = (double *) ret->data;
     for(i=0; i<n; ++i){
	  data[i] = gsl_spline_eval_integ(spline, gsl_vector_get(a, i), gsl_vector_get(b, i), acc);
     }
     FUNC_MESS_END();
     return (PyObject *) ret;

}

static PyObject *
_pygsl_spline_eval_integ_e_vector(const gsl_spline * spline, const gsl_vector *a,
				  const gsl_vector *b, gsl_interp_accel * acc)
{
     size_t i;
     int flag, lineno = -1;
     PyGSL_array_index_t n;
     double  *data, *ptr;
     PyArrayObject * ret = NULL;

     FUNC_MESS_BEGIN();
     n = a->size;
     if(b->size != n){
	  PyGSL_module_error_handler("Length of boundary b did not match boundary",
				     __FILE__, __LINE__ - 1, GSL_EBADLEN);
	  goto fail;
 
     }

     ret = PyGSL_New_Array(1, &n, PyArray_DOUBLE);
     if(ret == NULL){
	  lineno = lineno - 2;
	  goto fail;
     }
     
     data = (double *) ret->data;
     for(i=0; i<n; ++i){
	  ptr = &(data[i]);
	  flag = gsl_spline_eval_integ_e(spline, gsl_vector_get(a, i), gsl_vector_get(b, i), acc, ptr);
	  if (PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
	       lineno = __LINE__ - 2;
	       DEBUG_MESS(2, "Failed to evaluate element %ld", (long) i);
	       goto fail;
	  }
     }
     FUNC_MESS_END();
     return (PyObject *) ret;

 fail:
     PyGSL_add_traceback(module, __FILE__, __FUNCTION__, lineno);     
     Py_XDECREF(ret);
     return NULL;
}

%}



struct pygsl_spline{
};

%extend pygsl_spline{

     
     pygsl_spline(const gsl_interp_type * T, size_t n){
	  struct pygsl_spline *self = NULL;
	  
	  self = (struct pygsl_spline *) calloc(1, sizeof(struct pygsl_spline));
	  self->spline = NULL;
	  self->acc = NULL;

	  self->spline = gsl_spline_alloc(T, n);
	  DEBUG_MESS(5, "Spline memory @ %p", self->spline);
	  if(self->spline == NULL){
	    DEBUG_MESS(2, "Failed to allocate spline memory sp @ %p", self->spline);
	      pygsl_error("Failed to allocate spline memory",
			  __FILE__, __LINE__, GSL_EFAILED);
	      return NULL;
	  }
	  self->acc = gsl_interp_accel_alloc();
	  DEBUG_MESS(5, "Acc memory @ %p", self->spline);
	  if(self->acc == NULL){
 	       DEBUG_MESS(2, "Failed to allocate acceleration. Points to memory sp @ %p",
			  self->acc);
	       gsl_spline_free(self->spline);
	       self->spline = NULL;
	       pygsl_error("Failed to allocate acceleration memory",
			   __FILE__, __LINE__, GSL_EFAILED);
	       return NULL;
	  }
	  return self;
     }

     ~pygsl_spline(){
	  gsl_spline_free(self->spline);
	  self->spline = NULL;
	  gsl_interp_accel_free(self->acc);
	  self->acc = NULL;
	  free(self);
     }

     /* 
      * is that not a source to a memory leak or memory
      * corruption?
     gsl_interp_accel *get_accel_object(){
	  return self->acc;
     }
      */

     gsl_error_flag_drop accel_reset(void){
       return gsl_interp_accel_reset(self->acc);
     };

     size_t accel_find(double x){
       return gsl_interp_accel_find(self->acc, self->spline->x, self->spline->size, x);
     }
     
     PyObject *tocobject(){
	  return PyCObject_FromVoidPtrAndDesc((void* ) self->spline, (void *) pygsl_spline_des, NULL);
     }

     gsl_error_flag_drop init(const double xa[], const double ya[], size_t size){
	  gsl_interp_accel_reset(self->acc);
	  DEBUG_MESS(5, "size = %lu", (unsigned long) size);
	  return gsl_spline_init(self->spline, xa, ya, size);
     }


     double eval(double IN){
	  return gsl_spline_eval(self->spline, IN, self->acc);
     }
     gsl_error_flag_drop eval_deriv_e(double IN, double * OUTPUT){
	  return gsl_spline_eval_deriv_e(self->spline, IN, self->acc, OUTPUT);
     }
     
     double eval_deriv(double IN){
	  return gsl_spline_eval_deriv(self->spline, IN, self->acc);
     }

     gsl_error_flag_drop eval_deriv2_e(double IN, double * OUTPUT){
	  return gsl_spline_eval_deriv2_e(self->spline, IN, self->acc, OUTPUT);
     }

     double eval_deriv2(double IN) {
	  return gsl_spline_eval_deriv2(self->spline, IN, self->acc);                       
     }

     double eval_integ(double a, double b){
	  return gsl_spline_eval_integ(self->spline, a, b,self->acc);
     }

     gsl_error_flag_drop eval_integ_e(double a, double b, double * OUTPUT){
	  return gsl_spline_eval_integ_e(self->spline, a, b, self->acc, OUTPUT);
     }


     gsl_error_flag_drop eval_e(double IN, double * OUTPUT){
	  return gsl_spline_eval_e(self->spline, IN, self->acc, OUTPUT);
     }

     PyObject * eval_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_vector_generic(self->spline, IN, self->acc, gsl_spline_eval);
     }

     PyObject *eval_e_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_e_vector_generic(self->spline, IN, self->acc, gsl_spline_eval_e);
     }
     
     PyObject * eval_deriv_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_vector_generic(self->spline, IN, self->acc, gsl_spline_eval_deriv);
     }

     PyObject * eval_deriv2_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_vector_generic(self->spline, IN, self->acc, gsl_spline_eval_deriv2);
     }

     PyObject * eval_deriv_e_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_e_vector_generic(self->spline, IN, self->acc, gsl_spline_eval_deriv_e);
     }

     PyObject * eval_deriv2_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_vector_generic(self->spline, IN, self->acc, gsl_spline_eval_deriv2);
     }

     PyObject * eval_deriv2_e_vector(const gsl_vector *IN){
	  return  _pygsl_spline_eval_e_vector_generic(self->spline, IN, self->acc, gsl_spline_eval_deriv2_e);
     }

     PyObject * eval_integ_vector(const gsl_vector *IN, const gsl_vector *IN2){
	  return _pygsl_spline_eval_integ_vector(self->spline, IN,  IN2, self->acc);
     }
     
     PyObject * eval_integ_e_vector(const gsl_vector *IN, const gsl_vector *IN2){
	  return _pygsl_spline_eval_integ_e_vector(self->spline, IN,  IN2,  self->acc);
     }

     const char * name(){
       return gsl_spline_name(self->spline);
     }

     unsigned int min_size(){
       return gsl_spline_min_size(self->spline);
     }

}

GSL_VAR const gsl_interp_type * gsl_interp_linear;
GSL_VAR const gsl_interp_type * gsl_interp_polynomial;
GSL_VAR const gsl_interp_type * gsl_interp_cspline;
GSL_VAR const gsl_interp_type * gsl_interp_cspline_periodic;
GSL_VAR const gsl_interp_type * gsl_interp_akima;
GSL_VAR const gsl_interp_type * gsl_interp_akima_periodic;    



struct pygsl_interp{
};

%extend pygsl_interp{
    pygsl_interp(const gsl_interp_type * T, size_t n){
	  struct pygsl_interp *self = NULL;
	  
	  self = (struct pygsl_interp *) calloc(1, sizeof(struct pygsl_interp));
	  self->interp = NULL;
	  self->acc = NULL;
	  self->n = n;
	  self->interp = gsl_interp_alloc(T, n);
	  DEBUG_MESS(5, "Interp memory @ %p", self->interp);
	  if(self->interp == NULL){
	    DEBUG_MESS(2, "Failed to allocate interp memory sp @ %p", self->interp);
	      pygsl_error("Failed to allocate interp memory",
			  __FILE__, __LINE__, GSL_EFAILED);
	      return NULL;
	  }
	  self->acc = gsl_interp_accel_alloc();
	  DEBUG_MESS(5, "Acc memory @ %p", self->interp);
	  if(self->acc == NULL){
 	       DEBUG_MESS(2, "Failed to allocate acceleration. Points to memory sp @ %p",
			  self->acc);
	       gsl_interp_free(self->interp);
	       self->interp = NULL;
	       pygsl_error("Failed to allocate acceleration memory",
			   __FILE__, __LINE__, GSL_EFAILED);
	       return NULL;
	  }
	  return self;
     }

     ~pygsl_interp(){
	  gsl_interp_free(self->interp);
	  self->interp = NULL;
	  gsl_interp_accel_free(self->acc);
	  self->acc = NULL;

	  Py_XDECREF(self->x_array);
	  Py_XDECREF(self->y_array);
	  self->xa = NULL;
	  self->ya = NULL;
	  
	  free(self);
     }

     gsl_error_flag_drop init(PyObject *x, PyObject *y){
       PyArrayObject *xa = NULL, *ya = NULL;
       PyGSL_array_index_t size;
       int flag = GSL_EINVAL;

       FUNC_MESS_BEGIN();
       size = self->n;
       DEBUG_MESS(2, "Interpolation object expects arrays of size %ld", (long) size);
       xa = PyGSL_vector_check(x, size, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
       if(xa == NULL){
	 DEBUG_MESS(2, "Array size check failed for x argument %d", 1);
	 flag = GSL_EBADLEN;
	 goto fail;
       }

       ya = PyGSL_vector_check(y, size, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
       if(ya == NULL){
	 DEBUG_MESS(2, "Array size check failed for x argument %d", 1);
	 flag = GSL_EBADLEN;
	 goto fail;
       }
       
       Py_XDECREF(self->x_array);
       self->xa = NULL;
       self->x_array = xa;
       self->xa = (double *) xa->data;

       Py_XDECREF(self->y_array);
       self->ya = NULL;
       self->y_array = ya;
       self->ya = (double *) ya->data;

       flag = gsl_interp_init(self->interp, self->xa, self->ya, self->n);
       FUNC_MESS_END();
       return flag;

     fail:
       FUNC_MESS("FAIL");
       Py_XDECREF(xa);
       Py_XDECREF(ya);
       /* make sure that not success is returend if error is found. */
       if(flag == GSL_SUCCESS){
	 DEBUG_MESS(2, "In fail part but flag = %d\n", flag);
	 flag = GSL_EFAILED;
       }
       DEBUG_MESS(6, "Returning flag %d", flag);
       return flag;       
     }


     const char * name(){
       return gsl_interp_name(self->interp);
     }

     unsigned int min_size(){
       return gsl_interp_min_size(self->interp);
     }

     gsl_error_flag_drop eval_e(double x, double * OUTPUT){
       return gsl_interp_eval_e(self->interp, self->xa, self->ya, x, self->acc, OUTPUT);
     }

     double eval(double x){
       return gsl_interp_eval(self->interp, self->xa, self->ya, x, self->acc);
     }

     gsl_error_flag_drop eval_deriv_e(double x, double * OUTPUT){
       return gsl_interp_eval_deriv_e(self->interp, self->xa, self->ya, x, self->acc, OUTPUT);
     }

     double eval_deriv(double x){
       return gsl_interp_eval_deriv(self->interp, self->xa, self->ya, x, self->acc);
     }


     gsl_error_flag_drop eval_deriv2_e(double x, double * OUTPUT){
       return gsl_interp_eval_deriv2_e(self->interp, self->xa, self->ya, x, self->acc, OUTPUT);
     }

     double eval_deriv2(double x){
       return gsl_interp_eval_deriv2(self->interp, self->xa, self->ya, x, self->acc);
     }

     gsl_error_flag_drop eval_integ_e(double a, double b, double * OUTPUT){
       return gsl_interp_eval_integ_e(self->interp, self->xa, self->ya, a, b, self->acc, OUTPUT);
     }

     double eval_integ(double a, double b){
       return gsl_interp_eval_integ(self->interp, self->xa, self->ya, a, b, self->acc);
     }

     gsl_error_flag_drop accel_reset(void){
       return gsl_interp_accel_reset(self->acc);
     };

     size_t accel_find(double x){
       return gsl_interp_accel_find(self->acc, self->xa, self->n, x);
     }

}



     


%typemap(arginit) (const double x_array[]) %{
     PyArrayObject *_PyVector$argnum = NULL;
     int _PyVectorLength = 0;
%};
/* moved to check as I need the size of the interpolation! */
%typemap(in) (const double x_array[]) {
     _PyVector$argnum = PyGSL_vector_check($input, -1, PyGSL_DARRAY_CINPUT($argnum), NULL, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;
     $1 = (double *)(_PyVector$argnum->data);
     _PyVectorLength = _PyVector$argnum->dimensions[0];
};
%typemap(check) (const double x_array[]) {
     ;
};
%typemap(freearg) (const double x_array[]) {
     Py_XDECREF(_PyVector$argnum);
};
%typemap(check) size_t index{
     if($1 < 0){
	  PyErr_SetString(PyExc_ValueError, "The array index must be greater or equal to 0!");
	  goto fail;
     }
     if($1 >= _PyVectorLength){
	  PyErr_SetString(PyExc_ValueError, "The array index must not exceed the array length!");
	  goto fail;
     }
}


%apply(size_t index){size_t index_lo, size_t index_hi};
size_t gsl_interp_bsearch(const double x_array[], double x,
                          size_t index_lo, size_t index_hi);
