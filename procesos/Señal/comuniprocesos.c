#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void manejadorINT(int s);

int main(int argc,char **argv){

        signal(SIGINT,manejadorINT);
        while(1){
                printf("Ejecutando...\n");
                sleep(1);
        }
        return 0;
}
void manejadorINT(int s){
        printf("Señal recibida:INT!!!(%d)---SIGO VIVO!!!\n",s);
}


