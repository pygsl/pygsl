f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Ai_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Ai_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Ai_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Ai",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Bi_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Bi_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Bi_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Bi",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Ai_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Ai_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Ai_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Ai_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Bi_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Bi_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Bi_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Bi_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Ai_deriv_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Ai_deriv_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_deriv_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Ai_deriv_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Ai_deriv",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_deriv", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Bi_deriv_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Bi_deriv_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_deriv_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Bi_deriv_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Bi_deriv",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_deriv", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Ai_deriv_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Ai_deriv_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_deriv_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Ai_deriv_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Ai_deriv_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Ai_deriv_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             airy_Bi_deriv_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_Bi_deriv_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_deriv_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             airy_Bi_deriv_scaled_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_Bi_deriv_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_Bi_deriv_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             airy_zero_Ai_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_zero_Ai_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Ai_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             airy_zero_Ai_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_zero_Ai",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Ai", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             airy_zero_Bi_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_zero_Bi_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Bi_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             airy_zero_Bi_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_zero_Bi",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Bi", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             airy_zero_Ai_deriv_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_zero_Ai_deriv_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Ai_deriv_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             airy_zero_Ai_deriv_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_zero_Ai_deriv",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Ai_deriv", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             airy_zero_Bi_deriv_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "airy_zero_Bi_deriv_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Bi_deriv_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             airy_zero_Bi_deriv_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "airy_zero_Bi_deriv",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "airy_zero_Bi_deriv", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_J0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_J0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_J0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_J0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_J0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_J0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_J1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_J1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_J1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_J1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_J1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_J1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_Jn_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Jn_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Jn_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_Jn_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Jn",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Jn", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_Y0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Y0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Y0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_Y0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Y0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Y0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_Y1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Y1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Y1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_Y1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Y1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Y1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_Yn_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Yn_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Yn_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_Yn_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Yn",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Yn", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_I0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_I0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_I0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_I0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_I1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_I1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_I1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_I1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_In_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_In_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_In_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_In_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_In",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_In", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_I0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_I0_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I0_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_I0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_I0_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I0_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_I1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_I1_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I1_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_I1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_I1_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_I1_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_In_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_In_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_In_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_In_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_In_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_In_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_K0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_K0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_K0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_K0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_K1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_K1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_K1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_K1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_Kn_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Kn_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Kn_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_Kn_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Kn",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Kn", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_K0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_K0_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K0_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_K0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_K0_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K0_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_K1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_K1_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K1_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_K1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_K1_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_K1_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_Kn_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Kn_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Kn_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_Kn_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Kn_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Kn_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_j0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_j0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_j0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_j0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_j0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_j0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_j1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_j1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_j1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_j1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_j1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_j1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_j2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_j2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_j2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_j2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_j2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_j2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_jl_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_jl_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_jl_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_jl_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_jl",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_jl", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_y0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_y0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_y0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_y0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_y0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_y0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_y1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_y1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_y1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_y1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_y1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_y1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_y2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_y2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_y2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_y2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_y2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_y2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_yl_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_yl_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_yl_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_yl_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_yl",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_yl", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_i0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_i0_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_i0_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_i0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_i0_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_i0_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_i1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_i1_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_i1_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_i1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_i1_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_i1_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_i2_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_i2_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_i2_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_i2_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_i2_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_i2_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_il_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_il_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_il_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_il_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_il_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_il_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_k0_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_k0_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_k0_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_k0_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_k0_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_k0_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_k1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_k1_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_k1_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_k1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_k1_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_k1_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             bessel_k2_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_k2_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_k2_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             bessel_k2_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_k2_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_k2_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             bessel_kl_scaled_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_kl_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_kl_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             bessel_kl_scaled_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_kl_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_kl_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_Jnu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Jnu_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Jnu_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_Jnu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Jnu",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Jnu", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_Ynu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Ynu_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Ynu_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_Ynu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Ynu",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Ynu", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_Inu_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Inu_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Inu_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_Inu_scaled_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Inu_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Inu_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_Inu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Inu_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Inu_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_Inu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Inu",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Inu", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_Knu_scaled_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Knu_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Knu_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_Knu_scaled_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Knu_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Knu_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_Knu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_Knu_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Knu_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_Knu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_Knu",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_Knu", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             bessel_lnKnu_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_lnKnu_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_lnKnu_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             bessel_lnKnu_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_lnKnu",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_lnKnu", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             bessel_zero_J0_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_zero_J0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_zero_J0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             bessel_zero_J0_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_zero_J0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_zero_J0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             bessel_zero_J1_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_zero_J1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_zero_J1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             bessel_zero_J1_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_zero_J1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_zero_J1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dui_rd_one_data ,
                             bessel_zero_Jnu_e_data,
                             PyGSL_sf_ufunc_qi_dui_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "bessel_zero_Jnu_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_zero_Jnu_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dui__one_data ,
                             bessel_zero_Jnu_data,
                             PyGSL_sf_ufunc_pd_dui__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "bessel_zero_Jnu",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "bessel_zero_Jnu", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             clausen_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "clausen_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "clausen_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             clausen_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "clausen",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "clausen", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiii_rd_one_data ,
                             coupling_3j_e_data,
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "coupling_3j_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_3j_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             coupling_3j_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "coupling_3j",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_3j", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiii_rd_one_data ,
                             coupling_6j_e_data,
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "coupling_6j_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_6j_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             coupling_6j_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "coupling_6j",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_6j", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiii_rd_one_data ,
                             coupling_RacahW_e_data,
                             PyGSL_sf_ufunc_qi_iiiiii_rd_one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "coupling_RacahW_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_RacahW_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiii__one_data ,
                             coupling_RacahW_data,
                             PyGSL_sf_ufunc_pd_iiiiii__one_types,
                             2, /* number of supported types */
                             6, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "coupling_RacahW",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_RacahW", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_data ,
                             coupling_9j_e_data,
                             PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_types,
                             2, /* number of supported types */
                             9, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "coupling_9j_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_9j_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iiiiiiiii__one_data ,
                             coupling_9j_data,
                             PyGSL_sf_ufunc_pd_iiiiiiiii__one_types,
                             2, /* number of supported types */
                             9, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "coupling_9j",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coupling_9j", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             hydrogenicR_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hydrogenicR_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hydrogenicR_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             hydrogenicR_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hydrogenicR_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hydrogenicR_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iidd_rd_one_data ,
                             hydrogenicR_e_data,
                             PyGSL_sf_ufunc_qi_iidd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hydrogenicR_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hydrogenicR_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iidd__one_data ,
                             hydrogenicR_data,
                             PyGSL_sf_ufunc_pd_iidd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hydrogenicR",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hydrogenicR", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_data ,
                             coulomb_wave_FG_e_data,
                             PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             10, /* out args */
                             PyUFunc_None,
                             "coulomb_wave_FG_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coulomb_wave_FG_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             coulomb_CL_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "coulomb_CL_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "coulomb_CL_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             dawson_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "dawson_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "dawson_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             dawson_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "dawson",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "dawson", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             debye_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "debye_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             debye_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "debye_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             debye_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "debye_2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             debye_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "debye_2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             debye_3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "debye_3_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_3_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             debye_3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "debye_3",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_3", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             debye_4_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "debye_4_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_4_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             debye_4_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "debye_4",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "debye_4", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             dilog_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "dilog_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "dilog_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             dilog_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "dilog",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "dilog", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             multiply_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "multiply_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "multiply_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             multiply_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "multiply",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "multiply", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             multiply_err_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "multiply_err_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "multiply_err_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             ellint_Kcomp_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_Kcomp_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_Kcomp_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             ellint_Kcomp_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_Kcomp",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_Kcomp", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dm_rd_one_data ,
                             ellint_Ecomp_e_data,
                             PyGSL_sf_ufunc_qi_dm_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_Ecomp_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_Ecomp_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dm__one_data ,
                             ellint_Ecomp_data,
                             PyGSL_sf_ufunc_pd_dm__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_Ecomp",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_Ecomp", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddm_rd_one_data ,
                             ellint_F_e_data,
                             PyGSL_sf_ufunc_qi_ddm_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_F_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_F_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddm__one_data ,
                             ellint_F_data,
                             PyGSL_sf_ufunc_pd_ddm__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_F",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_F", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddm_rd_one_data ,
                             ellint_E_e_data,
                             PyGSL_sf_ufunc_qi_ddm_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_E_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_E_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddm__one_data ,
                             ellint_E_data,
                             PyGSL_sf_ufunc_pd_ddm__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_E",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_E", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             ellint_P_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_P_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_P_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             ellint_P_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_P",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_P", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             ellint_D_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_D_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_D_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             ellint_D_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_D",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_D", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddm_rd_one_data ,
                             ellint_RC_e_data,
                             PyGSL_sf_ufunc_qi_ddm_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_RC_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RC_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddm__one_data ,
                             ellint_RC_data,
                             PyGSL_sf_ufunc_pd_ddm__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_RC",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RC", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             ellint_RD_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_RD_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RD_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             ellint_RD_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_RD",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RD", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddm_rd_one_data ,
                             ellint_RF_e_data,
                             PyGSL_sf_ufunc_qi_dddm_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_RF_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RF_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddm__one_data ,
                             ellint_RF_data,
                             PyGSL_sf_ufunc_pd_dddm__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_RF",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RF", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddddm_rd_one_data ,
                             ellint_RJ_e_data,
                             PyGSL_sf_ufunc_qi_ddddm_rd_one_types,
                             2, /* number of supported types */
                             5, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "ellint_RJ_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RJ_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddddm__one_data ,
                             ellint_RJ_data,
                             PyGSL_sf_ufunc_pd_ddddm__one_types,
                             2, /* number of supported types */
                             5, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "ellint_RJ",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "ellint_RJ", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_ddd_one_data ,
                             elljac_e_data,
                             PyGSL_sf_ufunc_qi_dd_ddd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "elljac_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "elljac_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             erfc_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "erfc_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erfc_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             erfc_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "erfc",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erfc", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             log_erfc_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "log_erfc_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_erfc_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             log_erfc_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "log_erfc",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_erfc", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             erf_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "erf_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erf_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             erf_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "erf",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erf", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             erf_Z_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "erf_Z_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erf_Z_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             erf_Q_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "erf_Q_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erf_Q_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             erf_Z_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "erf_Z",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erf_Z", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             erf_Q_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "erf_Q",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "erf_Q", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_E1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_E1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_E1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_E1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_E2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_E2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_E2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_E2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_E1_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_E1_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E1_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_E1_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_E1_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E1_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_E2_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_E2_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E2_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_E2_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_E2_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_E2_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_Ei_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_Ei_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_Ei_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_Ei_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_Ei",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_Ei", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_Ei_scaled_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_Ei_scaled_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_Ei_scaled_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_Ei_scaled_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_Ei_scaled",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_Ei_scaled", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             Shi_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "Shi_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Shi_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             Shi_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "Shi",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Shi", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             Chi_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "Chi_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Chi_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             Chi_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "Chi",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Chi", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             expint_3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "expint_3_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_3_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             expint_3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "expint_3",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "expint_3", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             Si_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "Si_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Si_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             Si_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "Si",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Si", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             Ci_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "Ci_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Ci_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             Ci_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "Ci",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "Ci", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             atanint_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "atanint_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "atanint_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             atanint_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "atanint",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "atanint", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_m1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_m1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_m1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_m1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_m1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_m1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             fermi_dirac_int_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             fermi_dirac_int_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_mhalf_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_mhalf_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_mhalf_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_mhalf_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_mhalf",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_mhalf", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_half_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_half_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_half_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_half_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_half",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_half", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             fermi_dirac_3half_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_3half_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_3half_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             fermi_dirac_3half_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_3half",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_3half", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             fermi_dirac_inc_0_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_inc_0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_inc_0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             fermi_dirac_inc_0_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fermi_dirac_inc_0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fermi_dirac_inc_0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             lngamma_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lngamma_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lngamma_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             lngamma_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lngamma",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lngamma", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rdd_one_data ,
                             lngamma_sgn_e_data,
                             PyGSL_sf_ufunc_qi_d_rdd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "lngamma_sgn_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lngamma_sgn_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             gamma_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gamma_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gamma_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             gamma_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gamma",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gamma", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             gammastar_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gammastar_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gammastar_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             gammastar_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gammastar",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gammastar", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             gammainv_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gammainv_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gammainv_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             gammainv_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gammainv",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gammainv", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             taylorcoeff_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "taylorcoeff_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "taylorcoeff_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             taylorcoeff_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "taylorcoeff",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "taylorcoeff", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             fact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "fact_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fact_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             fact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "fact",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "fact", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             doublefact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "doublefact_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "doublefact_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             doublefact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "doublefact",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "doublefact", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             lnfact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lnfact_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnfact_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             lnfact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lnfact",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnfact", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ui_rd_one_data ,
                             lndoublefact_e_data,
                             PyGSL_sf_ufunc_qi_ui_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lndoublefact_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lndoublefact_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ui__one_data ,
                             lndoublefact_data,
                             PyGSL_sf_ufunc_pd_ui__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lndoublefact",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lndoublefact", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_uiui_rd_one_data ,
                             lnchoose_e_data,
                             PyGSL_sf_ufunc_qi_uiui_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lnchoose_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnchoose_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_uiui__one_data ,
                             lnchoose_data,
                             PyGSL_sf_ufunc_pd_uiui__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lnchoose",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnchoose", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_uiui_rd_one_data ,
                             choose_e_data,
                             PyGSL_sf_ufunc_qi_uiui_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "choose_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "choose_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_uiui__one_data ,
                             choose_data,
                             PyGSL_sf_ufunc_pd_uiui__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "choose",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "choose", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             lnpoch_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lnpoch_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnpoch_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             lnpoch_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lnpoch",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnpoch", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rdd_one_data ,
                             lnpoch_sgn_e_data,
                             PyGSL_sf_ufunc_qi_dd_rdd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "lnpoch_sgn_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnpoch_sgn_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             poch_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "poch_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "poch_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             poch_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "poch",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "poch", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             pochrel_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "pochrel_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "pochrel_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             pochrel_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "pochrel",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "pochrel", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             gamma_inc_Q_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gamma_inc_Q_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gamma_inc_Q_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             gamma_inc_Q_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gamma_inc_Q",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gamma_inc_Q", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             gamma_inc_P_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gamma_inc_P_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gamma_inc_P_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             gamma_inc_P_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gamma_inc_P",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gamma_inc_P", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             lnbeta_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lnbeta_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnbeta_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             lnbeta_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lnbeta",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnbeta", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             beta_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "beta_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "beta_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             beta_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "beta",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "beta", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             beta_inc_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "beta_inc_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "beta_inc_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             beta_inc_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "beta_inc",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "beta_inc", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             gegenpoly_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gegenpoly_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             gegenpoly_2_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gegenpoly_2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             gegenpoly_3_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gegenpoly_3_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_3_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             gegenpoly_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gegenpoly_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             gegenpoly_2_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gegenpoly_2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             gegenpoly_3_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gegenpoly_3",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_3", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             gegenpoly_n_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "gegenpoly_n_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_n_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             gegenpoly_n_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "gegenpoly_n",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "gegenpoly_n", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             hyperg_0F1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_0F1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_0F1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             hyperg_0F1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_0F1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_0F1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             hyperg_1F1_int_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_1F1_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_1F1_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             hyperg_1F1_int_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_1F1_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_1F1_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             hyperg_1F1_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_1F1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_1F1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             hyperg_1F1_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_1F1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_1F1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             hyperg_U_int_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_U_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_U_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             hyperg_U_int_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_U_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_U_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_erd_one_data ,
                             hyperg_U_int_e10_e_data,
                             PyGSL_sf_ufunc_qi_iid_erd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "hyperg_U_int_e10_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_U_int_e10_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             hyperg_U_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_U_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_U_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             hyperg_U_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_U",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_U", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_erd_one_data ,
                             hyperg_U_e10_e_data,
                             PyGSL_sf_ufunc_qi_ddd_erd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             3, /* out args */
                             PyUFunc_None,
                             "hyperg_U_e10_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_U_e10_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             hyperg_2F1_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             hyperg_2F1_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             hyperg_2F1_conj_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_conj_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_conj_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             hyperg_2F1_conj_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_conj",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_conj", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             hyperg_2F1_renorm_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_renorm_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_renorm_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             hyperg_2F1_renorm_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_renorm",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_renorm", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dddd_rd_one_data ,
                             hyperg_2F1_conj_renorm_e_data,
                             PyGSL_sf_ufunc_qi_dddd_rd_one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_conj_renorm_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_conj_renorm_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dddd__one_data ,
                             hyperg_2F1_conj_renorm_data,
                             PyGSL_sf_ufunc_pd_dddd__one_types,
                             2, /* number of supported types */
                             4, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_2F1_conj_renorm",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F1_conj_renorm", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_ddd_rd_one_data ,
                             hyperg_2F0_e_data,
                             PyGSL_sf_ufunc_qi_ddd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hyperg_2F0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_ddd__one_data ,
                             hyperg_2F0_data,
                             PyGSL_sf_ufunc_pd_ddd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hyperg_2F0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hyperg_2F0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             laguerre_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "laguerre_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             laguerre_2_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "laguerre_2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             laguerre_3_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "laguerre_3_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_3_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             laguerre_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "laguerre_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             laguerre_2_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "laguerre_2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             laguerre_3_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "laguerre_3",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_3", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             laguerre_n_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "laguerre_n_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_n_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             laguerre_n_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "laguerre_n",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "laguerre_n", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             lambert_W0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lambert_W0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lambert_W0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             lambert_W0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lambert_W0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lambert_W0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             lambert_Wm1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lambert_Wm1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lambert_Wm1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             lambert_Wm1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lambert_Wm1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lambert_Wm1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             legendre_Pl_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_Pl_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Pl_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             legendre_Pl_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_Pl",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Pl", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             legendre_P1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_P1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_P1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             legendre_P2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_P2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_P2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             legendre_P3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_P3_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_P3_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             legendre_P1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_P1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_P1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             legendre_P2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_P2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_P2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             legendre_P3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_P3",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_P3", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             legendre_Q0_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_Q0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Q0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             legendre_Q0_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_Q0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Q0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             legendre_Q1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_Q1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Q1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             legendre_Q1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_Q1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Q1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             legendre_Ql_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_Ql_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Ql_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             legendre_Ql_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_Ql",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Ql", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             legendre_Plm_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_Plm_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Plm_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             legendre_Plm_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_Plm",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_Plm", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_iid_rd_one_data ,
                             legendre_sphPlm_e_data,
                             PyGSL_sf_ufunc_qi_iid_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_sphPlm_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_sphPlm_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_iid__one_data ,
                             legendre_sphPlm_data,
                             PyGSL_sf_ufunc_pd_iid__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_sphPlm",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_sphPlm", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             conicalP_half_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "conicalP_half_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_half_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             conicalP_half_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "conicalP_half",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_half", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             conicalP_mhalf_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "conicalP_mhalf_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_mhalf_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             conicalP_mhalf_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "conicalP_mhalf",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_mhalf", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             conicalP_0_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "conicalP_0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             conicalP_0_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "conicalP_0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             conicalP_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "conicalP_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             conicalP_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "conicalP_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             conicalP_sph_reg_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "conicalP_sph_reg_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_sph_reg_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             conicalP_sph_reg_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "conicalP_sph_reg",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_sph_reg", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             conicalP_cyl_reg_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "conicalP_cyl_reg_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_cyl_reg_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             conicalP_cyl_reg_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "conicalP_cyl_reg",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "conicalP_cyl_reg", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             legendre_H3d_0_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_H3d_0_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_H3d_0_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             legendre_H3d_0_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_H3d_0",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_H3d_0", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             legendre_H3d_1_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_H3d_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_H3d_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             legendre_H3d_1_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_H3d_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_H3d_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_idd_rd_one_data ,
                             legendre_H3d_e_data,
                             PyGSL_sf_ufunc_qi_idd_rd_one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "legendre_H3d_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_H3d_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_idd__one_data ,
                             legendre_H3d_data,
                             PyGSL_sf_ufunc_pd_idd__one_types,
                             2, /* number of supported types */
                             3, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "legendre_H3d",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "legendre_H3d", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             log_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "log_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             log_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "log",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             log_abs_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "log_abs_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_abs_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             log_abs_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "log_abs",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_abs", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             log_1plusx_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "log_1plusx_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_1plusx_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             log_1plusx_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "log_1plusx",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_1plusx", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             log_1plusx_mx_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "log_1plusx_mx_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_1plusx_mx_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             log_1plusx_mx_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "log_1plusx_mx",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "log_1plusx_mx", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_di_rd_one_data ,
                             pow_int_e_data,
                             PyGSL_sf_ufunc_qi_di_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "pow_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "pow_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_di__one_data ,
                             pow_int_data,
                             PyGSL_sf_ufunc_pd_di__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "pow_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "pow_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             psi_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "psi_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             psi_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "psi_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             psi_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "psi_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             psi_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "psi",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             psi_1piy_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "psi_1piy_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_1piy_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             psi_1piy_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "psi_1piy",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_1piy", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             psi_1_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "psi_1_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_1_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             psi_1_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "psi_1_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_1_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_id_rd_one_data ,
                             psi_n_e_data,
                             PyGSL_sf_ufunc_qi_id_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "psi_n_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_n_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_id__one_data ,
                             psi_n_data,
                             PyGSL_sf_ufunc_pd_id__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "psi_n",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "psi_n", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             synchrotron_1_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "synchrotron_1_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "synchrotron_1_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             synchrotron_1_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "synchrotron_1",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "synchrotron_1", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             synchrotron_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "synchrotron_2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "synchrotron_2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             synchrotron_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "synchrotron_2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "synchrotron_2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             transport_2_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "transport_2_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_2_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             transport_2_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "transport_2",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_2", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             transport_3_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "transport_3_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_3_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             transport_3_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "transport_3",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_3", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             transport_4_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "transport_4_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_4_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             transport_4_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "transport_4",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_4", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             transport_5_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "transport_5_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_5_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             transport_5_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "transport_5",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "transport_5", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sin_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sin_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sin_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sin_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sin",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sin", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             cos_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "cos_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "cos_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             cos_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "cos",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "cos", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             hypot_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hypot_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hypot_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             hypot_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hypot",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hypot", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             sinc_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sinc_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sinc_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             sinc_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "sinc",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sinc", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             lnsinh_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lnsinh_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnsinh_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             lnsinh_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lnsinh",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lnsinh", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             lncosh_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "lncosh_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lncosh_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             lncosh_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "lncosh",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "lncosh", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             sin_err_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "sin_err_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "sin_err_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             cos_err_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "cos_err_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "cos_err_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             angle_restrict_symm_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "angle_restrict_symm",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "angle_restrict_symm", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             angle_restrict_pos_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "angle_restrict_pos",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "angle_restrict_pos", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             angle_restrict_symm_err_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "angle_restrict_symm_err_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "angle_restrict_symm_err_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             angle_restrict_pos_err_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "angle_restrict_pos_err_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "angle_restrict_pos_err_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             zeta_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "zeta_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "zeta_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             zeta_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "zeta_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "zeta_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             zeta_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "zeta_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "zeta_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             zeta_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "zeta",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "zeta", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_dd_rd_one_data ,
                             hzeta_e_data,
                             PyGSL_sf_ufunc_qi_dd_rd_one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "hzeta_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hzeta_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_dd__one_data ,
                             hzeta_data,
                             PyGSL_sf_ufunc_pd_dd__one_types,
                             2, /* number of supported types */
                             2, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "hzeta",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "hzeta", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_i_rd_one_data ,
                             eta_int_e_data,
                             PyGSL_sf_ufunc_qi_i_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "eta_int_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "eta_int_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_i__one_data ,
                             eta_int_data,
                             PyGSL_sf_ufunc_pd_i__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "eta_int",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "eta_int", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_qi_d_rd_one_data ,
                             eta_e_data,
                             PyGSL_sf_ufunc_qi_d_rd_one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             2, /* out args */
                             PyUFunc_None,
                             "eta_e",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "eta_e", f);
