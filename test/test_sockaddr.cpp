#include "../lib/mysockaddr.h"
#include <stdio.h>


int main(){
	MySockAddr addr("127.0.0.1", 8096);
	addr.Output();
	puts("Hello World");
}
