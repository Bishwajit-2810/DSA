#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int id;
    char name[50];
    float mark;
    char sec;
    struct student *next;
} node;
node *head = NULL;
node *temp = NULL;
node *newstudent = NULL;
void creat_new_stu()
{
    head = NULL;
    int a;
    printf("how many student is their :");
    scanf("%d", &a);
    while (a--)
    {
        newstudent = (node *)malloc(sizeof(node));
        printf("data input system 1st ID then space then name then section then mark\n");
        printf("input your student data : ");
        scanf("%d %s %C %f", &newstudent->id, &newstudent->name, &newstudent->sec, &newstudent->mark);

        newstudent->next = NULL;
        if (head == NULL)
        {
            head = temp = newstudent;
        }
        else
        {
            temp->next = newstudent;
            temp = newstudent;
        }
    }
}
void insert_new_first()
{

    newstudent = (struct student *)malloc(sizeof(struct student));
    printf("data input system 1st ID then space then name then section then mark\n");
    printf("input your student data : ");
    scanf("%d %s %C %f", &newstudent->id, &newstudent->name, &newstudent->sec, &newstudent->mark);
    newstudent->next = head;
    head = newstudent;
}
void insert_new_last()
{

    newstudent = (node *)malloc(sizeof(node));
    printf("data input system 1st ID then space then name then section then mark\n");
    printf("input your student data : ");
    scanf("%d %s %C %f", &newstudent->id, &newstudent->name, &newstudent->sec, &newstudent->mark);
    temp = head;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    temp->next = newstudent;
}
int student_list_length()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {

        temp = temp->next;
        count++;
    }
    return count;
}
void insert_in_position()
{
    int position;
    printf("desired position :");
    scanf("%d", &position);

    newstudent = (node *)malloc(sizeof(node));
    printf("data input system 1st ID then space then name then section then mark\n");
    printf("input your student data : ");
    scanf("%d %s %C %f", &newstudent->id, &newstudent->name, &newstudent->sec, &newstudent->mark);

    int count = student_list_length();
    if (position > count)
    {
        printf("invalid position");
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
        newstudent->next = temp->next;
        temp->next = newstudent;
    }
}
void delete_first()
{
    temp = head;
    head = temp->next;
    free(temp);
}
void delete_last()
{
    struct student *prestudent;
    temp = head;
    while (temp->next != 0)
    {
        prestudent = temp;
        temp = temp->next;
    }
    if (temp == head)
    {

        head = 0;
        free(temp);
    }
    else
    {
        prestudent->next = NULL;
        free(temp);
    }
}
void delete_from_position()
{
    struct student *nextstudent;
    int position;
    printf("desired position for delete : ");
    scanf("%d", &position);

    int count = student_list_length();
    if (position > count)
    {
        printf("invalid position");
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
        nextstudent = temp->next;
        temp->next = nextstudent->next;
    }
}
void reverse()
{
    struct student *prestudent = 0;
    struct student *curstudent = NULL;
    struct student *nextstudent = NULL;
    curstudent = nextstudent = head;
    while (curstudent != 0)
    {
        nextstudent = curstudent->next;
        curstudent->next = prestudent;
        prestudent = curstudent;
        curstudent = nextstudent;
    }
    head = prestudent;
}
void display()
{
    temp = head;
    int i = 1;
    while (temp != 0)
    {
        printf("Student no : %d\n", i);
        printf("ID : %d\nName : %s\nSec : %c\nMark : %.2f\n", temp->id, temp->name, temp->sec, temp->mark);
        temp = temp->next;
        i++;
    }
}
void tr_display()
{
    int position;
    scanf("%d", &position);

    temp = head;
    int i = 1;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    printf("details of which student you want to know : ");
    printf("Student no : %d\n", position);
    printf("ID : %d\nName : %s\nSec : %c\nMark : %.2f\n", temp->id, temp->name, temp->sec, temp->mark);
}
void search()
{
    int skey;
    printf("which id you want to search :");
    scanf("%d", &skey);

    temp = head;

    while (temp != 0)

    {
        if (skey == temp->id)
        {

            printf("Student no : %d\n", skey);
            printf("ID : %d\nName : %s\nSec : %c\nMark : %.2f\n", temp->id, temp->name, temp->sec, temp->mark);
        }
        temp = temp->next;
    }
}

int main()
{
    creat_new_stu();
    display();
    insert_new_first();
    display();
    return 0;
}
