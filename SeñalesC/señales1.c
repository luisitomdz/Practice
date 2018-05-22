#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_INT(int s);

int main(int argc, char **argv){
        signal(SIGINT, handler_INT);

        while(1){
                printf("Ejecutando... \n");
               	pause();
        }
        return 0;
}

void handler_INT(int s){
	printf("Por ahora no saldre, intenta nuevamente \n");
	signal(SIGINT, SIG_DFL);
}
