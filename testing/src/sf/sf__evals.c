
void PyGSL_sf_ufunc_Id_d__Rl__Od_d_d (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4], os5 = steps[5];
	
	
	int tmpr2;
	
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4, op5 += os5){

		 /* arg 'double u'*/
		 /* arg 'double m'*/
		tmpr2 =   ((int (*)(double, double, double *, double *, double *)) func)(/* double u */ (*((double *) ip0)), /* double m */ (*((double *) ip1)), /* double p dn */ ((double *) op3), /* double p cn */ ((double *) op4), /* double p sn */ ((double *) op5));
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		
		
		
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Od_d_d */ 

void PyGSL_sf_ufunc_Id_d__Rl__Od_d_d_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4], os5 = steps[5];
	double tmpi0;
	double tmpi1;
	
	double tmpo3;
	double tmpo4;
	double tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4, op5 += os5){

		tmpi0 = *((float *) ip0); /* arg 'double u'*/
		tmpi1 = *((float *) ip1); /* arg 'double m'*/
		*((int *) rp2) =   ((int (*)(double, double, double *, double *, double *)) func)(/* double u */ tmpi0, /* double m */ tmpi1, /* double p dn */ &tmpo3, /* double p cn */ &tmpo4, /* double p sn */ &tmpo5);
		
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x1091505e8>*/ *((float *) op3) = tmpo3;
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x109150548>*/ *((float *) op4) = tmpo4;
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x1091504a8>*/ *((float *) op5) = tmpo5;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Od_d_d_as_minor */ 

void PyGSL_sf_ufunc_Il_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	int tmpi0;
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		 /* arg 'double q(const) x'*/
		*((double *) rp2) =   ((double (*)(int, double)) func)(/* int q(const) n */ tmpi0, /* double q(const) x */ (*((double *) ip1)));
		
		continue;

	    fail:
		*((double *) rp2) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_d__Rd__O */ 

void PyGSL_sf_ufunc_Il_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	double tmpi1;
	double tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'int q(const) n'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) x'*/
		tmpr2 =   ((double (*)(int, double)) func)(/* int q(const) n */ (*((int *) ip0)), /* double q(const) x */ tmpi1);
		(*((float *) rp2)) = tmpr2;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_d_m__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *rp5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], rs5 = steps[5];
	
	
	
	
	gsl_mode_t tmpi4;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, rp5 += rs5){

		 /* arg 'double x'*/
		 /* arg 'double y'*/
		 /* arg 'double z'*/
		 /* arg 'double p'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip4), &tmpi4)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		*((double *) rp5) =   ((double (*)(double, double, double, double, gsl_mode_t)) func)(/* double x */ (*((double *) ip0)), /* double y */ (*((double *) ip1)), /* double z */ (*((double *) ip2)), /* double p */ (*((double *) ip3)), /* gsl_mode_t mode */ tmpi4);
		
		continue;

	    fail:
		*((double *) rp5) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d_m__Rd__O */ 

void PyGSL_sf_ufunc_Id_d_d_d_m__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *rp5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], rs5 = steps[5];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	double tmpi3;
	
	double tmpr5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, rp5 += rs5){

		tmpi0 = *((float *) ip0); /* arg 'double x'*/
		tmpi1 = *((float *) ip1); /* arg 'double y'*/
		tmpi2 = *((float *) ip2); /* arg 'double z'*/
		tmpi3 = *((float *) ip3); /* arg 'double p'*/
		 /* arg 'gsl_mode_t mode'*/
		tmpr5 =   ((double (*)(double, double, double, double, gsl_mode_t)) func)(/* double x */ tmpi0, /* double y */ tmpi1, /* double z */ tmpi2, /* double p */ tmpi3, /* gsl_mode_t mode */ (*((int *) ip4)));
		(*((float *) rp5)) = tmpr5;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d_m__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Il_d_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	int tmpi0;
	
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int n'*/
		 /* arg 'double lambda'*/
		 /* arg 'double x'*/
		*((double *) rp3) =   ((double (*)(int, double, double)) func)(/* int n */ tmpi0, /* double lambda */ (*((double *) ip1)), /* double x */ (*((double *) ip2)));
		
		continue;

	    fail:
		*((double *) rp3) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_d_d__Rd__O */ 

void PyGSL_sf_ufunc_Il_d_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	
	double tmpi1;
	double tmpi2;
	double tmpr3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		 /* arg 'int n'*/
		tmpi1 = *((float *) ip1); /* arg 'double lambda'*/
		tmpi2 = *((float *) ip2); /* arg 'double x'*/
		tmpr3 =   ((double (*)(int, double, double)) func)(/* int n */ (*((int *) ip0)), /* double lambda */ tmpi1, /* double x */ tmpi2);
		(*((float *) rp3)) = tmpr3;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_d_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	
	
	
	int tmpr3;
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		 /* arg 'double q(const) a'*/
		 /* arg 'double q(const) b'*/
		 /* arg 'double q(const) x'*/
		tmpr3 =   ((int (*)(double, double, double, gsl_sf_result *)) func)(/* double q(const) a */ (*((double *) ip0)), /* double q(const) b */ (*((double *) ip1)), /* double q(const) x */ (*((double *) ip2)), /* gsl_sf_result p result */ &tmpo4);
		*((long *) rp3) = 0;
		*((long *) rp3) = tmpr3;
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_d_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) a'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) b'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) x'*/
		*((int *) rp3) =   ((int (*)(double, double, double, gsl_sf_result *)) func)(/* double q(const) a */ tmpi0, /* double q(const) b */ tmpi1, /* double q(const) x */ tmpi2, /* gsl_sf_result p result */ &tmpo4);
		
		*((float *) op4) = tmpo4.val;
		*((float *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	int tmpi0;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		*((double *) rp1) =   ((double (*)(int)) func)(/* int q(const) n */ tmpi0);
		
		continue;

	    fail:
		*((double *) rp1) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il__Rd__O */ 

void PyGSL_sf_ufunc_Il__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	
	double tmpr1;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		 /* arg 'int q(const) n'*/
		tmpr1 =   ((double (*)(int)) func)(/* int q(const) n */ (*((int *) ip0)));
		(*((float *) rp1)) = tmpr1;
		continue;
	}
} /* PyGSL_sf_ufunc_Il__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Il_l_d__Rl__Oerd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4];
	int tmpi0;
	int tmpi1;
	
	int tmpr3;
	gsl_sf_result_e10 tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) m'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		 /* arg 'double q(const) x'*/
		tmpr3 =   ((int (*)(int, int, double, gsl_sf_result_e10 *)) func)(/* int q(const) m */ tmpi0, /* int q(const) n */ tmpi1, /* double q(const) x */ (*((double *) ip2)), /* gsl_sf_result_e10 p result */ &tmpo4);
		*((long *) rp3) = 0;
		*((long *) rp3) = tmpr3;
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		*((int *) op6) = tmpo4.e10;
		continue;

	    fail:
		*((int *) rp3) = INT_MIN;
		*((double *) op4) = _PyGSL_NAN;
		*((double *) op5) = _PyGSL_NAN;
		*((int *) op6) = INT_MIN;
	}
} /* PyGSL_sf_ufunc_Il_l_d__Rl__Oerd */ 

