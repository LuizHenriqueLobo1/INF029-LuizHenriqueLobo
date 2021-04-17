// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Luiz Henrique da Silva Lobo
//  email: luizhlobo25@gmail.com
//  Matrícula: 2019116029
//  Semestre: 2

// Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016
// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LuizHenriqueLobo2019116029.h"

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
	
	int soma = 0;
  	
  	soma = x + y;
  	
  	return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes

	int fat = 0;

	if(x < 0) {
		fat = 0;
	}
	else if(x == 0 || x == 1) {
		fat = 1;
	} else {
		for(fat = 1; x > 1; x = x - 1) {
			fat *= x;
		}
	}

	return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){

    int datavalida = 0;
    int i, y;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int diaI;
    int mesI;
    int anoI;
    int tamanhoAno;

	// Captura a string do dia e transforma em inteiro
    for(i = 0; data[i] != '/'; i++) {
    	sDia[i] = data[i];
    }
    sDia[i] = '\0';

    diaI = atoi(sDia);

    // Captura a string do mes e transforma em inteiro
    for(i = i + 1, y = 0; data[i] != '/'; i++, y++) {
    	sMes[y] = data[i];
    }
    sMes[y] = '\0';

    mesI = atoi(sMes);

    // Captura a string do ano e transforma em inteiro
    for(i = i + 1, y = 0; data[i] != '\0'; i++, y++) {
    	sAno[y] = data[i];
    }
    sAno[y] = '\0';

   	anoI = atoi(sAno);

   	// Verifica o tamanho da string do ano, se igual a 2, é somado 2000
   	if(strlen(sAno) == 2) {
   		anoI+=2000;
   		tamanhoAno = 4;
   	}
   	// Com o tamanho da string do ano igual a 4, o ano é válido, agora fazemos as validações do dia e mes
   	if(strlen(sAno) == 4 || tamanhoAno == 4) {
   		// Meses com 31 dias
   		if(mesI == 1 || mesI == 3 || mesI == 5 || mesI == 7 || mesI == 8 || mesI == 10 || mesI == 12) {
        	if(diaI <= 0 || diaI > 31) {
                datavalida = 0;
            } else {
                datavalida = 1;
            }
          // Mes 2, onde verificamos se o ano é bissexto  
   		} else if(mesI == 2) {
   			if(anoBissexto(anoI) == 1) {
   				if(diaI <= 0 || diaI > 29) {
                    datavalida = 0;
                } else {
                    datavalida = 1;
                }
   			} else {
   				if(diaI <= 0 || diaI > 28) {
   					datavalida = 0;
   				} else {
   					datavalida = 1;
   				}
   			}
   	      // Meses com 30 dias
   		} else if(mesI == 4 || mesI == 6 || mesI == 9 || mesI == 11) {
   			if(diaI <= 0 || diaI > 30) {
                datavalida = 0;
            } else {
                datavalida = 1;
            }
          // Mes inválido  
   		} else {
   			datavalida = 0;
   		}
   	  // Ano inválido
   	} else {
   		datavalida = 0;
   	}

    return datavalida;
}

int anoBissexto(int ano) {

	int retorno = 0;
	int contador = 0;

	if(ano % 4 == 0) {
		contador++;
	}
	if(ano % 100 == 0) {
		contador--;
	}
	if(ano % 400 == 0) {
		contador++;
	}

	if(contador > 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;


    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;




    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    
    int qtdOcorrencias = 0;
    int i;
    char textoAux[250];
    char cAux;
    int contador = 0;

	if(isCaseSensitive == 1) {
		for(i = 0; texto[i] != '\0'; i++) {
			if(texto[i] == c) {
				contador++;
			}
		}
	} else {
		for(i = 0; texto[i] != '\0'; i++) {
			textoAux[i] = tolower(texto[i]);
			cAux = tolower(c);
			if(textoAux[i] == cAux) {
				contador++;
			}
		}
	}

	qtdOcorrencias = contador;
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = -1;

    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int q5(int num){

	char strNum[100];
	int tamNum = 0;
	int numInvertido;

	itoa(num, strNum, 10);
	tamNum = strlen(strNum);

	for(int i = 0; i < tamNum / 2; i++) {
		char aux = strNum[i];
		strNum[i] = strNum[tamNum - i - 1];
		strNum[tamNum - i - 1] = aux;
	}

	numInvertido = atoi(strNum);

	num = numInvertido;
    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca){
    
    int qtdOcorrencias = 0;
    int multiplicador = 1;
    int numAux = numerobusca;

    while(numAux != 0) {
    	multiplicador *= 10;
    	numAux /= 10;
    }
    numAux = numerobase;

    while(numAux != 0) {
    	if(numAux % multiplicador == numerobusca) {
    		qtdOcorrencias++;
    		numAux /= multiplicador;
    	} else {
    		numAux /= 10;
    	}
    }

    return qtdOcorrencias;
}