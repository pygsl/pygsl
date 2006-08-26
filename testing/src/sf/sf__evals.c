typedef gsl_complex PyGSL_sf_ufunc_pD_DD__one(gsl_complex, gsl_complex);
void PyGSL_sf_ufunc_pD_DD_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_DD__one *) func)( *((gsl_complex *)ip0) , *((gsl_complex *)ip1) );
	}
}
void PyGSL_sf_ufunc_pD_DD__as_DD_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_DD__one *) func)( *((gsl_complex *)ip0) , *((gsl_complex *)ip1) );
	}
}

typedef gsl_complex PyGSL_sf_ufunc_pD_D__one(gsl_complex);
void PyGSL_sf_ufunc_pD_D_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_D__one *) func)( *((gsl_complex *)ip0) );
	}
}
void PyGSL_sf_ufunc_pD_D__as_D_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_D__one *) func)( *((gsl_complex *)ip0) );
	}
}

typedef gsl_complex PyGSL_sf_ufunc_pD_Dd__one(gsl_complex, double);
void PyGSL_sf_ufunc_pD_Dd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_Dd__one *) func)( *((gsl_complex *)ip0) , *((double *)ip1) );
	}
}
void PyGSL_sf_ufunc_pD_Df__as_Dd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_Dd__one *) func)( *((gsl_complex *)ip0) , (double)*((float *)ip1) );
	}
}

typedef gsl_complex PyGSL_sf_ufunc_pD_d__one(double);
void PyGSL_sf_ufunc_pD_d_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_d__one *) func)( *((double *)ip0) );
	}
}
void PyGSL_sf_ufunc_pD_f__as_d_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_d__one *) func)( (double)*((float *)ip0) );
	}
}

typedef gsl_complex PyGSL_sf_ufunc_pD_dd__one(double, double);
void PyGSL_sf_ufunc_pD_dd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_dd__one *) func)( *((double *)ip0) , *((double *)ip1) );
	}
}
void PyGSL_sf_ufunc_pD_ff__as_dd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(gsl_complex *)op0 = ((PyGSL_sf_ufunc_pD_dd__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) );
	}
}

typedef double PyGSL_sf_ufunc_pd_D__one(gsl_complex);
void PyGSL_sf_ufunc_pd_D_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_D__one *) func)( *((gsl_complex *)ip0) );
	}
}
void PyGSL_sf_ufunc_pd_D__as_D_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_D__one *) func)( *((gsl_complex *)ip0) );
	}
}

typedef double PyGSL_sf_ufunc_pd_d__one(double);
void PyGSL_sf_ufunc_pd_d_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_d__one *) func)( *((double *)ip0) );
	}
}
void PyGSL_sf_ufunc_pd_f__as_d_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_d__one *) func)( (double)*((float *)ip0) );
	}
}

typedef double PyGSL_sf_ufunc_pd_dd__one(double, double);
void PyGSL_sf_ufunc_pd_dd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_dd__one *) func)( *((double *)ip0) , *((double *)ip1) );
	}
}
void PyGSL_sf_ufunc_pd_ff__as_dd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_dd__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) );
	}
}

typedef double PyGSL_sf_ufunc_pd_ddd__one(double, double, double);
void PyGSL_sf_ufunc_pd_ddd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_ddd__one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) );
	}
}
void PyGSL_sf_ufunc_pd_fff__as_ddd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_ddd__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) );
	}
}

typedef double PyGSL_sf_ufunc_pd_dddd__one(double, double, double, double);
void PyGSL_sf_ufunc_pd_dddd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_dddd__one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((double *)ip3) );
	}
}
void PyGSL_sf_ufunc_pd_ffff__as_dddd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_dddd__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , (double)*((float *)ip3) );
	}
}

typedef double PyGSL_sf_ufunc_pd_ddddm__one(double, double, double, double, gsl_mode_t);
void PyGSL_sf_ufunc_pd_ddddm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , os0=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *op0=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_ddddm__one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((double *)ip3) , *((gsl_mode_t *)ip4) );
	}
}
void PyGSL_sf_ufunc_pd_ffffm__as_ddddm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , os0=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *op0=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_ddddm__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , (double)*((float *)ip3) , *((gsl_mode_t *)ip4) );
	}
}

