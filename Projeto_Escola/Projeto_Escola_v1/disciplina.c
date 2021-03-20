#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

// Em processo de implementação

int mainDisciplina(disc disciplina[], int qtdDisciplina, int numProfessor,  int numAluno, dados professor[], dados aluno[]) {

	int opcao = 0;
	int flag = 1;

	while(flag == 1) {

		opcao = menuDisciplina();

		switch(opcao) {

			case 0: {
				printf("\nVOLTANDO PARA O MENU PRINCIPAL!\n");
				flag = 0;
				break;
			}

			case 1: {
				if(cadastrarDisciplina(qtdDisciplina, disciplina, numProfessor, numAluno) == 1) {
					qtdDisciplina++;
					printf("\nDISCPLINA CADASTRADA COM SUCESSO!\n");
				} else {
					printf("\nPRECISA-SE DE ALUNOS E PROFESSORES REGISTRADOS PARA CONTINUAR COM ESTA OPERACAO!\n");
				}
				break;
			}

			case 2: {
				mostrarDisciplina(qtdDisciplina, disciplina, numProfessor, numAluno, professor, aluno);
				break;
			}

			case 3: {
				if(qtdDisciplina <= 0) {
					printf("\nNENHUMA DISCIPLINA CADASTRADA!\n");
				} else {
					alterarCadastroDisciplina(qtdDisciplina, disciplina, numProfessor, numAluno);
				}
				break;
			}

			default: {
				printf("\nOPCAO INVALIDA!\n");
				break;
			}
		}
	}

	return qtdDisciplina;
}

