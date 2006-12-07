#include <pygsl/utils.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <gsl/gsl_qrng.h>
#include <pygsl/error_helpers.h>
#include "qrng_module_defines.h"
static PyObject *module = NULL;

static void			/* generic instance destruction */
generic_dealloc (PyObject *self)
{
  DEBUG_MESS(1, " *** generic_dealloc %p\n", (void *) self);
  PyObject_Del(self);
}


/*---------------------------------------------------------------------------*/
/* encapsulation for the PyGSL_qrng_type */
typedef struct {
     PyObject_HEAD
     gsl_qrng_type * qrng_type;
     const char * py_name; /* can not use the name here... niederreiter-*/
} PyGSL_qrng_type;

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
static PyTypeObject PyGSL_qrng_type_pytype = {
  PyObject_HEAD_INIT(NULL)	/* fix up the type slot in initcrng */
  0,				/* ob_size */
  "PyGSL_qrng_type",     	/* tp_name */
  sizeof(PyGSL_qrng_type),       /* tp_basicsize */
  0,				/* tp_itemsize */

  /* standard methods */
  (destructor)  generic_dealloc,   /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		   /* tp_print    "print x"     */
  (getattrfunc) 0/*qrng_type_getattr*/, /* tp_getattr  "x.attr"      */
  (setattrfunc) 0,		   /* tp_setattr  "x.attr=v"    */
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */

  /* type categories */
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/
  0,				/* tp_as_mapping  [key], len, ...*/

  /* more methods */
  (hashfunc)     0,		/* tp_hash    "dict[x]" */
  (ternaryfunc)  0,             /* tp_call    "x()"     */
  (reprfunc)     0,             /* tp_str     "str(x)"  */
  (getattrofunc) 0,		/* tp_getattro */
  (setattrofunc) 0,		/* tp_setattro */
  0,				/* tp_as_buffer */
  0L,				/* tp_flags */
  NULL/* PyGSL_qrng_type_pytype_doc*/       /* tp_doc */
};

void
create_qrng_types(PyObject *module)
{
     PyGSL_qrng_type *a_rng = NULL;
     const gsl_qrng_type* thisRNGType, 
	  *types[3] = {gsl_qrng_niederreiter_2, gsl_qrng_sobol, NULL};
     const char* gsl_qrng_names[3] = {"_qrng.niederreiter_2", "_qrng.sobol", NULL};
	  
     PyObject* module_dict=PyModule_GetDict(module);
     PyObject* item = NULL;
     int i;
     
     assert(module_dict);     
     FUNC_MESS_BEGIN();
     /* provide other rng types as subclasses of rng  */
     for(i=0; types[i]!=NULL; i++){
	  thisRNGType = types[i];
	  a_rng =  PyObject_NEW(PyGSL_qrng_type, &PyGSL_qrng_type_pytype);
	  a_rng->qrng_type = (gsl_qrng_type *) thisRNGType;
	  item = PyString_FromString((thisRNGType)->name);
	  assert(item);
	  PyGSL_clear_name(PyString_AsString(item), PyString_Size(item));
	  assert(gsl_qrng_names[i]);
	  a_rng->py_name = gsl_qrng_names[i];
	  PyDict_SetItem(module_dict, item, (PyObject *) a_rng);
	  Py_DECREF(item);
	  item = NULL;	
	  thisRNGType++;       
     }
     FUNC_MESS_END();
}
#define PyGSL_QRngType_Check(v) ((v)->ob_type == &PyGSL_qrng_type_pytype)

/*---------------------------------------------------------------------------*/
/* qrng */

staticforward PyTypeObject PyGSL_qrng_pytype;
#if 1
typedef struct {
  PyObject_HEAD
  gsl_qrng * qrng;
} PyGSL_qrng;
#endif 
static void qrng_delete(PyGSL_qrng *self);


static PyObject *		/* on "instance.attr" */
qrng_getattr (PyGSL_qrng *self, char *name);

