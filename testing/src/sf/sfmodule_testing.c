/*
 * author: Pierre Schnizer
 * created: June 2003
 */
#include <pygsl/error_helpers.h>
#include <pygsl/string_helpers.h>
#include <pygsl/arrayobject.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_nan.h>
#undef _PyGSL_UFUNC_SUPPORTED
#ifdef PyGSL_NUMPY
#include <numpy/arrayobject.h>
#include <numpy/ufuncobject.h>
#define _PyGSL_UFUNC_SUPPORTED
#endif
#ifdef PyGSL_NUMERIC
#include <Numeric/arrayobject.h>
#include <Numeric/ufuncobject.h>
#define _PyGSL_UFUNC_SUPPORTED
#endif
#ifndef _PyGSL_UFUNC_SUPPORTED
#error "UFUNCs not supported by the selected/found array module!"
#endif
/*
   #include <pygsl/utils.h>
   #include <pygsl/error_helpers.h>
*/

static PyObject* module = NULL; /*used by the backtrace*/

#define IMPORTALL 1


/* I add the evaluate functions types by hand to have an extra check */
#ifdef IMPORTALL
#include "sf__arrays.c"


#undef SF_ARRAY
#endif

#ifdef IMPORTALL
#include "sf__evals.c" 
#include "sf__data.c"
#endif

static void * polar_to_rect_data [] = { (void *) gsl_sf_polar_to_rect, (void *) gsl_sf_polar_to_rect};
static void * rect_to_polar_data [] = { (void *) gsl_sf_rect_to_polar, (void *) gsl_sf_rect_to_polar};

static char PyGSL_sf_ufunc_qi_dd_D_one_types [] = { NPY_FLOAT,  NPY_FLOAT,  NPY_CFLOAT, 
                                                    NPY_DOUBLE, NPY_DOUBLE, NPY_CDOUBLE };

static char PyGSL_sf_ufunc_qi_D_dd_one_types [] = { NPY_CFLOAT,  NPY_FLOAT,  NPY_FLOAT, 
                                                    NPY_CDOUBLE, NPY_DOUBLE, NPY_DOUBLE };

typedef int PyGSL_sf_ufunc_qi_dd_D_one(double, double, gsl_sf_result *, gsl_sf_result *);
void  PyGSL_sf_ufunc_qi_dd_D(char **args, int *dimensions, int *steps, void *func)
{
        int is0=steps[0], is1=steps[1], os0=steps[2];
        char   *ip0=args[0], *ip1=args[1], *op0=args[2];
	double *dop;

	gsl_sf_result x, y;
	int tmp;
	PyGSL_array_index_t i;
	FUNC_MESS_BEGIN();
	DEBUG_MESS(2, "dimensions = %d %d %d", dimensions[0], dimensions[1],dimensions[2]);
	DEBUG_MESS(2, "steps = %d %d %d", steps[0], steps[1], steps[2]);
	DEBUG_MESS(2, "args = %p %p %p", args[0], args[1], args[2]);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, ip1+=is1, op0+=os0){
	     DEBUG_MESS(2, "i = %ld", (long)i);
	    dop = ((double *) op0);
	    tmp = ((PyGSL_sf_ufunc_qi_dd_D_one *) func)(*((double *)ip0), *((double *)ip1), &x, &y);
	    dop[0] = x.val;
	    dop[1] = y.val;
        }
	FUNC_MESS_END();
}
void  PyGSL_sf_ufunc_qi_dd_D_as_ff_F(char **args, int *dimensions, int *steps, void *func)
{
        int i,  is0=steps[0], is1=steps[1], os0=steps[2], tmp;
        char   *ip0=args[0], *ip1=args[1], *op0=args[2];
	gsl_sf_result x, y;

	FUNC_MESS_BEGIN();
	DEBUG_MESS(2, "dimensions = %d %d %d", dimensions[0], dimensions[1],dimensions[2]);
	DEBUG_MESS(2, "steps = %d %d %d", steps[0], steps[1], steps[2]);
	DEBUG_MESS(2, "args = %p %p %p", args[0], args[1], args[2]);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, ip1+=is1, op0+=os0){	     
	     DEBUG_MESS(2, "i = %d", i);
	     tmp = ((PyGSL_sf_ufunc_qi_dd_D_one *) func)((double) *((float *)ip0), (double) *((float *)ip1), &x, &y);
	     *((float *)op0) = (float) x.val;
	     *(((float *)op0)+1) = (float) y.val;
        }
	FUNC_MESS_END();
}
static PyUFuncGenericFunction PyGSL_sf_ufunc_qi_dd_D_one_data[] = {PyGSL_sf_ufunc_qi_dd_D_as_ff_F, PyGSL_sf_ufunc_qi_dd_D};

