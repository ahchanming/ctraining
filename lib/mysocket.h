#ifndef _MY_SOCKET_H
#define _MY_SOCKET_H

#include "mysockaddr.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/socket.h"


class MySocket{
private:
	int m_fd;
	MySockAddr*  m_addr;
public:
	MySocket();
	MySocket(const char *host, int port);
	MySocket(int fd, MySockAddr *ptAddr);
	MySocket(MySockAddr* ptAddr);
	int Init();
	int Connect();
	int Send(const void* buff, int length);
	int Recv(void* buff, int length);
	struct sockaddr* GetScokAddr();
};
#endif
