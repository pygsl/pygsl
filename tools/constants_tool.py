from extract_tool import *

output={}
for type in ["M","CGS","MKS","NUM"]:
    output[type]=file("const_"+type.lower()+"_array.c","w")

gsl_constants=constant_collector("/opt/gsl-cvs")
constant_list=gsl_constants.get_all_constants()
for c in constant_list:
    definition_string=c.make_array_entry()
    if definition_string is not None:
        if c.name[:2]=="M_":
            output["M"].write(definition_string+",\n")
        else:
            output[c.name[10:13]].write(definition_string+",\n")

for type in output.keys():
    output[type].close()
