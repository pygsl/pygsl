/**
 * Author : Pierre Schnizer
 * Date: January 2003
 */
#ifndef PyGSL_FUNCTION_HELPERS_H
#define  PyGSL_FUNCTION_HELPERS_H 1
/*   ------------------------------------------------------------------------- 
     See gsl_functions_reference.txt for a compilation of the different 
     callbacks found in GSL.

     Todo: 
           Perhaps split the file in general helpers and 
	   special helpers ????
	   Make all helpers reporting error via 
           PyGSL_set_error_string_for_callback

	   List all functions in these file in a header
   ------------------------------------------------------------------------- */
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_min.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_multimin.h>
#include <gsl/gsl_multifit_nlin.h>
#include <gsl/gsl_monte.h>
#include <pygsl/utils.h>
#include <pygsl/intern.h>
#include <pygsl/error_helpers.h>
#include <pygsl/general_helpers.h>
#include <pygsl/block_helpers.h>
#include <pygsl/function_helpers.h>
#include <math.h>
#include <setjmp.h>

/* -------------------------------------------------------------------------
   Helper Structs

   *_func_name : a descriptive message for the internal function used 
                 when reporting an error to the user.
   buffer_is_set : It depends on the user that she/he uses the
                   *BUFFER in the function interfaces. So this variable is
                  set to zero when the struct is generated. I hope this 
		  will stop the wrapper trying to jump to NIRVANA.
   ------------------------------------------------------------------------- */
/* 
 *  11 December 2003
 *  I return the flag that GSL returned using the flag argument to longjmp.
 *  This flag must be different from zero to be useful. GSL uses 
 *  0 (== GSL_SUCCESS) to indicate it. I check for that here to see if it is 
 *  always like that.
 */
#if GSL_SUCCESS != 0
#error "The function helpers use longjmp. GSL_SUCCESS must be zero. Pygsl Design error"
#endif
typedef struct {
     PyObject *function;
     PyObject *arguments;
     const char * c_func_name;
     jmp_buf buffer;
     int buffer_is_set;
} callback_function_params;

typedef struct {
     PyObject *f;
     PyObject *df;
     PyObject *fdf;
     PyObject *arguments;
     const char * c_f_func_name;
     const char * c_df_func_name;
     const char * c_fdf_func_name;
     jmp_buf buffer;
     int buffer_is_set;
} callback_function_params_fdf;




/* -------------------------------------------------------------------------
   Copy PyArray to gsl vector, gslarray and vice versa
   Are these functions ever needed by pure vector or matrix conversion?
   If so these functions should go into gsl_block_helpers.i
   ------------------------------------------------------------------------- */


/* 1. A_n O -> A_p  */
int
PyGSL_function_wrap_Op_On(const gsl_vector * x, gsl_vector *f, PyObject *callback, 
			  PyObject * arguments, int n, int p, const char *c_func_name);
/* 2. A_n O -> A_n_p */
int
PyGSL_function_wrap_Op_Opn(const gsl_vector * x, gsl_matrix *f, PyObject *callback,
			   PyObject *arguments, int n, int p, const char * c_func_name);

/* 3   dO -> d      gsl_function     */
/* 3.1 dO -> d d    gsl_function_fdf */
PyGSL_API_EXTERN int 
PyGSL_function_wrap_helper(double x, double * result, double *result2,
			   PyObject *callback, PyObject *arguments,
			   const char *c_func_name);

/*
 * Pass a NULL pointer for result 2, if not needed.
 */
/* 4. A_n O   ->  d (A_n) */
 int
PyGSL_function_wrap_On_O(const gsl_vector * x, PyObject *callback,
			PyObject *arguments, double *result1,
			 gsl_vector *result2, int n, const char * c_func_name);

/* 5. A_n O -> A_n A_n_p */
 int
PyGSL_function_wrap_Op_On_Opn(const gsl_vector * x, gsl_vector *f1, 
			      gsl_matrix *f2, PyObject *callback, 
			      PyObject *arguments, int n, int p, 
			      const char * c_func_name);


/* -------------------------------------------------------------------------
      Register Python Call backs
      
      Generic Helper Functions
   ------------------------------------------------------------------------ */
