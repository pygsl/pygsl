#!/usr/bin/env python

import sys
from distutils.core import setup, Extension
from gsl_Extension import gsl_Extension

pygsl_sf=gsl_Extension("sf",
		       ['src/sfmodule.c'],
		       gsl_min_version=(1,),
                       python_min_version=(2,1)
                       )
pygsl_histogram=gsl_Extension("histogram",
                              ['src/histogrammodule.c'],
                              gsl_min_version=(1,),
                              python_min_version=(2,2)
                              )
pygsl_ieee=gsl_Extension("ieee",
			 ['src/ieeemodule.c'],
                         gsl_min_version=(1,),
                         python_min_version=(2,1)
                         )
pygsl__rng=gsl_Extension("_rng",
			 ['src/_rngmodule.c'],
                         gsl_min_version=(1,),
                         python_min_version=(2,1)
                         )
pygsl_const=gsl_Extension("const",
			  ['src/constmodule.c'],
                          gsl_min_version=(1,),
                          python_min_version=(2,1)
                          )
pygsl_init=gsl_Extension("init",
			 ['src/initmodule.c'],
                         gsl_min_version=(1,),
                         python_min_version=(2,1)
                         )
pygsl_statistics=gsl_Extension("statistics",
                               ['src/statisticsmodule.c'],
                               gsl_min_version=(1,),
                               python_min_version=(2,1)
                               )

setup (name = "pygsl",
       version = "0.0.5",
       description = "GNU Scientific Library Interface",
       author = "Achim Gaedke",
       author_email = "AchimGaedke@users.sourceforge.net",
       url = "http://pygsl.sourceforge.net",
       py_modules = ['pygsl.errors','pygsl.rng'],
       ext_package = 'pygsl',
       ext_modules = [pygsl_sf, pygsl_const, pygsl_ieee, pygsl__rng,
                      pygsl_statistics, pygsl_init],
       )
