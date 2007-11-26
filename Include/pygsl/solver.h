#ifndef _PYGSL_SOLVER_H_
#define _PYGSL_SOLVER_H_ 1
#include <pygsl/intern.h>
#include <pygsl/block_helpers.h>
/* Not directly needed here, but provides a lot of convienience functions */
#include <pygsl/error_helpers.h>
#include <gsl/gsl_math.h>
#include <setjmp.h>
/*
 * Many functions are "just" accessor methods. These different methods are
 * listed here.
 *
 * Convention: they all end with "m_t" short for method type. This emphasises
 * that this type is pointer to a method.
 */ 
typedef int (*int_m_t)(void *);
typedef size_t (*size_t_m_t)(void *);
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

struct _PyGSLSolverObject;

/*
 * GSL Methods which are implemented as C functions. The specifiy pointer to
 * the solver struct are passed as (void *) pointers.
 */
struct _GSLMethods{
     /* Method to be called to free the GSL solver */
     void_m_t free;
     /*
      * Some solvers provide a restart method. If not available set it to NULL.
      */
     void_m_t restart;
     /* returns a string with the name of the solver */
     name_m_t name;
     /* takes one more step towards the solution */
     int_m_t iterate;
};

struct _SolverStatic{
     struct _GSLMethods cmethods;
     /* How many callbacks will be used? */
     int n_cbs;
     /* Additional methods not provided by the basis solver. */
     PyMethodDef *pymethods;
     /* Describes the type of the solver. e. g. F-Minimizer */
     const char * type_name;
};

struct pygsl_array_cache{
     double * data;
     PyArrayObject * ref;
};
#define PyGSL_SOLVER_NCBS_MAX 4
#define PyGSL_SOLVER_PB_ND_MAX 2
#define PyGSL_SOLVER_N_ARRAYS 10

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
     struct pygsl_array_cache *cache;
     /*
      * The Python callback methods.
      */
     PyObject* cbs[PyGSL_SOLVER_NCBS_MAX];
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
     int problem_dimensions[PyGSL_SOLVER_PB_ND_MAX];
     /*
      * The methods of the solver.
      */
     const struct _SolverStatic* mstatic;
     /* before one can iterate the solver the method set() must be called!*/
     int set_called;
     /* Used as a flag if the jmp_buf is set */
     int isset; 
};
typedef struct _PyGSLSolverObject PyGSL_solver;


typedef struct{
     const void * type;
     void* alloc;
     const struct _SolverStatic* mstatic;
} solver_alloc_struct;



#ifndef _PyGSL_SOLVER_API_MODULE
#define PyGSL_SOLVER_API_EXTERN extern
#else 
#define PyGSL_SOLVER_API_EXTERN static
#endif 

/*
 *  Initalises a solver
 *
 *  The internal structure is set up and the 
 *  nd: number of dimensions
 *     0 ... zero dimensional e.g. minimize, root
 *     1 ... one  dimensional e.g. multimin
 *     2 ... two  dimensional e.g. multifit_nlin
 *    
 *     3 ... only initalise the structure
 * 
 */
PyGSL_SOLVER_API_EXTERN  PyObject *
PyGSL_solver_dn_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc, int nd);

/*
 * Accessor methods.
 *
 * These methods allow to access parameters of the C structure using the access
 * methods _m_t func
 */
PyGSL_SOLVER_API_EXTERN PyObject* 
PyGSL_solver_ret_double(PyGSL_solver *self, PyObject *args, double_m_t func);

PyGSL_SOLVER_API_EXTERN PyObject* 
PyGSL_solver_ret_int(PyGSL_solver *self, PyObject *args, int_m_t func);

PyGSL_SOLVER_API_EXTERN PyObject* 
PyGSL_solver_ret_size_t(PyGSL_solver *self, PyObject *args, size_t_m_t func);

PyGSL_SOLVER_API_EXTERN PyObject* 
PyGSL_solver_ret_vec(PyGSL_solver *self, PyObject *args,  ret_vec func);

/*
 * evaluates a C function taking an vector and a double as input and returning a status.
 */

