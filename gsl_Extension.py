from distutils.core import setup, Extension
from distutils.errors import DistutilsExecError
import os
import os.path
import re
import string
import types
from sys import argv,version_info

# steel --gsl-prefix from option list

gsl_prefix_option=None
gsl_prefix_option_pattern=re.compile("--gsl-prefix=(.+)")
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
		     gsl_min_version=None,
		     python_min_version=None
		     ):

            if gsl_prefix is not None:
                self.gsl_config_tool=os.path.join(gsl_prefix,"bin","gsl-config")
            elif gsl_prefix_option is not None:
                self.gsl_config_tool=os.path.join(gsl_prefix_option,"bin","gsl-config")
            else:
                self.gsl_config_tool="gsl-config"

            # get real prefix
            self.gsl_prefix=self.get_gsl_prefix()

            # check gsl version
            if gsl_min_version is not None and \
               not self.check_gsl_version(gsl_min_version):
		    raise DistutilsExecError, \
			  "min gsl version %s required"%repr(gsl_min_version)

            # check python version
            if python_min_version is not None and \
               not self.check_python_version(python_min_version):
		    raise DistutilsExecError, \
			  "min python version %s required"%repr(python_min_version)

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

	def check_version(self, required_version, this_version):
		min_length=min(len(required_version),len(this_version))
		for pos in range(min_length):
			this_type=type(required_version[pos])
			if  this_type== types.StringType:
				if required_version[pos]>this_version[pos]: return 0
			elif this_type == types.IntType:
				if required_version[pos]>int(this_version[pos]): return 0
			else:
				raise DistutilsExecError,"incorrect version specification"
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
