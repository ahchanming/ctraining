#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

int Socket(int domain, int type, int protocol){
	int fd = 0;
	if ((fd = socket(domain, type, protocol)) < 0){
		printf("create socket error\n");
		exit(0);
	}
	return fd;
}


int main(int argc, char **argv){
	int serverFd = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in seraddr;
	char buff[4096], message[4096];

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(8098);
	if (inet_pton(AF_INET, "127.0.0.1", &seraddr.sin_addr) < 0){
		printf("inet_pton error\n");
		exit(0);
	}

	if (connect(serverFd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0){
		printf("connect error\n");
		exit(0);
	}

	int tmp;
	memset(message, 0, sizeof(message));
	fgets(message, 2048, stdin);

	if ((tmp = send(serverFd, message, strlen(message) - 1, 0)) < 0){
		printf("send message error\n");
		exit(0);
	}else{
		printf("send number: %d\n", tmp);
	}

	memset(buff, 0, sizeof(buff));
	if ((tmp = recv(serverFd , buff, 2048, 0)) < 0){
		printf("recieve error\n");
		exit(0);
	}

	puts("recieve from server\n");
	puts(buff);
	close(serverFd);
	return 0;
}
