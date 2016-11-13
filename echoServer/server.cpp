#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int Socket(int domain, int type, int protocol){
	int fd = 0;
	if ((fd = socket(domain, type, protocol)) < 0){
		printf("create socket error\n");
	}
	return fd;
}

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
	int ret = 0;
	if ((ret == bind(sockfd, addr, addrlen)) < 0){
		printf("bind error\n");
	}
	return ret;
}

int Listen(int sockfd, int backlog){
	int ret = 0;
	if ((ret == listen(sockfd, backlog)) < 0){
		printf("listen error\n");
	}
	return ret;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
	int confd = 0;
	if ((confd = accept(sockfd, addr, addrlen)) < 0){
		printf("accept error\n");
	}
	return confd;
}

int main(){
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, seraddr;
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	printf("listen fd is %d\n", listenfd);

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	seraddr.sin_port = htons(8098);
	Bind(listenfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
	Listen(listenfd, 0);
	for (;;){
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr*) &cliaddr, &clilen);
		printf("accept OK\n");
	}
	return 0;
}
