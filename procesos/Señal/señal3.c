#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void manejadorUSR2(int s);
void manejadorCHLD(int s);

int main(int argc,char **argv){
	signal(SIGUSR2,manejadorUSR2);
	int pid=fork();

	if(!pid){
		printf("iniciando hijo....\n");
		while(1){
			printf("Procesando...\n");
			pause();
		}
		printf("terminando hijo\n");
		exit(0);
	}
	sleep(1);
	signal(SIGCHLD,manejadorCHLD);
	printf("Padre avisando al hijo...\n");
	kill(pid,SIGUSR2);
	sleep(2);
	kill(pid,SIGUSR2);
	sleep(3);
	kill(pid,SIGTERM);
	wait(NULL);

	return 0;
}
void manejadorUSR2(int s){
	printf("Señal recibida:USR2!!!(%d)\n",s);
}
void manejadorCHLD(int s){
	printf("Adios hijo(%d)\n",s);
}
