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
					aluno[-1].matricula = 0;
					aluno[qtdAluno-1].matricula = 0;
					aluno[qtdAluno-1].matricula = aluno[qtdAluno-2].matricula + 1;
					printf("\nALUNO CADASTRADO COM SUCESSO!\n");
					break;
				} else {
					printf("\nQUANTIDADE MAXIMA DE ALUNOS ATINGIDA!\n");
					break;
				}
			}

			case 2: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					mostrarAluno(qtdAluno, aluno);
				}
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

			case 5: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					listarAlunoAniversariante(qtdAluno, aluno);
				}
				break;
			}

			case 6: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					listarAlunoSexo(qtdAluno, aluno);
				}
				break;
			}

			case 7: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					listarAlunoOrdemAlfabetica(qtdAluno, aluno);
				}
				break;
			}

			case 8: {
				if(qtdAluno <= 0) {
					printf("\nNENHUM ALUNO CADASTRADO!\n");
				} else {
					qtdAluno = apagarTodosAlunos(qtdAluno);
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

	printf("\n---------- MENU ALUNO ----------\n");
	printf("| 0 -> SAIR                    |\n");
	printf("| 1 -> CADASTRAR ALUNO         |\n");
	printf("| 2 -> MOSTRAR ALUNOS          |\n");
	printf("| 3 -> ALTERAR ALUNO           |\n");
	printf("| 4 -> RETIRAR ALUNO           |\n");
	printf("| 5 -> ANIVERSARIANTES DO MES  |\n");
	printf("| 6 -> MOSTRAR ALUNOS POR SEXO |\n");
	printf("| 7 -> ALUNOS EM ORDEM ALFAB   |\n");
	printf("| 8 -> APAGAR TODOS OS ALUNOS  |");
	printf("\n--------------------------------\n");
	printf("> ");
	scanf("%d", &op);
	setbuf(stdin, NULL);

	return op;
}

void cadastrarAluno(int qtdAluno, dados aluno[]) {

	printf("\n---------------------\n");
	printf("| CADASTRANDO ALUNO |");
	printf("\n---------------------\n");

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
	aluno[qtdAluno].sexo = toupper(aluno[qtdAluno].sexo);

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

	int i;

	printf("\n--------------------\n");
	printf("| LISTANDO ALUNOS  |");
	printf("\n--------------------\n");

	for(i = 0; i < qtdAluno; i++) {
		printf("\n-----------------------------\n", i+1);
		printf("MATRICULA: %d", aluno[i].matricula);
		printf("\nNOME: %s", aluno[i].nome);
		printf("SEXO: %c", aluno[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", aluno[i].data);
		printf("CPF: %s", aluno[i].cpf);
		printf("-----------------------------\n");
	}
}

void alterarCadastroAluno(int qtdAluno, dados aluno[]) {

	int op = 0;
	int num = 0;
	char novoNome[50];
	char novoSexo;
	char novaData[50];
	char novoCPF[50];

	mostrarAluno(qtdAluno, aluno);

	printf("\nInforme a matricula do aluno para alterar o cadastro: ");
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

		case 2: {
			printf("\nDigite o novo sexo: ");
			scanf("%c", &novoSexo);
			while(1) {
				if(validarSexo(aluno[num-1].sexo) != 1) {
					printf("\nSEXO INVALIDO! Tente novamente...\n");
					scanf("%c", &novoSexo);
				} else {
					novoSexo = toupper(novoSexo);
					aluno[num-1].sexo = novoSexo;
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

		case 4: {
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

	printf("\nInforme a matricula do aluno para ser removido: ");
	scanf("%d", &pos);
	while(1) {
		if(pos <= 0 || pos > qtdAluno) {
			printf("\nALUNO NAO ENCONTRADO OU NAO REGISTRADO! Tente novamente...\n");
			scanf("%d", &pos);
		} else {
			break;
		}
	}
	pos--;

	for(i = pos; i < qtdAluno; i++) {
		aluno[i].matricula = aluno[i+1].matricula;
		strcpy(aluno[i].nome, aluno[i+1].nome);
		aluno[i].sexo = aluno[i+1].sexo;
		strcpy(aluno[i].data, aluno[i+1].data);
		strcpy(aluno[i].cpf, aluno[i+1].cpf);
	}

	qtdAluno--;

	return pos;
}

void listarAlunoAniversariante(int qtdAluno, dados aluno[]) {

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

	for(i = 0; i < qtdAluno; i++) {
		vetDatas[i] = atoi(aluno[i].data);

		if(strlen(aluno[i].data) -1 == 6) {
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
				printf("Matricula: %d", aluno[i].matricula);
				printf("\nNome: %s", aluno[i].nome);
				printf("Data de Nascimento: %s", aluno[i].data);
				printf("----------------------------\n");
				verificacao = 1;
				break;
			}
			
		} else if(strlen(aluno[i].data) - 1 == 8) {
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
				printf("Matricula: %d", aluno[i].matricula);
				printf("\nNome: %s", aluno[i].nome);
				printf("Data de Nascimento: %s", aluno[i].data);
				printf("----------------------------\n");
				verificacao = 1;
				break;
			}
		}
	}

	if(verificacao != 1) {
		printf("\nNENHUM ALUNO FAZ ANIVESARIO ESTE MES!\n");
	}
}

void listarAlunoSexo(int qtdAluno, dados aluno[]) {

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
	printf("    ALUNOS DO SEXO %s ", strSexo);
	printf("\n---------------------------------\n");

	for(i = 0; i < qtdAluno; i++) {
		if(aluno[i].sexo == sexo) {
			printf("\n----------------------------\n");
			printf("Matricula: %d", aluno[i].matricula);
			printf("\nNome: %s", aluno[i].nome);
			printf("Sexo: %c", aluno[i].sexo);
			printf("\n----------------------------\n");
			verificacao = 1;
		}
	}
	if(verificacao != 1) {
		printf("\nNENHUM ALUNO DO SEXO %s CADASTRADO!\n", strSexo);
	}
}

void listarAlunoOrdemAlfabetica(int qtdAluno, dados aluno[]) {

	int i, y;
	int comparacao;
	dados cloneAluno[TAM];
	int matriculaAux;
	char nomeAux[50];
	char sexoAux;
	char dataAux[50];
	char cpfAux[50];
	
	for(i = 0; i < qtdAluno; i++) {
		cloneAluno[i].matricula = aluno[i].matricula;
		strcpy(cloneAluno[i].nome, aluno[i].nome);
		cloneAluno[i].sexo = aluno[i].sexo;
		strcpy(cloneAluno[i].data, aluno[i].data);
		strcpy(cloneAluno[i].cpf, aluno[i].cpf);
	}

	for(i = 0; i < qtdAluno; i++) {
		for(y = i + 1; y < qtdAluno; y++) {
			comparacao = strcmp(cloneAluno[i].nome, cloneAluno[y].nome);
			if(comparacao > 0) {
				matriculaAux = cloneAluno[i].matricula;
				cloneAluno[i].matricula = cloneAluno[y].matricula;
				cloneAluno[y].matricula = matriculaAux;
				strcpy(nomeAux, cloneAluno[i].nome);
				strcpy(cloneAluno[i].nome, cloneAluno[y].nome);
				strcpy(cloneAluno[y].nome, nomeAux);
				sexoAux = cloneAluno[i].sexo;
				cloneAluno[i].sexo = cloneAluno[y].sexo;
				cloneAluno[y].sexo = sexoAux;
				strcpy(dataAux, cloneAluno[i].data);
				strcpy(cloneAluno[i].data, cloneAluno[y].data);
				strcpy(cloneAluno[y].data, dataAux);
				strcpy(cpfAux, cloneAluno[i].cpf);
				strcpy(cloneAluno[i].cpf, cloneAluno[y].cpf);
				strcpy(cloneAluno[y].cpf, cpfAux);
			}
		}
	}

	printf("\n---------------------------------------\n");
	printf("| LISTANDO ALUNOS EM ORDEM ALFABETICA |");
	printf("\n---------------------------------------\n");

	for(i = 0; i < qtdAluno; i++) {
		printf("\n----------------------------\n");
		printf("MATRICULA: %d", cloneAluno[i].matricula);
		printf("\nNOME: %s", cloneAluno[i].nome);
		printf("SEXO: %c", cloneAluno[i].sexo);
		printf("\nDATA DE NASCIMENTO: %s", cloneAluno[i].data);
		printf("CPF: %s", cloneAluno[i].cpf);
		printf("----------------------------\n");
	}
}

int apagarTodosAlunos(int qtdAluno) {

	char confirmacao;

	printf("\nDeseja mesmo apagar todos os alunos? (S p/ confirmar): ");
	scanf("%c", &confirmacao);
	confirmacao = toupper(confirmacao);
	if(confirmacao == 'S') {
		qtdAluno = 0;
		printf("\nTODOS OS ALUNOS FORAM APAGADOS!\n");
	} else {
		printf("\nNENHUM ALUNO FOI APAGADO!\n");
	}

	return qtdAluno;
}