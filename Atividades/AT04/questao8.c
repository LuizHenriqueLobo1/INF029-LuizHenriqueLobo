#include <stdio.h>

/*8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente.*/

typedef struct {
	char nome[25];
	char dataNascimento[11];
	char cpf[16];
	char sexo[10];
}cliente;

cliente cadastrarCliente();

int main() {

	cliente valor;

	valor = cadastrarCliente();

	printf("Dados do Cliente\n");
	printf("Nome: %s", valor.nome);
	printf("Data de nascimento: %s", valor.dataNascimento);
	printf("\nCPF: %s", valor.cpf);
	printf("Sexo: %s", valor.sexo);

	return 0;
}

cliente cadastrarCliente() {

	cliente valores;

	printf("Digite o nome do cliente: ");
	fgets(valores.nome, 25, stdin);

	printf("Digite a data de nascimento do cliente: ");
	fgets(valores.dataNascimento, 11, stdin);
	getchar();

	printf("Digite o cpf do cliente: ");
	fgets(valores.cpf, 16, stdin);

	printf("Digite o sexo do cliente: ");
	fgets(valores.sexo, 10, stdin);
	getchar();

	return valores;
}