/* Callbacks using one function */
callback_function_params *
PyGSL_convert_to_generic_function(PyObject *object, int *size, int *size2, const char * c_func_name);
/* Callbacks using 3  functions */
callback_function_params_fdf *
PyGSL_convert_to_generic_function_fdf(PyObject *object, int *size, int *size2, 
				      const char * c_f_func_name, const char * c_df_func_name, const char * c_fdf_func_name);
void 
PyGSL_params_free(callback_function_params *p);
void 
PyGSL_params_free_fdf(callback_function_params_fdf *p);


double 
PyGSL_function_wrap(double x, void * params);
double 
PyGSL_function_wrap_f(double x, void * params);
double 
PyGSL_function_wrap_df(double x, void * params);
void
PyGSL_function_wrap_fdf(double x,  void * params, double *f, double * fdf);
gsl_function *  
PyGSL_convert_to_gsl_function(PyObject * object);
gsl_function_fdf *  
PyGSL_convert_to_gsl_function_fdf(PyObject * object);


/* Specialised functions ... should they go to callbacks? */


int 
PyGSL_multiroot_function_wrap(const gsl_vector *x, void *params, gsl_vector *f);
int 
PyGSL_multiroot_function_wrap_f(const gsl_vector *x, void *params, gsl_vector *f);
int 
PyGSL_multiroot_function_wrap_df(const gsl_vector *x, void *params, gsl_matrix *J);
int 
PyGSL_multiroot_function_wrap_fdf(const gsl_vector *x, void *params, gsl_vector *f, gsl_matrix *J);
gsl_multiroot_function *  
PyGSL_convert_to_gsl_multiroot_function(PyObject * object);
gsl_multiroot_function_fdf *  
PyGSL_convert_to_gsl_multiroot_function_fdf(PyObject * object);


double
PyGSL_multimin_function_wrap(const gsl_vector *x, void *params);
double
PyGSL_multimin_function_wrap_f(const gsl_vector *x, void *params);
void
PyGSL_multimin_function_wrap_df(const gsl_vector *x, void *params, gsl_vector *g);
void
PyGSL_multimin_function_wrap_fdf(const gsl_vector *x, void *params, double *f, gsl_vector *g);
gsl_multimin_function *  
PyGSL_convert_to_gsl_multimin_function(PyObject * object);
gsl_multimin_function_fdf *  
PyGSL_convert_to_gsl_multimin_function_fdf(PyObject * object);


int 
PyGSL_multifit_function_wrap(const gsl_vector *x, void *params, gsl_vector *f);
int 
PyGSL_multifit_function_wrap_f(const gsl_vector *x, void *params, gsl_vector *f);
int 
PyGSL_multifit_function_wrap_df(const gsl_vector *x, void *params, gsl_matrix *df);
int 
PyGSL_multifit_function_wrap_fdf(const gsl_vector *x, void *params, gsl_vector *f, gsl_matrix *df);
gsl_multifit_function *  
PyGSL_convert_to_gsl_multifit_function(PyObject * object);
gsl_multifit_function_fdf *  
PyGSL_convert_to_gsl_multifit_function_fdf(PyObject * object);
gsl_monte_function *
PyGSL_convert_to_gsl_monte_function(PyObject * object);


/* gsl_function */
extern char * pygsl_gsl_function;
extern char * pygsl_gsl_f_function;
extern char * pygsl_gsl_df_function;
extern char * pygsl_gsl_fdf_function;
/* gsl_multifit */
extern char * pygsl_multifit_function;
extern char * pygsl_multifit_f_function;
extern char * pygsl_multifit_df_function;
extern char * pygsl_multifit_fdf_function;
 
extern char * pygsl_multimin_function;
extern char * pygsl_multimin_f_function;
extern char * pygsl_multimin_df_function;
extern char * pygsl_multimin_fdf_function;
/* gsl_multiroot */
extern char * pygsl_multiroot_function;
extern char * pygsl_multiroot_f_function;
extern char * pygsl_multiroot_df_function;
extern char * pygsl_multiroot_fdf_function;

/* monte */
extern char * pygsl_monte_function;
#ifndef _PyGSL_API_MODULE
#define PyGSL_function_wrap_helper \
(*(int (*) (double, double *, double *, PyObject *, PyObject *, const char *)) PyGSL_API[PyGSL_function_wrap_helper_NUM])
#endif  /* _PyGSL_API_MODULE */
#endif  /* PyGSL_FUNCTION_HELPERS_H */




