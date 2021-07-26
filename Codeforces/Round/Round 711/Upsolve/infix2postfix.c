// Infix to Postfix

// Infix Equation: ( ( 4 / 2 ) + ( 9 * 2 ) - 7 )

// Postfix Equation: 4 2 / 9 2 * 7 - +

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Start of Stack Code
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

//End of Stack Code

// Start of second stack code

struct stack2
{
    int val;
    struct stack2 *next;
};

struct stack2 *head2 = NULL;

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

void initialize2() // 1
{
    head2 = NULL;

    return;
}

void pushnumber(int x) // 2
{
    /*
        Algorithm of pushing an element into the stack:

            1. Create a new box;
            2. Assign the value into the new box;
            3. Linked the new box with the last box;
            4. Shift the head pointer.

    */

    struct stack2 *new_box = (struct stack2*)malloc(sizeof (struct stack2)); // 1

    new_box->val = x; // 2
    new_box->next = head2; // 3
    head2 = new_box; // 4

    return;
}

int isempty2() // 3
{
    if(head2 == NULL) return 1;
    return 0;
}

int popnumber() // 5
{
    if(isempty2())
    {
        printf("Error! Stack is empty in pop function 2!\n");
        return 0;
    }

    int ret = head2->val;
    head2 = head2->next;

    return ret;
}

// End of second stack code


// Start of conversion code

char infix[500];
char postfix[500];

/*
 Infix to Postfix Algorithm:

    1. Start Traversing from Left to Right.
    2. If we find a closing bracket, we will start popping from top of the stack untill we find an opening bracket.
       And we insert everything into the output string except the opening and closing bracket.
    3. If we find a number, we insert it into output string (postfix eqn).
    4. If we find anything other than number and closing bracket, we push it into stack.

    Closing Bracket: )
    Opening Bracket: (

 Simulation:

    Infix Eqn: ( ( 4 / 2 ) + ( 9 * 2 ) - 7 )
    Stack:
    Element Type in stack: ( + - * / (data type = char)

    Postfix Eqn: 4 2 / 9 2 * 7 - +
*/

void infixtopostfix()
{
    int len = strlen(infix);
    int i;
    initialize();
    int index = 0;

    for(i = 0; i < len; i++) // 1
    {
        if(infix[i] == ')') // 2
        {
            while(isempty() == 0)
            {
                char topofstack = pop();

                if(topofstack == '(') break;

                // if we find + - * /, we will come here

                postfix[index] = topofstack; // insert the top of element into the string
                index++;
            }
        }
        else if('0' <= infix[i] && infix[i] <= '9') // && = and, || = or; // 3
        {
            postfix[index] = infix[i]; // insert the number into the string;
            index++;
        }
        else // 4
        {
            push(infix[i]);
        }
    }

    postfix[index] = '\0';


    return;

}

// End of converstion code

/*

    Inserting element into the array:

        Marjan;

        postfix += Marjan // It won't work;

        index = 0;
        postfix[index] = 'M'; /// postfix[0] = M;
        index++;

        index = 1;
        postfix[index] = 'A' // postfix[1] = A;
        index++;

        index = 2;
        postfix[index] = 'R' // postfix[2] = R;
        index++;

        index = 3;
        postfix[index] = 'J' // postfix[1] = J;
        index++;


*/


/*
    Infix Equation Solve Algorithm:

    % = reminder; //vagshesh
    5 % 2 = 1;

    Simulation:

    Precedence:

    % = 5;
    / = 4;
    * = 3;
    + = 2;
    - = 1;
    ( = 0;

    Input: ( ( 4 / 2 ) + (6 + 9 * 2 + 3) - 7)
    Output: 22

    Stack Int: 22
    Stack Char:

    a = 21;
    b = 6;
    c = a + b = 27;



*/


int precedence(char op)
{
    if(op == '%') return 5;
    if(op == '/') return 4;
    if(op == '*') return 3;
    if(op == '+') return 2;
    if(op == '-') return 1;

    return 0;
}

int applyoperation(int a, int b, char op)
{
    if(op == '%') return a % b;
    if(op == '/') return a / b;
    if(op == '*') return a * b;
    if(op == '+') return a + b;
    if(op == '-') return a - b;

    return 0;
}

int calculateinfixequation()
{
    initialize();
    initialize2();

    int len = strlen(infix);

//    printf("%s\n", infix);
    int i;

    for(i = 0; i < len; i++)
    {
        if(infix[i] == '(') push(infix[i]);
        else if('0' <= infix[i] && infix[i] <= '9') pushnumber(infix[i] - '0');
        else if(infix[i] == ')')
        {
            while(isempty() == 0)
            {
                char topofthestack = pop();

                if(topofthestack == '(') break;

                int b = popnumber();
                int a = popnumber();

                int c = applyoperation(a,b,topofthestack);

                pushnumber(c);
            }
        }
        else
        {
            while(isempty() == 0 && precedence(top()) >= precedence(infix[i]))
            {
                int b = popnumber();
                int a = popnumber();

                char op = pop();

                int c = applyoperation(a,b,op);

                pushnumber(c);
            }

            push(infix[i]);
        }
    }

    return popnumber();
}


int main()
{

    while(1)
    {
        scanf("%s", infix);

        infixtopostfix();

        printf("Here is the postfix function of the given infix: %s\n", postfix);

        int ans = calculateinfixequation();

        printf("The value of the infix and postfix function: %d\n", ans);
    }
    return 0;
}