Py_DECREF(f);

f = PyUFunc_FromFuncAndData( PyGSL_sf_ufunc_pd_d__one_data ,
                             eta_data,
                             PyGSL_sf_ufunc_pd_d__one_types,
                             2, /* number of supported types */
                             1, /* in args */
                             1, /* out args */
                             PyUFunc_None,
                             "eta",
                             NULL, /* doc string */
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict, "eta", f);
Py_DECREF(f);

PyGSL_sf_ufunc_pd_d__one_data[0] = PyGSL_sf_ufunc_pd_f__as_d_;
PyGSL_sf_ufunc_pd_d__one_data[1] = PyGSL_sf_ufunc_pd_d_;

PyGSL_sf_ufunc_pd_dd__one_data[0] = PyGSL_sf_ufunc_pd_ff__as_dd_;
PyGSL_sf_ufunc_pd_dd__one_data[1] = PyGSL_sf_ufunc_pd_dd_;

PyGSL_sf_ufunc_pd_ddd__one_data[0] = PyGSL_sf_ufunc_pd_fff__as_ddd_;
PyGSL_sf_ufunc_pd_ddd__one_data[1] = PyGSL_sf_ufunc_pd_ddd_;

PyGSL_sf_ufunc_pd_dddd__one_data[0] = PyGSL_sf_ufunc_pd_ffff__as_dddd_;
PyGSL_sf_ufunc_pd_dddd__one_data[1] = PyGSL_sf_ufunc_pd_dddd_;

