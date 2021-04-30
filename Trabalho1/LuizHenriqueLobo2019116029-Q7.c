#include <stdio.h>
#include <string.h>
#include <ctype.h>

int menu();
void preencherMatriz(int matriz[3][3]);
void printarMatriz(int matriz[3][3]);
void jogar(int matriz[3][3]);
int validarCelula(char celula[10]);

int main() {

	int matriz[3][3];
	int loop = 1;
	int opcao;

	preencherMatriz(matriz);
	printarMatriz(matriz);

	while(loop == 1) {

		opcao = menu();

		switch(opcao) {

			case 1: {
				jogar(matriz);
				break;
			}

			default: {
				printf("\nO JOGO FOI ENCERRADO COM SUCESSO!\n");
				loop = 0;
				break;
			}
		}
	}

	return 0;
}

int menu() {

	int opcao;

	printf("\n--JOGO DA VELHA--");
	printf("\n| 1) JOGAR      |");
	printf("\n| 0) SAIR       |");
	printf("\n-----------------");
	printf("\n> ");
	scanf("%d", &opcao);

	return opcao;
}

void preencherMatriz(int matriz[3][3]) {

	int l, c;

	for(l = 0; l < 3; l++) {
		for(c = 0; c < 3; c++) {
			matriz[l][c] = 9;
		}
	}
}

void printarMatriz(int matriz[3][3]) {

	int l, c;

	printf("\n");
	for(l = 0; l < 3; l++) {
		if(l >= 1)
			printf("\n------------\n");
		for(c = 0; c < 3; c++) {
			if(c >= 1)
				printf(" |");
			printf(" %d", matriz[l][c]);
		}
	}
	printf("\n\n");
}

void jogar(int matriz[3][3]) {

	int loop = 1;
	char celula[10];
	char linha, coluna;
	int iLinha, iColuna;

	while(loop == 1) {

		setbuf(stdin, NULL);
		printf("\nDICA -> (A, B, C = Linhas / 1, 2, 3 = Colunas)\n");
		printf("DIGITE A CELULA: ");
		fgets(celula, 10, stdin);
		while(1) {
			if(validarCelula(celula) != 1) {
				printf("\nCELULA INVALIDA! Digite novamente...\n");
				fgets(celula, 10, stdin);
			} else {
				break;
			}
		}

		linha = celula[0];
		linha = toupper(linha);
		coluna = celula[1];
		
		printf("\nLinha: %c", linha);
		printf("\nColuna: %c\n", coluna);

		loop = 0;
	}

}

int validarCelula(char celula[10]) {

	int retorno;
	int tamCelula;
	int i;

	tamCelula = strlen(celula);
	tamCelula--;

	// Validação do tamanho
	if(tamCelula != 2)
		retorno = -1;
	else
		retorno = 1;

	// Validação dos caracteres
	if((toupper(celula[0] == 'A')) || (toupper(celula[0] == 'B')) || (toupper(celula[0] == 'C')))
		retorno = 1;
	if((celula[1] == '1') || (celula[1] == '2') || (celula[1] == '3'))
		retorno = 1;
	else
		retorno = -1;
	
	return retorno;
}