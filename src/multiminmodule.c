/*
 * author: Achim Gaedke
 * created: January 2002
 * file: pygsl/src/multiminmodule.c
 * $Id$
 */

#include <Python.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_multimin.h>
#include <pygsl/error_helpers.h>

typedef struct {
  PyObject_HEAD
  size_t n;
  gsl_multimin_fminimizer* min;
  gsl_multimin_function* func;
  PyObject* py_function;
  PyObject* trailing_params;
} multimin_multiminObject;

double pygsl_multimin_function(const gsl_vector* x, void* params) {
  PyObject* trailing_params;
  PyObject* function;
  PyObject* result_py;
  PyObject* result_float;
  PyObject* args;
  PyObject* args_tuple;
  double result;
  int i;
  int length;

  /* construct argument list for python function */
  args=PyList_New(0);
  /* the optimization parameters are the first arguments */
  for (i=0;i<x->size;i++) {
    PyObject* arg=PyFloat_FromDouble(gsl_vector_get(x,i));
    if (arg==NULL) {
      Py_DECREF(args);
      return GSL_NAN;
    }
    PyList_Append(args,arg);
    Py_DECREF(arg);
  }
  
  /* the other parameters are following */
  trailing_params=((multimin_multiminObject*)params)->trailing_params;
  if (trailing_params!=NULL) {
    if (PyTuple_Check(trailing_params)==1 || PyList_Check(trailing_params)==1) {
      length=PySequence_Length(trailing_params);
      for (i=0;i<length;i++) {
	PyList_Append(args,PySequence_GetItem(trailing_params,i));
      }
    }
    else {
      PyList_Append(args,trailing_params);
    }
  }
  args_tuple=PyList_AsTuple(args);
  Py_DECREF(args);

  /* extract the function */
  function=((multimin_multiminObject*)params)->py_function;
  if (function==NULL) {
    Py_DECREF(args_tuple);
    return GSL_NAN;
  }
  Py_INCREF(function);
  result_py=PyObject_CallObject(function,args_tuple);
  Py_DECREF(function);
  Py_DECREF(args_tuple);
  if (result_py==NULL) {
    return GSL_NAN;
  }

  result_float=PyNumber_Float(result_py);
  Py_DECREF(result_py);
  if (result_float==NULL) return GSL_NAN;
  result=PyFloat_AsDouble(result_float);
  Py_DECREF(result_float);
  return result;
}

static PyObject* multimin_multimin_set(PyObject *self,
				       PyObject *args
				       ) {
  PyObject* func;
  PyObject* params;
  PyObject* x;
  PyObject* steps;
  int i;
  int n;
  gsl_vector* gsl_x;
  gsl_vector* gsl_steps;

  /* arguments PyFunction, Parameters, start Vector, step Vector */
  if (0==PyArg_ParseTuple(args,"O!OOO",
			  &PyFunction_Type,&func,&params,&x,&steps))
      return NULL;
  if (((multimin_multiminObject*)self)->min==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "got a min NULL pointer!");
    return NULL;
  }
  n=((multimin_multiminObject*)self)->n;

  /* look out for suitable x, steps */
  if (!PySequence_Check(x) || !PySequence_Check(steps)){
    PyErr_SetString(PyExc_RuntimeError, "start or steps are not a sequence");
    return NULL;
  }
  
  if (PySequence_Size(x)!=n || PySequence_Size(steps)!=n) {
    PyErr_SetString(PyExc_RuntimeError, "start or steps are not of required size");
    return NULL;
  }  

  if (((multimin_multiminObject*)self)->func!=NULL) {
    /* free the previous function and params */
    if (((multimin_multiminObject*)self)->trailing_params!=NULL) {
      Py_DECREF(((multimin_multiminObject*)self)->trailing_params);
    }
    if (((multimin_multiminObject*)self)->py_function!=NULL) {
      Py_DECREF(((multimin_multiminObject*)self)->py_function);
    }
  }
  else {
    /* allocate function space */
    ((multimin_multiminObject*)self)->func=malloc(sizeof(gsl_multimin_function));
    if (((multimin_multiminObject*)self)->func==NULL) {
      PyErr_SetString(PyExc_RuntimeError, "can't allocate function space");
      return NULL;
    }
  }
  /* add new function  and parameters */
  ((multimin_multiminObject*)self)->trailing_params=params;
  Py_INCREF(params);
  ((multimin_multiminObject*)self)->py_function=func;
  Py_INCREF(func);

  /* initialize the function struct */
  ((multimin_multiminObject*)self)->func->n=n;
  ((multimin_multiminObject*)self)->func->f=&pygsl_multimin_function;
  ((multimin_multiminObject*)self)->func->params=(void*)self;

  /* build gsl_vectors for x and steps */
  gsl_x=gsl_vector_alloc(n);
  gsl_steps=gsl_vector_alloc(n);
  for (i=0; i<PySequence_Size(x);i++) {
    PyObject* pyxi=PySequence_GetItem(x,i);
    PyObject* pystepi=PySequence_GetItem(steps,i);
    PyObject* floatxi=PyNumber_Float(pyxi);
    PyObject* floatstepi=PyNumber_Float(pystepi);
    if (floatxi==NULL || floatstepi==NULL) {
      PyErr_SetString(PyExc_RuntimeError, "start or steps elements are not numbers");
      if (floatxi!=NULL) { Py_DECREF(floatxi); }
      if (floatstepi!=NULL) { Py_DECREF(floatstepi); }
      return NULL;
    }
    gsl_vector_set(gsl_x,i,PyFloat_AsDouble(pyxi));
    gsl_vector_set(gsl_steps,i,PyFloat_AsDouble(pystepi));
    Py_DECREF(floatxi);
    Py_DECREF(floatstepi);
  }

  gsl_multimin_fminimizer_set(((multimin_multiminObject*)self)->min,((multimin_multiminObject*)self)->func,gsl_x,gsl_steps);

  /* gsl_vector_free ? */
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* multimin_multimin_iterate(PyObject *self,
					   PyObject *args
					   ) {

  if ( ((multimin_multiminObject*)self)->min==NULL || ((multimin_multiminObject*)self)->func==NULL) {
    PyErr_SetString(PyExc_RuntimeError,"no function specified!");
    return NULL;
  }
  return PyInt_FromLong(gsl_multimin_fminimizer_iterate(((multimin_multiminObject*)self)->min));
}

