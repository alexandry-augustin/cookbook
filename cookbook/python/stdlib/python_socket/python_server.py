import socket

def test_00():
	soc=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	soc.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) #reuse port
	port=4025
	soc.bind(('', port))
	print('listening on 0.0.0.0:',port)
	soc.listen(3)
	while 1:
		conn, add=soc.accept()
		while 1:
			data=conn.recv(1024)
			print(data)
			#print('[RX]', data) #messes up the printing...
			if not data:
				break
			conn.send('pong')
			print('[TX]', 'pong')
		conn.close()

if __name__ == '__main__':
	test_00()
