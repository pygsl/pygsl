#! /usr/bin/env python2
import string
import time
import sys
import distutils
from distutils.core import setup, Extension
from gsl_Extension import gsl_Extension
from distutils import sysconfig
from common_objects import libpygsl

exts = []
#rng=gsl_Extension("rng",
#                  ['testing/src/rngmodule_testing.c'],
#                  gsl_min_version=(1,),
#                  python_min_version=(2,0)
#                  )
#exts.append(rng)
#sf=gsl_Extension("sf",
#                 ['testing/src/sfmodule_testing.c'],
#                 gsl_min_version=(1,),
#                 python_min_version=(2,0)
#                 )
odeiv = gsl_Extension("odeiv",
                      ['testing/src/solvers/odeiv.c'],
                      gsl_min_version=(1,),
                      python_min_version=(2,0),
                      #define_macros = [('DEBUG', 10)]
                      
                      )
exts.append(odeiv)    
min = gsl_Extension("min",
                      ['testing/src/multiminmodule.c'],
                      gsl_min_version=(1,),
                      python_min_version=(2,0),
                      #define_macros = [('DEBUG', 10)]                      
                      )
exts.append(min)    
date = string.join(map(str, time.gmtime()[:3]), '-'),
setup (name = "pygsl-testing",
       version = "snapshot-%s" % date,
       description = "GNU Scientific Library Interface. Modules for testing",
       author = "Pierre Schnizer",
       author_email = "schnizer@users.sourceforge.net",
       url = "http://pygsl.sourceforge.net",
       ext_package = 'pygsl.testing',
       ext_modules = exts,
       py_modules = ['pygsl.testing.__init__'],
       libraries  = [libpygsl, ]
       )