PyGSL_sf_ufunc_pd_ddddm__one_data[0] = PyGSL_sf_ufunc_pd_ffffm__as_ddddm_;
PyGSL_sf_ufunc_pd_ddddm__one_data[1] = PyGSL_sf_ufunc_pd_ddddm_;

PyGSL_sf_ufunc_pd_dddm__one_data[0] = PyGSL_sf_ufunc_pd_fffm__as_dddm_;
PyGSL_sf_ufunc_pd_dddm__one_data[1] = PyGSL_sf_ufunc_pd_dddm_;

PyGSL_sf_ufunc_pd_ddm__one_data[0] = PyGSL_sf_ufunc_pd_ffm__as_ddm_;
PyGSL_sf_ufunc_pd_ddm__one_data[1] = PyGSL_sf_ufunc_pd_ddm_;

PyGSL_sf_ufunc_pd_di__one_data[0] = PyGSL_sf_ufunc_pd_fi__as_di_;
PyGSL_sf_ufunc_pd_di__one_data[1] = PyGSL_sf_ufunc_pd_di_;

PyGSL_sf_ufunc_pd_dm__one_data[0] = PyGSL_sf_ufunc_pd_fm__as_dm_;
PyGSL_sf_ufunc_pd_dm__one_data[1] = PyGSL_sf_ufunc_pd_dm_;

