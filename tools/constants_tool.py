import os
import sys
import string
from gsl_location_tool import gsl_path
from extract_tool import *

output={}

for type in constant_names:
    output[type]=file("const_"+type.lower()+"_array.c","w")
output['doc']=file("const_doc.tex","w")


header_path = os.path.join(gsl_path, "include")
gsl_constants=constant_collector(header_path)
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
