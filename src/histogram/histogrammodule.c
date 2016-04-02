/*
 * author: Achim Gaedke
 * created: January 2001
 * file: pygsl/src/histogrammodule.c
 * $Id$
 *
 *
 * May 2005
 *    Pierre Schnizer 
 *    maintainance: replaced direct python error calls with pygsl calls 
 *    added CAST and GET macros to reduce code duplication
 * 
 *    Now the warnings are all handled by a separate function.   
 *
 * September 2005
 *    Pierre Schnizer
 *    replaced to NUMPY Macros
 */

#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_histogram2d.h>


enum hist_error{
     NOHIST = 0,
     NOHIST2D,
     ARGNOHIST,
     ARGNOHIST2D,
     HISTP_NULL
};
static const char * filename = __FILE__;
static PyObject * module = NULL;
#include "histogram_doc.ic"


static int 
PyGSL_hist_error_helper(const char * function, int line, int myerrno, enum hist_error errtype)
{
     char *tmp;
     switch (errtype){
     case NOHIST:      tmp = "Object was not a histogramm"; break;
     case NOHIST2D:    tmp = "Object was not a 2D histogramm"; break;
     case ARGNOHIST:   tmp = "Argument was not a histogramm"; break;
     case ARGNOHIST2D: tmp = "Argument was not a 2D histogramm"; break;
     case HISTP_NULL:  tmp = "Pointer to GSL histogramm(2d) object was NULL!"; break;
     default:          tmp = "Unknown case in function hist_error_helper"; myerrno = GSL_ESANITY; break;
     }
     PyGSL_add_traceback(module, filename, function, line);
     pygsl_error(tmp, filename, line, myerrno);
     return myerrno;
}

/*
 * Check if the recieved object is of approbriate type and that the histogram is defined.
 * Invokes PyGSL_hist_error_helper if it fails.
 * returns GSL_SUCCESS on success
 *
 * ob      ... the object to check
 * type    ... the Python type object
 * errcode ... the errorcode used to describe the failure type for 
 *             PyGSL_hist_error_helper
 */

#define _PyGSL_HIST_CHECK_INT(ob, type, errcode) \
     ((ob->ob_type == &(type)) ?  GSL_SUCCESS :  \
     PyGSL_hist_error_helper(__FUNCTION__, __LINE__, (errcode), GSL_ESANITY))

/*
 * returns the gsl histogram from the object
 */
#define _PyGSL_HIST_CAST(ob, type) (( ((type *)(ob)) ->h ))

/*
 * Check if it the gsl_histogram is not NULL. Will give a descriptive error
 * message if it fails.
 */
#define _PyGSL_HIST_CAST_SAVE(ob, type) \
      (\
          (_PyGSL_HIST_CAST((ob), type)  == NULL ) \
        ? \
          (PyGSL_hist_error_helper(__FUNCTION__, __LINE__, GSL_EFAULT, HISTP_NULL), NULL) \
        : \
          ( _PyGSL_HIST_CAST((ob), type) ) \
      ) 

/*
 * Try to get the gsl_histogram from the python object.
 * Checks for errors ...
 */
#define _PyGSL_HIST_GET_INT(ob, type, cast, errcode) \
      ( \
          (  _PyGSL_HIST_CHECK_INT((ob), type, (errcode)) == GSL_SUCCESS ) \
        ? \
          _PyGSL_HIST_CAST_SAVE((ob), cast) \
	: \
          NULL \
      )
#define _PyGSL_HIST_GET(ob, type, errcode) _PyGSL_HIST_GET_INT(ob, type ## Type, type ## Object, errcode) 

#define _PyGSL_HIST_CHECK(ob, errcode)   _PyGSL_HIST_CHECK_INT((ob), (histogram_histogramType), (errcode)) 
#define _PyGSL_HIST2D_CHECK(ob, errcode) _PyGSL_HIST_CHECK_INT((ob), (histogram_histogram2dType), (errcode)) 

