/*Using complex_rect as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_dd__one_data ,
                             complex_rect_data,
                             PyGSL_sf_ufunc_pD_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_rect",
                             PyGSL_sf_ufunc_pD_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_rect", f);
/* Py_DECREF(f) */;

/*Using complex_polar as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_dd__one_data ,
                             complex_polar_data,
                             PyGSL_sf_ufunc_pD_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_polar",
                             PyGSL_sf_ufunc_pD_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_polar", f);
/* Py_DECREF(f) */;

/*Using complex_arg as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_D__one_data ,
                             complex_arg_data,
                             PyGSL_sf_ufunc_pd_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arg",
                             PyGSL_sf_ufunc_pd_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arg", f);
/* Py_DECREF(f) */;

/*Using complex_abs as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_D__one_data ,
                             complex_abs_data,
                             PyGSL_sf_ufunc_pd_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_abs",
                             PyGSL_sf_ufunc_pd_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_abs", f);
/* Py_DECREF(f) */;

/*Using complex_abs2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_D__one_data ,
                             complex_abs2_data,
                             PyGSL_sf_ufunc_pd_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_abs2",
                             PyGSL_sf_ufunc_pd_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_abs2", f);
/* Py_DECREF(f) */;

/*Using complex_logabs as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_D__one_data ,
                             complex_logabs_data,
                             PyGSL_sf_ufunc_pd_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_logabs",
                             PyGSL_sf_ufunc_pd_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_logabs", f);
/* Py_DECREF(f) */;

/*Using complex_add as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_DD__one_data ,
                             complex_add_data,
                             PyGSL_sf_ufunc_pD_DD__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_add",
                             PyGSL_sf_ufunc_pD_DD__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_add", f);
/* Py_DECREF(f) */;

/*Using complex_sub as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_DD__one_data ,
                             complex_sub_data,
                             PyGSL_sf_ufunc_pD_DD__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sub",
                             PyGSL_sf_ufunc_pD_DD__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sub", f);
/* Py_DECREF(f) */;

/*Using complex_mul as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_DD__one_data ,
                             complex_mul_data,
                             PyGSL_sf_ufunc_pD_DD__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_mul",
                             PyGSL_sf_ufunc_pD_DD__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_mul", f);
/* Py_DECREF(f) */;

/*Using complex_div as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_DD__one_data ,
                             complex_div_data,
                             PyGSL_sf_ufunc_pD_DD__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_div",
                             PyGSL_sf_ufunc_pD_DD__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_div", f);
/* Py_DECREF(f) */;

/*Using complex_add_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_add_real_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_add_real",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_add_real", f);
/* Py_DECREF(f) */;

/*Using complex_sub_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_sub_real_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sub_real",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sub_real", f);
/* Py_DECREF(f) */;

/*Using complex_mul_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_mul_real_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_mul_real",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_mul_real", f);
/* Py_DECREF(f) */;

/*Using complex_div_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_div_real_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_div_real",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_div_real", f);
/* Py_DECREF(f) */;

/*Using complex_add_imag as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_add_imag_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_add_imag",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_add_imag", f);
/* Py_DECREF(f) */;

/*Using complex_sub_imag as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_sub_imag_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sub_imag",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sub_imag", f);
/* Py_DECREF(f) */;

/*Using complex_mul_imag as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_mul_imag_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_mul_imag",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_mul_imag", f);
/* Py_DECREF(f) */;

/*Using complex_div_imag as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_div_imag_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_div_imag",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_div_imag", f);
/* Py_DECREF(f) */;

/*Using complex_conjugate as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_conjugate_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_conjugate",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_conjugate", f);
/* Py_DECREF(f) */;

/*Using complex_inverse as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_inverse_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_inverse",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_inverse", f);
/* Py_DECREF(f) */;

/*Using complex_negative as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_negative_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_negative",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_negative", f);
/* Py_DECREF(f) */;

/*Using complex_sqrt as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_sqrt_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sqrt",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sqrt", f);
/* Py_DECREF(f) */;

/*Using complex_sqrt_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_sqrt_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sqrt_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sqrt_real", f);
/* Py_DECREF(f) */;

/*Using complex_pow as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_DD__one_data ,
                             complex_pow_data,
                             PyGSL_sf_ufunc_pD_DD__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_pow",
                             PyGSL_sf_ufunc_pD_DD__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_pow", f);
/* Py_DECREF(f) */;

/*Using complex_pow_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_Dd__one_data ,
                             complex_pow_real_data,
                             PyGSL_sf_ufunc_pD_Dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_pow_real",
                             PyGSL_sf_ufunc_pD_Dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_pow_real", f);
/* Py_DECREF(f) */;

/*Using complex_exp as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_exp_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_exp",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_exp", f);
/* Py_DECREF(f) */;

/*Using complex_log as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_log_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_log",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_log", f);
/* Py_DECREF(f) */;

/*Using complex_log10 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_log10_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_log10",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_log10", f);
/* Py_DECREF(f) */;

/*Using complex_log_b as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_DD__one_data ,
                             complex_log_b_data,
                             PyGSL_sf_ufunc_pD_DD__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_log_b",
                             PyGSL_sf_ufunc_pD_DD__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_log_b", f);
/* Py_DECREF(f) */;

/*Using complex_sin as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_sin_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sin",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sin", f);
/* Py_DECREF(f) */;

/*Using complex_cos as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_cos_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_cos",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_cos", f);
/* Py_DECREF(f) */;

/*Using complex_sec as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_sec_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sec",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sec", f);
/* Py_DECREF(f) */;

/*Using complex_csc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_csc_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_csc",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_csc", f);
/* Py_DECREF(f) */;

/*Using complex_tan as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_tan_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_tan",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_tan", f);
/* Py_DECREF(f) */;

/*Using complex_cot as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_cot_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_cot",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_cot", f);
/* Py_DECREF(f) */;

/*Using complex_arcsin as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arcsin_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arcsin",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arcsin", f);
/* Py_DECREF(f) */;

/*Using complex_arcsin_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_arcsin_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arcsin_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arcsin_real", f);
/* Py_DECREF(f) */;

/*Using complex_arccos as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arccos_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccos",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccos", f);
/* Py_DECREF(f) */;

/*Using complex_arccos_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_arccos_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccos_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccos_real", f);
/* Py_DECREF(f) */;

/*Using complex_arcsec as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arcsec_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arcsec",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arcsec", f);
/* Py_DECREF(f) */;

/*Using complex_arcsec_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_arcsec_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arcsec_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arcsec_real", f);
/* Py_DECREF(f) */;

/*Using complex_arccsc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arccsc_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccsc",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccsc", f);
/* Py_DECREF(f) */;

/*Using complex_arccsc_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_arccsc_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccsc_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccsc_real", f);
/* Py_DECREF(f) */;

/*Using complex_arctan as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arctan_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arctan",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arctan", f);
/* Py_DECREF(f) */;

/*Using complex_arccot as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arccot_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccot",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccot", f);
/* Py_DECREF(f) */;

/*Using complex_sinh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_sinh_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sinh",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sinh", f);
/* Py_DECREF(f) */;

/*Using complex_cosh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_cosh_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_cosh",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_cosh", f);
/* Py_DECREF(f) */;

/*Using complex_sech as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_sech_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_sech",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_sech", f);
/* Py_DECREF(f) */;

/*Using complex_csch as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_csch_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_csch",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_csch", f);
/* Py_DECREF(f) */;

/*Using complex_tanh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_tanh_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_tanh",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_tanh", f);
/* Py_DECREF(f) */;

/*Using complex_coth as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_coth_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_coth",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_coth", f);
/* Py_DECREF(f) */;

/*Using complex_arcsinh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arcsinh_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arcsinh",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arcsinh", f);
/* Py_DECREF(f) */;

