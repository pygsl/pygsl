/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_complex_float_set_zero (gsl_vector_complex_float  * IN_SIZE_OUT);
void gsl_vector_complex_float_set_all (gsl_vector_complex_float * IN_SIZE_OUT, gsl_complex_float IN);
int gsl_vector_complex_float_set_basis (gsl_vector_complex_float * IN_SIZE_OUT, size_t i);


int gsl_vector_complex_float_fread (FILE * stream, gsl_vector_complex_float * IN_SIZE_OUT);
int gsl_vector_complex_float_fwrite (FILE * stream, const gsl_vector_complex_float * IN);
int gsl_vector_complex_float_fscanf (FILE * stream, gsl_vector_complex_float * IN_SIZE_OUT);
int gsl_vector_complex_float_fprintf (FILE * stream, const gsl_vector_complex_float * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_complex_float_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_complex_float_reverse (gsl_vector_complex_float * INOUT);

int gsl_vector_complex_float_swap (gsl_vector_complex_float * INOUT, gsl_vector_complex_float * INOUT);


int gsl_vector_complex_float_swap_elements (gsl_vector_complex_float * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_complex_float_max (const gsl_vector_complex_float * IN);
double gsl_vector_complex_float_min (const gsl_vector_complex_float * IN);
void gsl_vector_complex_float_minmax (const gsl_vector_complex_float * IN, gsl_complex_float * OUTPUT, 
			gsl_complex_float * OUTPUT);

size_t gsl_vector_complex_float_max_index (const gsl_vector_complex_float * IN);
size_t gsl_vector_complex_float_min_index (const gsl_vector_complex_float * IN);
void gsl_vector_complex_float_minmax_index (const gsl_vector_complex_float * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_complex_float_isnull(const gsl_vector_complex_float *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_complex_float_set_zero (gsl_matrix_complex_float  * IN_SIZE_OUT);
void gsl_matrix_complex_float_set_all (gsl_matrix_complex_float * IN_SIZE_OUT, gsl_complex_float IN);
void gsl_matrix_complex_float_set_identity (gsl_matrix_complex_float * IN_SIZE_OUT);


int gsl_matrix_complex_float_fread (FILE * stream, gsl_matrix_complex_float * IN_SIZE_OUT);
int gsl_matrix_complex_float_fwrite (FILE * stream, const gsl_matrix_complex_float * IN);
int gsl_matrix_complex_float_fscanf (FILE * stream, gsl_matrix_complex_float * IN_SIZE_OUT);
int gsl_matrix_complex_float_fprintf (FILE * stream, const gsl_matrix_complex_float * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_complex_float_swap(gsl_matrix_complex_float * INOUT, gsl_matrix_complex_float * INOUT);

int gsl_matrix_complex_float_swap_rows(gsl_matrix_complex_float * INOUT, const size_t i, const size_t j);
int gsl_matrix_complex_float_swap_columns(gsl_matrix_complex_float * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_complex_float_swap_rowcol(gsl_matrix_complex_float * INOUT, const size_t i, const size_t j);
int gsl_matrix_complex_float_transpose (gsl_matrix_complex_float * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_complex_float_transpose_memcpy (gsl_matrix_complex_float * OUT, const gsl_matrix_complex_float * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_complex_float_max (const gsl_matrix_complex_float * IN);
double gsl_matrix_complex_float_min (const gsl_matrix_complex_float * IN);
void gsl_matrix_complex_float_minmax (const gsl_matrix_complex_float * IN, gsl_complex_float * OUTPUT, gsl_complex_float * OUTPUT);

void gsl_matrix_complex_float_max_index (const gsl_matrix_complex_float * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_complex_float_min_index (const gsl_matrix_complex_float * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_complex_float_minmax_index (const gsl_matrix_complex_float * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_complex_float_isnull (const gsl_matrix_complex_float * IN);


gsl_vector_complex_float_view gsl_matrix_complex_float_diagonal(gsl_matrix_complex_float *IN);
gsl_vector_complex_float_view gsl_matrix_complex_float_subdiagonal(gsl_matrix_complex_float *IN, size_t k);
gsl_vector_complex_float_view gsl_matrix_complex_float_superdiagonal(gsl_matrix_complex_float *IN, size_t k);