typedef int PyGSL_sf_ufunc_qi_D_dd_one(double, double, gsl_sf_result *, gsl_sf_result *);
void  PyGSL_sf_ufunc_qi_D_dd(char **args, int *dimensions, int *steps, void *func)
{
	int tmp;
	PyGSL_array_index_t i,  is0=steps[0], os0=steps[1], os1=steps[2];
        char   *ip0=args[0], *op0=args[1], *op1=args[2];
	double *dip;
	gsl_sf_result radius, angle;

	FUNC_MESS_BEGIN();
	DEBUG_MESS(2, "dimensions = %d %d %d", dimensions[0], dimensions[1],dimensions[2]);
	DEBUG_MESS(2, "steps = %d %d %d", steps[0], steps[1], steps[2]);
	DEBUG_MESS(2, "args = %p %p %p", args[0], args[1], args[2]);
	DEBUG_MESS(1, "rect_to_polar %p", (void *)func);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, op0+=os0, op1+=os1){
	     DEBUG_MESS(2, "i = %ld", (long)i);
	    dip = ((double *) ip0);
	    tmp = ((PyGSL_sf_ufunc_qi_D_dd_one *) func)(dip[0], dip[1], &radius, &angle);
	    *((double *)op0) = radius.val;
	    *((double *)op1) = angle.val;
        }
	FUNC_MESS_END();
}
void  PyGSL_sf_ufunc_qi_D_dd_as_F_ff(char **args, int *dimensions, int *steps, void *func)
{
        PyGSL_array_index_t i,  is0=steps[0], os0=steps[1],  os1=steps[2], tmp;
        char   *ip0=args[0],  *op0=args[1], *op1=args[2];
	gsl_sf_result radius, angle;
	FUNC_MESS_BEGIN();
	DEBUG_MESS(2, "dimensions = %d %d %d", dimensions[0], dimensions[1],dimensions[2]);
	DEBUG_MESS(2, "steps = %d %d %d", steps[0], steps[1], steps[2]);
	DEBUG_MESS(2, "args = %p %p %p", args[0], args[1], args[2]);
	DEBUG_MESS(1, "polar_to_rect %p", (void *)func);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, op0+=os0, op1+=os1){
	     tmp = ((PyGSL_sf_ufunc_qi_D_dd_one *) func)((double) *((float *)ip0), (double) *(((float *)ip0)+1), &radius, &angle);
	     DEBUG_MESS(2, "i = %ld", (long)i);
	      *((float *)op0) = (float) radius.val;
	      *((float *)op1) = (float) angle.val;
	}
	FUNC_MESS_END();
}
static PyUFuncGenericFunction PyGSL_sf_ufunc_qi_D_dd_one_data[] = {PyGSL_sf_ufunc_qi_D_dd_as_F_ff, PyGSL_sf_ufunc_qi_D_dd};


static char *PyGSL_polar_to_rect_doc = "Convert r, theta into a complex representation";
static char *PyGSL_rect_to_polar_doc = "Convert a complex into r and theta. Theta will be in the range [-pi,pi]";
static char * sf_module_doc = 
"GSL Special Functions wrapped mostly as Numeric ufuncs. \n\
Use print sf.<function>.__doc__ to get more information about the ufunc.\n\
Help does not display the information stored there!\n";