/*Using complex_arccosh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arccosh_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccosh",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccosh", f);
/* Py_DECREF(f) */;

/*Using complex_arccosh_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_arccosh_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccosh_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccosh_real", f);
/* Py_DECREF(f) */;

/*Using complex_arcsech as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arcsech_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arcsech",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arcsech", f);
/* Py_DECREF(f) */;

/*Using complex_arccsch as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arccsch_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccsch",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccsch", f);
/* Py_DECREF(f) */;

/*Using complex_arctanh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arctanh_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arctanh",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arctanh", f);
/* Py_DECREF(f) */;

/*Using complex_arctanh_real as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_d__one_data ,
                             complex_arctanh_real_data,
                             PyGSL_sf_ufunc_pD_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arctanh_real",
                             PyGSL_sf_ufunc_pD_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arctanh_real", f);
/* Py_DECREF(f) */;

/*Using complex_arccoth as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pD_D__one_data ,
                             complex_arccoth_data,
                             PyGSL_sf_ufunc_pD_D__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "complex_arccoth",
                             PyGSL_sf_ufunc_pD_D__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "complex_arccoth", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Ai_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Ai_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Bi_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Bi_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Ai_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_scaled_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Ai_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_scaled",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Bi_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_scaled_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Bi_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_scaled",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_deriv_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Ai_deriv_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_deriv_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_deriv_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_deriv as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Ai_deriv_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_deriv",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_deriv", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_deriv_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Bi_deriv_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_deriv_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_deriv_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_deriv as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Bi_deriv_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_deriv",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_deriv", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_deriv_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Ai_deriv_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_deriv_scaled_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_deriv_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Ai_deriv_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Ai_deriv_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Ai_deriv_scaled",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Ai_deriv_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_deriv_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_airy_Bi_deriv_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_deriv_scaled_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_deriv_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_Bi_deriv_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_airy_Bi_deriv_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_Bi_deriv_scaled",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_Bi_deriv_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Ai_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_airy_zero_Ai_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Ai_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Ai_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Ai as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_airy_zero_Ai_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Ai",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Ai", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Bi_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_airy_zero_Bi_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Bi_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Bi_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Bi as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_airy_zero_Bi_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Bi",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Bi", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Ai_deriv_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_airy_zero_Ai_deriv_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Ai_deriv_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Ai_deriv_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Ai_deriv as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_airy_zero_Ai_deriv_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Ai_deriv",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Ai_deriv", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Bi_deriv_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_airy_zero_Bi_deriv_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Bi_deriv_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Bi_deriv_e", f);
/* Py_DECREF(f) */;

/*Using sf_airy_zero_Bi_deriv as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_airy_zero_Bi_deriv_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_airy_zero_Bi_deriv",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_airy_zero_Bi_deriv", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_J0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_J0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_J0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_J0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_J0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_J0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_J0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_J0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_J1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_J1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_J1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_J1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_J1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_J1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_J1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_J1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Jn_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_Jn_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Jn_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Jn_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Jn as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_Jn_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Jn",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Jn", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Y0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_Y0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Y0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Y0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Y0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_Y0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Y0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Y0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Y1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_Y1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Y1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Y1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Y1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_Y1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Y1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Y1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Yn_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_Yn_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Yn_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Yn_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Yn as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_Yn_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Yn",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Yn", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_I0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_I0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_I1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_I1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_In_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_In_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_In_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_In_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_In as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_In_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_In",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_In", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I0_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_I0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I0_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I0_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I0_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_I0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I0_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I0_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I1_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_I1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I1_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I1_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_I1_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_I1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_I1_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_I1_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_In_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_In_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_In_scaled_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_In_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_In_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_In_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_In_scaled",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_In_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_K0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_K0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_K1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_K1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Kn_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_Kn_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Kn_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Kn_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Kn as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_Kn_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Kn",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Kn", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K0_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_K0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K0_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K0_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K0_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_K0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K0_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K0_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K1_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_K1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K1_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K1_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_K1_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_K1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_K1_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_K1_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Kn_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_Kn_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Kn_scaled_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Kn_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Kn_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_Kn_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Kn_scaled",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Kn_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_j0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_j0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_j0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_j0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_j0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_j0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_j0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_j0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_j1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_j1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_j1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_j1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_j1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_j1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_j1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_j1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_j2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_j2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_j2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_j2_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_j2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_j2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_j2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_j2", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_jl_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_jl_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_jl_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_jl_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_jl as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_jl_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_jl",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_jl", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_y0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_y0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_y0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_y0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_y0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_y0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_y0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_y0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_y1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_y1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_y1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_y1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_y1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_y1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_y1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_y1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_y2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_y2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_y2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_y2_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_y2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_y2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_y2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_y2", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_yl_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_yl_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_yl_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_yl_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_yl as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_yl_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_yl",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_yl", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_i0_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_i0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_i0_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_i0_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_i0_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_i0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_i0_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_i0_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_i1_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_i1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_i1_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_i1_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_i1_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_i1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_i1_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_i1_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_i2_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_i2_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_i2_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_i2_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_i2_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_i2_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_i2_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_i2_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_il_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_il_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_il_scaled_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_il_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_il_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_il_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_il_scaled",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_il_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_k0_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_k0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_k0_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_k0_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_k0_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_k0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_k0_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_k0_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_k1_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_k1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_k1_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_k1_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_k1_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_k1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_k1_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_k1_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_k2_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_bessel_k2_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_k2_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_k2_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_k2_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_bessel_k2_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_k2_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_k2_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_kl_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_bessel_kl_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_kl_scaled_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_kl_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_kl_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_bessel_kl_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_kl_scaled",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_kl_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Jnu_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_Jnu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Jnu_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Jnu_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Jnu as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_Jnu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Jnu",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Jnu", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Ynu_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_Ynu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Ynu_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Ynu_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Ynu as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_Ynu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Ynu",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Ynu", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Inu_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_Inu_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Inu_scaled_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Inu_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Inu_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_Inu_scaled_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Inu_scaled",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Inu_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Inu_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_Inu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Inu_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Inu_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Inu as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_Inu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Inu",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Inu", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Knu_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_Knu_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Knu_scaled_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Knu_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Knu_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_Knu_scaled_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Knu_scaled",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Knu_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Knu_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_Knu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Knu_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Knu_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_Knu as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_Knu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_Knu",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_Knu", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_lnKnu_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_bessel_lnKnu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_lnKnu_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_lnKnu_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_lnKnu as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_bessel_lnKnu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_lnKnu",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_lnKnu", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_zero_J0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_bessel_zero_J0_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_zero_J0_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_zero_J0_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_zero_J0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_bessel_zero_J0_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_zero_J0",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_zero_J0", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_zero_J1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_bessel_zero_J1_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_zero_J1_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_zero_J1_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_zero_J1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_bessel_zero_J1_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_zero_J1",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_zero_J1", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_zero_Jnu_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dui_rd_one_data ,
                             sf_bessel_zero_Jnu_e_data,
                             PyGSL_sf_ufunc_qi_dui_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_bessel_zero_Jnu_e",
                             PyGSL_sf_ufunc_qi_dui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_zero_Jnu_e", f);
/* Py_DECREF(f) */;

/*Using sf_bessel_zero_Jnu as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dui__one_data ,
                             sf_bessel_zero_Jnu_data,
                             PyGSL_sf_ufunc_pd_dui__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_bessel_zero_Jnu",
                             PyGSL_sf_ufunc_pd_dui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_bessel_zero_Jnu", f);
/* Py_DECREF(f) */;

/*Using sf_clausen_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_clausen_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_clausen_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_clausen_e", f);
/* Py_DECREF(f) */;