#define PyGSL_HIST_CHECK(ob)       _PyGSL_HIST_CHECK((ob), (NOHIST)) 
#define PyGSL_HIST2D_CHECK(ob)     _PyGSL_HIST2D_CHECK((ob), (NOHIST2D)) 
#define PyGSL_HIST_ARG_CHECK(ob)   _PyGSL_HIST_CHECK((ob), (ARGNOHIST)) 
#define PyGSL_HIST2D_ARG_CHECK(ob) _PyGSL_HIST2D_CHECK((ob), (ARGNOHIST2D)) 

#define PyGSL_HIST_CAST(ob)   _PyGSL_HIST_CAST((ob), histogram_histogramObject)
#define PyGSL_HIST2D_CAST(ob) _PyGSL_HIST_CAST((ob), histogram_histogram2dObject)


#define PyGSL_HIST_GET(ob)        _PyGSL_HIST_GET((ob), histogram_histogram,   (NOHIST))
#define PyGSL_HIST2D_GET(ob)      _PyGSL_HIST_GET((ob), histogram_histogram2d, (NOHIST2D))
#define _PyGSL_HIST_GET_ARG(ob)   _PyGSL_HIST_GET((ob), histogram_histogram,   (ARGNOHIST))
#define _PyGSL_HIST2D_GET_ARG(ob) _PyGSL_HIST_GET((ob), histogram_histogram2d, (ARGNOHIST2D))


#define PyGSL_HIST_GET_ARG(ob)   ( ((ob) == NULL) ? NULL : _PyGSL_HIST_GET_ARG((ob)) )
#define PyGSL_HIST2D_GET_ARG(ob) ( ((ob) == NULL) ? NULL : _PyGSL_HIST2D_GET_ARG((ob)) )

/*
 * Helper function for dealing with warning and errors ...
 */
static int
PyGSL_warn_err(int rcode, int errcode, const char * errdes, const char * file, int line)
{
     int warn_result;   
     if (errcode==rcode) {
	  warn_result = PyGSL_warning(errdes, file, line, errcode);
	  if (warn_result==-1)
	       /* exception is raised by PyErr_Warn */
	       return GSL_EFAILED;
     }
     else if (PyGSL_ERROR_FLAG(rcode) != GSL_SUCCESS)
	  return rcode;

     return GSL_SUCCESS;
}

#define PyGSL_WARN_ERR(ob, errcode, errdes) \
   (\
       ((ob) == (GSL_SUCCESS)) \
      ? \
         GSL_SUCCESS \
      : \
          ((ob) == (errcode)) \
        ? PyGSL_warn_err(ob, errcode, errdes, filename, __LINE__) \
        : PyGSL_error_flag((ob)) \
    )  

static const char edom_message[] =  "value out of histogram range";
#define PyGSL_HIST_EDOM_WARN(ob) PyGSL_WARN_ERR((ob), GSL_EDOM, edom_message)

typedef int (*hist_op)(void *, const void *);
typedef int (*hist_file)(FILE *, void *);


static PyObject *
histogram_histogram_op(PyObject *self, PyObject * arg, hist_op fptr);
static PyObject *
histogram_histogram2d_op(PyObject *self, PyObject * arg, hist_op fptr);
static PyObject *
histogram_histogram_file(PyObject *self, PyObject * arg, hist_file fptr);
static PyObject *
histogram_histogram2d_file(PyObject *self, PyObject * arg, hist_file fptr);


/*
 *
 * histogram type
 * for 1d histogram data
 *
 */


/* my typedef */

staticforward PyTypeObject histogram_histogramType;
staticforward PyMethodDef histogram_histogram_methods[];

typedef struct {
    PyObject_HEAD
    gsl_histogram* h;
} histogram_histogramObject;


#define _CONCAT2(class, suffix) class ## _ ## suffix

#include "histogram.ic"

#define HISTTYPE gsl_histogram
#define PyGSLHISTTYPE histogram_histogramType
#define PyGSL_HIST_TYPE_GET(ob) PyGSL_HIST_GET((ob))
#define PyGSL_HIST_TYPE_CAST(ob) PyGSL_HIST_CAST((ob))
#define PyGSL_HIST_TYPE_ARG_GET(ob) PyGSL_HIST_GET_ARG((ob))
#define GSLNAME(suffix)  _CONCAT2(gsl_histogram, suffix)
#define FUNCNAME(suffix) _CONCAT2(histogram_histogram, suffix)
#ifdef HISTOGRAM2D
#undef HISTOGRAM2D
#endif
#include "histogram_pdf_common.ic"
#include "histogram_common.ic"

