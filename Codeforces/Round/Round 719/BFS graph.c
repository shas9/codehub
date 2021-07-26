#include<stdio.h>
#include<stdlib.h> // for allocating memory

struct queue
{
    int val;
    struct queue *next;
};

struct queue *front;
struct queue *rear;

/*
Function Name:

1. Initialize.
2. Enque
3. Deque
4. Check Function.
5. Getfront.
6. Display.

*/

void initialize()
{
    rear = (struct queue*)malloc(sizeof(struct queue));
    front = rear;
}

int isempty()
{
    if(front == rear) return 1; // It is empty;

    return 0; // Queue has value inside it.
}

int enque(int x) // Push
{
    /*
        Algorithm:
            1. Insert Value into rear box;
            2. Craete a new box;
            3. Linked up the rear box with new box
            4. Shift the rear into new box;
            5. Set the value of next of rear box == NULL;
    */

    rear->val = x; // 1
    struct queue *new_box = (struct queue*)malloc(sizeof(struct queue)); // 2
    rear->next = new_box; // 3
    rear = new_box; // 4;
    rear->next = NULL; // 5

    return x;
}

int deque()
{
    if(isempty() == 1)
    {
        printf("Queue is empty\n");
        return 0;
    }

    int ret = front->val;
    front = front->next;

    return ret;
}

int getfront()
{
    if(isempty() == 1)
    {
        printf("Queue is empty\n");
        return 0;
    }

    return front->val;
}

void display()
{
    if(isempty() == 1)
    {
        printf("Queue is empty\n");
        return;
    }

    struct queue *cursor = front;

    while(cursor->next != NULL)
    {
        printf("%d ", cursor->val);
        cursor = cursor->next;
    }

    printf("\n");

    return;
}

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

int dist[103];

void bfs(int src)
{
    enque(src);
    dist[src] = 0;

    while(isempty() == 0)
    {
        int top = deque();

        struct node *cursor = graph[top];

        while(cursor->next != NULL)
        {
            if(dist[cursor->value] == -1) // not visited
            {
                dist[cursor->value] = dist[top] + 1;
                enque(cursor->value);
            }

            cursor = cursor->next;
        }
    }

    return;
}

int main()
{
    init(); // graph storing adjacency list
    initialize(); // queue

    int edge;
    int i, j;

    scanf("%d", &edge);

    for(i = 1; i <= edge; i++)
    {
        int src, dest;
        scanf("%d%d", &src, &dest);

        add_undirected_edge(src,dest,0);
    }

    for(i = 1; i <= 10; i++) dist[i] = -1;

    bfs(5);

    for(i = 1; i <= 10; i++) printf("Distance from source to %d is: %d\n", i, dist[i]);
}
