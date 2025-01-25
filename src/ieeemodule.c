/*
 * author: Achim Gaedke
 * created: May 2001
 * file: pygsl/src/ieeemodule.c
 * $Id$
 *
 */
#include <pygsl/error_helpers.h>
#include <pygsl/general_helpers.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_errno.h>
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

static PyObject*
set_mode(PyObject *self, PyObject *args)
{
  int precision=2;
  int rounding=1;
  int exception_mask=GSL_IEEE_MASK_ALL;
  int flag;
  if (!PyArg_ParseTuple(args, "|iii", &precision, &rounding,  &exception_mask))
    return NULL;


  flag = gsl_ieee_set_mode(precision, rounding, exception_mask);
  if (GSL_SUCCESS != PyGSL_error_flag(flag))
    return NULL;

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject*
env_setup(PyObject *self, PyObject *args)
{
  gsl_ieee_env_setup();
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject*
bin_repr(PyObject *self, PyObject *args)
{
  double x;
  gsl_ieee_double_rep r;
  if (!PyArg_ParseTuple(args,"d", &x))
      return NULL;
  gsl_ieee_double_to_rep(&x,&r);
  return Py_BuildValue("(isii)",r.sign,r.mantissa,r.exponent,r.type);
}

static PyObject*
ieee_isnan(PyObject *self, PyObject *arg)
{
     double tmp;
     if(PyGSL_PYFLOAT_TO_DOUBLE(arg, &tmp, NULL) != GSL_SUCCESS)
	  return NULL;
     return PyLong_FromLong(gsl_isnan(tmp));
}

static PyObject*
ieee_isinf(PyObject *self, PyObject *arg)
{
     double tmp;
     if(PyGSL_PYFLOAT_TO_DOUBLE(arg, &tmp, NULL) != GSL_SUCCESS)
	  return NULL;
     return PyLong_FromLong(gsl_isinf(tmp));

}

static PyObject*
ieee_finite(PyObject *self, PyObject *arg)
{
     double tmp;
     if(PyGSL_PYFLOAT_TO_DOUBLE(arg, &tmp, NULL) != GSL_SUCCESS)
	  return NULL;
     return PyLong_FromLong(gsl_finite(tmp));

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

/* setup gsl mode and ieee modes from environment variable GSL_IEEE_MODE */

static const char env_setup_doc[] =
"Set the IEEE mode, the GSL library should use, using the GSL_IEEE_MODE\n\
  environement variable\n\n\
You can also use os.environ['GSL_IEEE_MODE']='<desired_behaviour>' to\n\
set the variable\n\
\n\
Calls :c:func:`gsl_ieee_env_setup()`\n\
";

static const char bin_repr_doc[] =
"takes a double and returns its  sign, mantissa, exponent and type\n";

static const char set_mode_doc[] =
".. py:function:: set_mode(precision, rounding, exception_mask)\n\
    \n\
    Sets the ieee float handling mode\n\n\
    \n\
    Args:\n\
       precision      : one of :py:data:`single_precision` , :py:data:`double_precision` , :py:data:`extended_precision` \n\
       rounding       : one of :py:data:`round_to_nearest` , :py:data:`round_down` , :py:data:`round_up` , :py:data:`round_to_zero` \n\
       exception_mask : \n\
    \n\
    Each flag can be a combination of the constants defined in this module\n \
    Raises  gsl_NoHardwareSupportError if support is not available.\n\
    \n\
    WARNING:\n\
       Use with care! It can abort your programm abnormaly!\n";

static const char pygsl_finite_doc[] = "Returns if the number is finite. \n\
\n\
Wrapper for :c:func:`gsl_finite`\n\
\n\
Args:\n\
    o: python object\n\
\n\
Returns:\n\
    bool: if finite or not\n\
";

static const char pygsl_ieee_isnan[] = "Returns if the object is Nan\n\
\n\
Wrapper for :c:func:`gsl_isnan`\n\
\n\
Args:\n\
    o: python object\n\
\n\
Returns:\n\
    bool: if Nan or not\n\
";

static const char pygsl_ieee_isinf[] = "Returns if the object is inif\n\
\n\
Wrapper for :c:func:`gsl_isinf`\n\
\n\
Args:\n\
    o: python object\n\
\n\
Returns:\n\
    bool: \n\
";

static const char  ieee_nan_doc[] = "Returns not a number\n";
static const char  ieee_neginf_doc[] = "Returns a negative infinite: Inf\n";
static const char  ieee_posinf_doc[] = "Returns a positive infinite: -Inf\n";
static PyMethodDef ieeeMethods[] = {
  {"set_mode", set_mode, METH_VARARGS, (char*)set_mode_doc},
  {"env_setup", env_setup, METH_NOARGS,  (char *)env_setup_doc},
  {"bin_repr", bin_repr, METH_VARARGS, NULL},
  /* tests on special IEEE-FP meanings */
  {"isnan",ieee_isnan,METH_O, pygsl_ieee_isnan},
  {"isinf",ieee_isinf,METH_O, pygsl_ieee_isinf},
  {"finite",ieee_finite,METH_O, pygsl_finite_doc},
  /* some special ieee-numbers */
  {"nan",(PyCFunction)ieee_nan, METH_NOARGS, (char *)ieee_nan_doc},
  {"neginf",(PyCFunction)ieee_neginf, METH_NOARGS, (char *)ieee_neginf_doc},
  {"posinf",(PyCFunction)ieee_posinf, METH_NOARGS, (char *)ieee_posinf_doc},
  {NULL,     NULL}        /* Sentinel */
};


static const char pygsl_ieee_m_doc[] =
  "ieee interface\n"
  "\n"
  "Wrappers for the functionality provided by  :std:ref:`chap_ieee`\n";

#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.ieee",
        pygsl_ieee_m_doc,
        -1,
	ieeeMethods,
        NULL,
        NULL,
        NULL,
        NULL
};
#endif /* PyGSL_PY3K */

#ifdef __cplusplus
extern "C"
#endif

#ifdef PyGSL_PY3K
PyMODINIT_FUNC PyInit_ieee(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) initieee(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
  PyObject* m;

#ifdef PyGSL_PY3K
	m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
  m=Py_InitModule("ieee", ieeeMethods);
#endif /* PyGSL_PY3K */

  if (m == NULL)
    return RETVAL;

  init_pygsl();
  define_const_ints(m);

  return RETVAL;
}
