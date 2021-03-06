GSL Capabilites not yet wrapped by PyGSL
========================================

Sorting
-------

Is covered by the list sorting methods of Python. See Python Mini
Sorting howto [1]_ and Python stable sort [2]_.

N-tuples
--------

If you do not know PAW or ROOT you probably will not need them. If you
need them, assistance will be provided if required.

GSL Capabilites partly implemented
==================================

Discrete Hankel Transforms
--------------------------

SWIG wrapped, but do you know what it is supposed to do? If so write a
test and an example!

Something else missing ?
------------------------

If some function or module is not covered do not hesitate to post your
request as a `GitHub Issue <https://github.com/pygsl/pygsl/issues>`_.

PyGSL related Capabilites
=========================

Blas Memory handling
--------------------

Blas is basically wrapped, but:

-  NumPy and GSL vectors and matrices differ slightly. 1-dimensional arrays
   and GSL Vectors can be interchanged. The difference between the two is
   mainly that Numpy counts the stride in bytes whereas GSL counts it in the
   basis type.

-  2-dimensional Numpy arrays use the stride concept for both dimensions
   whereas the GSL matrices use an offset tda. So they assume contiunes
   lines, with some elements on the line not used. Here one could think of a
   full featured matrix object, which can interoperate with a numeric array
   simulating an Matrix object. Such a object would be useful to allow
   prototyping of linear algebra systems in python. The next point needs to
   be implemented as well.

-  optional reused return object: Numpy allows to add an optional argument to
   many functions, which is to be used as return argument. This avoids the
   need to delete and reallocate objects.

References
==========

.. [1] http://www.amk.ca/python/howto/sorting/sorting.html
.. [2] http://py-stablesort.sourceforge.net/
