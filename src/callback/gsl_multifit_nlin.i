/* -*- C -*- */
/**
 * author: Pierre Schnizer
 */
%{
#include <gsl/gsl_multifit_nlin.h>
#include "pygsl_multifit_nlin_config.h"
#include "pygsl_multifit.ic"  
%}


/* add functions to allocate and free the memory stored by gsl_function */
%{
  typedef gsl_vector gsl_multifit_solver_vector;
  typedef gsl_matrix gsl_multifit_solver_matrix;
%}

%{
//#include <pygsl/pygsl_features.h>

//#define _PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J
#ifdef _PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC
  PyObject * _gsl_multifit_fdfsolver_getJ(gsl_multifit_fdfsolver * s)
  {
    int flag;
    gsl_matrix_view J;
    PyArrayObject *J_a = NULL;
    int nd;
    PyGSL_array_index_t dims[2];

    /* there are given in the documentation ... a bit of stomping right into the living room */
    dims[0] = s->fdf->n;
    dims[1] = s->fdf->p;
    
    J_a = PyGSL_New_Array(2, dims, NPY_DOUBLE);
    J = gsl_matrix_view_array((double *) PyArray_DATA(J_a), PyArray_DIM(J_a, 0), PyArray_DIM(J_a, 1));
    
    flag = gsl_multifit_fdfsolver_jac(s, &J.matrix);
    if (PyGSL_error_flag(flag) !=  GSL_SUCCESS){
      goto fail;
    }
    
    return (PyObject *) J_a;
    
  fail:
    Py_XDECREF(J_a);
    return NULL;
  }  
  #else /* _PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC */
  #ifndef _PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J
  #error automatically generater header did not define that the function gsl_multifit_fdfsolver_jac  
  #error was available (GSL 2.x). but then the gsl_multifit_fdfsolver struct should contain
  #error a member J which was not found neither ... 
  #endif
  PyObject * _gsl_multifit_fdfsolver_getJ(gsl_multifit_fdfsolver * s)
  {

       PyArrayObject *j_a = NULL;
       
       j_a = PyGSL_copy_gslmatrix_to_pyarray(s->J);

       DEBUG_MESS(2, "Jacobian=%p ->  py_array=%p", (void *) s->J, (void*) j_a);
       return (PyObject *) j_a;
  }
  #endif /* _PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC */
%}

%inline %{
  gsl_multifit_function * gsl_multifit_function_init(gsl_multifit_function * STORE)
  {
    return STORE;
    /* Do Not need to do anything here. All done in the typemaps */
  }
  gsl_multifit_function_fdf * gsl_multifit_function_init_fdf(gsl_multifit_function_fdf * STORE)
  {
    return STORE;
    /* Do Not need to do anything here. All done in the typemaps */
  }
  gsl_multifit_solver_vector * gsl_multifit_fsolver_getdx(gsl_multifit_fsolver * s)
  {
       return s->dx;
  }

  gsl_multifit_solver_vector * gsl_multifit_fsolver_getx(gsl_multifit_fsolver * s)
  {
       return s->x;
  }
  gsl_multifit_solver_vector * gsl_multifit_fsolver_getf(gsl_multifit_fsolver * s)
  {
       return s->f;
  }
  gsl_multifit_solver_vector * gsl_multifit_fdfsolver_getdx(gsl_multifit_fdfsolver * s)
  {
       return s->dx;
  }

  gsl_multifit_solver_vector * gsl_multifit_fdfsolver_getx(gsl_multifit_fdfsolver * s)
  {
       return s->x;
  }
  gsl_multifit_solver_vector * gsl_multifit_fdfsolver_getf(gsl_multifit_fdfsolver * s)
  {
       return s->f;
  }
  void gsl_multifit_function_free(gsl_multifit_function * FREE)
  {
    /* Do Not need to do anything here. All done in the typemaps */
  }
  void gsl_multifit_function_free_fdf(gsl_multifit_function_fdf * FREE)
  {
    /* Do Not need to do anything here. All done in the typemaps */
  }

  PyObject * gsl_multifit_fdfsolver_getJ(gsl_multifit_fdfsolver * s)
  {
    return  _gsl_multifit_fdfsolver_getJ(s);
  }
%}


/*
int gsl_multifit_gradient (const gsl_matrix * IN, const gsl_vector * IN,
                           gsl_vector * OUT);
*/
%native(gsl_multifit_gradient) PyObject * PyGSL_gsl_multifit_gradient(PyObject *self, PyObject *args);
/*
int gsl_multifit_covar (const gsl_matrix * IN, double epsrel, gsl_matrix * OUT);
*/
%native(gsl_multifit_covar) PyObject * PyGSL_gsl_multifit_covar(PyObject *self, PyObject *args);

gsl_multifit_fsolver *
gsl_multifit_fsolver_alloc (const gsl_multifit_fsolver_type * T, 
                            size_t n, size_t p);

void gsl_multifit_fsolver_free (gsl_multifit_fsolver * s);

int gsl_multifit_fsolver_set (gsl_multifit_fsolver * s, 
			      gsl_multifit_function * f, 
			      gsl_vector * IN);

int gsl_multifit_fsolver_iterate (gsl_multifit_fsolver * s);
const char * gsl_multifit_fsolver_name (const gsl_multifit_fsolver * s);
gsl_vector * gsl_multifit_fsolver_position (const gsl_multifit_fsolver * s);
gsl_multifit_fdfsolver *
gsl_multifit_fdfsolver_alloc (const gsl_multifit_fdfsolver_type * T, 
                              size_t n, size_t p);

int
gsl_multifit_fdfsolver_set (gsl_multifit_fdfsolver * s, 
			    gsl_multifit_function_fdf * fdf,
			    gsl_vector * IN);

int
gsl_multifit_fdfsolver_iterate (gsl_multifit_fdfsolver * s);

void
gsl_multifit_fdfsolver_free (gsl_multifit_fdfsolver * s);

const char * gsl_multifit_fdfsolver_name (const gsl_multifit_fdfsolver * s);
gsl_vector * gsl_multifit_fdfsolver_position (const gsl_multifit_fdfsolver * s);

%apply gsl_vector *IN {gsl_vector *dx};
%apply gsl_vector *IN {gsl_vector *x};
int gsl_multifit_test_delta (const gsl_vector * dx, const gsl_vector * x, 
                             double epsabs, double epsrel);

int gsl_multifit_test_gradient (const gsl_vector * IN, double epsabs);

/* extern const gsl_multifit_fsolver_type * gsl_multifit_fsolver_gradient; */

extern const gsl_multifit_fdfsolver_type * gsl_multifit_fdfsolver_lmder;
extern const gsl_multifit_fdfsolver_type * gsl_multifit_fdfsolver_lmsder;

%inline %{
//#include <pygsl/pygsl_features.h>
	/* 
	 * config process checked the available minimizers.
	 * If not available define them as NULL
	 */
#define _PYGSL_GSL_HAS_MULTFIT_FDFSOLVER_LMNIEL
#ifdef _PYGSL_GSL_HAS_MULTFIT_FDFSOLVER_LMNIEL
extern const gsl_multifit_fdfsolver_type * gsl_multifit_fdfsolver_lmniel;
#else
const gsl_multifit_fdfsolver_type * gsl_multifit_fdfsolver_lmniel = NULL;
#endif
%}
