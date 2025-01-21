/**
 * Original Author:
 * * author: Jochen K"upper
 * * created: April 2002
 *
 * author: Pierre Schnizer
 * created: December 2003
 * file: pygsl/src/simanmodule.c
 * $Id$
 *
 * Jochen K"upper wrote the original version of this module. In December 2003 I
 * rewrote it. Now I only support the variable type as it is more pythonic.
 *
 */

#include <Python.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <gsl/gsl_siman.h>
#include <gsl/gsl_nan.h>
#include <pygsl/error_helpers.h>
#include <pygsl/general_helpers.h>
#include <pygsl/rng.h>
#include <pygsl/rng_helpers.h>

/*
 * Common to all objects of one problem
 * Currently the individual method pointers are not used. Instead the method
 * is resolved every time. Do you know which method is faster? Is it advicable
 * to resolve it once and store it here? Pierre
 */
typedef struct{
	/*
	  PyObject * efunc;
	  PyObject * step;
	  PyObject * metric;
	  PyObject * print;
	*/
	PyObject * rng;
	jmp_buf  buffer;
}pygsl_siman_func_t;

/*
 * The Linked list keeping the reference to the individual objects.
 *
 * Necessary as I have to use longjmp as the current implementation does
 * not allow error propagation yet!
 */
struct _pygsl_siman_t{
	pygsl_siman_func_t *func;
	PyObject * x;
	struct _pygsl_siman_t * prev;
	struct _pygsl_siman_t * next;
};
typedef struct _pygsl_siman_t pygsl_siman_t;



static const char module_doc[] = "C Implementation needed for the siman module.";
static PyObject *module = NULL;
static const char filename[] = __FILE__;

/*
 * Naming of the various methods the object has provide as callbacks.
 */
static const char EFunc_name[]  = "EFunc";
static const char Metric_name[] = "Metric";
static const char Step_name[]   = "Step";
static const char Clone_name[]  = "Clone";
static const char Print_name[]  = "Print";


/*
 * Get a callable method from a object.
 *
 * Basically it is a flat wrapper around PyObject_GetAttrString but
 * checks if the method is callable and adds a Traceback frame
 *
 * Flag usage:
 *           flag == 1 Must exist and must be callable
 *           flag == 2 If it exists it must be callable
 *
 * For the traceback frame all arguments following the module are needed.
 * If you do not know the module, you can pass a NULL pointer.
 */
static PyObject *
PyGSL_get_callable_method(PyObject *o, const char * attr, int flag, PyObject *module,
			  const char * filename, const char * func_name,
			  int lineno)
{
	PyObject * method = NULL;

	FUNC_MESS_BEGIN();
	method = PyObject_GetAttrString(o, (char *) attr);
	if(method == NULL){
		if(flag == 1){
			PyGSL_add_traceback(module, filename, func_name, lineno);
		}else if(flag == 2){
			/* Clear the error otherwise it will show up later on! */
			PyErr_Clear();
		}
		return NULL;
	}
	if(!(PyCallable_Check(method))) {
		/* I must add the method name! I must change it to an more descriptive exception! */
		PyGSL_add_traceback(module, (const char *) filename, func_name, lineno);
		PyErr_SetString(PyExc_TypeError, "Found a attribute which was not callable!"
				"XXX must add the method name!");
		return NULL;
	}
	DEBUG_MESS(2, "Found a method at %p", (void *) method);
	FUNC_MESS_END();
	return method;
}

