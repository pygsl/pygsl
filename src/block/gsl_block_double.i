/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_double_set_zero (gsl_vector_double  * IN_SIZE_OUT);
void gsl_vector_double_set_all (gsl_vector_double * IN_SIZE_OUT, double IN);
int gsl_vector_double_set_basis (gsl_vector_double * IN_SIZE_OUT, size_t i);


int gsl_vector_double_fread (FILE * stream, gsl_vector_double * IN_SIZE_OUT);
int gsl_vector_double_fwrite (FILE * stream, const gsl_vector_double * IN);
int gsl_vector_double_fscanf (FILE * stream, gsl_vector_double * IN_SIZE_OUT);
int gsl_vector_double_fprintf (FILE * stream, const gsl_vector_double * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_double_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_double_reverse (gsl_vector_double * INOUT);

int gsl_vector_double_swap (gsl_vector_double * INOUT, gsl_vector_double * INOUT);


int gsl_vector_double_swap_elements (gsl_vector_double * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_double_max (const gsl_vector_double * IN);
double gsl_vector_double_min (const gsl_vector_double * IN);
void gsl_vector_double_minmax (const gsl_vector_double * IN, double * OUTPUT, 
			double * OUTPUT);

size_t gsl_vector_double_max_index (const gsl_vector_double * IN);
size_t gsl_vector_double_min_index (const gsl_vector_double * IN);
void gsl_vector_double_minmax_index (const gsl_vector_double * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_double_isnull(const gsl_vector_double *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_double_set_zero (gsl_matrix_double  * IN_SIZE_OUT);
void gsl_matrix_double_set_all (gsl_matrix_double * IN_SIZE_OUT, double IN);
void gsl_matrix_double_set_identity (gsl_matrix_double * IN_SIZE_OUT);


int gsl_matrix_double_fread (FILE * stream, gsl_matrix_double * IN_SIZE_OUT);
int gsl_matrix_double_fwrite (FILE * stream, const gsl_matrix_double * IN);
int gsl_matrix_double_fscanf (FILE * stream, gsl_matrix_double * IN_SIZE_OUT);
int gsl_matrix_double_fprintf (FILE * stream, const gsl_matrix_double * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_double_swap(gsl_matrix_double * INOUT, gsl_matrix_double * INOUT);

int gsl_matrix_double_swap_rows(gsl_matrix_double * INOUT, const size_t i, const size_t j);
int gsl_matrix_double_swap_columns(gsl_matrix_double * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_double_swap_rowcol(gsl_matrix_double * INOUT, const size_t i, const size_t j);
int gsl_matrix_double_transpose (gsl_matrix_double * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_double_transpose_memcpy (gsl_matrix_double * OUT, const gsl_matrix_double * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_double_max (const gsl_matrix_double * IN);
double gsl_matrix_double_min (const gsl_matrix_double * IN);
void gsl_matrix_double_minmax (const gsl_matrix_double * IN, double * OUTPUT, double * OUTPUT);

void gsl_matrix_double_max_index (const gsl_matrix_double * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_double_min_index (const gsl_matrix_double * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_double_minmax_index (const gsl_matrix_double * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_double_isnull (const gsl_matrix_double * IN);


gsl_vector_double_view gsl_matrix_double_diagonal(gsl_matrix_double *IN);
gsl_vector_double_view gsl_matrix_double_subdiagonal(gsl_matrix_double *IN, size_t k);
gsl_vector_double_view gsl_matrix_double_superdiagonal(gsl_matrix_double *IN, size_t k);
