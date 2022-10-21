import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
#----------------------------------------------------------
if __name__ == '__main__':
	nb_samples=1000
	data = pd.Series(np.random.normal(size=nb_samples))

#	full_std = np.std(data)
	mean=pd.expanding_mean(data, 1)
	std=pd.expanding_std(data, min_periods=1)

	fig, ax = plt.subplots()
	mean.plot(ax=ax, color='b', linewidth=1.5, label='Expanded Mean')
#	std.plot(ax=ax, color='k', linewidth=1.5, label='Expanded Std. Dev.')
	ax.axhline(y=0, color='g', label='True Mean')
	ax.fill_between(np.arange(nb_samples), mean+std, mean-std, color="#dddddd")
	ax.legend()

	plt.show()