PyGSL_sf_ufunc_pd_dui__one_data[0] = PyGSL_sf_ufunc_pd_fui__as_dui_;
PyGSL_sf_ufunc_pd_dui__one_data[1] = PyGSL_sf_ufunc_pd_dui_;

PyGSL_sf_ufunc_pd_i__one_data[0] = PyGSL_sf_ufunc_pd_i__as_i_;
PyGSL_sf_ufunc_pd_i__one_data[1] = PyGSL_sf_ufunc_pd_i_;

PyGSL_sf_ufunc_pd_id__one_data[0] = PyGSL_sf_ufunc_pd_if__as_id_;
PyGSL_sf_ufunc_pd_id__one_data[1] = PyGSL_sf_ufunc_pd_id_;

PyGSL_sf_ufunc_pd_idd__one_data[0] = PyGSL_sf_ufunc_pd_iff__as_idd_;
PyGSL_sf_ufunc_pd_idd__one_data[1] = PyGSL_sf_ufunc_pd_idd_;

PyGSL_sf_ufunc_pd_iid__one_data[0] = PyGSL_sf_ufunc_pd_iif__as_iid_;
PyGSL_sf_ufunc_pd_iid__one_data[1] = PyGSL_sf_ufunc_pd_iid_;

PyGSL_sf_ufunc_pd_iidd__one_data[0] = PyGSL_sf_ufunc_pd_iiff__as_iidd_;
PyGSL_sf_ufunc_pd_iidd__one_data[1] = PyGSL_sf_ufunc_pd_iidd_;

