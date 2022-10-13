import dateutil.parser
#----------------------------------------------------------
# sudo pip install python-dateutil
#----------------------------------------------------------
if __name__=='__main__':
	date=dateutil.parser.parse('2010-05-08T23:41:54.000Z') #iso 8601
	print date
