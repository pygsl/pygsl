.. py:function:: sf_multiply(x, y [, ret])

    Wrapper for :c:func:`gsl_sf_multiply`
    c code signature: double gsl_sf_multiply(const double x, const double y)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rd__O`
    
    :param double x: positional argument 0
    :param double y: positional argument 1
    :param double ret: positional argument 2
    :rtype:  double 
    :return: result 

.. py:function:: sf_multiply_e(x, y [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_multiply_e`
    c code signature: int gsl_sf_multiply_e(const double x, const double y, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d__Rl__Ord`
    
    :param double x: positional argument 0
    :param double y: positional argument 1
    :param int ret: positional argument 2
    :param double result.val: positional argument 3
    :param double result.err: positional argument 4
    :rtype:  tuple(:param int ret: positional argument 2, :param double result.val: positional argument 3, :param double result.err: positional argument 4) 
    :return: result 

.. py:function:: sf_multiply_err_e(x, dx, y, dy [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_multiply_err_e`
    c code signature: int gsl_sf_multiply_err_e(const double x, const double dx, const double y, const double dy, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id_d_d_d__Rl__Ord`
    
    :param double x: positional argument 0
    :param double dx: positional argument 1
    :param double y: positional argument 2
    :param double dy: positional argument 3
    :param int ret: positional argument 4
    :param double result.val: positional argument 5
    :param double result.err: positional argument 6
    :rtype:  tuple(:param int ret: positional argument 4, :param double result.val: positional argument 5, :param double result.err: positional argument 6) 
    :return: result 

