#ifndef PyGSL_MULTIMINMODULE_DOC_H
#define PyGSL_MULTIMINMODULE_DOC_H

static const char PyGSL_multimin_type_doc[] = "\
Multidimensional Minimizer object.\n\
\n\
Usage:\n\
     (n) \n\
     n ... dimension of the problem\n\
\n\
     Methods:\n\
     set()\n\
     iterate()\n\
     x()\n\
     name()\n\
     type()\n\
\n\
Generate a object and use dir() to get a full list of available methods!\
";
static const char PyGSL_multimin_module_doc[] = "\
Wrapper for the multidimensional Minimisers as provided by GSL\n\
\n\
The problem of multidimensional minimization requires finding a point x\n\
such that the scalar function,\n\
\n\
     f(x_1, ..., x_n)\n\
\n\
takes a value which is lower than at any neighboring point. For smooth\n\
functions the gradient g = \nabla f vanishes at the minimum. In general\n\
there are no bracketing methods available for the minimization of\n\
n-dimensional functions.  All algorithms proceed from an initial guess\n\
using a search algorithm which attempts to move in a downhill direction.\n\
\n\
   All algorithms making use of the gradient of the function perform a\n\
one-dimensional line minimisation along this direction until the lowest\n\
point is found to a suitable tolerance.  The search direction is then\n\
updated with local information from the function and its derivatives,\n\
and the whole process repeated until the true n-dimensional minimum is\n\
found.\n\
\n\
   The Nelder-Mead Simplex algorithm applies a different strategy.  It\n\
maintains n+1 trial parameter vectors as the vertices of a\n\
n-dimensional simplex.  In each iteration step it tries to improve the\n\
worst vertex by a simple geometrical transformation until the size of\n\
the simplex falls below a given tolerance.\n\
\n\
   Several minimization algorithms are available within a single\n\
framework. The user provides a high-level driver for the algorithms, and\n\
the library provides the individual functions necessary for each of the\n\
steps.  There are three main phases of the iteration.  The steps are,\n\
\n\
   * initialize the minimizer m for the choosen algorithm.\n\
   * update m using the iteration method\n\
   * test m for convergence, and repeat iteration if necessary\n\
";
#define PyGSL_INIT_USAGE_DOC  "\nUsage <name>(n):\n     n ... Dimensions of the problem\n\nSee the GSL reference document for a more detailed description of the\nalghoritm."

static const char  nmsimplex_doc[] = "\
The Simplex algorithm of Nelder and Mead." 
PyGSL_INIT_USAGE_DOC;

static const char  conjugate_fr_doc[]= "\
This is the Fletcher-Reeves conjugate gradient algorithm."
PyGSL_INIT_USAGE_DOC;
static const char  vector_bfgs_doc[]     = "\
This is the vector Broyden-Fletcher-Goldfarb-Shanno (BFGS)\n\
conjugate gradient algorithm"
PyGSL_INIT_USAGE_DOC;
static const char  conjugate_pr_doc[]    = "\
This is the Polak-Ribiere conjugate gradient algorithm."
PyGSL_INIT_USAGE_DOC;

static const char  steepest_descent_doc[]    = "\
The steepest descent algorithm follows the downhill gradient of the\n\
function at each step.  The steepest descent method is inefficient and\n\
 is included only for demonstration purposes."
PyGSL_INIT_USAGE_DOC;

static const char  test_gradient_doc[]       = "\
Usage: test_gradient(g, epsabs)\n\
       g       ... a vector \n\
       epsabs  ... a python float\n\
\n\
This function tests the norm of the gradient g against the\n\
absolute tolerance epsabs. The gradient of a multidimensional\n\
function goes to zero at a minimum. The test returns `GSL_SUCCESS'\n\
if the following condition is achieved,\n\
\n\
          |g| < epsabs\n\
\n\
and returns `GSL_CONTINUE' otherwise.";
static const char  test_size_doc[]   = "\
Usage: test_size(size, epsabs)\n\
       size   ... a python float\n\
       epsabs ... a python float\n\
This function tests the minimizer specific characteristic size (if\n\
applicable to the used minimizer) against absolute tolerance\n\
epsabs.  The test returns `GSL_SUCCESS' if the size is smaller\n\
than tolerance, otherwise `GSL_CONTINUE' is returned.\n\
";

static const char multimin_x_doc[]        ="\
Get the current best estimate for the location of minimum!";
static const char multimin_minimum_doc[]  ="\
Get the current best estimate for the value of minimum!";
static const char multimin_name_doc[]     ="\
 Get the name of the solver";
static const char multimin_iterate_doc[]  ="\
Perform one iteration to update the state of the minimizer";
static const char multimin_istype_doc[]   = "\
Return the type of the minimizer: F-Minimizer of Fdf-Minimizer";


static const char multimin_set_f_doc[]         = "\
Usage: set(f, par, x, steps):\n\
     f     ... a function of\n\
                 def f(x, par):\n\
                    return y\n\
     x     ... start vector\n\
     par   ... paramters to pass to the function f\n\
     steps ... initial steps vector\n\
";
static const char multimin_size_doc[]          = "Get the size of the minimizer";
static const char multimin_test_size_doc[]     = "\
Usage: test_size(epsabs)\n\
       size   ... a python float\n\
 This function tests the minimizer specific characteristic size (if\n\
 applicable to the used minimizer) against absolute tolerance\n\
 epsabs.  The test returns `GSL_SUCCESS' if the size is smaller\n\
 than tolerance, otherwise `GSL_CONTINUE' is returned.\n\
";

static const char multimin_set_fdf_doc[]       = "\
Usage: set(f, df, fdf, par, x, step_size, tol):\n\
     f    ... a function of\n\
                 def f(x, par):\n\
                    return y\n\
     df   ... a function of\n\
                 def f(x, par):\n\
                    return dy/dx[0] ... dy/dx[n]\n\
     fdf  ... allows to calculate f and df in one go\n\
     x    ... start vector\n\
     par  ... paramters to pass to the function f\n\
     step ... size of the first step\n\
     tol  ... accuracy of the line minimization\n\
";
static const char multimin_restart_doc[]       = "\
Resets the minimizer S to use the current point as a new starting point.";
static const char multimin_dx_doc[]            = "\
Get dx at the current point";
static const char multimin_gradient_doc[]      = "\
Get the gradient at the current point";
static const char multimin_test_gradient_doc[] = "\
Usage: test_gradient(epsabs)\n\
       epsabs  ... a python float\n\
\n\
This function tests the norm of the gradient g against the\n\
absolute tolerance epsabs. The gradient of a multidimensional\n\
function goes to zero at a minimum. The test returns `GSL_SUCCESS'\n\
if the following condition is achieved,\n\
\n\
          |g| < epsabs\n\
\n\
     and returns `GSL_CONTINUE' otherwise";
#endif /* PyGSL_MULTIMINMODULE_DOC_H */
