#include <stdio.h>
#include <stdlib.h>

// NORMAL TREE CODE

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *crt_tree()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    printf("enter 0 for no more node or 1 for continue : ");
    int x;
    scanf("%d", &x);
    if (x == 0)
    {
        return 0;
    }
    printf("enter data : ");
    int t_data;
    scanf("%d", &t_data);
    newnode->data = t_data;
    printf("left node of %d\n", t_data);
    newnode->left = crt_tree();
    printf("right node of %d\n", t_data);
    newnode->right = crt_tree();
}

void pre_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    pre_order(root->left);
    pre_order(root->right);
    printf("%d ", root->data);
}

void in_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    pre_order(root->left);
    printf("%d ", root->data);
    pre_order(root->right);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int hight(struct node *newnode)
{
    if (newnode == NULL)
    {
        return -1;
    }
    return max(hight(newnode->left), hight(newnode->right)) + 1;
}

int main()
{
    struct node *root = NULL;
    root = crt_tree();
    printf("pre-order of tree : ");
    pre_order(root);
    printf("\n");
    printf("post-order of tree : ");
    post_order(root);
    printf("\n");
    printf("in-order of tree : ");
    in_order(root);
    printf("\n");
    int a = hight(root);
    printf("%d\n", a);
}
