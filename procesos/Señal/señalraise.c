#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void manejadorUSR2(int s);

int main(int argc,char **argv){
	signal(SIGUSR2,manejadorUSR2);
	printf("Iniciando....\n");
	sleep(3);
	raise(SIGUSR2);

	sleep(3);
	kill(getpid(),SIGUSR2);

	return 0;
}
void manejadorUSR2(int s){
	printf("Señal recibida:USR2!!!(%d)\n",s);
}


