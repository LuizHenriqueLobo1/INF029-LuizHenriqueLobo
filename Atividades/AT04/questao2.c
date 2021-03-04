#include <stdio.h>

/*2) Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração.*/

int subtracao(int val1, int val2, int val3);

int main() {

	int valor1 = 0;
	int valor2 = 0;
	int valor3 = 0;
	int result = 0;

	printf("Digite o primeiro valor: ");
	scanf("%d", &valor1);
	
	printf("Digite o segundo valor: ");
	scanf("%d", &valor2);
	
	printf("Digite o terceiro valor: ");
	scanf("%d", &valor3);

	result = subtracao(valor1, valor2, valor3);

	printf("Resultado da subtracao: %d", result);

	return 0;
}

int subtracao(int val1, int val2, int val3) {

	int resultado = 0;

	resultado = val1 - val2 - val3;

	return resultado;
}