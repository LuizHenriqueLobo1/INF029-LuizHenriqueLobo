#include <stdio.h>

#include "lista_de_recursao_headers.h"

void main() {
	questao1();
	questao2();
}

void separadorInicio(char string[]) {
	printf("\n---------- %s ----------\n", string);
}

void separadorFinal() {
	printf("\n-------------------------------\n");
}

void questao1() {

	int n = 6;
	
	n = fatorial(n);
	
	separadorInicio("Questao 1");
	printf("Fatorial: %d", n);
	separadorFinal();
}

void questao2() {

	int tamSeq = 10;
	int r = 0;
	int i;

	separadorInicio("Questao 2");
	printf("Sequencia Fibonacci:\n");
	for(i = 0; i <= tamSeq; i++) {
    	r = fibonacci(i);
    	printf("%d ", r);       
	}
	separadorFinal();
}