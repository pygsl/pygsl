#ifndef PyGSL_TYPEMAPS_PROFILE_H
#define PyGSL_TYPEMAPS_PROFILE_H

/* -*- C -*- */
/**
 * author: Pierre Schnizer
 * created: January 2003
 * 
 * Variables indicating expensive operations performed by 
 * the wrappers.   
 */

#include <pygsl/utils.h>
#include <pygsl/intern.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif
__BEGIN_DECLS


#define PYGSL_PROFILE_INPUT 1

#ifdef PYGSL_PROFILE_INPUT

#if 0
/*
  One dimensional Python array can be directly passed to
  vectors. If not a function will be invoked. If it has 
  to work on the array it will increase this counter via
  PyGSL_INCREASE_vector_transform_counter
 */
extern int pygsl_profile_vector_transform_counter;
/*
 * Two dimensional Python array can be directly passed to
 * matrices, if they are contingous. (Currently not performed )
 * If not a function will be invoked. If it has 
 * to work on the array it will increase this counter via
 * INCREASE_matrix_transform_counter
 */
extern int pygsl_profile_matrix_transform_counter;

/*
 * From a mathematical point of view 0 is also a legal 
 * complex number. (YMMV;-) Complex objects are 
 * transferred directly  to  the underlying  function,
 * whereas other numeric objects have to  be converted. 
 * In that case this counter is increased. via 
 * 
 */
extern  int pygsl_profile_complex_transform_counter;

/*
 * From a mathematical point of view 0 is also a legal 
 * float. Float objects are 
 * transferred directly  to  the underlying  function,
 * whereas other numeric objects have to  be converted. 
 * In that case this counter is increased. via 
 * 
 */
extern int pygsl_profile_float_transform_counter;
#endif
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

__END_DECLS
#endif /* PyGSL_TYPEMAPS_PROFILE_H */
