#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

void dobrar(int *x) {
    *x = *x * 2;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {

    int retorno = 0;

    // Verifica se a posição da Estrutura Principal é válida
    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;

    // Verifica se o tamanho da Estrutura Auxiliar é válido
    else if(tamanho < 1)
        retorno = TAMANHO_INVALIDO;

    else {
        // Verifica se já existe Estrutura Auxiliar na posição
        if(existeEstruturaAuxiliar(posicao) != SEM_ESTRUTURA_AUXILIAR)
            retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        else
            retorno = SUCESSO;
    }

    if(retorno == SUCESSO) {

        // Faz a alocação da Estrutura Auxiliar
        vetorPrincipal[posicao - 1].pEstruturaAux = malloc(tamanho * sizeof(int));
        vetorPrincipal[posicao - 1].tamEstruturaAux = tamanho;
        
        // Verifica se existe espaço
        if(temEspacoMemoria(posicao) != SUCESSO)
            retorno = SEM_ESPACO_DE_MEMORIA;
    } 

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {

    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else {

        if(existeEstruturaAuxiliar(posicao) != SEM_ESTRUTURA_AUXILIAR){
            if(temEspacoEstruturaAux(posicao) == SUCESSO) {
                // Inserir na Estrura Aux
                vetorPrincipal[posicao - 1].pEstruturaAux[vetorPrincipal[posicao - 1].qtdElementos] = valor;
                vetorPrincipal[posicao - 1].qtdElementos += 1;
                retorno = SUCESSO;
            } else {
                retorno = SEM_ESPACO;
            }
        } else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    
    int retorno;
        
    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else {
        if(existeEstruturaAuxiliar(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else {
            if(estruturaAuxiliarVazia(posicao) != SUCESSO)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else {
                vetorPrincipal[posicao - 1].pEstruturaAux[vetorPrincipal[posicao - 1].qtdElementos - 1] = 0;
                vetorPrincipal[posicao - 1].qtdElementos -= 1;
                retorno = SUCESSO;
            }
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    
    int retorno = 0;
    int auxPosicao = 0;
    int contador = 0;
    int i, y;
        
    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else {
        if(existeEstruturaAuxiliar(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else {
            if(estruturaAuxiliarVazia(posicao) != SUCESSO)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else {
                for(i = 0; i < vetorPrincipal[posicao - 1].qtdElementos; i++) {
                    if(valor != vetorPrincipal[posicao - 1].pEstruturaAux[i]) {
                        contador++;
                        if(contador == vetorPrincipal[posicao - 1].qtdElementos) {
                            retorno = NUMERO_INEXISTENTE;
                            break;
                        }
                    } else {
                        vetorPrincipal[posicao - 1].pEstruturaAux[i] = 0;
                        auxPosicao = i;
                        for(y = auxPosicao; y < vetorPrincipal[posicao - 1].qtdElementos - 1; y++) {
                            vetorPrincipal[posicao - 1].pEstruturaAux[y] = vetorPrincipal[posicao - 1].pEstruturaAux[y + 1];
                        }
                        vetorPrincipal[posicao - 1].qtdElementos--;
                        retorno = SUCESSO;
                    }
                }
            }
        }
    }
    
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else
        retorno = SUCESSO;

    return retorno;
}

// se existe estrutura auxiliar
int existeEstruturaAuxiliar(int posicao) {

    int retorno = 0;

    if(vetorPrincipal[posicao - 1].pEstruturaAux != NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    else
        retorno = SEM_ESTRUTURA_AUXILIAR;

    return retorno;
}

// se tem espaço de memoria
int temEspacoMemoria(int posicao) {

    int retorno = 0;

    if(vetorPrincipal[posicao - 1].pEstruturaAux == NULL)
        retorno = SEM_ESPACO_DE_MEMORIA;
    else
        retorno = SUCESSO;

    return retorno;
}

// se tem espaço na estrutra auxiliar
int temEspacoEstruturaAux(int posicao) {

    int retorno = 0;

    if(vetorPrincipal[posicao - 1].qtdElementos >= vetorPrincipal[posicao - 1].tamEstruturaAux)
        retorno = SEM_ESPACO;
    else
        retorno = SUCESSO;

    return retorno;
}

// se a estrutura auxiliar está vazia
int estruturaAuxiliarVazia(int posicao) {

    int retorno = 0;

    if(vetorPrincipal[posicao - 1].qtdElementos == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

    int retorno = 0;
    int i;

    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else {
        if(existeEstruturaAuxiliar(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else {
            for(i = 0; i < vetorPrincipal[posicao - 1].qtdElementos; i++) {
                vetorAux[i] = vetorPrincipal[posicao - 1].pEstruturaAux[i];
            }
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

    int retorno = 0;
    int aux = 0;
    int i, y;

    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else {
        if(existeEstruturaAuxiliar(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else {
            for(i = 0; i < vetorPrincipal[posicao - 1].qtdElementos; i++) {
                for(y = i + 1; y < vetorPrincipal[posicao - 1].qtdElementos; y++) {
                    if(vetorAux[i] > vetorAux[y]) {
                        aux = vetorAux[i];
                        vetorAux[i] = vetorAux[y];
                        vetorAux[y] = aux;
                    }
                }
            }
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

    int retorno = 0;
    int i, y;
    int contador = 0;
    int vazio = 0;


    for(i = 0; i < TAM; i++) {
        if(vetorPrincipal[i].qtdElementos > 0) {
            vazio++;
            for(y = 0; y < vetorPrincipal[i].qtdElementos; y++) {
                vetorAux[contador] = vetorPrincipal[i].pEstruturaAux[y]; 
                contador++;
            }
        }
    }

    if(vazio == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    
    int retorno = 0;
    int i, y;
    int contador = 0;
    int vazio = 0;
    int aux;


    for(i = 0; i < TAM; i++) {
        if(vetorPrincipal[i].qtdElementos > 0) {
            vazio++;
            for(y = 0; y < vetorPrincipal[i].qtdElementos; y++) {
                vetorAux[contador] = vetorPrincipal[i].pEstruturaAux[y]; 
                contador++;
            }
        }
    }

    for(i = 0; i < contador; i++) {
        for(y = i + 1; y < contador; y++) {
            if(vetorAux[i] > vetorAux[y]) {
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[y];
                vetorAux[y] = aux;
            }
        }
    }

    if(vazio == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    
    int retorno = 0;
    int tamanhoAtual = vetorPrincipal[posicao - 1].tamEstruturaAux;

    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;

    else if((tamanhoAtual + novoTamanho) < 1)
        retorno = NOVO_TAMANHO_INVALIDO;

    else {
        if(existeEstruturaAuxiliar(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else
            retorno = SUCESSO;
    }

    if(retorno == SUCESSO) {
        
        vetorPrincipal[posicao - 1].pEstruturaAux = realloc(vetorPrincipal[posicao - 1].pEstruturaAux, (tamanhoAtual + novoTamanho));
        vetorPrincipal[posicao - 1].tamEstruturaAux += novoTamanho;

        if(novoTamanho < 0)
            vetorPrincipal[posicao - 1].qtdElementos += novoTamanho;

        if(temEspacoMemoria(posicao) != SUCESSO)
            retorno = SEM_ESPACO_DE_MEMORIA;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    
    int retorno = 0;
    
    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else {
        if(existeEstruturaAuxiliar(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else {
            if(estruturaAuxiliarVazia(posicao) != SUCESSO)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else
                retorno = vetorPrincipal[posicao - 1].qtdElementos;
        }
    }
    
    return retorno;
}

// Pegar a soma da quantidade de elementos de todas as estrutuas auxiliares
int getQuantidadeTotalElementos() {

    int i, y;
    int qtdTotalElementos = 0;

    for(i = 0; i < TAM; i++) {
        if(vetorPrincipal[i].qtdElementos > 0)
            for(y = 0; y < vetorPrincipal[i].qtdElementos; y++)
                qtdTotalElementos++;
    }

    return qtdTotalElementos;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote() {
    
    No *inicio = (No*)malloc(sizeof(No));
    inicio->prox = NULL;

    int quantidadeTotalElementos = getQuantidadeTotalElementos();
    int vetorTemp[quantidadeTotalElementos];
    getDadosDeTodasEstruturasAuxiliares(vetorTemp);

    int i;
    
    for(i = quantidadeTotalElementos; i >= 0; i--) {
        inserirNaListaEncadeada(&inicio, vetorTemp[i]);
    }

    return inicio;
}

// Inserir valor na lista encadeada
void inserirNaListaEncadeada(No** inicio, int valor) {

    No *p;
    p = (No*)malloc(sizeof(No));

    p->conteudo = valor;
    p->prox = *inicio;
    *inicio = p;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]) {

    int y = 0;

    while(inicio != NULL) {
        vetorAux[y] = inicio->conteudo;
        inicio = inicio->prox;
        y++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio) {
    if(*inicio != NULL)
        *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/
void inicializar() {

    for(int i = 0; i < TAM; i++) {
        vetorPrincipal[i].pEstruturaAux = NULL;
        vetorPrincipal[i].tamEstruturaAux = 0;
        vetorPrincipal[i].qtdElementos = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar() {

    for(int i = 0; i < TAM; i++) {
        if(existeEstruturaAuxiliar(i) == JA_TEM_ESTRUTURA_AUXILIAR) {
            free(vetorPrincipal[i].pEstruturaAux);
            vetorPrincipal[i].tamEstruturaAux = 0;
            vetorPrincipal[i].qtdElementos = 0;
        }
    }
}