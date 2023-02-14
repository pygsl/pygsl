.. py:function:: complex_pow_real(a, b [, ret])

    Wrapper for :c:func:`gsl_complex_pow_real`
    c code signature: gsl_complex gsl_complex_pow_real( gsl_complex a,  double b)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_ID_d__RD__O`
    
    :param gsl_complex a: positional argument 0
    :param double b: positional argument 1
    :param gsl_complex ret: positional argument 2
    :rtype:  gsl_complex 
    :return: result 

.. py:function:: sf_pow_int(x, n [, ret])

    Wrapper for :c:func:`gsl_sf_pow_int`
    c code signature: double gsl_sf_pow_int(const double x, const int n)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_l__Rd__O`
    
    :param double x: positional argument 0
    :param int n: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_pow_int_e(x, n [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_pow_int_e`
    c code signature: int gsl_sf_pow_int_e( double x,  int n, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_l__Rl__Ord`
    
    :param double x: positional argument 0
    :param int n: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: complex_pow(a, b [, ret])

    Wrapper for :c:func:`gsl_complex_pow`
    c code signature: gsl_complex gsl_complex_pow( gsl_complex a,  gsl_complex b)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_ID_D__RD__O`
    
    :param gsl_complex a: positional argument 0
    :param gsl_complex b: positional argument 1
    :param gsl_complex ret: positional argument 2
    :rtype:  gsl_complex 
    :return: result 

