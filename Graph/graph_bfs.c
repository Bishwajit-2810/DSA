#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 5

struct vertex
{
    char label;
    bool visited;
};

int queue[max];
int tail = -1;
int head = 0;
int totalqueueitem = 0;

struct vertex *arrvertex[max];

int adj_matrix[max][max];

int vertex_count = 0;

void insert(int data)
{
    queue[tail++] = data;
    totalqueueitem++;
}
int removedt()
{
    totalqueueitem--;
    return queue[head++];
}
bool isqueueempty()
{

    return totalqueueitem == 0;
}

void add_vertex(char lv)
{
    struct vertex *Vertex = (struct vertex *)malloc(sizeof(struct vertex));
    Vertex->label = lv;
    Vertex->visited = false;
    arrvertex[vertex_count++] = Vertex;
}
void addedge(int start, int end)
{
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

void display(int index)
{

    printf("%c ", arrvertex[index]->label);
}
int getadjunvisitedvertex(int index)
{
    int i;
    for (i = 0; i < vertex_count; i++)
    {
        if (adj_matrix[index][i] == 1 && arrvertex[i]->visited == false)
        {
            return i;
        }
    }
    return -1;
}

void bfs()
{
    int i;
    arrvertex[0]->visited = true;
    display(0);
    insert(0);
    int unvisitedvertex;
    while (!isqueueempty())
    {
        int tempvertex = removedt();

        while ((unvisitedvertex = getadjunvisitedvertex(tempvertex)) != -1)
        {
            arrvertex[unvisitedvertex]->visited = true;
            display(unvisitedvertex);
            insert(unvisitedvertex);
        }
    }
    for(i=0;i<vertex_count;i++){
        arrvertex[i]->visited=false;
    }

}

int main() {
   int i, j;

   for(i = 0; i<max; i++) {
      for(j = 0; j<max; j++) 
         adj_matrix[i][j] = 0;
   }

   add_vertex('S');   
   add_vertex('A');  
   add_vertex('B');  
   add_vertex('C');   
   add_vertex('D'); 

   addedge(0, 1);    
   addedge(0, 2);   
   addedge(0, 3);    
   addedge(1, 4);   
   addedge(2, 4);   
   addedge(3, 4);    


   printf("\nBreadth First Search: ");

   bfs();

   return 0;
}