typedef double PyGSL_sf_ufunc_pd_dddm__one(double, double, double, gsl_mode_t);
void PyGSL_sf_ufunc_pd_dddm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_dddm__one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((gsl_mode_t *)ip3) );
	}
}
void PyGSL_sf_ufunc_pd_fffm__as_dddm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_dddm__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , *((gsl_mode_t *)ip3) );
	}
}

typedef double PyGSL_sf_ufunc_pd_ddm__one(double, double, gsl_mode_t);
void PyGSL_sf_ufunc_pd_ddm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_ddm__one *) func)( *((double *)ip0) , *((double *)ip1) , *((gsl_mode_t *)ip2) );
	}
}
void PyGSL_sf_ufunc_pd_ffm__as_ddm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_ddm__one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , *((gsl_mode_t *)ip2) );
	}
}

typedef double PyGSL_sf_ufunc_pd_di__one(double, int);
void PyGSL_sf_ufunc_pd_di_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_di__one *) func)( *((double *)ip0) , *((int *)ip1) );
	}
}
void PyGSL_sf_ufunc_pd_fi__as_di_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_di__one *) func)( (double)*((float *)ip0) , *((int *)ip1) );
	}
}

typedef double PyGSL_sf_ufunc_pd_dm__one(double, gsl_mode_t);
void PyGSL_sf_ufunc_pd_dm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_dm__one *) func)( *((double *)ip0) , *((gsl_mode_t *)ip1) );
	}
}
void PyGSL_sf_ufunc_pd_fm__as_dm_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_dm__one *) func)( (double)*((float *)ip0) , *((gsl_mode_t *)ip1) );
	}
}

typedef double PyGSL_sf_ufunc_pd_dui__one(double, unsigned int);
void PyGSL_sf_ufunc_pd_dui_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_dui__one *) func)( *((double *)ip0) , *((unsigned int *)ip1) );
	}
}
void PyGSL_sf_ufunc_pd_fui__as_dui_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_dui__one *) func)( (double)*((float *)ip0) , *((unsigned int *)ip1) );
	}
}

typedef double PyGSL_sf_ufunc_pd_i__one(int);
void PyGSL_sf_ufunc_pd_i_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_i__one *) func)( *((int *)ip0) );
	}
}
void PyGSL_sf_ufunc_pd_i__as_i_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_i__one *) func)( *((int *)ip0) );
	}
}

typedef double PyGSL_sf_ufunc_pd_id__one(int, double);
void PyGSL_sf_ufunc_pd_id_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_id__one *) func)( *((int *)ip0) , *((double *)ip1) );
	}
}
void PyGSL_sf_ufunc_pd_if__as_id_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_id__one *) func)( *((int *)ip0) , (double)*((float *)ip1) );
	}
}

typedef double PyGSL_sf_ufunc_pd_idd__one(int, double, double);
void PyGSL_sf_ufunc_pd_idd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_idd__one *) func)( *((int *)ip0) , *((double *)ip1) , *((double *)ip2) );
	}
}
void PyGSL_sf_ufunc_pd_iff__as_idd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_idd__one *) func)( *((int *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) );
	}
}

typedef double PyGSL_sf_ufunc_pd_iid__one(int, int, double);
void PyGSL_sf_ufunc_pd_iid_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_iid__one *) func)( *((int *)ip0) , *((int *)ip1) , *((double *)ip2) );
	}
}
void PyGSL_sf_ufunc_pd_iif__as_iid_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_iid__one *) func)( *((int *)ip0) , *((int *)ip1) , (double)*((float *)ip2) );
	}
}

typedef double PyGSL_sf_ufunc_pd_iidd__one(int, int, double, double);
void PyGSL_sf_ufunc_pd_iidd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_iidd__one *) func)( *((int *)ip0) , *((int *)ip1) , *((double *)ip2) , *((double *)ip3) );
	}
}
void PyGSL_sf_ufunc_pd_iiff__as_iidd_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_iidd__one *) func)( *((int *)ip0) , *((int *)ip1) , (double)*((float *)ip2) , (double)*((float *)ip3) );
	}
}

typedef double PyGSL_sf_ufunc_pd_iiiiii__one(int, int, int, int, int, int);
void PyGSL_sf_ufunc_pd_iiiiii_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , os0=steps[6] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *op0=args[6] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_iiiiii__one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) );
	}
}
void PyGSL_sf_ufunc_pd_iiiiii__as_iiiiii_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , os0=steps[6] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *op0=args[6] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_iiiiii__one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) );
	}
}

