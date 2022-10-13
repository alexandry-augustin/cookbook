# -*- coding: utf-8 -*-
import codecs

"""
	http://softwareengineering.stackexchange.com/questions/168635/what-does-the-python-codecs-module-do

	out_file = open('example.txt', 'w')
	is actually opening the file for writing using the ascii codec implicitly. If you want to specify another codec, you need to either use the encoding parameter of the open function in Python 3.x:
	
	out_file = open('example.txt', 'a', 'utf-8')
	or if you are still using Python 2.x (the latest is Python 2.7.3 at the time of this writing), you need to use the functions from the codecs module:
	
	out_file = codecs.open('example.txt', 'a', 'utf-8')
	since open in Python 2.x doesn't allow you to specify an encoding (you can use it to read the byte stream into a byte string in memory though, and then decode that string).
"""
if __name__=="__main__":
	f=codecs.open("utf8_in", 'w', encoding='utf-8') # f is in unicode
	# The Python-specific encoding unicode_escape is a dummy encoding that converts all
	# non-ASCII characters into their \uXXXX representations. Code points above the ASCII
	# 0–127 range but below 256 are represented in the two-digit form \xXX.
 	for line in f:
		line = line.strip()
		print line.encode('unicode_escape')
