from extract_tool import *

file_prefix="sf"
print "creating index and functions to %s*.c"%file_prefix
sf_prototypes=prototype_collector("/opt/gsl-1.0")
sf_prototypes.make_wrapper_and_index_file(file_prefix)

