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
				quantidadeDisciplina = mainDisciplina(Disciplina, quantidadeDisciplina, quantidadeProfessor, Professor, quantidadeAluno, Aluno);
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

	printf("\n--------------------------\n");
	printf("| ALTERANDO CADASTRO     |\n");
	printf("| ALUNO DE MATRICULA %d   |", num);
	printf("\n--------------------------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> ALTERAR NOME      |\n");
	printf("| 2 -> ALTERAR SEXO      |\n");
	printf("| 3 -> ALTERAR DATA      |\n");
	printf("| 4 -> ALTERAR CPF       |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	getchar();

	return op;
}

int menu_alterarCadastroP(int num) {

	int op = 0;

	printf("\n--------------------------\n");
	printf("| ALTERANDO CADASTRO     |\n");
	printf("| PROF DE MATRICULA %d    |", num);
	printf("\n--------------------------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> ALTERAR NOME      |\n");
	printf("| 2 -> ALTERAR SEXO      |\n");
	printf("| 3 -> ALTERAR DATA      |\n");
	printf("| 4 -> ALTERAR CPF       |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	getchar();

	return op;
}

int menu_alterarCadastroD(int num) {

	int op = 0;

	printf("\n--------------------------\n");
	printf("| ALTERANDO CADASTRO     |\n");
	printf("| DISCIPLINA DE NUM %d    |", num);
	printf("\n--------------------------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> ALTERAR CODIGO    |\n");
	printf("| 2 -> ALTERAR NOME      |\n");
	printf("| 3 -> ALTERAR SEMESTRE  |\n");
	printf("| 4 -> ALTERAR PROFESSOR |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	getchar();

	return op;
}

void descobreNomeMes(int mes, char strMes[]) {

	if(mes == 1) {
		strcpy(strMes, "JANEIRO");
	} else if(mes == 2) {
		strcpy(strMes, "FEVEREIRO");
	} else if(mes == 3) {
		strcpy(strMes, "MARCO");
	} else if(mes == 4) {
		strcpy(strMes, "ABRIL");
	} else if(mes == 5) {
		strcpy(strMes, "MAIO");
	} else if(mes == 6) {
		strcpy(strMes, "JUNHO");
	} else if(mes == 7) {
		strcpy(strMes, "JULHO");
	} else if(mes == 8) {
		strcpy(strMes, "AGOSTO");
	} else if(mes == 9) {
		strcpy(strMes, "SETEMBRO");
	} else if(mes == 10) {
		strcpy(strMes, "OUTUBRO");
	} else if(mes == 11) {
		strcpy(strMes, "NOVEMBRO");
	} else if(mes == 12) {
		strcpy(strMes, "DEZEMBRO");
	} 
}