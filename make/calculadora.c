#include "calculadora.h"


int main(int argc, char** argv) {

	float num1,num2, resultado;
	char op;

	op=datos(&num1,&num2);

	switch(op){
	case '+':
		resultado=suma(num1,num2);
		break;
	case '-':
		resultado=resta(num1,num2);
		break;
	case '*':
		resultado=mult(num1,num2);
		break;
	case '/':
		resultado=division(num1,num2);
		break;
	default:
		printf("Opcion incorrecta\n");
		goto no_result;
	}

	printf("Resultado: %.2f\n",resultado);

no_result:

	return 0;
}
