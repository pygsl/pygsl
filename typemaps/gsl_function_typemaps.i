/* -*- C -*- */
/**
 * Author : Pierre Schnizer
 * Date   : January 2003
 */
/*
 * Typemaps to handle callbacks. 
 * 
 * 
 * see gsl_functions_reference.txt for a compilation of the callbacks used
 * by GSL.
 *
 * 10. February 2010: added the check typemap for free. This pointer
 *                    asignment was not made and thus the references were
 *                    not freed. This bug was here for years and got by
 *                    undetected. Thanks to Nor Pizal for reporting this
 *                    bug!
 */
/* ------------------------------------------------------------------------- 
   ------------------------------------------------------------------------- 
            Typemaps to translate python complex to gsl_complex.
   ------------------------------------------------------------------------- 
   ------------------------------------------------------------------------- */
%{
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <assert.h>
#include <float.h>
#include <setjmp.h>
#include <pygsl/utils.h>
#include <pygsl/function_helpers.h>
%}
/* -------------------------------------------------------------------------
   Generic Helper Functions
   ------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------
   gsl function
   ------------------------------------------------------------------------- */
%typemap(arginit) gsl_function * FREE %{
     $1_basetype *_function$argnum = NULL;
%}
%typemap(arginit) gsl_function_fdf * FREE = gsl_function * FREE;

%typemap(in) gsl_function * STORE {
     FUNC_MESS("gsl_function STORE BEGIN");
     $1 = PyGSL_convert_to_$1_basetype ($input);
     FUNC_MESS("gsl_function STORE END");
     if($1==NULL) goto fail;
}

/*
 * This typemap to free is crucial! It ensures that the 
 * pointer is passed to _function$argnum
 */
%typemap(check) gsl_function * FREE {
     DEBUG_MESS(2, "gsl_function STORE IN ptr @ %p", $1);
     if($1==NULL) goto fail;

     _function$argnum = $1;
}

%typemap(freearg) gsl_function * FREE {
     DEBUG_MESS(2, "gsl_function freeing %p", _function$argnum);
     if(_function$argnum){
	  assert($1 == _function$argnum);
	  PyGSL_params_free((callback_function_params *) $1->params);
	  free($1);    
     }
     _function$argnum = NULL;
     DEBUG_MESS(2, "gsl_function freed %p", _function$argnum);

}
%typemap(freearg) gsl_function_fdf * FREE {
     if(_function$argnum){
	  assert($1 == _function$argnum);
	  PyGSL_params_free_fdf((callback_function_params_fdf *) $1->params);
	  free($1);    
     }
}

/* -------------------------------------------------------------------------
 *  Solvers, which need a longjmp to report errors to python.
 *
 * Functions of type gslfunction return a double. I.e they are missing a 
 * Error reporting feature. (Similar also for the multimin functions).
 *
 * If your are applying these typemaps to other typemaps you must:
 *   - define the macro cooresponding to  PyGSL_$1_basetype_GET_PARAMS,
 *     which returns a pointer to the params pointer of the system to 
 *     solver is currently using.
 *     e.g. for roots this is:
 *     #define PyGSL_gsl_root_fsolver_GET_PARAMS(sys)   \
 *	     (sys)->function->params
 * ------------------------------------------------------------------------- */
%typemap(arginit) gsl_fsolver * BUFFER %{
     $1_basetype * volatile _solver$argnum = NULL;
%}
%typemap(arginit) gsl_fdfsolver * BUFFER = gsl_fsolver * BUFFER;

/*
#define PyGSL_HANDLE_JMP_BUF((p)) \
(setjmp(p->buffer) == 0) ? p->buffer_is_set = 1 : p->buffer_is_set = 0
*/
/*
 * I am too lazy to convert the Object to the pointer myself so I use 
 *  check. Is this hack acceptable? */
%typemap(check) gsl_fsolver * BUFFER {
     int flag;
     callback_function_params * p;

     FUNC_MESS("\t\t Setting jump buffer");
     assert($1);


     _solver$argnum = $1;
     p = (callback_function_params *) 
	  PyGSL_$1_basetype_GET_PARAMS(_solver$argnum);

     if((flag=setjmp(p->buffer)) == 0){
	  FUNC_MESS("\t\t Setting Jmp Buffer");
	  p->buffer_is_set = 1;
     } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  p->buffer_is_set = 0;
	  goto fail;
     }

     FUNC_MESS("\t\t END Setting jump buffer");
}

