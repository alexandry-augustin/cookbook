import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
def f_00():
	x=[0,1,2,3]
	y=[1,2,2,1]

	(fig, ax)=plt.subplots()

	#frame customization
	ax.spines['right'].set_color('none')
	ax.spines['top'].set_color('none')
#	ax.xaxis.set_ticks_position('bottom')
#	ax.yaxis.set_ticks_position('left')
	plt.tick_params(axis='x',		# changes apply to the x-axis
			which='both',		# both major and minor ticks are affected
			bottom='on',		# ticks along the bottom edge are off
			top='off',		# ticks along the top edge are off
			labelbottom='on',	# labels along the bottom edge are off
			direction='out'
			)
	plt.tick_params(axis='y',		# changes apply to the x-axis
			which='both',		# both major and minor ticks are affected
			left='on',		# ticks along the bottom edge are off
			right='off',		# ticks along the top edge are off
			labelleft='on',		# labels along the bottom edge are off
			direction='out'
			)
#	ax.tick_params(axis='both', direction='out', width=2, length=8,
#			labelsize=12, pad=8)
#	ax.spines['left'].set_linewidth(2)
#	ax.spines['bottom'].set_linewidth(2)

	plt.ylabel('y')
	plt.xlabel('x')
	


	plt.plot(y)
#----------------------------------------------------------
if __name__=='__main__':
	f_00()
	plt.show()
