%module sf

#include "pygsl_sf_config.h"
%ignore gsl_sf_angle_restrict_pos_e; // use a double * for input and output. not properly recognized.
// use gsl_sf_angle_restricted_pos_err_e complies to the usual interface
%ignore gsl_sf_result_smash_e; // the only one to use a const pointer as input. Not recognized by the tool.

%include <gsl/gsl_sf_result.h>

// makes swig preprocessor derail if not defined empty
#define INLINE_DECL

//Deprecated functions
%ignore gsl_sf_coupling_6j_INCORRECT_e;
%ignore gsl_sf_coupling_6j_INCORRECT;

// Not a direct map
%ignore gsl_sf_polar_to_rect;
%ignore gsl_sf_rect_to_polar;

// Functions returning arrays are not mapped currently.

%ignore gsl_sf_gegenpoly_array;


%include <gsl/gsl_sf_airy.h>

%ignore gsl_sf_bessel_sequence_Jnu_e;
%ignore gsl_sf_bessel_Jn_array;
%ignore gsl_sf_bessel_Yn_array;
%ignore gsl_sf_bessel_In_array;
%ignore gsl_sf_bessel_In_scaled_array;
%ignore gsl_sf_bessel_Kn_array;
%ignore gsl_sf_bessel_Kn_scaled_array;
%ignore gsl_sf_bessel_jl_array;
%ignore gsl_sf_bessel_jl_steed_array;
%ignore gsl_sf_bessel_yl_array;
%ignore gsl_sf_bessel_il_scaled_array;
%ignore gsl_sf_bessel_kl_scaled_array;
%include <gsl/gsl_sf_bessel.h>
%include <gsl/gsl_sf_clausen.h>

%ignore gsl_sf_coulomb_wave_F_array;
%ignore gsl_sf_coulomb_wave_FG_array;
%ignore gsl_sf_coulomb_wave_FGp_array;
%ignore gsl_sf_coulomb_wave_sphF_array;
%ignore gsl_sf_coulomb_CL_array;
%include <gsl/gsl_sf_coulomb.h>

%include <gsl/gsl_sf_coupling.h>
%include <gsl/gsl_sf_dawson.h>
%include <gsl/gsl_sf_debye.h>
%include <gsl/gsl_sf_dilog.h>
%include <gsl/gsl_sf_elementary.h>
%include <gsl/gsl_sf_ellint.h>
%include <gsl/gsl_sf_elljac.h>
%include <gsl/gsl_sf_erf.h>
%include <gsl/gsl_sf_exp.h>
%include <gsl/gsl_sf_expint.h>
%include <gsl/gsl_sf_fermi_dirac.h>
%include <gsl/gsl_sf_gamma.h>
%include <gsl/gsl_sf_gegenbauer.h>
%include <gsl/gsl_sf_hyperg.h>
%include <gsl/gsl_sf_laguerre.h>
%include <gsl/gsl_sf_lambert.h>


%ignore gsl_sf_legendre_Pl_array;
%ignore gsl_sf_legendre_Pl_deriv_array;
%ignore gsl_sf_legendre_Plm_array;
%ignore gsl_sf_legendre_Plm_deriv_array;
%ignore gsl_sf_legendre_sphPlm_array;
%ignore gsl_sf_legendre_sphPlm_deriv_array;
%ignore gsl_sf_legendre_array_size;
%ignore gsl_sf_legendre_H3d_array;
%ignore gsl_sf_legendre_array;
%ignore gsl_sf_legendre_array_e;
%ignore gsl_sf_legendre_deriv_array_e;
%ignore gsl_sf_legendre_deriv_array;
%ignore gsl_sf_legendre_deriv_alt_array;
%ignore gsl_sf_legendre_deriv_alt_array_e;
%ignore gsl_sf_legendre_deriv2_array;
%ignore gsl_sf_legendre_deriv2_array_e;
%ignore gsl_sf_legendre_deriv2_alt_array;
%ignore gsl_sf_legendre_deriv2_alt_array_e;
%ignore gsl_sf_legendre_array_n;
%ignore gsl_sf_legendre_array_index;
%ignore gsl_sf_legendre_nlm;
%include <gsl/gsl_sf_legendre.h>
%include <gsl/gsl_sf_log.h>

 /* */
#ifdef _PYGSL_GSL_HAS_SF_MATHIEU
%ignore gsl_sf_mathieu_ce_array;
%ignore gsl_sf_mathieu_se_array;
%ignore gsl_sf_mathieu_Mc_array;
%ignore gsl_sf_mathieu_Ms_array;
%ignore gsl_sf_mathieu_a_array;
%ignore gsl_sf_mathieu_b_array;
%ignore gsl_sf_mathieu_workspace;
%ignore gsl_sf_mathieu_free;
%ignore gsl_sf_mathieu_alloc;
%ignore gsl_sf_mathieu_a_coeff;
%ignore gsl_sf_mathieu_b_coeff;

%include <gsl/gsl_sf_mathieu.h>
#endif

 /* */
%include <gsl/gsl_sf_pow_int.h>
%include <gsl/gsl_sf_psi.h>
%include <gsl/gsl_sf_synchrotron.h>
%include <gsl/gsl_sf_transport.h>
%include <gsl/gsl_sf_trig.h>
%include <gsl/gsl_sf_zeta.h>



// Complex Functions are wrapped manually.
//%ignore gsl_sf_complex_dilog_e;   // polar to rect
//%ignore gsl_sf_lngamma_complex_e; // rect to polar
//%ignore gsl_sf_complex_log_e;     // rect to polar
//%ignore gsl_sf_complex_sin_e;     // rect to rect
//%ignore gsl_sf_complex_cos_e;     // rect to rect
//%ignore gsl_sf_complex_logsin_e;



%include <gsl/gsl_complex_math.h>
 //%ignore gsl_complex_sqrt_real;
 //%ignore gsl_complex_polar;
 //%ignore gsl_complex_polar;

%ignore gsl_coerce_float;
%ignore gsl_coerce_long_double;
%include <gsl/gsl_sys.h>
%ignore gsl_coerce_float;