int menuDisciplina() {
	
	int op = 0;

	printf("\n----- MENU DISCIPLINA -----\n");
	printf("| 0 -> SAIR               |\n");
	printf("| 1 -> CADASTRAR DISC     |\n");
	printf("| 2 -> MOSTRAR DISCS      |\n");
	printf("| 3 -> ALTERAR DISC       |\n");
	printf("| 4 -> RETIRAR DISC       |");
	printf("\n---------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

int cadastrarDisciplina(int qtdDisciplina, disc disciplina[], int numProfessor, int numAluno) {

	int auxProfessor = numProfessor;
	int auxAluno = numAluno;

	if(numAluno <= 0 || numProfessor <= 0) {
		return -1;
	} else {
		printf("\n--------------------------\n");
		printf("| CADASTRANDO DISCIPLINA |");
		printf("\n--------------------------\n");

		printf("\nDigite o codigo da disciplina: ");
		fgets(disciplina[qtdDisciplina].codigo, 50, stdin);
		setbuf(stdin, NULL);
		while(1) {
			if(validarMatricula(disciplina[qtdDisciplina].codigo) != 1) { 
				printf("\nCODIGO INVALIDO! Digite novamente...\n");
				fgets(disciplina[qtdDisciplina].codigo, 50, stdin);
			} else {
				break;
			}
		}

		printf("\nDigite o nome da discplina: ");
		fgets(disciplina[qtdDisciplina].nome, 50, stdin);
		setbuf(stdin, NULL);
		while(1) {
			if(validarNomeDisciplina(disciplina[qtdDisciplina].nome) != 1) {
				printf("\nNOME INVALIDO! Digite novamente...\n");
				fgets(disciplina[qtdDisciplina].nome, 50, stdin);
			} else {
				break;
			}
		}

		printf("\nDigite o semestre da discplina: ");
		scanf("%d", &disciplina[qtdDisciplina].semestre);
		setbuf(stdin, NULL);
		while(1) {
			if(validarSemestre(disciplina[qtdDisciplina].semestre) != 1) {
				printf("\nSEMESTRE INVALIDO! Digite novamente...\n");
				scanf("%d", &disciplina[qtdDisciplina].semestre);
			} else {
				break;
			}
		}

		printf("\nDigite o numero do professor da disciplina: ");
		scanf("%d", &numProfessor);
		setbuf(stdin, NULL);
		while(1) {
			if(numProfessor <= 0 || numProfessor > auxProfessor) {
				printf("\nNUMERO DO PROFESSOR INVALIDO! Digite novamente...\n");
				scanf("%d", &numProfessor);
			} else {
				break;
			}
		}

		printf("\nDigite o numero do aluno: ");
		scanf("%d", &numAluno);
		while(1) {
			if(numAluno <= 0 || numAluno > auxAluno) {
				printf("\nNUMERO DO ALUNO INVALIDO! Digite novamente...\n");
				scanf("%d", &numAluno);
			} else {
				break;
			}
		}
		
		return 1;
	}
}

void mostrarDisciplina(int qtdDisciplina, disc disciplina[], int numProfessor, int numAluno, dados professor[], dados aluno[]) {

	printf("\n------------------------\n");
	printf("| LISTANDO DISCIPLINAS |");
	printf("\n------------------------\n");

	if(qtdDisciplina <= 0) {
		printf("\nNENHUMA DISCPLINA CADASTRADA!\n");
	} else {
		for(int i = 0; i < qtdDisciplina; i++) {
			printf("\n------- DISCPLINA %d -------\n", i+1);
			printf("CODIGO: %s", disciplina[i].codigo);
			printf("NOME: %s", disciplina[i].nome);
			printf("SEMESTRE: %d", disciplina[i].semestre);
			//printf("\nNUM DO PROFESSOR: %d", numProfessor);
			printf("\nNOME DO PROFESSOR: %s", professor[numProfessor-1].nome);
			//printf("NUM DO ALUNO: %d", numAluno);
			printf("NOME DO ALUNO: %s", aluno[numAluno-1].nome);
			printf("---------------------------\n");
		}
	}
}

void alterarCadastroDisciplina(int qtdDisciplina, disc disciplina[], int numAluno, int numProfessor) {

	int num = 0;
	int opcao = 0;
	char novoCodigo[50];
	char novoNome[50];
	int novoSemestre = 0;

	printf("\nInforme o numero da disciplina para alterar o cadastro: ");
	scanf("%d", &num);

	while(1) {
		if(num <= 0 || num > qtdDisciplina) {
			printf("\nDISCPLINA NAO ENCONTRADA OU REGISTRADA! Tente novamente...\n");
			scanf("%d", &num);
		} else {
			break;
		}
	}
	
	opcao = menu_alterarCadastroD(num);

	switch(opcao) {

		case 0: {
			printf("\nVOLTANDO AO MENU DISCPLINA!\n");
			break;
		}

		case 1: {
			printf("\nDigite o novo codigo: ");
			fgets(novoCodigo, 50, stdin);
			setbuf(stdin, NULL);
			while(1) {
				if(validarMatricula(novoCodigo) != 1) {
					printf("\nCODIGO INVALIDO! Digite novamente...\n");
					fgets(novoCodigo, 50, stdin);
				} else {
					strcpy(disciplina[num-1].codigo, novoCodigo);
					printf("\nCODIGO ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 2: {
			printf("\nDigite o novo nome: ");
			fgets(novoNome, 50, stdin);
			setbuf(stdin, NULL);
			while(1) {
				if(validarNomeDisciplina(novoNome) != 1) {
					printf("\nNOME INVALIDO! Digite novamente...\n");
					fgets(novoNome, 50, stdin);
				} else {
					strcpy(disciplina[num-1].nome, novoNome);
					printf("\nNOME ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 3: {
			printf("\nDigite o novo semestre: ");
			scanf("%d", &novoSemestre);
			setbuf(stdin, NULL);
			while(1) {
				if(validarSemestre(novoSemestre) != 1) {
					printf("\nSEMESTRE INVALIDO! Digite novamente...\n");
					scanf("%d", &novoSemestre);
				} else {
					disciplina[num-1].semestre = novoSemestre;
					printf("\nSEMESTRE ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		default: {
			printf("\nVOLTANDO AO MENU DISCPLINA!\n");
			break;
		}
	}
}