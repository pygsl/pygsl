.. py:function:: sf_beta(a, b [, ret])

    Wrapper for :c:func:`gsl_sf_beta`
    c code signature: double gsl_sf_beta(const double a, const double b)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double a: positional argument 0
    :param double b: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_beta_e(a, b [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_beta_e`
    c code signature: int gsl_sf_beta_e(const double a, const double b, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double a: positional argument 0
    :param double b: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_beta_inc_e(a, b, x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_beta_inc_e`
    c code signature: int gsl_sf_beta_inc_e(const double a, const double b, const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d_d__Rl__Ord`
    
    :param double a: positional argument 0
    :param double b: positional argument 1
    :param double x: positional argument 2
    :param int ret: positional argument 3
    :param double result.val: positional argument 4
    :param double result.err: positional argument 5
    :rtype:  tuple(:param int ret: positional argument 3, :param double result.val: positional argument 4, :param double result.err: positional argument 5) 
    :return: result 

.. py:function:: sf_beta_inc(a, b, x [, ret])

    Wrapper for :c:func:`gsl_sf_beta_inc`
    c code signature: double gsl_sf_beta_inc(const double a, const double b, const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d_d__Rd__O`
    
    :param double a: positional argument 0
    :param double b: positional argument 1
    :param double x: positional argument 2
    :param double ret: positional argument 3
    :rtype:  double 
    :return: result 

.. py:function:: sf_choose(n, m [, ret])

    Wrapper for :c:func:`gsl_sf_choose`
    c code signature: double gsl_sf_choose( unsigned int n,  unsigned int m)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui_ui__Rd__O`
    
    :param unsigned int n: positional argument 0
    :param unsigned int m: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_choose_e(n, m [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_choose_e`
    c code signature: int gsl_sf_choose_e( unsigned int n,  unsigned int m, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui_ui__Rl__Ord`
    
    :param unsigned int n: positional argument 0
    :param unsigned int m: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_doublefact_e(n [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_doublefact_e`
    c code signature: int gsl_sf_doublefact_e(const unsigned int n, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rl__Ord`
    
    :param unsigned int n: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_doublefact(n [, ret])

    Wrapper for :c:func:`gsl_sf_doublefact`
    c code signature: double gsl_sf_doublefact(const unsigned int n)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rd__O`
    
    :param unsigned int n: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_fact(n [, ret])

    Wrapper for :c:func:`gsl_sf_fact`
    c code signature: double gsl_sf_fact(const unsigned int n)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rd__O`
    
    :param unsigned int n: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_fact_e(n [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_fact_e`
    c code signature: int gsl_sf_fact_e(const unsigned int n, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rl__Ord`
    
    :param unsigned int n: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_gamma_inc_P(a, x [, ret])

    Wrapper for :c:func:`gsl_sf_gamma_inc_P`
    c code signature: double gsl_sf_gamma_inc_P(const double a, const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double a: positional argument 0
    :param double x: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_gammainv_e(x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_gammainv_e`
    c code signature: int gsl_sf_gammainv_e(const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Ord`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_gamma_inc_Q(a, x [, ret])

    Wrapper for :c:func:`gsl_sf_gamma_inc_Q`
    c code signature: double gsl_sf_gamma_inc_Q(const double a, const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double a: positional argument 0
    :param double x: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_gamma_inc_P_e(a, x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_gamma_inc_P_e`
    c code signature: int gsl_sf_gamma_inc_P_e(const double a, const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double a: positional argument 0
    :param double x: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_gamma_inc_Q_e(a, x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_gamma_inc_Q_e`
    c code signature: int gsl_sf_gamma_inc_Q_e(const double a, const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double a: positional argument 0
    :param double x: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_gamma_e(x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_gamma_e`
    c code signature: int gsl_sf_gamma_e(const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Ord`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_gammastar(x [, ret])

    Wrapper for :c:func:`gsl_sf_gammastar`
    c code signature: double gsl_sf_gammastar(const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rd__O`
    
    :param double x: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_gammastar_e(x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_gammastar_e`
    c code signature: int gsl_sf_gammastar_e(const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Ord`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_gamma_inc_e(a, x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_gamma_inc_e`
    c code signature: int gsl_sf_gamma_inc_e(const double a, const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double a: positional argument 0
    :param double x: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_gamma(x [, ret])

    Wrapper for :c:func:`gsl_sf_gamma`
    c code signature: double gsl_sf_gamma(const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rd__O`
    
    :param double x: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_gammainv(x [, ret])

    Wrapper for :c:func:`gsl_sf_gammainv`
    c code signature: double gsl_sf_gammainv(const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rd__O`
    
    :param double x: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_gamma_inc(a, x [, ret])

    Wrapper for :c:func:`gsl_sf_gamma_inc`
    c code signature: double gsl_sf_gamma_inc(const double a, const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double a: positional argument 0
    :param double x: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_lnbeta_sgn_e(x, y [, ret, sgn, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_lnbeta_sgn_e`
    c code signature: int gsl_sf_lnbeta_sgn_e(const double x, const double y, gsl_sf_result* result, double* sgn)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Od_rd`
    
    :param double x: positional argument 0
    :param double y: positional argument 1
    :param int ret: positional argument 2
    :param double sgn: positional argument 3
    :param double result.val: positional argument 4
    :param double result.err: positional argument 5
    :rtype:  tuple(:param int ret: positional argument 2, :param double sgn: positional argument 3, :param double result.val: positional argument 4, :param double result.err: positional argument 5) 
    :return: result 

.. py:function:: sf_lnbeta_e(a, b [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_lnbeta_e`
    c code signature: int gsl_sf_lnbeta_e(const double a, const double b, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double a: positional argument 0
    :param double b: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_lnbeta(a, b [, ret])

    Wrapper for :c:func:`gsl_sf_lnbeta`
    c code signature: double gsl_sf_lnbeta(const double a, const double b)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double a: positional argument 0
    :param double b: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_lnchoose(n, m [, ret])

    Wrapper for :c:func:`gsl_sf_lnchoose`
    c code signature: double gsl_sf_lnchoose( unsigned int n,  unsigned int m)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui_ui__Rd__O`
    
    :param unsigned int n: positional argument 0
    :param unsigned int m: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_lnchoose_e(n, m [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_lnchoose_e`
    c code signature: int gsl_sf_lnchoose_e( unsigned int n,  unsigned int m, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui_ui__Rl__Ord`
    
    :param unsigned int n: positional argument 0
    :param unsigned int m: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_lndoublefact_e(n [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_lndoublefact_e`
    c code signature: int gsl_sf_lndoublefact_e(const unsigned int n, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rl__Ord`
    
    :param unsigned int n: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_lndoublefact(n [, ret])

    Wrapper for :c:func:`gsl_sf_lndoublefact`
    c code signature: double gsl_sf_lndoublefact(const unsigned int n)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rd__O`
    
    :param unsigned int n: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_lnfact(n [, ret])

    Wrapper for :c:func:`gsl_sf_lnfact`
    c code signature: double gsl_sf_lnfact(const unsigned int n)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rd__O`
    
    :param unsigned int n: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_lnfact_e(n [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_lnfact_e`
    c code signature: int gsl_sf_lnfact_e(const unsigned int n, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Iui__Rl__Ord`
    
    :param unsigned int n: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_lngamma_sgn_e(x [, ret, sgn, result_lg.val, result_lg.err])

    Wrapper for :c:func:`gsl_sf_lngamma_sgn_e`
    c code signature: int gsl_sf_lngamma_sgn_e( double x, gsl_sf_result* result_lg, double* sgn)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Od_rd`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double sgn: positional argument 2
    :param double result_lg.val: positional argument 3
    :param double result_lg.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 1, :param double sgn: positional argument 2, :param double result_lg.val: positional argument 3, :param double result_lg.err: positional argument 4) 
    :return: result 

.. py:function:: sf_lngamma_e(x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_lngamma_e`
    c code signature: int gsl_sf_lngamma_e( double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Ord`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_lngamma(x [, ret])

    Wrapper for :c:func:`gsl_sf_lngamma`
    c code signature: double gsl_sf_lngamma(const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rd__O`
    
    :param double x: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

.. py:function:: sf_taylorcoeff(n, x [, ret])

    Wrapper for :c:func:`gsl_sf_taylorcoeff`
    c code signature: double gsl_sf_taylorcoeff(const int n, const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Il_d__Rd__O`
    
    :param int n: positional argument 0
    :param double x: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_taylorcoeff_e(n, x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_taylorcoeff_e`
    c code signature: int gsl_sf_taylorcoeff_e(const int n, const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Il_d__Rl__Ord`
    
    :param int n: positional argument 0
    :param double x: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

