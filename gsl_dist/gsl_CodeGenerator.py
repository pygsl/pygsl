import sys
import os
import distutils.cmd
import distutils.log
import setuptools
import subprocess
from distutils.file_util import copy_file
from gsl_Location import gsl_Location_File

_Command = distutils.cmd.Command
class gsl_CodeGenerator(_Command):
  """Create code using GSL code generator
  """

  description = 'Code generator for GSL'

  def __init__(self, *args, **kws):
    _Command.__init__(self, *args, **kws)
    self._gsl_location = None

  @property
  def gsl_location(self):
    if self._gsl_location is None:
      self._gsl_location = gsl_Location()
    assert(self._gsl_location)
    return self._gsl_location
  
  def _get_gsl_src_dir(self):
    this_dir = os.path.dirname(__file__)
    tmp = os.path.join(this_dir, os.path.pardir)
    result = os.path.normpath(tmp)
    return result
  
  def _get_ufunc_src_dir(self):
    "Where is the ufunc code expected"
    tmp = os.path.join(self._get_gsl_src_dir(), "testing", "src", "sf")
    result = os.path.normpath(tmp)
    return result

  def _swig_create_xml_file(self, t_file):
    """Swig parser used for generating a swig file

    SWIG allows exporting the read code as an xml file.
    This is used by a self made code to build ufunc wrappers
    See :func:`_create_ufunc_wrapper`
    """
    inc = []

    for a_inc in gsl_Location.get_gsl_include_dirs():
      inc.append('-I' + a_inc)

    command = [gsl_Location.get_swig()] + inc + ["-xml", t_file]

    
    self.announce(
        'Exporting parser tree using swig: %s' % str(command),
        level=distutils.log.INFO)
    subprocess.check_call(command)

  def _create_ufunc_wrapper_code(self):
    """Create the code from the xml file 
    """
    sf_src_dir = self._get_ufunc_src_dir()

    tools_dir = os.path.join(self._get_gsl_src_dir(), "testing", "tools", "generate_interface")
    api_doc_dir = os.path.join(self._get_gsl_src_dir(), "doc", "api", "sf")
    
    tool = os.path.join(tools_dir, "extract_ufunc_swig.py")
    swig_xml_file = os.path.join(sf_src_dir, "sf_wrap.xml")

    test_dir = os.path.dirname(__file__)
    prefix = "sf_"
    command = [sys.executable, tool,
               "--input",  swig_xml_file, "--output-dir", sf_src_dir,
               "--prefix", "sf_", "--doc-dir", api_doc_dir,
               "--test-dir", test_dir]
    self.announce(
      'Creating ufunc wrappers: %s' % str(command),
      level=distutils.log.INFO)
    subprocess.check_call(command)

    #self.announce(
    #  'Copying generated doc (.rst) file to api doc directory')

    #src = os.path.join(sf_src_dir, "sf__doc.rst")    
    #copy_file(src, api_doc_dir)
    
  def _create_ufunc_wrapper(self):
    """    
    """
    sf_src_dir = self._get_ufunc_src_dir()
    t_file = os.path.join(sf_src_dir,  "sf.i")
    self._swig_create_xml_file(t_file)

    self._create_ufunc_wrapper_code()

    
  def run(self):
    """Run command

    Creates the code by:
        * running swig for creating an xml file containing the headers
        * running a dedicated tool creating the wrapper code
    """
    #if self.pylint_rcfile:
    #  command.append('--rcfile=%s' % self.pylint_rcfile)
    self._create_ufunc_wrapper()

