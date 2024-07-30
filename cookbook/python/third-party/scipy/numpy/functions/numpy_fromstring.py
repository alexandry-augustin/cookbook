import numpy as np

if __name__ == '__main__':

    a = '1,2,3'
    a = np.fromstring(a, dtype=int, sep=',')
    assert(np.array_equal(a, np.array([1, 2, 3])))