/* Odeint solver */
#include <pygsl/utils.h>
#include <pygsl/block_helpers.h>
#include <pygsl/error_helpers.h>
#include <Python.h>
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_errno.h>

char odeiv_module_doc[] = "XXX odeiv module doc missing!\n";

static char this_file[] = __FILE__;
static PyObject *module = NULL; /* set by initodeiv */ 

#if 0
static void			/* generic instance destruction */
generic_dealloc (PyObject *self)
{
  DEBUG_MESS(1, " *** generic_dealloc %p\n", (void *) self);
  PyMem_Free(self);
}
#endif 

typedef struct {
     PyObject_HEAD
     gsl_odeiv_step * step;
     gsl_odeiv_system system;
     PyObject *py_func;
     PyObject *py_jac;
     PyObject *arguments;
     jmp_buf buffer;
}
PyGSL_odeiv_step;

typedef struct {
     PyObject_HEAD
     PyGSL_odeiv_step * step;
     gsl_odeiv_control * control;
} PyGSL_odeiv_control;

typedef struct {
     PyObject_HEAD
     PyGSL_odeiv_step * step;
     PyGSL_odeiv_control * control;
     gsl_odeiv_evolve * evolve;
} PyGSL_odeiv_evolve;

/*---------------------------------------------------------------------------
 * Declaration of the various Methods
 *---------------------------------------------------------------------------*/
/*
 * stepper
 */
static int 
PyGSL_odeiv_func(double t, const double y[], double f[], void *params);
static int 
PyGSL_odeiv_jac(double t, const double y[], double *dfdy, double dfdt[], 
		void *params);
static PyObject *
PyGSL_odeiv_step_apply(PyGSL_odeiv_step *self, PyObject *args);
static PyObject *
PyGSL_odeiv_step_reset(PyGSL_odeiv_step *self, PyObject *args);
static PyObject *
PyGSL_odeiv_step_name(PyGSL_odeiv_step *self, PyObject *args);
static PyObject *
PyGSL_odeiv_step_order(PyGSL_odeiv_step *self, PyObject *args);
static void 
PyGSL_odeiv_step_free(PyGSL_odeiv_step * self);

/*
 * control 
 */
static PyObject *
PyGSL_odeiv_control_hadjust(PyGSL_odeiv_control *self, PyObject *args);
static PyObject *
PyGSL_odeiv_control_name(PyGSL_odeiv_control *self, PyObject *args);
static void 
PyGSL_odeiv_control_free(PyGSL_odeiv_control * self);

/*
 * evolve
 */
static PyObject *
PyGSL_odeiv_evolve_apply(PyGSL_odeiv_evolve *self, PyObject *args);
static PyObject *
PyGSL_odeiv_evolve_apply_array(PyGSL_odeiv_evolve *self, PyObject *args);
static PyObject *
PyGSL_odeiv_evolve_reset(PyGSL_odeiv_evolve *self, PyObject *args);
static void 
PyGSL_odeiv_evolve_free(PyGSL_odeiv_evolve * self);
/*---------------------------------------------------------------------------*/



static char  PyGSL_odeiv_step_doc[] = "XXX Documentation missing\n"; 
static char  PyGSL_odeiv_control_doc[] = "XXX Documentation missing\n";
static char  PyGSL_odeiv_evolve_doc[] = "XXX Documentation missing\n"; 
       
static char odeiv_step_apply_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_step_name_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_step_order_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_step_reset_doc[] =  "XXX Documentation missing\n"; 
       
static char odeiv_control_name_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_control_hadjust_doc[] =  "XXX Documentation missing\n"; 


static char odeiv_evolve_apply_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_evolve_apply_array_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_evolve_reset_doc[] =  "XXX Documentation missing\n";

static char * odeiv_step_init_err_msg = "odeiv_step.__init__";

static struct PyMethodDef PyGSL_odeiv_step_methods[] = {
     {"apply", (PyCFunction) PyGSL_odeiv_step_apply, METH_VARARGS, odeiv_step_apply_doc},
     {"reset", (PyCFunction) PyGSL_odeiv_step_reset, METH_VARARGS, odeiv_step_reset_doc},
     {"name",  (PyCFunction) PyGSL_odeiv_step_name,  METH_VARARGS, odeiv_step_name_doc},
     {"order", (PyCFunction) PyGSL_odeiv_step_order, METH_VARARGS, odeiv_step_order_doc},
     {NULL, NULL}
};
static struct PyMethodDef PyGSL_odeiv_control_methods[] = {
     {"hadjust", (PyCFunction) PyGSL_odeiv_control_hadjust, METH_VARARGS, odeiv_control_hadjust_doc},
     {"name",  (PyCFunction) PyGSL_odeiv_control_name,  METH_VARARGS, odeiv_control_name_doc},
     {NULL, NULL}
};

static struct PyMethodDef PyGSL_odeiv_evolve_methods[] = {
     {"apply", (PyCFunction) PyGSL_odeiv_evolve_apply, METH_VARARGS, odeiv_evolve_apply_doc},
     {"reset", (PyCFunction) PyGSL_odeiv_evolve_reset, METH_VARARGS, odeiv_evolve_reset_doc},
     {"apply_array", (PyCFunction) PyGSL_odeiv_evolve_apply_array, METH_VARARGS, odeiv_evolve_apply_array_doc},
     {NULL, NULL}
};






