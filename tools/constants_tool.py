import os
import sys
import string
from extract_tool import *

output={}

for type in constant_names:
    output[type]=file("const_"+type.lower()+"_array.c","w")
output['doc']=file("const_doc.tex","w")

gslpath = os.getenv('PYGSL_GSLCVS')
if gslpath == None:
    sys.exit("Set your environment variable PYGSL_GSLCVS to point to your GSL cvs sources.")

gsl_constants=constant_collector(gslpath)
constant_list=gsl_constants.get_all_constants()
for c in constant_list:
    definition_string=c.make_array_entry()
    if definition_string is not None:
        if c.name[:2]=="M_":
            output["M"].write(definition_string+",\n")
        else:	    
	    name = string.split(c.name, '_')[2]
	    test = 0
	    try:
		output[name].write(definition_string+",\n")
	    	test = 1
	    finally:
		if test == 0:
		    print "Name was ", c.name
        output['doc'].write("\lineiii{%s}{\constant{%s}}{%s}\n"%(c.derive_python_name(),c.name,c.comment))

for type in output.keys():
    output[type].close()
