*****************************
Design of the PyGSL interface
*****************************

The GSL library was implemented using the C language. This implies that
each function uses a certain type for the different variables and are
fixed to one specific type. The wrapper will try to convert each
argument to the approbriate C type. The PyGSL interface tries to follow
it as much as possible but only as far as resonable. For example the
definition of the :c:function:`gsl\_poly\_eval function in C is given by

.. c:function:: double gsl\_poly\_eval(const double C[], const int LEN, const double X)

The corresponding python wrapper was implemented by

.. py:function::  poly.poly\_eval(C, x)

as the wrapper can get the length of any python object and then fill the
len variable. The mathematical calculation is performed by the GSL
library. Thus the calculation is limited to the precision provided by
the underlying hardware.

Default arguments are used to allocate workspaces on the fly if not
provided by the user. Consider for example the fft module. The function
for the real forward transform is named

.. c:function:: int gsl\_fft\_real\_transform (double DATA[], size_t STRIDE, size_t N,
		const gsl_fft_real_wavetable * WAVETABLE, gsl_fft_real_workspace * WORK)

The corresponding python wrapper is provided by the function

.. py:function:: real\_transform(data, [space, table, output])

in the :mod:`pygsl.fft`  


The wrapper will get the stride and size information from the data
object provided by the user. If space or table are not provided, these
objects will be generated on the fly. As the GSL function applies the
transformation in space, an internal copy is made of the data and only
then the object is passed to the GSL function. If an output object is
provided the data will be copied there instead. PyGSL will always make
copies of objects which would be otherwise modified in place.

Callbacks
=========

Solvers require as one argument a user function to work on which have to
be provided by the user. These callbacks typically are of the form

.. py:function:: f (x, args)
   :param x: indepent variable
   :param args: additional [user] arguments

Please note that this function must return the exact number of arguments
as given in the example. The wrappers around callbacks go a long way to
try to provide meaningfull error messages. If a solver fails, please
check that the number of input and output arguments it takes are correct.

Error handling
==============

As GSL is a C library error handling is implemented using an error
handler and return values. PyGSL generates python exceptions out of
these values. See :mod:`pygsl.errors` for a list of the
exceptions. 

The GSL error numbers are given in :mod:`pygsl.errno`.

Exception handling
==================

GSL provides a selectable error handler, that is called for occuring
errors (like domain errors, division by zero, etc. ). This is switched
off. Instead each wrapper function will check the error return value and
in case of error an python exception is created.

Here is a python level example:

.. code-block:: python

    import pygsl.histogram
    import pygsl.errors
    hist=pygsl.histogram.histogram2d(100,100)
    try:
       hist[-1,-1]=0
    except pygsl.errors.gsl_Error as err:
       print err

Will result in 

::

    input domain error: index i lies outside valid range of 0 .. nx - 1

An exception are ufuncs in the testings.sf module (see
section[sec:ufuncs]).

Change of internal error handling.
----------------------------------


Before a error handler was installed by init\_pygsl into gsl which
translated the error code (and the message) to a python exception. This
required that the GIL was available, which numpy ufuncs dispose. Thus
now this gsl error handler is deactivated and instead the C error code
returned by the C function is translated to an error code by the wrapper
called from python.

UFuncs do not call this handler now at all.

The documentation gap
=====================

PyGSL does still lack an appropriate documentation. Most documentation
is accessible over the internal documentation strings. These are
accessible as attributes (the help function does not always show them).
It can be sometimes necessary to create an object to see its methods as
well as the documentation of the methods (e.g.a random number generator
in the rng module to see its methods). The directory contains examples
for (nearly each) module.

Please feel welcome to add to the documentation!

Acknowledgment
==============

Parts of this this manual are based on the GNU Scientific Library
reference manual. 

The authors want to thank all for contribution of
code, support material for generating distribution packages, bug reports
and example scripts.

