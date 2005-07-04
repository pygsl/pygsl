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


from exceptions import Warning

# The gsl version which was used when this module was compiled.
compiled_gsl_version = pygsl.init.compiled_gsl_version

# The gsl version which is used  now
run_gsl_version = pygsl.init.run_gsl_version

# The compile date
compile_date = pygsl.init.compile_date

version="0.3.2"
__all__=['blas', 'chebyshev', 'combination', 'const', 'diff', 'eigen', 'fit',
         'fft', 'histogram','ieee', 'integrate', 'interpolation','linalg',
         'math', 'minimize', 'monte', 'multifit', 'multifit_nlin', 'multimin',
         'multiroots','odeiv', 'permutation', 'poly', 'qrng', 'rng', 'roots',
         'siman', 'sf', 'spline', 'statistics']



import pygsl._numobj
import pygsl._mlab
def set_debug_level(level):
    """
    Allow to set the debug level if implemented in the init function.

    Silently ignore it if it does not exist
    """
    try:
        pygsl.init.set_debug_level(level)
    except pygsl.errors.gsl_NotImplementedError:
        print "Switchable debug information was not compiled in!"
    
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

if compiled_gsl_version != run_gsl_version:
    txt = """This pygsl module was compiled for GSL version %s but it
is used with version %s!"""
    raise Warning,  txt % (compiled_gsl_version, run_gsl_version)
