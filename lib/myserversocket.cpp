#include "myserversocket.h"

MyServerSocket::MyServerSocket(){
	m_port = 8096;
	m_backlog = 50;
}

MyServerSocket::MyServerSocket(int port){
	m_port = port;
	m_backlog = 50;
}

MyServerSocket::MyServerSocket(int port, int backlog){
	m_port = port;
	m_backlog = backlog;
}

int MyServerSocket::Bind(){
	int ret = 0;
	if ((ret = bind(m_fd, (struct sockaddr*)&m_sockaddr, sizeof(m_sockaddr))) < 0){
		puts("bind error");
		return -1;
	}
	return 0;
}

int MyServerSocket::Listen(){
	int ret = 0;
	if ((ret = listen(m_fd, m_backlog)) < 0){
		puts("listen error");
		return -1;
	}
	return 0;
}

int MyServerSocket::Socket(int domain, int type, int procotol){
	int ret;
	if ((ret = socket(domain,type, procotol)) < 0){
		return -1;
	}
	return ret;
}

int MyServerSocket::Init(){
	if ((m_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		puts("socket init error");
		return -1;
	}
	bzero(&m_sockaddr, sizeof(m_sockaddr));
	m_sockaddr.sin_family = AF_INET;
	m_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	m_sockaddr.sin_port = htons(m_port);
	int bindRet;
	if ((bindRet = Bind()) < 0){
		return bindRet;
	}
	int listenRet;
	if ((listenRet = Listen()) < 0){
		return listenRet;
	}
	return 0;
}

int MyServerSocket::GetPort(){
	return m_port;
}

void MyServerSocket::SetPort(int port){
	m_port = port;
}

