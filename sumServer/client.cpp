#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "sum.h"

int Socket(int domain, int type, int protocol){
	int fd = 0;
	if ((fd = socket(domain, type, protocol)) < 0){
		printf("create socket error\n");
		exit(0);
	}
	return fd;
}

int Send(int serverFd, const void* buffer, size_t size){
	int ret;
	if ((ret = send(serverFd, buffer, size, 0)) < 0){
		puts("send error");
		exit(0);
	}
	printf("send OK, size is %d\n", ret);
	return 0;
}

int Recv(int fd, void* holder, size_t size){
	int ret;
	if ((ret = recv(fd, holder, size, 0)) < 0){
		puts("error \n");
		exit(0);
	}
	return 0;
}
	


int main(int argc, char **argv){
	if (argc < 2){
		puts("please run client $host");
		exit(0);
	}

	int serverFd = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in seraddr;
	char buff[4096], message[4096];

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(8098);
	if (inet_pton(AF_INET, argv[1], &seraddr.sin_addr) < 0){
		printf("inet_pton error\n");
		exit(0);
	}

	if (connect(serverFd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0){
		printf("connect error\n");
		exit(0);
	}

	while (true){
		puts("enter arg A and arg B");
		struct sumarg arg;
		scanf("%d %d", &arg.a, &arg.b);
		Send(serverFd, &arg, sizeof(arg));
		struct sumans ans;
		Recv(serverFd, &ans, sizeof(ans));
		printf("recieve from server %d\n", ans.ans);
	}
	close(serverFd);
	return 0;
}
