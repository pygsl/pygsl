#!/bin/sh
# It can be that you have to make python ready for handling msys2
# # python handling of the Microsoft C libary msvcr 
# # needs to be handled by    
# pacman -S patch
# # Do I need that ... if I hack on numpy
# # Some patch for msvcr 
# # Now put into two patches
# wget.exe https://bugs.python.org/file40608/patch.diff
# cd /c/LocalPrograms/Python36/Lib/distutils
# patch  -p0 < /c/Users/mfp/Devel/patch.diff

# Make sure that the build system is installed
pacman -S make
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-lld
pacman -S tar


# A build directory
mkdir Devel
# A directory to install the GSL library to
mkdir local

# The location of the tar balls. 
GSL_DIST_FILE=`pwd`/Downloads/gsl-2.3.tar.gz
PyGSL_DIST_FILE=`pwd`/Downloads/pygsl-2.2.0.tar.gz

# I assume that GSL has to be built. lets get started
cd Devel
tar zxvf "$GSL_DIST_FILE"
pushd  gsl-2.3/
# include the gcc path ...
# if one uses the environment variable CC the configure script does not
export PATH=$PATH:/mingw64/bin
./configure --enable-shared=no --disable-shared --prefix=`pwd`/../../local/
make
make install
popd
# Assuming that it has been successful!


$ tar zxvf "$PyGSL_DIST_FILE"
echo "pygsl is now built using pygsl_windows_compile.bat"
echo "Start it from the command shell!"