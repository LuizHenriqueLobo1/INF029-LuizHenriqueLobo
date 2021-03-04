#include <stdio.h>

/*6) Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.*/

typedef struct 
{
	char primeiraLetra;
	char segundaLetra;
	char terceiraLetra;
}letra;

letra ler3Letras();

int main() {

	letra valores;

	valores = ler3Letras();

	printf("Primeira letra: %c", valores.primeiraLetra);
	printf("\nSegunda letra: %c", valores.segundaLetra);
	printf("\nTerceira letra: %c", valores.terceiraLetra);
}


letra ler3Letras() {

	letra valor;

	printf("Digite a primeira letra: ");
	scanf("%c", &valor.primeiraLetra);
	getchar();

	printf("Digite a segunda letra: ");
	scanf("%c", &valor.segundaLetra);
	getchar();

	printf("Digite a terceira letra: ");
	scanf("%c", &valor.terceiraLetra);

	return valor;
}