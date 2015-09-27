/*
 * Author : Pierre Schnizer <schnizer@users.sourceforge.net>
 *
 * $Id:
 */
#ifndef PyGSL_API_INTERN_H
#define PyGSL_API_INTERN_H 1

#include <Python.h>
#include <pygsl/transition.h>
#include <pygsl/capsuletrunk.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
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



/*
 * The version of the API. Allows to check if the used 
 * API is correct.
 */
#define PyGSL_API_VERSION       ((unsigned long) ( 0x3))
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
#define PyGSL_function_wrap_Op_On_Opn_NUM              40
#define PyGSL_function_wrap_On_O_NUM                   41
#define PyGSL_function_wrap_Op_On_NUM                  42
#define PyGSL_function_wrap_Op_Opn_NUM                 43
#define PyGSL_solver_n_set_NUM                         44
#define PyGSL_solver_set_f_NUM                         45
#define PyGSL_solver_getset_NUM                        46

/* to be resorted */
#define PyGSL_vector_check_NUM                         50
#define PyGSL_matrix_check_NUM                         51
#define PyGSL_array_check_NUM                          52

/* Add Debug Number */
#define PyGSL_register_debug_flag_NUM                  61

#define PyGSL_error_string_for_callback_NUM            62

#define PyGSL_pyint_to_int_NUM                         63
#define PyGSL_string_as_string_NUM                     64
#define PyGSL_NENTRIES_NUM                             65

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


/* #define PyGSL_SET_GSL_ERROR_HANDLER 1 */
#define _PyGSL_MODULE_ERROR_HANDLER_FUNC \
    (*(void (*)(const char *, const char *, int, int))PyGSL_API[PyGSL_module_error_handler_NUM])
#ifdef PyGSL_SET_GSL_ERROR_HANDLER 
#define PyGSL_SET_ERROR_HANDLER() \
        gsl_set_error_handler(_PyGSL_MODULE_ERROR_HANDLER_FUNC)
#define PyGSL_CHECK_ERROR_HANDLER() \
    if(PyGSL_SET_ERROR_HANDLER() != _PyGSL_MODULE_ERROR_HANDLER_FUNC){\
        fprintf(stderr, "Installation of error handler failed! In File %s\n", __FILE__);\
    }
#else  /* PyGSL_SET_GSL_ERROR_HANDLER */ 
#define PyGSL_SET_ERROR_HANDLER() gsl_set_error_handler_off()
#define PyGSL_CHECK_ERROR_HANDLER() 
#endif /* PyGSL_SET_GSL_ERROR_HANDLER */

#define pygsl_error(reason, file, line, pygsl_errorno)  \
     _PyGSL_MODULE_ERROR_HANDLER_FUNC((reason), (file), (line), (pygsl_errorno))


#define PyGSL_ERROR_VAL(reason, gsl_errno, value) \
       do { \
       pygsl_error((reason), __FILE__, __LINE__, (gsl_errno)) ; \
       return (value) ; \
       } while (0)

#define PyGSL_ERROR(reason, gsl_errno)      PyGSL_ERROR_VAL((reason), (gsl_errno), (gsl_errno))
#define PyGSL_ERROR_NULL(reason, gsl_errno) PyGSL_ERROR_VAL((reason), (gsl_errno), NULL)

static const char pygsl_api_name[] = "pygsl_api";
#define init_pygsl()\
{ \
   PyObject *pygsl = NULL, *c_api = NULL, *md = NULL; \
   unsigned long version;\
   if ( \
      (pygsl = PyImport_ImportModule("pygsl.init"))    != NULL && \
      (md = PyModule_GetDict(pygsl))                   != NULL && \
      (c_api = PyDict_GetItemString(md, "_PYGSL_API")) != NULL && \
      (PyCapsule_CheckExact(c_api))                                    \
     ) { \
     PyGSL_API = (void **)PyCapsule_GetPointer(c_api, pygsl_api_name);		    \
     version = (unsigned long) PyGSL_API[PyGSL_api_version_NUM];		\
         if (PyGSL_API_VERSION != version ){ \
            fprintf(stderr, "Compiled for PyGSL_API_VERSION 0x%lx but found 0x%lx! In File %s\n", PyGSL_API_VERSION, version, __FILE__); \
         } \
         PyGSL_SET_ERROR_HANDLER(); \
         PyGSL_CHECK_ERROR_HANDLER(); \
       if((PyGSL_init_debug()) != GSL_SUCCESS){ \
         fprintf(stderr, "Failed to register debug switch for file %s\n", __FILE__);} \
   } else { \
        PyGSL_API = NULL; \
        fprintf(stderr, "Import of pygsl.init Failed!!! File %s\n", __FILE__);\
   } \
} 

__END_DECLS

#endif  /*  PyGSL_API_INTERN_H */
