import sys
sys.stdout = sys.stderr
import os
import glob

excluded_files = ['gsl_test.py', 'run_test.py']

def run_file_posix(file):
    

    pid = os.fork()
    if pid == 0:
	#child 
	#print "Executing child %d" % os.getpid()
	absfile = os.path.abspath(file)
	print "Executing file %s %s" % (sys.executable,  absfile)	
	os.execl(sys.executable, "", absfile)
	#print "Exit status of %s is %d" % (absfile, flag)
	#sys.exit(flag)
	
    elif pid > 0:
	# parent
	#print "Parent waiting for child %d" % pid
	cpid , status = os.waitpid(pid, os.P_WAIT)
	assert(cpid == pid)
	if os.WIFSIGNALED(status):
	    print "Recieved signal when executing file %s, status %d" % (file, status)
	return
    elif pid < 0:
	print "Fork error!"
	sys.exit(-1)
    else:
	raise ValueError, "How could I end up here?"

def run_file_nt(file):
    absfile = os.path.abspath(file)
    print absfile
    pid = os.spawnv(os.P_WAIT, sys.executable, (" ", absfile))
    pass

if os.name == 'posix':
    run_file = run_file_posix
elif os.name == 'nt':   
    run_file = run_file_nt
    
def run():
    import pygsl
    try:
	file = __file__
    except NameError:
	file = sys.argv[0]
    search_path = os.path.normpath(os.path.dirname(file))
    os.chdir(search_path)    
    files = glob.glob('*_test.py')
    files.sort()
    print "I will run the tests in the following order:"
    for file in files:
	print "\t%s" % file
    print "\n"
    
    for file in files:
	if file in excluded_files:
	    continue	
	path = os.path.join(search_path, file)
	path = os.path.normpath(path)
	run_file(path)
	
if __name__ == '__main__':
    run()
    
