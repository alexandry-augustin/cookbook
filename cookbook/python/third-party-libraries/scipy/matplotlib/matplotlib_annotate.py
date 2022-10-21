#http://stackoverflow.com/questions/9074996/matplotlib-how-to-annotate-point-on-a-scatter-automatically-placed-arrow
#----------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
def fct_00():
	x, y = np.random.random((2,500))

	fig, ax = plt.subplots()
	ax.plot(x, y, 'bo')

	# The key option here is `bbox`. I'm just going a bit crazy with it.
	ax.annotate('Something', xy=(x[0], y[0]), xytext=(-20,20), 
		    textcoords='offset points', ha='center', va='bottom',
		    bbox=dict(boxstyle='round,pad=0.2', fc='yellow', alpha=0.3),
		    arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=0.5', 
				    color='black'))
#----------------------------------------------------------
def fct_01():
	fig = plt.figure()
	ax = fig.add_subplot(111)
	ax.set_ylim(-2,2)
	ax.set_xlim(0,5)
	ax.annotate('text'
		, xy=(2, 1)		#location being annotated
		, xytext=(3, 1.5) 	#location of the text 
#		, arrowprops=dict(facecolor='black', shrink=0.05)
            )
#----------------------------------------------------------
if __name__=="__main__":
	np.random.seed(1)
	fct_01()
	plt.show()
