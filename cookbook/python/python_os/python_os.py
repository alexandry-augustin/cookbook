import os
import re
import sys
#----------------------------------------------------------
# see also shutil
#----------------------------------------------------------
# cf also subprocess.call(()
# os.system() is DEPRECATED
#----------------------------------------------------------
# open(path, 'w')   #create a file
# os.path.basename(path)
# os.path.join(path, path, ...)
# os.path.exists(path)  #
# os.path.isdir(path)   #
# os.path.isfile(path)  #
# os.walk(path)     #
# os.makedirs(path)     #create dir
#               creates intermediate directories if they don't exist
# os.mkdir(path)    #create dir
#               throws if dir already exists
#               do not creates intermediate directories if they don't exist (throws)
# os.listdir(path)  #
# os.rename(path)   #[rename|move] a [file|dir]
# os.remove(path)   #[rename|delete] file
#               can't remove dir
# os.rmdir(path)    #delete empty dir
#               thows if [not empty|dir doesn't exist]

#----------------------------------------------------------
def find_(path, regex):
    """
        DEPRECATED: see `scantree(...)` below
        
        list files matching regex (not directories)
        NOTE empty directories won't be listed
        NOTE no warnings on "Permission denied" paths
        
        see also:
            for e in os.scandir(path):
                print(e.path, e.name)

            for d in os.listdir(path):
                print(d)
                
        TODO use os.scandir() instead
        
    """
#    ret=[]
    for (path, dirs, files) in os.walk(path):
        for f in files:
            if regex.search(f):
#                ret.append(os.path.join(path, f))
                yield os.path.join(path, f)
#    return ret
#----------------------------------------------------------
def scantree(path, regex):
    """
        Recursively yield DirEntry objects for given directory.
        
        https://stackoverflow.com/questions/33135038/how-do-i-use-os-scandir-to-return-direntry-objects-recursively-on-a-directory
    """
    
    for p in os.scandir(path):
        if p.is_dir(follow_symlinks=False):
            try:
                yield from scantree(p.path, regex)
            except Exception as e:
                print(e)
        else:
            if regex.search(p.name):
                yield p
#----------------------------------------------------------
def ls_recursive(path):
    tree=os.walk(path)
    for (path, dirs, files) in tree:
        print('==============')
        print('path:', path)
        print('dirs:', dirs)
        print('files:', files)
    #or
#   for tuple in tree:
#       print('==============')
#       print('path:', tuple[0])
#       print('dirs:', tuple[1])
#       print('files:', tuple[2])
#----------------------------------------------------------
def ls(path):
    d={}
    files=os.listdir(path)
    files.sort()
    for f in files:
        if os.path.isdir(f):
            print("-d "+f)
            d[f]="d"
        if os.path.isfile(f):
            d[f]="f"

    for k,v in d.iteritems():
        print "-"+v+" "+k
#----------------------------------------------------------
def lsd(path):
    """ list directories """
    return [e for e in os.listdir(path) if os.path.isdir(os.path.join(path, e))]
#----------------------------------------------------------
def lsf(path):
    """ list files """
    return [e for e in os.listdir(path) if os.path.isfile(os.path.join(path, e))]
#----------------------------------------------------------
def lsf(path, filter_):
    """ list files with filter"""
    return [e for e in os.listdir(path) if os.path.isfile(os.path.join(path, e)) and e.find(filter_)!=-1]
#----------------------------------------------------------
def lsf(path, pattern):
    """ list files with regex pattern"""
    regex = re.compile(pattern) 
    return [e for e in os.listdir(path) if os.path.isfile(os.path.join(path, e)) and regex.search(e)]
#----------------------------------------------------------
def getDirPaths(path):
    return [e for e in os.listdir(path) if os.path.isdir(e)]
#----------------------------------------------------------
def subsystem(cmd):
    error=os.system(cmd)
    assert(error==0) #no errors
#----------------------------------------------------------
#def test():
#   for dirname, dirnames, filenames in os.walk('.'):
#       # print path to all subdirectories first.
#       for subdirname in dirnames:
#           print os.path.join(dirname, subdirname)
#
#       # print path to all filenames.
#       for filename in filenames:
#           print os.path.join(dirname, filename)
#
#       # Advanced usage:
#       # editing the 'dirnames' list will stop os.walk() from recursing into there.
#       if '.git' in dirnames:
#           # don't go into any .git directories.
#           dirnames.remove('.git')
#----------------------------------------------------------
def dir_tree_mk_(dir_path_list):
    for path in dir_path_list:
        assert(not os.path.exists(path))
        os.makedirs(path)
#----------------------------------------------------------
def dir_tree_mk():
    assert(not os.path.exists('foo'))
    assert(not os.path.exists('foo/bar'))
    os.makedirs('foo/bar')
    assert(os.path.exists('foo'))
    assert(os.path.exists('foo/bar'))
    open('foo/bar/test', 'w')
    assert(os.path.exists('foo/bar/test'))
#----------------------------------------------------------
def dir_tree_rm():
#   try:
#       os.rmdir('foo/bar')
#   except OSError:
#       print 'no'
    os.remove('test')
    assert(not os.path.exists('test'))
    os.rmdir('foo/bar')
    assert(os.path.exists('foo'))
    assert(not os.path.exists('foo/bar'))
    os.rmdir('foo')
    assert(not os.path.exists('foo'))
    assert(not os.path.exists('foo/bar'))
#----------------------------------------------------------
if __name__=='__main__':
#   print(find('..', re.compile('\.py$')))
#   print(find('..', re.compile('^base\.py$')))
    for path in find('..', re.compile('^base\.py$')):
        print(path)

	for entry in scantree('..', re.compile('^base\.py$'):
		print(entry.path)

#   dir_tree_mk_(['./foo', './bar'])
#   dir_tree_mk()
#   dir_tree_rm()
#   dir_tree_rm_('foo')
#    ls('.')
#   ls_recursive('../boost_asio')
#   subsystem('ls -al')
    
#   print __file__ #current file path
#   print os.path.dirname(os.path.realpath(__file__)) #directory of this file
#
#   curr_dir=os.getcwd() #get current directory
#   os.chdir(curr_dir) #change current directory
#
#   print os.name

#   os.spawnl(os.P_NOWAIT, 'nohup sleep 3 && echo finished')
