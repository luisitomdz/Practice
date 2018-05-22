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
	count=read(tuberia[0],cadena,BUF_SIZE);
	*(cadena+count)='\0';
	printf("HIjo lee:%s\n",cadena);
	write(tuberia[1],"Adios padre",11);
	close(tuberia[0]);
	close(tuberia[1]);
	exit(0);

        }

	write(tuberia[1],"Hola hijo",9);
	sleep(1);
	count=read(tuberia[0],cadena,BUF_SIZE);
	*(cadena+count)='\0';
	printf("Padre lee %s\n",cadena);
	close (tuberia[0]);
	close(tuberia[1]);

	return 0;
}

