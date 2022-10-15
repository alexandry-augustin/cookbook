#!/usr/bin/env python
# -*- coding: utf-8 -*-

# see python_codes/
# https://nedbatchelder.com/text/unipain.html

# see python_codes

if __name__=='__main__':

	print u'\u0420\u043e\u0441\u0441\u0438\u044f' #Unicode string literal 
	print "Россия" # assums a default encoding of the Unicode character, namely ASCII.

	import sys
	print sys.getdefaultencoding() #ascii

	#equality
	a1= u'\xeatre'
	a2= u'e\u0302tre'
	print(a1)
	print(a2)
	assert(a1 != a2) #)a1 and a2 are equivalent but not equal:
	import unicodedata as ud
	assert(ud.normalize('NFC', a1) == ud.normalize('NFC', a2))

	#disable casting str->unicode
#	import sys
#	sys.setdefaultencoding('undefined')
#	"foo" + u"bar"
