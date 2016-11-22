#ifndef _MY_SERVERSOCKET_H
#define _MY_SERVERSOCKET_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mysocket.h"
#include "mysockaddr.h"
#include "errno.h"
class MyServerSocket{
private:
	int m_port;
	int m_backlog;
	bool hasInit;
	sockaddr_in m_sockaddr;
	int m_fd;

public:
	MyServerSocket();
	MyServerSocket(int port);
	MyServerSocket(int port, int backlog);
	MySocket* Accept();
	int Init();
	int Bind();
	int Listen();
	int GetPort();
	void SetPort(int port);
};
#endif

