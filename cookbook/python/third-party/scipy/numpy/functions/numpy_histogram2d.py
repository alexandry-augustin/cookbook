import numpy as np
import numpy.random
import matplotlib.pyplot as plt

if __name__ == '__main__':
	x = np.random.randn(8873)
	y = np.random.randn(8873)

	heatmap, xedges, yedges = np.histogram2d(x, y, bins=50)
	extent = [xedges[0], xedges[-1], yedges[0], yedges[-1]]

	plt.imshow(heatmap, extent=extent)
	plt.show()
