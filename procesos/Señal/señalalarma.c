
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void manejadorALRM(int s);

int main(int argc,char **argv){

        signal(SIGALRM,manejadorALRM);
	alarm(5);
	while(1){
		printf("Ejecutando...\n");
		sleep(1);
	}
	return 0;
}
void manejadorALRM(int s){
	printf("RINGGGGG!!!!!!(%d)\n",s);
	alarm(5); //seteo de la alarma
}
