#include <pygsl/utils.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <pygsl/string_helpers.h>
#include <gsl/gsl_qrng.h>
#include "qrng_module_defines.h"
static PyObject *module = NULL;

#define PyGSLQRng_Check(v) (Py_TYPE(v) == &PyGSL_qrng_pytype)
//#define PyGSL_QRngType_Check(v) ((v)->ob_type == &PyGSL_qrng__pytype)


#ifdef PyGSL_PY3K
#define PyGSL_STRING_AS_STRING(obj) PyBytes_FromString(obj) 
#define PyGSL_STRING_LENGTH(obj)      PyBytes_Length(obj) 
#else
#define PyGSL_STRING_AS_STRING(obj) PyString_AsString(obj) 
#define PyGSL_STRING_LENGTH(obj)      PyString_Size(obj) 
#endif


/*---------------------------------------------------------------------------*/
typedef struct {
  PyObject_HEAD
  gsl_qrng * qrng;
} PyGSL_qrng;

static PyObject *
qrng_get(PyGSL_qrng *self, PyObject *args);

static void
qrng_delete(PyGSL_qrng *self);
static PyObject *
qrng_reinit(PyGSL_qrng *self, PyObject *args);
static PyObject *
qrng_name(PyGSL_qrng *self, PyObject *args);
static PyObject *
qrng_clone(PyGSL_qrng *self, PyObject *args);


static struct PyMethodDef qrng_methods[] = {
     {"init", (PyCFunction) qrng_reinit, METH_VARARGS, QRNG_INIT},
     {"get", (PyCFunction) qrng_get, METH_VARARGS, QRNG_GET},
     {"name", (PyCFunction) qrng_name, METH_VARARGS, QRNG_NAME},
     {"clone", (PyCFunction) qrng_clone, METH_VARARGS, QRNG_CLONE},
     {"__copy__", (PyCFunction) qrng_clone, METH_VARARGS, QRNG_CLONE},
     {NULL, NULL}
};


/*
PyObject*
qrng_type_getattr(PyGSL_qrng_type *self, char *name)
{
     if(strcmp(name, "__doc__") == 0){
	  return PyGSL_get_docobject_for_object(self->py_name);
     }else{
	  Py_INCREF(Py_None);
	  return Py_None;
     }	  
}
*/

#ifdef PyGSL_PY3K
static PyTypeObject PyGSL_qrng_pytype = {
	PyObject_HEAD_INIT(NULL)
	"PyGSL_qrng",                    /* tp_name */
	sizeof(PyGSL_qrng),              /* tp_basicsize */
	0,                                          /* tp_itemsize */
	(destructor) qrng_delete, /* tp_dealloc */
	0,                       /* tp_print */
	0,                       /* tp_getattr */
	0,                       /* tp_setattr */
	0,                       /* tp_reserved */
	0,                       /* tp_repr */
	0,                       /* tp_as_number */
	0,                       /* tp_as_sequence */
	0,                       /* tp_as_mapping */
	0,                       /* tp_hash */
	(ternaryfunc)  qrng_get, /* tp_call */
	0,                       /* tp_str */
	0,                       /* tp_getattro */
	0,                       /* tp_setattro */
	0,                       /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,      /* tp_flags */
	(char *)0, /* tp_doc */
	0,                       /* tp_traverse */
	0,                       /* tp_clear */
	0,                       /* tp_richcompare */
	0,                       /* tp_weaklistoffset */
	0,                       /* tp_iter */
	0,                       /* tp_iternext */
	qrng_methods,          /* tp_methods */
	0,                       /* tp_members */
	0,                       /* tp_getset */
	0,                       /* tp_base */
	0,                       /* tp_dict */
	0,                       /* tp_descr_get */
	0,                       /* tp_descr_set */
	0,                       /* tp_dictoffset */
	0,                       /* tp_init */
	0,                       /* tp_alloc */
	0,                       /* tp_new */
};
#else /* PyGSL_PY3K */
static PyObject *		/* on "instance.attr" */
qrng_getattr (PyGSL_qrng *self, char *name);
static PyTypeObject PyGSL_qrng_pytype = {
  PyObject_HEAD_INIT(NULL)	/* fix up the type slot in initcrng */
  0,				/* ob_size */
  "PyGSL_qrng",			/* tp_name */
  sizeof(PyGSL_qrng),	        /* tp_basicsize */
  0,				/* tp_itemsize */

  /* standard methods */
  (destructor)  qrng_delete,       /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		   /* tp_print    "print x"     */
  (getattrfunc) qrng_getattr,       /* tp_getattr  "x.attr"      */
  (setattrfunc) 0,		   /* tp_setattr  "x.attr=v"    */
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */

  /* type categories */
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/
  0,				/* tp_as_mapping  [key], len, ...*/

  /* more methods */
  (hashfunc)     0,		/* tp_hash    "dict[x]" */
  (ternaryfunc)  qrng_get,      /* tp_call    "x()"     */
  (reprfunc)     0,             /* tp_str     "str(x)"  */
  (getattrofunc) 0,		/* tp_getattro */
  (setattrofunc) 0,		/* tp_setattro */
  0,				/* tp_as_buffer */
  0L,				/* tp_flags */
  0		/* tp_doc */
};

