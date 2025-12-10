#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <climits>

int prims(int cost[][8], int size)
{
    int minCost = 0;

    bool *selected = (bool *)malloc(sizeof(bool) * size);
    int *near = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i <= size; i++)
        selected[i] = false;

    int u = 1, v;
    int min = INT_MAX;

    for (int i = 1; i <= size; i++)
    {
        if (cost[u][i] < min)
        {
            min = cost[u][i];
            v = i;
        }
    }
    selected[u] = selected[v] = true;
    minCost += cost[u][v];

    for (int i = 1; i <= size; i++)
    {
        if (cost[u][i] < cost[v][i])
            near[i] = u;
        else
            near[i] = v;
    }

    // repeating process edge count increased so now needed edge count = size-2
    for (int i = 1; i <= size - 2; i++)
    {
        min = INT_MAX;

        for (int j = 1; j <= size; j++)
        {
            if (selected[j] == false && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                v = j;
            }
        }
        selected[v] = true;
        u = near[v];
        minCost += cost[u][v];

        for (int k = 1; k <= size; k++)
        {
            if (selected[k] == false && cost[k][v] < cost[k][near[k]])
                near[k] = v;
        }
    }
    return minCost;
}

int main()
{
    int cost[][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, INT_MAX, 28, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX},
                     {0, 28, INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 14},
                     {0, INT_MAX, 16, INT_MAX, 12, INT_MAX, INT_MAX, INT_MAX},
                     {0, INT_MAX, INT_MAX, 12, INT_MAX, 22, INT_MAX, 18},
                     {0, INT_MAX, INT_MAX, INT_MAX, 22, INT_MAX, 25, 24},
                     {0, 10, INT_MAX, INT_MAX, INT_MAX, 25, INT_MAX, INT_MAX},
                     {0, INT_MAX, 14, INT_MAX, 18, 24, INT_MAX, INT_MAX}};

    printf("%d\t", prims(cost, 7));
}