PyGSL_sf_ufunc_pd_iiiiii__one_data[0] = PyGSL_sf_ufunc_pd_iiiiii__as_iiiiii_;
PyGSL_sf_ufunc_pd_iiiiii__one_data[1] = PyGSL_sf_ufunc_pd_iiiiii_;

PyGSL_sf_ufunc_pd_iiiiiiiii__one_data[0] = PyGSL_sf_ufunc_pd_iiiiiiiii__as_iiiiiiiii_;
PyGSL_sf_ufunc_pd_iiiiiiiii__one_data[1] = PyGSL_sf_ufunc_pd_iiiiiiiii_;

PyGSL_sf_ufunc_pd_ui__one_data[0] = PyGSL_sf_ufunc_pd_ui__as_ui_;
PyGSL_sf_ufunc_pd_ui__one_data[1] = PyGSL_sf_ufunc_pd_ui_;

PyGSL_sf_ufunc_pd_uiui__one_data[0] = PyGSL_sf_ufunc_pd_uiui__as_uiui_;
PyGSL_sf_ufunc_pd_uiui__one_data[1] = PyGSL_sf_ufunc_pd_uiui_;

PyGSL_sf_ufunc_qi_d_rd_one_data[0] = PyGSL_sf_ufunc_qi_f_rf_as_d_rd;
PyGSL_sf_ufunc_qi_d_rd_one_data[1] = PyGSL_sf_ufunc_qi_d_rd;

