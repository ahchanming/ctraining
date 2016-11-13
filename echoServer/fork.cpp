#include <unistd.h>
#include <stdio.h>

int main(){
	int pid = 0;
	int x = 1024;
	pid = fork();
	if (pid < 0){
		printf("error in fork");
	}else if (pid == 0){
		printf("pid is %d this is parent, x is %d, x's addr is %p\n", pid, x, (&x));
	}else{
		x = 17;
		printf("pid is %d this is child, x is %d, x's addr is %p\n", pid, x, (&x));
	}
	printf("program over\n");
}
