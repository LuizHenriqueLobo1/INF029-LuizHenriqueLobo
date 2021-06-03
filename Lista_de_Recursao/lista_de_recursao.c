#include <stdio.h>

#include "lista_de_recursao_headers.h"

void main() {
	// Questão 1
	int n = 6;
	n = fatorial(n);
	printf("\n----------Questao 1----------\n");
	printf("Fatorial: %d", n);
	printf("\n-----------------------------\n");

	// Questão 2
	int tamSeq = 10;
	int r = 0;
	printf("\n----------Questao 2----------\n");
	printf("Sequencia Fibonacci:\n");
	for(int i = 0; i <= tamSeq; i++) {
    	r = fibonacci(i);
    	printf("%d ", r);       
	}
	printf("\n-----------------------------\n");
}

// Questão 1
int fatorial(int n) {
	if(n <= 0)
		return 1;
	else
		return n * fatorial(n - 1) * -1;
}

// Questão 2
int fibonacci(int n) {
	if(n == 0)
		return 0;
	else if(n < 3)
		return 1;
	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}