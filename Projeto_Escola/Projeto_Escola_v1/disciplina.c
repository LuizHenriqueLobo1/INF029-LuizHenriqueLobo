#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

// Em processo de implementação

int mainDisciplina(disc disciplina[], int qtdDisciplina, int qtdProfessor, dados professor[], int qtdAluno, dados aluno[]) {

	int opcao = 0;
	int flag = 1;
	int disciplinaRemovida = 0;

	while(flag == 1) {

		opcao = menuDisciplina();

		switch(opcao) {

			case 0: {
				printf("\nVOLTANDO PARA O MENU PRINCIPAL!\n");
				flag = 0;
				break;
			}

			case 1: {
				if(qtdProfessor <= 0) {
					printf("\nPRECISA-SE DE AO MENOS UM PROFESSOR REGISTRADO PARA CONTINUAR!\n");
				} else {
					cadastrarDisciplina(qtdDisciplina, disciplina, qtdProfessor);
					qtdDisciplina++;
					printf("\nDISCPLINA CADASTRADA COM SUCESSO!\n");
				}	
				break;
			}

			case 2: {
				mostrarDisciplina(qtdDisciplina, disciplina, qtdProfessor, professor);
				break;
			}

			case 3: {
				if(qtdDisciplina <= 0) {
					printf("\nNENHUMA DISCIPLINA CADASTRADA!\n");
				} else {
					alterarCadastroDisciplina(qtdDisciplina, disciplina, qtdProfessor);
				}
				break;
			}

			case 4: {
				if(qtdDisciplina <= 0) {
					printf("\nNENHUMA DISCIPLINA CADASTRADA!\n");
				} else {
					disciplinaRemovida = removerDisciplina(qtdDisciplina, disciplina);
					qtdDisciplina--;
					printf("\nDISCIPLINA %d REMOVIDA COM SUCESSO!\n", disciplinaRemovida+1);
				}
				break;
			}

			case 5: {
				if(qtdDisciplina <= 0 || qtdAluno <= 0) {
					printf("\nPRECISA-SE DE AO MENOS UMA DISCIPLINA E UM ALUNO REGISTRADO PARA CONTINUAR!\n");
				} else {
					cadastrarAlunoDisciplina(qtdDisciplina, disciplina, qtdAluno, aluno);
					printf("\nALUNO CADASTRADO NA DISCPLINA COM SUCESSO!\n");
				}
				break;
			}

			case 6: {
				mostrarDisciplinaComAluno(qtdDisciplina, disciplina, qtdProfessor, professor);
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

	printf("\n-------- MENU DISCIPLINA --------\n");
	printf("| 0 -> SAIR                     |\n");
	printf("| 1 -> CADASTRAR DISC           |\n");
	printf("| 2 -> MOSTRAR DISCS            |\n");
	printf("| 3 -> ALTERAR DISC             |\n");
	printf("| 4 -> RETIRAR DISC             |\n");
	printf("| 5 -> CADASTRAR ALUNO NA DISC  |\n");
	printf("| 6 -> MOSTRAR ALUNOS DA DISC   |");
	printf("\n---------------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

void cadastrarDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor) {

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
	scanf("%d", &disciplina[qtdDisciplina].numProfessor);
	while(1) {
		if(disciplina[qtdDisciplina].numProfessor <= 0 || disciplina[qtdDisciplina].numProfessor > qtdProfessor) {
			printf("\nNUMERO INVALIDO! Digite novamente...\n");
			scanf("%d", &disciplina[qtdDisciplina].numProfessor);
		} else {
			break;
		}
	}

	disciplina[qtdDisciplina].qtdAlunoCadastrado = 0;
}

void mostrarDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor, dados professor[]) {

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
			printf("\nNUM DO PROFESSOR: %d", disciplina[i].numProfessor);
			printf("\nNOME DO PROFESSOR: %s", professor[disciplina[i].numProfessor-1].nome);
			printf("---------------------------\n");
		}
	}
}

void alterarCadastroDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor) {

	int num = 0;
	int opcao = 0;
	char novoCodigo[50];
	char novoNome[50];
	int novoSemestre = 0;
	int novoNumProfessor = 0;
	int novoNumAluno = 0;

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
		
		case 4: {
			printf("\nDigite o numero do novo professor: ");
			scanf("%d", &novoNumProfessor);
			setbuf(stdin, NULL);
			while(1) {
				if(novoNumProfessor <= 0 || novoNumProfessor > qtdProfessor) {
					printf("\nNUMERO INVALIDO! Digite novamente...\n");
					scanf("%d", &disciplina[qtdDisciplina].numProfessor);
				} else {
					disciplina[num-1].numProfessor = novoNumProfessor;
					printf("\nPROFESSOR ALTERADO COM SUCESSO!\n");
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

int removerDisciplina(int qtdDisciplina, disc disciplina[]) {
		
	int pos = 0;

	printf("\nInforme o numero da discplina para ser removida: ");
	scanf("%d", &pos);
	pos--;

	for(int i = pos; i < qtdDisciplina ; i++) {
		strcpy(disciplina[i].codigo, disciplina[i+1].codigo);
		strcpy(disciplina[i].nome, disciplina[i+1].nome);
		disciplina[i].semestre = disciplina[i+1].semestre;
		disciplina[i].numProfessor = disciplina[i+1].numProfessor;
	}

	qtdDisciplina--;

	return pos;
}

void cadastrarAlunoDisciplina(int qtdDisciplina, disc disciplina[], int qtdAluno, dados aluno[]) {

	int numA;
	int numD;
	int pAlunoCadastrado;

	printf("\n----------------------------------\n");
	printf("| CADASTRANDO ALUNO NA DISCPLINA |");
	printf("\n----------------------------------\n");

	printf("\nDigite o numero da disciplina que deseja cadastrar um aluno: ");
	scanf("%d", &numD);
	while(1) {
		if(numD <= 0 || numD > qtdDisciplina) {
			printf("\nNUMERO INVALIDO! Tente novamente...\n");
			scanf("%d", &numD);
		} else {
			break;
		}
	}
	numD--;

	pAlunoCadastrado = disciplina[numD].qtdAlunoCadastrado;

	printf("\nDigite o numero do aluno para ser cadastrado na discplina: ");
	scanf("%d", &numA);
	while(1) {
		if(numA <= 0 || numA > qtdAluno) {
			printf("\nNUMERO INVALIDO! Tente novamente...\n");
			scanf("%d", &numA);
		} else {
			break;
		}
	}
	numA--;

	strcpy(disciplina[numD].aluno[pAlunoCadastrado].matricula, aluno[numA].matricula);
	strcpy(disciplina[numD].aluno[pAlunoCadastrado].nome, aluno[numA].nome);
	disciplina[numD].aluno[pAlunoCadastrado].sexo = aluno[numA].sexo;
	strcpy(disciplina[numD].aluno[pAlunoCadastrado].data, aluno[numA].data);
	strcpy(disciplina[numD].aluno[pAlunoCadastrado].cpf, aluno[numA].cpf);

	disciplina[numD].qtdAlunoCadastrado++;
}

void mostrarDisciplinaComAluno(int qtdDisciplina, disc disciplina[], int qtdProfessor, dados professor[]) {

	int pAlunoCadastrado;

	printf("\n-----------------------------------\n");
	printf("| LISTANDO DISCIPLINAS COM ALUNOS |");
	printf("\n-----------------------------------\n");

	if(qtdDisciplina <= 0) {
		printf("\nNENHUMA DISCPLINA CADASTRADA!\n");
	} else {
		for(int i = 0; i < qtdDisciplina; i++) {
			pAlunoCadastrado = disciplina[i].qtdAlunoCadastrado;	
			printf("\n------------- DISCPLINA %d -------------\n", i+1);
			printf("CODIGO: %s", disciplina[i].codigo);
			printf("NOME: %s", disciplina[i].nome);
			printf("SEMESTRE: %d", disciplina[i].semestre);
			printf("\nNUM DO PROFESSOR: %d", disciplina[i].numProfessor);
			printf("\nNOME DO PROFESSOR: %s", professor[disciplina[i].numProfessor-1].nome);
			printf("QTD ALUNOS CADASTRADOS NA DISCPLINA: %d\n", pAlunoCadastrado);
			for(int y = 0; y < pAlunoCadastrado; y++) {
				printf("NOME DO ALUNO %d: %s", y+1, disciplina[i].aluno[y].nome);
			}
			printf("---------------------------------------\n");
		}
	}
}