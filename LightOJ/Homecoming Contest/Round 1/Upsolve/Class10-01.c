/*

Advantage:

 1. We don't have to be concerned about memory limit.

Disadvantage:

    1. Difficult procedure to handle than array;


Procedure:

    1. Design a box;
    2. Handle two different cursor.

*/


#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    initialize();
    int i, n;

    printf("Please enter the size of queue: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        int val;
        printf("Please enter the %d-th value: ", i);
        scanf("%d", &val);

        enque(val);
        display();
    }

    printf("++++++++++++++\n"); // Divide;

    for(i = 1; i <= n; i++)
    {
        printf("Now, the value %d is going to be dequed\n", deque());
        display();
    }
}

