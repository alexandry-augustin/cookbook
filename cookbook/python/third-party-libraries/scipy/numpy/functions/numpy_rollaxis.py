import numpy as np

if __name__ == '__main__':

    x = np.empty((1,2,3,4))

    x = np.rollaxis(x, 1)

    print(x.shape)
