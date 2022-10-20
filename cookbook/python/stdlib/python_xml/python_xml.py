import xml.dom.minidom
#----------------------------------------------------------
# xml need a single root element
#----------------------------------------------------------
if __name__=='__main__':
	dom=xml.dom.minidom.parse("in.xml")
#	print dom.toxml()

	dom=xml.dom.minidom.parseString("<root>\
<section>\
<value1>50</value1>\
<value2>text</value2>\
</section>\
<section>\
<value1>50</value1>\
<value2>text</value2>\
</section>\
</root>")
#	print dom.toxml()

#	print dom.childNodes[1]

	for node in dom.getElementsByTagName('section'):
		print node.toxml()
		print node.firstChild.nodeValue
