#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(char* msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("usage: %s [ip] [port]\n", argv[0]);
		exit(1);
	}
	//const char host_name[]="localhost";
	char ip[16];
	strcpy(ip, argv[1]);
	int port=atoi(argv[2]);
	int sock_desc_00;

	char buffer[256];
	memset(&buffer, 0, 256);
	{
		sock_desc_00=socket(AF_INET, SOCK_STREAM, 0);
		assert(sock_desc_00>=0);
		//-----------------------------------------
		struct sockaddr_in socket_info;
		socket_info.sin_family=AF_INET;
		socket_info.sin_addr.s_addr=inet_addr(ip);
		socket_info.sin_port=htons(port);
		//-----------------------------------------
		printf("connecting to %s:%d\n", ip, port);
		assert(connect(sock_desc_00, (struct sockaddr*)&socket_info, sizeof(socket_info))==0);
		//-----------------------------------------
		char msg[]="abc";
		int n;
		while(1)
		{
			//n=write(sock_desc_00, msg, strlen(msg), 0);
			//or
			n=send(sock_desc_00, msg, strlen(msg), 0);
			assert(n>=0);
			printf("[TX][%d][%s]\n", n, msg);
			sleep(2);
		}
	}
	{
//		sock_desc_00=socket(AF_INET, SOCK_STREAM, 0);
//		if(sock_desc_00<0)
//			error("ERROR opening socket");
//		//-----------------------------------------
//		struct hostent* server=gethostbyname(host_name);
//		if(server==NULL)
//			error("ERROR, no such host");
//
//		struct sockaddr_in serv_addr;
//		memset(&serv_addr, 0, sizeof(serv_addr));
//
//		serv_addr.sin_family=AF_INET;
//		memcpy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
//		serv_addr.sin_port=htons(port);
//		//-----------------------------------------
//		if(connect(sock_desc_00, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
//			error("ERROR connecting");
//		//-----------------------------------------
//		printf("message: ");
//		fgets(buffer, 255, stdin);
//		//-----------------------------------------
//		int n=write(sock_desc_00, buffer, strlen(buffer));
//		if(n<0)
//			error("ERROR writing to socket");
//		//-----------------------------------------
//		memset(&buffer, 0, 256);
//		n=read(sock_desc_00, buffer, 255);
//		if(n<0)
//			error("ERROR reading from socket");
//		printf("%s\n", buffer);
	}
	return 0;
}