#define PyGSL_CALLABLE_CHECK(ob, name) \
(PyCallable_Check(ob) ? GSL_SUCCESS : PyGSL_Callable_Check(ob, name))

PyGSL_SOLVER_API_EXTERN int
PyGSL_Callable_Check(PyObject *f, const char * myname);

PyGSL_SOLVER_API_EXTERN int
PyGSL_function_wrap_On_O(const gsl_vector * x, PyObject *callback,
			 PyObject *arguments, double *result1,
			 gsl_vector *result2, int n, const char * c_func_name);

PyGSL_SOLVER_API_EXTERN int
PyGSL_function_wrap_OnOn_On(const gsl_vector *x, const gsl_vector *v, gsl_vector *hv, PyObject *callback,
			    PyObject *arguments, int n, const char *c_func_name);

PyGSL_SOLVER_API_EXTERN int
PyGSL_function_wrap_Op_On_Opn(const gsl_vector *x, gsl_vector *f1, gsl_matrix *f2, PyObject *callback,
			    PyObject *arguments, int n, int p, const char *c_func_name);

PyGSL_SOLVER_API_EXTERN int
PyGSL_function_wrap_Op_On(const gsl_vector * x, gsl_vector *f, PyObject *callback, 
			  PyObject * arguments, int n, int p, const char *c_func_name);

PyGSL_SOLVER_API_EXTERN int
PyGSL_function_wrap_Op_Opn(const gsl_vector * x, gsl_matrix *f, PyObject *callback,
			   PyObject *arguments, int n, int p, const char * c_func_name);

/*
 * evaluates a C function taking an vector and a double as input and returning a status.
 */
PyGSL_SOLVER_API_EXTERN PyObject*
PyGSL_solver_vd_i(PyObject * self, PyObject *args, int_f_vd_t func);

PyGSL_SOLVER_API_EXTERN PyObject *
PyGSL_solver_vvdd_i(PyObject * self, PyObject * args, int_f_vvdd_t func);

struct pygsl_solver_n_set{
     int is_fdf;
     void *c_sys;
     set_m_t set;
};

PyGSL_SOLVER_API_EXTERN PyObject *
PyGSL_solver_n_set(PyGSL_solver *self, PyObject *pyargs, PyObject *kw, 
		   const struct pygsl_solver_n_set * info);


/*
 *
 */
PyGSL_SOLVER_API_EXTERN int
PyGSL_solver_func_set(PyGSL_solver *self, PyObject *args, PyObject *f,
		       PyObject *df, PyObject *fdf);

PyGSL_SOLVER_API_EXTERN PyObject* 
PyGSL_solver_set_f(PyGSL_solver *self, PyObject *pyargs, PyObject *kw, 
		   void *fptr, int isfdf); 


#define _GET(name, cast, func) \
PyObject * PyGSL_ ## name(PyGSL_solver *self, PyObject *args) \
{ \
    return PyGSL_solver_ ## func(self, args, (cast) gsl_ ## name); \
} 

#define GETDOUBLE(name) _GET(name, double_m_t, ret_double)
#define GETSIZET(name)  _GET(name, size_t_m_t, ret_size_t)
#define GETINT(name)    _GET(name, int_m_t,    ret_int)
#define GETVEC(name)    _GET(name, ret_vec,    ret_vec)


/*
 * Get or set a double ....
 */
enum PyGSL_GETSET_typemode {
     PyGSL_MODE_DOUBLE = 0,
     PyGSL_MODE_INT,
     PyGSL_MODE_SIZE_T
};

PyGSL_SOLVER_API_EXTERN PyObject *
PyGSL_solver_GetSet(PyObject *self, PyObject *args, void * address, enum PyGSL_GETSET_typemode mode);

#ifndef _PyGSL_SOLVER_API_MODULE

#define PyGSL_function_wrap_Op_On \
(* (int (*)(const gsl_vector *, gsl_vector *, PyObject *, PyObject *, int, int, const char *))\
 PyGSL_API[PyGSL_function_wrap_Op_On_NUM])

