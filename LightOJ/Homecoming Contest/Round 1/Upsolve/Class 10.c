/* Last class briefing

    if(we get closing bracket) .....
    else if(we get number).....
    else ..... sqrt, ^,

    if(we get closing bracket) ......
    else if(we get an operator +, -, *, /, %) ........ ^
    else ......... // cosidering as number;

    num = 75;

    if(num >= 80) print(A+)
    else if(num >= 60) print(A-)
    else if(num >= 70) print(A)
    else print(F)
*/

/*
Problem Solve:

    Precendece:

    / = 4;
    * = 3;
    + = 2
    - = 1
    ( = 0

    Equation: ((A+B)*(C*D-E)*F/G)
    Stack:
    Answer: A B + C D * E - F G / * *                 // Precedence included
*/

/*
    if(front == rear) Queue is empty;
*/

#include <stdio.h>

int queue[20]; // overflow: code crash + you will lose your value
int front, rear;

void initialize()
{
    front = 0;
    rear = 0;
}

int enque(int x) //pushing an element
{
    queue[rear] = x;
    rear++;

    return x;
}

int getfront()
{
    return queue[front];
}

int deque() // popping an element
{
    int ret = queue[front];
    front++;
    return ret;
}

int isempty()
{
    if(front >= rear) return 1;

    return 0;
}

int main()
{
    int i;

    initialize();

    enque(36);
    enque(15);
    enque(17);
    enque(3);
    enque(25);
    enque(6);
    enque(18);
    enque(27);
    enque(36);
    enque(36);
    enque(32);


    for(i = 1;isempty() == 0; i++)
    {
        printf("%d-th popped value: %d\n", i, getfront());
        deque();
    }
}

