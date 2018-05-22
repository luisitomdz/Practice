#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int);

int main(int argc, char **argv){

	signal(SIGUSR2,handler);
	printf("Proc %s, pid: %d\n",*argv,getpid());
	pause();
	printf("Señal recibida!!!\n");
	return 0;
}
void handler(int s){
	printf("Señal USR2\n");
}
