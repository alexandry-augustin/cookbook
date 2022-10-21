import csv
#----------------------------------------------------------
def f_00():
	"""
		read
	"""
	with open('input.csv', 'rb') as csvfile:
		reader=csv.reader(csvfile, delimiter=',', quotechar='|')
		for row in reader: #row is always of type string
#			print ', '.join(row)
			print row
#----------------------------------------------------------
def f_01():
	"""
		read
	"""
	with open('input.csv', 'rb') as csvfile:
		reader=csv.reader(csvfile, delimiter=',', quotechar='|')
		#next(reader, None) #skip header
		row=reader.next()
		print row
		row=reader.next()
		print row
		for row in reader:
			print row
#----------------------------------------------------------
if __name__ == '__main__':
	f_00()
