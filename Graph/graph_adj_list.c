#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int vertex_data;
    struct vertex *next;
};
struct adj_list
{
    struct vertex *head;
};
struct graph
{
    int numofvertex;
    struct adj_list *array;
};

struct vertex *crt_vertex(int data)
{

    struct vertex *newnode = (struct vertex *)malloc(sizeof(struct vertex));
    newnode->vertex_data = data;
    newnode->next = NULL;
    return newnode;
}

struct graph *crt_graph(int numofVertex)
{
    struct graph *Graph = (struct graph *)malloc(sizeof(struct graph));
    Graph->numofvertex = numofVertex;

    Graph->array = (struct adj_list *)malloc(numofVertex * sizeof(struct adj_list));

    int i;
    for (i = 0; i < numofVertex; i++)
    {
        Graph->array[i].head = NULL;
    }

    return Graph;
}
void add_edge(struct graph *Graph, int src, int dest)
{
    struct vertex *temp;
    struct vertex *newvertex = crt_vertex(dest);

    if (Graph->array[src].head == NULL)
    {
        newvertex->next = Graph->array[src].head;
        Graph->array[src].head = newvertex;
    }
    else
    {

        temp = Graph->array[src].head;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = newvertex;
    }

    newvertex = crt_vertex(src);
    if (Graph->array[dest].head == NULL)
    {
        newvertex->next = Graph->array[dest].head;
        Graph->array[dest].head = newvertex;
    }
    else
    {

        temp = Graph->array[dest].head;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = newvertex;
    }
}

void print(struct graph *Graph)
{

    int v;
    for (v = 0; v < Graph->numofvertex; v++)
    {
        struct vertex *temp1 = Graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp1)
        {
            printf("-> %d", temp1->vertex_data);
            temp1 = temp1->next;
        }

        printf("\n");
    }
}

int main()
{

    int v = 7;
    struct graph *Graph = crt_graph(v);

    add_edge(Graph, 0, 1);
    add_edge(Graph, 0, 4);
    add_edge(Graph, 1, 2);
    add_edge(Graph, 1, 3);
    add_edge(Graph, 1, 4);
    add_edge(Graph, 2, 3);
    add_edge(Graph, 3, 4);
    add_edge(Graph, 6, 3);
    add_edge(Graph, 5, 4);
    print(Graph);
}
