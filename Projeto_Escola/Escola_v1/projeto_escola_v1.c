#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

int main() {

	aluno estud[10];
	int quantidadeAlunos = 0;
	int flag = 1;
	int opcao = 0;

	while(flag == 1) {

		opcao = menu(opcao);

		switch(opcao) {

			case 0: {
				flag = 0;
				printf("\nPROGRAMA FINALIZADO!\n");
				break;
			}

			case 1: {
				int retornoCadastroAluno = 0;
				retornoCadastroAluno = cadastrarAlunos(quantidadeAlunos, estud);
				if(retornoCadastroAluno == 1) {
					quantidadeAlunos++;
					printf("\nALUNO CADASTRADO COM SUCESSO!\n");
				} else {
					printf("\nFALHA AO CADASTRAR ALUNO!\n");
				}
	
				break;
			}

			case 2: {
				mostrarAlunos(quantidadeAlunos, estud);
				break;
			}

			default: {
				printf("\nOPCAO INVALIDA!\n");
			}
		}
	}

	return 0;
}

int menu(int op) {

	printf("\n---------- MENU ----------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> CADASTRAR ALUNO   |\n");
	printf("| 2 -> MOSTRAR ALUNOS    |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

int cadastrarAlunos(int qtdAlunos, aluno estudante[]) {

	printf("\n---------------------\n");
	printf("| CADASTRANDO ALUNO |");
	printf("\n---------------------\n");

	printf("\nDigite o numero de matricula: ");
	fgets(estudante[qtdAlunos].matricula, 50, stdin);
	setbuf(stdin, NULL);

	printf("\nDigite o nome do aluno (Ate 20 caracteres): ");
	fgets(estudante[qtdAlunos].nome, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarNome(estudante[qtdAlunos].nome) != 1) {
			printf("\nNOME INVALIDO! Digite novamente...\n");
			fgets(estudante[qtdAlunos].nome, 50, stdin);
		} else {
			break;
		}
	}
	
	printf("\nDigite o sexo do aluno (M, F ou O): ");
	scanf("%c", &estudante[qtdAlunos].sexo);
	setbuf(stdin, NULL);
	while(1) {
		if(validarSexo(estudante[qtdAlunos].sexo) != 1) {
			printf("\nSEXO INVALIDO! Digite novamente...\n");
			scanf("%c", &estudante[qtdAlunos].sexo);
			setbuf(stdin, NULL);
		} else {
			break;
		}
	}

	printf("\nDigite a data de nascimento do aluno (Somente os numeros): ");
	fgets(estudante[qtdAlunos].data, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarData(estudante[qtdAlunos].data) != 1) {
			printf("\nDATA INVALIDA! Digite novamente...\n");
			fgets(estudante[qtdAlunos].data, 50, stdin);
		} else {
			break;
		}
	}


	printf("\nDigite o CPF do aluno (Somente os numeros): ");
	fgets(estudante[qtdAlunos].cpf, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarCPF(estudante[qtdAlunos].cpf) != 1) {
			printf("\nCPF INVALIDO! Digito novamente...\n");
			fgets(estudante[qtdAlunos].cpf, 50, stdin);
		} else {
			break;
		}
	}

	return 1;
}

void mostrarAlunos(int qtdAlunos, aluno estudante[]) {

	printf("\n--------------------\n");
	printf("| LISTANDO ALUNOS  |");
	printf("\n--------------------\n");

	if(qtdAlunos <= 0) {
		printf("\nNENHUM ALUNO CADASTRADO!\n");
	} else {
		for(int i = 0; i < qtdAlunos; i++) {
		printf("\n---------- ALUNO %d ----------\n", i+1);
		printf("Numero de matricula: %s", estudante[i].matricula);
		printf("Nome: %s", estudante[i].nome);
		printf("Sexo: %c", estudante[i].sexo);
		printf("\nData de nascimento: %s", estudante[i].data);
		printf("CPF: %s", estudante[i].cpf);
		printf("-----------------------------\n");
		}
	}
}