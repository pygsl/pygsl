/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_short_set_zero (gsl_vector_short  * IN_SIZE_OUT);
void gsl_vector_short_set_all (gsl_vector_short * IN_SIZE_OUT, short IN);
int gsl_vector_short_set_basis (gsl_vector_short * IN_SIZE_OUT, size_t i);


int gsl_vector_short_fread (FILE * stream, gsl_vector_short * IN_SIZE_OUT);
int gsl_vector_short_fwrite (FILE * stream, const gsl_vector_short * IN);
int gsl_vector_short_fscanf (FILE * stream, gsl_vector_short * IN_SIZE_OUT);
int gsl_vector_short_fprintf (FILE * stream, const gsl_vector_short * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_short_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_short_reverse (gsl_vector_short * INOUT);

int gsl_vector_short_swap (gsl_vector_short * INOUT, gsl_vector_short * INOUT);


int gsl_vector_short_swap_elements (gsl_vector_short * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_short_max (const gsl_vector_short * IN);
double gsl_vector_short_min (const gsl_vector_short * IN);
void gsl_vector_short_minmax (const gsl_vector_short * IN, short * OUTPUT, 
			short * OUTPUT);

size_t gsl_vector_short_max_index (const gsl_vector_short * IN);
size_t gsl_vector_short_min_index (const gsl_vector_short * IN);
void gsl_vector_short_minmax_index (const gsl_vector_short * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_short_isnull(const gsl_vector_short *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_short_set_zero (gsl_matrix_short  * IN_SIZE_OUT);
void gsl_matrix_short_set_all (gsl_matrix_short * IN_SIZE_OUT, short IN);
void gsl_matrix_short_set_identity (gsl_matrix_short * IN_SIZE_OUT);


int gsl_matrix_short_fread (FILE * stream, gsl_matrix_short * IN_SIZE_OUT);
int gsl_matrix_short_fwrite (FILE * stream, const gsl_matrix_short * IN);
int gsl_matrix_short_fscanf (FILE * stream, gsl_matrix_short * IN_SIZE_OUT);
int gsl_matrix_short_fprintf (FILE * stream, const gsl_matrix_short * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_short_swap(gsl_matrix_short * INOUT, gsl_matrix_short * INOUT);

int gsl_matrix_short_swap_rows(gsl_matrix_short * INOUT, const size_t i, const size_t j);
int gsl_matrix_short_swap_columns(gsl_matrix_short * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_short_swap_rowcol(gsl_matrix_short * INOUT, const size_t i, const size_t j);
int gsl_matrix_short_transpose (gsl_matrix_short * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_short_transpose_memcpy (gsl_matrix_short * OUT, const gsl_matrix_short * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_short_max (const gsl_matrix_short * IN);
double gsl_matrix_short_min (const gsl_matrix_short * IN);
void gsl_matrix_short_minmax (const gsl_matrix_short * IN, short * OUTPUT, short * OUTPUT);

void gsl_matrix_short_max_index (const gsl_matrix_short * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_short_min_index (const gsl_matrix_short * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_short_minmax_index (const gsl_matrix_short * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_short_isnull (const gsl_matrix_short * IN);


gsl_vector_short_view gsl_matrix_short_diagonal(gsl_matrix_short *IN);
gsl_vector_short_view gsl_matrix_short_subdiagonal(gsl_matrix_short *IN, size_t k);
gsl_vector_short_view gsl_matrix_short_superdiagonal(gsl_matrix_short *IN, size_t k);
