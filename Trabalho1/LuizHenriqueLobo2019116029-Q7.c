#include <stdio.h>

int menu();
void preencherMatriz(int matriz[3][3]);
void printarMatriz(int matriz[3][3]);
void jogar(int matriz[3][3]);

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
				// Ainda em implementação...
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