#include <stdio.h>
#include <stdlib.h>

int adjmat[11][11];

typedef struct node
{
    int val;
    int weight;
    struct node *next;

} graph;

graph *g[11];

void init()
{
    int i;

    for(i = 0; i <= 10; i++)
    {
        g[i] = (graph*)malloc(sizeof(graph));
    }

    return;
}

void insert(int src, int dest, int w)
{
    graph *cursor = g[src];

    while(cursor->next != NULL)
    {
        cursor = cursor->next;
    }

    cursor->val = dest;
    cursor->weight = w;
    cursor->next = (graph*)malloc(sizeof(graph));

    return;
}

int getpos(int src, int pos)
{
    graph *cursor = g[src];
    int idx = 0;

    while(cursor->next != NULL && idx != pos)
    {
        cursor = cursor->next;
        idx++;
    }

    if(cursor->next == NULL)
    {
        printf("The position does not exist.\n");
        return -1;
    }

    return cursor->val;
}


int main()
{

}
