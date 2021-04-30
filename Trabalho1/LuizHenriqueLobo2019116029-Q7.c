#include <stdio.h>
#include <string.h>
#include <ctype.h>

int menu();
void tutorial();
void preencherMatriz(int matriz[3][3]);
void printarMatriz(int matriz[3][3]);
void jogar(int matriz[3][3]);
int terminarJogo(int matriz[3][3], int numero);
int validarCelula(char celula[10]);

int main() {

	int matriz[3][3];
	int loop = 1;
	int opcao;

	preencherMatriz(matriz);

	while(loop == 1) {

		opcao = menu();

		switch(opcao) {

			case 1: {
				jogar(matriz);
				break;
			}

			case 2: {
				tutorial();
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
	printf("\n| 2) TUTORIAL   |");
	printf("\n| 0) SAIR       |");
	printf("\n-----------------");
	printf("\n> ");
	scanf("%d", &opcao);

	return opcao;
}

void tutorial() {

	printf("\n------TUTORIAL------");
	printf("\n| JOGADOR 1 = X    |");
	printf("\n| JOGADOR 2 = O    |");
	printf("\n--------------------");
	printf("\n| A CELULA eh a    |");
	printf("\n| combinacao da    |");
	printf("\n| LINHA e da COLUNA|");
	printf("\n| Ex: A1 - B3 - C2 |");
	printf("\n--------------------\n");
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
			if(matriz[l][c] == 1)
				printf(" X");
			else if(matriz[l][c] == 2)
				printf(" O");
			else
				printf("  ");
		}
	}
	printf("\n\n");
}

void jogar(int matriz[3][3]) {

	int loop = 1;
	char celula[10];
	char linha, coluna;
	int iLinha, iColuna;
	int jogada;
	int contador = 0;

	while(loop == 1) {

		printarMatriz(matriz);

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

		if(matriz[iLinha][iColuna] == 9) 
			matriz[iLinha][iColuna] = jogada;
		else {
			printf("\nJOGADA INVALIDA!\n");
			contador--;
		}

		contador++;
		
		if(terminarJogo(matriz, jogada) == 2) {
			printf("\nPARTIDA ENCERRADA!!!\n");
			printarMatriz(matriz);
			printf("\nJOGADOR 1 VENCEU!\n");
			preencherMatriz(matriz);
			loop = 0;
		}
		else if(terminarJogo(matriz, jogada) == 3) {
			printf("\nPARTIDA ENCERRADA!!!\n");
			printarMatriz(matriz);
			printf("\nJOGADOR 2 VENCEU!\n");
			preencherMatriz(matriz);
			loop = 0;
		}

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

int terminarJogo(int matriz[3][3], int numero) {

	int retorno;

	// Linha 1
	if((matriz[0][0] == numero) && (matriz[0][1] == numero) && (matriz[0][2] == numero))
		retorno = numero + 1;
	// Linha 2
	if((matriz[1][0] == numero) && (matriz[1][1] == numero) && (matriz[1][2] == numero))
		retorno = numero + 1;
	// Linha 3
	if((matriz[2][0] == numero) && (matriz[2][1] == numero) && (matriz[2][2] == numero))
		retorno = numero + 1;

	// Coluna 1
	if((matriz[0][0] == numero) && (matriz[1][0] == numero) && (matriz[2][0] == numero))
		retorno = numero + 1;
	// Coluna 2
	if((matriz[0][1] == numero) && (matriz[1][1] == numero) && (matriz[2][1] == numero))
		retorno = numero + 1;
	// Coluna 3
	if((matriz[0][2] == numero) && (matriz[1][2] == numero) && (matriz[2][2] == numero))
		retorno = numero + 1;

	// Diagonal 1
	if((matriz[0][0] == numero) && (matriz[1][1] == numero) && (matriz[2][2] == numero))
		retorno = numero + 1;
	// Diagonal 2
	if((matriz[0][2] == numero) && (matriz[1][1] == numero) && (matriz[2][0] == numero))
		retorno = numero + 1;

	return retorno;
}