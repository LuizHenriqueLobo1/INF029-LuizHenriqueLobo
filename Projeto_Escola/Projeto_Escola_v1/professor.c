#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

int mainProfessor(dados professor[], int qtdProfessor) {

	int opcao = 0;
	int flag = 1;
	int professorRemovido = 0;

	while(flag == 1) {

		opcao = menuProfessor();

		switch(opcao) {

			case 0: {
				flag = 0;
				printf("\nVOLTANDO PARA MENU PRINCIPAL!\n");
				break;
			}

			case 1: {
				if(qtdProfessor < TAM) {
					cadastrarProfessor(qtdProfessor, professor);
					qtdProfessor++;
					printf("\nPROFESSOR CADASTRADO COM SUCESSO!\n");
					break;
				} else {
					printf("\nQUANTIDADE MAXIMA DE PROFESSORES ATINGIDA!\n");
					break;
				}
			}

			case 2: {
				mostrarProfessor(qtdProfessor, professor);
				break;
			}

			case 3: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					alterarCadastroProfessor(qtdProfessor, professor);
				}	
				break;
			}

			case 4: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					professorRemovido = removerProfessor(qtdProfessor, professor);
					qtdProfessor--;
					printf("\nPROFESSOR %d REMOVIDO COM SUCESSO!\n", professorRemovido+1);
				}
				break;
			}

			default: {
				printf("\nOPCAO INVALIDA!\n");
				break;
			}
		}
	}

	return qtdProfessor;
}

int menuProfessor() {

	int op = 0;

	printf("\n----- MENU PROFESSOR -----\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> CADASTRAR PROF    |\n");
	printf("| 2 -> MOSTRAR PROFS     |\n");
	printf("| 3 -> ALTERAR CADASTRO  |\n");
	printf("| 4 -> RETIRAR CADASTRO  |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

void cadastrarProfessor(int qtdProfessor, dados professor[]) {

	printf("\n-------------------------\n");
	printf("| CADASTRANDO PROFESSOR |");
	printf("\n-------------------------\n");

	printf("\nDigite o numero de matricula: ");
	fgets(professor[qtdProfessor].matricula, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarMatricula(professor[qtdProfessor].matricula) != 1) {
			printf("\nMATRICULA INVALIDA! Digite novamente...\n");
			fgets(professor[qtdProfessor].matricula, 50, stdin);
		} else {
			break;
		}
	}

	printf("\nDigite o nome do professor (Ate 20 caracteres): ");
	fgets(professor[qtdProfessor].nome, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarNome(professor[qtdProfessor].nome) != 1) {
			printf("\nNOME INVALIDO! Digite novamente...\n");
			fgets(professor[qtdProfessor].nome, 50, stdin);
		} else {
			break;
		}
	}
	
	printf("\nDigite o sexo do professor (M, F ou O): ");
	scanf("%c", &professor[qtdProfessor].sexo);
	setbuf(stdin, NULL);
	while(1) {
		if(validarSexo(professor[qtdProfessor].sexo) != 1) {
			printf("\nSEXO INVALIDO! Digite novamente...\n");
			scanf("%c", &professor[qtdProfessor].sexo);
			setbuf(stdin, NULL);
		} else {
			break;
		}
	}

	printf("\nDigite a data de nascimento do professor (Somente os numeros): ");
	fgets(professor[qtdProfessor].data, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarData(professor[qtdProfessor].data) != 1) {
			printf("\nDATA INVALIDA! Digite novamente...\n");
			fgets(professor[qtdProfessor].data, 50, stdin);
		} else {
			break;
		}
	}

	printf("\nDigite o CPF do professor (Somente os numeros): ");
	fgets(professor[qtdProfessor].cpf, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarCPF(professor[qtdProfessor].cpf) != 1) {
			printf("\nCPF INVALIDO! Digite novamente...\n");
			fgets(professor[qtdProfessor].cpf, 50, stdin);
		} else {
			break;
		}
	}
}