/*Using sf_clausen as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_clausen_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_clausen",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_clausen", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_3j_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiii_rd_one_data ,
                             sf_coupling_3j_e_data,
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_coupling_3j_e",
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_3j_e", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_3j as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             sf_coupling_3j_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_coupling_3j",
                             PyGSL_sf_ufunc_pd_iiiiii__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_3j", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_6j_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiii_rd_one_data ,
                             sf_coupling_6j_e_data,
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_coupling_6j_e",
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_6j_e", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_6j as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             sf_coupling_6j_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_coupling_6j",
                             PyGSL_sf_ufunc_pd_iiiiii__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_6j", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_RacahW_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiii_rd_one_data ,
                             sf_coupling_RacahW_e_data,
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_coupling_RacahW_e",
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_RacahW_e", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_RacahW as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             sf_coupling_RacahW_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_coupling_RacahW",
                             PyGSL_sf_ufunc_pd_iiiiii__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_RacahW", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_9j_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_data ,
                             sf_coupling_9j_e_data,
                             PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_types,
                             2, /* number of supported types */
                             9, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_coupling_9j_e",
                             PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_9j_e", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_9j as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiiiiii__one_data ,
                             sf_coupling_9j_data,
                             PyGSL_sf_ufunc_pd_iiiiiiiii__one_types,
                             2, /* number of supported types */
                             9, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_coupling_9j",
                             PyGSL_sf_ufunc_pd_iiiiiiiii__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_9j", f);
/* Py_DECREF(f) */;

/*Using sf_coupling_6j_INCORRECT as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             sf_coupling_6j_INCORRECT_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_coupling_6j_INCORRECT",
                             PyGSL_sf_ufunc_pd_iiiiii__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coupling_6j_INCORRECT", f);
/* Py_DECREF(f) */;

/*Using sf_hydrogenicR_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_hydrogenicR_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hydrogenicR_1_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hydrogenicR_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_hydrogenicR_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_hydrogenicR_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hydrogenicR_1",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hydrogenicR_1", f);
/* Py_DECREF(f) */;

/*Using sf_hydrogenicR_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iidd_rd_one_data ,
                             sf_hydrogenicR_e_data,
                             PyGSL_sf_ufunc_qi_iidd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hydrogenicR_e",
                             PyGSL_sf_ufunc_qi_iidd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hydrogenicR_e", f);
/* Py_DECREF(f) */;

/*Using sf_hydrogenicR as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iidd__one_data ,
                             sf_hydrogenicR_data,
                             PyGSL_sf_ufunc_pd_iidd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hydrogenicR",
                             PyGSL_sf_ufunc_pd_iidd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hydrogenicR", f);
/* Py_DECREF(f) */;

/*Using sf_coulomb_wave_FG_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_data ,
                             sf_coulomb_wave_FG_e_data,
                             PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             10, /* out args */
                             PyUFunc_None,
                             "sf_coulomb_wave_FG_e",
                             PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coulomb_wave_FG_e", f);
/* Py_DECREF(f) */;

/*Using sf_coulomb_CL_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_coulomb_CL_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_coulomb_CL_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_coulomb_CL_e", f);
/* Py_DECREF(f) */;

/*Using sf_dawson_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_dawson_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_dawson_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_dawson_e", f);
/* Py_DECREF(f) */;

/*Using sf_dawson as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_dawson_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_dawson",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_dawson", f);
/* Py_DECREF(f) */;

/*Using sf_debye_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_debye_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_debye_1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_debye_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_debye_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_debye_1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_1", f);
/* Py_DECREF(f) */;

/*Using sf_debye_2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_debye_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_debye_2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_2_e", f);
/* Py_DECREF(f) */;

/*Using sf_debye_2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_debye_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_debye_2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_2", f);
/* Py_DECREF(f) */;

/*Using sf_debye_3_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_debye_3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_debye_3_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_3_e", f);
/* Py_DECREF(f) */;

/*Using sf_debye_3 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_debye_3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_debye_3",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_3", f);
/* Py_DECREF(f) */;

/*Using sf_debye_4_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_debye_4_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_debye_4_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_4_e", f);
/* Py_DECREF(f) */;

/*Using sf_debye_4 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_debye_4_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_debye_4",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_4", f);
/* Py_DECREF(f) */;

/*Using sf_debye_5_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_debye_5_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_debye_5_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_5_e", f);
/* Py_DECREF(f) */;

/*Using sf_debye_5 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_debye_5_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_debye_5",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_5", f);
/* Py_DECREF(f) */;

/*Using sf_debye_6_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_debye_6_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_debye_6_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_6_e", f);
/* Py_DECREF(f) */;

/*Using sf_debye_6 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_debye_6_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_debye_6",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_debye_6", f);
/* Py_DECREF(f) */;

/*Using sf_dilog_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_dilog_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_dilog_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_dilog_e", f);
/* Py_DECREF(f) */;

/*Using sf_dilog as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_dilog_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_dilog",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_dilog", f);
/* Py_DECREF(f) */;

/*Using sf_complex_dilog_xy_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rdrd_one_data ,
                             sf_complex_dilog_xy_e_data,
                             PyGSL_sf_ufunc_qi_dd_rdrd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             4, /* out args */
                             PyUFunc_None,
                             "sf_complex_dilog_xy_e",
                             PyGSL_sf_ufunc_qi_dd_rdrd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_complex_dilog_xy_e", f);
/* Py_DECREF(f) */;

/*Using sf_complex_spence_xy_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rdrd_one_data ,
                             sf_complex_spence_xy_e_data,
                             PyGSL_sf_ufunc_qi_dd_rdrd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             4, /* out args */
                             PyUFunc_None,
                             "sf_complex_spence_xy_e",
                             PyGSL_sf_ufunc_qi_dd_rdrd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_complex_spence_xy_e", f);
/* Py_DECREF(f) */;

/*Using sf_multiply_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_multiply_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_multiply_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_multiply_e", f);
/* Py_DECREF(f) */;

/*Using sf_multiply as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_multiply_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_multiply",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_multiply", f);
/* Py_DECREF(f) */;

/*Using sf_multiply_err_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             sf_multiply_err_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_multiply_err_e",
                             PyGSL_sf_ufunc_qi_dddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_multiply_err_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_Kcomp_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_ellint_Kcomp_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_Kcomp_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_Kcomp_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_Kcomp as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_ellint_Kcomp_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_Kcomp",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_Kcomp", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_Ecomp_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             sf_ellint_Ecomp_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_Ecomp_e",
                             PyGSL_sf_ufunc_qi_dm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_Ecomp_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_Ecomp as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             sf_ellint_Ecomp_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_Ecomp",
                             PyGSL_sf_ufunc_pd_dm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_Ecomp", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_F_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddm_rd_one_data ,
                             sf_ellint_F_e_data,
                             PyGSL_sf_ufunc_qi_ddm_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_F_e",
                             PyGSL_sf_ufunc_qi_ddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_F_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_F as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddm__one_data ,
                             sf_ellint_F_data,
                             PyGSL_sf_ufunc_pd_ddm__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_F",
                             PyGSL_sf_ufunc_pd_ddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_F", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_E_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddm_rd_one_data ,
                             sf_ellint_E_e_data,
                             PyGSL_sf_ufunc_qi_ddm_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_E_e",
                             PyGSL_sf_ufunc_qi_ddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_E_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_E as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddm__one_data ,
                             sf_ellint_E_data,
                             PyGSL_sf_ufunc_pd_ddm__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_E",
                             PyGSL_sf_ufunc_pd_ddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_E", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_P_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             sf_ellint_P_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_P_e",
                             PyGSL_sf_ufunc_qi_dddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_P_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_P as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             sf_ellint_P_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_P",
                             PyGSL_sf_ufunc_pd_dddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_P", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_D_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             sf_ellint_D_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_D_e",
                             PyGSL_sf_ufunc_qi_dddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_D_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_D as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             sf_ellint_D_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_D",
                             PyGSL_sf_ufunc_pd_dddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_D", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RC_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddm_rd_one_data ,
                             sf_ellint_RC_e_data,
                             PyGSL_sf_ufunc_qi_ddm_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RC_e",
                             PyGSL_sf_ufunc_qi_ddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RC_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RC as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddm__one_data ,
                             sf_ellint_RC_data,
                             PyGSL_sf_ufunc_pd_ddm__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RC",
                             PyGSL_sf_ufunc_pd_ddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RC", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RD_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             sf_ellint_RD_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RD_e",
                             PyGSL_sf_ufunc_qi_dddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RD_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RD as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             sf_ellint_RD_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RD",
                             PyGSL_sf_ufunc_pd_dddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RD", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RF_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             sf_ellint_RF_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RF_e",
                             PyGSL_sf_ufunc_qi_dddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RF_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RF as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             sf_ellint_RF_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RF",
                             PyGSL_sf_ufunc_pd_dddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RF", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RJ_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddddm_rd_one_data ,
                             sf_ellint_RJ_e_data,
                             PyGSL_sf_ufunc_qi_ddddm_rd_one_types,
                             2, /* number of supported types */
                             5, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RJ_e",
                             PyGSL_sf_ufunc_qi_ddddm_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RJ_e", f);
