#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int val;
    struct stack *prev;

} st;

/*
init()
push()
pop()
top()
isempty()
*/

st *head;

void init()
{
    head = NULL;
    return;
}

void push(int x)
{
    st *newbox = (st*)malloc(sizeof(st));

    newbox->val = x;
    newbox->prev = head;

    head = newbox;

    return;
}

void pop()
{
    if(head == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }

    head = head->prev;

    return;
}

int top()
{
    if(head == NULL)
    {
        printf("The stack is empty.\n");
        return -1;
    }

    return head->val;
}

int isempty() // return 1 if is empty, 0r 0 if it has element in it;
{
    if(head == NULL) return 1;
    return 0;
}

int main()
{

}
