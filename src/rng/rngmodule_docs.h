static char rng_module_doc[] =
"GSL Random-number generators implemented as C extension types.\n\
\n\
Use rng(Random-number generator types) to create an instance of a new\n\
random generator. All known random generator types are listed below. The\n\
different distributions are methods of the random generator instances.\n\
Consult the GSL manual for full details.\n\
\n\
    Random-number generator types\n\
borosh13\n\
cmrg\n\
coveyou\n\
fishman18\n\
fishman20\n\
fishman2x\n\
gfsr4\n\
knuthran\n\
knuthran2\n\
lecuyer21\n\
minstd\n\
mrg\n\
mt19937\n\
mt19937_1999\n\
r250\n\
ran0\n\
ran1\n\
ran2\n\
ran3\n\
rand\n\
rand48\n\
random128_bsd\n\
random128_glibc2\n\
random128_libc5\n\
random256_bsd\n\
random256_glibc2\n\
random256_libc5\n\
random32_bsd\n\
random32_glibc2\n\
random32_libc5\n\
random64_bsd\n\
random64_glibc2\n\
random64_libc5\n\
random8_bsd\n\
random8_glibc2\n\
random8_libc5\n\
random_bsd\n\
random_glibc2\n\
random_libc5\n\
randu\n\
ranf\n\
ranlux\n\
ranlux389\n\
ranlxd1\n\
ranlxd2\n\
ranlxs0\n\
ranlxs1\n\
ranlxs2\n\
ranmar\n\
slatec\n\
taus\n\
taus2\n\
taus113\n\
transputer\n\
tt800\n\
uni\n\
uni32\n\
vax\n\
waterman14\n\
zuf\n";

static char rng_doc[]= 
"RNG Object Constructor\n\
Usage:\n\
rng(rng_type)\n\
Input:\n\
     rng_type ... one of the many rng types GSL provides.\n\
";

static char rng_type_doc[]=
"A PyGSL encapsulation of a GSL random number generator\n\
Try help(<your_instance>.method) to get more information about the method\n\
in question.\n\
\n\
\n\
Methods:\n\
  Basic methods:\n\
    __copy__ returns a copy of this instance\n\
    clone    \n\
    get\n\
    max\n\
    min\n\
    name\n\
    set\n\
\n\
  Random distributions:\n\
    bernoulli\n\
    beta\n\
    binomial\n\
    bivariate_gaussian\n\
    cauchy\n\
    chisq\n\
    dir_2d\n\
    dir_2d_trig_method\n\
    dir_3d\n\
    dir_nd\n\
    dirichlet\n\
    erlang\n\
    exponential\n\
    exppow\n\
    fdist\n\
    flat\n\
    gamma\n\
    gamma_int\n\
    gaussian\n\
    gaussian_ratio_method\n\
    gaussian_tail\n\
    geometric\n\
    gumbel1\n\
    gumbel2\n\
    hypergeometric\n\
    landau\n\
    laplace\n\
    levy\n\
    levy_skew\n\
    logarithmic\n\
    logistic\n\
    lognormal\n\
    multinomial\n\
    negative_binomial\n\
    pareto\n\
    pascal\n\
    poisson\n\
    rayleigh\n\
    rayleigh_tail\n\
    tdist\n\
    ugaussian\n\
    ugaussian_ratio_method\n\
    ugaussian_tail\n\
    uniform\n\
    uniform_int\n\
    uniform_pos\n\
    weibull\n";

#define RNG_ARRAY_ITERATE  "\n x can be an array. In this case this function\
 will iterate over it and\nreturn an array of p(x).\n"

#define RNG_ARRAY_INTEGER_ITERATE  "\n k can be an array. In this case this function\
 will iterate over it and\nreturn an array of p(k).\n"

#define RNG_ARRAY  "\n If the optional paramter n is given, this method will\
 return a sample\nof size n.\n"

static char rng_clone_doc [] = "Returns a clone of this instance\n";
static char rng_set_doc[] = 
"Initalises (seeds) the random number generator.\n\
Usage:\n\
  set(seed)\n";


static char rng_get_doc[] = 
"Returns a random integer.\n\
Usage:\n\
  get((n))\n"  RNG_ARRAY_ITERATE;