#define PyGSL_ODEIV_GENERIC_ALL                                                           \
static PyObject *									  \
PyGSL_ODEIV_GENERIC_GETATTR(PyGSL_ODEIV_GENERIC *self, char *name)		          \
{											  \
     PyObject *tmp = NULL;								  \
											  \
     FUNC_MESS_BEGIN();									  \
     tmp = Py_FindMethod(PyGSL_ODEIV_GENERIC_METHODS, (PyObject *) self, name);	          \
     if(NULL == tmp){	  								  \
	  PyGSL_add_traceback(module, __FILE__, "odeiv.__attr__", __LINE__ - 1);	  \
	  return NULL;									  \
     }											  \
     FUNC_MESS_END();									  \
     return tmp;                                                                          \
}                                                                                         \
static PyTypeObject PyGSL_ODEIV_GENERIC_PYTYPE = {					  \
  PyObject_HEAD_INIT(NULL)	/* fix up the type slot in initcrng */			  \
  0,				/* ob_size */						  \
  PyGSL_ODEIV_GENERIC_NAME,			/* tp_name */			          \
  sizeof(PyGSL_ODEIV_GENERIC),  /* tp_basicsize */					  \
  0,				/* tp_itemsize */					  \
											  \
  /* standard methods */								  \
  (destructor)  PyGSL_ODEIV_GENERIC_DELETE,       /* tp_dealloc  ref-count==0  */	  \
  (printfunc)   0,		                      /* tp_print    "print x"     */	  \
  (getattrfunc) PyGSL_ODEIV_GENERIC_GETATTR,       /* tp_getattr  "x.attr"      */	  \
  (setattrfunc) 0,		   /* tp_setattr  "x.attr=v"    */			  \
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */			  \
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */			  \
											  \
  /* type categories */									  \
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/		  \
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/		  \
  0,				/* tp_as_mapping  [key], len, ...*/			  \
											  \
  /* more methods */									  \
  (hashfunc)     0,		/* tp_hash    "dict[x]" */				  \
  (ternaryfunc)  0,             /* tp_call    "x()"     */				  \
  (reprfunc)     0,             /* tp_str     "str(x)"  */				  \
  (getattrofunc) 0,		/* tp_getattro */					  \
  (setattrofunc) 0,		/* tp_setattro */					  \
  0,				/* tp_as_buffer */					  \
  0L,				/* tp_flags */						  \
  PyGSL_ODEIV_GENERIC_DOC       /* doc */                                                 \
};                                                                                        


#define PyGSL_ODEIV_GENERIC            PyGSL_odeiv_step
#define PyGSL_ODEIV_GENERIC_NAME      "PyGSL_odeiv_step"
#define PyGSL_ODEIV_GENERIC_PYTYPE     PyGSL_odeiv_step_pytype
#define PyGSL_ODEIV_GENERIC_DOC        PyGSL_odeiv_step_doc
#define PyGSL_ODEIV_GENERIC_GETATTR    PyGSL_odeiv_step_getattr
#define PyGSL_ODEIV_GENERIC_METHODS    PyGSL_odeiv_step_methods
#define PyGSL_ODEIV_GENERIC_DELETE     PyGSL_odeiv_step_free
PyGSL_ODEIV_GENERIC_ALL
/**/;
#undef PyGSL_ODEIV_GENERIC       
#undef PyGSL_ODEIV_GENERIC_NAME  
#undef PyGSL_ODEIV_GENERIC_PYTYPE
#undef PyGSL_ODEIV_GENERIC_DOC   
#undef PyGSL_ODEIV_GENERIC_GETATTR
#undef PyGSL_ODEIV_GENERIC_METHODS
#undef PyGSL_ODEIV_GENERIC_DELETE
#define PyGSL_ODEIV_GENERIC            PyGSL_odeiv_control
#define PyGSL_ODEIV_GENERIC_NAME      "PyGSL_odeiv_control"
#define PyGSL_ODEIV_GENERIC_PYTYPE     PyGSL_odeiv_control_pytype
#define PyGSL_ODEIV_GENERIC_DOC        PyGSL_odeiv_control_doc
#define PyGSL_ODEIV_GENERIC_GETATTR    PyGSL_odeiv_control_getattr
#define PyGSL_ODEIV_GENERIC_METHODS    PyGSL_odeiv_control_methods
#define PyGSL_ODEIV_GENERIC_DELETE     PyGSL_odeiv_control_free
PyGSL_ODEIV_GENERIC_ALL
/**/;
#undef PyGSL_ODEIV_GENERIC       
#undef PyGSL_ODEIV_GENERIC_NAME  
#undef PyGSL_ODEIV_GENERIC_PYTYPE
#undef PyGSL_ODEIV_GENERIC_DOC   
#undef PyGSL_ODEIV_GENERIC_GETATTR
#undef PyGSL_ODEIV_GENERIC_METHODS
#undef PyGSL_ODEIV_GENERIC_DELETE
#define PyGSL_ODEIV_GENERIC            PyGSL_odeiv_evolve
#define PyGSL_ODEIV_GENERIC_NAME      "PyGSL_odeiv_evolve"
#define PyGSL_ODEIV_GENERIC_PYTYPE     PyGSL_odeiv_evolve_pytype
#define PyGSL_ODEIV_GENERIC_DOC        PyGSL_odeiv_evolve_doc
#define PyGSL_ODEIV_GENERIC_GETATTR    PyGSL_odeiv_evolve_getattr
#define PyGSL_ODEIV_GENERIC_METHODS    PyGSL_odeiv_evolve_methods
#define PyGSL_ODEIV_GENERIC_DELETE     PyGSL_odeiv_evolve_free
PyGSL_ODEIV_GENERIC_ALL
/**/;

