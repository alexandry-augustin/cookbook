#http://stackoverflow.com/questions/3142705/is-there-a-websocket-client-implemented-for-python

#sudo pip install websocket-client

import websocket
import thread
import time

def on_message(ws, message):
	print message

def on_error(ws, error):
	print error

def on_close(ws):
	print "### closed ###"

#def on_open(ws):
#	def run(*args):
#		for i in range(30000):
#			time.sleep(1)
#			ws.send("Hello %d" % i)
#		time.sleep(1)
#		ws.close()
#		print "thread terminating..."
#	 thread.start_new_thread(run, ())
#
#def test_01():
#	websocket.enableTrace(True)
#	ws = websocket.WebSocketApp("ws://localhost:4025/",
#					on_message = on_message,
#					on_error = on_error,
#					on_close = on_close)
#	ws.on_open = on_open
#
#	ws.run_forever()

def test_00():
	ws=websocket.create_connection("ws://localhost:4025/")
	ws.send("abc")
	result=ws.recv()
	print result
	ws.close()


if __name__=='__main__':
	test_00()
