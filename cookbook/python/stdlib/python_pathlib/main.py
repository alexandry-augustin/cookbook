from pathlib import Path

def ls(path):
    return [x for x in path.iterdir() ]

def lsd(path):
    return [ x for x in path.iterdir() if x.is_dir() ]

def lsf(path):
    return [ x for x in path.iterdir() if x.is_file() ]

def test_00():

    path = Path('/')
    path = path / 'tmp'

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

def test_01():
    
    path = Path("/", "path", "to", "a.b.c")
    # path = Path("/")
    # path = path / "path" / "to" / "a.b.c"

    assert(path.root == "/")
    # path.parent
    # list(path.parents)
    # path.parts
    assert(path.name == "a.b.c")
    assert(path.stem == "a.b")
    assert(path.suffix == ".c")


if __name__ == '__main__':

    # test_00()
    test_01()
