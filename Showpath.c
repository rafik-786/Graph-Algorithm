#include <stdio.h>
#include "Graph.c"
#include "dataStructures.c"
#include "header.h"

void BFS(Graph g, int *visited, int *parent, int startnode)
{
    Queue q;
    createQueue(&q, g.vertices + 1);

    QueuePush(&q, startnode);

    while (!QueueIsEmpty(q))
    {
        int cn = QueuePeek(q);
        QueuePop(&q);

        if (visited[cn])
            continue;

        visited[cn] = 1;

        for (int i = 1; i <= g.vertices; i++)
        {
            if (g.connect[cn][i] == 1 && !visited[i])
            {
                if (parent[i] == -1)
                    parent[i] = cn;
                QueuePush(&q, i);
            }
        }
    }
}

void path(Graph g, int startnode, int endnode)
{
    int *visited = createArray(g.vertices + 1, 0);
    int *parent = createArray(g.vertices + 1, -1);
    BFS(g, visited, parent, startnode);

    while (endnode != startnode)
    {
        printf("%d->", endnode);
        endnode = parent[endnode];
    }
    printf("%d", startnode);
}

int main(int argc, char const *argv[])
{
    freopen("Graph2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Graph g;

    //read vertices 

    read(g.vertices);

    //allocate memory for the graph
    createGraph(&g);

    // read graph
    readGraph(g);

    path(g, 5, 4);
    return 0;
}
