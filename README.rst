PyGSL: Python interface for GNU Scientific Library
==================================================


.. image:: https://img.shields.io/pypi/v/pygsl.svg
        :target: https://pypi.python.org/pypi/pygsl

.. image:: https://img.shields.io/conda/vn/conda-forge/pygsl
        :target: https://anaconda.org/conda-forge/pygsl

..
  .. image:: https://img.shields.io/codecov/c/github/bluesky/pygsl
          :target: https://codecov.io/gh/pygsl/pygsl

.. image:: https://img.shields.io/github/commits-since/pygsl/pygsl/latest
        :target: https://github.com/pygsl/pygsl

.. image:: https://img.shields.io/pypi/dm/pygsl?label=PyPI%20downloads
        :target: https://pypi.python.org/pypi/pygsl

.. image:: https://img.shields.io/conda/dn/conda-forge/pygsl?label=Conda-Forge%20downloads
        :target: https://anaconda.org/conda-forge/pygsl




PyGSL is a Python wrapper for the `GNU Scientific Library (GSL) <http://www.gnu.org/software/gsl/>`_. Nearly all modules are wrapped. A lot of tests are covering various functionality.

Please report it as a `Github Issue <https://github.com/pygsl/pygsl/issues>`_ if you find a bug. We are looking forward to contributions of new submodules, while maintaining the available code, and welcome `pull requests <https://github.com/pygsl/pygsl/pulls>`_.

PyGSL moved from Sourceforge to GitHub in 2021.

Requirements
------------

To build the interface, you will need

- `GSL 2.x <https://www.gnu.org/software/gsl/>`_
- `Python 3.9 <https://python.org/>`_ or newer
- `NumPy <https://www.numpy.org/>`_
- Swig4 <https://www.swig.org>_
- an ANSI C compiler (e.g. gcc).
- A Posix 1 compliant operating system

Since version 2.6 PyGSL is built using meson-python. Swig must be always
installed to build PyGSL.Meson-python will be automatically
installed by PyPI during the build process.

Installing PyGSL
----------------

Installing via PyPI
~~~~~~~~~~~~~~~~~~~


PyGSL can also installed using the pip package installer.
SWIG is required to be installed and can usually be found via your distribution's package manager
(for example, ``apt install swig``).

To install PyGSL from PyPI, first install

.. code-block:: sh

   pip install --upgrade pip wheel

.. code-block:: sh

   pip install pygsl

To remove PyGSL, use:

.. code-block:: sh

   pip uninstall pygsl


Building it locally
~~~~~~~~~~~~~~~~~~~

It can be useful to install PyGSL locally e.g. if the automatic build process fails.
In a first step, update the packages `pip` and `wheel` as

.. code-block:: sh

   pip install --upgrade build

-- code-block:: sh

   python3 -m build -w .



Using PyGSL
-----------

Do NOT test the interface in the distribution root directory! -- please
install it first and then change to the tests directory and execute ``python
-m pytest .``.


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

but is supposed to compile and run on any posix platform.

Currently it is being tested using GitHub Actions continuous integration on:

- Python 3.9 -- 3.12, numpy 1.x and 2.x  and GSL 2.7.1 under Ubuntu Linux 22.04.2.


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


What is not implemented yet (versus GSL 2.7)
---------------------------------------------

- GSL Capabilites not yet wrapped by PyGSL

    - Sorting
    - N-tuples

- GSL Capabilites partly implemented

    - Discrete Hankel Transforms

See also the TODO file in the distribution.

For the exact function volume for a module, please type:

.. code-block:: python

   from pygsl.testing import sf
   dir(sf)

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
* Sergei Ossokine
* Jerry James
* and all for support by providing feed back on testing or showing by
  email that the code is useful for them


Maintainers
-----------

PyGSL is currently maintained by `Achim Gaedke <mailto:achimgaedke@users.sourceforge.net>`_, `Pierre Schnizer <mailto:schnizer@users.sourceforge.net>`_ and `Charl Linssen <mailto:c.linssen@fz-juelich.de>`_.
