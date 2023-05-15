#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    float mark;
    char sec;
    struct student *next;
};
struct student *head = NULL;
struct student *temp = NULL;
struct student *newstudent = NULL;

void creat_new_stu()
{
    head = NULL;
    int a;
    printf("how many student is their :");
    scanf("%d", &a);
    while (a--)
    {
        newstudent = (struct student *)malloc(sizeof(struct student));
        printf("data input system 1st ID then space then mark then section\n");
        printf("input your student data : ");
        scanf("%d %f %c", &newstudent->id, &newstudent->mark, &newstudent->sec);

        newstudent->next = 0;
        if (head == 0)
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
    printf("data input system 1st ID then space then mark then section\n");
    printf("input your student data : ");
    scanf("%d%f %c", &newstudent->id, &newstudent->mark, &newstudent->sec);
    newstudent->next = head;
    head = newstudent;
}
void insert_new_last()
{

    newstudent = (struct student *)malloc(sizeof(struct student));
    printf("data input system 1st ID then space then mark then section\n");
    printf("input your student data : ");
    scanf("%d%f %c", &newstudent->id, &newstudent->mark, &newstudent->sec);
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

    newstudent = (struct student *)malloc(sizeof(struct student));
    printf("data input system 1st ID then space then mark then section\n");
    printf("input your student data : \n");
    scanf("%d%f %c", &newstudent->id, &newstudent->mark, &newstudent->sec);

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
        printf("ID : %d\nMark : %.2f\nSec : %c\n", temp->id, temp->mark, temp->sec);
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
    printf("ID : %d\nMark : %.2f\nSec : %c\n", temp->id, temp->mark, temp->sec);
}
void search()
{
    int skey;
    printf("which id you want to search :");
    scanf("%d", &skey);

    temp = head;

    while (temp!=0)

    {
        if(skey == temp->id){



    printf("Student no : %d\n", skey);
    printf("ID : %d\nMark : %.2f\nSec : %c\n", temp->id, temp->mark, temp->sec);
        }
        temp = temp->next;

    }

}

int main()
{
    creat_new_stu();
    display();
    search();



    return 0;
}
