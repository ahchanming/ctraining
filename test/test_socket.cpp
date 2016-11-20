#include "../lib/mysocket.h"


int main(){
	const char* host = "127.0.0.1";
	MySocket socket(host, 8096);
	socket.Init();
	printf("Hello World");
}
