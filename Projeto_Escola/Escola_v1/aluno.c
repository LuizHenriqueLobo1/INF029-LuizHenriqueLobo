#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5

#include "projeto_escola_adendos.h"

int main() {

	dados estud[TAM];
	int quantidadeAlunos = 0;
	int opcao = 0;
	int flag = 1;
	int alunoRemovido = 0;

	while(flag == 1) {

		opcao = menuAlunos(opcao);

		switch(opcao) {

			case 0: {
				flag = 0;
				printf("\nPROGRAMA FINALIZADO!\n");
				break;
			}

			case 1: {
				if(quantidadeAlunos < 5) {
					cadastrarAlunos(quantidadeAlunos, estud);
					quantidadeAlunos++;
					printf("\nALUNO CADASTRADO COM SUCESSO!\n");
					break;
				} else {
					printf("\nQUANTIDADE MAXIMA DE ALUNOS ATINGIDA!\n");
					break;
				}
			}

			case 2: {
				mostrarAlunos(quantidadeAlunos, estud);
				break;
			}

			case 3: {
				if(quantidadeAlunos <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					alterarCadastroAlunos(quantidadeAlunos, estud);
				}	
				break;
			}

			case 4: {
				if(quantidadeAlunos <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					alunoRemovido = removerAluno(quantidadeAlunos, estud);
					quantidadeAlunos--;
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

	return 0;
}

int menuAlunos(int op) {

	printf("\n---------- MENU ----------\n");
	printf("| 0 -> SAIR              |\n");
	printf("| 1 -> CADASTRAR ALUNO   |\n");
	printf("| 2 -> MOSTRAR ALUNOS    |\n");
	printf("| 3 -> ALTERAR CADASTRO  |\n");
	printf("| 4 -> RETIRAR CADASTRO  |");
	printf("\n--------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

void cadastrarAlunos(int qtdAlunos, dados estudante[]) {

	printf("\n---------------------\n");
	printf("| CADASTRANDO ALUNO |");
	printf("\n---------------------\n");

	printf("\nDigite o numero de matricula: ");
	fgets(estudante[qtdAlunos].matricula, 50, stdin);
	setbuf(stdin, NULL);
	while(1) {
		if(validarMatricula(estudante[qtdAlunos].matricula) != 1) {
			printf("\nMATRICULA INVALIDA! Digite novamente...\n");
			fgets(estudante[qtdAlunos].matricula, 50, stdin);
		} else {
			break;
		}
	}

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
}

void mostrarAlunos(int qtdAlunos, dados estudante[]) {

	printf("\n--------------------\n");
	printf("| LISTANDO ALUNOS  |");
	printf("\n--------------------\n");

	if(qtdAlunos <= 0) {
		printf("\nNENHUM ALUNO CADASTRADO!\n");
	} else {
		for(int i = 0; i < qtdAlunos; i++) {
		printf("\n---------- ALUNO %d ----------\n", i+1);
		printf("MATRICULA: %s", estudante[i].matricula);
		printf("NOME: %s", estudante[i].nome);
		printf("SEXO: %c", estudante[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", estudante[i].data);
		printf("CPF: %s", estudante[i].cpf);
		printf("-----------------------------\n");
		}
	}
}

void alterarCadastroAlunos(int qtdAlunos, dados estudante[]) {

	int op = 0;
	int num = 0;
	char novaMatricula[50];
	char novoNome[50];
	char novoSexo;
	char novaData[50];
	char novoCPF[50];

	mostrarAlunos(qtdAlunos, estudante);

	printf("\nInforme o numero do aluno para alterar o cadastro: ");
	scanf("%d", &num);
	setbuf(stdin, NULL);

	while(1) {
		if(num <= 0 || num > qtdAlunos) {
			printf("\nALUNO NAO ENCONTRADO OU NAO REGISTRADO! Tente novamente...\n");
			scanf("%d", &num);
		} else {
			break;
		}
	}
	
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

	switch(op) {

		case 0: {
			printf("\nVOLTANDO AO MENU PRINCIPAL!\n");
			break;
		}

		case 1: {
			printf("\nDigite a nova matricula: ");
			fgets(novaMatricula, 50, stdin);
			while(1) {
				if(validarMatricula(estudante[num-1].matricula) != 1) {
					printf("\nMATRICULA INVALIDA! Tente novamente...\n");
					fgets(novaMatricula, 50, stdin);
				} else {
					strcpy(estudante[num-1].matricula, novaMatricula);
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
				if(validarNome(estudante[num-1].nome) != 1) {
					printf("\nNOME INVALIDO! Tente novamente...\n");
					fgets(novoNome, 50, stdin);
				} else {
					strcpy(estudante[num-1].nome, novoNome);
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
				if(validarSexo(estudante[num-1].sexo) != 1) {
					printf("\nSEXO INVALIDO! Tente novamente...\n");
					scanf("%c", &novoSexo);
				} else {
					estudante[num-1].sexo = novoSexo;
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
				if(validarData(estudante[num-1].data) != 1) {
					printf("\nDATA DE NASCIMENTO INVALIDA! Tente novamente...\n");
					fgets(novaData, 50, stdin);
				} else {
					strcpy(estudante[num-1].data, novaData);
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
				if(validarCPF(estudante[num-1].cpf) != 1) {
					printf("\nCPF INVALIDO! Tente novamente...\n");
					fgets(novaData, 50, stdin);
				} else {
					strcpy(estudante[num-1].cpf, novoCPF);
					printf("\nCPF ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		default: {
			printf("\nVOLTANDO AO MENU PRINCIPAL!\n");
			break;
		}

	}
}

int removerAluno(int qtdAlunos, dados estudante[]) {

	int i;
	int pos;

	mostrarAlunos(qtdAlunos, estudante);

	printf("\nInforme o numero do aluno para ser removido: ");
	scanf("%d", &pos);
	pos--;

	for(i = pos; i < qtdAlunos; i++) {
		strcpy(estudante[i].matricula, estudante[i+1].matricula);
		strcpy(estudante[i].nome, estudante[i+1].nome);
		estudante[i].sexo = estudante[i+1].sexo;
		strcpy(estudante[i].data, estudante[i+1].data);
		strcpy(estudante[i].cpf, estudante[i+1].cpf);
	}

	qtdAlunos--;

	mostrarAlunos(qtdAlunos, estudante);

	return pos;
}