void PyGSL_sf_ufunc_Il_l_d__Rl__Oerd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4];
	
	
	double tmpi2;
	
	gsl_sf_result_e10 tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4){

		 /* arg 'int q(const) m'*/
		 /* arg 'int q(const) n'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) x'*/
		*((int *) rp3) =   ((int (*)(int, int, double, gsl_sf_result_e10 *)) func)(/* int q(const) m */ (*((int *) ip0)), /* int q(const) n */ (*((int *) ip1)), /* double q(const) x */ tmpi2, /* gsl_sf_result_e10 p result */ &tmpo4);
		
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		*((int *) op6) = tmpo4.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_d__Rl__Oerd_as_minor */ 

void PyGSL_sf_ufunc_Il_l_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	int tmpi0;
	int tmpi1;
	
	int tmpr3;
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) m'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		 /* arg 'double q(const) x'*/
		tmpr3 =   ((int (*)(int, int, double, gsl_sf_result *)) func)(/* int q(const) m */ tmpi0, /* int q(const) n */ tmpi1, /* double q(const) x */ (*((double *) ip2)), /* gsl_sf_result p result */ &tmpo4);
		*((long *) rp3) = 0;
		*((long *) rp3) = tmpr3;
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		continue;

	    fail:
		*((int *) rp3) = INT_MIN;
		*((double *) op4) = _PyGSL_NAN;
		*((double *) op5) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Il_l_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	
	
	double tmpi2;
	
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		 /* arg 'int q(const) m'*/
		 /* arg 'int q(const) n'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) x'*/
		*((int *) rp3) =   ((int (*)(int, int, double, gsl_sf_result *)) func)(/* int q(const) m */ (*((int *) ip0)), /* int q(const) n */ (*((int *) ip1)), /* double q(const) x */ tmpi2, /* gsl_sf_result p result */ &tmpo4);
		
		*((float *) op4) = tmpo4.val;
		*((float *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_d__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6];
	
	
	
	
	int tmpr4;
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6){

		 /* arg 'double q(const) x'*/
		 /* arg 'double q(const) dx'*/
		 /* arg 'double q(const) y'*/
		 /* arg 'double q(const) dy'*/
		tmpr4 =   ((int (*)(double, double, double, double, gsl_sf_result *)) func)(/* double q(const) x */ (*((double *) ip0)), /* double q(const) dx */ (*((double *) ip1)), /* double q(const) y */ (*((double *) ip2)), /* double q(const) dy */ (*((double *) ip3)), /* gsl_sf_result p result */ &tmpo5);
		*((long *) rp4) = 0;
		*((long *) rp4) = tmpr4;
		*((double *) op5) = tmpo5.val;
		*((double *) op6) = tmpo5.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_d_d_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	double tmpi3;
	
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) dx'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) y'*/
		tmpi3 = *((float *) ip3); /* arg 'double q(const) dy'*/
		*((int *) rp4) =   ((int (*)(double, double, double, double, gsl_sf_result *)) func)(/* double q(const) x */ tmpi0, /* double q(const) dx */ tmpi1, /* double q(const) y */ tmpi2, /* double q(const) dy */ tmpi3, /* gsl_sf_result p result */ &tmpo5);
		
		*((float *) op5) = tmpo5.val;
		*((float *) op6) = tmpo5.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d_m__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	
	
	gsl_mode_t tmpi2;
	int tmpr3;
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		 /* arg 'double k'*/
		 /* arg 'double n'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip2), &tmpi2)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		tmpr3 =   ((int (*)(double, double, gsl_mode_t, gsl_sf_result *)) func)(/* double k */ (*((double *) ip0)), /* double n */ (*((double *) ip1)), /* gsl_mode_t mode */ tmpi2, /* gsl_sf_result p result */ &tmpo4);
		*((long *) rp3) = 0;
		*((long *) rp3) = tmpr3;
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		continue;

	    fail:
		*((int *) rp3) = INT_MIN;
		*((double *) op4) = _PyGSL_NAN;
		*((double *) op5) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_m__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_d_m__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	double tmpi0;
	double tmpi1;
	
	
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		tmpi0 = *((float *) ip0); /* arg 'double k'*/
		tmpi1 = *((float *) ip1); /* arg 'double n'*/
		 /* arg 'gsl_mode_t mode'*/
		*((int *) rp3) =   ((int (*)(double, double, gsl_mode_t, gsl_sf_result *)) func)(/* double k */ tmpi0, /* double n */ tmpi1, /* gsl_mode_t mode */ (*((int *) ip2)), /* gsl_sf_result p result */ &tmpo4);
		
		*((float *) op4) = tmpo4.val;
		*((float *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_m__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_m__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6];
	
	
	
	gsl_mode_t tmpi3;
	int tmpr4;
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6){

		 /* arg 'double phi'*/
		 /* arg 'double k'*/
		 /* arg 'double n'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		tmpr4 =   ((int (*)(double, double, double, gsl_mode_t, gsl_sf_result *)) func)(/* double phi */ (*((double *) ip0)), /* double k */ (*((double *) ip1)), /* double n */ (*((double *) ip2)), /* gsl_mode_t mode */ tmpi3, /* gsl_sf_result p result */ &tmpo5);
		*((long *) rp4) = 0;
		*((long *) rp4) = tmpr4;
		*((double *) op5) = tmpo5.val;
		*((double *) op6) = tmpo5.err;
		continue;

	    fail:
		*((int *) rp4) = INT_MIN;
		*((double *) op5) = _PyGSL_NAN;
		*((double *) op6) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_d_m__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_d_d_m__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	
	
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6){

		tmpi0 = *((float *) ip0); /* arg 'double phi'*/
		tmpi1 = *((float *) ip1); /* arg 'double k'*/
		tmpi2 = *((float *) ip2); /* arg 'double n'*/
		 /* arg 'gsl_mode_t mode'*/
		*((int *) rp4) =   ((int (*)(double, double, double, gsl_mode_t, gsl_sf_result *)) func)(/* double phi */ tmpi0, /* double k */ tmpi1, /* double n */ tmpi2, /* gsl_mode_t mode */ (*((int *) ip3)), /* gsl_sf_result p result */ &tmpo5);
		
		*((float *) op5) = tmpo5.val;
		*((float *) op6) = tmpo5.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_m__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il_d_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	int tmpi0;
	
	
	int tmpr3;
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int n'*/
		 /* arg 'double lambda'*/
		 /* arg 'double x'*/
		tmpr3 =   ((int (*)(int, double, double, gsl_sf_result *)) func)(/* int n */ tmpi0, /* double lambda */ (*((double *) ip1)), /* double x */ (*((double *) ip2)), /* gsl_sf_result p result */ &tmpo4);
		*((long *) rp3) = 0;
		*((long *) rp3) = tmpr3;
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		continue;

	    fail:
		*((int *) rp3) = INT_MIN;
		*((double *) op4) = _PyGSL_NAN;
		*((double *) op5) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_d_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Il_d_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4], os5 = steps[5];
	
	double tmpi1;
	double tmpi2;
	
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4, op5 += os5){

		 /* arg 'int n'*/
		tmpi1 = *((float *) ip1); /* arg 'double lambda'*/
		tmpi2 = *((float *) ip2); /* arg 'double x'*/
		*((int *) rp3) =   ((int (*)(int, double, double, gsl_sf_result *)) func)(/* int n */ (*((int *) ip0)), /* double lambda */ tmpi1, /* double x */ tmpi2, /* gsl_sf_result p result */ &tmpo4);
		
		*((float *) op4) = tmpo4.val;
		*((float *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_d_d__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3];
	int tmpi0;
	int tmpr1;
	gsl_sf_result tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		tmpr1 =   ((int (*)(int, gsl_sf_result *)) func)(/* int q(const) n */ tmpi0, /* gsl_sf_result p result */ &tmpo2);
		*((long *) rp1) = 0;
		*((long *) rp1) = tmpr1;
		*((double *) op2) = tmpo2.val;
		*((double *) op3) = tmpo2.err;
		continue;

	    fail:
		*((int *) rp1) = INT_MIN;
		*((double *) op2) = _PyGSL_NAN;
		*((double *) op3) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il__Rl__Ord */ 

void PyGSL_sf_ufunc_Il__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3];
	
	
	gsl_sf_result tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3){

		 /* arg 'int q(const) n'*/
		*((int *) rp1) =   ((int (*)(int, gsl_sf_result *)) func)(/* int q(const) n */ (*((int *) ip0)), /* gsl_sf_result p result */ &tmpo2);
		
		*((float *) op2) = tmpo2.val;
		*((float *) op3) = tmpo2.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *ip6 = args[6], *ip7 = args[7], *ip8 = args[8], *rp9 = args[9], *op10 = args[10], *op11 = args[11];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], is6 = steps[6], is7 = steps[7], is8 = steps[8], rs9 = steps[9], os10 = steps[10], os11 = steps[11];
	int tmpi0;
	int tmpi1;
	int tmpi2;
	int tmpi3;
	int tmpi4;
	int tmpi5;
	int tmpi6;
	int tmpi7;
	int tmpi8;
	int tmpr9;
	gsl_sf_result tmpo10;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, ip6 += is6, ip7 += is7, ip8 += is8, rp9 += rs9, op10 += os10, op11 += os11){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ja'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jb'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip2), &tmpi2)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jc'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jd'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip4), &tmpi4)) != GSL_SUCCESS){goto fail;} /* arg 'int two_je'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip5), &tmpi5)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jf'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip6), &tmpi6)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jg'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip7), &tmpi7)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jh'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip8), &tmpi8)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ji'*/
		tmpr9 =   ((int (*)(int, int, int, int, int, int, int, int, int, gsl_sf_result *)) func)(/* int two_ja */ tmpi0, /* int two_jb */ tmpi1, /* int two_jc */ tmpi2, /* int two_jd */ tmpi3, /* int two_je */ tmpi4, /* int two_jf */ tmpi5, /* int two_jg */ tmpi6, /* int two_jh */ tmpi7, /* int two_ji */ tmpi8, /* gsl_sf_result p result */ &tmpo10);
		*((long *) rp9) = 0;
		*((long *) rp9) = tmpr9;
		*((double *) op10) = tmpo10.val;
		*((double *) op11) = tmpo10.err;
		continue;

	    fail:
		*((int *) rp9) = INT_MIN;
		*((double *) op10) = _PyGSL_NAN;
		*((double *) op11) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rl__Ord */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *ip6 = args[6], *ip7 = args[7], *ip8 = args[8], *rp9 = args[9], *op10 = args[10], *op11 = args[11];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], is6 = steps[6], is7 = steps[7], is8 = steps[8], rs9 = steps[9], os10 = steps[10], os11 = steps[11];
	
	
	
	
	
	
	
	
	
	
	gsl_sf_result tmpo10;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, ip6 += is6, ip7 += is7, ip8 += is8, rp9 += rs9, op10 += os10, op11 += os11){

		 /* arg 'int two_ja'*/
		 /* arg 'int two_jb'*/
		 /* arg 'int two_jc'*/
		 /* arg 'int two_jd'*/
		 /* arg 'int two_je'*/
		 /* arg 'int two_jf'*/
		 /* arg 'int two_jg'*/
		 /* arg 'int two_jh'*/
		 /* arg 'int two_ji'*/
		*((int *) rp9) =   ((int (*)(int, int, int, int, int, int, int, int, int, gsl_sf_result *)) func)(/* int two_ja */ (*((int *) ip0)), /* int two_jb */ (*((int *) ip1)), /* int two_jc */ (*((int *) ip2)), /* int two_jd */ (*((int *) ip3)), /* int two_je */ (*((int *) ip4)), /* int two_jf */ (*((int *) ip5)), /* int two_jg */ (*((int *) ip6)), /* int two_jh */ (*((int *) ip7)), /* int two_ji */ (*((int *) ip8)), /* gsl_sf_result p result */ &tmpo10);
		
		*((float *) op10) = tmpo10.val;
		*((float *) op11) = tmpo10.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_d_m__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *rp5 = args[5], *op6 = args[6], *op7 = args[7];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], rs5 = steps[5], os6 = steps[6], os7 = steps[7];
	
	
	
	
	gsl_mode_t tmpi4;
	int tmpr5;
	gsl_sf_result tmpo6;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, rp5 += rs5, op6 += os6, op7 += os7){

		 /* arg 'double x'*/
		 /* arg 'double y'*/
		 /* arg 'double z'*/
		 /* arg 'double p'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip4), &tmpi4)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		tmpr5 =   ((int (*)(double, double, double, double, gsl_mode_t, gsl_sf_result *)) func)(/* double x */ (*((double *) ip0)), /* double y */ (*((double *) ip1)), /* double z */ (*((double *) ip2)), /* double p */ (*((double *) ip3)), /* gsl_mode_t mode */ tmpi4, /* gsl_sf_result p result */ &tmpo6);
		*((long *) rp5) = 0;
		*((long *) rp5) = tmpr5;
		*((double *) op6) = tmpo6.val;
		*((double *) op7) = tmpo6.err;
		continue;

	    fail:
		*((int *) rp5) = INT_MIN;
		*((double *) op6) = _PyGSL_NAN;
		*((double *) op7) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d_m__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_d_d_d_m__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *rp5 = args[5], *op6 = args[6], *op7 = args[7];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], rs5 = steps[5], os6 = steps[6], os7 = steps[7];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	double tmpi3;
	
	
	gsl_sf_result tmpo6;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, rp5 += rs5, op6 += os6, op7 += os7){

		tmpi0 = *((float *) ip0); /* arg 'double x'*/
		tmpi1 = *((float *) ip1); /* arg 'double y'*/
		tmpi2 = *((float *) ip2); /* arg 'double z'*/
		tmpi3 = *((float *) ip3); /* arg 'double p'*/
		 /* arg 'gsl_mode_t mode'*/
		*((int *) rp5) =   ((int (*)(double, double, double, double, gsl_mode_t, gsl_sf_result *)) func)(/* double x */ tmpi0, /* double y */ tmpi1, /* double z */ tmpi2, /* double p */ tmpi3, /* gsl_mode_t mode */ (*((int *) ip4)), /* gsl_sf_result p result */ &tmpo6);
		
		*((float *) op6) = tmpo6.val;
		*((float *) op7) = tmpo6.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d_m__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_I__Rl__Od (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *rp0 = args[0], *op1 = args[1];
	PyGSL_array_index_t i, rs0 = steps[0], os1 = steps[1];
	int tmpr0;
	
	 for(i = 0; i < dimensions[0]; ++i, rp0 += rs0, op1 += os1){

		tmpr0 =   ((int (*)(double *)) func)(/* double p theta */ ((double *) op1));
		*((long *) rp0) = 0;
		*((long *) rp0) = tmpr0;
		
		continue;
	}
} /* PyGSL_sf_ufunc_I__Rl__Od */ 

void PyGSL_sf_ufunc_I__Rl__Od_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *rp0 = args[0], *op1 = args[1];
	PyGSL_array_index_t i, rs0 = steps[0], os1 = steps[1];
	
	double tmpo1;
	 for(i = 0; i < dimensions[0]; ++i, rp0 += rs0, op1 += os1){

		*((int *) rp0) =   ((int (*)(double *)) func)(/* double p theta */ &tmpo1);
		
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x1091fcea8>*/ *((float *) op1) = tmpo1;
		continue;
	}
} /* PyGSL_sf_ufunc_I__Rl__Od_as_minor */ 

