#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void manejadorCHLD(int s);

int main(int argc,char **argv){

	signal(SIGCHLD,manejadorCHLD);
	if(!fork()){
		printf("Iniciando hijo....\n");
		sleep(10);
		printf("terminando hijo\n");
		return 0;
	}
	printf("padre esperando\n");
	wait(NULL);
	printf("padre terminando\n");

	return 0;
}
void manejadorCHLD(int s){
	printf("Adios hijo(%d)\n",s);
}
