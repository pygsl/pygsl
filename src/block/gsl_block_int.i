/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_int_set_zero (gsl_vector_int  * IN_SIZE_OUT);
void gsl_vector_int_set_all (gsl_vector_int * IN_SIZE_OUT, int IN);
int gsl_vector_int_set_basis (gsl_vector_int * IN_SIZE_OUT, size_t i);


int gsl_vector_int_fread (FILE * stream, gsl_vector_int * IN_SIZE_OUT);
int gsl_vector_int_fwrite (FILE * stream, const gsl_vector_int * IN);
int gsl_vector_int_fscanf (FILE * stream, gsl_vector_int * IN_SIZE_OUT);
int gsl_vector_int_fprintf (FILE * stream, const gsl_vector_int * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_int_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_int_reverse (gsl_vector_int * INOUT);

int gsl_vector_int_swap (gsl_vector_int * INOUT, gsl_vector_int * INOUT);


int gsl_vector_int_swap_elements (gsl_vector_int * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_int_max (const gsl_vector_int * IN);
double gsl_vector_int_min (const gsl_vector_int * IN);
void gsl_vector_int_minmax (const gsl_vector_int * IN, int * OUTPUT, 
			int * OUTPUT);

size_t gsl_vector_int_max_index (const gsl_vector_int * IN);
size_t gsl_vector_int_min_index (const gsl_vector_int * IN);
void gsl_vector_int_minmax_index (const gsl_vector_int * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_int_isnull(const gsl_vector_int *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_int_set_zero (gsl_matrix_int  * IN_SIZE_OUT);
void gsl_matrix_int_set_all (gsl_matrix_int * IN_SIZE_OUT, int IN);
void gsl_matrix_int_set_identity (gsl_matrix_int * IN_SIZE_OUT);


int gsl_matrix_int_fread (FILE * stream, gsl_matrix_int * IN_SIZE_OUT);
int gsl_matrix_int_fwrite (FILE * stream, const gsl_matrix_int * IN);
int gsl_matrix_int_fscanf (FILE * stream, gsl_matrix_int * IN_SIZE_OUT);
int gsl_matrix_int_fprintf (FILE * stream, const gsl_matrix_int * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_int_swap(gsl_matrix_int * INOUT, gsl_matrix_int * INOUT);

int gsl_matrix_int_swap_rows(gsl_matrix_int * INOUT, const size_t i, const size_t j);
int gsl_matrix_int_swap_columns(gsl_matrix_int * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_int_swap_rowcol(gsl_matrix_int * INOUT, const size_t i, const size_t j);
int gsl_matrix_int_transpose (gsl_matrix_int * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_int_transpose_memcpy (gsl_matrix_int * OUT, const gsl_matrix_int * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_int_max (const gsl_matrix_int * IN);
double gsl_matrix_int_min (const gsl_matrix_int * IN);
void gsl_matrix_int_minmax (const gsl_matrix_int * IN, int * OUTPUT, int * OUTPUT);

void gsl_matrix_int_max_index (const gsl_matrix_int * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_int_min_index (const gsl_matrix_int * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_int_minmax_index (const gsl_matrix_int * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_int_isnull (const gsl_matrix_int * IN);


gsl_vector_int_view gsl_matrix_int_diagonal(gsl_matrix_int *IN);
gsl_vector_int_view gsl_matrix_int_subdiagonal(gsl_matrix_int *IN, size_t k);
gsl_vector_int_view gsl_matrix_int_superdiagonal(gsl_matrix_int *IN, size_t k);
