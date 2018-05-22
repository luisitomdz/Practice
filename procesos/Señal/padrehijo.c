#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char **argv){

        int pid;
	pid=fork();
	if(!pid){ //HIJO
		printf("Soy el hijo, mi pid:%d, el pid de mi padre:%d\n",getpid(),getppid());

	}else{ //PADRE
		printf("Soy el padre, mi pid:%d, el pid de mi hijo:%d,el pid de mi padre:%d\n", getpid(),pid,getppid());
		wait(NULL);
		sleep(1);
		system("ps fax");
	}

        return 0;
}


