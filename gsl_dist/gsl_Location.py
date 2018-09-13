# file: pygsl/gsl_dist/gsl_extension.py
# $Id$
"""

Todo:
    Integrate into config process
"""
import os
import re
from sys import argv,version_info
from distutils.errors import DistutilsModuleError, DistutilsExecError

## steal --gsl-prefix from option list
#import re
#gsl_prefix_option=None
#gsl_prefix_option_pattern=re.compile("--gsl-prefix=(.+)")
#pos=0
#while pos<len(argv):
#	gsl_prefix_match=gsl_prefix_option_pattern.match(argv[pos])
#	if gsl_prefix_match:
#		gsl_prefix_option=gsl_prefix_match.group(1)
#		gsl_prefix_option.strip()
#		argv[pos:pos+1]=[]
#		break
#	pos+=1

# Extension class adapted for gsl
class _gsl_Location(object):
	"""
	Wrapper for the location of the gsl library.

	On unix one can run gsl-config to find the locations. On other systems
	one has to revert to other ways to find the configuration.
	"""
	def __init__(self, gsl_prefix_option = None):
		"""
		Warning:
		   Currently gsl_prefix_option is only used on os.name == "posix"
		"""
		self.prefix = None
		self.cflags = None
		self.libs   = None
		self.version = None
		self.swig = None
		self.gsl_prefix_option = gsl_prefix_option

	def get_gsl_prefix(self):
		assert(self.prefix != None)
		return self.prefix

	def get_gsl_cflags(self):
		assert(self.cflags != None)
		return self.cflags

	def get_gsl_libs(self):
		#print self.libs
		assert(self.libs != None)
		return self.libs


	def get_gsl_version(self):
		assert(self.version != None)
		return self.version

	def get_gsl_config_version(self):
		"Which version string gsl-config --version returned "
		assert(self.config_version != None)
		return self.config_version

	def _split_version(self, version):
		if version[-1] == '+':
			version = version[:-1]
		return re.split('\.',version)

	def get_swig(self):
		assert(self.swig)
		return self.swig

	# Originaly in GSL extension:
	# Now used by gsl_Config and gsl_Extension so given here to be available to both
	def get_gsl_include_dirs(self):
	    prefix = self.get_gsl_prefix()
	    t_prefix_include_dir = os.path.join(prefix, "include")
	    include_dirs =[t_prefix_include_dir]
	    return include_dirs

	def get_gsl_library_dirs(self):
	    prefix = self.get_gsl_prefix()
	    t_prefix_lib_dir = os.path.join(prefix, "lib")
	    library_dirs =[t_prefix_lib_dir]
	    return library_dirs

	def get_gsl_lib_list(self):            
	    # prepare lib list
	    # split optionlist and strip blanks from each option
	    gsl_lib_list=map(lambda x: x.strip(),self.get_gsl_libs().split())

	    # filter options with -l
	    not_lib_opt=lambda a:a[:2]=="-l"
	    gsl_lib_list=filter(not_lib_opt,gsl_lib_list)
	    # cut -l
	    only_lib_name=lambda a:a[2:]
	    gsl_lib_list=map(only_lib_name,gsl_lib_list); return gsl_lib_list

      

class _gsl_Location_gsl_config(_gsl_Location):
	"""
	Call gsl_config to find the location of gsl
	"""
	def __init__(self, *args, **kws):
		_gsl_Location.__init__(self, *args, **kws)
		gsl_prefix = None
		if gsl_prefix is not None:
			self.gsl_config_tool=os.path.join(gsl_prefix,"bin","gsl-config")
		elif self.gsl_prefix_option is not None:
			self.gsl_config_tool=os.path.join(self.gsl_prefix_option,"bin","gsl-config")
		else:
			self.gsl_config_tool="gsl-config"
			
		self.prefix         = self.get_gsl_info('--prefix').strip()
		self.cflags         = self.get_gsl_info('--cflags').strip()
		self.libs           = self.get_gsl_info('--libs').strip()
		self.config_version = self.get_gsl_info('--version')
		self.version        = self._split_version(self.config_version.strip())[:2]
		self.version        = [int(v) for v in self.version]
		
		# I am running on swig. I suppose that swig is in the path
		self.swig = "swig"
		try:
			self.swig = os.environ["SWIG"]
		except KeyError:
			pass

		
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


	def dump_info(self):
            fmt = """version = "%s"
prefix  = "%s"
cflags  = "%s"
libs    = "%s"
swig    = "%s"
"""
            
            version = ".".join(map(str, self.version))
            tup = version, self.prefix, self.cflags, self.libs, self.swig
            txt = fmt % tup
            return txt

class gsl_Location_File(_gsl_Location):
    """GSL Location is defined during the config process.
    
   
    """

    def __init__(self, gsl_config_file = None, **kws):
        if gsl_config_file is None:
            gsl_config_file = "gsl_version"

        gsl_site = __import__(gsl_config_file)

        self.prefix  = gsl_site.prefix 
        self.cflags  = gsl_site.cflags 
        self.libs    = gsl_site.libs   
        self.swig    = gsl_site.swig
        self.config_version = gsl_site.version
        self.version = self._split_version(gsl_site.version)
            
   
class _gsl_Location_site_file(gsl_Location_File):
    def __init__(self, **kws):
        try:
           gsl_Location_file.__init__(self, gsl_config_file = "gsl_site", **kws)
        except ImportError as des:
            msg = "I do not know how to run gsl-config \n"+\
                "on this system. Therefore you must provide me with the information\n" +\
                "where to find the GSL library. I could not import `gsl_site'.\n" +\
                "Reason: %s. Copy gsl_site_example.py to gsl_site.py.\n"+\
                "Edit the variables in that file to reflect your installation."
            raise DistutilsExecError(msg % des)

gsl_Location = gsl_Location_File

if os.name == 'posix':
	gsl_Location_for_config = _gsl_Location_gsl_config
else:
	gsl_Location_for_config = _gsl_Location_site_file
