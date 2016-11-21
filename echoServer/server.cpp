#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

int DoEcho(int sockfd){
	ssize_t n;
	char buff[1024];
	memset(buff, 0, sizeof(buff));
	while ((n = read(sockfd, buff, 1024)) > 0){
		printf("recieve from client,data[%s]\n",buff);
		write(sockfd, buff, n);
	}
}

int DoEcho2(int pid, int sockfd){
	ssize_t n;
	char buff[1024];
	memset(buff, 0, sizeof(buff));
	while ((n = read(sockfd, buff, 1024)) > 0){
		printf("recieve from client, pid is [%d], data[%s]\n", pid, buff);
		write(sockfd, buff, n);
		close(sockfd);
		break;
	}
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
		printf("A new client connect, client fd is %d\n", connfd);
		int pid;
		if ((pid = fork()) < 0){
			printf("fork error\n");
		}else if (pid == 0){
			close(connfd);
		}else{
			close(listenfd);
			DoEcho(connfd);
		}
	}
	return 0;
}
