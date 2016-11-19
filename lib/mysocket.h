#ifndef _MY_SOCKET_H
#define _MY_SOCKET_H

class MySocket(){
private:
	int m_fd;
	int m_family;
	int m_type;
	int m_procotol;
public:
	MySocket();
	Init();
	
}
#endif
