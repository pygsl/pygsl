#ifndef _PYGSL_FEATURES_H_
#define _PYGSL_FEATURES_H_ 1

/*
 * Common place to put the conditional defines for the various features added
 * to GSL during the development.
 */

#if PYGSL_GSL_MAJOR_VERSION < 1
#error "PyGSL requires at least GSL 1.0"
#endif 
	  
/*
 * currently the wrapper is only written for GSL 1.xx
 */
#if PYGSL_GSL_MAJOR_VERSION == 1


/*
 * The NMSIMPLEX solver was added with version 1.3
 */
#if PYGSL_GSL_MINOR_VERSION >= 3	  
#define _PYGSL_GSL_HAS_FMINIMIZER_NMSIMPLEX
#endif


/*
 * The deriv module was added with version 1.5
 */
#if (PYGSL_GSL_MINOR_VERSION < 5)
#define _PYGSL_GSL_HAS_DERIV 0
#else 
#define _PYGSL_GSL_HAS_DERIV 1
#endif 


/*
 * The wavelet module
 */
#if (PYGSL_GSL_MINOR_VERSION > 5)
#define _PYGSL_GSL_HAS_WAVELET 1
#endif

/*
 * When was KNUTHRAN 2002 really added?
 */
#if  PYGSL_GSL_MINOR_VERSION > 8
#define _PYGSL_GSL_HAS_RNG_KNUTHRAN2002 1
#endif


/*
 * The const module .....
 *
 * That was an on and off. Hopefully it is correct.
 */
#if (PYGSL_GSL_MINOR_VERSION < 4) || (PYGSL_GSL_MINOR_VERSION > 5)
#define _PYGSL_GSL_HAS_CGS 1
#define _PYGSL_GSL_HAS_MKS 1
#endif 

#if (PYGSL_GSL_MINOR_VERSION >= 4)
#define _PYGSL_GSL_HAS_CGSM 1
#define _PYGSL_GSL_HAS_MKSA 1
#endif

#else
#error "Should be version 1."
#endif /* PYGSL_GSL_MAJOR_VERSION == 1 */

#endif /* _PYGSL_FEATURES_H_ */
