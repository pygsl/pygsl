#! /usr/bin/env python2
#
# author: Achim Gaedke
# created: May 2001
# file: pygsl/setup.py
# $Id$
#
# setup script for building and installing pygsl

import sys
import distutils
from distutils.core import setup, Extension
from gsl_Extension import gsl_Extension


exts = []
exts.append(gsl_Extension("__callback",
                          ["swig_src/callback_wrap.c"],
                          include_dirs=["src/callback", "."],
                          gsl_min_version=(1,2),
                          #define_macros=[('DEBUG' ,'2')],
                          python_min_version=(2,1)
                          )
            )

exts.append(gsl_Extension("__poly",
                          ["swig_src/poly_wrap.c"],
                          include_dirs=["src/poly", "."],
                          gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
            )

exts.append(gsl_Extension("__block",
                          ["swig_src/block_wrap.c"],
                          include_dirs=["src/block", "."],
                          #define_macros=[('DEBUG' ,'0')],
                          gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
            )


pygsl_const=gsl_Extension("const",
			  ['src/constmodule.c'],
                          gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
exts.append(pygsl_const)
pygsl_diff = gsl_Extension("diff",
                           ['src/diffmodule.c'],
                           gsl_min_version=(1,'0+'),
                           python_min_version=(2,1)
                           )
exts.append(pygsl_diff)
try:
    pygsl_histogram=gsl_Extension("histogram",
                                  ['src/histogrammodule.c'],
                                  gsl_min_version=(1,'0+'),
                                  python_min_version=(2,2)
                                  )
    exts.append(pygsl_histogram)    
    pygsl_matrix=gsl_Extension("matrix",
                                  ['src/matrixmodule.c'],
                                  gsl_min_version=(1,'0+'),
                                  python_min_version=(2,2)
                                  )
    exts.append(pygsl_matrix)    
    pygsl_multimin=gsl_Extension("multimin",
                                  ['src/multiminmodule.c'],
                                  gsl_min_version=(1,'0+'),
                                  python_min_version=(2,2)
                                  )
    exts.append(pygsl_multimin)    
    pygsl_rng=gsl_Extension("rng",
			 ['src/rngmodule.c'],
                         gsl_min_version=(1,'0+'),
                         python_min_version=(2,2)
                         )
    exts.append(pygsl_rng)
    pygsl_ieee=gsl_Extension("ieee",
			 ['src/ieeemodule.c'],
                         gsl_min_version=(1,),
                         python_min_version=(2,2)
                         )
    exts.append(pygsl_ieee)    
    exts.append(gsl_Extension("_gslwrap",
                              ["swig_src/gslwrap_wrap.c"],
                              include_dirs=["src/gslwrap", "."],
                              gsl_min_version=(1,2),
                              python_min_version=(2,2)
                              )
                )

except distutils.errors.DistutilsExecError:
    pass

pygsl_init=gsl_Extension("init",
			 ['src/initmodule.c'],
                         gsl_min_version=(1,),
                         python_min_version=(2,1)
                         )
exts.append(pygsl_init)    
pygsl_sf=gsl_Extension("sf",
		       ['src/sfmodule.c'],
		       gsl_min_version=(1,),
                       python_min_version=(2,1)
                       )
exts.append(pygsl_sf)    
pygsl_statistics_uchar=gsl_Extension("statistics.uchar",
                                     ['src/statistics/ucharmodule.c'],
                                     gsl_min_version=(1,),
                                     python_min_version=(2,1)
                                     )
exts.append(pygsl_statistics_uchar)    
pygsl_statistics_char=gsl_Extension("statistics.char",
                                    ['src/statistics/charmodule.c'],
                                    gsl_min_version=(1,),
                                    python_min_version=(2,1)
                                    )
exts.append(pygsl_statistics_char)    
pygsl_statistics_double=gsl_Extension("statistics.double",
                                      ['src/statistics/doublemodule.c'],
                                      gsl_min_version=(1,),
                                      python_min_version=(2,1)
                                      )
exts.append(pygsl_statistics_double)    
pygsl_statistics_float=gsl_Extension("statistics.float",
                                     ['src/statistics/floatmodule.c'],
                                     gsl_min_version=(1,),
                                     python_min_version=(2,1)
                                      )
exts.append(pygsl_statistics_float)    
pygsl_statistics_long=gsl_Extension("statistics.long",
                                    ['src/statistics/longmodule.c'],
                                    gsl_min_version=(1,),
                                    python_min_version=(2,1)
                                    )
exts.append(pygsl_statistics_long)    
pygsl_statistics_int=gsl_Extension("statistics.int",
                                   ['src/statistics/intmodule.c'],
                                   gsl_min_version=(1,),
                                   python_min_version=(2,1)
                                   )
exts.append(pygsl_statistics_int)    
pygsl_statistics_short=gsl_Extension("statistics.short",
                                     ['src/statistics/shortmodule.c'],
                                     gsl_min_version=(1,),
                                     python_min_version=(2,1)
                                     )
exts.append(pygsl_statistics_short)    

setup (name = "pygsl",
       version = "0.1b",
       description = "GNU Scientific Library Interface",
       author = "Achim Gaedke",
       author_email = "AchimGaedke@users.sourceforge.net",
       url = "http://pygsl.sourceforge.net",
       py_modules = ['pygsl.errors',
                     'pygsl.statistics.__init__',
                     'pygsl._block',
                     'pygsl._callback',
                     'pygsl._generic_solver',
                     'pygsl._poly',
                     'pygsl.blas',
                     'pygsl.block',
                     'pygsl.chebyshev',
                     'pygsl.eigen',
                     'pygsl.gsl_function',
                     'pygsl.gslwrap',
                     'pygsl.integrate',
                     'pygsl.linalg',
                     'pygsl.matrix_pierre',
                     'pygsl.interpolation',
                     'pygsl.spline',
                     'pygsl.minimize',
                     'pygsl.fit',
                     'pygsl.multifit',
                     'pygsl.multifit_nlin',
                     'pygsl.multiroots',
                     'pygsl.odeiv',
                     'pygsl.permutation',
                     'pygsl.poly',
                     'pygsl.roots',
                     'pygsl.vector',
                     ],
       ext_package = 'pygsl',
       ext_modules = exts
       )



