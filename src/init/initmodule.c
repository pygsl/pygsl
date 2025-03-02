/*
 * author: Pierre Schnizer
 * created: March 2004
 * file: pygsl/src/initmodule.c
 * $Id$
 *
 * Changes:
 *     7. October 2003:
 *     Removed the error handler from this file. It is now in
 *     Lib/error_helpers.c Each module must call init_pygsl()
 *     in its init routine. This is necessary to support platforms
 *     where the gsl library is statically linked to the various
 *     modules.
 */
#define  _PyGSL_API_MODULE 1
static const char pygsl_debug_name[] = "pygsl_debug";
#define _PyGSL_API_CAP_NAME pygsl_api_name
#define _PyGSL_DEBUG_CAP_NAME pygsl_debug_name
#include <pygsl/intern.h>
#include <pygsl/utils.h>
#include <pygsl/error_helpers.h>
#include <pygsl/string_helpers.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_version.h>


/* Taken from Modules/getbuildinfo */
#ifndef DATE
#ifdef __DATE__
#define DATE __DATE__
#else
#define DATE "xx/xx/xx"
#endif
#endif

#ifndef TIME
#ifdef __TIME__
#define TIME __TIME__
#else
#define TIME "xx:xx:xx"
#endif
#endif
/* End */

/*
 * Used as a buffer to generate error messages.
 */
static char pygsl_error_str[512];
#define PyGSL_string_as_string _PyGSL_string_as_string
static char *
_PyGSL_string_as_string(PyObject * unicode_obj)
{
	PyObject * bytes_obj = NULL;
	char *r = NULL;

	FUNC_MESS_BEGIN();
	bytes_obj = PyUnicode_AsASCIIString(unicode_obj);
	if(bytes_obj == NULL)
		goto fail;

	r = PyBytes_AsString(bytes_obj);
	FUNC_MESS_END();
	return r;

  fail:
	FUNC_MESS("FAIL");
	Py_XDECREF(bytes_obj);
	return NULL;
}

#include "profile.c"
#include "error_helpers.c"
#include "general_helpers.c"
#include "complex_helpers.c"
#include "block_helpers.c"
#include "function_helpers.c"
#include "rng_helpers.c"

static PyObject * debuglist = NULL;



static int
PyGSL_register_debug_flag(int * ptr, const char * module_name)
{
#if DEBUG == 1
     PyObject * cobj;
     FUNC_MESS_BEGIN();
     if ((cobj = PyCapsule_New((void *) ptr, _PyGSL_DEBUG_CAP_NAME, NULL)) == NULL){
	  fprintf(stderr, "Could not create PyCObject for ptr %p to debug flag for module %s\n",
		  (void * ) ptr, module_name);
	  return GSL_EFAILED;
     }
     DEBUG_MESS(2, "Registering ptr %p for module %s", (void *) ptr,  module_name);
     if(PyList_Append(debuglist, cobj) != 0){
	  return GSL_EFAILED;
     }
     *ptr = pygsl_debug_level;
     FUNC_MESS_END();
     return GSL_SUCCESS;
#endif
     PyGSL_ERROR("Why does it try to register the debug level callback? Should"
	       " use the compile time value DEBUG!", GSL_ESANITY);
}

static PyObject *
PyGSL_set_debug_level(PyObject *self, PyObject *args)
{

     int status=GSL_EFAILED;
     FUNC_MESS_BEGIN();
#if DEBUG == 1
     PyObject *o;
     int tmp, i, max, *ptr;
     if(!PyArg_ParseTuple(args, "i", &tmp))
	  return NULL;
     if(tmp >= 0 && tmp <PyGSL_DEBUG_MAX)
	  ;
     else
	  PyGSL_ERROR_VAL("Only accept debug levels between 0 and PyGSL_DEBUG_MAX", GSL_EINVAL, NULL);

     pygsl_debug_level = tmp;
     max = PySequence_Size(debuglist);
     DEBUG_MESS(3, "Setting debug level to %d for %d modules", pygsl_debug_level, max);
     for(i = 0; i < max; ++i){
	  if((o = PySequence_GetItem(debuglist, i)) == NULL){
	       fprintf(stderr, "In file %s at line %d; Could not get element %d\n",
		       __FILE__, __LINE__, i);
	       continue;
	  }
	  ptr = (int *)PyCapsule_GetPointer(o, _PyGSL_DEBUG_CAP_NAME);
	  DEBUG_MESS(2, "Setting info ptr %p", (void *) ptr);
	  *ptr = tmp;
     }
     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;
#else
     fprintf(stderr, "set_debug_level, debug level not enabled at combpile time\n");
     status = GSL_EUNIMPL;
     pygsl_error("PyGSL was not compiled with DEBUG = 1; Can not set DEBUG level!",
		 __FILE__, __LINE__, status);
     if (PyGSL_ERROR_FLAG(status)!= GSL_SUCCESS){
	 FUNC_MESS_FAILED();
	 return NULL;
     }

     Py_INCREF(Py_None);
     FUNC_MESS_END();
     return Py_None;
#endif
}

