"""
	Bar chart
"""
#----------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
def plot_00():
	values=[1,2,3]
	stds=[.5, .5, .5]
	bins=[1,2,3]
	#bins=["a","b","c"]
	plt.bar(bins, values, width=1.0, yerr=stds, ecolor='g', color="#AAAAAA") #default width=.8
#----------------------------------------------------------
def plot_01():
	n = 12
	X = np.arange(n)
	Y1 = (1-X/float(n)) * np.random.uniform(0.5,1.0,n)
	Y2 = (1-X/float(n)) * np.random.uniform(0.5,1.0,n)

	plt.bar(X, +Y1, facecolor='#9999ff', edgecolor='white')
	plt.bar(X, -Y2, facecolor='#ff9999', edgecolor='white')

	for x,y in zip(X,Y1):
	    plt.text(x+0.4, y+0.05, '%.2f' % y, ha='center', va= 'bottom')

	plt.ylim(-1.25,+1.25)
#----------------------------------------------------------
def plot_02():
	means   = [26.82,26.4,61.17,61.55]         # Mean Data 
	stds    = [4.59,4.39,4.37,4.38]            # Standard deviation Data
	peakval = ['26.82','26.4','61.17','61.55'] # String array of means

	ind = np.arange(len(means))
	width = 0.35
	colours = ['red','blue','green','yellow']

	plt.figure()
	plt.title('Average Age')
	for i in range(len(means)):
		plt.bar(ind[i],means[i],width,color=colours[i],align='center',yerr=stds[i],ecolor='k')
	plt.ylabel('Age (years)')
	plt.xticks(ind,('Young Male','Young Female','Elderly Male','Elderly Female'))

	def autolabel(bars,peakval):
	    for ii,bar in enumerate(bars):
		height = bars[ii]
		plt.text(ind[ii], height-5, '%s'% (peakval[ii]), ha='center', va='bottom')
	autolabel(means,peakval)    
#----------------------------------------------------------
if __name__=='__main__':
	plot_00()
	#--------------------------------------------------
	plt.show()