#define PyGSL_ODEIV_STEP_Check(v)    ((v)->ob_type == &PyGSL_odeiv_step_pytype)
#define PyGSL_ODEIV_CONTROL_Check(v) ((v)->ob_type == &PyGSL_odeiv_control_pytype)
#define PyGSL_ODEIV_EVOLVE_Check(v)  ((v)->ob_type == &PyGSL_odeiv_evolve_pytype)

/*---------------------------------------------------------------------------
  Wrapper functions to push call the approbriate Python Objects
  ---------------------------------------------------------------------------*/
static int 
PyGSL_odeiv_func(double t, const double y[], double f[], void *params)
{
    int dimension, flag = GSL_FAILURE;

    PyObject *arglist = NULL, *result = NULL;
    PyArrayObject *yo = NULL;
    PyGSL_odeiv_step * step;
    gsl_vector_view yv, fv;
    PyGSL_error_info  info;

    FUNC_MESS_BEGIN();

    step = (PyGSL_odeiv_step *) params;
    if(!PyGSL_ODEIV_STEP_Check(step)){
	  PyGSL_add_traceback(module, this_file, __FUNCTION__, 
			      __LINE__ - 2);
	  gsl_error("Param not a step type!", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail;
    }
    dimension =  step->system.dimension;


    /* Do I need to copy the array ??? */
    yv = gsl_vector_view_array((double *) y, dimension);
    yo = PyGSL_copy_gslvector_to_pyarray(&yv.vector);
    if (yo == NULL) goto fail;

    FUNC_MESS("\t\tBuild args");
    arglist = Py_BuildValue("(dOO)", t, yo, step->arguments);
    FUNC_MESS("\t\tEnd Build args");

    info.callback = step->py_func;
    info.message  = "odeiv_func";
    result  = PyEval_CallObject(step->py_func, arglist);


    if((flag = PyGSL_CHECK_PYTHON_RETURN(result, 1, &info)) != GSL_SUCCESS){
	  goto fail;
     }
    info.argnum = 1;
    fv = gsl_vector_view_array(f, dimension);
    if((flag = PyGSL_copy_pyarray_to_gslvector(&fv.vector, result, dimension, 
					       &info)) != GSL_SUCCESS){
	  goto fail;
     }     
     

    Py_DECREF(arglist);    arglist = NULL;
    Py_DECREF(yo);         yo = NULL;
    Py_DECREF(result);     result = NULL;
    FUNC_MESS_END();
    return GSL_SUCCESS;

 fail:
    FUNC_MESS("    IN Fail BEGIN");
    Py_XDECREF(yo);
    Py_XDECREF(result);
    Py_XDECREF(arglist);
    FUNC_MESS("    IN Fail END");
    assert(flag != GSL_SUCCESS);
    longjmp(step->buffer, flag);
    return flag;
}

static int 
PyGSL_odeiv_jac(double t, const double y[], double *dfdy, double dfdt[], 
		void *params)
{
    int dimension, flag = GSL_FAILURE;
    PyGSL_odeiv_step *step = NULL;
    PyGSL_error_info  info;
    
    PyObject *arglist = NULL, *result = NULL, *tmp=NULL;
    PyArrayObject *yo = NULL;

    gsl_vector_view yv, dfdtv;
    gsl_matrix_view dfdyv;


    FUNC_MESS_BEGIN();
    
    step = (PyGSL_odeiv_step *) params;
    if(!PyGSL_ODEIV_STEP_Check(step)){
	  PyGSL_add_traceback(module, this_file, __FUNCTION__, 
			      __LINE__ - 2);
	  gsl_error("Param not a step type!", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail;
    }
    dimension = step->system.dimension;



    yv = gsl_vector_view_array((double *) y, dimension);
    yo = PyGSL_copy_gslvector_to_pyarray(&yv.vector);
    if (yo == NULL) goto fail;


    arglist = Py_BuildValue("(dOO)", t, yo, step->arguments);

    assert(step->py_jac);
    result  = PyEval_CallObject(step->py_jac, arglist);

    info.callback = step->py_jac;
    info.message  = "odeiv_jac";
    if((flag = PyGSL_CHECK_PYTHON_RETURN(result, 2, &info)) != GSL_SUCCESS){
	  goto fail;
     }

    info.argnum = 1;
    tmp = PyTuple_GET_ITEM(result, 0);
    dfdyv = gsl_matrix_view_array((double *) dfdy, dimension, dimension);
    if((flag = PyGSL_copy_pyarray_to_gslmatrix(&dfdyv.matrix, tmp, dimension, dimension, &info)) != GSL_SUCCESS){
	  goto fail;
    }     
    
    info.argnum = 2;
    tmp = PyTuple_GET_ITEM(result, 1);
    dfdtv = gsl_vector_view_array((double *) dfdt, dimension);
    if((flag = PyGSL_copy_pyarray_to_gslvector(&dfdtv.vector, tmp, dimension, &info)) != GSL_SUCCESS){
	  goto fail;
    }     

          
    Py_DECREF(arglist);    arglist = NULL;
    Py_DECREF(result);     result = NULL;
    Py_DECREF(yo);         yo = NULL;
    FUNC_MESS_END();
    return GSL_SUCCESS;

 fail:
    FUNC_MESS("IN Fail");
    assert(flag != GSL_SUCCESS);
    longjmp(step->buffer, flag);
    return flag;
}


/* Wrappers for the evaluation of the system */
static PyObject *
PyGSL_odeiv_step_apply(PyGSL_odeiv_step *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *y0_o = NULL, *dydt_in_o = NULL;
    PyArrayObject *volatile y0 = NULL, * volatile yerr = NULL, 
	 *volatile dydt_in = NULL, *volatile dydt_out = NULL,
	 *volatile yout = NULL;

    double t=0, h=0, *volatile dydt_in_d;
    int dimension, r, flag;


    FUNC_MESS_BEGIN();
    assert(PyGSL_ODEIV_STEP_Check(self));
    if(! PyArg_ParseTuple(args, "ddOOO", &t, &h, &y0_o,  &dydt_in_o)){
      return NULL;
    }


    dimension = self->system.dimension;
    y0 = PyGSL_PyArray_PREPARE_gsl_vector_view(y0_o, PyArray_DOUBLE, 1, dimension, 1, NULL);
    if(y0 == NULL) goto fail;


    if (Py_None == dydt_in_o){
	 dydt_in_d = NULL;
    }else{
	 dydt_in = PyGSL_PyArray_PREPARE_gsl_vector_view(dydt_in_o, PyArray_DOUBLE, 1, dimension, 2, NULL);
	 if(dydt_in == NULL) goto fail;
	 dydt_in_d = (double *) dydt_in->data;
    }


    dydt_out = (PyArrayObject *)  PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
    if (dydt_out == NULL) goto fail;

    yerr = (PyArrayObject *) PyArray_FromDims(1, &dimension, PyArray_DOUBLE);
    if(yerr == NULL) goto fail;


    yout = (PyArrayObject *) PyArray_CopyFromObject((PyObject * ) y0, PyArray_DOUBLE, 1, 1);
    if(yout == NULL) goto fail;


    if((flag=setjmp(self->buffer)) == 0){
	  FUNC_MESS("\t\t Setting Jmp Buffer");
    } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  goto fail;
    }
    
    r = gsl_odeiv_step_apply(self->step, t, h, 
			     (double *) yout->data, 
			     (double *) yerr->data, 
			     dydt_in_d, 
			     (double *) dydt_out->data, 
			     &(self->system));
    if (GSL_SUCCESS != r){
	PyErr_SetString(PyExc_TypeError, "Error While evaluating gsl_odeiv");
      goto fail;
    }

    FUNC_MESS("    Returnlist create ");
    assert(yout != NULL);
    assert(yerr != NULL);
    assert(dydt_out != NULL);

    result = Py_BuildValue("(OOO)", yout, yerr, dydt_out);

    FUNC_MESS("    Memory free ");
    /* Deleting the arrays */    
    Py_DECREF(y0);           y0 = NULL;
    Py_DECREF(yout);         yout = NULL;
    Py_DECREF(yerr);         yerr = NULL;
    Py_DECREF(dydt_out);     dydt_out = NULL;
    /* This array does not need to exist ... */
    Py_XDECREF(dydt_in);	 dydt_in=NULL;
    
    FUNC_MESS_END();
    return result;

    fail:
    FUNC_MESS("IN Fail");
    Py_XDECREF(y0);
    Py_XDECREF(yout);
    Py_XDECREF(yerr);
    Py_XDECREF(dydt_in);
    Py_XDECREF(dydt_out);
    FUNC_MESS("IN Fail End");   
    return NULL;
}



static void 
PyGSL_odeiv_step_free(PyGSL_odeiv_step * self)
{
     assert(PyGSL_ODEIV_STEP_Check(self));
     Py_DECREF(self->py_func);
     Py_XDECREF(self->py_jac);
     Py_DECREF(self->arguments);
     gsl_odeiv_step_free(self->step);
     PyMem_Free(self);
}

static PyObject *
PyGSL_odeiv_step_reset(PyGSL_odeiv_step *self, PyObject *args)
{
     assert(PyGSL_ODEIV_STEP_Check(self));
     gsl_odeiv_step_reset(self->step);
     Py_INCREF(Py_None);
     return Py_None;
}

static PyObject *
PyGSL_odeiv_step_name(PyGSL_odeiv_step *self, PyObject *args)
{
     assert(PyGSL_ODEIV_STEP_Check(self));
     return PyString_FromString(gsl_odeiv_step_name(self->step));
}

static PyObject *
PyGSL_odeiv_step_order(PyGSL_odeiv_step *self, PyObject *args)
{
     assert(PyGSL_ODEIV_STEP_Check(self));
     return PyInt_FromLong((long) gsl_odeiv_step_order(self->step));
}


/* --------------------------------------------------------------------------- */
/* control_hadjust needs a few arrays */
/*
extern int 
gsl_odeiv_control_hadjust (gsl_odeiv_control * c, gsl_odeiv_step * s, 
			   const double y0[],  const double yerr[], 
			   const double dydt[], double * h);
*/
static PyObject *
PyGSL_odeiv_control_hadjust(PyGSL_odeiv_control *self, PyObject *args)
{
  
  PyObject *result = NULL;
  PyObject *y0_o = NULL, *yerr_o = NULL, *dydt_o = NULL;
  PyArrayObject *y0 = NULL, *yerr = NULL, *dydt = NULL;
  double h = 0;
  int r = 0;


  size_t dimension = 0;

  FUNC_MESS_BEGIN();
  assert(PyGSL_ODEIV_CONTROL_Check(self));
  if(!PyArg_ParseTuple(args, "OOOd",  &y0_o, &yerr_o, &dydt_o, &h)){
    return NULL;
  }

  dimension = self->step->system.dimension;


  y0 = PyGSL_PyArray_PREPARE_gsl_vector_view(y0_o, PyArray_DOUBLE, 1, dimension,  1, NULL);
  if(y0 == NULL)   goto fail;
  yerr = PyGSL_PyArray_PREPARE_gsl_vector_view(yerr_o, PyArray_DOUBLE, 1, dimension, 2, NULL);
  if(yerr == NULL) goto fail;
  dydt = PyGSL_PyArray_PREPARE_gsl_vector_view(yerr_o, PyArray_DOUBLE, 1, dimension, 3, NULL);
  if(dydt == NULL) goto fail;
  
  FUNC_MESS("      Array Pointers End");

  r = gsl_odeiv_control_hadjust(self->control, self->step->step, 
				(double *) y0->data,
				(double *) yerr->data,
				(double *) dydt->data, &h);

  FUNC_MESS("      Function End");
  Py_DECREF(y0);       y0 = NULL;  
  Py_DECREF(yerr);     yerr = NULL;
  Py_DECREF(dydt);     dydt = NULL;

  result = Py_BuildValue("di",h,r);
  FUNC_MESS_END();
  return result;

 fail:
  FUNC_MESS("IN Fail");
  Py_XDECREF(y0);
  Py_XDECREF(yerr);
  Py_XDECREF(dydt);
  FUNC_MESS("IN Fail END");
  return NULL;
}


static void 
PyGSL_odeiv_control_free(PyGSL_odeiv_control * self)
{
     assert(PyGSL_ODEIV_CONTROL_Check(self));
     Py_DECREF(self->step);
     //gsl_odeiv_control_free(self->control);
     PyMem_Free(self);
}

static PyObject *
PyGSL_odeiv_control_name(PyGSL_odeiv_control *self, PyObject *args)
{
     assert(PyGSL_ODEIV_CONTROL_Check(self));
     return PyString_FromString(gsl_odeiv_control_name(self->control));
}

static void 
PyGSL_odeiv_evolve_free(PyGSL_odeiv_evolve * self)
{
     assert(PyGSL_ODEIV_EVOLVE_Check(self));
     Py_DECREF(self->step);
     Py_DECREF(self->control);
     gsl_odeiv_evolve_free(self->evolve);
     PyMem_Free(self);
}

static PyObject *
PyGSL_odeiv_evolve_apply(PyGSL_odeiv_evolve *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *y0_o = NULL;
    PyArrayObject *volatile y0 = NULL, *volatile yout = NULL;

    double t=0, h=0, t1 = 0, flag;

    int dimension, r;

    assert(PyGSL_ODEIV_EVOLVE_Check(self));
    FUNC_MESS_BEGIN();

    if(! PyArg_ParseTuple(args, "dddO",
			  &t, &t1, &h, &y0_o)){
      return NULL;
    }

    dimension = self->step->system.dimension;



    y0 = PyGSL_PyArray_PREPARE_gsl_vector_view(y0_o, PyArray_DOUBLE, 1, dimension, 1, NULL);
    if(y0 == NULL) goto fail;


    yout = (PyArrayObject *)  PyArray_CopyFromObject((PyObject * ) y0, PyArray_DOUBLE, 1, 1);
    if(yout == NULL) goto fail;


    if((flag=setjmp(self->step->buffer)) == 0){
	  FUNC_MESS("\t\t Setting Jmp Buffer");
     } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  goto fail;
     }

    r = gsl_odeiv_evolve_apply(self->evolve, 
			       self->control->control, 
			       self->step->step, 
			       &(self->step->system), &t, t1, &h,
			       (double * )yout->data); 

    if (GSL_SUCCESS != r){
	 goto fail;
    } 


    assert(yout != NULL);


    result = Py_BuildValue("(ddO)", t, h, yout);

    /* Deleting the arrays */    
    /* Do I need to do that??? Not transfered Py_DECREF(yout);     yout = NULL; */
    Py_DECREF(y0);       y0=NULL;
    FUNC_MESS_END();
    return result;

 fail:
    FUNC_MESS("IN Fail");
    PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__);
    Py_XDECREF(y0);
    Py_XDECREF(yout); 
    FUNC_MESS("IN Fail End");   
    return NULL;
}

