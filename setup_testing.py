#! /usr/bin/env python2
import sys
import distutils
from distutils.core import setup, Extension
from gsl_Extension import gsl_Extension
from distutils import sysconfig
from common_objects import libpygsl

exts = []
rng=gsl_Extension("rng",
                  ['testing/src/rngmodule_testing.c'],
                  gsl_min_version=(1,),
                  python_min_version=(2,0)
                  )
exts.append(rng)    
sf=gsl_Extension("sf",
                 ['testing/src/sfmodule_testing.c'],
                 gsl_min_version=(1,),
                 python_min_version=(2,0)
                 )
exts.append(sf)    
setup (name = "pygsl",
       version = "0.1b-testing",
       description = "GNU Scientific Library Interface",
       author = "Pierre Schnizer",
       author_email = "schnizer@users.sourceforge.net",
       url = "http://pygsl.sourceforge.net",
       ext_package = 'pygsl.testing',
       ext_modules = exts,
       py_modules = ['pygsl.testing.__init__'],
       libraries  = [libpygsl, ]
       )
