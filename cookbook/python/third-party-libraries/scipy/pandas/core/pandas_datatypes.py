import pandas as pd

if __name__=='__main__':
	a = [['a', '1.2', '4.2'], ['b', '70', '0.03'], ['x', '5', '0']]
	df = pd.DataFrame(a, columns=['one', 'two', 'three'])
	print df
	print df.dtypes
	df[['two', 'three']] = df[['two', 'three']].astype(float)
	print df.dtypes