/* Py_DECREF(f) */;

/*Using sf_ellint_RJ as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddddm__one_data ,
                             sf_ellint_RJ_data,
                             PyGSL_sf_ufunc_pd_ddddm__one_types,
                             2, /* number of supported types */
                             5, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_ellint_RJ",
                             PyGSL_sf_ufunc_pd_ddddm__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_ellint_RJ", f);
/* Py_DECREF(f) */;

/*Using sf_elljac_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_ddd_one_data ,
                             sf_elljac_e_data,
                             PyGSL_sf_ufunc_qi_dd_ddd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "sf_elljac_e",
                             PyGSL_sf_ufunc_qi_dd_ddd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_elljac_e", f);
/* Py_DECREF(f) */;

/*Using sf_erfc_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_erfc_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_erfc_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erfc_e", f);
/* Py_DECREF(f) */;

/*Using sf_erfc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_erfc_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_erfc",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erfc", f);
/* Py_DECREF(f) */;

/*Using sf_log_erfc_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_log_erfc_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_log_erfc_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_erfc_e", f);
/* Py_DECREF(f) */;

/*Using sf_log_erfc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_log_erfc_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_log_erfc",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_erfc", f);
/* Py_DECREF(f) */;

/*Using sf_erf_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_erf_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_erf_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erf_e", f);
/* Py_DECREF(f) */;

/*Using sf_erf as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_erf_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_erf",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erf", f);
/* Py_DECREF(f) */;

/*Using sf_erf_Z_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_erf_Z_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_erf_Z_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erf_Z_e", f);
/* Py_DECREF(f) */;

/*Using sf_erf_Q_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_erf_Q_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_erf_Q_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erf_Q_e", f);
/* Py_DECREF(f) */;

/*Using sf_erf_Z as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_erf_Z_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_erf_Z",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erf_Z", f);
/* Py_DECREF(f) */;

/*Using sf_erf_Q as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_erf_Q_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_erf_Q",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_erf_Q", f);
/* Py_DECREF(f) */;

/*Using sf_hazard_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_hazard_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hazard_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hazard_e", f);
/* Py_DECREF(f) */;

/*Using sf_hazard as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_hazard_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hazard",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hazard", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_E1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_E1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E1_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_E1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_E1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E1", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_E2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_E2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E2_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_E2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_E2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E2", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E1_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_E1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_E1_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E1_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E1_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_E1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_E1_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E1_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E2_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_E2_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_E2_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E2_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_E2_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_E2_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_E2_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_E2_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_expint_Ei_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_Ei_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_Ei_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_Ei_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_Ei as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_Ei_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_Ei",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_Ei", f);
/* Py_DECREF(f) */;

/*Using sf_expint_Ei_scaled_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_Ei_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_Ei_scaled_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_Ei_scaled_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_Ei_scaled as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_Ei_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_Ei_scaled",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_Ei_scaled", f);
/* Py_DECREF(f) */;

/*Using sf_Shi_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_Shi_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_Shi_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Shi_e", f);
/* Py_DECREF(f) */;

/*Using sf_Shi as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_Shi_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_Shi",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Shi", f);
/* Py_DECREF(f) */;

/*Using sf_Chi_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_Chi_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_Chi_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Chi_e", f);
/* Py_DECREF(f) */;

/*Using sf_Chi as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_Chi_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_Chi",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Chi", f);
/* Py_DECREF(f) */;

/*Using sf_expint_3_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_expint_3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_expint_3_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_3_e", f);
/* Py_DECREF(f) */;

/*Using sf_expint_3 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_expint_3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_expint_3",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_expint_3", f);
/* Py_DECREF(f) */;

/*Using sf_Si_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_Si_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_Si_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Si_e", f);
/* Py_DECREF(f) */;

/*Using sf_Si as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_Si_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_Si",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Si", f);
/* Py_DECREF(f) */;

/*Using sf_Ci_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_Ci_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_Ci_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Ci_e", f);
/* Py_DECREF(f) */;

/*Using sf_Ci as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_Ci_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_Ci",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_Ci", f);
/* Py_DECREF(f) */;

/*Using sf_atanint_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_atanint_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_atanint_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_atanint_e", f);
/* Py_DECREF(f) */;

/*Using sf_atanint as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_atanint_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_atanint",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_atanint", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_m1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_m1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_m1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_m1_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_m1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_m1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_m1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_m1", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_0_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_0", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_1", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_2_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_2", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_fermi_dirac_int_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_int_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_fermi_dirac_int_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_int",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_int", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_mhalf_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_mhalf_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_mhalf_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_mhalf_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_mhalf as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_mhalf_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_mhalf",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_mhalf", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_half_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_half_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_half_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_half_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_half as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_half_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_half",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_half", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_3half_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_fermi_dirac_3half_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_3half_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_3half_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_3half as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_fermi_dirac_3half_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_3half",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_3half", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_inc_0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_fermi_dirac_inc_0_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_inc_0_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_inc_0_e", f);
/* Py_DECREF(f) */;

/*Using sf_fermi_dirac_inc_0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_fermi_dirac_inc_0_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fermi_dirac_inc_0",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fermi_dirac_inc_0", f);
/* Py_DECREF(f) */;

/*Using sf_lngamma_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_lngamma_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lngamma_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lngamma_e", f);
/* Py_DECREF(f) */;

/*Using sf_lngamma as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_lngamma_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lngamma",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lngamma", f);
/* Py_DECREF(f) */;

/*Using sf_lngamma_sgn_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rdd_one_data ,
                             sf_lngamma_sgn_e_data,
                             PyGSL_sf_ufunc_qi_d_rdd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "sf_lngamma_sgn_e",
                             PyGSL_sf_ufunc_qi_d_rdd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lngamma_sgn_e", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_gamma_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gamma_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_e", f);
/* Py_DECREF(f) */;

/*Using sf_gamma as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_gamma_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gamma",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma", f);
/* Py_DECREF(f) */;

/*Using sf_gammastar_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_gammastar_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gammastar_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gammastar_e", f);
/* Py_DECREF(f) */;

/*Using sf_gammastar as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_gammastar_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gammastar",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gammastar", f);
/* Py_DECREF(f) */;

/*Using sf_gammainv_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_gammainv_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gammainv_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gammainv_e", f);
/* Py_DECREF(f) */;

/*Using sf_gammainv as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_gammainv_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gammainv",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gammainv", f);
/* Py_DECREF(f) */;

