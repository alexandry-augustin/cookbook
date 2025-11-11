#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(char* msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("usage: %s [port]\n", argv[0]);
		exit(1);
	}
	const int port=atoi(argv[1]);
	int sock_desc_00;
	int sock_desc_01;

	char buffer[256];
	memset(&buffer, 0, 256);
	{
		sock_desc_00=socket(AF_INET,SOCK_STREAM,0);
		assert(sock_desc_00>=0);
		//-----------------------------------------
		struct sockaddr_in socket_info;
		socket_info.sin_family=AF_INET;
		socket_info.sin_addr.s_addr=htonl(INADDR_ANY);
		socket_info.sin_port=htons(port);
		//-----------------------------------------
		assert(bind(sock_desc_00, (struct sockaddr*)&socket_info, sizeof(socket_info))>=0);
		//-----------------------------------------
		listen(sock_desc_00, 1);
		//-----------------------------------------
		sock_desc_01=accept(sock_desc_00, 0, 0);
		assert(sock_desc_01>=0);
		printf("listening on %s:%d\n", "0.0.0.0", port);
		//-----------------------------------------
		close(sock_desc_00);
		//-----------------------------------------
		int n;
		while(1)
		{
			n=recv(sock_desc_01, buffer, sizeof(buffer), 0);
			if(n==0)
				exit(0);
			buffer[n]=NULL;
			printf("[RX][%d][%s]\n", n, buffer);
		}
	}
	{
//		sock_desc_00=socket(AF_INET, SOCK_STREAM, 0);
//		if(sock_desc_00<0) 
//			error("ERROR opening socket");
//		//-----------------------------------------
//		struct sockaddr_in serv_addr;
//		memset(&serv_addr, 0, sizeof(serv_addr)); 
//		serv_addr.sin_family=AF_INET;
//		serv_addr.sin_addr.s_addr=INADDR_ANY;
//		serv_addr.sin_port=htons(port);
//		if(bind(sock_desc_00, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0) 
//			error("ERROR on binding");
//		//-----------------------------------------
//		listen(sock_desc_00, 5);
//		struct sockaddr_in cli_addr;
//		int clilen=sizeof(cli_addr);
//		sock_desc_01=accept(sock_desc_00, (struct sockaddr*)&cli_addr, &clilen);
//		if(sock_desc_01<0)
//			error("ERROR on accept");
//		//-----------------------------------------
//		int n=read(sock_desc_01, buffer, 255);
//		if(n<0)
//			error("ERROR reading from socket");
//		printf("%s\n", buffer);
//		//-----------------------------------------
//		n=write(sock_desc_01, "I got your message", 18);
//		if(n<0)
//			error("ERROR writing to socket");
	}
	return 0; 
}
