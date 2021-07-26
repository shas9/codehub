#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int i;

    initialize();

    for(i = 1; i <= 10; i++) push(i); // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

    display(); // 10, 9, 8, 7, 6, 5,  4, 3, 2, 1

    while(isempty() == 0)
    {
        printf("%d is top of the element.\n", top());
        printf("%d is the element that is going to be deleted.\n", pop());
        display();
    }

    // Now the stack is empty.
    top();
    pop();
    printf("Function is empty: %d\n", isempty());

    return 0;
}