void PyGSL_sf_ufunc_Id_l__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	int tmpi1;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'double q(const) x'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		*((double *) rp2) =   ((double (*)(double, int)) func)(/* double q(const) x */ (*((double *) ip0)), /* int q(const) n */ tmpi1);
		
		continue;

	    fail:
		*((double *) rp2) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_l__Rd__O */ 

void PyGSL_sf_ufunc_Id_l__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	double tmpi0;
	
	double tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		 /* arg 'int q(const) n'*/
		tmpr2 =   ((double (*)(double, int)) func)(/* double q(const) x */ tmpi0, /* int q(const) n */ (*((int *) ip1)));
		(*((float *) rp2)) = tmpr2;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_l__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *rp6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], rs6 = steps[6];
	int tmpi0;
	int tmpi1;
	int tmpi2;
	int tmpi3;
	int tmpi4;
	int tmpi5;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, rp6 += rs6){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ja'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jb'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip2), &tmpi2)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jc'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ma'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip4), &tmpi4)) != GSL_SUCCESS){goto fail;} /* arg 'int two_mb'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip5), &tmpi5)) != GSL_SUCCESS){goto fail;} /* arg 'int two_mc'*/
		*((double *) rp6) =   ((double (*)(int, int, int, int, int, int)) func)(/* int two_ja */ tmpi0, /* int two_jb */ tmpi1, /* int two_jc */ tmpi2, /* int two_ma */ tmpi3, /* int two_mb */ tmpi4, /* int two_mc */ tmpi5);
		
		continue;

	    fail:
		*((double *) rp6) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l__Rd__O */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *rp6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], rs6 = steps[6];
	
	
	
	
	
	
	double tmpr6;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, rp6 += rs6){

		 /* arg 'int two_ja'*/
		 /* arg 'int two_jb'*/
		 /* arg 'int two_jc'*/
		 /* arg 'int two_ma'*/
		 /* arg 'int two_mb'*/
		 /* arg 'int two_mc'*/
		tmpr6 =   ((double (*)(int, int, int, int, int, int)) func)(/* int two_ja */ (*((int *) ip0)), /* int two_jb */ (*((int *) ip1)), /* int two_jc */ (*((int *) ip2)), /* int two_ma */ (*((int *) ip3)), /* int two_mb */ (*((int *) ip4)), /* int two_mc */ (*((int *) ip5)));
		(*((float *) rp6)) = tmpr6;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_d__Rl__Oerd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6], *op7 = args[7];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5];
	
	
	
	
	int tmpr4;
	gsl_sf_result_e10 tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5){

		 /* arg 'double q(const) x'*/
		 /* arg 'double q(const) dx'*/
		 /* arg 'double q(const) y'*/
		 /* arg 'double q(const) dy'*/
		tmpr4 =   ((int (*)(double, double, double, double, gsl_sf_result_e10 *)) func)(/* double q(const) x */ (*((double *) ip0)), /* double q(const) dx */ (*((double *) ip1)), /* double q(const) y */ (*((double *) ip2)), /* double q(const) dy */ (*((double *) ip3)), /* gsl_sf_result_e10 p result */ &tmpo5);
		*((long *) rp4) = 0;
		*((long *) rp4) = tmpr4;
		*((double *) op5) = tmpo5.val;
		*((double *) op6) = tmpo5.err;
		*((int *) op7) = tmpo5.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d__Rl__Oerd */ 

void PyGSL_sf_ufunc_Id_d_d_d__Rl__Oerd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6], *op7 = args[7];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	double tmpi3;
	
	gsl_sf_result_e10 tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) dx'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) y'*/
		tmpi3 = *((float *) ip3); /* arg 'double q(const) dy'*/
		*((int *) rp4) =   ((int (*)(double, double, double, double, gsl_sf_result_e10 *)) func)(/* double q(const) x */ tmpi0, /* double q(const) dx */ tmpi1, /* double q(const) y */ tmpi2, /* double q(const) dy */ tmpi3, /* gsl_sf_result_e10 p result */ &tmpo5);
		
		*((double *) op5) = tmpo5.val;
		*((double *) op6) = tmpo5.err;
		*((int *) op7) = tmpo5.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d__Rl__Oerd_as_minor */ 

