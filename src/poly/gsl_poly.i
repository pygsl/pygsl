/* -*- C -*- */
/**
* Author :  Pierre Schnizer
*/



%module _poly
/*
%feature("docstring") _poly
"Wrapper over the functions as described in Chapter 6 of the\n\
reference manual.\n\
\n\
There are routines for finding real  and complex roots of quadratic and cubic\n\
equations  using analytic  methods. An  iterative polynomial  solver  is also\n\
available for finding the roots of general polynomials with real coefficients\n\
(of any order).\n\
\n\
All the doc strings were taken form the gsl reference document.";
*/
%{
#include <gsl/gsl_poly.h>
#include <gsl/gsl_errno.h>
#include <poly.ic>
%}
%init %{
  init_pygsl();
%}
/*
typedef double * gsl_complex_packed_ptr;
*/
%include typemaps.i
%include gsl_complex_typemap.i
/* Error handling the int */
/* %include gsl_error_typemap.i */


typedef unsigned int size_t;

/*
%feature("autodoc", "1"); 
*/
/* %rename(solve_quadratic) gsl_poly_solve_quadratic; */
/*
%feature("docstring") gsl_poly_solve_quadratic\
"\
a x^2 + b x + c = 0\n\
\n\
The number  of real  roots (either  zero or two)  is returned,  and their\n\
locations are stored in x0 and x1. If no real roots are found then x0 and\n\
x1 are not modified. When two real  roots are found they are stored in x0\n\
and x1 in ascending order. The case of coincident roots is not considered\n\
special. For example (x-1)^2=0 will  have two roots, which happen to have\n\
exactly equal values.\n\
\n\
The number of roots found depends on the sign of the discriminant b^2 - 4\n\
a  c. This  will  be subject  to  rounding and  cancellation errors  when\n\
computed in double  precision, and will also be subject  to errors if the\n\
coefficients  of the  polynomial are  inexact. These  errors may  cause a\n\
discrete change  in the  number of roots.  However, for  polynomials with\n\
small  integer  coefficients  the  discriminant can  always  be  computed\n\
exactly.\n\
\n\
input : a, b, c\n\
\n\
output : n, r1, r2\n\
    n  ... number of roots found\n\
    r1 ... first root\n\
    r2 ... second root\n\
"
;
*/
int gsl_poly_solve_quadratic (double A, double B, double C, 
			      double * OUTPUT, double * OUTPUT);


/* %rename(complex_solve_quadratic) gsl_poly_solve_quadratic; */
/* %feature("docstring") gsl_poly_complex_solve_quadratic\
"solve a complex quadratic equation "
*/
int gsl_poly_complex_solve_quadratic (double A, double B, double C, 
					     gsl_complex * OUTPUT,
				      gsl_complex * OUTPUT);


int gsl_poly_solve_cubic (double A, double B, double C, 
				 double *OUTPUT, double *OUTPUT, 
				 double *OUTPUT);

int gsl_poly_complex_solve_cubic (double A, double B, double C, 
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
%feature("docstring") gsl_poly_eval
"
This function evaluates the polynomial\n\
c[0] + c[1] x + c[2] x^2 + \dots + c[len-1] x^{len-1}\n\
using Horner's method for stability\n\
\n\
input: c, x\n\
    c ... array of coefficients\n\
    x ... \n\
\n\    
output: y\n\
"
*/
/*
extern int gsl_poly_dd_init (double dd[], const double xa[], const double ya[],
			     size_t SIZE);
*/
%native (gsl_poly_dd_init) PyObject *
pygsl_poly_dd_init(PyObject *self, PyObject *args);
/* %feature ("docstring") gsl_poly_dd_init " XXX Missing" */

/*
extern double gsl_poly_dd_eval (const double dd[], const double xa[], 
				const size_t SIZE, const double X);
*/
/* %feature("docstring") _poly " XXX Poly module doc "; */

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
