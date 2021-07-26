#include<stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *head;

void print_inorder(struct node *tree)
{
    if(tree != NULL)
    {
        print_inorder(tree->left);
        printf("%d\n", tree->data);
        print_inorder(tree->right);
    }

    return;
}

void print_preorder(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d\n", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

    return;
}

void print_postorder(struct node *tree)
{
    if(tree != NULL)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n", tree->data);
    }

    return;
}

// Printing In Order: 8, 4, 2, 5, 1, 6, 3 [Left - Node - Right]
// Printing DFS Order / Pre Order: 1, 2, 4, 8, 5, 3, 6 [Node - Left - Right]
// Printing Post Order: 8, 4, 5, 2, 6, 3, 1 [Left - Right - Node]

int main()
{
    print_inorder(head);
    print_preorder(head);
    print_postorder(head);
}
