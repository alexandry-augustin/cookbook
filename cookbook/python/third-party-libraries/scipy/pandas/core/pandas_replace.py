import pandas as pd

if __name__=='__main__':
	df = pd.DataFrame({1: [2,3,4], 2: [2,4,5]})
	print df
	print df[2]
	print df[2].replace(4, 17)
	print df[2].replace(4, 17, inplace=True)
	print df

	print df.replace(2, 0)

	#print df.replace(r'\s+', np.nan, regex=True)
