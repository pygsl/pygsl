/**
 * Author: Fabian Jakobs
 */   
%{
#include <gsl/gsl_blas.h>
#define _PyGSL_CblasRowMajor  CblasRowMajor   
#define _PyGSL_CblasColMajor  CblasColMajor
#define _PyGSL_CblasNoTrans   CblasNoTrans
#define _PyGSL_CblasTrans     CblasTrans
#define _PyGSL_CblasConjTrans CblasConjTrans
#define _PyGSL_CblasUpper     CblasUpper
#define _PyGSL_CblasLower     CblasLower
#define _PyGSL_CblasNonUnit   CblasNonUnit
#define _PyGSL_CblasUnit      CblasUnit
#define _PyGSL_CblasLeft      CblasLeft
#define _PyGSL_CblasRight     CblasRight
%}

#define _PyGSL_USE_HIDDEN(name) name = _PyGSL_ ## name
enum CBLAS_ORDER {_PyGSL_USE_HIDDEN(CblasRowMajor), _PyGSL_USE_HIDDEN(CblasColMajor)};
enum CBLAS_TRANSPOSE {_PyGSL_USE_HIDDEN(CblasNoTrans), _PyGSL_USE_HIDDEN(CblasTrans), _PyGSL_USE_HIDDEN(CblasConjTrans)};
enum CBLAS_UPLO {_PyGSL_USE_HIDDEN(CblasUpper), _PyGSL_USE_HIDDEN(CblasLower)};
enum CBLAS_DIAG {_PyGSL_USE_HIDDEN(CblasNonUnit), _PyGSL_USE_HIDDEN(CblasUnit)};
enum CBLAS_SIDE {_PyGSL_USE_HIDDEN(CblasLeft), _PyGSL_USE_HIDDEN(CblasRight)};

#define CBLAS_INDEX size_t  /* this may vary between platforms */
%apply double *OUTPUT {double *result};

%include gsl/gsl_blas.h
%include gsl/gsl_blas_types.h
