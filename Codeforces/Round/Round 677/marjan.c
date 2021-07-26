#include <stdio.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *head;

struct node *insert(struct node *cursor, int val);

struct node *findme(struct node *cursor, int val)
{
    if(cursor == NULL) return NULL;

    if(val < cursor->data)
    {
        findme(cursor->right, val);
    }
    else if(val > cursor->data)
    {
        findme(cursor->left, val);
    }

    return cursor; // we found the value
}

int main()
{
    int val;
    scanf("%d", &val);

    struct node *ans = findme(head, val);

    return 0;
}


void printvalue_dfsorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}
