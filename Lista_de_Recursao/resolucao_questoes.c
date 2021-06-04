#include <stdio.h>

#include "lista_de_recursao_headers.h"

// Q1
int fatorial(int n) {
	if(n <= 0)
		return 1;
	else
		return n * fatorial(n - 1) * -1;
}

// Q2
int fibonacci(int n) {
	if(n == 0)
		return 0;
	else if(n < 3)
		return 1;
	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}

// Q3
int inverteNumero(int num) {
	if(num == 0)
		return num;
	else {
		printf("%d", num % 10);
		num /= 10;
		return inverteNumero(num);
	}
}