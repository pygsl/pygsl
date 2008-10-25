#include "transformtypes.h"
#include "wavelet.h"


static void 
PyGSL_wavelet_dealloc(PyGSL_wavelet *self);

static PyObject *
PyGSL_wavelet_getattr(PyGSL_wavelet *self, const char * name);

PyTypeObject PyGSL_wavelet_pytype = {
	PyObject_HEAD_INIT(NULL)	 /* fix up the type slot in init */
	0,				 /* ob_size */
	"PyGSL_wavelet",		 /* tp_name */
	sizeof(PyGSL_wavelet),	 /* tp_basicsize */
	0,				 /* tp_itemsize */

	/* standard methods */
	(destructor)  PyGSL_wavelet_dealloc, /* tp_dealloc  ref-count==0  */
	(printfunc)   0,		         /* tp_print    "print x"     */
	(getattrfunc) PyGSL_wavelet_getattr,  /* tp_getattr  "x.attr"      */
	(setattrfunc) 0,		 /* tp_setattr  "x.attr=v"    */
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
	(char *) PyGSL_wavelet_type_doc		/* tp_doc */
};

/*
typedef int (complex_transform)(gsl_complex_packed_array
          DATA, size_t STRIDE, size_t N, const
          gsl_fft_complex_wavetable * WAVETABLE,
          gsl_fft_complex_workspace * WORK);
*/

static void 
PyGSL_wavelet_dealloc(PyGSL_wavelet *self)
{
	FUNC_MESS_BEGIN();
	assert(PyGSL_WAVELET_CHECK(self));
	if(self->wavelet)
		gsl_wavelet_free(self->wavelet);
	self->wavelet = NULL;
	FUNC_MESS_END();
}

static struct _pygsl_transform_info_s
wavelet_info           = INIT_INFO(RealReal,  DOUBLE, , , 0, WAVELET, SINGLE_TYPE);

static struct _pygsl_transform_func_rf_s wavelet_func = {(pygsl_transform_helpn_t *) gsl_wavelet_workspace_alloc,
						      (pygsl_transform_help_t *)gsl_wavelet_workspace_free,
						      NULL, NULL, WAVELET_WORKSPACE, NOSPACE};

#define PYGSL_WAVLET(direction) \
static PyObject * \
PyGSL_wavelet_ ## direction(PyGSL_wavelet *self, PyObject *args) \
{ \
	PyObject *tmp; \
	FUNC_MESS_BEGIN(); \
        pygsl_transform_help_s helps;\
        struct _pygsl_transform_help_rf_s s; \
        helps.info = &wavelet_info; \
	helps.transform.v = (void *) gsl_wavelet_transform_ ## direction;\
        s.func = &wavelet_func;\
        helps.helpers = &s; \
	tmp = PyGSL_transform_((PyObject *) self, args, &helps); \
	FUNC_MESS_END(); \
	return tmp; \
}
PYGSL_WAVLET(forward)
PYGSL_WAVLET(inverse)

#define PYGSL_WAVLET2D(type, direction) \
static PyObject * \
PyGSL_wavelet2d_ ## type ## direction(PyGSL_wavelet *self, PyObject *args) \
{ \
	PyObject *tmp; \
	FUNC_MESS_BEGIN(); \
        pygsl_transform_help_s helps;\
        struct _pygsl_transform_help_rf_s s; \
        helps.info = &wavelet_info; \
	helps.transform.v = (void *) gsl_wavelet2d_ ## type ## transform_matrix_ ## direction;\
        s.func = &wavelet_func;\
        helps.helpers = &s; \
	tmp = PyGSL_transform_2d_((PyObject *) self, args, &helps); \
	FUNC_MESS_END(); \
	return tmp; \
}
PYGSL_WAVLET2D(,forward)
PYGSL_WAVLET2D(,inverse)
PYGSL_WAVLET2D(ns,forward)
PYGSL_WAVLET2D(ns,inverse)

