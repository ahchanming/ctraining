#include "../lib/mysocket.h"
#include <string.h>

int main(){
	const char* host = "127.0.0.1";
	MySocket socket(host, 8098);
	socket.Init();
	char buff[1024];
	while (true){
		memset(buff, 0, sizeof(buff));
		gets(buff);
		int sendRet;
		sendRet = socket.Send(buff, 1024);
		printf("the socket send result is %d\n", sendRet);
		int recvRet;
		recvRet = socket.Recv(buff, 1024);
		printf("the socket recv result is %d\n", recvRet);
		puts(buff);
	}
	printf("Hello World");
}