static PyObject *
PyGSL_get_debug_level(PyObject *self, PyObject *args)
{
     int tmp;
#if DEBUG == 1
     tmp = (int) pygsl_debug_level;
#else
     tmp = DEBUG;
#endif
     return PyLong_FromLong(tmp);
}

static void * _PyGSL_API[PyGSL_NENTRIES_NUM];

static const char pygsl_init_set_debug_level_doc[] =
  "Set the internal debug level\n"
  "\n"
  "see :py:func:`pygsl.set_debug_level` for details\n";


static const char pygsl_init_get_debug_level_doc[] =
  "Get the internal debug level\n"
  "\n"
  "see :py:func:`pygsl.set_debug_level` for details\n";

static const char reg_exc_doc[] =
  "Used to register all exceptions\n"
  "\n"
  "WARNING:\n"
  "    Internal function! Do not use it if not familar!";

static const char reg_war_doc[] =
  "Used to register all exceptions\n"
  "\n"
  "WARNING:\n"
  "    Internal function! Do not use it if not familar!";

static const char eh_state_reset_doc[] =
  "Reset the stored error state\n"
  "\n"
  "User access best using: :py:data:`pygsl.errors.error_safe_state`\n";

static const char eh_state_get_doc[] =
  "Get the stored error state\n"
  "\n"
  "User access best using: :py:data:`pygsl.errors.error_safe_state`\n";

static const char vector_tf_doc[] =
  "Number of transforms required by vector objects\n"
  "\n"
  "How many times objects which were passed as vector arguments had to be\n"
  "transformed to appropriate numpy array?\n"
  "\n"
  "Args:\n"
  "     None"
  "\n"
  "Returns:\n"
  "     long: number of convertions executed"
  "\n";

static const char matrix_tf_doc[] =
  "Number of transforms required by matrix objects\n"
  "\n"
  "How many times objects which were passed as matrix arguments had to be\n"
  "transformed to appropriate numpy array?\n"
  "\n"
  "Args:\n"
  "     None"
  "\n"
  "Returns:\n"
  "     long: number of convertions executed"
  "\n";

static const char complex_tf_doc[] =
  "Number of transforms required by complex objects\n"
  "\n"
  "How many times objects which were passed as complex arguments had to be\n"
  "transformed to appropriate python object?\n"
  "\n"
  "Args:\n"
  "     None"
  "\n"
  "Returns:\n"
  "     long: number of convertions executed"
  "\n";

static const char float_tf_doc[] =
  "Number of transforms required by float objects\n"
  "\n"
  "How many times objects which were passed as float arguments had to be\n"
  "transformed to appropriate object? (e.g. an integer had to be converted\n"
  "to a float)\n"
  "\n"
  "Args:\n"
  "     None"
  "\n"
  "Returns:\n"
  "     long: number of convertions executed"
  "\n";

static PyMethodDef initMethods[] = {
     {"get_debug_level", PyGSL_get_debug_level, METH_NOARGS, pygsl_init_get_debug_level_doc},
     {"set_debug_level", PyGSL_set_debug_level, METH_VARARGS, pygsl_init_set_debug_level_doc},
     {"vector_transform_counter",  PyGSL_get_vector_transform_counter ,METH_NOARGS, vector_tf_doc},
     {"matrix_transform_counter",  PyGSL_get_matrix_transform_counter ,METH_NOARGS, matrix_tf_doc},
     {"complex_transform_counter", PyGSL_get_complex_transform_counter,METH_NOARGS, complex_tf_doc},
     {"float_transform_counter",   PyGSL_get_float_transform_counter  ,METH_NOARGS, float_tf_doc},
     {"register_exceptions",       PyGSL_register_exceptions,          METH_VARARGS, reg_exc_doc},
     {"register_warnings",         PyGSL_register_warnings,            METH_VARARGS, reg_war_doc},
     {"add_c_traceback_frames",    PyGSL_add_c_traceback_frames,       METH_VARARGS,add_c_traceback_frames_doc},
     {"error_handler_state_reset", PyGSL_pygsl_error_handler_save_reset, METH_NOARGS, eh_state_reset_doc},
     {"error_handler_state_get",   PyGSL_get_gsl_error_handler_saved_state, METH_NOARGS, eh_state_get_doc},
    {NULL,     NULL, 0, NULL}        /* Sentinel */
};

