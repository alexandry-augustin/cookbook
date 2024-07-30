"""
	"o"	dots
	"-"	line

	markersize=10
"""
#----------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
def f(t):
    return np.exp(-t) * np.cos(2*np.pi*t)
#----------------------------------------------------------
def f_00():
	""" misc """
	y=[1,2,2,1]
	x=[0,1,2,3]

	#plt.plot(y)
	plt.plot(x, y, 'b-', linewidth=3, color="#000000", linestyle='--') #default: linewidth=1

	plt.axis([0, 3, 0, 4]) #[xmin, xmax, ymin, ymax]
	plt.title('Title')
	plt.ylabel(r'$\sigma_i$') #matplotlib accepts TeX equation expressions in any text expression
	plt.xlabel('X')
	plt.xlim([0, 3])
	plt.ylim([0, 3])

#	xmin, xmax, ymin, ymax = plt.axis()
#	plt.axis((xmin, xmax, ymin, ymax))

	ax = plt.gca()
	xmin, xmax, ymin, ymax = ax.axis()
	ax.set_xlim([xmin, xmax])
	ax.set_ylim([ymin, ymax])

#----------------------------------------------------------
def aspect_ratio():
	(fig, ax)=plt.subplots()
	ax.set_aspect(1./(2*ax.get_data_ratio()))
	fig.tight_layout()
#----------------------------------------------------------
def f_01():
	""" multiple functions on same figure """
	t=np.arange(0., 5., 0.2)
	plt.plot(t, t, 'r--', t, t**2, 'bs', t, t**3, 'g^')
#----------------------------------------------------------
def f_02():
	""" multiple figures """
	t1=np.arange(0.0, 5.0, 0.1)
	t2=np.arange(0.0, 5.0, 0.02)

	fig=plt.figure(1)
	fig.suptitle('test title', fontsize=20)

	plt.subplot(211)
	plt.plot(t1, f(t1), 'bo', t2, f(t2), 'k')

	plt.subplot(212)
	plt.plot(t2, np.cos(2*np.pi*t2), 'r--')
#----------------------------------------------------------
def f_03():
	data=f(np.arange(0.0, 5.0, 0.02))	
	data=np.column_stack((data, np.cos(2*np.pi*np.arange(0.0, 5.0, 0.02))))
	plt.plot(data)
#----------------------------------------------------------
def f_04():
	""" arbitrary function """
	#x=np.arange(-20,20, .5)
	x=np.arange(0,1, .1)
	y=[(lambda z: 0 if z==1.0 else z/(1.0-z))(i) for i in x]

	plt.plot(x, y)
#----------------------------------------------------------
if __name__=='__main__':
	aspect_ratio()
	plt.show()
