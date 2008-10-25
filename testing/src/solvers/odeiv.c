#include <pygsl/solver.h>
#include <pygsl/utils.h>
#include <gsl/gsl_odeiv.h>

static const char odeiv_step_type_name   [] = "Odeiv-Step";
static const char odeiv_control_type_name[] = "Odeiv-Control";
static const char odeiv_evolve_type_name [] = "Odeiv-Evolve";

const char  * filename = __FILE__;
PyObject *module = NULL;

struct _mycontrol{
     gsl_odeiv_control *control;
     gsl_odeiv_step    *step;
     PyGSL_solver      *step_ob;
};
typedef struct _mycontrol mycontrol;

struct _myevolve{
     gsl_odeiv_evolve  *evolve;
     gsl_odeiv_control *control;
     gsl_odeiv_step    *step;
     PyGSL_solver      *control_ob;
     PyGSL_solver      *step_ob;
};
typedef struct _myevolve myevolve;

void
_mycontrol_free(mycontrol *c)
{
     FUNC_MESS_BEGIN();     
     gsl_odeiv_control_free(c->control);
     if(c->step_ob){
	  DEBUG_MESS(3, "Decreasing step @ %p refcont %d", c->step_ob,
		     c->step_ob->ob_refcnt);
	  Py_DECREF(c->step_ob);
     }else{
	  DEBUG_MESS(3, "Freeing GSL Step @ %p", c->step);
	  gsl_odeiv_step_free(c->step);
     }     
     memset(c, 0, sizeof(mycontrol));
     free(c);
     c = NULL;
     FUNC_MESS_END();
}

void
_myevolve_free(myevolve *c)
{
     FUNC_MESS_BEGIN();
     gsl_odeiv_evolve_free(c->evolve);
     if(c->control_ob){
	  DEBUG_MESS(3, "Decreasing control @ %p refcont %d", c->control_ob,
		     c->control_ob->ob_refcnt);
	  Py_DECREF(c->control_ob);
     }else{
	  DEBUG_MESS(3, "Freeing GSL Control @ %p", c->control);
	  gsl_odeiv_control_free(c->control);
     }
     if(c->step_ob){
	  DEBUG_MESS(3, "Decreasing step @ %p refcont %d", c->step_ob,
		     c->step_ob->ob_refcnt);
	  Py_DECREF(c->step_ob);
     }else{
	  DEBUG_MESS(3, "Freeing GSL Step @ %p", c->step);
	  gsl_odeiv_step_free(c->step);
     }
     memset(c, 0, sizeof(myevolve));
     free(c);
     c = NULL;
     FUNC_MESS_END();
}

const char *
PyGSL_mycontrol_getname(void *v)
{
     mycontrol *c = (mycontrol *) v;
     return gsl_odeiv_control_name(c->control);
}




#define _PyGSL_ODEIV_GENERIC_CHECK(ob, type_desc) \
  ((PyGSL_solver_check((ob))) && (((PyGSL_solver *)ob)->mstatic->type_name == (type_desc)))

#define PyGSL_ODEIV_STEP_Check(ob)    _PyGSL_ODEIV_GENERIC_CHECK((ob), odeiv_step_type_name)
#define PyGSL_ODEIV_CONTROL_Check(ob) _PyGSL_ODEIV_GENERIC_CHECK((ob), odeiv_control_type_name)
#define PyGSL_ODEIV_EVOLVE_Check(ob)  _PyGSL_ODEIV_GENERIC_CHECK((ob), odeiv_evolve_type_name)


static const char *this_file = __FILE__;
static char odeiv_step_init_err_msg[] = "odeiv_step.__init__";
static char odeiv_step_apply_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_step_order_doc[] =  "XXX Documentation missing\n"; 
       
static char odeiv_control_hadjust_doc[] =  "XXX Documentation missing\n"; 
static char odeiv_evolve_apply_doc[] =  "XXX Documentation missing\n"; 


static char  PyGSL_odeiv_step_doc[] = "XXX Documentation missing\n"; 
static char  PyGSL_odeiv_control_doc[] = "XXX Documentation missing\n";
static char  PyGSL_odeiv_evolve_doc[] = "XXX Documentation missing\n"; 
       

/*---------------------------------------------------------------------------
  Wrapper functions to push call the approbriate Python Objects
  ---------------------------------------------------------------------------*/
