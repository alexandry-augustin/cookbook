import socket

def test_00():
	soc=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	try:
		soc.connect(('localhost', 4025))
	except:
		print("can't connect to: localhost:4025")
		return
	soc.send('ping')
	print('[TX]', 'ping')
	data=soc.recv(1024)
	print('[RX]', data)

if __name__ == '__main__':
	test_00()
