#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc,char **argv){
	int i=0;
	printf("Creando Padre\n");
	for(i=0;i<10;i++){
		if(!fork()){
			printf("Creando hijo %d,PID:%d\n",i,getpid());
			sleep(1);
			printf("terminando proceso %i\n",i);
			return 0;
		}
	}
	system("ps fax");
	printf("Padre esperando a que mueran los hijos...\n");
	for(i=0;i<10;i++){
		printf("Liberando proceso PID:%d\n",wait(NULL));
	}
	printf("terminando padre...\n");


	return 0;
}
