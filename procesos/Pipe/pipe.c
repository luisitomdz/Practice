#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define BUF_SIZE 128

int main(int argc, char **argv){
	int tuberia[2];
	int count,i;
	char cadena[BUF_SIZE];

	if(pipe(tuberia)<0){
		perror("pipe");
		exit(-1);
	}
goto pipe3;
goto pipe2;

	count=sprintf(cadena,"Hola mundo");
	write(tuberia[1],cadena,count);
	strcpy(cadena,"limpiando");
	printf("La cadena tiene:%s\n",cadena);
	count=read(tuberia[0],cadena,BUF_SIZE);
	*(cadena + count)='\0';				//Despues del read siempre para que no muestre basura
	printf("Cadena leida:%s\n",cadena);

	printf("PID:%d\n",getpid());
	sprintf(cadena,"ls -l /proc/%d/fd",getpid());
	system(cadena);

	close(tuberia[0]);
	close(tuberia[1]);
	return 0;


pipe2:
	if(!fork()){
		close(tuberia[0]);
		printf("hijo escribiendo\n");
		count=sprintf(cadena,"hola padre...");
		write(tuberia[1],cadena,count);
		sleep(3);

		for(i=0;i<5;i++){
			count=sprintf(cadena,"Dame plata");
			write(tuberia[1],cadena,count);
			sleep(1);
		}
		count=sprintf(cadena,"Adios padre");
		write(tuberia[1],cadena,count);
		close(tuberia[1]);
		exit(0);
	}else{
		close(tuberia[1]);
		while(count=read(tuberia[0],cadena,BUF_SIZE)){
			*(cadena+count)='\0';
			printf("Padre leyendo:%s\n",cadena);
		}
		wait(NULL);
		close(tuberia[0]);
		printf("No tengo plata\n");
	}
	return 0;

pipe3:
	if(!fork()){
		count=read(tuberia[0],cadena,BUF_SIZE);
		*(cadena+count)='\0';
		printf("Hijo lee:%s\n",cadena);
		write(tuberia[1],"Adios padre",11);
		close(tuberia[0]);
		close(tuberia[1]);
		exit(0);
	}else{
		write(tuberia[1],"Hola hijo",9);
		sleep(1);
		count=read(tuberia[0],cadena,BUF_SIZE);
		*(cadena+count)='\0';
		printf("Padre lee:%s\n",cadena);
		wait(NULL);
		close(tuberia[0]);
		close(tuberia[1]);
	}
	return 0;

}