static char rng_uniform_doc [] = 
"Returns a double precision floating point number uniformly distributed\n\
in the range [0,1).  The range includes 0.0 but excludes 1.0.\n\
Usage:\n\
   uniform((n))\n" RNG_ARRAY_ITERATE;


static char rng_uniform_pos_doc [] = 
"Returns a double precision floating point number uniformly distributed\n\
in the range (0,1).  The range excludes 0.0 and 1.0.\n\
Usage:\n\
   uniform_pos((n))\n" RNG_ARRAY_ITERATE;


static char rng_uniform_int_doc [] = 
"Returns an integer between 0 and M-1\n\
Usage:\n\
   uniform(M, (n))\n" RNG_ARRAY_ITERATE;

static char rng_max_doc [] = "Returns the larget value that the get method can return\n";
static char rng_min_doc [] = "Returns the smallest value that the get method can return\n";

static char rng_gaussian_doc[] =
"Returns a Gaussian random variate, with mean zero and standard deviation\n\
SIGMA. Use the transformation z =mu + x on the numbers returned by this\n\
method to obtain a Gaussian distribution with mean mu.  This function\n\
uses the Box-Mueller algorithm which requires two calls to the random\n\
number generator R.\n\
\n\
Usage:\n\
gaussian(sigma, (n))\n" RNG_ARRAY;

static char rng_gaussian_pdf_doc[]=
"Computes the probability density p(x) at x for a Gaussian distribution\n\
with  standard deviation SIGMA\n\
Usage:\n\
p = gaussian_pdf(x, sigma)\n\
\n" RNG_ARRAY_ITERATE;

static char rng_gaussian_ratio_doc [] = 
"Computes a gaussian random variate using the Kinderman-Monahan ratio\n\
method. See the gaussian method for usage details.\n";

static char rng_ugaussian_ratio_doc [] = 
"Computes a gaussian random variate using the Kinderman-Monahan ratio\n\
method. See the ugaussian method for usage details.\n";

static char rng_ugaussian_doc[] =
"Returns a Gaussian random variate, with mean zero and standard deviation\n\
SIGMA = 1. Use the transformation z =mu + x on the numbers returned by this\n\
method to obtain a Gaussian distribution with mean mu.  This function\n\
uses the Box-Mueller algorithm which requires two calls to the random\n\
number generator R.\n\
\n\
Usage:\n\
   ugaussian((n))\n" RNG_ARRAY;

static char rng_ugaussian_pdf_doc[] =
"Computes the probability density p(x) at x for a Gaussian distribution\n\
 with  standard deviation SIGMA=1\n\
 Usage:\n\
 p = ugaussian_pdf(x)\n\
\n"  RNG_ARRAY_ITERATE;

static char rng_gaussian_tail_doc [] =
"This method provides random variates from the upper tail of a Gaussian\n\
distribution with standard deviation SIGMA.  The values returned are\n\
larger than the lower limit A, which must be positive.  The method is\n\
based on Marsaglia's famous rectangle-wedge-tail algorithm.\n\
 Usage:\n\
 p = gaussian_tail(a, sigma, (n))\n\
\n"  RNG_ARRAY;


static char rng_ugaussian_tail_doc [] =
"This method provides random variates from the upper tail of a Gaussian\n\
distribution with standard deviation SIGMA=1.  The values returned are\n\
larger than the lower limit A, which must be positive.  The method is\n\
based on Marsaglia's famous rectangle-wedge-tail algorithm.\n\
 Usage:\n\
 p = gaussian_tail(a, (n))\n\
\n"  RNG_ARRAY;

static char rng_gaussian_tail_pdf_doc[] = 
"Computes the probability density p(x) at X for a Gaussian tail\n\
 distribution with standard deviation SIGMA and lower limit A\n\
 Usage:\n\
 p = gaussian_tail_pdf(x, a, sigma)\n\
\n" RNG_ARRAY_ITERATE;

static char rng_ugaussian_tail_pdf_doc[] = 
"Computes the probability density p(x) at X for a Gaussian tail\n\
 distribution with standard deviation SIGMA=1 and lower limit A\n\
 Usage:\n\
 p = gaussian_tail_pdf(x, a, sigma)\n\
\n" RNG_ARRAY_ITERATE;

