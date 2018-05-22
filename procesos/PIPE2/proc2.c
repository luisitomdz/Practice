#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv){
	int pid=atoi(*(argv+1));
	int s=atoi(*(argv+2));
	kill(pid,s);

return 0;

}
