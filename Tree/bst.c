#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;

    struct node *left;
    struct node *right;
};
struct node *crt_newnode(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = crt_newnode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(struct node *root, int data)
{

    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int find_min(struct node *root)
{
    if (root == NULL)
    {
        printf("empty tree\n");
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int find_max(struct node *root)
{
    if (root == NULL)
    {
        printf("empty tree\n");
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int find_min_recursion(struct node *root)
{
    if (root == NULL)
    {
        printf("empty tree\n");
        return -1;
    }

    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return find_min_recursion(root->left);
    }
}
int find_max_recursion(struct node *root)
{
    if (root == NULL)
    {
        printf("empty tree\n");
        return -1;
    }

    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return find_min_recursion(root->right);
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int hight(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return max(hight(root->left), hight(root->right)) + 1;
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

    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}

void in_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 300);
  root = insert(root, 150);
  root = insert(root, 200);
  root = insert(root, 30);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 100);
    in_order(root);
    printf("\n");

    pre_order(root);
    printf("\n");

    post_order(root);
    printf("\n");

    if (search(root, 300) == true)
        printf("FOUND");

    else
        printf("NOT FOUND");
}
