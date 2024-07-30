"""
	http://stackoverflow.com/questions/14324477/bold-font-weight-for-latex-axes-label-in-matplotlib
"""
#----------------------------------------------------------
import matplotlib
import matplotlib.pyplot as plt
#----------------------------------------------------------
if __name__=='__main__':
	matplotlib.rc('text', usetex=True)
	matplotlib.rcParams['text.latex.preamble']=[r"\usepackage{amsmath}"] #for \boldsymbol

	plt.title(r"$\boldsymbol{\kappa}$", fontsize=16)
	plt.plot(range(10))
	plt.show()
