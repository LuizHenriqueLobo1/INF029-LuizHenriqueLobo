// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

// Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018
// #################################################

#include<stdio.h>
#include<string.h>

#include "LuizHenriqueLobo2019116029.h"

void testSomar(); //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main(){
    //testSomar();
    //testFatorial();
    //testQ1();
    //testQ2();
    //testQ3();
    //testQ4();
    //testQ5();
    testQ6();
}

void testSomar(){
    printf("%d\n",somar(3, 4) == 7);
    printf("%d\n",somar(-1, 3) == 2);
    printf("%d\n",somar(-6, 6) == 0);
    printf("%d\n",somar(74, 9) == 83);
    printf("%d\n",somar(30, -9) == 21);
}

void testFatorial(){
    printf("%d\n",fatorial(3) == 6);
    printf("%d\n",fatorial(1) == 1);
    printf("%d\n",fatorial(5) == 120);
    // Meus testes
    printf("%d\n",fatorial(0) == 1);
    printf("%d\n",fatorial(6) == 720);
    printf("%d\n",fatorial(2) == 2);
    printf("%d\n",fatorial(-4) == 0);
}

void testQ1(){
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
    // Meus testes
    strcpy(str,"29/2/2100");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/5/01");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"/4/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"15//2005");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"7/11/");
    printf("%d\n",q1(str) == 0);
}

void testQ2(){
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/06/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 1);
    printf("%d\n",qtdDias == 0);
    printf("%d\n",qtdMeses == 0);
    printf("%d\n",qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 2);

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 3);

    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 1);
    printf("%d\n",qtdDias == 1);
    printf("%d\n",qtdMeses == 1);
    printf("%d\n",qtdAnos == 0);
}

void testQ3(){
    char str[250];
    strcpy(str,"Renato Lima Novais");
    printf("%d\n",q3(str, 'a', 0) == 3);
    printf("%d\n",q3(str, 'b', 0) == 0);
    printf("%d\n",q3(str, 'l', 1) == 0);
    printf("%d\n",q3(str, 'l', 0) == 1);
    printf("%d\n",q3(str, 'L', 0) == 1);
    // Meus testes
    printf("%d\n",q3(str, 'L', 1) == 1);
    printf("%d\n",q3(str, 'o', 1) == 2);
    printf("%d\n",q3(str, 'N', 1) == 1);
    printf("%d\n",q3(str, 'n', 0) == 2);
}

void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);
}

void testQ5(){
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    // Meus testes
    printf("%d\n",q5(100) == 1);
    printf("%d\n",q5(123456789) == 987654321);
    printf("%d\n",q5(2002) == 2002);
    printf("%d\n",q5(76201) == 10267);
}

void testQ6(){
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    // Meus testes
    printf("%d\n",q6(552551555, 55) == 3);
    printf("%d\n",q6(12412672, 2) == 3);
    printf("%d\n",q6(3333, 3) == 4);
}