static PyObject *
PyGSL_odeiv_evolve_apply_array(PyGSL_odeiv_evolve *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *y0_o = NULL;
    PyObject *t_o = NULL;
    PyArrayObject *volatile y0 = NULL, *volatile yout = NULL, *volatile ta = NULL;

    double t=0, h=0, t1 = 0, flag;
    double *y0_data = NULL, *yout_data = NULL;
    int dimension, r, dims[2];
    int nlen=-1, i, j;

    assert(PyGSL_ODEIV_EVOLVE_Check(self));
    FUNC_MESS_BEGIN();

    if(! PyArg_ParseTuple(args, "OdO", &t_o, &h, &y0_o)){
      return NULL;
    }

    dimension = self->step->system.dimension;

    ta = PyGSL_PyArray_PREPARE_gsl_vector_view(t_o, PyArray_DOUBLE, 1, -1, 1, NULL);
    if(ta == NULL) goto fail;
    nlen = ta->dimensions[0];

    y0 = PyGSL_PyArray_PREPARE_gsl_vector_view(y0_o, PyArray_DOUBLE, 1, dimension, 1, NULL);
    if(y0 == NULL) goto fail;

    dims[0] = nlen;
    dims[1] = dimension;
    yout = (PyArrayObject *)  PyArray_FromDims(2, dims, PyArray_DOUBLE);
    if(yout == NULL) goto fail;


    if((flag=setjmp(self->step->buffer)) == 0){
	  FUNC_MESS("\t\t Setting Jmp Buffer");
     } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  goto fail;
     }

    DEBUG_MESS(5, "\t\t Yout Layout %p, shape=[%d,%d], strides=[%d,%d]", 
	       yout->data, yout->dimensions[0], yout->dimensions[1], yout->strides[0], yout->strides[1]);
    r = GSL_CONTINUE;

    yout_data = (double *)(yout->data);
    /* Copy the start vector */
    for(j=0; j<dimension; j++){
	 yout_data[j] = *((double *)(y0->data + y0->strides[0] * j));
    }
    for(i=1; i<nlen; i++){
	 y0_data   = (double *)(yout->data + yout->strides[0]*(i-1));	 
	 yout_data = (double *)(yout->data + yout->strides[0]*(i)  );	 
	 /* Copy the start vector */
	 for(j=0; j<dimension; j++){
	      yout_data[j] = y0_data[j];
	 }
	 t =  *((double *) (ta->data + ta->strides[0]*(i-1)) );	 
	 t1 = *((double *) (ta->data + ta->strides[0]*(i)  ) );	 

	 while(t<t1){
	      r = gsl_odeiv_evolve_apply(self->evolve, 
					 self->control->control, 
					 self->step->step, 
					 &(self->step->system), &t, t1, &h,
					 yout_data); 
	      /* All GSL Errors are > 0. */
	      if (r != GSL_SUCCESS){
		   goto fail;
	      }
	 }
	 assert(r == GSL_SUCCESS);
    }


    result = (PyObject *) yout;

    /* Deleting the arrays */    
    Py_DECREF(y0); y0=NULL;
    Py_DECREF(ta); 
    FUNC_MESS_END();
    return result;

 fail:
    FUNC_MESS("IN Fail");
    PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__);
    Py_XDECREF(ta);  ta = NULL;
    Py_XDECREF(y0);  y0=NULL;
    Py_XDECREF(yout); 
    FUNC_MESS("IN Fail End");   
    return NULL;
}

