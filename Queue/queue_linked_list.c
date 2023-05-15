#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *tail;
struct node *newnode;

void crt_queue()
{
    head = NULL;
    tail = NULL;
}
void crt_newnode()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("data you want to push in queue : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}

void enque()
{
    crt_newnode();
    if (head == NULL && tail == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}
void dequeue()
{

    if (head == NULL && tail == NULL)
    {
        printf("queue is empty so dequeue is not possible\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        printf("dequeuing %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}

void display()
{

    if (head == NULL && tail == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        struct node *temp;

        temp = head;
        printf("the queue is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    crt_queue();
    enque();
    enque();
    enque();
    enque();
    enque();
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
}