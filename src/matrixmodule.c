/*
 * author: Achim Gaedke
 * created: January 2001
 * file: pygsl/src/histogrammodule.c
 * $Id$
 */

#include <Python.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <pygsl/error_helpers.h>
/*
 * matrix
 */

/* my typedef */

staticforward PyTypeObject matrix_matrixType;

typedef struct {
    PyObject_HEAD
    gsl_matrix* m;
} matrix_matrixObject;


static PyObject* matrix_matrix_get(PyObject *self,
				   PyObject *args
				   )
{
  gsl_matrix* matrix;
  long int i;
  long int j;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.get got a NULL pointer");
    return NULL;
  }

  /* get index */  
  if (0==PyArg_ParseTuple(args,"ll",&i,&j))
      return NULL;
  if (i<0 || i>=matrix->size1) {
    gsl_error ("1st index lies outside valid range of 0 .. size1 - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (j<0 || j>=matrix->size2) {
    gsl_error ("2nd index lies outside valid range of 0 .. size2 - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  return PyFloat_FromDouble(gsl_matrix_get(matrix,i,j));
}

static PyObject* matrix_matrix_set(PyObject *self,
				   PyObject *args
				   )
{
  gsl_matrix* matrix;
  long int i;
  long int j;
  double x;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.get got a NULL pointer");
    return NULL;
  }

  /* get index */  
  if (0==PyArg_ParseTuple(args,"lld",&i,&j,&x))
      return NULL;
  if (i<0 || i>=matrix->size1) {
    gsl_error ("1st index lies outside valid range of 0 .. size1 - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  if (j<0 || j>=matrix->size2) {
    gsl_error ("2nd index lies outside valid range of 0 .. size2 - 1",
	       __FILE__,
	       __LINE__,
	       GSL_EDOM );
    return NULL;
  }
  gsl_matrix_set(matrix,i,j,x);
  Py_INCREF(Py_None);
  return Py_None;  
}

static PyObject* matrix_matrix_set_all(PyObject *self,
				       PyObject* args)
{
  gsl_matrix* matrix;
  double x;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (0==PyArg_ParseTuple(args,"d",&x))
      return NULL;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.size got a NULL pointer");
    return NULL;
  }
  gsl_matrix_set_all(matrix,x);
  Py_INCREF(Py_None);
  return Py_None;  
}


static PyObject* matrix_matrix_set_identity(PyObject *self)
{
  gsl_matrix* matrix;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.size got a NULL pointer");
    return NULL;
  }
  gsl_matrix_set_identity(matrix);
  Py_INCREF(Py_None);
  return Py_None;  
}

static PyObject* matrix_matrix_set_zero(PyObject *self)
{
  gsl_matrix* matrix;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.size got a NULL pointer");
    return NULL;
  }
  gsl_matrix_set_zero(matrix);
  Py_INCREF(Py_None);
  return Py_None;  
}

static PyObject* matrix_matrix_transpose(PyObject *self)
{
  gsl_matrix* matrix;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.size got a NULL pointer");
    return NULL;
  }
  gsl_matrix_transpose(matrix);
  Py_INCREF(Py_None);
  return Py_None;  
}


static PyObject* matrix_matrix_size(PyObject *self)
{
  gsl_matrix* matrix;

  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.size got a NULL pointer");
    return NULL;
  }

  return Py_BuildValue("(ll)",matrix->size1,matrix->size2);
}

static PyObject* matrix_matrix_add(PyObject *self,
				   PyObject *arg) {
  gsl_matrix* matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  gsl_matrix* matrix2;
  int result;

  if (matrix==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix.add got a NULL pointer");
    return NULL;
  }
  Py_INCREF(arg);
  /* get histogram from argument */
  if (arg==NULL || !PyObject_TypeCheck(arg,&matrix_matrixType)) {
    PyErr_SetString(PyExc_TypeError, "matrix.add requires pygsl.matrix.matrix");
    Py_DECREF(arg);
    return NULL;
  }
  matrix2=(gsl_matrix*)((matrix_matrixObject*)arg)->m;
  if (matrix2==NULL) {
    PyErr_SetString(PyExc_RuntimeError, "matrix in argument has a NULL pointer");
    return NULL;
  }
  result=gsl_matrix_add(matrix,matrix2);
  Py_DECREF(arg);
  if (result!=GSL_SUCCESS) {
    return NULL;
  }
  Py_INCREF(Py_None);
  return Py_None;
}

