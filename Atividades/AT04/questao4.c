#include <stdio.h>

/*4) Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.*/


void ler3Numeros(int vet[]);

int main() {

	int vetor[3];

	ler3Numeros(vetor);

	for(int i = 0; i < 3; i++) {
		printf("Numero passado: %d\n", vetor[i]);
	}
	
	return 0;
}

void ler3Numeros(int vet[]) {

	for(int i = 0; i < 3; i++) {
		printf("Digite o numero: ");
		scanf("%d", &vet[i]);
	}
}