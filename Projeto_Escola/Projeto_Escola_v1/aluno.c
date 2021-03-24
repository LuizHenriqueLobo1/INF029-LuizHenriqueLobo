#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

int mainAluno(dados aluno[], int qtdAluno) {

	int opcao = 0;
	int flag = 1;
	int alunoRemovido = 0;

	while(flag == 1) {

		opcao = menuAluno();

		switch(opcao) {

			case 0: {
				flag = 0;
				printf("\nVOLTANDO PARA MENU PRINCIPAL!\n");
				break;
			}

			case 1: {
				if(qtdAluno < TAM) {
					cadastrarAluno(qtdAluno, aluno);
					qtdAluno++;
					printf("\nALUNO CADASTRADO COM SUCESSO!\n");
					break;
				} else {
					printf("\nQUANTIDADE MAXIMA DE ALUNOS ATINGIDA!\n");
					break;
				}
			}

			case 2: {
				mostrarAluno(qtdAluno, aluno);
				break;
			}

			case 3: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					alterarCadastroAluno(qtdAluno, aluno);
				}	
				break;
			}

			case 4: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					alunoRemovido = removerAluno(qtdAluno, aluno);
					qtdAluno--;
					printf("\nALUNO %d REMOVIDO COM SUCESSO!\n", alunoRemovido+1);
				}
				break;
			}

			default: {
				printf("\nOPCAO INVALIDA!\n");
				break;
			}
		}
	}

	return qtdAluno;
}

int menuAluno() {

	int op = 0;

	printf("\n------- MENU ALUNO -------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> CADASTRAR ALUNO   |\n");
	printf("| 2 -> MOSTRAR ALUNOS    |\n");
	printf("| 3 -> ALTERAR ALUNO     |\n");
	printf("| 4 -> RETIRAR ALUNO     |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

void cadastrarAluno(int qtdAluno, dados aluno[]) {

	printf("\n---------------------\n");
	printf("| CADASTRANDO ALUNO |");
	printf("\n---------------------\n");

	printf("\nDigite o numero de matricula: ");
	fgets(aluno[qtdAluno].matricula, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarMatricula(aluno[qtdAluno].matricula) != 1) {
			printf("\nMATRICULA INVALIDA! Digite novamente...\n");
			fgets(aluno[qtdAluno].matricula, 50, stdin);
		} else {
			break;
		}
	}

	printf("\nDigite o nome do aluno (Ate 20 caracteres): ");
	fgets(aluno[qtdAluno].nome, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarNome(aluno[qtdAluno].nome) != 1) {
			printf("\nNOME INVALIDO! Digite novamente...\n");
			fgets(aluno[qtdAluno].nome, 50, stdin);
		} else {
			break;
		}
	}
	
	printf("\nDigite o sexo do aluno (M, F ou O): ");
	scanf("%c", &aluno[qtdAluno].sexo);
	setbuf(stdin, NULL);
	while(1) {
		if(validarSexo(aluno[qtdAluno].sexo) != 1) {
			printf("\nSEXO INVALIDO! Digite novamente...\n");
			scanf("%c", &aluno[qtdAluno].sexo);
			setbuf(stdin, NULL);
		} else {
			break;
		}
	}

	printf("\nDigite a data de nascimento do aluno (Somente os numeros): ");
	fgets(aluno[qtdAluno].data, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarData(aluno[qtdAluno].data) != 1) {
			printf("\nDATA INVALIDA! Digite novamente...\n");
			fgets(aluno[qtdAluno].data, 50, stdin);
		} else {
			break;
		}
	}

	printf("\nDigite o CPF do aluno (Somente os numeros): ");
	fgets(aluno[qtdAluno].cpf, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarCPF(aluno[qtdAluno].cpf) != 1) {
			printf("\nCPF INVALIDO! Digito novamente...\n");
			fgets(aluno[qtdAluno].cpf, 50, stdin);
		} else {
			break;
		}
	}
}

