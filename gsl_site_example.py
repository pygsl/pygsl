# Some systems do not provide gsl-config. So here the locations can be entered
# by hand.
import os

# The path to the dir
prefix = os.path.join("F:\\", "Programs", "GSL", "gsl-1.3")

cflags = "-g -I" + os.path.join(prefix, "include")

libs   = "-L" + os.path.join(prefix, "lib")+ " -lgsl -lgslcblas -lm"

# Enter the correct versions by hand..
version = "1.3"

