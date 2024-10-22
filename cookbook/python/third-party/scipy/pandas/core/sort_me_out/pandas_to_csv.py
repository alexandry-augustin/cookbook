import pandas as pd

if __name__ == '__main__':

	data = pd.read_csv('../datasets/data.csv', sep=',') #, dtype={'rating': np.float32}
	data.to_csv('out/out.csv', sep=',', index=False)#, columns=['']) # no write row index/name
