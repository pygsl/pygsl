/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_complex_set_zero (gsl_vector_complex  * IN_SIZE_OUT);
void gsl_vector_complex_set_all (gsl_vector_complex * IN_SIZE_OUT, gsl_complex IN);
int gsl_vector_complex_set_basis (gsl_vector_complex * IN_SIZE_OUT, size_t i);


int gsl_vector_complex_fread (FILE * stream, gsl_vector_complex * IN_SIZE_OUT);
int gsl_vector_complex_fwrite (FILE * stream, const gsl_vector_complex * IN);
int gsl_vector_complex_fscanf (FILE * stream, gsl_vector_complex * IN_SIZE_OUT);
int gsl_vector_complex_fprintf (FILE * stream, const gsl_vector_complex * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_complex_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_complex_reverse (gsl_vector_complex * INOUT);

int gsl_vector_complex_swap (gsl_vector_complex * INOUT, gsl_vector_complex * INOUT);


int gsl_vector_complex_swap_elements (gsl_vector_complex * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_complex_max (const gsl_vector_complex * IN);
double gsl_vector_complex_min (const gsl_vector_complex * IN);
void gsl_vector_complex_minmax (const gsl_vector_complex * IN, gsl_complex * OUTPUT, 
			gsl_complex * OUTPUT);

size_t gsl_vector_complex_max_index (const gsl_vector_complex * IN);
size_t gsl_vector_complex_min_index (const gsl_vector_complex * IN);
void gsl_vector_complex_minmax_index (const gsl_vector_complex * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_complex_isnull(const gsl_vector_complex *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_complex_set_zero (gsl_matrix_complex  * IN_SIZE_OUT);
void gsl_matrix_complex_set_all (gsl_matrix_complex * IN_SIZE_OUT, gsl_complex IN);
void gsl_matrix_complex_set_identity (gsl_matrix_complex * IN_SIZE_OUT);


int gsl_matrix_complex_fread (FILE * stream, gsl_matrix_complex * IN_SIZE_OUT);
int gsl_matrix_complex_fwrite (FILE * stream, const gsl_matrix_complex * IN);
int gsl_matrix_complex_fscanf (FILE * stream, gsl_matrix_complex * IN_SIZE_OUT);
int gsl_matrix_complex_fprintf (FILE * stream, const gsl_matrix_complex * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_complex_swap(gsl_matrix_complex * INOUT, gsl_matrix_complex * INOUT);

int gsl_matrix_complex_swap_rows(gsl_matrix_complex * INOUT, const size_t i, const size_t j);
int gsl_matrix_complex_swap_columns(gsl_matrix_complex * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_complex_swap_rowcol(gsl_matrix_complex * INOUT, const size_t i, const size_t j);
int gsl_matrix_complex_transpose (gsl_matrix_complex * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_complex_transpose_memcpy (gsl_matrix_complex * OUT, const gsl_matrix_complex * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_complex_max (const gsl_matrix_complex * IN);
double gsl_matrix_complex_min (const gsl_matrix_complex * IN);
void gsl_matrix_complex_minmax (const gsl_matrix_complex * IN, gsl_complex * OUTPUT, gsl_complex * OUTPUT);

void gsl_matrix_complex_max_index (const gsl_matrix_complex * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_complex_min_index (const gsl_matrix_complex * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_complex_minmax_index (const gsl_matrix_complex * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_complex_isnull (const gsl_matrix_complex * IN);


gsl_vector_complex_view gsl_matrix_complex_diagonal(gsl_matrix_complex *IN);
gsl_vector_complex_view gsl_matrix_complex_subdiagonal(gsl_matrix_complex *IN, size_t k);
gsl_vector_complex_view gsl_matrix_complex_superdiagonal(gsl_matrix_complex *IN, size_t k);
