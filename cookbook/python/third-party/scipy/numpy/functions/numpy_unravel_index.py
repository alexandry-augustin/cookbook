import numpy as np

if __name__ == '__main__':

    a=np.arange(10,19)

    b=a.reshape((3,3))

    # convert the index '8' in the flatten array of 'b' (e.i. 'a' or b.flatten()), into the new coordinates 'b.shape'

    np.unravel_index(8, b.shape)

    #def unravel_idx(i, shape):
    #    a.flatten()

    y=np.arange(10,19).reshape((3,3))

    np.unravel_index(y.argmax(), y.shape)

    np.unravel_index(y.argmin(), y.shape)

    it = np.nditer(y, flags=['multi_index'])
    #it_min = None
    #while not it.finished:
    #    if y[it.multi_index]
    #    it.iternext()

    np.rollaxis(y,1)
