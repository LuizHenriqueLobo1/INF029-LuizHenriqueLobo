#include <stdio.h>

/*7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras.*/

typedef struct 
{
	char palavra1[25];
	char palavra2[25];
	char palavra3[25];
}palavra;

palavra ler3Palavras();

int main() {

	palavra valor;

	valor = ler3Palavras();

	printf("Primeira palavra: %s", valor.palavra1);
	printf("Segunda palavra: %s", valor.palavra2);
	printf("Terceira palavra: %s", valor.palavra3);

	return 0;
}

palavra ler3Palavras() {

	palavra valores;

	printf("Digite a primeira palavra: ");
	fgets(valores.palavra1, 25, stdin);

	printf("Digite a segunda palavra: ");
	fgets(valores.palavra2, 25, stdin);

	printf("Digite a terceira palavra: ");
	fgets(valores.palavra3, 25, stdin);

	return valores;
}