/* This function type should return the energy of a configuration XP. */
static double
PyGSL_siman_efunc(void *xp)
{


	PyObject *result = NULL, *callback = NULL, *arglist = NULL;
	PyGSL_error_info info;
	pygsl_siman_t *x;
	int flag=GSL_EFAILED;
	double value;
	/* static char *functionname  = __FUNCTION__; */

	FUNC_MESS_BEGIN();

	assert(xp);
	x = (pygsl_siman_t *) xp;

	DEBUG_MESS(2, "Found a pygsl_siman_t at %p and a pygsl_siman_func_t at %p and x at %p",
		   (void *)x, (void *) x->func, (void *) x->x);

	assert(x);
	assert(x->func);

	callback = PyGSL_get_callable_method(x->x, EFunc_name, 1, module, filename, __FUNCTION__, __LINE__);
	if(callback == NULL)
		goto fail;

	info.callback = callback;
	info.message  = __FUNCTION__;
	info.error_description = "and the description ???";
	info.argnum = 1;

	arglist = PyTuple_New(0);
	result = PyObject_CallObject(callback, arglist);
	Py_DECREF(arglist);
	if((flag = PyGSL_CHECK_PYTHON_RETURN(result, 1, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	if((flag = PyGSL_PYFLOAT_TO_DOUBLE(result, &value, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	Py_DECREF(result);
	FUNC_MESS_END();
	return value;

  fail:
	FUNC_MESS("In Fail");
	Py_XDECREF(result);
	longjmp(x->func->buffer, flag);
	return GSL_NAN;
}



/*
 *  This function type should modify the configuration XP using a random step
 *  taken from the generator R, up to a maximum distance of STEP_SIZE.
 */
static void
PyGSL_siman_step(const gsl_rng *r, void *xp, double step_size)
{


	PyObject *result = NULL, *arglist = NULL, *callback = NULL;
	PyGSL_error_info info;
	pygsl_siman_t *x;
	int flag=GSL_EFAILED;

	/* static const char * functionname  = __FUNCTION__; */

	FUNC_MESS_BEGIN();
	x = (pygsl_siman_t *) xp;
	DEBUG_MESS(2, "Found x at %p", xp);

	callback = PyGSL_get_callable_method(x->x, Step_name, 1, module, filename, __FUNCTION__, __LINE__);
	if(callback == NULL)
		goto fail;

	info.callback = callback;
	info.message  = __FUNCTION__;
	info.error_description = "???";
	info.argnum = 1;

	assert(PyGSL_RNG_Check(x->func->rng));
	assert(((PyGSL_rng *) x->func->rng)->rng == r);

	/* create argument list */
	arglist = PyTuple_New(2);
	PyTuple_SET_ITEM(arglist, 0, x->func->rng);
	Py_INCREF(x->func->rng); /* Don't forget tuple is owner! */
	PyTuple_SET_ITEM(arglist, 1, PyFloat_FromDouble(step_size));

	result = PyObject_CallObject(callback, arglist);
	Py_DECREF(arglist);
	if((flag = PyGSL_CHECK_PYTHON_RETURN(result, 0, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	Py_DECREF(result);
	FUNC_MESS_END();
	return;

  fail:
	FUNC_MESS("In Fail");
	Py_XDECREF(result);
	longjmp(x->func->buffer, flag);
	return;
}



/* This function type should return the distance between two configurations XP
   and YP. */
static double
PyGSL_siman_metric(void *xp, void *yp)
{

	PyObject *result = NULL, *arglist = NULL, *callback = NULL;
	PyGSL_error_info info;
	pygsl_siman_t *x, *y;
	int flag=GSL_EFAILED;
	double value;
	/* static const char * functionname = __FUNCTION__; */

	FUNC_MESS_BEGIN();
	x = (pygsl_siman_t *) xp;
	y = (pygsl_siman_t *) yp;

	DEBUG_MESS(2, "Found x at (%p,%p) and y at (%p %p)",
		   (void *) x, (void *)x->x, (void *) y, (void *) y->x);

	assert(x);
	assert(y);
	assert(x->x);
	assert(y->x);

	callback = PyGSL_get_callable_method(x->x, Metric_name, 1, module, filename, __FUNCTION__, __LINE__);
	if(callback == NULL)
		goto fail;

	info.callback = callback;
	info.message  = __FUNCTION__;
	info.error_description = "???";
	info.argnum = 1;

	arglist = PyTuple_New(1);
	PyTuple_SET_ITEM(arglist, 0, y->x);
	Py_INCREF(y->x); /* Tuple is owner! */

	result = PyObject_CallObject(callback, arglist);
	Py_XDECREF(arglist);

	if((flag = PyGSL_CHECK_PYTHON_RETURN(result, 0, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	if((flag = PyGSL_PYFLOAT_TO_DOUBLE(result, &value, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	Py_DECREF(result);
	FUNC_MESS_END();
	return value;

  fail:
	FUNC_MESS("In Fail");
	Py_XDECREF(result);
	longjmp(x->func->buffer, flag);
	return GSL_NAN;
}



/* This function type should print the contents of the configuration XP. */
static void
PyGSL_siman_print(void *xp)
{
	PyObject *result = NULL, *callback=NULL, *arglist=NULL;
	PyGSL_error_info info;
	pygsl_siman_t *x;
	int flag=GSL_EFAILED;
	/* static const char * functionname  = __FUNCTION__; */

	FUNC_MESS_BEGIN();
	x = (pygsl_siman_t *) xp;

	callback = PyGSL_get_callable_method(x->x, Print_name, 1, module, filename, __FUNCTION__, __LINE__);
	if(callback == NULL)
		goto fail;

	info.callback = callback;
	info.message  = __FUNCTION__;
	info.error_description = "what goes here ???";
	info.argnum = 1;

	arglist = PyTuple_New(0);
	result = PyObject_CallObject(callback, arglist);
	Py_DECREF(arglist);

	if((flag = PyGSL_CHECK_PYTHON_RETURN(result, 0, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, (const char*)filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	Py_DECREF(result);
	FUNC_MESS_END();
	return;

  fail:
	FUNC_MESS("In Fail");
	Py_XDECREF(result);
	longjmp(x->func->buffer, flag);
	return;

}

/*
 * As Python is generating the new objects I can not skip the reference
 * counting, but must add a reference for each object in construct and
 * depose it here and in the siman_destroy function.
 *
 * siman_solve will call siman_release_x anyway at the end to clear up
 * all objects. Necessary to non existing error propagation in the siman
 * module.
 */
static void
PyGSL_siman_copy(void *src, void *dst)
{
	PyObject *callback=NULL, *t_new = NULL, *arglist = NULL;
	PyGSL_error_info info;
	pygsl_siman_t *x, *y;
	int flag=GSL_EFAILED;
	/* static const char * functionname = __FUNCTION__; */

	FUNC_MESS_BEGIN();
	x = (pygsl_siman_t *) src;
	y = (pygsl_siman_t *) dst;

	DEBUG_MESS(2, "Got source at %p, Destination at %p", (void *) x, (void *) y);
	assert(x->x);
	callback = PyGSL_get_callable_method(x->x, Clone_name, 1, module, filename, __FUNCTION__, __LINE__);
	if(callback == NULL)
		goto fail;

	arglist = PyTuple_New(0);
	t_new = PyObject_CallObject(callback, arglist);
	Py_DECREF(arglist);

	info.callback = callback;
	info.message  = __FUNCTION__;
	info.error_description = "???";
	info.argnum = 1;

	if((flag = PyGSL_CHECK_PYTHON_RETURN(t_new, 1, &info)) != GSL_SUCCESS){
		PyGSL_add_traceback(module, (const char*)filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	Py_XDECREF(y->x);
	/* Py_INCREF(t_new);  Necessary? I don't think so. */
	y->x = t_new;
	FUNC_MESS_END();
	return;

  fail:
	FUNC_MESS("Fail");
	Py_XDECREF(t_new);
	longjmp(x->func->buffer, flag);

}

static void *
PyGSL_siman_copy_construct(void *t_new)
{
	pygsl_siman_t * ret, * n, *p;
	int flag = GSL_ENOMEM;

	FUNC_MESS_BEGIN();
	n   = (pygsl_siman_t *) t_new;

	/* The pointers next and prev are checked against NULL */
	ret = (pygsl_siman_t *) calloc(1, sizeof(pygsl_siman_t));
	DEBUG_MESS(2, "T_New was %p, Constructed a new object at %p", t_new, (void *) ret);
	if(ret == NULL){
		pygsl_error("Could not allocate the object for the linked list",
			  filename, __LINE__ - 3, GSL_ENOMEM);
		goto fail;
	}
	/* Put the Link to the old object so that I can clone when I need to copy */
	ret->x    = n->x;
	/* Eventually I will dispose the object */
	Py_INCREF(ret->x);
	/* Pointer to the func struct. This information is the same for all objects */
	ret->func = n->func;


	/* Find the first open object in the linked list ... */
	p = n;
	while(p->next != NULL){
		p = p->next;
	}
	DEBUG_MESS(2, "I found a open object at %p", (void *) p);
	/* and connect the links */
	p->next = ret;
	ret->prev = p;

	FUNC_MESS_END();
	return ret;

  fail:
	FUNC_MESS("Fail");
	longjmp(n->func->buffer, flag);
	return NULL;

}

static void
PyGSL_siman_destroy(void * old)
{
	pygsl_siman_t * o;

	FUNC_MESS_BEGIN();
	o = (pygsl_siman_t *) old;
	assert(o);


	/* fprintf(stderr, "Destroying: Previous object = %p, Next Object = %p\n",
	   (void *)o->prev, (void *)o->next); */

	/* Reconnect the linked list */
	if (o->prev && o->next){
		/* Connect the both */
		o->prev->next = o->next;
		o->next->prev = o->prev;
	}
	else if (o->prev && o->next == NULL){
		/* Prev last element. Terminate the list */
		o->prev->next = NULL;
	}
	else if (o->prev == NULL && o->next == NULL){
		/* Last Element, better to leave it */
		DEBUG_MESS(2, "I do not dispose the last element %p!", (void *) o);
		return;
	}

	/* Dispose the object */
	Py_XDECREF(o->x);
	free(o);
	FUNC_MESS_END();
}

/* Clean up of the linked list of objects */
int
PyGSL_siman_release_x(pygsl_siman_t * myargs, pygsl_siman_t * x)
{
	pygsl_siman_t *p=NULL;
	FUNC_MESS_BEGIN();

	p = myargs;
	/* fprintf(stderr, "Releasing list!\n"); */
	while(1){
		/* fprintf(stderr, "Previous object = %p, Next Object = %p\n",
		   (void *)p->prev, (void *)p->next); */
		/* Don't delete the object containing the result! */
		if(p != x){
			/* fprintf(stderr, "Deleting object at %p\n", (void *) p); */
			PyGSL_siman_destroy((void *) p);
		}
		if(p->next == NULL)
			break;
		p = p->next;
	}
	FUNC_MESS_END();
	return GSL_SUCCESS;
}

static const char pygsl_siman_solve_doc[] =
"Simulated annealing driver.\n\
\n\
Usage:\n\
result = solve(r, x0, ...)\n\
\n\
Args:\n\
    r:  a random generator from pygsl.rng\n\
    x0: a configuration. It must be an object providing the following\n\
        methods:\n\
           * EFunc()\n\
           * Metric()\n\
           * Step()\n\
           * Clone()\n\
               If you want to use the print functionality you must provide\n\
               the following method:\n\
           * Print()\n\
\n\
Keyword Args:\n\
    n_tries       = 200: how many points to try for each step\n\
    iters_fixed_T = 10:  how many iterations at each temperature?\n\
    step_size     = 10:  max step size in the random walk\n\
\n\
                      parameters for the Boltzmann distribution\n\
    k             = 1.0:   Boltzmann constant\n\
    t_initial     = 0.002: initial temperature\n\
    mu_t          = 1.005:  damping factor for the temperature\n\
    t_min         = 2.0e-6\n\
\n\
    do_print      = 0:   print the status of the annealing process\n\
                               (== 0: do not print)\n\
                               ( > 0: print)\n\
Returns:\n\
    result: a object of type x0 with the final value.\n\
";


/* wrapper functions */
static PyObject *
PyGSL_siman_solve(PyObject *self, PyObject *args, PyObject *kw)
{
	PyObject *result = NULL;
	PyObject *efunc = NULL, *step = NULL, *metric = NULL, *clone = NULL,
		 *print = NULL, *r_o = NULL, *x_o=NULL;

	gsl_rng *rng = NULL;

	gsl_siman_print_t    a_print= PyGSL_siman_print;
	gsl_siman_params_t   params = {200, 10, 10.0, 1.0, 0.002, 1.005, 2.0e-6};


	pygsl_siman_func_t   myargs_func = {NULL};
	pygsl_siman_t        myargs = {NULL, NULL, NULL, NULL};


	/* static const char  * functionname = __FUNCTION__; */

	int flag=GSL_EFAILED, do_print=0;
	void * x0 = NULL;

	static const char * kwlist[] = {"rng", "x0", "n_tries", "iters_fixed_T", "step_size", "k",
					"t_initial", "mu_t",  "t_min", "do_print", NULL};

	FUNC_MESS_BEGIN();
	/* python arguments are (rng, x0, settings) */
	if(! PyArg_ParseTupleAndKeywords(args, kw, "OO|iidddddi",  (char **) kwlist, &r_o, &x_o,
			      &params.n_tries, &params.iters_fixed_T, &params.step_size,
			      &params.k, &params.t_initial, &params.mu_t, &params.t_min, &do_print))
		return NULL;

	/* The following methods must exist */
	efunc  = PyGSL_get_callable_method(x_o, EFunc_name,  1, module, filename, __FUNCTION__, __LINE__);
	step   = PyGSL_get_callable_method(x_o, Step_name,   1, module, filename, __FUNCTION__, __LINE__);
	metric = PyGSL_get_callable_method(x_o, Metric_name, 1, module, filename, __FUNCTION__, __LINE__);
	clone  = PyGSL_get_callable_method(x_o, Clone_name,  1, module, filename, __FUNCTION__, __LINE__);
	if( efunc == NULL || step == NULL || metric == NULL || clone == NULL){
		return NULL;
	}

	/* optional print */
	if(do_print == 0){
		a_print = NULL;
	} else {
		print  = PyGSL_get_callable_method(x_o, Print_name,  1, module, filename, __FUNCTION__, __LINE__);
		if(print == NULL){
			DEBUG_MESS(2, "Did not get a print method! print = %p", print);
			a_print = NULL;
			return NULL;
		}
	}

	rng = PyGSL_gsl_rng_from_pyobject(r_o);
	if(rng == NULL){
		return NULL;
	}


	/* initialize/assign functions */
	Py_INCREF(x_o);
	/*
	  myargs_func.efunc  = efunc;
	  myargs_func.step   = step;
	  myargs_func.metric = metric;
	  myargs_func.print  = print;
	*/
	myargs_func.rng    = r_o;

	myargs.func = &myargs_func;
	myargs.x   = x_o;
	myargs.prev = NULL;
	myargs.next = NULL;

	x0 = (void *) &myargs;
	DEBUG_MESS(2, "x0 @ %p; myargs at %p; myargs_func at %p", x0, (void *) &myargs, (void *) &myargs_func);
	DEBUG_MESS(2, "Found a pygsl_siman_t at %p and a pygsl_siman_func_t at %p",
		   (void *) x0,
		   (void *) (((pygsl_siman_t *) x0)->func));

	if((flag = setjmp(myargs_func.buffer)) == 0){
		FUNC_MESS("Starting siman");
		gsl_siman_solve(rng, x0, PyGSL_siman_efunc, PyGSL_siman_step,
				PyGSL_siman_metric, a_print, PyGSL_siman_copy,
				PyGSL_siman_copy_construct, PyGSL_siman_destroy,
				0, /* Only variable mode supported by this wrapper. */
				params);
		FUNC_MESS("End siman");
	}else{
		PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__);
		goto fail;
	}
	Py_DECREF(x_o);
	DEBUG_MESS(2, "I found x0 at %p", x0);
	result = ((pygsl_siman_t *) x0)->x;

	PyGSL_siman_release_x(&myargs, (pygsl_siman_t *) x0);
	FUNC_MESS_END();
	return result;

  fail:
	FUNC_MESS("In Fail");
	PyGSL_siman_release_x(&myargs, (pygsl_siman_t *) x0);
	Py_XDECREF(x_o);
	PyGSL_error_flag(flag);
	return NULL;
}


/* module initialization */
static PyMethodDef simanMethods[] = {
	{"solve", (PyCFunction) PyGSL_siman_solve,
	 METH_VARARGS | METH_KEYWORDS, (char *) pygsl_siman_solve_doc},
	{NULL, NULL} /* Sentinel */
};

#ifdef PyGSL_PY3K
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "pygsl.siman",
        NULL,
        -1,
        simanMethods,
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
PyMODINIT_FUNC
PyInit__siman(void)
#define RETVAL m
#else /* PyGSL_PY3K */
DL_EXPORT(void) init_siman(void)
#define RETVAL
#endif /* PyGSL_PY3K */
{
	PyObject *m = NULL;
	FUNC_MESS_BEGIN();

#ifdef PyGSL_PY3K
	m = PyModule_Create(&moduledef);
#else /* PyGSL_PY3K */
	m = Py_InitModule("_siman", simanMethods);
#endif /* PyGSL_PY3K */
	if (m == NULL)
		return RETVAL;
	module = m;

	init_pygsl();
	import_pygsl_rng();
	FUNC_MESS_END();
	return RETVAL;
}



/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