%typemap(check) gsl_fdfsolver * BUFFER {
     int flag;
     callback_function_params_fdf * p;

     FUNC_MESS("\t\t Setting jump buffer");
     assert($1);

     _solver$argnum = $1;
     p = (callback_function_params_fdf *) 
	  PyGSL_$1_basetype_GET_PARAMS(_solver$argnum);

     if((flag=setjmp(p->buffer)) == 0){
	  FUNC_MESS("\t\t Setting Jmp Buffer");
	  /* Set jump buffer */
	  p->buffer_is_set = 1;
     } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  p->buffer_is_set = 0;
	  goto fail;
     }

     FUNC_MESS("\t\t END Setting jump buffer");
}

%typemap(freearg) gsl_fsolver * BUFFER {
     callback_function_params * p;
     if(_solver$argnum){
	  FUNC_MESS("\t\t Looking for pointer params");
	  p = (callback_function_params *)  
	       PyGSL_$1_basetype_GET_PARAMS(_solver$argnum);
	  if(p){
	       FUNC_MESS("\t\t Setting buffer_is_set = 0");
	       p->buffer_is_set = 0;
	  }
     }
}
%typemap(freearg) gsl_fdfsolver * BUFFER {
     callback_function_params_fdf * p;
     if(_solver$argnum){
	  FUNC_MESS("\t\t Looking for pointer params");
	  p = (callback_function_params_fdf *)  
	       PyGSL_$1_basetype_GET_PARAMS(_solver$argnum);
	  if(p){
	       FUNC_MESS("\t\t Setting buffer_is_set = 0");
	       p->buffer_is_set = 0;
	  }
     }
}
/*
 * When the set method of many solvers is called, the function to solve
 * is not yet attached to the solver. So the above can not be used. 
 * So I copy the above typemaps to gsl_function and gsl_function_fdf 
 * and  defining the macro the jumpbuffer is attached to the functions.
 */
%typemap(arginit) gsl_function * BUFFER %{
     $1_basetype volatile *_solver$argnum = NULL;
%}
%typemap(arginit) gsl_function_fdf * BUFFER = gsl_function * BUFFER;

/* gsl_function is so common found in GSL, so I provide this macro here */
%{
#define  PyGSL_gsl_function_GET_PARAMS(sys) \
         (sys)->params
#define  PyGSL_gsl_function_fdf_GET_PARAMS(sys) \
         (sys)->params
%}
%apply gsl_fsolver   * BUFFER {gsl_function     * BUFFER};
%apply gsl_fdfsolver * BUFFER {gsl_function_fdf * BUFFER};
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */

/* -------------------------------------------------------------------------
   Allows to return a numeric array from a gsl_vector stored in some function.
   gsl multiroot function
   ------------------------------------------------------------------------- */
%typemap(out) gsl_multiroot_solver_data * {
     PyArrayObject *a_array;  
     a_array = PyGSL_copy_gslvector_to_pyarray($1);
     $result = (PyObject *) a_array;
}
%typemap(out) gsl_multifit_solver_matrix * {
     PyArrayObject *a_array = NULL;  
     a_array = PyGSL_copy_gslmatrix_to_pyarray($1);
     $result = (PyObject *) a_array;
}
%typemap(out) gsl_multimin_solver_data *    = gsl_multiroot_solver_data *;
%typemap(out) gsl_multifit_solver_vector *  = gsl_multiroot_solver_data *;

/* -------------------------------------------------------------------------
                      Copies
   ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* These have to be converted to apply !*/
%apply gsl_function * {gsl_function_fdf            *,
		       gsl_multiroot_function      *, 
		       gsl_multiroot_function_fdf  *, 
		       gsl_multifit_function       *, 
		       gsl_multifit_function_fdf   *, 
		       gsl_multimin_function       *, 
		       gsl_multimin_function_fdf   *}

/*
 * Only make copies of the following types if you have the helper functions 
 * convert_to_$basetype !
 */
%apply gsl_function * STORE {gsl_function_fdf            * STORE,
		             gsl_multiroot_function      * STORE, 
		             gsl_multiroot_function_fdf  * STORE, 
		             gsl_multifit_function       * STORE, 
		             gsl_multifit_function_fdf   * STORE, 
		             gsl_multimin_function       * STORE, 
			     gsl_multimin_function_fdf   * STORE}

%apply gsl_function * FREE  {gsl_function_fdf            * FREE,
		             gsl_multiroot_function      * FREE, 
		             gsl_multiroot_function_fdf  * FREE, 
		             gsl_multifit_function       * FREE, 
		             gsl_multifit_function_fdf   * FREE, 
		             gsl_multimin_function       * FREE, 
		             gsl_multimin_function_fdf   * FREE}


%typemap(out)     gsl_multiroot_function_fdf_data *            = gsl_multiroot_solver_data  *;
