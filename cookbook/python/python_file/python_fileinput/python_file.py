import fileinput

#http://stackoverflow.com/questions/5914627/append-line-to-beginning-of-a-file

def line_prepender(filename, line):
	with open(filename,'r+') as f:
		content=f.read()
		f.seek(0, 0)
		f.write(line.rstrip('\r\n')+'\n'+content)

def line_pre_adder(filename, line_to_prepend):
	f = fileinput.input(filename, inplace=1)
	for xline in f:
		if f.isfirstline():
			print line_to_prepend.rstrip('\r\n')+'\n'+xline,
		else:
			print xline,

def prepend_(filename, l):
	for line in reversed(l):
		line_prepender(filename, line)

if __name__=='__main__':
	file_object=open('file', 'w')	#create the file, if file exists, truncates it
	file_object.write('a\n');
	file_object.close()
	#--------------------------------------------------
	file_object=open('file', 'a') #append
	file_object.write('b\n');
	file_object.write('c\n');
	file_object.close()
	#--------------------------------------------------
	file_object=open('file', 'r') #r is the default
	line=file_object.readline() #return empty string if nothing more to read
	assert(line=='a\n')
	line=file_object.readline()
	assert(line=='b\n')
	line=file_object.readline()
	assert(line=='c\n')
	assert(file_object.readline()=="") #end of file
	lines=file_object.readlines()
	assert(len(lines)==0)
	file_object.close()
	#--------------------------------------------------
	import os
	file_name=os.path.join("/",  "fooo")
	#--------------------------------------------------
#	try:
#	open(readonly_file_name, 'a')
#	except IOError:
#		pass
	#--------------------------------------------------
	line_prepender('file', '===')
#	line_pre_adder('file', '......')

#	save file to list
	with open('file') as f:
		lines=f.read().splitlines()
#	save list to file
	file_object=open('file', 'w')
	for line in lines:
		file_object.write('%s\n' % line)
	file_object.close()