PyGSL_sf_ufunc_qi_d_rdd_one_data[0] = PyGSL_sf_ufunc_qi_f_rff_as_d_rdd;
PyGSL_sf_ufunc_qi_d_rdd_one_data[1] = PyGSL_sf_ufunc_qi_d_rdd;

PyGSL_sf_ufunc_qi_dd_ddd_one_data[0] = PyGSL_sf_ufunc_qi_ff_fff_as_dd_ddd;
PyGSL_sf_ufunc_qi_dd_ddd_one_data[1] = PyGSL_sf_ufunc_qi_dd_ddd;

PyGSL_sf_ufunc_qi_dd_rd_one_data[0] = PyGSL_sf_ufunc_qi_ff_rf_as_dd_rd;
PyGSL_sf_ufunc_qi_dd_rd_one_data[1] = PyGSL_sf_ufunc_qi_dd_rd;

PyGSL_sf_ufunc_qi_dd_rdd_one_data[0] = PyGSL_sf_ufunc_qi_ff_rff_as_dd_rdd;
PyGSL_sf_ufunc_qi_dd_rdd_one_data[1] = PyGSL_sf_ufunc_qi_dd_rdd;

PyGSL_sf_ufunc_qi_ddd_erd_one_data[0] = PyGSL_sf_ufunc_qi_fff_erf_as_ddd_erd;
PyGSL_sf_ufunc_qi_ddd_erd_one_data[1] = PyGSL_sf_ufunc_qi_ddd_erd;

