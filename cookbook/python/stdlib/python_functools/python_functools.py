# cf boost::bind
import functools

def f_00(n):
    return n

def f_01(n,m):
    return n-m

if __name__ == '__main__':

    f=functools.partial(f_00, 5)
    assert(f()==5)

    f=functools.partial(f_01, 5)
    assert(f(4)==1)

    f=functools.partial(f_01, m=5)
    assert(f(4)==-1)