typedef double PyGSL_sf_ufunc_pd_iiiiiiiii__one(int, int, int, int, int, int, int, int, int);
void PyGSL_sf_ufunc_pd_iiiiiiiii_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , is6=steps[6] , is7=steps[7] , is8=steps[8] , os0=steps[9] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *ip6=args[6] , *ip7=args[7] , *ip8=args[8] , *op0=args[9] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,ip6+=is6 ,ip7+=is7 ,ip8+=is8 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_iiiiiiiii__one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) , *((int *)ip6) , *((int *)ip7) , *((int *)ip8) );
	}
}
void PyGSL_sf_ufunc_pd_iiiiiiiii__as_iiiiiiiii_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , is6=steps[6] , is7=steps[7] , is8=steps[8] , os0=steps[9] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *ip6=args[6] , *ip7=args[7] , *ip8=args[8] , *op0=args[9] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,ip6+=is6 ,ip7+=is7 ,ip8+=is8 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_iiiiiiiii__one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) , *((int *)ip6) , *((int *)ip7) , *((int *)ip8) );
	}
}

typedef double PyGSL_sf_ufunc_pd_ui__one(unsigned int);
void PyGSL_sf_ufunc_pd_ui_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_ui__one *) func)( *((unsigned int *)ip0) );
	}
}
void PyGSL_sf_ufunc_pd_ui__as_ui_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] ;
	char   *ip0=args[0] , *op0=args[1] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_ui__one *) func)( *((unsigned int *)ip0) );
	}
}

typedef double PyGSL_sf_ufunc_pd_uiui__one(unsigned int, unsigned int);
void PyGSL_sf_ufunc_pd_uiui_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(double *)op0 = ((PyGSL_sf_ufunc_pd_uiui__one *) func)( *((unsigned int *)ip0) , *((unsigned int *)ip1) );
	}
}
void PyGSL_sf_ufunc_pd_uiui__as_uiui_ (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		*(float *)op0 = (float)((PyGSL_sf_ufunc_pd_uiui__one *) func)( *((unsigned int *)ip0) , *((unsigned int *)ip1) );
	}
}

