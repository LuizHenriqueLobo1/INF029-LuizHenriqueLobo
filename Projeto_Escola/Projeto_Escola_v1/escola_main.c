#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

int main() {

	dados Aluno[TAM];
	int quantidadeAluno = 0;

	dados Professor[TAM];
	int quantidadeProfessor = 0;

	disc Disciplina[TAM];
	int quantidadeDisciplina = 0;

	int flag = 1;

	while(flag == 1) {

		int opcao = menu_principal();

		switch(opcao) {

			case 0: {
				printf("\nPROGRAMA FINALIZADO!\n");
				flag = 0;
				break;
			}

			case 1: {
				quantidadeAluno = mainAluno(Aluno, quantidadeAluno);
				break;
			}

			case 2: {
				quantidadeProfessor = mainProfessor(Professor, quantidadeProfessor);
				break;
			}

			case 3: {
				quantidadeDisciplina  = mainDisciplina(Disciplina, quantidadeDisciplina, quantidadeProfessor, quantidadeAluno, Professor, Aluno);
				break;
			}

			default: {
				printf("\nOPCAO INVALIDA!\n");
				break;
			}
		
		}
	}

	return 0;
}

int menu_principal() {

	int opcao = 0;

	printf("\n----- MENU PRINCIPAL -----\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> MENU ALUNO        |\n");
	printf("| 2 -> MENU PROFESSOR    |\n");
	printf("| 3 -> MENU DISCIPLINA   |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &opcao);

	return opcao;
}

int menu_alterarCadastroA(int num) {

	int op = 0;

	printf("\n----------------------\n");
	printf("| ALTERANDO CADASTRO |\n");
	printf("| ALUNO %d            |", num);
	printf("\n--------------------------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> ALTERAR MATRICULA |\n");
	printf("| 2 -> ALTERAR NOME      |\n");
	printf("| 3 -> ALTERAR SEXO      |\n");
	printf("| 4 -> ALTERAR DATA      |\n");
	printf("| 5 -> ALTERAR CPF       |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	getchar();

	return op;
}

int menu_alterarCadastroP(int num) {

	int op = 0;

	printf("\n----------------------\n");
	printf("| ALTERANDO CADASTRO |\n");
	printf("| PROFESSOR %d        |", num);
	printf("\n--------------------------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> ALTERAR MATRICULA |\n");
	printf("| 2 -> ALTERAR NOME      |\n");
	printf("| 3 -> ALTERAR SEXO      |\n");
	printf("| 4 -> ALTERAR DATA      |\n");
	printf("| 5 -> ALTERAR CPF       |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	getchar();

	return op;
}

int menu_alterarCadastroD(int num) {

	int op = 0;

	printf("\n----------------------\n");
	printf("| ALTERANDO CADASTRO |\n");
	printf("| DISCIPLINA %d       |", num);
	printf("\n--------------------------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> ALTERAR CODIGO    |\n");
	printf("| 2 -> ALTERAR NOME      |\n");
	printf("| 3 -> ALTERAR SEMESTRE  |\n");
	printf("| 4 -> ALTERAR PROFESSOR |\n");
	printf("| 5 -> ALTERAR ALUNO     |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	getchar();

	return op;
}