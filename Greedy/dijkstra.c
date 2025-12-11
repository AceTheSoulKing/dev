#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <climits>

int *dijkstra(int cost[][7], int size, int source)
{
    int *distance = (int *)malloc(sizeof(int) * (size + 1));
    bool *selected = (bool *)malloc(sizeof(bool) * (size + 1));

    for (int i = 0; i <= size; i++)
        selected[i] = false;

    for (int i = 1; i <= size; i++)
        distance[i] = cost[source][i];

    distance[source] = 0;
    selected[source] = true;

    int min, u;

    for (int i = 1; i <= size - 1; i++)
    {
        min = INT_MAX;
        u = -1;

        for (int j = 1; j <= size; j++)
        {
            if (!selected[j] && distance[j] < min)
            {
                min = distance[j];
                u = j;
            }
        }

        if (u == -1) // no reachable unselected vertex remains
            break;

        selected[u] = true;

        for (int v = 1; v <= size; v++)
        {
            if (!selected[v] && distance[u] != INT_MAX && cost[u][v] != INT_MAX && distance[u] + cost[u][v] < distance[v])
            {
                distance[v] = distance[u] + cost[u][v];
            }
        }
    }

    free(selected);
    return distance;
}

int main()
{
    int cost[][7] = {{0, 0, 0, 0, 0, 0, 0},
                     {0, INT_MAX, 1, 5, INT_MAX, INT_MAX, INT_MAX},
                     {0, 1, INT_MAX, 3, 10, 8, INT_MAX},
                     {0, 5, 3, INT_MAX, INT_MAX, 2, INT_MAX},
                     {0, INT_MAX, 10, INT_MAX, INT_MAX, 3, 2},
                     {0, INT_MAX, 8, 2, 3, INT_MAX, 7},
                     {0, INT_MAX, INT_MAX, INT_MAX, 2, 7, INT_MAX}};

    int *distance = dijkstra(cost, 6, 3);

    for (int i = 1; i <= 6; i++)
    {
        if (distance[i] == INT_MAX)
            printf("INF\t");
        else
            printf("%d\t", distance[i]);
    }
    printf("\n");

    free(distance);
    return 0;
}