static PyObject* multimin_multimin_x(PyObject *self,
				     PyObject *args
				     ) {
  gsl_vector* result;
  PyObject* py_result;
  size_t i;
  if ( ((multimin_multiminObject*)self)->min==NULL || ((multimin_multiminObject*)self)->func==NULL) {
    PyErr_SetString(PyExc_RuntimeError,"no function specified!");
    return NULL;
  }
  result=gsl_multimin_fminimizer_x(((multimin_multiminObject*)self)->min);
  if (result==NULL) {
    return NULL;
  }
  py_result=PyTuple_New(result->size);
  if (py_result==NULL) {
    return NULL;
  }
  for (i=0; i<result->size; i++)
    PyTuple_SetItem(py_result,i,PyFloat_FromDouble(gsl_vector_get(result,i)));
  return py_result;
}

static PyObject* multimin_multimin_minimum(PyObject *self,
					   PyObject *args
					   ) {

  if ( ((multimin_multiminObject*)self)->min==NULL || ((multimin_multiminObject*)self)->func==NULL) {
    PyErr_SetString(PyExc_RuntimeError,"no function specified!");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_multimin_fminimizer_minimum(((multimin_multiminObject*)self)->min));
}
static PyObject* multimin_multimin_size(PyObject *self,
					PyObject *args
					) {

  if ( ((multimin_multiminObject*)self)->min==NULL || ((multimin_multiminObject*)self)->func==NULL) {
    PyErr_SetString(PyExc_RuntimeError,"no function specified!");
    return NULL;
  }
  return PyFloat_FromDouble(gsl_multimin_fminimizer_size(((multimin_multiminObject*)self)->min));
}

static PyMethodDef multimin_multimin_methods[] = {
  {"set",(PyCFunction)multimin_multimin_set,METH_VARARGS,"sets a function and start values"},
  {"x",(PyCFunction)multimin_multimin_x,METH_VARARGS,"estimated position of the minimum"},
  {"minimum",(PyCFunction)multimin_multimin_minimum,METH_VARARGS,"estimated value of the minimum"},
  {"size",(PyCFunction)multimin_multimin_size,METH_VARARGS,"size of the minimizer"},
  {"iterate",(PyCFunction)multimin_multimin_iterate,METH_VARARGS,"makes next step"},
  /*  {"alloc",(PyCFunction)multimin_multimin_alloc,METH_VARARGS,"allocate necessary space"}, */
  {NULL, NULL, 0, NULL}           /* sentinel */
};

