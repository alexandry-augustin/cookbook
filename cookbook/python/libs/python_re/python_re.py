import re

if __name__=='__main__':
	regex=re.compile("\.py")
	assert(regex.search("asdasd.py"))

	regex=".*"+re.escape("*te.*st")+".*"
	assert(re.match(regex, "_*te.*st_"))

	# bool(regex.search(...)) #to force True/False
