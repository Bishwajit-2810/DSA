#include <stdio.h>
#include <stdlib.h>

#define a 6
int queue[a];
int head = -1;
int tail = -1;
void enqueue()
{
    printf("enter data : ");
    int data;
    scanf("%d", &data);
    if ((tail + 1) % a == head)
    {
        printf("overflow\n");
    }
    else if (head == -1 && tail == -1)
    {
        head++;
        tail++;
        queue[head] = data;
    }
    else
    {
        tail = (tail + 1) % a;
        queue[tail] = data;
    }
}
void dequeue()
{
    if (head == -1 && tail == -1)
    {
        printf("queue is empty\n");
    }
    if (head == tail)
    {
        head = tail = -1;
        printf("dequeue Successful\n");
    }
    else
    {
        head = (head + 1) % a;
        printf("dequeue Successful\n");
    }
}
void display_queue()
{
    if (head == -1 && tail == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("the queue is : \n");
        for (int i = head; i != tail; i = ((i + 1) % a))
        {

            printf("%d ", queue[i]);
        }
        printf("%d", queue[tail]);
    }
    printf("\n");
}
int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    display_queue();
    dequeue();
    dequeue();
    dequeue();
    display_queue();
    enqueue();
    enqueue();
    enqueue();
    display_queue();
    dequeue();
    display_queue();
}
