#! /usr/bin/env python2
#
# author: Achim Gaedke
# created: May 2001
# file: pygsl/setup.py
# $Id$
#
# setup script for building and installing pygsl


# Use SWIG to generate the approbriate wrapper files. This is only necessary
# if you modified any interface file as the wrapper files are included in the
# distribution
USE_SWIG = 1

# Some modules have been reimplemented. These modules will be installed in
# pygsl.testing...
# Set to one if you want them built
BUILD_TESTING = 1

#------------------------------------------------------------------------------
# As long as you are not taking part in the development process, I hope that 
# you do not need to modify anything here.


import sys
import time
import string


import distutils
from distutils.core import setup, Extension
from gsl_Extension import gsl_Extension
from swig_extension import SWIG_Extension as _SWIG_Extension
from swig_extension import SWIG_Extension_Nop as _SWIG_Extension_Nop

from distutils import sysconfig
from common_objects import libpygsl


if USE_SWIG == 0:
    _SWIG_Extension = _SWIG_Extension_Nop

exts = []

def SWIG_Extension(*args, **kws):
    kws["py_dir"] = "pygsl"
    kws["c_dir"] = "swig_src"
    return apply(_SWIG_Extension, args, kws)


macros = [('SWIG_COBJECT_TYPES', 1),] #, [('NO_IMPORT_ARRAY', 1)]
exts.append(SWIG_Extension("hankel",                           
                           ["src/hankel/gsl_hankel.i"],
                           swig_include_dirs=["src/hankel"],
                           gsl_min_version=(1,0),
                           define_macros = macros,
                           python_min_version=(2,0),
                          )
            
            )
# Basic implementation here but not working yet....
#exts.append(gsl_Extension("_sum",
#                          ["swig_src/sum_wrap.c"],
#                          gsl_min_version=(1,0),
#                          define_macros = [('SWIG_COBJECT_TYPES', 1),
#                                           #('DEBUG' ,'2'),
#                                           ],
#                          python_min_version=(2,0),
#                          )
#            )

exts.append(SWIG_Extension("_callback",
                           ["src/callback/gsl_callback.i"],
                           include_dirs=["src/callback"],
                           swig_include_dirs=["src/callback"],
                           gsl_min_version=(1,2),
                           define_macros = macros,
                           python_min_version=(2,1),
                          )            
            )

