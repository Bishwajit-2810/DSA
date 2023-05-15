#include <stdio.h>
#include <stdlib.h>

#define vertex 5
int adj_matrix[vertex][vertex];

void print_matrix()
{
    printf("\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int a, int b)
{
    if (a >= vertex || a < 0 || b >= vertex || b < 0)
    {
        return;
    }

    adj_matrix[a][b] = 1;
    adj_matrix[b][a] = 1;
}

int main()
{
    print_matrix();
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 3);

    print_matrix();
}