/*Using sf_taylorcoeff_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_taylorcoeff_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_taylorcoeff_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_taylorcoeff_e", f);
/* Py_DECREF(f) */;

/*Using sf_taylorcoeff as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_taylorcoeff_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_taylorcoeff",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_taylorcoeff", f);
/* Py_DECREF(f) */;

/*Using sf_fact_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_fact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_fact_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fact_e", f);
/* Py_DECREF(f) */;

/*Using sf_fact as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_fact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_fact",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_fact", f);
/* Py_DECREF(f) */;

/*Using sf_doublefact_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_doublefact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_doublefact_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_doublefact_e", f);
/* Py_DECREF(f) */;

/*Using sf_doublefact as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_doublefact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_doublefact",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_doublefact", f);
/* Py_DECREF(f) */;

/*Using sf_lnfact_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_lnfact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lnfact_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnfact_e", f);
/* Py_DECREF(f) */;

/*Using sf_lnfact as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_lnfact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lnfact",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnfact", f);
/* Py_DECREF(f) */;

/*Using sf_lndoublefact_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             sf_lndoublefact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lndoublefact_e",
                             PyGSL_sf_ufunc_qi_ui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lndoublefact_e", f);
/* Py_DECREF(f) */;

/*Using sf_lndoublefact as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             sf_lndoublefact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lndoublefact",
                             PyGSL_sf_ufunc_pd_ui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lndoublefact", f);
/* Py_DECREF(f) */;

/*Using sf_lnchoose_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_uiui_rd_one_data ,
                             sf_lnchoose_e_data,
                             PyGSL_sf_ufunc_qi_uiui_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lnchoose_e",
                             PyGSL_sf_ufunc_qi_uiui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnchoose_e", f);
/* Py_DECREF(f) */;

/*Using sf_lnchoose as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_uiui__one_data ,
                             sf_lnchoose_data,
                             PyGSL_sf_ufunc_pd_uiui__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lnchoose",
                             PyGSL_sf_ufunc_pd_uiui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnchoose", f);
/* Py_DECREF(f) */;

/*Using sf_choose_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_uiui_rd_one_data ,
                             sf_choose_e_data,
                             PyGSL_sf_ufunc_qi_uiui_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_choose_e",
                             PyGSL_sf_ufunc_qi_uiui_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_choose_e", f);
/* Py_DECREF(f) */;

/*Using sf_choose as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_uiui__one_data ,
                             sf_choose_data,
                             PyGSL_sf_ufunc_pd_uiui__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_choose",
                             PyGSL_sf_ufunc_pd_uiui__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_choose", f);
/* Py_DECREF(f) */;

/*Using sf_lnpoch_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_lnpoch_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lnpoch_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnpoch_e", f);
/* Py_DECREF(f) */;

/*Using sf_lnpoch as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_lnpoch_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lnpoch",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnpoch", f);
/* Py_DECREF(f) */;

/*Using sf_lnpoch_sgn_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rdd_one_data ,
                             sf_lnpoch_sgn_e_data,
                             PyGSL_sf_ufunc_qi_dd_rdd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "sf_lnpoch_sgn_e",
                             PyGSL_sf_ufunc_qi_dd_rdd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnpoch_sgn_e", f);
/* Py_DECREF(f) */;

/*Using sf_poch_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_poch_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_poch_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_poch_e", f);
/* Py_DECREF(f) */;

/*Using sf_poch as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_poch_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_poch",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_poch", f);
/* Py_DECREF(f) */;

/*Using sf_pochrel_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_pochrel_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_pochrel_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_pochrel_e", f);
/* Py_DECREF(f) */;

/*Using sf_pochrel as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_pochrel_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_pochrel",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_pochrel", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_inc_Q_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_gamma_inc_Q_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gamma_inc_Q_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_inc_Q_e", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_inc_Q as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_gamma_inc_Q_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gamma_inc_Q",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_inc_Q", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_inc_P_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_gamma_inc_P_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gamma_inc_P_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_inc_P_e", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_inc_P as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_gamma_inc_P_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gamma_inc_P",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_inc_P", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_inc_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_gamma_inc_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gamma_inc_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_inc_e", f);
/* Py_DECREF(f) */;

/*Using sf_gamma_inc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_gamma_inc_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gamma_inc",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gamma_inc", f);
/* Py_DECREF(f) */;

/*Using sf_lnbeta_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_lnbeta_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lnbeta_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnbeta_e", f);
/* Py_DECREF(f) */;

/*Using sf_lnbeta as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_lnbeta_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lnbeta",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnbeta", f);
/* Py_DECREF(f) */;

/*Using sf_beta_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_beta_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_beta_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_beta_e", f);
/* Py_DECREF(f) */;

/*Using sf_beta as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_beta_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_beta",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_beta", f);
/* Py_DECREF(f) */;

/*Using sf_beta_inc_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             sf_beta_inc_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_beta_inc_e",
                             PyGSL_sf_ufunc_qi_ddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_beta_inc_e", f);
/* Py_DECREF(f) */;

/*Using sf_beta_inc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             sf_beta_inc_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_beta_inc",
                             PyGSL_sf_ufunc_pd_ddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_beta_inc", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_gegenpoly_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_1_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_gegenpoly_2_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_2_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_2_e", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_3_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_gegenpoly_3_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_3_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_3_e", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_gegenpoly_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_1",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_1", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_gegenpoly_2_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_2",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_2", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_3 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_gegenpoly_3_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_3",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_3", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_n_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             sf_gegenpoly_n_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_n_e",
                             PyGSL_sf_ufunc_qi_idd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_n_e", f);
/* Py_DECREF(f) */;

/*Using sf_gegenpoly_n as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             sf_gegenpoly_n_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_gegenpoly_n",
                             PyGSL_sf_ufunc_pd_idd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_gegenpoly_n", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_0F1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_hyperg_0F1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_0F1_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_0F1_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_0F1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_hyperg_0F1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_0F1",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_0F1", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_1F1_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             sf_hyperg_1F1_int_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_1F1_int_e",
                             PyGSL_sf_ufunc_qi_iid_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_1F1_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_1F1_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             sf_hyperg_1F1_int_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_1F1_int",
                             PyGSL_sf_ufunc_pd_iid__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_1F1_int", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_1F1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             sf_hyperg_1F1_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_1F1_e",
                             PyGSL_sf_ufunc_qi_ddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_1F1_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_1F1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             sf_hyperg_1F1_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_1F1",
                             PyGSL_sf_ufunc_pd_ddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_1F1", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_U_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             sf_hyperg_U_int_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_U_int_e",
                             PyGSL_sf_ufunc_qi_iid_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_U_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_U_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             sf_hyperg_U_int_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_U_int",
                             PyGSL_sf_ufunc_pd_iid__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_U_int", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_U_int_e10_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_erd_one_data ,
                             sf_hyperg_U_int_e10_e_data,
                             PyGSL_sf_ufunc_qi_iid_erd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_U_int_e10_e",
                             PyGSL_sf_ufunc_qi_iid_erd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_U_int_e10_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_U_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             sf_hyperg_U_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_U_e",
                             PyGSL_sf_ufunc_qi_ddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_U_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_U as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             sf_hyperg_U_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_U",
                             PyGSL_sf_ufunc_pd_ddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_U", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_U_e10_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_erd_one_data ,
                             sf_hyperg_U_e10_e_data,
                             PyGSL_sf_ufunc_qi_ddd_erd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_U_e10_e",
                             PyGSL_sf_ufunc_qi_ddd_erd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_U_e10_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             sf_hyperg_2F1_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_e",
                             PyGSL_sf_ufunc_qi_dddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             sf_hyperg_2F1_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1",
                             PyGSL_sf_ufunc_pd_dddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_conj_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             sf_hyperg_2F1_conj_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_conj_e",
                             PyGSL_sf_ufunc_qi_dddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_conj_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_conj as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             sf_hyperg_2F1_conj_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_conj",
                             PyGSL_sf_ufunc_pd_dddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_conj", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_renorm_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             sf_hyperg_2F1_renorm_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_renorm_e",
                             PyGSL_sf_ufunc_qi_dddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_renorm_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_renorm as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             sf_hyperg_2F1_renorm_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_renorm",
                             PyGSL_sf_ufunc_pd_dddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_renorm", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_conj_renorm_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             sf_hyperg_2F1_conj_renorm_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_conj_renorm_e",
                             PyGSL_sf_ufunc_qi_dddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_conj_renorm_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F1_conj_renorm as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             sf_hyperg_2F1_conj_renorm_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F1_conj_renorm",
                             PyGSL_sf_ufunc_pd_dddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F1_conj_renorm", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             sf_hyperg_2F0_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F0_e",
                             PyGSL_sf_ufunc_qi_ddd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F0_e", f);
/* Py_DECREF(f) */;

