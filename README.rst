PyGSL: Python interface for GNU Scientific Library
==================================================

Status of GSL-Library
---------------------

The gsl-library is since version 1.0 stable and for general use. Read more
about it at the `GSL homepage <http://www.gnu.org/software/gsl/>`_.

PyGSL moved from Sourceforge to GitHub in 2021.

Status of this interface
------------------------

We are collecting implementations of parts of GSL. So the interface is not
complete. We are looking forward to contributions of new submodules, while
maintaining the available code. See `TODO <TODO.html>`_.


Requirements
------------

To build the interface, you will need

- `GSL 2.x <https://www.gnu.org/software/gsl/>`_
- `Python 3.x <https://python.org/>`_
- `NumPy <https://www.numpy.org/>`_
- an ANSI C compiler (e.g. gcc).

Retrieving the Interface
------------------------

You can download PyGSL at https://github.com/pygsl/pygsl/releases.

Installing GSL interface
------------------------

Uninstall the old version of PyGSL.

gsl-config must be on your path.

.. code-block:: sh

   gzip -d -c pygsl-x.y.z.tar.gz|tar xvf-
   cd pygsl-x.y.z
   # do this with your preferred python version
   # to set the gsl location explicitly use setup.py --gsl-prefix=/path/to/gsl
   # If your are using cvs, remove your build directory.
   python setup.py config
   python setup.py build
   # Running only
   python setup.py
   # can result in an error. So if you see an error running setup.py please run
   python setup.py build
   # change to a id, that is allowed to do installation
   python setup.py install

Ready!

PyGSL is installed to the Python packages path, and can be uninstalled by typing:

.. code-block:: sh

   rm -r <python install path>/lib/python<version>/site-packages/pygsl

Installation via PyPI
---------------------

PyGSL can also be installed using the pip package installer. This requires the Python packages ``setuptools`` and ``wheel`` to be already installed. Simply type:

.. code-block:: sh

   python -m pip install setuptools wheel
   python -m pip install pygsl

To remove PyGSL, use:

.. code-block:: sh

   python -m pip uninstall pygsl

Using PyGSL
-----------

Do NOT test the interface in the distribution root directory! -- please
install it first and then change to the tests directory and execute ``python
run_test.py``. If you want to execute it in the distribution root directory,
please run ``python setup.py build_ext -i`` first! It will put the required
binary files into the ``pygsl`` directory.

Just write in Python

.. code-block:: python

   import pygsl.sf
   print("%g+/-%g"%pygsl.sf.erf(1))

or

.. code-block:: python

   import pygsl.rng
   rng=pygsl.rng.rng()
   print rng.gaussian(1.0)

You may set the environment variable ``LD_LIBRARY_PATH`` to find the gsl
shared object.

Supported Platforms
-------------------

- Linux with Python 3.x and GSL 2.x
- Mac OS X with Python 3.x and GSL 2.x
- Win32 with Python 3.x and GSL 2.x

but is supposed to compile and run on any posix platform.

Currently it is being tested using GitHub Actions continuous integration on:

- Python 3.8, numpy-latest and GSL 2.5 under Ubuntu Linux 20.04.


Testing
-------

The directory test will contain several testsuites, based on Python
unittest. Change to this directory to run the tests.

What is implemented (versus GSL 2.1):

- Blas
- BSplines
- Chebyshev
- Combination
- Const
- Diff
- Eigen
- Fit
- Ieee
- Integrate
- Interpolation
- Interpolation2D
- Linalg
- Math
- Minimize
- Multifit
- Multifit_nlin
- Multimin
- Multiroots
- Odeiv
- Permutation
- Poly
- Qrng
- Rng
- Roots
- Siman
- Sf
- Spline
- Statistics

What is not implemented yet (versus GSL 1.10)
---------------------------------------------

- GSL Capabilites not yet wrapped by PyGSL

    - Sorting
    - N-tuples

- GSL Capabilites partly implemented

    - Discrete Hankel Transforms

See also the TODO file in the distribution.

For the exact function volume for a module, please type:

.. code-block:: python

   import pygsl.sf
   dir(pygsl.sf)

You can do this with the other modules, too. The naming scheme is the same
as in GSL.

Documentation
-------------

The function reference can be found in the docstrings and at the gsl-reference.

Written documentation can be found in the ``doc/ref`` directory.

See also the ``examples`` directory.

Support
-------

Support requests and all other questions should be submitted as a `GitHub Issue <https://github.com/pygsl/pygsl/issues>`_.

Developement
------------

You can browse our `git repository <https://github.com/pygsl/pygsl>`_.

If you want to contribute to PyGSL, please fork the repository and create a pull request.

The script tools/extract_tool.py generates most of the special function code.

History
-------

A GSL interface for Python was needed for a project at `Center for
applied informatics Cologne <http://www.zaik.uni-koeln.de/AFS>`_.

pygsl-0.0.3 was released on May 23, 2001.

Thanks
------

* Charl Linssen for continous integration
* Jochen Küpper for pygsl.statistics
* Fabian Jakobs for pygsl.blas, pygsl.eigen,
  pygsl.linalg and pygsl.permutation
* Leonardo Milano for rpm build support and test
* Eric Gurrola and Peter Stoltz for testing and supporting the port of
  pygsl to the MAC
* Sebastien Maret for supporting the Fink http://fink.sourceforge.net
  port of pygsl.
* Michael Forbes for Series Acceleration
* and all for support by providing feed back on testing or showing by
  email that the code is useful for them

Maintainers
-----------

PyGSL is currently maintained by `Achim Gaedke <mailto:achimgaedke@users.sourceforge.net>`_, `Pierre Schnizer <mailto:schnizer@users.sourceforge.net>`_ and `Charl Linssen <mailto:c.linssen@fz-juelich.de>`_.
