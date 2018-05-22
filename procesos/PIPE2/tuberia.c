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
char cadena[128];

int main(int argc,char **argv){

	if (pipe(tuberia)<0){
		perror("pipe");
		exit(-1);
	}

count=sprintf(cadena,"hola mundo");
write(tuberia[1],cadena,count);
strcpy(cadena,"limpiando");
printf("La cadena tiene %s\n",cadena);
count=read(tuberia[0],cadena,BUF_SIZE);
*(cadena+count)='\0'; //despues del read para colocar un caracternulo
printf("Cadena leida: %s\n",cadena);
printf("PID: %d\n",getpid());
sprintf(cadena,"ls -l /proc/%d/fd", getpid());
system(cadena);
close(tuberia[0]);
close(tuberia[1]);

return 0;

}