/*Using sf_hyperg_2F0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             sf_hyperg_2F0_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hyperg_2F0",
                             PyGSL_sf_ufunc_pd_ddd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hyperg_2F0", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_laguerre_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_1_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_laguerre_2_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_2_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_2_e", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_3_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_laguerre_3_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_3_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_3_e", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_laguerre_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_1",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_1", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_laguerre_2_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_2",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_2", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_3 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_laguerre_3_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_3",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_3", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_n_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             sf_laguerre_n_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_n_e",
                             PyGSL_sf_ufunc_qi_idd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_n_e", f);
/* Py_DECREF(f) */;

/*Using sf_laguerre_n as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             sf_laguerre_n_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_laguerre_n",
                             PyGSL_sf_ufunc_pd_idd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_laguerre_n", f);
/* Py_DECREF(f) */;

/*Using sf_lambert_W0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_lambert_W0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lambert_W0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lambert_W0_e", f);
/* Py_DECREF(f) */;

/*Using sf_lambert_W0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_lambert_W0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lambert_W0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lambert_W0", f);
/* Py_DECREF(f) */;

/*Using sf_lambert_Wm1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_lambert_Wm1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lambert_Wm1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lambert_Wm1_e", f);
/* Py_DECREF(f) */;

/*Using sf_lambert_Wm1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_lambert_Wm1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lambert_Wm1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lambert_Wm1", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Pl_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_legendre_Pl_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Pl_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Pl_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Pl as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_legendre_Pl_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Pl",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Pl", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_P1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_legendre_P1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_P1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_P1_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_P2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_legendre_P2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_P2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_P2_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_P3_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_legendre_P3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_P3_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_P3_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_P1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_legendre_P1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_P1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_P1", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_P2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_legendre_P2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_P2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_P2", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_P3 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_legendre_P3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_P3",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_P3", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Q0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_legendre_Q0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Q0_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Q0_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Q0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_legendre_Q0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Q0",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Q0", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Q1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_legendre_Q1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Q1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Q1_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Q1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_legendre_Q1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Q1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Q1", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Ql_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_legendre_Ql_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Ql_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Ql_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Ql as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_legendre_Ql_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Ql",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Ql", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Plm_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             sf_legendre_Plm_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Plm_e",
                             PyGSL_sf_ufunc_qi_iid_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Plm_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_Plm as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             sf_legendre_Plm_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_Plm",
                             PyGSL_sf_ufunc_pd_iid__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_Plm", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_sphPlm_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             sf_legendre_sphPlm_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_sphPlm_e",
                             PyGSL_sf_ufunc_qi_iid_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_sphPlm_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_sphPlm as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             sf_legendre_sphPlm_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_sphPlm",
                             PyGSL_sf_ufunc_pd_iid__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_sphPlm", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_half_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_conicalP_half_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_half_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_half_e", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_half as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_conicalP_half_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_half",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_half", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_mhalf_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_conicalP_mhalf_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_mhalf_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_mhalf_e", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_mhalf as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_conicalP_mhalf_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_mhalf",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_mhalf", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_conicalP_0_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_0_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_0_e", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_conicalP_0_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_0",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_0", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_conicalP_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_1_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_conicalP_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_1",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_1", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_sph_reg_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             sf_conicalP_sph_reg_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_sph_reg_e",
                             PyGSL_sf_ufunc_qi_idd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_sph_reg_e", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_sph_reg as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             sf_conicalP_sph_reg_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_sph_reg",
                             PyGSL_sf_ufunc_pd_idd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_sph_reg", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_cyl_reg_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             sf_conicalP_cyl_reg_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_cyl_reg_e",
                             PyGSL_sf_ufunc_qi_idd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_cyl_reg_e", f);
/* Py_DECREF(f) */;

/*Using sf_conicalP_cyl_reg as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             sf_conicalP_cyl_reg_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_conicalP_cyl_reg",
                             PyGSL_sf_ufunc_pd_idd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_conicalP_cyl_reg", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_H3d_0_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_legendre_H3d_0_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_H3d_0_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_H3d_0_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_H3d_0 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_legendre_H3d_0_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_H3d_0",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_H3d_0", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_H3d_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_legendre_H3d_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_H3d_1_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_H3d_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_H3d_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_legendre_H3d_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_H3d_1",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_H3d_1", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_H3d_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             sf_legendre_H3d_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_legendre_H3d_e",
                             PyGSL_sf_ufunc_qi_idd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_H3d_e", f);
/* Py_DECREF(f) */;

/*Using sf_legendre_H3d as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             sf_legendre_H3d_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_legendre_H3d",
                             PyGSL_sf_ufunc_pd_idd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_legendre_H3d", f);
/* Py_DECREF(f) */;

/*Using sf_log_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_log_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_log_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_e", f);
/* Py_DECREF(f) */;

/*Using sf_log as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_log_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_log",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log", f);
/* Py_DECREF(f) */;

/*Using sf_log_abs_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_log_abs_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_log_abs_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_abs_e", f);
/* Py_DECREF(f) */;

/*Using sf_log_abs as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_log_abs_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_log_abs",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_abs", f);
/* Py_DECREF(f) */;

/*Using sf_log_1plusx_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_log_1plusx_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_log_1plusx_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_1plusx_e", f);
/* Py_DECREF(f) */;

/*Using sf_log_1plusx as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_log_1plusx_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_log_1plusx",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_1plusx", f);
/* Py_DECREF(f) */;

/*Using sf_log_1plusx_mx_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_log_1plusx_mx_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_log_1plusx_mx_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_1plusx_mx_e", f);
/* Py_DECREF(f) */;

/*Using sf_log_1plusx_mx as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_log_1plusx_mx_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_log_1plusx_mx",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_log_1plusx_mx", f);
/* Py_DECREF(f) */;

/*Using sf_pow_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_di_rd_one_data ,
                             sf_pow_int_e_data,
                             PyGSL_sf_ufunc_qi_di_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_pow_int_e",
                             PyGSL_sf_ufunc_qi_di_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_pow_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_pow_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_di__one_data ,
                             sf_pow_int_data,
                             PyGSL_sf_ufunc_pd_di__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_pow_int",
                             PyGSL_sf_ufunc_pd_di__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_pow_int", f);
/* Py_DECREF(f) */;

/*Using sf_psi_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             sf_psi_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_psi_int_e",
                             PyGSL_sf_ufunc_qi_i_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_psi_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             sf_psi_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_psi_int",
                             PyGSL_sf_ufunc_pd_i__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_int", f);
/* Py_DECREF(f) */;

/*Using sf_psi_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_psi_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_psi_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_e", f);
/* Py_DECREF(f) */;

/*Using sf_psi as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_psi_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_psi",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi", f);
/* Py_DECREF(f) */;

