# Some systems do not provide gsl-config. So here the locations can be entered
# by hand.

# The path to the dir
prefix = "/usr"

cflags = "-I/usr/include"

libs   = "-L/usr/lib -lgsl -lgslcblas -lm"

# Enter the correct versions by hand..
version = "1.3"