void PyGSL_sf_ufunc_Id_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'double q(const) nu'*/
		 /* arg 'double q(const) x'*/
		*((double *) rp2) =   ((double (*)(double, double)) func)(/* double q(const) nu */ (*((double *) ip0)), /* double q(const) x */ (*((double *) ip1)));
		
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rd__O */ 

void PyGSL_sf_ufunc_Id_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	double tmpi0;
	double tmpi1;
	double tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) nu'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) x'*/
		tmpr2 =   ((double (*)(double, double)) func)(/* double q(const) nu */ tmpi0, /* double q(const) x */ tmpi1);
		(*((float *) rp2)) = tmpr2;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3];
	
	int tmpr1;
	gsl_sf_result tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3){

		 /* arg 'double q(const) x'*/
		tmpr1 =   ((int (*)(double, gsl_sf_result *)) func)(/* double q(const) x */ (*((double *) ip0)), /* gsl_sf_result p result */ &tmpo2);
		*((long *) rp1) = 0;
		*((long *) rp1) = tmpr1;
		*((double *) op2) = tmpo2.val;
		*((double *) op3) = tmpo2.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rl__Ord */ 

void PyGSL_sf_ufunc_Id__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3];
	double tmpi0;
	
	gsl_sf_result tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		*((int *) rp1) =   ((int (*)(double, gsl_sf_result *)) func)(/* double q(const) x */ tmpi0, /* gsl_sf_result p result */ &tmpo2);
		
		*((float *) op2) = tmpo2.val;
		*((float *) op3) = tmpo2.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il_l_d_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4];
	int tmpi0;
	int tmpi1;
	
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) l'*/
		 /* arg 'double q(const) Z'*/
		 /* arg 'double q(const) r'*/
		*((double *) rp4) =   ((double (*)(int, int, double, double)) func)(/* int q(const) n */ tmpi0, /* int q(const) l */ tmpi1, /* double q(const) Z */ (*((double *) ip2)), /* double q(const) r */ (*((double *) ip3)));
		
		continue;

	    fail:
		*((double *) rp4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_d_d__Rd__O */ 

void PyGSL_sf_ufunc_Il_l_d_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4];
	
	
	double tmpi2;
	double tmpi3;
	double tmpr4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4){

		 /* arg 'int q(const) n'*/
		 /* arg 'int q(const) l'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) Z'*/
		tmpi3 = *((float *) ip3); /* arg 'double q(const) r'*/
		tmpr4 =   ((double (*)(int, int, double, double)) func)(/* int q(const) n */ (*((int *) ip0)), /* int q(const) l */ (*((int *) ip1)), /* double q(const) Z */ tmpi2, /* double q(const) r */ tmpi3);
		(*((float *) rp4)) = tmpr4;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_d_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4];
	
	
	
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4){

		 /* arg 'double a'*/
		 /* arg 'double b'*/
		 /* arg 'double c'*/
		 /* arg 'double x'*/
		*((double *) rp4) =   ((double (*)(double, double, double, double)) func)(/* double a */ (*((double *) ip0)), /* double b */ (*((double *) ip1)), /* double c */ (*((double *) ip2)), /* double x */ (*((double *) ip3)));
		
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d__Rd__O */ 

void PyGSL_sf_ufunc_Id_d_d_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	double tmpi3;
	double tmpr4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4){

		tmpi0 = *((float *) ip0); /* arg 'double a'*/
		tmpi1 = *((float *) ip1); /* arg 'double b'*/
		tmpi2 = *((float *) ip2); /* arg 'double c'*/
		tmpi3 = *((float *) ip3); /* arg 'double x'*/
		tmpr4 =   ((double (*)(double, double, double, double)) func)(/* double a */ tmpi0, /* double b */ tmpi1, /* double c */ tmpi2, /* double x */ tmpi3);
		(*((float *) rp4)) = tmpr4;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id__Rl__Od_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	int tmpr1;
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3, op4 += os4){

		 /* arg 'double x'*/
		tmpr1 =   ((int (*)(double, double *, gsl_sf_result *)) func)(/* double x */ (*((double *) ip0)), /* double p sgn */ ((double *) op2), /* gsl_sf_result p result_lg */ &tmpo3);
		*((long *) rp1) = 0;
		*((long *) rp1) = tmpr1;
		
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rl__Od_rd */ 

void PyGSL_sf_ufunc_Id__Rl__Od_rd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3], os4 = steps[4];
	double tmpi0;
	
	double tmpo2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3, op4 += os4){

		tmpi0 = *((float *) ip0); /* arg 'double x'*/
		*((int *) rp1) =   ((int (*)(double, double *, gsl_sf_result *)) func)(/* double x */ tmpi0, /* double p sgn */ &tmpo2, /* gsl_sf_result p result_lg */ &tmpo3);
		
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x10917ef48>*/ *((float *) op2) = tmpo2;
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rl__Od_rd_as_minor */ 

void PyGSL_sf_ufunc_Iui_ui__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	unsigned int tmpi0;
	unsigned int tmpi1;
	int tmpr2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		if( (_PyGSL_SF_L_TO_U(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int n'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int m'*/
		tmpr2 =   ((int (*)(unsigned int, unsigned int, gsl_sf_result *)) func)(/* unsigned int n */ tmpi0, /* unsigned int m */ tmpi1, /* gsl_sf_result p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;

	    fail:
		*((int *) rp2) = INT_MIN;
		*((double *) op3) = _PyGSL_NAN;
		*((double *) op4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Iui_ui__Rl__Ord */ 

void PyGSL_sf_ufunc_Iui_ui__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		 /* arg 'unsigned int n'*/
		 /* arg 'unsigned int m'*/
		*((int *) rp2) =   ((int (*)(unsigned int, unsigned int, gsl_sf_result *)) func)(/* unsigned int n */ (*((int *) ip0)), /* unsigned int m */ (*((int *) ip1)), /* gsl_sf_result p result */ &tmpo3);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Iui_ui__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_l__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	int tmpi1;
	int tmpr2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		 /* arg 'double x'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int n'*/
		tmpr2 =   ((int (*)(double, int, gsl_sf_result *)) func)(/* double x */ (*((double *) ip0)), /* int n */ tmpi1, /* gsl_sf_result p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;

	    fail:
		*((int *) rp2) = INT_MIN;
		*((double *) op3) = _PyGSL_NAN;
		*((double *) op4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_l__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_l__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	double tmpi0;
	
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		tmpi0 = *((float *) ip0); /* arg 'double x'*/
		 /* arg 'int n'*/
		*((int *) rp2) =   ((int (*)(double, int, gsl_sf_result *)) func)(/* double x */ tmpi0, /* int n */ (*((int *) ip1)), /* gsl_sf_result p result */ &tmpo3);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_l__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d__Rl__Oerd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4];
	
	
	
	int tmpr3;
	gsl_sf_result_e10 tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4){

		 /* arg 'double q(const) a'*/
		 /* arg 'double q(const) b'*/
		 /* arg 'double q(const) x'*/
		tmpr3 =   ((int (*)(double, double, double, gsl_sf_result_e10 *)) func)(/* double q(const) a */ (*((double *) ip0)), /* double q(const) b */ (*((double *) ip1)), /* double q(const) x */ (*((double *) ip2)), /* gsl_sf_result_e10 p result */ &tmpo4);
		*((long *) rp3) = 0;
		*((long *) rp3) = tmpr3;
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		*((int *) op6) = tmpo4.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d__Rl__Oerd */ 

void PyGSL_sf_ufunc_Id_d_d__Rl__Oerd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3], *op4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3], os4 = steps[4];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	
	gsl_sf_result_e10 tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3, op4 += os4){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) a'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) b'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) x'*/
		*((int *) rp3) =   ((int (*)(double, double, double, gsl_sf_result_e10 *)) func)(/* double q(const) a */ tmpi0, /* double q(const) b */ tmpi1, /* double q(const) x */ tmpi2, /* gsl_sf_result_e10 p result */ &tmpo4);
		
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		*((int *) op6) = tmpo4.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d__Rl__Oerd_as_minor */ 

void PyGSL_sf_ufunc_Iui__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	unsigned int tmpi0;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		if( (_PyGSL_SF_L_TO_U(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int s'*/
		*((double *) rp1) =   ((double (*)(unsigned int)) func)(/* unsigned int s */ tmpi0);
		
		continue;

	    fail:
		*((double *) rp1) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Iui__Rd__O */ 

void PyGSL_sf_ufunc_Iui__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	
	double tmpr1;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		 /* arg 'unsigned int s'*/
		tmpr1 =   ((double (*)(unsigned int)) func)(/* unsigned int s */ (*((int *) ip0)));
		(*((float *) rp1)) = tmpr1;
		continue;
	}
} /* PyGSL_sf_ufunc_Iui__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_ui__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	unsigned int tmpi1;
	int tmpr2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		 /* arg 'double nu'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int s'*/
		tmpr2 =   ((int (*)(double, unsigned int, gsl_sf_result *)) func)(/* double nu */ (*((double *) ip0)), /* unsigned int s */ tmpi1, /* gsl_sf_result p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;

	    fail:
		*((int *) rp2) = INT_MIN;
		*((double *) op3) = _PyGSL_NAN;
		*((double *) op4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_ui__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_ui__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	double tmpi0;
	
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		tmpi0 = *((float *) ip0); /* arg 'double nu'*/
		 /* arg 'unsigned int s'*/
		*((int *) rp2) =   ((int (*)(double, unsigned int, gsl_sf_result *)) func)(/* double nu */ tmpi0, /* unsigned int s */ (*((int *) ip1)), /* gsl_sf_result p result */ &tmpo3);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_ui__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	int tmpi0;
	
	int tmpr2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int n'*/
		 /* arg 'double x'*/
		tmpr2 =   ((int (*)(int, double, gsl_sf_result *)) func)(/* int n */ tmpi0, /* double x */ (*((double *) ip1)), /* gsl_sf_result p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;

	    fail:
		*((int *) rp2) = INT_MIN;
		*((double *) op3) = _PyGSL_NAN;
		*((double *) op4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Il_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	double tmpi1;
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		 /* arg 'int n'*/
		tmpi1 = *((float *) ip1); /* arg 'double x'*/
		*((int *) rp2) =   ((int (*)(int, double, gsl_sf_result *)) func)(/* int n */ (*((int *) ip0)), /* double x */ tmpi1, /* gsl_sf_result p result */ &tmpo3);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_d__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Il_l_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	int tmpi0;
	int tmpi1;
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) m'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		 /* arg 'double x'*/
		*((double *) rp3) =   ((double (*)(int, int, double)) func)(/* int q(const) m */ tmpi0, /* int q(const) n */ tmpi1, /* double x */ (*((double *) ip2)));
		
		continue;

	    fail:
		*((double *) rp3) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_d__Rd__O */ 

void PyGSL_sf_ufunc_Il_l_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	
	
	double tmpi2;
	double tmpr3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		 /* arg 'int q(const) m'*/
		 /* arg 'int q(const) n'*/
		tmpi2 = *((float *) ip2); /* arg 'double x'*/
		tmpr3 =   ((double (*)(int, int, double)) func)(/* int q(const) m */ (*((int *) ip0)), /* int q(const) n */ (*((int *) ip1)), /* double x */ tmpi2);
		(*((float *) rp3)) = tmpr3;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_m__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4];
	
	
	
	gsl_mode_t tmpi3;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4){

		 /* arg 'double phi'*/
		 /* arg 'double k'*/
		 /* arg 'double n'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		*((double *) rp4) =   ((double (*)(double, double, double, gsl_mode_t)) func)(/* double phi */ (*((double *) ip0)), /* double k */ (*((double *) ip1)), /* double n */ (*((double *) ip2)), /* gsl_mode_t mode */ tmpi3);
		
		continue;

	    fail:
		*((double *) rp4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_d_m__Rd__O */ 

void PyGSL_sf_ufunc_Id_d_d_m__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	
	double tmpr4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4){

		tmpi0 = *((float *) ip0); /* arg 'double phi'*/
		tmpi1 = *((float *) ip1); /* arg 'double k'*/
		tmpi2 = *((float *) ip2); /* arg 'double n'*/
		 /* arg 'gsl_mode_t mode'*/
		tmpr4 =   ((double (*)(double, double, double, gsl_mode_t)) func)(/* double phi */ tmpi0, /* double k */ tmpi1, /* double n */ tmpi2, /* gsl_mode_t mode */ (*((int *) ip3)));
		(*((float *) rp4)) = tmpr4;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_m__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d_l__Rl__Od_d_rd_rd_rd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6], *op7 = args[7], *op8 = args[8], *op9 = args[9], *op10 = args[10], *op11 = args[11], *op12 = args[12], *op13 = args[13], *op14 = args[14];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6], os7 = steps[7], os8 = steps[8], os9 = steps[9], os10 = steps[10], os11 = steps[11], os12 = steps[12], os13 = steps[13], os14 = steps[14];
	
	
	
	int tmpi3;
	int tmpr4;
	
	
	gsl_sf_result tmpo7;
	gsl_sf_result tmpo9;
	gsl_sf_result tmpo11;
	gsl_sf_result tmpo13;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6, op7 += os7, op8 += os8, op9 += os9, op10 += os10, op11 += os11, op12 += os12, op13 += os13, op14 += os14){

		 /* arg 'double q(const) eta'*/
		 /* arg 'double q(const) x'*/
		 /* arg 'double q(const) lam_F'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) k_lam_G'*/
		tmpr4 =   ((int (*)(double, double, double, int, double *, double *, gsl_sf_result *, gsl_sf_result *, gsl_sf_result *, gsl_sf_result *)) func)(/* double q(const) eta */ (*((double *) ip0)), /* double q(const) x */ (*((double *) ip1)), /* double q(const) lam_F */ (*((double *) ip2)), /* int q(const) k_lam_G */ tmpi3, /* double p exp_G */ ((double *) op5), /* double p exp_F */ ((double *) op6), /* gsl_sf_result p Gp */ &tmpo7, /* gsl_sf_result p G */ &tmpo9, /* gsl_sf_result p Fp */ &tmpo11, /* gsl_sf_result p F */ &tmpo13);
		*((long *) rp4) = 0;
		*((long *) rp4) = tmpr4;
		
		
		*((double *) op7) = tmpo7.val;
		*((double *) op8) = tmpo7.err;
		*((double *) op9) = tmpo9.val;
		*((double *) op10) = tmpo9.err;
		*((double *) op11) = tmpo11.val;
		*((double *) op12) = tmpo11.err;
		*((double *) op13) = tmpo13.val;
		*((double *) op14) = tmpo13.err;
		continue;

	    fail:
		*((int *) rp4) = INT_MIN;
		*((double *) op5) = _PyGSL_NAN;
		*((double *) op6) = _PyGSL_NAN;
		*((double *) op7) = _PyGSL_NAN;
		*((double *) op8) = _PyGSL_NAN;
		*((double *) op9) = _PyGSL_NAN;
		*((double *) op10) = _PyGSL_NAN;
		*((double *) op11) = _PyGSL_NAN;
		*((double *) op12) = _PyGSL_NAN;
		*((double *) op13) = _PyGSL_NAN;
		*((double *) op14) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_d_l__Rl__Od_d_rd_rd_rd_rd */ 

void PyGSL_sf_ufunc_Id_d_d_l__Rl__Od_d_rd_rd_rd_rd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6], *op7 = args[7], *op8 = args[8], *op9 = args[9], *op10 = args[10], *op11 = args[11], *op12 = args[12], *op13 = args[13], *op14 = args[14];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6], os7 = steps[7], os8 = steps[8], os9 = steps[9], os10 = steps[10], os11 = steps[11], os12 = steps[12], os13 = steps[13], os14 = steps[14];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	
	
	double tmpo5;
	double tmpo6;
	gsl_sf_result tmpo7;
	gsl_sf_result tmpo9;
	gsl_sf_result tmpo11;
	gsl_sf_result tmpo13;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6, op7 += os7, op8 += os8, op9 += os9, op10 += os10, op11 += os11, op12 += os12, op13 += os13, op14 += os14){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) eta'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) x'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) lam_F'*/
		 /* arg 'int q(const) k_lam_G'*/
		*((int *) rp4) =   ((int (*)(double, double, double, int, double *, double *, gsl_sf_result *, gsl_sf_result *, gsl_sf_result *, gsl_sf_result *)) func)(/* double q(const) eta */ tmpi0, /* double q(const) x */ tmpi1, /* double q(const) lam_F */ tmpi2, /* int q(const) k_lam_G */ (*((int *) ip3)), /* double p exp_G */ &tmpo5, /* double p exp_F */ &tmpo6, /* gsl_sf_result p Gp */ &tmpo7, /* gsl_sf_result p G */ &tmpo9, /* gsl_sf_result p Fp */ &tmpo11, /* gsl_sf_result p F */ &tmpo13);
		
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x1091225e8>*/ *((float *) op5) = tmpo5;
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x109122548>*/ *((float *) op6) = tmpo6;
		*((float *) op7) = tmpo7.val;
		*((float *) op8) = tmpo7.err;
		*((float *) op9) = tmpo9.val;
		*((float *) op10) = tmpo9.err;
		*((float *) op11) = tmpo11.val;
		*((float *) op12) = tmpo11.err;
		*((float *) op13) = tmpo13.val;
		*((float *) op14) = tmpo13.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d_l__Rl__Od_d_rd_rd_rd_rd_as_minor */ 

