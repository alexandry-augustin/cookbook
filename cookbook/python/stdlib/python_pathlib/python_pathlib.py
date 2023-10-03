from pathlib import Path

def ls(path):
    return [x for x in path.iterdir() ]

def lsd(path):
    return [ x for x in path.iterdir() if x.is_dir() ]

def lsf(path):
    return [ x for x in path.iterdir() if x.is_file() ]

if __name__ == '__main__':

    # path/stem.suffix[es]

    # path = Path('/', 'tmp')
    path = Path('.')
    files = ls(path)
    # print(files)

    for p in path.rglob("*"):
        # print(p.stem)
        print(p.with_suffix(''))
        # print(p.name)
        print(p.parts) # split path
