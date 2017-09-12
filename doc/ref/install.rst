*********************************
System Requirements, Installation
*********************************


Status
------

Status of GSL-Library
'''''''''''''''''''''

The gsl-library is since version 1.0 stable and for general use. More
information about it at http://www.gnu.org/software/gsl/.

Status of this interface
''''''''''''''''''''''''

Nearly all modules are wrapped. A lot of tests are covering various
functionality. Please report to the mailing list
`pygsl-discuss@lists.sourceforge.net`_ if you find a bug.

The hankel modules have been wrapped. Please write to the mailing list
`pygsl-discuss@lists.sourceforge.net`_ if you require one of the modules
and are willing to help with a simple example. If any other function is
missing or some other module (e.g. ntuple) or function, do not hesitate
to write to the list.

Retriving the Interface
'''''''''''''''''''''''

You can download it here: http://sourceforge.net/projects/pygsl

Requirements
------------

To build the interface, you will need

-  gsl-1.x or gsl-2.1 or newer http://www.gnu.org/software/gsl/
-  python2.7 or python3.x,
-  numpy  http://numpy.sf.net
-  a c compiler like gcc: 

Supported Platforms are:
-  Linux (Redhat/Debian/SuSE) with python2.\* and gsl-1.\*
-  Win32
-  MacOS X

It was tested and is tested on an irregular basis on the following
platforms
-  SUN
-  Cygwin

but is supposed to build on any POSIX platforms.

Installing the pygsl interface
------------------------------

:program:`gsl-config` must be on your path:

::

    # unpack the source distribution
    gzip -d -c pygsl-x.y.z.tar.gz|tar xvf-
    cd pygsl-x.y.z
    # do this with your prefered python version
    # to set the gsl location explicitly use setup.py --gsl-prefix=/path/to/gsl
    # First configure pygsl interface
    python setup.py config
    #
    python setup.py build
    # change to an user id, that is allowed to do installation
    python setup.py install

Ready....

**Do not test the interface in the distribution root or in the
directories or .**

If you find unresolved symbols later on, delete the C source in the
swig\_src files. Check that swig can be called from the command line.
Then start the build process again.

In this case swig will rebuild the C files. The swig\_src files
distributed with pygsl are to an up to date version of GSL (1.16 as of
this writing). Swig parses partly some header header files and builds
the appropriate interface functions. If you have an older GSL version
locally installed, the sources in the swig\_src directory can contain
links to symbols which are not defined by the locally installed GSL
version.

Building on win32
~~~~~~~~~~~~~~~~~

Windows by default does not allow to run a posix shell. Here a different
path is required. First change into the directory *gsl_dist*. Copy the file and
edit it to reflect your installation of GSL and SWIG if you want to run
it yourself. The pygsl windows binaries distributed over
http://sourceforge.net/projects/pygsl/ are built using the mingw32
compiler.

Uninstall GSL interface
'''''''''''''''''''''''

``rm -r`` “python install path”``/lib/pyhon``“version”``site-packages/pygsl``

Testing
'''''''

The directory ``tests`` contains several testsuites, based on python :module:`unittest`. The script
``run_test.py``in this directory will run one test suit after the other.

Support
'''''''

Please send mails to our mailinglist at pygsl-discuss@lists.sourceforge.net.

Developement
''''''''''''

At last the development tree was migrated to git.
 You can browse our cvs tree at  https://sourceforge.net/p/pygsl/GitRepro/ci/master/tree/
 
| Type this to check out the repository::
   
   git clone https://git.code.sf.net/p/pygsl/GitRepro pygsl-GitRepro

The script ``tools/extract_tools.py`` generates most of the special function code. Please note that most special functions are available as numericl Ufuncs from :module:`testing/sf`

ToDo
''''

- complete implementation of modules
- documentation
- examples
- test suits


History
'''''''

-  a gsl-interface for python was needed for a project at
   Center for Applied Informatics Cologne  http://www.zaik.uni-koeln.de/AFS 

-  gsl-0.0.3 was released at May 23, 2001
-  gsl-0.0.4 was released at January 8, 2002
-  gsl-0.0.5 was growing since January, 2002
-  gsl-0.2.0 was released at
-  gsl-0.3.0 was released at
-  gsl-0.3.1 was released at
-  gsl-0.3.2 was released at
-  gsl-0.9.4 was released at 25. October 2008

Thanks
''''''

- Jochen Küpper for :module:`pygsl.statistics`
  
-  Fabian Jakobs for :module:`pygsl.blas` :module:`pygsl.eigen` :module:`pygsl.linalg` :module:`pygsl.permutation`

-  Leonardo Milano for rpm build

- Eric Gurrola and Peter Stoltz for testing and supporting the port of
  pygsl to the MAC

- Sebastien Maret for supporting the Fink http://fink.sourceforge.net
  port of pygsl.

- and all for support by providing feed back on testing or showing by email that the code is useful for them  

Maintainers
'''''''''''

-  Achim Gädke (),
-  Pierre Schnizer ()