#undef HISTTYPE
#undef PyGSLHISTTYPE
#undef PyGSL_HIST_TYPE_GET
#undef PyGSL_HIST_TYPE_CAST
#undef PyGSL_HIST_TYPE_ARG_GET
#undef FUNCNAME 
#undef GSLNAME



static
PyTypeObject histogram_histogramType = {
	PyObject_HEAD_INIT(NULL)
	0,
	"pygsl.histogram.histogram",
	sizeof(histogram_histogramObject),
	0,
	(destructor)histogram_histogram_dealloc, /* tp_dealloc */
	0,                                      /* tp_print */
	histogram_histogram_getattr,            /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	&histogram_histogram_as_mapping,	/* tp_as_mapping */
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
	(initproc)histogram_histogram_init,	/* tp_init */
	NULL,              			/* tp_alloc */
	NULL,                			/* tp_new */
	NULL         			        /* tp_free */
};


/*
 *
 * here begins the section for the 2d histogram
 *
 */

/* my typedef */

staticforward PyTypeObject histogram_histogram2dType;
staticforward PyMethodDef histogram_histogram2d_methods[];
typedef struct {
    PyObject_HEAD
    gsl_histogram2d* h;
} histogram_histogram2dObject;


static PyObject *
histogram_histogram2d_reset(PyObject *);

#include "histogram2d.ic"
#define HISTOGRAM2D 1
#define HISTTYPE gsl_histogram2d
#define PyGSLHISTTYPE histogram_histogram2dType
#define PyGSL_HIST_TYPE_GET(ob) PyGSL_HIST2D_GET((ob))
#define PyGSL_HIST_TYPE_ARG_GET(ob) PyGSL_HIST2D_GET_ARG((ob))
#define PyGSL_HIST_TYPE_CAST(ob) PyGSL_HIST2D_CAST((ob))
#define GSLNAME(suffix)  _CONCAT2(gsl_histogram2d, suffix)
#define FUNCNAME(suffix) _CONCAT2(histogram_histogram2d, suffix)
#include "histogram_pdf_common.ic"
#include "histogram_common.ic"



static
PyTypeObject histogram_histogram2dType = {
	PyObject_HEAD_INIT(NULL)
	0,
	"pygsl.histogram.histogram2d",
	sizeof(histogram_histogram2dObject),
	0,
	(destructor)histogram_histogram2d_dealloc, /* tp_dealloc */
	0,                                      /* tp_print */
	histogram_histogram2d_getattr,          /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	0,                  			/* tp_repr */
	0,					/* tp_as_number */
	0,	                		/* tp_as_sequence */
	&histogram_histogram2d_as_mapping,      /* tp_as_mapping */
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
	(initproc)histogram_histogram2d_init,	/* tp_init */
	NULL,            			/* tp_alloc */
	NULL,			                /* tp_new */
	NULL			                /* tp_free */
};

#include "histogram_pdf.ic"
/*
 *
 * module specific stuff
 *
 */


static PyMethodDef histogramMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};


void 
register_type(PyTypeObject *p, char *name)
{
     p->ob_type  = &PyType_Type;
     p->tp_alloc = PyType_GenericAlloc;
     p->tp_new   = PyType_GenericNew;
     p->tp_free  = _PyObject_Del;
     /* install histogram type */
     /* important! must increment histogram type reference counter */
     Py_INCREF((PyObject*)p);
     PyModule_AddObject(module, name, (PyObject*)p);     
}


#ifdef PyGSL_PY3K
PyObject *PyInit_histogram(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) inithistogram(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
  PyObject* m;
  m=Py_InitModule("histogram", histogramMethods);
  if(!m)
       return;

  module = m;
  init_pygsl();
  /* init histogram type */
  register_type(&histogram_histogramType, "histogram");
  register_type(&histogram_histogram_pdfType, "histogram_pdf");
  register_type(&histogram_histogram2dType, "histogram2d");
  register_type(&histogram_histogram2d_pdfType, "histogram2d_pdf");

  return RETVAL;
}
