/* -*- C -*- */
/**
 * Author : Pierre Schnizer
 * Date : January 2003
 *
 * Warning nearly no function tested, so a danergous to use allready!
 */
%{
#include <gsl/gsl_integration.h>
%}

%include typemaps.i
%include gsl_function_typemaps.i
%include gsl_error_typemap.i

%apply double *OUTPUT {double *result}
%apply double *OUTPUT {double *abserr}
%apply unsigned int *OUTPUT {size_t *neval}

gsl_integration_workspace *
gsl_integration_workspace_alloc (const size_t n);

void
gsl_integration_workspace_free (gsl_integration_workspace * w);
%{
size_t 
gsl_integration_workspace_get_size(gsl_integration_workspace * w)
{
     return w->size;
}
%}
size_t 
gsl_integration_workspace_get_size(gsl_integration_workspace * w);

gsl_integration_qaws_table * 
gsl_integration_qaws_table_alloc (double alpha, double beta, int mu, int nu);

int
gsl_integration_qaws_table_set (gsl_integration_qaws_table * t,
                                double alpha, double beta, int mu, int nu);

void
gsl_integration_qaws_table_free (gsl_integration_qaws_table * t);

/* Workspace for QAWO integrator */

enum gsl_integration_qawo_enum { GSL_INTEG_COSINE, GSL_INTEG_SINE };


gsl_integration_qawo_table * 
gsl_integration_qawo_table_alloc (double omega, double L, 
                                  enum gsl_integration_qawo_enum sine,
                                  size_t n);

int
gsl_integration_qawo_table_set (gsl_integration_qawo_table * t,
                                double omega, double L,
                                enum gsl_integration_qawo_enum sine);

int
gsl_integration_qawo_table_set_length (gsl_integration_qawo_table * t,
                                       double L);

void
gsl_integration_qawo_table_free (gsl_integration_qawo_table * t);




/*
void gsl_integration_qk15 (const gsl_function * f, double a, double b,
			   double *result, double *abserr,
			   double *resabs, double *resasc);

void gsl_integration_qk21 (const gsl_function * f, double a, double b,
			   double *result, double *abserr,
			   double *resabs, double *resasc);

void gsl_integration_qk31 (const gsl_function * f, double a, double b,
			   double *result, double *abserr,
			   double *resabs, double *resasc);

void gsl_integration_qk41 (const gsl_function * f, double a, double b,
			   double *result, double *abserr,
			   double *resabs, double *resasc);

void gsl_integration_qk51 (const gsl_function * f, double a, double b,
			   double *result, double *abserr,
			   double *resabs, double *resasc);

void gsl_integration_qk61 (const gsl_function * f, double a, double b,
			   double *result, double *abserr,
			   double *resabs, double *resasc);

void gsl_integration_qcheb (gsl_function * f, double a, double b, 
                            double *cheb12, double *cheb24);
*/
/* The low-level integration rules in QUADPACK are identified by small
   integers (1-6). We'll use symbolic constants to refer to them.  */

enum gsl_integ_gauss
  {
    GSL_INTEG_GAUSS15 = 1,	/* 15 point Gauss-Kronrod rule */
    GSL_INTEG_GAUSS21 = 2,	/* 21 point Gauss-Kronrod rule */
    GSL_INTEG_GAUSS31 = 3,	/* 31 point Gauss-Kronrod rule */
    GSL_INTEG_GAUSS41 = 4,	/* 41 point Gauss-Kronrod rule */
    GSL_INTEG_GAUSS51 = 5,	/* 51 point Gauss-Kronrod rule */
    GSL_INTEG_GAUSS61 = 6	/* 61 point Gauss-Kronrod rule */
  };

int gsl_integration_qng (const gsl_function *  BUFFER,
			 double a, double b,
			 double epsabs, double epsrel,
			 double *result, double *abserr,
			 size_t * neval);

int gsl_integration_qag (const gsl_function *  BUFFER,
			 double a, double b,
			 double epsabs, double epsrel, size_t limit,
			 int key,
			 gsl_integration_workspace * workspace,
			 double *result, double *abserr);

int gsl_integration_qagi (gsl_function *  BUFFER,
			  double epsabs, double epsrel, size_t limit,
			  gsl_integration_workspace * workspace,
			  double *result, double *abserr);

int gsl_integration_qagiu (gsl_function *  BUFFER,
			   double a,
			   double epsabs, double epsrel, size_t limit,
			   gsl_integration_workspace * workspace,
			   double *result, double *abserr);

int gsl_integration_qagil (gsl_function *  BUFFER,
			   double b,
			   double epsabs, double epsrel, size_t limit,
			   gsl_integration_workspace * workspace,
			   double *result, double *abserr);


int gsl_integration_qags (const gsl_function *  BUFFER,
			  double a, double b,
			  double epsabs, double epsrel, size_t limit,
			  gsl_integration_workspace * workspace,
			  double *result, double *abserr);

%typemap(arginit) (double *pts, size_t npts) %{
     PyArrayObject * volatile _PyVector$argnum = NULL;
%}
%typemap(in) (double *pts, size_t npts) %{
     _PyVector$argnum = PyGSL_vector_check($input, -1, PyGSL_DARRAY_CINPUT($argnum), NULL, NULL);
     if (_PyVector$argnum == NULL)
	  goto fail;
     $1 = (double*)(_PyVector$argnum->data);
     $2 = _PyVector$argnum->dimensions[0];
%};
%typemap(argout) (double *pts, 
		  size_t npts) {
     Py_XDECREF(_PyVector$argnum);
};

int gsl_integration_qagp (const gsl_function *  BUFFER,
			  double *pts, size_t npts,
			  double epsabs, double epsrel, size_t limit,
			  gsl_integration_workspace * workspace,
			  double *result, double *abserr);

int gsl_integration_qawc (gsl_function * BUFFER,
			  const double a, const double b, const double c,
			  const double epsabs, const double epsrel, 
			  const size_t limit,
			  gsl_integration_workspace * workspace,
			  double * result, double * abserr);

int gsl_integration_qaws (gsl_function *  BUFFER,
			  const double a, const double b,
			  gsl_integration_qaws_table * t,
			  const double epsabs, const double epsrel,
			  const size_t limit,
			  gsl_integration_workspace * workspace,
			  double *result, double *abserr);

int gsl_integration_qawo (gsl_function *  BUFFER,
			  const double a,
			  const double epsabs, const double epsrel,
			  const size_t limit,
			  gsl_integration_workspace * workspace,
			  gsl_integration_qawo_table * wf,
			  double *result, double *abserr);

int gsl_integration_qawf (gsl_function *  BUFFER,
			  const double a,
			  const double epsabs,
			  const size_t limit,
			  gsl_integration_workspace * workspace,
			  gsl_integration_workspace * cycle_workspace,
			  gsl_integration_qawo_table * wf,
			  double *result, double *abserr);

