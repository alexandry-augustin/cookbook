import pandas as pd

if __name__ == '__main__':
	data=pd.read_csv("../datasets/data.csv", sep=",")
	print data.to_html()

	f=open("out.html", "w")
	f.write(data.to_html())
