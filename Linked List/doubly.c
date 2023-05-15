#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *pre;
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
        newnode->pre = NULL;
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
            newnode->pre = tail;
            tail = newnode;
        }
    }
}
void display()
{

    temp = head;
    printf("data in the list are :\n");
    while (temp != NULL)
    {

        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void fordisplay()
{

    temp = head;
    printf("data in the list are (forword) :\n");
    while (temp != NULL)
    {

        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void backdisplay()
{

    temp = tail;
    printf("data in the list are (backword) :\n");
    while (temp != NULL)
    {

        printf("%d ", temp->data);
        temp = temp->pre;
    }
    printf("\n");
}
void insertfirst()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->pre = NULL;
    newnode->next = NULL;
    printf("enter data you want to insert first: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {

        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
    }
}
void insertlast()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->pre = NULL;
    newnode->next = NULL;
    printf("enter data you want to insert last: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {

        head = tail = newnode;
    }
    else
    {
        newnode->pre = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
int length()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertinposition()
{
    int size = length();
    printf("in which position you want to insert data: ");
    int position;
    scanf("%d", &position);
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

            temp = temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->pre = NULL;
        newnode->next = NULL;
        printf("enter data you want to insert: ");
        scanf("%d", &newnode->data);

        newnode->pre = temp;
        newnode->next = temp->next;
        temp->next->pre = newnode;
        temp->next = newnode;
    }
}
void dltfirst()
{
    temp = head;
    head = temp->next;
    head->pre = NULL;
    free(temp);
}
void dltlast()
{

    temp = tail;
    tail = tail->pre;
    tail->next = NULL;
    free(temp);
}

void dltfromposition()
{

    int size = length();
    printf("in which position you want to delete data: ");
    int position;
    scanf("%d", &position);
    if (position > size)
    {

        printf("invalid position(too large)\n");
    }
    else
    {

        temp = head;
        int i = 1;
        while (i < position)
        {

            temp = temp->next;
            i++;
        }
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
    }
}

void reverse()
{

    struct node *current = NULL;
    struct node *nextnode = NULL;
    current = head;
    while (current != 0)
    {

        nextnode = current->next;
        current->next = current->pre;
        current->pre = nextnode;
        current = nextnode;
    }
    temp = head;
    head = tail;
    tail = temp;
}
void search()
{

    int a;
    printf("enter the data you are searching: ");
    scanf("%d", &a);
    temp = head;
    while (temp != 0)
    {

        if (a == temp->data)
        {

            printf("match found\n");
            break;
        }
        else
        {
            printf("match not found\n");
            break;
        }
        temp = temp->next;
    }
}

int main()
{

    create();
    fordisplay();
    search();
}