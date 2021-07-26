#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right, *middle;
} node;

typedef int samin;

node *pt;

// malloc = memory allocation

int main()
{
    samin x;

    pt = (node *)malloc(sizeof(node)); // memory allocated for pt

    pt -> data = 14; // assigned 14 to pt data member

    pt->left = (node *)malloc(sizeof(node)); // memory allocated for left;


    pt->right = (node *)malloc(sizeof(node)); // memory allocated for right;
    pt->middle = (node *)malloc(sizeof(node)); // memory allocated for middle;

    return 0;
}

/*

start = 8;
end = 16;

if(start <= time && time <= end)

240 hour;
int totalhour = 280;

int overtime = 280 - 240;
int overtimesalary = 900;

int extraovertimemoney = overtime * overtimesalary;

int dose;

if(dose == 0) No vaccine taken;
if(dose == 1) 1 dose taken;
if(dose == 2) Dose has been completed;
*/
