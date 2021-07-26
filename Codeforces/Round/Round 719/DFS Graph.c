#include<stdio.h>
#include<stdlib.h> // for allocating memory

struct stack
{
    int val;
    struct stack *next;
};

struct stack *head = NULL;

/*

Variable declaration types:

1. Globally declared Variable. (Usually declares in the body of the code outside every function for global use)
2. Locally declared Variable (Usually declared in a particular function for limited use)
*/

/*

Stack Property:

1. Initialize Funtion. (Initialize the stack from the beginning)
2. Push Function. (Push an element at the top of the stack)
3. Cheker Function. (Check if a stack is empty)
4. Top Function. (Returns the top element from the stack)
5. Pop Function. (Delets the element from top of the stack and return that deleted element)
6. Display Function. (Display all the elements in the stack from top to bottom)

*/

void initialize() // 1
{
    head = NULL;

    return;
}

void push(int x) // 2
{
    /*
        Algorithm of pushing an element into the stack:

            1. Create a new box;
            2. Assign the value into the new box;
            3. Linked the new box with the last box;
            4. Shift the head pointer.

    */

    struct stack *new_box = (struct stack*)malloc(sizeof (struct stack)); // 1

    new_box->val = x; // 2
    new_box->next = head; // 3
    head = new_box; // 4

    return;
}

int isempty() // 3
{
    if(head == NULL) return 1;
    return 0;
}

int top() // 4
{
    if(isempty())
    {
        printf("Error! Stack is empty in top function!\n");
        return 0;
    }

    return head->val;
}

int pop() // 5
{
    if(isempty())
    {
        printf("Error! Stack is empty in pop function!\n");
        return 0;
    }

    int ret = head->val;
    head = head->next;

    return ret;
}

void display() // 6
{
    struct stack *t_head = head;

    printf("Values in stacks are: ");
    while(t_head != NULL)
    {
        printf("%d ", t_head->val);
        t_head = t_head->next;
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

void dfs(int src)
{
    push(src);
    dist[src] = 0;

    while(isempty() == 0)
    {
        int top = pop();

        struct node *cursor = graph[top];

        while(cursor->next != NULL)
        {
            if(dist[cursor->value] == -1) // not visited
            {
                dist[cursor->value] = dist[top] + 1;
                push(cursor->value);
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

    dfs(5);

    for(i = 1; i <= 10; i++) printf("Distance from source to %d is: %d\n", i, dist[i]);
}
