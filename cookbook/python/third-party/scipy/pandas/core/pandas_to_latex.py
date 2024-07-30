import pandas as pd

if __name__ == '__main__':
	data=pd.read_csv("../datasets/data.csv", sep=",")
	print data.to_latex()

	f=open("out.tex", "w")
	f.write(data.to_latex(index=False, longtable=True)) #no row index