static void
PyGSL_init_api(void)
{
     int i;

     for(i=0;i<PyGSL_NENTRIES_NUM; ++i){
	  _PyGSL_API[i] = NULL;
     }
     _PyGSL_API[PyGSL_api_version_NUM                          ] = (void *) PyGSL_API_VERSION;
     _PyGSL_API[PyGSL_RNG_ObjectType_NUM                       ] = NULL;
     _PyGSL_API[PyGSL_error_flag_NUM                           ] = (void *) &PyGSL_error_flag;
     _PyGSL_API[PyGSL_error_flag_to_pyint_NUM                  ] = (void *) &PyGSL_error_flag_to_pyint;
     _PyGSL_API[PyGSL_add_traceback_NUM                        ] = (void *) &PyGSL_add_traceback;
     _PyGSL_API[PyGSL_module_error_handler_NUM                 ] = (void *) &PyGSL_module_error_handler;

     _PyGSL_API[PyGSL_error_string_for_callback_NUM            ] = (void *) & PyGSL_set_error_string_for_callback        ;
     _PyGSL_API[PyGSL_pyfloat_to_double_NUM                    ] = (void *) & PyGSL_pyfloat_to_double                    ;
     _PyGSL_API[PyGSL_pylong_to_ulong_NUM                      ] = (void *) & PyGSL_pylong_to_ulong                      ;
     _PyGSL_API[PyGSL_pylong_to_uint_NUM                       ] = (void *) & PyGSL_pylong_to_uint                       ;
     _PyGSL_API[PyGSL_check_python_return_NUM                  ] = (void *) & PyGSL_check_python_return                  ;
     _PyGSL_API[PyGSL_clear_name_NUM                           ] = (void *) & PyGSL_clear_name                           ;


     _PyGSL_API[PyGSL_PyComplex_to_gsl_complex_NUM             ] = (void *) & PyGSL_PyComplex_to_gsl_complex             ;
     _PyGSL_API[PyGSL_PyComplex_to_gsl_complex_float_NUM       ] = (void *) & PyGSL_PyComplex_to_gsl_complex_float       ;
     _PyGSL_API[PyGSL_PyComplex_to_gsl_complex_long_double_NUM ] = (void *) & PyGSL_PyComplex_to_gsl_complex_long_double ;

     _PyGSL_API[PyGSL_stride_recalc_NUM                        ] = (void *) & PyGSL_stride_recalc                        ;
     _PyGSL_API[PyGSL_PyArray_new_NUM                          ] = (void *) & PyGSL_New_Array                            ;
     _PyGSL_API[PyGSL_PyArray_copy_NUM                         ] = (void *) & PyGSL_Copy_Array                           ;
/*
     _PyGSL_API[PyGSL_PyArray_prepare_gsl_vector_view_NUM      ] = (void *) & PyGSL_PyArray_prepare_gsl_vector_view      ;
     _PyGSL_API[PyGSL_PyArray_prepare_gsl_matrix_view_NUM      ] = (void *) & PyGSL_PyArray_prepare_gsl_matrix_view      ;
*/
     _PyGSL_API[PyGSL_PyArray_generate_gsl_vector_view_NUM     ] = (void *) & PyGSL_PyArray_generate_gsl_vector_view     ;
     _PyGSL_API[PyGSL_PyArray_generate_gsl_matrix_view_NUM     ] = (void *) & PyGSL_PyArray_generate_gsl_matrix_view     ;
     _PyGSL_API[PyGSL_copy_pyarray_to_gslvector_NUM            ] = (void *) & PyGSL_copy_pyarray_to_gslvector            ;
     _PyGSL_API[PyGSL_copy_pyarray_to_gslmatrix_NUM            ] = (void *) & PyGSL_copy_pyarray_to_gslmatrix            ;
     _PyGSL_API[PyGSL_copy_gslvector_to_pyarray_NUM            ] = (void *) & PyGSL_copy_gslvector_to_pyarray            ;
     _PyGSL_API[PyGSL_copy_gslmatrix_to_pyarray_NUM            ] = (void *) & PyGSL_copy_gslmatrix_to_pyarray            ;

     _PyGSL_API[PyGSL_gsl_rng_from_pyobject_NUM                ] = (void *) & PyGSL_gsl_rng_from_pyobject                ;
     _PyGSL_API[PyGSL_function_wrap_helper_NUM                 ] = (void *) & PyGSL_function_wrap_helper                 ;
     _PyGSL_API[PyGSL_register_debug_flag_NUM                  ] = (void *) & PyGSL_register_debug_flag                  ;
     _PyGSL_API[PyGSL_vector_or_double_NUM                     ] = (void *) & PyGSL_vector_or_double                     ;
     _PyGSL_API[PyGSL_warning_NUM                              ] = (void *) & PyGSL_warning                              ;
     _PyGSL_API[PyGSL_pyint_to_int_NUM                         ] = (void *) & PyGSL_pyint_to_int                         ;
     _PyGSL_API[PyGSL_vector_check_NUM                         ] = (void *) & PyGSL_vector_check                         ;
     _PyGSL_API[PyGSL_matrix_check_NUM                         ] = (void *) & PyGSL_matrix_check                         ;
     _PyGSL_API[PyGSL_array_check_NUM                          ] = (void *) & PyGSL_array_check                          ;
     _PyGSL_API[PyGSL_string_as_string_NUM                     ] = (void *) &_PyGSL_string_as_string                     ;
}

