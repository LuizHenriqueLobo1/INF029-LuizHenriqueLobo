#include <stdio.h>

int soma(int v1, int v2);
int subt(int v1, int v2);
int mult(int v1, int v2);
int divi(int v1, int v2);

int main() {

	int val1 = 10;
	int val2 = 2;
	int result = 0;
	int x = 1;
	int opcao;

	while(x == 1) {
	
		printf("\n\n* MENU *\n0-Sair\n1-Somar\n2-Subtrair\n3-Multiplicacao\n4-Divisao\nR: ");
		scanf("%d", &opcao);

		switch(opcao) {

			case 0: 
				x = 0; break;

			case 1:
				result = soma(val1, val2); printf("Resultado: %d", result); break;

			case 2:
				result = subt(val1, val2); printf("Resultado: %d", result); break;

			case 3:
				result = mult(val1, val2); printf("Resultado: %d", result); break;

			case 4:
				result = divi(val1, val2); printf("Resultado: %d", result); break;
			
			default:
				printf("ERRO! Opcao invalida!"); break;
		}
	}


	return 0;
}

int soma(int v1, int v2) {

	int resultado = 0;

	resultado = v1 + v2;

	return resultado;
}

int subt(int v1, int v2) {

	int resultado = 0;

	resultado = v1 - v2;

	return resultado;
}

int mult(int v1, int v2) {

	int resultado = 0;

	resultado = v1 * v2;

	return resultado;
}

int divi(int v1, int v2) {

	int resultado = 0;

	resultado = v1 / v2;

	return resultado;
}