#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
int pid;
pid=fork();

	/*printf("antes del fork\n");
	fork();
	printf("despues del fork\n");
	fork();
	printf("despues del segundo fork\n");
	*/

	if (!pid){
		printf("Soy el hijo, mi pid:%d, el pid de mi padre:%d\n",getpid(), getppid());
		//sleep(1);
		//system("ps fax");
		// Nunca debe terminar el padre antes que el hijo.
		//printf("Soy el hijo, mi pid:%d, el pid de mi padre:%d\n",getpid(), getppid());
}else{

		printf("Soy el padre, mi pid:%d, el pid de mi hijo:%d, el pid de mi padre:%d\n",getpid(), pid, getppid());
		wait(NULL);

		sleep(1);
		system("ps fax");


	}
return(0);

}
