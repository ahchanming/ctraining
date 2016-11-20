#include "../lib/myserversocket.h"
#include <iostream>

int main(int argc, char **argv){
	MyServerSocket *socket = new MyServerSocket(8096, 1);
	std::cout << socket->GetPort() << std::endl;
	std::cout << socket->Init() << std::endl;
	std::cout << "helloworld" << std::endl;
	while (true){
		if (socket->Accept() > 0){
			puts("helloWorld");
		}
	}
	return 0;
}
