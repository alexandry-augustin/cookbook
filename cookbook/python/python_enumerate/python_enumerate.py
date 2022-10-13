import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
if __name__=='__main__':
#	seasons = ['Spring', 'Summer', 'Fall', 'Winter']
#	print list(enumerate(seasons))
#	print list(enumerate(seasons, start=1))

	elements = ('foo', 'bar', 'baz')
	for elem in elements:
		print elem
	for count, elem in enumerate(elements):
		print count, elem
