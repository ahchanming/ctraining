#ifndef _MY_SERVERSOCKET_H
#define _MY_SERVERSOCKET_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

class MyServerSocket{
private:
	int m_port;
	int m_backlog;
	bool hasInit;
	sockaddr_in m_sockaddr;
	int m_fd;
	int Socket(int domain, int type, int protocol);

public:
	MyServerSocket();
	MyServerSocket(int port);
	MyServerSocket(int port, int backlog);
	int Init();
	int Bind();
	int Listen();
	
	int GetPort();
	void SetPort(int port);
};
#endif

