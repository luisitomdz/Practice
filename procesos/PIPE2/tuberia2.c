#define BUF_SIZE 128
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int tuberia[2];
int count;
int i;
char cadena[128];

int main(int argc,char **argv){

        if (pipe(tuberia)<0){
                perror("pipe");
                exit(-1);
        }

	if(!fork()){
	close(tuberia[0]);
	printf("Hijo escribiendo\n");
	count=sprintf(cadena,"Hola padre...\n");
	write(tuberia[1],cadena,count);
	sleep(3);

	for(i=0;i<5;i++){
		count=sprintf(cadena,"Dame plata!\n");
		write(tuberia[1],cadena,count);
		sleep(1);
	}
	count=sprintf(cadena,"Adios padre\n");
	write(tuberia[1],cadena,count);
	close(tuberia[1]);
	exit(0);

}
close(tuberia[1]);
	while(count=read(tuberia[0],cadena,BUF_SIZE)){
	*(cadena+count)='\0';
	printf("Padre leyendo:%s\n",cadena);
	}
wait(NULL);
close(tuberia[0]);
printf("Padre terminando\n");

return 0;
}

