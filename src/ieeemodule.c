/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/ieeemodule.c
 * $Id$
 *
 */

#include <gsl/gsl_math.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_errno.h>
#include <Python.h>
#include <pygsl/error_helpers.h>
#include <pygsl/general_helpers.h>
/*
 * constants definitions
 */

typedef struct {
  char *name;
  int flag;
} const_int_names;

static const_int_names ieeeConsts[] = {
  /* used as precision argument in set_mode*/
  {"single_precision",GSL_IEEE_SINGLE_PRECISION},
  {"double_precision",GSL_IEEE_DOUBLE_PRECISION},
  {"extended_precision",GSL_IEEE_EXTENDED_PRECISION},
  /* used as round argument in set_mode*/
  {"round_to_nearest",GSL_IEEE_ROUND_TO_NEAREST},
  {"round_down",GSL_IEEE_ROUND_DOWN},
  {"round_up",GSL_IEEE_ROUND_UP},
  {"round_to_zero",GSL_IEEE_ROUND_TO_ZERO},
  /* used as exception argument in set_mode*/
  {"mask_invalid",GSL_IEEE_MASK_INVALID},
  {"mask_denormalized",GSL_IEEE_MASK_DENORMALIZED},
  {"mask_division_by_zero",GSL_IEEE_MASK_DIVISION_BY_ZERO},
  {"mask_overflow",GSL_IEEE_MASK_OVERFLOW},
  {"mask_underflow",GSL_IEEE_MASK_UNDERFLOW},
  {"mask_all",GSL_IEEE_MASK_ALL},
  {"trap_inexact",GSL_IEEE_TRAP_INEXACT},
  /* used as type in ieee_*_rep */
  {"type_nan",GSL_IEEE_TYPE_NAN},
  {"type_inf",GSL_IEEE_TYPE_INF},
  {"type_normal",GSL_IEEE_TYPE_NORMAL},
  {"type_denormal",GSL_IEEE_TYPE_DENORMAL},
  {"type_zero",GSL_IEEE_TYPE_ZERO},
  /* sentinel */
  {NULL,0}
};

static void define_const_ints(PyObject* module)
{
  int i=0;

  while (ieeeConsts[i].name!=NULL)
    {
      PyModule_AddIntConstant(module,ieeeConsts[i].name,ieeeConsts[i].flag);
      i++;
    }
  return;
}

/*
 * method definitions
 */

static PyObject* set_mode(PyObject *self,
			  PyObject *args
			  )
{
  int precision=2;
  int rounding=1;
  int exception_mask=GSL_IEEE_MASK_ALL;

  if (!PyArg_ParseTuple(args, "|iii", &precision, &rounding,  &exception_mask))
    return NULL;
  
 
  if (GSL_SUCCESS!=   PyGSL_error_flag(gsl_ieee_set_mode(precision, rounding, exception_mask)))
    return NULL;

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* env_setup(PyObject *self,
			   PyObject *args
			   )
{
  gsl_ieee_env_setup();
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* bin_repr(PyObject *self,
			  PyObject *args
			  )
{
  double x;
  gsl_ieee_double_rep r;
  if (!PyArg_ParseTuple(args,"d", &x))
      return NULL;
  gsl_ieee_double_to_rep(&x,&r);
  return Py_BuildValue("(isii)",r.sign,r.mantissa,r.exponent,r.type);
}

static PyObject* ieee_isnan(PyObject *self,
			    PyObject *arg
     )
{
     double tmp;
     if(PyGSL_PYFLOAT_TO_DOUBLE(arg, &tmp, NULL) != GSL_SUCCESS)
	  return NULL;
     return PyInt_FromLong(gsl_isnan(tmp));
}
static PyObject* ieee_isinf(PyObject *self,
			    PyObject *arg
     )
{
     double tmp;
     if(PyGSL_PYFLOAT_TO_DOUBLE(arg, &tmp, NULL) != GSL_SUCCESS)
	  return NULL;
     return PyInt_FromLong(gsl_isinf(tmp));

}

static PyObject* ieee_finite(PyObject *self,
		       PyObject *arg
		       )
{
     double tmp;
     if(PyGSL_PYFLOAT_TO_DOUBLE(arg, &tmp, NULL) != GSL_SUCCESS)
	  return NULL;
     return PyInt_FromLong(gsl_finite(tmp));

}

static PyObject* ieee_nan(PyObject *self)
{
  return PyFloat_FromDouble(GSL_NAN);
}

static PyObject* ieee_neginf(PyObject *self)
{
  return PyFloat_FromDouble(GSL_NEGINF);
}

static PyObject* ieee_posinf(PyObject *self)
{
  return PyFloat_FromDouble(GSL_POSINF);
}

static PyMethodDef ieeeMethods[] = {
  {"set_mode", set_mode, METH_VARARGS},
  {"env_setup", env_setup, METH_NOARGS},
  {"bin_repr", bin_repr, METH_VARARGS},
  /* tests on special IEEE-FP meanings */
  {"isnan",ieee_isnan,METH_O},
  {"isinf",ieee_isinf,METH_O},
  {"finite",ieee_finite,METH_O},
  /* some special ieee-numbers */
  {"nan",(PyCFunction)ieee_nan, METH_NOARGS},
  {"neginf",(PyCFunction)ieee_neginf, METH_NOARGS},
  {"posinf",(PyCFunction)ieee_posinf, METH_NOARGS},
  {NULL,     NULL}        /* Sentinel */
};

DL_EXPORT(void) initieee(void)
{
  PyObject* m;

  m=Py_InitModule("ieee", ieeeMethods);
  init_pygsl();
  define_const_ints(m);

  return;
}