#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.testing.sf",
        NULL,
        -1,
        sf_array_functions,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif 

#ifdef PyGSL_PY3K
PyObject *PyInit__ufuncs(void)
#define RETVAL sf_module
#else /* PyGSL_PY3K */
DL_EXPORT(void) init_ufuncs(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
  PyObject* sf_module=NULL, *sf_dict=NULL;
  PyObject* f=NULL, *item=NULL;

  FUNC_MESS_BEGIN();
  DEBUG_MESS(2, "Module compiled at %s %s\n", __DATE__, __TIME__);

#ifdef PyGSL_PY3K
  sf_module = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */    
  sf_module=Py_InitModule("_ufuncs", sf_array_functions);
#endif /* PyGSL_PY3K */
  if(sf_module == NULL)
    goto fail;
  
  module = sf_module;

  import_array();
  import_ufunc();
  init_pygsl();

  /* here is an error check needed! */
  /*
  gsl_errors_module=PyImport_ImportModule ("pygsl.errors");

  gsl_errors_dict=PyModule_GetDict(gsl_errors_module);
  gsl_module_error=PyDict_GetItemString(gsl_errors_dict,"gsl_Error");
  */


  sf_dict=PyModule_GetDict(sf_module);
  if (!(item = PyGSL_string_from_string(sf_module_doc))){
       PyErr_SetString(PyExc_ImportError, 
		       "I could not generate module doc string!");
       goto fail;
  }
  if (PyDict_SetItemString(sf_dict, "__doc__", item) != 0){
       PyErr_SetString(PyExc_ImportError, 
		       "I could not add doc string to module dict!");
       goto fail;
  }

  PyDict_SetItemString(sf_dict, "PREC_DOUBLE", PyLong_FromLong((long) GSL_PREC_DOUBLE));
  PyDict_SetItemString(sf_dict, "PREC_SINGLE", PyLong_FromLong((long) GSL_PREC_SINGLE));
  PyDict_SetItemString(sf_dict, "PREC_APPROX", PyLong_FromLong((long) GSL_PREC_APPROX));

  DEBUG_MESS(1, "polar_to_rect %p", (void *)gsl_sf_polar_to_rect);
  f = PyUFunc_FromFuncAndData(PyGSL_sf_ufunc_qi_dd_D_one_data,
			      polar_to_rect_data,
			      PyGSL_sf_ufunc_qi_dd_D_one_types,
			      2, /* number of supported types */
			      2, /* in args */
			      1, /* out args */
			      PyUFunc_None,
			      "polar_to_rect",
			      PyGSL_polar_to_rect_doc,
			      0 /*check return*/);   
  PyDict_SetItemString(sf_dict, "polar_to_rect", f);
  /* Py_DECREF(f); */

  DEBUG_MESS(1, "rect_to_polar %p", (void *)gsl_sf_rect_to_polar);
  f = PyUFunc_FromFuncAndData(PyGSL_sf_ufunc_qi_D_dd_one_data,
			      rect_to_polar_data,
			      PyGSL_sf_ufunc_qi_D_dd_one_types,
			       2, /* number of supported types */
			       1, /* in args */
			       2, /* out args */
			       PyUFunc_None,
			       "rect_to_polar",
			       PyGSL_rect_to_polar_doc,
			       0 /*check return*/);   
  PyDict_SetItemString(sf_dict, "rect_to_polar", f);
  /* Py_DECREF(f); */

#ifdef IMPORTALL
#include "sf__objects.c"
#endif

  FUNC_MESS_END();
  return RETVAL;

 fail:
     if(!PyErr_Occurred()){
	  PyErr_SetString(PyExc_ImportError, "I could not init sf module!");
     }
     /* shold the module be derefed ?? */
     return RETVAL;
}