PyGSL_sf_ufunc_qi_ddd_rd_one_data[0] = PyGSL_sf_ufunc_qi_fff_rf_as_ddd_rd;
PyGSL_sf_ufunc_qi_ddd_rd_one_data[1] = PyGSL_sf_ufunc_qi_ddd_rd;

PyGSL_sf_ufunc_qi_dddd_rd_one_data[0] = PyGSL_sf_ufunc_qi_ffff_rf_as_dddd_rd;
PyGSL_sf_ufunc_qi_dddd_rd_one_data[1] = PyGSL_sf_ufunc_qi_dddd_rd;

PyGSL_sf_ufunc_qi_ddddm_rd_one_data[0] = PyGSL_sf_ufunc_qi_ffffm_rf_as_ddddm_rd;
PyGSL_sf_ufunc_qi_ddddm_rd_one_data[1] = PyGSL_sf_ufunc_qi_ddddm_rd;

PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_data[0] = PyGSL_sf_ufunc_qi_fffi_rfrfrfrfff_as_dddi_rdrdrdrddd;
PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one_data[1] = PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd;

PyGSL_sf_ufunc_qi_dddm_rd_one_data[0] = PyGSL_sf_ufunc_qi_fffm_rf_as_dddm_rd;
PyGSL_sf_ufunc_qi_dddm_rd_one_data[1] = PyGSL_sf_ufunc_qi_dddm_rd;

