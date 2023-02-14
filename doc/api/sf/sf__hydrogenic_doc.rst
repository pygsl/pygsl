.. py:function:: sf_hydrogenicR_1(Z, r [, ret])

    Wrapper for :c:func:`gsl_sf_hydrogenicR_1`
    c code signature: double gsl_sf_hydrogenicR_1(const double Z, const double r)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double Z: positional argument 0
    :param double r: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_hydrogenicR(n, l, Z, r [, ret])

    Wrapper for :c:func:`gsl_sf_hydrogenicR`
    c code signature: double gsl_sf_hydrogenicR(const int n, const int l, const double Z, const double r)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Il_l_d_d__Rd__O`
    
    :param int n: positional argument 0
    :param int l: positional argument 1
    :param double Z: positional argument 2
    :param double r: positional argument 3
    :param double ret: positional argument 4
    :rtype:  double 
    :return: result 

.. py:function:: sf_hydrogenicR_1_e(Z, r [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_hydrogenicR_1_e`
    c code signature: int gsl_sf_hydrogenicR_1_e(const double Z, const double r, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double Z: positional argument 0
    :param double r: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_hydrogenicR_e(n, l, Z, r [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_hydrogenicR_e`
    c code signature: int gsl_sf_hydrogenicR_e(const int n, const int l, const double Z, const double r, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Il_l_d_d__Rl__Ord`
    
    :param int n: positional argument 0
    :param int l: positional argument 1
    :param double Z: positional argument 2
    :param double r: positional argument 3
    :param int ret: positional argument 4
    :param double result.val: positional argument 5
    :param double result.err: positional argument 6
    :rtype:  tuple(:param int ret: positional argument 4, :param double result.val: positional argument 5, :param double result.err: positional argument 6) 
    :return: result 

