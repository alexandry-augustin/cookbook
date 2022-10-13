import sys
import threading  
import time
#----------------------------------------------------------
#NOTE if this file name is: 'threading.py':
#Traceback (most recent call last):
#  File "threading.py", line 2, in <module>
#    import threading  
#  File "/home/aaugustin/data/sandbox/threading.py", line 7, in <module>
#    class base_00(threading.Thread):
#AttributeError: 'module' object has no attribute 'Thread'
#----------------------------------------------------------
#Thread Object:
#only override the __init__() and run() methods
#----------------------------------------------------------
#daemon: A boolean value indicating whether this thread is a daemon thread (True) or not (False).
#This must be set before start() is called, otherwise RuntimeError is raised.
#Its initial value is inherited from the creating thread;
#the main thread is not a daemon thread and therefore all threads created in the main thread default to daemon = False.
#The entire Python program exits when no alive non-daemon threads are left.
#----------------------------------------------------------
class base_00(threading.Thread):
  def __init__(self):
    threading.Thread.__init__ (self)
  def run(self):
    print 'sleeping'
    time.sleep(1)
    print 'awake'
#----------------------------------------------------------
class base_01(threading.Thread):
  def __init__(self):
    self.__quit=False
    threading.Thread.__init__ (self)
  def run(self):
    while not self.__quit:
      pass
  def set(self, quit):
    self.__quit=quit
#----------------------------------------------------------
def test_00():
  b_00=base_00()

  b_00.setDaemon(True)
  assert b_00.isDaemon()

  b_00.start() #invokes run() in a separate thread 
  #b_00.is_alive() #tests whether the thread is alive
  #b_00.join()

  #time.sleep(1)
  print 'exit'
#----------------------------------------------------------
def test_01():
  b_00=base_01()

  b_00.setDaemon(True)
  b_00.start()
  b_00.join()

  print 'exit'
#----------------------------------------------------------
if __name__ == '__main__':
  test_01()
