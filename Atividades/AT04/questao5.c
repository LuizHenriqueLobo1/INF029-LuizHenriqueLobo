#include <stdio.h>

/*5) Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do
usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize
struct para fazer o retorno.*/

typedef struct
{
	int num1;
	int num2;
	int num3;
	int num4;
}num;

num ler4Numeros();

int main() {

	num valor;

	valor = ler4Numeros();

	printf("Primeiro valor: %d\n", valor.num1);
	printf("Segundo valor: %d\n", valor.num2);
	printf("Terceiro valor: %d\n", valor.num3);
	printf("Quarto valor: %d", valor.num4);

	return 0;
}

num ler4Numeros() {

	num valores;

	printf("Digite o primeiro valor: ");
	scanf("%d", &valores.num1);

	printf("Digite o segundo valor: ");
	scanf("%d", &valores.num2);

	printf("Digite o terceiro valor: ");
	scanf("%d", &valores.num3);

	printf("Digite o quarto valor: ");
	scanf("%d", &valores.num4);

	return valores;
}