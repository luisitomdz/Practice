#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void manejadorUSR1(int s);

int main(int argc,char **argv){
	int i=0;
	signal(SIGUSR1,manejadorUSR1);
	printf("PID:%d\n",getpid());

	for(i=0;i<50;i++){
		printf("Ejecutando...%d\n",i);
		sleep (1);
		if(i==20){
			signal(SIGUSR1,SIG_IGN);
		}
	}
	printf("terminando...\n");
	return 0;


}
void manejadorUSR1(int s){
	printf("Señal recibida:USR1!!!(%d)\n",s);
}
