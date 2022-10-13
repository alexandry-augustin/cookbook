import sys
import time
import calendar
import datetime
#----------------------------------------------------------
#date +%s in ms
#----------------------------------------------------------
def to_string(timestamp):
  return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(timestamp))

def to_epoch(timestamp):
  return int(time.mktime(time.strptime(timestamp, '%d.%m.%Y %H:%M:%S'))*1000000000)

if __name__=="__main__":
  if(len(sys.argv)!=2):
    print 'usage: \n\tstring_to_epoc 29.08.2011 11:05:02'
    exit(1)

  timestamp='29.08.2011 11:05:02'
  print timestamp+'   =>   '+`to_epoch(timestamp)`
