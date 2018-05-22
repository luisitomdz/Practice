#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void handler1(int s);
void handler2(int r);
int flag = 1;
int main(int argc, char **argv){
	int estado, pid1, pid2;

		if((pid1=fork())!=0){
                        signal(SIGUSR1, handler1);
                        while(flag);
		}else{
                        sleep(2);
                        kill(getppid(),SIGUSR1);
			wait(&estado);
		}

		if((pid2=fork())==0){
			signal(SIGUSR1, handler2);
			while(flag);
		}else{
			sleep(2);
			kill(pid2, SIGUSR1);
			wait(&estado);
		}
}

void handler1(int s){
	while(s==SIGUSR1){
		printf("Soy el hijo 1, mi PID es=%d: PING\n",getpid());
		sleep(5);
	}
	flag=0;
}

void handler2(int r){
	while(r==SIGUSR1){
		printf("SSoy el hijo 2, mi PID es=%d: PONG\n",getpid());
		sleep(5);
	}
	flag=0;
}
			
