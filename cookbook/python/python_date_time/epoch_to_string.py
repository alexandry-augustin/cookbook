import sys
import time
import calendar
import datetime
#----------------------------------------------------------
#date +%s in ms
#----------------------------------------------------------
ratio=1

def to_string(timestamp):
  return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(timestamp))

def to_epoch(timestamp):
  return int(time.mktime(time.strptime(timestamp, '%d.%m.%Y %H:%M:%S'))*ratio)

if __name__=="__main__":
  if(len(sys.argv)!=2):
    print 'usage: \n\tepoc_to_string n'
    exit(1)

  if(len(sys.argv[1])==10+3):
    print "Assuming that this timestamp is in milliseconds (1/1,000 second):"
    ratio=1000
  if(len(sys.argv[1])==10+6):
    print "Assuming that this timestamp is in microseconds (1/1,000,000 second):"
    ratio=1000000
  if(len(sys.argv[1])==10+9):
    print "Assuming that this timestamp is in nanoseconds (1/1,000,000,000 second):"
    ratio=1000000000

  timestamp=int(sys.argv[1])/ratio
  print `timestamp`+'   =>   '+to_string(timestamp)
