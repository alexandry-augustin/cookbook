import argparse

if __name__ == '__main__':

	parser = argparse.ArgumentParser()

	# required parameter
	parser.add_argument('m')
	
	# optional parameter
	parser.add_argument('--n',
		help='some integer', 
		type=int,
		default=9)
	
	args = parser.parse_args()
	
	print(args.m)
	print(args.n)

	# python python_argparse.py 3 --n 5
