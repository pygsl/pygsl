.. py:function:: sf_complex_dilog_xy_e(x, y [, ret, result_im.val, result_im.err, result_re.val, result_re.err])

    Wrapper for :c:func:`gsl_sf_complex_dilog_xy_e`
    c code signature: int gsl_sf_complex_dilog_xy_e(const double x, const double y, gsl_sf_result* result_re, gsl_sf_result* result_im)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord_rd`
    
    :param double x: positional argument 0
    :param double y: positional argument 1
    :param int ret: positional argument 2
    :param double result_im.val: positional argument 3
    :param double result_im.err: positional argument 4
    :param double result_re.val: positional argument 5
    :param double result_re.err: positional argument 6
    :rtype:  tuple(:param int ret: positional argument 2, :param double result_im.val: positional argument 3, :param double result_im.err: positional argument 4, :param double result_re.val: positional argument 5, :param double result_re.err: positional argument 6) 
    :return: result 

.. py:function:: sf_complex_spence_xy_e(x, y [, ret, imag_sp.val, imag_sp.err, real_sp.val, real_sp.err])

    Wrapper for :c:func:`gsl_sf_complex_spence_xy_e`
    c code signature: int gsl_sf_complex_spence_xy_e(const double x, const double y, gsl_sf_result* real_sp, gsl_sf_result* imag_sp)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord_rd`
    
    :param double x: positional argument 0
    :param double y: positional argument 1
    :param int ret: positional argument 2
    :param double imag_sp.val: positional argument 3
    :param double imag_sp.err: positional argument 4
    :param double real_sp.val: positional argument 5
    :param double real_sp.err: positional argument 6
    :rtype:  tuple(:param int ret: positional argument 2, :param double imag_sp.val: positional argument 3, :param double imag_sp.err: positional argument 4, :param double real_sp.val: positional argument 5, :param double real_sp.err: positional argument 6) 
    :return: result 

.. py:function:: sf_dilog_e(x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_dilog_e`
    c code signature: int gsl_sf_dilog_e(const double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Ord`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_dilog(x [, ret])

    Wrapper for :c:func:`gsl_sf_dilog`
    c code signature: double gsl_sf_dilog(const double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rd__O`
    
    :param double x: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