static PyMethodDef matrix_matrix_methods[] = {
  /*  {"alloc",(PyCFunction)histogram_histogram_alloc,METH_VARARGS,"allocate necessary space"}, */
  {"get",(PyCFunction)matrix_matrix_get,METH_VARARGS,"gets the (i,j) element"},
  {"size",(PyCFunction)matrix_matrix_size,METH_NOARGS,"returns the size as tuple"},
  {"add",(PyCFunction)matrix_matrix_add,METH_O,"adds the given matrix"},
  {"set",(PyCFunction)matrix_matrix_set,METH_VARARGS,"sets the (i,j) element"},
  {"set_zero",(PyCFunction)matrix_matrix_set_zero,METH_NOARGS,"sets all to 0"},
  {"set_identity",(PyCFunction)matrix_matrix_set_identity,METH_NOARGS,"sets diagonal to 1 and others to 0"},
  {"set_all",(PyCFunction)matrix_matrix_set_identity,METH_O,"sets all entries to x"},
  {"transpose",(PyCFunction)matrix_matrix_transpose,METH_NOARGS,"transposes the matrix in place"}, 
  {NULL, NULL, 0, NULL}           /* sentinel */
};

static int matrix_matrix_init(PyObject *self,
			      PyObject *args,
			      PyObject *kwds
			      )
{

  PyObject* orig_matrix;
  long int n1;
  long int n2;
  
  static char *kwlist1[] = {"matrix",NULL};
  static char *kwlist2[] = {"size1","size2",NULL};

  /* initialise histogram pointer */
  ((matrix_matrixObject*)self)->m=NULL;

  /* test two call alternatives: */

  if (PyArg_ParseTupleAndKeywords(args, kwds,"O!",kwlist1,&matrix_matrixType,&orig_matrix)) {
    gsl_matrix* matrix;
    gsl_matrix* matrix2=(gsl_matrix*)((matrix_matrixObject*)orig_matrix)->m;
    if (matrix2==NULL) {
      PyErr_SetString(PyExc_RuntimeError, "matrix in argument has a NULL pointer");
      return -1;
    }
    matrix=gsl_matrix_calloc(matrix2->size1,matrix2->size2);
    if (matrix==NULL)
      return -1;
    gsl_matrix_memcpy(matrix,matrix2);
    ((matrix_matrixObject*)self)->m=matrix;
    return 0;
  }
  else {
    /* reset exception */
    PyErr_Clear();
  }
  if (PyArg_ParseTupleAndKeywords(args, kwds,"ll",kwlist2,&n1,&n2)) {
    gsl_matrix* matrix;
    if (n1<=0 || n2<=0) {
      gsl_error ("matrix length must be positive",
		 __FILE__,
		 __LINE__,
		 GSL_EDOM );
      return -1;
    }
    matrix=gsl_matrix_calloc(n1,n2);
    if (matrix==NULL)
      return -1;
    ((matrix_matrixObject*)self)->m=matrix;
    return 0;
    
  }
  else {
    /* set own error message */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError, "matrix.init requires pygsl.matrix.matirx object or two long int argument");
    return -1;
  }
}

static PyObject*
matrix_matrix_getattr(PyObject* obj, char *name)
{
  return Py_FindMethod(matrix_matrix_methods, obj, name);
}

static void
matrix_matrix_dealloc(PyObject* self)
{
  gsl_matrix* matrix;
  matrix=(gsl_matrix*)((matrix_matrixObject*)self)->m;
  if (matrix!=NULL) gsl_matrix_free(matrix);
  self->ob_type->tp_free(self);
}

static
PyTypeObject matrix_matrixType = {
	PyObject_HEAD_INIT(NULL)
	0,
	"pygsl.matrix.matrix",
	sizeof(matrix_matrixObject),
	0,
	(destructor)matrix_matrix_dealloc,      /* tp_dealloc */
	0,                                      /* tp_print */
	matrix_matrix_getattr,                  /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	0,    /* &matrix_marix_as_mapping,*/	/* tp_as_mapping */
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
	(initproc)matrix_matrix_init,	        /* tp_init */
	NULL,              			/* tp_alloc */
	NULL,                			/* tp_new */
	NULL         			        /* tp_free */
};


static PyMethodDef matrixMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

void
initmatrix(void)
{
  PyObject* m;
  m=Py_InitModule("matrix", matrixMethods);
  init_pygsl();
  /* init histogram type */
  matrix_matrixType.ob_type  = &PyType_Type;
  matrix_matrixType.tp_alloc = PyType_GenericAlloc;
  matrix_matrixType.tp_new   = PyType_GenericNew;
  matrix_matrixType.tp_free  = _PyObject_Del;

  /* install histogram type */
  /* important! must increment histogram type reference counter */
  Py_INCREF((PyObject*)&matrix_matrixType);
  PyModule_AddObject(m,"matrix", (PyObject*)&matrix_matrixType);
}
