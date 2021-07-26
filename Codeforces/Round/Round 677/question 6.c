/*
node* findme(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }

}

*/

#include <stdio.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *head;


struct node *findme(struct node *tree, int val)
{
    if(tree == NULL) return NULL;

    if(val < tree->data)
    {
        return findme(tree->right, val);
    }
    else if(val > tree->data)
    {
        return findme(tree->left, val);
    }
    else if(val == tree->data)
    {
        return tree;
    }
}

void insert(int val)
{
    if(tree == NULL)
    {
        tree = (struct node*)malloc(sizeof (struct node));
        tree->data = val;

        return;
    }

    if(val < tree->data)
    {
        return findme(tree->right, val);
    }
    else if(val > tree->data)
    {
        return findme(tree->left, val);
    }
    else if(val == tree->data)
    {
        return;
    }
}

int main()
{
    int val;
    scanf("%d", val);

    struct node *ans = findme(head, val);
}
