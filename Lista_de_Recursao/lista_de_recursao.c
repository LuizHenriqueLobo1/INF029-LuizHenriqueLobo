#include <stdio.h>

#include "lista_de_recursao_headers.h"

void main() {
	questao1();
	questao2();
	questao3();
	questao4();
	questao5();
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

void questao3() {

	int numero = 12345;

	separadorInicio("Questao 3");
	printf("Numero invertido: ");
	numero = inverteNumero(numero);
	separadorFinal();
}

void questao4() {

	int tamVetor = 5;
	int vetor[tamVetor];
	int i;
	int soma;

	for(i = 0; i < tamVetor; i++) {
		vetor[i] = i + 1;
	}

	separadorInicio("Questao 4");
	printf("Soma dos valores do vetor: %d", soma = somaInteirosVetor(vetor, tamVetor));
	separadorFinal();
}

void questao5() {

	int n = 3;
	int resultado = 0;

	separadorInicio("Questao 5");
	printf("Soma dos valores de 1 a N: %d", resultado = somatorioNumeros(n));
	separadorFinal();
}