static PyObject *
qrng_get(PyGSL_qrng *self, PyObject *args);

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


#define PyGSLQRng_Check(v) ((v)->ob_type == &PyGSL_qrng_pytype)


PyObject *
qrng_init(PyObject *self, PyObject *args)
{
     PyObject *type = NULL;
     PyGSL_qrng *qrng = NULL;
     int dimension;
     assert(args);
     if (0 == PyArg_ParseTuple(args, "O!i:rng.__init__", &PyGSL_qrng_type_pytype, 
			       &type, &dimension)){
	  PyGSL_add_traceback(module, __FILE__, "rng.__init__", __LINE__ - 2);
	  return NULL;
     }
     if (dimension <= 0){
	  PyErr_SetString(PyExc_ValueError, "The sample number must be positive!");
	  PyGSL_add_traceback(module, __FILE__, "qrng.__init__", __LINE__ - 2);
	  return NULL;
     }
     qrng =  (PyGSL_qrng *) PyObject_NEW(PyGSL_qrng, &PyGSL_qrng_pytype);
     qrng->qrng = gsl_qrng_alloc(((PyGSL_qrng_type *)type)->qrng_type, dimension);
     return (PyObject *) qrng;
}

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
     a_array = (PyArrayObject *) PyGSL_New_Array(2, dims, PyArray_DOUBLE);
     if(a_array == NULL){lineno = __LINE__ - 1; goto fail;}
     DEBUG_MESS(5, "Its strides are (%d,%d)", a_array->strides[0], a_array->strides[1]);
     assert((a_array->strides[1] / sizeof(double)) == 1);

     for(i=0; i<dimension; i++){
	  DEBUG_MESS(6, "Setting slice %d", i);
	  data = (double *) (a_array->data + a_array->strides[0] * i);
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

static PyObject *
qrng_name(PyGSL_qrng *self, PyObject *args)
{
     assert(PyGSLQRng_Check(self));
     if(0 == PyArg_ParseTuple(args, ":name"))
	  return NULL;
     return PyString_FromString(gsl_qrng_name(self->qrng));
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


static struct PyMethodDef qrng_methods[] = {
     {"init", (PyCFunction) qrng_reinit, METH_VARARGS, QRNG_INIT},
     {"get", (PyCFunction) qrng_get, METH_VARARGS, QRNG_GET},
     {"name", (PyCFunction) qrng_name, METH_VARARGS, QRNG_NAME},
     {"clone", (PyCFunction) qrng_clone, METH_VARARGS, QRNG_CLONE},
     {"__copy__", (PyCFunction) qrng_clone, METH_VARARGS, QRNG_CLONE},
     {NULL, NULL}
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

static PyMethodDef PyGSL_qrng_module_functions[] = {
     {"qrng", qrng_init, METH_VARARGS},
     {0, 0}
}; 


void 
init_qrng(void)
{
     PyObject *m;

     m = Py_InitModule("_qrng", PyGSL_qrng_module_functions);
     init_pygsl();


     assert(m);
     create_qrng_types(m);
     module = m;

     PyGSL_qrng_type_pytype.ob_type = &PyType_Type;
     PyGSL_qrng_pytype.ob_type = &PyType_Type;   

     /*
       {
       PyObject *o, *s, *d;
       d = PyModule_GetDict(m);

       s = PyGSL_get_docobject_for_object("_qrng");
       if(s)
          PyDict_SetItemString(d, "__doc__", s);


     o = PyGSL_get_docobject_for_object("_qrng.PyGSL_qrng_type");
     if(o){
	  Py_INCREF(o);
	  PyGSL_qrng_type_pytype.tp_doc = PyString_AsString(o);
     }
     o = PyGSL_get_docobject_for_object("_qrng.PyGSL_qrng");
     if(o){
	  Py_INCREF(o);
	  PyGSL_qrng_type_pytype.tp_doc = PyString_AsString(o);
     }
     }
     */
     
}
