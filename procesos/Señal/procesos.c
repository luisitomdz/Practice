#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char **argv){

	printf("antes del fork\n");
	fork();
	printf("despues del fork\n");
	fork();
	printf("despues del segundo fork\n");
	system("ps fax");
	return 0;
}
