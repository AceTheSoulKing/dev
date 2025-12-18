#include <stdio.h>
#include <climits>

int MatrixM(int i, int j, int dimension[])
{
    if (i == j)
        return 0;

    int minCost = INT_MAX;
    int cost;

    for (int k = i; k < j; k++)
    {
        cost = MatrixM(i, k, dimension) + MatrixM(k + 1, j, dimension) + dimension[i - 1] * dimension[k] * dimension[j];

        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}

int main()
{
    int d[] = {3, 2, 4, 2, 5};

    int result = MatrixM(1, 4, d);

    printf("%d\n", result);
}