/**
 * Author: Fabian Jakobs
 */   
%{
#include <gsl/gsl_blas.h>
%}

enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102};
enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113};
enum CBLAS_UPLO {CblasUpper=121, CblasLower=122};
enum CBLAS_DIAG {CblasNonUnit=131, CblasUnit=132};
enum CBLAS_SIDE {CblasLeft=141, CblasRight=142};
#define CBLAS_INDEX size_t  /* this may vary between platforms */

%apply double *OUTPUT {double *result};

%include gsl/gsl_blas.h
%include gsl/gsl_blas_types.h