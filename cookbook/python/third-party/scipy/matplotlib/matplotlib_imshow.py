import numpy as np
import matplotlib.pyplot as plt
# from scipy.misc import imread
import matplotlib.image as mpimg

if __name__=='__main__':

    np.random.seed(0)

    # x=np.random.uniform(0.0,10.0,15)
    # y=np.random.uniform(0.0,10.0,15)

    path = '../../../../../res/lena.bmp'
    img=mpimg.imread(path)

    # plt.scatter(x,y,zorder=1)
    plt.imshow(img,zorder=0)
    plt.show()
