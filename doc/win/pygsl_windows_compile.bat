@echo off
rem Batch processing file for building pygsl with mingw64 from msys2

rem The path to your python installation
set MYPYTHONDIR=C:\LocalPrograms\Python361\
rem set MYPYTHONDIR=C:\LocalPrograms\Python36-modified2\
rem set MYPYTHONDIR=C:\LocalPrograms\Anaconda3\

set PYTHONEXE=%MYPYTHONDIR%\python.exe
rem The path to your msys2 installation
set MSYS2PATH=C:\LocalPrograms\Msys2

set GSL_DIST_CONFIG=gsl_dist\gsl_site.py
if exist %GSL_DIST_CONFIG% (
	echo Is your %GSL_DIST_CONFIG% up to date?
) else (
	echo copy gsl_dist/gsl_site_example.py to %GSL_DIST_CONFIG%
	echo and edit it so that it reflects your gsl installation!
	
	exit /B 
)

rem gcc shall be in the search path
set PATH=%PATH%;%MSYS2PATH%\mingw64\bin;
set LIBRARY_PATH=%MYPYTHONDIR%;

rem config now possible on windows :-)
rem lets see what your GSL installation provides
%PYTHONEXE% setup.py config --compiler=mingw32
rem %PYTHONEXE% setup.py gsl_wrappers

rem build the code
%PYTHONEXE% setup.py build --compiler=mingw32

rem and make the installer
%PYTHONEXE% setup.py build --compiler=mingw32 bdist --formats=msi
