/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 */   
/* treat the following integers as error flags ! */
%apply gsl_error_flag {int gsl_matrix_TYPE_fread,
		       int gsl_matrix_TYPE_fwrite,
		       int gsl_matrix_TYPE_fscanf,
		       int gsl_matrix_TYPE_fprintf,
		       int gsl_matrix_TYPE_swap,
		       int gsl_matrix_TYPE_swap_rows,
		       int gsl_matrix_TYPE_swap_columns,
		       int gsl_matrix_TYPE_swap_rowcol,
		       int gsl_matrix_TYPE_transpose,
                       int gsl_vector_TYPE_set_basis,
		       int gsl_vector_TYPE_reverse,
                       int gsl_vector_TYPE_swap,
         	       int gsl_vector_TYPE_swap_elements,
                       int gsl_vector_TYPE_fread,   
		       int gsl_vector_TYPE_fwrite, 
		       int gsl_vector_TYPE_fscanf, 
		       int gsl_vector_TYPE_fprintf
		      };

/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_TYPE_set_zero (gsl_vector_TYPE  * IN_SIZE_OUT);
void gsl_vector_TYPE_set_all (gsl_vector_TYPE * IN_SIZE_OUT, TYPE_BASIS IN);
int gsl_vector_TYPE_set_basis (gsl_vector_TYPE * IN_SIZE_OUT, size_t i);


int gsl_vector_TYPE_fread (FILE * stream, gsl_vector_TYPE * IN_SIZE_OUT);
int gsl_vector_TYPE_fwrite (FILE * stream, const gsl_vector_TYPE * IN);
int gsl_vector_TYPE_fscanf (FILE * stream, gsl_vector_TYPE * IN_SIZE_OUT);
int gsl_vector_TYPE_fprintf (FILE * stream, const gsl_vector_TYPE * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_TYPE_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_TYPE_reverse (gsl_vector_TYPE * INOUT);

int gsl_vector_TYPE_swap (gsl_vector_TYPE * INOUT, gsl_vector_TYPE * INOUT);


int gsl_vector_TYPE_swap_elements (gsl_vector_TYPE * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_TYPE_max (const gsl_vector_TYPE * IN);
double gsl_vector_TYPE_min (const gsl_vector_TYPE * IN);
void gsl_vector_TYPE_minmax (const gsl_vector_TYPE * IN, TYPE_BASIS * OUTPUT, 
			TYPE_BASIS * OUTPUT);

size_t gsl_vector_TYPE_max_index (const gsl_vector_TYPE * IN);
size_t gsl_vector_TYPE_min_index (const gsl_vector_TYPE * IN);
void gsl_vector_TYPE_minmax_index (const gsl_vector_TYPE * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_TYPE_isnull(const gsl_vector_TYPE *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_TYPE_set_zero (gsl_matrix_TYPE  * IN_SIZE_OUT);
void gsl_matrix_TYPE_set_all (gsl_matrix_TYPE * IN_SIZE_OUT, TYPE_BASIS IN);
void gsl_matrix_TYPE_set_identity (gsl_matrix_TYPE * IN_SIZE_OUT);


int gsl_matrix_TYPE_fread (FILE * stream, gsl_matrix_TYPE * IN_SIZE_OUT);
int gsl_matrix_TYPE_fwrite (FILE * stream, const gsl_matrix_TYPE * IN);
int gsl_matrix_TYPE_fscanf (FILE * stream, gsl_matrix_TYPE * IN_SIZE_OUT);
int gsl_matrix_TYPE_fprintf (FILE * stream, const gsl_matrix_TYPE * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_TYPE_swap(gsl_matrix_TYPE * INOUT, gsl_matrix_TYPE * INOUT);

int gsl_matrix_TYPE_swap_rows(gsl_matrix_TYPE * INOUT, const size_t i, const size_t j);
int gsl_matrix_TYPE_swap_columns(gsl_matrix_TYPE * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_TYPE_swap_rowcol(gsl_matrix_TYPE * INOUT, const size_t i, const size_t j);
int gsl_matrix_TYPE_transpose (gsl_matrix_TYPE * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_TYPE_transpose_memcpy (gsl_matrix_TYPE * OUT, const gsl_matrix_TYPE * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_TYPE_max (const gsl_matrix_TYPE * IN);
double gsl_matrix_TYPE_min (const gsl_matrix_TYPE * IN);
void gsl_matrix_TYPE_minmax (const gsl_matrix_TYPE * IN, TYPE_BASIS * OUTPUT, TYPE_BASIS * OUTPUT);

void gsl_matrix_TYPE_max_index (const gsl_matrix_TYPE * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_TYPE_min_index (const gsl_matrix_TYPE * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_TYPE_minmax_index (const gsl_matrix_TYPE * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_TYPE_isnull (const gsl_matrix_TYPE * IN);


gsl_vector_TYPE_view gsl_matrix_TYPE_diagonal(gsl_matrix_TYPE *IN);
gsl_vector_TYPE_view gsl_matrix_TYPE_subdiagonal(gsl_matrix_TYPE *IN, size_t k);
gsl_vector_TYPE_view gsl_matrix_TYPE_superdiagonal(gsl_matrix_TYPE *IN, size_t k);
