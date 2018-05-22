#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void handler(int s);
int bandera = 1;
int main(int argc, char **argv){
	int estado, pid;
	do{
	if((pid=fork())==0){
		printf("Hijo esperando señal del padre... \n");
		signal(SIGUSR1, handler);
		while(bandera);
       	}else{
		printf("Padre ejecutando... \n");
		sleep(4);
		kill(pid, SIGUSR1);
		wait(&estado);
	}
	}while(bandera);
}

void handler(int s){
	if(s==SIGUSR1){
		printf("Hijo recibiendo señal del padre... \n");
		sleep(1);
	}
	bandera=0;
}

