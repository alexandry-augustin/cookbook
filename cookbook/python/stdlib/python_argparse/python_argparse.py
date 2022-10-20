import argparse

if __name__=='__main__':
	parser = argparse.ArgumentParser()
#	parser.add_argument("m") # required param
	parser.add_argument("--n",
			help="some integer", 
			type=int,
			default=9) # optional
	args = parser.parse_args()
	print args.n
