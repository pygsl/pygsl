import os
import sys
from extract_tool import *

gslpath = os.getenv('PYGSL_GSLCVS')
if gslpath == None:
    sys.exit("Set your environment variable PYGSL_GSLCVS to point to your GSL cvs sources.")

file_prefix="sf"
print "creating index and functions to %s*.c"%file_prefix
sf_prototypes=prototype_collector(gslpath)
sf_prototypes.make_wrapper_and_index_file(file_prefix)

