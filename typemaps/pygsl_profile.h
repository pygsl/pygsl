/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * created: January 2003
 * 
 * Variables indicating expensive operations performed by 
 * the wrappers.   
 */
#ifndef _PYGSL_TYPEMAPS_PROFILE_IC_
#define _PYGSL_TYPEMAPS_PROFILE_IC_ 1

#define PYGSL_PROFILE_INPUT 1
#ifdef PYGSL_PROFILE_INPUT

/*
  One dimensional Python array can be directly passed to
  vectors. If not a function will be invoked. If it has 
  to work on the array it will increase this counter via
  PyGSL_INCREASE_vector_transform_counter
 */
static  int pygsl_profile_vector_transform_counter = 0;
/*
 * Two dimensional Python array can be directly passed to
 * matrices, if they are contingous. (Currently not performed )
 * If not a function will be invoked. If it has 
 * to work on the array it will increase this counter via
 * INCREASE_matrix_transform_counter
 */
static  int pygsl_profile_matrix_transform_counter = 0;

/*
 * From a mathematical point of view 0 is also a legal 
 * complex number. (YMMV;-) Complex objects are 
 * transferred directly  to  the underlying  function,
 * whereas other numeric objects have to  be converted. 
 * In that case this counter is increased. via 
 * 
 */
static  int pygsl_profile_complex_transform_counter = 0;

/*
 * From a mathematical point of view 0 is also a legal 
 * float. Float objects are 
 * transferred directly  to  the underlying  function,
 * whereas other numeric objects have to  be converted. 
 * In that case this counter is increased. via 
 * 
 */
static  int pygsl_profile_float_transform_counter = 0;

#define PyGSL_INCREASE_vector_transform_counter()      \
                pygsl_profile_vector_transform_counter++

#define PyGSL_INCREASE_matrix_transform_counter()    \
                  pygsl_profile_matrix_transform_counter++

#define PyGSL_INCREASE_complex_transform_counter()   \
                 pygsl_profile_complex_transform_counter++

#define PyGSL_INCREASE_float_transform_counter()   \
                 pygsl_profile_float_transform_counter++

#else /* PYGSL_PROFILE_INPUT */

#define PyGSL_INCREASE_vector_transform_counter() 
#define PyGSL_INCREASE_matrix_transform_counter() 
#define PyGSL_INCREASE_complex_transform_counter()
#define PyGSL_INCREASE_float_transform_counter()

#endif /* PYGSL_PROFILE_INPUT */

#endif /* _PYGSL_TYPEMAPS_PROFILE_IC_ */
