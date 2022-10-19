import numpy as np

if __name__=="__main__":
	x=np.arange(0,3,1)
	y=np.array([0, 1, 0])

	# Compute the area using the composite trapezoidal rule.
	area_00 = np.trapz(y, dx=10)
	area_01 = np.trapz(y, x=x)
	print("area =%f"%(2*area_01))