void mostrarProfessor(int qtdProfessor, dados professor[]) {

	printf("\n-------------------------\n");
	printf("| LISTANDO PROFESSORES  |");
	printf("\n-------------------------\n");

	if(qtdProfessor <= 0) {
		printf("\nNENHUM PROFESSOR CADASTRADO!\n");
	} else {
		for(int i = 0; i < qtdProfessor; i++) {
		printf("\n--------- PROFESSOR %d ---------\n", i+1);
		printf("MATRICULA: %s", professor[i].matricula);
		printf("NOME: %s", professor[i].nome);
		printf("SEXO: %c", professor[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", professor[i].data);
		printf("CPF: %s", professor[i].cpf);
		printf("-------------------------------\n");
		}
	}
}

void alterarCadastroProfessor(int qtdProfessor, dados professor[]) {

	int op = 0;
	int num = 0;
	char novaMatricula[50];
	char novoNome[50];
	char novoSexo;
	char novaData[50];
	char novoCPF[50];

	mostrarProfessor(qtdProfessor, professor);

	printf("\nInforme o numero do professor para alterar o cadastro: ");
	scanf("%d", &num);
	setbuf(stdin, NULL);

	while(1) {
		if(num <= 0 || num > qtdProfessor) {
			printf("\nPROFESSOR NAO ENCONTRADO OU NAO REGISTRADO! Tente novamente...\n");
			scanf("%d", &num);
		} else {
			break;
		}
	}
	
	op = menu_alterarCadastroP(num);

	switch(op) {

		case 0: {
			printf("\nVOLTANDO AO MENU PROFESSOR!\n");
			break;
		}

		case 1: {
			printf("\nDigite a nova matricula: ");
			fgets(novaMatricula, 50, stdin);
			while(1) {
				if(validarMatricula(professor[num-1].matricula) != 1) {
					printf("\nMATRICULA INVALIDA! Tente novamente...\n");
					fgets(novaMatricula, 50, stdin);
				} else {
					strcpy(professor[num-1].matricula, novaMatricula);
					printf("\nMATRICULA ALTERADA COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 2: {
			printf("\nDigite o novo nome: ");
			fgets(novoNome, 50, stdin);
			while(1) {
				if(validarNome(professor[num-1].nome) != 1) {
					printf("\nNOME INVALIDO! Tente novamente...\n");
					fgets(novoNome, 50, stdin);
				} else {
					strcpy(professor[num-1].nome, novoNome);
					printf("\nNOME ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 3: {
			printf("\nDigite o novo sexo: ");
			scanf("%c", &novoSexo);
			while(1) {
				if(validarSexo(professor[num-1].sexo) != 1) {
					printf("\nSEXO INVALIDO! Tente novamente...\n");
					scanf("%c", &novoSexo);
				} else {
					professor[num-1].sexo = novoSexo;
					printf("\nSEXO ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 4: {
			printf("\nDigite a nova data de nascimento: ");
			fgets(novaData, 50, stdin);
			while(1) {
				if(validarData(professor[num-1].data) != 1) {
					printf("\nDATA DE NASCIMENTO INVALIDA! Tente novamente...\n");
					fgets(novaData, 50, stdin);
				} else {
					strcpy(professor[num-1].data, novaData);
					printf("\nDATA DE NASCIMENTO ALTERADA COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 5: {
			printf("\nDigite o novo CPF: ");
			fgets(novoCPF, 50, stdin);
			while(1) {
				if(validarCPF(professor[num-1].cpf) != 1) {
					printf("\nCPF INVALIDO! Tente novamente...\n");
					fgets(novaData, 50, stdin);
				} else {
					strcpy(professor[num-1].cpf, novoCPF);
					printf("\nCPF ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		default: {
			printf("\nVOLTANDO AO MENU PROFESSOR!\n");
			break;
		}

	}
}

int removerProfessor(int qtdProfessor, dados professor[]) {

	int i;
	int pos;

	mostrarProfessor(qtdProfessor, professor);

	printf("\nInforme o numero do professor para ser removido: ");
	scanf("%d", &pos);
	pos--;

	for(i = pos; i < qtdProfessor; i++) {
		strcpy(professor[i].matricula, professor[i+1].matricula);
		strcpy(professor[i].nome, professor[i+1].nome);
		professor[i].sexo = professor[i+1].sexo;
		strcpy(professor[i].data, professor[i+1].data);
		strcpy(professor[i].cpf, professor[i+1].cpf);
	}

	qtdProfessor--;

	mostrarProfessor(qtdProfessor, professor);

	return pos;
}