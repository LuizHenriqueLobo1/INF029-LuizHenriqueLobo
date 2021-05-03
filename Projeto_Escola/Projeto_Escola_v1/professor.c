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
					professor[-1].matricula = 0;
					professor[qtdProfessor-1].matricula = 0;
					professor[qtdProfessor-1].matricula = professor[qtdProfessor-2].matricula + 1;
					printf("\nPROFESSOR CADASTRADO COM SUCESSO!\n");
				} else {
					printf("\nQUANTIDADE MAXIMA DE PROFESSORES ATINGIDA!\n");
				}
				break;
			}

			case 2: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					mostrarProfessor(qtdProfessor, professor);
				}		
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

			case 5: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					listarProfessorAniversariante(qtdProfessor, professor);
				}
				break;
			}

			case 6: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					listarProfessorSexo(qtdProfessor, professor);
				}
				break;
			}

			case 7: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					listarProfessorOrdemAlfabetica(qtdProfessor, professor);
				}
				break;
			}

			case 8: {
				if(qtdProfessor <= 0) {
					printf("\nNENHUM PROFESSOR CADASTRADO!\n");
				} else {
					qtdProfessor = apagarTodosProfessores(qtdProfessor);
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

	printf("\n-------- MENU PROFESSOR --------\n");
	printf("| 0 -> SAIR                    |\n");
	printf("| 1 -> CADASTRAR PROFESSOR     |\n");
	printf("| 2 -> MOSTRAR PROFESSORES     |\n");
	printf("| 3 -> ALTERAR PROFESSOR       |\n");
	printf("| 4 -> REMOVER PROFESSOR       |\n");
	printf("| 5 -> ANIVERSARIANTES DO MES  |\n");
	printf("| 6 -> MOSTRAR PROFS POR SEXO  |\n");
	printf("| 7 -> PROFS EM ORDEM ALFABET  |\n");
	printf("| 8 -> APAGAR TODOS OS PROFS   |");
	printf("\n--------------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

void cadastrarProfessor(int qtdProfessor, dados professor[]) {

	printf("\n-------------------------\n");
	printf("| CADASTRANDO PROFESSOR |");
	printf("\n-------------------------\n");

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
	professor[qtdProfessor].sexo = toupper(professor[qtdProfessor].sexo);

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

	int i;

	printf("\n-------------------------\n");
	printf("| LISTANDO PROFESSORES  |");
	printf("\n-------------------------\n");

	for(i = 0; i < qtdProfessor; i++) {
		printf("\n-------------------------------\n", i+1);
		printf("MATRICULA: %d", professor[i].matricula);
		printf("\nNOME: %s", professor[i].nome);
		printf("SEXO: %c", professor[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", professor[i].data);
		printf("CPF: %s", professor[i].cpf);
		printf("-------------------------------\n");
	}
}

void alterarCadastroProfessor(int qtdProfessor, dados professor[]) {

	int op = 0;
	int num = 0;
	char novoNome[50];
	char novoSexo;
	char novaData[50];
	char novoCPF[50];

	mostrarProfessor(qtdProfessor, professor);

	printf("\nInforme a matricula do professor para alterar o cadastro: ");
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

		case 2: {
			printf("\nDigite o novo sexo: ");
			scanf("%c", &novoSexo);
			while(1) {
				if(validarSexo(professor[num-1].sexo) != 1) {
					printf("\nSEXO INVALIDO! Tente novamente...\n");
					scanf("%c", &novoSexo);
				} else {
					novoSexo = toupper(novoSexo);
					professor[num-1].sexo = novoSexo;
					printf("\nSEXO ALTERADO COM SUCESSO!\n");
					break;
				}
			}
			break;
		}

		case 3: {
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

		case 4: {
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

	printf("\nInforme a matricula do professor para ser removido: ");
	scanf("%d", &pos);
	while(1) {
		if(pos <= 0 || pos > qtdProfessor) {
			printf("\nPROFESSOR NAO ENCONTRADO OU NAO REGISTRADO! Tente novamente...\n");
			scanf("%d", &pos);
		} else {
			break;
		}
	}
	pos--;

	for(i = pos; i < qtdProfessor; i++) {
		professor[i].matricula = professor[i+1].matricula;
		strcpy(professor[i].nome, professor[i+1].nome);
		professor[i].sexo = professor[i+1].sexo;
		strcpy(professor[i].data, professor[i+1].data);
		strcpy(professor[i].cpf, professor[i+1].cpf);
	}

	qtdProfessor--;

	return pos;
}

void listarProfessorAniversariante(int qtdProfessor, dados professor[]) {

	int mes;
	int i, y;
	long int vetDatas[6];
	int verificacao = 0;
	char strMes[20];

	printf("\nInforme o mes que deseja listar os aniversariantes (1/12): ");
	scanf("%d", &mes);
	while(1) {
		if(mes <= 0 || mes > 12) {
			printf("\nMES INVALIDO! Digite novamente...\n");
			scanf("%d", &mes);
		} else {
			break;
		}
	}

	descobreNomeMes(mes, strMes);

	printf("\n---------------------------------\n");
	printf("   ANIVERSARIANTES DE %s ", strMes);
	printf("\n---------------------------------\n");

	for(i = 0; i < qtdProfessor; i++) {
		vetDatas[i] = atoi(professor[i].data);

		if(strlen(professor[i].data) -1 == 6) {
			int digito1 = 0;
			int digito2 = 0;
			digito1 = (vetDatas[i] / 1000) % 10;
			digito2 = (vetDatas[i] / 100) % 10;

			int digito1Mes = 0;
			int digito2Mes = 0;
			int digitoMes = 0;
		
			digito1Mes = digito1 * 10;
			digito2Mes = digito2;
			digitoMes = digito1Mes + digito2Mes;

			for(y = 0; mes == digitoMes; y++) {
				printf("\n----------------------------\n");
				printf("PROFESSOR %d", i+1);
				printf("\nNome: %s", professor[i].nome);
				printf("Data de Nascimento: %s", professor[i].data);
				printf("----------------------------\n");
				verificacao = 1;
				break;
			}
			
		} else if(strlen(professor[i].data) - 1 == 8) {
			int digito1 = 0;
			int digito2 = 0;
			digito1 = (vetDatas[i] / 100000) % 10;
			digito2 = (vetDatas[i] / 10000) % 10;

			int digito1Mes = 0;
			int digito2Mes = 0;
			int digitoMes = 0;

			digito1Mes = digito1 * 10;
			digito2Mes = digito2;
			digitoMes = digito1Mes + digito2Mes;

			for(y = 0; mes == digitoMes; y++) {
				printf("\n----------------------------\n");
				printf("PROFESSOR %d", i+1);
				printf("\nNome: %s", professor[i].nome);
				printf("Data de Nascimento: %s", professor[i].data);
				printf("----------------------------\n");
				verificacao = 1;
				break;
			}
		}
	}

	if(verificacao != 1) {
		printf("\nNENHUM PROFESSOR FAZ ANIVESARIO ESTE MES!\n");
	}
}

void listarProfessorSexo(int qtdProfessor, dados professor[]) {

	char sexo;
	int i;
	char strSexo[15];
	int verificacao = 0;

	setbuf(stdin, NULL);
	printf("\nDigite o sexo que deseja listar (M, F ou O): ");
	scanf("%c", &sexo);
	while(1) {
		if(validarSexo(sexo) != 1) {
			setbuf(stdin, NULL);
			printf("\nSEXO INVALIDO! Digite novamente...\n");
			scanf("%c", &sexo);
		} else {
			break;
		}
	}
	sexo = toupper(sexo);
	
	if(sexo == 'M') {
		strcpy(strSexo, "MASCULINO");
	} else if(sexo == 'F') {
		strcpy(strSexo, "FEMININO");
	} else {
		strcpy(strSexo, "OUTROS");
	}

	printf("\n---------------------------------\n");
	printf("  PROFESSORES DO SEXO %s ", strSexo);
	printf("\n---------------------------------\n");

	for(i = 0; i < qtdProfessor; i++) {
		if(professor[i].sexo == sexo) {
			printf("\n----------------------------\n");
			printf("Matricula: %d", professor[i].matricula);
			printf("\nNome: %s", professor[i].nome);
			printf("Sexo: %c", professor[i].sexo);
			printf("\n----------------------------\n");
			verificacao = 1;
		}
	}
	if(verificacao != 1) {
		printf("\nNENHUM PROFESSOR DO SEXO %s CADASTRADO!\n", strSexo);
	}
}

void listarProfessorOrdemAlfabetica(int qtdProfessor, dados professor[]) {

	int i, y;
	int comparacao;
	dados cloneProfessor[TAM];
	int matriculaAux;
	char nomeAux[50];
	char sexoAux;
	char dataAux[50];
	char cpfAux[50];

	for(i = 0; i < qtdProfessor; i++) {
		cloneProfessor[i].matricula = professor[i].matricula;
		strcpy(cloneProfessor[i].nome, professor[i].nome);
		cloneProfessor[i].sexo = professor[i].sexo;
		strcpy(cloneProfessor[i].data, professor[i].data);
		strcpy(cloneProfessor[i].cpf, professor[i].cpf);
	}

	for(i = 0; i < qtdProfessor; i++) {
		for(y = i + 1; y < qtdProfessor; y++) {
			comparacao = strcmp(cloneProfessor[i].nome, cloneProfessor[y].nome);
			if(comparacao > 0) {
				matriculaAux = cloneProfessor[i].matricula;
				cloneProfessor[i].matricula = cloneProfessor[y].matricula;
				cloneProfessor[y].matricula = matriculaAux;
				strcpy(nomeAux, cloneProfessor[i].nome);
				strcpy(cloneProfessor[i].nome, cloneProfessor[y].nome);
				strcpy(cloneProfessor[y].nome, nomeAux);
				sexoAux = cloneProfessor[i].sexo;
				cloneProfessor[i].sexo = cloneProfessor[y].sexo;
				cloneProfessor[y].sexo = sexoAux;
				strcpy(dataAux, cloneProfessor[i].data);
				strcpy(cloneProfessor[i].data, cloneProfessor[y].data);
				strcpy(cloneProfessor[y].data, dataAux);
				strcpy(cpfAux, cloneProfessor[i].cpf);
				strcpy(cloneProfessor[i].cpf, cloneProfessor[y].cpf);
				strcpy(cloneProfessor[y].cpf, cpfAux);
			}
		}
	}

	printf("\n--------------------------------------------\n");
	printf("| LISTANDO PROFESSORES EM ORDEM ALFABETICA |");
	printf("\n--------------------------------------------\n");

	for(i = 0; i < qtdProfessor; i++) {
		printf("\n----------------------------\n");
		printf("MATRICULA: %d", cloneProfessor[i].matricula);
		printf("\nNOME: %s", cloneProfessor[i].nome);
		printf("SEXO: %c", cloneProfessor[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", cloneProfessor[i].data);
		printf("CPF: %s", cloneProfessor[i].cpf);
		printf("----------------------------\n");
	}
}

int apagarTodosProfessores(int qtdProfessor) {

	char confirmacao;

	printf("\nDeseja mesmo apagar todos os professores? (S p/ confirmar): ");
	scanf("%c", &confirmacao);
	confirmacao = toupper(confirmacao);
	if(confirmacao == 'S') {
		qtdProfessor = 0;
		printf("\nTODOS OS PROFESSORES FORAM APAGADOS!\n");
	} else {
		printf("\nNENHUM PROFESSOR FOI APAGADO!\n");
	}

	return qtdProfessor;
}