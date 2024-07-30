import numpy as np

# https://numpy.org/doc/stable/user/basics.indexing.html

if __name__ == '__main__':
    
    # 1D
    a=np.array([0,1,2,3,4])
    assert(a[1] == 1)
    assert(a[-1] == 4)
    assert(a[-2] == 3)

    #idx = np.array([0,4])
    # or
    idx = [0,4]
    assert(np.array_equal(a[idx], np.array([0,4])))

    # 2D

    # "So note that x[i, j] == x[i][j] 
    # though the second case is more inefficient as 
    # a new temporary array is created after the first 
    # index that is subsequently indexed by 2."
    # -- https://numpy.org/doc/stable/user/basics.indexing.html

    a=np.array([[1,2,3], 
                [4,5,6]]) 
    assert(a[1][1] == a[1, 1])
    assert(np.array_equal(a[1], np.array([4,5,6])))
    assert(np.array_equal(a[..., 1], np.array([2,5])))

    # From each row, a specific element is selected
    row_idx = [0,1]
    col_idx = [1,2]
    assert(np.array_equal(a[row_idx, col_idx], np.array([2,6])))
    assert(np.array_equal(a[row_idx, col_idx], 
                          np.array([a[row_idx[0],col_idx[0]], 
                                    a[row_idx[1],col_idx[1]]])))

    a[row_idx, col_idx] = np.array([-2, -6])
    assert(np.array_equal(a, np.array([[1,-2,3], [4,5,-6]])))