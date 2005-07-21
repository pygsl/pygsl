#ifndef _PYGSL_SOLVER_H_
#define _PYGSL_SOLVER_H_ 1
#include <pygsl/general_helpers.h>
#include <pygsl/block_helpers.h>
#include <pygsl/function_helpers.h>
#include <setjmp.h>
#include <gsl/gsl_math.h>
#ifdef ONEFILE
#define PyGSL_SOLVER_STATIC static
#else /* ONEFILE */
#define PyGSL_SOLVER_STATIC
#endif /* ONEFILE */
/*
 * Many functions are "just" accessor methods. These are named with this 
 * struct.
 */ 
typedef int (*int_m_t)(void *);
typedef void (*void_m_t)(void *);
typedef void *(*void_a_t)(const void *);
typedef void *(*void_an_t)(const void *, size_t n);
typedef void *(*void_anp_t)(const void *, size_t n, size_t p);
typedef const char * (*name_m_t)(void *);
typedef double  (*double_m_t)(void *);
typedef gsl_vector *(*ret_vec)(void *);
typedef int (*set_m_t)(void *, void *, const gsl_vector *);
typedef int (*set_m_d_t) (void *, gsl_function *, double);
typedef int (*set_m_ddd_t) (void *, gsl_function *, double, double, double);
typedef int (*int_f_vd_t)(const gsl_vector *, double);
typedef int (*int_f_vvdd_t)(const gsl_vector *, const gsl_vector *, double, double);

/*
 * Collect all element accessor methods which just need a pointer to the struct
 * and return a value.
 */
struct _ElementAccessor{
     int_m_t method;
     const char * name;
};
struct _PyGSLSolverObject;
/*
 * The gsl implementation for each solver type ....
 */
struct _GSLMethods{
     void_m_t free;
     void_m_t restart;
     name_m_t name;
     int_m_t iterate;
};

/*
 * Methods which can be overwritten by "derived classes."
 */
struct _SolverMethods{
     int n_cbs;
     PyMethodDef *pymethods;
};

static PyTypeObject PyGSL_solver_pytype;
#define PyGSL_solver_check(ob) ((ob)->ob_type == &PyGSL_solver_pytype)

struct _PyGSLSolverObject{
     PyObject_HEAD
     /* 
      *	Some solvers do not propagate errors. Here I use longjmp if an error 
      * is raised by the evaluator.
      */
     jmp_buf buffer;
     /*
      * Array generation is a vital part of the callback process. To increase
      * the calculation speed, I want to store them here, thus I can reuse them
      * if not stored by the user for later evaluation.
      */
     PyArrayObject *tmparrays;
     /*
      * The Python callback methods.
      */
     PyObject** cbs;
     /*
      * Additional arguments passed to the callbacks
      */
     PyObject* args;
     /*
      * The solver itself.
      */     
     void * solver;
     /*
      * The space needed to store the variables for the C functions ....
      */
     void * c_sys;
     /*
      * The dimensionality of the problem. Typically one or two numbers ...
      */
     int *problem_dimensions;
     const struct _SolverMethods* methods;
     /*
      * Pointer to gsl functions which are actually methods and common to most
      * of the solvers.
      */
     const struct _GSLMethods* raw_methods;
     /*
      * Describes the type of the solver. e. g. F-Minimizer or Fdf-Minimizer
      */
     const char * type_name;
     /* before one can iterate the solver the method set() must be called!*/
     int set_called;
     /* Used as a flag if the jmp_buf is set */
     int isset; 
};
typedef struct _PyGSLSolverObject PyGSL_solver;

PyGSL_SOLVER_STATIC PyGSL_solver* 
_PyGSL_solver_init(const struct _SolverMethods *methods, 
		   const struct _GSLMethods* raw_methods);

typedef struct{
     const void * type;
     void* alloc;
     const char * type_name;
     const struct _SolverMethods* methods;
     const struct _GSLMethods* raw_methods;
} solver_alloc_struct;

struct pygsl_solver_n_set{
     int is_fdf;
     void *c_sys;
     set_m_t set;
};

PyGSL_SOLVER_STATIC  PyObject *
_PyGSL_solver_n_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc);
PyGSL_SOLVER_STATIC  PyObject *
_PyGSL_solver_np_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc);

PyGSL_SOLVER_STATIC int *
PyGSL_solver_set_called(PyGSL_solver *self);

#define PyGSL_SOLVER_SET_CALLED(ob) \
        (((ob)->set_called == 1) ? GSL_SUCCESS: PyGSL_solver_set_called((ob)))

PyGSL_SOLVER_STATIC int
PyGSL_Callable_Check(PyObject *, const char * name);

#define PyGSL_CALLABLE_CHECK(ob, name) \
(PyCallable_Check(ob) ? GSL_SUCCESS : PyGSL_Callable_Check(ob, name))

PyGSL_SOLVER_STATIC int
_PyGSL_solver_func_set(PyGSL_solver *self, PyObject *args, PyObject *f,
		       PyObject *df, PyObject *fdf);



/*
 * evaluates a C function taking an vector and a double as input and returning a status.
 */
PyGSL_SOLVER_STATIC PyObject*
_PyGSL_solver_i_vd(PyObject * self, PyObject *args, int_f_vd_t func);

PyGSL_SOLVER_STATIC PyObject *
_PyGSL_solver_i_vvdd(PyObject * self, PyObject * args, int_f_vvdd_t func);

PyGSL_SOLVER_STATIC PyObject* 
PyGSL_solver_ret_double(PyGSL_solver *self, PyObject *args, double_m_t func);

PyGSL_SOLVER_STATIC PyObject* 
PyGSL_solver_ret_int(PyGSL_solver *self, PyObject *args, int_m_t func);

PyGSL_SOLVER_STATIC PyObject* 
PyGSL_solver_ret_vec(PyGSL_solver *self, PyObject *args,  ret_vec func);

#define _GET(name, cast, func) \
PyObject * PyGSL_ ## name(PyGSL_solver *self, PyObject *args) \
{ \
    return PyGSL_solver_ ## func(self, args, (cast) gsl_ ## name); \
} 

#define GETDOUBLE(name) _GET(name, double_m_t, ret_double)
#define GETINT(name)    _GET(name, int_m_t,    ret_int)

PyObject * module = NULL;
const char *filename = __FILE__;


#endif /* _PYGSL_SOLVER_H_ */
