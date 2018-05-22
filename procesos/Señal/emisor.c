#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
        int pid=atoi(*(argv+1));
	int s=atoi(*(argv+2));
	printf("%d",s);
	kill(pid,s);
	return 0;
}


