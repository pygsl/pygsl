from distutils.core import setup, Extension
from distutils.errors import DistutilsExecError
import os
import os.path
import re
import string
import types
from sys import argv

# steel --gsl_prefix from option list

gsl_prefix_option=None
gsl_prefix_option_pattern=re.compile("--gsl_prefix=(.+)")
pos=0
while pos<len(argv):
	gsl_prefix_match=gsl_prefix_option_pattern.match(argv[pos])
	if gsl_prefix_match:
		gsl_prefix_option=gsl_prefix_match.group(1)
		gsl_prefix_option.strip()
                argv[pos:pos+1]=[]
                break
        pos+=1

# Extension class adapted for gsl

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
		     gsl_needed_version=None,
		     ):

            if gsl_prefix is not None:
                self.gsl_config_tool=os.path.join(gsl_prefix,"bin","gsl-config")
            elif gsl_prefix_option is not None:
                self.gsl_config_tool=os.path.join(gsl_prefix_option,"bin","gsl-config")
            else:
                self.gsl_config_tool="gsl-config"

            # get real prefix
            self.gsl_prefix=self.get_gsl_prefix()


            # check version
            if gsl_needed_version is not None and \
               not self.check_version(gsl_needed_version):
                raise DistutilsExecError, \
                      "min version "+repr(gsl_needed_version)+" required"

            # prepend include directory
            if include_dirs is None: include_dirs=[]
            include_dirs[0:0]=[os.path.join(self.gsl_prefix,'include')]

            # prepend library directory
            if library_dirs is None: library_dirs=[]
            library_dirs[0:0] = [os.path.join(self.gsl_prefix,'lib')]

            # prepare lib list
            # split optionlist and strip blanks from each option
            gsl_lib_list=map(string.strip,self.get_gsl_libs().split())
            # filter options with -l
            not_lib_opt=lambda a:a[:2]=="-l"
            gsl_lib_list=filter(not_lib_opt,gsl_lib_list)
            # cut -l
            only_lib_name=lambda a:a[2:]
            gsl_lib_list=map(only_lib_name,gsl_lib_list)

            if libraries is None: libraries=[]
            libraries.extend(gsl_lib_list)
		
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
                               export_symbols
                               )

	def check_version(self, version_array):

		my_version=self.get_gsl_version()
		min_length=min(len(version_array),len(my_version))
		for pos in range(min_length):
			this_type=type(version_array[pos])
			if  this_type== types.StringType:
				if version_array[pos]>my_version[pos]: return 0
			elif this_type == types.IntType:
				if version_array[pos]>int(my_version[pos]): return 0
			else:
				raise DistutilsExecError,"incorrect version specification"
                # problematic: 0.9 < 0.9.0, but assures that 0.9.1 > 0.9
                if len(version_array)>len(my_version): return 0
		return 1
			
	# get gsl-prefix option
	def get_gsl_info(self, arguments):
		"""
		executes gsl-config with given arguments
		"""
		gsl_command=os.popen(self.gsl_config_tool+' '+arguments)
		gsl_output=gsl_command.readline()
		gsl_command.close()
                if not gsl_output:
			raise DistutilsExecError,"could not start %s"%self.gsl_config_tool
		return  gsl_output

	def get_gsl_prefix(self,):
		return self.get_gsl_info('--prefix').strip()
	def get_gsl_cflags(self):
		return self.get_gsl_info('--cflags').strip()
	def get_gsl_libs(self):
		return self.get_gsl_info('--libs').strip()
	def get_gsl_version(self):
		return re.split('\.',self.get_gsl_info('--version').strip())
