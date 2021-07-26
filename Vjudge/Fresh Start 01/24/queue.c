#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int val;
    struct queue *next;
} qq;

qq *front, *back;

/*

init()
enque()
deque()
top()
isempty()

*/

void init()
{
    front = back = (qq*)malloc(sizeof(qq));
}

int isempty()
{
    if(front == back) return 1;

    return 0;
}

void enque(int x) // push
{
    back->val = x;
    back->next = (qq*)malloc(sizeof(qq));
    back = back->next;

    return;
}

void deque() // pop
{
    if(isempty())
    {
        printf("The queue is empty.\n");
        return;
    }

    front = front->next;

    return;
}

void edit(int x)
{
    if(isempty())
    {
        printf("The queue is empty.\n");
        return;
    }

    front->val = x;

    return;
}

int top()
{
    if(isempty())
    {
        printf("The queue is empty.\n");
        return -1;
    }

    return front->val;
}

int main()
{

}
