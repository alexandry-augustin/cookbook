import thread
import time
import sys

def f_00(n):
	while True:
#sys.stdout.write('.')
		print('.')
		time.sleep(n)

if __name__ == '__main__':

	thread.start_new_thread(f_00, (1,))
	time.sleep(5)
