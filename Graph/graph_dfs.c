#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 5

struct vertex
{
    char label;
    bool visited;
};

int stack[max];
int head = -1;

struct vertex *arrvertex[max];

int adj_matrix[max][max];

int vertex_count = 0;
void push(int item)
{
    head++;
    stack[head] = item;
    // stack[++head] = item;
}

int pop()
{
    return stack[head--];
}
int peek()
{
    return stack[head];
}
bool isstackempty()
{
    return head == -1;
}

void add_vertex(char a)
{

    struct vertex *Vertex = (struct vertex *)malloc(sizeof(struct vertex));
    Vertex->label = a;
    Vertex->visited = false;
    arrvertex[vertex_count++] = Vertex;
}

void add_edge(int start, int end)
{
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}
void display(int vertexindex)
{
    printf("%c ", arrvertex[vertexindex]->label);
}

int getadjunvisitedvertex(int vertexindex)
{
    int i;
    for (i = 0; i < vertex_count; i++)
    {
        if (adj_matrix[vertexindex][i] == 1 && arrvertex[i]->visited == false)
        {

            return i;
        }
    }

    return -1;
}

void dfs()
{
    int i;

    arrvertex[0]->visited = true;
    display(0);
    push(0);
    while (!isstackempty())
    {
        int unvisited = getadjunvisitedvertex(peek());
        if (unvisited == -1)
        {
            pop();
        }
        else
        {
            arrvertex[unvisited]->visited = true;
            display(unvisited);
            push(unvisited);
        }
    }

    for (i = 0; i < vertex_count; i++)
    {
        arrvertex[i]->visited = false;
    }
}

int main()
{
    int i, j;
    for (i = 0; i < max; i++)
    {

        for (j = 0; j < max; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    add_vertex('S');
    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 4);
    add_edge(2, 4);
    add_edge(3, 4);

    printf("Depth First Search: ");

    dfs();

    return 0;
}