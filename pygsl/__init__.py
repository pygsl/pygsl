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
         -- ieee
         -- integrate
         -- interpolation
         -- linalg
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

# Central Module used by C callbacks. So a good idea to import it here to be
# sure that  it exists from the very beginning!
import pygsl.errors

import pygsl.init
from exceptions import Warning

# The gsl version which was used when this module was compiled.
compiled_gsl_version = pygsl.init.compiled_gsl_version

# The gsl version which is used  now
run_gsl_version = pygsl.init.run_gsl_version

# The compile date
compile_date = pygsl.init.compile_date

version="0.1.x"
__all__=['sf','const','ieee','rng','errors','histogram',
         'statistics','matrix']

if compiled_gsl_version != run_gsl_version:
    # Make warning out of it
    txt = """WARNING: This pygsl module was compiled for GSL version %s but it
is used with version %s!"""

    raise Warning,  txt % (compiled_gsl_version, run_gsl_version)


def import_all():
    """
    PyGSL does not import all modules on statup. If you like that
    e.g for autocompletion call this function!
    """
    import pygsl.blas
    import pygsl.chebyshev
    import pygsl.combination
    import pygsl.const
    import pygsl.diff
    import pygsl.eigen
    import pygsl.fit
    import pygsl.ieee
    import pygsl.integrate
    import pygsl.interpolation
    import pygsl.linalg
    import pygsl.minimize
    import pygsl.multifit
    import pygsl.multifit_nlin
    import pygsl.multimin
    import pygsl.multiroots
    import pygsl.odeiv
    import pygsl.permutation
    import pygsl.poly
    import pygsl.qrng
    import pygsl.rng
    import pygsl.roots
    import pygsl.siman
    import pygsl.sf
    import pygsl.statistics
    
    
