pygsl_errno=gsl_Extension("errno",
			 ['src/init/errorno.c'],
                         gsl_min_version=(1,),
                         define_macros = macros,
                         python_min_version=(2,1),
                         )
exts.append(pygsl_errno)
pygsl_init=gsl_Extension("init",
			 ['src/init/initmodule.c'],
                         gsl_min_version=(1,),
                         define_macros = macros,
                         python_min_version=(2,1),
                         )
exts.append(pygsl_init)
pygsl_init=gsl_Extension("inittest",
			 ['src/init/inittestmodule.c'],
                         gsl_min_version=(1,),
                         define_macros = macros,
                         python_min_version=(2,1),
                         )
exts.append(pygsl_init)

exts.append(SWIG_Extension("gslwrap",
                           ["src/gslwrap/gsl_gslwrap.i"],
                           swig_include_dirs=["src/gslwrap/"],
                           # -builtin does not yet work for gslwrap
                           # swig_flags = swig_flags,
                           define_macros = macros,
                           #gsl_min_version=(1,10),
                           python_min_version=(2,1)
                       )
        )


exts.append(SWIG_Extension("hankel",                           
                           ["src/hankel/gsl_hankel.i"],
                           swig_include_dirs=["src/hankel"],
                           swig_flags = swig_flags,
                           gsl_min_version=(1,0),
                           define_macros = macros,
                           python_min_version=(2,0),
                          )
            
            )

exts.append(SWIG_Extension("sum",
                          ["src/sum/gsl_sum.i"],
                          gsl_min_version=(1,0),
                          swig_flags = swig_flags,
                          define_macros = macros,
                          python_min_version=(2,0),
                          )
            )
flag = 0
try:
    flag = gsl_features.bspline
except AttributeError:
    pass

if flag:
	exts.append(SWIG_Extension("bspline",
				   ["src/bspline/bspline.i"],
				   include_dirs=["src/bspline"],
				   swig_include_dirs=["src/bspline"],
				   swig_flags = swig_flags,
				   #gsl_min_version=(1,9),
				   define_macros = macros,
				   python_min_version=(2,1),
				   )            
		)

flag = 0
try:
    flag = gsl_features.interp2d
except AttributeError:
    pass
if flag:
    exts.append(SWIG_Extension("interpolation2d_wrap",
                               ["src/gslwrap/interpolation2d.i"],
                               include_dirs=["src/gslwrap"],
                               swig_include_dirs=["src/gslwrap"],
                               swig_flags = swig_flags,
                               define_macros = macros,
                               python_min_version=(2,1),
                           )            
            )


flag = 0
try:
    flag = gsl_features.multfit_robust
except AttributeError:
    pass
if flag:
        exts.append(SWIG_Extension("multifit_robust",
                                   ["src/callback/gsl_multifit_robust.i"],
                                   include_dirs=["src/callback"],
                                   swig_include_dirs=["src/callback"],
                                   swig_flags = swig_flags,
                                   #gsl_min_version=(1,2),
                                   define_macros = macros,
                                   python_min_version=(2,1),
                                   ) 
            )
        
flag = 0
try:
    flag = gsl_features.odeiv2
except AttributeError:
    pass
if flag:
    exts.append(SWIG_Extension("odeiv2",
                               ["src/callback/gsl_odeiv2.i"],
                               include_dirs=["src/callback"],
                               swig_include_dirs=["src/callback"],
                               swig_flags = swig_flags,
                               #gsl_min_version=(1,2),
                               define_macros = macros,
                               python_min_version=(2,1),
                               )
        )

