

PYTHONVER = 2.2
PYTHON = python$(PYTHONVER)
GSLCONFIG = gsl-config

GSL_INLUDES = `$(GSLCONFIG) --cflags`

SWIG = swig
SWIGMODULES = callback \
              poly \
              block\
	      gslwrap


SWIG_INCLUDES = -Itypemaps $(GSL_INLUDES)
SWIGOPTS = -python -keyword -shadow

SRC_DIR = src
PY_DIR = pygsl
TEST_DIR = test
BUILD_DIR = swig_src

WRAPPER = $(foreach i, $(SWIGMODULES), $(BUILD_DIR)/$(i)_wrap.c)
WRAPPER_PY = $(foreach i, $(SWIGMODULES), $(PY_DIR)/_$(i).py)
BUILD_DIRS = $(SWIGMODULES:%=$(BUILD_DIR)/%)
SWIG_INCLUDES += $(SWIGMODULES:%=-I$(SRC_DIR)/%)

DIRS = $(BUILD_DIR)

all: Makefile $(DIRS) $(WRAPPER)
	$(PYTHON) setup.py build

$(DIRS):
	mkdir -p $@

$(BUILD_DIR)/%_wrap.c %/gsl_%.i:
	$(SWIG) $(SWIG_INCLUDES) -I$(SRC_DIR) $(SWIGOPTS) -o $@ $(SRC_DIR)/$*/gsl_$*.i
	cp $(BUILD_DIR)/*$*.py $(PY_DIR)

clean:
	$(PYTHON) setup.py clean
	rm -rf $(BUILD_DIR)
	rm -f $(BUILD_DIR)/_*py
	rm -f $(WRAPPER_PY)
