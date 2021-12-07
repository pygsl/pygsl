.. py:function:: sf_dawson_e(x [, ret, result.val, result.err])

    Wrapper for :c:func:`gsl_sf_dawson_e`
    c code signature: int gsl_sf_dawson_e( double x, gsl_sf_result* result)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rl__Ord`
    
    :param double x: positional argument 0
    :param int ret: positional argument 1
    :param double result.val: positional argument 2
    :param double result.err: positional argument 3
    :rtype:  tuple(:param int ret: positional argument 1, :param double result.val: positional argument 2, :param double result.err: positional argument 3) 
    :return: result 

.. py:function:: sf_dawson(x [, ret])

    Wrapper for :c:func:`gsl_sf_dawson`
    c code signature: double gsl_sf_dawson( double x)
    Wrapped by ufunc :class:`PyGSL_sf_ufunc_Id__Rd__O`
    
    :param double x: positional argument 0
    :param double ret: positional argument 1
    :rtype:  double 
    :return: result 

