#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 5
int stack[max];
int top = -1;

void push()
{
    int data;
    printf("enter data you want to push : ");
    scanf("%d", &data);
    if (top == max - 1)
    {
        printf("overflow\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
void pop()
{

    if (top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("popped item : %d\n", stack[top]);
        top--;
    }
}
void peek()
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("peeked item : %d", stack[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (int j = top; j >= 0; j--)
        {

            printf("%d ", stack[j]);
        }
        printf("\n");
    }
}
int main()
{
    push();
    push();
    push();
    push();
    push();
    push();
    display();
    pop();
    pop();
    display();
    push();
    display();
    peek();
}