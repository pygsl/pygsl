/* 
 * Author: Pierre Schnizer
 * Previously features were included based on the GSL version the code was 
 * compiled against.
 * Now python setup.py config writes pygsl_features_config. There preprocessor
 * variables are defined for the different available features.
 * $Id$
 */
#ifndef _PYGSL_FEATURES_H_
#define _PYGSL_FEATURES_H_ 1

#include <pygsl/pygsl_features_config.h>


static const char _pygsl_gsl_unimpl_feature[] =  "Feature not implemented in your version of GSL";
#define _PyGSL_ERROR_UNIMPL pygsl_error(_pygsl_gsl_unimpl_feature, __FILE__, __LINE__, GSL_EUNIMPL)
#define PyGSL_ERROR_UNIMPL      do{_PyGSL_ERROR_UNIMPL; PyGSL_ERROR_FLAG(GSL_EUNIMPL); return GSL_EUNIMPL; }while(0);
#define PyGSL_ERROR_UNIMPL_NULL do{_PyGSL_ERROR_UNIMPL; PyGSL_ERROR_FLAG(GSL_EUNIMPL); return NULL; }while(0);

#endif /* _PYGSL_FEATURES_H_ */
