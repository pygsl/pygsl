/*
 * File Included by the rng module. The following 43 distributions only use a 
 * small amount of different internal functions. These functions can be found 
 * in the pygsl library.
 *
 * These macro calls are used to generate
 *        -- the distribution methods of the rng.
 *       -- the probability density functions for the rng module.
 *
 * Naming conventions:
 *              *_to_* ... seperates the input argument types from the output 
 *                         argument types. 
 *              d      ... a double argument
 *              double ... a double argument
 *              ui     ... a unsigned int argument
 *              A      ... a array argument. It is a suffix to the 
 *                         type argument.
 *
 *   So d_to_double is a short cut for the following c type:
 *           double (*)(gsl_rng *, double)
 *
 *   The probability density functions use the description of the corresponding
 *   distribution.
 *
 * Statistics:
 *    List of how many different distributions use the same evaluator.
 *           NAME             CALLS   TYPE
 *    	    to_double         3
 *    	    to_dd             2
 *    	    to_ddd            1   
 *    	    to_nd             1   
 *    	  d_to_double        10
 *    	 dd_to_double        14
 *    	ddd_to_double         1
 *    	ddd_to_dd             1
 *    	 ui_to_double         1
 *    	  d_to_ui             4
 *    	 dd_to_ui             1
 *    	 dA_to_dA             1
 *   uiuiui_to_ui             1
 *     uidA_to_uiA            1  
 */ 
RNG_DISTRIBUTION(gaussian,               d_to_double)
#ifndef RNG_GENERATE_PDF
RNG_DISTRIBUTION(gaussian_ratio_method,  d_to_double)
#endif
RNG_DISTRIBUTION(ugaussian,              to_double)
#ifndef RNG_GENERATE_PDF
RNG_DISTRIBUTION(ugaussian_ratio_method, to_double)
#endif
RNG_DISTRIBUTION(gaussian_tail,          dd_to_double)
RNG_DISTRIBUTION(ugaussian_tail,         d_to_double)
RNG_DISTRIBUTION(bivariate_gaussian,     ddd_to_dd)
RNG_DISTRIBUTION(exponential,            d_to_double)
RNG_DISTRIBUTION(laplace,                d_to_double)
RNG_DISTRIBUTION(exppow,                 dd_to_double)
RNG_DISTRIBUTION(cauchy,                 d_to_double)
RNG_DISTRIBUTION(rayleigh,               d_to_double)
RNG_DISTRIBUTION(rayleigh_tail,          dd_to_double)
#ifndef RNG_GENERATE_PDF
RNG_DISTRIBUTION(levy,                   dd_to_double)
RNG_DISTRIBUTION(levy_skew,              ddd_to_double)
#endif
RNG_DISTRIBUTION(gamma,                  dd_to_double)
#ifndef RNG_GENERATE_PDF
RNG_DISTRIBUTION(gamma_int,              ui_to_double)
#endif
RNG_DISTRIBUTION(flat,                   dd_to_double)
RNG_DISTRIBUTION(lognormal,              dd_to_double)
RNG_DISTRIBUTION(chisq,                  d_to_double)
RNG_DISTRIBUTION(fdist,                  dd_to_double)
RNG_DISTRIBUTION(tdist,                  d_to_double)
RNG_DISTRIBUTION(beta,                   dd_to_double)
RNG_DISTRIBUTION(logistic,               d_to_double)
RNG_DISTRIBUTION(pareto,                 dd_to_double)
					 
#ifndef RNG_GENERATE_PDF
/* These distributions do not provide a probabillity density function. */
RNG_DISTRIBUTION(dir_2d,                 to_dd)
RNG_DISTRIBUTION(dir_2d_trig_method,     to_dd)
RNG_DISTRIBUTION(dir_3d,                 to_ddd)
RNG_DISTRIBUTION(dir_nd,                 to_nd)
#endif
RNG_DISTRIBUTION(weibull,                dd_to_double)
RNG_DISTRIBUTION(gumbel1,                dd_to_double)
RNG_DISTRIBUTION(gumbel2,                dd_to_double)
RNG_DISTRIBUTION(poisson,                d_to_ui)
RNG_DISTRIBUTION(bernoulli,              d_to_ui)
RNG_DISTRIBUTION(binomial,               dui_to_ui)
RNG_DISTRIBUTION(negative_binomial,      dd_to_ui)
RNG_DISTRIBUTION(pascal,                 dui_to_ui)
RNG_DISTRIBUTION(geometric,              d_to_ui)
RNG_DISTRIBUTION(logarithmic,            d_to_ui)
RNG_DISTRIBUTION(landau,                 to_double)
RNG_DISTRIBUTION(erlang,                 dd_to_double)
RNG_DISTRIBUTION(hypergeometric,         uiuiui_to_ui)
RNG_DISTRIBUTION(dirichlet,              dA_to_dA)
RNG_DISTRIBUTION(multinomial,            uidA_to_uiA)




