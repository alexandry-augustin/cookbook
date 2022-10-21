import numpy as np
from scipy.stats import multivariate_normal
import matplotlib.pyplot as plt

if __name__ == '__main__':

    x, y=np.mgrid[-1.0:1.0:30j, -1.0:1.0:30j]
    # Need an (N, 2) array of (x, y) pairs.
    xy=np.column_stack([x.flat, y.flat])

    mu=np.array([0.0, 0.0])
    sigma=np.array([.025, .025])
    covariance=np.diag(sigma**2)
    z=multivariate_normal.pdf(xy, mean=mu, cov=covariance)

    # Reshape back to a (30, 30) grid.
    z=z.reshape(x.shape)
    #--------------------------------------------------
    mu=[0.5, -0.2]
    sigma=[[2.0, 0.3], [0.3, 0.5]]
    f=multivariate_normal(mu, sigma)

    x,y=np.mgrid[-1:1:.01, -1:1:.01]
    pos=np.empty(x.shape + (2,))
    pos[:, :, 0]=x
    pos[:, :, 1]=y

    plt.contour(x, y, f.pdf(pos))
    plt.show()