void PyGSL_sf_ufunc_Id_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	
	int tmpr2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		 /* arg 'double q(const) nu'*/
		 /* arg 'double q(const) x'*/
		tmpr2 =   ((int (*)(double, double, gsl_sf_result *)) func)(/* double q(const) nu */ (*((double *) ip0)), /* double q(const) x */ (*((double *) ip1)), /* gsl_sf_result p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	double tmpi0;
	double tmpi1;
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) nu'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) x'*/
		*((int *) rp2) =   ((int (*)(double, double, gsl_sf_result *)) func)(/* double q(const) nu */ tmpi0, /* double q(const) x */ tmpi1, /* gsl_sf_result p result */ &tmpo3);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d_m__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	
	
	gsl_mode_t tmpi2;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		 /* arg 'double k'*/
		 /* arg 'double n'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip2), &tmpi2)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		*((double *) rp3) =   ((double (*)(double, double, gsl_mode_t)) func)(/* double k */ (*((double *) ip0)), /* double n */ (*((double *) ip1)), /* gsl_mode_t mode */ tmpi2);
		
		continue;

	    fail:
		*((double *) rp3) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_d_m__Rd__O */ 

void PyGSL_sf_ufunc_Id_d_m__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	double tmpi0;
	double tmpi1;
	
	double tmpr3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		tmpi0 = *((float *) ip0); /* arg 'double k'*/
		tmpi1 = *((float *) ip1); /* arg 'double n'*/
		 /* arg 'gsl_mode_t mode'*/
		tmpr3 =   ((double (*)(double, double, gsl_mode_t)) func)(/* double k */ tmpi0, /* double n */ tmpi1, /* gsl_mode_t mode */ (*((int *) ip2)));
		(*((float *) rp3)) = tmpr3;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_m__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d_d__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	
	
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		 /* arg 'double q(const) a'*/
		 /* arg 'double q(const) b'*/
		 /* arg 'double q(const) x'*/
		*((double *) rp3) =   ((double (*)(double, double, double)) func)(/* double q(const) a */ (*((double *) ip0)), /* double q(const) b */ (*((double *) ip1)), /* double q(const) x */ (*((double *) ip2)));
		
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d__Rd__O */ 

