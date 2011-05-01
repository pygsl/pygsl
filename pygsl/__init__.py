# author: Achim Gaedke
# created: May 2001
# file: pygsl/__init__.py
# $Id$
"""
    Wrapper for the GNU Scientific Library.


    This module provides the following submodules:
         -- blas
         -- chebyshev
         -- combination
         -- const
         -- diff
         -- eigen
         -- fit
         -- histogram
         -- ieee
         -- integrate
         -- interpolation
         -- linalg
         -- math
         -- minimize
         -- multifit
         -- multifit_nlin
         -- multimin
         -- multiroots
         -- odeiv
         -- permutation
         -- poly
         -- qrng
         -- rng
         -- roots
         -- siman
         -- sf
         -- statistics

         
    Homepage: http://pygsl.sourceforge.net

Warning: if you want to use setup from the environement you have to call
pygsl.ieee.env_setup() and pygsl.rng.env_setup() explicitly!
"""
_init_import_errm ="""
Did you try to import pygsl in the build directory?

Well, that does not work out of the box. If you want to do that, please
use
      python setup.py build_ext -i
to add the necessary extension module in the local pygsl/ directory!

Please read the README first! Any further questions or missing information
please post to pygsl-discuss@lists.sourceforge.net!
"""
__test = 0
try:    
    import pygsl.init
    __test = 1
finally:
    if __test == 0:
        print _init_import_errm

# Central Module used by C callbacks. So a good idea to import it here to be
# sure that  it exists from the very beginning!
import pygsl.errors
# And register all the errors
pygsl.init.register_exceptions(*(pygsl.errors.get_exceptions()))
pygsl.init.register_warnings(*(pygsl.errors.get_warnings()))

from exceptions import Warning

# The gsl version which was used when this module was compiled.
compiled_gsl_version = pygsl.init.compiled_gsl_version

# The gsl version which is used  now
run_gsl_version = pygsl.init.run_gsl_version

# The compile date
compile_date = pygsl.init.compile_date

import _numobj
import errno
import _version
version= _version.version


__all__=['blas', 'chebyshev', 'combination', 'const', 'deriv', 'eigen', 'fit',
         'fft', 'histogram','ieee', 'integrate', 'interpolation','linalg',
         'math', 'minimize', 'monte', 'multifit', 'multifit_nlin', 'multimin',
         'multiroots','odeiv', 'permutation', 'poly', 'qrng', 'rng', 'roots',
         'siman', 'sf', 'spline', 'statistics']




get_typecode_numpy = lambda x: x.dtype
get_typecode_default = lambda x: x.typecode()
    
if _numobj.nummodule == "numpy":
    get_typecode = get_typecode_numpy
else:
    get_typecode = get_typecode_default



try:
    Int =  _numobj.Int
except  AttributeError:
    # For numpy 1.0
    Int = _numobj.int_

try:
    Float = _numobj.Float
except  AttributeError:
    # For numpy 1.0
    Float = _numobj.float_

try:
    Complex = _numobj.Complex
except  AttributeError:
    # For numpy 1.0
    Complex = _numobj.complex_

try:
    ArrayType = _numobj.ArrayType
except AttributeError:
    # For numpy 1.0
    ArrayType = _numobj.ndarray
    
def array_typed_copy(array, code = None):
    """
    Return a new copy for the array
    """
    if code == None:
        code = get_typecode(array)
    return array.astype(code)
    
#import pygsl._mlab
def set_debug_level(level):
    """
    Allow to set the debug level if implemented in the init function.

    Silently ignore it if it does not exist
    """
    try:
        pygsl.init.set_debug_level(level)
    except pygsl.errors.gsl_NotImplementedError:
        #print "Switchable debug information was not compiled in!"
        pass

#
add_c_traceback_frames = init.add_c_traceback_frames

def import_all():
    """
    PyGSL does not import all modules on statup. If you need it
    e.g for autocompletion call this function!
    """
    for i in __all__:
        name = "pygsl." + i
        try:
            __import__(name, globals(), locals(), [])
        except ImportError:
            print "Import of %s failed!" % (name,)

def _zeros_default(dimensions, array):
    """
    Generate zeros of the same type as the array
    """
    return _zeros(dimensions, array.typecode())

def _zeros_numpy(dimensions, array):
    """
    Generate zeros of the same type as the array
    """
    return _zeros(dimensions, array.dtype)

if pygsl._numobj.nummodule == "numpy":
    zeros = _zeros_numpy
else:
    zeros = _zeros_default
_zeros = pygsl._numobj.zeros

if compiled_gsl_version != run_gsl_version:
    txt = """This pygsl module was compiled for GSL version %s but it
is used with version %s!"""
    raise Warning,  txt % (compiled_gsl_version, run_gsl_version)
