/* -*- C -*- */
/**
* Author :  Pierre Schnizer
*/
%module _poly

%{
#include <gsl/gsl_poly.h>
#include <gsl/gsl_errno.h>
#include <poly.ic>
%}
%init %{
  import_array();
%}
/*
typedef double * gsl_complex_packed_ptr;
*/
%include typemaps.i
%include gsl_complex_typemap.i
/* Error handling the int */
%include gsl_error_typemap.i


typedef unsigned int size_t;


extern int gsl_poly_solve_quadratic (double A, double B, double C, 
				     double * OUTPUT, double * OUTPUT);
extern int gsl_poly_complex_solve_quadratic (double A, double B, double C, 
					     gsl_complex * OUTPUT,
					     gsl_complex * OUTPUT);
extern int gsl_poly_solve_cubic (double A, double B, double C, 
				 double *OUTPUT, double *OUTPUT, 
				 double *OUTPUT);

extern int gsl_poly_complex_solve_cubic (double A, double B, double C, 
					 gsl_complex *OUTPUT, 
					 gsl_complex *OUTPUT,
					 gsl_complex *OUTPUT);
/*
extern double gsl_poly_eval (const double *INSIMPLE, const int simplelen, 
			     const double X);
*/
%native (gsl_poly_eval) PyObject *
pygsl_poly_eval(PyObject *self, PyObject *args);
/*
extern int gsl_poly_dd_init (double dd[], const double xa[], const double ya[],
			     size_t SIZE);
*/
%native (gsl_poly_dd_init) PyObject *
pygsl_poly_dd_init(PyObject *self, PyObject *args);
/*
extern double gsl_poly_dd_eval (const double dd[], const double xa[], 
				const size_t SIZE, const double X);
*/
%native (gsl_poly_dd_eval) PyObject *
pygsl_poly_dd_eval(PyObject *self, PyObject *args);
/*
extern int gsl_poly_dd_taylor (double c[], double XP, const double dd[], 
			       const double xa[], size_t SIZE, double w[]);
*/
%native (gsl_poly_dd_taylor) PyObject *
pygsl_poly_dd_taylor(PyObject *self, PyObject *args);


extern gsl_poly_complex_workspace * 
gsl_poly_complex_workspace_alloc (size_t N);

extern void gsl_poly_complex_workspace_free (gsl_poly_complex_workspace * W);
/*
extern int gsl_poly_complex_solve (const double * A, size_t N, 
				   gsl_poly_complex_workspace * W, 
				   gsl_complex_packet_ptr *Z);
*/
%native (gsl_poly_complex_solve) PyObject *
pygsl_poly_complex_solve(PyObject *self, PyObject *args);
