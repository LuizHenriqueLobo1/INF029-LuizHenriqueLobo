#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

int main() {

	dados estud[TAM];
	int quantidadeAlunos = 0;

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
				quantidadeAlunos = mainAlunos(estud, quantidadeAlunos);
				break;
			}

			case 2: {
				printf("\nTRABALHANDO NA IMPLEMENTACAO!\n");
				break;
			}

			case 3: {
				printf("\nTRABALHANDO NA IMPLEMENTACAO!\n");
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