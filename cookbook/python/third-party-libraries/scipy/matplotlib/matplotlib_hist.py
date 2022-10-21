#https://bespokeblog.wordpress.com/2011/07/11/basic-data-plotting-with-matplotlib-part-3-histograms/
#----------------------------------------------------------
import matplotlib.pyplot as plt
import numpy as np
#----------------------------------------------------------
def fct_00():
	data=np.random.randint(0,2,100) #bernouli
	weights=np.ones_like(data, dtype=float)/len(data) #normalise histogram
	plt.hist(data, bins=2, weights=weights)

	print len(data)
	print np.ones_like(data)
	print weights
#----------------------------------------------------------
def fct_01():
#	data=([1,1,2,3,3,3,3,3,4,5.1])
	data=np.random.normal(size=1000)
	weights=np.ones_like(data, dtype=float)/len(data) #normalise histogram
	plt.hist(data, bins=100, weights=weights) #default: bins=10
#----------------------------------------------------------
def fct_02():
	#centered txticks
	data=np.random.normal(size=1000)

	(fig,ax)=plt.subplots()
	bins=range(4)
	ax.hist(data, bins=bins, align="right")
	ax.set_xticks(bins[:-1])
#----------------------------------------------------------
def fct_03():
	#http://stackoverflow.com/questions/6352740/matplotlib-label-each-bin
	data = np.random.randn(82)
	fig, ax = plt.subplots()
	counts, bins, patches = ax.hist(data, facecolor='yellow', edgecolor='gray')

	# Set the ticks to be at the edges of the bins.
	ax.set_xticks(bins)
	# Set the xaxis's tick labels to be formatted with 1 decimal place...
	from matplotlib.ticker import FormatStrFormatter
	ax.xaxis.set_major_formatter(FormatStrFormatter('%0.1f'))

	# Change the colors of bars at the edges...
	twentyfifth, seventyfifth = np.percentile(data, [25, 75])
	for patch, rightside, leftside in zip(patches, bins[1:], bins[:-1]):
	    if rightside < twentyfifth:
		patch.set_facecolor('green')
	    elif leftside > seventyfifth:
		patch.set_facecolor('red')

	# Label the raw counts and the percentages below the x-axis...
	bin_centers = 0.5 * np.diff(bins) + bins[:-1]
	for count, x in zip(counts, bin_centers):
	    # Label the raw counts
	    ax.annotate(str(count), xy=(x, 0), xycoords=('data', 'axes fraction'),
		xytext=(0, -18), textcoords='offset points', va='top', ha='center')

	    # Label the percentages
	    percent = '%0.0f%%' % (100 * float(count) / counts.sum())
	    ax.annotate(percent, xy=(x, 0), xycoords=('data', 'axes fraction'),
		xytext=(0, -32), textcoords='offset points', va='top', ha='center')

	# Give ourselves some more room at the bottom of the plot
	plt.subplots_adjust(bottom=0.15)
#----------------------------------------------------------
if __name__=='__main__':
#	x=np.random.dirichlet((1, 1, 1), 20)

	fct_03()
	plt.show()
