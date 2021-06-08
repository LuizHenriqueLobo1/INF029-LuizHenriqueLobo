#include <stdio.h>

#include "lista_de_recursao_headers.h"

// Q1
int fatorial(int n) {
	if(n <= 0)
		return 1;
	else
		return n * fatorial(n - 1) * -1;
}

// Q2
int fibonacci(int n) {
	if(n == 0)
		return 0;
	else if(n < 3)
		return 1;
	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// Q3
int inverteNumero(int num) {
	if(num == 0)
		return num;
	else {
		printf("%d", num % 10);
		num /= 10;
		return inverteNumero(num);
	}
}

// Q4
int somaInteirosVetor(int vetor[], int tamVet) {
	if(tamVet == 1)
		return vetor[tamVet - 1];
	else
		return vetor[tamVet - 1] + somaInteirosVetor(vetor, tamVet - 1);
}

// Q5
int somatorioNumeros(int num) {
	if(num == 0)
		return 0;
	else
		return num + somatorioNumeros(num - 1);
}

// Q6
int calcularKelevadoN(int k, int n) {
	if(k == 0 && n == 0)
		return 1;
	else if(n > 1)
		return k * calcularKelevadoN(k, n - 1);
}

// Q7
void inverteOrdemDosElementos(float vetor[], int inicio, int final) {
	float aux;
	if(inicio < final) {
		aux = vetor[inicio];
		vetor[inicio] = vetor[final];
		vetor[final] = aux;
		inverteOrdemDosElementos(vetor, inicio + 1, final - 1);
	}
}

// Q8
int mdc(int x, int y) {
  if (y == 0)
    return x;
  else
    return mdc(y, x % y);
}