#define PyGSL_function_wrap_On_O \
(* (int (*)(const gsl_vector *, PyObject *, PyObject *, double *, gsl_vector *, int, const char *))\
 PyGSL_API[PyGSL_function_wrap_On_O_NUM])

#define PyGSL_function_wrap_OnOn_On \
(* (int (*)(const gsl_vector *, const gsl_vector *, gsl_vector *, PyObject *,  PyObject *,int, const char *))\
 PyGSL_API[PyGSL_function_wrap_OnOn_On_NUM])

#define PyGSL_function_wrap_Op_On_Opn \
(* (int (*)(const gsl_vector *, gsl_vector *, gsl_matrix *, PyObject *, PyObject *, int, int, const char *))\
 PyGSL_API[PyGSL_function_wrap_Op_On_Opn_NUM])

#define PyGSL_function_wrap_Op_Opn \
(* (int (*)(const gsl_vector *, gsl_matrix *, PyObject *, PyObject *, int, int, const char *))\
 PyGSL_API[PyGSL_function_wrap_Op_Opn_NUM])


#define PyGSL_solver_ret_int \
(*(PyObject *  (*) (PyGSL_solver *, PyObject *, int_m_t func))    PyGSL_API[PyGSL_solver_ret_int_NUM])

#define PyGSL_solver_ret_double \
(*(PyObject *  (*) (PyGSL_solver *, PyObject *, double_m_t func)) PyGSL_API[PyGSL_solver_ret_double_NUM])

#define PyGSL_solver_ret_size_t \
(*(PyObject *  (*) (PyGSL_solver *, PyObject *, size_t_m_t func)) PyGSL_API[PyGSL_solver_ret_size_t_NUM])

#define PyGSL_solver_ret_vec \
(*(PyObject *  (*) (PyGSL_solver *, PyObject *, ret_vec func))    PyGSL_API[PyGSL_solver_ret_vec_NUM])    

#define  PyGSL_solver_dn_init \
(*(PyObject * (*)(PyObject *, PyObject *, const solver_alloc_struct *, int))PyGSL_API[PyGSL_solver_dn_init_NUM])  

#define PyGSL_Callable_Check \
(*(int (*)(PyObject *, const char *)) PyGSL_API[PyGSL_Callable_Check_NUM])

#define PyGSL_solver_vd_i \
(*(PyObject * (*) (PyObject *, PyObject *, int_f_vd_t)) PyGSL_API[PyGSL_solver_vd_i_NUM])

#define PyGSL_solver_vvdd_i \
(*(PyObject * (*) (PyObject *, PyObject *, int_f_vvdd_t)) PyGSL_API[PyGSL_solver_vvdd_i_NUM])

#define PyGSL_solver_func_set \
(*(int (*)(PyGSL_solver *, PyObject *, PyObject *, PyObject *, PyObject *)) PyGSL_API[PyGSL_solver_func_set_NUM])

#define PyGSL_solver_n_set \
(*(PyObject * (*)(PyGSL_solver *, PyObject *, PyObject *,  const struct pygsl_solver_n_set *)) PyGSL_API[PyGSL_solver_n_set_NUM])

#define PyGSL_solver_set_f \
(* (PyObject * (*)(PyGSL_solver *, PyObject *, PyObject *, void *, int )) PyGSL_API[PyGSL_solver_set_f_NUM])

#define PyGSL_solver_GetSet \
(* (PyObject * (*) (PyObject *, PyObject *, void *, enum PyGSL_GETSET_typemode mode)) PyGSL_API[PyGSL_solver_getset_NUM])

#define PyGSL_solver_check(ob) (((ob)->ob_type) == (PyGSL_API[PyGSL_solver_type_NUM]))

#define import_pygsl_solver() \
{ \
   init_pygsl(); \
   if (PyImport_ImportModule("pygsl.testing.solver") != NULL) { \
          ;\
   } else { \
        fprintf(stderr, "failed to import pygsl solver!!\n"); \
   } \
}

#else  /* _PyGSL_API_MODULE */
#define PyGSL_solver_check(ob) ((ob)->ob_type == &PyGSL_solver_pytype)
#endif /* _PyGSL_API_MODULE */


#endif /* _PYGSL_SOLVER_H_ */
