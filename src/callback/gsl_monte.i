/* -*- C -*- */
%{
#include <gsl/gsl_monte.h>
#include <gsl/gsl_monte_plain.h>
#include <gsl/gsl_monte_miser.h>
#include <gsl/gsl_monte_vegas.h>
%}

/* Hide the function type in a typedef so that we can use it in all our
   integration functions, and make it easy to change things.
*/

%include gsl_block_special_typemaps.i
%include gsl_rng_typemaps.i
%include file_typemaps.i

%{
#define PyGSL_gsl_monte_function_GET_PARAMS(sys)   \
        (sys)->params;
%}
/* Triggers the above inlined code to convert the callback to a c function */
%apply gsl_function  * STORE {gsl_monte_function *STORE};
%apply gsl_function  * FREE  {gsl_monte_function *FREE};
%inline %{
  gsl_monte_function * gsl_monte_function_init(gsl_monte_function * STORE)
  {
       FUNC_MESS("BEGIN");
       assert(STORE);
       FUNC_MESS("END");
       return STORE;
  }
  void gsl_monte_function_free(gsl_monte_function * FREE)
  {
       ;
  }
%}

%apply gsl_fsolver   * BUFFER {gsl_monte_function     * BUFFER};
%apply gsl_rng * IN {gsl_rng *r}

%apply (const double *, const double *, size_t ) {
     (const double xl[], const double xu[], const size_t dim),
     (double xl[], double xu[], size_t dim)
};


%apply (gsl_error_flag_drop) {gsl_monte_plain_integrate,
		              gsl_monte_plain_init,
			      gsl_monte_miser_integrate,
                              gsl_monte_miser_init,
			      gsl_monte_vegas_integrate,
                              gsl_monte_vegas_init
			 };

gsl_error_flag_drop
gsl_monte_plain_integrate (const gsl_monte_function * BUFFER,
			   const double xl[], const double xu[],
			   const size_t dim,
			   const size_t calls, 
			   gsl_rng * r,
			   gsl_monte_plain_state * state,
                           double *OUTPUT, double *OUTPUT);

gsl_monte_plain_state* gsl_monte_plain_alloc(size_t dim);
gsl_error_flag_drop gsl_monte_plain_init(gsl_monte_plain_state* state);
void gsl_monte_plain_free (gsl_monte_plain_state* state);

%inline %{
     size_t
	  pygsl_monte_miser_get_min_calls(gsl_monte_miser_state * s){
	  return s->min_calls;
     }
     size_t
	  pygsl_monte_miser_get_min_calls_per_bisection(gsl_monte_miser_state * s){
	  return s->min_calls_per_bisection;
     }
     double
	  pygsl_monte_miser_get_dither(gsl_monte_miser_state * s){
	  return s->dither;
     }
     double
	  pygsl_monte_miser_get_estimate_frac(gsl_monte_miser_state * s){
	  return s->estimate_frac;
     }
     double
	  pygsl_monte_miser_get_alpha(gsl_monte_miser_state * s){
	  return s->alpha;
     }

     void
	  pygsl_monte_miser_set_min_calls(gsl_monte_miser_state * s, int NONNEGATIVE){
	   s->min_calls = (size_t) NONNEGATIVE;
     }
     void
	  pygsl_monte_miser_set_min_calls_per_bisection(gsl_monte_miser_state * s, int NONNEGATIVE){
	   s->min_calls_per_bisection = (size_t) NONNEGATIVE;
     }
     void
	  pygsl_monte_miser_set_dither(gsl_monte_miser_state * s, double d){
	   s->dither = d;
     }
     void
	  pygsl_monte_miser_set_estimate_frac(gsl_monte_miser_state * s, double e){
	   s->estimate_frac = e;
     }
     void
	  pygsl_monte_miser_set_alpha(gsl_monte_miser_state * s, double alpha){
	   s->alpha = alpha;
     }
%}
gsl_error_flag_drop
gsl_monte_miser_integrate (gsl_monte_function * BUFFER,
			   double xl[], double xu[],
			   size_t dim,
			   size_t calls, 
			   gsl_rng * r,
			   gsl_monte_miser_state * state,
                           double *OUTPUT, double *OUTPUT);

gsl_monte_miser_state* gsl_monte_miser_alloc(size_t dim);

gsl_error_flag_drop gsl_monte_miser_init(gsl_monte_miser_state* state);

void gsl_monte_miser_free(gsl_monte_miser_state* state);





enum {GSL_VEGAS_MODE_IMPORTANCE = 1, 
      GSL_VEGAS_MODE_IMPORTANCE_ONLY = 0, 
      GSL_VEGAS_MODE_STRATIFIED = -1};

%inline %{
     double pygsl_monte_vegas_get_result(gsl_monte_vegas_state *s){return     s->result    ;}
     double pygsl_monte_vegas_get_sigma(gsl_monte_vegas_state *s){return      s->sigma     ;}
     double pygsl_monte_vegas_get_chisq(gsl_monte_vegas_state *s){return      s->chisq     ;}     
     double pygsl_monte_vegas_get_alpha(gsl_monte_vegas_state *s){return      s->alpha     ;}
     size_t pygsl_monte_vegas_get_iterations(gsl_monte_vegas_state *s){return s->iterations;}
     int    pygsl_monte_vegas_get_stage(gsl_monte_vegas_state *s){return      s->stage     ;}
     int    pygsl_monte_vegas_get_mode(gsl_monte_vegas_state *s){return       s->mode      ;}
     int    pygsl_monte_vegas_get_verbose(gsl_monte_vegas_state *s){return    s->verbose   ;}
     FILE * pygsl_monte_vegas_get_ostream(gsl_monte_vegas_state *s){return    s->ostream   ;}

     void pygsl_monte_vegas_set_result(gsl_monte_vegas_state *s    , double v){      s->result     = v;}
     void pygsl_monte_vegas_set_sigma(gsl_monte_vegas_state *s     , double v){      s->sigma      = v;}
     void pygsl_monte_vegas_set_chisq(gsl_monte_vegas_state *s     , double v){      s->chisq      = v;}     
     void pygsl_monte_vegas_set_alpha(gsl_monte_vegas_state *s     , double v){      s->alpha      = v;}
     void pygsl_monte_vegas_set_iterations(gsl_monte_vegas_state *s, int  NONNEGATIVE){      s->iterations = (size_t) NONNEGATIVE;}
     void pygsl_monte_vegas_set_stage(gsl_monte_vegas_state *s     , int    NONNEGATIVE){      s->stage      = NONNEGATIVE;}
     void pygsl_monte_vegas_set_mode(gsl_monte_vegas_state *s      , int    v){      s->mode       = v;}
     void pygsl_monte_vegas_set_verbose(gsl_monte_vegas_state *s   , int    v){      s->verbose    = v;}
     void pygsl_monte_vegas_set_ostream(gsl_monte_vegas_state *s   , FILE * v){      s->ostream    = v;}

%}
/* xl and xu are of dimension dim */
gsl_error_flag_drop 
gsl_monte_vegas_integrate(gsl_monte_function * BUFFER, 
			  double xl[], double xu[], 
			  size_t dim, size_t calls,
			  gsl_rng * r,
			  gsl_monte_vegas_state *state,
			  double *OUTPUT, double *OUTPUT);


gsl_monte_vegas_state* gsl_monte_vegas_alloc(size_t dim);

gsl_error_flag_drop gsl_monte_vegas_init(gsl_monte_vegas_state* state);

void gsl_monte_vegas_free (gsl_monte_vegas_state* state);




