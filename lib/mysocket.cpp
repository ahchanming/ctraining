#include "mysocket.h"

MySocket::MySocket(){

}

MySocket::MySocket(MySockAddr* ptAddr){
	m_addr = ptAddr;
}

MySocket::MySocket(const char* host, int port){
	m_addr = new MySockAddr(host, port);
}

MySocket::MySocket(int fd, MySockAddr* addr){
	m_addr = addr;
	m_fd = fd;
}

int MySocket::Init(){
	if ((m_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("socket init error\n");
		return -1;
	}
	if (m_addr == NULL){
		printf("Error, m_addr is null");
		return -1;
	}
	int conRet;
	if (( conRet = Connect()) < 0){
		return conRet;
	}
}

int MySocket::Connect(){
	if (m_addr == NULL){
		printf("Error, m_addr is null");
	}
	int conRet;
	if ((conRet = connect(m_fd, m_addr->GetPtSockAddr(), sizeof(*(m_addr->GetPtSockAddr())))) < 0){
		printf("Connect Error\n");
		return -1;
	}
	return 0;
}

int MySocket::Send(const void* buff, int length){
	int ret;
	if ((ret = send(m_fd, buff, length, 0)) < 0){
		printf("MySocket send error\n");
		return -1;
	}
	return ret;
}

int MySocket::Recv(void* buff, int length){
	int ret;
	if ((ret = recv(m_fd, buff, length, 0)) < 0){
		printf("MySocket recv error\n");
		return -1;
	}
	return ret;
}


struct sockaddr* MySocket::GetScokAddr(){
	return m_addr->GetPtSockAddr();
}
