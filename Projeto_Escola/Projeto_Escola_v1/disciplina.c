#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "projeto_escola_adendos.h"

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
					printf("\nDISCIPLINA CADASTRADA COM SUCESSO!\n");
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
					if(cadastrarAlunoDisciplina(qtdDisciplina, disciplina, qtdAluno, aluno) == 1) {
						printf("\nALUNO CADASTRADO NA DISCIPLINA COM SUCESSO!\n");
					} else {
						printf("\nESTE ALUNO JA ESTA CADASTRADO NESTA DISCIPLINA!\n");
					}
				}
				break;
			}

			case 6: {
				mostrarDisciplinaComAluno(qtdDisciplina, disciplina, qtdProfessor, professor);
				break;
			}

			case 7: {
				if(qtdDisciplina <= 0 || disciplina[0].qtdAlunoCadastrado <= 0) {
					printf("\nNAO EXISTE DISCIPLINA OU ALUNO CADASTRADO EM DISCIPLINA!\n");
				} else {
					removerAlunoDisciplina(qtdDisciplina, disciplina);
					printf("\nALUNO REMOVIDO DA DISCIPLINA COM SUCESSO!\n");
				}
				break;
			}

			case 8: {
				if(qtdDisciplina <= 0 || disciplina[0].qtdAlunoCadastrado <= 0) {
					printf("\nNAO EXISTE DISCIPLINA OU ALUNO CADASTRADO EM DISCIPLINA!\n");
				} else {
					removerTodosAlunosDisciplina(qtdDisciplina, disciplina);
					printf("\nTODOS OS ALUNOS FORAM REMOVIDOS COM SUCESSO!\n");
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

	printf("\n-------- MENU DISCIPLINA --------\n");
	printf("| 0 -> SAIR                     |\n");
	printf("| 1 -> CADASTRAR DISC           |\n");
	printf("| 2 -> MOSTRAR DISCS            |\n");
	printf("| 3 -> ALTERAR DISC             |\n");
	printf("| 4 -> REMOVER DISC             |\n");
	printf("| 5 -> CADASTRAR ALUNO NA DISC  |\n");
	printf("| 6 -> MOSTRAR ALUNOS DA DISC   |\n");
	printf("| 7 -> REMOVER ALUNOS DA DISC   |\n");
	printf("| 8 -> REMOVER TODOS ALUNOS DISC|");
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
		if(validarCodigoDisciplina(disciplina[qtdDisciplina].codigo) != 1) { 
			printf("\nCODIGO INVALIDO! Digite novamente...\n");
			fgets(disciplina[qtdDisciplina].codigo, 50, stdin);
		} else {
			break;
		}
	}

	printf("\nDigite o nome da disciplina: ");
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

	printf("\nDigite o semestre da disciplina: ");
	scanf("%d", &disciplina[qtdDisciplina].semestre);
	setbuf(stdin, NULL);
	while(1) {
		if(validarSemestreDisciplina(disciplina[qtdDisciplina].semestre) != 1) {
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
		printf("\nNENHUMA DISCIPLINA CADASTRADA!\n");
	} else {
		for(int i = 0; i < qtdDisciplina; i++) {
			printf("\n------- DISCIPLINA %d -------\n", i+1);
			printf("CODIGO: %s", disciplina[i].codigo);
			printf("NOME: %s", disciplina[i].nome);
			printf("SEMESTRE: %d", disciplina[i].semestre);
			printf("\nNUM DO PROFESSOR: %d", disciplina[i].numProfessor);
			printf("\nNOME DO PROFESSOR: %s", professor[disciplina[i].numProfessor-1].nome);
			printf("----------------------------\n");
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
			printf("\nDISCIPLINA NAO ENCONTRADA OU REGISTRADA! Tente novamente...\n");
			scanf("%d", &num);
		} else {
			break;
		}
	}
	
	opcao = menu_alterarCadastroD(num);

	switch(opcao) {

		case 0: {
			printf("\nVOLTANDO AO MENU DISCIPLINA!\n");
			break;
		}

		case 1: {
			printf("\nDigite o novo codigo: ");
			fgets(novoCodigo, 50, stdin);
			setbuf(stdin, NULL);
			while(1) {
				if(validarCodigoDisciplina(novoCodigo) != 1) {
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
				if(validarSemestreDisciplina(novoSemestre) != 1) {
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
			printf("\nVOLTANDO AO MENU DISCIPLINA!\n");
			break;
		}
	}
}

int removerDisciplina(int qtdDisciplina, disc disciplina[]) {
		
	int pos = 0;

	printf("\nInforme o numero da disciplina para ser removida: ");
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

int cadastrarAlunoDisciplina(int qtdDisciplina, disc disciplina[], int qtdAluno, dados aluno[]) {

	int numA;
	int numD;
	int pAlunoCadastrado;
	int i;
	int retorno;

	printf("\n-----------------------------------\n");
	printf("| CADASTRANDO ALUNO NA DISCIPLINA |");
	printf("\n-----------------------------------\n");

	printf("\nDigite o numero da disciplina que deseja cadastrar um aluno: ");
	scanf("%d", &numD);
	while(1) {
		if(numD <= 0 || numD > qtdDisciplina) {
			printf("\nNUMERO INVALIDO! Tente novamente...\n");
			scanf("%d", &numD);
		} else if(disciplina[numD-1].qtdAlunoCadastrado == TAM) {
			printf("\nESTA DISCIPLINA ESTA LOTADA! Tente novamente...\n");
			scanf("%d", &numD);
		} else {
			break;
		}
	}
	numD--;

	pAlunoCadastrado = disciplina[numD].qtdAlunoCadastrado;
	
	printf("\nDigite o numero do aluno para ser cadastrado na disciplina: ");
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

	disciplina[numD].aluno[pAlunoCadastrado].matricula = aluno[numA].matricula;
	strcpy(disciplina[numD].aluno[pAlunoCadastrado].nome, aluno[numA].nome);
	disciplina[numD].aluno[pAlunoCadastrado].sexo = aluno[numA].sexo;
	strcpy(disciplina[numD].aluno[pAlunoCadastrado].data, aluno[numA].data);
	strcpy(disciplina[numD].aluno[pAlunoCadastrado].cpf, aluno[numA].cpf);

	if(pAlunoCadastrado <= 0) {
		retorno = 1;
	} else if(pAlunoCadastrado > 0) {
		for(i = 0; i < pAlunoCadastrado; i++) {
			if(aluno[numA].matricula == disciplina[numD].aluno[i].matricula) {
				retorno = -1;
				break;
			} else {
				retorno = 1;
			}
		}
	}
	
	if(retorno == 1)
		disciplina[numD].qtdAlunoCadastrado++;
		
	return retorno;
}

void mostrarDisciplinaComAluno(int qtdDisciplina, disc disciplina[], int qtdProfessor, dados professor[]) {

	int pAlunoCadastrado;

	printf("\n-----------------------------------\n");
	printf("| LISTANDO DISCIPLINAS COM ALUNOS |");
	printf("\n-----------------------------------\n");

	if(qtdDisciplina <= 0) {
		printf("\nNENHUMA DISCIPLINA CADASTRADA!\n");
	} else {
		for(int i = 0; i < qtdDisciplina; i++) {
			pAlunoCadastrado = disciplina[i].qtdAlunoCadastrado;	
			printf("\n------------- DISCIPLINA %d -------------\n", i+1);
			printf("CODIGO: %s", disciplina[i].codigo);
			printf("NOME: %s", disciplina[i].nome);
			printf("SEMESTRE: %d", disciplina[i].semestre);
			printf("\nNUM DO PROFESSOR: %d", disciplina[i].numProfessor);
			printf("\nNOME DO PROFESSOR: %s", professor[disciplina[i].numProfessor-1].nome);
			printf("QTD ALUNOS CADASTRADOS NA DISCIPLINA: %d\n", pAlunoCadastrado);
			for(int y = 0; y < pAlunoCadastrado; y++) {
				printf("NOME DO ALUNO %d: %s", y+1, disciplina[i].aluno[y].nome);
			}
			printf("----------------------------------------\n");
		}
	}
}

void removerAlunoDisciplina(int qtdDisciplina, disc disciplina[]) {

	int numD;
	int numA;
	int pAlunoCadastrado;

	printf("\nDigite o numero da disciplina que deseja remover um aluno: ");
	scanf("%d", &numD);
	while(1) {
		if(numD <= 0 || numD > qtdDisciplina) {
			printf("\nNUMERO INVALIDO! Digite novamente...\n");
			scanf("%d", &numD);
		} else {
			break;
		}
	}
	numD--;

	printf("\nDigite o numero do aluno que deseja remover da disciplina: ");
	scanf("%d", &numA);
	while(1) {
		if(numA <= 0 || numA > disciplina[numD].qtdAlunoCadastrado) {
			printf("\nNUMERO INVALIDO! Digite novamente...\n");
			scanf("%d", &numA);
		} else {
			break;
		}
	}
	numA--;

	pAlunoCadastrado = disciplina[numD].qtdAlunoCadastrado;

	for(int i = numA; i < pAlunoCadastrado; i++) {
		disciplina[numD].aluno[numA].matricula = disciplina[i].aluno[i+1].matricula;
		strcpy(disciplina[numD].aluno[numA].nome, disciplina[i].aluno[i+1].nome);
		disciplina[numD].aluno[numA].sexo = disciplina[i].aluno[i+1].sexo;
		strcpy(disciplina[numD].aluno[numA].data, disciplina[i].aluno[i+1].data);
		strcpy(disciplina[numD].aluno[numA].cpf, disciplina[i].aluno[i+1].cpf);
	}

	disciplina[numD].qtdAlunoCadastrado--;
}

void removerTodosAlunosDisciplina(int qtdDisciplina, disc disciplina[]) {

	int numD;

	printf("\nDigite o numero da disciplina que deseja remover todos os alunos: ");
	scanf("%d", &numD);
	while(1) {
		if(numD <= 0 || numD > qtdDisciplina) {
			printf("\nNUMERO INVALIDO! Digite novamente...\n");
			scanf("%d", &numD);
		} else {
			break;
		}
	}
	numD--;

	disciplina[numD].qtdAlunoCadastrado = 0;
}