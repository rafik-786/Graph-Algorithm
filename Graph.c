#include <stdio.h>
#include <stdlib.h>

typedef struct g_r_a_p_h
{
    int vertices;
    int edges;
    int **connect;

} Graph;

void createGraph(Graph *g)
{

    g->connect = (int **)malloc(sizeof(int *) * (g->vertices + 1));

    for (int i = 1; i <= g->vertices; i++)
    {
        g->connect[i] = (int *)malloc(sizeof(int) * (g->vertices + 1));
    }
}

void readGraph(Graph g)
{
    for (int i = 1; i <= g.vertices; i++)
        for (int j = 1; j <= g.vertices; j++)
            scanf("%d", &g.connect[i][j]);
}

void printGraphWithvertex(Graph g)
{

    for (int i = 1; i <= g.vertices; i++)
        printf("\t%d", i);

    printf("\n");

    for (int i = 1; i <= g.vertices; i++)
    {

        for (int j = 0; j <= g.vertices; j++)
        {
            if (j == 0)
                printf("%d", i);
            else
                printf("\t%d", g.connect[i][j]);
        }
        printf("\n");
    }
}
