from extract_tool import *

output=file("scientific_constants.c","w")
gsl_constants=constant_collector("/opt/gsl-cvs")
constant_list=gsl_constants.get_all_constants()
for c in constant_list:
    output.write(c.make_module_definition()+";\n")
output.close()
