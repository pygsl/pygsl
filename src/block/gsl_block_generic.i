/* -*- C -*- */
/**
 * Author: Pierre Schnizer
 */   
/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Vector functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/*
 * The following should mimic the Numeric.ones functions ....
 */
void gsl_vector_set_zero (gsl_vector  * IN_SIZE_OUT);
void gsl_vector_set_all (gsl_vector * IN_SIZE_OUT, double x);
int gsl_vector_set_basis (gsl_vector * IN_SIZE_OUT, size_t i);


int gsl_vector_fread (FILE * stream, gsl_vector * IN_SIZE_OUT);
int gsl_vector_fwrite (FILE * stream, const gsl_vector * IN);
int gsl_vector_fscanf (FILE * stream, gsl_vector * IN_SIZE_OUT);
int gsl_vector_fprintf (FILE * stream, const gsl_vector * IN,
			const char *format);

/*
 * Copy module provides the same 
 * int gsl_vector_memcpy (gsl_vector * INOUT, const gsl_vector * IN);
 */

int gsl_vector_reverse (gsl_vector * INOUT);

int gsl_vector_swap (gsl_vector * INOUT, gsl_vector * INOUT);


int gsl_vector_swap_elements (gsl_vector * INOUT, const size_t i, 
			      const size_t j);

double gsl_vector_max (const gsl_vector * IN);
double gsl_vector_min (const gsl_vector * IN);
void gsl_vector_minmax (const gsl_vector * IN, double * OUTPUT, 
			double * OUTPUT);

size_t gsl_vector_max_index (const gsl_vector * IN);
size_t gsl_vector_min_index (const gsl_vector * IN);
void gsl_vector_minmax_index (const gsl_vector * IN, size_t * OUTPUT, 
			size_t * OUTPUT);

int gsl_vector_isnull(const gsl_vector *IN);


/* -------------------------------------------------------------------------
   -------------------------------------------------------------------------
                     Matrix functions
   -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

/*
 * The following should mimic the Numeric.ones functions ....
 */

void gsl_matrix_set_zero (gsl_matrix  * IN_SIZE_OUT);
void gsl_matrix_set_all (gsl_matrix * IN_SIZE_OUT, double x);
void gsl_matrix_set_identity (gsl_matrix * IN_SIZE_OUT);


int gsl_matrix_fread (FILE * stream, gsl_matrix * IN_SIZE_OUT);
int gsl_matrix_fwrite (FILE * stream, const gsl_matrix * IN);
int gsl_matrix_fscanf (FILE * stream, gsl_matrix * IN_SIZE_OUT);
int gsl_matrix_fprintf (FILE * stream, const gsl_matrix * IN,
			const char *format);

/*
 * int gsl_matrix_memcpy(gsl_matrix * dest, const gsl_matrix * src);
 */

int gsl_matrix_swap(gsl_matrix * INOUT, gsl_matrix * INOUT);

int gsl_matrix_swap_rows(gsl_matrix * INOUT, const size_t i, const size_t j);
int gsl_matrix_swap_columns(gsl_matrix * INOUT, const size_t i, 
			    const size_t j);
int gsl_matrix_swap_rowcol(gsl_matrix * INOUT, const size_t i, const size_t j);
int gsl_matrix_transpose (gsl_matrix * INOUT);

/*
 * Need a proper typemap for that
 * int gsl_matrix_transpose_memcpy (gsl_matrix * OUT, const gsl_matrix * src);
 */

double gsl_matrix_max (const gsl_matrix * IN);
double gsl_matrix_min (const gsl_matrix * IN);
void gsl_matrix_minmax (const gsl_matrix * IN, double * OUTPUT, double * OUTPUT);

void gsl_matrix_max_index (const gsl_matrix * IN, size_t * OUTPUT, size_t * OUTPUT);
void gsl_matrix_min_index (const gsl_matrix * IN, size_t * OUTPUT, size_t * OUTPUT);
void gsl_matrix_minmax_index (const gsl_matrix * IN, size_t * OUTPUT, 
			      size_t * OUTPUT, size_t * OUTPUT, size_t * OUTPUT);

int gsl_matrix_isnull (const gsl_matrix * IN);


gsl_vector_view gsl_matrix_diagonal(gsl_matrix *IN);
gsl_vector_view gsl_matrix_subdiagonal(gsl_matrix *IN, size_t k);
gsl_vector_view gsl_matrix_superdiagonal(gsl_matrix *IN, size_t k);
