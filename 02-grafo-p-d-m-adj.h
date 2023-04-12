// ===================== GRAFO PONDERADO (COM PESO NAS ARESTAS) E DIRECIONADO =====================

// importando pacotes

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// definindo tamanho padrao e peso da aresta nula

#define MAX_NUM_VERTICES 20 // numero maximo de vertices que pode existir no grafo
#define MAX_PESO 10 // peso maximo de uma aresta
#define MIN_PESO 0 // peso minimo de uma aresta
#define AN -1 // se a aresta nao existe, seu peso e -1

// criando grafo a partir de uma matriz de adjacencia

typedef int PESO;

typedef struct 
{
    PESO m[MAX_NUM_VERTICES + 1][MAX_NUM_VERTICES + 1]; // vertices enumerados de 1 a MAX_NUM_VERTICES
    int numArestas;
    int numVertices;

} GRAFO;

// declarando funcoes

/*

    bool inicializaGrafo(GRAFO* g, int nv) recebe como parametro o endereco do grafo g 
    e um int nv que e a quantidade de vertices que tera nesse grafo. A funcao inicializa 
    com 0 uma matriz de adjacencia que representa o grafo. Alem disso, tambem atualiza o 
    numero de vertices e zera o numero de arestas do grafo.

*/

bool inicializaGrafo(GRAFO* g, int nv);

/*

    bool insereAresta(GRAFO* g, int v1, int v2, PESO p) recebe o endereco do grafo g, um
    int v1 e um int v2 que sao vertices e o PESO p, que e o peso da aresta que sera inserida.
    Se v1 e v2 forem vertices validos, a funcao ira inserir uma aresta que sai de v1 e
    chega em v2 com peso p. Ademais ira incrementar uma unidade no numero de arestas do grafo.

*/

bool insereAresta(GRAFO* g, int v1, int v2, PESO p);

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
    uma aresta que sai de v1 e chega em v2, a funcao a retirara, decrementara o numero de arestas
    e retornara true. Caso nao haja, retornara false.

*/

bool retiraAresta(GRAFO* g, int v1, int v2);

/*

    void liberaGrafo(GRAFO* g) recebe o endereco do grafo g e zera o numero de vertices
    e arestas dele. Dessa forma, ele e reinicializado.

*/


bool liberaGrafo(GRAFO* g);

/*

    void imprimeGrafo(GRAFO* g) recebe o endereco do grafo g e imprime a matriz de
    adjacencia que o representa. Nessa matriz, o AN sinaliza que nao ha uma aresta 
    que sai do vertice na linha i e chega no vertice na coluna j. Caso haja aresta,
    a posicao guardara o peso dela.

*/

void imprimeGrafo(GRAFO* g);

/*

    PESO retornaMin(GRAFO* g) recebe o endereco do grafo g e retorna o menor peso desse grafo.
    Caso o grafo nao possua arestas, a funcao retorna um erro informando que nao existe nenhuma aresta.

*/

PESO retornaMin(GRAFO* g);

/*

    GRAFO grafoTransposto(GRAFO* g) recebe o endereco do grafo g e retorna o seu grafo
    transposto, ou seja, as colunas viram linhas e as linhas viram colunas.

*/

GRAFO grafoTransposto(GRAFO* g);