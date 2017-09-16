#
# author: Achim Gaedke, Pierre Schnizer
# created: May 2001
# modified: Sep 2017
# file: pygsl/gsl_dist/gsl_extension.py
# $Id$
#
# module for gsl extensions compilation

from setuptools import setup, Extension
from distutils.errors import DistutilsModuleError, DistutilsExecError
from distutils.dep_util import newer_group

import os
import os.path
import re
import string
import types
import imp
from sys import argv,version_info

from gsl_Location import gsl_Location

try:
        from array_includes import array_include_dirs        
except ImportError:
        from pygsl.gsl_dist.array_includes import array_include_dirs


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
		     gsl_prefix=None,
		     gsl_min_version=None,
		     python_min_version=None,
		     depends=None,
		     **kws
		     ):

		
	    # get real prefix
	    self.gsl_prefix=self.get_gsl_prefix()

	    gsl_major_version, gsl_minor_version = self.get_gsl_version()
	    # check gsl version
	    if gsl_min_version is not None and \
	       not self.check_gsl_version(gsl_min_version):
		    raise DistutilsExecError("min gsl version %s required"%repr(gsl_min_version))

	    # check python version
	    if python_min_version is not None and \
	       not self.check_python_version(python_min_version):
		    raise DistutilsExecError("min python version %s required"%repr(python_min_version))

	    # prepend include directory
	    if include_dirs is None: include_dirs=[]
	    include_dirs.append('Include')
	    include_dirs.append('.')
	    include_dirs =  gsl_Location.get_gsl_include_dirs() + include_dirs
	    include_dirs = include_dirs + array_include_dirs

	    # prepend library directory
	    if library_dirs is None: library_dirs=[]
	    library_dirs = library_dirs + gsl_Location.get_gsl_library_dirs()

	    # Testing linking to non standard location if standard location is available
	    #runtime_library_dirs = gsl_Location.get_gsl_library_dirs()
	    if libraries is None: libraries=[]
	    #libraries.append('pygsl')
	    libraries.extend(gsl_Location.get_gsl_lib_list())

	    # test if Numeric module is available
	    if define_macros is None:
		    define_macros=[]
	    try:
		    imp.find_module("Numeric")
		    define_macros = define_macros + [("NUMERIC",1),]
	    except ImportError:	    
		    define_macros = define_macros + [("NUMERIC",0), ]

	    if undef_macros == None:
		    undef_macros = []
	    if 'NDEBUG' not in undef_macros:
		    undef_macros.append('NDEBUG')
	    tmp = map(lambda x: x[0], define_macros)

	    # Now config will test of GSL_MAJOR_VERSION and GSL_MINOR_VERSION is defined 
	    #if "PYGSL_GSL_MAJOR_VERSION" not in tmp:
	    #        define_macros = define_macros + [("PYGSL_GSL_MAJOR_VERSION", gsl_major_version),]


	    #if "PYGSL_GSL_MINOR_VERSION" not in tmp:
	    #        #define_macros.append(("PYGSL_GSL_MINOR_VERSION", gsl_minor_version))
	    #        define_macros = define_macros + [("PYGSL_GSL_MINOR_VERSION", gsl_minor_version),]

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

	def check_version(self, required_version, this_version):
		this_version = tuple(this_version)
		#print("req '%s' this '%s'" %(required_version, this_version))
		min_length=min(len(required_version),len(this_version))
		for pos in range(min_length):
			t_val = this_version[pos]
			test_val = required_version[pos]
			#print("\t %d: req '%s' this '%s'" %( pos, test_val, t_val))

			this_type=type(t_val)
			if  this_type== type(" "):
				t_val = int(t_val)

			if  type(test_val)== type(" "):
				test_val = int(test_val)

			if t_val > test_val:
				# already larger
				return 1
			elif t_val == test_val:
				continue
			elif t_val < test_val:
				return 0
			else:
				raise DistutilsExecError("incorrect version specification")
		# problematic: 0.9 < 0.9.0, but assures that 0.9.1 > 0.9
		if len(required_version)>len(this_version): return 0
		return 1



	def check_gsl_version(self, version_array):
		return self.check_version(version_array,self.get_gsl_version())

	def check_python_version(self, version_array):
		return self.check_version(version_array,version_info)

	# get gsl-prefix option
	def get_gsl_info(self, arguments):
		"""
		executes gsl-config with given arguments
		"""
		gsl_command=os.popen(self.gsl_config_tool+' '+arguments)
		gsl_output=gsl_command.readline()
		gsl_command.close()
		if not gsl_output:
		       raise DistutilsExecError("could not start %s"%self.gsl_config_tool)
		return  gsl_output

	def get_gsl_prefix(self,):
		return gsl_Location.get_gsl_prefix()

	def get_gsl_cflags(self):
		return gsl_Location.get_gsl_cflags()

	def get_gsl_libs(self):
		return gsl_Location.get_gsl_libs()

	def get_gsl_version(self):
		return gsl_Location.get_gsl_version()