static const char pygsl_init_m_doc[] =
  "pygsl.init module\n"
"\n"
"This module is a collection of internal conversion function. These functions\n"
"typically need not be accessed by the pygsl user. All functionality is wrapped\n"
"by appropriate functions and exported to the user at a higher level\n"
"\n"
"WARNING:\n"
"    Please note the functions given here change the total behaviour of pygsl.\n"
"    If wrongly used it could even crash the program.\n"
"\n";

#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.init",
        pygsl_init_m_doc,
        -1,
        initMethods,
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
PyMODINIT_FUNC
PyInit_init(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) initinit(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
  PyObject *m = NULL, *d = NULL, *version=NULL, *date=NULL, *api = NULL;

#ifdef PyGSL_PY3K
  m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
  m = Py_InitModule("pygsl.init", initMethods);
#endif /* PyGSL_PY3K */

  import_array();


  if(m == NULL){
       fprintf(stderr, "I could not init pygsl.init!");
       return RETVAL;
  }

  d = PyModule_GetDict(m);
  if(d == NULL){
       fprintf(stderr, "I could not get the module dict for  pygsl.init!");
       return RETVAL;
  }

  PyGSL_init_api();

  if(PyGSL_init_errno() != 0){
       PyErr_SetString(PyExc_ImportError, "Failed to init errno handling!");
  }
  PyGSL_API = _PyGSL_API;
  PyGSL_SET_ERROR_HANDLER();

  api = PyCapsule_New((void *) PyGSL_API, _PyGSL_API_CAP_NAME,NULL);
  assert(api);
  if (PyDict_SetItemString(d, "_PYGSL_API", api) != 0){
       PyErr_SetString(PyExc_ImportError,
		       "I could not add  _PYGSL_API!");
       return RETVAL;
  }

  version = PyGSL_string_from_string(GSL_VERSION);
  if(version == NULL){
       fprintf(stderr, "I could not create the version string for pygsl.init!");
       return RETVAL;
  }
  if(PyDict_SetItemString(d, "compiled_gsl_version", version) != 0){
       fprintf(stderr, "I could not add the compile version string to the module dict of pygsl.init!");
       return RETVAL;
  }

  version = PyGSL_string_from_string(gsl_version);
  if(version == NULL){
       fprintf(stderr, "I could not create the version string for pygsl.init!");
       return RETVAL;
  }
  if(PyDict_SetItemString(d, "run_gsl_version", version) != 0){
       fprintf(stderr, "I could not add the run version string to the module dict of pygsl.init!");
       return RETVAL;
  }

  date = PyGSL_string_from_string(DATE " " TIME);
  if(version == NULL){
       fprintf(stderr, "I could not create the date string for pygsl.init!");
       return RETVAL;
  }
  if(PyDict_SetItemString(d, "compile_date", date) != 0){
       fprintf(stderr, "I could not add the date version string to the module dict of pygsl.init!");
       return RETVAL;
  }

  if((debuglist = PyList_New(0)) == NULL){
       fprintf(stderr, "Failed to init Debug list!\n");
  }
  /*
   * These functions will be moved to the approbriate modules and the user will
   * have to call them explicitly when needed.
   */

  return RETVAL;
}