static PyObject *
PyGSL_wavelet_get_n_py(PyGSL_wavelet *self, PyObject *unsused)
{
	PyObject *tmp;
	FUNC_MESS_BEGIN();
	assert(PyGSL_WAVELET_CHECK(self));
	tmp = PyInt_FromLong((long)self->wavelet->nc);
	FUNC_MESS_END();
	return tmp;
}
static PyMethodDef PyGSL_wavelet_methods[] = {
	{"transform_forward",     (PyCFunction)PyGSL_wavelet_forward,     METH_VARARGS,  (char *)PyGSL_wavelet_forward_doc},
	{"transform_inverse",     (PyCFunction)PyGSL_wavelet_inverse,     METH_VARARGS,  (char *)PyGSL_wavelet_inverse_doc},
	{"transform2d_forward",   (PyCFunction)PyGSL_wavelet2d_forward,   METH_VARARGS,  (char *)PyGSL_wavelet_forward_doc},
	{"transform2d_inverse",   (PyCFunction)PyGSL_wavelet2d_inverse,   METH_VARARGS,  (char *)PyGSL_wavelet_inverse_doc},	
	{"nstransform2d_forward", (PyCFunction)PyGSL_wavelet2d_nsforward, METH_VARARGS,  (char *)PyGSL_wavelet_forward_doc},
	{"nstransform2d_inverse", (PyCFunction)PyGSL_wavelet2d_nsinverse, METH_VARARGS,  (char *)PyGSL_wavelet_inverse_doc},	
	{"get_n",                 (PyCFunction)PyGSL_wavelet_get_n_py,    METH_NOARGS,  NULL},
	{NULL, NULL, 0, NULL}           /* sentinel */
};


static PyObject *
PyGSL_wavelet_getattr(PyGSL_wavelet *self, const char * name)
{
	PyObject *tmp;
	FUNC_MESS_BEGIN();
	assert(PyGSL_WAVELET_CHECK(self));
	tmp = Py_FindMethod(PyGSL_wavelet_methods, (PyObject *) self, (char *)name);
	FUNC_MESS_END();
	return tmp;
}

static PyObject *
PyGSL_wavelet_init(PyObject *self, PyObject *args, const gsl_wavelet_type *type)
{
	int n;
	int line = __LINE__;
	PyGSL_wavelet * o = NULL;
	FUNC_MESS_BEGIN();
	if (0==PyArg_ParseTuple(args,"l", &n)){
		line = __LINE__ -1;
		goto fail;
	}
	if (n<=0) {
		line = __LINE__ -1;
		PyErr_SetString(PyExc_RuntimeError, "dimension must be >0");
		goto fail;
	}

	o =  (PyGSL_wavelet *) PyObject_NEW(PyGSL_wavelet, &PyGSL_wavelet_pytype);
	if(o == NULL){
		line = __LINE__ - 2;
		goto fail;
	}

	if((o->wavelet = gsl_wavelet_alloc(type, n)) == NULL){
		line = __LINE__ - 1;
		/* 
		 * If the wrong parameter n is given, it will call PyGSL_ERROR()
		 * and return NULL. I hope it does that in case of no memory as
		 * well. The installed error handler will then call
		 *	PyErr_NoMemory();
		 */
		goto fail;
	}
	FUNC_MESS_END();
	return (PyObject *) o;
	
 fail:
	FUNC_MESS("Fail");
	PyGSL_add_traceback(module, filename, __FUNCTION__, line);
	Py_XDECREF(o);
	return NULL;
}

#define PyGSL_WAVELET_INIT(name) \
static PyObject * \
PyGSL_wavelet_init_ ## name(PyObject *self, PyObject *args) \
{ \
	PyObject *tmp; \
	FUNC_MESS_BEGIN();\
	tmp = PyGSL_wavelet_init(self, args, gsl_wavelet_ ## name); \
	if(tmp == NULL) \
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 2); \
	FUNC_MESS_END(); \
	return tmp; \
}
PyGSL_WAVELET_INIT(daubechies)
PyGSL_WAVELET_INIT(daubechies_centered)
PyGSL_WAVELET_INIT(haar)
PyGSL_WAVELET_INIT(haar_centered)
PyGSL_WAVELET_INIT(bspline)
PyGSL_WAVELET_INIT(bspline_centered)

/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
