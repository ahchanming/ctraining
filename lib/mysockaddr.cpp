#include "mysockaddr.h"
#include <iostream>

MySockAddr::MySockAddr(){
	bzero(&m_sa, sizeof(m_sa));
	m_sa.sin_family = MySockAddr_IPv4;
	m_sa.sin_addr.s_addr = htonl(INADDR_ANY);
}

MySockAddr::MySockAddr(const char* host, int port){
	bzero(&m_sa, sizeof(m_sa));
	m_sa.sin_family = MySockAddr_IPv4;
	m_sa.sin_port = htons(port);
	if ((inet_pton(AF_INET, host, &m_sa.sin_addr)) < 0){
		printf("MySockAddr Set host Error\n");
	}
}

MySockAddr::MySockAddr(struct sockaddr addr, socklen_t len){
	memcpy(&m_sa, &addr, sizeof(addr));
	m_socklen = len;
}

struct sockaddr* MySockAddr::GetPtSockAddr(){
	return (struct sockaddr*)&m_sa;
}

int MySockAddr::GetFamily(){
	return m_sa.sin_family;
}

int MySockAddr::GetPort(){
	return m_sa.sin_port;
}

void MySockAddr::SetPort(int _port){
	m_sa.sin_port = htons(_port);
}

int MySockAddr::SetAddr(char* host){
	if ((inet_pton(AF_INET, host, &m_sa.sin_addr)) < 0){
		printf("MysockAddr Set host error\n");
		return -1;
	}
	return 0;
}

void MySockAddr::Output(){
	std::cout << m_sa.sin_family << std::endl;
	std::cout << m_sa.sin_port << std::endl;
	std::cout << m_sa.sin_addr.s_addr << std::endl;
}
