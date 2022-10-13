# intended to be a replacement to the old os.system
#----------------------------------------------------------
import subprocess
import shlex
#----------------------------------------------------------
# this module intends to replace:
#    os.system DEPRECATED
#    os.spawn*
#    os.popen*
#    popen2.*
#    commands.*

# The difference with a check_* prefix is that it raises a CalledProcessError if the return code is non-zero



#----------------------------------------------------------
# subprocess.call(args, *, stdin=None, stdout=None, stderr=None, shell=False)
#----------------------------------------------------------
subprocess.call("echo -n \"test\"", shell=True)
subprocess.call('ls | wc -l', shell=True)
subprocess.call(['ls', '-l'])



#--------------------------------------------------
# subprocess.check_output()
#--------------------------------------------------
# get the stdout as string
output = subprocess.check_output(['ls','/usr'])
output = subprocess.check_output(['echo', '-n', 'ok'])
assert(output == b'ok')




#--------------------------------------------------
# subprocess.Popen()
#     call(), check_output(), and check_call() use Popen internally. 
#--------------------------------------------------
cmd=[]
cmd.append('echo 3')
cmd.append('ls /non/existing/path/')
for i,c in enumerate(cmd):
    args=shlex.split(c)
    proc=subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    proc.wait()
    out, err = proc.communicate()
    print('{}: cmd: {}'.format(i, c))
    print('{}: out: {}'.format(i, out))
    print('{}: err: {}'.format(i, err))
    print('{}: returncode: {}'.format(i, proc.returncode))
#--------------------------------------------------
proc=subprocess.Popen(['echo', '-n', 'ok'], stdout=subprocess.PIPE)
assert(proc.stdout.read()==b'ok')
#--------------------------------------------------
#run in the background
#	p=list()
#	p.append(subprocess.Popen(["nohup", "sleep","3"]))
#	p.append(subprocess.Popen(["nohup", "sleep","5"]))
##	exit_codes=[q.wait() for q in p]
#	p[0].wait()
#	print "p[0] finished"
#	p[1].wait()
#	print "p[1] finished"

##	cmd="sleep 3 && print finished"
#	cmd="sleep 3"
#	args=shlex.split(cmd)
#	p=subprocess.Popen(args)
#	p.wait()

