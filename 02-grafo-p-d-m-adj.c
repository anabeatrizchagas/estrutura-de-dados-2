// importando header

#include "02-grafo-p-d-m-adj.h"

// implementando funcoes

bool inicializaGrafo(GRAFO* g, int nv)
{
    if(nv < 1) // numero de vertices menor que o minimo
    {
        fprintf(stderr, "Erro: inicializaGrafo(GRAFO* g, int nv) - nv < 1\n");
        return (false);

    } else if(nv > MAX_NUM_VERTICES) { // numero de vertices maior que o maximo

        fprintf(stderr, "Erro: inicializaGrafo(GRAFO* g, int nv) - nv > NUM_MAX_VERTICES\n");
        return (false);

    } else { // numero de vertices valido

        int i, j;

        for(i = 1; i <= nv; i++)
        {
            for(j = 1; j <= nv; j++) g->m[i][j] = AN;
        }

        g->numArestas = 0;
        g->numVertices = nv;

    }

    return (true);

}

bool insereAresta(GRAFO* g, int v1, int v2, PESO p)
{
    if(v1 < 1 || v2 < 1) // indice menor que o minimo
    {
        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - v1 ou v2 < 1\n");
        return (false);

    } else if(v1 > g->numVertices || v2 > g->numVertices) { // indice maior que o maximo

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - v1 ou v2 > g->numVertices\n");
        return (false);

    } else if(p < MIN_PESO) { // peso menor que o minimo

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - p < MIN_PESO \n");
        return (false);

    } else if(p > MAX_PESO) { // peso maior que o maximo

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - p > MAX_PESO\n");
        return (false);

    } else { // indice e peso validos

        if(g->m[v1][v2] == AN) g->numArestas++;
        g->m[v1][v2] = p;
        return (true);

    }

}

bool existeAresta(GRAFO* g, int v1, int v2)
{
    if(v1 < 1 || v2 < 1) // indice menor que o minimo
    {
        fprintf(stderr, "Erro: existeAresta(GRAFO* g, int v1, int v2) - v1 ou v2 < 1");

    } else if(v1 > g->numVertices || v2 > g->numVertices) { // indice maior que o maximo

        fprintf(stderr, "Erro: existeAresta(GRAFO* g, int v1, int v2) - v1 ou v2 > g->numVertices");

    } else { // indice valido

        if(g->m[v1][v2] != AN) return (true);
        else return (false);

    }

}

bool retiraAresta(GRAFO* g, int v1, int v2)
{
    if(v1 < 1 || v2 < 1) // indice menor que o minimo
    {
        fprintf(stderr, "Erro: retiraAresta(GRAFO* g, int v1, int v2, bool direc) - v1 ou v2 < 1");
        return (false);

    } else if(v1 > g->numVertices || v2 > g->numVertices) { // indice maior que o maximo

        fprintf(stderr, "Erro: retiraAresta(GRAFO* g, int v1, int v2, bool direc) - v1 ou v2 > g->numVertices");
        return (false);

    } else { // indice valido

        if(g->m[v1][v2] != AN) g->numArestas--;
        g->m[v1][v2] = AN;

    }

    return (true);


}

bool liberaGrafo(GRAFO* g)
{
    g->numArestas = 0;
    g->numVertices = 0;

    return (true);
 
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

PESO retornaMin(GRAFO* g)
{
    if(g->numArestas == 0) // grafo vazio (sem pesos validos)
    {
        fprintf(stderr, "Erro: retornaMin(GRAFO* g) o grafo g indicado esta vazio\n");
        
    } else { // grafo com arestas (tem peso validos)

        int i, j;
        PESO resp = 999;

        for(i = 1; i <= g->numVertices; i++)
        {
            for(j = 1; j <= g->numVertices; j++) 
            {
                if(g->m[i][j] != AN && g->m[i][j] < resp) resp = g->m[i][j];
            }

        }    

        return (resp);

    }

}

GRAFO grafoTransposto(GRAFO* g)
{
    int i, j;

    GRAFO resp;
    resp.numArestas = g->numArestas;
    resp.numVertices = g->numVertices;

    for(i = 1; i <= g->numVertices; i++)
    {
        for(j = 1; j <= g->numVertices; j++) resp.m[i][j] = g->m[j][i];
    }

    return (resp);

}

int main()
{

    return (0);
    
}