#
# author: Achim Gaedke, Pierre Schnizer
# created: May 2001
# modified: Sep 2017
# file: pygsl/gsl_dist/gsl_extension.py
# $Id:$
#
# module for gsl extensions compilation

from setuptools import Extension
from distutils.errors import DistutilsModuleError, DistutilsExecError
from distutils.dep_util import newer_group

import os
import os.path
import re
import string
import types
import imp
from sys import argv,version_info

#from gsl_Location import gsl_Location

#: Needs to be fixed 
#gsl_Location = gsl_Location()

from numpy.distutils.misc_util import get_numpy_include_dirs
array_include_dirs = get_numpy_include_dirs()


if 1 == 0:
	# Testing numpy extensions
	OldExtension = Extension
	from numpy.distutils.extension import Extension

#def check_dependencies(sources, depends):
#	"""Check if any of the dependencies is newer than the src
#
#	It assumes that the dependencies are in the same directory as the
#	src file
#
#	Returns:
#	     the deps if they are newer than the src file, None if not
#	"""
#	is_old = True
#	for src in sources:
#		t_dir = os.path.dirname(src)
#		check_deps = map(lambda x: os.path.join(t_dir, x), depends)
#		is_old = newer_group(check_deps, src)
#		print("src %s is old %s" % (src, is_old))
#		if is_old == True:
#			break
#
#	if is_old == False:
#		return None
#
#	return depends


class gsl_Extension(Extension):
	"""
	for gsl needs
	"""
	def __init__(self, name, sources,
		     include_dirs=None,
		     define_macros=None,
		     undef_macros=None,
		     library_dirs=None,
		     libraries=None,
		     runtime_library_dirs=None,
		     extra_objects=None,
		     extra_compile_args=None,
		     extra_link_args=None,
		     export_symbols=None,
		     depends=None,
		     gsl_configurable_module=None,
		     **kws
		     ):


		self._gsl_configurable_module = gsl_configurable_module

		# Move to build_ext
 	    # prepend include directory
		if include_dirs is None: include_dirs=[]
		include_dirs.append('Include')
		include_dirs.append('.')
		# now in build_ext
		# include_dirs =  gsl_Location.get_gsl_include_dirs() + include_dirs
		include_dirs = include_dirs + array_include_dirs

	    # prepend library directory
		if library_dirs is None: library_dirs=[]
		# now in build_ext
		#library_dirs = library_dirs + gsl_Location.get_gsl_library_dirs()

	    # Testing linking to non standard location if standard location is available
	    #runtime_library_dirs = gsl_Location.get_gsl_library_dirs()
		if libraries is None: libraries=[]
	    #libraries.append('pygsl')
		# now in build_ext
		#libraries.extend(gsl_Location.get_gsl_lib_list())

		if undef_macros == None:
		    undef_macros = []
		if 'NDEBUG' not in undef_macros:
		    undef_macros.append('NDEBUG')
		tmp = map(lambda x: x[0], define_macros)

	    # dependes triggers always a recompile ...
	    # try to fix it
	    # if depends is not None:
	    #	    depends = check_dependencies(sources, depends)

		Extension.__init__(self, name, sources,
			       include_dirs,
			       define_macros,
			       undef_macros,
			       library_dirs,
			       libraries,
			       runtime_library_dirs,
			       extra_objects,
			       extra_compile_args,
			       extra_link_args,
			       export_symbols,
			       depends = depends,
			       **kws
			       )

		# Set during the build process so that further extensions have
		# access to this information if required
		self._gsl_location = None

	@property
	def gsl_configurable_module(self):
		return self._gsl_configurable_module

	# Part of config process now
	# Testing for features not for version
	#def check_gsl_version(self, version_array):
	#	return self.check_version(version_array,self.get_gsl_version())
        #
	#def check_python_version(self, version_array):
	#		return self.check_version(version_array,version_info)

	## now all moved to build_Ext
	## get gsl-prefix option	
	#def get_gsl_info(self, arguments):
	#	"""
	#	executes gsl-config with given arguments
	#	"""
	#	gsl_command=os.popen(self.gsl_config_tool+' '+arguments)
	#	gsl_output=gsl_command.readline()
	#	gsl_command.close()
	#	if not gsl_output:
	#	       raise DistutilsExecError("could not start %s"%self.gsl_config_tool)
	#	return  gsl_output
	#
	#def get_gsl_prefix(self,):
	#	return gsl_Location.get_gsl_prefix()
	#
	#def get_gsl_cflags(self):
	#	return gsl_Location.get_gsl_cflags()
	#
	#def get_gsl_libs(self):
	#	return gsl_Location.get_gsl_libs()
	#
	#def get_gsl_version(self):
	#	return gsl_Location.get_gsl_version()


	def runSourceGenerator(self):
		pass
    # THat would be nice ... but I have to build the list of packages
    # So untested code ...
    # super(gsl_Extension,self)

	#def has_config(self):
	#	return self.distribution.has_config()

    #+ super(Extension, cls).sub_commands
	 #sub_commands = [("config", has_config)] + Extension.sub_commands