/*Using sf_psi_1piy_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_psi_1piy_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_psi_1piy_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_1piy_e", f);
/* Py_DECREF(f) */;

/*Using sf_psi_1piy as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_psi_1piy_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_psi_1piy",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_1piy", f);
/* Py_DECREF(f) */;

/*Using sf_psi_1_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             sf_psi_1_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_psi_1_int_e",
                             PyGSL_sf_ufunc_qi_i_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_1_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_psi_1_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             sf_psi_1_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_psi_1_int",
                             PyGSL_sf_ufunc_pd_i__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_1_int", f);
/* Py_DECREF(f) */;

/*Using sf_psi_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_psi_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_psi_1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_psi_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_psi_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_psi_1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_1", f);
/* Py_DECREF(f) */;

/*Using sf_psi_n_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             sf_psi_n_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_psi_n_e",
                             PyGSL_sf_ufunc_qi_id_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_n_e", f);
/* Py_DECREF(f) */;

/*Using sf_psi_n as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             sf_psi_n_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_psi_n",
                             PyGSL_sf_ufunc_pd_id__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_psi_n", f);
/* Py_DECREF(f) */;

/*Using sf_synchrotron_1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_synchrotron_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_synchrotron_1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_synchrotron_1_e", f);
/* Py_DECREF(f) */;

/*Using sf_synchrotron_1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_synchrotron_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_synchrotron_1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_synchrotron_1", f);
/* Py_DECREF(f) */;

/*Using sf_synchrotron_2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_synchrotron_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_synchrotron_2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_synchrotron_2_e", f);
/* Py_DECREF(f) */;

/*Using sf_synchrotron_2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_synchrotron_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_synchrotron_2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_synchrotron_2", f);
/* Py_DECREF(f) */;

/*Using sf_transport_2_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_transport_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_transport_2_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_2_e", f);
/* Py_DECREF(f) */;

/*Using sf_transport_2 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_transport_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_transport_2",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_2", f);
/* Py_DECREF(f) */;

/*Using sf_transport_3_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_transport_3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_transport_3_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_3_e", f);
/* Py_DECREF(f) */;

/*Using sf_transport_3 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_transport_3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_transport_3",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_3", f);
/* Py_DECREF(f) */;

/*Using sf_transport_4_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_transport_4_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_transport_4_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_4_e", f);
/* Py_DECREF(f) */;

/*Using sf_transport_4 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_transport_4_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_transport_4",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_4", f);
/* Py_DECREF(f) */;

/*Using sf_transport_5_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_transport_5_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_transport_5_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_5_e", f);
/* Py_DECREF(f) */;

/*Using sf_transport_5 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_transport_5_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_transport_5",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_transport_5", f);
/* Py_DECREF(f) */;

/*Using sf_sin_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_sin_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_sin_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_sin_e", f);
/* Py_DECREF(f) */;

/*Using sf_sin as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_sin_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_sin",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_sin", f);
/* Py_DECREF(f) */;

/*Using sf_cos_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_cos_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_cos_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_cos_e", f);
/* Py_DECREF(f) */;

/*Using sf_cos as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_cos_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_cos",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_cos", f);
/* Py_DECREF(f) */;

/*Using sf_hypot_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_hypot_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hypot_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hypot_e", f);
/* Py_DECREF(f) */;

/*Using sf_hypot as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_hypot_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hypot",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hypot", f);
/* Py_DECREF(f) */;

/*Using sf_sinc_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_sinc_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_sinc_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_sinc_e", f);
/* Py_DECREF(f) */;

/*Using sf_sinc as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_sinc_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_sinc",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_sinc", f);
/* Py_DECREF(f) */;

/*Using sf_lnsinh_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_lnsinh_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lnsinh_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnsinh_e", f);
/* Py_DECREF(f) */;

/*Using sf_lnsinh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_lnsinh_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lnsinh",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lnsinh", f);
/* Py_DECREF(f) */;

/*Using sf_lncosh_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_lncosh_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_lncosh_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lncosh_e", f);
/* Py_DECREF(f) */;

/*Using sf_lncosh as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_lncosh_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_lncosh",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_lncosh", f);
/* Py_DECREF(f) */;

/*Using sf_sin_err_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_sin_err_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_sin_err_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_sin_err_e", f);
/* Py_DECREF(f) */;

/*Using sf_cos_err_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_cos_err_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_cos_err_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_cos_err_e", f);
/* Py_DECREF(f) */;

/*Using sf_angle_restrict_symm as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_angle_restrict_symm_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_angle_restrict_symm",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_angle_restrict_symm", f);
/* Py_DECREF(f) */;

/*Using sf_angle_restrict_pos as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_angle_restrict_pos_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_angle_restrict_pos",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_angle_restrict_pos", f);
/* Py_DECREF(f) */;

/*Using sf_angle_restrict_symm_err_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_angle_restrict_symm_err_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_angle_restrict_symm_err_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_angle_restrict_symm_err_e", f);
/* Py_DECREF(f) */;

/*Using sf_angle_restrict_pos_err_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_angle_restrict_pos_err_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_angle_restrict_pos_err_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_angle_restrict_pos_err_e", f);
/* Py_DECREF(f) */;

/*Using sf_zeta_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             sf_zeta_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_zeta_int_e",
                             PyGSL_sf_ufunc_qi_i_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zeta_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_zeta_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             sf_zeta_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_zeta_int",
                             PyGSL_sf_ufunc_pd_i__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zeta_int", f);
/* Py_DECREF(f) */;

/*Using sf_zeta_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_zeta_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_zeta_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zeta_e", f);
/* Py_DECREF(f) */;

/*Using sf_zeta as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_zeta_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_zeta",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zeta", f);
/* Py_DECREF(f) */;

/*Using sf_zetam1_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_zetam1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_zetam1_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zetam1_e", f);
/* Py_DECREF(f) */;

/*Using sf_zetam1 as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_zetam1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_zetam1",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zetam1", f);
/* Py_DECREF(f) */;

/*Using sf_zetam1_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             sf_zetam1_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_zetam1_int_e",
                             PyGSL_sf_ufunc_qi_i_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zetam1_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_zetam1_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             sf_zetam1_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_zetam1_int",
                             PyGSL_sf_ufunc_pd_i__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_zetam1_int", f);
/* Py_DECREF(f) */;

/*Using sf_hzeta_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sf_hzeta_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_hzeta_e",
                             PyGSL_sf_ufunc_qi_dd_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hzeta_e", f);
/* Py_DECREF(f) */;

/*Using sf_hzeta as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             sf_hzeta_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_hzeta",
                             PyGSL_sf_ufunc_pd_dd__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_hzeta", f);
/* Py_DECREF(f) */;

/*Using sf_eta_int_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             sf_eta_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_eta_int_e",
                             PyGSL_sf_ufunc_qi_i_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_eta_int_e", f);
/* Py_DECREF(f) */;

/*Using sf_eta_int as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             sf_eta_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_eta_int",
                             PyGSL_sf_ufunc_pd_i__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_eta_int", f);
/* Py_DECREF(f) */;

/*Using sf_eta_e as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sf_eta_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sf_eta_e",
                             PyGSL_sf_ufunc_qi_d_rd_one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_eta_e", f);
/* Py_DECREF(f) */;

/*Using sf_eta as pyton name*/
f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sf_eta_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sf_eta",
                             PyGSL_sf_ufunc_pd_d__one_doc ,
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sf_eta", f);
/* Py_DECREF(f) */;

PyGSL_sf_ufunc_pD_DD__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_DD__as_DD_;
PyGSL_sf_ufunc_pD_DD__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_DD_;

PyGSL_sf_ufunc_pD_D__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_D__as_D_;
PyGSL_sf_ufunc_pD_D__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_D_;

