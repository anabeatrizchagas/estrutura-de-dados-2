// ======================== GRAFO SIMPLES (SEM PESO NAS ARESTAS) E DIRECIONADO ========================

// importando pacotes

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// definindo tamanho padrao

#define MAX_NUM_VERTICES 10 // numero maximo de vertices que pode existir no grafo

// criando grafo a partir de uma matriz de adjacencia

typedef struct 
{
    int m[MAX_NUM_VERTICES + 1][MAX_NUM_VERTICES + 1]; // vertices enumerados de 1 a MAX_NUM_VERTICES
    int numArestas; // numero de arestas
    int numVertices; // numero de vertices

} GRAFO;

// declarando funcoes

/*

    bool inicializaGrafo(GRAFO* g, int nv) recebe como parametro o endereco do
    grafo g e um int nv que e a quantidade de vertices que tera nesse grafo. 
    A funcao inicializa com 0 uma matriz de adjacencia que representa o grafo.
    Alem disso, tambem zera a o numero de vertices e arestas do grafo.

*/

bool inicializaGrafo(GRAFO* g, int nv);

/*

    bool insereAresta(GRAFO* g, int v1, int v2) recebe o endereco do grafo g, um
    int v1 e um int v2 que sao vertices. Se v1 e v2 forem vertices validos, a funcao
    ira inserir uma aresta que sai de v1 e chega em v2. Ademais ira incrementar uma
    unidade no numero de arestas do grafo.

*/

bool insereAresta(GRAFO* g, int v1, int v2);

/*

    bool existeAresta(GRAFO* g, int v1, int v2) recebe o endereco do grafo g, um
    int v1 e um int v2 que sao vertices. Se v1 e v2 forem vertices validos, a funcao
    ira checar se existe uma aresta que sai de v1 e chega em v2. Se existir, retornara
    true, caso contrario, retornara false.

*/

bool existeAresta(GRAFO* g, int v1, int v2); 

/*

    bool retiraAresta(GRAFO* g, int v1, int v2) recebe o endereco do grafo g, um
    int v1 e um int v2 que sao vertices. Se v1 e v2 forem vertices validos e existir
    uma aresta que sai de v1 e chega em v2, a funcao a retirara e retornara true. Caso
    nao haja, retornara false.

*/

bool retiraAresta(GRAFO* g, int v1, int v2);

/*

    void liberaGrafo(GRAFO* g) recebe o endereco do grafo g e zera o numero de vertices
    e arestas dele. Dessa forma, ele e reinicializado.

*/

void liberaGrafo(GRAFO* g);

/*

    void imprimeGrafo(GRAFO* g) recebe o endereco do grafo g e imprime a matriz de
    adjacencia que o representa. Nessa matriz, o numero 1 sinaliza que a uma aresta 
    que sai do vertice na linha i e chega no vertice na coluna j. Caso nao haja vertice,
    a posicao guardara o numero 0.

*/

void imprimeGrafo(GRAFO* g);

/*

    GRAFO grafoTransposto(GRAFO* g) recebe o endereco do grafo g e retorna o seu grafo
    transposto, ou seja, as colunas viram linhas e as linhas viram colunas.

*/

GRAFO grafoTransposto(GRAFO* g);