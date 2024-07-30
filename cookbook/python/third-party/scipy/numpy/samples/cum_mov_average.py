import numpy as np

if __name__ == '__main__':

    N=3
    x=np.empty((N, 3))
    mean=np.empty(N, np.ndarray)

    x=np.array([1,2,3])
    mean[0]=x
    for i in range(1,3):
        x+=1
        mean[i]=(i*mean[i-1]+x)/(i+1)

    print(x)
    print(mean[N-1])
