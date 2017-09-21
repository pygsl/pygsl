.. py:function:: sf_coulomb_CL_e(L, eta [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_coulomb_CL_e`
    c code signature: int gsl_sf_coulomb_CL_e( double L,  double eta, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double L: positional argument 0
    :param double eta: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_coulomb_wave_FG_e(eta, x, lam_F, k_lam_G [, ret, exp_G, exp_F, Gp.val, Gp.err, G.val, G.err, Fp.val, Fp.err, F.val, F.err])

    Wrapper for :c:func:`gsl_sf_coulomb_wave_FG_e`
    c code signature: int gsl_sf_coulomb_wave_FG_e(const double eta, const double x, const double lam_F, const int k_lam_G, gsl_sf_result* F, gsl_sf_result* Fp, gsl_sf_result* G, gsl_sf_result* Gp, double* exp_F, double* exp_G)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d_d_l__Rl__Od_d_rd_rd_rd_rd`
    
    :param double eta: positional argument 0
    :param double x: positional argument 1
    :param double lam_F: positional argument 2
    :param int k_lam_G: positional argument 3
    :param int ret: positional argument 4
    :param double exp_G: positional argument 5
    :param double exp_F: positional argument 6
    :param double Gp.val: positional argument 7
    :param double Gp.err: positional argument 8
    :param double G.val: positional argument 9
    :param double G.err: positional argument 10
    :param double Fp.val: positional argument 11
    :param double Fp.err: positional argument 12
    :param double F.val: positional argument 13
    :param double F.err: positional argument 14
    :rtype:  tuple(:param int ret: positional argument 4, :param double exp_G: positional argument 5, :param double exp_F: positional argument 6, :param double Gp.val: positional argument 7, :param double Gp.err: positional argument 8, :param double G.val: positional argument 9, :param double G.err: positional argument 10, :param double Fp.val: positional argument 11, :param double Fp.err: positional argument 12, :param double F.val: positional argument 13, :param double F.err: positional argument 14) 
    :return: result 

