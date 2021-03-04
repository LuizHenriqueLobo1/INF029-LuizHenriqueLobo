#include <stdio.h>

/*3) Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial
deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do
usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.*/

int fatorial(int val);

int main() {

	int valor = 0;
	int result = 0;

	printf("Digite um valor para receber seu fatorial: ");
	scanf("%d", &valor);

	result = fatorial(valor);

	if(result == -1) {
		printf("Erro! O fatorial nao pode ser calculado!");
	} else {
		printf("Fatorial: %d", result);
	}

	return 0;
}

int fatorial(int val) {

	int fatorial = 0;
	int erro = -1;

	if(val < 0) {
		return erro;
	} else {
		for(fatorial = 1; val > 1; val = val - 1) {
			fatorial = fatorial * val;
		}
		return fatorial;
	}
}