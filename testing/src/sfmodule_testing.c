/*
 * author: Pierre Schnizer
 * created: June 2003
 */
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_nan.h>
#include <pygsl/block_helpers.h>
#include <Python.h>
#include <Numeric/arrayobject.h>
#include <Numeric/ufuncobject.h>
#include <pygsl/error_helpers.h>
/*
   #include <pygsl/utils.h>
   #include <pygsl/error_helpers.h>
*/

static PyObject* gsl_module_error;
static PyObject* module = NULL; /*used by the backtrace*/

#if 1
static void 
invoke_error_handler(char *filename, char *func_name, int errno, int element);

static void 
invoke_error_handler(char *filename, char *func_name, int errno, int element)
{
     ;
     /* DEBUG_MESS(2, "Got error flag of %d for element number %d", errno, element); */
}
#endif
/* I add the evaluate functions types by hand to have an extra check */
#if 1
#include "sf__arrays.c"

#define SF_ARRAY(name, function)                                           \
static PyObject* sf_ ## name      (PyObject *self, PyObject *args)         \
{                                                                          \
     PyObject * tmp;                                                       \
     FUNC_MESS_BEGIN();                                                    \
     tmp =  PyGSL_sf_array_evaluator_ ## function (self, args, gsl_sf_ ## name); \
     if (tmp == NULL){                                                     \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__,  __LINE__);  \
     }                                                                     \
     FUNC_MESS_END();                                                      \
     return tmp;                                                           \
}

SF_ARRAY(bessel_Jn_array, iid_ad);
SF_ARRAY(bessel_Yn_array, iid_ad);
SF_ARRAY(bessel_In_array, iid_ad);
SF_ARRAY(bessel_Kn_array, iid_ad);
SF_ARRAY(bessel_Kn_scaled_array, iid_ad);
SF_ARRAY(bessel_jl_array, id_ad);
SF_ARRAY(bessel_jl_steed_array, id_ad);
SF_ARRAY(bessel_yl_array, id_ad);
SF_ARRAY(bessel_il_scaled_array, id_ad);
SF_ARRAY(bessel_kl_scaled_array, id_ad);

#undef SF_ARRAY
#endif

static PyMethodDef sf_functions[] = {
#if 1
     {"bessel_Jn_array", (PyCFunction) sf_bessel_Jn_array, METH_VARARGS, NULL},
     {"bessel_Yn_array", (PyCFunction) sf_bessel_Yn_array, METH_VARARGS, NULL},
     {"bessel_In_array", (PyCFunction) sf_bessel_In_array, METH_VARARGS, NULL},
     {"bessel_Kn_array", (PyCFunction) sf_bessel_Kn_array, METH_VARARGS, NULL},
     {"bessel_Kn_scaled_array", (PyCFunction) sf_bessel_Kn_scaled_array, METH_VARARGS, NULL},
     {"bessel_jl_array", (PyCFunction) sf_bessel_jl_array, METH_VARARGS, NULL},
     {"bessel_jl_steed_array", (PyCFunction) sf_bessel_jl_steed_array, METH_VARARGS, NULL},
     {"bessel_yl_array", (PyCFunction) sf_bessel_yl_array, METH_VARARGS, NULL},
     {"bessel_il_scaled_array", (PyCFunction) sf_bessel_il_scaled_array, METH_VARARGS, NULL},
     {"bessel_kl_scaled_array", (PyCFunction) sf_bessel_kl_scaled_array, METH_VARARGS, NULL},
#endif
     {NULL, NULL, 0}
};

#include "sf__evals.c" 
#include "sf__data.c"

static void * polar_to_rect_data [] = { (void *) gsl_sf_polar_to_rect, (void *) gsl_sf_polar_to_rect};
static void * rect_to_polar_data [] = { (void *) gsl_sf_rect_to_polar, (void *) gsl_sf_rect_to_polar};

static char PyGSL_sf_ufunc_qi_dd_D_one_types [] = { PyArray_FLOAT,  PyArray_FLOAT,  PyArray_CFLOAT, 
                                                    PyArray_DOUBLE, PyArray_DOUBLE, PyArray_CDOUBLE };

static char PyGSL_sf_ufunc_qi_D_dd_one_types [] = { PyArray_CFLOAT,  PyArray_FLOAT,  PyArray_FLOAT, 
                                                    PyArray_CDOUBLE, PyArray_DOUBLE, PyArray_DOUBLE };

