import pandas as pd

if __name__=='__main__':
#	headers = ['name', 'title', 'department', 'salary']
#	chicago = pd.read_csv('./datasets/city-of-chicago-salaries.csv',
#			header=False,
#			names=headers,
#			converters={'salary': lambda x: float(x.replace('$', ''))})

	data=pd.read_csv("../datasets/data.csv", sep=",")

	#print data.head()
	#print data.tail()
	#print data.describe()

	print data
	#print data.GroupId
	#print data[0:1] #5 first raws
	#print data["GroupId"]==6
	#print data[data["GroupId"]==6]
	#print data.ix[2:4, ["GroupId", "Name"]]

	#print data[["Name", "GroupId"]][(data["EmployeeId"] > 5) & (data["GroupId"] < 10)]
	#print data[(data["EmployeeId"] > 5) & (data["GroupId"] < 10)].GroupId

#	print data.groupby("GroupId").sum() #mean() median()
#	print data.GroupId.count() #number of items (including duplicates) - without NULL
#	print data.GroupId.size #number of items (including duplicates)
