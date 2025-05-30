import os

if __name__ == '__main__':

	print(__file__)
	path=os.path.realpath(__file__)
	print(path)

	basename = os.path.basename(path) # filename (with extension)
	print(basename)
	print(os.path.splitext(basename)[0]) # filename (without extension). split only last dot
	assert(os.path.splitext('a.out.r') == ('a.out', '.r'))
	
	print(os.path.dirname(path)) # path to file
	assert(os.path.split('/path/to/file.txt') == ('/path/to', 'file.txt'))
	
	path_ = os.path.normpath('/path/to////file.txt')
	assert(path_.split(os.sep) == ('', 'path', 'to', 'file.txt'))
	
	print(os.path.exists(path))
	print(os.path.isfile(path))
	print(os.path.isdir(path))

	print(os.path.join(path, "test"))
	print(os.path.join("./dir/", "filename"))
