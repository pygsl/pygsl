/* -*- C -*- */
/*
 * Author: Fabian Jakobs
 * Modified by : Pierre Schnizer Feburary 2003, 2016
 * $Id$
 */		 
%{
#include <gsl/gsl_linalg.h>
%}

/* 
   The function gsl_linalg_LU_sgndet uses int as a normal return value. 
   Therefore I can not map int to gsl_error_flag. So I apply it to all 
   but the one function.
*/
%apply gsl_error_flag_drop {
		       int gsl_linalg_matmult,
		       int gsl_linalg_matmult_mod,
		       int gsl_linalg_matmult,
 		       int gsl_linalg_matmult_mod,
 		       int gsl_linalg_exponential_ss,
 		       int gsl_linalg_householder_transform,
 		       int gsl_linalg_complex_householder_transform,
 		       int gsl_linalg_householder_hm,
 		       int gsl_linalg_householder_mh,
 		       int gsl_linalg_householder_hv,
 		       int gsl_linalg_householder_hm1,
 		       int gsl_linalg_complex_householder_hm,
 		       int gsl_linalg_SV_decomp,
 		       int gsl_linalg_SV_decomp_mod,
 		       int gsl_linalg_SV_decomp_jacobi,
 		       int gsl_linalg_SV_solve,
 		       int gsl_linalg_LU_decomp,
 		       int gsl_linalg_LU_solve,
 		       int gsl_linalg_LU_svx,
 		       int gsl_linalg_LU_refine,
 		       int gsl_linalg_LU_invert,
 		       int gsl_linalg_LU_det,
 		       int gsl_linalg_LU_lndet,
 		       int gsl_linalg_complex_LU_decomp,
 		       int gsl_linalg_complex_LU_solve,
 		       int gsl_linalg_complex_LU_svx,
 		       int gsl_linalg_complex_LU_refine,
 		       int gsl_linalg_complex_LU_invert,
 		       int gsl_linalg_complex_LU_det,
 		       int gsl_linalg_complex_LU_lndet,
 		       int gsl_linalg_complex_LU_sgndet,
 		       int gsl_linalg_QR_decomp,
 		       int gsl_linalg_QR_solve,
 		       int gsl_linalg_QR_svx,
 		       int gsl_linalg_QR_lssolve,
 		       int gsl_linalg_QR_QRsolve,
 		       int gsl_linalg_QR_Rsolve,
 		       int gsl_linalg_QR_Rsvx,
 		       int gsl_linalg_QR_update,
 		       int gsl_linalg_QR_QTvec,
 		       int gsl_linalg_QR_Qvec,
 		       int gsl_linalg_QR_unpack,
 		       int gsl_linalg_R_solve,
 		       int gsl_linalg_QRPT_decomp,
 		       int gsl_linalg_QRPT_decomp2,
 		       int gsl_linalg_QRPT_solve,
 		       int gsl_linalg_QRPT_svx,
 		       int gsl_linalg_QRPT_QRsolve,
 		       int gsl_linalg_QRPT_Rsolve,
 		       int gsl_linalg_QRPT_Rsvx,
 		       int gsl_linalg_QRPT_update,
 		       int gsl_linalg_cholesky_decomp,
 		       int gsl_linalg_cholesky_solve,
 		       int gsl_linalg_cholesky_svx,
 		       int gsl_linalg_symmtd_decomp,
 		       int gsl_linalg_symmtd_unpack,
 		       int gsl_linalg_symmtd_unpack_T,
 		       int gsl_linalg_hermtd_decomp,
 		       int gsl_linalg_hermtd_unpack,
 		       int gsl_linalg_hermtd_unpack_T,
 		       int gsl_linalg_HH_solve,
 		       int gsl_linalg_HH_svx,
 		       int gsl_linalg_solve_symm_tridiag,
 		       int gsl_linalg_solve_tridiag,
 		       int gsl_linalg_solve_symm_cyc_tridiag,
 		       int gsl_linalg_solve_cyc_tridiag,
 		       int gsl_linalg_bidiag_decomp,
 		       int gsl_linalg_bidiag_unpack,
 		       int gsl_linalg_bidiag_unpack2,
 		       int gsl_linalg_bidiag_unpack_B,
 		       int gsl_linalg_balance_columns
                       };
%apply int *OUTPUT {int *signum}

%ignore gsl_linalg_complex_householder_mh;
%{
int 
pygsl_linalg_complex_householder_mh (gsl_complex tau, const gsl_vector_complex * v, gsl_matrix_complex * A){
#ifdef _PYGSL_GSL_HAS_GSL_LINALG_COMPLEX_HOUSEHOLDER_MH
  return gsl_linalg_complex_householder_mh(tau, v, A);
#else
  PyGSL_ERROR_UNIMPL;
#endif
}

%}
int 
pygsl_linalg_complex_householder_mh (gsl_complex tau, const gsl_vector_complex * v, gsl_matrix_complex * OUTPUT);

%ignore gsl_linalg_hessenberg_decomp;
%{
int 
pygsl_linalg_hessenberg_decomp(gsl_matrix * A, gsl_vector * tau)
{
#ifdef _PYGSL_GSL_HAS_GSL_LINALG_HESSENBERG_DECOMP
  return gsl_linalg_hessenberg_decomp (A, tau);
#else
  PyGSL_ERROR_UNIMPL
#endif  
}
%}
int 
pygsl_linalg_hessenberg_decomp (gsl_matrix * A, gsl_vector * tau);


%ignore gsl_linalg_complex_cholesky_invert;
%{
int 
pygsl_linalg_complex_cholesky_invert(gsl_matrix_complex * cholesky)
{
#ifdef _PYGSL_GSL_HAS_GSL_LINALG_COMPLEX_CHOLESKY_INVERT
  return gsl_linalg_complex_cholesky_invert(cholesky);
#else
  PyGSL_ERROR_UNIMPL
#endif  
}
%}

int 
pygsl_linalg_complex_cholesky_invert(gsl_matrix_complex * cholesky);



%ignore gsl_linalg_SV_leverage;
%ignore gsl_linalg_QR_matQ;
/* gsl 1.13 does not know it */
%ignore gsl_linalg_complex_cholesky_invert;
/* as for permutation / combination */
#define INLINE_DECL
%ignore gsl_linalg_givens;
%ignore gsl_linalg_givens_gv;
%include gsl/gsl_linalg.h

