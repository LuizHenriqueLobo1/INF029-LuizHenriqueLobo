#include <stdio.h>
#include <string.h>

typedef struct {
	int dia;
	int mes;
	int ano;
}data;

typedef struct {
	char matricula[50];
	char nome[50];
	char sexo;
	data nascimento;
	char cpf[50];
}aluno;

int cadastrarAlunos(int qtdAlunos, aluno estudante[]);
void mostrarAlunos(int qtdAlunos, aluno estudante[]);
int validarNome(char nome[]);
int validarSexo(char sexo);

int main() {

	aluno estud[10];
	int quantidadeAlunos = 0;
	int validador = 0;
	int flag = 1;
	int option = 0;

	while(flag == 1) {

		printf("\n---------- MENU ----------\n");
		printf("| 0 -> SAIR              |\n");
		printf("| 1 -> CADASTRAR ALUNO   |\n");
		printf("| 2 -> MOSTRAR ALUNOS    |");
		printf("\n--------------------------\n");
		printf("> ");
		scanf("%d", &option);
		setbuf(stdin, NULL);

		switch(option) {

			case 0: {
				flag = 0;
				printf("\nPROGRAMA FINALIZADO!\n");
				break;
			}

			case 1: {
				int retornoCadastroAluno = 0;
				retornoCadastroAluno = cadastrarAlunos(quantidadeAlunos, estud);
				if(retornoCadastroAluno == 1) {
					quantidadeAlunos++;
					printf("\nALUNO CADASTRADO COM SUCESSO!\n");
				} else {
					printf("\nFALHA AO CADASTRAR ALUNO!\n");
				}
	
				break;
			}

			case 2: {
				mostrarAlunos(quantidadeAlunos, estud);
				break;
			}

			default: {
				printf("\nOPCAO INVALIDA!\n");
			}
		}
	}

	return 0;
}

int cadastrarAlunos(int qtdAlunos, aluno estudante[]) {

	printf("\n---------------------\n");
	printf("| CADASTRANDO ALUNO |");
	printf("\n---------------------\n");

	printf("\nDigite o numero de matricula: ");
	fgets(estudante[qtdAlunos].matricula, 50, stdin);
	setbuf(stdin, NULL);

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
		} else {
			break;
		}
	}

	printf("\nDigite a data de nascimento do aluno:\nDia: ");
	scanf("%d", &estudante[qtdAlunos].nascimento.dia);
	setbuf(stdin, NULL);
	printf("Mes: ");
	scanf("%d", &estudante[qtdAlunos].nascimento.mes);
	setbuf(stdin, NULL);
	printf("Ano: ");
	scanf("%d", &estudante[qtdAlunos].nascimento.ano);
	setbuf(stdin, NULL);

	printf("\nDigite o CPF do aluno: ");
	fgets(estudante[qtdAlunos].cpf, 50, stdin);
	setbuf(stdin, NULL);

	return 1;
}

void mostrarAlunos(int qtdAlunos, aluno estudante[]) {

	printf("\n--------------------\n");
	printf("| LISTANDO ALUNOS  |");
	printf("\n--------------------\n");

	if(qtdAlunos <= 0) {
		printf("\nNENHUM ALUNO CADASTRADO!\n");
	} else {
		for(int i = 0; i < qtdAlunos; i++) {
		printf("\n---------- ALUNO %d ----------\n", i+1);
		printf("Numero de matricula: %s", estudante[i].matricula);
		printf("Nome: %s", estudante[i].nome);
		printf("Sexo: %c", estudante[i].sexo);
		printf("\nData de nascimento: %d/%d/%d", estudante[i].nascimento.dia, 
				estudante[i].nascimento.mes, estudante[i].nascimento.ano);
		printf("\nCPF: %s", estudante[i].cpf);
		printf("-----------------------------\n");
		}
	}
}

int validarNome(char nome[]) {
	if(strlen(nome) - 1 > 20 || strlen(nome) - 1 <= 0) {
		return -1;
	} else {
		return 1;
	}
}

int validarSexo(char sexo) {
	if(sexo == 'M' || sexo == 'F' || sexo == 'O' ||
		sexo == 'm' || sexo == 'f' || sexo == 'o') {
		return 1;
	} else {
		return -1;
	}
}