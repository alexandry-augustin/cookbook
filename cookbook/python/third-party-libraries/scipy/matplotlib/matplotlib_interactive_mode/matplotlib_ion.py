""" 
	Interactive mode works with suitable backends in ipython and in the ordinary python shell, but it does not work in the IDLE IDE.
"""
import numpy as np
import matplotlib.pyplot as plt


if __name__=='__main__':
	plt.ioff()
	plt.ion()

