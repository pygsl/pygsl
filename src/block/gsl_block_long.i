/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_long_set_zero (gsl_vector_long  * IN_SIZE_OUT);
void gsl_vector_long_set_all (gsl_vector_long * IN_SIZE_OUT, long IN);
int gsl_vector_long_set_basis (gsl_vector_long * IN_SIZE_OUT, size_t i);


int gsl_vector_long_fread (FILE * stream, gsl_vector_long * IN_SIZE_OUT);
int gsl_vector_long_fwrite (FILE * stream, const gsl_vector_long * IN);
int gsl_vector_long_fscanf (FILE * stream, gsl_vector_long * IN_SIZE_OUT);
int gsl_vector_long_fprintf (FILE * stream, const gsl_vector_long * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_long_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_long_reverse (gsl_vector_long * INOUT);

int gsl_vector_long_swap (gsl_vector_long * INOUT, gsl_vector_long * INOUT);


int gsl_vector_long_swap_elements (gsl_vector_long * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_long_max (const gsl_vector_long * IN);
double gsl_vector_long_min (const gsl_vector_long * IN);
void gsl_vector_long_minmax (const gsl_vector_long * IN, long * OUTPUT, 
			long * OUTPUT);

size_t gsl_vector_long_max_index (const gsl_vector_long * IN);
size_t gsl_vector_long_min_index (const gsl_vector_long * IN);
void gsl_vector_long_minmax_index (const gsl_vector_long * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_long_isnull(const gsl_vector_long *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_long_set_zero (gsl_matrix_long  * IN_SIZE_OUT);
void gsl_matrix_long_set_all (gsl_matrix_long * IN_SIZE_OUT, long IN);
void gsl_matrix_long_set_identity (gsl_matrix_long * IN_SIZE_OUT);


int gsl_matrix_long_fread (FILE * stream, gsl_matrix_long * IN_SIZE_OUT);
int gsl_matrix_long_fwrite (FILE * stream, const gsl_matrix_long * IN);
int gsl_matrix_long_fscanf (FILE * stream, gsl_matrix_long * IN_SIZE_OUT);
int gsl_matrix_long_fprintf (FILE * stream, const gsl_matrix_long * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_long_swap(gsl_matrix_long * INOUT, gsl_matrix_long * INOUT);

int gsl_matrix_long_swap_rows(gsl_matrix_long * INOUT, const size_t i, const size_t j);
int gsl_matrix_long_swap_columns(gsl_matrix_long * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_long_swap_rowcol(gsl_matrix_long * INOUT, const size_t i, const size_t j);
int gsl_matrix_long_transpose (gsl_matrix_long * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_long_transpose_memcpy (gsl_matrix_long * OUT, const gsl_matrix_long * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_long_max (const gsl_matrix_long * IN);
double gsl_matrix_long_min (const gsl_matrix_long * IN);
void gsl_matrix_long_minmax (const gsl_matrix_long * IN, long * OUTPUT, long * OUTPUT);

void gsl_matrix_long_max_index (const gsl_matrix_long * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_long_min_index (const gsl_matrix_long * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_long_minmax_index (const gsl_matrix_long * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_long_isnull (const gsl_matrix_long * IN);


gsl_vector_long_view gsl_matrix_long_diagonal(gsl_matrix_long *IN);
gsl_vector_long_view gsl_matrix_long_subdiagonal(gsl_matrix_long *IN, size_t k);
gsl_vector_long_view gsl_matrix_long_superdiagonal(gsl_matrix_long *IN, size_t k);