static PyObject *		/* on "instance.attr" */
qrng_getattr (PyGSL_qrng *self, char *name){
     PyObject *tmp = NULL;

     assert(PyGSLQRng_Check(self));

     /*
     if(strcmp(name, "__doc__") == 0)
	  return PyGSL_get_docobject_for_object("qrng.qrng");
     */
     tmp = Py_FindMethod(qrng_methods, (PyObject *) self, name);
     if(NULL == tmp){	  
	  PyGSL_add_traceback(module, __FILE__, "qrng.__attr__", __LINE__ - 1);
	  return NULL;
     }
     return tmp;

}

#endif /* PyGSL_PY3K */


 
static PyObject *
qrng_get(PyGSL_qrng *self, PyObject *args)
{
     int dimension = 1, lineno=0;
     PyArrayObject *a_array;
     PyGSL_array_index_t dims[2];
     double *data;
     int i;

     FUNC_MESS_BEGIN();
     assert(PyGSLQRng_Check(self));
     if(0 == PyArg_ParseTuple(args, "|i", &dimension)){
	  goto fail;
     }
     if(dimension <= 0){
	  lineno = __LINE__ - 1;
	  PyErr_SetString(PyExc_ValueError, 
			  "The sample number must be positive!");
	  goto fail;
     }
     dims[0] = dimension;
     dims[1] = self->qrng->dimension;
     DEBUG_MESS(5, "Building return array with dimensions (%ld,%ld)", (long)dims[0], (long)dims[1]);
     a_array = (PyArrayObject *) PyGSL_New_Array(2, dims, NPY_DOUBLE);
     if(a_array == NULL){lineno = __LINE__ - 1; goto fail;}
     DEBUG_MESS(5, "Its strides are (%ld,%ld)", PyArray_STRIDE(a_array, 0), PyArray_STRIDE(a_array, 1));
     assert((PyArray_STRIDE(a_array, 1) / sizeof(double)) == 1);

     for(i=0; i<dimension; i++){
	  DEBUG_MESS(6, "Setting slice %d", i);
	  data = (double *) (PyArray_GETPTR1(a_array, i));
	  DEBUG_MESS(6, "Data at %p", (void *) data);
	  gsl_qrng_get(self->qrng, data);
     }

     FUNC_MESS_END();
     return (PyObject *) a_array;

 fail:
     FUNC_MESS("In Fail!");
     PyGSL_add_traceback(module, __FILE__, "_qrng.__attr__",  lineno);
     return NULL;
}


/*---------------------------------------------------------------------------*/
/* qrng */
static void
qrng_delete(PyGSL_qrng *self)
{
     assert(PyGSLQRng_Check(self));
     gsl_qrng_free(self->qrng);
     DEBUG_MESS(1, " self %p\n",(void *) self);
}

