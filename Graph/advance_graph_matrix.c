#include <stdio.h>
#include <stdlib.h>

#define vertex 9999
struct graph
{
    int numofvertex;
    int numofedge;
    int adj_matrix[vertex][vertex];
};

struct graph *creat_graph(int numvertex)
{
    struct graph *Graph = (struct graph *)malloc(sizeof(struct graph));
    Graph->numofvertex = numvertex;
    Graph->numofedge = 0;
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            Graph->adj_matrix[i][j] = 0;
        }
    }
    return Graph;
}

void add_edge(struct graph *Graph, int a, int b)
{

    Graph->adj_matrix[a][b] = 1;
    Graph->adj_matrix[b][a] = 1;
    Graph->numofedge++;
}
int numberofedge(struct graph *Graph)
{
    return Graph->numofedge;
}

void print_matrix(struct graph* Graph)
{
    for (int i = 0; i < Graph->numofvertex; i++)
    {
        for (int j = 0; j < Graph->numofvertex; j++)
        {
            printf("%d ", Graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){

    struct graph* Graph=creat_graph(5);
    print_matrix(Graph);
    printf("\n\n");
    add_edge(Graph,0, 1);
    add_edge(Graph,0, 2);
    add_edge(Graph,1, 2);
    add_edge(Graph,2, 3);
    add_edge(Graph,3, 3);
    print_matrix(Graph);
    int k=numberofedge(Graph);
    printf("\n%d",k);
}