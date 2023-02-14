Front Matter
============

Copyright © 2002,2005,2017 The pygsl Team.

Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.1 or
any later version published by the Free Software Foundation; with no
Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts. A
copy of the license is included in section :ref:`gun-free-doc`
entitled “GNU Free Documentation License”.


System Requirements, Installation
=================================



Status of GSL-Library
---------------------

The gsl-library is since version 1.0 stable and for general use. More
information about it at http://www.gnu.org/software/gsl/.

Status of this interface
------------------------

Nearly all modules are wrapped. A lot of tests are covering various
functionality. Please report to https://github.com/pygsl/pygsl/issues
in case of any problems

The hankel modules have been wrapped. Please write to the mailing list
`pygsl-discuss`_ if you require one of the modules
and are willing to help with a simple example. If any other function is
missing or some other module (e.g. ntuple) or function, do not hesitate
to write to the list.

Retriving the Interface
-----------------------
You can download it here: https://github.com/pygsl/pygsl/

Requirements
------------

To build the interface, you will need
    *  gsl-2.1 or newer http://www.gnu.org/software/gsl/
    *  python3.x,
    *  numpy  http://numpy.sf.net
    *  a c compiler like gcc

Supported Platforms are:
    *  Linux with python3 and gsl-2
    *  MacOS X

But is is supposed to build on any POSIX platforms. It should build on windos. But this build is not trivial. Descriptions follow below.



Installing the pygsl interface
------------------------------

The :program:`gsl-config` must be on your path on posix platforms.
Then type:

.. code-block:: shell

    # unpack the source distribution
    gzip -d -c pygsl-x.y.z.tar.gz|tar xvf-
    cd pygsl-x.y.z
    # do this with your prefered python version
    # to set the gsl location explicitly use setup.py --gsl-prefix=/path/to/gsl
    # First configure pygsl interface
    python setup.py config
    # Build the wrappers (if required ... needs swig installed)
    python setup.py gsl_wrappers
    # Then build the interface
    python setup.py build
    # change to an user id, that is allowed to do installation
    python setup.py install

Ready....

**NB**: e.g. Ubuntu 22.0 provides `swig` by name `swig4.0`. The gsl-wrapper want's to call a program named swig. This can be changed by specifing the environment variable `SWIG` to

.. code-block:: shell

   export SWIG=swig4.0




**Do not test the interface in the distribution root** In this case
python will search for all modules in the distribution directory ``pygsl``.

If you find unresolved symbols later on, delete the C source in the
swig\_src files. Check that swig can be called from the command line.
Then start the build process again.

In this case swig will rebuild the C files. The swig\_src files
distributed with pygsl are to an up to date version of GSL (2.4 as of
this writing). Swig parses partly some header header files and builds
the appropriate interface functions. If you have an older GSL version
locally installed, the sources in the swig\_src directory can contain
links to symbols which are not defined by the locally installed GSL
version.

Building on win32
-----------------

Windows by default does not allow to run a posix shell. Here a different
path is required. First change into the directory *gsl_dist*. Copy the file and
edit it to reflect your installation of GSL and SWIG if you want to run
it yourself. The pygsl windows binaries distributed over
http://sourceforge.net/projects/pygsl/ are built using the mingw
compiler.

Building the GSL library
~~~~~~~~~~~~~~~~~~~~~~~~
In a first step install Msys http://www.msys2.org/ .
Execute the commands given in the shell
script below (it is also given in ``doc/win/pygsl_msys2_prepare.sh``
or can be dowloaded :download:`here </win/pygsl_msys2_prepare.sh>`):

.. literalinclude:: ../win/pygsl_msys2_prepare.sh
    :language: bash

This will build gsl using the mingw compiler.

Building the pygsl interface
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Copy the file
``gsl_dist/gsl_site_example.py`` to
``gsl_dist/gsl_site.py``. Edit it so that it reflects your
installation.
Now open a windows command shell. An example batch file
is found at ``doc/win/pygsl_windows_compile.bat`` or can be downloaded
:download:`here  </win/pygsl_windows_compile.bat>`. Change it to your
needs and start it from the command shell.

.. literalinclude:: ../win/pygsl_windows_compile.bat
    :language: bat


Uninstall GSL interface
-----------------------

.. code-block:: bash

    rm -r “python install path”/lib/"pyhon version"/site-packages/pygsl

Testing
-------

The directory ``tests`` contains several testsuites, based on python :mod:`unittest`. The script
``run_test.py`` in this directory will run one test suit after the
other. Alternatively you can change into the test's directory and run

.. code-block:: bash

   pytest


Support
-------

Please report issues at https://github.com/pygsl/pygsl/issues

Development
-----------
At last the development tree was migrated to git.
You can browse our git tree at
https://github.com/pygsl/pygsl/


Some wrappers use swig http://swig.org ; thus a runnable recent swig
is a perequisite. The wrapper code which is distributed together with
the source is built using swig-4.

PyGSL provides tools for generating the wrapper code from source
files. These tools can be executed by

.. code-block:: bash

    python setup.py gsl_wrappers

Currently the wrapper code is generated for special functions.  These
are wrapped as numpy universal functions.



ToDo
----

* complete implementation of modules
* documentation
* examples
* test suits


History
-------


*  a gsl-interface for python was needed for a project at
*  Center for Applied Informatics Cologne  http://www.zaik.uni-koeln.de/AFS
*
*  gsl-0.0.3 was released at May 23, 2001
*  gsl-0.0.4 was released at January 8, 2002
*  gsl-0.0.5 was growing since January, 2002
*  gsl-0.2.0 was released at
*  gsl-0.3.0 was released at
*  gsl-0.3.1 was released at
*  gsl-0.3.2 was released at
*  gsl-0.9.4 was released at 25. October 2008

Thanks
------

* Jochen Küpper for :mod:`pygsl.statistics`
* Fabian Jakobs for :mod:`pygsl.blas`, :mod:`pygsl.eigen`,
  :mod:`pygsl.linalg` and :mod:`pygsl.permutation`
* Leonardo Milano for rpm build
* Eric Gurrola and Peter Stoltz for testing and supporting the port of
  pygsl to the MAC
* Sebastien Maret for supporting the Fink http://fink.sourceforge.net
  port of pygsl.
* and all for support by providing feed back on testing or showing by
  email that the code is useful for them

Maintainers
-----------

*  :email:`Pierre Schnizer <schnizer@users.sourceforge.net>`
*  `Charl Linsen https://github.com/clinssen`
*  :email:`Achim Gädke <AchimGaedke@users.sourceforge.net>`
