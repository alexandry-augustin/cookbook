#http://matplotlib.org/examples/lines_bars_and_markers/marker_reference.html
#http://stackoverflow.com/questions/13091649/unique-plot-marker-for-each-plot-in-matplotlib
import numpy as np
import matplotlib.pyplot as plt
import itertools

x = np.linspace(0,2,10)
y = np.sin(x)

marker = itertools.cycle((',', '+', '.', 'o', '*')) 

fig = plt.figure()
ax = fig.add_subplot(111)

for q,p in zip(x,y):
    ax.plot(q,p, linestyle = '', marker=marker.next())

plt.show()
