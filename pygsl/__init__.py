# author: Achim Gaedke
# created: May 2001
# file: pygsl/__init__.py
# $Id$

# Central Module used by C callbacks. So a good idea to import it here to be
# sure that  it exists from the very beginning!
import pygsl.errors
import pygsl.init

version="0.0.5"
__all__=['sf','const','ieee','rng','errors','histogram','statistics','matrix']
