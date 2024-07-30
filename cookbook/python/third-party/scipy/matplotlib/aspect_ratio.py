import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
if __name__=='__main__':
	X = np.linspace(-6, 6, 1024)
	Y1, Y2 = np.sinc(X), np.cos(X)

	plt.figure(figsize=(10.24, 2.56))
	plt.plot(X, Y1, c='k', lw = 3.)
	plt.plot(X, Y2, c='.75', lw = 3.)