exts.append(SWIG_Extension("_poly",
                          ["src/poly/gsl_poly.i"],
                          include_dirs=["src/poly"],
                          define_macros = macros,
                          gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
            )

exts.append(SWIG_Extension("_block",
                          ["src/block/gsl_block.i"],
                           swig_include_dirs=["src/block"],
                          define_macros = macros,
                          gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
            )


pygsl_const=gsl_Extension("const",
			  ['src/constmodule.c'],
                          define_macros = macros,
                          gsl_min_version=(1,2),
                          python_min_version=(2,1)
                          )
exts.append(pygsl_const)
pygsl_diff = gsl_Extension("diff",
                           ['src/diffmodule.c'],
                           define_macros = macros,
                           gsl_min_version=(1,'0+'),
                           python_min_version=(2,1)
                           )
exts.append(pygsl_diff)
try:
    pygsl_histogram=gsl_Extension("histogram",
                                  ['src/histogrammodule.c'],
                                  define_macros = macros,
                                  gsl_min_version=(1,'0+'),
                                  python_min_version=(2,2)
                                  )
    exts.append(pygsl_histogram)    
    pygsl_matrix=gsl_Extension("matrix",
                                  ['src/matrixmodule.c'],
                               define_macros = macros,
                                  gsl_min_version=(1,'0+'),
                                  python_min_version=(2,2)
                                  )
    exts.append(pygsl_matrix)    
    pygsl_multimin=gsl_Extension("multimin",
                                  ['src/multiminmodule.c'],
                                 define_macros = macros,
                                  gsl_min_version=(1,'0+'),
                                  python_min_version=(2,2)
                                  )
    exts.append(pygsl_multimin)    
    pygsl_rng=gsl_Extension("rng",
                            ['src/rngmodule.c'],
                            #define_macros = [('DEBUG', 10)],
                            gsl_min_version=(1,'0+'),
                            define_macros = macros,
                            python_min_version=(2,2)
                         )
    exts.append(pygsl_rng)
    
    
    exts.append(SWIG_Extension("gslwrap",
                              ["src/gslwrap/gsl_gslwrap.i"],
                               swig_include_dirs=["src/gslwrap/"],
                              define_macros = macros,
                              gsl_min_version=(1,2),
                              python_min_version=(2,2)
                              )
                )

    pygsl_ieee=gsl_Extension("ieee",
                             ['src/ieeemodule.c'],
                             gsl_min_version=(1,),
                             define_macros = macros,
                             python_min_version=(2,1)
                             )
    exts.append(pygsl_ieee)
    exts.append(SWIG_Extension("gslwrap",
                              ["src/gslwrap/gsl_gslwrap.i"],
                               swig_include_dirs=["src/gslwrap/"],
                              define_macros = macros,
                              gsl_min_version=(1,2),
                              python_min_version=(2,2)
                              )
                )


except distutils.errors.DistutilsExecError:
    pass


pygsl_qrng=gsl_Extension("_qrng",
                         ['src/qrng_module.c'],
                         #define_macros = [('DEBUG', 10)],
                         gsl_min_version=(1,'0+'),
                         define_macros = macros,
                         python_min_version=(2,1)
                         )
exts.append(pygsl_qrng)

pygsl_init=gsl_Extension("init",
			 ['src/initmodule.c'],
                         gsl_min_version=(1,),
                         define_macros = macros,
                         python_min_version=(2,1)
                         )
exts.append(pygsl_init)    
pygsl_sf=gsl_Extension("sf",
		       ['src/sfmodule.c'],
		       gsl_min_version=(1,),
                       define_macros = macros,
                       python_min_version=(2,1)
                       )
exts.append(pygsl_sf)    
pygsl_statistics_uchar=gsl_Extension("statistics.uchar",
                                     ['src/statistics/ucharmodule.c'],
                                     gsl_min_version=(1,),
                                     #define_macros = macros,
                                     python_min_version=(2,1)
                                     )
exts.append(pygsl_statistics_uchar)    
pygsl_statistics_char=gsl_Extension("statistics.char",
                                    ['src/statistics/charmodule.c'],
                                    gsl_min_version=(1,),
                                    #define_macros = macros,
                                    python_min_version=(2,1)
                                    )
exts.append(pygsl_statistics_char)    
pygsl_statistics_double=gsl_Extension("statistics.double",
                                      ['src/statistics/doublemodule.c'],
                                      gsl_min_version=(1,),
                                      #define_macros = macros,
                                      python_min_version=(2,1)
                                      )
exts.append(pygsl_statistics_double)    
pygsl_statistics_float=gsl_Extension("statistics.float",
                                     ['src/statistics/floatmodule.c'],
                                     gsl_min_version=(1,),
                                     #define_macros = macros,
                                     python_min_version=(2,1)
                                      )
exts.append(pygsl_statistics_float)    
pygsl_statistics_long=gsl_Extension("statistics.long",
                                    ['src/statistics/longmodule.c'],
                                    gsl_min_version=(1,),
                                    #define_macros = macros,
                                    python_min_version=(2,1)
                                    )
exts.append(pygsl_statistics_long)    
pygsl_statistics_int=gsl_Extension("statistics.int",
                                   ['src/statistics/intmodule.c'],
                                   gsl_min_version=(1,),
                                   #define_macros = macros,
                                   python_min_version=(2,1)
                                   )
exts.append(pygsl_statistics_int)    
pygsl_statistics_short=gsl_Extension("statistics.short",
                                     ['src/statistics/shortmodule.c'],
                                     gsl_min_version=(1,),
                                     #define_macros = macros,
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

if BUILD_TESTING:
    rng=gsl_Extension("testing.rng",
                      ['testing/src/rngmodule_testing.c'],
                      gsl_min_version=(1,),
                      define_macros = macros,
                      python_min_version=(2,0)
                      )
    exts.append(rng)    
    sf=gsl_Extension("testing.sf",
                     ['testing/src/sfmodule_testing.c'],
                     gsl_min_version=(1,),
                     define_macros = macros,
                     python_min_version=(2,0)
                     )
    exts.append(sf)
    

setup (name = "pygsl",
       #version = "0.2",
       version = "snapshot-" + string.join(map(str, time.gmtime()[:3]), '-'),
       description = "GNU Scientific Library Interface",
       author = "Achim Gaedke",
       author_email = "AchimGaedke@users.sourceforge.net",
       url = "http://pygsl.sourceforge.net",
       py_modules = ['pygsl.errors',
                     'pygsl.statistics.__init__',
                     'pygsl._block',
                     'pygsl._callback',
                     'pygsl.hankel',
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
                     #'pygsl.combination',
                     'pygsl.poly',
                     'pygsl.roots',
                     'pygsl.vector',
                     'pygsl.monte',
                     'pygsl.qrng',
                     'pygsl.testing.__init__'
                     ],
       ext_package = 'pygsl',
       ext_modules = exts,
       libraries  = [libpygsl, ]
                                    
       #'].append(('superlu',{'sources':superlu,
                             #              'include_dirs':head}))
       )




