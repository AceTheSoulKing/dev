#include <stdio.h>
#include <limits.h>

int mcm(int i, int j, int d[], int n, int M[][n])
{
    if (i == j)
    {
        M[i][j] = 0;
        return 0;
    }

    if (M[i][j] != -1)
        return M[i][j];

    M[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int cost =
            mcm(i, k, d, n, M) +
            mcm(k + 1, j, d, n, M) +
            d[i - 1] * d[k] * d[j];

        if (cost < M[i][j])
            M[i][j] = cost;
    }

    return M[i][j];
}

int main()
{
    int d[] = {3, 2, 4, 2, 5};
    int size_for_memo = sizeof(d) / sizeof(d[0]);

    int M[size_for_memo][size_for_memo];

    for (int i = 0; i < size_for_memo; i++)
        for (int j = 0; j < size_for_memo; j++)
            M[i][j] = -1;

    mcm(1, 4, d, size_for_memo, M);

    for (int i = 0; i < size_for_memo; i++)
    {
        for (int j = 0; j < size_for_memo; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}