static char rng_bivariate_gaussian_doc [] = 
"This method generates a pair of correlated gaussian variates,\n\
with mean zero, correlation coefficient RHO and standard deviations\n\
SIGMA_X and SIGMA_Y in the x and y directions.\n\
Usage:\n\
x, y = bivariate_gaussian(sigma_x, sigma_y, rho, (n)\n" RNG_ARRAY_ITERATE;

static char rng_bivariate_gaussian_pdf_doc[] = 
"Computes the probability density p(x,y) at (X,Y) for a bivariate\n\
gaussian distribution with standard deviations SIGMA_X, SIGMA_Y\n\
and correlation coefficient RHO\n\
Usage :\n\
p_x, p_y = bivariate_gaussian_pdf(x, y, sigma_x, sigma_y, rho)\n\
\n\
If x and y are arrays, the function will iterate over them and return\n\
arrays\n";

static char rng_exponential_doc [] = 
"This method returns a random variate from the exponential distribution\n\
 with mean MU.\n\
Usage:\n\
  exponential(mu, (n))\n" RNG_ARRAY;

static char rng_exponential_pdf_doc [] =
"Computes the probability density p(x) at X for an exponential\n\
distribution with mean MU\n\
Usage:\n\
p = exponential_pdf(x, mu)\n" RNG_ARRAY_ITERATE;

static char rng_laplace_doc [] = 
"This method returns a random variate from the laplace distribution\n\
 with witdh A.\n\
Usage:\n\
  laplace(a, (n))\n" RNG_ARRAY;

static char rng_laplace_pdf_doc [] = 
"Computes the probability density p(x) at X for a Laplace distribution\n\
with mean A\n\
Usage:\n\
p = laplace_pdf(x, a)\n" RNG_ARRAY_ITERATE;

static char rng_exppow_doc [] = 
"This method returns a random variate from the exponential power\n\
distribution with scale parameter A and exponent B.\n\
Usage:\n\
  exponential(a, b, (n))\n" RNG_ARRAY;

static char rng_exppow_pdf_doc [] = 
"Computes the probability density p(x) at X for an exponential power\n\
distribution with scale parameter A and exponent B\n\
Usage:\n\
p = exppow_pdf(x, a, b)\n"  RNG_ARRAY_ITERATE;


static char rng_cauchy_doc [] = 
"This method returns  a random variate from the Cauchy distribution\n\
with scale parameter A.\n\
Usage:\n\
  cauchy(a, (n))\n" RNG_ARRAY;

static char rng_cauchy_pdf_doc [] =
"Computes the probability density p(x) at X for a Cauchy distribution\n\
with scale parameter A\n\
Usage:\n\
p = cauchy_pdf(x, a)\n" RNG_ARRAY_ITERATE;

static char rng_rayleigh_doc [] = 
"This method returns  a random variate from the Rayleigh distribution\n\
with scale parameter SIGMA.\n\
Usage:\n\
  rayleigh(sigma, (n))\n" RNG_ARRAY;

static char rng_rayleigh_pdf_doc [] = 
"Computes the probability density p(x) at X for a Rayleigh distribution\n\
with scale parameter SIGMA\n\
Usage:\n\
p = rayleigh_pdf(x, a, sigma)\n" RNG_ARRAY_ITERATE;

static char rng_rayleigh_tail_doc [] = 
"This method returns  a random variate from the Rayleigh tail\n\
distribution with scale parameter SIGMA and a lower limit A.\n\
Usage:\n\
  rayleigh_tail(a, sigma, (n))\n" RNG_ARRAY;

static char rng_rayleigh_tail_pdf_doc [] = 
"Computes the probability density p(x) at X for a Rayleigh tail\n\
distribution with scale parameter SIGMA and lower limit A.\n\
Usage:\n\
p = rayleigh_tail_pdf(x, a, sigma)" RNG_ARRAY_ITERATE;

static char rng_landau_doc [] = 
"This method returns  a random variate from the Landau distribution\n\
Usage:\n\
  landau((n))\n" RNG_ARRAY;