static PyObject* multimin_multimin_init(PyObject *self,
					PyObject *args,
					PyObject *kwds
					) {
  gsl_multimin_fminimizer* min;
  gsl_multimin_fminimizer_type* type;
  PyObject* type_py;
  size_t n;

  if (0==PyArg_ParseTuple(args,"O!l",
			  &PyCObject_Type,&type_py,&n))
    return NULL;
  if (n<=0) {
    PyErr_SetString(PyExc_RuntimeError, "dimension must be >0");
    return NULL;
  }
  
  type=PyCObject_AsVoidPtr(type_py);  
  min=gsl_multimin_fminimizer_alloc(type,n);
  if (min==NULL) {
    return NULL;
  }
  ((multimin_multiminObject*)self)->n=n;
  ((multimin_multiminObject*)self)->min=min;
  ((multimin_multiminObject*)self)->func=NULL;
  ((multimin_multiminObject*)self)->py_function=NULL;
  ((multimin_multiminObject*)self)->trailing_params=NULL;
  Py_INCREF(Py_None);
  return Py_None;
}

static void
multimin_multimin_dealloc(PyObject* self)
{
  gsl_multimin_fminimizer* min;
  gsl_multimin_function* func;
  min=(gsl_multimin_fminimizer*)((multimin_multiminObject*)self)->min;
  if (min!=NULL) gsl_multimin_fminimizer_free(min);
  func=(gsl_multimin_function*)(((multimin_multiminObject*)self)->func);
  if (func!=NULL) { free(func); }
  if (((multimin_multiminObject*)self)->trailing_params!=NULL) {
    Py_DECREF(((multimin_multiminObject*)self)->trailing_params);
  }
  if (((multimin_multiminObject*)self)->py_function!=NULL) {
    Py_DECREF(((multimin_multiminObject*)self)->py_function);
  }
  self->ob_type->tp_free(self);
}


static PyObject*
multimin_multimin_getattr(PyObject* obj, char *name)
{
  return Py_FindMethod(multimin_multimin_methods, obj, name);
}


static
PyTypeObject multimin_multiminType = {
	PyObject_HEAD_INIT(NULL)
	0,
	"pygsl.multimin.multimin",
	sizeof(multimin_multiminObject),
	0,
	(destructor)multimin_multimin_dealloc,  /* tp_dealloc */
	0,                                      /* tp_print */
	multimin_multimin_getattr,              /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	0,                                      /* tp_as_mapping */
	0,				        /* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,		                        /* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,		        /* tp_flags */
        0,				        /* tp_doc */
	0, 		                        /* tp_traverse */
	0,			                /* tp_clear */
	0,              			/* tp_richcompare */
	0,					/* tp_weaklistoffset */
	0,			                /* tp_iter */
	0,					/* tp_iternext */
	0,				        /* tp_methods */
	0,					/* tp_members */
	0,					/* tp_getset */
	0,					/* tp_base */
	0,					/* tp_dict */
	0,					/* tp_descr_get */
	0,					/* tp_descr_set */
	0,					/* tp_dictoffset */
	(initproc)multimin_multimin_init,	/* tp_init */
	NULL,              			/* tp_alloc */
	NULL,                			/* tp_new */
	NULL         			        /* tp_free */
};

static PyMethodDef multiminMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

void registerMinTypes(PyObject* m) {
  PyObject* dict=PyModule_GetDict(m);
  PyDict_SetItemString(dict, "nmsimplex" , PyCObject_FromVoidPtr((void*)gsl_multimin_fminimizer_nmsimplex,NULL));
  PyDict_SetItemString(dict, "steepest_descent" , PyCObject_FromVoidPtr((void*)gsl_multimin_fdfminimizer_steepest_descent,NULL));
  PyDict_SetItemString(dict, "vector_bfgs" , PyCObject_FromVoidPtr((void*)gsl_multimin_fdfminimizer_vector_bfgs,NULL));
  PyDict_SetItemString(dict, "conjugate_pr" , PyCObject_FromVoidPtr((void*)gsl_multimin_fdfminimizer_conjugate_pr,NULL));
  PyDict_SetItemString(dict, "conjugate_fr" , PyCObject_FromVoidPtr((void*)gsl_multimin_fdfminimizer_conjugate_fr,NULL));
}


void
initmultimin(void)
{
  PyObject* m;
  m=Py_InitModule("multimin", multiminMethods);
  init_pygsl();
  /* init multimin type */
  multimin_multiminType.ob_type  = &PyType_Type;
  multimin_multiminType.tp_alloc = PyType_GenericAlloc;
  multimin_multiminType.tp_new   = PyType_GenericNew;
  multimin_multiminType.tp_free  = _PyObject_Del;

  /* install histogram type */
  /* important! must increment histogram type reference counter */
  Py_INCREF((PyObject*)&multimin_multiminType);
  PyModule_AddObject(m,"multimin", (PyObject*)&multimin_multiminType);
  registerMinTypes(m);
}
