"""
Find out if Numeric of numarray is going to be used as its array package

WARNING: PyGSL has used Numeric as its core. This is to test to see
if we can support both, but sooner or later the favour has to be given
to one of these packages.

When imported this module:
     1.) Looks on the command line if it can find a flag of type
         --array-object=[Numeric|nummarray|numpy]

     2.) Tries to import these modules.

     3.) Tries to use the preferred one.

     4.) Or goes with the other one found
     
         
"""
import re
import string
import sys
import os
from distutils.errors import DistutilsModuleError


packagedir = os.path.dirname(os.path.abspath(__file__))
includedir = os.path.join(packagedir, "Include", "pygsl")
pygsldir   = os.path.join(packagedir, "pygsl")
gsl_dist   = os.path.join(packagedir, "gsl_dist")

def extractpattern():
	"""
	Try to find if the array object was specified at the command line
	"""
	array_pattern = re.compile("--array-object=(.+)")
	pos=0
	array_preference = None

	result = ""
	while pos<len(sys.argv):
		match=array_pattern.match(sys.argv[pos])
		if match:
		    result=match.group(1)
		    result.strip()
		    sys.argv[pos:pos+1]=[]
		    break
		pos+=1
	return result	

def switchpreference(array_preference):
	"""
	Find out if the set preference can be used ...
	"""
	have_numeric = 0
	have_numarray = 0
	have_numpy = 0
	use_numeric = 0
	use_numarray = 0
	use_numpy = 0
	try:
		import numpy
		have_numpy = 1
	except ImportError:
		pass
	
	try:
		import Numeric
		have_numeric = 1
	except ImportError:
		pass

	try:
		import numarray
		have_numarray = 1
	except ImportError:
		pass

	#array_preference = 'numarray'
	if array_preference != None:
	    if array_preference == 'numpy':
		if have_numpy == 1:
		    use_numpy = 1
	        else:
		    print "Did not find the numpy module you asked for"            

	    if array_preference == 'Numeric':
		if have_numeric == 1:
		    use_numeric = 1
		else:
		    print "Did not find the Numeric module you asked for"            
	    else:
		if array_preference == 'numarray':
		    if have_numarray == 1:
			use_numarray = 1
		    else:
			print "Did not find the numarray module you asked for"

	if use_numeric == 0 and use_numarray == 0 and use_numpy == 0:            
	    if have_numpy == 1:
		use_numpy = 1
	    elif have_numarray == 1:
		use_numarray = 1
	    elif have_numeric == 1:
		use_numeric = 1
	    else:
		raise  DistutilsModuleError, "I need either numpy, nummarray, or Numeric!"
	
	if use_numpy == 1:
		use_numeric = 0
		use_numarray = 0
		nummodule = "numpy"
		
	elif use_numeric == 1:
		#print "Using Numeric as array Package"
		use_numpy = 0
		use_numarray = 0
		nummodule = "Numeric"

	elif use_numarray == 1:    
		#print "Using nummarray as array Package"
		use_numeric = 0
		use_numpy = 0
		nummodule = "numarray"
	else:
		raise  DistutilsModuleError, "I need either numpy, nummarray or Numeric!"
	return nummodule

def writenumobj(nummodule):
	# Write the chosen module to a file so it is automatically inculded when pygsl starts up
	file = open(os.path.join(pygsldir, "_numobj.py"), "w")
	warnmsg = """
	       WARNING: File Generated during build. DO NOT MODIFY!!!
	"""
	file.write('"""\n')
	file.write(warnmsg)
	file.write('"""\n')
	file.write('\n')
	file.write('from %s import *\n\n' % nummodule)
	file.write('nummodule = "%s"\n' % nummodule)
	file.close()
	del file

        file = open(os.path.join(gsl_dist, "array_includes.py"), "w")
	file.write('"""\n')
	file.write(warnmsg)
	file.write('"""\n')
	file.write('\n')
	file.write('array_include_dirs = []\n')
	if nummodule == "numpy":
	    file.write('from numpy.distutils.misc_util import get_numpy_include_dirs\n')
            file.write('array_include_dirs = get_numpy_include_dirs()\n')
	file.close()
	del file

	# Write the chosen module to a include header
	file = open(os.path.join(includedir, "arrayobject.h"), "w")
	file.write('/*')
	file.write(warnmsg)
	file.write('*/\n')
	#file.write('#include <%s/arrayobject.h>\n' % nummodule)
	file.write('#define PyGSL_%s 1\n' % string.upper(nummodule))
	file.close()
	del file

	# Write the chosen module to a include header
	file = open(os.path.join(pygsldir, "_mlab.py"), "w")
	file.write('"""\n')
	file.write(warnmsg)
	file.write('"""\n')
	if  nummodule == "numpy":
		file.write('from numpy.oldnumeric.mlab import *\n')
	elif nummodule == "Numeric":
		file.write('from MLab import *\n')
	elif nummodule == "numarray":
		file.write('from numarray.linear_algebra.mlab import *\n')
	else:
		raise ValueError, ("Unknown array object %s" % nummodule)
	file.close()
	del file


def read_numobj():
	"""
	read the nummodule from the file
	"""
	path = os.path.join(pygsldir, "_numobj.py")
	g = {}
	l = {}
	module = None
	try:
		execfile(path, g, l)
		module = l["nummodule"]
		return module
	except IOError:
		print "No array object was selected."
		return None
	except ImportError:
		pass

	# Try to find the name of the set module
	line = open(path).readlines()[-1]
	lastobject =  string.strip(string.split(line, "=")[1])
	print "Array object %s found in pygsl._numobj can not be imported!" % (lastobject,)
	return None

def build_guess(selectedmodule):
	"""
	Find out which array module to use ...
	"""
	# See if --array-object was given on the command line

	lastmodule = read_numobj()
	# If not return the last selection if possible ....
	if selectedmodule == "" and lastmodule != None:
		return lastmodule

	print "Looking for a suitable array module"
	# If given, find out if it can be used ...	
	nummodule = switchpreference(selectedmodule)
	
	# find out if it is a change ...
	if lastmodule == None or lastmodule != nummodule:
		if lastmodule != nummodule:
			print "SELECTED a NEW array module ->", nummodule
			print "Please make sure that all modules are built with the same setting."
			print "e.g. remove the build directory and start the build process again!"
		else:
			print "SELECTED as array module ->", nummodule
		writenumobj(nummodule)
	return nummodule

def read_from_numobj(default):
	"""
	tries to read from the file. If this fails it searches if one of the
	array objects can be found
	"""
	tmp = read_numobj()
	if tmp != None:
		return tmp
	return build_guess(default)


class _nummodule:
	"""
	Delay finding the array object until really needed
	"""
	def __init__(self):
		self.__arrayobject = None
		self.__preference = extractpattern()
		pass

	def __findarrayobject(self):
		if "build" in sys.argv:
			nummodule = build_guess(self.__preference)
		else:
			nummodule = read_from_numobj(self.__preference)	
		self.__arrayobject = nummodule

	def __str__(self):
		if self.__arrayobject == None:
			self.__findarrayobject()
		#print "Using '%s' as array object" %  self.__arrayobject		
		return self.__arrayobject

		
nummodule = _nummodule()
print nummodule
