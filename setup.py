#!/usr/bin/env python

from distutils.core import setup, Extension
from distutils.errors import DistutilsExecError
import os
import re
import string

def get_gsl_info(arguments):
        """
        executes gsl-config with given arguments
        """
        gsl_command=os.popen('gsl-config '+arguments)
	gsl_output=gsl_command.readline()
        gsl_command.close()
        if not gsl_output:
            raise DistutilsExecError,"could not start gsl-config"
        return  gsl_output

get_gsl_prefix=lambda:get_gsl_info('--prefix')[:-1]
get_gsl_cflags=lambda:get_gsl_info('--cflags')[:-1]
get_gsl_libs=lambda:get_gsl_info('--libs')[:-1]

#split optionlist and strip blanks from each option
strip_this=lambda a:a.strip()
gsl_lib_list=map(strip_this,get_gsl_libs().split())
#filter options with -l
not_lib_opt=lambda a:a[:2]=="-l"
gsl_lib_list=filter(not_lib_opt,gsl_lib_list)
#cut -l
only_lib_name=lambda a:a[2:]
gsl_lib_list=map(only_lib_name,gsl_lib_list)

get_gsl_version=lambda:re.split('\.',get_gsl_info('--version')[:-1])

version=get_gsl_version()
if version[0]<'1':
	raise DistutilsExecError,"min version 1.0 required"

gsl_prefix=get_gsl_prefix()

pygsl_sf=Extension("sf",
                 ['src/sfmodule.c'],
                 include_dirs=[gsl_prefix+'/include'],
                 libraries = gsl_lib_list,
                 library_dirs = [gsl_prefix+'/lib'] )

pygsl_ieee=Extension("ieee",
  		   ['src/ieeemodule.c'],
  		   include_dirs=[gsl_prefix+'/include'],
  		   libraries = gsl_lib_list,
  		   library_dirs = [gsl_prefix+'/lib'] )

pygsl__rng=Extension("_rng",
		   ['src/_rngmodule.c'],
		   include_dirs=[gsl_prefix+'/include'],
		   libraries = gsl_lib_list,
		   library_dirs = [gsl_prefix+'/lib'] )

pygsl_const=Extension("const",
   		    ['src/constmodule.c'],
   		    include_dirs=[gsl_prefix+'/include'] )

pygsl_init=Extension("init",
		   ['src/initmodule.c'],
		   include_dirs=[gsl_prefix+'/include'],
		   libraries = gsl_lib_list,
		   library_dirs = [gsl_prefix+'/lib'] )

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
