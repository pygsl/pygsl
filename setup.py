#!/usr/bin/env python

from distutils.core import setup, Extension
from gsl_Extension import gsl_Extension

pygsl_sf=gsl_Extension("sf",
		       ['src/sfmodule.c'],
		       gsl_needed_version=[1])
pygsl_ieee=gsl_Extension("ieee",
			 ['src/ieeemodule.c'])
pygsl__rng=gsl_Extension("_rng",
			 ['src/_rngmodule.c'])
pygsl_const=gsl_Extension("const",
			  ['src/constmodule.c'])
pygsl_init=gsl_Extension("init",
			 ['src/initmodule.c'])

setup (name = "pygsl",
       version = "0.0.4",
       description = "GNU Scientific Library Interface",
       author = "Achim Gaedke",
       author_email = "AchimGaedke@users.sourceforge.net",
       url = "http://pygsl.sourceforge.net",
       py_modules = ['pygsl.errors','pygsl.rng'],
       ext_package = 'pygsl',
       ext_modules = [pygsl_sf, pygsl_const, pygsl_ieee, pygsl__rng, pygsl_init],
       )
