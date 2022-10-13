#http://popdevelop.com/2010/03/a-minimal-python-websocket-server/

import socket

if __name__=='__main__':
	port=4025
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) #reuse port
	sock.bind(("", port))
	sock.listen(5)
	 
	handshake = '\
	HTTP/1.1 101 Web Socket Protocol Handshake\r\n\
	Upgrade: WebSocket\r\n\
	Connection: Upgrade\r\n\
	WebSocket-Origin: http://localhost:8888\r\n\
	WebSocket-Location: ws://localhost:9999/\r\n\r\n\
	'
#GET / HTTP/1.1
#Upgrade: websocket
#Connection: Upgrade
#Host: localhost:4025
#Origin: http://localhost:4025
#Sec-WebSocket-Key: XLCDWHkTTj6Nk74BcWPeYw==
#Sec-WebSocket-Version: 13
#

#	import sys
     
	data = ''
	header = ''
	handshaken = False
	print('listening on 0.0.0.0:',port)
	client, address = sock.accept()
	while True:
	    if handshaken == False:
		header += client.recv(16)
		print(header)
		if header.find('\r\n\r\n') != -1:
			data = header.split('\r\n\r\n', 1)[1]
			handshaken = True
			client.send(handshake)
		else:
			tmp = client.recv(128)
#			print(data)
			data += tmp;
		     
			validated = []
				 
			msgs = data.split('\xff')
			data = msgs.pop()
	 
			for msg in msgs:
				if msg[0] == '\x00':
					validated.append(msg[1:])
	 
			for v in validated:
				print v
				client.send('\x00' + v + '\xff')
