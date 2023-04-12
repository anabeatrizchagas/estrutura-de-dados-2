// importando header

#include "03-grafo-s-nd-m-adj.h"

// implementando as funcoes

bool inicializaGrafo(GRAFO* g, int nv)
{
    if(nv < 1) // numero de vertices menor que o minimo
    {
        fprintf(stderr, "Erro: inicializaGrafo(GRAFO* g, int nv) - nv < 1");
        return (false);

    } else if(nv > MAX_NUM_VERTICES) { // numero de vertices maior que o maximo

        fprintf(stderr, "Erro: inicializaGrafo(GRAFO* g, int nv) - nv > que MAX_NUM_VERTICES");
        return (false);

    } else { // numero de vertices valido

        int i, j;

        for(i = 1; i <= nv; i++)
        {
            for(j = 1; j <= nv; j++)  g->m[i][j] = 0;
        }

        g->numArestas = 0;
        g->numVertices = nv;
        
        return (true);

    }

}

bool insereAresta(GRAFO* g, int v1, int v2)
{
    if(v1 < 1 || v2 < 1) // indice menor que o minimo
    {
        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - v1 ou v2 < que 1\n");

    } else if(v1 > MAX_NUM_VERTICES || v2 > MAX_NUM_VERTICES) { // indice maior que o maximo

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - v1 ou v2 > que NUM_MAX_VERTICES\n");

    } else if(v1 == v2) { // no grafo nao direcionado, a matriz tem diagonal vazia

        fprintf(stderr, "Erro: insereAresta(GRAFO* g, int v1, int v2) - v1 == v2\n");

    } else { // indice valido

        if(g->m[v1][v2] == 0) g->numArestas++;
        g->m[v1][v2] = 1;
        g->m[v2][v1] = 1;

        return (true);

    }

    return(false);

}

bool existeAresta(GRAFO* g, int v1, int v2)
{
    if(v1 < 1 || v2 < 1) // indice menor que o minimo
    {
        fprintf(stderr, "Erro: existeAresta(GRAFO* g, int v1, int v2) - v1 ou v2 < que 1\n");

    } else if(v1 > MAX_NUM_VERTICES || v2 > MAX_NUM_VERTICES) { // indice maior que o maximo

        fprintf(stderr, "Erro: existeAresta(GRAFO* g, int v1, int v2) - v1 ou v2 > que NUM_MAX_VERTICES\n");

    } else { // indice valido

        if(g->m[v1][v2] == 1) return (true);

    }

    return (false);

}

bool retiraAresta(GRAFO* g, int v1, int v2)
{
    if(v1 < 1 || v2 < 1) // indice menor que o minimo
    {
        fprintf(stderr, "Erro: retiraAresta(GRAFO* g, int v1, int v2) - v1 ou v2 < que 1\n");

    } else if(v1 > MAX_NUM_VERTICES || v2 > MAX_NUM_VERTICES) { // indice maior que o maximo

        fprintf(stderr, "Erro: retiraAresta(GRAFO* g, int v1, int v2) - v1 ou v2 > que NUM_MAX_VERTICES\n");

    } else { // indice valido

        if(g->m[v1][v2] != 0) // tem aresta para retirar
        {
            g->m[v1][v2] = 0;
            g->m[v2][v1] = 0;

            g->numArestas--;

            return (true);

        }

    }

    return (false);

}

void liberaGrafo(GRAFO* g)
{
    g->numArestas = 0;
    g->numVertices = 0;

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

GRAFO grafoTransposto(GRAFO* g) // porque o grafo g e uma matriz simetrica
{
    return (*g);

}

int main()
{

    return (0);
    
}