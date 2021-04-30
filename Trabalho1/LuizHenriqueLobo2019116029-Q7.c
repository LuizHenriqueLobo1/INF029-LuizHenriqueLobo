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

	printf("\n\n   1    2    3\n\n");
	for(l = 0; l < 3; l++) {
		if(l == 0)
			printf("A");
		if(l >= 1)
			printf("\n   ------------\n");
		if(l == 1)
			printf("B");
		if(l == 2)
			printf("C");
		for(c = 0; c < 3; c++) {
			printf(" ");
			if(c >= 1)
				printf(" |");
			if(matriz[l][c] != 9)
				printf(" %d", matriz[l][c]);
			else
				printf("  ");
		}
	}
	printf("\n\n");
}

void jogar(int matriz[3][3]) {

	int loop = 1;
	char celula[10];
	int l, c;
	char linha, coluna;
	int iLinha, iColuna;
	int jogada;
	int contador = 0;

	while(loop == 1) {

		if(contador % 2 == 0)
			jogada = 1;
		else
			jogada = 2;

		printf("\nVEZ DO JOGADOR: %d", jogada);

		setbuf(stdin, NULL);
		printf("\nDIGITE A CELULA: ");
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

		if(linha == 'A')
			iLinha = 1;
		else if(linha == 'B')
			iLinha = 2;
		else
			iLinha = 3;

		iColuna = coluna - '0';

		iLinha--;
		iColuna--;

		matriz[iLinha][iColuna] = jogada;
		contador++;

		printarMatriz(matriz);
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