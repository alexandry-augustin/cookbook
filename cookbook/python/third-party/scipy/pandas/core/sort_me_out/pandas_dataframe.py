import pandas as pd
import numpy as np

if __name__ == '__main__':

	data = pd.read_csv("../datasets/cities.csv", sep=";")
	#--------------------------------------------------
	# get fields' header
	#--------------------------------------------------
	print(list(data.columns.values))
	#--------------------------------------------------
	# print list(data.columns.values) # get column names
	#--------------------------------------------------
	# unique
	#--------------------------------------------------
	print(data.Inhabitants.unique()) # array of unique values
	print(data.Inhabitants.nunique()) # number of unique elements
	#--------------------------------------------------
	# remove constant columns
	#--------------------------------------------------
	# print(data.loc[:, (data!=data.ix[0]).any()]) # FIXME .ix is deprecated https://stackoverflow.com/questions/59991397/attributeerror-dataframe-object-has-no-attribute-ix
	print(data.loc[:, data.apply(pd.Series.nunique)!=1])

#	print(data)
#	print(data["City"])

#	print(data.mean())
#	print(data.std() # unbiased: =1/(n-1)*sum())

#	print(data.City)
#	print(data.City.value_counts()) #return list of unique element with their frequency
#	print(np.unique(data.City.values))
	#--------------------------------------------------
	# Apply to each element
	#--------------------------------------------------
	df = pd.DataFrame({ "A": [1, 2] })
	df["A"] = df["A"].apply(np.sqrt)

	df = pd.DataFrame({"A":[1.398, 2.857]})
	df["A"] = df["A"].apply(lambda x: float("%.1f"%x))
	#--------------------------------------------------
	# as_matrix()
	#--------------------------------------------------
	# print data.as_matrix()
	#--------------------------------------------------
	# append new row
	#--------------------------------------------------
	df = pd.DataFrame([[1, 2], [3, 4]], columns=[ 'A', 'B' ])
	df2 = pd.DataFrame([[5, 6], [7, 8]], columns=[ 'A', 'B' ])
	df = df.append(df2)
	#print df
	# A  B
	# 1  2
	# 3  4
	# 5  6
	# 7  8
	# pd.concate([df, df2])
	#--------------------------------------------------
	# append new column
	#--------------------------------------------------
	df = pd.DataFrame([[1, 2], [3, 4]], columns=[ 'A', 'B' ])
	df["A-B"] = pd.DataFrame(df["B"]-df["A"])
	print(df)
	# pd.concate([df, df2], axis=1)
	#--------------------------------------------------
	# check if column exist
	#--------------------------------------------------
	if 'A' in df.columns:
	# or
	#if 'A' in df:
		pass