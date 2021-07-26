#include <stdio.h>
#include <stdlib.h>
#include <string.h> // uses mainly to use string

struct stack
{
    char val;
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

void push(char x) // 2
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

char top() // 4
{
    if(isempty())
    {
        printf("Error! Stack is empty in top function!\n");
        return 0;
    }

    return head->val;
}

char pop() // 5
{
    if(isempty())
    {
        printf("Error! Stack is empty in pop function!\n");
        return 0;
    }

    char ret = head->val;
    head = head->next;

    return ret;
}

/*

    Algorithm:

    1. We will traverse from left to right.
    2. if we encounter number, we will push that in the string.
    3. if we encounter + , - , * , / , ( then we will push that in stack
    4. if we encounter ), then we will start popping element untill we get an (.

*/



/*
    Infix Equation: ( ( 4 / 2 ) + ( 9 * 2 ) - 7 )
    Solution Demonstraton:

    Stack:
    String: 4 2 / 9 2 * 7 - +
*/


// Postfix Equation: 4 2 / 9 2 * 7 - +

// char a, b, A, B, +, -, 0, 1, 2, 9
void infix2postfix(char *eqn)
{
    char postfix[100];

    initialize();

    int len = strlen(eqn);

    int i;

    int idx = 0;

    for(i = 0; i < len; i++)
    {
        // you can also write '0' for 48 and '9' for 57

        if('0' <= eqn[i] && eqn[i] <= '9') postfix[idx++] = eqn[i];
        else if(eqn[i] == ')')
        {
            while(isempty() == 0)
            {
                char topchar = top();
                pop();

                if(topchar == '(') break;

                postfix[idx++] = topchar;
            }
        }
        else push(eqn[i]);
    }

    for(i = 0; i < idx; i++) printf("%c ", postfix[i]);

    printf("\n");
}

int main()
{
    int i;

    char infix[100];

    scanf("%s", infix);

    infix2postfix(infix);

    return 0;
}

