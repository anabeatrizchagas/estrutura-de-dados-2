// importando header

#include "01-grafo-s-d-m-adj.h"

// implementando funcoes

bool inicializaGrafo(GRAFO* g, int nv)
{
    if(nv >= 1 && nv <= MAX_NUM_VERTICES) // numero de vertices for valido
    {
        int i, j;

        g->numArestas = 0;
        g->numVertices = nv;

        for(i = 1; i <= nv; i++)
        {
            for(j = 1; j <= nv; j++) g->m[i][j] = 0;
        }

        return (true);

    } else if (nv < 1) { // numero de vertices menor que 1

        fprintf(stderr, "Erro: inicializaGrafo(GRAFO* g, int nv) - nv < 1");

    } else { // numero de vertices maior que o limite

        fprintf(stderr, "Erro: inicializaGrafo(GRAFO* g, int nv) - nv > %d", MAX_NUM_VERTICES);

    }

    return (false);

}

bool insereAresta(GRAFO* g, int v1, int v2)
{
    if((v1 >= 1 && v1 <= g->numVertices) && (v2 >= 1 && v2 <= g->numVertices))
    {
        if(g->m[v1][v2] != 1)
        {
            g->m[v1][v2] = 1;
            g->numArestas++;

        }

        return (true);

    } else if(v1 < 1 || v2 < 1) {

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2, int direc) - v1 ou v2 < 1");

    } else {

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2, int direc) - v1 ou v2 > g->numVertices");

    }

    return (false);

}

bool existeAresta(GRAFO* g, int v1, int v2)
{
    if((v1 > 0 && v2 > 0) && (v1 <= g->numVertices && v2 <= g->numVertices))
    {
        if(g->m[v1][v2] == 1) return (true);

    } else if(v1 < 1 || v2 < 1) {

        fprintf(stderr, "Erro: existeAresta(GRAFO* g, int v1, int v2) - v1 ou v2 menor que um\n");

    } else if (v1 > g->numVertices || v2 > g->numVertices) {

        fprintf(stderr, "Erro: existeAresta(GRAFO* g, int v1, int v2) - v1 ou v2 maior que qtd de vertices\n");

    } else return (false);

}

bool retiraAresta(GRAFO* g, int v1, int v2)
{
    if(v1 > 0 && v2 > 0 && v1 <= g->numVertices && v2 <= g->numVertices) 
    {
        if(g->m[v1][v2] == 1) 
        {
            g->m[v1][v2] = 0;
            g->numArestas--;

            return (true);

        }

    } else if(v1 < 1 || v2 < 1) {

        fprintf(stderr, "Erro: retiraAresta(GRAFO* g, int v1, int v2, int direc) - v1 ou v1 < 1");

    } else if(v1 > g->numVertices || v2 > g->numVertices) {

        fprintf(stderr, "Erro: retiraAresta(GRAFO* g, int v1, int v2, int direc) - v1 ou v1 > g->numVertices");

    }

    return (false);

}

void liberaGrafo(GRAFO* g)
{
    g->numVertices = 0;
    g->numArestas = 0;

}

void imprimeGrafo(GRAFO* g)
{
    int i, j;

    for(i = 1; i <= g->numVertices; i++)
    {
        for(j = 1; j <= g->numVertices; j++) printf("%d ", g->m[i][j]);
        printf("\n");

    }

}

GRAFO grafoTransposto(GRAFO* g)
{
    //if(g->numVertices == 0) return (g);

    GRAFO resp;
    resp.numArestas = g->numArestas;
    resp.numVertices = g->numVertices;

    int i, j;

    for(i = 1; i <= resp.numVertices; i++)
    {
        for(j = 1; j <= resp.numVertices; j++) resp.m[j][i] = g->m[i][j]; 
    }

    return (resp);

}

int main()
{

    return 0;

}