static PyObject *
qrng_reinit(PyGSL_qrng *self, PyObject *args)
{
     assert(PyGSLQRng_Check(self));
     gsl_qrng_init(self->qrng);
     Py_INCREF(Py_None);
     return Py_None;
}



static PyObject *
qrng_name(PyGSL_qrng *self, PyObject *args)
{
     assert(PyGSLQRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":name"))
	  return NULL;
     return PyGSL_string_from_string(gsl_qrng_name(self->qrng));
}

static PyObject *
qrng_clone(PyGSL_qrng *self, PyObject *args)
{
     PyGSL_qrng * qrng;
     assert(PyGSLQRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":clone"))
	  return NULL;
     qrng =  (PyGSL_qrng *) PyObject_NEW(PyGSL_qrng, &PyGSL_qrng_pytype);
     qrng->qrng = gsl_qrng_clone(self->qrng);
     return (PyObject *) qrng;
}


static PyObject *
PyGSL_qrng_init(PyObject *self, PyObject *args, const gsl_qrng_type * qrng_type)
{

     PyGSL_qrng *qrng = NULL;
     int dimension = 0;


     FUNC_MESS_BEGIN();
     if(qrng_type == NULL){
	  PyGSL_add_traceback(module, __FILE__, "qrng.__init__", __LINE__ - 2);
	  return NULL;
     }

     if (0 == PyArg_ParseTuple(args, "i:qrng.__init__", &dimension)){
	  PyGSL_add_traceback(module, __FILE__, "qrng.__init__", __LINE__ - 2);
	  return NULL;
     }

     if (dimension <= 0){
	  PyErr_SetString(PyExc_ValueError, "The sample number must be positive!");
	  PyGSL_add_traceback(module, __FILE__, "qrng.__init__", __LINE__ - 2);
	  return NULL;
     }

     qrng =  (PyGSL_qrng *) PyObject_NEW(PyGSL_qrng, &PyGSL_qrng_pytype);
     if(qrng == NULL){
	  return NULL;
     }
     qrng->qrng = NULL;
     qrng->qrng = gsl_qrng_alloc(qrng_type, dimension);
     /* XXX handle failure in allocation of qrng! ... */
     
     FUNC_MESS_END();
     return (PyObject *) qrng;
}


#define RNG_ARNG(name)					\
static PyObject* PyGSL_qrng_init_ ## name (PyObject *self, PyObject *args)    \
{                                                                            \
     PyObject *tmp = NULL;                                                   \
     FUNC_MESS_BEGIN();                                                      \
     tmp = PyGSL_qrng_init(self, args,  gsl_qrng_ ## name);                    \
     if (tmp == NULL){                                                       \
	  PyGSL_add_traceback(module, __FILE__, __FUNCTION__, __LINE__);     \
     }                                                                       \
     FUNC_MESS_END();                                                        \
     return tmp;                                                             \
}

RNG_ARNG(niederreiter_2)
RNG_ARNG(sobol)


static PyMethodDef PyGSL_qrng_module_functions[] = {
	{"niederreiter_2", PyGSL_qrng_init_niederreiter_2, METH_VARARGS, NULL},
	{"sobol",          PyGSL_qrng_init_sobol,    METH_VARARGS, NULL},
	{NULL, 0, 0, NULL}
}; 

#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "_qrng",
        NULL,
        -1,
	PyGSL_qrng_module_functions,
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
PyObject *PyInit__qrng(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) init_qrng(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
	PyObject *m = NULL;

	init_pygsl();
     
#ifdef PyGSL_PY3K
	m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
	m = Py_InitModule("_qrng", PyGSL_qrng_module_functions);
#endif

	assert(m);
	/* create_qrng_types(m); */
	module = m;

#ifdef PyGSL_PY3K
	if (PyType_Ready(&PyGSL_qrng_pytype) < 0)
		return NULL;
#else /* PyGSL_PY3K */
	PyGSL_qrng_pytype.ob_type = &PyType_Type;   
#endif /* PyGSL_PY3K */
     
     return RETVAL;
}
