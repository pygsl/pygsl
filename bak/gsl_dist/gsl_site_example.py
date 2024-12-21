# Some systems do not provide gsl-config. So here the locations can be entered
# by hand.
import os

# The path to the directory where gsl is installed. Currently setup.py assumes
# that the include files are located in "prefix/include". 
prefix = os.path.join("C:\\", "Programs", "GSL", "gsl-1.3")

cflags = "-g -I" + os.path.join(prefix, "include")

libs   = "-L" + os.path.join(prefix, "lib")+ " -lgsl -lgslcblas -lm"

# Enter the correct GSL versions by hand..
version = "1.3"


# swig_extension.py needs swig to generate the approbriate wrapper files. This
# variable only needs to be correct is you use USE_SWIG=1 in setup.py
swig = os.path.join("F:\\", "Programs", "Swig", "swig")
#swig = os.path.join("C:\\", "Programs", "Swig", "SWIG-1.3.19", "swig")