PyGSL_sf_ufunc_pD_Dd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_Df__as_Dd_;
PyGSL_sf_ufunc_pD_Dd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_Dd_;

PyGSL_sf_ufunc_pD_d__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_f__as_d_;
PyGSL_sf_ufunc_pD_d__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_d_;

PyGSL_sf_ufunc_pD_dd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_ff__as_dd_;
PyGSL_sf_ufunc_pD_dd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pD_dd_;

PyGSL_sf_ufunc_pd_D__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_D__as_D_;
PyGSL_sf_ufunc_pd_D__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_D_;

PyGSL_sf_ufunc_pd_d__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_f__as_d_;
PyGSL_sf_ufunc_pd_d__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_d_;

PyGSL_sf_ufunc_pd_dd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ff__as_dd_;
PyGSL_sf_ufunc_pd_dd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_dd_;

PyGSL_sf_ufunc_pd_ddd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_fff__as_ddd_;
PyGSL_sf_ufunc_pd_ddd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ddd_;

PyGSL_sf_ufunc_pd_dddd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ffff__as_dddd_;
PyGSL_sf_ufunc_pd_dddd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_dddd_;

PyGSL_sf_ufunc_pd_ddddm__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ffffm__as_ddddm_;
PyGSL_sf_ufunc_pd_ddddm__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ddddm_;

PyGSL_sf_ufunc_pd_dddm__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_fffm__as_dddm_;
PyGSL_sf_ufunc_pd_dddm__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_dddm_;

PyGSL_sf_ufunc_pd_ddm__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ffm__as_ddm_;
PyGSL_sf_ufunc_pd_ddm__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ddm_;

PyGSL_sf_ufunc_pd_di__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_fi__as_di_;
PyGSL_sf_ufunc_pd_di__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_di_;

PyGSL_sf_ufunc_pd_dm__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_fm__as_dm_;
PyGSL_sf_ufunc_pd_dm__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_dm_;

PyGSL_sf_ufunc_pd_dui__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_fui__as_dui_;
PyGSL_sf_ufunc_pd_dui__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_dui_;

PyGSL_sf_ufunc_pd_i__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_i__as_i_;
PyGSL_sf_ufunc_pd_i__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_i_;

PyGSL_sf_ufunc_pd_id__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_if__as_id_;
PyGSL_sf_ufunc_pd_id__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_id_;

PyGSL_sf_ufunc_pd_idd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iff__as_idd_;
PyGSL_sf_ufunc_pd_idd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_idd_;

PyGSL_sf_ufunc_pd_iid__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iif__as_iid_;
PyGSL_sf_ufunc_pd_iid__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iid_;

PyGSL_sf_ufunc_pd_iidd__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iiff__as_iidd_;
PyGSL_sf_ufunc_pd_iidd__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iidd_;

PyGSL_sf_ufunc_pd_iiiiii__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iiiiii__as_iiiiii_;
PyGSL_sf_ufunc_pd_iiiiii__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iiiiii_;

PyGSL_sf_ufunc_pd_iiiiiiiii__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iiiiiiiii__as_iiiiiiiii_;
PyGSL_sf_ufunc_pd_iiiiiiiii__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_iiiiiiiii_;

PyGSL_sf_ufunc_pd_ui__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ui__as_ui_;
PyGSL_sf_ufunc_pd_ui__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_ui_;

PyGSL_sf_ufunc_pd_uiui__one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_uiui__as_uiui_;
PyGSL_sf_ufunc_pd_uiui__one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_pd_uiui_;

PyGSL_sf_ufunc_qi_d_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_f_rf_as_d_rd;
PyGSL_sf_ufunc_qi_d_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_d_rd;

PyGSL_sf_ufunc_qi_d_rdd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_f_rff_as_d_rdd;
PyGSL_sf_ufunc_qi_d_rdd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_d_rdd;

PyGSL_sf_ufunc_qi_dd_ddd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ff_fff_as_dd_ddd;
PyGSL_sf_ufunc_qi_dd_ddd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dd_ddd;

PyGSL_sf_ufunc_qi_dd_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ff_rf_as_dd_rd;
PyGSL_sf_ufunc_qi_dd_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dd_rd;

PyGSL_sf_ufunc_qi_dd_rdd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ff_rff_as_dd_rdd;
PyGSL_sf_ufunc_qi_dd_rdd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dd_rdd;

PyGSL_sf_ufunc_qi_dd_rdrd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ff_rfrf_as_dd_rdrd;
PyGSL_sf_ufunc_qi_dd_rdrd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dd_rdrd;

PyGSL_sf_ufunc_qi_ddd_erd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fff_erf_as_ddd_erd;
PyGSL_sf_ufunc_qi_ddd_erd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ddd_erd;

PyGSL_sf_ufunc_qi_ddd_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fff_rf_as_ddd_rd;
PyGSL_sf_ufunc_qi_ddd_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ddd_rd;

PyGSL_sf_ufunc_qi_dddd_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ffff_rf_as_dddd_rd;
PyGSL_sf_ufunc_qi_dddd_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dddd_rd;

PyGSL_sf_ufunc_qi_ddddm_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ffffm_rf_as_ddddm_rd;
PyGSL_sf_ufunc_qi_ddddm_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ddddm_rd;

PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fffi_rfrfrfrfff_as_dddi_rdrdrdrddd;
PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd;

PyGSL_sf_ufunc_qi_dddm_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fffm_rf_as_dddm_rd;
PyGSL_sf_ufunc_qi_dddm_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dddm_rd;

PyGSL_sf_ufunc_qi_ddm_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ffm_rf_as_ddm_rd;
PyGSL_sf_ufunc_qi_ddm_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ddm_rd;

PyGSL_sf_ufunc_qi_di_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fi_rf_as_di_rd;
PyGSL_sf_ufunc_qi_di_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_di_rd;

PyGSL_sf_ufunc_qi_dm_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fm_rf_as_dm_rd;
PyGSL_sf_ufunc_qi_dm_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dm_rd;

PyGSL_sf_ufunc_qi_dui_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_fui_rf_as_dui_rd;
PyGSL_sf_ufunc_qi_dui_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_dui_rd;

PyGSL_sf_ufunc_qi_i_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_i_rf_as_i_rd;
PyGSL_sf_ufunc_qi_i_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_i_rd;

PyGSL_sf_ufunc_qi_id_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_if_rf_as_id_rd;
PyGSL_sf_ufunc_qi_id_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_id_rd;

PyGSL_sf_ufunc_qi_idd_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iff_rf_as_idd_rd;
PyGSL_sf_ufunc_qi_idd_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_idd_rd;

PyGSL_sf_ufunc_qi_iid_erd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iif_erf_as_iid_erd;
PyGSL_sf_ufunc_qi_iid_erd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iid_erd;

PyGSL_sf_ufunc_qi_iid_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iif_rf_as_iid_rd;
PyGSL_sf_ufunc_qi_iid_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iid_rd;

PyGSL_sf_ufunc_qi_iidd_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iiff_rf_as_iidd_rd;
PyGSL_sf_ufunc_qi_iidd_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iidd_rd;

PyGSL_sf_ufunc_qi_iiiiii_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iiiiii_rf_as_iiiiii_rd;
PyGSL_sf_ufunc_qi_iiiiii_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iiiiii_rd;

PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iiiiiiiii_rf_as_iiiiiiiii_rd;
PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_iiiiiiiii_rd;

PyGSL_sf_ufunc_qi_ui_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ui_rf_as_ui_rd;
PyGSL_sf_ufunc_qi_ui_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_ui_rd;

PyGSL_sf_ufunc_qi_uiui_rd_one_data[0] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_uiui_rf_as_uiui_rd;
PyGSL_sf_ufunc_qi_uiui_rd_one_data[1] = (PyUFuncGenericFunction) PyGSL_sf_ufunc_qi_uiui_rd;