typedef int PyGSL_sf_ufunc_qi_dd_D_one(double, double, double *, double *);
void  PyGSL_sf_ufunc_qi_dd_D(char **args, int *dimensions, int *steps, void *func)
{
        int is0=steps[0], is1=steps[1], os0=steps[2];
        char   *ip0=args[0], *ip1=args[1], *op0=args[2];
	double *dop, tmp1, tmp2;


	int i, tmp;
	fprintf(stderr, "Function %s dimensions=%d\n", __FUNCTION__, dimensions[0]);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, ip1+=is1, op0+=os0){
	     fprintf(stderr, "i=%d\n", i);
	    dop = ((double *) op0);
	    tmp = ((PyGSL_sf_ufunc_qi_dd_D_one *) func)(*((double *)ip0), *((double *)ip1), &tmp1, &tmp2);
	    dop[0] = tmp1;
	    dop[1] = tmp2;
        }
	fprintf(stderr, "End!\n");
}
void  PyGSL_sf_ufunc_qi_dd_D_as_ff_F(char **args, int *dimensions, int *steps, void *func)
{
        int i,  is0=steps[0], is1=steps[1], os0=steps[2], tmp;
        char   *ip0=args[0], *ip1=args[1], *op0=args[2];
	double tmp1, tmp2;
	fprintf(stderr, "Function %s\n", __FUNCTION__);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, ip1+=is1, op0+=os0){	     
                tmp = ((PyGSL_sf_ufunc_qi_dd_D_one *) func)((double) *((float *)ip0), (double) *((float *)ip1), &tmp1, &tmp2);
		*((float *)op0) = (float) tmp1;
		*(((float *)op0)+1) = (float) tmp2;
        }
}
static PyUFuncGenericFunction PyGSL_sf_ufunc_qi_dd_D_one_data[] = {PyGSL_sf_ufunc_qi_dd_D_as_ff_F, PyGSL_sf_ufunc_qi_dd_D};

typedef int PyGSL_sf_ufunc_qi_D_dd_one(double, double, double *, double*);
void  PyGSL_sf_ufunc_qi_D_dd(char **args, int *dimensions, int *steps, void *func)
{
        int i,  is0=steps[0], os0=steps[1], os1=steps[2], tmp;
        char   *ip0=args[0], *op0=args[1], *op1=args[2];
	double *dip;
	fprintf(stderr, "Function %s\n", __FUNCTION__);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, op0+=os0, op1+=os1){
	    dip = ((double *) ip0);
	    tmp = ((PyGSL_sf_ufunc_qi_D_dd_one *) func)(dip[0], dip[1], ((double *)op0), ((double *)op1));
        }
}
void  PyGSL_sf_ufunc_qi_D_dd_as_F_ff(char **args, int *dimensions, int *steps, void *func)
{
        int i,  is0=steps[0], os0=steps[1],  os1=steps[2], tmp;
        char   *ip0=args[0],  *op0=args[1], *op1=args[2];
	double tmp2, tmp1;
	fprintf(stderr, "Function %s\n", __FUNCTION__);
        for(i = 0; i<dimensions[0]; i++, ip0+=is0, op0+=os0, op1+=os1){
	     tmp = ((PyGSL_sf_ufunc_qi_D_dd_one *) func)((double) *((float *)ip0), (double) *(((float *)ip0)+1), &tmp1, &tmp2);
	      *((float *)op0) = (float) tmp1;
	      *((float *)op1) = (float) tmp2;
	}
}
static PyUFuncGenericFunction PyGSL_sf_ufunc_qi_D_dd_one_data[] = {PyGSL_sf_ufunc_qi_D_dd_as_F_ff, PyGSL_sf_ufunc_qi_D_dd};


static char *PyGSL_polar_to_rect_doc = "Convert r, theta into a complex representation";
static char *PyGSL_rect_to_polar_doc = "Convert a complex into r and theta. Theta will be in the range [-pi,pi]";
static char * sf_module_doc = 
"GSL Special Functions wrapped mostly as Numeric ufuncs. \n\
Use print sf.<function>.__doc__ to get more information about the ufunc.\n\
Help does not display the information stored there!\n";

DL_EXPORT(void) initsf(void)
{
  PyObject* gsl_errors_module=NULL;
  PyObject* sf_module=NULL, *sf_dict=NULL;
  PyObject* gsl_errors_dict=NULL;
  PyObject* f=NULL, *item=NULL;

  fprintf(stderr, "Module compiled at %s %s\n", __DATE__, __TIME__);
  sf_module=Py_InitModule("sf", sf_functions);
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
  if (!(item = PyString_FromString(sf_module_doc))){
       PyErr_SetString(PyExc_ImportError, 
		       "I could not generate module doc string!");
       goto fail;
  }
  if (PyDict_SetItemString(sf_dict, "__doc__", item) != 0){
       PyErr_SetString(PyExc_ImportError, 
		       "I could not add doc string to module dict!");
       goto fail;
  }

  PyDict_SetItemString(sf_dict, "PREC_DOUBLE", PyInt_FromLong(GSL_PREC_DOUBLE));
  PyDict_SetItemString(sf_dict, "PREC_SINGLE", PyInt_FromLong(GSL_PREC_SINGLE));
  PyDict_SetItemString(sf_dict, "PREC_APPROX", PyInt_FromLong(GSL_PREC_APPROX));

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

 #include "sf__objects.c"


  return;

 fail:
     if(!PyErr_Occurred()){
	  PyErr_SetString(PyExc_ImportError, "I could not init sf module!");
     }
}
