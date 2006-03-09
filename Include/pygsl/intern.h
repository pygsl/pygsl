/*
 * Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 */
#ifndef PyGSL_API_H
#define PyGSL_API_H 1


#include <Python.h>

/*
#define PyGSL_API_UNIQUE_SYMBOL PyGSL_API
*/
/*
 * This API import trick was copied from Numeric/arrayobject.h
 */
#if defined(PyGSL_API_UNIQUE_SYMBOL)
#define PyGSL_API PyGSL_API_UNIQUE_SYMBOL
#endif

/* C API address pointer */ 
#if defined(PyGSL_NO_IMPORT_API)
extern void **PyGSL_API;
#else
#if defined(PyGSL_API_UNIQUE_SYMBOL)
void **PyGSL_API;
#else
static void **PyGSL_API;
#endif /* PyGSL_API_UNIQUE_SYMBOL */
#endif /* PyGSL_NO_IMPORT_API */


#ifndef _PyGSL_API_MODULE
#define PyGSL_API_EXTERN extern
#else /* _PyGSL_API_MODULE */
#define PyGSL_API_EXTERN static
#endif /* _PyGSL_API_MODULE */





/* Functions found in the file <pygsl/error_helpers.h> */
#define PyGSL_api_version_NUM                           0
#define PyGSL_error_flag_NUM                            1
#define PyGSL_error_flag_to_pyint_NUM                   2
#define PyGSL_warning_NUM                               3
#define PyGSL_add_traceback_NUM                         4
#define PyGSL_module_error_handler_NUM                  5

/* float, complex, int conversions */
#define PyGSL_pyfloat_to_double_NUM                     6
#define PyGSL_pylong_to_ulong_NUM                       7
#define PyGSL_pylong_to_uint_NUM                        8
#define PyGSL_check_python_return_NUM                   9
#define PyGSL_clear_name_NUM                           10 

#define PyGSL_PyComplex_to_gsl_complex_NUM             11
#define PyGSL_PyComplex_to_gsl_complex_float_NUM       12
#define PyGSL_PyComplex_to_gsl_complex_long_double_NUM 13

/* vector matrix conversion */
#define PyGSL_stride_recalc_NUM                        14
#define PyGSL_PyArray_new_NUM                          15
#define PyGSL_PyArray_copy_NUM                         16

#define PyGSL_PyArray_prepare_gsl_vector_view_NUM      17
#define PyGSL_PyArray_prepare_gsl_matrix_view_NUM      18
#define PyGSL_PyArray_generate_gsl_vector_view_NUM     19 
#define PyGSL_PyArray_generate_gsl_matrix_view_NUM     20
#define PyGSL_copy_pyarray_to_gslvector_NUM            21
#define PyGSL_copy_pyarray_to_gslmatrix_NUM            22
#define PyGSL_copy_gslvector_to_pyarray_NUM            23
#define PyGSL_copy_gslmatrix_to_pyarray_NUM            24

#define PyGSL_vector_or_double_NUM                     25

/* rng object */
#define PyGSL_RNG_ObjectType_NUM                       26
#define PyGSL_gsl_rng_from_pyobject_NUM                27 
#define PyGSL_function_wrap_helper_NUM                 28

/* solver type */
#define PyGSL_solver_type_NUM                          29
#define PyGSL_solver_ret_int_NUM                       30
#define PyGSL_solver_ret_double_NUM                    31
#define PyGSL_solver_ret_size_t_NUM                    32
#define PyGSL_solver_ret_vec_NUM                       33
#define PyGSL_solver_dn_init_NUM                       34
#define PyGSL_solver_vd_i_NUM                          35
#define PyGSL_solver_vvdd_i_NUM                        36
#define PyGSL_Callable_Check_NUM                       37
#define PyGSL_solver_func_set_NUM                      38

#define PyGSL_function_wrap_OnOn_On_NUM                39
#define PyGSL_function_wrap_On_O_NUM                   40
#define PyGSL_function_wrap_Op_On_NUM                  41
#define PyGSL_solver_n_set_NUM                         42
#define PyGSL_solver_set_f_NUM                         43

/* Add Debug Number */
#define PyGSL_register_debug_flag_NUM                  44

#define PyGSL_error_string_for_callback_NUM            45

#define PyGSL_NENTRIES_NUM                             46
#ifndef _PyGSL_API_MODULE
#endif /* _PyGSL_API_MODULE */

/*
 * Entries in the API. 
 * WARNING: This is the length of the entries. 
 * All Entries defined here with _NUM must be smaller than this number!!
 */


/* 
 * I define the error handler here as the api import shall also set the error 
 * handler. The error handler must be set in each module speratley as on some 
 * platforms GSL is linked statically, thus each module has its seperate error
 * gsl handler.
 * And I think the other platforms can spare these extra cycles, so I do that 
 * on all platforms.
 */
PyGSL_API_EXTERN void 
PyGSL_module_error_handler(const char *reason, /* name of function */
			   const char *file,   /* from CPP */
			   int line,           /* from CPP */
			   int gsl_error);     /* real "reason" */


/*
 * Used to inform the module of the approbriate number
 */
PyGSL_API_EXTERN int 
PyGSL_register_debug_flag(int *, const char * module_name);

#ifndef _PyGSL_API_MODULE
#define PyGSL_module_error_handler\
 (*(void (*)(const char *, const char *, int, int)) PyGSL_API[PyGSL_module_error_handler_NUM])
#define PyGSL_register_debug_flag \
 (*(int (*)(int *, const char *)) PyGSL_API[PyGSL_register_debug_flag_NUM])
#endif  /* _PyGSL_API_MODULE */

#if DEBUG == 1 
static int pygsl_debug_level = 0;
#define PyGSL_DEBUG_LEVEL() (pygsl_debug_level)
#define PyGSL_init_debug()  (PyGSL_register_debug_flag(&pygsl_debug_level, __FILE__))
#else /*  DEBUG == 1 */
#define PyGSL_DEBUG_LEVEL() (DEBUG)
#define PyGSL_init_debug()  (GSL_SUCCESS)
#endif /*  DEBUG == 1 */




#define PyGSL_SET_ERROR_HANDLER() \
        gsl_set_error_handler(&(*(void (*)(const char *, const char *, int, int))PyGSL_API[PyGSL_module_error_handler_NUM]))
        
#define init_pygsl()\
{ \
   PyObject *pygsl = NULL, *c_api = NULL, *md = NULL; \
   if ( \
      (pygsl = PyImport_ImportModule("pygsl.init"))    != NULL && \
      (md = PyModule_GetDict(pygsl))                   != NULL && \
      (c_api = PyDict_GetItemString(md, "_PYGSL_API")) != NULL && \
      (PyCObject_Check(c_api))                                    \
     ) { \
	 PyGSL_API = (void **)PyCObject_AsVoidPtr(c_api); \
         PyGSL_SET_ERROR_HANDLER(); \
         if((void *) PyGSL_SET_ERROR_HANDLER() != PyGSL_API[PyGSL_module_error_handler_NUM]){\
            fprintf(stderr, "Installation of error handler failed! In File %s\n", __FILE__); \
         }\
       if((PyGSL_init_debug()) != GSL_SUCCESS){ \
         fprintf(stderr, "Failed to register debug switch for file %s\n", __FILE__);} \
   } else { \
        PyGSL_API = NULL; \
        fprintf(stderr, "Import of pygsl.init Failed!!! File %s\n", __FILE__);\
   } \
} 
#endif  /*  PyGSL_API_H */
