#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char **argv){
	int num=123;
	int status=0;

	if(!fork()){//hijo
		num++;
		printf("num en el hijo:%d\n",num);
		exit(256);
	}else{
		num--;
		printf("num en el padre:%d\n",num);
		wait(&status);
		printf("Valor de status:%d\n",WEXITSTATUS(status));

	}

	return 0;
}
