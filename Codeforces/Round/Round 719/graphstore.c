#include<stdio.h>
#include<stdlib.h> // for allocating memory

struct node
{
    int value, cost;
    struct node *next;
} *graph[103];

void init()
{
    int i;

    for(i = 0; i <= 100; i++)
    {
        graph[i] = (struct node*)malloc(sizeof (struct node));
        graph[i]->next = NULL;
    }

    return;
}

void addedge(int src, int dest, int cost)
{
    struct node *head = graph[src];

    while(head->next != NULL)
    {
        head = head->next;
    }

    head->value = dest;
    head->cost = cost;
    head->next = (struct node*)malloc(sizeof (struct node));
    head->next->next = NULL;

    return;
}

void add_undirected_edge(int src, int dest, int cost)
{
    addedge(src, dest, cost);
    addedge(dest, src, cost);

    return;
}

void printedge(int src)
{
    struct node *head = graph[src];

    printf("The edges connected to %d are: ", src);

    while(head->next != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");

    return;
}

void printedgewithcost(int src)
{
    struct node *head = graph[src];

    printf("The edges connected to %d are: ", src);

    while(head->next != NULL)
    {
        printf("%d with cost = %d,", head->value, head->cost);
        head = head->next;
    }

    printf("\n");

    return;
}

int main()
{
    init();

    int edge, i;

    scanf("%d", &edge);

    for(i = 1; i <= edge; i++)
    {
        int src, dest, cost;
        scanf("%d%d%d", &src, &dest, &cost);

        add_undirected_edge(src, dest, cost);
    }

    for(i = 0; i <= 100; i++)
    {
        printedgewithcost(i);
    }

    int ask;
    scanf("%d", &ask);

    for(i = 1; i <= ask; i++)
    {
        int src, dest, cost;
        scanf("%d%d%d", &src, &dest, &cost);

        addedge(src,dest,cost);
        printedge(src);
    }
}
