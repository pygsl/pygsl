"""
Find out if Numeric of numarray is going to be used as its array package

WARNING: PyGSL has used Numeric as its core. This is to test to see
if we can support both, but sooner or later the favour has to be given
to one of these packages.

When imported this module:
     1.) Looks on the command line if it can find a flag of type
         --array-object=[Numeric|nummarray]

     2.) Tries to import these modules.

     3.) Tries to use the preferred one.

     4.) Or goes with the other one found
     
         
"""
import re
import sys
import os
from distutils.errors import DistutilsModuleError


array_pattern = re.compile("--array-object=(.+)")
pos=0
array_preference = None
while pos<len(sys.argv):
	match=array_pattern.match(sys.argv[pos])
	if match:
            array_preference=match.group(1)
            array_preference.strip()
            sys.argv[pos:pos+1]=[]
            break
        pos+=1



have_numeric = 0
have_numarray = 0
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


use_numeric = 0
use_numarray = 0

#array_preference = 'numarray'
if array_preference != None:
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

if use_numeric == 0 and use_numarray == 0:            
    if have_numeric == 1:
        use_numeric = 1
    elif have_numarray == 1:
        use_numarray = 1
    else:
        raise  DistutilsModuleError, "I need either Numeric or nummarray!"

if use_numeric == 1:
	print "Using Numeric as array Package"
	use_numarray = 0
        nummodule = "Numeric"

elif use_numarray == 1:    
	print "Using nummarray as array Package"
	print "WARNING: Only use if you want to participate in the porting!!"
	use_numeric = 0
        nummodule = "numarray"
else:
	raise  DistutilsModuleError, "I need either Numeric or nummarray!"

# Write the chosen module to a file so it is automatically inculded when pygsl starts up
file = open(os.path.join("pygsl", "_numobj.py"), "w")
warnmsg = """
       WARNING: File Generated during build. DO NOT MODIFY!!!
"""
file.write('"""\n')
file.write(warnmsg)
file.write('"""\n')
file.write('\n')
file.write('from %s import *' % nummodule)
file.close()
del file

# Write the chosen module to a include header
file = open(os.path.join("Include", "pygsl", "arrayobject.h"), "w")
file.write('/*')
file.write(warnmsg)
file.write('*/\n')
file.write('#include <%s/arrayobject.h>\n' % nummodule)
file.close()
del file

# Write the chosen module to a include header
file = open(os.path.join("pygsl", "_mlab.py"), "w")
file.write('"""\n')
file.write(warnmsg)
file.write('"""\n')
if use_numeric == 1:
	file.write('from MLab import *\n')
elif use_numarray == 1:
	file.write('from numarray.linear_algebra.mlab import *\n')
file.close()
del file