void PyGSL_sf_ufunc_Id_d_d__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *rp3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], rs3 = steps[3];
	double tmpi0;
	double tmpi1;
	double tmpi2;
	double tmpr3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, rp3 += rs3){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) a'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) b'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) x'*/
		tmpr3 =   ((double (*)(double, double, double)) func)(/* double q(const) a */ tmpi0, /* double q(const) b */ tmpi1, /* double q(const) x */ tmpi2);
		(*((float *) rp3)) = tmpr3;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d_d__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d__Rl__Ord_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4], os5 = steps[5], os6 = steps[6];
	
	
	int tmpr2;
	gsl_sf_result tmpo3;
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4, op5 += os5, op6 += os6){

		 /* arg 'double q(const) x'*/
		 /* arg 'double q(const) y'*/
		tmpr2 =   ((int (*)(double, double, gsl_sf_result *, gsl_sf_result *)) func)(/* double q(const) x */ (*((double *) ip0)), /* double q(const) y */ (*((double *) ip1)), /* gsl_sf_result p result_im */ &tmpo3, /* gsl_sf_result p result_re */ &tmpo5);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		*((double *) op5) = tmpo5.val;
		*((double *) op6) = tmpo5.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Ord_rd */ 

void PyGSL_sf_ufunc_Id_d__Rl__Ord_rd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4], os5 = steps[5], os6 = steps[6];
	double tmpi0;
	double tmpi1;
	
	gsl_sf_result tmpo3;
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4, op5 += os5, op6 += os6){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) y'*/
		*((int *) rp2) =   ((int (*)(double, double, gsl_sf_result *, gsl_sf_result *)) func)(/* double q(const) x */ tmpi0, /* double q(const) y */ tmpi1, /* gsl_sf_result p result_im */ &tmpo3, /* gsl_sf_result p result_re */ &tmpo5);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		*((float *) op5) = tmpo5.val;
		*((float *) op6) = tmpo5.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Ord_rd_as_minor */ 

void PyGSL_sf_ufunc_Id_d__Rl__Oerd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3];
	
	
	int tmpr2;
	gsl_sf_result_e10 tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3){

		 /* arg 'double q(const) nu'*/
		 /* arg 'double q(const) x'*/
		tmpr2 =   ((int (*)(double, double, gsl_sf_result_e10 *)) func)(/* double q(const) nu */ (*((double *) ip0)), /* double q(const) x */ (*((double *) ip1)), /* gsl_sf_result_e10 p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		*((int *) op5) = tmpo3.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Oerd */ 

void PyGSL_sf_ufunc_Id_d__Rl__Oerd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3];
	double tmpi0;
	double tmpi1;
	
	gsl_sf_result_e10 tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) nu'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) x'*/
		*((int *) rp2) =   ((int (*)(double, double, gsl_sf_result_e10 *)) func)(/* double q(const) nu */ tmpi0, /* double q(const) x */ tmpi1, /* gsl_sf_result_e10 p result */ &tmpo3);
		
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		*((int *) op5) = tmpo3.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Oerd_as_minor */ 

