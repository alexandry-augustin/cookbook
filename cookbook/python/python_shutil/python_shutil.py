import shutil
#----------------------------------------------------------
def dir_tree_rm_(path):
    print("delete '"+path+"'?[y/n]")
    ret=sys.stdin.read(1)
    if(ret=='y' or ret=='Y'):
        # shutil.rmtree()   #delete empty/non-empty dir
        shutil.rmtree(path)
        return
    print('operation aborted')
#----------------------------------------------------------
if __name__ == ' __main__':
    pass