static char rng_landau_pdf_doc [] = 
"Computes the probability density p(x) at X for the Landau distribution\n\
using an approximation.\n\
Usage:\n\
p = landau_pdf(x)" RNG_ARRAY_ITERATE;


static char rng_levy_doc [] = 
"This method returns a random variate from the Levy symmetric stable\n\
distribution with scale C and exponent ALPHA. The algorithm only works\n\
for 0 < alpha <= 2. There is no 'pdf' implemented\n\
Usage:\n\
  levy(c, alpha, (n))\n" RNG_ARRAY;

static char rng_levy_skew_doc [] = 
"This method returns a random variate from the Levy skew stable\n\
distribution with scale C, exponent ALPHA and skewness parameter BETA.\n\
The skewness parameter must lie in the range [-1,1].\n\
Usage:\n\
  levy_skew(c, alpha, beta, (n))\n" RNG_ARRAY;


static char rng_gamma_doc [] = 
"This method returns  a random variate from the gamma distribution\n\
Usage:\n\
  gamma(a, b, (n))\n" RNG_ARRAY;

static char rng_gamma_pdf_doc [] = 
"Computes the probability density p(x) at X for the gamma distribution\n\
Usage:\n\
p = gamma_pdf(x, a, b)" RNG_ARRAY_ITERATE;


static char rng_flat_doc [] = 
"This method returns  a random variate from the flat (uniform)\n\
 distribution from A to B.\n\
Usage:\n\
  flat(a, b, (n))\n" RNG_ARRAY;

static char rng_flat_pdf_doc [] = 
"Computes the probability density p(x) at X for the flat (uniform) distribution\n\
Usage:\n\
p = flat_pdf(x, a, b)" RNG_ARRAY_ITERATE;


static char rng_lognormal_doc [] = 
"This method returns  a random variate from the log normal distribution.\n\
Usage:\n\
  flat(zeta, sigma, (n))\n" RNG_ARRAY;

static char rng_lognormal_pdf_doc [] = 
"Computes the probability density p(x) at X for the log normal distribution\n\
Usage:\n\
p = lognormal_pdf(x, zeta, sigma)" RNG_ARRAY_ITERATE;


static char rng_chisq_doc [] = 
"This method returns a random variate from the chi-squared distribution\n\
with NU degrees of freedom\n\
Usage:\n\
  chisq(nu, (n))\n" RNG_ARRAY;

static char rng_chisq_pdf_doc [] = 
"Computes the probability density p(x) at X for the chisq distribution\n\
Usage:\n\
p = chisq_pdf(x, nu)" RNG_ARRAY_ITERATE;


/* Update number of variables !!! */
static char rng_fdist_doc [] = 
"This method returns a random variate from the F-distribution\n\
distribution with degrees of freedom NU\n\
Usage:\n\
  fdist(nu, (n))\n" RNG_ARRAY;

static char rng_fdist_pdf_doc [] = 
"Computes the probability density p(x) at X for the F-distribution\n\
with NU  degrees of freedom.\n\
Usage:\n\
p = fdist_pdf(x, nu1)" RNG_ARRAY_ITERATE;

static char rng_tdist_doc [] = 
"This method returns a random variate from the t-distribution\n\
distribution with degrees of freedom NU1 and NU2\n\
Usage:\n\
  tdist(nu1, nu2, (n))\n" RNG_ARRAY;

static char rng_tdist_pdf_doc [] = 
"Computes the probability density p(x) at X for the t-distribution\n\
with NU1 and NU2 degrees of freedom.\n\
Usage:\n\
p = tdist_pdf(x, nu1, nu2)" RNG_ARRAY_ITERATE;


static char rng_beta_doc [] = 
"This method returns a random variate from the beta distribution\n\
Usage:\n\
  beta(a, b, (n))\n" RNG_ARRAY;

static char rng_beta_pdf_doc [] = 
"Computes the probability density p(x) at X for the beta distribution\n\
Usage:\n\
p = beta_pdf(x, a, b)" RNG_ARRAY_ITERATE;


static char rng_logistic_doc [] = 
"This method returns a random variate from the logistic distribution\n\
Usage:\n\
  logistic(a, (n))\n" RNG_ARRAY;