void PyGSL_sf_ufunc_Id__Rl__Oerd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2];
	
	int tmpr1;
	gsl_sf_result_e10 tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2){

		 /* arg 'double q(const) x'*/
		tmpr1 =   ((int (*)(double, gsl_sf_result_e10 *)) func)(/* double q(const) x */ (*((double *) ip0)), /* gsl_sf_result_e10 p result */ &tmpo2);
		*((long *) rp1) = 0;
		*((long *) rp1) = tmpr1;
		*((double *) op2) = tmpo2.val;
		*((double *) op3) = tmpo2.err;
		*((int *) op4) = tmpo2.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rl__Oerd */ 

void PyGSL_sf_ufunc_Id__Rl__Oerd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2];
	double tmpi0;
	
	gsl_sf_result_e10 tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		*((int *) rp1) =   ((int (*)(double, gsl_sf_result_e10 *)) func)(/* double q(const) x */ tmpi0, /* gsl_sf_result_e10 p result */ &tmpo2);
		
		*((double *) op2) = tmpo2.val;
		*((double *) op3) = tmpo2.err;
		*((int *) op4) = tmpo2.e10;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rl__Oerd_as_minor */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *ip6 = args[6], *ip7 = args[7], *ip8 = args[8], *rp9 = args[9];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], is6 = steps[6], is7 = steps[7], is8 = steps[8], rs9 = steps[9];
	int tmpi0;
	int tmpi1;
	int tmpi2;
	int tmpi3;
	int tmpi4;
	int tmpi5;
	int tmpi6;
	int tmpi7;
	int tmpi8;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, ip6 += is6, ip7 += is7, ip8 += is8, rp9 += rs9){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ja'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jb'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip2), &tmpi2)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jc'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jd'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip4), &tmpi4)) != GSL_SUCCESS){goto fail;} /* arg 'int two_je'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip5), &tmpi5)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jf'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip6), &tmpi6)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jg'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip7), &tmpi7)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jh'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip8), &tmpi8)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ji'*/
		*((double *) rp9) =   ((double (*)(int, int, int, int, int, int, int, int, int)) func)(/* int two_ja */ tmpi0, /* int two_jb */ tmpi1, /* int two_jc */ tmpi2, /* int two_jd */ tmpi3, /* int two_je */ tmpi4, /* int two_jf */ tmpi5, /* int two_jg */ tmpi6, /* int two_jh */ tmpi7, /* int two_ji */ tmpi8);
		
		continue;

	    fail:
		*((double *) rp9) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rd__O */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *ip6 = args[6], *ip7 = args[7], *ip8 = args[8], *rp9 = args[9];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], is6 = steps[6], is7 = steps[7], is8 = steps[8], rs9 = steps[9];
	
	
	
	
	
	
	
	
	
	double tmpr9;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, ip6 += is6, ip7 += is7, ip8 += is8, rp9 += rs9){

		 /* arg 'int two_ja'*/
		 /* arg 'int two_jb'*/
		 /* arg 'int two_jc'*/
		 /* arg 'int two_jd'*/
		 /* arg 'int two_je'*/
		 /* arg 'int two_jf'*/
		 /* arg 'int two_jg'*/
		 /* arg 'int two_jh'*/
		 /* arg 'int two_ji'*/
		tmpr9 =   ((double (*)(int, int, int, int, int, int, int, int, int)) func)(/* int two_ja */ (*((int *) ip0)), /* int two_jb */ (*((int *) ip1)), /* int two_jc */ (*((int *) ip2)), /* int two_jd */ (*((int *) ip3)), /* int two_je */ (*((int *) ip4)), /* int two_jf */ (*((int *) ip5)), /* int two_jg */ (*((int *) ip6)), /* int two_jh */ (*((int *) ip7)), /* int two_ji */ (*((int *) ip8)));
		(*((float *) rp9)) = tmpr9;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l_l_l_l__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_ui__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	unsigned int tmpi1;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'double nu'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int s'*/
		*((double *) rp2) =   ((double (*)(double, unsigned int)) func)(/* double nu */ (*((double *) ip0)), /* unsigned int s */ tmpi1);
		
		continue;

	    fail:
		*((double *) rp2) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_ui__Rd__O */ 

void PyGSL_sf_ufunc_Id_ui__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	double tmpi0;
	
	double tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		tmpi0 = *((float *) ip0); /* arg 'double nu'*/
		 /* arg 'unsigned int s'*/
		tmpr2 =   ((double (*)(double, unsigned int)) func)(/* double nu */ tmpi0, /* unsigned int s */ (*((int *) ip1)));
		(*((float *) rp2)) = tmpr2;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_ui__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Iui__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3];
	unsigned int tmpi0;
	int tmpr1;
	gsl_sf_result tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3){

		if( (_PyGSL_SF_L_TO_U(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int s'*/
		tmpr1 =   ((int (*)(unsigned int, gsl_sf_result *)) func)(/* unsigned int s */ tmpi0, /* gsl_sf_result p result */ &tmpo2);
		*((long *) rp1) = 0;
		*((long *) rp1) = tmpr1;
		*((double *) op2) = tmpo2.val;
		*((double *) op3) = tmpo2.err;
		continue;

	    fail:
		*((int *) rp1) = INT_MIN;
		*((double *) op2) = _PyGSL_NAN;
		*((double *) op3) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Iui__Rl__Ord */ 

void PyGSL_sf_ufunc_Iui__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1], *op2 = args[2], *op3 = args[3];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1], os2 = steps[2], os3 = steps[3];
	
	
	gsl_sf_result tmpo2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1, op2 += os2, op3 += os3){

		 /* arg 'unsigned int s'*/
		*((int *) rp1) =   ((int (*)(unsigned int, gsl_sf_result *)) func)(/* unsigned int s */ (*((int *) ip0)), /* gsl_sf_result p result */ &tmpo2);
		
		*((float *) op2) = tmpo2.val;
		*((float *) op3) = tmpo2.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Iui__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_m__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	
	gsl_mode_t tmpi1;
	int tmpr2;
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		 /* arg 'double q(const) x'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t q(const) mode'*/
		tmpr2 =   ((int (*)(double, gsl_mode_t, gsl_sf_result *)) func)(/* double q(const) x */ (*((double *) ip0)), /* gsl_mode_t q(const) mode */ tmpi1, /* gsl_sf_result p result */ &tmpo3);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		*((double *) op3) = tmpo3.val;
		*((double *) op4) = tmpo3.err;
		continue;

	    fail:
		*((int *) rp2) = INT_MIN;
		*((double *) op3) = _PyGSL_NAN;
		*((double *) op4) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_m__Rl__Ord */ 

void PyGSL_sf_ufunc_Id_m__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4];
	double tmpi0;
	
	
	gsl_sf_result tmpo3;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		 /* arg 'gsl_mode_t q(const) mode'*/
		*((int *) rp2) =   ((int (*)(double, gsl_mode_t, gsl_sf_result *)) func)(/* double q(const) x */ tmpi0, /* gsl_mode_t q(const) mode */ (*((int *) ip1)), /* gsl_sf_result p result */ &tmpo3);
		
		*((float *) op3) = tmpo3.val;
		*((float *) op4) = tmpo3.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_m__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		 /* arg 'double q(const) x'*/
		*((double *) rp1) =   ((double (*)(double)) func)(/* double q(const) x */ (*((double *) ip0)));
		
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rd__O */ 

void PyGSL_sf_ufunc_Id__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	double tmpi0;
	double tmpr1;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		tmpr1 =   ((double (*)(double)) func)(/* double q(const) x */ tmpi0);
		(*((float *) rp1)) = tmpr1;
		continue;
	}
} /* PyGSL_sf_ufunc_Id__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id__RD__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	
	gsl_complex tmpr1;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		 /* arg 'double x'*/
		tmpr1 =   ((gsl_complex (*)(double)) func)(/* double x */ (*((double *) ip0)));
		*(( (double *) rp1)    ) = tmpr1.dat[0];
		*(( (double *) rp1) + 1) = tmpr1.dat[1];
		continue;
	}
} /* PyGSL_sf_ufunc_Id__RD__O */ 

void PyGSL_sf_ufunc_Id__RD__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *rp1 = args[1];
	PyGSL_array_index_t i, is0 = steps[0], rs1 = steps[1];
	double tmpi0;
	gsl_complex tmpr1;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, rp1 += rs1){

		tmpi0 = *((float *) ip0); /* arg 'double x'*/
		tmpr1 =   ((gsl_complex (*)(double)) func)(/* double x */ tmpi0);
		*(( (float *) rp1)    ) = tmpr1.dat[0];
		*(( (float *) rp1) + 1) = tmpr1.dat[1];
		continue;
	}
} /* PyGSL_sf_ufunc_Id__RD__O_as_minor */ 

void PyGSL_sf_ufunc_Id_m__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	gsl_mode_t tmpi1;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'double q(const) x'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'gsl_mode_t mode'*/
		*((double *) rp2) =   ((double (*)(double, gsl_mode_t)) func)(/* double q(const) x */ (*((double *) ip0)), /* gsl_mode_t mode */ tmpi1);
		
		continue;

	    fail:
		*((double *) rp2) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Id_m__Rd__O */ 

void PyGSL_sf_ufunc_Id_m__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	double tmpi0;
	
	double tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) x'*/
		 /* arg 'gsl_mode_t mode'*/
		tmpr2 =   ((double (*)(double, gsl_mode_t)) func)(/* double q(const) x */ tmpi0, /* gsl_mode_t mode */ (*((int *) ip1)));
		(*((float *) rp2)) = tmpr2;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_m__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *rp6 = args[6], *op7 = args[7], *op8 = args[8];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], rs6 = steps[6], os7 = steps[7], os8 = steps[8];
	int tmpi0;
	int tmpi1;
	int tmpi2;
	int tmpi3;
	int tmpi4;
	int tmpi5;
	int tmpr6;
	gsl_sf_result tmpo7;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, rp6 += rs6, op7 += os7, op8 += os8){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ja'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jb'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip2), &tmpi2)) != GSL_SUCCESS){goto fail;} /* arg 'int two_jc'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip3), &tmpi3)) != GSL_SUCCESS){goto fail;} /* arg 'int two_ma'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip4), &tmpi4)) != GSL_SUCCESS){goto fail;} /* arg 'int two_mb'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip5), &tmpi5)) != GSL_SUCCESS){goto fail;} /* arg 'int two_mc'*/
		tmpr6 =   ((int (*)(int, int, int, int, int, int, gsl_sf_result *)) func)(/* int two_ja */ tmpi0, /* int two_jb */ tmpi1, /* int two_jc */ tmpi2, /* int two_ma */ tmpi3, /* int two_mb */ tmpi4, /* int two_mc */ tmpi5, /* gsl_sf_result p result */ &tmpo7);
		*((long *) rp6) = 0;
		*((long *) rp6) = tmpr6;
		*((double *) op7) = tmpo7.val;
		*((double *) op8) = tmpo7.err;
		continue;

	    fail:
		*((int *) rp6) = INT_MIN;
		*((double *) op7) = _PyGSL_NAN;
		*((double *) op8) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l__Rl__Ord */ 

