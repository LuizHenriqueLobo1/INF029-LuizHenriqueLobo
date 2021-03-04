#include <stdio.h>

#include "calculadora.h"

int main() {

	int valor1 = 12;
	int valor2 = 6;

	int resultSoma = 0;
	int resultSubtracao = 0;
	int resultMultiplicacao = 0;
	int resultDivisao = 0;

	resultSoma = soma(valor1, valor2);
	resultSubtracao = subtracao(valor1, valor2);
	resultMultiplicacao = multiplicacao(valor1, valor2);
	resultDivisao = divisao(valor1, valor2);

	printf("Resultado da soma: %d", resultSoma);
	printf("\nResultado da subtracao: %d", resultSubtracao);
	printf("\nResultado da multiplicacao: %d", resultMultiplicacao);
	printf("\nResultado da divisao: %d", resultDivisao);
	
	return 0;
}