static int 
PyGSL_odeiv_func(double t, const double y[], double f[], void *params)
{
    int dimension, flag = GSL_FAILURE;

    PyObject *arglist = NULL, *result = NULL;
    PyArrayObject *yo = NULL;
    PyGSL_solver * step;
    gsl_vector_view yv, fv;
    PyGSL_error_info  info;

    FUNC_MESS_BEGIN();

    step = (PyGSL_solver *) params;
    if(!PyGSL_ODEIV_STEP_Check(step)){
	  PyGSL_add_traceback(module, this_file, __FUNCTION__, 
			      __LINE__ - 2);
	  pygsl_error("Param not a step type!", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail;
    }
    dimension =  step->problem_dimensions[0];


    /* Do I need to copy the array ??? */
    yv = gsl_vector_view_array((double *) y, dimension);
    yo = PyGSL_copy_gslvector_to_pyarray(&yv.vector);
    if (yo == NULL) goto fail;

    FUNC_MESS("\t\tBuild args");
    arglist = Py_BuildValue("(dOO)", t, yo, step->args);
    FUNC_MESS("\t\tEnd Build args");

    info.callback = step->cbs[0];
    info.message  = "odeiv_func";
    result  = PyEval_CallObject(step->cbs[0], arglist);


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
    assert(flag != GSL_SUCCESS);
    FUNC_MESS("    IN Fail END");
    if(step->isset)
	 longjmp(step->buffer, flag);
    return flag;
}

static int 
PyGSL_odeiv_jac(double t, const double y[], double *dfdy, double dfdt[], 
		void *params)
{
    int dimension, flag = GSL_FAILURE;
    PyGSL_solver *step;
    PyGSL_error_info  info;
    
    PyObject *arglist = NULL, *result = NULL, *tmp=NULL;
    PyArrayObject *yo = NULL;

    gsl_vector_view yv, dfdtv;
    gsl_matrix_view dfdyv;


    FUNC_MESS_BEGIN();
    
    step = (PyGSL_solver *) params;
    if(!PyGSL_ODEIV_STEP_Check(step)){
	  PyGSL_add_traceback(module, this_file, __FUNCTION__, 
			      __LINE__ - 2);
	  pygsl_error("Param not a step type!", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail;
    }
    dimension = step->problem_dimensions[0];



    yv = gsl_vector_view_array((double *) y, dimension);
    yo = PyGSL_copy_gslvector_to_pyarray(&yv.vector);
    if (yo == NULL) goto fail;


    arglist = Py_BuildValue("(dOO)", t, yo, step->args);


    result  = PyEval_CallObject(step->cbs[1], arglist);

    info.callback = step->cbs[1];
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
PyGSL_odeiv_step_apply(PyGSL_solver *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *y0_o = NULL, *dydt_in_o = NULL;
    PyArrayObject *volatile y0 = NULL, * volatile yerr = NULL, 
	 *volatile dydt_in = NULL, *volatile dydt_out = NULL,
	 *volatile yout = NULL;

    double t=0, h=0, *volatile dydt_in_d;
    int  r, flag;
    PyGSL_array_index_t dimension;

    FUNC_MESS_BEGIN();
    assert(PyGSL_ODEIV_STEP_Check(self));
    if(! PyArg_ParseTuple(args, "ddOOO", &t, &h, &y0_o,  &dydt_in_o)){
      return NULL;
    }


    dimension = self->problem_dimensions[0];
    y0 = PyGSL_vector_check(y0_o, dimension, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
    if(y0 == NULL) goto fail;


    if (Py_None == dydt_in_o){
	 dydt_in_d = NULL;
    }else{
	 dydt_in = PyGSL_vector_check(dydt_in_o, dimension, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
	 if(dydt_in == NULL) goto fail;
	 dydt_in_d = (double *) dydt_in->data;
    }


    dydt_out =  PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
    if (dydt_out == NULL) goto fail;

    yerr = PyGSL_New_Array(1, &dimension, PyArray_DOUBLE);
    if(yerr == NULL) goto fail;


    yout = (PyArrayObject *) PyGSL_Copy_Array(y0);
    if(yout == NULL) goto fail;


    self->isset = 0;
    if((flag=setjmp(self->buffer)) == 0){
	  FUNC_MESS("\t\t Setting Jmp Buffer");
	  self->isset = 1;
    } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  self->isset = 0;
	  goto fail;
    }
    
    r = gsl_odeiv_step_apply(self->solver, t, h, 
			     (double *) yout->data, 
			     (double *) yerr->data, 
			     dydt_in_d, 
			     (double *) dydt_out->data, 
			     ((gsl_odeiv_system *)self->c_sys));
    self->isset = 0;
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
    self->isset = 0;
    Py_XDECREF(y0);
    Py_XDECREF(yout);
    Py_XDECREF(yerr);
    Py_XDECREF(dydt_in);
    Py_XDECREF(dydt_out);
    FUNC_MESS("IN Fail End");   
    return NULL;
}

static PyObject *
PyGSL_odeiv_control_hadjust(PyGSL_solver *self, PyObject *args)
{
  
  PyObject *result = NULL;
  PyObject *y0_o = NULL, *yerr_o = NULL, *dydt_o = NULL;
  PyArrayObject *y0 = NULL, *yerr = NULL, *dydt = NULL;
  double h = 0;
  int r = 0;
  mycontrol *c;

  PyGSL_array_index_t dimension = 0;

  FUNC_MESS_BEGIN();
  assert(PyGSL_ODEIV_CONTROL_Check(self));
  if(!PyArg_ParseTuple(args, "OOOd",  &y0_o, &yerr_o, &dydt_o, &h)){
    return NULL;
  }

  dimension = self->problem_dimensions[0];


  y0 = PyGSL_vector_check(y0_o, dimension, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
  if(y0 == NULL)   goto fail;
  yerr = PyGSL_vector_check(yerr_o, dimension, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
  if(yerr == NULL) goto fail;
  dydt = PyGSL_vector_check(dydt_o, dimension, PyGSL_DARRAY_CINPUT(3), NULL, NULL);
  if(dydt == NULL) goto fail;
  
  FUNC_MESS("      Array Pointers End");

  c = (mycontrol *) self->solver;
  r = gsl_odeiv_control_hadjust(c->control, c->step, 
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

static PyObject *
PyGSL_odeiv_evolve_apply(PyGSL_solver *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *y0_o = NULL,  *myargs = NULL;
    PyArrayObject *volatile y0 = NULL, *volatile yout = NULL;
    myevolve *e = NULL;
    
    double t=0, h=0, t1 = 0, flag;

    int dimension = self->problem_dimensions[0], r;

    assert(PyGSL_ODEIV_EVOLVE_Check(self));
    FUNC_MESS_BEGIN();

    if(!PyArg_ParseTuple(args, "dddOO", &t, &t1, &h, &y0_o, &myargs)){
      return NULL;
    }


    DEBUG_MESS(3, "y0_o @ %p", y0_o);
    
    y0 = PyGSL_vector_check(y0_o, dimension, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
    if(y0 == NULL) goto fail;


    yout = (PyArrayObject *)  PyGSL_Copy_Array(y0);
    if(yout == NULL) goto fail;


    e = (myevolve *) self->solver;

    if((flag=setjmp(e->step_ob->buffer)) == 0){
	 e->step_ob->isset = 1;
	  FUNC_MESS("\t\t Setting Jmp Buffer");
     } else {
	  FUNC_MESS("\t\t Returning from Jmp Buffer");
	  e->step_ob->isset = 0;
	  goto fail;
     }
    DEBUG_MESS(3, "evolve @ %p\t control @ %p\t step @ %p", e, e->control, e->step);

    r = gsl_odeiv_evolve_apply(e->evolve, 
			       e->control, 
			       e->step, 
			       e->step_ob->c_sys, &t, t1, &h,
			       (double * )yout->data); 
   e->step_ob->isset = 0;
    if (GSL_SUCCESS != r){
	 goto fail;
    } 


    assert(yout != NULL);


    result = Py_BuildValue("(ddO)", t, h, yout);

    /* Deleting the arrays */    
    Py_DECREF(yout);     yout = NULL;
    Py_DECREF(y0);       y0=NULL;
    FUNC_MESS_END();
    return result;

 fail:
    FUNC_MESS("IN Fail");
    e->step_ob->isset = 0;
    PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__);
    Py_XDECREF(y0);
    Py_XDECREF(yout); 
    FUNC_MESS("IN Fail End");   
    return NULL;
}

GETINT(odeiv_step_order)

static struct PyMethodDef PyGSL_odeiv_step_methods[] = {
     {"apply", (PyCFunction) PyGSL_odeiv_step_apply, METH_VARARGS, odeiv_step_apply_doc},
     {"order", (PyCFunction) PyGSL_odeiv_step_order, METH_VARARGS, odeiv_step_order_doc},
     {NULL, NULL}
};
static struct PyMethodDef PyGSL_odeiv_control_methods[] = {
     {"hadjust", (PyCFunction) PyGSL_odeiv_control_hadjust, METH_VARARGS, odeiv_control_hadjust_doc},
     {NULL, NULL}
};

static struct PyMethodDef PyGSL_odeiv_evolve_methods[] = {
     {"apply", (PyCFunction) PyGSL_odeiv_evolve_apply, METH_VARARGS, odeiv_evolve_apply_doc},
     {NULL, NULL}
};


static const struct _SolverStatic
_StepMethods     = {{(void_m_t) gsl_odeiv_step_free,   
		   (void_m_t) gsl_odeiv_step_reset,
		   (name_m_t) gsl_odeiv_step_name,   
		   (int_m_t) NULL},
		    3, PyGSL_odeiv_step_methods, odeiv_step_type_name},
_ControlMethods  = {{(void_m_t) _mycontrol_free,   
		      (void_m_t) NULL,
		      (name_m_t) PyGSL_mycontrol_getname,
		      (int_m_t) NULL},
		    3, PyGSL_odeiv_control_methods, odeiv_control_type_name},
_EvolveMethods   = {{(void_m_t) _myevolve_free,   
		     (void_m_t) gsl_odeiv_evolve_reset,
		     (name_m_t) NULL,   
		     (int_m_t) NULL,},
		    3, PyGSL_odeiv_evolve_methods, odeiv_evolve_type_name};


static PyObject *
PyGSL_odeiv_step_init(PyObject *self, PyObject *args, PyObject *kwdict, const gsl_odeiv_step_type * odeiv_type)
{
     
     PyObject *func=NULL, *jac=NULL, *o_params=NULL;
     PyGSL_solver *solver = NULL;

     static char * kwlist[] = {"dimension", "func", "jac", "args", NULL}; 
     int dim, has_jacobian = 0;
     gsl_odeiv_system * c_sys;
     
     solver_alloc_struct s = {odeiv_type, (void_an_t) gsl_odeiv_step_alloc,
			      &_StepMethods};


     FUNC_MESS_BEGIN();

     assert(args);
     if (0 == PyArg_ParseTupleAndKeywords(args, kwdict, "iOOO:odeiv_step.__init__", kwlist, 
					  &dim, &func, &jac, &o_params)){
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 2);
	  return NULL;
     }     
     if (dim <= 0){	  
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	  pygsl_error("The dimension of the problem must be at least 1", 
		    this_file, __LINE__ -2, GSL_EDOM);
	  return NULL;
     }
     if(!PyCallable_Check(func)){
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	  pygsl_error("The function object is not callable!", 
		    this_file, __LINE__ -2, GSL_EBADFUNC);
	  goto fail;	  
     }

     if(jac == Py_None){
	  if(odeiv_type == gsl_odeiv_step_bsimp){
	       PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	       pygsl_error("The bsimp method needs a jacobian! You supplied None.", 
			 this_file, __LINE__ -2, GSL_EBADFUNC);
	       goto fail;
	  }
     }else{
	  if(!PyCallable_Check(jac)){
	       PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, __LINE__ - 1);
	       pygsl_error("The jacobian object must be None or callable!", 
			 this_file, __LINE__ -2, GSL_EBADFUNC);
	       goto fail;
	  }
	  has_jacobian = 1;

     }

     solver = (PyGSL_solver *) PyGSL_solver_dn_init(self, args, &s, 3);

     if(solver == NULL){
	  goto fail;
     }
     DEBUG_MESS(3, "solver @ %p", solver);

     solver->solver =  gsl_odeiv_step_alloc(odeiv_type, dim);     
     if(solver->solver == NULL){
	  goto fail;
     }
     DEBUG_MESS(3, "step @ %p", solver->solver);
     c_sys = (gsl_odeiv_system *)calloc(1, sizeof(gsl_odeiv_system));
     if(c_sys == NULL){
	  PyErr_NoMemory();
	  goto fail;
     }

     /* Need for cleanup in fail : */
     solver->c_sys = c_sys;     
     DEBUG_MESS(3, "c_sys @ %p", solver->c_sys);
     solver->problem_dimensions[0] = dim;
     if(has_jacobian){
	  c_sys->jacobian = PyGSL_odeiv_jac;
	  if(!PyCallable_Check(jac))
	       goto fail;
	  solver->cbs[1] = jac;
     }else{
	  c_sys->jacobian = NULL;
	  solver->cbs[1] = NULL;
     }
     c_sys->function = PyGSL_odeiv_func;
     if(!PyCallable_Check(func))
	       goto fail;

     solver->cbs[0] = func;
     c_sys->params = (void *) solver;
     DEBUG_MESS(3, "params @ %p", c_sys->params);
     Py_INCREF(solver->cbs[0]);
     Py_XINCREF(solver->cbs[1]);
     Py_XINCREF(solver->args);
	  
     solver->args  = o_params;
     Py_INCREF(solver->args);

     FUNC_MESS_END();
     return (PyObject *) solver;

 fail:
     FUNC_MESS("FAIL");
     Py_XDECREF(solver);
     return NULL;
}
#define ADD_ODESTEPPER(mytype)                                                   \
static PyObject *                                                                \
PyGSL_odeiv_step_init_ ## mytype (PyObject * self, PyObject * args, PyObject *kwdic)   \
{                                                                                \
     return PyGSL_odeiv_step_init(self, args, kwdic, gsl_odeiv_step_ ## mytype); \
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
     PyGSL_solver *step=NULL, *solver=NULL;
     mycontrol * c;

     gsl_odeiv_control *(*evaluator_5)(double , double , double , double ) = NULL;
     gsl_odeiv_control *(*evaluator_3)(double , double ) = NULL;

     solver_alloc_struct s = {type, (void_an_t) gsl_odeiv_control_alloc,
			      &_ControlMethods};

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
	  pygsl_error("Unknown control type", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail;
     }
     assert(nargs > -1);


     switch(nargs){
     case 5:
	  tmp == PyArg_ParseTuple(args, "Odddd:odeiv_control.__init__", 
				   &step, &eps_abs, &eps_rel, &a_y, &a_dydt);
	  break;
     case 3:
	  tmp == PyArg_ParseTuple(args, "Odd:odeiv_control.__init__", 
				  &step, &eps_abs, &eps_rel);
	  break;
     default:
	  fprintf(stderr, "nargs = %d\n", nargs);
	  pygsl_error("Unknown number of arguments", 
		    this_file, __LINE__ -2, GSL_EFAULT);
	  goto fail; break;
     }
     if(!PyGSL_ODEIV_STEP_Check(step)){
	  int flag;
	  flag = PyGSL_solver_check(step);
	  DEBUG_MESS(3, "is solver?  %d, %p %p ", flag,  PyGSL_API[PyGSL_solver_type_NUM], step->ob_type);
	  if(flag){
	       DEBUG_MESS(3, "solver = %s, %p !=  %p", step->mstatic->type_name, step->mstatic->type_name, 
			  odeiv_step_type_name);
	       pygsl_error("First argument must be a step solver!", __FILE__, __LINE__, GSL_EINVAL);
	  }     
	  goto fail;
     }
	  
     
     if(tmp){	  
	  PyGSL_add_traceback(module, this_file, odeiv_step_init_err_msg, 
			      __LINE__ - 2);
	  return NULL;
     }


     solver =  (PyGSL_solver *) PyGSL_solver_dn_init(self, args, &s, 3);
     if (NULL == solver){
	  PyErr_NoMemory();
	  goto fail;
     }
     c = calloc(1, sizeof(mycontrol));
     if(c == NULL){
	  PyErr_NoMemory();
	  goto fail;
     }
     solver->solver = c;
     switch(nargs){
     case 5:
	  evaluator_5 = type;
	  c->control = evaluator_5(eps_abs, eps_rel, a_y, a_dydt);
	  break;
     case 3:
	  evaluator_3 = type;
	  c->control = evaluator_3(eps_abs, eps_rel);
	  break;
     default:
	  goto fail;
     }
     if (NULL == c->control){
	  PyErr_NoMemory();
	  goto fail;
     }
     DEBUG_MESS(3, "c->control @ %p", c->control);
     c->step =  step->solver;
     c->step_ob = step;
     Py_INCREF(step);
     FUNC_MESS_END();
     return (PyObject *) solver;

 fail:
     FUNC_MESS("FAIL");
     Py_XDECREF(solver);
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
     PyGSL_solver *step, *control, *a_ev = NULL;
     myevolve *e;
     solver_alloc_struct s = {NULL, (void_an_t) gsl_odeiv_evolve_alloc,
			      &_EvolveMethods};

     /* step, control */
     FUNC_MESS_BEGIN();
     if(0== PyArg_ParseTuple(args, "OO:odeiv_evolve.__init__", 
			     &step, &control)){
	  return NULL;
     }
     if(!PyGSL_ODEIV_STEP_Check(step)){
	  pygsl_error("First argument must be a step solver!", __FILE__, __LINE__, GSL_EINVAL);
	  goto fail;
     }

     if(!PyGSL_ODEIV_CONTROL_Check(control)){
	  pygsl_error("Second argument must be a control solver!", __FILE__, __LINE__, GSL_EINVAL);
	  goto fail;
     }

     a_ev =  (PyGSL_solver *) PyGSL_solver_dn_init(self, args, &s, 3);
     if(NULL == a_ev){
	  PyErr_NoMemory();
	  return NULL;
     }
     a_ev->problem_dimensions[0] = step->problem_dimensions[0];

     e = (myevolve *) calloc(1, sizeof(myevolve));
     if(e == NULL){
	  PyErr_NoMemory();
	  goto fail;
     }
     a_ev->solver = e;
     e->step_ob =  step;
     e->control_ob = control;
     Py_INCREF(step);
     Py_INCREF(control);
     e->step = step->solver;
     e->control = ((mycontrol *)control->solver)->control;
     e->evolve = gsl_odeiv_evolve_alloc(step->problem_dimensions[0]);
     if(NULL == e->evolve){
	  PyErr_NoMemory();
	  goto fail;
     }
     FUNC_MESS_END();
     return (PyObject *) a_ev;
 fail:
     FUNC_MESS("FAIL");
     Py_XDECREF(a_ev);
     return NULL;
}

static const char PyGSL_odeiv_module_doc [] = "XXX Missing ";
static PyMethodDef mMethods[] = {
     {"step_rk2",    (PyCFunction)PyGSL_odeiv_step_init_rk2,    METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_rk4",    (PyCFunction)PyGSL_odeiv_step_init_rk4,    METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_rkf45",  (PyCFunction)PyGSL_odeiv_step_init_rkf45,  METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_rkck",   (PyCFunction)PyGSL_odeiv_step_init_rkck,   METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_rk8pd",  (PyCFunction)PyGSL_odeiv_step_init_rk8pd,  METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_rk2imp", (PyCFunction)PyGSL_odeiv_step_init_rk2imp, METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_rk4imp", (PyCFunction)PyGSL_odeiv_step_init_rk4imp, METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_bsimp",  (PyCFunction)PyGSL_odeiv_step_init_bsimp,  METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_gear1",  (PyCFunction)PyGSL_odeiv_step_init_gear1,  METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"step_gear2",  (PyCFunction)PyGSL_odeiv_step_init_gear2,  METH_VARARGS|METH_KEYWORDS, PyGSL_odeiv_step_doc},
     {"control_standard_new", PyGSL_odeiv_control_init_standard_new, METH_VARARGS, PyGSL_odeiv_control_doc},
     {"control_y_new",        PyGSL_odeiv_control_init_y_new,        METH_VARARGS, PyGSL_odeiv_control_doc},
     {"control_yp_new",       PyGSL_odeiv_control_init_yp_new,       METH_VARARGS, PyGSL_odeiv_control_doc},
     {"evolve", PyGSL_odeiv_evolve_init, METH_VARARGS, PyGSL_odeiv_evolve_doc},
     {NULL, NULL, 0, NULL}
};

void
initodeiv(void)
{
     PyObject* m, *dict, *item;
     FUNC_MESS_BEGIN();

     m=Py_InitModule("odeiv", mMethods);
     module = m;
     assert(m);
     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     init_pygsl()
     import_pygsl_solver();
     assert(PyGSL_API);


     if (!(item = PyString_FromString((char*)PyGSL_odeiv_module_doc))){
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

 fail:
     FUNC_MESS("FAIL");
     return;
}
