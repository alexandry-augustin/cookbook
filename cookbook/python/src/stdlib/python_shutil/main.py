import sys
import shutil

def dir_tree_rm_(path):
    print(f"delete '{path}'?[y/n]")
    ret=sys.stdin.read(1)
    if(ret=='y' or ret=='Y'):
        # shutil.rmtree()   #delete empty/non-empty dir
        shutil.rmtree(path)
        return
    print('operation aborted')

if __name__ == '__main__':
    
    # 1. Copy an entire directory to a new location 
    # shutil.copytree('source_dir', 'backup_dir', dirs_exist_ok=False)

    # 2. Move a file to a new location (also renaming it) 
    # shutil.move('source_dir/filel.txt', 'backup_dir/renamed_filel.txt')

    # 3. Create a compressed ZIP archive of the backup directory 
    # shutil.make_archive('backup_archive', 'zip', 'backup_dir')

    # 4. Extract the ZIP archive to a new directory 
    # shutil.unpack_archive('backup_archive.zip', 'extracted_backup')

    usage = shutil.disk_usage('.')
    print(f"Disk usage - Total: {usage.total}, Used: {usage.used}, Free: {usage.free}")