static PyObject *
PyGSL_odeiv_evolve_reset(PyGSL_odeiv_evolve *self, PyObject *args)
{
     assert(PyGSL_ODEIV_EVOLVE_Check(self));
     gsl_odeiv_evolve_reset(self->evolve);
     Py_INCREF(Py_None);
     return Py_None;
}



static PyObject *
PyGSL_odeiv_step_init(PyObject *self, PyObject *args, PyObject *kwdict, const gsl_odeiv_step_type * odeiv_type)
{
     
     PyObject *func=NULL, *jac=NULL, *o_params=NULL;
     PyGSL_odeiv_step *odeiv_step = NULL;

     static char * kwlist[] = {"dimension", "func", "jac", "args", NULL}; 
     int dim, has_jacobian = 0;

     FUNC_MESS_BEGIN();
     assert(args);
     if (0 == PyArg_ParseTupleAndKeywords(args, kwdict, "iOOO:odeiv_step.__init__", kwlist, 
					  &dim, &func, &jac, &o_params)){
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 2);
	  return NULL;
     }     
     if (dim <= 0){	  
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	  gsl_error("The dimension of the problem must be at least 1", 
		    this_file, __LINE__ -2, GSL_EDOM);
	  return NULL;
     }
     if(!PyCallable_Check(func)){
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	  gsl_error("The function object is not callable!", 
		    this_file, __LINE__ -2, GSL_EBADFUNC);
	  goto fail;	  
     }

     if(jac == Py_None){
	  if(odeiv_type == gsl_odeiv_step_bsimp){
	       PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	       gsl_error("The bsimp method needs a jacobian! You supplied None.", 
			 this_file, __LINE__ -2, GSL_EBADFUNC);
	       goto fail;
	  }
     }else{
	  if(!PyCallable_Check(jac)){
	       PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	       gsl_error("The jacobian object must be None or callable!", 
			 this_file, __LINE__ -2, GSL_EBADFUNC);
	       goto fail;
	  }
	  has_jacobian = 1;

     }

     odeiv_step =  (PyGSL_odeiv_step *) PyObject_NEW(PyGSL_odeiv_step, &PyGSL_odeiv_step_pytype);
     if(odeiv_step == NULL){
	  PyErr_NoMemory();
	  goto fail;
     }
     odeiv_step->step=NULL;
     odeiv_step->py_func=NULL;
     odeiv_step->py_jac=NULL;
     odeiv_step->arguments=NULL;

     odeiv_step->system.dimension = dim;
     if(has_jacobian)
	  odeiv_step->system.jacobian = PyGSL_odeiv_jac;
     else
	  odeiv_step->system.jacobian = NULL;

     odeiv_step->system.function = PyGSL_odeiv_func;
     odeiv_step->system.params = (void *) odeiv_step;

     odeiv_step->step =  gsl_odeiv_step_alloc(odeiv_type, dim);     
     if(odeiv_step->step == NULL){
	  Py_DECREF(odeiv_step);
	  PyErr_NoMemory();
	  return NULL;
     }

     odeiv_step->py_func=func;
     if(has_jacobian)
	  odeiv_step->py_jac=jac;

     odeiv_step->arguments = o_params;
     Py_INCREF(odeiv_step->py_func);
     Py_INCREF(odeiv_step->arguments);

     
     Py_XINCREF(odeiv_step->py_jac);

     FUNC_MESS_END();
     return (PyObject *) odeiv_step;
 fail:
     return NULL;
}
#define ADD_ODESTEPPER(mytype)                                                      \
static PyObject *                                                                   \
PyGSL_odeiv_step_init_ ## mytype (PyObject * self, PyObject * args, PyObject *kwdic)\
{                                                                                   \
     return PyGSL_odeiv_step_init(self, args, kwdic, gsl_odeiv_step_ ## mytype);    \
}   
ADD_ODESTEPPER(rk2)
ADD_ODESTEPPER(rk4)
ADD_ODESTEPPER(rkf45)
ADD_ODESTEPPER(rkck)
ADD_ODESTEPPER(rk8pd)
ADD_ODESTEPPER(rk2imp)
ADD_ODESTEPPER(rk4imp)
ADD_ODESTEPPER(bsimp)
ADD_ODESTEPPER(gear1)
ADD_ODESTEPPER(gear2)


static PyObject *
PyGSL_odeiv_control_init(PyObject *self, PyObject *args, void * type)
{
     int nargs = -1, tmp=0;
     double eps_abs, eps_rel, a_y, a_dydt;
     PyGSL_odeiv_step *step=NULL;
     PyGSL_odeiv_control *a_con=NULL;

     gsl_odeiv_control *(*evaluator_5)(double , double , double , double ) = NULL;
     gsl_odeiv_control *(*evaluator_3)(double , double ) = NULL;

     FUNC_MESS_BEGIN();
     /* The arguments depend on the type of control */
     if(type == (void *) gsl_odeiv_control_standard_new){
	  /* step, eps_abs, eps_rel, a_y, a_dydt */
	  nargs = 5;
     }else if(type == (void *) gsl_odeiv_control_y_new || 
	      type == (void *) gsl_odeiv_control_yp_new){
	  nargs = 3;
     }else{
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, 
			      __LINE__ - 2);
	  gsl_error("Unknown control type", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail;
     }
     assert(nargs > -1);


     switch(nargs){
     case 5:
	  tmp == PyArg_ParseTuple(args, "O!dddd:odeiv_control.__init__", 
				  &PyGSL_odeiv_step_pytype, &step, &eps_abs, &eps_rel, &a_y, &a_dydt);
	  break;
     case 3:
	  tmp == PyArg_ParseTuple(args, "O!dd:odeiv_control.__init__", 
				  &PyGSL_odeiv_step_pytype, &step, &eps_abs, &eps_rel);
	  break;
     default:
	  fprintf(stderr, "nargs = %d\n", nargs);
	  gsl_error("Unknown number of arguments", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail; break;
     }
     
     if(!step){
	  PyErr_SetString(PyExc_TypeError, "The first argument must be a step object!");
	  goto fail;
     }


     if(tmp){	  
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, 
			      __LINE__ - 2);
	  return NULL;
     }

     a_con =  PyObject_NEW(PyGSL_odeiv_control, &PyGSL_odeiv_control_pytype);
     if (NULL == a_con){
	  PyErr_NoMemory();
	  goto fail;
     }
     a_con->control=NULL;
     switch(nargs){
     case 5:
	  evaluator_5 = type;
	  a_con->control = evaluator_5(eps_abs, eps_rel, a_y, a_dydt);
	  break;
     case 3:
	  evaluator_3 = type;
	  a_con->control = evaluator_3(eps_abs, eps_rel);
	  break;
     default:
	  goto fail;
     }
     if (NULL == a_con->control){
	  PyErr_NoMemory();
	  goto fail;
     }
     assert(step);
     a_con->step =  step;
     Py_INCREF(step);
     FUNC_MESS_END();
     return (PyObject *) a_con;

 fail:
     FUNC_MESS("FAIL");
     Py_XDECREF(a_con);
     return NULL;
     
}

#define ADD_ODECONTROL(name)                                                  \
static PyObject *                                                             \
PyGSL_odeiv_control_init_ ## name (PyObject * self, PyObject * args)          \
{                                                                             \
     return PyGSL_odeiv_control_init(self, args, (void *) gsl_odeiv_control_ ## name);    \
}   
ADD_ODECONTROL(standard_new)
ADD_ODECONTROL(y_new)
ADD_ODECONTROL(yp_new)

static PyObject *
PyGSL_odeiv_evolve_init(PyObject *self, PyObject *args)
{
     PyGSL_odeiv_step *step = NULL;
     PyGSL_odeiv_control *control = NULL;
     PyGSL_odeiv_evolve *a_ev = NULL;


     /* step, control */
     FUNC_MESS_BEGIN();
     if(0== PyArg_ParseTuple(args, "O!O!:odeiv_evolve.__init__", 
			     &PyGSL_odeiv_step_pytype, &step,
			     &PyGSL_odeiv_control_pytype, &control)){
	  return NULL;
     }

     if(!step){
	  PyErr_SetString(PyExc_TypeError, "The first argument must be a step object!");
	  goto fail;
     }

     if(!control){
	  PyErr_SetString(PyExc_TypeError, "The second argument must be a control object!");
	  goto fail;
     }

     a_ev =  (PyGSL_odeiv_evolve *) PyObject_NEW(PyGSL_odeiv_evolve, &PyGSL_odeiv_evolve_pytype);
     if(NULL == a_ev){
	  PyErr_NoMemory();
	  return NULL;
     }
     


     a_ev->step = step;
     a_ev->control = control;

     a_ev->evolve = gsl_odeiv_evolve_alloc(step->system.dimension);
     if(NULL == a_ev){
	  PyErr_NoMemory();
	  goto fail;
     }
     Py_INCREF(step);
     Py_INCREF(control);
     FUNC_MESS_END();
     return (PyObject *) a_ev;
 fail:
     FUNC_MESS("FAIL");
     Py_DECREF(a_ev);
     return NULL;
}

static PyMethodDef PyGSL_odeiv_module_functions[] = {
     {"step_rk2",    PyGSL_odeiv_step_init_rk2,    METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk4",    PyGSL_odeiv_step_init_rk4,    METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rkf45",  PyGSL_odeiv_step_init_rkf45,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rkck",   PyGSL_odeiv_step_init_rkck,   METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk8pd",  PyGSL_odeiv_step_init_rk8pd,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk2imp", PyGSL_odeiv_step_init_rk2imp, METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_rk4imp", PyGSL_odeiv_step_init_rk4imp, METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_bsimp",  PyGSL_odeiv_step_init_bsimp,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_gear1",  PyGSL_odeiv_step_init_gear1,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"step_gear2",  PyGSL_odeiv_step_init_gear2,  METH_VARARGS|METH_KEYWORDS, NULL},
     {"control_standard_new", PyGSL_odeiv_control_init_standard_new, METH_VARARGS, NULL},
     {"control_y_new",        PyGSL_odeiv_control_init_y_new,        METH_VARARGS, NULL},
     {"control_yp_new",       PyGSL_odeiv_control_init_yp_new,       METH_VARARGS, NULL},
     {"evolve", PyGSL_odeiv_evolve_init, METH_VARARGS, NULL},
     {NULL, NULL, 0}        /* Sentinel */
};

void 
initodeiv(void)
{
     PyObject *m=NULL, *item=NULL, *dict=NULL;

     FUNC_MESS_BEGIN();
     fprintf(stderr, "Compiled at %s %s\n", __DATE__, __TIME__);
     m = Py_InitModule("odeiv", PyGSL_odeiv_module_functions);
     assert(m);
     module = m;
     import_array();
     init_pygsl();


     PyGSL_odeiv_step_pytype.ob_type = &PyType_Type;
     PyGSL_odeiv_control_pytype.ob_type = &PyType_Type;
     PyGSL_odeiv_evolve_pytype.ob_type = &PyType_Type;

     dict = PyModule_GetDict(m);
     /* create_odeiv_step_types(dict); */
     if(!dict)
	  goto fail;
     
     if (!(item = PyString_FromString(odeiv_module_doc))){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not generate module doc string!");
	  goto fail;
     }
     if (PyDict_SetItemString(dict, "__doc__", item) != 0){
	  PyErr_SetString(PyExc_ImportError, 
			  "I could not init doc string!");
	  goto fail;
     }
     
     FUNC_MESS_END();
     return;
 fail:
     FUNC_MESS("Fail");
     fprintf(stderr, "Import of module odeiv failed!\n");
}

