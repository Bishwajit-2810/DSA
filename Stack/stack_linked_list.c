#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top;
struct node *temp;
void crt_stack()
{

    top = NULL;
    temp = NULL;
}

void push()
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("data you want to push in stack : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (top == NULL)
    {

        top = temp = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
void pop()
{

    if (top == NULL)
    {

        printf("there is nothing to pop\n");
    }
    else
    {
        temp = top;
        printf("poped the last data from stack which is %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}
void peek()
{
    temp = top;

    printf("peeking the data form the stack which is %d\n", temp->data);
}
void display()
{

    temp = top;
    if (temp == NULL)
    {
        printf("no data in stack to show\n");
    }
    else
    {
        printf("the stack data is ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    crt_stack();
    push();
    display();
    push();
    push();
    display();
    pop();
    display();
    pop();
    peek();
    pop();
    pop();
    display();
}