#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;
struct node *newnode = NULL;

void create()
{
    printf("how many node you have :");
    int a;
    scanf("%d", &a); 
    while (a--)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("enter data: ");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {

            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
    }
}
void display()
{
    temp = head;
    printf("the data in the link list are: \n");
    while (temp->next != head)
    {

        printf("%d ", temp->data);

        temp = temp->next;
    }
    printf("%d ", temp->data);
}

void insertfirst()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("enter the data you want to insert first: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {

        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    tail->next = head;
}
void insertlast()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("enter the data you want to insert last: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = head;
}
int length()
{

    int length = 1;

    temp = head;

    while (temp->next != head)
    {
        length++;
        temp = temp->next;
    }

    return length;
}
void insertinposition()
{
    int position;
    printf("in which position you want to enter new data: ");
    scanf("%d", &position);
    int size = length();
    if (position > size)
    {
        printf("invalid position(too large)\n");
    }
    else
    {
        temp = head;
        int i = 1;
        while (i < position - 1)
        {
            i++;
            temp = temp->next;
        }

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("enter the data you want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void dltfirst()
{
    temp = head;
    head = temp->next;
    free(temp);
    tail->next = head;
}
void dltlast()
{
    struct node *temp2 = NULL;
    temp = head;
    while (temp->next != head)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = head;
    tail = temp2;
    free(temp);
}
void dltfromposition()
{

    int position;
    printf("in which position you want to delete data: ");
    scanf("%d", &position);
    int size = length();
    if (position > size)
    {
        printf("invalid position(too large)\n");
    }
    else
    {
        struct node *temp2 = NULL;

        temp = head;
        int i = 1;
        while (i < position - 1)
        {
            i++;
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}
void reverse()
{

    struct node *curr = NULL;
    struct node *nextt = NULL;
    struct node *pre = NULL;

    curr = head;
    nextt = curr->next;
    while (curr != tail)
    {
        pre = curr;
        curr = nextt;
        nextt = curr->next;
        curr->next = pre;
    }
    nextt->next = tail;
    tail = nextt;
    head = tail->next;
}

int main()
{

    create();
    display();
    reverse();
    display();
     printf("%d %d",tail->next,head);
     printf("\n%d %d", tail->data, head->data);
}