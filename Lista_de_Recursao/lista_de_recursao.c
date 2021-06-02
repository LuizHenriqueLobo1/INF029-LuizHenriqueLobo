#include <stdio.h>

#include "lista_de_recursao_headers.h"

void main() {
	// Questão 1
	int n = 6;
	n = fatorial(n);
	printf("\nFatorial: %d\n", n);
}

// Questão 1
int fatorial(int n) {
	if(n <= 0)
		return 1;
	else
		return n * fatorial(n - 1) * -1;
}