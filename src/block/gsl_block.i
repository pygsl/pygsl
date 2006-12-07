/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * created: December 2002
 * file: pygsl/src/odeiv/pygsl_odeiv.i
 *
 * Provides conversions of numpy arrays to gsl_vectors and gsl_matrices.
 */

/**
 * author: Pierre Schnizer
 * created: December 2002
 * file: pygsl/src/odeiv/pygsl_odeiv.i
 *
 */


%module _block
%{
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_complex.h>
#include <stdlib.h>
#include <assert.h>
#include <pygsl/error_helpers.h>
%}

%init %{
  init_pygsl();
%}


/* Provides the conversion double * */
%include typemaps.i
/* Allows to pass open files from python to C */
%include file_typemaps.i
/* size_t conversions */
%include misc_typemaps.i

/* vector conversions */
%include gsl_block_typemaps.i


/* Error handling the int */
%include gsl_error_typemap.i

%apply gsl_error_flag {int gsl_matrix_fread,
		       int gsl_matrix_fwrite,
		       int gsl_matrix_fscanf,
		       int gsl_matrix_fprintf,
		       int gsl_matrix_swap,
		       int gsl_matrix_swap_rows,
		       int gsl_matrix_swap_columns,
		       int gsl_matrix_swap_rowcol,
		       int gsl_matrix_transpose,
                       int gsl_vector_set_basis,
		       int gsl_vector_reverse,
                       int gsl_vector_swap,
         	       int gsl_vector_swap_elements,
                       int gsl_vector_fread,   
		       int gsl_vector_fwrite, 
		       int gsl_vector_fscanf, 
		       int gsl_vector_fprintf
		      };

typedef unsigned int size_t;


%include gsl_block_generic.i

%include gsl_block_float.i
%include gsl_block_long.i
%include gsl_block_int.i
%include gsl_block_short.i
%include gsl_block_char.i

%{
#define _GSL_BLOCK_COMPLEX_FUNCTIONS_C
%}
#define _GSL_BLOCK_COMPLEX_FUNCTIONS
%include gsl_complex_typemap.i
%include gsl_block_complex.i
%include gsl_block_complex_float.i





