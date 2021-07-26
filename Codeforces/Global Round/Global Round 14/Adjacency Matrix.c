#include<stdio.h>

int adjacencymatrix[110][110];

void init()
{
    int i, j;

    for(i = 0; i <= 100; i++)
        for(j = 0; j <= 100; j++)
            adjacencymatrix[i][j] = 0; //
}

void addege(int u, int v, int dir)
{
    // dir == 1 means bi directional edge;

    adjacencymatrix[u][v] = 1;
    if(dir == 1) adjacencymatrix[v][u] = 1; // Bi-Directional
}

void printmatrix(int node)
{
    int i, j;

    for(i = 0; i <= node; i++)
    {
        for(j = 0; j <= node; j++)
        {
            printf("%d ", adjacencymatrix[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    init();

    int i, j;

    int edge;

    scanf("%d", &edge);

    for(i = 1; i <= edge; i++)
    {
        int u, v;

        scanf("%d%d", &u, &v);

        addege(u,v,1);
    }

    printmatrix(100);
}