void mostrarAluno(int qtdAluno, dados aluno[]) {

	printf("\n--------------------\n");
	printf("| LISTANDO ALUNOS  |");
	printf("\n--------------------\n");

	if(qtdAluno <= 0) {
		printf("\nNENHUM ALUNO CADASTRADO!\n");
	} else {
		for(int i = 0; i < qtdAluno; i++) {
		printf("\n---------- ALUNO %d ----------\n", i+1);
		printf("MATRICULA: %s", aluno[i].matricula);
		printf("NOME: %s", aluno[i].nome);
		printf("SEXO: %c", aluno[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", aluno[i].data);
		printf("CPF: %s", aluno[i].cpf);
		printf("-----------------------------\n");
		}
	}
}

void alterarCadastroAluno(int qtdAluno, dados aluno[]) {

	int op = 0;
	int num = 0;
	char novaMatricula[50];
	char novoNome[50];
	char novoSexo;
	char novaData[50];
	char novoCPF[50];

	mostrarAluno(qtdAluno, aluno);

	printf("\nInforme o numero do aluno para alterar o cadastro: ");
	scanf("%d", &num);
	setbuf(stdin, NULL);

	while(1) {
		if(num <= 0 || num > qtdAluno) {
			printf("\nALUNO NAO ENCONTRADO OU NAO REGISTRADO! Tente novamente...\n");
			scanf("%d", &num);
		} else {
			break;
		}
	}
	
	op = menu_alterarCadastroA(num);

	switch(op) {

		case 0: {
			printf("\nVOLTANDO AO MENU ALUNO!\n");
			break;
		}

		case 1: {
			printf("\nDigite a nova matricula: ");
			fgets(novaMatricula, 50, stdin);
			while(1) {
				if(validarMatricula(aluno[num-1].matricula) != 1) {
					printf("\nMATRICULA INVALIDA! Tente novamente...\n");
					fgets(novaMatricula, 50, stdin);
				} else {
					strcpy(aluno[num-1].matricula, novaMatricula);
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
				if(validarNome(aluno[num-1].nome) != 1) {
					printf("\nNOME INVALIDO! Tente novamente...\n");
					fgets(novoNome, 50, stdin);
				} else {
					strcpy(aluno[num-1].nome, novoNome);
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
				if(validarSexo(aluno[num-1].sexo) != 1) {
					printf("\nSEXO INVALIDO! Tente novamente...\n");
					scanf("%c", &novoSexo);
				} else {
					aluno[num-1].sexo = novoSexo;
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
				if(validarData(aluno[num-1].data) != 1) {
					printf("\nDATA DE NASCIMENTO INVALIDA! Tente novamente...\n");
					fgets(novaData, 50, stdin);
				} else {
					strcpy(aluno[num-1].data, novaData);
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
				if(validarCPF(aluno[num-1].cpf) != 1) {
					printf("\nCPF INVALIDO! Tente novamente...\n");
					fgets(novaData, 50, stdin);
				} else {
					strcpy(aluno[num-1].cpf, novoCPF);
					printf("\nCPF ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		default: {
			printf("\nVOLTANDO AO MENU ALUNO!\n");
			break;
		}

	}
}

int removerAluno(int qtdAluno, dados aluno[]) {

	int i;
	int pos;

	mostrarAluno(qtdAluno, aluno);

	printf("\nInforme o numero do aluno para ser removido: ");
	scanf("%d", &pos);
	pos--;

	for(i = pos; i < qtdAluno; i++) {
		strcpy(aluno[i].matricula, aluno[i+1].matricula);
		strcpy(aluno[i].nome, aluno[i+1].nome);
		aluno[i].sexo = aluno[i+1].sexo;
		strcpy(aluno[i].data, aluno[i+1].data);
		strcpy(aluno[i].cpf, aluno[i+1].cpf);
	}

	qtdAluno--;

	mostrarAluno(qtdAluno, aluno);

	return pos;
}