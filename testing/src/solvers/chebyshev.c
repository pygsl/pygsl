#include <gsl/gsl_chebyshev.h>
const struct _GSLMethods 
chebyshev_f   = { (void_m_t) gsl_cheb_free,   
		  /* gsl_multimin_fminimizer_restart */  (void_m_t) NULL,
		  NULL, NULL};

static int
PyGSL_cheb_init(PyGSL_Solver *self, PyObject *args, PyObject *kw)
{
     ;
}
