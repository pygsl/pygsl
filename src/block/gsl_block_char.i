/* -*- C -*- */
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_char_set_zero (gsl_vector_char  * IN_SIZE_OUT);
void gsl_vector_char_set_all (gsl_vector_char * IN_SIZE_OUT, char IN);
int gsl_vector_char_set_basis (gsl_vector_char * IN_SIZE_OUT, size_t i);


int gsl_vector_char_fread (FILE * stream, gsl_vector_char * IN_SIZE_OUT);
int gsl_vector_char_fwrite (FILE * stream, const gsl_vector_char * IN);
int gsl_vector_char_fscanf (FILE * stream, gsl_vector_char * IN_SIZE_OUT);
int gsl_vector_char_fprintf (FILE * stream, const gsl_vector_char * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_char_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_char_reverse (gsl_vector_char * INOUT);

int gsl_vector_char_swap (gsl_vector_char * INOUT, gsl_vector_char * INOUT);


int gsl_vector_char_swap_elements (gsl_vector_char * INOUT, const size_t i, 
			      const size_t j);

#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_vector_char_max (const gsl_vector_char * IN);
double gsl_vector_char_min (const gsl_vector_char * IN);
void gsl_vector_char_minmax (const gsl_vector_char * IN, char * OUTPUT, 
			char * OUTPUT);

size_t gsl_vector_char_max_index (const gsl_vector_char * IN);
size_t gsl_vector_char_min_index (const gsl_vector_char * IN);
void gsl_vector_char_minmax_index (const gsl_vector_char * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

#endif
int gsl_vector_char_isnull(const gsl_vector_char *IN);
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_char_set_zero (gsl_matrix_char  * IN_SIZE_OUT);
void gsl_matrix_char_set_all (gsl_matrix_char * IN_SIZE_OUT, char IN);
void gsl_matrix_char_set_identity (gsl_matrix_char * IN_SIZE_OUT);


int gsl_matrix_char_fread (FILE * stream, gsl_matrix_char * IN_SIZE_OUT);
int gsl_matrix_char_fwrite (FILE * stream, const gsl_matrix_char * IN);
int gsl_matrix_char_fscanf (FILE * stream, gsl_matrix_char * IN_SIZE_OUT);
int gsl_matrix_char_fprintf (FILE * stream, const gsl_matrix_char * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */
int gsl_matrix_char_swap(gsl_matrix_char * INOUT, gsl_matrix_char * INOUT);

int gsl_matrix_char_swap_rows(gsl_matrix_char * INOUT, const size_t i, const size_t j);
int gsl_matrix_char_swap_columns(gsl_matrix_char * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_char_swap_rowcol(gsl_matrix_char * INOUT, const size_t i, const size_t j);
int gsl_matrix_char_transpose (gsl_matrix_char * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_char_transpose_memcpy (gsl_matrix_char * OUT, const gsl_matrix_char * src);
 */
#if !defined(_GSL_BLOCK_COMPLEX_FUNCTIONS)
double gsl_matrix_char_max (const gsl_matrix_char * IN);
double gsl_matrix_char_min (const gsl_matrix_char * IN);
void gsl_matrix_char_minmax (const gsl_matrix_char * IN, char * OUTPUT, char * OUTPUT);

void gsl_matrix_char_max_index (const gsl_matrix_char * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_char_min_index (const gsl_matrix_char * IN, size_t * OUTPUT, size_t *OUTPUT);
void gsl_matrix_char_minmax_index (const gsl_matrix_char * IN, size_t * OUTPUT, 
			      size_t * OUTPUT,size_t * OUTPUT, size_t * OUTPUT);
#endif
int gsl_matrix_char_isnull (const gsl_matrix_char * IN);


gsl_vector_char_view gsl_matrix_char_diagonal(gsl_matrix_char *IN);
gsl_vector_char_view gsl_matrix_char_subdiagonal(gsl_matrix_char *IN, size_t k);
gsl_vector_char_view gsl_matrix_char_superdiagonal(gsl_matrix_char *IN, size_t k);
