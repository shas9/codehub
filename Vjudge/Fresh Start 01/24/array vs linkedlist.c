#include<stdio.h>
#include<stdlib.h>

int arr[5];
char name[5];


/*

Array: Memoery Inefficient, Time efficient.
Linked list: Memory efficient, Time inefficient.

*/

typedef struct people
{
    int phone;
    long long bank_balance;
    char address[30];

    struct people *next; // mandatory
} man;

man *head;

void init()
{
    head = (man*)malloc(sizeof(man));
    head->next = NULL;
}

void insert()
{
    man *cursor = head;

    while(cursor->next != NULL)
    {
        cursor = cursor->next;
    }

//    scanf(box);

    cursor->next = (man*)malloc(sizeof(man));
    cursor->next->next = NULL;

    return;
}

void indexing(int pos)
{
    man *cursor = head;
    int idx = 0;

    while(cursor->next != NULL && idx != pos)
    {
        cursor = cursor->next;
        idx++;
    }

    if(cursor->next == NULL)
    {
        printf("Sorry! This position doesn't exist / is invalid.\n");
        return;
    }

//    print(cursor);

    return;
}

int main()
{

}

