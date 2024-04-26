import time
import calendar
import datetime

def epoch():

	print(int(time.time())) #current epoch time
	print(time.strftime('%d.%m.%Y %H:%M:%S', time.localtime(1347517370)))
	print(int(time.mktime(time.strptime('29.08.2011 11:05:02', '%d.%m.%Y %H:%M:%S'))))

def misc():

	time.time() #Number of ticks since 12:00am, January 1, 1970 (epoch)
	time.localtime(time.time())
	time.asctime(time.localtime(time.time()))
	calendar.month(2008, 1)

#http://www.saltycrane.com/blog/2008/06/how-to-get-current-date-and-time-in/

	now = datetime.datetime.now()
	print()
	print('Current date and time using str method of datetime object:')
	print(str(now))
	print()
	print('Current date and time using instance attributes:')
	print('Current year: %d' % now.year)
	print('Current month: %d' % now.month)
	print('Current day: %d' % now.day)
	print('Current hour: %d' % now.hour)
	print('Current minute: %d' % now.minute)
	print('Current second: %d' % now.second)
	print('Current microsecond: %d' % now.microsecond)
	print()
	print('Current date and time using strftime:')
	print(now.strftime('%Y-%m-%d %H:%M'))

	print('sleeping')
	time.sleep(1) #in sec
	print('waking')

if __name__=='__main__':
	
	misc()
	epoch()
