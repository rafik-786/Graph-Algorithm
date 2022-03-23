#include <stdio.h>
#include <stdlib.h>

#define read(A) scanf("%d", &A)
#define out(A) printf("%d\t", A)
#define nextLine printf("\n")
#define true 1
#define false 0
typedef struct g_r_a_p_h
{
    int vertices;
    int edges;
    int **graphMat;
} Graph;

void createGraph(Graph *g)
{

    (*g).graphMat = (int **)malloc(sizeof(int *) * ((*g).vertices + 1));

    if ((*g).graphMat == NULL)
        printf("Memory could not be assigned");

    for (int i = 1; i <= (*g).vertices; i++)
    {
        (*g).graphMat[i] = (int *)malloc(sizeof(int) * ((*g).vertices + 1));
    }
}

void inputGraph(Graph g)
{

    for (int i = 1; i <= (g).vertices; i++)
        for (int j = 1; j <= (g).vertices; j++)
            read(g.graphMat[i][j]);
}

void printGraph(Graph g)
{
    for (int i = 1; i <= (g).vertices; i++)
    {
        for (int j = 1; j <= (g).vertices; j++)
            out(g.graphMat[i][j]);
        nextLine;
    }
}

void printWithVertex(Graph g)
{
    for (int i = 0; i < g.vertices; i++)
        printf("\t%c", (char)(i + 'a'));
    nextLine;

    for (int i = 1; i <= g.vertices; i++)
    {
        printf("%c\t", (char)(i + 'a' - 1));
        for (int j = 1; j <= g.vertices; j++)
        {
            out(g.graphMat[i][j]);
        }
        nextLine;
    }
}

int main(int argc, char const *argv[])
{
#ifndef CHECKER
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Graph g;

    read(g.vertices);

    createGraph(&g);

    inputGraph(g);

    printWithVertex(g);

    return 0;
}