static char rng_logistic_pdf_doc [] = 
"Computes the probability density p(x) at X for the logistic distribution\n\
Usage:\n\
p = logistic_pdf(x, a)" RNG_ARRAY_ITERATE;

static char rng_pareto_doc [] = 
"This method returns a random variate from the pareto distribution\n\
Usage:\n\
  pareto(a, b, (n))\n" RNG_ARRAY;

static char rng_pareto_pdf_doc [] = 
"Computes the probability density p(x) at X for the pareto distribution\n\
with exponent a and scale b\n\
Usage:\n\
p = pareto_pdf(x, a)" RNG_ARRAY_ITERATE;


static char rng_dir_2d_doc [] = 
"This method returns a random direction vector v = (X,Y) in two\n\
 dimensions.\n\
Usage:\n\
  dir_2d((n))\n" RNG_ARRAY;

static char rng_dir_2d_trig_method_doc [] = 
"This method returns a random direction vector v = (X,Y) in two\n\
 dimensions using trigonometric functions internally.\n\
Usage:\n\
  dir_2d_trig_method((n))\n" RNG_ARRAY;


static char rng_dir_3d_doc [] = 
"This method returns a random direction vector v = (X,Y,Z) in three\n\
 dimensions.\n\
Usage:\n\
  dir_3d((n))\n" RNG_ARRAY;


static char rng_dir_nd_doc [] = 
"This method returns a random direction vector v = (x1, ..., xn) in three\n\
 dimensions.\n\
Usage:\n\
  dir_nd((n))\n" RNG_ARRAY;


static char rng_weibull_doc [] = 
"This method returns a random variate from the weibull distribution\n\
with scale a and exponent b\n\
Usage:\n\
  weibull(a, b, (n))\n" RNG_ARRAY;

static char rng_weibull_pdf_doc [] = 
"Computes the probability density p(x) at X for the weibull distribution\n\
with scale a and exponent b\n\
Usage:\n\
p = weibull_pdf(x, a)" RNG_ARRAY_ITERATE;


static char rng_gumbel1_doc [] = 
"This method returns a random variate from the gumbel1 distribution\n\
with parametes a and b\n\
Usage:\n\
  gumbel1(a, b, (n))\n" RNG_ARRAY;

static char rng_gumbel1_pdf_doc [] = 
"Computes the probability density p(x) at X for the gumbel1 distribution\n\
with parameters a and b \n\
Usage:\n\
p = gumbel1_pdf(x, a, b)" RNG_ARRAY_ITERATE;

static char rng_gumbel2_doc [] = 
"This method returns a random variate from the gumbel2 distribution\n\
with parametes a and b\n\
Usage:\n\
  gumbel2(a, b, (n))\n" RNG_ARRAY;

static char rng_gumbel2_pdf_doc [] = 
"Computes the probability density p(x) at X for the gumbel2 distribution\n\
with parameters a and b \n\
Usage:\n\
p = gumbel2_pdf(x, a, b)" RNG_ARRAY_ITERATE;

static char rng_dirichlet_doc [] = 
"This method returns an array of K random variates from a Dirichlet\n\
distribution of order K-1\n\
Usage:\n\
p(theta_1, ..., theta_k) = dirchlet(alpha, (n))\n\
alpha must be of length k" RNG_ARRAY;

static char rng_dirichlet_pdf_doc [] = 
" Computes the probability density p(\theta_1, ... ,  \theta_K) at\n\
THETA[K] for a Dirichlet distribution with parameters\n\
ALPHA[K]\n\
Usage:\n";

static char rng_dirichlet_lnpdf_doc [] = 
" Computes logarithmic of the probability density\n\
 p(\theta_1, ... ,  \theta_K) at THETA[K] for a Dirichlet distribution\n\
 with parameters ALPHA[K]\n\
Usage:\n";

static char rng_poisson_doc [] = 
"This method returns a random integer from the poisson distribution\n\
with mean MU\n\
Usage:\n\
  poisson(mu, (n))\n" RNG_ARRAY;

static char rng_poisson_pdf_doc [] = 
"Computes the probability density p(k) at k for the poisson distribution\n\
with mean MU \n\
Usage:\n\
p = poisson_pdf(k, mu)" RNG_ARRAY_INTEGER_ITERATE;


