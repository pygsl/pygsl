#!/usr/bin/env python
import string
from extract_tool_ufunc import *
import sys
pipe = os.popen("gsl-config --prefix")
prefix = pipe.readlines()[0]
prefix = os.path.join(string.strip(prefix), 'include')
p = prototype_collector(prefix)
# Functions to exclude from the whole list.
exclude_list = ['gsl_sf_angle_restrict_pos_e', # use a double * for input and output. not properly recognized.
                'gsl_sf_result_smash_e', # the only one to use a const pointer as input. Not recognized by the tool.
                # Complex Functions are wrapped manually.
                'gsl_sf_complex_dilog_e',
                'gsl_sf_lngamma_complex_e',
                'gsl_sf_complex_log_e',
                'gsl_sf_complex_sin_e',
                'gsl_sf_complex_cos_e',
                'gsl_sf_complex_logsin_e',
                #Deprecated functions
                'gsl_sf_coupling_6j_INCORRECT_e',
                'gsl_sf_coupling_INCORRECT_6j',
                # Functions returning arrays are not mapped currently.
                'gsl_sf_coulomb_wave_F_array',
                'gsl_sf_polar_to_rect',
                'gsl_sf_rect_to_polar',
                'gsl_sf_bessel_sequence_Jnu_e',
                'gsl_sf_bessel_Jn_array',
                'gsl_sf_bessel_Yn_array',
                'gsl_sf_bessel_In_array',
                'gsl_sf_bessel_In_scaled_array',
                'gsl_sf_bessel_Kn_array',
                'gsl_sf_bessel_Kn_scaled_array',
                'gsl_sf_bessel_jl_array',
                'gsl_sf_bessel_jl_steed_array',
                'gsl_sf_bessel_yl_array',
                'gsl_sf_bessel_il_scaled_array',
                'gsl_sf_bessel_kl_scaled_array',
                'gsl_sf_coulomb_wave_FG_array',
                'gsl_sf_coulomb_wave_FGp_array',
                'gsl_sf_coulomb_wave_sphF_array',
                'gsl_sf_coulomb_CL_array',
                'gsl_sf_gegenpoly_array',
                'gsl_sf_legendre_Pl_array',
                'gsl_sf_legendre_Pl_deriv_array',
                'gsl_sf_legendre_Plm_array',
                'gsl_sf_legendre_Plm_deriv_array',
                'gsl_sf_legendre_sphPlm_array',
                'gsl_sf_legendre_sphPlm_deriv_array',
                'gsl_sf_legendre_array_size',
                'gsl_sf_legendre_H3d_array'
                ]
p.set_exclude_list(exclude_list)
p.make_wrapper_and_index_file("sf_")