void PyGSL_sf_ufunc_Il_l_l_l_l_l__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *ip4 = args[4], *ip5 = args[5], *rp6 = args[6], *op7 = args[7], *op8 = args[8];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], is4 = steps[4], is5 = steps[5], rs6 = steps[6], os7 = steps[7], os8 = steps[8];
	
	
	
	
	
	
	
	gsl_sf_result tmpo7;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, ip4 += is4, ip5 += is5, rp6 += rs6, op7 += os7, op8 += os8){

		 /* arg 'int two_ja'*/
		 /* arg 'int two_jb'*/
		 /* arg 'int two_jc'*/
		 /* arg 'int two_ma'*/
		 /* arg 'int two_mb'*/
		 /* arg 'int two_mc'*/
		*((int *) rp6) =   ((int (*)(int, int, int, int, int, int, gsl_sf_result *)) func)(/* int two_ja */ (*((int *) ip0)), /* int two_jb */ (*((int *) ip1)), /* int two_jc */ (*((int *) ip2)), /* int two_ma */ (*((int *) ip3)), /* int two_mb */ (*((int *) ip4)), /* int two_mc */ (*((int *) ip5)), /* gsl_sf_result p result */ &tmpo7);
		
		*((float *) op7) = tmpo7.val;
		*((float *) op8) = tmpo7.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_l_l_l_l__Rl__Ord_as_minor */ 

void PyGSL_sf_ufunc_Id_d__RD__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	
	gsl_complex tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'double r'*/
		 /* arg 'double theta'*/
		tmpr2 =   ((gsl_complex (*)(double, double)) func)(/* double r */ (*((double *) ip0)), /* double theta */ (*((double *) ip1)));
		*(( (double *) rp2)    ) = tmpr2.dat[0];
		*(( (double *) rp2) + 1) = tmpr2.dat[1];
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__RD__O */ 

void PyGSL_sf_ufunc_Id_d__RD__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	double tmpi0;
	double tmpi1;
	gsl_complex tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		tmpi0 = *((float *) ip0); /* arg 'double r'*/
		tmpi1 = *((float *) ip1); /* arg 'double theta'*/
		tmpr2 =   ((gsl_complex (*)(double, double)) func)(/* double r */ tmpi0, /* double theta */ tmpi1);
		*(( (float *) rp2)    ) = tmpr2.dat[0];
		*(( (float *) rp2) + 1) = tmpr2.dat[1];
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__RD__O_as_minor */ 

void PyGSL_sf_ufunc_Iui_ui__Rd__O (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	unsigned int tmpi0;
	unsigned int tmpi1;
	
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		if( (_PyGSL_SF_L_TO_U(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int n'*/
		if( (_PyGSL_SF_L_TO_U(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'unsigned int m'*/
		*((double *) rp2) =   ((double (*)(unsigned int, unsigned int)) func)(/* unsigned int n */ tmpi0, /* unsigned int m */ tmpi1);
		
		continue;

	    fail:
		*((double *) rp2) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Iui_ui__Rd__O */ 

void PyGSL_sf_ufunc_Iui_ui__Rd__O_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2];
	
	
	double tmpr2;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2){

		 /* arg 'unsigned int n'*/
		 /* arg 'unsigned int m'*/
		tmpr2 =   ((double (*)(unsigned int, unsigned int)) func)(/* unsigned int n */ (*((int *) ip0)), /* unsigned int m */ (*((int *) ip1)));
		(*((float *) rp2)) = tmpr2;
		continue;
	}
} /* PyGSL_sf_ufunc_Iui_ui__Rd__O_as_minor */ 

void PyGSL_sf_ufunc_Id_d__Rl__Od_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4], os5 = steps[5];
	
	
	int tmpr2;
	
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4, op5 += os5){

		 /* arg 'double q(const) a'*/
		 /* arg 'double q(const) x'*/
		tmpr2 =   ((int (*)(double, double, double *, gsl_sf_result *)) func)(/* double q(const) a */ (*((double *) ip0)), /* double q(const) x */ (*((double *) ip1)), /* double p sgn */ ((double *) op3), /* gsl_sf_result p result */ &tmpo4);
		*((long *) rp2) = 0;
		*((long *) rp2) = tmpr2;
		
		*((double *) op4) = tmpo4.val;
		*((double *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Od_rd */ 

void PyGSL_sf_ufunc_Id_d__Rl__Od_rd_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *rp2 = args[2], *op3 = args[3], *op4 = args[4], *op5 = args[5];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], rs2 = steps[2], os3 = steps[3], os4 = steps[4], os5 = steps[5];
	double tmpi0;
	double tmpi1;
	
	double tmpo3;
	gsl_sf_result tmpo4;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, rp2 += rs2, op3 += os3, op4 += os4, op5 += os5){

		tmpi0 = *((float *) ip0); /* arg 'double q(const) a'*/
		tmpi1 = *((float *) ip1); /* arg 'double q(const) x'*/
		*((int *) rp2) =   ((int (*)(double, double, double *, gsl_sf_result *)) func)(/* double q(const) a */ tmpi0, /* double q(const) x */ tmpi1, /* double p sgn */ &tmpo3, /* gsl_sf_result p result */ &tmpo4);
		
		/*<ufunc_arg._FloatArgumentAsMinor object at 0x10918da48>*/ *((float *) op3) = tmpo3;
		*((float *) op4) = tmpo4.val;
		*((float *) op5) = tmpo4.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Id_d__Rl__Od_rd_as_minor */ 

void PyGSL_sf_ufunc_Il_l_d_d__Rl__Ord (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6];
	int tmpi0;
	int tmpi1;
	
	
	int tmpr4;
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6){

		if( (_PyGSL_SF_L_TO_I(*((long *) ip0), &tmpi0)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) n'*/
		if( (_PyGSL_SF_L_TO_I(*((long *) ip1), &tmpi1)) != GSL_SUCCESS){goto fail;} /* arg 'int q(const) l'*/
		 /* arg 'double q(const) Z'*/
		 /* arg 'double q(const) r'*/
		tmpr4 =   ((int (*)(int, int, double, double, gsl_sf_result *)) func)(/* int q(const) n */ tmpi0, /* int q(const) l */ tmpi1, /* double q(const) Z */ (*((double *) ip2)), /* double q(const) r */ (*((double *) ip3)), /* gsl_sf_result p result */ &tmpo5);
		*((long *) rp4) = 0;
		*((long *) rp4) = tmpr4;
		*((double *) op5) = tmpo5.val;
		*((double *) op6) = tmpo5.err;
		continue;

	    fail:
		*((int *) rp4) = INT_MIN;
		*((double *) op5) = _PyGSL_NAN;
		*((double *) op6) = _PyGSL_NAN;
	}
} /* PyGSL_sf_ufunc_Il_l_d_d__Rl__Ord */ 

void PyGSL_sf_ufunc_Il_l_d_d__Rl__Ord_as_minor (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{
	char *ip0 = args[0], *ip1 = args[1], *ip2 = args[2], *ip3 = args[3], *rp4 = args[4], *op5 = args[5], *op6 = args[6];
	PyGSL_array_index_t i, is0 = steps[0], is1 = steps[1], is2 = steps[2], is3 = steps[3], rs4 = steps[4], os5 = steps[5], os6 = steps[6];
	
	
	double tmpi2;
	double tmpi3;
	
	gsl_sf_result tmpo5;
	 for(i = 0; i < dimensions[0]; ++i, ip0 += is0, ip1 += is1, ip2 += is2, ip3 += is3, rp4 += rs4, op5 += os5, op6 += os6){

		 /* arg 'int q(const) n'*/
		 /* arg 'int q(const) l'*/
		tmpi2 = *((float *) ip2); /* arg 'double q(const) Z'*/
		tmpi3 = *((float *) ip3); /* arg 'double q(const) r'*/
		*((int *) rp4) =   ((int (*)(int, int, double, double, gsl_sf_result *)) func)(/* int q(const) n */ (*((int *) ip0)), /* int q(const) l */ (*((int *) ip1)), /* double q(const) Z */ tmpi2, /* double q(const) r */ tmpi3, /* gsl_sf_result p result */ &tmpo5);
		
		*((float *) op5) = tmpo5.val;
		*((float *) op6) = tmpo5.err;
		continue;
	}
} /* PyGSL_sf_ufunc_Il_l_d_d__Rl__Ord_as_minor */ 
