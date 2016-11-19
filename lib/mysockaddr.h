#ifndef _MY_SOCKADDR_
#define _MY_SOCKADDR_

#define MySockAddr_IPv4 AF_INET
#define MYSOckAddr_IPv6 AF_INET6
#include <string.h>

class MySockAddr{
private:
	struct sockaddr_in m_sockaddr;
	int m_address;
	int m_family;
public:
	MySockAddr();
	struct sockaddr* GetPtSockAddr();
}
#endif
