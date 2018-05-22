#include "calculadora.h"

char datos(float *num1, float *num2){
	printf("Introduzca valor 1: ");
	scanf("%f",num1);

	printf("Introduzca valor 2: ");
	scanf("%f",num2);

	printf("Introduzca a operacion: (+ - * /) ");
	getchar();
	return getchar();
}
