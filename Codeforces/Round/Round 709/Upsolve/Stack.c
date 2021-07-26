#include <stdio.h>

int stack[500];

struct stack_list
{
    int val;
    struct stack_list *prev;
};

int main()
{
    int position = 0;
    int i;

    for(i = 1; i <= 10; i++)
    {
        stack[position] = i;
        position++;
    }

    printf("Size of stack: %d\n", position);

    while(position >= 1)
    {
        position--;
        printf("%d ", stack[position]);
    }

    printf("\n");

    // Now starts linked list based stack

    printf("Linked List Starts\n");

    struct stack_list *head = NULL;

    for(i = 1; i <= 10; i++)
    {
        struct stack_list *newbox = (struct stack_list*)malloc(sizeof(struct stack_list));

        newbox->val = i;
        newbox->prev = head;
        head = newbox;
    }

    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->prev;
    }

    printf("\n");
}

(4 + (6 * (7 + 8) * 9 + (3 + 6 - 3)))

( = Opening Bracket
) = Closing Bracket

Stack =

cnt = +816 + 4 = 820

Algorithm:

1. Push value into stack
2. If we get closing bracket


//2 + 5 * (6 + 6) / 3  = 2 + 30 + 2 = 34

10
1 2 4 8 6 10 15 17 19 14 13 16
1 2 3 4 5 6  7  8  9  10 11 12

Ans[1] = 0;
Ans[2] = 1;
Ans[4] = 2;
Ans[8] = 4;
Ans[6] = 4;
Ans[10] = 6;
Ans[15] = 10;
Ans[17] = 15;
Ans[19] = 17;
Ans[14] = 10;
Ans[13] = 10;
Ans[16] = 13;

Stack: 1 2 4 6 10 13 16

{
    int arr[] = {1,2,4,8,6,10,15,17,19,14,13,16};
    int stack[100];
    int cursor = 0;
    int i;

    10,

    14

    for(i = 0; i < 12; i++)
    {
        int choto = -1;

        while(cursor >= 1)
        {
            if(stack[cursor] > arr[i])
            {
                cursor--;
            }
            else
            {
                break;
            }
        }


        ans[i] = cursor;

        stack[++cursor] = i;

    }
}


BODMAS
=>  Bracket
    Of
    Division
    Multiplication
    Addition
    Subtraction


    4 8 6 15 20 25 12










