#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int s);
int main(int argc, char **argv){
	printf("Proc %s, pid: %d\n",*argv,getpid());
	pause();
	printf("Señal recibida!!\n");
	return 0;

void handler(int s){
	printf("Señal usr 2!!\n");
}
}