static char rng_bernoulli_doc [] = 
"This method returns either 0 or 1, the result of a Bernoulli trial with\n\
probability P.\n\
Usage:\n\
  bernoulli(p, (n))\n" RNG_ARRAY;

static char rng_bernoulli_pdf_doc [] = 
"Computes the probability density p(k) at k for the bernoulli\n\
distribution with probability parameter P.\n\
Usage:\n\
p = bernoulli_pdf(k, P)" RNG_ARRAY_INTEGER_ITERATE;

static char rng_binomial_doc [] = 
"This method returns a random integer from the binomial distribution,\n\
the number of successes in N independent trials with probability P\n\
Usage:\n\
  binomial(P, N, (n))\n" RNG_ARRAY;

static char rng_binomial_pdf_doc [] = 
"Computes the probability density p(k) of obtaining K from a\n\
  binomial distribution with parameters P and N\n\
Usage:\n\
p = binomial_pdf(k, P, N)" RNG_ARRAY_INTEGER_ITERATE;


static char rng_negative_binomial_doc [] = 
"This method returns a random integer from the negative binomial\n\
 distribution, the number of failures in N independent trials with\n\
 probability P. Note: N is not required to be an integer\n\
Usage:\n\
  negative_binomial(P, N, (n))\n" RNG_ARRAY;

static char rng_negative_binomial_pdf_doc [] = 
"Computes the probability density p(k) of obtaining K from a\n\
  negative binomial distribution with parameters P and N.\n\
Usage:\n\
p = negative_binomial_pdf(k, P, N)" RNG_ARRAY_INTEGER_ITERATE;



static char rng_pascal_doc [] = 
"This method returns a random integer from the pascal distribution\n\
Usage:\n\
  pascal(P, K, (n))\n" RNG_ARRAY;

static char rng_pascal_pdf_doc [] = 
"Computes the probability density p(k) of obtaining K from a\n\
  pascal distribution with parameters P and N\n\
Usage:\n\
p = pascal_pdf(k, P, N)" RNG_ARRAY_INTEGER_ITERATE;



static char rng_geometric_doc [] = 
"This method returns a random integer from the geometric distribution\n\
Usage:\n\
  geometric(P, (n))\n" RNG_ARRAY;

static char rng_geometric_pdf_doc [] = 
"Computes the probability density p(k) of obtaining K from a\n\
  geometric distribution with parameters P\n\
Usage:\n\
p = geometric_pdf(k, P)" RNG_ARRAY_INTEGER_ITERATE;




static char rng_hypergeometric_doc [] = 
"This method returns a random integer from the hypergeometric distribution\n\
Usage:\n\
  hypergeometric(N1, N2, N3, (n))\n" RNG_ARRAY;

static char rng_hypergeometric_pdf_doc [] = 
"Computes the probability density p(k) of obtaining K from a\n\
  hypergeometric distribution with parameters  N1, N2, N3\n\
Usage:\n\
p = hypergeometric_pdf(k, n1, n2, n3)" RNG_ARRAY_INTEGER_ITERATE;


static char rng_logarithmic_doc [] = 
"This method returns a random integer from the logarithmic distribution\n\
Usage:\n\
  logarithmic(P, K, (n))\n" RNG_ARRAY;

static char rng_logarithmic_pdf_doc [] = 
"Computes the probability density p(k) of obtaining K from a\n\
  logarithmic distribution with parameters P and N\n\
Usage:\n\
p = logarithmic_pdf(k, P, N)" RNG_ARRAY_INTEGER_ITERATE;

static char multinomial_doc [] =
"samples from the multinomial distribution parametrized\n\
by 'phi' and 'k'\n\
Usage:\n\
multinomial(phi, k, N)" RNG_ARRAY;

static char multinomial_pdf_doc [] =
"Computes the probability P(n_1, n_2, ..., n_K) of sampling N[K]\n\
 from a multinomial distribution with parameters \n\
 P[K].\n\
Usage:\n\
p = multinomial_pdf(phi, n)\n\
\n\
phi ... probability distribution over possible events.\n\
n   ... an two dimensional array, where each pdf is stored in one row\n\
";