PyGSL_sf_ufunc_qi_ddm_rd_one_data[0] = PyGSL_sf_ufunc_qi_ffm_rf_as_ddm_rd;
PyGSL_sf_ufunc_qi_ddm_rd_one_data[1] = PyGSL_sf_ufunc_qi_ddm_rd;

PyGSL_sf_ufunc_qi_di_rd_one_data[0] = PyGSL_sf_ufunc_qi_fi_rf_as_di_rd;
PyGSL_sf_ufunc_qi_di_rd_one_data[1] = PyGSL_sf_ufunc_qi_di_rd;

PyGSL_sf_ufunc_qi_dm_rd_one_data[0] = PyGSL_sf_ufunc_qi_fm_rf_as_dm_rd;
PyGSL_sf_ufunc_qi_dm_rd_one_data[1] = PyGSL_sf_ufunc_qi_dm_rd;

PyGSL_sf_ufunc_qi_dui_rd_one_data[0] = PyGSL_sf_ufunc_qi_fui_rf_as_dui_rd;
PyGSL_sf_ufunc_qi_dui_rd_one_data[1] = PyGSL_sf_ufunc_qi_dui_rd;

PyGSL_sf_ufunc_qi_i_rd_one_data[0] = PyGSL_sf_ufunc_qi_i_rf_as_i_rd;
PyGSL_sf_ufunc_qi_i_rd_one_data[1] = PyGSL_sf_ufunc_qi_i_rd;

PyGSL_sf_ufunc_qi_id_rd_one_data[0] = PyGSL_sf_ufunc_qi_if_rf_as_id_rd;
PyGSL_sf_ufunc_qi_id_rd_one_data[1] = PyGSL_sf_ufunc_qi_id_rd;

PyGSL_sf_ufunc_qi_idd_rd_one_data[0] = PyGSL_sf_ufunc_qi_iff_rf_as_idd_rd;
PyGSL_sf_ufunc_qi_idd_rd_one_data[1] = PyGSL_sf_ufunc_qi_idd_rd;

PyGSL_sf_ufunc_qi_iid_erd_one_data[0] = PyGSL_sf_ufunc_qi_iif_erf_as_iid_erd;
PyGSL_sf_ufunc_qi_iid_erd_one_data[1] = PyGSL_sf_ufunc_qi_iid_erd;

PyGSL_sf_ufunc_qi_iid_rd_one_data[0] = PyGSL_sf_ufunc_qi_iif_rf_as_iid_rd;
PyGSL_sf_ufunc_qi_iid_rd_one_data[1] = PyGSL_sf_ufunc_qi_iid_rd;

PyGSL_sf_ufunc_qi_iidd_rd_one_data[0] = PyGSL_sf_ufunc_qi_iiff_rf_as_iidd_rd;
PyGSL_sf_ufunc_qi_iidd_rd_one_data[1] = PyGSL_sf_ufunc_qi_iidd_rd;

PyGSL_sf_ufunc_qi_iiiiii_rd_one_data[0] = PyGSL_sf_ufunc_qi_iiiiii_rf_as_iiiiii_rd;
PyGSL_sf_ufunc_qi_iiiiii_rd_one_data[1] = PyGSL_sf_ufunc_qi_iiiiii_rd;

PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_data[0] = PyGSL_sf_ufunc_qi_iiiiiiiii_rf_as_iiiiiiiii_rd;
PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one_data[1] = PyGSL_sf_ufunc_qi_iiiiiiiii_rd;

PyGSL_sf_ufunc_qi_ui_rd_one_data[0] = PyGSL_sf_ufunc_qi_ui_rf_as_ui_rd;
PyGSL_sf_ufunc_qi_ui_rd_one_data[1] = PyGSL_sf_ufunc_qi_ui_rd;

PyGSL_sf_ufunc_qi_uiui_rd_one_data[0] = PyGSL_sf_ufunc_qi_uiui_rf_as_uiui_rd;
PyGSL_sf_ufunc_qi_uiui_rd_one_data[1] = PyGSL_sf_ufunc_qi_uiui_rd;