typedef int PyGSL_sf_ufunc_qi_d_rd_one(double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_d_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_d_rd_one *) func)( *((double *)ip0) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_f_rf_as_d_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_d_rd_one *) func)( (double)*((float *)ip0) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_d_rdd_one(double, gsl_sf_result *, double *);
void PyGSL_sf_ufunc_qi_d_rdd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] , os2=steps[3] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] , *op2=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_d_rdd_one *) func)( *((double *)ip0) , &r0 , (double *)op1 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_f_rff_as_d_rdd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] , os2=steps[3] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] , *op2=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		double tmp1;
		flag = ((PyGSL_sf_ufunc_qi_d_rdd_one *) func)( (double)*((float *)ip0) , &r0 , &tmp1 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
			/* casting fake out_counter = 2, counter = 1 */
			*(float *) op2 = (float) tmp1;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dd_ddd_one(double, double, double *, double *, double *);
void PyGSL_sf_ufunc_qi_dd_ddd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] , os2=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] , *op2=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		flag = ((PyGSL_sf_ufunc_qi_dd_ddd_one *) func)( *((double *)ip0) , *((double *)ip1) , (double *)op0 , (double *)op1 , (double *)op2 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
		}else{
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ff_fff_as_dd_ddd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] , os2=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] , *op2=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		double tmp0;
		double tmp1;
		double tmp2;
		flag = ((PyGSL_sf_ufunc_qi_dd_ddd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , &tmp0 , &tmp1 , &tmp2 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
		}else{
			/* casting fake out_counter = 0, counter = 0 */
			*(float *) op0 = (float) tmp0;
			/* casting fake out_counter = 1, counter = 1 */
			*(float *) op1 = (float) tmp1;
			/* casting fake out_counter = 2, counter = 2 */
			*(float *) op2 = (float) tmp2;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dd_rd_one(double, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_dd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dd_rd_one *) func)( *((double *)ip0) , *((double *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ff_rf_as_dd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dd_rd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dd_rdd_one(double, double, gsl_sf_result *, double *);
void PyGSL_sf_ufunc_qi_dd_rdd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] , os2=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] , *op2=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dd_rdd_one *) func)( *((double *)ip0) , *((double *)ip1) , &r0 , (double *)op1 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ff_rff_as_dd_rdd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] , os2=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] , *op2=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		double tmp1;
		flag = ((PyGSL_sf_ufunc_qi_dd_rdd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , &r0 , &tmp1 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
			/* casting fake out_counter = 2, counter = 1 */
			*(float *) op2 = (float) tmp1;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dd_rdrd_one(double, double, gsl_sf_result *, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_dd_rdrd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] , os2=steps[4] , os3=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] , *op2=args[4] , *op3=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ,op2+=os2 ,op3+=os3 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		gsl_sf_result r1;
		flag = ((PyGSL_sf_ufunc_qi_dd_rdrd_one *) func)( *((double *)ip0) , *((double *)ip1) , &r0 , &r1 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
			*(double *) op3 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
			*(double *) op2 = r1.val;
			*(double *) op3 = r1.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ff_rfrf_as_dd_rdrd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] , os2=steps[4] , os3=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] , *op2=args[4] , *op3=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ,op2+=os2 ,op3+=os3 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		gsl_sf_result r1;
		flag = ((PyGSL_sf_ufunc_qi_dd_rdrd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , &r0 , &r1 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
			*(float *) op2 = (float) gsl_nan();
			*(float *) op3 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
			*(float *) op2 = r1.val;
			*(float *) op3 = r1.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_ddd_erd_one(double, double, double, gsl_sf_result_e10 *);
void PyGSL_sf_ufunc_qi_ddd_erd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] , os2=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] , *op2=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result_e10 r0;
		flag = ((PyGSL_sf_ufunc_qi_ddd_erd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(int *) op2 = (int) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
			*(int *) op2 = r0.e10;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fff_erf_as_ddd_erd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] , os2=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] , *op2=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result_e10 r0;
		flag = ((PyGSL_sf_ufunc_qi_ddd_erd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
			*(int *) op2 = (int) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
			*(int *) op2 = r0.e10;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_ddd_rd_one(double, double, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_ddd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ddd_rd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fff_rf_as_ddd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ddd_rd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dddd_rd_one(double, double, double, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_dddd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dddd_rd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((double *)ip3) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ffff_rf_as_dddd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dddd_rd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , (double)*((float *)ip3) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_ddddm_rd_one(double, double, double, double, gsl_mode_t, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_ddddm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , os0=steps[5] , os1=steps[6] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *op0=args[5] , *op1=args[6] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ddddm_rd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((double *)ip3) , *((gsl_mode_t *)ip4) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ffffm_rf_as_ddddm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , os0=steps[5] , os1=steps[6] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *op0=args[5] , *op1=args[6] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ddddm_rd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , (double)*((float *)ip3) , *((gsl_mode_t *)ip4) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one(double, double, double, int, gsl_sf_result *, gsl_sf_result *, gsl_sf_result *, gsl_sf_result *, double *, double *);
void PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] , os2=steps[6] , os3=steps[7] , os4=steps[8] , os5=steps[9] , os6=steps[10] , os7=steps[11] , os8=steps[12] , os9=steps[13] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] , *op2=args[6] , *op3=args[7] , *op4=args[8] , *op5=args[9] , *op6=args[10] , *op7=args[11] , *op8=args[12] , *op9=args[13] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ,op2+=os2 ,op3+=os3 ,op4+=os4 ,op5+=os5 ,op6+=os6 ,op7+=os7 ,op8+=os8 ,op9+=os9 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		gsl_sf_result r1;
		gsl_sf_result r2;
		gsl_sf_result r3;
		flag = ((PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((int *)ip3) , &r0 , &r1 , &r2 , &r3 , (double *)op4 , (double *)op5 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(double *) op2 = (double) gsl_nan();
			*(double *) op3 = (double) gsl_nan();
			*(double *) op4 = (double) gsl_nan();
			*(double *) op5 = (double) gsl_nan();
			*(double *) op6 = (double) gsl_nan();
			*(double *) op7 = (double) gsl_nan();
			*(double *) op8 = (double) gsl_nan();
			*(double *) op9 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
			*(double *) op2 = r1.val;
			*(double *) op3 = r1.err;
			*(double *) op4 = r2.val;
			*(double *) op5 = r2.err;
			*(double *) op6 = r3.val;
			*(double *) op7 = r3.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fffi_rfrfrfrfff_as_dddi_rdrdrdrddd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] , os2=steps[6] , os3=steps[7] , os4=steps[8] , os5=steps[9] , os6=steps[10] , os7=steps[11] , os8=steps[12] , os9=steps[13] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] , *op2=args[6] , *op3=args[7] , *op4=args[8] , *op5=args[9] , *op6=args[10] , *op7=args[11] , *op8=args[12] , *op9=args[13] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ,op2+=os2 ,op3+=os3 ,op4+=os4 ,op5+=os5 ,op6+=os6 ,op7+=os7 ,op8+=os8 ,op9+=os9 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		gsl_sf_result r1;
		gsl_sf_result r2;
		gsl_sf_result r3;
		double tmp4;
		double tmp5;
		flag = ((PyGSL_sf_ufunc_qi_dddi_rdrdrdrddd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , *((int *)ip3) , &r0 , &r1 , &r2 , &r3 , &tmp4 , &tmp5 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
			*(float *) op2 = (float) gsl_nan();
			*(float *) op3 = (float) gsl_nan();
			*(float *) op4 = (float) gsl_nan();
			*(float *) op5 = (float) gsl_nan();
			*(float *) op6 = (float) gsl_nan();
			*(float *) op7 = (float) gsl_nan();
			*(double *) op8 = (double) gsl_nan();
			*(double *) op9 = (double) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
			*(float *) op2 = r1.val;
			*(float *) op3 = r1.err;
			*(float *) op4 = r2.val;
			*(float *) op5 = r2.err;
			*(float *) op6 = r3.val;
			*(float *) op7 = r3.err;
			/* casting fake out_counter = 8, counter = 4 */
			*(float *) op8 = (float) tmp4;
			/* casting fake out_counter = 9, counter = 5 */
			*(float *) op9 = (float) tmp5;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dddm_rd_one(double, double, double, gsl_mode_t, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_dddm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dddm_rd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((double *)ip2) , *((gsl_mode_t *)ip3) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fffm_rf_as_dddm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dddm_rd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , *((gsl_mode_t *)ip3) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_ddm_rd_one(double, double, gsl_mode_t, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_ddm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ddm_rd_one *) func)( *((double *)ip0) , *((double *)ip1) , *((gsl_mode_t *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ffm_rf_as_ddm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ddm_rd_one *) func)( (double)*((float *)ip0) , (double)*((float *)ip1) , *((gsl_mode_t *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_di_rd_one(double, int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_di_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_di_rd_one *) func)( *((double *)ip0) , *((int *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fi_rf_as_di_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_di_rd_one *) func)( (double)*((float *)ip0) , *((int *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dm_rd_one(double, gsl_mode_t, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_dm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dm_rd_one *) func)( *((double *)ip0) , *((gsl_mode_t *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fm_rf_as_dm_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dm_rd_one *) func)( (double)*((float *)ip0) , *((gsl_mode_t *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_dui_rd_one(double, unsigned int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_dui_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dui_rd_one *) func)( *((double *)ip0) , *((unsigned int *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_fui_rf_as_dui_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_dui_rd_one *) func)( (double)*((float *)ip0) , *((unsigned int *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_i_rd_one(int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_i_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_i_rd_one *) func)( *((int *)ip0) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_i_rf_as_i_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_i_rd_one *) func)( *((int *)ip0) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_id_rd_one(int, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_id_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_id_rd_one *) func)( *((int *)ip0) , *((double *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_if_rf_as_id_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_id_rd_one *) func)( *((int *)ip0) , (double)*((float *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_idd_rd_one(int, double, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_idd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_idd_rd_one *) func)( *((int *)ip0) , *((double *)ip1) , *((double *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_iff_rf_as_idd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_idd_rd_one *) func)( *((int *)ip0) , (double)*((float *)ip1) , (double)*((float *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_iid_erd_one(int, int, double, gsl_sf_result_e10 *);
void PyGSL_sf_ufunc_qi_iid_erd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] , os2=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] , *op2=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result_e10 r0;
		flag = ((PyGSL_sf_ufunc_qi_iid_erd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((double *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
			*(int *) op2 = (int) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
			*(int *) op2 = r0.e10;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_iif_erf_as_iid_erd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] , os2=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] , *op2=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ,op2+=os2 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result_e10 r0;
		flag = ((PyGSL_sf_ufunc_qi_iid_erd_one *) func)( *((int *)ip0) , *((int *)ip1) , (double)*((float *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
			*(int *) op2 = (int) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
			*(int *) op2 = r0.e10;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_iid_rd_one(int, int, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_iid_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iid_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((double *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_iif_rf_as_iid_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , os0=steps[3] , os1=steps[4] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *op0=args[3] , *op1=args[4] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iid_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , (double)*((float *)ip2) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_iidd_rd_one(int, int, double, double, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_iidd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iidd_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((double *)ip2) , *((double *)ip3) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_iiff_rf_as_iidd_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , os0=steps[4] , os1=steps[5] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *op0=args[4] , *op1=args[5] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iidd_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , (double)*((float *)ip2) , (double)*((float *)ip3) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_iiiiii_rd_one(int, int, int, int, int, int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_iiiiii_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , os0=steps[6] , os1=steps[7] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *op0=args[6] , *op1=args[7] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iiiiii_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_iiiiii_rf_as_iiiiii_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , os0=steps[6] , os1=steps[7] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *op0=args[6] , *op1=args[7] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iiiiii_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one(int, int, int, int, int, int, int, int, int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_iiiiiiiii_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , is6=steps[6] , is7=steps[7] , is8=steps[8] , os0=steps[9] , os1=steps[10] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *ip6=args[6] , *ip7=args[7] , *ip8=args[8] , *op0=args[9] , *op1=args[10] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,ip6+=is6 ,ip7+=is7 ,ip8+=is8 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) , *((int *)ip6) , *((int *)ip7) , *((int *)ip8) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_iiiiiiiii_rf_as_iiiiiiiii_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , is2=steps[2] , is3=steps[3] , is4=steps[4] , is5=steps[5] , is6=steps[6] , is7=steps[7] , is8=steps[8] , os0=steps[9] , os1=steps[10] ;
	char   *ip0=args[0] , *ip1=args[1] , *ip2=args[2] , *ip3=args[3] , *ip4=args[4] , *ip5=args[5] , *ip6=args[6] , *ip7=args[7] , *ip8=args[8] , *op0=args[9] , *op1=args[10] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,ip2+=is2 ,ip3+=is3 ,ip4+=is4 ,ip5+=is5 ,ip6+=is6 ,ip7+=is7 ,ip8+=is8 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_iiiiiiiii_rd_one *) func)( *((int *)ip0) , *((int *)ip1) , *((int *)ip2) , *((int *)ip3) , *((int *)ip4) , *((int *)ip5) , *((int *)ip6) , *((int *)ip7) , *((int *)ip8) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_ui_rd_one(unsigned int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_ui_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ui_rd_one *) func)( *((unsigned int *)ip0) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_ui_rf_as_ui_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , os0=steps[1] , os1=steps[2] ;
	char   *ip0=args[0] , *op0=args[1] , *op1=args[2] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_ui_rd_one *) func)( *((unsigned int *)ip0) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

typedef int PyGSL_sf_ufunc_qi_uiui_rd_one(unsigned int, unsigned int, gsl_sf_result *);
void PyGSL_sf_ufunc_qi_uiui_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_uiui_rd_one *) func)( *((unsigned int *)ip0) , *((unsigned int *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(double *) op0 = (double) gsl_nan();
			*(double *) op1 = (double) gsl_nan();
		}else{
			*(double *) op0 = r0.val;
			*(double *) op1 = r0.err;
		}
		}
	}
}
void PyGSL_sf_ufunc_qi_uiui_rf_as_uiui_rd (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){
	PyGSL_array_index_t i,  is0=steps[0] , is1=steps[1] , os0=steps[2] , os1=steps[3] ;
	char   *ip0=args[0] , *ip1=args[1] , *op0=args[2] , *op1=args[3] ;
	for(i = 0; i<dimensions[0]; i++ ,ip0+=is0 ,ip1+=is1 ,op0+=os0 ,op1+=os1 ){
		DEBUG_MESS(2, "Evaluating element %ld", (long)i);
		{
		int flag;
		gsl_sf_result r0;
		flag = ((PyGSL_sf_ufunc_qi_uiui_rd_one *) func)( *((unsigned int *)ip0) , *((unsigned int *)ip1) , &r0 );
		if (flag != GSL_SUCCESS){
			*(float *) op0 = (float) gsl_nan();
			*(float *) op1 = (float) gsl_nan();
		}else{
			*(float *) op0 = r0.val;
			*(float *) op1 = r0.err;
		}
		}
	}
}

