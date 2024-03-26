import csv

def read_00():

	with open('input.csv', 'r') as csvfile:

		reader = csv.reader(csvfile, delimiter=',', quotechar='|')

		for row in reader: 
			# `row` is always of type string

#			print(', '.join(row))
			print(row)

def read_01():

	with open('input.csv', 'r') as csvfile:

		reader = csv.reader(csvfile, delimiter=',', quotechar='|')

		# For python 2.x, use reader.next() instead of next(reader)
		header = next(reader, None)
		print(header)
		row = next(reader)
		print(row)
		row = next(reader)
		print(row)
		for row in reader:
			print(row)

def write():

	with open('output.csv', 'w') as csvfile:

		writer = csv.writer(csvfile, delimiter=';', quotechar='|')

		writer.writerow(['First row', 'Foo', 'Bar', 'Baz'])
		writer.writerow(['Second row', 'A', 'B', 'C', '"Testing"', 'Here\'s a quote'])

if __name__ == '__main__':
	write()
