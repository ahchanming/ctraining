#include "../lib/myserversocket.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

int main(int argc, char **argv){
	MyServerSocket *socket = new MyServerSocket(8096, 1);
	std::cout << socket->GetPort() << std::endl;
	std::cout << socket->Init() << std::endl;
	std::cout << "helloworld" << std::endl;
	while (true){
		MySocket* pt = socket->Accept();
		puts("helloWorld");
		std::string str;
		std::cin >> str;
		//char* str =  "123456789";
		pt->Send(str.c_str(), 9);
	}
	return 0;
}
