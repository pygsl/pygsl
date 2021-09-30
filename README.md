PyGSL: Python interface for GNU Scientific Library
===

Status of GSL-Library
---

The gsl-library is since version 1.0 stable and for general use. Read more
about it at the [GSL homepage](http://www.gnu.org/software/gsl/).

PyGSL moved from Sourceforge to GitHub in 2021.

Status of this interface
---

We are collecting implementations of parts of gsl. So the interface is not
complete. We are looking forward to contributions of new submodules, while
maintaining the available code.

Requirements
---

To build the interface, you will need

- [gsl-1.13](https://www.gnu.org/software/gsl/) or better,
- [python2.6](https://python.org/) or better and
- [NumPy](https://www.numpy.org/), and
- a ANSI C compiler (i.e. gcc).

Retrieving the Interface
---

You can download pygsl at https://github.com/pygsl/pygsl

Installing GSL interface
---

Uninstall the old version of pygsl

gsl-config must be on your path

```sh
gzip -d -c pygsl-x.y.z.tar.gz|tar xvf-
cd pygsl-x.y.z
#do this with your preferred python version
#to set the gsl location explicitly use setup.py --gsl-prefix=/path/to/gsl
#If your are using cvs, remove your build directory.
python setup.py config
python setup.py build
# Running only
python setup.py
# can result in an error. So if you see an error running setup.py please
run python setup.py build
# change to a id, that is allowed to do installation
python setup.py install
```

Ready....

Using pygsl
---

Do NOT test the interface in the distribution root directory! -- please
install it first and then change to the tests directory and execute python
run_test.py If you want to execute it in the distribution root directory,
please run python setup.py build_ext -i first! It will put the required
binary files into the pygsl directory.

Just write in python

```py
import pygsl.sf
print "%g+/-%g"%pygsl.sf.erf(1)
```

or

```py
import pygsl.rng
rng=pygsl.rng.rng()
print rng.gaussian(1.0)
```

You may set the environment variable LD_LIBRARY_PATH to find the gsl
shared object.

Uninstall GSL interface
---

```sh
rm -r "python install path"/lib/python"version"/site-packages/pygsl
```

Supported Platforms:

- Linux with python2.* and gsl-1.x
- Mac OS X with python2.* and gsl-1.x
- Win32 with python2.* and gsl-1.x

but is supposed to compile and run on any posix platform

Currently it is being tested:

- python3.5 numpy1.9.2 and gsl-2.1 (on mac os x, fink)

The version 2.1.1 was tested with

- python2.6, numpy1.4 and gsl-1.13 (on linux redhat)
- python2.7 numpy1.8 and gsl-1.16 (on mac os x, fink)
- python3.4 numpy1.8 and gsl-1.16 (on linux debian stable)

Testing
---

The directory test will contain several testsuites, based on python
unittest. Change to this directory to run the tests.

What is implemented (versus gsl2.1):

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

What is not implemented yet (versus gsl1.10)
---

- GSL Capabilites not yet wrapped by PyGSL

    - Sorting
    - N-tuples

- GSL Capabilites partly implemented

    - Discrete Hankel Transforms

See also the TODO file in the distribution.

For the exact function volume for a module, please type:

```python
import pygsl.sf
dir(pygsl.sf)
```

You can do this with the other modules, too. The naming scheme is the same
as in gsl.

Documentation
---

There will be a small reference, but the function reference can be found
in the doc strings and at the gsl-reference. See also the "examples"
directory.

Support
---

Please send mails to [the pygsl mailinglist](mailto:pygsl-discuss@lists.sourceforge.net).

Developement
---

You can browse our [git repository](https://github.com/pygsl/pygsl).

Type this to check out the actual version:
git clone ssh://schnizer@git.code.sf.net/p/pygsl/GitRepro pygsl
The script tools/extract_tool.py generates most of the special function
code.

ToDo
---

See TODO.

History
---

- a gsl-interface for python was needed for a project at [Center for
applied informatics Cologne](http://www.zaik.uni-koeln.de/AFS).
- pygsl-0.0.3 was released at May 23, 2001
- pygsl-0.0.4 was released at January 8, 2002
- pygsl-0.1 was released at August 28, 2002
- pygsl-0.1b was released at May 17, 2003
- pygsl-0.3.0 was released
- pygsl-0.3.1 was released
- pygsl-0.3.3 was released
- pygsl-0.9.0 was released
- pygsl-0.9.3 was released on 15. June 2008
- pygsl-2.2.0 was released 18. April 2016

Thanks
---

- Fabian Jakobs for blas, linalg and eigen
- [Jochen Küpper](mailto:jochen@jochen-kuepper.de) for pygsl.statistics functions
- Leonardo Milano for rpm build support and test
- Michael Forbes for Series Acceleration

Maintainers
---

PyGSL is currently maintained by [Achim Gaedke](achimgaedke@users.sourceforge.net) and [Pierre Schnizer](mailto:schnizer@users.sourceforge.net).
