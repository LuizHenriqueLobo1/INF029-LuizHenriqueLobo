#include <stdio.h>

#include "lista_de_recursao_headers.h"

void main() {
	questao1();
	questao2();
	questao3();
	questao4();
	questao5();
	questao6();
	questao7();
	questao8();
	questao10();
	questao11();
	questao12();
	questao13();
	questao14();
	questao15();
}

void separadorInicio(char string[]) {
	printf("\n---------- %s ----------\n", string);
}

void separadorFinal() {
	printf("\n-------------------------------\n");
}

void separadorFinal2() {
	printf("\n--------------------------------\n");
}

void questao1() {

	int n = 6;
	int fat = 0;
	
	separadorInicio("Questao 1");
	printf("Fatorial de %d: %d", n, fat = fatorial(n));
	separadorFinal();
}

void questao2() {

	int tamSeq = 10;
	int r = 0;
	int i;

	separadorInicio("Questao 2");
	printf("Seq Fibonacci ate %d nums:\n", tamSeq);
	for(i = 0; i <= tamSeq; i++) {
		r = fibonacci(i);
		printf("%d ", r);       
	}
	separadorFinal();
}

void questao3() {

	int numero = 12345;

	separadorInicio("Questao 3");
	printf("Numero original: ");
	printf("%d\n", numero);
	printf("Numero invertido: ");
	numero = inverteNumero(numero);
	separadorFinal();
}

void questao4() {

	int tamVetor = 5;
	int vetor[tamVetor];
	int i;
	int soma;

	for(i = 0; i < tamVetor; i++) {
		vetor[i] = i + 1;
	}

	separadorInicio("Questao 4");
	printf("Valores do vetor:\n");
	for(i = 0; i < tamVetor; i++)
		printf("%d ", vetor[i]);
	printf("\nSoma dos valores do vetor: %d", soma = somaInteirosVetor(vetor, tamVetor));
	separadorFinal();
}

void questao5() {

	int n = 3;
	int resultado = 0;

	separadorInicio("Questao 5");
	printf("Soma dos valores de 1 a N: %d", resultado = somatorioNumeros(n));
	separadorFinal();
}

void questao6() {
	
	int k = 5;
	int n = 3;
	int resultado = 0;

	separadorInicio("Questao 6");
	printf("K(%d) elevado a N(%d): %d", k, n, resultado = calcularKelevadoN(k,n ));
	separadorFinal();
}

void questao7() {

	float vetor[4] = {1.5, 2.3, 3.7, 4.2};
	int i;

	separadorInicio("Questao 7");
	printf("Vet Original: ");
	for(i = 0; i < 4; i++)
		printf("%.1f ", vetor[i]);

	inverteOrdemDosElementos(vetor, 0, 3);

	printf("\nVet Invertido: ");
	for(i = 0; i < 4; i++)
		printf("%.1f ", vetor[i]);
	separadorFinal();
}

void questao8() {

	int x = 12;
	int y = 4;
	int resultado = 0;

	separadorInicio("Questao 8");
	printf("MDC de X(%d) e Y(%d): %d", x, y, resultado = mdc(x, y));
	separadorFinal();
}

void questao10() {

	int numero = 25389202;
	int nBusca = 2;
	int qtd = 0;
	int *k = &qtd;

	separadorInicio("Questao 10");
	procuraNumeroEmOutro(numero, k, nBusca);
	printf("Numero Base: %d\nNumero Busca: %d", numero, nBusca);
	printf("\nQtd Ocorrencias: %d", qtd);
	separadorFinal2();
}

void questao11() {

	int num1 = 5;
	int num2 = 6;
	int resultado = 0;

	resultado = multiplicacaoRecursiva(num1, num2);

	separadorInicio("Questao 11");
	printf("N1(%d) * N2(%d) = %d", num1, num2, resultado);
	separadorFinal2();
}

void questao12() {

	int n = 7;

	separadorInicio("Questao 12");
	printf("Imprime Crescente de 0 a N(%d):\n", n);
	imprimeOrdemCrescente(n);
	separadorFinal2();
}

void questao13() {

	int n = 7;

	separadorInicio("Questao 13");
	printf("Imprime Decrescente de 0 a N(%d):\n", n);
	imprimeOrdemDecrescente(n);
	separadorFinal2();
}

void questao14() {

	int n = 20;

	separadorInicio("Questao 14");
	printf("Imprime Nums Pares de 0 a N(%d):\n", n);
	imprimeNumerosPares(n);
	separadorFinal2();
}

void questao15() {

	int n = 20;

	separadorInicio("Questao 15");
	printf("Imprime Nums Pares de 0 a N(%d):\n", n);
	imprimeNumerosParesDecrescente(n);
	separadorFinal2();
}