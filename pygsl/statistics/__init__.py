# author: Achim Gaedke
# created: January 2002
# file: pygsl/statistics/__init__.py
# $Id$

from pygsl.statistics.double import *

__all__ = filter(lambda s:s[0:2]!="__" or s=="double",dir())