exts.append(SWIG_Extension("_poly",
                          ["src/poly/gsl_poly.i"],
                          include_dirs=["src/poly"],
                           swig_flags = swig_flags,
                          define_macros = macros,
                          #gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
            )

exts.append(SWIG_Extension("_block",
                          ["src/block/gsl_block.i"],
                           swig_include_dirs=["src/block"],
                          define_macros = macros,
                           swig_flags = swig_flags,
                           #gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
            )

pygsl_siman=gsl_Extension("_siman",
                          ['src/simanmodule.c'],
                          define_macros = macros,
                          #gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
exts.append(pygsl_siman)

pygsl_const=gsl_Extension("const",
			  ['src/constmodule.c'],
                          define_macros = macros,
                          #gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
exts.append(pygsl_const)
if BUILD_DEPRECATED:
    pygsl_diff = gsl_Extension("diff",
                               ['src/diffmodule.c'],
                               define_macros = macros,
                               gsl_min_version=(1,0),
                               python_min_version=(2,1)
                               )
    exts.append(pygsl_diff)
    pygsl_sf=gsl_Extension("sf",
		       ['src/sfmodule.c'],
		       gsl_min_version=(1,),
                       define_macros = macros,
                       python_min_version=(2,1)
                       )
    exts.append(pygsl_sf)

pygsl__callback = SWIG_Extension("_callback",
                           ["src/callback/gsl_callback.i"],
                           include_dirs=["src/callback"],
                           swig_include_dirs=["src/callback"],
                           # -builtin can still have problems for some functions
                           swig_flags = swig_flags,
                           #gsl_min_version=(1,2),
                           define_macros = macros,
                           python_min_version=(2,1),
)
print(pygsl__callback)
exts.append(pygsl__callback)

flag = 0
try:
    flag = gsl_features.deriv
except AttributeError:
    pass
if flag:
    pygsl_deriv = gsl_Extension("deriv",
                               ['src/derivmodule.c'],
                               define_macros = macros,
                               #gsl_min_version=(1, 5),
                               python_min_version=(2,1)
                               )
    exts.append(pygsl_deriv)

pygsl_transform = gsl_Extension("_transform",
                           ['src/transform/transformmodule.c'],
                           define_macros = macros,
                           #gsl_min_version=(1,0),
                           python_min_version=(2,1)
                           )
exts.append(pygsl_transform)

pygsl_rng=gsl_Extension("rng",
                        ['src/rng/rngmodule.c'],
                        gsl_min_version=(1,0),
                        define_macros = macros,
                        python_min_version=(2,1)
                    )
exts.append(pygsl_rng)
        
pygsl_ieee=gsl_Extension("ieee",
                         ['src/ieeemodule.c'],
                         gsl_min_version=(1,),
                         define_macros = macros,
                         python_min_version=(2,1)
)
exts.append(pygsl_ieee)

pygsl_histogram=gsl_Extension("histogram",
                              ['src/histogram/histogrammodule.c'],
                              define_macros = macros,
                              gsl_min_version=(1,0),
                              python_min_version=(2,2)
)
extsOnly2.append(pygsl_histogram)    
pygsl_multimin=gsl_Extension("multimin",
                             ['src/multiminmodule.c'],
                             define_macros = macros,
                             gsl_min_version=(1,0),
                             python_min_version=(2,2)
)
extsOnly2.append(pygsl_multimin)    


pygsl_qrng=gsl_Extension("_qrng",
                         ['src/qrng_module.c'],
                         gsl_min_version=(1,0),
                         define_macros = macros,
                         python_min_version=(2,1)
                         )
exts.append(pygsl_qrng)

pygsl_statistics_basis=gsl_Extension("statistics._stat",
                                     ['src/statistics/_statmodule.c'],
                                     gsl_min_version=(1,),
                                     define_macros = macros,
                                     python_min_version=(2,1)
                                     )
exts.append(pygsl_statistics_basis)
pygsl_statistics_uchar=gsl_Extension("statistics.uchar",
                                     ['src/statistics/ucharmodule.c'],
                                     gsl_min_version=(1,),
                                     define_macros = macros,
                                     python_min_version=(2,1)
                                     )
exts.append(pygsl_statistics_uchar)    
pygsl_statistics_char=gsl_Extension("statistics.char",
                                    ['src/statistics/charmodule.c'],
                                    gsl_min_version=(1,),
                                    define_macros = macros,
                                    python_min_version=(2,1)
                                    )
exts.append(pygsl_statistics_char)    
pygsl_statistics_double=gsl_Extension("statistics.double",
                                      ['src/statistics/doublemodule.c'],
                                      gsl_min_version=(1,),
                                      define_macros = macros,
                                      python_min_version=(2,1)
                                      )
exts.append(pygsl_statistics_double)    
pygsl_statistics_float=gsl_Extension("statistics.float",
                                     ['src/statistics/floatmodule.c'],
                                     gsl_min_version=(1,),
                                     define_macros = macros,
                                     python_min_version=(2,1)
                                      )
exts.append(pygsl_statistics_float)    
pygsl_statistics_long=gsl_Extension("statistics.long",
                                    ['src/statistics/longmodule.c'],
                                    gsl_min_version=(1,),
                                    define_macros = macros,
                                    python_min_version=(2,1)
                                    )
exts.append(pygsl_statistics_long)    
pygsl_statistics_int=gsl_Extension("statistics.int",
                                   ['src/statistics/intmodule.c'],
                                   gsl_min_version=(1,),
                                   define_macros = macros,
                                   python_min_version=(2,1)
                                   )
exts.append(pygsl_statistics_int)    
pygsl_statistics_short=gsl_Extension("statistics.short",
                                     ['src/statistics/shortmodule.c'],
                                     gsl_min_version=(1,),
                                     define_macros = macros,
                                     python_min_version=(2,1)
                                     )
exts.append(pygsl_statistics_short)    

errortest = gsl_Extension("errortest",
                          ['src/errortestmodule.c'],
                          gsl_min_version=(1,),
                          define_macros = macros,
                          python_min_version=(2,0)
                          )
exts.append(errortest)

if BUILD_DEPRECATED:
    pygsl_matrix=gsl_Extension("matrix",
                               ['src/matrixmodule.c'],
                               define_macros = macros,
                               gsl_min_version=(1,0),
                               python_min_version=(2,2)
                               )
    exts.append(pygsl_matrix)    

if BUILD_TESTING:
    solver=gsl_Extension("testing.multimin",
                         ['testing/src/solvers/multimin.c'],
                         gsl_min_version=(1,),
                         define_macros = macros, 
                         python_min_version=(2,0)
                         )
    extsOnly2.append(solver)

    solver=gsl_Extension("testing.multiroot",
                         ['testing/src/solvers/multiroot.c'],
                         gsl_min_version=(1,),
                         define_macros = macros, 
                         python_min_version=(2,0)
                         )
    extsOnly2.append(solver)

    solver=gsl_Extension("testing.multifit_nlin",
                         ['testing/src/solvers/multifit_nlin.c'],
                         gsl_min_version=(1,),
                         define_macros = macros, 
                         python_min_version=(2,0)
                         )
    #extsOnly2.append(solver)

    solver=gsl_Extension("testing.minimize",
                         ['testing/src/solvers/minimize.c'],
                         gsl_min_version=(1,),
                         define_macros = macros, 
                         python_min_version=(2,0)
                         )
    extsOnly2.append(solver)

    solver=gsl_Extension("testing.roots",
                         ['testing/src/solvers/roots.c'],
                         gsl_min_version=(1,),
                         define_macros = macros, 
                         python_min_version=(2,0)
                         )
    extsOnly2.append(solver)

    solver=gsl_Extension("testing.odeiv",
                         ['testing/src/solvers/odeiv.c'],
                         gsl_min_version=(1,),
                         define_macros = macros, 
                         python_min_version=(2,0)
                         )
    extsOnly2.append(solver)

    #solver=gsl_Extension("testing.monte",
    #                     ['testing/src/solvers/monte.c'],
    #                     gsl_min_version=(1,),
    #                     define_macros = macros, 
    #                     python_min_version=(2,0)
    #                     )
    #exts.append(solver)

    solver=gsl_Extension("testing.solver",
                         ['testing/src/solvers/solvermodule.c'],
                         gsl_min_version=(1,),
                         define_macros = macros + [("ONEFILE", 1)],
                         python_min_version=(2,0)
                     )
    exts.append(solver)
    #cheb=gsl_Extension("testing.chebyshev",
    #                     ['testing/src/solvers/chebyshev.c'],
    #                     gsl_min_version=(1,),
    #                     define_macros = macros + [("ONEFILE", 1)],
    #                     python_min_version=(2,0)
    #                 )
    #exts.append(cheb)

    sys.stdout.write("Building testing ufuncs!\n")
    sfarray=gsl_Extension("testing.sfarray",
                          ['testing/src/sf/sf__arrays.c'],
                          gsl_min_version=(1,),
                          define_macros = macros,
                          python_min_version=(2,0)
                          )
    #exts.append(sfarray)        
    sf=gsl_Extension("testing._ufuncs",
                     ['testing/src/sf/sfmodule_testing.c'],
                     gsl_min_version=(1,),
                     define_macros = macros,
                     python_min_version=(2,0)
                     )
    exts.append(sf)
    #sftest=gsl_Extension("testing.sftest",
    #                 ['testing/src/sf/sf_test.c'],
    #                 gsl_min_version=(1,),
    #                 define_macros = macros,
    #                 python_min_version=(2,0)
    #                 )
    #exts.append(sftest)

        
    
