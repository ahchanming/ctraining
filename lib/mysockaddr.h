#ifndef _MY_SOCKADDR_
#define _MY_SOCKADDR_

#define MySockAddr_IPv4 AF_INET
#define MySockAddr_IPv6 AF_INET6
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

class MySockAddr{
private:
	struct sockaddr_in m_sa;
	socklen_t m_socklen;
public:
	MySockAddr();
	MySockAddr(const char* host, int port);
	MySockAddr(struct sockaddr addr, socklen_t socklen);
	struct sockaddr* GetPtSockAddr();
	int GetFamily();
	void SetFamily(int _family);
	int GetPort();
	void SetPort(int _port);
	int SetAddr(char* host);
	void Output();
};
#endif
