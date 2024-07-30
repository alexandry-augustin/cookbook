import numpy as np

# https://stackoverflow.com/questions/31145413/what-is-the-default-value-of-j-in-ijk-numpy-slicing

if __name__ == '__main__':
    
    # 1D
    a=np.array([0,1,2,3,4])
    
    assert(np.array_equal(a[:], a))
    assert(np.array_equal(a[0:1], [0]))
    assert(np.array_equal(a[0:2], [0, 1]))
    assert(np.array_equal(a[1:-1], [1, 2, 3]))

    assert(np.array_equal(a[::2], [0, 2, 4]))
    assert(np.array_equal(a[-1:0:-1], [4, 3, 2, 1]))
    assert(np.array_equal(a[::-1], [4, 3, 2, 1, 0]))

    # slice() object
    a=np.array([0,1,2,3,4])
    assert(np.array_equal(a, a[slice(None, None, 1)]))

    # 2D
    a=np.array([[1,2,3], 
                [4,5,6]])
    assert(np.array_equal(a[:,:], a))
    assert(np.array_equal(a[:,1], [2,5]))
    assert(np.array_equal(a[1,:], [4,5,6]))
    
    a=np.array([[1,2,3],
                [4,5,6]])
    last_row = a[a.shape[0]-1,:]
    assert(np.array_equal(last_row, np.array([4,5,6])))
    
    last_row[2]=9 # this modifies a
    assert(np.array_equal(a[a.shape[0]-1,:], np.array([4,5,9])))

    a=np.array([[1,2,3], 
                [4,5,6],
                [7,8,9]])
    assert(np.array_equal(a[1:, 1:], np.array([[5,6], [8,9]])))

    # modify sub array
    a[1:, 1:] = np.array([[1,0], [0,1]])
    assert(np.array_equal(a, np.array([[1,2,3], [4,1,0], [7,0,1]])))
